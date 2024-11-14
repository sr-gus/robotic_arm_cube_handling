// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice

#ifndef ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "robotic_arm_cube_handling/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace robotic_arm_cube_handling
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
cdr_serialize(
  const robotic_arm_cube_handling::msg::CalibrationParams & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robotic_arm_cube_handling::msg::CalibrationParams & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
get_serialized_size(
  const robotic_arm_cube_handling::msg::CalibrationParams & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
max_serialized_size_CalibrationParams(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
cdr_serialize_key(
  const robotic_arm_cube_handling::msg::CalibrationParams & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
get_serialized_size_key(
  const robotic_arm_cube_handling::msg::CalibrationParams & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
max_serialized_size_key_CalibrationParams(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace robotic_arm_cube_handling

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robotic_arm_cube_handling, msg, CalibrationParams)();

#ifdef __cplusplus
}
#endif

#endif  // ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
