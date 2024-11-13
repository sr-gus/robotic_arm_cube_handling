import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32MultiArray
import pigpio

DEFAULT_COLOR = [255, 255, 0]

class LEDControllerNode(Node):
    def __init__(self):
        super().__init__('led_controller')

        self.pi = pigpio.pi()
        if not self.pi.connected:
            self.get_logger().error("No se pudo conectar a pigpio. Asegúrate de que el demonio pigpiod está en ejecución.")
            exit(1)

        self.pins = {'red': 23, 'green': 24, 'blue': 25}

        for color, pin in self.pins.items():
            self.pi.set_mode(pin, pigpio.OUTPUT)

        self.set_color(DEFAULT_COLOR)

        self.subscription = self.create_subscription(
            Int32MultiArray,
            'led_color',
            self.color_callback,
            10
        )

    def set_color(self, color):
        red_intensity, green_intensity, blue_intensity = color
        self.pi.set_PWM_dutycycle(self.pins['red'], red_intensity)
        self.pi.set_PWM_dutycycle(self.pins['green'], green_intensity)
        self.pi.set_PWM_dutycycle(self.pins['blue'], blue_intensity)

    def color_callback(self, msg):
        color = msg.data
        if len(color) == 3:
            self.set_color(color)
        else:
            self.get_logger().warn("Se requiere un arreglo de 3 valores para el color RGB")

    def destroy_node(self):
        super().destroy_node()
        for pin in self.pins.values():
            self.pi.set_PWM_dutycycle(pin, 0)
        self.pi.stop()

def main(args=None):
    rclpy.init(args=args)
    node = LEDControllerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
