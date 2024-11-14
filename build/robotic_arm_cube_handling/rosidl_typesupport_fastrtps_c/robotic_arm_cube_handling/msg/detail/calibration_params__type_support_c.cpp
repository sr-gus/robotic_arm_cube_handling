// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice
#include "robotic_arm_cube_handling/msg/detail/calibration_params__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robotic_arm_cube_handling/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__struct.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _CalibrationParams__ros_msg_type = robotic_arm_cube_handling__msg__CalibrationParams;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
bool cdr_serialize_robotic_arm_cube_handling__msg__CalibrationParams(
  const robotic_arm_cube_handling__msg__CalibrationParams * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: lower_h
  {
    cdr << ros_message->lower_h;
  }

  // Field name: upper_h
  {
    cdr << ros_message->upper_h;
  }

  // Field name: lower_s
  {
    cdr << ros_message->lower_s;
  }

  // Field name: upper_s
  {
    cdr << ros_message->upper_s;
  }

  // Field name: lower_v
  {
    cdr << ros_message->lower_v;
  }

  // Field name: upper_v
  {
    cdr << ros_message->upper_v;
  }

  // Field name: canny_threshold1
  {
    cdr << ros_message->canny_threshold1;
  }

  // Field name: canny_threshold2
  {
    cdr << ros_message->canny_threshold2;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
bool cdr_deserialize_robotic_arm_cube_handling__msg__CalibrationParams(
  eprosima::fastcdr::Cdr & cdr,
  robotic_arm_cube_handling__msg__CalibrationParams * ros_message)
{
  // Field name: lower_h
  {
    cdr >> ros_message->lower_h;
  }

  // Field name: upper_h
  {
    cdr >> ros_message->upper_h;
  }

  // Field name: lower_s
  {
    cdr >> ros_message->lower_s;
  }

  // Field name: upper_s
  {
    cdr >> ros_message->upper_s;
  }

  // Field name: lower_v
  {
    cdr >> ros_message->lower_v;
  }

  // Field name: upper_v
  {
    cdr >> ros_message->upper_v;
  }

  // Field name: canny_threshold1
  {
    cdr >> ros_message->canny_threshold1;
  }

  // Field name: canny_threshold2
  {
    cdr >> ros_message->canny_threshold2;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
size_t get_serialized_size_robotic_arm_cube_handling__msg__CalibrationParams(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CalibrationParams__ros_msg_type * ros_message = static_cast<const _CalibrationParams__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: lower_h
  {
    size_t item_size = sizeof(ros_message->lower_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: upper_h
  {
    size_t item_size = sizeof(ros_message->upper_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: lower_s
  {
    size_t item_size = sizeof(ros_message->lower_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: upper_s
  {
    size_t item_size = sizeof(ros_message->upper_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: lower_v
  {
    size_t item_size = sizeof(ros_message->lower_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: upper_v
  {
    size_t item_size = sizeof(ros_message->upper_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: canny_threshold1
  {
    size_t item_size = sizeof(ros_message->canny_threshold1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: canny_threshold2
  {
    size_t item_size = sizeof(ros_message->canny_threshold2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
size_t max_serialized_size_robotic_arm_cube_handling__msg__CalibrationParams(
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

  // Field name: lower_h
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: upper_h
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: lower_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: upper_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: lower_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: upper_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: canny_threshold1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: canny_threshold2
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
    using DataType = robotic_arm_cube_handling__msg__CalibrationParams;
    is_plain =
      (
      offsetof(DataType, canny_threshold2) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
bool cdr_serialize_key_robotic_arm_cube_handling__msg__CalibrationParams(
  const robotic_arm_cube_handling__msg__CalibrationParams * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: lower_h
  {
    cdr << ros_message->lower_h;
  }

  // Field name: upper_h
  {
    cdr << ros_message->upper_h;
  }

  // Field name: lower_s
  {
    cdr << ros_message->lower_s;
  }

  // Field name: upper_s
  {
    cdr << ros_message->upper_s;
  }

  // Field name: lower_v
  {
    cdr << ros_message->lower_v;
  }

  // Field name: upper_v
  {
    cdr << ros_message->upper_v;
  }

  // Field name: canny_threshold1
  {
    cdr << ros_message->canny_threshold1;
  }

  // Field name: canny_threshold2
  {
    cdr << ros_message->canny_threshold2;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
size_t get_serialized_size_key_robotic_arm_cube_handling__msg__CalibrationParams(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CalibrationParams__ros_msg_type * ros_message = static_cast<const _CalibrationParams__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: lower_h
  {
    size_t item_size = sizeof(ros_message->lower_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: upper_h
  {
    size_t item_size = sizeof(ros_message->upper_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: lower_s
  {
    size_t item_size = sizeof(ros_message->lower_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: upper_s
  {
    size_t item_size = sizeof(ros_message->upper_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: lower_v
  {
    size_t item_size = sizeof(ros_message->lower_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: upper_v
  {
    size_t item_size = sizeof(ros_message->upper_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: canny_threshold1
  {
    size_t item_size = sizeof(ros_message->canny_threshold1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: canny_threshold2
  {
    size_t item_size = sizeof(ros_message->canny_threshold2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robotic_arm_cube_handling
size_t max_serialized_size_key_robotic_arm_cube_handling__msg__CalibrationParams(
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
  // Field name: lower_h
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: upper_h
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: lower_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: upper_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: lower_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: upper_v
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: canny_threshold1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: canny_threshold2
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
    using DataType = robotic_arm_cube_handling__msg__CalibrationParams;
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
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const robotic_arm_cube_handling__msg__CalibrationParams * ros_message = static_cast<const robotic_arm_cube_handling__msg__CalibrationParams *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_robotic_arm_cube_handling__msg__CalibrationParams(ros_message, cdr);
}

static bool _CalibrationParams__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  robotic_arm_cube_handling__msg__CalibrationParams * ros_message = static_cast<robotic_arm_cube_handling__msg__CalibrationParams *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_robotic_arm_cube_handling__msg__CalibrationParams(cdr, ros_message);
}

static uint32_t _CalibrationParams__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robotic_arm_cube_handling__msg__CalibrationParams(
      untyped_ros_message, 0));
}

static size_t _CalibrationParams__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robotic_arm_cube_handling__msg__CalibrationParams(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CalibrationParams = {
  "robotic_arm_cube_handling::msg",
  "CalibrationParams",
  _CalibrationParams__cdr_serialize,
  _CalibrationParams__cdr_deserialize,
  _CalibrationParams__get_serialized_size,
  _CalibrationParams__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CalibrationParams__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CalibrationParams,
  get_message_typesupport_handle_function,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_hash,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_description,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robotic_arm_cube_handling, msg, CalibrationParams)() {
  return &_CalibrationParams__type_support;
}

#if defined(__cplusplus)
}
#endif
