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
// spec/tests/yaml/swiftnav/sbp/ssr/test_ssr_structs.yaml by generate.py. Do not
// modify by hand!

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

class Test_Struct_auto_check_sbp_ssr_ssr_structs0 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs0() {
    assign(test_struct_.code, 185);
    assign(test_struct_.value, -28374);
  }

  struct TestStructInfo {
    sbp_code_biases_content_t test_struct;
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
  sbp_code_biases_content_t test_struct_{};
  uint8_t encoded_data_[3] = {
      185,
      42,
      145,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs0, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_code_biases_content_encoded_len(&info.test_struct), 3);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs0, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[3];
  EXPECT_EQ(sbp_code_biases_content_encode(&buf[0], sizeof(buf), &nwritten,
                                           &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 3);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs0, FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[3];
  EXPECT_EQ(sbp_code_biases_content_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 3), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs0, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[3];
  for (uint8_t i = 0; i < 3; i++) {
    EXPECT_EQ(
        sbp_code_biases_content_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs0, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_code_biases_content_t t{};
  EXPECT_EQ(sbp_code_biases_content_decode(info.encoded_data, 3, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_code_biases_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs0, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_code_biases_content_t t{};
  EXPECT_EQ(sbp_code_biases_content_decode(info.encoded_data, 3, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_code_biases_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs0, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_code_biases_content_t t{};

  for (uint8_t i = 0; i < 3; i++) {
    EXPECT_EQ(sbp_code_biases_content_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs1 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs1() {
    assign(test_struct_.bias, 193740482);
    assign(test_struct_.code, 80);
    assign(test_struct_.discontinuity_counter, 250);
    assign(test_struct_.integer_indicator, 230);
    assign(test_struct_.widelane_integer_indicator, 40);
  }

  struct TestStructInfo {
    sbp_phase_biases_content_t test_struct;
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
  sbp_phase_biases_content_t test_struct_{};
  uint8_t encoded_data_[8] = {
      80, 230, 40, 250, 194, 62, 140, 11,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs1, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_phase_biases_content_encoded_len(&info.test_struct), 8);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs1, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[8];
  EXPECT_EQ(sbp_phase_biases_content_encode(&buf[0], sizeof(buf), &nwritten,
                                            &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 8);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs1, FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[8];
  EXPECT_EQ(sbp_phase_biases_content_encode(&buf[0], sizeof(buf), nullptr,
                                            &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 8), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs1, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[8];
  for (uint8_t i = 0; i < 8; i++) {
    EXPECT_EQ(
        sbp_phase_biases_content_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs1, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_phase_biases_content_t t{};
  EXPECT_EQ(sbp_phase_biases_content_decode(info.encoded_data, 8, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_phase_biases_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs1, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_phase_biases_content_t t{};
  EXPECT_EQ(sbp_phase_biases_content_decode(info.encoded_data, 8, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_phase_biases_content_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs1, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_phase_biases_content_t t{};

  for (uint8_t i = 0; i < 8; i++) {
    EXPECT_EQ(
        sbp_phase_biases_content_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs2 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs2() {
    assign(test_struct_.iod_atmo, 195);
    assign(test_struct_.num_msgs, 6);
    assign(test_struct_.seq_num, 199);
    assign(test_struct_.tile_id, 59568);
    assign(test_struct_.tile_set_id, 25856);
    assign(test_struct_.time.tow, 3053425451);
    assign(test_struct_.time.wn, 57417);
    assign(test_struct_.update_interval, 87);
  }

  struct TestStructInfo {
    sbp_stec_header_t test_struct;
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
  sbp_stec_header_t test_struct_{};
  uint8_t encoded_data_[14] = {
      0, 101, 176, 232, 43, 147, 255, 181, 73, 224, 6, 199, 87, 195,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs2, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_stec_header_encoded_len(&info.test_struct), 14);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs2, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[14];
  EXPECT_EQ(sbp_stec_header_encode(&buf[0], sizeof(buf), &nwritten,
                                   &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 14);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs2, FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[14];
  EXPECT_EQ(
      sbp_stec_header_encode(&buf[0], sizeof(buf), nullptr, &info.test_struct),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 14), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs2, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[14];
  for (uint8_t i = 0; i < 14; i++) {
    EXPECT_EQ(sbp_stec_header_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs2, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_stec_header_t t{};
  EXPECT_EQ(sbp_stec_header_decode(info.encoded_data, 14, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_stec_header_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs2, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_stec_header_t t{};
  EXPECT_EQ(sbp_stec_header_decode(info.encoded_data, 14, nullptr, &t), SBP_OK);
  EXPECT_EQ(sbp_stec_header_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs2, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_stec_header_t t{};

  for (uint8_t i = 0; i < 14; i++) {
    EXPECT_EQ(sbp_stec_header_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs3 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs3() {
    assign(test_struct_.iod_atmo, 195);
    assign(test_struct_.num_msgs, 2496);
    assign(test_struct_.seq_num, 56738);
    assign(test_struct_.tile_id, 52781);
    assign(test_struct_.tile_set_id, 42009);
    assign(test_struct_.time.tow, 4113264812);
    assign(test_struct_.time.wn, 63764);
    assign(test_struct_.tropo_quality_indicator, 122);
    assign(test_struct_.update_interval, 144);
  }

  struct TestStructInfo {
    sbp_gridded_correction_header_t test_struct;
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
  sbp_gridded_correction_header_t test_struct_{};
  uint8_t encoded_data_[17] = {
      25,  164, 45, 206, 172, 112, 43,  245, 20,
      249, 192, 9,  162, 221, 144, 195, 122,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs3, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_gridded_correction_header_encoded_len(&info.test_struct), 17);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs3, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[17];
  EXPECT_EQ(sbp_gridded_correction_header_encode(&buf[0], sizeof(buf),
                                                 &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 17);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs3, FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[17];
  EXPECT_EQ(sbp_gridded_correction_header_encode(&buf[0], sizeof(buf), nullptr,
                                                 &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 17), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs3, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[17];
  for (uint8_t i = 0; i < 17; i++) {
    EXPECT_EQ(sbp_gridded_correction_header_encode(&buf[0], i, nullptr,
                                                   &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs3, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_gridded_correction_header_t t{};
  EXPECT_EQ(
      sbp_gridded_correction_header_decode(info.encoded_data, 17, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_gridded_correction_header_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs3, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_gridded_correction_header_t t{};
  EXPECT_EQ(
      sbp_gridded_correction_header_decode(info.encoded_data, 17, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_gridded_correction_header_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs3, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_gridded_correction_header_t t{};

  for (uint8_t i = 0; i < 17; i++) {
    EXPECT_EQ(
        sbp_gridded_correction_header_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs4 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs4() {
    assign(test_struct_.stec_coeff[0], -20543);
    assign(test_struct_.stec_coeff[1], -20563);
    assign(test_struct_.stec_coeff[2], -31725);
    assign(test_struct_.stec_coeff[3], 24164);
    assign(test_struct_.stec_quality_indicator, 168);
    assign(test_struct_.sv_id.constellation, 193);
    assign(test_struct_.sv_id.satId, 96);
  }

  struct TestStructInfo {
    sbp_stec_sat_element_t test_struct;
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
  sbp_stec_sat_element_t test_struct_{};
  uint8_t encoded_data_[11] = {
      96, 193, 168, 193, 175, 173, 175, 19, 132, 100, 94,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs4, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_stec_sat_element_encoded_len(&info.test_struct), 11);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs4, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[11];
  EXPECT_EQ(sbp_stec_sat_element_encode(&buf[0], sizeof(buf), &nwritten,
                                        &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 11);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs4, FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[11];
  EXPECT_EQ(sbp_stec_sat_element_encode(&buf[0], sizeof(buf), nullptr,
                                        &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 11), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs4, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[11];
  for (uint8_t i = 0; i < 11; i++) {
    EXPECT_EQ(
        sbp_stec_sat_element_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs4, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_stec_sat_element_t t{};
  EXPECT_EQ(sbp_stec_sat_element_decode(info.encoded_data, 11, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_stec_sat_element_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs4, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_stec_sat_element_t t{};
  EXPECT_EQ(sbp_stec_sat_element_decode(info.encoded_data, 11, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_stec_sat_element_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs4, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_stec_sat_element_t t{};

  for (uint8_t i = 0; i < 11; i++) {
    EXPECT_EQ(sbp_stec_sat_element_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs5 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs5() {
    assign(test_struct_.hydro, 15483);
    assign(test_struct_.wet, 75);
  }

  struct TestStructInfo {
    sbp_tropospheric_delay_correction_no_std_t test_struct;
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
  sbp_tropospheric_delay_correction_no_std_t test_struct_{};
  uint8_t encoded_data_[3] = {
      123,
      60,
      75,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs5, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(
      sbp_tropospheric_delay_correction_no_std_encoded_len(&info.test_struct),
      3);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs5, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[3];
  EXPECT_EQ(sbp_tropospheric_delay_correction_no_std_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 3);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs5, FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[3];
  EXPECT_EQ(sbp_tropospheric_delay_correction_no_std_encode(
                &buf[0], sizeof(buf), nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 3), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs5, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[3];
  for (uint8_t i = 0; i < 3; i++) {
    EXPECT_EQ(sbp_tropospheric_delay_correction_no_std_encode(
                  &buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs5, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_tropospheric_delay_correction_no_std_t t{};
  EXPECT_EQ(sbp_tropospheric_delay_correction_no_std_decode(info.encoded_data,
                                                            3, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_tropospheric_delay_correction_no_std_cmp(&t, &info.test_struct),
            0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs5, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_tropospheric_delay_correction_no_std_t t{};
  EXPECT_EQ(sbp_tropospheric_delay_correction_no_std_decode(info.encoded_data,
                                                            3, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_tropospheric_delay_correction_no_std_cmp(&t, &info.test_struct),
            0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs5, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_tropospheric_delay_correction_no_std_t t{};

  for (uint8_t i = 0; i < 3; i++) {
    EXPECT_EQ(sbp_tropospheric_delay_correction_no_std_decode(info.encoded_data,
                                                              i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs6 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs6() {
    assign(test_struct_.hydro, 32529);
    assign(test_struct_.stddev, 38);
    assign(test_struct_.wet, -16);
  }

  struct TestStructInfo {
    sbp_tropospheric_delay_correction_t test_struct;
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
  sbp_tropospheric_delay_correction_t test_struct_{};
  uint8_t encoded_data_[4] = {
      17,
      127,
      240,
      38,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs6, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_tropospheric_delay_correction_encoded_len(&info.test_struct),
            4);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs6, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[4];
  EXPECT_EQ(sbp_tropospheric_delay_correction_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 4);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs6, FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  EXPECT_EQ(sbp_tropospheric_delay_correction_encode(
                &buf[0], sizeof(buf), nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 4), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs6, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(sbp_tropospheric_delay_correction_encode(&buf[0], i, nullptr,
                                                       &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs6, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_tropospheric_delay_correction_t t{};
  EXPECT_EQ(sbp_tropospheric_delay_correction_decode(info.encoded_data, 4,
                                                     &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_tropospheric_delay_correction_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs6, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_tropospheric_delay_correction_t t{};
  EXPECT_EQ(sbp_tropospheric_delay_correction_decode(info.encoded_data, 4,
                                                     nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_tropospheric_delay_correction_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs6, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_tropospheric_delay_correction_t t{};

  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(sbp_tropospheric_delay_correction_decode(info.encoded_data, i,
                                                       nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs7 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs7() {
    assign(test_struct_.residual, -12476);
    assign(test_struct_.sv_id.constellation, 103);
    assign(test_struct_.sv_id.satId, 101);
  }

  struct TestStructInfo {
    sbp_stec_residual_no_std_t test_struct;
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
  sbp_stec_residual_no_std_t test_struct_{};
  uint8_t encoded_data_[4] = {
      101,
      103,
      68,
      207,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs7, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_stec_residual_no_std_encoded_len(&info.test_struct), 4);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs7, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[4];
  EXPECT_EQ(sbp_stec_residual_no_std_encode(&buf[0], sizeof(buf), &nwritten,
                                            &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 4);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs7, FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  EXPECT_EQ(sbp_stec_residual_no_std_encode(&buf[0], sizeof(buf), nullptr,
                                            &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 4), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs7, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[4];
  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(
        sbp_stec_residual_no_std_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs7, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_stec_residual_no_std_t t{};
  EXPECT_EQ(sbp_stec_residual_no_std_decode(info.encoded_data, 4, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_stec_residual_no_std_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs7, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_stec_residual_no_std_t t{};
  EXPECT_EQ(sbp_stec_residual_no_std_decode(info.encoded_data, 4, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_stec_residual_no_std_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs7, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_stec_residual_no_std_t t{};

  for (uint8_t i = 0; i < 4; i++) {
    EXPECT_EQ(
        sbp_stec_residual_no_std_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs8 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs8() {
    assign(test_struct_.residual, 26158);
    assign(test_struct_.stddev, 7);
    assign(test_struct_.sv_id.constellation, 245);
    assign(test_struct_.sv_id.satId, 169);
  }

  struct TestStructInfo {
    sbp_stec_residual_t test_struct;
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
  sbp_stec_residual_t test_struct_{};
  uint8_t encoded_data_[5] = {
      169, 245, 46, 102, 7,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs8, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_stec_residual_encoded_len(&info.test_struct), 5);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs8, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[5];
  EXPECT_EQ(sbp_stec_residual_encode(&buf[0], sizeof(buf), &nwritten,
                                     &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 5);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs8, FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[5];
  EXPECT_EQ(sbp_stec_residual_encode(&buf[0], sizeof(buf), nullptr,
                                     &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 5), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs8, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[5];
  for (uint8_t i = 0; i < 5; i++) {
    EXPECT_EQ(sbp_stec_residual_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs8, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_stec_residual_t t{};
  EXPECT_EQ(sbp_stec_residual_decode(info.encoded_data, 5, &nread, &t), SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_stec_residual_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs8, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_stec_residual_t t{};
  EXPECT_EQ(sbp_stec_residual_decode(info.encoded_data, 5, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_stec_residual_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs8, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_stec_residual_t t{};

  for (uint8_t i = 0; i < 5; i++) {
    EXPECT_EQ(sbp_stec_residual_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs9 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs9() {
    assign(test_struct_.num_msgs, 40);
    assign(test_struct_.seq_num, 205);
    assign(test_struct_.sol_id, 7);
    assign(test_struct_.time.tow, 964634800);
    assign(test_struct_.time.wn, 35954);
    assign(test_struct_.update_interval, 241);
  }

  struct TestStructInfo {
    sbp_bounds_header_t test_struct;
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
  sbp_bounds_header_t test_struct_{};
  uint8_t encoded_data_[10] = {
      176, 40, 127, 57, 114, 140, 40, 205, 241, 7,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs9, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_bounds_header_encoded_len(&info.test_struct), 10);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs9, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[10];
  EXPECT_EQ(sbp_bounds_header_encode(&buf[0], sizeof(buf), &nwritten,
                                     &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 10);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs9, FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[10];
  EXPECT_EQ(sbp_bounds_header_encode(&buf[0], sizeof(buf), nullptr,
                                     &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 10), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs9, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[10];
  for (uint8_t i = 0; i < 10; i++) {
    EXPECT_EQ(sbp_bounds_header_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs9, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_bounds_header_t t{};
  EXPECT_EQ(sbp_bounds_header_decode(info.encoded_data, 10, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_bounds_header_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs9, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_bounds_header_t t{};
  EXPECT_EQ(sbp_bounds_header_decode(info.encoded_data, 10, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_bounds_header_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs9, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_bounds_header_t t{};

  for (uint8_t i = 0; i < 10; i++) {
    EXPECT_EQ(sbp_bounds_header_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs10 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs10() {
    assign(test_struct_.stec_bound_mu, 128);
    assign(test_struct_.stec_bound_mu_dot, 52);
    assign(test_struct_.stec_bound_sig, 167);
    assign(test_struct_.stec_bound_sig_dot, 60);
    assign(test_struct_.stec_residual.residual, 20646);
    assign(test_struct_.stec_residual.stddev, 89);
    assign(test_struct_.stec_residual.sv_id.constellation, 88);
    assign(test_struct_.stec_residual.sv_id.satId, 83);
  }

  struct TestStructInfo {
    sbp_stec_sat_element_integrity_t test_struct;
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
  sbp_stec_sat_element_integrity_t test_struct_{};
  uint8_t encoded_data_[9] = {
      83, 88, 166, 80, 89, 128, 167, 52, 60,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs10, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_stec_sat_element_integrity_encoded_len(&info.test_struct), 9);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs10, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[9];
  EXPECT_EQ(sbp_stec_sat_element_integrity_encode(&buf[0], sizeof(buf),
                                                  &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 9);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs10,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[9];
  EXPECT_EQ(sbp_stec_sat_element_integrity_encode(&buf[0], sizeof(buf), nullptr,
                                                  &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 9), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs10, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[9];
  for (uint8_t i = 0; i < 9; i++) {
    EXPECT_EQ(sbp_stec_sat_element_integrity_encode(&buf[0], i, nullptr,
                                                    &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs10, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_stec_sat_element_integrity_t t{};
  EXPECT_EQ(
      sbp_stec_sat_element_integrity_decode(info.encoded_data, 9, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_stec_sat_element_integrity_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs10, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_stec_sat_element_integrity_t t{};
  EXPECT_EQ(
      sbp_stec_sat_element_integrity_decode(info.encoded_data, 9, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_stec_sat_element_integrity_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs10, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_stec_sat_element_integrity_t t{};

  for (uint8_t i = 0; i < 9; i++) {
    EXPECT_EQ(sbp_stec_sat_element_integrity_decode(info.encoded_data, i,
                                                    nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs11 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs11() {
    assign(test_struct_.pco[0], 8405);

    assign(test_struct_.pco[1], -18163);

    assign(test_struct_.pco[2], 4437);

    assign(test_struct_.pcv[0], 56);

    assign(test_struct_.pcv[1], 113);

    assign(test_struct_.pcv[2], 34);

    assign(test_struct_.pcv[3], -79);

    assign(test_struct_.pcv[4], -54);

    assign(test_struct_.pcv[5], -19);

    assign(test_struct_.pcv[6], -78);

    assign(test_struct_.pcv[7], -18);

    assign(test_struct_.pcv[8], -66);

    assign(test_struct_.pcv[9], 74);

    assign(test_struct_.pcv[10], -64);

    assign(test_struct_.pcv[11], -19);

    assign(test_struct_.pcv[12], -90);

    assign(test_struct_.pcv[13], -108);

    assign(test_struct_.pcv[14], -65);

    assign(test_struct_.pcv[15], 122);

    assign(test_struct_.pcv[16], 111);

    assign(test_struct_.pcv[17], 43);

    assign(test_struct_.pcv[18], -35);

    assign(test_struct_.pcv[19], -15);

    assign(test_struct_.pcv[20], 78);
    assign(test_struct_.sat_info, 190);
    assign(test_struct_.sid.code, 13);
    assign(test_struct_.sid.sat, 207);
    assign(test_struct_.svn, 29092);
  }

  struct TestStructInfo {
    sbp_satellite_apc_t test_struct;
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
  sbp_satellite_apc_t test_struct_{};
  uint8_t encoded_data_[32] = {
      207, 13,  190, 164, 113, 213, 32,  13,  185, 85, 17,
      56,  113, 34,  177, 202, 237, 178, 238, 190, 74, 192,
      237, 166, 148, 191, 122, 111, 43,  221, 241, 78,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs11, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_satellite_apc_encoded_len(&info.test_struct), 32);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs11, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[32];
  EXPECT_EQ(sbp_satellite_apc_encode(&buf[0], sizeof(buf), &nwritten,
                                     &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 32);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs11,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[32];
  EXPECT_EQ(sbp_satellite_apc_encode(&buf[0], sizeof(buf), nullptr,
                                     &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 32), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs11, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[32];
  for (uint8_t i = 0; i < 32; i++) {
    EXPECT_EQ(sbp_satellite_apc_encode(&buf[0], i, nullptr, &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs11, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_satellite_apc_t t{};
  EXPECT_EQ(sbp_satellite_apc_decode(info.encoded_data, 32, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_satellite_apc_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs11, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_satellite_apc_t t{};
  EXPECT_EQ(sbp_satellite_apc_decode(info.encoded_data, 32, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_satellite_apc_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs11, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_satellite_apc_t t{};

  for (uint8_t i = 0; i < 32; i++) {
    EXPECT_EQ(sbp_satellite_apc_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs12 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs12() {
    assign(test_struct_.iod_atmo, 76);
    assign(test_struct_.num_msgs, 185);
    assign(test_struct_.seq_num, 163);
    assign(test_struct_.time.tow, 748938257);
    assign(test_struct_.time.wn, 61526);
    assign(test_struct_.update_interval, 105);
  }

  struct TestStructInfo {
    sbp_stec_header_dep_a_t test_struct;
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
  sbp_stec_header_dep_a_t test_struct_{};
  uint8_t encoded_data_[10] = {
      17, 228, 163, 44, 86, 240, 185, 163, 105, 76,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs12, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_stec_header_dep_a_encoded_len(&info.test_struct), 10);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs12, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[10];
  EXPECT_EQ(sbp_stec_header_dep_a_encode(&buf[0], sizeof(buf), &nwritten,
                                         &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 10);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs12,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[10];
  EXPECT_EQ(sbp_stec_header_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                         &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 10), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs12, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[10];
  for (uint8_t i = 0; i < 10; i++) {
    EXPECT_EQ(
        sbp_stec_header_dep_a_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs12, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_stec_header_dep_a_t t{};
  EXPECT_EQ(sbp_stec_header_dep_a_decode(info.encoded_data, 10, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_stec_header_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs12, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_stec_header_dep_a_t t{};
  EXPECT_EQ(sbp_stec_header_dep_a_decode(info.encoded_data, 10, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_stec_header_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs12, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_stec_header_dep_a_t t{};

  for (uint8_t i = 0; i < 10; i++) {
    EXPECT_EQ(sbp_stec_header_dep_a_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs13 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs13() {
    assign(test_struct_.iod_atmo, 199);
    assign(test_struct_.num_msgs, 50568);
    assign(test_struct_.seq_num, 39205);
    assign(test_struct_.time.tow, 3185536009);
    assign(test_struct_.time.wn, 31680);
    assign(test_struct_.tropo_quality_indicator, 135);
    assign(test_struct_.update_interval, 215);
  }

  struct TestStructInfo {
    sbp_gridded_correction_header_dep_a_t test_struct;
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
  sbp_gridded_correction_header_dep_a_t test_struct_{};
  uint8_t encoded_data_[13] = {
      9, 108, 223, 189, 192, 123, 136, 197, 37, 153, 215, 199, 135,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs13, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_gridded_correction_header_dep_a_encoded_len(&info.test_struct),
            13);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs13, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[13];
  EXPECT_EQ(sbp_gridded_correction_header_dep_a_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 13);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs13,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[13];
  EXPECT_EQ(sbp_gridded_correction_header_dep_a_encode(
                &buf[0], sizeof(buf), nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 13), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs13, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[13];
  for (uint8_t i = 0; i < 13; i++) {
    EXPECT_EQ(sbp_gridded_correction_header_dep_a_encode(&buf[0], i, nullptr,
                                                         &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs13, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_gridded_correction_header_dep_a_t t{};
  EXPECT_EQ(sbp_gridded_correction_header_dep_a_decode(info.encoded_data, 13,
                                                       &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_gridded_correction_header_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs13, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_gridded_correction_header_dep_a_t t{};
  EXPECT_EQ(sbp_gridded_correction_header_dep_a_decode(info.encoded_data, 13,
                                                       nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_gridded_correction_header_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs13, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_gridded_correction_header_dep_a_t t{};

  for (uint8_t i = 0; i < 13; i++) {
    EXPECT_EQ(sbp_gridded_correction_header_dep_a_decode(info.encoded_data, i,
                                                         nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs14 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs14() {
    assign(test_struct_.area_width, 40934);
    assign(test_struct_.lat_nw_corner_enc, 38421);
    assign(test_struct_.lon_nw_corner_enc, 25699);
    assign(test_struct_.num_msgs, 217);
    assign(test_struct_.region_size_inverse, 240);
    assign(test_struct_.seq_num, 199);
  }

  struct TestStructInfo {
    sbp_grid_definition_header_dep_a_t test_struct;
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
  sbp_grid_definition_header_dep_a_t test_struct_{};
  uint8_t encoded_data_[9] = {
      240, 230, 159, 21, 150, 99, 100, 217, 199,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs14, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_grid_definition_header_dep_a_encoded_len(&info.test_struct), 9);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs14, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[9];
  EXPECT_EQ(sbp_grid_definition_header_dep_a_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 9);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs14,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[9];
  EXPECT_EQ(sbp_grid_definition_header_dep_a_encode(&buf[0], sizeof(buf),
                                                    nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 9), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs14, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[9];
  for (uint8_t i = 0; i < 9; i++) {
    EXPECT_EQ(sbp_grid_definition_header_dep_a_encode(&buf[0], i, nullptr,
                                                      &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs14, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_grid_definition_header_dep_a_t t{};
  EXPECT_EQ(
      sbp_grid_definition_header_dep_a_decode(info.encoded_data, 9, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_grid_definition_header_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs14, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_grid_definition_header_dep_a_t t{};
  EXPECT_EQ(sbp_grid_definition_header_dep_a_decode(info.encoded_data, 9,
                                                    nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_grid_definition_header_dep_a_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs14, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_grid_definition_header_dep_a_t t{};

  for (uint8_t i = 0; i < 9; i++) {
    EXPECT_EQ(sbp_grid_definition_header_dep_a_decode(info.encoded_data, i,
                                                      nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs15 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs15() {
    assign(test_struct_.clock_bound_mu, 235);
    assign(test_struct_.clock_bound_sig, 237);
    assign(test_struct_.orb_along_bound_mu, 210);
    assign(test_struct_.orb_along_bound_sig, 60);
    assign(test_struct_.orb_cross_bound_mu, 61);
    assign(test_struct_.orb_cross_bound_sig, 123);
    assign(test_struct_.orb_radial_bound_mu, 54);
    assign(test_struct_.orb_radial_bound_sig, 231);
    assign(test_struct_.sat_id, 243);
  }

  struct TestStructInfo {
    sbp_orbit_clock_bound_t test_struct;
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
  sbp_orbit_clock_bound_t test_struct_{};
  uint8_t encoded_data_[9] = {
      243, 54, 210, 61, 231, 60, 123, 235, 237,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs15, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_orbit_clock_bound_encoded_len(&info.test_struct), 9);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs15, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[9];
  EXPECT_EQ(sbp_orbit_clock_bound_encode(&buf[0], sizeof(buf), &nwritten,
                                         &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 9);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs15,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[9];
  EXPECT_EQ(sbp_orbit_clock_bound_encode(&buf[0], sizeof(buf), nullptr,
                                         &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 9), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs15, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[9];
  for (uint8_t i = 0; i < 9; i++) {
    EXPECT_EQ(
        sbp_orbit_clock_bound_encode(&buf[0], i, nullptr, &info.test_struct),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs15, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_orbit_clock_bound_t t{};
  EXPECT_EQ(sbp_orbit_clock_bound_decode(info.encoded_data, 9, &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_orbit_clock_bound_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs15, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_orbit_clock_bound_t t{};
  EXPECT_EQ(sbp_orbit_clock_bound_decode(info.encoded_data, 9, nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_orbit_clock_bound_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs15, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_orbit_clock_bound_t t{};

  for (uint8_t i = 0; i < 9; i++) {
    EXPECT_EQ(sbp_orbit_clock_bound_decode(info.encoded_data, i, nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs16 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs16() {
    assign(test_struct_.code_bias_bound_mu, 0);
    assign(test_struct_.code_bias_bound_sig, 87);
    assign(test_struct_.phase_bias_bound_mu, 0);
    assign(test_struct_.phase_bias_bound_sig, 118);
    assign(test_struct_.sat_id, 232);
    assign(test_struct_.signal_id, 38);
  }

  struct TestStructInfo {
    sbp_code_phase_biases_sat_sig_t test_struct;
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
  sbp_code_phase_biases_sat_sig_t test_struct_{};
  uint8_t encoded_data_[6] = {
      232, 38, 0, 87, 0, 118,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs16, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_code_phase_biases_sat_sig_encoded_len(&info.test_struct), 6);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs16, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[6];
  EXPECT_EQ(sbp_code_phase_biases_sat_sig_encode(&buf[0], sizeof(buf),
                                                 &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 6);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs16,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[6];
  EXPECT_EQ(sbp_code_phase_biases_sat_sig_encode(&buf[0], sizeof(buf), nullptr,
                                                 &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 6), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs16, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[6];
  for (uint8_t i = 0; i < 6; i++) {
    EXPECT_EQ(sbp_code_phase_biases_sat_sig_encode(&buf[0], i, nullptr,
                                                   &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs16, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_code_phase_biases_sat_sig_t t{};
  EXPECT_EQ(
      sbp_code_phase_biases_sat_sig_decode(info.encoded_data, 6, &nread, &t),
      SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_code_phase_biases_sat_sig_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs16, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_code_phase_biases_sat_sig_t t{};
  EXPECT_EQ(
      sbp_code_phase_biases_sat_sig_decode(info.encoded_data, 6, nullptr, &t),
      SBP_OK);
  EXPECT_EQ(sbp_code_phase_biases_sat_sig_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs16, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_code_phase_biases_sat_sig_t t{};

  for (uint8_t i = 0; i < 6; i++) {
    EXPECT_EQ(
        sbp_code_phase_biases_sat_sig_decode(info.encoded_data, i, nullptr, &t),
        SBP_DECODE_ERROR);
  }
}

class Test_Struct_auto_check_sbp_ssr_ssr_structs17 : public ::testing::Test {
 public:
  Test_Struct_auto_check_sbp_ssr_ssr_structs17() {
    assign(test_struct_.clock_bound_mu_dot, 69);
    assign(test_struct_.clock_bound_sig_dot, 63);
    assign(test_struct_.orb_along_bound_mu_dot, 112);
    assign(test_struct_.orb_along_bound_sig_dot, 99);
    assign(test_struct_.orb_cross_bound_mu_dot, 238);
    assign(test_struct_.orb_cross_bound_sig_dot, 82);
    assign(test_struct_.orb_radial_bound_mu_dot, 108);
    assign(test_struct_.orb_radial_bound_sig_dot, 151);
  }

  struct TestStructInfo {
    sbp_orbit_clock_bound_degradation_t test_struct;
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
  sbp_orbit_clock_bound_degradation_t test_struct_{};
  uint8_t encoded_data_[8] = {
      108, 112, 238, 151, 99, 82, 69, 63,
  };
};

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs17, EncodedLen) {
  auto info = get_test_struct_info();
  EXPECT_EQ(sbp_orbit_clock_bound_degradation_encoded_len(&info.test_struct),
            8);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs17, FreeEncode) {
  auto info = get_test_struct_info();
  uint8_t nwritten = 0;
  uint8_t buf[8];
  EXPECT_EQ(sbp_orbit_clock_bound_degradation_encode(
                &buf[0], sizeof(buf), &nwritten, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(nwritten, 8);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, nwritten), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs17,
       FreeEncodeWithoutNwritten) {
  auto info = get_test_struct_info();
  uint8_t buf[8];
  EXPECT_EQ(sbp_orbit_clock_bound_degradation_encode(
                &buf[0], sizeof(buf), nullptr, &info.test_struct),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_data, 8), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs17, FreeEncodeUnderflow) {
  auto info = get_test_struct_info();
  uint8_t buf[8];
  for (uint8_t i = 0; i < 8; i++) {
    EXPECT_EQ(sbp_orbit_clock_bound_degradation_encode(&buf[0], i, nullptr,
                                                       &info.test_struct),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs17, FreeDecode) {
  auto info = get_test_struct_info();
  uint8_t nread = 0;
  sbp_orbit_clock_bound_degradation_t t{};
  EXPECT_EQ(sbp_orbit_clock_bound_degradation_decode(info.encoded_data, 8,
                                                     &nread, &t),
            SBP_OK);
  EXPECT_EQ(nread, info.encoded_len);
  EXPECT_EQ(sbp_orbit_clock_bound_degradation_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs17, FreeDecodeWithoutNread) {
  auto info = get_test_struct_info();
  sbp_orbit_clock_bound_degradation_t t{};
  EXPECT_EQ(sbp_orbit_clock_bound_degradation_decode(info.encoded_data, 8,
                                                     nullptr, &t),
            SBP_OK);
  EXPECT_EQ(sbp_orbit_clock_bound_degradation_cmp(&t, &info.test_struct), 0);
}

TEST_F(Test_Struct_auto_check_sbp_ssr_ssr_structs17, FreeDecodeUnderflow) {
  auto info = get_test_struct_info();
  sbp_orbit_clock_bound_degradation_t t{};

  for (uint8_t i = 0; i < 8; i++) {
    EXPECT_EQ(sbp_orbit_clock_bound_degradation_decode(info.encoded_data, i,
                                                       nullptr, &t),
              SBP_DECODE_ERROR);
  }
}

}  // namespace