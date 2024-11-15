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
GRIPPER_SPEED = 60.0  # [deg/s]
GRIPPER_ANGLE_RATE = 1.0 / SERVO_SPEED
GRIPPER_OPEN_ANGLE = 60
GRIPPER_CLOSE_ANGLE = 0

class ServoControllerNode(Node):
    def __init__(self):
        super().__init__('servo_control')
        self.get_logger().info('Initializing servo control node...')

        self.i2c = busio.I2C(board.SCL, board.SDA)
        self.pca = PCA9685(self.i2c)
        self.pca.frequency = 50
        self.get_logger().info('PCA9685 initialized at 50 Hz.')

        self.servos = [servo.Servo(self.pca.channels[i]) for i in range(10, 15)]
        self.claw_servo = servo.Servo(self.pca.channels[15])

        for i in range(5):
            self.create_subscription(Float32, f'/servo_{i+1}_angle', lambda msg, i=i: self.move_servo(i, msg), 10)
            self.get_logger().info(f'Subscribed to topic /servo_{i+1}_angle for controlling servo {i+1}.')

        self.create_subscription(Bool, '/servo_gripper', self.toggle_claw, 10)
        self.get_logger().info('Subscribed to topic /servo_gripper for controlling the gripper.')

        self.current_angles = [0.0] * 6
        self.target_angles = [0.0] * 6
        self.get_logger().info('Initial angles set to 0 degrees.')

    def move_servo(self, servo_id, msg):
        target_angle = msg.data
        if 0 <= target_angle <= 180:
            current_angle = self.current_angles[servo_id]

            self.get_logger().info(f'Received command to move servo {servo_id + 1} from {current_angle}° to {target_angle}°.')

            step = 1 if target_angle > current_angle else -1

            if current_angle == target_angle:
                self.servos[servo_id].angle = current_angle
                self.get_logger().info(f'Servo {servo_id + 1} is already at the target position of {target_angle}°.')
            else:
                while current_angle != target_angle:
                    current_angle += step
                    self.servos[servo_id].angle = current_angle
                    time.sleep(SERVO_ANGLE_RATE)
                    self.current_angles[servo_id] = current_angle
                    self.get_logger().debug(f'Servo {servo_id + 1} at position: {current_angle}°')

                    if abs(current_angle - target_angle) < 1:
                        self.get_logger().info(f'Servo {servo_id + 1} reached the target angle of {target_angle}°.')
                        break

    def toggle_claw(self, msg):
        target_angle = 0
        servo_id = 5
        if msg.data:
            target_angle = GRIPPER_OPEN_ANGLE
            self.get_logger().info('Gripper servo: opening.')
        else:
            target_angle = GRIPPER_CLOSE_ANGLE
            self.get_logger().info('Gripper servo: closing.')
        current_angle = self.current_angles[servo_id]

        self.get_logger().info(f'Received command to move servo {servo_id + 1} from {current_angle}° to {target_angle}°.')

        step = 1 if target_angle > current_angle else -1

        if current_angle == target_angle:
            self.claw_servo.angle = current_angle
            self.get_logger().info(f'Servo {servo_id + 1} is already at the target position of {target_angle}°.')
        else:
            while current_angle != target_angle:
                current_angle += step
                self.claw_servo.angle = current_angle
                time.sleep(GRIPPER_ANGLE_RATE)
                self.current_angles[servo_id] = current_angle
                self.get_logger().debug(f'Servo {servo_id + 1} at position: {current_angle}°')

                if abs(current_angle - target_angle) < 1:
                    self.get_logger().info(f'Servo {servo_id + 1} reached the target angle of {target_angle}°.')
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
