FILE(GLOB generated_cpp_sources auto*.cc)

swift_add_test(test-libsbp-cpp
    UNIT_TEST
    SRCS
        ${generated_cpp_sources}
    INCLUDE
        ${PROJECT_SOURCE_DIR}/include/libsbp
    LINK
        gtest_main
        swiftnav::sbp
)
swift_set_language_standards(test-libsbp-cpp)
swift_set_compile_options(test-libsbp-cpp)

