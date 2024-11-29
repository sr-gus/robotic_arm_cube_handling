import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool
import time
import board
import busio
from adafruit_pca9685 import PCA9685
from adafruit_motor import servo

SERVO_SPEED = 55.0  # [deg/s]
SERVO_ANGLE_RATE = 1.0 / SERVO_SPEED
GRIPPER_SPEED = 90.0  # [deg/s]
GRIPPER_ANGLE_RATE = 1.0 / GRIPPER_SPEED
GRIPPER_OPEN_ANGLE = 60
GRIPPER_CLOSE_ANGLE = 0

class ServoControllerNode(Node):
    def __init__(self):
        super().__init__('servo_control')
        self.get_logger().info('Initializing servo control node...')

        # Inicializar controlador PCA9685
        self.i2c = busio.I2C(board.SCL, board.SDA)
        self.pca = PCA9685(self.i2c)
        self.pca.frequency = 50
        self.get_logger().info('PCA9685 initialized at 50 Hz.')

        # Inicializar servos
        self.servos = [servo.Servo(self.pca.channels[i]) for i in range(10, 15)]
        self.claw_servo = servo.Servo(self.pca.channels[15])

        # Crear suscripciones para los servos
        for i in range(5):
            self.create_subscription(Float32, f'/servo_{i+1}_angle', lambda msg, i=i: self.update_target_angle(i, msg), 10)
            self.get_logger().info(f'Subscribed to topic /servo_{i+1}_angle for controlling servo {i+1}.')

        # Crear suscripción para el gripper
        self.create_subscription(Bool, '/servo_gripper', self.toggle_claw, 10)
        self.get_logger().info('Subscribed to topic /servo_gripper for controlling the gripper.')

        # Inicializar posiciones actuales y metas
        self.current_angles = [0.0] * 6
        self.target_angles = [0.0] * 6

        self.initialize_servos()
        # Temporizador para mover los servos periódicamente
        self.create_timer(0.02, self.update_servo_positions)  # Actualizar cada 20 ms

    def initialize_servos(self):
        """Mueve todos los servos a una posición inicial definida."""
        initial_positions = [110.0, 90.0, 180.0, 90.0, 0.0]  # Posiciones iniciales en grados para los 5 servos
        claw_position = 60.0  # Posición inicial del gripper (abierto)

        for i, servo in enumerate(self.servos):
            self.target_angles[i] = initial_positions[i]
            self.get_logger().info(f'Servo {i + 1} moved to initial position {initial_positions[i]}°.')

        self.claw_servo.angle = claw_position
        self.current_angles[-1] = claw_position
        self.get_logger().info(f'Gripper moved to initial position {claw_position}°.')

    def update_target_angle(self, servo_id, msg):
        target_angle = msg.data
        if 0 <= target_angle <= 180:
            self.target_angles[servo_id] = target_angle
            self.get_logger().info(f'Servo {servo_id + 1}: Target angle updated to {target_angle}°.')

    def update_servo_positions(self):
        for i, servo in enumerate(self.servos):
            current_angle = self.current_angles[i]
            target_angle = self.target_angles[i]

            if abs(current_angle - target_angle) > 0.5:  # Tolerancia para detener el movimiento
                step = 1 if target_angle > current_angle else -1
                new_angle = current_angle + step
                servo.angle = new_angle
                self.current_angles[i] = new_angle
                self.get_logger().debug(f'Servo {i + 1}: Moving to {new_angle}°.')

    def toggle_claw(self, msg):
        target_angle = GRIPPER_OPEN_ANGLE if msg.data else GRIPPER_CLOSE_ANGLE
        current_angle = self.current_angles[5]

        self.get_logger().info(f'Gripper servo: Moving from {current_angle}° to {target_angle}°.')

        if abs(current_angle - target_angle) > 0.5:
            step = 1 if target_angle > current_angle else -1
            while current_angle != target_angle:
                current_angle += step
                self.claw_servo.angle = current_angle
                time.sleep(GRIPPER_ANGLE_RATE)
                self.current_angles[5] = current_angle
                self.get_logger().debug(f'Gripper at position: {current_angle}°.')

                if abs(current_angle - target_angle) < 1:
                    break


def main(args=None):
    rclpy.init(args=args)
    node = ServoControllerNode()
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
