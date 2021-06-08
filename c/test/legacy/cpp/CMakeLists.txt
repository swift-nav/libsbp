FILE(GLOB generated_cpp_sources auto*.cc)

swift_add_test(test-legacy-libsbp-cpp
    UNIT_TEST
    POST_BUILD
    SRCS
        test_sbp_stdio.cc
        ${generated_cpp_sources}
    INCLUDE
        ${PROJECT_SOURCE_DIR}/include/libsbp
    LINK
        sbp
        gtest_main)
swift_set_language_standards(test-legacy-libsbp-cpp)
swift_set_compile_options(test-legacy-libsbp-cpp ADD -Wno-error=array-bounds)

file(COPY sbp_data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
