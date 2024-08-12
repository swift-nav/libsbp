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
// spec/tests/yaml/swiftnav/sbp/soln_meta/test_soln_meta_structs.yaml by
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

class Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs0
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs0() {
    assign(test_struct_.flags, 237);
    assign(test_struct_.sensor_type, 102);
  }

  struct TestStructInfo {
    sbp_solution_input_type_t test_struct;
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
  sbp_solution_input_type_t test_struct_{};
  uint8_t encoded_data_[2] = {
      102,
      237,
  };
};

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_solution_input_type_encoded_len(&info.test_struct), 2);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[2];
  EXPECT_EQ(sbp_solution_input_type_encode(&buf[0], sizeof(buf), &nwritten,
                                           &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 2);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[2];
  EXPECT_EQ(sbp_solution_input_type_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 2), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs0,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[2];
  for (uint8_t i = 0; i < 2; i++) {
    EXPECT_EQ(
        sbp_solution_input_type_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_solution_input_type_t t{};
  EXPECT_EQ(sbp_solution_input_type_decode(info.encoded_data, 2, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_solution_input_type_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs0,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_solution_input_type_t t{};
  EXPECT_EQ(sbp_solution_input_type_decode(info.encoded_data, 2, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_solution_input_type_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs0,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_solution_input_type_t t{};

  for (uint8_t i = 0; i < 2; i++) {
    EXPECT_EQ(sbp_solution_input_type_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs1
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs1() {
    assign(test_struct_.flags, 54);
  }

  struct TestStructInfo {
    sbp_gnss_input_type_t test_struct;
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
  sbp_gnss_input_type_t test_struct_{};
  uint8_t encoded_data_[1] = {
      54,
  };
};

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs1, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_gnss_input_type_encoded_len(&info.test_struct), 1);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs1, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[1];
  EXPECT_EQ(sbp_gnss_input_type_encode(&buf[0], sizeof(buf), &nwritten,
                                       &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 1);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs1,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[1];
  EXPECT_EQ(sbp_gnss_input_type_encode(&buf[0], sizeof(buf), nullptr,
                                       &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 1), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs1,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[1];
  for (uint8_t i = 0; i < 1; i++) {
    EXPECT_EQ(
        sbp_gnss_input_type_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs1, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_gnss_input_type_t t{};
  EXPECT_EQ(sbp_gnss_input_type_decode(info.encoded_data, 1, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_gnss_input_type_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs1,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_gnss_input_type_t t{};
  EXPECT_EQ(sbp_gnss_input_type_decode(info.encoded_data, 1, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_gnss_input_type_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs1,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_gnss_input_type_t t{};

  for (uint8_t i = 0; i < 1; i++) {
    EXPECT_EQ(sbp_gnss_input_type_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs2
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs2() {
    assign(test_struct_.flags, 214);
  }

  struct TestStructInfo {
    sbp_imu_input_type_t test_struct;
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
  sbp_imu_input_type_t test_struct_{};
  uint8_t encoded_data_[1] = {
      214,
  };
};

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs2, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_imu_input_type_encoded_len(&info.test_struct), 1);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs2, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[1];
  EXPECT_EQ(sbp_imu_input_type_encode(&buf[0], sizeof(buf), &nwritten,
                                      &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 1);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs2,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[1];
  EXPECT_EQ(sbp_imu_input_type_encode(&buf[0], sizeof(buf), nullptr,
                                      &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 1), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs2,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[1];
  for (uint8_t i = 0; i < 1; i++) {
    EXPECT_EQ(sbp_imu_input_type_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs2, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_imu_input_type_t t{};
  EXPECT_EQ(sbp_imu_input_type_decode(info.encoded_data, 1, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_imu_input_type_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs2,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_imu_input_type_t t{};
  EXPECT_EQ(sbp_imu_input_type_decode(info.encoded_data, 1, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_imu_input_type_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs2,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_imu_input_type_t t{};

  for (uint8_t i = 0; i < 1; i++) {
    EXPECT_EQ(sbp_imu_input_type_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs3
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs3() {
    assign(test_struct_.flags, 230);
  }

  struct TestStructInfo {
    sbp_odo_input_type_t test_struct;
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
  sbp_odo_input_type_t test_struct_{};
  uint8_t encoded_data_[1] = {
      230,
  };
};

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs3, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_odo_input_type_encoded_len(&info.test_struct), 1);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs3, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[1];
  EXPECT_EQ(sbp_odo_input_type_encode(&buf[0], sizeof(buf), &nwritten,
                                      &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 1);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs3,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[1];
  EXPECT_EQ(sbp_odo_input_type_encode(&buf[0], sizeof(buf), nullptr,
                                      &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 1), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs3,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[1];
  for (uint8_t i = 0; i < 1; i++) {
    EXPECT_EQ(sbp_odo_input_type_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs3, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_odo_input_type_t t{};
  EXPECT_EQ(sbp_odo_input_type_decode(info.encoded_data, 1, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_odo_input_type_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs3,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_odo_input_type_t t{};
  EXPECT_EQ(sbp_odo_input_type_decode(info.encoded_data, 1, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_odo_input_type_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_soln_meta_soln_meta_structs3,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_odo_input_type_t t{};

  for (uint8_t i = 0; i < 1; i++) {
    EXPECT_EQ(sbp_odo_input_type_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace