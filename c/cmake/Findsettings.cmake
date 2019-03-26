if(TARGET settings)
  return()
endif()

set(SUBMOD_PATH "${PROJECT_SOURCE_DIR}/third_party/libsettings")
if(FINDSETTINGS_SUBMOD_PATH)
  set(SUBMOD_PATH ${FINDSETTINGS_SUBMOD_PATH})
endif()

if(EXISTS "${SUBMOD_PATH}/CMakeLists.txt")
  message(STATUS "Found settings source in ${SUBMOD_PATH}")
  add_subdirectory("${SUBMOD_PATH}")
  if(NOT TARGET settings)
    message(FATAL_ERROR "Including directory ${SUBMOD_PATH} did not generate target settings as expected")
  endif()
  return()
endif()

find_path(SETTINGS_INCLUDE_DIR libsettings/settings.h)

set(SETTINGS_LIB_NAMES ${SETTINGS_LIB_NAMES} settings libsettings)
find_library(SETTINGS_LIBRARY NAMES ${SETTINGS_LIB_NAMES})

include(${CMAKE_ROOT}/Modules/FindPackageHandleStandardArgs.cmake)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(settings DEFAULT_MSG SETTINGS_LIBRARY SETTINGS_INCLUDE_DIR)

if(SETTINGS_FOUND)
  add_library(settings UNKNOWN IMPORTED)
  set_target_properties(settings PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${SETTINGS_INCLUDE_DIRS}")

  set_property(TARGET settings APPEND PROPERTY
      IMPORTED_LOCATION "${SETTINGS_LIBRARY}")
endif()


