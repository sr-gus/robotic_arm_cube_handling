import rclpy
from rclpy.node import Node
from robotic_arm_cube_handling.msg import CalibrationParams

class CalibrationNode(Node):
    def __init__(self):
        super().__init__('calibration_node')
        self.subscription = self.create_subscription(
            CalibrationParams,
            '/calibration_params',
            self.calibration_callback,
            10
        )
        self.get_logger().info('Calibration node started and listening for calibration parameters.')

    def calibration_callback(self, msg):
        self.get_logger().info(f"Received calibration parameters: {msg}")

        self.set_parameters([
            rclpy.parameter.Parameter('lower_h', rclpy.Parameter.Type.INTEGER, msg.lower_h),
            rclpy.parameter.Parameter('upper_h', rclpy.Parameter.Type.INTEGER, msg.upper_h),
            rclpy.parameter.Parameter('lower_s', rclpy.Parameter.Type.INTEGER, msg.lower_s),
            rclpy.parameter.Parameter('upper_s', rclpy.Parameter.Type.INTEGER, msg.upper_s),
            rclpy.parameter.Parameter('lower_v', rclpy.Parameter.Type.INTEGER, msg.lower_v),
            rclpy.parameter.Parameter('upper_v', rclpy.Parameter.Type.INTEGER, msg.upper_v),
            rclpy.parameter.Parameter('canny_threshold1', rclpy.Parameter.Type.INTEGER, msg.canny_threshold1),
            rclpy.parameter.Parameter('canny_threshold2', rclpy.Parameter.Type.INTEGER, msg.canny_threshold2),
        ])

def main(args=None):
    rclpy.init(args=args)
    node = CalibrationNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
