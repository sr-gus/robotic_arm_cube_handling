import rclpy
from rclpy.node import Node
from robotic_arm_cube_handling.msg import CalibrationParams

class CalibrationPublisher(Node):
    def __init__(self):
        super().__init__('calibration_publisher')
        self.publisher_ = self.create_publisher(CalibrationParams, '/calibration_params', 10)
        self.get_logger().info('Calibration publisher started.')

    def publish_params(self, lower_h, upper_h, lower_s, upper_s, lower_v, upper_v, canny1, canny2):
        msg = CalibrationParams()
        msg.lower_h = lower_h
        msg.upper_h = upper_h
        msg.lower_s = lower_s
        msg.upper_s = upper_s
        msg.lower_v = lower_v
        msg.upper_v = upper_v
        msg.canny_threshold1 = canny1
        msg.canny_threshold2 = canny2
        self.publisher_.publish(msg)
        self.get_logger().info(f"Published calibration parameters: {msg}")

def main(args=None):
    rclpy.init(args=args)
    node = CalibrationPublisher()
    try:
        node.publish_params(0, 179, 50, 255, 50, 255, 100, 200)
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
