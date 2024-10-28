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
            executable='calibration_node.py',
            name='calibration_node',
            output='screen',
            prefix='python3'
        )
    ])
