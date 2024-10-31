import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import subprocess

class CameraNode(Node):
    def __init__(self):
        super().__init__('camera_node')
        self.publisher_ = self.create_publisher(Image, '/camera/image_raw', 10)
        self.timer = self.create_timer(0.1, self.publish_image)
        self.bridge = CvBridge()
        self.cap = cv2.VideoCapture('/dev/video0')
        self.restart_attempts = 0
        self.max_restarts = 100
        self.get_logger().info('Camera node started.')

    def publish_image(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().error('Failed to capture image. Attempting to reset the camera...')
            self.restart_camera()
            return
        
        self.restart_attempts = 0
        img_msg = self.bridge.cv2_to_imgmsg(frame, encoding="bgr8")
        self.publisher_.publish(img_msg)

    def restart_camera(self):
        if self.restart_attempts < self.max_restarts:
            self.get_logger().info(f'Attempting to restart camera (Attempt {self.restart_attempts + 1}/{self.max_restarts})')
            self.cap.release()

            subprocess.run(['echo', '1-1', '|', 'sudo', 'tee', '/sys/bus/usb/drivers/usb/unbind'])
            subprocess.run(['echo', '1-1', '|', 'sudo', 'tee', '/sys/bus/usb/drivers/usb/bind'])

            self.cap = cv2.VideoCapture('/dev/video0')
            self.restart_attempts += 1
        else:
            self.get_logger().error('Maximum restart attempts reached. Stopping further attempts.')

    def destroy_node(self):
        self.cap.release()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = CameraNode()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
