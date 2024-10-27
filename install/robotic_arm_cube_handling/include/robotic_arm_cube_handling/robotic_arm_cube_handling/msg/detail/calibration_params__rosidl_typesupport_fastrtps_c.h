// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice
#ifndef ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "robotic_arm_cube_handling/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
bool cdr_serialize_robotic_arm_cube_handling__msg__CalibrationParams(
  const robotic_arm_cube_handling__msg__CalibrationParams * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
bool cdr_deserialize_robotic_arm_cube_handling__msg__CalibrationParams(
  eprosima::fastcdr::Cdr &,
  robotic_arm_cube_handling__msg__CalibrationParams * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
size_t get_serialized_size_robotic_arm_cube_handling__msg__CalibrationParams(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
size_t max_serialized_size_robotic_arm_cube_handling__msg__CalibrationParams(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
bool cdr_serialize_key_robotic_arm_cube_handling__msg__CalibrationParams(
  const robotic_arm_cube_handling__msg__CalibrationParams * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
size_t get_serialized_size_key_robotic_arm_cube_handling__msg__CalibrationParams(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
size_t max_serialized_size_key_robotic_arm_cube_handling__msg__CalibrationParams(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robotic_arm_cube_handling, msg, CalibrationParams)();

#ifdef __cplusplus
}
#endif

#endif  // ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
