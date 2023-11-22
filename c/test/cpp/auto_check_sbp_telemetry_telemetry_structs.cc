/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/telemetry/test_telemetry_structs.yaml by
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

class Test_Struct_auto_check_sbp_telemetry_telemetry_structs0
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_telemetry_telemetry_structs0() {
    assign(test_struct_.availability_flags, 23);
    assign(test_struct_.az, 65);
    assign(test_struct_.correction_flags, 6);
    assign(test_struct_.el, 96);
    assign(test_struct_.ephemeris_flags, 52);
    assign(test_struct_.outlier_flags, 37);
    assign(test_struct_.phase_residual, -27718);
    assign(test_struct_.pseudorange_residual, 17614);
    assign(test_struct_.sid.code, 196);
    assign(test_struct_.sid.sat, 88);
  }

  struct TestStructInfo {
    sbp_telemetry_sv_t test_struct;
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
  sbp_telemetry_sv_t test_struct_{};
  uint8_t encoded_data_[12] = {
      65, 96, 23, 206, 68, 186, 147, 37, 52, 6, 88, 196,
  };
};

TEST_F(Test_Struct_auto_check_sbp_telemetry_telemetry_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_telemetry_sv_encoded_len(&info.test_struct), 12);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_telemetry_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[12];
  EXPECT_EQ(sbp_telemetry_sv_encode(&buf[0], sizeof(buf), &nwritten,
                                    &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 12);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_telemetry_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[12];
  EXPECT_EQ(
      sbp_telemetry_sv_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 12), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_telemetry_structs0,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[12];
  for (uint8_t i = 0; i < 12; i++) {
    EXPECT_EQ(sbp_telemetry_sv_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_telemetry_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_telemetry_sv_t t{};
  EXPECT_EQ(sbp_telemetry_sv_decode(info.encoded_data, 12, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_telemetry_sv_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_telemetry_structs0,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_telemetry_sv_t t{};
  EXPECT_EQ(sbp_telemetry_sv_decode(info.encoded_data, 12, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_telemetry_sv_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_telemetry_structs0,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_telemetry_sv_t t{};

  for (uint8_t i = 0; i < 12; i++) {
    EXPECT_EQ(sbp_telemetry_sv_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace