option(BUILD_EXAMPLES "" OFF)

if(BUILD_EXAMPLES)
  add_custom_target(examples)

  foreach(target example cpp_example tcp_example tcp_2sigma_example)
    add_subdirectory(${target})
    add_dependencies(examples libsbp_${target})
  endforeach()
endif()
