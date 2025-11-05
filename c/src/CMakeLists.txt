
set(libsbp_SRCS
  edc.c
  sbp.c
  string/sbp_string.c
  string/multipart.c
  string/unterminated.c
  string/null_terminated.c
  string/double_null_terminated.c
  #generated files
  acquisition.c
  bootload.c
  ext_events.c
  file_io.c
  flash.c
  gnss.c
  imu.c
  integrity.c
  linux.c
  logging.c
  mag.c
  navigation.c
  ndb.c
  observation.c
  orientation.c
  piksi.c
  profiling.c
  sbas.c
  settings.c
  signing.c
  solution_meta.c
  ssr.c
  system.c
  telemetry.c
  tracking.c
  user.c
  vehicle.c
  )

swift_add_library(sbp
  SOURCES ${libsbp_SRCS}
)

if(I_KNOW_WHAT_I_AM_DOING_AND_HOW_DANGEROUS_IT_IS__LIBSBP_DISABLE_CRC_VALIDATION)
  target_compile_definitions(sbp PRIVATE LIBSBP_DISABLE_CRC_VALIDATION)
endif()

target_compile_definitions(sbp
  PRIVATE
    $<BUILD_INTERFACE:sbp_EXPORTS>
)
target_include_directories(sbp
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_LIBDIR}>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
set_target_properties(sbp
  PROPERTIES
    VISIBILITY_INLINES_HIDDEN true
    C_VISIBILITY_PRESET hidden
    CXX_VISIBILITY_PRESET hidden
    POSITION_INDEPENDENT_CODE true
)

if (MINGW)
  if (CMAKE_C_COMPILER_VERSION VERSION_GREATER "4.7.0" AND CMAKE_C_COMPILER_VERSION VERSION_LESS "8.0.0")
    message(WARNING "Detected MinGW adding __attribute__((packed)) workaround")
    target_compile_options(sbp PUBLIC "-mno-ms-bitfields")
  endif()
endif()

install(
  TARGETS sbp
  EXPORT sbp-export
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/libsbp/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/libsbp)

export(EXPORT sbp-export
       NAMESPACE swiftnav::
       FILE ${PROJECT_BINARY_DIR}/LibSbpImport.cmake)

install(
  EXPORT sbp-export
  DESTINATION ${CMAKE_INSTALL_DATADIR}/libsbp/cmake
  NAMESPACE swiftnav::
)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/libsbpConfig.cmake.in
  libsbpConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}
)
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/libsbpConfig.cmake"
  DESTINATION ${CMAKE_INSTALL_DATADIR}/libsbp/cmake
)
