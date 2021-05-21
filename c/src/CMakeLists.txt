FILE(GLOB generated_c_sources unpacked/*.c)

set(libsbp_SRCS
  edc.c
  sbp.c
  unpacked/string/unterminated.c
  unpacked/string/null_terminated.c
  unpacked/string/multipart.c
  unpacked/string/sequence.c
  unpacked/string/binary.c
  ${generated_c_sources}
  )

add_library(sbp ${libsbp_SRCS})
add_library(swiftnav::sbp ALIAS sbp)

if(MSVC)
    separate_arguments(LIBSBP_COMPILER_OPTIONS WINDOWS_COMMAND ${LIBSBP_CFLAGS})
else()
    separate_arguments(LIBSBP_COMPILER_OPTIONS UNIX_COMMAND ${LIBSBP_CFLAGS})
endif()
target_compile_options(sbp PRIVATE ${LIBSBP_COMPILER_OPTIONS})

target_include_directories(sbp PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(sbp PRIVATE ${PROJECT_SOURCE_DIR}/src/include)
set_target_properties(sbp PROPERTIES
        POSITION_INDEPENDENT_CODE ON)
target_code_coverage(sbp AUTO ALL)
swift_set_language_standards(sbp)
swift_set_compile_options(sbp ADD -pedantic)

if (MINGW)
  if (CMAKE_C_COMPILER_VERSION VERSION_GREATER "4.7.0" AND CMAKE_C_COMPILER_VERSION VERSION_LESS "8.0.0")
    message(WARNING "Detected MinGW adding __attribute__((packed)) workaround")
    target_compile_options(sbp PUBLIC "-mno-ms-bitfields")
  endif()
endif()

install(TARGETS sbp
        EXPORT sbp-export
        DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})
install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/libsbp/" DESTINATION "${CMAKE_INSTALL_FULL_INCLUDEDIR}/libsbp")

export(EXPORT sbp-export
       NAMESPACE LibSbp::
       FILE ${PROJECT_BINARY_DIR}/LibSbpImport.cmake)
