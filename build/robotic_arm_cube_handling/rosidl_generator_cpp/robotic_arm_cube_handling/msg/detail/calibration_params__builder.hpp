// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robotic_arm_cube_handling/msg/calibration_params.hpp"


#ifndef ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__BUILDER_HPP_
#define ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robotic_arm_cube_handling/msg/detail/calibration_params__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robotic_arm_cube_handling
{

namespace msg
{

namespace builder
{

class Init_CalibrationParams_canny_threshold2
{
public:
  explicit Init_CalibrationParams_canny_threshold2(::robotic_arm_cube_handling::msg::CalibrationParams & msg)
  : msg_(msg)
  {}
  ::robotic_arm_cube_handling::msg::CalibrationParams canny_threshold2(::robotic_arm_cube_handling::msg::CalibrationParams::_canny_threshold2_type arg)
  {
    msg_.canny_threshold2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robotic_arm_cube_handling::msg::CalibrationParams msg_;
};

class Init_CalibrationParams_canny_threshold1
{
public:
  explicit Init_CalibrationParams_canny_threshold1(::robotic_arm_cube_handling::msg::CalibrationParams & msg)
  : msg_(msg)
  {}
  Init_CalibrationParams_canny_threshold2 canny_threshold1(::robotic_arm_cube_handling::msg::CalibrationParams::_canny_threshold1_type arg)
  {
    msg_.canny_threshold1 = std::move(arg);
    return Init_CalibrationParams_canny_threshold2(msg_);
  }

private:
  ::robotic_arm_cube_handling::msg::CalibrationParams msg_;
};

class Init_CalibrationParams_upper_v
{
public:
  explicit Init_CalibrationParams_upper_v(::robotic_arm_cube_handling::msg::CalibrationParams & msg)
  : msg_(msg)
  {}
  Init_CalibrationParams_canny_threshold1 upper_v(::robotic_arm_cube_handling::msg::CalibrationParams::_upper_v_type arg)
  {
    msg_.upper_v = std::move(arg);
    return Init_CalibrationParams_canny_threshold1(msg_);
  }

private:
  ::robotic_arm_cube_handling::msg::CalibrationParams msg_;
};

class Init_CalibrationParams_lower_v
{
public:
  explicit Init_CalibrationParams_lower_v(::robotic_arm_cube_handling::msg::CalibrationParams & msg)
  : msg_(msg)
  {}
  Init_CalibrationParams_upper_v lower_v(::robotic_arm_cube_handling::msg::CalibrationParams::_lower_v_type arg)
  {
    msg_.lower_v = std::move(arg);
    return Init_CalibrationParams_upper_v(msg_);
  }

private:
  ::robotic_arm_cube_handling::msg::CalibrationParams msg_;
};

class Init_CalibrationParams_upper_s
{
public:
  explicit Init_CalibrationParams_upper_s(::robotic_arm_cube_handling::msg::CalibrationParams & msg)
  : msg_(msg)
  {}
  Init_CalibrationParams_lower_v upper_s(::robotic_arm_cube_handling::msg::CalibrationParams::_upper_s_type arg)
  {
    msg_.upper_s = std::move(arg);
    return Init_CalibrationParams_lower_v(msg_);
  }

private:
  ::robotic_arm_cube_handling::msg::CalibrationParams msg_;
};

class Init_CalibrationParams_lower_s
{
public:
  explicit Init_CalibrationParams_lower_s(::robotic_arm_cube_handling::msg::CalibrationParams & msg)
  : msg_(msg)
  {}
  Init_CalibrationParams_upper_s lower_s(::robotic_arm_cube_handling::msg::CalibrationParams::_lower_s_type arg)
  {
    msg_.lower_s = std::move(arg);
    return Init_CalibrationParams_upper_s(msg_);
  }

private:
  ::robotic_arm_cube_handling::msg::CalibrationParams msg_;
};

class Init_CalibrationParams_upper_h
{
public:
  explicit Init_CalibrationParams_upper_h(::robotic_arm_cube_handling::msg::CalibrationParams & msg)
  : msg_(msg)
  {}
  Init_CalibrationParams_lower_s upper_h(::robotic_arm_cube_handling::msg::CalibrationParams::_upper_h_type arg)
  {
    msg_.upper_h = std::move(arg);
    return Init_CalibrationParams_lower_s(msg_);
  }

private:
  ::robotic_arm_cube_handling::msg::CalibrationParams msg_;
};

class Init_CalibrationParams_lower_h
{
public:
  Init_CalibrationParams_lower_h()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalibrationParams_upper_h lower_h(::robotic_arm_cube_handling::msg::CalibrationParams::_lower_h_type arg)
  {
    msg_.lower_h = std::move(arg);
    return Init_CalibrationParams_upper_h(msg_);
  }

private:
  ::robotic_arm_cube_handling::msg::CalibrationParams msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robotic_arm_cube_handling::msg::CalibrationParams>()
{
  return robotic_arm_cube_handling::msg::builder::Init_CalibrationParams_lower_h();
}

}  // namespace robotic_arm_cube_handling

#endif  // ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__BUILDER_HPP_
