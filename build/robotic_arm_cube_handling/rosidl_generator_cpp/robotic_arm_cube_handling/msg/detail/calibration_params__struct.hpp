// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robotic_arm_cube_handling/msg/calibration_params.hpp"


#ifndef ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__STRUCT_HPP_
#define ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robotic_arm_cube_handling__msg__CalibrationParams __attribute__((deprecated))
#else
# define DEPRECATED__robotic_arm_cube_handling__msg__CalibrationParams __declspec(deprecated)
#endif

namespace robotic_arm_cube_handling
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CalibrationParams_
{
  using Type = CalibrationParams_<ContainerAllocator>;

  explicit CalibrationParams_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lower_h = 0l;
      this->upper_h = 0l;
      this->lower_s = 0l;
      this->upper_s = 0l;
      this->lower_v = 0l;
      this->upper_v = 0l;
      this->canny_threshold1 = 0l;
      this->canny_threshold2 = 0l;
    }
  }

  explicit CalibrationParams_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lower_h = 0l;
      this->upper_h = 0l;
      this->lower_s = 0l;
      this->upper_s = 0l;
      this->lower_v = 0l;
      this->upper_v = 0l;
      this->canny_threshold1 = 0l;
      this->canny_threshold2 = 0l;
    }
  }

  // field types and members
  using _lower_h_type =
    int32_t;
  _lower_h_type lower_h;
  using _upper_h_type =
    int32_t;
  _upper_h_type upper_h;
  using _lower_s_type =
    int32_t;
  _lower_s_type lower_s;
  using _upper_s_type =
    int32_t;
  _upper_s_type upper_s;
  using _lower_v_type =
    int32_t;
  _lower_v_type lower_v;
  using _upper_v_type =
    int32_t;
  _upper_v_type upper_v;
  using _canny_threshold1_type =
    int32_t;
  _canny_threshold1_type canny_threshold1;
  using _canny_threshold2_type =
    int32_t;
  _canny_threshold2_type canny_threshold2;

  // setters for named parameter idiom
  Type & set__lower_h(
    const int32_t & _arg)
  {
    this->lower_h = _arg;
    return *this;
  }
  Type & set__upper_h(
    const int32_t & _arg)
  {
    this->upper_h = _arg;
    return *this;
  }
  Type & set__lower_s(
    const int32_t & _arg)
  {
    this->lower_s = _arg;
    return *this;
  }
  Type & set__upper_s(
    const int32_t & _arg)
  {
    this->upper_s = _arg;
    return *this;
  }
  Type & set__lower_v(
    const int32_t & _arg)
  {
    this->lower_v = _arg;
    return *this;
  }
  Type & set__upper_v(
    const int32_t & _arg)
  {
    this->upper_v = _arg;
    return *this;
  }
  Type & set__canny_threshold1(
    const int32_t & _arg)
  {
    this->canny_threshold1 = _arg;
    return *this;
  }
  Type & set__canny_threshold2(
    const int32_t & _arg)
  {
    this->canny_threshold2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator> *;
  using ConstRawPtr =
    const robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robotic_arm_cube_handling__msg__CalibrationParams
    std::shared_ptr<robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robotic_arm_cube_handling__msg__CalibrationParams
    std::shared_ptr<robotic_arm_cube_handling::msg::CalibrationParams_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibrationParams_ & other) const
  {
    if (this->lower_h != other.lower_h) {
      return false;
    }
    if (this->upper_h != other.upper_h) {
      return false;
    }
    if (this->lower_s != other.lower_s) {
      return false;
    }
    if (this->upper_s != other.upper_s) {
      return false;
    }
    if (this->lower_v != other.lower_v) {
      return false;
    }
    if (this->upper_v != other.upper_v) {
      return false;
    }
    if (this->canny_threshold1 != other.canny_threshold1) {
      return false;
    }
    if (this->canny_threshold2 != other.canny_threshold2) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibrationParams_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibrationParams_

// alias to use template instance with default allocator
using CalibrationParams =
  robotic_arm_cube_handling::msg::CalibrationParams_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robotic_arm_cube_handling

#endif  // ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__STRUCT_HPP_
