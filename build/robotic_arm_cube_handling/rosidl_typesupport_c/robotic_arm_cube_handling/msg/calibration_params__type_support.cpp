// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__struct.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__type_support.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace robotic_arm_cube_handling
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _CalibrationParams_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CalibrationParams_type_support_ids_t;

static const _CalibrationParams_type_support_ids_t _CalibrationParams_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CalibrationParams_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CalibrationParams_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CalibrationParams_type_support_symbol_names_t _CalibrationParams_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robotic_arm_cube_handling, msg, CalibrationParams)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robotic_arm_cube_handling, msg, CalibrationParams)),
  }
};

typedef struct _CalibrationParams_type_support_data_t
{
  void * data[2];
} _CalibrationParams_type_support_data_t;

static _CalibrationParams_type_support_data_t _CalibrationParams_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CalibrationParams_message_typesupport_map = {
  2,
  "robotic_arm_cube_handling",
  &_CalibrationParams_message_typesupport_ids.typesupport_identifier[0],
  &_CalibrationParams_message_typesupport_symbol_names.symbol_name[0],
  &_CalibrationParams_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CalibrationParams_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CalibrationParams_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_hash,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_description,
  &robotic_arm_cube_handling__msg__CalibrationParams__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace robotic_arm_cube_handling

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robotic_arm_cube_handling, msg, CalibrationParams)() {
  return &::robotic_arm_cube_handling::msg::rosidl_typesupport_c::CalibrationParams_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
