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
// spec/tests/yaml/swiftnav/sbp/piksi/test_piksi_structs.yaml by generate.py. Do
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

class Test_Struct_auto_check_sbp_piksi_piksi_structs0 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_piksi_piksi_structs0() {
    assign(test_struct_.crc_error_count, 4092);
    assign(test_struct_.io_error_count, 53609);
    assign(test_struct_.rx_buffer_level, 172);
    assign(test_struct_.rx_throughput, 1132.199951);
    assign(test_struct_.tx_buffer_level, 154);
    assign(test_struct_.tx_throughput, 9820.200195);
  }

  struct TestStructInfo {
    sbp_uart_channel_t test_struct;
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
  sbp_uart_channel_t test_struct_{};
  uint8_t encoded_data_[14] = {
      205, 112, 25, 70, 102, 134, 141, 68, 252, 15, 105, 209, 154, 172,
  };
};

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_uart_channel_encoded_len(&info.test_struct), 14);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[14];
  EXPECT_EQ(sbp_uart_channel_encode(&buf[0], sizeof(buf), &nwritten,
                                    &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 14);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[14];
  EXPECT_EQ(
      sbp_uart_channel_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 14), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs0, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[14];
  for (uint8_t i = 0; i < 14; i++) {
    EXPECT_EQ(sbp_uart_channel_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_uart_channel_t t{};
  EXPECT_EQ(sbp_uart_channel_decode(info.encoded_data, 14, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_uart_channel_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs0,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_uart_channel_t t{};
  EXPECT_EQ(sbp_uart_channel_decode(info.encoded_data, 14, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_uart_channel_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs0, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_uart_channel_t t{};

  for (uint8_t i = 0; i < 14; i++) {
    EXPECT_EQ(sbp_uart_channel_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_piksi_piksi_structs1 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_piksi_piksi_structs1() {
    assign(test_struct_.avg, 983064568);
    assign(test_struct_.current, -80492514);
    assign(test_struct_.pmax, 1099066158);
    assign(test_struct_.pmin, -1233728064);
  }

  struct TestStructInfo {
    sbp_period_t test_struct;
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
  sbp_period_t test_struct_{};
  uint8_t encoded_data_[16] = {
      248, 95, 152, 58, 192, 205, 118, 182, 46, 107, 130, 65, 30, 200, 51, 251,
  };
};

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs1, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_period_encoded_len(&info.test_struct), 16);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs1, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[16];
  EXPECT_EQ(
      sbp_period_encode(&buf[0], sizeof(buf), &nwritten, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(nwritten, 16);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs1,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[16];
  EXPECT_EQ(sbp_period_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 16), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs1, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[16];
  for (uint8_t i = 0; i < 16; i++) {
    EXPECT_EQ(sbp_period_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs1, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_period_t t{};
  EXPECT_EQ(sbp_period_decode(info.encoded_data, 16, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_period_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs1,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_period_t t{};
  EXPECT_EQ(sbp_period_decode(info.encoded_data, 16, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_period_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs1, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_period_t t{};

  for (uint8_t i = 0; i < 16; i++) {
    EXPECT_EQ(sbp_period_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_piksi_piksi_structs2 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_piksi_piksi_structs2() {
    assign(test_struct_.avg, -2108990172);
    assign(test_struct_.current, 419199087);
    assign(test_struct_.lmax, 346613123);
    assign(test_struct_.lmin, 700673711);
  }

  struct TestStructInfo {
    sbp_latency_t test_struct;
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
  sbp_latency_t test_struct_{};
  uint8_t encoded_data_[16] = {
      36, 93, 75, 130, 175, 110, 195, 41, 131, 229, 168, 20, 111, 120, 252, 24,
  };
};

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs2, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_latency_encoded_len(&info.test_struct), 16);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs2, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[16];
  EXPECT_EQ(
      sbp_latency_encode(&buf[0], sizeof(buf), &nwritten, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(nwritten, 16);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs2,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[16];
  EXPECT_EQ(
      sbp_latency_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 16), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs2, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[16];
  for (uint8_t i = 0; i < 16; i++) {
    EXPECT_EQ(sbp_latency_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs2, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_latency_t t{};
  EXPECT_EQ(sbp_latency_decode(info.encoded_data, 16, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_latency_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs2,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_latency_t t{};
  EXPECT_EQ(sbp_latency_decode(info.encoded_data, 16, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_latency_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs2, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_latency_t t{};

  for (uint8_t i = 0; i < 16; i++) {
    EXPECT_EQ(sbp_latency_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_piksi_piksi_structs3 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_piksi_piksi_structs3() {
    assign(test_struct_.duration, 126555400413);
    {
      const char assign_string[] = {(char)105, (char)102, (char)48};
      memcpy(test_struct_.interface_name, assign_string, sizeof(assign_string));
    }
    assign(test_struct_.rx_bytes, 2785204760);
    assign(test_struct_.total_bytes, 149958941973);
    assign(test_struct_.tx_bytes, 1462542650);
  }

  struct TestStructInfo {
    sbp_network_usage_t test_struct;
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
  sbp_network_usage_t test_struct_{};
  uint8_t encoded_data_[40] = {
      221, 40, 74, 119, 29, 0,   0,  0,   21, 221, 63,  234, 34, 0,
      0,   0,  24, 218, 2,  166, 58, 161, 44, 87,  105, 102, 48, 0,
      0,   0,  0,  0,   0,  0,   0,  0,   0,  0,   0,   0,
  };
};

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs3, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_network_usage_encoded_len(&info.test_struct), 40);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs3, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[40];
  EXPECT_EQ(sbp_network_usage_encode(&buf[0], sizeof(buf), &nwritten,
                                     &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 40);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs3,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[40];
  EXPECT_EQ(sbp_network_usage_encode(&buf[0], sizeof(buf), nullptr,
                                     &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 40), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs3, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[40];
  for (uint8_t i = 0; i < 40; i++) {
    EXPECT_EQ(sbp_network_usage_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs3, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_network_usage_t t{};
  EXPECT_EQ(sbp_network_usage_decode(info.encoded_data, 40, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_network_usage_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs3,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_network_usage_t t{};
  EXPECT_EQ(sbp_network_usage_decode(info.encoded_data, 40, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_network_usage_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_piksi_piksi_structs3, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_network_usage_t t{};

  for (uint8_t i = 0; i < 40; i++) {
    EXPECT_EQ(sbp_network_usage_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace
