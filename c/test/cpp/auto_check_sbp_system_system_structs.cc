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
// spec/tests/yaml/swiftnav/sbp/system/test_system_structs.yaml by generate.py.
// Do not modify by hand!

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

class Test_Struct_auto_check_sbp_system_system_structs0
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_system_system_structs0() {
    assign(test_struct_.component, 53869);
    assign(test_struct_.generic, 81);
    assign(test_struct_.specific, 106);
  }

  struct TestStructInfo {
    sbp_sub_system_report_t test_struct;
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
  sbp_sub_system_report_t test_struct_{};
  uint8_t encoded_data_[4] = {
      109,
      210,
      81,
      106,
  };
};

TEST_F(Test_Struct_auto_check_sbp_system_system_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_sub_system_report_encoded_len(&info.test_struct), 4);
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[4];
  EXPECT_EQ(sbp_sub_system_report_encode(&buf[0], sizeof(buf), &nwritten,
                                         &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 4);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  EXPECT_EQ(sbp_sub_system_report_encode(&buf[0], sizeof(buf), nullptr,
                                         &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 4), 0);
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs0, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(
        sbp_sub_system_report_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_sub_system_report_t t{};
  EXPECT_EQ(sbp_sub_system_report_decode(info.encoded_data, 4, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_sub_system_report_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs0,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_sub_system_report_t t{};
  EXPECT_EQ(sbp_sub_system_report_decode(info.encoded_data, 4, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_sub_system_report_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs0, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_sub_system_report_t t{};

  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(sbp_sub_system_report_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_system_system_structs1
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_system_system_structs1() {
    assign(test_struct_.report.component, 45733);
    assign(test_struct_.report.generic, 205);
    assign(test_struct_.report.specific, 203);
    assign(test_struct_.uptime, 1251193470);
  }

  struct TestStructInfo {
    sbp_status_journal_item_t test_struct;
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
  sbp_status_journal_item_t test_struct_{};
  uint8_t encoded_data_[8] = {
      126, 178, 147, 74, 165, 178, 205, 203,
  };
};

TEST_F(Test_Struct_auto_check_sbp_system_system_structs1, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_status_journal_item_encoded_len(&info.test_struct), 8);
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs1, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[8];
  EXPECT_EQ(sbp_status_journal_item_encode(&buf[0], sizeof(buf), &nwritten,
                                           &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 8);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs1,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[8];
  EXPECT_EQ(sbp_status_journal_item_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 8), 0);
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs1, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[8];
  for (uint8_t i = 0; i < 8; i++) {
    EXPECT_EQ(
        sbp_status_journal_item_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs1, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_status_journal_item_t t{};
  EXPECT_EQ(sbp_status_journal_item_decode(info.encoded_data, 8, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_status_journal_item_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs1,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_status_journal_item_t t{};
  EXPECT_EQ(sbp_status_journal_item_decode(info.encoded_data, 8, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_status_journal_item_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_system_system_structs1, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_status_journal_item_t t{};

  for (uint8_t i = 0; i < 8; i++) {
    EXPECT_EQ(sbp_status_journal_item_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace
