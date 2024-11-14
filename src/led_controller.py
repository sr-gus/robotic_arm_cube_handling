import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32MultiArray
import pigpio

DEFAULT_COLOR = [255, 255, 0]

class LEDControllerNode(Node):
    def __init__(self):
        super().__init__('led_controller')

        try:
            self.pi = pigpio.pi()
            if not self.pi.connected:
                raise RuntimeError('No se pudo conectar a pigpio. Asegúrate de que el demonio pigpiod está en ejecución.')
        except Exception as e:
            self.get_logger().error(f'Error al conectar a pigpio: {e}')
            rclpy.shutdown()
            return

        self.pins = {'red': 24, 'green': 23, 'blue': 25}
        try:
            for color, pin in self.pins.items():
                self.pi.set_mode(pin, pigpio.OUTPUT)
        except Exception as e:
            self.get_logger().error(f'Error al configurar los pines: {e}')
            self.cleanup()
            rclpy.shutdown()
            return

        try:
            self.set_color(DEFAULT_COLOR)
        except ValueError as e:
            self.get_logger().error(f'Color inicial no válido: {e}')
            self.cleanup()
            rclpy.shutdown()
            return

        self.subscription = self.create_subscription(
            Int32MultiArray,
            'led_color',
            self.color_callback,
            10
        )

    def set_color(self, color):
        try:
            if not all(0 <= intensity <= 255 for intensity in color):
                raise ValueError('Los valores RGB deben estar entre 0 y 255.')
            
            red_intensity, green_intensity, blue_intensity = color
            self.pi.set_PWM_dutycycle(self.pins['red'], red_intensity)
            self.pi.set_PWM_dutycycle(self.pins['green'], green_intensity)
            self.pi.set_PWM_dutycycle(self.pins['blue'], blue_intensity)
        except Exception as e:
            self.get_logger().error(f'Error al establecer el color: {e}')

    def color_callback(self, msg):
        color = msg.data
        if len(color) == 3:
            try:
                self.set_color(color)
            except ValueError as e:
                self.get_logger().warn(f'Valores RGB no válidos: {e}')
        else:
            self.get_logger().warn('Se requiere un arreglo de 3 valores para el color RGB')

    def destroy_node(self):
        self.cleanup()
        super().destroy_node()

    def cleanup(self):
        for pin in self.pins.values():
            try:
                self.pi.set_PWM_dutycycle(pin, 0)
            except Exception as e:
                self.get_logger().warn(f'Error al apagar el pin {pin}: {e}')
        try:
            self.pi.stop()
        except Exception as e:
            self.get_logger().warn(f'Error al detener pigpio: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = LEDControllerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        node.get_logger().error(f'Error inesperado: {e}')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()