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
// spec/tests/yaml/swiftnav/sbp/signing/test_signing_structs.yaml by
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

class Test_Struct_auto_check_sbp_signing_signing_structs0
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_signing_signing_structs0() {
    assign(test_struct_.day, 130);
    assign(test_struct_.hours, 58);
    assign(test_struct_.minutes, 5);
    assign(test_struct_.month, 64);
    assign(test_struct_.ns, 344202884);
    assign(test_struct_.seconds, 121);
    assign(test_struct_.year, 31718);
  }

  struct TestStructInfo {
    sbp_utc_time_t test_struct;
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
  sbp_utc_time_t test_struct_{};
  uint8_t encoded_data_[11] = {
      230, 123, 64, 130, 58, 5, 121, 132, 30, 132, 20,
  };
};

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_utc_time_encoded_len(&info.test_struct), 11);
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[11];
  EXPECT_EQ(
      sbp_utc_time_encode(&buf[0], sizeof(buf), &nwritten, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(nwritten, 11);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs0,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[11];
  EXPECT_EQ(
      sbp_utc_time_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 11), 0);
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs0,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[11];
  for (uint8_t i = 0; i < 11; i++) {
    EXPECT_EQ(sbp_utc_time_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_utc_time_t t{};
  EXPECT_EQ(sbp_utc_time_decode(info.encoded_data, 11, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_utc_time_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs0,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_utc_time_t t{};
  EXPECT_EQ(sbp_utc_time_decode(info.encoded_data, 11, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_utc_time_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs0,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_utc_time_t t{};

  for (uint8_t i = 0; i < 11; i++) {
    EXPECT_EQ(sbp_utc_time_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_signing_signing_structs1
    : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_signing_signing_structs1() {
    assign(test_struct_.data[0], 189);

    assign(test_struct_.data[1], 249);

    assign(test_struct_.data[2], 166);

    assign(test_struct_.data[3], 211);

    assign(test_struct_.data[4], 246);

    assign(test_struct_.data[5], 7);

    assign(test_struct_.data[6], 83);

    assign(test_struct_.data[7], 222);

    assign(test_struct_.data[8], 182);

    assign(test_struct_.data[9], 121);

    assign(test_struct_.data[10], 22);

    assign(test_struct_.data[11], 64);

    assign(test_struct_.data[12], 18);

    assign(test_struct_.data[13], 190);

    assign(test_struct_.data[14], 156);

    assign(test_struct_.data[15], 212);

    assign(test_struct_.data[16], 23);

    assign(test_struct_.data[17], 15);

    assign(test_struct_.data[18], 222);

    assign(test_struct_.data[19], 41);

    assign(test_struct_.data[20], 5);

    assign(test_struct_.data[21], 208);

    assign(test_struct_.data[22], 49);

    assign(test_struct_.data[23], 127);

    assign(test_struct_.data[24], 30);

    assign(test_struct_.data[25], 82);

    assign(test_struct_.data[26], 214);

    assign(test_struct_.data[27], 253);

    assign(test_struct_.data[28], 4);

    assign(test_struct_.data[29], 151);

    assign(test_struct_.data[30], 122);

    assign(test_struct_.data[31], 254);

    assign(test_struct_.data[32], 58);

    assign(test_struct_.data[33], 23);

    assign(test_struct_.data[34], 117);

    assign(test_struct_.data[35], 155);

    assign(test_struct_.data[36], 233);

    assign(test_struct_.data[37], 180);

    assign(test_struct_.data[38], 118);

    assign(test_struct_.data[39], 207);

    assign(test_struct_.data[40], 160);

    assign(test_struct_.data[41], 84);

    assign(test_struct_.data[42], 117);

    assign(test_struct_.data[43], 57);

    assign(test_struct_.data[44], 46);

    assign(test_struct_.data[45], 232);

    assign(test_struct_.data[46], 206);

    assign(test_struct_.data[47], 68);

    assign(test_struct_.data[48], 155);

    assign(test_struct_.data[49], 175);

    assign(test_struct_.data[50], 51);

    assign(test_struct_.data[51], 186);

    assign(test_struct_.data[52], 111);

    assign(test_struct_.data[53], 240);

    assign(test_struct_.data[54], 33);

    assign(test_struct_.data[55], 20);

    assign(test_struct_.data[56], 107);

    assign(test_struct_.data[57], 63);

    assign(test_struct_.data[58], 114);

    assign(test_struct_.data[59], 204);

    assign(test_struct_.data[60], 115);

    assign(test_struct_.data[61], 64);

    assign(test_struct_.data[62], 241);

    assign(test_struct_.data[63], 145);

    assign(test_struct_.data[64], 216);

    assign(test_struct_.data[65], 160);

    assign(test_struct_.data[66], 96);

    assign(test_struct_.data[67], 214);

    assign(test_struct_.data[68], 53);

    assign(test_struct_.data[69], 181);

    assign(test_struct_.data[70], 120);

    assign(test_struct_.data[71], 132);
    assign(test_struct_.len, 166);
  }

  struct TestStructInfo {
    sbp_ecdsa_signature_t test_struct;
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
  sbp_ecdsa_signature_t test_struct_{};
  uint8_t encoded_data_[73] = {
      166, 189, 249, 166, 211, 246, 7,   83,  222, 182, 121, 22,  64,  18,  190,
      156, 212, 23,  15,  222, 41,  5,   208, 49,  127, 30,  82,  214, 253, 4,
      151, 122, 254, 58,  23,  117, 155, 233, 180, 118, 207, 160, 84,  117, 57,
      46,  232, 206, 68,  155, 175, 51,  186, 111, 240, 33,  20,  107, 63,  114,
      204, 115, 64,  241, 145, 216, 160, 96,  214, 53,  181, 120, 132,
  };
};

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs1, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_ecdsa_signature_encoded_len(&info.test_struct), 73);
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs1, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[73];
  EXPECT_EQ(sbp_ecdsa_signature_encode(&buf[0], sizeof(buf), &nwritten,
                                       &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 73);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs1,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[73];
  EXPECT_EQ(sbp_ecdsa_signature_encode(&buf[0], sizeof(buf), nullptr,
                                       &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 73), 0);
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs1,
       FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[73];
  for (uint8_t i = 0; i < 73; i++) {
    EXPECT_EQ(
        sbp_ecdsa_signature_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs1, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_ecdsa_signature_t t{};
  EXPECT_EQ(sbp_ecdsa_signature_decode(info.encoded_data, 73, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_ecdsa_signature_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs1,
       FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_ecdsa_signature_t t{};
  EXPECT_EQ(sbp_ecdsa_signature_decode(info.encoded_data, 73, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_ecdsa_signature_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_signing_signing_structs1,
       FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_ecdsa_signature_t t{};

  for (uint8_t i = 0; i < 73; i++) {
    EXPECT_EQ(sbp_ecdsa_signature_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace