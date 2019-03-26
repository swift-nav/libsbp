if(TARGET rtcm)
  return()
endif()

set(SUBMOD_PATH "${PROJECT_SOURCE_DIR}/third_party/librtcm/c")
if(FINDRTCM_SUBMOD_PATH)
  set(SUBMOD_PATH ${FINDRTCM_SUBMOD_PATH})
endif()

if(EXISTS "${SUBMOD_PATH}/CMakeLists.txt")
  message(STATUS "Found rtcm source in ${SUBMOD_PATH}")
  add_subdirectory("${SUBMOD_PATH}")
  if(NOT TARGET rtcm)
    message(FATAL_ERROR "Including directory ${SUBMOD_PATH} did not generate target rtcm as expected")
  endif()
  return()
endif()

find_path(RTCM_INCLUDE_DIR librtcm/rtcm.h)

set(RTCM_LIB_NAMES ${RTCM_LIB_NAMES} rtcm librtcm)
find_library(RTCM_LIBRARY NAMES ${RTCM_LIB_NAMES})

include(${CMAKE_ROOT}/Modules/FindPackageHandleStandardArgs.cmake)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(rtcm DEFAULT_MSG RTCM_LIBRARY RTCM_INCLUDE_DIR)

if(RTCM_FOUND)
  add_library(rtcm UNKNOWN IMPORTED)
  set_target_properties(rtcm PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${RTCM_INCLUDE_DIRS}")

  set_property(TARGET rtcm APPEND PROPERTY
      IMPORTED_LOCATION "${RTCM_LIBRARY}")
endif()


