import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float32MultiArray
from ikpy.chain import Chain
from ament_index_python.packages import get_package_share_directory
import numpy as np
import os

class InverseKinematicsNode(Node):
    def __init__(self):
        super().__init__('inverse_kinematics_node')

        urdf_path = os.path.join(
            get_package_share_directory('robotic_arm_cube_handling'),
            'urdf',
            'robotic_arm.urdf'
        )

        if not os.path.exists(urdf_path):
            self.get_logger().error(f'URDF file not found at: {urdf_path}')
            raise FileNotFoundError(f'URDF file not found at: {urdf_path}')

        self.chain = Chain.from_urdf_file(urdf_path)

        self.create_subscription(
            Float32MultiArray,
            'target_position',
            self.target_position_callback,
            10
        )

        self.joint_pub = self.create_publisher(JointState, 'joint_states', 10)

        self.stability_window = 5
        self.position_tolerance = 1.5
        self.stable_detections = []
        self.last_position = None
        self.movement_interval = 2.0
        self.max_time_between_detections = 2.0
        self.last_detection_time = self.get_clock().now()
        self.last_movement_time = self.get_clock().now()

    def target_position_callback(self, msg):
        current_time = self.get_clock().now()
        time_since_last_detection = (current_time - self.last_detection_time).nanoseconds * 1e-9

        if time_since_last_detection > self.max_time_between_detections:
            self.stable_detections = []
            self.get_logger().info(f'Detection time exceeded ({time_since_last_detection:.2f}s). Restarting stable detections.')

        self.last_detection_time = current_time
        current_position = np.array(msg.data[:3])

        if self.last_position is None or np.linalg.norm(current_position - self.last_position) > self.position_tolerance:
            self.stable_detections = []
            self.get_logger().info('Position changed significantly. Restarting stable detections.')
        else:
            self.stable_detections.append(current_position)

        self.last_position = current_position

        if len(self.stable_detections) >= self.stability_window:
            if (self.get_clock().now() - self.last_movement_time).nanoseconds * 1e-9 >= self.movement_interval:
                self.calculate_and_move(current_position)
                self.stable_detections = []
                self.last_movement_time = self.get_clock().now()

    def calculate_and_move(self, target_position):
        try:
            joint_names = [joint.name for joint in self.chain.links[1:]]
            joint_angles = self.chain.inverse_kinematics(target_position)[1:]
            joint_state_msg = JointState()
            joint_state_msg.header.stamp = self.get_clock().now().to_msg()
            joint_state_msg.name = joint_names
            joint_state_msg.position = joint_angles
            self.joint_pub.publish(joint_state_msg)

            self.get_logger().info(f'Joint names: {joint_names}')
            self.get_logger().info(f'Calculated angles: {joint_angles}')

        except Exception as e:
            self.get_logger().error(f'Error calculating inverse kinematics: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = InverseKinematicsNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

