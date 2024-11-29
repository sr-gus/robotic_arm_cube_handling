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

        self.is_moving = False
        self.resting_position = [60.0, 155.0, 0.0, 90.0, 0.0]
        self.stop_position    = [90.0, 90.0, 180.0, 90.0, 0.0]

    def joint_state_callback(self, msg):
        # Ignorar nuevas instrucciones si ya se está ejecutando un movimiento
        if self.is_moving:
            self.get_logger().info('Movement in progress, ignoring new joint_states.')
            return

        self.is_moving = True  # Bloquea nuevas instrucciones mientras este movimiento se ejecuta

        self.get_logger().info('Received joint_states, publishing angles to servos.')

        # Publicar ángulos transformados simultáneamente a todos los servos
        servo_msgs = []
        for i, angle in enumerate(msg.position[:5]):
            transformed_angle = self.apply_transformation(i, angle)
            servo_msg = Float32()
            servo_msg.data = transformed_angle
            self.servo_publishers[i].publish(servo_msg)  # Publicar directamente
            servo_msgs.append(transformed_angle)

        self.get_logger().info(f'Published angles {servo_msgs}° to all servos simultaneously.')

        time.sleep(3)  # Simula el tiempo necesario para que el brazo se mueva

        # Abrir el gripper
        self.toggle_gripper(False)
        time.sleep(2)
        self.get_logger().info('Gripper opened.')

        # Regresar a la posición de reposo
        self.move_to_resting_position()
        time.sleep(2)

        # Cerrar el gripper
        self.toggle_gripper(True)
        time.sleep(2)
        self.get_logger().info('Gripper closed.')

        self.move_to_stop_position()
        time.sleep(2)

        self.is_moving = False  # Libera el bloqueo al finalizar el movimiento

    def apply_transformation(self, joint_index, angle, radians = True):
        transformed_angle = angle
        if radians:
            transformed_angle = angle * 180 / 3.14159

        if joint_index == 0:
            transformed_angle += 20
            if transformed_angle < 0.0:
                transformed_angle += 90.0
            if transformed_angle < 45.0:
                transformed_angle = 45.0
            if transformed_angle > 145.0:
                transformed_angle = 145.0

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
            transformed_angle = self.apply_transformation(i, angle, False)
            servo_msg = Float32()
            servo_msg.data = transformed_angle
            self.servo_publishers[i].publish(servo_msg)
            time.sleep(1.5)

    def move_to_stop_position(self):
        self.get_logger().info('Moving arm to stop position.')

        for i, angle in enumerate(self.stop_position):
            transformed_angle = self.apply_transformation(i, angle, False)
            servo_msg = Float32()
            servo_msg.data = transformed_angle
            self.servo_publishers[i].publish(servo_msg)
            time.sleep(1)

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
