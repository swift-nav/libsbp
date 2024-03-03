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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDep.yaml by
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
class Test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDep0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_stec_correction_dep_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDep0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_stec_correction_dep_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ssr_stec_correction_dep_t *>(
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
                      const msg_ssr_stec_correction_dep_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_stec_correction_dep_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrectionDep0, Test) {
  uint8_t encoded_frame[] = {
      85,  251, 5,   204, 151, 245, 158, 228, 114, 117, 50,  158, 156, 42,  119,
      156, 157, 112, 47,  60,  132, 40,  70,  87,  235, 83,  177, 198, 3,   14,
      8,   70,  12,  44,  53,  181, 90,  174, 247, 150, 58,  172, 247, 179, 119,
      176, 125, 4,   177, 229, 113, 14,  77,  153, 185, 23,  53,  222, 187, 146,
      250, 91,  212, 215, 14,  107, 250, 94,  107, 33,  91,  234, 0,   213, 139,
      95,  179, 50,  21,  74,  174, 169, 61,  86,  91,  142, 51,  108, 9,   38,
      225, 146, 101, 73,  139, 56,  117, 82,  37,  213, 108, 205, 93,  18,  19,
      195, 33,  202, 87,  206, 178, 125, 188, 119, 56,  69,  150, 150, 76,  3,
      131, 18,  73,  208, 72,  232, 8,   250, 203, 178, 170, 163, 252, 86,  49,
      247, 178, 166, 56,  31,  10,  119, 213, 241, 212, 164, 1,   162, 42,  18,
      124, 169, 121, 158, 26,  56,  23,  142, 125, 40,  120, 67,  45,  126, 235,
      110, 23,  12,  241, 88,  69,  239, 252, 57,  93,  44,  201, 216, 173, 242,
      178, 17,  5,   223, 169, 192, 3,   77,  107, 2,   144, 233, 14,  88,  32,
      209, 1,   17,  123, 155, 41,  183, 244, 158, 82,  53,  103, 14,  202, 185,
      35,  181, 21,  118, 254, 250, 50,  184, 50,  31,  45,  56,  163, 177, 126,
      217, 79,  171, 239, 237, 188, 238, 112, 201, 118, 141, 18,  163, 103, 35,
      63,  21,  82,  129, 18,  117, 85,  190, 79,  210, 215, 227, 177,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_stec_correction_dep_t *test_msg =
      (msg_ssr_stec_correction_dep_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->header.iod_atmo = 60;
  test_msg->header.num_msgs = 157;
  test_msg->header.seq_num = 112;
  test_msg->header.tile_id = 30066;
  test_msg->header.tile_set_id = 58526;
  test_msg->header.time.tow = 714907186;
  test_msg->header.time.wn = 40055;
  test_msg->header.update_interval = 47;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[0] = -5289;
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[1] = -20141;
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[2] = 966;
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[3] = 2062;
  test_msg->stec_sat_list[0].stec_quality_indicator = 70;
  test_msg->stec_sat_list[0].sv_id.constellation = 40;
  test_msg->stec_sat_list[0].sv_id.satId = 132;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[0] = -19147;
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[1] = -20902;
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[2] = -26889;
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[3] = -21446;
  test_msg->stec_sat_list[1].stec_quality_indicator = 44;
  test_msg->stec_sat_list[1].sv_id.constellation = 12;
  test_msg->stec_sat_list[1].sv_id.satId = 70;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[2].stec_coeff[0]));
  }
  test_msg->stec_sat_list[2].stec_coeff[0] = 32176;
  if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[2].stec_coeff[0]));
  }
  test_msg->stec_sat_list[2].stec_coeff[1] = -20220;
  if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[2].stec_coeff[0]));
  }
  test_msg->stec_sat_list[2].stec_coeff[2] = 29157;
  if (sizeof(test_msg->stec_sat_list[2].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[2].stec_coeff[0]));
  }
  test_msg->stec_sat_list[2].stec_coeff[3] = 19726;
  test_msg->stec_sat_list[2].stec_quality_indicator = 119;
  test_msg->stec_sat_list[2].sv_id.constellation = 179;
  test_msg->stec_sat_list[2].sv_id.satId = 247;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[3].stec_coeff[0]));
  }
  test_msg->stec_sat_list[3].stec_coeff[0] = -8651;
  if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[3].stec_coeff[0]));
  }
  test_msg->stec_sat_list[3].stec_coeff[1] = -27973;
  if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[3].stec_coeff[0]));
  }
  test_msg->stec_sat_list[3].stec_coeff[2] = 23546;
  if (sizeof(test_msg->stec_sat_list[3].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[3].stec_coeff[0]));
  }
  test_msg->stec_sat_list[3].stec_coeff[3] = -10284;
  test_msg->stec_sat_list[3].stec_quality_indicator = 23;
  test_msg->stec_sat_list[3].sv_id.constellation = 185;
  test_msg->stec_sat_list[3].sv_id.satId = 153;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[4].stec_coeff[0]));
  }
  test_msg->stec_sat_list[4].stec_coeff[0] = 27486;
  if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[4].stec_coeff[0]));
  }
  test_msg->stec_sat_list[4].stec_coeff[1] = 23329;
  if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[4].stec_coeff[0]));
  }
  test_msg->stec_sat_list[4].stec_coeff[2] = 234;
  if (sizeof(test_msg->stec_sat_list[4].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[4].stec_coeff[0]));
  }
  test_msg->stec_sat_list[4].stec_coeff[3] = -29739;
  test_msg->stec_sat_list[4].stec_quality_indicator = 250;
  test_msg->stec_sat_list[4].sv_id.constellation = 107;
  test_msg->stec_sat_list[4].sv_id.satId = 14;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[5].stec_coeff[0]));
  }
  test_msg->stec_sat_list[5].stec_coeff[0] = 18965;
  if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[5].stec_coeff[0]));
  }
  test_msg->stec_sat_list[5].stec_coeff[1] = -22098;
  if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[5].stec_coeff[0]));
  }
  test_msg->stec_sat_list[5].stec_coeff[2] = 22077;
  if (sizeof(test_msg->stec_sat_list[5].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[5].stec_coeff[0]));
  }
  test_msg->stec_sat_list[5].stec_coeff[3] = -29093;
  test_msg->stec_sat_list[5].stec_quality_indicator = 50;
  test_msg->stec_sat_list[5].sv_id.constellation = 179;
  test_msg->stec_sat_list[5].sv_id.satId = 95;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[6].stec_coeff[0]));
  }
  test_msg->stec_sat_list[6].stec_coeff[0] = -7898;
  if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[6].stec_coeff[0]));
  }
  test_msg->stec_sat_list[6].stec_coeff[1] = 26002;
  if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[6].stec_coeff[0]));
  }
  test_msg->stec_sat_list[6].stec_coeff[2] = -29879;
  if (sizeof(test_msg->stec_sat_list[6].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[6].stec_coeff[0]));
  }
  test_msg->stec_sat_list[6].stec_coeff[3] = 30008;
  test_msg->stec_sat_list[6].stec_quality_indicator = 9;
  test_msg->stec_sat_list[6].sv_id.constellation = 108;
  test_msg->stec_sat_list[6].sv_id.satId = 51;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[7].stec_coeff[0]));
  }
  test_msg->stec_sat_list[7].stec_coeff[0] = -12948;
  if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[7].stec_coeff[0]));
  }
  test_msg->stec_sat_list[7].stec_coeff[1] = 4701;
  if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[7].stec_coeff[0]));
  }
  test_msg->stec_sat_list[7].stec_coeff[2] = -15597;
  if (sizeof(test_msg->stec_sat_list[7].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[7].stec_coeff[0]));
  }
  test_msg->stec_sat_list[7].stec_coeff[3] = -13791;
  test_msg->stec_sat_list[7].stec_quality_indicator = 213;
  test_msg->stec_sat_list[7].sv_id.constellation = 37;
  test_msg->stec_sat_list[7].sv_id.satId = 82;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[8].stec_coeff[0]));
  }
  test_msg->stec_sat_list[8].stec_coeff[0] = -17283;
  if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[8].stec_coeff[0]));
  }
  test_msg->stec_sat_list[8].stec_coeff[1] = 14455;
  if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[8].stec_coeff[0]));
  }
  test_msg->stec_sat_list[8].stec_coeff[2] = -27067;
  if (sizeof(test_msg->stec_sat_list[8].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[8].stec_coeff[0]));
  }
  test_msg->stec_sat_list[8].stec_coeff[3] = 19606;
  test_msg->stec_sat_list[8].stec_quality_indicator = 178;
  test_msg->stec_sat_list[8].sv_id.constellation = 206;
  test_msg->stec_sat_list[8].sv_id.satId = 87;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[9].stec_coeff[0]));
  }
  test_msg->stec_sat_list[9].stec_coeff[0] = -12215;
  if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[9].stec_coeff[0]));
  }
  test_msg->stec_sat_list[9].stec_coeff[1] = -6072;
  if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[9].stec_coeff[0]));
  }
  test_msg->stec_sat_list[9].stec_coeff[2] = -1528;
  if (sizeof(test_msg->stec_sat_list[9].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[9].stec_coeff[0]));
  }
  test_msg->stec_sat_list[9].stec_coeff[3] = -19765;
  test_msg->stec_sat_list[9].stec_quality_indicator = 18;
  test_msg->stec_sat_list[9].sv_id.constellation = 131;
  test_msg->stec_sat_list[9].sv_id.satId = 3;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[10].stec_coeff[0]));
  }
  test_msg->stec_sat_list[10].stec_coeff[0] = 12630;
  if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[10].stec_coeff[0]));
  }
  test_msg->stec_sat_list[10].stec_coeff[1] = -19721;
  if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[10].stec_coeff[0]));
  }
  test_msg->stec_sat_list[10].stec_coeff[2] = 14502;
  if (sizeof(test_msg->stec_sat_list[10].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[10].stec_coeff[0]));
  }
  test_msg->stec_sat_list[10].stec_coeff[3] = 2591;
  test_msg->stec_sat_list[10].stec_quality_indicator = 252;
  test_msg->stec_sat_list[10].sv_id.constellation = 163;
  test_msg->stec_sat_list[10].sv_id.satId = 170;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[11].stec_coeff[0]));
  }
  test_msg->stec_sat_list[11].stec_coeff[0] = -23340;
  if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[11].stec_coeff[0]));
  }
  test_msg->stec_sat_list[11].stec_coeff[1] = -24063;
  if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[11].stec_coeff[0]));
  }
  test_msg->stec_sat_list[11].stec_coeff[2] = 4650;
  if (sizeof(test_msg->stec_sat_list[11].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[11].stec_coeff[0]));
  }
  test_msg->stec_sat_list[11].stec_coeff[3] = -22148;
  test_msg->stec_sat_list[11].stec_quality_indicator = 241;
  test_msg->stec_sat_list[11].sv_id.constellation = 213;
  test_msg->stec_sat_list[11].sv_id.satId = 119;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[12].stec_coeff[0]));
  }
  test_msg->stec_sat_list[12].stec_coeff[0] = 5944;
  if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[12].stec_coeff[0]));
  }
  test_msg->stec_sat_list[12].stec_coeff[1] = 32142;
  if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[12].stec_coeff[0]));
  }
  test_msg->stec_sat_list[12].stec_coeff[2] = 30760;
  if (sizeof(test_msg->stec_sat_list[12].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[12].stec_coeff[0]));
  }
  test_msg->stec_sat_list[12].stec_coeff[3] = 11587;
  test_msg->stec_sat_list[12].stec_quality_indicator = 26;
  test_msg->stec_sat_list[12].sv_id.constellation = 158;
  test_msg->stec_sat_list[12].sv_id.satId = 121;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[13].stec_coeff[0]));
  }
  test_msg->stec_sat_list[13].stec_coeff[0] = 3095;
  if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[13].stec_coeff[0]));
  }
  test_msg->stec_sat_list[13].stec_coeff[1] = 22769;
  if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[13].stec_coeff[0]));
  }
  test_msg->stec_sat_list[13].stec_coeff[2] = -4283;
  if (sizeof(test_msg->stec_sat_list[13].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[13].stec_coeff[0]));
  }
  test_msg->stec_sat_list[13].stec_coeff[3] = 14844;
  test_msg->stec_sat_list[13].stec_quality_indicator = 110;
  test_msg->stec_sat_list[13].sv_id.constellation = 235;
  test_msg->stec_sat_list[13].sv_id.satId = 126;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[14].stec_coeff[0]));
  }
  test_msg->stec_sat_list[14].stec_coeff[0] = -21032;
  if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[14].stec_coeff[0]));
  }
  test_msg->stec_sat_list[14].stec_coeff[1] = -19726;
  if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[14].stec_coeff[0]));
  }
  test_msg->stec_sat_list[14].stec_coeff[2] = 1297;
  if (sizeof(test_msg->stec_sat_list[14].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[14].stec_coeff[0]));
  }
  test_msg->stec_sat_list[14].stec_coeff[3] = -22049;
  test_msg->stec_sat_list[14].stec_quality_indicator = 201;
  test_msg->stec_sat_list[14].sv_id.constellation = 44;
  test_msg->stec_sat_list[14].sv_id.satId = 93;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[15].stec_coeff[0]));
  }
  test_msg->stec_sat_list[15].stec_coeff[0] = 619;
  if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[15].stec_coeff[0]));
  }
  test_msg->stec_sat_list[15].stec_coeff[1] = -5744;
  if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[15].stec_coeff[0]));
  }
  test_msg->stec_sat_list[15].stec_coeff[2] = 22542;
  if (sizeof(test_msg->stec_sat_list[15].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[15].stec_coeff[0]));
  }
  test_msg->stec_sat_list[15].stec_coeff[3] = -12000;
  test_msg->stec_sat_list[15].stec_quality_indicator = 77;
  test_msg->stec_sat_list[15].sv_id.constellation = 3;
  test_msg->stec_sat_list[15].sv_id.satId = 192;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[16].stec_coeff[0]));
  }
  test_msg->stec_sat_list[16].stec_coeff[0] = 10651;
  if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[16].stec_coeff[0]));
  }
  test_msg->stec_sat_list[16].stec_coeff[1] = -2889;
  if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[16].stec_coeff[0]));
  }
  test_msg->stec_sat_list[16].stec_coeff[2] = 21150;
  if (sizeof(test_msg->stec_sat_list[16].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[16].stec_coeff[0]));
  }
  test_msg->stec_sat_list[16].stec_coeff[3] = 26421;
  test_msg->stec_sat_list[16].stec_quality_indicator = 123;
  test_msg->stec_sat_list[16].sv_id.constellation = 17;
  test_msg->stec_sat_list[16].sv_id.satId = 1;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[17].stec_coeff[0]));
  }
  test_msg->stec_sat_list[17].stec_coeff[0] = -19165;
  if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[17].stec_coeff[0]));
  }
  test_msg->stec_sat_list[17].stec_coeff[1] = 30229;
  if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[17].stec_coeff[0]));
  }
  test_msg->stec_sat_list[17].stec_coeff[2] = -1282;
  if (sizeof(test_msg->stec_sat_list[17].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[17].stec_coeff[0]));
  }
  test_msg->stec_sat_list[17].stec_coeff[3] = -18382;
  test_msg->stec_sat_list[17].stec_quality_indicator = 185;
  test_msg->stec_sat_list[17].sv_id.constellation = 202;
  test_msg->stec_sat_list[17].sv_id.satId = 14;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[18].stec_coeff[0]));
  }
  test_msg->stec_sat_list[18].stec_coeff[0] = -23752;
  if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[18].stec_coeff[0]));
  }
  test_msg->stec_sat_list[18].stec_coeff[1] = 32433;
  if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[18].stec_coeff[0]));
  }
  test_msg->stec_sat_list[18].stec_coeff[2] = 20441;
  if (sizeof(test_msg->stec_sat_list[18].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[18].stec_coeff[0]));
  }
  test_msg->stec_sat_list[18].stec_coeff[3] = -4181;
  test_msg->stec_sat_list[18].stec_quality_indicator = 45;
  test_msg->stec_sat_list[18].sv_id.constellation = 31;
  test_msg->stec_sat_list[18].sv_id.satId = 50;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[19].stec_coeff[0]));
  }
  test_msg->stec_sat_list[19].stec_coeff[0] = -13968;
  if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[19].stec_coeff[0]));
  }
  test_msg->stec_sat_list[19].stec_coeff[1] = -29322;
  if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[19].stec_coeff[0]));
  }
  test_msg->stec_sat_list[19].stec_coeff[2] = -23790;
  if (sizeof(test_msg->stec_sat_list[19].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[19].stec_coeff[0]));
  }
  test_msg->stec_sat_list[19].stec_coeff[3] = 9063;
  test_msg->stec_sat_list[19].stec_quality_indicator = 238;
  test_msg->stec_sat_list[19].sv_id.constellation = 188;
  test_msg->stec_sat_list[19].sv_id.satId = 237;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[20].stec_coeff[0]));
  }
  test_msg->stec_sat_list[20].stec_coeff[0] = 4737;
  if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[20].stec_coeff[0]));
  }
  test_msg->stec_sat_list[20].stec_coeff[1] = 21877;
  if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[20].stec_coeff[0]));
  }
  test_msg->stec_sat_list[20].stec_coeff[2] = 20414;
  if (sizeof(test_msg->stec_sat_list[20].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[20].stec_coeff[0]));
  }
  test_msg->stec_sat_list[20].stec_coeff[3] = -10286;
  test_msg->stec_sat_list[20].stec_quality_indicator = 82;
  test_msg->stec_sat_list[20].sv_id.constellation = 21;
  test_msg->stec_sat_list[20].sv_id.satId = 63;

  EXPECT_EQ(send_message(0x5fb, 38860, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 38860);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->header.iod_atmo)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.iod_atmo)),
            60)
      << "incorrect value for header.iod_atmo, expected 60, is "
      << last_msg_->header.iod_atmo;
  EXPECT_EQ(get_as<decltype(last_msg_->header.num_msgs)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.num_msgs)),
            157)
      << "incorrect value for header.num_msgs, expected 157, is "
      << last_msg_->header.num_msgs;
  EXPECT_EQ(get_as<decltype(last_msg_->header.seq_num)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.seq_num)),
            112)
      << "incorrect value for header.seq_num, expected 112, is "
      << last_msg_->header.seq_num;
  EXPECT_EQ(get_as<decltype(last_msg_->header.tile_id)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.tile_id)),
            30066)
      << "incorrect value for header.tile_id, expected 30066, is "
      << last_msg_->header.tile_id;
  EXPECT_EQ(
      get_as<decltype(last_msg_->header.tile_set_id)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->header.tile_set_id)),
      58526)
      << "incorrect value for header.tile_set_id, expected 58526, is "
      << last_msg_->header.tile_set_id;
  EXPECT_EQ(get_as<decltype(last_msg_->header.time.tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.time.tow)),
            714907186)
      << "incorrect value for header.time.tow, expected 714907186, is "
      << last_msg_->header.time.tow;
  EXPECT_EQ(get_as<decltype(last_msg_->header.time.wn)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.time.wn)),
            40055)
      << "incorrect value for header.time.wn, expected 40055, is "
      << last_msg_->header.time.wn;
  EXPECT_EQ(get_as<decltype(last_msg_->header.update_interval)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->header.update_interval)),
            47)
      << "incorrect value for header.update_interval, expected 47, is "
      << last_msg_->header.update_interval;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].stec_coeff[0])),
            -5289)
      << "incorrect value for stec_sat_list[0].stec_coeff[0], expected -5289, "
         "is "
      << last_msg_->stec_sat_list[0].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].stec_coeff[1])),
            -20141)
      << "incorrect value for stec_sat_list[0].stec_coeff[1], expected -20141, "
         "is "
      << last_msg_->stec_sat_list[0].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].stec_coeff[2])),
            966)
      << "incorrect value for stec_sat_list[0].stec_coeff[2], expected 966, is "
      << last_msg_->stec_sat_list[0].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].stec_coeff[3])),
            2062)
      << "incorrect value for stec_sat_list[0].stec_coeff[3], expected 2062, "
         "is "
      << last_msg_->stec_sat_list[0].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[0].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[0].stec_quality_indicator)),
      70)
      << "incorrect value for stec_sat_list[0].stec_quality_indicator, "
         "expected 70, is "
      << last_msg_->stec_sat_list[0].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].sv_id.constellation)),
            40)
      << "incorrect value for stec_sat_list[0].sv_id.constellation, expected "
         "40, is "
      << last_msg_->stec_sat_list[0].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[0].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[0].sv_id.satId)),
            132)
      << "incorrect value for stec_sat_list[0].sv_id.satId, expected 132, is "
      << last_msg_->stec_sat_list[0].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].stec_coeff[0])),
            -19147)
      << "incorrect value for stec_sat_list[1].stec_coeff[0], expected -19147, "
         "is "
      << last_msg_->stec_sat_list[1].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].stec_coeff[1])),
            -20902)
      << "incorrect value for stec_sat_list[1].stec_coeff[1], expected -20902, "
         "is "
      << last_msg_->stec_sat_list[1].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].stec_coeff[2])),
            -26889)
      << "incorrect value for stec_sat_list[1].stec_coeff[2], expected -26889, "
         "is "
      << last_msg_->stec_sat_list[1].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].stec_coeff[3])),
            -21446)
      << "incorrect value for stec_sat_list[1].stec_coeff[3], expected -21446, "
         "is "
      << last_msg_->stec_sat_list[1].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[1].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[1].stec_quality_indicator)),
      44)
      << "incorrect value for stec_sat_list[1].stec_quality_indicator, "
         "expected 44, is "
      << last_msg_->stec_sat_list[1].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].sv_id.constellation)),
            12)
      << "incorrect value for stec_sat_list[1].sv_id.constellation, expected "
         "12, is "
      << last_msg_->stec_sat_list[1].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[1].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[1].sv_id.satId)),
            70)
      << "incorrect value for stec_sat_list[1].sv_id.satId, expected 70, is "
      << last_msg_->stec_sat_list[1].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].stec_coeff[0])),
            32176)
      << "incorrect value for stec_sat_list[2].stec_coeff[0], expected 32176, "
         "is "
      << last_msg_->stec_sat_list[2].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].stec_coeff[1])),
            -20220)
      << "incorrect value for stec_sat_list[2].stec_coeff[1], expected -20220, "
         "is "
      << last_msg_->stec_sat_list[2].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].stec_coeff[2])),
            29157)
      << "incorrect value for stec_sat_list[2].stec_coeff[2], expected 29157, "
         "is "
      << last_msg_->stec_sat_list[2].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].stec_coeff[3])),
            19726)
      << "incorrect value for stec_sat_list[2].stec_coeff[3], expected 19726, "
         "is "
      << last_msg_->stec_sat_list[2].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[2].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[2].stec_quality_indicator)),
      119)
      << "incorrect value for stec_sat_list[2].stec_quality_indicator, "
         "expected 119, is "
      << last_msg_->stec_sat_list[2].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].sv_id.constellation)),
            179)
      << "incorrect value for stec_sat_list[2].sv_id.constellation, expected "
         "179, is "
      << last_msg_->stec_sat_list[2].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[2].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[2].sv_id.satId)),
            247)
      << "incorrect value for stec_sat_list[2].sv_id.satId, expected 247, is "
      << last_msg_->stec_sat_list[2].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].stec_coeff[0])),
            -8651)
      << "incorrect value for stec_sat_list[3].stec_coeff[0], expected -8651, "
         "is "
      << last_msg_->stec_sat_list[3].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].stec_coeff[1])),
            -27973)
      << "incorrect value for stec_sat_list[3].stec_coeff[1], expected -27973, "
         "is "
      << last_msg_->stec_sat_list[3].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].stec_coeff[2])),
            23546)
      << "incorrect value for stec_sat_list[3].stec_coeff[2], expected 23546, "
         "is "
      << last_msg_->stec_sat_list[3].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].stec_coeff[3])),
            -10284)
      << "incorrect value for stec_sat_list[3].stec_coeff[3], expected -10284, "
         "is "
      << last_msg_->stec_sat_list[3].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[3].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[3].stec_quality_indicator)),
      23)
      << "incorrect value for stec_sat_list[3].stec_quality_indicator, "
         "expected 23, is "
      << last_msg_->stec_sat_list[3].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].sv_id.constellation)),
            185)
      << "incorrect value for stec_sat_list[3].sv_id.constellation, expected "
         "185, is "
      << last_msg_->stec_sat_list[3].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[3].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[3].sv_id.satId)),
            153)
      << "incorrect value for stec_sat_list[3].sv_id.satId, expected 153, is "
      << last_msg_->stec_sat_list[3].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].stec_coeff[0])),
            27486)
      << "incorrect value for stec_sat_list[4].stec_coeff[0], expected 27486, "
         "is "
      << last_msg_->stec_sat_list[4].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].stec_coeff[1])),
            23329)
      << "incorrect value for stec_sat_list[4].stec_coeff[1], expected 23329, "
         "is "
      << last_msg_->stec_sat_list[4].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].stec_coeff[2])),
            234)
      << "incorrect value for stec_sat_list[4].stec_coeff[2], expected 234, is "
      << last_msg_->stec_sat_list[4].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].stec_coeff[3])),
            -29739)
      << "incorrect value for stec_sat_list[4].stec_coeff[3], expected -29739, "
         "is "
      << last_msg_->stec_sat_list[4].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[4].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[4].stec_quality_indicator)),
      250)
      << "incorrect value for stec_sat_list[4].stec_quality_indicator, "
         "expected 250, is "
      << last_msg_->stec_sat_list[4].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].sv_id.constellation)),
            107)
      << "incorrect value for stec_sat_list[4].sv_id.constellation, expected "
         "107, is "
      << last_msg_->stec_sat_list[4].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[4].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[4].sv_id.satId)),
            14)
      << "incorrect value for stec_sat_list[4].sv_id.satId, expected 14, is "
      << last_msg_->stec_sat_list[4].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].stec_coeff[0])),
            18965)
      << "incorrect value for stec_sat_list[5].stec_coeff[0], expected 18965, "
         "is "
      << last_msg_->stec_sat_list[5].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].stec_coeff[1])),
            -22098)
      << "incorrect value for stec_sat_list[5].stec_coeff[1], expected -22098, "
         "is "
      << last_msg_->stec_sat_list[5].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].stec_coeff[2])),
            22077)
      << "incorrect value for stec_sat_list[5].stec_coeff[2], expected 22077, "
         "is "
      << last_msg_->stec_sat_list[5].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].stec_coeff[3])),
            -29093)
      << "incorrect value for stec_sat_list[5].stec_coeff[3], expected -29093, "
         "is "
      << last_msg_->stec_sat_list[5].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[5].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[5].stec_quality_indicator)),
      50)
      << "incorrect value for stec_sat_list[5].stec_quality_indicator, "
         "expected 50, is "
      << last_msg_->stec_sat_list[5].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].sv_id.constellation)),
            179)
      << "incorrect value for stec_sat_list[5].sv_id.constellation, expected "
         "179, is "
      << last_msg_->stec_sat_list[5].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[5].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[5].sv_id.satId)),
            95)
      << "incorrect value for stec_sat_list[5].sv_id.satId, expected 95, is "
      << last_msg_->stec_sat_list[5].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].stec_coeff[0])),
            -7898)
      << "incorrect value for stec_sat_list[6].stec_coeff[0], expected -7898, "
         "is "
      << last_msg_->stec_sat_list[6].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].stec_coeff[1])),
            26002)
      << "incorrect value for stec_sat_list[6].stec_coeff[1], expected 26002, "
         "is "
      << last_msg_->stec_sat_list[6].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].stec_coeff[2])),
            -29879)
      << "incorrect value for stec_sat_list[6].stec_coeff[2], expected -29879, "
         "is "
      << last_msg_->stec_sat_list[6].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].stec_coeff[3])),
            30008)
      << "incorrect value for stec_sat_list[6].stec_coeff[3], expected 30008, "
         "is "
      << last_msg_->stec_sat_list[6].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[6].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[6].stec_quality_indicator)),
      9)
      << "incorrect value for stec_sat_list[6].stec_quality_indicator, "
         "expected 9, is "
      << last_msg_->stec_sat_list[6].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].sv_id.constellation)),
            108)
      << "incorrect value for stec_sat_list[6].sv_id.constellation, expected "
         "108, is "
      << last_msg_->stec_sat_list[6].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[6].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[6].sv_id.satId)),
            51)
      << "incorrect value for stec_sat_list[6].sv_id.satId, expected 51, is "
      << last_msg_->stec_sat_list[6].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].stec_coeff[0])),
            -12948)
      << "incorrect value for stec_sat_list[7].stec_coeff[0], expected -12948, "
         "is "
      << last_msg_->stec_sat_list[7].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].stec_coeff[1])),
            4701)
      << "incorrect value for stec_sat_list[7].stec_coeff[1], expected 4701, "
         "is "
      << last_msg_->stec_sat_list[7].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].stec_coeff[2])),
            -15597)
      << "incorrect value for stec_sat_list[7].stec_coeff[2], expected -15597, "
         "is "
      << last_msg_->stec_sat_list[7].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].stec_coeff[3])),
            -13791)
      << "incorrect value for stec_sat_list[7].stec_coeff[3], expected -13791, "
         "is "
      << last_msg_->stec_sat_list[7].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[7].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[7].stec_quality_indicator)),
      213)
      << "incorrect value for stec_sat_list[7].stec_quality_indicator, "
         "expected 213, is "
      << last_msg_->stec_sat_list[7].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].sv_id.constellation)),
            37)
      << "incorrect value for stec_sat_list[7].sv_id.constellation, expected "
         "37, is "
      << last_msg_->stec_sat_list[7].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[7].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[7].sv_id.satId)),
            82)
      << "incorrect value for stec_sat_list[7].sv_id.satId, expected 82, is "
      << last_msg_->stec_sat_list[7].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].stec_coeff[0])),
            -17283)
      << "incorrect value for stec_sat_list[8].stec_coeff[0], expected -17283, "
         "is "
      << last_msg_->stec_sat_list[8].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].stec_coeff[1])),
            14455)
      << "incorrect value for stec_sat_list[8].stec_coeff[1], expected 14455, "
         "is "
      << last_msg_->stec_sat_list[8].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].stec_coeff[2])),
            -27067)
      << "incorrect value for stec_sat_list[8].stec_coeff[2], expected -27067, "
         "is "
      << last_msg_->stec_sat_list[8].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].stec_coeff[3])),
            19606)
      << "incorrect value for stec_sat_list[8].stec_coeff[3], expected 19606, "
         "is "
      << last_msg_->stec_sat_list[8].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[8].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[8].stec_quality_indicator)),
      178)
      << "incorrect value for stec_sat_list[8].stec_quality_indicator, "
         "expected 178, is "
      << last_msg_->stec_sat_list[8].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].sv_id.constellation)),
            206)
      << "incorrect value for stec_sat_list[8].sv_id.constellation, expected "
         "206, is "
      << last_msg_->stec_sat_list[8].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[8].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[8].sv_id.satId)),
            87)
      << "incorrect value for stec_sat_list[8].sv_id.satId, expected 87, is "
      << last_msg_->stec_sat_list[8].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].stec_coeff[0])),
            -12215)
      << "incorrect value for stec_sat_list[9].stec_coeff[0], expected -12215, "
         "is "
      << last_msg_->stec_sat_list[9].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].stec_coeff[1])),
            -6072)
      << "incorrect value for stec_sat_list[9].stec_coeff[1], expected -6072, "
         "is "
      << last_msg_->stec_sat_list[9].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].stec_coeff[2])),
            -1528)
      << "incorrect value for stec_sat_list[9].stec_coeff[2], expected -1528, "
         "is "
      << last_msg_->stec_sat_list[9].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].stec_coeff[3])),
            -19765)
      << "incorrect value for stec_sat_list[9].stec_coeff[3], expected -19765, "
         "is "
      << last_msg_->stec_sat_list[9].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[9].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[9].stec_quality_indicator)),
      18)
      << "incorrect value for stec_sat_list[9].stec_quality_indicator, "
         "expected 18, is "
      << last_msg_->stec_sat_list[9].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].sv_id.constellation)),
            131)
      << "incorrect value for stec_sat_list[9].sv_id.constellation, expected "
         "131, is "
      << last_msg_->stec_sat_list[9].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[9].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[9].sv_id.satId)),
            3)
      << "incorrect value for stec_sat_list[9].sv_id.satId, expected 3, is "
      << last_msg_->stec_sat_list[9].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].stec_coeff[0])),
            12630)
      << "incorrect value for stec_sat_list[10].stec_coeff[0], expected 12630, "
         "is "
      << last_msg_->stec_sat_list[10].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].stec_coeff[1])),
            -19721)
      << "incorrect value for stec_sat_list[10].stec_coeff[1], expected "
         "-19721, is "
      << last_msg_->stec_sat_list[10].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].stec_coeff[2])),
            14502)
      << "incorrect value for stec_sat_list[10].stec_coeff[2], expected 14502, "
         "is "
      << last_msg_->stec_sat_list[10].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].stec_coeff[3])),
            2591)
      << "incorrect value for stec_sat_list[10].stec_coeff[3], expected 2591, "
         "is "
      << last_msg_->stec_sat_list[10].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[10].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[10].stec_quality_indicator)),
      252)
      << "incorrect value for stec_sat_list[10].stec_quality_indicator, "
         "expected 252, is "
      << last_msg_->stec_sat_list[10].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].sv_id.constellation)),
            163)
      << "incorrect value for stec_sat_list[10].sv_id.constellation, expected "
         "163, is "
      << last_msg_->stec_sat_list[10].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[10].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[10].sv_id.satId)),
            170)
      << "incorrect value for stec_sat_list[10].sv_id.satId, expected 170, is "
      << last_msg_->stec_sat_list[10].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].stec_coeff[0])),
            -23340)
      << "incorrect value for stec_sat_list[11].stec_coeff[0], expected "
         "-23340, is "
      << last_msg_->stec_sat_list[11].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].stec_coeff[1])),
            -24063)
      << "incorrect value for stec_sat_list[11].stec_coeff[1], expected "
         "-24063, is "
      << last_msg_->stec_sat_list[11].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].stec_coeff[2])),
            4650)
      << "incorrect value for stec_sat_list[11].stec_coeff[2], expected 4650, "
         "is "
      << last_msg_->stec_sat_list[11].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].stec_coeff[3])),
            -22148)
      << "incorrect value for stec_sat_list[11].stec_coeff[3], expected "
         "-22148, is "
      << last_msg_->stec_sat_list[11].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[11].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[11].stec_quality_indicator)),
      241)
      << "incorrect value for stec_sat_list[11].stec_quality_indicator, "
         "expected 241, is "
      << last_msg_->stec_sat_list[11].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].sv_id.constellation)),
            213)
      << "incorrect value for stec_sat_list[11].sv_id.constellation, expected "
         "213, is "
      << last_msg_->stec_sat_list[11].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[11].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[11].sv_id.satId)),
            119)
      << "incorrect value for stec_sat_list[11].sv_id.satId, expected 119, is "
      << last_msg_->stec_sat_list[11].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].stec_coeff[0])),
            5944)
      << "incorrect value for stec_sat_list[12].stec_coeff[0], expected 5944, "
         "is "
      << last_msg_->stec_sat_list[12].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].stec_coeff[1])),
            32142)
      << "incorrect value for stec_sat_list[12].stec_coeff[1], expected 32142, "
         "is "
      << last_msg_->stec_sat_list[12].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].stec_coeff[2])),
            30760)
      << "incorrect value for stec_sat_list[12].stec_coeff[2], expected 30760, "
         "is "
      << last_msg_->stec_sat_list[12].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].stec_coeff[3])),
            11587)
      << "incorrect value for stec_sat_list[12].stec_coeff[3], expected 11587, "
         "is "
      << last_msg_->stec_sat_list[12].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[12].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[12].stec_quality_indicator)),
      26)
      << "incorrect value for stec_sat_list[12].stec_quality_indicator, "
         "expected 26, is "
      << last_msg_->stec_sat_list[12].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].sv_id.constellation)),
            158)
      << "incorrect value for stec_sat_list[12].sv_id.constellation, expected "
         "158, is "
      << last_msg_->stec_sat_list[12].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[12].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[12].sv_id.satId)),
            121)
      << "incorrect value for stec_sat_list[12].sv_id.satId, expected 121, is "
      << last_msg_->stec_sat_list[12].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].stec_coeff[0])),
            3095)
      << "incorrect value for stec_sat_list[13].stec_coeff[0], expected 3095, "
         "is "
      << last_msg_->stec_sat_list[13].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].stec_coeff[1])),
            22769)
      << "incorrect value for stec_sat_list[13].stec_coeff[1], expected 22769, "
         "is "
      << last_msg_->stec_sat_list[13].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].stec_coeff[2])),
            -4283)
      << "incorrect value for stec_sat_list[13].stec_coeff[2], expected -4283, "
         "is "
      << last_msg_->stec_sat_list[13].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].stec_coeff[3])),
            14844)
      << "incorrect value for stec_sat_list[13].stec_coeff[3], expected 14844, "
         "is "
      << last_msg_->stec_sat_list[13].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[13].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[13].stec_quality_indicator)),
      110)
      << "incorrect value for stec_sat_list[13].stec_quality_indicator, "
         "expected 110, is "
      << last_msg_->stec_sat_list[13].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].sv_id.constellation)),
            235)
      << "incorrect value for stec_sat_list[13].sv_id.constellation, expected "
         "235, is "
      << last_msg_->stec_sat_list[13].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[13].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[13].sv_id.satId)),
            126)
      << "incorrect value for stec_sat_list[13].sv_id.satId, expected 126, is "
      << last_msg_->stec_sat_list[13].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].stec_coeff[0])),
            -21032)
      << "incorrect value for stec_sat_list[14].stec_coeff[0], expected "
         "-21032, is "
      << last_msg_->stec_sat_list[14].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].stec_coeff[1])),
            -19726)
      << "incorrect value for stec_sat_list[14].stec_coeff[1], expected "
         "-19726, is "
      << last_msg_->stec_sat_list[14].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].stec_coeff[2])),
            1297)
      << "incorrect value for stec_sat_list[14].stec_coeff[2], expected 1297, "
         "is "
      << last_msg_->stec_sat_list[14].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].stec_coeff[3])),
            -22049)
      << "incorrect value for stec_sat_list[14].stec_coeff[3], expected "
         "-22049, is "
      << last_msg_->stec_sat_list[14].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[14].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[14].stec_quality_indicator)),
      201)
      << "incorrect value for stec_sat_list[14].stec_quality_indicator, "
         "expected 201, is "
      << last_msg_->stec_sat_list[14].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].sv_id.constellation)),
            44)
      << "incorrect value for stec_sat_list[14].sv_id.constellation, expected "
         "44, is "
      << last_msg_->stec_sat_list[14].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[14].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[14].sv_id.satId)),
            93)
      << "incorrect value for stec_sat_list[14].sv_id.satId, expected 93, is "
      << last_msg_->stec_sat_list[14].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].stec_coeff[0])),
            619)
      << "incorrect value for stec_sat_list[15].stec_coeff[0], expected 619, "
         "is "
      << last_msg_->stec_sat_list[15].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].stec_coeff[1])),
            -5744)
      << "incorrect value for stec_sat_list[15].stec_coeff[1], expected -5744, "
         "is "
      << last_msg_->stec_sat_list[15].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].stec_coeff[2])),
            22542)
      << "incorrect value for stec_sat_list[15].stec_coeff[2], expected 22542, "
         "is "
      << last_msg_->stec_sat_list[15].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].stec_coeff[3])),
            -12000)
      << "incorrect value for stec_sat_list[15].stec_coeff[3], expected "
         "-12000, is "
      << last_msg_->stec_sat_list[15].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[15].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[15].stec_quality_indicator)),
      77)
      << "incorrect value for stec_sat_list[15].stec_quality_indicator, "
         "expected 77, is "
      << last_msg_->stec_sat_list[15].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].sv_id.constellation)),
            3)
      << "incorrect value for stec_sat_list[15].sv_id.constellation, expected "
         "3, is "
      << last_msg_->stec_sat_list[15].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[15].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[15].sv_id.satId)),
            192)
      << "incorrect value for stec_sat_list[15].sv_id.satId, expected 192, is "
      << last_msg_->stec_sat_list[15].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].stec_coeff[0])),
            10651)
      << "incorrect value for stec_sat_list[16].stec_coeff[0], expected 10651, "
         "is "
      << last_msg_->stec_sat_list[16].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].stec_coeff[1])),
            -2889)
      << "incorrect value for stec_sat_list[16].stec_coeff[1], expected -2889, "
         "is "
      << last_msg_->stec_sat_list[16].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].stec_coeff[2])),
            21150)
      << "incorrect value for stec_sat_list[16].stec_coeff[2], expected 21150, "
         "is "
      << last_msg_->stec_sat_list[16].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].stec_coeff[3])),
            26421)
      << "incorrect value for stec_sat_list[16].stec_coeff[3], expected 26421, "
         "is "
      << last_msg_->stec_sat_list[16].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[16].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[16].stec_quality_indicator)),
      123)
      << "incorrect value for stec_sat_list[16].stec_quality_indicator, "
         "expected 123, is "
      << last_msg_->stec_sat_list[16].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].sv_id.constellation)),
            17)
      << "incorrect value for stec_sat_list[16].sv_id.constellation, expected "
         "17, is "
      << last_msg_->stec_sat_list[16].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[16].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[16].sv_id.satId)),
            1)
      << "incorrect value for stec_sat_list[16].sv_id.satId, expected 1, is "
      << last_msg_->stec_sat_list[16].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].stec_coeff[0])),
            -19165)
      << "incorrect value for stec_sat_list[17].stec_coeff[0], expected "
         "-19165, is "
      << last_msg_->stec_sat_list[17].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].stec_coeff[1])),
            30229)
      << "incorrect value for stec_sat_list[17].stec_coeff[1], expected 30229, "
         "is "
      << last_msg_->stec_sat_list[17].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].stec_coeff[2])),
            -1282)
      << "incorrect value for stec_sat_list[17].stec_coeff[2], expected -1282, "
         "is "
      << last_msg_->stec_sat_list[17].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].stec_coeff[3])),
            -18382)
      << "incorrect value for stec_sat_list[17].stec_coeff[3], expected "
         "-18382, is "
      << last_msg_->stec_sat_list[17].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[17].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[17].stec_quality_indicator)),
      185)
      << "incorrect value for stec_sat_list[17].stec_quality_indicator, "
         "expected 185, is "
      << last_msg_->stec_sat_list[17].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].sv_id.constellation)),
            202)
      << "incorrect value for stec_sat_list[17].sv_id.constellation, expected "
         "202, is "
      << last_msg_->stec_sat_list[17].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[17].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[17].sv_id.satId)),
            14)
      << "incorrect value for stec_sat_list[17].sv_id.satId, expected 14, is "
      << last_msg_->stec_sat_list[17].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].stec_coeff[0])),
            -23752)
      << "incorrect value for stec_sat_list[18].stec_coeff[0], expected "
         "-23752, is "
      << last_msg_->stec_sat_list[18].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].stec_coeff[1])),
            32433)
      << "incorrect value for stec_sat_list[18].stec_coeff[1], expected 32433, "
         "is "
      << last_msg_->stec_sat_list[18].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].stec_coeff[2])),
            20441)
      << "incorrect value for stec_sat_list[18].stec_coeff[2], expected 20441, "
         "is "
      << last_msg_->stec_sat_list[18].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].stec_coeff[3])),
            -4181)
      << "incorrect value for stec_sat_list[18].stec_coeff[3], expected -4181, "
         "is "
      << last_msg_->stec_sat_list[18].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[18].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[18].stec_quality_indicator)),
      45)
      << "incorrect value for stec_sat_list[18].stec_quality_indicator, "
         "expected 45, is "
      << last_msg_->stec_sat_list[18].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].sv_id.constellation)),
            31)
      << "incorrect value for stec_sat_list[18].sv_id.constellation, expected "
         "31, is "
      << last_msg_->stec_sat_list[18].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[18].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[18].sv_id.satId)),
            50)
      << "incorrect value for stec_sat_list[18].sv_id.satId, expected 50, is "
      << last_msg_->stec_sat_list[18].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].stec_coeff[0])),
            -13968)
      << "incorrect value for stec_sat_list[19].stec_coeff[0], expected "
         "-13968, is "
      << last_msg_->stec_sat_list[19].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].stec_coeff[1])),
            -29322)
      << "incorrect value for stec_sat_list[19].stec_coeff[1], expected "
         "-29322, is "
      << last_msg_->stec_sat_list[19].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].stec_coeff[2])),
            -23790)
      << "incorrect value for stec_sat_list[19].stec_coeff[2], expected "
         "-23790, is "
      << last_msg_->stec_sat_list[19].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].stec_coeff[3])),
            9063)
      << "incorrect value for stec_sat_list[19].stec_coeff[3], expected 9063, "
         "is "
      << last_msg_->stec_sat_list[19].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[19].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[19].stec_quality_indicator)),
      238)
      << "incorrect value for stec_sat_list[19].stec_quality_indicator, "
         "expected 238, is "
      << last_msg_->stec_sat_list[19].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].sv_id.constellation)),
            188)
      << "incorrect value for stec_sat_list[19].sv_id.constellation, expected "
         "188, is "
      << last_msg_->stec_sat_list[19].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[19].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[19].sv_id.satId)),
            237)
      << "incorrect value for stec_sat_list[19].sv_id.satId, expected 237, is "
      << last_msg_->stec_sat_list[19].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].stec_coeff[0])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].stec_coeff[0])),
            4737)
      << "incorrect value for stec_sat_list[20].stec_coeff[0], expected 4737, "
         "is "
      << last_msg_->stec_sat_list[20].stec_coeff[0];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].stec_coeff[1])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].stec_coeff[1])),
            21877)
      << "incorrect value for stec_sat_list[20].stec_coeff[1], expected 21877, "
         "is "
      << last_msg_->stec_sat_list[20].stec_coeff[1];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].stec_coeff[2])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].stec_coeff[2])),
            20414)
      << "incorrect value for stec_sat_list[20].stec_coeff[2], expected 20414, "
         "is "
      << last_msg_->stec_sat_list[20].stec_coeff[2];
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].stec_coeff[3])>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].stec_coeff[3])),
            -10286)
      << "incorrect value for stec_sat_list[20].stec_coeff[3], expected "
         "-10286, is "
      << last_msg_->stec_sat_list[20].stec_coeff[3];
  EXPECT_EQ(
      get_as<decltype(last_msg_->stec_sat_list[20].stec_quality_indicator)>(
          reinterpret_cast<const uint8_t *>(
              &last_msg_->stec_sat_list[20].stec_quality_indicator)),
      82)
      << "incorrect value for stec_sat_list[20].stec_quality_indicator, "
         "expected 82, is "
      << last_msg_->stec_sat_list[20].stec_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].sv_id.constellation)),
            21)
      << "incorrect value for stec_sat_list[20].sv_id.constellation, expected "
         "21, is "
      << last_msg_->stec_sat_list[20].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_sat_list[20].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_sat_list[20].sv_id.satId)),
            63)
      << "incorrect value for stec_sat_list[20].sv_id.satId, expected 63, is "
      << last_msg_->stec_sat_list[20].sv_id.satId;
}
