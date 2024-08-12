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
// spec/tests/yaml/swiftnav/sbp/gnss/test_gnss_structs.yaml by generate.py. Do
// not modify by hand!

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

class Test_Struct_auto_check_sbp_gnss_gnss_structs0 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_gnss_gnss_structs0() {
    assign(test_struct_.code, 244);
    assign(test_struct_.sat, 162);
  }

  struct TestStructInfo {
    sbp_gnss_signal_t test_struct;
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
  sbp_gnss_signal_t test_struct_{};
  uint8_t encoded_data_[2] = {
      162,
      244,
  };
};

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_gnss_signal_encoded_len(&info.test_struct), 2);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[2];
  EXPECT_EQ(sbp_gnss_signal_encode(&buf[0], sizeof(buf), &nwritten,
                                   &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 2);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[2];
  EXPECT_EQ(
      sbp_gnss_signal_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 2), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs0, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[2];
  for (uint8_t i = 0; i < 2; i++) {
    EXPECT_EQ(sbp_gnss_signal_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_gnss_signal_t t{};
  EXPECT_EQ(sbp_gnss_signal_decode(info.encoded_data, 2, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_gnss_signal_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs0, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_gnss_signal_t t{};
  EXPECT_EQ(sbp_gnss_signal_decode(info.encoded_data, 2, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_gnss_signal_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs0, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_gnss_signal_t t{};

  for (uint8_t i = 0; i < 2; i++) {
    EXPECT_EQ(sbp_gnss_signal_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_gnss_gnss_structs1 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_gnss_gnss_structs1() {
    assign(test_struct_.constellation, 44);
    assign(test_struct_.satId, 178);
  }

  struct TestStructInfo {
    sbp_sv_id_t test_struct;
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
  sbp_sv_id_t test_struct_{};
  uint8_t encoded_data_[2] = {
      178,
      44,
  };
};

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs1, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_sv_id_encoded_len(&info.test_struct), 2);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs1, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[2];
  EXPECT_EQ(
      sbp_sv_id_encode(&buf[0], sizeof(buf), &nwritten, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(nwritten, 2);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs1,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[2];
  EXPECT_EQ(sbp_sv_id_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 2), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs1, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[2];
  for (uint8_t i = 0; i < 2; i++) {
    EXPECT_EQ(sbp_sv_id_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs1, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_sv_id_t t{};
  EXPECT_EQ(sbp_sv_id_decode(info.encoded_data, 2, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_sv_id_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs1, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_sv_id_t t{};
  EXPECT_EQ(sbp_sv_id_decode(info.encoded_data, 2, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_sv_id_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs1, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_sv_id_t t{};

  for (uint8_t i = 0; i < 2; i++) {
    EXPECT_EQ(sbp_sv_id_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_gnss_gnss_structs2 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_gnss_gnss_structs2() {
    assign(test_struct_.code, 241);
    assign(test_struct_.reserved, 245);
    assign(test_struct_.sat, 17091);
  }

  struct TestStructInfo {
    sbp_gnss_signal_dep_t test_struct;
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
  sbp_gnss_signal_dep_t test_struct_{};
  uint8_t encoded_data_[4] = {
      195,
      66,
      241,
      245,
  };
};

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs2, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_gnss_signal_dep_encoded_len(&info.test_struct), 4);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs2, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[4];
  EXPECT_EQ(sbp_gnss_signal_dep_encode(&buf[0], sizeof(buf), &nwritten,
                                       &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 4);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs2,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  EXPECT_EQ(sbp_gnss_signal_dep_encode(&buf[0], sizeof(buf), nullptr,
                                       &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 4), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs2, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(
        sbp_gnss_signal_dep_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs2, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_gnss_signal_dep_t t{};
  EXPECT_EQ(sbp_gnss_signal_dep_decode(info.encoded_data, 4, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_gnss_signal_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs2, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_gnss_signal_dep_t t{};
  EXPECT_EQ(sbp_gnss_signal_dep_decode(info.encoded_data, 4, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_gnss_signal_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs2, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_gnss_signal_dep_t t{};

  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(sbp_gnss_signal_dep_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_gnss_gnss_structs3 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_gnss_gnss_structs3() {
    assign(test_struct_.tow, 1454655020);
    assign(test_struct_.wn, 26743);
  }

  struct TestStructInfo {
    sbp_gps_time_dep_t test_struct;
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
  sbp_gps_time_dep_t test_struct_{};
  uint8_t encoded_data_[6] = {
      44, 70, 180, 86, 119, 104,
  };
};

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs3, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_gps_time_dep_encoded_len(&info.test_struct), 6);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs3, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[6];
  EXPECT_EQ(sbp_gps_time_dep_encode(&buf[0], sizeof(buf), &nwritten,
                                    &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 6);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs3,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[6];
  EXPECT_EQ(
      sbp_gps_time_dep_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 6), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs3, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[6];
  for (uint8_t i = 0; i < 6; i++) {
    EXPECT_EQ(sbp_gps_time_dep_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs3, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_gps_time_dep_t t{};
  EXPECT_EQ(sbp_gps_time_dep_decode(info.encoded_data, 6, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_gps_time_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs3, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_gps_time_dep_t t{};
  EXPECT_EQ(sbp_gps_time_dep_decode(info.encoded_data, 6, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_gps_time_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs3, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_gps_time_dep_t t{};

  for (uint8_t i = 0; i < 6; i++) {
    EXPECT_EQ(sbp_gps_time_dep_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_gnss_gnss_structs4 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_gnss_gnss_structs4() {
    assign(test_struct_.tow, 2061297728);
    assign(test_struct_.wn, 62230);
  }

  struct TestStructInfo {
    sbp_gps_time_sec_t test_struct;
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
  sbp_gps_time_sec_t test_struct_{};
  uint8_t encoded_data_[6] = {
      64, 232, 220, 122, 22, 243,
  };
};

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs4, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_gps_time_sec_encoded_len(&info.test_struct), 6);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs4, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[6];
  EXPECT_EQ(sbp_gps_time_sec_encode(&buf[0], sizeof(buf), &nwritten,
                                    &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 6);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs4,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[6];
  EXPECT_EQ(
      sbp_gps_time_sec_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 6), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs4, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[6];
  for (uint8_t i = 0; i < 6; i++) {
    EXPECT_EQ(sbp_gps_time_sec_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs4, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_gps_time_sec_t t{};
  EXPECT_EQ(sbp_gps_time_sec_decode(info.encoded_data, 6, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_gps_time_sec_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs4, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_gps_time_sec_t t{};
  EXPECT_EQ(sbp_gps_time_sec_decode(info.encoded_data, 6, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_gps_time_sec_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs4, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_gps_time_sec_t t{};

  for (uint8_t i = 0; i < 6; i++) {
    EXPECT_EQ(sbp_gps_time_sec_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_gnss_gnss_structs5 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_gnss_gnss_structs5() {
    assign(test_struct_.ns_residual, 471708190);
    assign(test_struct_.tow, 96275743);
    assign(test_struct_.wn, 47135);
  }

  struct TestStructInfo {
    sbp_gps_time_t test_struct;
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
  sbp_gps_time_t test_struct_{};
  uint8_t encoded_data_[10] = {
      31, 13, 189, 5, 30, 178, 29, 28, 31, 184,
  };
};

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs5, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_gps_time_encoded_len(&info.test_struct), 10);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs5, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[10];
  EXPECT_EQ(
      sbp_gps_time_encode(&buf[0], sizeof(buf), &nwritten, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(nwritten, 10);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs5,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[10];
  EXPECT_EQ(
      sbp_gps_time_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 10), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs5, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[10];
  for (uint8_t i = 0; i < 10; i++) {
    EXPECT_EQ(sbp_gps_time_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs5, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_gps_time_t t{};
  EXPECT_EQ(sbp_gps_time_decode(info.encoded_data, 10, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_gps_time_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs5, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_gps_time_t t{};
  EXPECT_EQ(sbp_gps_time_decode(info.encoded_data, 10, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_gps_time_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs5, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_gps_time_t t{};

  for (uint8_t i = 0; i < 10; i++) {
    EXPECT_EQ(sbp_gps_time_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_gnss_gnss_structs6 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_gnss_gnss_structs6() {
    assign(test_struct_.f, 122);
    assign(test_struct_.i, -2018454494);
  }

  struct TestStructInfo {
    sbp_carrier_phase_t test_struct;
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
  sbp_carrier_phase_t test_struct_{};
  uint8_t encoded_data_[5] = {
      34, 212, 176, 135, 122,
  };
};

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs6, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_carrier_phase_encoded_len(&info.test_struct), 5);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs6, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[5];
  EXPECT_EQ(sbp_carrier_phase_encode(&buf[0], sizeof(buf), &nwritten,
                                     &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 5);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs6,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[5];
  EXPECT_EQ(sbp_carrier_phase_encode(&buf[0], sizeof(buf), nullptr,
                                     &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 5), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs6, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[5];
  for (uint8_t i = 0; i < 5; i++) {
    EXPECT_EQ(sbp_carrier_phase_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs6, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_carrier_phase_t t{};
  EXPECT_EQ(sbp_carrier_phase_decode(info.encoded_data, 5, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_carrier_phase_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs6, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_carrier_phase_t t{};
  EXPECT_EQ(sbp_carrier_phase_decode(info.encoded_data, 5, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_carrier_phase_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_gnss_gnss_structs6, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_carrier_phase_t t{};

  for (uint8_t i = 0; i < 5; i++) {
    EXPECT_EQ(sbp_carrier_phase_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace