FILE(GLOB generated_cpp_sources auto*.cc)

swift_add_test(test-libsbp-cpp-legacy
    UNIT_TEST
    SRCS
        test_sbp_stdio.cc
        ${generated_cpp_sources}
    INCLUDE
        ${PROJECT_SOURCE_DIR}/include/libsbp
    LINK
        sbp
        gtest_main)
swift_set_language_standards(test-libsbp-cpp-legacy)
swift_set_compile_options(test-libsbp-cpp-legacy ADD -Wno-error=array-bounds)

file(COPY sbp_data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
