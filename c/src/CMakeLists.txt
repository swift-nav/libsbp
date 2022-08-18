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
)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/libsbp/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/libsbp)

export(EXPORT sbp-export
       NAMESPACE swiftnav::
       FILE ${PROJECT_BINARY_DIR}/LibSbpImport.cmake)
