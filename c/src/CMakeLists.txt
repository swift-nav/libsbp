set(libsbp_SRCS
  edc.c
  sbp.c
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
set_target_properties(sbp PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        C_STANDARD 99
        C_STANDARD_REQUIRED ON)
target_code_coverage(sbp AUTO ALL)

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
