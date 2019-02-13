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

if (NOT MSVC)
  set(LIBSBP_CFLAGS "-fpic" CACHE STRING "Compile flags for libsbp.")
endif (NOT MSVC)

add_library(sbp ${libsbp_SRCS})
target_compile_options(sbp PRIVATE "${LIBSBP_CFLAGS}")
target_include_directories(sbp PUBLIC "${PROJECT_SOURCE_DIR}/include")
install(TARGETS sbp DESTINATION lib${LIB_SUFFIX})
install(FILES ${libsbp_HEADERS} DESTINATION include/libsbp)
