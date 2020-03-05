swift_add_test(test-libsbp-cpp
    SRCS
        test_sbp_stdio.cc
    INCLUDE
        ${PROJECT_SOURCE_DIR}/include/libsbp
    LINK
        sbp
        gtest_main)

file(COPY sbp_data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
