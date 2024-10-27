// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robotic_arm_cube_handling/msg/calibration_params.hpp"


#ifndef ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__TRAITS_HPP_
#define ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robotic_arm_cube_handling/msg/detail/calibration_params__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robotic_arm_cube_handling
{

namespace msg
{

inline void to_flow_style_yaml(
  const CalibrationParams & msg,
  std::ostream & out)
{
  out << "{";
  // member: lower_h
  {
    out << "lower_h: ";
    rosidl_generator_traits::value_to_yaml(msg.lower_h, out);
    out << ", ";
  }

  // member: upper_h
  {
    out << "upper_h: ";
    rosidl_generator_traits::value_to_yaml(msg.upper_h, out);
    out << ", ";
  }

  // member: lower_s
  {
    out << "lower_s: ";
    rosidl_generator_traits::value_to_yaml(msg.lower_s, out);
    out << ", ";
  }

  // member: upper_s
  {
    out << "upper_s: ";
    rosidl_generator_traits::value_to_yaml(msg.upper_s, out);
    out << ", ";
  }

  // member: lower_v
  {
    out << "lower_v: ";
    rosidl_generator_traits::value_to_yaml(msg.lower_v, out);
    out << ", ";
  }

  // member: upper_v
  {
    out << "upper_v: ";
    rosidl_generator_traits::value_to_yaml(msg.upper_v, out);
    out << ", ";
  }

  // member: canny_threshold1
  {
    out << "canny_threshold1: ";
    rosidl_generator_traits::value_to_yaml(msg.canny_threshold1, out);
    out << ", ";
  }

  // member: canny_threshold2
  {
    out << "canny_threshold2: ";
    rosidl_generator_traits::value_to_yaml(msg.canny_threshold2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CalibrationParams & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: lower_h
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lower_h: ";
    rosidl_generator_traits::value_to_yaml(msg.lower_h, out);
    out << "\n";
  }

  // member: upper_h
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "upper_h: ";
    rosidl_generator_traits::value_to_yaml(msg.upper_h, out);
    out << "\n";
  }

  // member: lower_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lower_s: ";
    rosidl_generator_traits::value_to_yaml(msg.lower_s, out);
    out << "\n";
  }

  // member: upper_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "upper_s: ";
    rosidl_generator_traits::value_to_yaml(msg.upper_s, out);
    out << "\n";
  }

  // member: lower_v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lower_v: ";
    rosidl_generator_traits::value_to_yaml(msg.lower_v, out);
    out << "\n";
  }

  // member: upper_v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "upper_v: ";
    rosidl_generator_traits::value_to_yaml(msg.upper_v, out);
    out << "\n";
  }

  // member: canny_threshold1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "canny_threshold1: ";
    rosidl_generator_traits::value_to_yaml(msg.canny_threshold1, out);
    out << "\n";
  }

  // member: canny_threshold2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "canny_threshold2: ";
    rosidl_generator_traits::value_to_yaml(msg.canny_threshold2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CalibrationParams & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace robotic_arm_cube_handling

namespace rosidl_generator_traits
{

[[deprecated("use robotic_arm_cube_handling::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robotic_arm_cube_handling::msg::CalibrationParams & msg,
  std::ostream & out, size_t indentation = 0)
{
  robotic_arm_cube_handling::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robotic_arm_cube_handling::msg::to_yaml() instead")]]
inline std::string to_yaml(const robotic_arm_cube_handling::msg::CalibrationParams & msg)
{
  return robotic_arm_cube_handling::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robotic_arm_cube_handling::msg::CalibrationParams>()
{
  return "robotic_arm_cube_handling::msg::CalibrationParams";
}

template<>
inline const char * name<robotic_arm_cube_handling::msg::CalibrationParams>()
{
  return "robotic_arm_cube_handling/msg/CalibrationParams";
}

template<>
struct has_fixed_size<robotic_arm_cube_handling::msg::CalibrationParams>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robotic_arm_cube_handling::msg::CalibrationParams>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robotic_arm_cube_handling::msg::CalibrationParams>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__TRAITS_HPP_
