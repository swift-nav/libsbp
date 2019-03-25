set(libsbp_HEADERS
  "${PROJECT_SOURCE_DIR}/include/libsbp/acquisition.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/bootload.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/common.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/edc.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/ext_events.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/file_io.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/flash.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/gnss.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/imu.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/linux.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/logging.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/mag.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/navigation.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/ndb.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/observation.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/orientation.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/piksi.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/sbas.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/sbp.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/settings.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/ssr.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/system.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/tracking.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/user.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/vehicle.h"
  "${PROJECT_SOURCE_DIR}/include/libsbp/version.h"
  )

set(libsbp_SRCS
  edc.c
  sbp.c
  )

add_library(sbp ${libsbp_SRCS})

if(MSVC)
    separate_arguments(LIBSBP_COMPILER_OPTIONS WINDOWS_COMMAND ${LIBSBP_CFLAGS})
else()
    separate_arguments(LIBSBP_COMPILER_OPTIONS UNIX_COMMAND ${LIBSBP_CFLAGS})
endif()
target_compile_options(sbp PRIVATE ${LIBSBP_COMPILER_OPTIONS})

target_include_directories(sbp PUBLIC ${PROJECT_SOURCE_DIR}/include)
set_target_properties(sbp PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        C_STANDARD 99
        C_STANDARD_REQUIRED ON)

install(TARGETS sbp
        EXPORT sbp-export
        DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})
install(FILES ${libsbp_HEADERS} DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}/libsbp)

export(EXPORT sbp-export
        NAMESPACE LibSbp::
        FILE ${PROJECT_BINARY_DIR}/LibSbpImport.cmake)
