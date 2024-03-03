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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionDepA.yaml by
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
class Test_legacy_auto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_gridded_correction_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_gridded_correction_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ssr_gridded_correction_dep_a_t *>(
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
                      const msg_ssr_gridded_correction_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_gridded_correction_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  250, 5,   108, 106, 254, 164, 217, 44,  53,  98,  93,  63,  147, 104,
      252, 133, 245, 28,  95,  100, 147, 41,  33,  92,  87,  25,  142, 151, 74,
      151, 95,  94,  7,   146, 237, 45,  167, 86,  42,  116, 224, 169, 234, 220,
      23,  176, 18,  13,  178, 79,  160, 160, 110, 15,  53,  206, 151, 158, 22,
      117, 184, 48,  170, 82,  40,  53,  122, 69,  180, 110, 38,  65,  104, 244,
      19,  238, 227, 88,  169, 164, 146, 63,  37,  183, 85,  71,  235, 168, 114,
      211, 105, 221, 156, 60,  18,  230, 2,   142, 172, 16,  39,  33,  126, 106,
      99,  188, 234, 41,  162, 197, 138, 227, 80,  12,  54,  67,  238, 5,   93,
      1,   207, 129, 13,  46,  115, 49,  58,  185, 127, 156, 200, 96,  217, 202,
      15,  245, 55,  198, 81,  218, 132, 70,  73,  82,  147, 26,  255, 14,  134,
      96,  138, 55,  214, 83,  156, 170, 163, 79,  173, 228, 115, 51,  241, 107,
      245, 112, 168, 210, 10,  5,   117, 1,   57,  108, 248, 212, 145, 119, 226,
      165, 5,   141, 202, 106, 0,   60,  36,  61,  243, 203, 216, 215, 12,  137,
      16,  28,  247, 115, 152, 181, 119, 208, 228, 203, 236, 34,  167, 196, 32,
      109, 1,   17,  101, 200, 25,  94,  125, 168, 137, 157, 4,   164, 29,  31,
      48,  132, 72,  229, 126, 186, 68,  76,  133, 21,  0,   180, 139, 164, 148,
      119, 149, 214, 120, 177, 201, 80,  80,  105, 10,  136, 118, 77,  46,  233,
      233, 227, 11,  158, 103, 167, 216,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_gridded_correction_dep_a_t *test_msg =
      (msg_ssr_gridded_correction_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->header.iod_atmo = 245;
  test_msg->header.num_msgs = 37695;
  test_msg->header.seq_num = 64616;
  test_msg->header.time.tow = 892131748;
  test_msg->header.time.wn = 23906;
  test_msg->header.tropo_quality_indicator = 28;
  test_msg->header.update_interval = 133;
  test_msg->index = 25695;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[0].residual = -26738;
  test_msg->stec_residuals[0].stddev = 74;
  test_msg->stec_residuals[0].sv_id.constellation = 25;
  test_msg->stec_residuals[0].sv_id.satId = 87;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[1].residual = 1886;
  test_msg->stec_residuals[1].stddev = 146;
  test_msg->stec_residuals[1].sv_id.constellation = 95;
  test_msg->stec_residuals[1].sv_id.satId = 151;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[2].residual = 22183;
  test_msg->stec_residuals[2].stddev = 42;
  test_msg->stec_residuals[2].sv_id.constellation = 45;
  test_msg->stec_residuals[2].sv_id.satId = 237;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[3].residual = -5463;
  test_msg->stec_residuals[3].stddev = 220;
  test_msg->stec_residuals[3].sv_id.constellation = 224;
  test_msg->stec_residuals[3].sv_id.satId = 116;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[4].residual = 3346;
  test_msg->stec_residuals[4].stddev = 178;
  test_msg->stec_residuals[4].sv_id.constellation = 176;
  test_msg->stec_residuals[4].sv_id.satId = 23;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[5].residual = 28320;
  test_msg->stec_residuals[5].stddev = 15;
  test_msg->stec_residuals[5].sv_id.constellation = 160;
  test_msg->stec_residuals[5].sv_id.satId = 79;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[6].residual = -24937;
  test_msg->stec_residuals[6].stddev = 22;
  test_msg->stec_residuals[6].sv_id.constellation = 206;
  test_msg->stec_residuals[6].sv_id.satId = 53;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[7].residual = -21968;
  test_msg->stec_residuals[7].stddev = 82;
  test_msg->stec_residuals[7].sv_id.constellation = 184;
  test_msg->stec_residuals[7].sv_id.satId = 117;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[8].residual = 17786;
  test_msg->stec_residuals[8].stddev = 180;
  test_msg->stec_residuals[8].sv_id.constellation = 53;
  test_msg->stec_residuals[8].sv_id.satId = 40;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[9].residual = 26689;
  test_msg->stec_residuals[9].stddev = 244;
  test_msg->stec_residuals[9].sv_id.constellation = 38;
  test_msg->stec_residuals[9].sv_id.satId = 110;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[10].residual = 22755;
  test_msg->stec_residuals[10].stddev = 169;
  test_msg->stec_residuals[10].sv_id.constellation = 238;
  test_msg->stec_residuals[10].sv_id.satId = 19;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[11].residual = 9535;
  test_msg->stec_residuals[11].stddev = 183;
  test_msg->stec_residuals[11].sv_id.constellation = 146;
  test_msg->stec_residuals[11].sv_id.satId = 164;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[12].residual = -22293;
  test_msg->stec_residuals[12].stddev = 114;
  test_msg->stec_residuals[12].sv_id.constellation = 71;
  test_msg->stec_residuals[12].sv_id.satId = 85;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[13].residual = -25379;
  test_msg->stec_residuals[13].stddev = 60;
  test_msg->stec_residuals[13].sv_id.constellation = 105;
  test_msg->stec_residuals[13].sv_id.satId = 211;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[14].residual = -29182;
  test_msg->stec_residuals[14].stddev = 172;
  test_msg->stec_residuals[14].sv_id.constellation = 230;
  test_msg->stec_residuals[14].sv_id.satId = 18;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[15].residual = 32289;
  test_msg->stec_residuals[15].stddev = 106;
  test_msg->stec_residuals[15].sv_id.constellation = 39;
  test_msg->stec_residuals[15].sv_id.satId = 16;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[16].residual = 10730;
  test_msg->stec_residuals[16].stddev = 162;
  test_msg->stec_residuals[16].sv_id.constellation = 188;
  test_msg->stec_residuals[16].sv_id.satId = 99;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[17].residual = 20707;
  test_msg->stec_residuals[17].stddev = 12;
  test_msg->stec_residuals[17].sv_id.constellation = 138;
  test_msg->stec_residuals[17].sv_id.satId = 197;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[18].residual = 1518;
  test_msg->stec_residuals[18].stddev = 93;
  test_msg->stec_residuals[18].sv_id.constellation = 67;
  test_msg->stec_residuals[18].sv_id.satId = 54;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[19].residual = 3457;
  test_msg->stec_residuals[19].stddev = 46;
  test_msg->stec_residuals[19].sv_id.constellation = 207;
  test_msg->stec_residuals[19].sv_id.satId = 1;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[20].residual = -18118;
  test_msg->stec_residuals[20].stddev = 127;
  test_msg->stec_residuals[20].sv_id.constellation = 49;
  test_msg->stec_residuals[20].sv_id.satId = 115;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[21].residual = -9888;
  test_msg->stec_residuals[21].stddev = 202;
  test_msg->stec_residuals[21].sv_id.constellation = 200;
  test_msg->stec_residuals[21].sv_id.satId = 156;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[22].residual = -14793;
  test_msg->stec_residuals[22].stddev = 81;
  test_msg->stec_residuals[22].sv_id.constellation = 245;
  test_msg->stec_residuals[22].sv_id.satId = 15;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[23].residual = 18758;
  test_msg->stec_residuals[23].stddev = 82;
  test_msg->stec_residuals[23].sv_id.constellation = 132;
  test_msg->stec_residuals[23].sv_id.satId = 218;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[24].residual = 3839;
  test_msg->stec_residuals[24].stddev = 134;
  test_msg->stec_residuals[24].sv_id.constellation = 26;
  test_msg->stec_residuals[24].sv_id.satId = 147;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[25].residual = -10697;
  test_msg->stec_residuals[25].stddev = 83;
  test_msg->stec_residuals[25].sv_id.constellation = 138;
  test_msg->stec_residuals[25].sv_id.satId = 96;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[26].residual = 20387;
  test_msg->stec_residuals[26].stddev = 173;
  test_msg->stec_residuals[26].sv_id.constellation = 170;
  test_msg->stec_residuals[26].sv_id.satId = 156;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[27].residual = -3789;
  test_msg->stec_residuals[27].stddev = 107;
  test_msg->stec_residuals[27].sv_id.constellation = 115;
  test_msg->stec_residuals[27].sv_id.satId = 228;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[28].residual = -11608;
  test_msg->stec_residuals[28].stddev = 10;
  test_msg->stec_residuals[28].sv_id.constellation = 112;
  test_msg->stec_residuals[28].sv_id.satId = 245;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[29].residual = 14593;
  test_msg->stec_residuals[29].stddev = 108;
  test_msg->stec_residuals[29].sv_id.constellation = 117;
  test_msg->stec_residuals[29].sv_id.satId = 5;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[30].residual = 30609;
  test_msg->stec_residuals[30].stddev = 226;
  test_msg->stec_residuals[30].sv_id.constellation = 212;
  test_msg->stec_residuals[30].sv_id.satId = 248;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[31].residual = -13683;
  test_msg->stec_residuals[31].stddev = 106;
  test_msg->stec_residuals[31].sv_id.constellation = 5;
  test_msg->stec_residuals[31].sv_id.satId = 165;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[32].residual = 15652;
  test_msg->stec_residuals[32].stddev = 243;
  test_msg->stec_residuals[32].sv_id.constellation = 60;
  test_msg->stec_residuals[32].sv_id.satId = 0;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[33].residual = 3287;
  test_msg->stec_residuals[33].stddev = 137;
  test_msg->stec_residuals[33].sv_id.constellation = 216;
  test_msg->stec_residuals[33].sv_id.satId = 203;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[34].residual = 29687;
  test_msg->stec_residuals[34].stddev = 152;
  test_msg->stec_residuals[34].sv_id.constellation = 28;
  test_msg->stec_residuals[34].sv_id.satId = 16;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[35].residual = -6960;
  test_msg->stec_residuals[35].stddev = 203;
  test_msg->stec_residuals[35].sv_id.constellation = 119;
  test_msg->stec_residuals[35].sv_id.satId = 181;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[36].residual = -15193;
  test_msg->stec_residuals[36].stddev = 32;
  test_msg->stec_residuals[36].sv_id.constellation = 34;
  test_msg->stec_residuals[36].sv_id.satId = 236;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[37].residual = 25873;
  test_msg->stec_residuals[37].stddev = 200;
  test_msg->stec_residuals[37].sv_id.constellation = 1;
  test_msg->stec_residuals[37].sv_id.satId = 109;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[38].residual = -22403;
  test_msg->stec_residuals[38].stddev = 137;
  test_msg->stec_residuals[38].sv_id.constellation = 94;
  test_msg->stec_residuals[38].sv_id.satId = 25;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[39].residual = 7588;
  test_msg->stec_residuals[39].stddev = 31;
  test_msg->stec_residuals[39].sv_id.constellation = 4;
  test_msg->stec_residuals[39].sv_id.satId = 157;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[40].residual = -6840;
  test_msg->stec_residuals[40].stddev = 126;
  test_msg->stec_residuals[40].sv_id.constellation = 132;
  test_msg->stec_residuals[40].sv_id.satId = 48;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[41].residual = -31412;
  test_msg->stec_residuals[41].stddev = 21;
  test_msg->stec_residuals[41].sv_id.constellation = 68;
  test_msg->stec_residuals[41].sv_id.satId = 186;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[42].residual = -23413;
  test_msg->stec_residuals[42].stddev = 148;
  test_msg->stec_residuals[42].sv_id.constellation = 180;
  test_msg->stec_residuals[42].sv_id.satId = 0;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[43].residual = 30934;
  test_msg->stec_residuals[43].stddev = 177;
  test_msg->stec_residuals[43].sv_id.constellation = 149;
  test_msg->stec_residuals[43].sv_id.satId = 119;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[44].residual = 26960;
  test_msg->stec_residuals[44].stddev = 10;
  test_msg->stec_residuals[44].sv_id.constellation = 80;
  test_msg->stec_residuals[44].sv_id.satId = 201;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[45].residual = 11853;
  test_msg->stec_residuals[45].stddev = 233;
  test_msg->stec_residuals[45].sv_id.constellation = 118;
  test_msg->stec_residuals[45].sv_id.satId = 136;
  if (sizeof(test_msg->stec_residuals) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->stec_residuals[0]));
  }
  test_msg->stec_residuals[46].residual = -25077;
  test_msg->stec_residuals[46].stddev = 103;
  test_msg->stec_residuals[46].sv_id.constellation = 227;
  test_msg->stec_residuals[46].sv_id.satId = 233;
  test_msg->tropo_delay_correction.hydro = 10643;
  test_msg->tropo_delay_correction.stddev = 92;
  test_msg->tropo_delay_correction.wet = 33;

  EXPECT_EQ(send_message(0x5fa, 27244, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 27244);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->header.iod_atmo)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.iod_atmo)),
            245)
      << "incorrect value for header.iod_atmo, expected 245, is "
      << last_msg_->header.iod_atmo;
  EXPECT_EQ(get_as<decltype(last_msg_->header.num_msgs)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.num_msgs)),
            37695)
      << "incorrect value for header.num_msgs, expected 37695, is "
      << last_msg_->header.num_msgs;
  EXPECT_EQ(get_as<decltype(last_msg_->header.seq_num)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.seq_num)),
            64616)
      << "incorrect value for header.seq_num, expected 64616, is "
      << last_msg_->header.seq_num;
  EXPECT_EQ(get_as<decltype(last_msg_->header.time.tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.time.tow)),
            892131748)
      << "incorrect value for header.time.tow, expected 892131748, is "
      << last_msg_->header.time.tow;
  EXPECT_EQ(get_as<decltype(last_msg_->header.time.wn)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->header.time.wn)),
            23906)
      << "incorrect value for header.time.wn, expected 23906, is "
      << last_msg_->header.time.wn;
  EXPECT_EQ(get_as<decltype(last_msg_->header.tropo_quality_indicator)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->header.tropo_quality_indicator)),
            28)
      << "incorrect value for header.tropo_quality_indicator, expected 28, is "
      << last_msg_->header.tropo_quality_indicator;
  EXPECT_EQ(get_as<decltype(last_msg_->header.update_interval)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->header.update_interval)),
            133)
      << "incorrect value for header.update_interval, expected 133, is "
      << last_msg_->header.update_interval;
  EXPECT_EQ(get_as<decltype(last_msg_->index)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->index)),
            25695)
      << "incorrect value for index, expected 25695, is " << last_msg_->index;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[0].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[0].residual)),
            -26738)
      << "incorrect value for stec_residuals[0].residual, expected -26738, is "
      << last_msg_->stec_residuals[0].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[0].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[0].stddev)),
            74)
      << "incorrect value for stec_residuals[0].stddev, expected 74, is "
      << last_msg_->stec_residuals[0].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[0].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[0].sv_id.constellation)),
            25)
      << "incorrect value for stec_residuals[0].sv_id.constellation, expected "
         "25, is "
      << last_msg_->stec_residuals[0].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[0].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[0].sv_id.satId)),
            87)
      << "incorrect value for stec_residuals[0].sv_id.satId, expected 87, is "
      << last_msg_->stec_residuals[0].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[1].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[1].residual)),
            1886)
      << "incorrect value for stec_residuals[1].residual, expected 1886, is "
      << last_msg_->stec_residuals[1].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[1].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[1].stddev)),
            146)
      << "incorrect value for stec_residuals[1].stddev, expected 146, is "
      << last_msg_->stec_residuals[1].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[1].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[1].sv_id.constellation)),
            95)
      << "incorrect value for stec_residuals[1].sv_id.constellation, expected "
         "95, is "
      << last_msg_->stec_residuals[1].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[1].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[1].sv_id.satId)),
            151)
      << "incorrect value for stec_residuals[1].sv_id.satId, expected 151, is "
      << last_msg_->stec_residuals[1].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[2].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[2].residual)),
            22183)
      << "incorrect value for stec_residuals[2].residual, expected 22183, is "
      << last_msg_->stec_residuals[2].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[2].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[2].stddev)),
            42)
      << "incorrect value for stec_residuals[2].stddev, expected 42, is "
      << last_msg_->stec_residuals[2].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[2].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[2].sv_id.constellation)),
            45)
      << "incorrect value for stec_residuals[2].sv_id.constellation, expected "
         "45, is "
      << last_msg_->stec_residuals[2].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[2].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[2].sv_id.satId)),
            237)
      << "incorrect value for stec_residuals[2].sv_id.satId, expected 237, is "
      << last_msg_->stec_residuals[2].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[3].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[3].residual)),
            -5463)
      << "incorrect value for stec_residuals[3].residual, expected -5463, is "
      << last_msg_->stec_residuals[3].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[3].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[3].stddev)),
            220)
      << "incorrect value for stec_residuals[3].stddev, expected 220, is "
      << last_msg_->stec_residuals[3].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[3].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[3].sv_id.constellation)),
            224)
      << "incorrect value for stec_residuals[3].sv_id.constellation, expected "
         "224, is "
      << last_msg_->stec_residuals[3].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[3].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[3].sv_id.satId)),
            116)
      << "incorrect value for stec_residuals[3].sv_id.satId, expected 116, is "
      << last_msg_->stec_residuals[3].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[4].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[4].residual)),
            3346)
      << "incorrect value for stec_residuals[4].residual, expected 3346, is "
      << last_msg_->stec_residuals[4].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[4].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[4].stddev)),
            178)
      << "incorrect value for stec_residuals[4].stddev, expected 178, is "
      << last_msg_->stec_residuals[4].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[4].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[4].sv_id.constellation)),
            176)
      << "incorrect value for stec_residuals[4].sv_id.constellation, expected "
         "176, is "
      << last_msg_->stec_residuals[4].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[4].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[4].sv_id.satId)),
            23)
      << "incorrect value for stec_residuals[4].sv_id.satId, expected 23, is "
      << last_msg_->stec_residuals[4].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[5].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[5].residual)),
            28320)
      << "incorrect value for stec_residuals[5].residual, expected 28320, is "
      << last_msg_->stec_residuals[5].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[5].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[5].stddev)),
            15)
      << "incorrect value for stec_residuals[5].stddev, expected 15, is "
      << last_msg_->stec_residuals[5].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[5].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[5].sv_id.constellation)),
            160)
      << "incorrect value for stec_residuals[5].sv_id.constellation, expected "
         "160, is "
      << last_msg_->stec_residuals[5].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[5].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[5].sv_id.satId)),
            79)
      << "incorrect value for stec_residuals[5].sv_id.satId, expected 79, is "
      << last_msg_->stec_residuals[5].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[6].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[6].residual)),
            -24937)
      << "incorrect value for stec_residuals[6].residual, expected -24937, is "
      << last_msg_->stec_residuals[6].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[6].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[6].stddev)),
            22)
      << "incorrect value for stec_residuals[6].stddev, expected 22, is "
      << last_msg_->stec_residuals[6].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[6].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[6].sv_id.constellation)),
            206)
      << "incorrect value for stec_residuals[6].sv_id.constellation, expected "
         "206, is "
      << last_msg_->stec_residuals[6].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[6].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[6].sv_id.satId)),
            53)
      << "incorrect value for stec_residuals[6].sv_id.satId, expected 53, is "
      << last_msg_->stec_residuals[6].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[7].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[7].residual)),
            -21968)
      << "incorrect value for stec_residuals[7].residual, expected -21968, is "
      << last_msg_->stec_residuals[7].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[7].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[7].stddev)),
            82)
      << "incorrect value for stec_residuals[7].stddev, expected 82, is "
      << last_msg_->stec_residuals[7].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[7].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[7].sv_id.constellation)),
            184)
      << "incorrect value for stec_residuals[7].sv_id.constellation, expected "
         "184, is "
      << last_msg_->stec_residuals[7].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[7].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[7].sv_id.satId)),
            117)
      << "incorrect value for stec_residuals[7].sv_id.satId, expected 117, is "
      << last_msg_->stec_residuals[7].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[8].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[8].residual)),
            17786)
      << "incorrect value for stec_residuals[8].residual, expected 17786, is "
      << last_msg_->stec_residuals[8].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[8].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[8].stddev)),
            180)
      << "incorrect value for stec_residuals[8].stddev, expected 180, is "
      << last_msg_->stec_residuals[8].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[8].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[8].sv_id.constellation)),
            53)
      << "incorrect value for stec_residuals[8].sv_id.constellation, expected "
         "53, is "
      << last_msg_->stec_residuals[8].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[8].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[8].sv_id.satId)),
            40)
      << "incorrect value for stec_residuals[8].sv_id.satId, expected 40, is "
      << last_msg_->stec_residuals[8].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[9].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[9].residual)),
            26689)
      << "incorrect value for stec_residuals[9].residual, expected 26689, is "
      << last_msg_->stec_residuals[9].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[9].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[9].stddev)),
            244)
      << "incorrect value for stec_residuals[9].stddev, expected 244, is "
      << last_msg_->stec_residuals[9].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[9].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[9].sv_id.constellation)),
            38)
      << "incorrect value for stec_residuals[9].sv_id.constellation, expected "
         "38, is "
      << last_msg_->stec_residuals[9].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[9].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[9].sv_id.satId)),
            110)
      << "incorrect value for stec_residuals[9].sv_id.satId, expected 110, is "
      << last_msg_->stec_residuals[9].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[10].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[10].residual)),
            22755)
      << "incorrect value for stec_residuals[10].residual, expected 22755, is "
      << last_msg_->stec_residuals[10].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[10].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[10].stddev)),
            169)
      << "incorrect value for stec_residuals[10].stddev, expected 169, is "
      << last_msg_->stec_residuals[10].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[10].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[10].sv_id.constellation)),
            238)
      << "incorrect value for stec_residuals[10].sv_id.constellation, expected "
         "238, is "
      << last_msg_->stec_residuals[10].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[10].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[10].sv_id.satId)),
            19)
      << "incorrect value for stec_residuals[10].sv_id.satId, expected 19, is "
      << last_msg_->stec_residuals[10].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[11].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[11].residual)),
            9535)
      << "incorrect value for stec_residuals[11].residual, expected 9535, is "
      << last_msg_->stec_residuals[11].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[11].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[11].stddev)),
            183)
      << "incorrect value for stec_residuals[11].stddev, expected 183, is "
      << last_msg_->stec_residuals[11].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[11].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[11].sv_id.constellation)),
            146)
      << "incorrect value for stec_residuals[11].sv_id.constellation, expected "
         "146, is "
      << last_msg_->stec_residuals[11].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[11].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[11].sv_id.satId)),
            164)
      << "incorrect value for stec_residuals[11].sv_id.satId, expected 164, is "
      << last_msg_->stec_residuals[11].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[12].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[12].residual)),
            -22293)
      << "incorrect value for stec_residuals[12].residual, expected -22293, is "
      << last_msg_->stec_residuals[12].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[12].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[12].stddev)),
            114)
      << "incorrect value for stec_residuals[12].stddev, expected 114, is "
      << last_msg_->stec_residuals[12].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[12].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[12].sv_id.constellation)),
            71)
      << "incorrect value for stec_residuals[12].sv_id.constellation, expected "
         "71, is "
      << last_msg_->stec_residuals[12].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[12].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[12].sv_id.satId)),
            85)
      << "incorrect value for stec_residuals[12].sv_id.satId, expected 85, is "
      << last_msg_->stec_residuals[12].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[13].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[13].residual)),
            -25379)
      << "incorrect value for stec_residuals[13].residual, expected -25379, is "
      << last_msg_->stec_residuals[13].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[13].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[13].stddev)),
            60)
      << "incorrect value for stec_residuals[13].stddev, expected 60, is "
      << last_msg_->stec_residuals[13].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[13].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[13].sv_id.constellation)),
            105)
      << "incorrect value for stec_residuals[13].sv_id.constellation, expected "
         "105, is "
      << last_msg_->stec_residuals[13].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[13].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[13].sv_id.satId)),
            211)
      << "incorrect value for stec_residuals[13].sv_id.satId, expected 211, is "
      << last_msg_->stec_residuals[13].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[14].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[14].residual)),
            -29182)
      << "incorrect value for stec_residuals[14].residual, expected -29182, is "
      << last_msg_->stec_residuals[14].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[14].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[14].stddev)),
            172)
      << "incorrect value for stec_residuals[14].stddev, expected 172, is "
      << last_msg_->stec_residuals[14].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[14].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[14].sv_id.constellation)),
            230)
      << "incorrect value for stec_residuals[14].sv_id.constellation, expected "
         "230, is "
      << last_msg_->stec_residuals[14].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[14].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[14].sv_id.satId)),
            18)
      << "incorrect value for stec_residuals[14].sv_id.satId, expected 18, is "
      << last_msg_->stec_residuals[14].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[15].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[15].residual)),
            32289)
      << "incorrect value for stec_residuals[15].residual, expected 32289, is "
      << last_msg_->stec_residuals[15].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[15].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[15].stddev)),
            106)
      << "incorrect value for stec_residuals[15].stddev, expected 106, is "
      << last_msg_->stec_residuals[15].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[15].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[15].sv_id.constellation)),
            39)
      << "incorrect value for stec_residuals[15].sv_id.constellation, expected "
         "39, is "
      << last_msg_->stec_residuals[15].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[15].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[15].sv_id.satId)),
            16)
      << "incorrect value for stec_residuals[15].sv_id.satId, expected 16, is "
      << last_msg_->stec_residuals[15].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[16].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[16].residual)),
            10730)
      << "incorrect value for stec_residuals[16].residual, expected 10730, is "
      << last_msg_->stec_residuals[16].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[16].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[16].stddev)),
            162)
      << "incorrect value for stec_residuals[16].stddev, expected 162, is "
      << last_msg_->stec_residuals[16].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[16].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[16].sv_id.constellation)),
            188)
      << "incorrect value for stec_residuals[16].sv_id.constellation, expected "
         "188, is "
      << last_msg_->stec_residuals[16].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[16].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[16].sv_id.satId)),
            99)
      << "incorrect value for stec_residuals[16].sv_id.satId, expected 99, is "
      << last_msg_->stec_residuals[16].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[17].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[17].residual)),
            20707)
      << "incorrect value for stec_residuals[17].residual, expected 20707, is "
      << last_msg_->stec_residuals[17].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[17].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[17].stddev)),
            12)
      << "incorrect value for stec_residuals[17].stddev, expected 12, is "
      << last_msg_->stec_residuals[17].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[17].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[17].sv_id.constellation)),
            138)
      << "incorrect value for stec_residuals[17].sv_id.constellation, expected "
         "138, is "
      << last_msg_->stec_residuals[17].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[17].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[17].sv_id.satId)),
            197)
      << "incorrect value for stec_residuals[17].sv_id.satId, expected 197, is "
      << last_msg_->stec_residuals[17].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[18].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[18].residual)),
            1518)
      << "incorrect value for stec_residuals[18].residual, expected 1518, is "
      << last_msg_->stec_residuals[18].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[18].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[18].stddev)),
            93)
      << "incorrect value for stec_residuals[18].stddev, expected 93, is "
      << last_msg_->stec_residuals[18].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[18].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[18].sv_id.constellation)),
            67)
      << "incorrect value for stec_residuals[18].sv_id.constellation, expected "
         "67, is "
      << last_msg_->stec_residuals[18].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[18].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[18].sv_id.satId)),
            54)
      << "incorrect value for stec_residuals[18].sv_id.satId, expected 54, is "
      << last_msg_->stec_residuals[18].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[19].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[19].residual)),
            3457)
      << "incorrect value for stec_residuals[19].residual, expected 3457, is "
      << last_msg_->stec_residuals[19].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[19].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[19].stddev)),
            46)
      << "incorrect value for stec_residuals[19].stddev, expected 46, is "
      << last_msg_->stec_residuals[19].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[19].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[19].sv_id.constellation)),
            207)
      << "incorrect value for stec_residuals[19].sv_id.constellation, expected "
         "207, is "
      << last_msg_->stec_residuals[19].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[19].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[19].sv_id.satId)),
            1)
      << "incorrect value for stec_residuals[19].sv_id.satId, expected 1, is "
      << last_msg_->stec_residuals[19].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[20].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[20].residual)),
            -18118)
      << "incorrect value for stec_residuals[20].residual, expected -18118, is "
      << last_msg_->stec_residuals[20].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[20].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[20].stddev)),
            127)
      << "incorrect value for stec_residuals[20].stddev, expected 127, is "
      << last_msg_->stec_residuals[20].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[20].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[20].sv_id.constellation)),
            49)
      << "incorrect value for stec_residuals[20].sv_id.constellation, expected "
         "49, is "
      << last_msg_->stec_residuals[20].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[20].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[20].sv_id.satId)),
            115)
      << "incorrect value for stec_residuals[20].sv_id.satId, expected 115, is "
      << last_msg_->stec_residuals[20].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[21].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[21].residual)),
            -9888)
      << "incorrect value for stec_residuals[21].residual, expected -9888, is "
      << last_msg_->stec_residuals[21].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[21].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[21].stddev)),
            202)
      << "incorrect value for stec_residuals[21].stddev, expected 202, is "
      << last_msg_->stec_residuals[21].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[21].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[21].sv_id.constellation)),
            200)
      << "incorrect value for stec_residuals[21].sv_id.constellation, expected "
         "200, is "
      << last_msg_->stec_residuals[21].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[21].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[21].sv_id.satId)),
            156)
      << "incorrect value for stec_residuals[21].sv_id.satId, expected 156, is "
      << last_msg_->stec_residuals[21].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[22].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[22].residual)),
            -14793)
      << "incorrect value for stec_residuals[22].residual, expected -14793, is "
      << last_msg_->stec_residuals[22].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[22].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[22].stddev)),
            81)
      << "incorrect value for stec_residuals[22].stddev, expected 81, is "
      << last_msg_->stec_residuals[22].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[22].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[22].sv_id.constellation)),
            245)
      << "incorrect value for stec_residuals[22].sv_id.constellation, expected "
         "245, is "
      << last_msg_->stec_residuals[22].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[22].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[22].sv_id.satId)),
            15)
      << "incorrect value for stec_residuals[22].sv_id.satId, expected 15, is "
      << last_msg_->stec_residuals[22].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[23].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[23].residual)),
            18758)
      << "incorrect value for stec_residuals[23].residual, expected 18758, is "
      << last_msg_->stec_residuals[23].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[23].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[23].stddev)),
            82)
      << "incorrect value for stec_residuals[23].stddev, expected 82, is "
      << last_msg_->stec_residuals[23].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[23].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[23].sv_id.constellation)),
            132)
      << "incorrect value for stec_residuals[23].sv_id.constellation, expected "
         "132, is "
      << last_msg_->stec_residuals[23].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[23].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[23].sv_id.satId)),
            218)
      << "incorrect value for stec_residuals[23].sv_id.satId, expected 218, is "
      << last_msg_->stec_residuals[23].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[24].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[24].residual)),
            3839)
      << "incorrect value for stec_residuals[24].residual, expected 3839, is "
      << last_msg_->stec_residuals[24].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[24].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[24].stddev)),
            134)
      << "incorrect value for stec_residuals[24].stddev, expected 134, is "
      << last_msg_->stec_residuals[24].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[24].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[24].sv_id.constellation)),
            26)
      << "incorrect value for stec_residuals[24].sv_id.constellation, expected "
         "26, is "
      << last_msg_->stec_residuals[24].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[24].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[24].sv_id.satId)),
            147)
      << "incorrect value for stec_residuals[24].sv_id.satId, expected 147, is "
      << last_msg_->stec_residuals[24].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[25].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[25].residual)),
            -10697)
      << "incorrect value for stec_residuals[25].residual, expected -10697, is "
      << last_msg_->stec_residuals[25].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[25].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[25].stddev)),
            83)
      << "incorrect value for stec_residuals[25].stddev, expected 83, is "
      << last_msg_->stec_residuals[25].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[25].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[25].sv_id.constellation)),
            138)
      << "incorrect value for stec_residuals[25].sv_id.constellation, expected "
         "138, is "
      << last_msg_->stec_residuals[25].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[25].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[25].sv_id.satId)),
            96)
      << "incorrect value for stec_residuals[25].sv_id.satId, expected 96, is "
      << last_msg_->stec_residuals[25].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[26].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[26].residual)),
            20387)
      << "incorrect value for stec_residuals[26].residual, expected 20387, is "
      << last_msg_->stec_residuals[26].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[26].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[26].stddev)),
            173)
      << "incorrect value for stec_residuals[26].stddev, expected 173, is "
      << last_msg_->stec_residuals[26].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[26].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[26].sv_id.constellation)),
            170)
      << "incorrect value for stec_residuals[26].sv_id.constellation, expected "
         "170, is "
      << last_msg_->stec_residuals[26].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[26].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[26].sv_id.satId)),
            156)
      << "incorrect value for stec_residuals[26].sv_id.satId, expected 156, is "
      << last_msg_->stec_residuals[26].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[27].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[27].residual)),
            -3789)
      << "incorrect value for stec_residuals[27].residual, expected -3789, is "
      << last_msg_->stec_residuals[27].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[27].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[27].stddev)),
            107)
      << "incorrect value for stec_residuals[27].stddev, expected 107, is "
      << last_msg_->stec_residuals[27].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[27].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[27].sv_id.constellation)),
            115)
      << "incorrect value for stec_residuals[27].sv_id.constellation, expected "
         "115, is "
      << last_msg_->stec_residuals[27].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[27].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[27].sv_id.satId)),
            228)
      << "incorrect value for stec_residuals[27].sv_id.satId, expected 228, is "
      << last_msg_->stec_residuals[27].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[28].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[28].residual)),
            -11608)
      << "incorrect value for stec_residuals[28].residual, expected -11608, is "
      << last_msg_->stec_residuals[28].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[28].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[28].stddev)),
            10)
      << "incorrect value for stec_residuals[28].stddev, expected 10, is "
      << last_msg_->stec_residuals[28].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[28].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[28].sv_id.constellation)),
            112)
      << "incorrect value for stec_residuals[28].sv_id.constellation, expected "
         "112, is "
      << last_msg_->stec_residuals[28].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[28].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[28].sv_id.satId)),
            245)
      << "incorrect value for stec_residuals[28].sv_id.satId, expected 245, is "
      << last_msg_->stec_residuals[28].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[29].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[29].residual)),
            14593)
      << "incorrect value for stec_residuals[29].residual, expected 14593, is "
      << last_msg_->stec_residuals[29].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[29].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[29].stddev)),
            108)
      << "incorrect value for stec_residuals[29].stddev, expected 108, is "
      << last_msg_->stec_residuals[29].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[29].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[29].sv_id.constellation)),
            117)
      << "incorrect value for stec_residuals[29].sv_id.constellation, expected "
         "117, is "
      << last_msg_->stec_residuals[29].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[29].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[29].sv_id.satId)),
            5)
      << "incorrect value for stec_residuals[29].sv_id.satId, expected 5, is "
      << last_msg_->stec_residuals[29].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[30].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[30].residual)),
            30609)
      << "incorrect value for stec_residuals[30].residual, expected 30609, is "
      << last_msg_->stec_residuals[30].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[30].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[30].stddev)),
            226)
      << "incorrect value for stec_residuals[30].stddev, expected 226, is "
      << last_msg_->stec_residuals[30].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[30].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[30].sv_id.constellation)),
            212)
      << "incorrect value for stec_residuals[30].sv_id.constellation, expected "
         "212, is "
      << last_msg_->stec_residuals[30].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[30].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[30].sv_id.satId)),
            248)
      << "incorrect value for stec_residuals[30].sv_id.satId, expected 248, is "
      << last_msg_->stec_residuals[30].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[31].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[31].residual)),
            -13683)
      << "incorrect value for stec_residuals[31].residual, expected -13683, is "
      << last_msg_->stec_residuals[31].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[31].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[31].stddev)),
            106)
      << "incorrect value for stec_residuals[31].stddev, expected 106, is "
      << last_msg_->stec_residuals[31].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[31].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[31].sv_id.constellation)),
            5)
      << "incorrect value for stec_residuals[31].sv_id.constellation, expected "
         "5, is "
      << last_msg_->stec_residuals[31].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[31].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[31].sv_id.satId)),
            165)
      << "incorrect value for stec_residuals[31].sv_id.satId, expected 165, is "
      << last_msg_->stec_residuals[31].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[32].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[32].residual)),
            15652)
      << "incorrect value for stec_residuals[32].residual, expected 15652, is "
      << last_msg_->stec_residuals[32].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[32].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[32].stddev)),
            243)
      << "incorrect value for stec_residuals[32].stddev, expected 243, is "
      << last_msg_->stec_residuals[32].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[32].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[32].sv_id.constellation)),
            60)
      << "incorrect value for stec_residuals[32].sv_id.constellation, expected "
         "60, is "
      << last_msg_->stec_residuals[32].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[32].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[32].sv_id.satId)),
            0)
      << "incorrect value for stec_residuals[32].sv_id.satId, expected 0, is "
      << last_msg_->stec_residuals[32].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[33].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[33].residual)),
            3287)
      << "incorrect value for stec_residuals[33].residual, expected 3287, is "
      << last_msg_->stec_residuals[33].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[33].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[33].stddev)),
            137)
      << "incorrect value for stec_residuals[33].stddev, expected 137, is "
      << last_msg_->stec_residuals[33].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[33].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[33].sv_id.constellation)),
            216)
      << "incorrect value for stec_residuals[33].sv_id.constellation, expected "
         "216, is "
      << last_msg_->stec_residuals[33].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[33].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[33].sv_id.satId)),
            203)
      << "incorrect value for stec_residuals[33].sv_id.satId, expected 203, is "
      << last_msg_->stec_residuals[33].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[34].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[34].residual)),
            29687)
      << "incorrect value for stec_residuals[34].residual, expected 29687, is "
      << last_msg_->stec_residuals[34].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[34].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[34].stddev)),
            152)
      << "incorrect value for stec_residuals[34].stddev, expected 152, is "
      << last_msg_->stec_residuals[34].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[34].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[34].sv_id.constellation)),
            28)
      << "incorrect value for stec_residuals[34].sv_id.constellation, expected "
         "28, is "
      << last_msg_->stec_residuals[34].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[34].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[34].sv_id.satId)),
            16)
      << "incorrect value for stec_residuals[34].sv_id.satId, expected 16, is "
      << last_msg_->stec_residuals[34].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[35].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[35].residual)),
            -6960)
      << "incorrect value for stec_residuals[35].residual, expected -6960, is "
      << last_msg_->stec_residuals[35].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[35].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[35].stddev)),
            203)
      << "incorrect value for stec_residuals[35].stddev, expected 203, is "
      << last_msg_->stec_residuals[35].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[35].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[35].sv_id.constellation)),
            119)
      << "incorrect value for stec_residuals[35].sv_id.constellation, expected "
         "119, is "
      << last_msg_->stec_residuals[35].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[35].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[35].sv_id.satId)),
            181)
      << "incorrect value for stec_residuals[35].sv_id.satId, expected 181, is "
      << last_msg_->stec_residuals[35].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[36].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[36].residual)),
            -15193)
      << "incorrect value for stec_residuals[36].residual, expected -15193, is "
      << last_msg_->stec_residuals[36].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[36].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[36].stddev)),
            32)
      << "incorrect value for stec_residuals[36].stddev, expected 32, is "
      << last_msg_->stec_residuals[36].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[36].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[36].sv_id.constellation)),
            34)
      << "incorrect value for stec_residuals[36].sv_id.constellation, expected "
         "34, is "
      << last_msg_->stec_residuals[36].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[36].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[36].sv_id.satId)),
            236)
      << "incorrect value for stec_residuals[36].sv_id.satId, expected 236, is "
      << last_msg_->stec_residuals[36].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[37].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[37].residual)),
            25873)
      << "incorrect value for stec_residuals[37].residual, expected 25873, is "
      << last_msg_->stec_residuals[37].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[37].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[37].stddev)),
            200)
      << "incorrect value for stec_residuals[37].stddev, expected 200, is "
      << last_msg_->stec_residuals[37].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[37].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[37].sv_id.constellation)),
            1)
      << "incorrect value for stec_residuals[37].sv_id.constellation, expected "
         "1, is "
      << last_msg_->stec_residuals[37].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[37].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[37].sv_id.satId)),
            109)
      << "incorrect value for stec_residuals[37].sv_id.satId, expected 109, is "
      << last_msg_->stec_residuals[37].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[38].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[38].residual)),
            -22403)
      << "incorrect value for stec_residuals[38].residual, expected -22403, is "
      << last_msg_->stec_residuals[38].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[38].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[38].stddev)),
            137)
      << "incorrect value for stec_residuals[38].stddev, expected 137, is "
      << last_msg_->stec_residuals[38].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[38].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[38].sv_id.constellation)),
            94)
      << "incorrect value for stec_residuals[38].sv_id.constellation, expected "
         "94, is "
      << last_msg_->stec_residuals[38].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[38].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[38].sv_id.satId)),
            25)
      << "incorrect value for stec_residuals[38].sv_id.satId, expected 25, is "
      << last_msg_->stec_residuals[38].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[39].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[39].residual)),
            7588)
      << "incorrect value for stec_residuals[39].residual, expected 7588, is "
      << last_msg_->stec_residuals[39].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[39].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[39].stddev)),
            31)
      << "incorrect value for stec_residuals[39].stddev, expected 31, is "
      << last_msg_->stec_residuals[39].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[39].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[39].sv_id.constellation)),
            4)
      << "incorrect value for stec_residuals[39].sv_id.constellation, expected "
         "4, is "
      << last_msg_->stec_residuals[39].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[39].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[39].sv_id.satId)),
            157)
      << "incorrect value for stec_residuals[39].sv_id.satId, expected 157, is "
      << last_msg_->stec_residuals[39].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[40].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[40].residual)),
            -6840)
      << "incorrect value for stec_residuals[40].residual, expected -6840, is "
      << last_msg_->stec_residuals[40].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[40].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[40].stddev)),
            126)
      << "incorrect value for stec_residuals[40].stddev, expected 126, is "
      << last_msg_->stec_residuals[40].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[40].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[40].sv_id.constellation)),
            132)
      << "incorrect value for stec_residuals[40].sv_id.constellation, expected "
         "132, is "
      << last_msg_->stec_residuals[40].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[40].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[40].sv_id.satId)),
            48)
      << "incorrect value for stec_residuals[40].sv_id.satId, expected 48, is "
      << last_msg_->stec_residuals[40].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[41].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[41].residual)),
            -31412)
      << "incorrect value for stec_residuals[41].residual, expected -31412, is "
      << last_msg_->stec_residuals[41].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[41].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[41].stddev)),
            21)
      << "incorrect value for stec_residuals[41].stddev, expected 21, is "
      << last_msg_->stec_residuals[41].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[41].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[41].sv_id.constellation)),
            68)
      << "incorrect value for stec_residuals[41].sv_id.constellation, expected "
         "68, is "
      << last_msg_->stec_residuals[41].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[41].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[41].sv_id.satId)),
            186)
      << "incorrect value for stec_residuals[41].sv_id.satId, expected 186, is "
      << last_msg_->stec_residuals[41].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[42].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[42].residual)),
            -23413)
      << "incorrect value for stec_residuals[42].residual, expected -23413, is "
      << last_msg_->stec_residuals[42].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[42].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[42].stddev)),
            148)
      << "incorrect value for stec_residuals[42].stddev, expected 148, is "
      << last_msg_->stec_residuals[42].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[42].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[42].sv_id.constellation)),
            180)
      << "incorrect value for stec_residuals[42].sv_id.constellation, expected "
         "180, is "
      << last_msg_->stec_residuals[42].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[42].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[42].sv_id.satId)),
            0)
      << "incorrect value for stec_residuals[42].sv_id.satId, expected 0, is "
      << last_msg_->stec_residuals[42].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[43].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[43].residual)),
            30934)
      << "incorrect value for stec_residuals[43].residual, expected 30934, is "
      << last_msg_->stec_residuals[43].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[43].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[43].stddev)),
            177)
      << "incorrect value for stec_residuals[43].stddev, expected 177, is "
      << last_msg_->stec_residuals[43].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[43].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[43].sv_id.constellation)),
            149)
      << "incorrect value for stec_residuals[43].sv_id.constellation, expected "
         "149, is "
      << last_msg_->stec_residuals[43].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[43].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[43].sv_id.satId)),
            119)
      << "incorrect value for stec_residuals[43].sv_id.satId, expected 119, is "
      << last_msg_->stec_residuals[43].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[44].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[44].residual)),
            26960)
      << "incorrect value for stec_residuals[44].residual, expected 26960, is "
      << last_msg_->stec_residuals[44].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[44].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[44].stddev)),
            10)
      << "incorrect value for stec_residuals[44].stddev, expected 10, is "
      << last_msg_->stec_residuals[44].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[44].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[44].sv_id.constellation)),
            80)
      << "incorrect value for stec_residuals[44].sv_id.constellation, expected "
         "80, is "
      << last_msg_->stec_residuals[44].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[44].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[44].sv_id.satId)),
            201)
      << "incorrect value for stec_residuals[44].sv_id.satId, expected 201, is "
      << last_msg_->stec_residuals[44].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[45].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[45].residual)),
            11853)
      << "incorrect value for stec_residuals[45].residual, expected 11853, is "
      << last_msg_->stec_residuals[45].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[45].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[45].stddev)),
            233)
      << "incorrect value for stec_residuals[45].stddev, expected 233, is "
      << last_msg_->stec_residuals[45].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[45].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[45].sv_id.constellation)),
            118)
      << "incorrect value for stec_residuals[45].sv_id.constellation, expected "
         "118, is "
      << last_msg_->stec_residuals[45].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[45].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[45].sv_id.satId)),
            136)
      << "incorrect value for stec_residuals[45].sv_id.satId, expected 136, is "
      << last_msg_->stec_residuals[45].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[46].residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[46].residual)),
            -25077)
      << "incorrect value for stec_residuals[46].residual, expected -25077, is "
      << last_msg_->stec_residuals[46].residual;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[46].stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[46].stddev)),
            103)
      << "incorrect value for stec_residuals[46].stddev, expected 103, is "
      << last_msg_->stec_residuals[46].stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[46].sv_id.constellation)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[46].sv_id.constellation)),
            227)
      << "incorrect value for stec_residuals[46].sv_id.constellation, expected "
         "227, is "
      << last_msg_->stec_residuals[46].sv_id.constellation;
  EXPECT_EQ(get_as<decltype(last_msg_->stec_residuals[46].sv_id.satId)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->stec_residuals[46].sv_id.satId)),
            233)
      << "incorrect value for stec_residuals[46].sv_id.satId, expected 233, is "
      << last_msg_->stec_residuals[46].sv_id.satId;
  EXPECT_EQ(get_as<decltype(last_msg_->tropo_delay_correction.hydro)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->tropo_delay_correction.hydro)),
            10643)
      << "incorrect value for tropo_delay_correction.hydro, expected 10643, is "
      << last_msg_->tropo_delay_correction.hydro;
  EXPECT_EQ(get_as<decltype(last_msg_->tropo_delay_correction.stddev)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->tropo_delay_correction.stddev)),
            92)
      << "incorrect value for tropo_delay_correction.stddev, expected 92, is "
      << last_msg_->tropo_delay_correction.stddev;
  EXPECT_EQ(get_as<decltype(last_msg_->tropo_delay_correction.wet)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->tropo_delay_correction.wet)),
            33)
      << "incorrect value for tropo_delay_correction.wet, expected 33, is "
      << last_msg_->tropo_delay_correction.wet;
}
