// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robotic_arm_cube_handling/msg/calibration_params.h"


#ifndef ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__STRUCT_H_
#define ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/CalibrationParams in the package robotic_arm_cube_handling.
typedef struct robotic_arm_cube_handling__msg__CalibrationParams
{
  int32_t lower_h;
  int32_t upper_h;
  int32_t lower_s;
  int32_t upper_s;
  int32_t lower_v;
  int32_t upper_v;
  int32_t canny_threshold1;
  int32_t canny_threshold2;
} robotic_arm_cube_handling__msg__CalibrationParams;

// Struct for a sequence of robotic_arm_cube_handling__msg__CalibrationParams.
typedef struct robotic_arm_cube_handling__msg__CalibrationParams__Sequence
{
  robotic_arm_cube_handling__msg__CalibrationParams * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robotic_arm_cube_handling__msg__CalibrationParams__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOTIC_ARM_CUBE_HANDLING__MSG__DETAIL__CALIBRATION_PARAMS__STRUCT_H_
