import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Bool
from cv_bridge import CvBridge
import paho.mqtt.client as mqtt
import cv2

class MQTTPublisherNode(Node):
    def __init__(self):
        super().__init__('mqtt_publisher_node')
        self.bridge = CvBridge()

        self.camera0_enabled = True
        self.camera1_enabled = True

        self.mqtt_client = mqtt.Client()
        self.mqtt_client.on_connect = self.on_connect
        self.mqtt_client.on_disconnect = self.on_disconnect
        self.mqtt_client.connect('localhost', 1883, 60)
        self.mqtt_client.loop_start()

        self.camera0_raw_subscription = self.create_subscription(
            Image,
            '/camera0/image_raw',
            self.camera0_raw_callback,
            10
        )
        self.camera1_raw_subscription = self.create_subscription(
            Image,
            '/camera1/image_raw',
            self.camera1_raw_callback,
            10
        )

        self.camera0_color_mask_subscription = self.create_subscription(
            Image,
            '/camera0/color_mask',
            self.camera0_color_mask_callback,
            10
        )
        self.camera1_color_mask_subscription = self.create_subscription(
            Image,
            '/camera1/color_mask',
            self.camera1_color_mask_callback,
            10
        )

        self.camera0_canny_edges_subscription = self.create_subscription(
            Image,
            '/camera0/canny_edges',
            self.camera0_canny_edges_callback,
            10
        )
        self.camera1_canny_edges_subscription = self.create_subscription(
            Image,
            '/camera1/canny_edges',
            self.camera1_canny_edges_callback,
            10
        )

        self.camera0_final_output_subscription = self.create_subscription(
            Image,
            '/camera0/final_output',
            self.camera0_final_output_callback,
            10
        )
        self.camera1_final_output_subscription = self.create_subscription(
            Image,
            '/camera1/final_output',
            self.camera1_final_output_callback,
            10
        )

        self.camera0_enable_subscription = self.create_subscription(
            Bool,
            '/camera0/mqtt_enable',
            self.camera0_enable_callback,
            10
        )
        self.camera1_enable_subscription = self.create_subscription(
            Bool,
            '/camera1/mqtt_enable',
            self.camera1_enable_callback,
            10
        )

        self.get_logger().info('MQTT Publisher Node started for dual cameras.')

    def on_connect(self, client, userdata, flags, rc):
        if rc == 0:
            self.get_logger().info('Connected to MQTT Broker!')
        else:
            self.get_logger().error(f'Failed to connect to MQTT Broker, return code {rc}')

    def on_disconnect(self, client, userdata, rc):
        self.get_logger().info('Disconnected from MQTT Broker.')

    def camera0_enable_callback(self, msg):
        self.camera0_enabled = msg.data
        self.get_logger().info(f'Camera 0 enabled set to {self.camera0_enabled}')

    def camera1_enable_callback(self, msg):
        self.camera1_enabled = msg.data
        self.get_logger().info(f'Camera 1 enabled set to {self.camera1_enabled}')

    def camera0_raw_callback(self, msg):
        if self.camera0_enabled:
            self.publish_image(msg, 'ros/camera0/image_raw', 'camera0 raw image')

    def camera1_raw_callback(self, msg):
        if self.camera1_enabled:
            self.publish_image(msg, 'ros/camera1/image_raw', 'camera1 raw image')

    def camera0_color_mask_callback(self, msg):
        if self.camera0_enabled:
            self.publish_image(msg, 'ros/camera0/color_mask', 'camera0 color mask')

    def camera1_color_mask_callback(self, msg):
        if self.camera1_enabled:
            self.publish_image(msg, 'ros/camera1/color_mask', 'camera1 color mask')

    def camera0_canny_edges_callback(self, msg):
        if self.camera0_enabled:
            self.publish_image(msg, 'ros/camera0/canny_edges', 'camera0 canny edges')

    def camera1_canny_edges_callback(self, msg):
        if self.camera1_enabled:
            self.publish_image(msg, 'ros/camera1/canny_edges', 'camera1 canny edges')

    def camera0_final_output_callback(self, msg):
        if self.camera0_enabled:
            self.publish_image(msg, 'ros/camera0/final_output', 'camera0 final output')

    def camera1_final_output_callback(self, msg):
        if self.camera1_enabled:
            self.publish_image(msg, 'ros/camera1/final_output', 'camera1 final output')

    def publish_image(self, msg, topic, log_message):
        '''Helper function to publish images to MQTT and log messages.'''
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
            _, buffer = cv2.imencode('.jpg', frame)
            self.mqtt_client.publish(topic, buffer.tobytes())
        except Exception as e:
            self.get_logger().error(f'Failed to process or publish {log_message}: {e}')

    def destroy_node(self):
        self.mqtt_client.loop_stop()
        self.mqtt_client.disconnect()
        super().destroy_node()
        self.get_logger().info('MQTT Publisher Node has been shut down.')

def main(args=None):
    rclpy.init(args=args)
    node = MQTTPublisherNode()
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
