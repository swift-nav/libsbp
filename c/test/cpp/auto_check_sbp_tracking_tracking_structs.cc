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
// spec/tests/yaml/swiftnav/sbp/tracking/test_tracking_structs.yaml by
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

class Test_Struct_auto_check_sbp_tracking_tracking_structs0
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_tracking_tracking_structs0() {
    assign(test_struct_.cn0, 45);
    assign(test_struct_.fcn, 10);
    assign(test_struct_.sid.code, 0);
    assign(test_struct_.sid.sat, 22);
  }

  struct TestStructInfo {
    sbp_tracking_channel_state_t test_struct;
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
  sbp_tracking_channel_state_t test_struct_{};
  uint8_t encoded_data_[4] = {
      22,
      0,
      10,
      45,
  };
};

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_tracking_channel_state_encoded_len(&info.test_struct), 4);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[4];
  EXPECT_EQ(sbp_tracking_channel_state_encode(&buf[0], sizeof(buf), &nwritten,
                                              &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 4);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  EXPECT_EQ(sbp_tracking_channel_state_encode(&buf[0], sizeof(buf), nullptr,
                                              &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 4), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs0,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(sbp_tracking_channel_state_encode(&buf[0], i, nullptr,
                                                &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_tracking_channel_state_t t{};
  EXPECT_EQ(sbp_tracking_channel_state_decode(info.encoded_data, 4, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_tracking_channel_state_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs0,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_tracking_channel_state_t t{};
  EXPECT_EQ(
      sbp_tracking_channel_state_decode(info.encoded_data, 4, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_tracking_channel_state_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs0,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_tracking_channel_state_t t{};

  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(
        sbp_tracking_channel_state_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_tracking_tracking_structs1
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_tracking_tracking_structs1() {
    assign(test_struct_.cn0, 30);
    assign(test_struct_.mesid.code, 1);
    assign(test_struct_.mesid.sat, 23);
  }

  struct TestStructInfo {
    sbp_measurement_state_t test_struct;
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
  sbp_measurement_state_t test_struct_{};
  uint8_t encoded_data_[3] = {
      23,
      1,
      30,
  };
};

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs1, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_measurement_state_encoded_len(&info.test_struct), 3);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs1, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[3];
  EXPECT_EQ(sbp_measurement_state_encode(&buf[0], sizeof(buf), &nwritten,
                                         &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 3);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs1,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[3];
  EXPECT_EQ(sbp_measurement_state_encode(&buf[0], sizeof(buf), nullptr,
                                         &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 3), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs1,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[3];
  for (uint8_t i = 0; i < 3; i++) {
    EXPECT_EQ(
        sbp_measurement_state_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs1, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_measurement_state_t t{};
  EXPECT_EQ(sbp_measurement_state_decode(info.encoded_data, 3, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_measurement_state_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs1,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_measurement_state_t t{};
  EXPECT_EQ(sbp_measurement_state_decode(info.encoded_data, 3, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_measurement_state_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs1,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_measurement_state_t t{};

  for (uint8_t i = 0; i < 3; i++) {
    EXPECT_EQ(sbp_measurement_state_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_tracking_tracking_structs2
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_tracking_tracking_structs2() {
    assign(test_struct_.I, 37341);
    assign(test_struct_.Q, 8818);
  }

  struct TestStructInfo {
    sbp_tracking_channel_correlation_t test_struct;
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
  sbp_tracking_channel_correlation_t test_struct_{};
  uint8_t encoded_data_[4] = {
      221,
      145,
      114,
      34,
  };
};

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs2, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_tracking_channel_correlation_encoded_len(&info.test_struct), 4);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs2, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[4];
  EXPECT_EQ(sbp_tracking_channel_correlation_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 4);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs2,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  EXPECT_EQ(sbp_tracking_channel_correlation_encode(&buf[0], sizeof(buf),
                                                    nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 4), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs2,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(sbp_tracking_channel_correlation_encode(&buf[0], i, nullptr,
                                                      &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs2, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_tracking_channel_correlation_t t{};
  EXPECT_EQ(
      sbp_tracking_channel_correlation_decode(info.encoded_data, 4, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_tracking_channel_correlation_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs2,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_tracking_channel_correlation_t t{};
  EXPECT_EQ(sbp_tracking_channel_correlation_decode(info.encoded_data, 4,
                                                    nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_tracking_channel_correlation_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs2,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_tracking_channel_correlation_t t{};

  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(sbp_tracking_channel_correlation_decode(info.encoded_data, i,
                                                      nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_tracking_tracking_structs3
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_tracking_tracking_structs3() {
    assign(test_struct_.I, 6871523);
    assign(test_struct_.Q, 817264192);
  }

  struct TestStructInfo {
    sbp_tracking_channel_correlation_dep_t test_struct;
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
  sbp_tracking_channel_correlation_dep_t test_struct_{};
  uint8_t encoded_data_[8] = {
      227, 217, 104, 0, 64, 118, 182, 48,
  };
};

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs3, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_tracking_channel_correlation_dep_encoded_len(&info.test_struct),
            8);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs3, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[8];
  EXPECT_EQ(sbp_tracking_channel_correlation_dep_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 8);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs3,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[8];
  EXPECT_EQ(sbp_tracking_channel_correlation_dep_encode(
                &buf[0], sizeof(buf), nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 8), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs3,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[8];
  for (uint8_t i = 0; i < 8; i++) {
    EXPECT_EQ(sbp_tracking_channel_correlation_dep_encode(&buf[0], i, nullptr,
                                                          &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs3, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_tracking_channel_correlation_dep_t t{};
  EXPECT_EQ(sbp_tracking_channel_correlation_dep_decode(info.encoded_data, 8,
                                                        &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_tracking_channel_correlation_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs3,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_tracking_channel_correlation_dep_t t{};
  EXPECT_EQ(sbp_tracking_channel_correlation_dep_decode(info.encoded_data, 8,
                                                        nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_tracking_channel_correlation_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs3,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_tracking_channel_correlation_dep_t t{};

  for (uint8_t i = 0; i < 8; i++) {
    EXPECT_EQ(sbp_tracking_channel_correlation_dep_decode(info.encoded_data, i,
                                                          nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_tracking_tracking_structs4
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_tracking_tracking_structs4() {
    assign(test_struct_.cn0, 2961.199951);
    assign(test_struct_.prn, 195);
    assign(test_struct_.state, 19);
  }

  struct TestStructInfo {
    sbp_tracking_channel_state_dep_a_t test_struct;
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
  sbp_tracking_channel_state_dep_a_t test_struct_{};
  uint8_t encoded_data_[6] = {
      19, 195, 51, 19, 57, 69,
  };
};

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs4, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_tracking_channel_state_dep_a_encoded_len(&info.test_struct), 6);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs4, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[6];
  EXPECT_EQ(sbp_tracking_channel_state_dep_a_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 6);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs4,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[6];
  EXPECT_EQ(sbp_tracking_channel_state_dep_a_encode(&buf[0], sizeof(buf),
                                                    nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 6), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs4,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[6];
  for (uint8_t i = 0; i < 6; i++) {
    EXPECT_EQ(sbp_tracking_channel_state_dep_a_encode(&buf[0], i, nullptr,
                                                      &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs4, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_tracking_channel_state_dep_a_t t{};
  EXPECT_EQ(
      sbp_tracking_channel_state_dep_a_decode(info.encoded_data, 6, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_tracking_channel_state_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs4,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_tracking_channel_state_dep_a_t t{};
  EXPECT_EQ(sbp_tracking_channel_state_dep_a_decode(info.encoded_data, 6,
                                                    nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_tracking_channel_state_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs4,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_tracking_channel_state_dep_a_t t{};

  for (uint8_t i = 0; i < 6; i++) {
    EXPECT_EQ(sbp_tracking_channel_state_dep_a_decode(info.encoded_data, i,
                                                      nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_tracking_tracking_structs5
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_tracking_tracking_structs5() {
    assign(test_struct_.cn0, 2357.199951);
    assign(test_struct_.sid.code, 236);
    assign(test_struct_.sid.sat, 3011);
    assign(test_struct_.state, 118);
  }

  struct TestStructInfo {
    sbp_tracking_channel_state_dep_b_t test_struct;
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
  sbp_tracking_channel_state_dep_b_t test_struct_{};
  uint8_t encoded_data_[9] = {
      118, 195, 11, 236, 0, 51, 83, 19, 69,
  };
};

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs5, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_tracking_channel_state_dep_b_encoded_len(&info.test_struct), 9);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs5, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[9];
  EXPECT_EQ(sbp_tracking_channel_state_dep_b_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 9);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs5,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[9];
  EXPECT_EQ(sbp_tracking_channel_state_dep_b_encode(&buf[0], sizeof(buf),
                                                    nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 9), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs5,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[9];
  for (uint8_t i = 0; i < 9; i++) {
    EXPECT_EQ(sbp_tracking_channel_state_dep_b_encode(&buf[0], i, nullptr,
                                                      &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs5, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_tracking_channel_state_dep_b_t t{};
  EXPECT_EQ(
      sbp_tracking_channel_state_dep_b_decode(info.encoded_data, 9, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_tracking_channel_state_dep_b_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs5,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_tracking_channel_state_dep_b_t t{};
  EXPECT_EQ(sbp_tracking_channel_state_dep_b_decode(info.encoded_data, 9,
                                                    nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_tracking_channel_state_dep_b_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_tracking_tracking_structs5,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_tracking_channel_state_dep_b_t t{};

  for (uint8_t i = 0; i < 9; i++) {
    EXPECT_EQ(sbp_tracking_channel_state_dep_b_decode(info.encoded_data, i,
                                                      nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace