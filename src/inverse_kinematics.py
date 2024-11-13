import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Point
from ikpy.chain import Chain
from ament_index_python.packages import get_package_share_directory
import numpy as np
import os


class CinematicaInversaNode(Node):
    def __init__(self):
        super().__init__('inverse_kinematics_node')

        urdf_path = os.path.join(
            get_package_share_directory('robotic_arm_cube_handling'),
            'urdf',
            'urdf_files.urdf'
        )
  
        if not os.path.exists(urdf_path):
            self.get_logger().error(f"Archivo URDF no encontrado en {urdf_path}")
            raise FileNotFoundError(f"Archivo URDF no encontrado en {urdf_path}")

        self.chain = Chain.from_urdf_file(urdf_path)

        self.create_subscription(
            Point,
            'target_position',
            self.calculate_ik_callback,
            10
        )

        self.joint_pub = self.create_publisher(JointState, 'joint_states', 10)

    def calculate_ik_callback(self, msg):
        target_position = np.array([msg.x, msg.y, msg.z])
        self.get_logger().info(f'Recibido objetivo: {target_position}')

        joint_angles = self.chain.inverse_kinematics(target_position)
        joint_angles = joint_angles[1:]

        joint_state_msg = JointState()
        joint_state_msg.name = [joint.name for joint in self.chain.links[1:]]
        joint_state_msg.position = joint_angles
        self.joint_pub.publish(joint_state_msg)

        self.get_logger().info(f'Ángulos calculados: {joint_state_msg.position}')
        self.get_logger().info(f'Juntas calculadas: {joint_state_msg.name}')

def main(args=None):
    rclpy.init(args=args)
    node = CinematicaInversaNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
