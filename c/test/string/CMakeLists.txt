# Since test-libsbp-string is testing internal functions that are not publicly
# exposed by the sbp library, we can only build and run this test when ingesting
# it as a static library.
if (BUILD_SHARED_LIBS)
  return()
endif()

swift_add_test(test-libsbp-string
  UNIT_TEST
  POST_BUILD
  SRCS
    test_unterminated.cc
    test_multipart.cc
    test_double_null_terminated.cc
    test_null_terminated.cc
  INCLUDE
    ${PROJECT_SOURCE_DIR}/src/include
    ${PROJECT_SOURCE_DIR}/include
  LINK
    sbp
    gtest_main)
swift_set_language_standards(test-libsbp-string)
swift_set_compile_options(test-libsbp-string)
