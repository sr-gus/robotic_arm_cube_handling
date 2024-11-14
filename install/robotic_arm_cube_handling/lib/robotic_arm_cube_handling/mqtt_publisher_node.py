kimport rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Float32MultiArray
from cv_bridge import CvBridge
import paho.mqtt.client as mqtt
import cv2
import numpy as np

class MQTTPublisherNode(Node):
    def __init__(self):
        super().__init__('mqtt_publisher_node')
        self.bridge = CvBridge()
        
        self.mqtt_client = mqtt.Client()
        self.mqtt_client.connect("localhost", 1883, 60)

        self.color_mask_subscription = self.create_subscription(
            Image,
            '/image_processing/color_mask',
            self.color_mask_callback,
            10
        )
        self.canny_edges_subscription = self.create_subscription(
            Image,
            '/image_processing/canny_edges',
            self.canny_edges_callback,
            10
        )
        self.final_image_subscription = self.create_subscription(
            Image,
            '/image_processing/final_output',
            self.final_image_callback,
            10
        )
        self.cube_info_subscription = self.create_subscription(
            Float32MultiArray,
            '/cube_info',
            self.cube_info_callback,
            10
        )

        self.get_logger().info('MQTT Publisher Node started.')

    def color_mask_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        _, buffer = cv2.imencode('.jpg', frame)
        self.mqtt_client.publish("ros/color_mask", buffer.tobytes())
    
    def canny_edges_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        _, buffer = cv2.imencode('.jpg', frame)
        self.mqtt_client.publish("ros/canny_edges", buffer.tobytes())
    
    def final_image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        _, buffer = cv2.imencode('.jpg', frame)
        self.mqtt_client.publish("ros/final_image", buffer.tobytes())
    
    def cube_info_callback(self, msg):
        info = msg.data
        self.mqtt_client.publish("ros/cube_info", f"{info}")

def main(args=None):
    rclpy.init(args=args)
    node = MQTTPublisherNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
