FILE(GLOB generated_cpp_sources auto*.cc)

swift_add_test(test-libsbp-cpp
    UNIT_TEST
    POST_BUILD
    SRCS
        ${generated_cpp_sources}
    INCLUDE
        ${PROJECT_SOURCE_DIR}/include/libsbp
    LINK
        sbp
        gtest_main)
swift_set_language_standards(test-libsbp-cpp)
swift_set_compile_options(test-libsbp-cpp)

