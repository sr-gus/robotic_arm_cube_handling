from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robotic_arm_cube_handling',
            executable='camera_node',
            name='camera_node',
            output='screen'
        ),
        Node(
            package='robotic_arm_cube_handling',
            executable='image_processing_node',
            name='image_processing_node',
            output='screen'
        ),
        Node(
            package='robotic_arm_cube_handling',
            executable='calibration_node',
            name='calibration_node',
            output='screen'
        )
    ])
