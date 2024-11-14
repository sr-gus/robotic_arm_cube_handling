// generated from rosidl_generator_c/resource/rosidl_generator_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef ROBOTIC_ARM_CUBE_HANDLING__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
#define ROBOTIC_ARM_CUBE_HANDLING__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_C_EXPORT_robotic_arm_cube_handling __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_C_IMPORT_robotic_arm_cube_handling __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_C_EXPORT_robotic_arm_cube_handling __declspec(dllexport)
    #define ROSIDL_GENERATOR_C_IMPORT_robotic_arm_cube_handling __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_C_BUILDING_DLL_robotic_arm_cube_handling
    #define ROSIDL_GENERATOR_C_PUBLIC_robotic_arm_cube_handling ROSIDL_GENERATOR_C_EXPORT_robotic_arm_cube_handling
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_robotic_arm_cube_handling ROSIDL_GENERATOR_C_IMPORT_robotic_arm_cube_handling
  #endif
#else
  #define ROSIDL_GENERATOR_C_EXPORT_robotic_arm_cube_handling __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_C_IMPORT_robotic_arm_cube_handling
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_C_PUBLIC_robotic_arm_cube_handling __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_robotic_arm_cube_handling
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // ROBOTIC_ARM_CUBE_HANDLING__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
