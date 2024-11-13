from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robotic_arm_cube_handling',
            executable='camera_node.py',
            name='camera_node',
            output='screen',
            prefix='python3'
        ),
        Node(
            package='robotic_arm_cube_handling',
            executable='image_processing_node.py',
            name='image_processing_node',
            output='screen',
            prefix='python3'
        ),
        Node(
            package='robotic_arm_cube_handling',
            executable='mqtt_publisher_node.py',
            name='mqtt_publisher_node',
            output='screen',
            prefix='python3'
        ),
        Node(
            package='robotic_arm_cube_handling',
            executable='servo_control_node.py',
            name='servo_control_node',
            output='screen',
            prefix='python3'
        ),
        Node(
            package='robotic_arm_cube_handling',
            executable='led_controller.py',
            name='led_controller',
            output='screen',
            prefix='python3'
        ),
         Node(
            package='robotic_arm_cube_handling',
            executable='inverse_kinematics.py',
            name='inverse_kinematics_node',
            output='screen',
               
        ),

    ])
