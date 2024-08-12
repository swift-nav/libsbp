/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/navigation/test_navigation_structs.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/state.h>
#include <libsbp/sbp.h>
#include <algorithm>

namespace {

template <typename T, typename U>
void assign(T &dest, const U &source) {
  dest = static_cast<T>(source);
}

class Test_Struct_auto_check_sbp_navigation_navigation_structs0
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_navigation_navigation_structs0() {
    assign(test_struct_.orientation, 91.199997);
    assign(test_struct_.semi_major, 4869.200195);
    assign(test_struct_.semi_minor, 5968.200195);
  }

  struct TestStructInfo {
    sbp_estimated_horizontal_error_ellipse_t test_struct;
    const uint8_t *encoded_data;
    uint32_t encoded_len;
  };

  TestStructInfo get_test_struct_info() const noexcept {
    TestStructInfo info;
    memcpy(&info.test_struct, &test_struct_, sizeof(test_struct_));
    info.encoded_data = encoded_data_;
    info.encoded_len = sizeof(encoded_data_);
    return info;
  }

 private:
  sbp_estimated_horizontal_error_ellipse_t test_struct_{};
  uint8_t encoded_data_[12] = {
      154, 41, 152, 69, 154, 129, 186, 69, 102, 102, 182, 66,
  };
};

TEST_F(Test_Struct_auto_check_sbp_navigation_navigation_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(
      sbp_estimated_horizontal_error_ellipse_encoded_len(&info.test_struct),
      12);
}

TEST_F(Test_Struct_auto_check_sbp_navigation_navigation_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[12];
  EXPECT_EQ(sbp_estimated_horizontal_error_ellipse_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 12);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_navigation_navigation_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[12];
  EXPECT_EQ(sbp_estimated_horizontal_error_ellipse_encode(
                &buf[0], sizeof(buf), nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 12), 0);
}

TEST_F(Test_Struct_auto_check_sbp_navigation_navigation_structs0,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[12];
  for (uint8_t i = 0; i < 12; i++) {
    EXPECT_EQ(sbp_estimated_horizontal_error_ellipse_encode(&buf[0], i, nullptr,
                                                            &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_navigation_navigation_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_estimated_horizontal_error_ellipse_t t{};
  EXPECT_EQ(sbp_estimated_horizontal_error_ellipse_decode(info.encoded_data, 12,
                                                          &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_estimated_horizontal_error_ellipse_cmp(&t, &info.test_struct),
            0);
}

TEST_F(Test_Struct_auto_check_sbp_navigation_navigation_structs0,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_estimated_horizontal_error_ellipse_t t{};
  EXPECT_EQ(sbp_estimated_horizontal_error_ellipse_decode(info.encoded_data, 12,
                                                          nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_estimated_horizontal_error_ellipse_cmp(&t, &info.test_struct),
            0);
}

TEST_F(Test_Struct_auto_check_sbp_navigation_navigation_structs0,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_estimated_horizontal_error_ellipse_t t{};

  for (uint8_t i = 0; i < 12; i++) {
    EXPECT_EQ(sbp_estimated_horizontal_error_ellipse_decode(info.encoded_data,
                                                            i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace