import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
from cv_bridge import CvBridge
import cv2
import numpy as np

class ImageProcessingNode(Node):
    def __init__(self):
        super().__init__('image_processing_node')
        self.bridge = CvBridge()

        self.subscription = self.create_subscription(
            Image,
            '/camera/image_raw',
            self.process_image,
            10
        )

        self.color_mask_pub = self.create_publisher(Image, '/image_processing/color_mask', 10)
        self.canny_pub = self.create_publisher(Image, '/image_processing/canny_edges', 10)
        self.final_pub = self.create_publisher(Image, '/image_processing/final_output', 10)
        self.cube_info_pub = self.create_publisher(Float32MultiArray, '/cube_info', 10)

        self.declare_parameters(
            namespace='',
            parameters=[
                ('lower_h', 0), ('upper_h', 10),   # Rango de H para naranja
                ('lower_s', 75), ('upper_s', 125), # Rango de S para colores intensos
                ('lower_v', 200), ('upper_v', 250), # Rango de V para colores brillantes
                ('canny_threshold1', 100), ('canny_threshold2', 200) # Valores Canny
            ]
        )

        self.get_logger().info('Image processing node started.')

    def process_image(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")

        lower_h = self.get_parameter('lower_h').get_parameter_value().integer_value
        upper_h = self.get_parameter('upper_h').get_parameter_value().integer_value
        lower_s = self.get_parameter('lower_s').get_parameter_value().integer_value
        upper_s = self.get_parameter('upper_s').get_parameter_value().integer_value
        lower_v = self.get_parameter('lower_v').get_parameter_value().integer_value
        upper_v = self.get_parameter('upper_v').get_parameter_value().integer_value
        canny_threshold1 = self.get_parameter('canny_threshold1').get_parameter_value().integer_value
        canny_threshold2 = self.get_parameter('canny_threshold2').get_parameter_value().integer_value

        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        lower_bound = np.array([lower_h, lower_s, lower_v])
        upper_bound = np.array([upper_h, upper_s, upper_v])
        mask = cv2.inRange(hsv, lower_bound, upper_bound)

        mask_bgr = cv2.cvtColor(mask, cv2.COLOR_GRAY2BGR)
        self.color_mask_pub.publish(self.bridge.cv2_to_imgmsg(mask_bgr, "bgr8"))

        edges = cv2.Canny(cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY), canny_threshold1, canny_threshold2)
        edges_bgr = cv2.cvtColor(edges, cv2.COLOR_GRAY2BGR)
        self.canny_pub.publish(self.bridge.cv2_to_imgmsg(edges_bgr, "bgr8"))

        output_frame = self.detect_cube(frame, mask, edges)
        self.final_pub.publish(self.bridge.cv2_to_imgmsg(output_frame, "bgr8"))

    def detect_cube(self, frame, mask, edges):
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        output_frame = frame.copy()
        best_contour = None

        for contour in contours:
            area = cv2.contourArea(contour)
            if area > 500:
                epsilon = 0.02 * cv2.arcLength(contour, True)
                approx = cv2.approxPolyDP(contour, epsilon, True)

                if len(approx) == 4:
                    best_contour = contour
                    break

        if best_contour is not None:
            M = cv2.moments(best_contour)
            if M["m00"] > 0:
                cx = int(M["m10"] / M["m00"])
                cy = int(M["m01"] / M["m00"])
                area = cv2.contourArea(best_contour)

                height, width = frame.shape[:2]
                dx = cx - (width // 2)
                dy = cy - (height // 2)

                cube_info = Float32MultiArray()
                cube_info.data = [float(dx), float(dy), float(area)]
                self.cube_info_pub.publish(cube_info)

                cv2.drawContours(output_frame, [best_contour], 0, (0, 255, 0), 2)
                cv2.circle(output_frame, (cx, cy), 5, (0, 0, 255), -1)
                cv2.putText(output_frame, f"Pos (pix): {dx}, {dy}",
                            (cx - 50, cy - 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
                cv2.putText(output_frame, f"Area: {area:.2f} px^2",
                            (cx - 50, cy - 40), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)

        return output_frame

def main(args=None):
    rclpy.init(args=args)
    node = ImageProcessingNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
