cmake_minimum_required(VERSION 3.8)

project(robotic_arm_cube_handling)

find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
    "msg/CalibrationParams.msg"
)

ament_export_dependencies(rosidl_default_runtime)

install(
    DIRECTORY src/
    DESTINATION lib/${PROJECT_NAME}
)

install(
    DIRECTORY launch config urdf rviz
    DESTINATION share/${PROJECT_NAME}
)

ament_package()
