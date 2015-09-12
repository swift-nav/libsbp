if (NOT DEFINED BUILD_SHARED_LIBS)
  set(BUILD_SHARED_LIBS ON)
endif (NOT DEFINED BUILD_SHARED_LIBS)

file(GLOB libsbp_HEADERS "${PROJECT_SOURCE_DIR}/include/libsbp/*.h")

include_directories("${PROJECT_SOURCE_DIR}/CBLAS/include")
include_directories("${PROJECT_SOURCE_DIR}/clapack-3.2.1-CMAKE/INCLUDE")
include_directories("${PROJECT_SOURCE_DIR}/lapacke/include")
include_directories("${PROJECT_SOURCE_DIR}/include")

set(libsbp_SRCS
  edc.c
  sbp.c
)

add_library(sbp-static STATIC ${libsbp_SRCS})
install(TARGETS sbp-static DESTINATION lib${LIB_SUFFIX})

if(BUILD_SHARED_LIBS)
  add_library(sbp SHARED ${libsbp_SRCS})
  install(TARGETS sbp DESTINATION lib${LIB_SUFFIX})
else(BUILD_SHARED_LIBS)
  message(STATUS "Not building shared libraries")
endif(BUILD_SHARED_LIBS)

install(FILES ${libsbp_HEADERS} DESTINATION include/libsbp)
