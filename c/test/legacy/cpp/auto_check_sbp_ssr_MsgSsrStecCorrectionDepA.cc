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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/legacy_state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/ssr.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDepA0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_stec_correction_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDepA0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_stec_correction_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ssr_stec_correction_dep_a_t *>(
            last_msg_storage_)),
        last_msg_len_(),
        last_sender_id_(),
        n_callbacks_logged_(),
        dummy_wr_(),
        dummy_rd_(),
        dummy_buff_() {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
    dummy_rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(dummy_buff_ + dummy_wr_, buf, real_n);
    dummy_wr_ += real_n;
    return (s32)real_n;
  }

 protected:
  void handle_sbp_msg(uint16_t sender_id, uint8_t message_length,
                      const msg_ssr_stec_correction_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_stec_correction_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  235, 5,   39,  7,   252, 70,  81,  196, 232, 185, 43,  147, 123, 39,
      4,   126, 19,  111, 97,  248, 130, 217, 217, 106, 58,  12,  65,  230, 171,
      81,  95,  86,  16,  39,  84,  228, 208, 201, 81,  219, 99,  203, 61,  182,
      66,  125, 203, 3,   193, 44,  100, 220, 125, 60,  21,  93,  218, 247, 158,
      207, 93,  129, 134, 14,  209, 48,  14,  215, 153, 148, 147, 72,  225, 180,
      236, 205, 201, 33,  3,   246, 204, 19,  3,   98,  4,   194, 191, 246, 76,
      219, 31,  191, 113, 79,  177, 15,  251, 33,  19,  96,  54,  58,  146, 210,
      100, 249, 72,  21,  161, 211, 198, 21,  238, 111, 107, 36,  227, 225, 213,
      3,   71,  243, 63,  65,  236, 92,  77,  0,   169, 15,  182, 5,   240, 180,
      9,   122, 86,  232, 6,   103, 104, 254, 189, 81,  110, 2,   49,  202, 84,
      216, 55,  50,  181, 5,   123, 80,  49,  244, 224, 188, 125, 164, 230, 56,
      66,  124, 168, 59,  139, 106, 118, 51,  187, 216, 191, 158, 77,  92,  58,
      253, 132, 150, 165, 9,   154, 189, 218, 61,  209, 1,   82,  181, 196, 23,
      53,  182, 112, 192, 206, 167, 157, 244, 35,  1,   189, 217, 61,  88,  97,
      201, 201, 74,  251, 217, 14,  104, 184, 54,  52,  74,  238, 10,  129, 22,
      178, 226, 109, 88,  157, 30,  196, 175, 26,  76,  34,  116, 220, 154, 232,
      12,  179, 244, 15,  155, 196, 202, 72,  70,  115, 10,  214, 114, 39,  245,
      28,  237, 68,  136, 155,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_stec_correction_dep_a_t *test_msg =
      (msg_ssr_stec_correction_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->header.iod_atmo = 4;
  test_msg->header.num_msgs = 147;
  test_msg->header.seq_num = 123;
  test_msg->header.time.tow = 3905179974;
  test_msg->header.time.wn = 11193;
  test_msg->header.update_interval = 39;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[0] = -1951;
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[1] = -9854;
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[2] = 27353;
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[3] = 3130;
  test_msg->stec_sat_list[0].stec_quality_indicator = 111;
  test_msg->stec_sat_list[0].sv_id.constellation = 19;
  test_msg->stec_sat_list[0].sv_id.satId = 126;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[0] = 24401;
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[1] = 4182;
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[2] = 21543;
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[3] = -12060;
  test_msg->stec_sat_list[1].stec_quality_indicator = 171;
  test_msg->stec_sat_list[1].sv_id.constellation = 230;
  test_msg->stec_sat_list[1].sv_id.satId = 65;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[2].stec_coeff[0]));
  }
  test_msg->stec_sat_list[2].stec_coeff[0] = -13469;
  if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[2].stec_coeff[0]));
  }
  test_msg->stec_sat_list[2].stec_coeff[1] = -18883;
  if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[2].stec_coeff[0]));
  }
  test_msg->stec_sat_list[2].stec_coeff[2] = 32066;
  if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[2].stec_coeff[0]));
  }
  test_msg->stec_sat_list[2].stec_coeff[3] = 971;
  test_msg->stec_sat_list[2].stec_quality_indicator = 219;
  test_msg->stec_sat_list[2].sv_id.constellation = 81;
  test_msg->stec_sat_list[2].sv_id.satId = 201;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[3].stec_coeff[0]));
  }
  test_msg->stec_sat_list[3].stec_coeff[0] = 32220;
  if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[3].stec_coeff[0]));
  }
  test_msg->stec_sat_list[3].stec_coeff[1] = 5436;
  if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[3].stec_coeff[0]));
  }
  test_msg->stec_sat_list[3].stec_coeff[2] = -9635;
  if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[3].stec_coeff[0]));
  }
  test_msg->stec_sat_list[3].stec_coeff[3] = -24841;
  test_msg->stec_sat_list[3].stec_quality_indicator = 100;
  test_msg->stec_sat_list[3].sv_id.constellation = 44;
  test_msg->stec_sat_list[3].sv_id.satId = 193;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[4].stec_coeff[0]));
  }
  test_msg->stec_sat_list[4].stec_coeff[0] = 3718;
  if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[4].stec_coeff[0]));
  }
  test_msg->stec_sat_list[4].stec_coeff[1] = 12497;
  if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[4].stec_coeff[0]));
  }
  test_msg->stec_sat_list[4].stec_coeff[2] = -10482;
  if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[4].stec_coeff[0]));
  }
  test_msg->stec_sat_list[4].stec_coeff[3] = -27495;
  test_msg->stec_sat_list[4].stec_quality_indicator = 129;
  test_msg->stec_sat_list[4].sv_id.constellation = 93;
  test_msg->stec_sat_list[4].sv_id.satId = 207;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[5].stec_coeff[0]));
  }
  test_msg->stec_sat_list[5].stec_coeff[0] = -4940;
  if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[5].stec_coeff[0]));
  }
  test_msg->stec_sat_list[5].stec_coeff[1] = -13875;
  if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[5].stec_coeff[0]));
  }
  test_msg->stec_sat_list[5].stec_coeff[2] = 801;
  if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[5].stec_coeff[0]));
  }
  test_msg->stec_sat_list[5].stec_coeff[3] = -13066;
  test_msg->stec_sat_list[5].stec_quality_indicator = 225;
  test_msg->stec_sat_list[5].sv_id.constellation = 72;
  test_msg->stec_sat_list[5].sv_id.satId = 147;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[6].stec_coeff[0]));
  }
  test_msg->stec_sat_list[6].stec_coeff[0] = -15868;
  if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[6].stec_coeff[0]));
  }
  test_msg->stec_sat_list[6].stec_coeff[1] = -2369;
  if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[6].stec_coeff[0]));
  }
  test_msg->stec_sat_list[6].stec_coeff[2] = -9396;
  if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[6].stec_coeff[0]));
  }
  test_msg->stec_sat_list[6].stec_coeff[3] = -16609;
  test_msg->stec_sat_list[6].stec_quality_indicator = 98;
  test_msg->stec_sat_list[6].sv_id.constellation = 3;
  test_msg->stec_sat_list[6].sv_id.satId = 19;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[7].stec_coeff[0]));
  }
  test_msg->stec_sat_list[7].stec_coeff[0] = -1265;
  if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[7].stec_coeff[0]));
  }
  test_msg->stec_sat_list[7].stec_coeff[1] = 4897;
  if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[7].stec_coeff[0]));
  }
  test_msg->stec_sat_list[7].stec_coeff[2] = 13920;
  if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[7].stec_coeff[0]));
  }
  test_msg->stec_sat_list[7].stec_coeff[3] = -28102;
  test_msg->stec_sat_list[7].stec_quality_indicator = 177;
  test_msg->stec_sat_list[7].sv_id.constellation = 79;
  test_msg->stec_sat_list[7].sv_id.satId = 113;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[8].stec_coeff[0]));
  }
  test_msg->stec_sat_list[8].stec_coeff[0] = 5448;
  if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[8].stec_coeff[0]));
  }
  test_msg->stec_sat_list[8].stec_coeff[1] = -11359;
  if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[8].stec_coeff[0]));
  }
  test_msg->stec_sat_list[8].stec_coeff[2] = 5574;
  if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[8].stec_coeff[0]));
  }
  test_msg->stec_sat_list[8].stec_coeff[3] = 28654;
  test_msg->stec_sat_list[8].stec_quality_indicator = 249;
  test_msg->stec_sat_list[8].sv_id.constellation = 100;
  test_msg->stec_sat_list[8].sv_id.satId = 210;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[9].stec_coeff[0]));
  }
  test_msg->stec_sat_list[9].stec_coeff[0] = -10783;
  if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[9].stec_coeff[0]));
  }
  test_msg->stec_sat_list[9].stec_coeff[1] = 18179;
  if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[9].stec_coeff[0]));
  }
  test_msg->stec_sat_list[9].stec_coeff[2] = 16371;
  if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[9].stec_coeff[0]));
  }
  test_msg->stec_sat_list[9].stec_coeff[3] = -5055;
  test_msg->stec_sat_list[9].stec_quality_indicator = 227;
  test_msg->stec_sat_list[9].sv_id.constellation = 36;
  test_msg->stec_sat_list[9].sv_id.satId = 107;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[10].stec_coeff[0]));
  }
  test_msg->stec_sat_list[10].stec_coeff[0] = 4009;
  if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[10].stec_coeff[0]));
  }
  test_msg->stec_sat_list[10].stec_coeff[1] = 1462;
  if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[10].stec_coeff[0]));
  }
  test_msg->stec_sat_list[10].stec_coeff[2] = -19216;
  if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[10].stec_coeff[0]));
  }
  test_msg->stec_sat_list[10].stec_coeff[3] = 31241;
  test_msg->stec_sat_list[10].stec_quality_indicator = 0;
  test_msg->stec_sat_list[10].sv_id.constellation = 77;
  test_msg->stec_sat_list[10].sv_id.satId = 92;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[11].stec_coeff[0]));
  }
  test_msg->stec_sat_list[11].stec_coeff[0] = 26727;
  if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[11].stec_coeff[0]));
  }
  test_msg->stec_sat_list[11].stec_coeff[1] = -16898;
  if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[11].stec_coeff[0]));
  }
  test_msg->stec_sat_list[11].stec_coeff[2] = 28241;
  if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[11].stec_coeff[0]));
  }
  test_msg->stec_sat_list[11].stec_coeff[3] = 12546;
  test_msg->stec_sat_list[11].stec_quality_indicator = 6;
  test_msg->stec_sat_list[11].sv_id.constellation = 232;
  test_msg->stec_sat_list[11].sv_id.satId = 86;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[12].stec_coeff[0]));
  }
  test_msg->stec_sat_list[12].stec_coeff[0] = 12855;
  if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[12].stec_coeff[0]));
  }
  test_msg->stec_sat_list[12].stec_coeff[1] = 1461;
  if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[12].stec_coeff[0]));
  }
  test_msg->stec_sat_list[12].stec_coeff[2] = 20603;
  if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[12].stec_coeff[0]));
  }
  test_msg->stec_sat_list[12].stec_coeff[3] = -3023;
  test_msg->stec_sat_list[12].stec_quality_indicator = 216;
  test_msg->stec_sat_list[12].sv_id.constellation = 84;
  test_msg->stec_sat_list[12].sv_id.satId = 202;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[13].stec_coeff[0]));
  }
  test_msg->stec_sat_list[13].stec_coeff[0] = -6492;
  if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[13].stec_coeff[0]));
  }
  test_msg->stec_sat_list[13].stec_coeff[1] = 16952;
  if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[13].stec_coeff[0]));
  }
  test_msg->stec_sat_list[13].stec_coeff[2] = -22404;
  if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[13].stec_coeff[0]));
  }
  test_msg->stec_sat_list[13].stec_coeff[3] = -29893;
  test_msg->stec_sat_list[13].stec_quality_indicator = 125;
  test_msg->stec_sat_list[13].sv_id.constellation = 188;
  test_msg->stec_sat_list[13].sv_id.satId = 224;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[14].stec_coeff[0]));
  }
  test_msg->stec_sat_list[14].stec_coeff[0] = -10053;
  if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[14].stec_coeff[0]));
  }
  test_msg->stec_sat_list[14].stec_coeff[1] = -24897;
  if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[14].stec_coeff[0]));
  }
  test_msg->stec_sat_list[14].stec_coeff[2] = 23629;
  if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[14].stec_coeff[0]));
  }
  test_msg->stec_sat_list[14].stec_coeff[3] = -710;
  test_msg->stec_sat_list[14].stec_quality_indicator = 51;
  test_msg->stec_sat_list[14].sv_id.constellation = 118;
  test_msg->stec_sat_list[14].sv_id.satId = 106;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[15].stec_coeff[0]));
  }
  test_msg->stec_sat_list[15].stec_coeff[0] = -26103;
  if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[15].stec_coeff[0]));
  }
  test_msg->stec_sat_list[15].stec_coeff[1] = -9539;
  if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[15].stec_coeff[0]));
  }
  test_msg->stec_sat_list[15].stec_coeff[2] = -11971;
  if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[15].stec_coeff[0]));
  }
  test_msg->stec_sat_list[15].stec_coeff[3] = 20993;
  test_msg->stec_sat_list[15].stec_quality_indicator = 165;
  test_msg->stec_sat_list[15].sv_id.constellation = 150;
  test_msg->stec_sat_list[15].sv_id.satId = 132;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[16].stec_coeff[0]));
  }
  test_msg->stec_sat_list[16].stec_coeff[0] = -18891;
  if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[16].stec_coeff[0]));
  }
  test_msg->stec_sat_list[16].stec_coeff[1] = -16272;
  if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[16].stec_coeff[0]));
  }
  test_msg->stec_sat_list[16].stec_coeff[2] = -22578;
  if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[16].stec_coeff[0]));
  }
  test_msg->stec_sat_list[16].stec_coeff[3] = -2915;
  test_msg->stec_sat_list[16].stec_quality_indicator = 23;
  test_msg->stec_sat_list[16].sv_id.constellation = 196;
  test_msg->stec_sat_list[16].sv_id.satId = 181;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[17].stec_coeff[0]));
  }
  test_msg->stec_sat_list[17].stec_coeff[0] = 15833;
  if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[17].stec_coeff[0]));
  }
  test_msg->stec_sat_list[17].stec_coeff[1] = 24920;
  if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[17].stec_coeff[0]));
  }
  test_msg->stec_sat_list[17].stec_coeff[2] = -13879;
  if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[17].stec_coeff[0]));
  }
  test_msg->stec_sat_list[17].stec_coeff[3] = -1206;
  test_msg->stec_sat_list[17].stec_quality_indicator = 189;
  test_msg->stec_sat_list[17].sv_id.constellation = 1;
  test_msg->stec_sat_list[17].sv_id.satId = 35;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[18].stec_coeff[0]));
  }
  test_msg->stec_sat_list[18].stec_coeff[0] = 14008;
  if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[18].stec_coeff[0]));
  }
  test_msg->stec_sat_list[18].stec_coeff[1] = 18996;
  if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[18].stec_coeff[0]));
  }
  test_msg->stec_sat_list[18].stec_coeff[2] = 2798;
  if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[18].stec_coeff[0]));
  }
  test_msg->stec_sat_list[18].stec_coeff[3] = 5761;
  test_msg->stec_sat_list[18].stec_quality_indicator = 104;
  test_msg->stec_sat_list[18].sv_id.constellation = 14;
  test_msg->stec_sat_list[18].sv_id.satId = 217;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[19].stec_coeff[0]));
  }
  test_msg->stec_sat_list[19].stec_coeff[0] = -25256;
  if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[19].stec_coeff[0]));
  }
  test_msg->stec_sat_list[19].stec_coeff[1] = -15330;
  if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[19].stec_coeff[0]));
  }
  test_msg->stec_sat_list[19].stec_coeff[2] = 6831;
  if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[19].stec_coeff[0]));
  }
  test_msg->stec_sat_list[19].stec_coeff[3] = 8780;
  test_msg->stec_sat_list[19].stec_quality_indicator = 109;
  test_msg->stec_sat_list[19].sv_id.constellation = 226;
  test_msg->stec_sat_list[19].sv_id.satId = 178;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[20].stec_coeff[0]));
  }
  test_msg->stec_sat_list[20].stec_coeff[0] = 3304;
  if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[20].stec_coeff[0]));
  }
  test_msg->stec_sat_list[20].stec_coeff[1] = -2893;
  if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[20].stec_coeff[0]));
  }
  test_msg->stec_sat_list[20].stec_coeff[2] = -25841;
  if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[20].stec_coeff[0]));
  }
  test_msg->stec_sat_list[20].stec_coeff[3] = -13628;
  test_msg->stec_sat_list[20].stec_quality_indicator = 154;
  test_msg->stec_sat_list[20].sv_id.constellation = 220;
  test_msg->stec_sat_list[20].sv_id.satId = 116;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[21].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[21].stec_coeff[0]));
  }
  test_msg->stec_sat_list[21].stec_coeff[0] = -10742;
  if (sizeof(test_msg->stec_sat_list[21].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[21].stec_coeff[0]));
  }
  test_msg->stec_sat_list[21].stec_coeff[1] = 10098;
  if (sizeof(test_msg->stec_sat_list[21].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[21].stec_coeff[0]));
  }
  test_msg->stec_sat_list[21].stec_coeff[2] = 7413;
  if (sizeof(test_msg->stec_sat_list[21].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[21].stec_coeff[0]));
  }
  test_msg->stec_sat_list[21].stec_coeff[3] = 17645;
  test_msg->stec_sat_list[21].stec_quality_indicator = 115;
  test_msg->stec_sat_list[21].sv_id.constellation = 70;
  test_msg->stec_sat_list[21].sv_id.satId = 72;

  EXPECT_EQ(send_message(0x5eb, 1831, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1831);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->header.iod_atmo)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.iod_atmo)),
            4)
      << "incorrect value for header.iod_atmo, expected 4, is "
      << last_msg_->header.iod_atmo;
  EXPECT_EQ(get_as<decltype(last_msg_->header.num_msgs)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.num_msgs)),
            147)
      << "incorrect value for header.num_msgs, expected 147, is "
      << last_msg_->header.num_msgs;
  EXPECT_EQ(get_as<decltype(last_msg_->header.seq_num)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.seq_num)),
            123)
      << "incorrect value for header.seq_num, expected 123, is "
      << last_msg_->header.seq_num;
  EXPECT_EQ(get_as<decltype(last_msg_->header.time.tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.time.tow)),
            3905179974)
      << "incorrect value for header.time.tow, expected 3905179974, is "
      << last_msg_->header.time.tow;
  EXPECT_EQ(get_as<decltype(last_msg_->header.time.wn)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.time.wn)),
            11193)
      << "incorrect value for header.time.wn, expected 11193, is "
      << last_msg_->header.time.wn;
  EXPECT_EQ(get_as<decltype(last_msg_->header.update_interval)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->header.update_interval)),
            39)
      << "incorrect value for header.update_interval, expected 39, is "
      << last_msg_->header.update_interval;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].stec_coeff[0])),
            -1951)
      << "incorrect value for stec_sat_list[0].stec_coeff[0], expected -1951, "
         "is "
      << last_msg_->stec_sat_list[0].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].stec_coeff[1])),
            -9854)
      << "incorrect value for stec_sat_list[0].stec_coeff[1], expected -9854, "
         "is "
      << last_msg_->stec_sat_list[0].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].stec_coeff[2])),
            27353)
      << "incorrect value for stec_sat_list[0].stec_coeff[2], expected 27353, "
         "is "
      << last_msg_->stec_sat_list[0].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].stec_coeff[3])),
            3130)
      << "incorrect value for stec_sat_list[0].stec_coeff[3], expected 3130, "
         "is "
      << last_msg_->stec_sat_list[0].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[0].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[0].stec_quality_indicator)),
      111)
      << "incorrect value for stec_sat_list[0].stec_quality_indicator, "
         "expected 111, is "
      << last_msg_->stec_sat_list[0].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].sv_id.constellation)),
            19)
      << "incorrect value for stec_sat_list[0].sv_id.constellation, expected "
         "19, is "
      << last_msg_->stec_sat_list[0].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].sv_id.satId)),
            126)
      << "incorrect value for stec_sat_list[0].sv_id.satId, expected 126, is "
      << last_msg_->stec_sat_list[0].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].stec_coeff[0])),
            24401)
      << "incorrect value for stec_sat_list[1].stec_coeff[0], expected 24401, "
         "is "
      << last_msg_->stec_sat_list[1].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].stec_coeff[1])),
            4182)
      << "incorrect value for stec_sat_list[1].stec_coeff[1], expected 4182, "
         "is "
      << last_msg_->stec_sat_list[1].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].stec_coeff[2])),
            21543)
      << "incorrect value for stec_sat_list[1].stec_coeff[2], expected 21543, "
         "is "
      << last_msg_->stec_sat_list[1].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].stec_coeff[3])),
            -12060)
      << "incorrect value for stec_sat_list[1].stec_coeff[3], expected -12060, "
         "is "
      << last_msg_->stec_sat_list[1].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[1].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[1].stec_quality_indicator)),
      171)
      << "incorrect value for stec_sat_list[1].stec_quality_indicator, "
         "expected 171, is "
      << last_msg_->stec_sat_list[1].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].sv_id.constellation)),
            230)
      << "incorrect value for stec_sat_list[1].sv_id.constellation, expected "
         "230, is "
      << last_msg_->stec_sat_list[1].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].sv_id.satId)),
            65)
      << "incorrect value for stec_sat_list[1].sv_id.satId, expected 65, is "
      << last_msg_->stec_sat_list[1].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].stec_coeff[0])),
            -13469)
      << "incorrect value for stec_sat_list[2].stec_coeff[0], expected -13469, "
         "is "
      << last_msg_->stec_sat_list[2].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].stec_coeff[1])),
            -18883)
      << "incorrect value for stec_sat_list[2].stec_coeff[1], expected -18883, "
         "is "
      << last_msg_->stec_sat_list[2].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].stec_coeff[2])),
            32066)
      << "incorrect value for stec_sat_list[2].stec_coeff[2], expected 32066, "
         "is "
      << last_msg_->stec_sat_list[2].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].stec_coeff[3])),
            971)
      << "incorrect value for stec_sat_list[2].stec_coeff[3], expected 971, is "
      << last_msg_->stec_sat_list[2].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[2].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[2].stec_quality_indicator)),
      219)
      << "incorrect value for stec_sat_list[2].stec_quality_indicator, "
         "expected 219, is "
      << last_msg_->stec_sat_list[2].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].sv_id.constellation)),
            81)
      << "incorrect value for stec_sat_list[2].sv_id.constellation, expected "
         "81, is "
      << last_msg_->stec_sat_list[2].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].sv_id.satId)),
            201)
      << "incorrect value for stec_sat_list[2].sv_id.satId, expected 201, is "
      << last_msg_->stec_sat_list[2].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].stec_coeff[0])),
            32220)
      << "incorrect value for stec_sat_list[3].stec_coeff[0], expected 32220, "
         "is "
      << last_msg_->stec_sat_list[3].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].stec_coeff[1])),
            5436)
      << "incorrect value for stec_sat_list[3].stec_coeff[1], expected 5436, "
         "is "
      << last_msg_->stec_sat_list[3].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].stec_coeff[2])),
            -9635)
      << "incorrect value for stec_sat_list[3].stec_coeff[2], expected -9635, "
         "is "
      << last_msg_->stec_sat_list[3].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].stec_coeff[3])),
            -24841)
      << "incorrect value for stec_sat_list[3].stec_coeff[3], expected -24841, "
         "is "
      << last_msg_->stec_sat_list[3].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[3].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[3].stec_quality_indicator)),
      100)
      << "incorrect value for stec_sat_list[3].stec_quality_indicator, "
         "expected 100, is "
      << last_msg_->stec_sat_list[3].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].sv_id.constellation)),
            44)
      << "incorrect value for stec_sat_list[3].sv_id.constellation, expected "
         "44, is "
      << last_msg_->stec_sat_list[3].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].sv_id.satId)),
            193)
      << "incorrect value for stec_sat_list[3].sv_id.satId, expected 193, is "
      << last_msg_->stec_sat_list[3].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].stec_coeff[0])),
            3718)
      << "incorrect value for stec_sat_list[4].stec_coeff[0], expected 3718, "
         "is "
      << last_msg_->stec_sat_list[4].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].stec_coeff[1])),
            12497)
      << "incorrect value for stec_sat_list[4].stec_coeff[1], expected 12497, "
         "is "
      << last_msg_->stec_sat_list[4].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].stec_coeff[2])),
            -10482)
      << "incorrect value for stec_sat_list[4].stec_coeff[2], expected -10482, "
         "is "
      << last_msg_->stec_sat_list[4].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].stec_coeff[3])),
            -27495)
      << "incorrect value for stec_sat_list[4].stec_coeff[3], expected -27495, "
         "is "
      << last_msg_->stec_sat_list[4].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[4].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[4].stec_quality_indicator)),
      129)
      << "incorrect value for stec_sat_list[4].stec_quality_indicator, "
         "expected 129, is "
      << last_msg_->stec_sat_list[4].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].sv_id.constellation)),
            93)
      << "incorrect value for stec_sat_list[4].sv_id.constellation, expected "
         "93, is "
      << last_msg_->stec_sat_list[4].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].sv_id.satId)),
            207)
      << "incorrect value for stec_sat_list[4].sv_id.satId, expected 207, is "
      << last_msg_->stec_sat_list[4].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].stec_coeff[0])),
            -4940)
      << "incorrect value for stec_sat_list[5].stec_coeff[0], expected -4940, "
         "is "
      << last_msg_->stec_sat_list[5].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].stec_coeff[1])),
            -13875)
      << "incorrect value for stec_sat_list[5].stec_coeff[1], expected -13875, "
         "is "
      << last_msg_->stec_sat_list[5].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].stec_coeff[2])),
            801)
      << "incorrect value for stec_sat_list[5].stec_coeff[2], expected 801, is "
      << last_msg_->stec_sat_list[5].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].stec_coeff[3])),
            -13066)
      << "incorrect value for stec_sat_list[5].stec_coeff[3], expected -13066, "
         "is "
      << last_msg_->stec_sat_list[5].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[5].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[5].stec_quality_indicator)),
      225)
      << "incorrect value for stec_sat_list[5].stec_quality_indicator, "
         "expected 225, is "
      << last_msg_->stec_sat_list[5].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].sv_id.constellation)),
            72)
      << "incorrect value for stec_sat_list[5].sv_id.constellation, expected "
         "72, is "
      << last_msg_->stec_sat_list[5].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].sv_id.satId)),
            147)
      << "incorrect value for stec_sat_list[5].sv_id.satId, expected 147, is "
      << last_msg_->stec_sat_list[5].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].stec_coeff[0])),
            -15868)
      << "incorrect value for stec_sat_list[6].stec_coeff[0], expected -15868, "
         "is "
      << last_msg_->stec_sat_list[6].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].stec_coeff[1])),
            -2369)
      << "incorrect value for stec_sat_list[6].stec_coeff[1], expected -2369, "
         "is "
      << last_msg_->stec_sat_list[6].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].stec_coeff[2])),
            -9396)
      << "incorrect value for stec_sat_list[6].stec_coeff[2], expected -9396, "
         "is "
      << last_msg_->stec_sat_list[6].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].stec_coeff[3])),
            -16609)
      << "incorrect value for stec_sat_list[6].stec_coeff[3], expected -16609, "
         "is "
      << last_msg_->stec_sat_list[6].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[6].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[6].stec_quality_indicator)),
      98)
      << "incorrect value for stec_sat_list[6].stec_quality_indicator, "
         "expected 98, is "
      << last_msg_->stec_sat_list[6].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].sv_id.constellation)),
            3)
      << "incorrect value for stec_sat_list[6].sv_id.constellation, expected "
         "3, is "
      << last_msg_->stec_sat_list[6].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].sv_id.satId)),
            19)
      << "incorrect value for stec_sat_list[6].sv_id.satId, expected 19, is "
      << last_msg_->stec_sat_list[6].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].stec_coeff[0])),
            -1265)
      << "incorrect value for stec_sat_list[7].stec_coeff[0], expected -1265, "
         "is "
      << last_msg_->stec_sat_list[7].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].stec_coeff[1])),
            4897)
      << "incorrect value for stec_sat_list[7].stec_coeff[1], expected 4897, "
         "is "
      << last_msg_->stec_sat_list[7].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].stec_coeff[2])),
            13920)
      << "incorrect value for stec_sat_list[7].stec_coeff[2], expected 13920, "
         "is "
      << last_msg_->stec_sat_list[7].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].stec_coeff[3])),
            -28102)
      << "incorrect value for stec_sat_list[7].stec_coeff[3], expected -28102, "
         "is "
      << last_msg_->stec_sat_list[7].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[7].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[7].stec_quality_indicator)),
      177)
      << "incorrect value for stec_sat_list[7].stec_quality_indicator, "
         "expected 177, is "
      << last_msg_->stec_sat_list[7].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].sv_id.constellation)),
            79)
      << "incorrect value for stec_sat_list[7].sv_id.constellation, expected "
         "79, is "
      << last_msg_->stec_sat_list[7].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].sv_id.satId)),
            113)
      << "incorrect value for stec_sat_list[7].sv_id.satId, expected 113, is "
      << last_msg_->stec_sat_list[7].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].stec_coeff[0])),
            5448)
      << "incorrect value for stec_sat_list[8].stec_coeff[0], expected 5448, "
         "is "
      << last_msg_->stec_sat_list[8].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].stec_coeff[1])),
            -11359)
      << "incorrect value for stec_sat_list[8].stec_coeff[1], expected -11359, "
         "is "
      << last_msg_->stec_sat_list[8].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].stec_coeff[2])),
            5574)
      << "incorrect value for stec_sat_list[8].stec_coeff[2], expected 5574, "
         "is "
      << last_msg_->stec_sat_list[8].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].stec_coeff[3])),
            28654)
      << "incorrect value for stec_sat_list[8].stec_coeff[3], expected 28654, "
         "is "
      << last_msg_->stec_sat_list[8].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[8].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[8].stec_quality_indicator)),
      249)
      << "incorrect value for stec_sat_list[8].stec_quality_indicator, "
         "expected 249, is "
      << last_msg_->stec_sat_list[8].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].sv_id.constellation)),
            100)
      << "incorrect value for stec_sat_list[8].sv_id.constellation, expected "
         "100, is "
      << last_msg_->stec_sat_list[8].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].sv_id.satId)),
            210)
      << "incorrect value for stec_sat_list[8].sv_id.satId, expected 210, is "
      << last_msg_->stec_sat_list[8].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].stec_coeff[0])),
            -10783)
      << "incorrect value for stec_sat_list[9].stec_coeff[0], expected -10783, "
         "is "
      << last_msg_->stec_sat_list[9].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].stec_coeff[1])),
            18179)
      << "incorrect value for stec_sat_list[9].stec_coeff[1], expected 18179, "
         "is "
      << last_msg_->stec_sat_list[9].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].stec_coeff[2])),
            16371)
      << "incorrect value for stec_sat_list[9].stec_coeff[2], expected 16371, "
         "is "
      << last_msg_->stec_sat_list[9].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].stec_coeff[3])),
            -5055)
      << "incorrect value for stec_sat_list[9].stec_coeff[3], expected -5055, "
         "is "
      << last_msg_->stec_sat_list[9].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[9].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[9].stec_quality_indicator)),
      227)
      << "incorrect value for stec_sat_list[9].stec_quality_indicator, "
         "expected 227, is "
      << last_msg_->stec_sat_list[9].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].sv_id.constellation)),
            36)
      << "incorrect value for stec_sat_list[9].sv_id.constellation, expected "
         "36, is "
      << last_msg_->stec_sat_list[9].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].sv_id.satId)),
            107)
      << "incorrect value for stec_sat_list[9].sv_id.satId, expected 107, is "
      << last_msg_->stec_sat_list[9].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].stec_coeff[0])),
            4009)
      << "incorrect value for stec_sat_list[10].stec_coeff[0], expected 4009, "
         "is "
      << last_msg_->stec_sat_list[10].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].stec_coeff[1])),
            1462)
      << "incorrect value for stec_sat_list[10].stec_coeff[1], expected 1462, "
         "is "
      << last_msg_->stec_sat_list[10].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].stec_coeff[2])),
            -19216)
      << "incorrect value for stec_sat_list[10].stec_coeff[2], expected "
         "-19216, is "
      << last_msg_->stec_sat_list[10].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].stec_coeff[3])),
            31241)
      << "incorrect value for stec_sat_list[10].stec_coeff[3], expected 31241, "
         "is "
      << last_msg_->stec_sat_list[10].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[10].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[10].stec_quality_indicator)),
      0)
      << "incorrect value for stec_sat_list[10].stec_quality_indicator, "
         "expected 0, is "
      << last_msg_->stec_sat_list[10].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].sv_id.constellation)),
            77)
      << "incorrect value for stec_sat_list[10].sv_id.constellation, expected "
         "77, is "
      << last_msg_->stec_sat_list[10].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].sv_id.satId)),
            92)
      << "incorrect value for stec_sat_list[10].sv_id.satId, expected 92, is "
      << last_msg_->stec_sat_list[10].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].stec_coeff[0])),
            26727)
      << "incorrect value for stec_sat_list[11].stec_coeff[0], expected 26727, "
         "is "
      << last_msg_->stec_sat_list[11].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].stec_coeff[1])),
            -16898)
      << "incorrect value for stec_sat_list[11].stec_coeff[1], expected "
         "-16898, is "
      << last_msg_->stec_sat_list[11].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].stec_coeff[2])),
            28241)
      << "incorrect value for stec_sat_list[11].stec_coeff[2], expected 28241, "
         "is "
      << last_msg_->stec_sat_list[11].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].stec_coeff[3])),
            12546)
      << "incorrect value for stec_sat_list[11].stec_coeff[3], expected 12546, "
         "is "
      << last_msg_->stec_sat_list[11].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[11].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[11].stec_quality_indicator)),
      6)
      << "incorrect value for stec_sat_list[11].stec_quality_indicator, "
         "expected 6, is "
      << last_msg_->stec_sat_list[11].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].sv_id.constellation)),
            232)
      << "incorrect value for stec_sat_list[11].sv_id.constellation, expected "
         "232, is "
      << last_msg_->stec_sat_list[11].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].sv_id.satId)),
            86)
      << "incorrect value for stec_sat_list[11].sv_id.satId, expected 86, is "
      << last_msg_->stec_sat_list[11].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].stec_coeff[0])),
            12855)
      << "incorrect value for stec_sat_list[12].stec_coeff[0], expected 12855, "
         "is "
      << last_msg_->stec_sat_list[12].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].stec_coeff[1])),
            1461)
      << "incorrect value for stec_sat_list[12].stec_coeff[1], expected 1461, "
         "is "
      << last_msg_->stec_sat_list[12].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].stec_coeff[2])),
            20603)
      << "incorrect value for stec_sat_list[12].stec_coeff[2], expected 20603, "
         "is "
      << last_msg_->stec_sat_list[12].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].stec_coeff[3])),
            -3023)
      << "incorrect value for stec_sat_list[12].stec_coeff[3], expected -3023, "
         "is "
      << last_msg_->stec_sat_list[12].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[12].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[12].stec_quality_indicator)),
      216)
      << "incorrect value for stec_sat_list[12].stec_quality_indicator, "
         "expected 216, is "
      << last_msg_->stec_sat_list[12].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].sv_id.constellation)),
            84)
      << "incorrect value for stec_sat_list[12].sv_id.constellation, expected "
         "84, is "
      << last_msg_->stec_sat_list[12].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].sv_id.satId)),
            202)
      << "incorrect value for stec_sat_list[12].sv_id.satId, expected 202, is "
      << last_msg_->stec_sat_list[12].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].stec_coeff[0])),
            -6492)
      << "incorrect value for stec_sat_list[13].stec_coeff[0], expected -6492, "
         "is "
      << last_msg_->stec_sat_list[13].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].stec_coeff[1])),
            16952)
      << "incorrect value for stec_sat_list[13].stec_coeff[1], expected 16952, "
         "is "
      << last_msg_->stec_sat_list[13].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].stec_coeff[2])),
            -22404)
      << "incorrect value for stec_sat_list[13].stec_coeff[2], expected "
         "-22404, is "
      << last_msg_->stec_sat_list[13].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].stec_coeff[3])),
            -29893)
      << "incorrect value for stec_sat_list[13].stec_coeff[3], expected "
         "-29893, is "
      << last_msg_->stec_sat_list[13].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[13].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[13].stec_quality_indicator)),
      125)
      << "incorrect value for stec_sat_list[13].stec_quality_indicator, "
         "expected 125, is "
      << last_msg_->stec_sat_list[13].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].sv_id.constellation)),
            188)
      << "incorrect value for stec_sat_list[13].sv_id.constellation, expected "
         "188, is "
      << last_msg_->stec_sat_list[13].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].sv_id.satId)),
            224)
      << "incorrect value for stec_sat_list[13].sv_id.satId, expected 224, is "
      << last_msg_->stec_sat_list[13].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].stec_coeff[0])),
            -10053)
      << "incorrect value for stec_sat_list[14].stec_coeff[0], expected "
         "-10053, is "
      << last_msg_->stec_sat_list[14].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].stec_coeff[1])),
            -24897)
      << "incorrect value for stec_sat_list[14].stec_coeff[1], expected "
         "-24897, is "
      << last_msg_->stec_sat_list[14].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].stec_coeff[2])),
            23629)
      << "incorrect value for stec_sat_list[14].stec_coeff[2], expected 23629, "
         "is "
      << last_msg_->stec_sat_list[14].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].stec_coeff[3])),
            -710)
      << "incorrect value for stec_sat_list[14].stec_coeff[3], expected -710, "
         "is "
      << last_msg_->stec_sat_list[14].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[14].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[14].stec_quality_indicator)),
      51)
      << "incorrect value for stec_sat_list[14].stec_quality_indicator, "
         "expected 51, is "
      << last_msg_->stec_sat_list[14].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].sv_id.constellation)),
            118)
      << "incorrect value for stec_sat_list[14].sv_id.constellation, expected "
         "118, is "
      << last_msg_->stec_sat_list[14].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].sv_id.satId)),
            106)
      << "incorrect value for stec_sat_list[14].sv_id.satId, expected 106, is "
      << last_msg_->stec_sat_list[14].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].stec_coeff[0])),
            -26103)
      << "incorrect value for stec_sat_list[15].stec_coeff[0], expected "
         "-26103, is "
      << last_msg_->stec_sat_list[15].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].stec_coeff[1])),
            -9539)
      << "incorrect value for stec_sat_list[15].stec_coeff[1], expected -9539, "
         "is "
      << last_msg_->stec_sat_list[15].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].stec_coeff[2])),
            -11971)
      << "incorrect value for stec_sat_list[15].stec_coeff[2], expected "
         "-11971, is "
      << last_msg_->stec_sat_list[15].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].stec_coeff[3])),
            20993)
      << "incorrect value for stec_sat_list[15].stec_coeff[3], expected 20993, "
         "is "
      << last_msg_->stec_sat_list[15].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[15].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[15].stec_quality_indicator)),
      165)
      << "incorrect value for stec_sat_list[15].stec_quality_indicator, "
         "expected 165, is "
      << last_msg_->stec_sat_list[15].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].sv_id.constellation)),
            150)
      << "incorrect value for stec_sat_list[15].sv_id.constellation, expected "
         "150, is "
      << last_msg_->stec_sat_list[15].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].sv_id.satId)),
            132)
      << "incorrect value for stec_sat_list[15].sv_id.satId, expected 132, is "
      << last_msg_->stec_sat_list[15].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].stec_coeff[0])),
            -18891)
      << "incorrect value for stec_sat_list[16].stec_coeff[0], expected "
         "-18891, is "
      << last_msg_->stec_sat_list[16].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].stec_coeff[1])),
            -16272)
      << "incorrect value for stec_sat_list[16].stec_coeff[1], expected "
         "-16272, is "
      << last_msg_->stec_sat_list[16].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].stec_coeff[2])),
            -22578)
      << "incorrect value for stec_sat_list[16].stec_coeff[2], expected "
         "-22578, is "
      << last_msg_->stec_sat_list[16].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].stec_coeff[3])),
            -2915)
      << "incorrect value for stec_sat_list[16].stec_coeff[3], expected -2915, "
         "is "
      << last_msg_->stec_sat_list[16].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[16].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[16].stec_quality_indicator)),
      23)
      << "incorrect value for stec_sat_list[16].stec_quality_indicator, "
         "expected 23, is "
      << last_msg_->stec_sat_list[16].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].sv_id.constellation)),
            196)
      << "incorrect value for stec_sat_list[16].sv_id.constellation, expected "
         "196, is "
      << last_msg_->stec_sat_list[16].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].sv_id.satId)),
            181)
      << "incorrect value for stec_sat_list[16].sv_id.satId, expected 181, is "
      << last_msg_->stec_sat_list[16].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].stec_coeff[0])),
            15833)
      << "incorrect value for stec_sat_list[17].stec_coeff[0], expected 15833, "
         "is "
      << last_msg_->stec_sat_list[17].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].stec_coeff[1])),
            24920)
      << "incorrect value for stec_sat_list[17].stec_coeff[1], expected 24920, "
         "is "
      << last_msg_->stec_sat_list[17].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].stec_coeff[2])),
            -13879)
      << "incorrect value for stec_sat_list[17].stec_coeff[2], expected "
         "-13879, is "
      << last_msg_->stec_sat_list[17].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].stec_coeff[3])),
            -1206)
      << "incorrect value for stec_sat_list[17].stec_coeff[3], expected -1206, "
         "is "
      << last_msg_->stec_sat_list[17].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[17].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[17].stec_quality_indicator)),
      189)
      << "incorrect value for stec_sat_list[17].stec_quality_indicator, "
         "expected 189, is "
      << last_msg_->stec_sat_list[17].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].sv_id.constellation)),
            1)
      << "incorrect value for stec_sat_list[17].sv_id.constellation, expected "
         "1, is "
      << last_msg_->stec_sat_list[17].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].sv_id.satId)),
            35)
      << "incorrect value for stec_sat_list[17].sv_id.satId, expected 35, is "
      << last_msg_->stec_sat_list[17].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].stec_coeff[0])),
            14008)
      << "incorrect value for stec_sat_list[18].stec_coeff[0], expected 14008, "
         "is "
      << last_msg_->stec_sat_list[18].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].stec_coeff[1])),
            18996)
      << "incorrect value for stec_sat_list[18].stec_coeff[1], expected 18996, "
         "is "
      << last_msg_->stec_sat_list[18].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].stec_coeff[2])),
            2798)
      << "incorrect value for stec_sat_list[18].stec_coeff[2], expected 2798, "
         "is "
      << last_msg_->stec_sat_list[18].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].stec_coeff[3])),
            5761)
      << "incorrect value for stec_sat_list[18].stec_coeff[3], expected 5761, "
         "is "
      << last_msg_->stec_sat_list[18].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[18].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[18].stec_quality_indicator)),
      104)
      << "incorrect value for stec_sat_list[18].stec_quality_indicator, "
         "expected 104, is "
      << last_msg_->stec_sat_list[18].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].sv_id.constellation)),
            14)
      << "incorrect value for stec_sat_list[18].sv_id.constellation, expected "
         "14, is "
      << last_msg_->stec_sat_list[18].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].sv_id.satId)),
            217)
      << "incorrect value for stec_sat_list[18].sv_id.satId, expected 217, is "
      << last_msg_->stec_sat_list[18].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].stec_coeff[0])),
            -25256)
      << "incorrect value for stec_sat_list[19].stec_coeff[0], expected "
         "-25256, is "
      << last_msg_->stec_sat_list[19].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].stec_coeff[1])),
            -15330)
      << "incorrect value for stec_sat_list[19].stec_coeff[1], expected "
         "-15330, is "
      << last_msg_->stec_sat_list[19].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].stec_coeff[2])),
            6831)
      << "incorrect value for stec_sat_list[19].stec_coeff[2], expected 6831, "
         "is "
      << last_msg_->stec_sat_list[19].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].stec_coeff[3])),
            8780)
      << "incorrect value for stec_sat_list[19].stec_coeff[3], expected 8780, "
         "is "
      << last_msg_->stec_sat_list[19].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[19].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[19].stec_quality_indicator)),
      109)
      << "incorrect value for stec_sat_list[19].stec_quality_indicator, "
         "expected 109, is "
      << last_msg_->stec_sat_list[19].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].sv_id.constellation)),
            226)
      << "incorrect value for stec_sat_list[19].sv_id.constellation, expected "
         "226, is "
      << last_msg_->stec_sat_list[19].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].sv_id.satId)),
            178)
      << "incorrect value for stec_sat_list[19].sv_id.satId, expected 178, is "
      << last_msg_->stec_sat_list[19].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].stec_coeff[0])),
            3304)
      << "incorrect value for stec_sat_list[20].stec_coeff[0], expected 3304, "
         "is "
      << last_msg_->stec_sat_list[20].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].stec_coeff[1])),
            -2893)
      << "incorrect value for stec_sat_list[20].stec_coeff[1], expected -2893, "
         "is "
      << last_msg_->stec_sat_list[20].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].stec_coeff[2])),
            -25841)
      << "incorrect value for stec_sat_list[20].stec_coeff[2], expected "
         "-25841, is "
      << last_msg_->stec_sat_list[20].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].stec_coeff[3])),
            -13628)
      << "incorrect value for stec_sat_list[20].stec_coeff[3], expected "
         "-13628, is "
      << last_msg_->stec_sat_list[20].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[20].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[20].stec_quality_indicator)),
      154)
      << "incorrect value for stec_sat_list[20].stec_quality_indicator, "
         "expected 154, is "
      << last_msg_->stec_sat_list[20].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].sv_id.constellation)),
            220)
      << "incorrect value for stec_sat_list[20].sv_id.constellation, expected "
         "220, is "
      << last_msg_->stec_sat_list[20].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].sv_id.satId)),
            116)
      << "incorrect value for stec_sat_list[20].sv_id.satId, expected 116, is "
      << last_msg_->stec_sat_list[20].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[21].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[21].stec_coeff[0])),
            -10742)
      << "incorrect value for stec_sat_list[21].stec_coeff[0], expected "
         "-10742, is "
      << last_msg_->stec_sat_list[21].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[21].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[21].stec_coeff[1])),
            10098)
      << "incorrect value for stec_sat_list[21].stec_coeff[1], expected 10098, "
         "is "
      << last_msg_->stec_sat_list[21].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[21].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[21].stec_coeff[2])),
            7413)
      << "incorrect value for stec_sat_list[21].stec_coeff[2], expected 7413, "
         "is "
      << last_msg_->stec_sat_list[21].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[21].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[21].stec_coeff[3])),
            17645)
      << "incorrect value for stec_sat_list[21].stec_coeff[3], expected 17645, "
         "is "
      << last_msg_->stec_sat_list[21].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[21].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[21].stec_quality_indicator)),
      115)
      << "incorrect value for stec_sat_list[21].stec_quality_indicator, "
         "expected 115, is "
      << last_msg_->stec_sat_list[21].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[21].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[21].sv_id.constellation)),
            70)
      << "incorrect value for stec_sat_list[21].sv_id.constellation, expected "
         "70, is "
      << last_msg_->stec_sat_list[21].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[21].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[21].sv_id.satId)),
            72)
      << "incorrect value for stec_sat_list[21].sv_id.satId, expected 72, is "
      << last_msg_->stec_sat_list[21].sv_id.satId;
}
