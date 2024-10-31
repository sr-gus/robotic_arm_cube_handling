import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, Bool
import time
import board
import busio
from adafruit_pca9685 import PCA9685
from adafruit_motor import servo

SERVO_SPEED = 45.0  # [deg/s]
SERVO_ANGLE_RATE = 1.0 / SERVO_SPEED
GRIPPER_OPEN_ANGLE = 90
GRIPPER_CLOSE_ANGLE = 0

class ServoControllerNode(Node):
    def __init__(self):
        super().__init__('servo_control')
        self.get_logger().info("Inicializando el nodo de control de servos...")

        self.i2c = busio.I2C(board.SCL, board.SDA)
        self.pca = PCA9685(self.i2c)
        self.pca.frequency = 50
        self.get_logger().info("PCA9685 inicializado a 50 Hz.")

        self.servos = [servo.Servo(self.pca.channels[i]) for i in range(5)]
        self.claw_servo = servo.Servo(self.pca.channels[5])

        for i in range(5):
            self.create_subscription(Float32, f'/servo_{i+1}_angle', lambda msg, i=i: self.move_servo(i, msg), 10)
            self.get_logger().info(f"Suscrito al tópico /servo_{i+1}_angle para el control del servo {i+1}.")

        self.create_subscription(Bool, '/servo_gripper', self.toggle_claw, 10)
        self.get_logger().info("Suscrito al tópico /servo_gripper para el control de la garra.")

        self.current_angles = [0.0] * 5
        self.target_angles = [0.0] * 5
        self.get_logger().info("Ángulos iniciales configurados en 0 grados.")

    def move_servo(self, servo_id, msg):
        target_angle = msg.data
        current_angle = self.current_angles[servo_id]

        self.get_logger().info(f"Recibido comando para mover el servo {servo_id + 1} de {current_angle}° a {target_angle}°.")

        step = 1 if target_angle > current_angle else -1

        if current_angle == target_angle:
            self.servos[servo_id].angle = current_angle
            self.get_logger().info(f"Servo {servo_id + 1} ya está en la posición objetivo de {target_angle}°.")
        else:
            while current_angle != target_angle:
                current_angle += step
                self.servos[servo_id].angle = current_angle
                time.sleep(SERVO_ANGLE_RATE)
                self.current_angles[servo_id] = current_angle
                self.get_logger().debug(f"Servo {servo_id + 1} en posición: {current_angle}°")

                if abs(current_angle - target_angle) < 1:
                    self.get_logger().info(f"Servo {servo_id + 1} alcanzó el ángulo objetivo de {target_angle}°.")
                    break

    def toggle_claw(self, msg):
        if msg.data:
            self.claw_servo.angle = GRIPPER_OPEN_ANGLE
            self.get_logger().info("Servo de garra: abriendo.")
        else:
            self.claw_servo.angle = GRIPPER_CLOSE_ANGLE
            self.get_logger().info("Servo de garra: cerrando.")

def main(args=None):
    rclpy.init(args=args)
    servo_controller = ServoControllerNode()
    rclpy.spin(servo_controller)
    servo_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
