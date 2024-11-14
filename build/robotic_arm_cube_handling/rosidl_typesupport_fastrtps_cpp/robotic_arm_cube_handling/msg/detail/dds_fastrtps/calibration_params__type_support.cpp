// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice
#include "robotic_arm_cube_handling/msg/detail/calibration_params__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__functions.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: lower_h
  cdr << ros_message.lower_h;

  // Member: upper_h
  cdr << ros_message.upper_h;

  // Member: lower_s
  cdr << ros_message.lower_s;

  // Member: upper_s
  cdr << ros_message.upper_s;

  // Member: lower_v
  cdr << ros_message.lower_v;

  // Member: upper_v
  cdr << ros_message.upper_v;

  // Member: canny_threshold1
  cdr << ros_message.canny_threshold1;

  // Member: canny_threshold2
  cdr << ros_message.canny_threshold2;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robotic_arm_cube_handling::msg::CalibrationParams & ros_message)
{
  // Member: lower_h
  cdr >> ros_message.lower_h;

  // Member: upper_h
  cdr >> ros_message.upper_h;

  // Member: lower_s
  cdr >> ros_message.lower_s;

  // Member: upper_s
  cdr >> ros_message.upper_s;

  // Member: lower_v
  cdr >> ros_message.lower_v;

  // Member: upper_v
  cdr >> ros_message.upper_v;

  // Member: canny_threshold1
  cdr >> ros_message.canny_threshold1;

  // Member: canny_threshold2
  cdr >> ros_message.canny_threshold2;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
get_serialized_size(
  const robotic_arm_cube_handling::msg::CalibrationParams & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: lower_h
  {
    size_t item_size = sizeof(ros_message.lower_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: upper_h
  {
    size_t item_size = sizeof(ros_message.upper_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: lower_s
  {
    size_t item_size = sizeof(ros_message.lower_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: upper_s
  {
    size_t item_size = sizeof(ros_message.upper_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: lower_v
  {
    size_t item_size = sizeof(ros_message.lower_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: upper_v
  {
    size_t item_size = sizeof(ros_message.upper_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: canny_threshold1
  {
    size_t item_size = sizeof(ros_message.canny_threshold1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: canny_threshold2
  {
    size_t item_size = sizeof(ros_message.canny_threshold2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
max_serialized_size_CalibrationParams(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: lower_h
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: upper_h
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: lower_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: upper_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: lower_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: upper_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: canny_threshold1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: canny_threshold2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robotic_arm_cube_handling::msg::CalibrationParams;
    is_plain =
      (
      offsetof(DataType, canny_threshold2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
cdr_serialize_key(
  const robotic_arm_cube_handling::msg::CalibrationParams & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: lower_h
  cdr << ros_message.lower_h;

  // Member: upper_h
  cdr << ros_message.upper_h;

  // Member: lower_s
  cdr << ros_message.lower_s;

  // Member: upper_s
  cdr << ros_message.upper_s;

  // Member: lower_v
  cdr << ros_message.lower_v;

  // Member: upper_v
  cdr << ros_message.upper_v;

  // Member: canny_threshold1
  cdr << ros_message.canny_threshold1;

  // Member: canny_threshold2
  cdr << ros_message.canny_threshold2;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
get_serialized_size_key(
  const robotic_arm_cube_handling::msg::CalibrationParams & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: lower_h
  {
    size_t item_size = sizeof(ros_message.lower_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: upper_h
  {
    size_t item_size = sizeof(ros_message.upper_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: lower_s
  {
    size_t item_size = sizeof(ros_message.lower_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: upper_s
  {
    size_t item_size = sizeof(ros_message.upper_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: lower_v
  {
    size_t item_size = sizeof(ros_message.lower_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: upper_v
  {
    size_t item_size = sizeof(ros_message.upper_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: canny_threshold1
  {
    size_t item_size = sizeof(ros_message.canny_threshold1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: canny_threshold2
  {
    size_t item_size = sizeof(ros_message.canny_threshold2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robotic_arm_cube_handling
max_serialized_size_key_CalibrationParams(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: lower_h
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: upper_h
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: lower_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: upper_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: lower_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: upper_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: canny_threshold1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: canny_threshold2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robotic_arm_cube_handling::msg::CalibrationParams;
    is_plain =
      (
      offsetof(DataType, canny_threshold2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _CalibrationParams__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robotic_arm_cube_handling::msg::CalibrationParams *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _CalibrationParams__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robotic_arm_cube_handling::msg::CalibrationParams *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _CalibrationParams__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robotic_arm_cube_handling::msg::CalibrationParams *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _CalibrationParams__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_CalibrationParams(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _CalibrationParams__callbacks = {
  "robotic_arm_cube_handling::msg",
  "CalibrationParams",
  _CalibrationParams__cdr_serialize,
  _CalibrationParams__cdr_deserialize,
  _CalibrationParams__get_serialized_size,
  _CalibrationParams__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CalibrationParams__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_CalibrationParams__callbacks,
  get_message_typesupport_handle_function,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_hash,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_description,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace robotic_arm_cube_handling

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robotic_arm_cube_handling
const rosidl_message_type_support_t *
get_message_type_support_handle<robotic_arm_cube_handling::msg::CalibrationParams>()
{
  return &robotic_arm_cube_handling::msg::typesupport_fastrtps_cpp::_CalibrationParams__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robotic_arm_cube_handling, msg, CalibrationParams)() {
  return &robotic_arm_cube_handling::msg::typesupport_fastrtps_cpp::_CalibrationParams__handle;
}

#ifdef __cplusplus
}
#endif
