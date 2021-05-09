swift_add_test(test-libsbp-string
  UNIT_TEST
  POST_BUILD
  SRCS
    test_unterminated.cc
    test_null_terminated.cc
    test_multipart_2_2.cc
    test_multipart_3_4.cc
    test_sequence_double_null.cc
    test_sequence_ff.cc
  LINK
    sbp
    gtest_main
)
swift_set_language_standards(test-libsbp-string)
swift_set_compile_options(test-libsbp-string ADD -pedantic)
