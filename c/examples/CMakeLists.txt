option(BUILD_EXAMPLES "" OFF)

if(BUILD_EXAMPLES)
  add_custom_target(examples)
  add_subdirectory(legacy)
  add_subdirectory(v4)
endif()
