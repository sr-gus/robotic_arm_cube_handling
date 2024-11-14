import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray, Int32MultiArray
from robotic_arm_cube_handling.msg import CalibrationParams
from cv_bridge import CvBridge
import cv2
import numpy as np

class ImageProcessingNode(Node):
    def __init__(self):
        super().__init__('image_processing_node')
        self.bridge = CvBridge()

        self.camera0_subscription = self.create_subscription(
            Image,
            '/camera0/image_raw',
            lambda msg: self.process_camera_image(msg, camera_id=0),
            10
        )
        self.camera1_subscription = self.create_subscription(
            Image,
            '/camera1/image_raw',
            lambda msg: self.process_camera_image(msg, camera_id=1),
            10
        )

        self.cube_info_pub = self.create_publisher(Float32MultiArray, '/cube_info', 10)
        self.target_position_pub = self.create_publisher(Float32MultiArray, '/target_position', 10)
        self.led_color_pub = self.create_publisher(Int32MultiArray, '/led_color', 10)

        self.last_image_time_camera0 = self.get_clock().now()
        self.last_image_time_camera1 = self.get_clock().now()

        self.timer = self.create_timer(1.0, self.check_image_timeout)

        self.declare_parameters(
            namespace='',
            parameters=[
                ('camera0_lower_h', 0), ('camera0_upper_h', 20),
                ('camera0_lower_s', 180), ('camera0_upper_s', 255),
                ('camera0_lower_v', 60), ('camera0_upper_v', 80),
                ('camera0_canny_threshold1', 100), ('camera0_canny_threshold2', 200),
                
                ('camera1_lower_h', 0), ('camera1_upper_h', 180),
                ('camera1_lower_s', 0), ('camera1_upper_s', 255),
                ('camera1_lower_v', 0), ('camera1_upper_v', 255),
                ('camera1_canny_threshold1', 100), ('camera1_canny_threshold2', 200)
            ]
        )

        self.calibration_subscription = self.create_subscription(
            CalibrationParams,
            '/calibration_params',
            self.calibration_callback,
            10
        )

        self.get_logger().info('Dual camera processing node started with independent parameters for each camera.')

    def calibration_callback(self, msg):
        camera_prefix = f'camera{msg.camera_id}'

        self.set_parameters([
            rclpy.parameter.Parameter(f'{camera_prefix}_lower_h', rclpy.Parameter.Type.INTEGER, msg.lower_h),
            rclpy.parameter.Parameter(f'{camera_prefix}_upper_h', rclpy.Parameter.Type.INTEGER, msg.upper_h),
            rclpy.parameter.Parameter(f'{camera_prefix}_lower_s', rclpy.Parameter.Type.INTEGER, msg.lower_s),
            rclpy.parameter.Parameter(f'{camera_prefix}_upper_s', rclpy.Parameter.Type.INTEGER, msg.upper_s),
            rclpy.parameter.Parameter(f'{camera_prefix}_lower_v', rclpy.Parameter.Type.INTEGER, msg.lower_v),
            rclpy.parameter.Parameter(f'{camera_prefix}_upper_v', rclpy.Parameter.Type.INTEGER, msg.upper_v),
            rclpy.parameter.Parameter(f'{camera_prefix}_canny_threshold1', rclpy.Parameter.Type.INTEGER, msg.canny_threshold1),
            rclpy.parameter.Parameter(f'{camera_prefix}_canny_threshold2', rclpy.Parameter.Type.INTEGER, msg.canny_threshold2),
        ])
        self.get_logger().info(f'Updated calibration parameters for {camera_prefix}')

    def publish_led_color(self, color):
        led_msg = Int32MultiArray(data=color)
        self.led_color_pub.publish(led_msg)

    def process_camera_image(self, msg, camera_id):
        if camera_id == 0:
            self.last_image_time_camera0 = self.get_clock().now()
        else:
            self.last_image_time_camera1 = self.get_clock().now()

        frame = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        processed_frame, cube_info = self.process_image(frame, camera_id)

        cube_msg = Float32MultiArray()
        cube_msg.data = [cube_info['x'], cube_info['y'], cube_info['area']]

        if cube_info['area'] == 0:
            if hasattr(self, 'best_cube_info') and self.best_cube_info['camera_id'] == camera_id:
                self.best_cube_info = None
                self.publish_led_color([255, 0, 0])  
            return
        else:
            self.cube_info_pub.publish(cube_msg)
            self.publish_led_color([0, 255, 0])

        if not hasattr(self, 'best_cube_info') or cube_info['area'] > self.best_cube_info['area']:
            self.best_cube_info = cube_info

            if camera_id == 0:
                x_mm, y_mm = self.pixel_to_mm_camera0(cube_info['x'], cube_info['y'])
                z_mm = self.area_to_z_mm_camera0(cube_info['area'])
            else:
                x_mm, y_mm = self.pixel_to_mm_camera1(cube_info['x'], cube_info['y'])
                z_mm = self.area_to_z_mm_camera1(cube_info['area'])

            target_msg = Float32MultiArray()
            target_msg.data = [x_mm, y_mm, z_mm]
            self.target_position_pub.publish(target_msg)

            self.publish_led_color([0, 0, 255])

    def check_image_timeout(self):
        timeout_duration = rclpy.duration.Duration(seconds=2.0)

        current_time = self.get_clock().now()
        if (current_time - self.last_image_time_camera0) > timeout_duration and \
           (current_time - self.last_image_time_camera1) > timeout_duration:
            self.publish_led_color([255, 255, 255])  # Blanco: No se reciben imágenes de ninguna cámara

    def process_image(self, frame, camera_id):
        camera_prefix = f'camera{camera_id}'
        lower_h = self.get_parameter(f'{camera_prefix}_lower_h').get_parameter_value().integer_value
        upper_h = self.get_parameter(f'{camera_prefix}_upper_h').get_parameter_value().integer_value
        lower_s = self.get_parameter(f'{camera_prefix}_lower_s').get_parameter_value().integer_value
        upper_s = self.get_parameter(f'{camera_prefix}_upper_s').get_parameter_value().integer_value
        lower_v = self.get_parameter(f'{camera_prefix}_lower_v').get_parameter_value().integer_value
        upper_v = self.get_parameter(f'{camera_prefix}_upper_v').get_parameter_value().integer_value
        canny_threshold1 = self.get_parameter(f'{camera_prefix}_canny_threshold1').get_parameter_value().integer_value
        canny_threshold2 = self.get_parameter(f'{camera_prefix}_canny_threshold2').get_parameter_value().integer_value

        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        lower_bound = np.array([lower_h, lower_s, lower_v])
        upper_bound = np.array([upper_h, upper_s, upper_v])
        mask = cv2.inRange(hsv, lower_bound, upper_bound)

        edges = cv2.Canny(cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY), canny_threshold1, canny_threshold2)

        x, y, area = self.detect_cube(mask)

        return frame, {'x': x, 'y': y, 'area': area}

    def detect_cube(self, mask):
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        x, y, area = 0, 0, 0
        for contour in contours:
            area = cv2.contourArea(contour)
            if 100 < area < 10000:
                M = cv2.moments(contour)
                if M['m00'] > 0:
                    x = int(M['m10'] / M['m00'])
                    y = int(M['m01'] / M['m00'])
                    break
        return x, y, area

    def pixel_to_mm_camera0(self, x, y):
        x_mm = x * 0.5
        y_mm = y * 0.5
        return x_mm, y_mm

    def pixel_to_mm_camera1(self, x, y):
        x_mm = x * 0.4
        y_mm = y * 0.4
        return x_mm, y_mm

    def area_to_z_mm_camera0(self, area):
        z_mm = 1000 / (area + 1)
        return z_mm

    def area_to_z_mm_camera1(self, area):
        z_mm = 1200 / (area + 1)
        return z_mm

def main(args=None):
    rclpy.init(args=args)
    node = ImageProcessingNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down due to CTRL+C')
    finally:
        if rclpy.ok():
            node.destroy_node()
            rclpy.shutdown()

if __name__ == '__main__':
    main()