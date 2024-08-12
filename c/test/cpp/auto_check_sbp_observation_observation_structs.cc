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
// spec/tests/yaml/swiftnav/sbp/observation/test_observation_structs.yaml by
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

class Test_Struct_auto_check_sbp_observation_observation_structs0
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs0() {
    assign(test_struct_.n_obs, 68);
    assign(test_struct_.t.ns_residual, -749915819);
    assign(test_struct_.t.tow, 1204421761);
    assign(test_struct_.t.wn, 45178);
  }

  struct TestStructInfo {
    sbp_observation_header_t test_struct;
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
  sbp_observation_header_t test_struct_{};
  uint8_t encoded_data_[11] = {
      129, 4, 202, 71, 85, 49, 77, 211, 122, 176, 68,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs0,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_observation_header_encoded_len(&info.test_struct), 11);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs0,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[11];
  EXPECT_EQ(sbp_observation_header_encode(&buf[0], sizeof(buf), &nwritten,
                                          &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 11);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[11];
  EXPECT_EQ(sbp_observation_header_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 11), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs0,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[11];
  for (uint8_t i = 0; i < 11; i++) {
    EXPECT_EQ(
        sbp_observation_header_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs0,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_observation_header_t t{};
  EXPECT_EQ(sbp_observation_header_decode(info.encoded_data, 11, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_observation_header_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs0,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_observation_header_t t{};
  EXPECT_EQ(sbp_observation_header_decode(info.encoded_data, 11, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_observation_header_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs0,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_observation_header_t t{};

  for (uint8_t i = 0; i < 11; i++) {
    EXPECT_EQ(sbp_observation_header_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs1
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs1() {
    assign(test_struct_.f, 185);
    assign(test_struct_.i, 9039);
  }

  struct TestStructInfo {
    sbp_doppler_t test_struct;
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
  sbp_doppler_t test_struct_{};
  uint8_t encoded_data_[3] = {
      79,
      35,
      185,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs1,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_doppler_encoded_len(&info.test_struct), 3);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs1,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[3];
  EXPECT_EQ(
      sbp_doppler_encode(&buf[0], sizeof(buf), &nwritten, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(nwritten, 3);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs1,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[3];
  EXPECT_EQ(
      sbp_doppler_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 3), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs1,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[3];
  for (uint8_t i = 0; i < 3; i++) {
    EXPECT_EQ(sbp_doppler_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs1,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_doppler_t t{};
  EXPECT_EQ(sbp_doppler_decode(info.encoded_data, 3, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_doppler_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs1,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_doppler_t t{};
  EXPECT_EQ(sbp_doppler_decode(info.encoded_data, 3, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_doppler_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs1,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_doppler_t t{};

  for (uint8_t i = 0; i < 3; i++) {
    EXPECT_EQ(sbp_doppler_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs2
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs2() {
    assign(test_struct_.D.f, 140);
    assign(test_struct_.D.i, 17441);
    assign(test_struct_.L.f, 113);
    assign(test_struct_.L.i, -1839286973);
    assign(test_struct_.P, 4093148394);
    assign(test_struct_.cn0, 54);
    assign(test_struct_.flags, 65);
    assign(test_struct_.lock, 185);
    assign(test_struct_.sid.code, 230);
    assign(test_struct_.sid.sat, 170);
  }

  struct TestStructInfo {
    sbp_packed_obs_content_t test_struct;
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
  sbp_packed_obs_content_t test_struct_{};
  uint8_t encoded_data_[17] = {
      234, 124, 248, 243, 67,  181, 94,  146, 113,
      33,  68,  140, 54,  185, 65,  170, 230,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs2,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_packed_obs_content_encoded_len(&info.test_struct), 17);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs2,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[17];
  EXPECT_EQ(sbp_packed_obs_content_encode(&buf[0], sizeof(buf), &nwritten,
                                          &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 17);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs2,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[17];
  EXPECT_EQ(sbp_packed_obs_content_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 17), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs2,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[17];
  for (uint8_t i = 0; i < 17; i++) {
    EXPECT_EQ(
        sbp_packed_obs_content_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs2,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_packed_obs_content_t t{};
  EXPECT_EQ(sbp_packed_obs_content_decode(info.encoded_data, 17, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_packed_obs_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs2,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_packed_obs_content_t t{};
  EXPECT_EQ(sbp_packed_obs_content_decode(info.encoded_data, 17, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_packed_obs_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs2,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_packed_obs_content_t t{};

  for (uint8_t i = 0; i < 17; i++) {
    EXPECT_EQ(sbp_packed_obs_content_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs3
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs3() {
    assign(test_struct_.L.f, 216);
    assign(test_struct_.L.i, 900607277);
    assign(test_struct_.P, 4011084941);
    assign(test_struct_.flags, 40);
    assign(test_struct_.iono_std, 10443);
    assign(test_struct_.lock, 230);
    assign(test_struct_.range_std, 2340);
    assign(test_struct_.sid.code, 189);
    assign(test_struct_.sid.sat, 56);
    assign(test_struct_.tropo_std, 25355);
  }

  struct TestStructInfo {
    sbp_packed_osr_content_t test_struct;
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
  sbp_packed_osr_content_t test_struct_{};
  uint8_t encoded_data_[19] = {
      141, 76, 20,  239, 45, 45, 174, 53, 216, 230,
      40,  56, 189, 203, 40, 11, 99,  36, 9,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs3,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_packed_osr_content_encoded_len(&info.test_struct), 19);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs3,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[19];
  EXPECT_EQ(sbp_packed_osr_content_encode(&buf[0], sizeof(buf), &nwritten,
                                          &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 19);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs3,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[19];
  EXPECT_EQ(sbp_packed_osr_content_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 19), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs3,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[19];
  for (uint8_t i = 0; i < 19; i++) {
    EXPECT_EQ(
        sbp_packed_osr_content_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs3,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_packed_osr_content_t t{};
  EXPECT_EQ(sbp_packed_osr_content_decode(info.encoded_data, 19, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_packed_osr_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs3,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_packed_osr_content_t t{};
  EXPECT_EQ(sbp_packed_osr_content_decode(info.encoded_data, 19, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_packed_osr_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs3,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_packed_osr_content_t t{};

  for (uint8_t i = 0; i < 19; i++) {
    EXPECT_EQ(sbp_packed_osr_content_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs4
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs4() {
    assign(test_struct_.fit_interval, 1060346971);
    assign(test_struct_.health_bits, 115);
    assign(test_struct_.sid.code, 93);
    assign(test_struct_.sid.sat, 70);
    assign(test_struct_.toe.tow, 1645528456);
    assign(test_struct_.toe.wn, 39419);
    assign(test_struct_.ura, 3505.199951);
    assign(test_struct_.valid, 250);
  }

  struct TestStructInfo {
    sbp_ephemeris_common_content_t test_struct;
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
  sbp_ephemeris_common_content_t test_struct_{};
  uint8_t encoded_data_[18] = {
      70, 93, 136, 197, 20,  98, 251, 153, 51,
      19, 91, 69,  91,  156, 51, 63,  250, 115,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs4,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_ephemeris_common_content_encoded_len(&info.test_struct), 18);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs4,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[18];
  EXPECT_EQ(sbp_ephemeris_common_content_encode(&buf[0], sizeof(buf), &nwritten,
                                                &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 18);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs4,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[18];
  EXPECT_EQ(sbp_ephemeris_common_content_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 18), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs4,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[18];
  for (uint8_t i = 0; i < 18; i++) {
    EXPECT_EQ(sbp_ephemeris_common_content_encode(&buf[0], i, nullptr,
                                                  &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs4,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_ephemeris_common_content_t t{};
  EXPECT_EQ(
      sbp_ephemeris_common_content_decode(info.encoded_data, 18, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_ephemeris_common_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs4,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_ephemeris_common_content_t t{};
  EXPECT_EQ(
      sbp_ephemeris_common_content_decode(info.encoded_data, 18, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_ephemeris_common_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs4,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_ephemeris_common_content_t t{};

  for (uint8_t i = 0; i < 18; i++) {
    EXPECT_EQ(
        sbp_ephemeris_common_content_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs5
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs5() {
    assign(test_struct_.fit_interval, 195023785);
    assign(test_struct_.health_bits, 96);
    assign(test_struct_.sid.code, 162);
    assign(test_struct_.sid.sat, 5);
    assign(test_struct_.toe.tow, 2868221875);
    assign(test_struct_.toe.wn, 459);
    assign(test_struct_.ura, 7160.2);
    assign(test_struct_.valid, 70);
  }

  struct TestStructInfo {
    sbp_ephemeris_common_content_dep_b_t test_struct;
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
  sbp_ephemeris_common_content_dep_b_t test_struct_{};
  uint8_t encoded_data_[22] = {
      5,  162, 179, 151, 245, 170, 203, 1,   51, 51, 51,
      51, 51,  248, 187, 64,  169, 211, 159, 11, 70, 96,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs5,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_ephemeris_common_content_dep_b_encoded_len(&info.test_struct),
            22);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs5,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[22];
  EXPECT_EQ(sbp_ephemeris_common_content_dep_b_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 22);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs5,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[22];
  EXPECT_EQ(sbp_ephemeris_common_content_dep_b_encode(
                &buf[0], sizeof(buf), nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 22), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs5,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[22];
  for (uint8_t i = 0; i < 22; i++) {
    EXPECT_EQ(sbp_ephemeris_common_content_dep_b_encode(&buf[0], i, nullptr,
                                                        &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs5,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_ephemeris_common_content_dep_b_t t{};
  EXPECT_EQ(sbp_ephemeris_common_content_dep_b_decode(info.encoded_data, 22,
                                                      &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_ephemeris_common_content_dep_b_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs5,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_ephemeris_common_content_dep_b_t t{};
  EXPECT_EQ(sbp_ephemeris_common_content_dep_b_decode(info.encoded_data, 22,
                                                      nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_ephemeris_common_content_dep_b_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs5,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_ephemeris_common_content_dep_b_t t{};

  for (uint8_t i = 0; i < 22; i++) {
    EXPECT_EQ(sbp_ephemeris_common_content_dep_b_decode(info.encoded_data, i,
                                                        nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs6
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs6() {
    assign(test_struct_.fit_interval, 3607180585);
    assign(test_struct_.health_bits, 113);
    assign(test_struct_.sid.code, 225);
    assign(test_struct_.sid.sat, 41585);
    assign(test_struct_.toe.tow, 1655038953);
    assign(test_struct_.toe.wn, 45402);
    assign(test_struct_.ura, 3126.2);
    assign(test_struct_.valid, 199);
  }

  struct TestStructInfo {
    sbp_ephemeris_common_content_dep_a_t test_struct;
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
  sbp_ephemeris_common_content_dep_a_t test_struct_{};
  uint8_t encoded_data_[24] = {
      113, 162, 225, 0,   233, 227, 165, 98, 90, 177, 102, 102,
      102, 102, 102, 108, 168, 64,  41,  53, 1,  215, 199, 113,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs6,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_ephemeris_common_content_dep_a_encoded_len(&info.test_struct),
            24);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs6,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[24];
  EXPECT_EQ(sbp_ephemeris_common_content_dep_a_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 24);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs6,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[24];
  EXPECT_EQ(sbp_ephemeris_common_content_dep_a_encode(
                &buf[0], sizeof(buf), nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 24), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs6,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[24];
  for (uint8_t i = 0; i < 24; i++) {
    EXPECT_EQ(sbp_ephemeris_common_content_dep_a_encode(&buf[0], i, nullptr,
                                                        &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs6,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_ephemeris_common_content_dep_a_t t{};
  EXPECT_EQ(sbp_ephemeris_common_content_dep_a_decode(info.encoded_data, 24,
                                                      &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_ephemeris_common_content_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs6,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_ephemeris_common_content_dep_a_t t{};
  EXPECT_EQ(sbp_ephemeris_common_content_dep_a_decode(info.encoded_data, 24,
                                                      nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_ephemeris_common_content_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs6,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_ephemeris_common_content_dep_a_t t{};

  for (uint8_t i = 0; i < 24; i++) {
    EXPECT_EQ(sbp_ephemeris_common_content_dep_a_decode(info.encoded_data, i,
                                                        nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs7
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs7() {
    assign(test_struct_.n_obs, 33);
    assign(test_struct_.t.tow, 4166840455);
    assign(test_struct_.t.wn, 14864);
  }

  struct TestStructInfo {
    sbp_observation_header_dep_t test_struct;
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
  sbp_observation_header_dep_t test_struct_{};
  uint8_t encoded_data_[7] = {
      135, 240, 92, 248, 16, 58, 33,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs7,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_observation_header_dep_encoded_len(&info.test_struct), 7);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs7,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[7];
  EXPECT_EQ(sbp_observation_header_dep_encode(&buf[0], sizeof(buf), &nwritten,
                                              &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 7);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs7,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[7];
  EXPECT_EQ(sbp_observation_header_dep_encode(&buf[0], sizeof(buf), nullptr,
                                              &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 7), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs7,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[7];
  for (uint8_t i = 0; i < 7; i++) {
    EXPECT_EQ(sbp_observation_header_dep_encode(&buf[0], i, nullptr,
                                                &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs7,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_observation_header_dep_t t{};
  EXPECT_EQ(sbp_observation_header_dep_decode(info.encoded_data, 7, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_observation_header_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs7,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_observation_header_dep_t t{};
  EXPECT_EQ(
      sbp_observation_header_dep_decode(info.encoded_data, 7, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_observation_header_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs7,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_observation_header_dep_t t{};

  for (uint8_t i = 0; i < 7; i++) {
    EXPECT_EQ(
        sbp_observation_header_dep_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs8
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs8() {
    assign(test_struct_.f, 217);
    assign(test_struct_.i, 1138701703);
  }

  struct TestStructInfo {
    sbp_carrier_phase_dep_a_t test_struct;
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
  sbp_carrier_phase_dep_a_t test_struct_{};
  uint8_t encoded_data_[5] = {
      135, 53, 223, 67, 217,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs8,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_carrier_phase_dep_a_encoded_len(&info.test_struct), 5);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs8,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[5];
  EXPECT_EQ(sbp_carrier_phase_dep_a_encode(&buf[0], sizeof(buf), &nwritten,
                                           &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 5);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs8,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[5];
  EXPECT_EQ(sbp_carrier_phase_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 5), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs8,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[5];
  for (uint8_t i = 0; i < 5; i++) {
    EXPECT_EQ(
        sbp_carrier_phase_dep_a_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs8,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_carrier_phase_dep_a_t t{};
  EXPECT_EQ(sbp_carrier_phase_dep_a_decode(info.encoded_data, 5, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_carrier_phase_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs8,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_carrier_phase_dep_a_t t{};
  EXPECT_EQ(sbp_carrier_phase_dep_a_decode(info.encoded_data, 5, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_carrier_phase_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs8,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_carrier_phase_dep_a_t t{};

  for (uint8_t i = 0; i < 5; i++) {
    EXPECT_EQ(sbp_carrier_phase_dep_a_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs9
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs9() {
    assign(test_struct_.L.f, 211);
    assign(test_struct_.L.i, -1008767887);
    assign(test_struct_.P, 1469217046);
    assign(test_struct_.cn0, 175);
    assign(test_struct_.lock, 52050);
    assign(test_struct_.prn, 147);
  }

  struct TestStructInfo {
    sbp_packed_obs_content_dep_a_t test_struct;
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
  sbp_packed_obs_content_dep_a_t test_struct_{};
  uint8_t encoded_data_[13] = {
      22, 121, 146, 87, 113, 108, 223, 195, 211, 175, 82, 203, 147,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs9,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_packed_obs_content_dep_a_encoded_len(&info.test_struct), 13);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs9,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[13];
  EXPECT_EQ(sbp_packed_obs_content_dep_a_encode(&buf[0], sizeof(buf), &nwritten,
                                                &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 13);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs9,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[13];
  EXPECT_EQ(sbp_packed_obs_content_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 13), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs9,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[13];
  for (uint8_t i = 0; i < 13; i++) {
    EXPECT_EQ(sbp_packed_obs_content_dep_a_encode(&buf[0], i, nullptr,
                                                  &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs9,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_packed_obs_content_dep_a_t t{};
  EXPECT_EQ(
      sbp_packed_obs_content_dep_a_decode(info.encoded_data, 13, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_packed_obs_content_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs9,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_packed_obs_content_dep_a_t t{};
  EXPECT_EQ(
      sbp_packed_obs_content_dep_a_decode(info.encoded_data, 13, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_packed_obs_content_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs9,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_packed_obs_content_dep_a_t t{};

  for (uint8_t i = 0; i < 13; i++) {
    EXPECT_EQ(
        sbp_packed_obs_content_dep_a_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs10
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs10() {
    assign(test_struct_.L.f, 155);
    assign(test_struct_.L.i, -351247318);
    assign(test_struct_.P, 2918161029);
    assign(test_struct_.cn0, 223);
    assign(test_struct_.lock, 17054);
    assign(test_struct_.sid.code, 103);
    assign(test_struct_.sid.reserved, 208);
    assign(test_struct_.sid.sat, 42698);
  }

  struct TestStructInfo {
    sbp_packed_obs_content_dep_b_t test_struct;
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
  sbp_packed_obs_content_dep_b_t test_struct_{};
  uint8_t encoded_data_[16] = {
      133, 154, 239, 173, 42,  100, 16,  235,
      155, 223, 158, 66,  202, 166, 103, 208,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs10,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_packed_obs_content_dep_b_encoded_len(&info.test_struct), 16);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs10,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[16];
  EXPECT_EQ(sbp_packed_obs_content_dep_b_encode(&buf[0], sizeof(buf), &nwritten,
                                                &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 16);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs10,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[16];
  EXPECT_EQ(sbp_packed_obs_content_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 16), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs10,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[16];
  for (uint8_t i = 0; i < 16; i++) {
    EXPECT_EQ(sbp_packed_obs_content_dep_b_encode(&buf[0], i, nullptr,
                                                  &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs10,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_packed_obs_content_dep_b_t t{};
  EXPECT_EQ(
      sbp_packed_obs_content_dep_b_decode(info.encoded_data, 16, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_packed_obs_content_dep_b_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs10,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_packed_obs_content_dep_b_t t{};
  EXPECT_EQ(
      sbp_packed_obs_content_dep_b_decode(info.encoded_data, 16, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_packed_obs_content_dep_b_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs10,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_packed_obs_content_dep_b_t t{};

  for (uint8_t i = 0; i < 16; i++) {
    EXPECT_EQ(
        sbp_packed_obs_content_dep_b_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs11
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs11() {
    assign(test_struct_.L.f, 78);
    assign(test_struct_.L.i, 1582873968);
    assign(test_struct_.P, 3329272896);
    assign(test_struct_.cn0, 113);
    assign(test_struct_.lock, 26674);
    assign(test_struct_.sid.code, 160);
    assign(test_struct_.sid.reserved, 90);
    assign(test_struct_.sid.sat, 53544);
  }

  struct TestStructInfo {
    sbp_packed_obs_content_dep_c_t test_struct;
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
  sbp_packed_obs_content_dep_c_t test_struct_{};
  uint8_t encoded_data_[16] = {
      64, 172, 112, 198, 112, 189, 88, 94, 78, 113, 50, 104, 40, 209, 160, 90,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs11,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_packed_obs_content_dep_c_encoded_len(&info.test_struct), 16);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs11,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[16];
  EXPECT_EQ(sbp_packed_obs_content_dep_c_encode(&buf[0], sizeof(buf), &nwritten,
                                                &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 16);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs11,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[16];
  EXPECT_EQ(sbp_packed_obs_content_dep_c_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 16), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs11,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[16];
  for (uint8_t i = 0; i < 16; i++) {
    EXPECT_EQ(sbp_packed_obs_content_dep_c_encode(&buf[0], i, nullptr,
                                                  &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs11,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_packed_obs_content_dep_c_t t{};
  EXPECT_EQ(
      sbp_packed_obs_content_dep_c_decode(info.encoded_data, 16, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_packed_obs_content_dep_c_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs11,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_packed_obs_content_dep_c_t t{};
  EXPECT_EQ(
      sbp_packed_obs_content_dep_c_decode(info.encoded_data, 16, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_packed_obs_content_dep_c_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs11,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_packed_obs_content_dep_c_t t{};

  for (uint8_t i = 0; i < 16; i++) {
    EXPECT_EQ(
        sbp_packed_obs_content_dep_c_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs12
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs12() {
    assign(test_struct_.bds_active, 1076821549129);
    assign(test_struct_.bds_b2, 878366344419);
    assign(test_struct_.bds_b2a, 929021071030);
    assign(test_struct_.bds_d2nav, 993705552075);
    assign(test_struct_.gal_active, 713683388100);
    assign(test_struct_.gal_e5, 82813285742);
    assign(test_struct_.glo_active, 3618100845);
    assign(test_struct_.glo_l2of, 2612838619);
    assign(test_struct_.glo_l3, 1984440581);
    assign(test_struct_.gps_active, 836207997107);
    assign(test_struct_.gps_l2c, 11856600751);
    assign(test_struct_.gps_l5, 410257746729);
    assign(test_struct_.qzss_active, 2109335123);
    assign(test_struct_.sbas_active, 835833936142);
    assign(test_struct_.sbas_l5, 898852327014);
  }

  struct TestStructInfo {
    sbp_gnss_capb_t test_struct;
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
  sbp_gnss_capb_t test_struct_{};
  uint8_t encoded_data_[104] = {
      179, 112, 225, 177, 194, 0,   0,   0,   175, 94,  181, 194, 2,   0,   0,
      0,   41,  107, 68,  133, 95,  0,   0,   0,   109, 214, 167, 215, 219, 192,
      188, 155, 5,   41,  72,  118, 14,  185, 149, 155, 194, 0,   0,   0,   102,
      14,  198, 71,  209, 0,   0,   0,   73,  224, 144, 183, 250, 0,   0,   0,
      203, 104, 119, 93,  231, 0,   0,   0,   227, 196, 182, 130, 204, 0,   0,
      0,   182, 142, 248, 77,  216, 0,   0,   0,   83,  230, 185, 125, 196, 70,
      216, 42,  166, 0,   0,   0,   110, 117, 14,  72,  19,  0,   0,   0,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs12,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_gnss_capb_encoded_len(&info.test_struct), 104);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs12,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[104];
  EXPECT_EQ(
      sbp_gnss_capb_encode(&buf[0], sizeof(buf), &nwritten, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(nwritten, 104);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs12,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[104];
  EXPECT_EQ(
      sbp_gnss_capb_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 104), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs12,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[104];
  for (uint8_t i = 0; i < 104; i++) {
    EXPECT_EQ(sbp_gnss_capb_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs12,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_gnss_capb_t t{};
  EXPECT_EQ(sbp_gnss_capb_decode(info.encoded_data, 104, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_gnss_capb_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs12,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_gnss_capb_t t{};
  EXPECT_EQ(sbp_gnss_capb_decode(info.encoded_data, 104, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_gnss_capb_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs12,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_gnss_capb_t t{};

  for (uint8_t i = 0; i < 104; i++) {
    EXPECT_EQ(sbp_gnss_capb_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs13
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs13() {
    assign(test_struct_.fit_interval, 3112182001);
    assign(test_struct_.health_bits, 24);
    assign(test_struct_.sid.code, 181);
    assign(test_struct_.sid.sat, 163);
    assign(test_struct_.toa.tow, 3325838080);
    assign(test_struct_.toa.wn, 15069);
    assign(test_struct_.ura, 8042.2);
    assign(test_struct_.valid, 64);
  }

  struct TestStructInfo {
    sbp_almanac_common_content_t test_struct;
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
  sbp_almanac_common_content_t test_struct_{};
  uint8_t encoded_data_[22] = {
      163, 181, 0,   67,  60, 198, 221, 58,  51,  51, 51,
      51,  51,  106, 191, 64, 241, 32,  128, 185, 64, 24,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs13,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_almanac_common_content_encoded_len(&info.test_struct), 22);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs13,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[22];
  EXPECT_EQ(sbp_almanac_common_content_encode(&buf[0], sizeof(buf), &nwritten,
                                              &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 22);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs13,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[22];
  EXPECT_EQ(sbp_almanac_common_content_encode(&buf[0], sizeof(buf), nullptr,
                                              &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 22), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs13,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[22];
  for (uint8_t i = 0; i < 22; i++) {
    EXPECT_EQ(sbp_almanac_common_content_encode(&buf[0], i, nullptr,
                                                &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs13,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_almanac_common_content_t t{};
  EXPECT_EQ(
      sbp_almanac_common_content_decode(info.encoded_data, 22, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_almanac_common_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs13,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_almanac_common_content_t t{};
  EXPECT_EQ(
      sbp_almanac_common_content_decode(info.encoded_data, 22, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_almanac_common_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs13,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_almanac_common_content_t t{};

  for (uint8_t i = 0; i < 22; i++) {
    EXPECT_EQ(
        sbp_almanac_common_content_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs14
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs14() {
    assign(test_struct_.fit_interval, 4108237589);
    assign(test_struct_.health_bits, 142);
    assign(test_struct_.sid.code, 32);
    assign(test_struct_.sid.reserved, 10);
    assign(test_struct_.sid.sat, 57244);
    assign(test_struct_.toa.tow, 1277272173);
    assign(test_struct_.toa.wn, 2954);
    assign(test_struct_.ura, 6746.2);
    assign(test_struct_.valid, 52);
  }

  struct TestStructInfo {
    sbp_almanac_common_content_dep_t test_struct;
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
  sbp_almanac_common_content_dep_t test_struct_{};
  uint8_t encoded_data_[24] = {
      156, 223, 32, 10, 109, 160, 33, 76,  138, 11,  51, 51,
      51,  51,  51, 90, 186, 64,  21, 187, 222, 244, 52, 142,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs14,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_almanac_common_content_dep_encoded_len(&info.test_struct), 24);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs14,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[24];
  EXPECT_EQ(sbp_almanac_common_content_dep_encode(&buf[0], sizeof(buf),
                                                  &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 24);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs14,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[24];
  EXPECT_EQ(sbp_almanac_common_content_dep_encode(&buf[0], sizeof(buf), nullptr,
                                                  &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 24), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs14,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[24];
  for (uint8_t i = 0; i < 24; i++) {
    EXPECT_EQ(sbp_almanac_common_content_dep_encode(&buf[0], i, nullptr,
                                                    &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs14,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_almanac_common_content_dep_t t{};
  EXPECT_EQ(
      sbp_almanac_common_content_dep_decode(info.encoded_data, 24, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_almanac_common_content_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs14,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_almanac_common_content_dep_t t{};
  EXPECT_EQ(
      sbp_almanac_common_content_dep_decode(info.encoded_data, 24, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_almanac_common_content_dep_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs14,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_almanac_common_content_dep_t t{};

  for (uint8_t i = 0; i < 24; i++) {
    EXPECT_EQ(sbp_almanac_common_content_dep_decode(info.encoded_data, i,
                                                    nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_observation_observation_structs15
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_observation_observation_structs15() {
    assign(test_struct_.az, 127);
    assign(test_struct_.el, 87);
    assign(test_struct_.sid.code, 46);
    assign(test_struct_.sid.sat, 115);
  }

  struct TestStructInfo {
    sbp_sv_az_el_t test_struct;
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
  sbp_sv_az_el_t test_struct_{};
  uint8_t encoded_data_[4] = {
      115,
      46,
      127,
      87,
  };
};

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs15,
       EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_sv_az_el_encoded_len(&info.test_struct), 4);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs15,
       FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[4];
  EXPECT_EQ(
      sbp_sv_az_el_encode(&buf[0], sizeof(buf), &nwritten, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(nwritten, 4);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs15,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  EXPECT_EQ(
      sbp_sv_az_el_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 4), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs15,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(sbp_sv_az_el_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs15,
       FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_sv_az_el_t t{};
  EXPECT_EQ(sbp_sv_az_el_decode(info.encoded_data, 4, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_sv_az_el_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs15,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_sv_az_el_t t{};
  EXPECT_EQ(sbp_sv_az_el_decode(info.encoded_data, 4, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_sv_az_el_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_observation_observation_structs15,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_sv_az_el_t t{};

  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(sbp_sv_az_el_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace