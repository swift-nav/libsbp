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
// spec/tests/yaml/swiftnav/sbp/integrity/test_integrity_structs.yaml by
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

class Test_Struct_auto_check_sbp_integrity_integrity_structs0
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_integrity_integrity_structs0() {
    assign(test_struct_.chain_id, 200);
    assign(test_struct_.num_msgs, 240);
    assign(test_struct_.obs_time.tow, 439933335);
    assign(test_struct_.obs_time.wn, 37300);
    assign(test_struct_.seq_num, 13);
    assign(test_struct_.ssr_sol_id, 93);
    assign(test_struct_.tile_id, 20278);
    assign(test_struct_.tile_set_id, 24876);
  }

  struct TestStructInfo {
    sbp_integrity_ssr_header_t test_struct;
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
  sbp_integrity_ssr_header_t test_struct_{};
  uint8_t encoded_data_[14] = {
      151, 217, 56, 26, 180, 145, 240, 13, 93, 44, 97, 54, 79, 200,
  };
};

TEST_F(Test_Struct_auto_check_sbp_integrity_integrity_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_integrity_ssr_header_encoded_len(&info.test_struct), 14);
}

TEST_F(Test_Struct_auto_check_sbp_integrity_integrity_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[14];
  EXPECT_EQ(sbp_integrity_ssr_header_encode(&buf[0], sizeof(buf), &nwritten,
                                            &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 14);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_integrity_integrity_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[14];
  EXPECT_EQ(sbp_integrity_ssr_header_encode(&buf[0], sizeof(buf), nullptr,
                                            &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 14), 0);
}

TEST_F(Test_Struct_auto_check_sbp_integrity_integrity_structs0,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[14];
  for (uint8_t i = 0; i < 14; i++) {
    EXPECT_EQ(
        sbp_integrity_ssr_header_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_integrity_integrity_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_integrity_ssr_header_t t{};
  EXPECT_EQ(sbp_integrity_ssr_header_decode(info.encoded_data, 14, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_integrity_ssr_header_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_integrity_integrity_structs0,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_integrity_ssr_header_t t{};
  EXPECT_EQ(sbp_integrity_ssr_header_decode(info.encoded_data, 14, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_integrity_ssr_header_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_integrity_integrity_structs0,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_integrity_ssr_header_t t{};

  for (uint8_t i = 0; i < 14; i++) {
    EXPECT_EQ(
        sbp_integrity_ssr_header_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

}  // namespace
