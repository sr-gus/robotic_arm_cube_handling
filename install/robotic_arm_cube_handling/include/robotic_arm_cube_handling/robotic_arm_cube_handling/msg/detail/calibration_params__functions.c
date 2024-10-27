// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice
#include "robotic_arm_cube_handling/msg/detail/calibration_params__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robotic_arm_cube_handling__msg__CalibrationParams__init(robotic_arm_cube_handling__msg__CalibrationParams * msg)
{
  if (!msg) {
    return false;
  }
  // lower_h
  // upper_h
  // lower_s
  // upper_s
  // lower_v
  // upper_v
  // canny_threshold1
  // canny_threshold2
  return true;
}

void
robotic_arm_cube_handling__msg__CalibrationParams__fini(robotic_arm_cube_handling__msg__CalibrationParams * msg)
{
  if (!msg) {
    return;
  }
  // lower_h
  // upper_h
  // lower_s
  // upper_s
  // lower_v
  // upper_v
  // canny_threshold1
  // canny_threshold2
}

bool
robotic_arm_cube_handling__msg__CalibrationParams__are_equal(const robotic_arm_cube_handling__msg__CalibrationParams * lhs, const robotic_arm_cube_handling__msg__CalibrationParams * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // lower_h
  if (lhs->lower_h != rhs->lower_h) {
    return false;
  }
  // upper_h
  if (lhs->upper_h != rhs->upper_h) {
    return false;
  }
  // lower_s
  if (lhs->lower_s != rhs->lower_s) {
    return false;
  }
  // upper_s
  if (lhs->upper_s != rhs->upper_s) {
    return false;
  }
  // lower_v
  if (lhs->lower_v != rhs->lower_v) {
    return false;
  }
  // upper_v
  if (lhs->upper_v != rhs->upper_v) {
    return false;
  }
  // canny_threshold1
  if (lhs->canny_threshold1 != rhs->canny_threshold1) {
    return false;
  }
  // canny_threshold2
  if (lhs->canny_threshold2 != rhs->canny_threshold2) {
    return false;
  }
  return true;
}

bool
robotic_arm_cube_handling__msg__CalibrationParams__copy(
  const robotic_arm_cube_handling__msg__CalibrationParams * input,
  robotic_arm_cube_handling__msg__CalibrationParams * output)
{
  if (!input || !output) {
    return false;
  }
  // lower_h
  output->lower_h = input->lower_h;
  // upper_h
  output->upper_h = input->upper_h;
  // lower_s
  output->lower_s = input->lower_s;
  // upper_s
  output->upper_s = input->upper_s;
  // lower_v
  output->lower_v = input->lower_v;
  // upper_v
  output->upper_v = input->upper_v;
  // canny_threshold1
  output->canny_threshold1 = input->canny_threshold1;
  // canny_threshold2
  output->canny_threshold2 = input->canny_threshold2;
  return true;
}

robotic_arm_cube_handling__msg__CalibrationParams *
robotic_arm_cube_handling__msg__CalibrationParams__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robotic_arm_cube_handling__msg__CalibrationParams * msg = (robotic_arm_cube_handling__msg__CalibrationParams *)allocator.allocate(sizeof(robotic_arm_cube_handling__msg__CalibrationParams), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robotic_arm_cube_handling__msg__CalibrationParams));
  bool success = robotic_arm_cube_handling__msg__CalibrationParams__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robotic_arm_cube_handling__msg__CalibrationParams__destroy(robotic_arm_cube_handling__msg__CalibrationParams * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robotic_arm_cube_handling__msg__CalibrationParams__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robotic_arm_cube_handling__msg__CalibrationParams__Sequence__init(robotic_arm_cube_handling__msg__CalibrationParams__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robotic_arm_cube_handling__msg__CalibrationParams * data = NULL;

  if (size) {
    data = (robotic_arm_cube_handling__msg__CalibrationParams *)allocator.zero_allocate(size, sizeof(robotic_arm_cube_handling__msg__CalibrationParams), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robotic_arm_cube_handling__msg__CalibrationParams__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robotic_arm_cube_handling__msg__CalibrationParams__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robotic_arm_cube_handling__msg__CalibrationParams__Sequence__fini(robotic_arm_cube_handling__msg__CalibrationParams__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robotic_arm_cube_handling__msg__CalibrationParams__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robotic_arm_cube_handling__msg__CalibrationParams__Sequence *
robotic_arm_cube_handling__msg__CalibrationParams__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robotic_arm_cube_handling__msg__CalibrationParams__Sequence * array = (robotic_arm_cube_handling__msg__CalibrationParams__Sequence *)allocator.allocate(sizeof(robotic_arm_cube_handling__msg__CalibrationParams__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robotic_arm_cube_handling__msg__CalibrationParams__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robotic_arm_cube_handling__msg__CalibrationParams__Sequence__destroy(robotic_arm_cube_handling__msg__CalibrationParams__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robotic_arm_cube_handling__msg__CalibrationParams__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robotic_arm_cube_handling__msg__CalibrationParams__Sequence__are_equal(const robotic_arm_cube_handling__msg__CalibrationParams__Sequence * lhs, const robotic_arm_cube_handling__msg__CalibrationParams__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robotic_arm_cube_handling__msg__CalibrationParams__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robotic_arm_cube_handling__msg__CalibrationParams__Sequence__copy(
  const robotic_arm_cube_handling__msg__CalibrationParams__Sequence * input,
  robotic_arm_cube_handling__msg__CalibrationParams__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robotic_arm_cube_handling__msg__CalibrationParams);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robotic_arm_cube_handling__msg__CalibrationParams * data =
      (robotic_arm_cube_handling__msg__CalibrationParams *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robotic_arm_cube_handling__msg__CalibrationParams__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robotic_arm_cube_handling__msg__CalibrationParams__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robotic_arm_cube_handling__msg__CalibrationParams__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
