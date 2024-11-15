import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float32, Bool
import time

class ServoControlIntermediaryNode(Node):
    def __init__(self):
        super().__init__('servo_control_intermediary_node')

        self.create_subscription(JointState, 'joint_states', self.joint_state_callback, 10)

        self.servo_publishers = [self.create_publisher(Float32, f'/servo_{i+1}_angle', 10) for i in range(5)]
        self.gripper_publisher = self.create_publisher(Bool, '/servo_gripper', 10)

        self.resting_position = [90.0, 90.0, 180.0, 0.0, 0.0] 

    def joint_state_callback(self, msg):
        self.get_logger().info('Received joint_states, publishin angles to servos.')
        
        for i, angle in enumerate(msg.position[:5]):
            transformed_angle = self.apply_transformation(i, angle)
            servo_msg = Float32()
            servo_msg.data = transformed_angle
            self.servo_publishers[i].publish(servo_msg)
            self.get_logger().info(f'Published angle {transformed_angle}° to servo {i+1}.')
        
        time.sleep(5)

        self.toggle_gripper(False)
        self.get_logger().info('Gripper opened.')

        self.move_to_resting_position()

        self.toggle_gripper(True)
        self.get_logger().info('Gripper closed.')

    def apply_transformation(self, joint_index, angle):
        transformed_angle = angle * 180 / 3.14159

        while transformed_angle < 0:
            transformed_angle += 180
        while transformed_angle > 180:
            transformed_angle -= 180

        return transformed_angle


    def toggle_gripper(self, open):
        gripper_msg = Bool()
        gripper_msg.data = open
        self.gripper_publisher.publish(gripper_msg)

    def move_to_resting_position(self):
        self.get_logger().info('Moving arm to rest position.')
        
        for i, angle in enumerate(self.resting_position):
            servo_msg = Float32()
            servo_msg.data = angle
            self.servo_publishers[i].publish(servo_msg)
            self.get_logger().info(f'Published rest angle {angle}° to servo {i+1}.')

        time.sleep(5)

def main(args=None):
    rclpy.init(args=args)
    node = ServoControlIntermediaryNode()
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
