if(TARGET swiftnav)
  return()
endif()

set(SUBMOD_PATH "${PROJECT_SOURCE_DIR}/third_party/libswiftnav")
if(FINDSWIFTNAV_SUBMOD_PATH)
  set(SUBMOD_PATH ${FINDSWIFTNAV_SUBMOD_PATH})
endif()

if(EXISTS "${SUBMOD_PATH}/CMakeLists.txt")
  message(STATUS "Found swiftnav source in ${SUBMOD_PATH}")
  add_subdirectory("${SUBMOD_PATH}")
  if(NOT TARGET swiftnav)
    message(FATAL_ERROR "Including directory ${SUBMOD_PATH} did not generate target swiftnav as expected")
  endif()
  return()
endif()

find_path(SWIFTNAV_INCLUDE_DIR swiftnav/common.h)

set(SWIFTNAV_LIB_NAMES ${SWIFTNAV_LIB_NAMES} swiftnav libswiftnav)
find_library(SWIFTNAV_LIBRARY NAMES ${SWIFTNAV_LIB_NAMES})

include(${CMAKE_ROOT}/Modules/FindPackageHandleStandardArgs.cmake)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(swiftnav DEFAULT_MSG SWIFTNAV_LIBRARY SWIFTNAV_INCLUDE_DIR)

if(SWIFTNAV_FOUND)
  add_library(swiftnav UNKNOWN IMPORTED)
  set_target_properties(swiftnav PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${SWIFTNAV_INCLUDE_DIRS}")

  set_property(TARGET swiftnav APPEND PROPERTY
      IMPORTED_LOCATION "${SWIFTNAV_LIBRARY}")
endif()


