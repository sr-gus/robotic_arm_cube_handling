// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robotic_arm_cube_handling/msg/detail/calibration_params__rosidl_typesupport_introspection_c.h"
#include "robotic_arm_cube_handling/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__functions.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robotic_arm_cube_handling__msg__CalibrationParams__init(message_memory);
}

void robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_fini_function(void * message_memory)
{
  robotic_arm_cube_handling__msg__CalibrationParams__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_message_member_array[8] = {
  {
    "lower_h",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robotic_arm_cube_handling__msg__CalibrationParams, lower_h),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "upper_h",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robotic_arm_cube_handling__msg__CalibrationParams, upper_h),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lower_s",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robotic_arm_cube_handling__msg__CalibrationParams, lower_s),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "upper_s",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robotic_arm_cube_handling__msg__CalibrationParams, upper_s),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lower_v",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robotic_arm_cube_handling__msg__CalibrationParams, lower_v),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "upper_v",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robotic_arm_cube_handling__msg__CalibrationParams, upper_v),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "canny_threshold1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robotic_arm_cube_handling__msg__CalibrationParams, canny_threshold1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "canny_threshold2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robotic_arm_cube_handling__msg__CalibrationParams, canny_threshold2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_message_members = {
  "robotic_arm_cube_handling__msg",  // message namespace
  "CalibrationParams",  // message name
  8,  // number of fields
  sizeof(robotic_arm_cube_handling__msg__CalibrationParams),
  false,  // has_any_key_member_
  robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_message_member_array,  // message members
  robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_init_function,  // function to initialize message memory (memory has to be allocated)
  robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_message_type_support_handle = {
  0,
  &robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_message_members,
  get_message_typesupport_handle_function,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_hash,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_description,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robotic_arm_cube_handling
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robotic_arm_cube_handling, msg, CalibrationParams)() {
  if (!robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_message_type_support_handle.typesupport_identifier) {
    robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robotic_arm_cube_handling__msg__CalibrationParams__rosidl_typesupport_introspection_c__CalibrationParams_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
