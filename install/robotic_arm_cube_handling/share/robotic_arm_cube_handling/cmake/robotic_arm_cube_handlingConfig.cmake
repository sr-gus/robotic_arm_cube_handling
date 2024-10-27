# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_robotic_arm_cube_handling_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED robotic_arm_cube_handling_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(robotic_arm_cube_handling_FOUND FALSE)
  elseif(NOT robotic_arm_cube_handling_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(robotic_arm_cube_handling_FOUND FALSE)
  endif()
  return()
endif()
set(_robotic_arm_cube_handling_CONFIG_INCLUDED TRUE)

# output package information
if(NOT robotic_arm_cube_handling_FIND_QUIETLY)
  message(STATUS "Found robotic_arm_cube_handling: 0.0.0 (${robotic_arm_cube_handling_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'robotic_arm_cube_handling' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT robotic_arm_cube_handling_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(robotic_arm_cube_handling_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "rosidl_cmake-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake;ament_cmake_export_targets-extras.cmake;rosidl_cmake_export_typesupport_targets-extras.cmake;ament_cmake_export_dependencies-extras.cmake;rosidl_cmake_export_typesupport_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${robotic_arm_cube_handling_DIR}/${_extra}")
endforeach()
