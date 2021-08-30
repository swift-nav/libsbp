include(GenerateExportHeader)

FILE(GLOB generated_c_sources v4/*.c)

set(libsbp_SRCS
  edc.c
  sbp.c
  v4/string/sbp_string.c
  v4/string/multipart.c
  v4/string/unterminated.c
  v4/string/null_terminated.c
  v4/string/double_null_terminated.c
  ${generated_c_sources}
  )

swift_add_library(sbp
  SOURCES ${libsbp_SRCS}
)
add_library(swiftnav::sbp ALIAS sbp)

generate_export_header(sbp
  DEPRECATED_MACRO_NAME CMAKE_SBP_DEPRECATED
  NO_DEPRECATED_MACRO_NAME CMAKE_SBP_NO_DEPRECATED
  INCLUDE_GUARD_NAME LIBSBP_SBP_EXPORT_H
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
)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/libsbp/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/libsbp)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/sbp_export.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/libsbp)

export(EXPORT sbp-export
       NAMESPACE swiftnav::
       FILE ${PROJECT_BINARY_DIR}/LibSbpImport.cmake)
