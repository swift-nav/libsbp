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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_acquisition_structs.yaml by
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

class Test_Struct_auto_check_sbp_telemetry_acquisition_structs0
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_telemetry_acquisition_structs0() {
    assign(test_struct_.bin_width, 47800);
    assign(test_struct_.cf, 76658289);
    assign(test_struct_.cf_max, 1240169926);
    assign(test_struct_.cf_min, -1846717559);
    assign(test_struct_.cn0, 6092);
    assign(test_struct_.cp, 941027232);
    assign(test_struct_.int_time, 224);
    assign(test_struct_.job_type, 30);
    assign(test_struct_.sid.code, 255);
    assign(test_struct_.sid.sat, 125);
    assign(test_struct_.status, 109);
    assign(test_struct_.time_spent, 115890281);
    assign(test_struct_.timestamp, 2936122286);
  }

  struct TestStructInfo {
    sbp_acq_sv_profile_t test_struct;
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
  sbp_acq_sv_profile_t test_struct_{};
  uint8_t encoded_data_[33] = {
      30,  109, 204, 23,  224, 125, 255, 184, 186, 174, 171,
      1,   175, 105, 88,  232, 6,   137, 83,  237, 145, 198,
      125, 235, 73,  113, 182, 145, 4,   160, 239, 22,  56,
  };
};

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_acq_sv_profile_encoded_len(&info.test_struct), 33);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[33];
  EXPECT_EQ(sbp_acq_sv_profile_encode(&buf[0], sizeof(buf), &nwritten,
                                      &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 33);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[33];
  EXPECT_EQ(sbp_acq_sv_profile_encode(&buf[0], sizeof(buf), nullptr,
                                      &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 33), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs0,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[33];
  for (uint8_t i = 0; i < 33; i++) {
    EXPECT_EQ(sbp_acq_sv_profile_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_acq_sv_profile_t t{};
  EXPECT_EQ(sbp_acq_sv_profile_decode(info.encoded_data, 33, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_acq_sv_profile_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs0,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_acq_sv_profile_t t{};
  EXPECT_EQ(sbp_acq_sv_profile_decode(info.encoded_data, 33, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_acq_sv_profile_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs0,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_acq_sv_profile_t t{};

  for (uint8_t i = 0; i < 33; i++) {
    EXPECT_EQ(sbp_acq_sv_profile_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_telemetry_acquisition_structs1
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_telemetry_acquisition_structs1() {
    assign(test_struct_.bin_width, 39981);
    assign(test_struct_.cf, 657970044);
    assign(test_struct_.cf_max, 2142496829);
    assign(test_struct_.cf_min, -1962679006);
    assign(test_struct_.cn0, 3806);
    assign(test_struct_.cp, 2715693981);
    assign(test_struct_.int_time, 228);
    assign(test_struct_.job_type, 100);
    assign(test_struct_.sid.code, 153);
    assign(test_struct_.sid.sat, 19540);
    assign(test_struct_.status, 114);
    assign(test_struct_.time_spent, 3609490020);
    assign(test_struct_.timestamp, 3521954072);
  }

  struct TestStructInfo {
    sbp_acq_sv_profile_dep_t test_struct;
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
  sbp_acq_sv_profile_dep_t test_struct_{};
  uint8_t encoded_data_[35] = {
      100, 114, 222, 14,  228, 84, 76,  153, 0,   45,  156, 24,
      193, 236, 209, 100, 114, 36, 215, 34,  229, 3,   139, 61,
      232, 179, 127, 124, 211, 55, 39,  157, 51,  222, 161,
  };
};

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs1, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_acq_sv_profile_dep_encoded_len(&info.test_struct), 35);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs1, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[35];
  EXPECT_EQ(sbp_acq_sv_profile_dep_encode(&buf[0], sizeof(buf), &nwritten,
                                          &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 35);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs1,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[35];
  EXPECT_EQ(sbp_acq_sv_profile_dep_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 35), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs1,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[35];
  for (uint8_t i = 0; i < 35; i++) {
    EXPECT_EQ(
        sbp_acq_sv_profile_dep_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs1, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_acq_sv_profile_dep_t t{};
  EXPECT_EQ(sbp_acq_sv_profile_dep_decode(info.encoded_data, 35, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_acq_sv_profile_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs1,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_acq_sv_profile_dep_t t{};
  EXPECT_EQ(sbp_acq_sv_profile_dep_decode(info.encoded_data, 35, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_acq_sv_profile_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_telemetry_acquisition_structs1,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_acq_sv_profile_dep_t t{};

  for (uint8_t i = 0; i < 35; i++) {
    EXPECT_EQ(sbp_acq_sv_profile_dep_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace