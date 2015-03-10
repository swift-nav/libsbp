if (NOT DEFINED BUILD_SHARED_LIBS)
  set(BUILD_SHARED_LIBS ON)
endif (NOT DEFINED BUILD_SHARED_LIBS)

file(GLOB libswiftnav_HEADERS "${PROJECT_SOURCE_DIR}/include/libswiftnav/*.h")

include_directories("${PROJECT_SOURCE_DIR}/CBLAS/include")
include_directories("${PROJECT_SOURCE_DIR}/clapack-3.2.1-CMAKE/INCLUDE")
include_directories("${PROJECT_SOURCE_DIR}/lapacke/include")

include_directories("${PROJECT_SOURCE_DIR}/include/libsbp")

set(libsbp_SRCS
  edc.c
  sbp.c
  sbp_utils.c
)

add_library(swiftnav-static STATIC ${libsbp_SRCS})
install(TARGETS swiftnav-static DESTINATION lib${LIB_SUFFIX})

if(BUILD_SHARED_LIBS)
  add_library(swiftnav SHARED ${libsbp_SRCS})
  install(TARGETS swiftnav DESTINATION lib${LIB_SUFFIX})
else(BUILD_SHARED_LIBS)
  message(STATUS "Not building shared libraries")
endif(BUILD_SHARED_LIBS)

install(FILES ${libsbp_HEADERS} DESTINATION include/libsbp)
