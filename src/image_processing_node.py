import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
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
            self.process_camera0_image,
            10
        )
        self.camera1_subscription = self.create_subscription(
            Image,
            '/camera1/image_raw',
            self.process_camera1_image,
            10
        )

        self.color_mask_pub0 = self.create_publisher(Image, '/camera0/color_mask', 10)
        self.canny_pub0 = self.create_publisher(Image, '/camera0/canny_edges', 10)
        self.final_pub0 = self.create_publisher(Image, '/camera0/final_output', 10)

        self.color_mask_pub1 = self.create_publisher(Image, '/camera1/color_mask', 10)
        self.canny_pub1 = self.create_publisher(Image, '/camera1/canny_edges', 10)
        self.final_pub1 = self.create_publisher(Image, '/camera1/final_output', 10)

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
        self.get_logger().info(f"Updated calibration parameters for {camera_prefix}")

    def process_camera0_image(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        processed_frame = self.process_image(frame, camera_id=0)

        self.color_mask_pub0.publish(self.bridge.cv2_to_imgmsg(processed_frame["mask"], "mono8"))
        self.canny_pub0.publish(self.bridge.cv2_to_imgmsg(processed_frame["edges"], "mono8"))
        self.final_pub0.publish(self.bridge.cv2_to_imgmsg(processed_frame["final"], "bgr8"))

    def process_camera1_image(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        processed_frame = self.process_image(frame, camera_id=1)

        self.color_mask_pub1.publish(self.bridge.cv2_to_imgmsg(processed_frame["mask"], "mono8"))
        self.canny_pub1.publish(self.bridge.cv2_to_imgmsg(processed_frame["edges"], "mono8"))
        self.final_pub1.publish(self.bridge.cv2_to_imgmsg(processed_frame["final"], "bgr8"))

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

        output_frame = self.detect_cube(frame, mask, edges)

        return {"mask": mask, "edges": edges, "final": output_frame}

    def detect_cube(self, frame, mask, edges):
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        output_frame = frame.copy()

        for contour in contours:
            area = cv2.contourArea(contour)
            if area > 100 and area < 10000:
                epsilon = 0.02 * cv2.arcLength(contour, True)
                approx = cv2.approxPolyDP(contour, epsilon, True)
                if len(approx) >= 4 and len(approx) <= 6:
                    M = cv2.moments(contour)
                    if M["m00"] > 0:
                        cx = int(M["m10"] / M["m00"])
                        cy = int(M["m01"] / M["m00"])
                        cv2.drawContours(output_frame, [contour], 0, (0, 255, 0), 2)
                        cv2.circle(output_frame, (cx, cy), 5, (0, 0, 255), -1)
                        self.get_logger().info(f'Coordenadas: ({cx}, {cy})')
                        self.get_logger().info(f'Area: {area}')


        return output_frame

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

