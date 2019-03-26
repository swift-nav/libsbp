if(TARGET gtest)
  return()
endif()

set(SUBMOD_PATH "${PROJECT_SOURCE_DIR}/third_party/googletest/googletest")
if(FINDGTEST_SUBMOD_PATH)
  set(SUBMOD_PATH ${FINDGTEST_SUBMOD_PATH})
endif()

if(EXISTS "${SUBMOD_PATH}/CMakeLists.txt")
  message(STATUS "Found googletest source in ${SUBMOD_PATH}")
  add_subdirectory("${SUBMOD_PATH}")
  if(NOT TARGET googletest)
    message(FATAL_ERROR "Including directory ${SUBMOD_PATH} did not generate target googletest as expected")
  endif()
  return()
endif()


