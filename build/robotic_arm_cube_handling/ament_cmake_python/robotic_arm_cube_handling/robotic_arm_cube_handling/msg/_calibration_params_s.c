// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robotic_arm_cube_handling:msg/CalibrationParams.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__struct.h"
#include "robotic_arm_cube_handling/msg/detail/calibration_params__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robotic_arm_cube_handling__msg__calibration_params__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[68];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("robotic_arm_cube_handling.msg._calibration_params.CalibrationParams", full_classname_dest, 67) == 0);
  }
  robotic_arm_cube_handling__msg__CalibrationParams * ros_message = _ros_message;
  {  // lower_h
    PyObject * field = PyObject_GetAttrString(_pymsg, "lower_h");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->lower_h = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // upper_h
    PyObject * field = PyObject_GetAttrString(_pymsg, "upper_h");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->upper_h = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // lower_s
    PyObject * field = PyObject_GetAttrString(_pymsg, "lower_s");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->lower_s = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // upper_s
    PyObject * field = PyObject_GetAttrString(_pymsg, "upper_s");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->upper_s = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // lower_v
    PyObject * field = PyObject_GetAttrString(_pymsg, "lower_v");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->lower_v = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // upper_v
    PyObject * field = PyObject_GetAttrString(_pymsg, "upper_v");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->upper_v = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // canny_threshold1
    PyObject * field = PyObject_GetAttrString(_pymsg, "canny_threshold1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->canny_threshold1 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // canny_threshold2
    PyObject * field = PyObject_GetAttrString(_pymsg, "canny_threshold2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->canny_threshold2 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robotic_arm_cube_handling__msg__calibration_params__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CalibrationParams */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robotic_arm_cube_handling.msg._calibration_params");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CalibrationParams");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robotic_arm_cube_handling__msg__CalibrationParams * ros_message = (robotic_arm_cube_handling__msg__CalibrationParams *)raw_ros_message;
  {  // lower_h
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->lower_h);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lower_h", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // upper_h
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->upper_h);
    {
      int rc = PyObject_SetAttrString(_pymessage, "upper_h", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lower_s
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->lower_s);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lower_s", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // upper_s
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->upper_s);
    {
      int rc = PyObject_SetAttrString(_pymessage, "upper_s", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lower_v
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->lower_v);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lower_v", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // upper_v
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->upper_v);
    {
      int rc = PyObject_SetAttrString(_pymessage, "upper_v", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // canny_threshold1
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->canny_threshold1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "canny_threshold1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // canny_threshold2
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->canny_threshold2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "canny_threshold2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
