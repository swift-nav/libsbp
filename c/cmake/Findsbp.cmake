if(TARGET sbp)
  return()
endif()

set(SUBMOD_PATH "${PROJECT_SOURCE_DIR}/third_party/libsbp/c")
if(FINDSBP_SUBMOD_PATH)
  set(SUBMOD_PATH ${FINDSBP_SUBMOD_PATH})
endif()

if(EXISTS "${SUBMOD_PATH}/CMakeLists.txt")
  message(STATUS "Found sbp source in ${SUBMOD_PATH}")
  add_subdirectory("${SUBMOD_PATH}")
  if(NOT TARGET sbp)
    message(FATAL_ERROR "Including directory ${SUBMOD_PATH} did not generate target sbp as expected")
  endif()
  return()
endif()

find_path(SBP_INCLUDE_DIR libsbp/sbp.h)

set(SBP_LIB_NAMES ${SBP_LIB_NAMES} sbp libsbp)
find_library(SBP_LIBRARY NAMES ${SBP_LIB_NAMES})

include(${CMAKE_ROOT}/Modules/FindPackageHandleStandardArgs.cmake)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(sbp DEFAULT_MSG SBP_LIBRARY SBP_INCLUDE_DIR)

if(SBP_FOUND)
  add_library(sbp UNKNOWN IMPORTED)
  set_target_properties(sbp PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${SBP_INCLUDE_DIRS}")

  set_property(TARGET sbp APPEND PROPERTY
      IMPORTED_LOCATION "${SBP_LIBRARY}")
endif()


