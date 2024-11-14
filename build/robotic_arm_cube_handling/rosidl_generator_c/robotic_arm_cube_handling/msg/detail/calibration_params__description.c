// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice

#include "robotic_arm_cube_handling/msg/detail/calibration_params__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robotic_arm_cube_handling
const rosidl_type_hash_t *
robotic_arm_cube_handling__msg__CalibrationParams__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xef, 0xab, 0x1c, 0x65, 0xe3, 0xa2, 0xf2, 0xb8,
      0x89, 0x1d, 0xf6, 0x65, 0x50, 0x1d, 0xea, 0xcc,
      0x8a, 0x0b, 0x77, 0x34, 0x90, 0x76, 0x56, 0x6c,
      0xf3, 0x78, 0x15, 0xcd, 0x64, 0xf4, 0xbf, 0xb8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char robotic_arm_cube_handling__msg__CalibrationParams__TYPE_NAME[] = "robotic_arm_cube_handling/msg/CalibrationParams";

// Define type names, field names, and default values
static char robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__lower_h[] = "lower_h";
static char robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__upper_h[] = "upper_h";
static char robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__lower_s[] = "lower_s";
static char robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__upper_s[] = "upper_s";
static char robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__lower_v[] = "lower_v";
static char robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__upper_v[] = "upper_v";
static char robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__canny_threshold1[] = "canny_threshold1";
static char robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__canny_threshold2[] = "canny_threshold2";

static rosidl_runtime_c__type_description__Field robotic_arm_cube_handling__msg__CalibrationParams__FIELDS[] = {
  {
    {robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__lower_h, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__upper_h, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__lower_s, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__upper_s, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__lower_v, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__upper_v, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__canny_threshold1, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robotic_arm_cube_handling__msg__CalibrationParams__FIELD_NAME__canny_threshold2, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robotic_arm_cube_handling__msg__CalibrationParams__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robotic_arm_cube_handling__msg__CalibrationParams__TYPE_NAME, 47, 47},
      {robotic_arm_cube_handling__msg__CalibrationParams__FIELDS, 8, 8},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 lower_h\n"
  "int32 upper_h\n"
  "int32 lower_s\n"
  "int32 upper_s\n"
  "int32 lower_v\n"
  "int32 upper_v\n"
  "int32 canny_threshold1\n"
  "int32 canny_threshold2";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robotic_arm_cube_handling__msg__CalibrationParams__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robotic_arm_cube_handling__msg__CalibrationParams__TYPE_NAME, 47, 47},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 130, 130},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robotic_arm_cube_handling__msg__CalibrationParams__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robotic_arm_cube_handling__msg__CalibrationParams__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
