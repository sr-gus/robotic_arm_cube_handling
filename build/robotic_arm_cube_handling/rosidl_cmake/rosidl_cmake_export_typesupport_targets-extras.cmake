# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:robotic_arm_cube_handling__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:robotic_arm_cube_handling__rosidl_typesupport_fastrtps_c;__rosidl_generator_cpp:robotic_arm_cube_handling__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:robotic_arm_cube_handling__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_c:robotic_arm_cube_handling__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:robotic_arm_cube_handling__rosidl_typesupport_c;__rosidl_typesupport_introspection_cpp:robotic_arm_cube_handling__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:robotic_arm_cube_handling__rosidl_typesupport_cpp;:robotic_arm_cube_handling__rosidl_generator_py")

# populate robotic_arm_cube_handling_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "robotic_arm_cube_handling::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'robotic_arm_cube_handling' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND robotic_arm_cube_handling_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
