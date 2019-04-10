set(libsbp_SRCS
  edc.c
  sbp.c
  )

add_library(sbp ${libsbp_SRCS})

target_include_directories(sbp
    PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    )

if(MSVC)
    separate_arguments(LIBSBP_COMPILER_OPTIONS WINDOWS_COMMAND ${LIBSBP_CFLAGS})
else()
    separate_arguments(LIBSBP_COMPILER_OPTIONS UNIX_COMMAND ${LIBSBP_CFLAGS})
endif()
target_compile_options(sbp PRIVATE ${LIBSBP_COMPILER_OPTIONS})

set_target_properties(sbp PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        C_STANDARD 99
        C_STANDARD_REQUIRED ON)

set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
set(include_install_dir "${CMAKE_INSTALL_INCLUDEDIR}")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

include(CMakePackageConfigHelpers)

write_basic_package_version_file("${version_config}" COMPATIBILITY SameMajorVersion)

configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
  )

install(
    TARGETS sbp
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    INCLUDES DESTINATION "${include_install_Dir}"
  )

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/include/libsbp"
    DESTINATION "${include_install_dir}"
  )

install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
  )

install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
  )
