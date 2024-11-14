import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import subprocess

class CameraNode(Node):
    def __init__(self):
        super().__init__('camera_node')
        self.publisher_cam0 = self.create_publisher(Image, '/camera0/image_raw', 10)
        self.publisher_cam1 = self.create_publisher(Image, '/camera1/image_raw', 10)
        self.timer = self.create_timer(0.1, self.publish_images)
        self.bridge = CvBridge()
        
        self.cap0 = cv2.VideoCapture('/dev/video0')
        self.cap1 = cv2.VideoCapture('/dev/video2')
        
        self.restart_attempts = {0: 0, 1: 0}
        self.max_restarts = 100
        self.get_logger().info('Dual camera node started.')

    def publish_images(self):
        self.capture_and_publish(self.cap0, self.publisher_cam0, 0)
        
        self.capture_and_publish(self.cap1, self.publisher_cam1, 1)

    def capture_and_publish(self, cap, publisher, camera_id):
        ret, frame = cap.read()
        if not ret:
            self.get_logger().error(f'Failed to capture image from camera {camera_id}. Attempting to reset the camera...')
            self.restart_camera(camera_id)
            return

        self.restart_attempts[camera_id] = 0
        img_msg = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
        publisher.publish(img_msg)

    def restart_camera(self, camera_id):
        if self.restart_attempts[camera_id] < self.max_restarts:
            self.get_logger().info(f'Attempting to restart camera {camera_id} (Attempt {self.restart_attempts[camera_id] + 1}/{self.max_restarts})')
            
            if camera_id == 0:
                self.cap0.release()
                self.cap0 = cv2.VideoCapture('/dev/video0')
            elif camera_id == 1:
                self.cap1.release()
                self.cap1 = cv2.VideoCapture('/dev/video1')
            
            self.restart_attempts[camera_id] += 1
        else:
            self.get_logger().error(f'Maximum restart attempts reached for camera {camera_id}. Stopping further attempts.')

    def destroy_node(self):
        self.cap0.release()
        self.cap1.release()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = CameraNode()
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
