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

        # Suscripciones a las imágenes de las cámaras
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

        self.joint_states_subscription = self.create_subscription(
            Float32MultiArray,  # Tipo del mensaje del tópico joint_states
            '/joint_states',
            self.joint_states_callback,
            10
        )

        # Publicadores para los resultados de procesamiento de cada cámara
        self.color_mask_pub0 = self.create_publisher(Image, '/camera0/color_mask', 10)
        self.canny_edges_pub0 = self.create_publisher(Image, '/camera0/canny_edges', 10)
        self.final_output_pub0 = self.create_publisher(Image, '/camera0/final_output', 10)

        self.color_mask_pub1 = self.create_publisher(Image, '/camera1/color_mask', 10)
        self.canny_edges_pub1 = self.create_publisher(Image, '/camera1/canny_edges', 10)
        self.final_output_pub1 = self.create_publisher(Image, '/camera1/final_output', 10)

        self.cube_info_pub = self.create_publisher(Float32MultiArray, '/cube_info', 10)
        self.target_position_pub = self.create_publisher(Float32MultiArray, '/target_position', 10)
        self.led_color_pub = self.create_publisher(Int32MultiArray, '/led_color', 10)

        # Tiempo de última imagen recibida para cada cámara
        self.last_image_time_camera0 = self.get_clock().now()
        self.last_image_time_camera1 = self.get_clock().now()

        self.best_cube_info = None
        self.best_cube_info_reset = 0

        # Parámetros de calibración de procesamiento de imágenes
        self.declare_parameters(
            namespace='',
            parameters=[
                ('camera0_lower_h', 0), ('camera0_upper_h', 20),
                ('camera0_lower_s', 150), ('camera0_upper_s', 255),
                ('camera0_lower_v', 130), ('camera0_upper_v', 255),
                ('camera0_canny_threshold1', 25), ('camera0_canny_threshold2', 50),

                ('camera1_lower_h', 0), ('camera1_upper_h', 20),
                ('camera1_lower_s', 150), ('camera1_upper_s', 255),
                ('camera1_lower_v', 130), ('camera1_upper_v', 255),
                ('camera1_canny_threshold1', 25), ('camera1_canny_threshold2', 50)
            ]
        )

        self.calibration_subscription = self.create_subscription(
            CalibrationParams,
            '/calibration_params',
            self.calibration_callback,
            10
        )

        self.get_logger().info('Dual camera processing node started with independent parameters for each camera.')

    def joint_states_callback(self, msg):
        self.get_logger().info('Joint states message received. Resetting best_cube_info to None.')
        self.best_cube_info = None
        self.publish_led_color([255, 255, 255])
        time.sleep(10)
        self.publish_led_color([0, 0, 0])

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
        frame = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        processed_frame, cube_info = self.process_image(frame, camera_id)

    # Publicar máscaras y salidas para cada cámara
        mask_pub = self.color_mask_pub0 if camera_id == 0 else self.color_mask_pub1
        edges_pub = self.canny_edges_pub0 if camera_id == 0 else self.canny_edges_pub1
        final_pub = self.final_output_pub0 if camera_id == 0 else self.final_output_pub1

        mask_pub.publish(self.bridge.cv2_to_imgmsg(processed_frame["mask"], "mono8"))
        edges_pub.publish(self.bridge.cv2_to_imgmsg(processed_frame["edges"], "mono8"))
        final_pub.publish(self.bridge.cv2_to_imgmsg(processed_frame["final"], "bgr8"))

        cube_msg = Float32MultiArray()
        cube_msg.data = [cube_info['x'], cube_info['y'], cube_info['area']]
        self.cube_info_pub.publish(cube_msg)

        if cube_info['area'] == 0:
            # No se detecta cubo: LED Rojo
            self.publish_led_color([0, 0, 0])
            return

        # Verifica si la nueva detección es mejor o similar a la mejor actual
        if self.best_cube_info:
            if self.is_similar_to_best_cube(cube_info):
                self.best_cube_info['x'] = (self.best_cube_info['x'] + cube_info['x']) / 2
                self.best_cube_info['y'] = (self.best_cube_info['y'] + cube_info['y']) / 2
                self.best_cube_info['area'] = (self.best_cube_info['area'] + cube_info['area']) / 2
                self.best_cube_info_reset += 1
                self.publish_led_color([0, 0, 255])
            elif self.is_new_cube_better(cube_info):
                self.best_cube_info = cube_info
                self.best_cube_info_reset = 0
                # Cambio a una mejor detección: LED Verde
                self.publish_led_color([0, 255, 0])
            else:
                self.best_cube_info = None
        else:
            self.best_cube_info = cube_info
            self.best_cube_info_reset = 0
            # Cambio a una mejor detección: LED Verde
            self.publish_led_color([0, 255, 0])

        # Convierte las coordenadas a cm
        if self.best_cube_info:
            x_mm, y_mm = self.pixel_to_mm_camera0(cube_info['x'], cube_info['y']) if camera_id == 0 else \
                        self.pixel_to_mm_camera1(cube_info['x'], cube_info['y'])
            z_mm = self.area_to_z_mm_camera0(cube_info['area']) if camera_id == 0 else \
                self.area_to_z_mm_camera1(cube_info['area'])

            # Publica la posición en cm
            target_msg = Float32MultiArray()
            target_msg.data = [x_mm, y_mm, z_mm]  # Convertir a cm
            self.target_position_pub.publish(target_msg)

    def is_new_cube_better(self, cube_info, tolerance=500):
        """Determina si una nueva detección es mejor que la actual basada en el área."""
        return cube_info['area'] > (self.best_cube_info.get('area', 0) + tolerance)

    def is_similar_to_best_cube(self, cube_info, tolerance=100):
        dx = abs(self.best_cube_info['x'] - cube_info['x'])
        dy = abs(self.best_cube_info['y'] - cube_info['y'])
        darea = abs(self.best_cube_info['area'] - cube_info['area'])
        return dx < (tolerance/10) and dy < (tolerance/10) and darea < tolerance

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

        x, y, area = self.get_cube_info(mask)

        return {"mask": mask, "edges": edges, "final": output_frame}, {'x': x, 'y': y, 'area': area}

    def detect_cube(self, frame, mask, edges):
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        for contour in contours:
            area = cv2.contourArea(contour)
            if 1000 < area < 10000:
                M = cv2.moments(contour)
                if M['m00'] > 0:
                    x = int(M['m10'] / M['m00'])
                    y = int(M['m01'] / M['m00'])
                    cv2.drawContours(frame, [contour], 0, (0, 255, 0), 2)
                    cv2.circle(frame, (x, y), 5, (0, 0, 255), -1)
                    break
        return frame

    def get_cube_info(self, mask):
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
        x_mm = -(6/85)*x - 33.41
        y_mm = -(3/4)*y + 292.5
        return x_mm, y_mm

    def pixel_to_mm_camera1(self, x, y):
        x_mm = -(7/170)*x + 26.176
        y_mm = (7/110)*y + 6.73
        return x_mm, y_mm

    def area_to_z_mm_camera0(self, area):
        z_mm = -(1/120)*area+54.17
        return z_mm

    def area_to_z_mm_camera1(self, area):
        z_mm = -(3/400)*area + 25.25
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
