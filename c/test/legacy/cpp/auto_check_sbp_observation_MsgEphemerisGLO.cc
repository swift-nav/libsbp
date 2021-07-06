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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGLO.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_observation_MsgEphemerisGLO0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ephemeris_glo_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgEphemerisGLO0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ephemeris_glo_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ephemeris_glo_t *>(last_msg_storage_)),
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
                      const msg_ephemeris_glo_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ephemeris_glo_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgEphemerisGLO0, Test) {
  uint8_t encoded_frame[] = {
      85,  139, 0,  10,  9,   92,  4,   3,   70,  197, 6,   0,   106, 8,   0,
      0,   160, 64, 96,  9,   0,   0,   1,   0,   0,   0,   128, 43,  128, 97,
      175, 184, 0,  0,   64,  177, 0,   0,   128, 66,  246, 57,  103, 193, 0,
      0,   0,   34, 170, 78,  34,  65,  0,   0,   240, 199, 84,  86,  117, 193,
      0,   0,   0,  98,  6,   250, 154, 192, 0,   0,   0,   217, 58,  221, 163,
      192, 0,   0,  0,   184, 138, 46,  139, 64,  0,   0,   122, 53,  0,   0,
      122, 53,  0,  128, 59,  54,  14,  100, 89,  149,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ephemeris_glo_t *test_msg = (msg_ephemeris_glo_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->acc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->acc[0]));
  }
  test_msg->acc[0] = 9.313225746154785e-07;
  if (sizeof(test_msg->acc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->acc[0]));
  }
  test_msg->acc[1] = 9.313225746154785e-07;
  if (sizeof(test_msg->acc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->acc[0]));
  }
  test_msg->acc[2] = 2.7939677238464355e-06;
  test_msg->common.fit_interval = 2400;
  test_msg->common.health_bits = 0;
  test_msg->common.sid.code = 3;
  test_msg->common.sid.sat = 4;
  test_msg->common.toe.tow = 443718;
  test_msg->common.toe.wn = 2154;
  test_msg->common.ura = 5.0;
  test_msg->common.valid = 1;
  test_msg->d_tau = -2.7939677238464355e-09;
  test_msg->fcn = 14;
  test_msg->gamma = 9.094947017729282e-13;
  test_msg->iod = 100;
  if (sizeof(test_msg->pos) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->pos[0]));
  }
  test_msg->pos[0] = -12177330.078125;
  if (sizeof(test_msg->pos) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->pos[0]));
  }
  test_msg->pos[1] = 599893.06640625;
  if (sizeof(test_msg->pos) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->pos[0]));
  }
  test_msg->pos[2] = -22373708.49609375;
  test_msg->tau = -8.36281105875969e-05;
  if (sizeof(test_msg->vel) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->vel[0]));
  }
  test_msg->vel[0] = -1726.506233215332;
  if (sizeof(test_msg->vel) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->vel[0]));
  }
  test_msg->vel[1] = -2542.6149368286133;
  if (sizeof(test_msg->vel) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->vel[0]));
  }
  test_msg->vel[2] = 869.8177337646484;

  EXPECT_EQ(send_message(0x8b, 2314, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 2314);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->acc[0] * 100 - 9.31322574615e-07 * 100), 0.05)
      << "incorrect value for acc[0], expected 9.31322574615e-07, is "
      << last_msg_->acc[0];
  EXPECT_LT((last_msg_->acc[1] * 100 - 9.31322574615e-07 * 100), 0.05)
      << "incorrect value for acc[1], expected 9.31322574615e-07, is "
      << last_msg_->acc[1];
  EXPECT_LT((last_msg_->acc[2] * 100 - 2.79396772385e-06 * 100), 0.05)
      << "incorrect value for acc[2], expected 2.79396772385e-06, is "
      << last_msg_->acc[2];
  EXPECT_EQ(last_msg_->common.fit_interval, 2400)
      << "incorrect value for common.fit_interval, expected 2400, is "
      << last_msg_->common.fit_interval;
  EXPECT_EQ(last_msg_->common.health_bits, 0)
      << "incorrect value for common.health_bits, expected 0, is "
      << last_msg_->common.health_bits;
  EXPECT_EQ(last_msg_->common.sid.code, 3)
      << "incorrect value for common.sid.code, expected 3, is "
      << last_msg_->common.sid.code;
  EXPECT_EQ(last_msg_->common.sid.sat, 4)
      << "incorrect value for common.sid.sat, expected 4, is "
      << last_msg_->common.sid.sat;
  EXPECT_EQ(last_msg_->common.toe.tow, 443718)
      << "incorrect value for common.toe.tow, expected 443718, is "
      << last_msg_->common.toe.tow;
  EXPECT_EQ(last_msg_->common.toe.wn, 2154)
      << "incorrect value for common.toe.wn, expected 2154, is "
      << last_msg_->common.toe.wn;
  EXPECT_LT((last_msg_->common.ura * 100 - 5.0 * 100), 0.05)
      << "incorrect value for common.ura, expected 5.0, is "
      << last_msg_->common.ura;
  EXPECT_EQ(last_msg_->common.valid, 1)
      << "incorrect value for common.valid, expected 1, is "
      << last_msg_->common.valid;
  EXPECT_LT((last_msg_->d_tau * 100 - -2.79396772385e-09 * 100), 0.05)
      << "incorrect value for d_tau, expected -2.79396772385e-09, is "
      << last_msg_->d_tau;
  EXPECT_EQ(last_msg_->fcn, 14)
      << "incorrect value for fcn, expected 14, is " << last_msg_->fcn;
  EXPECT_LT((last_msg_->gamma * 100 - 9.09494701773e-13 * 100), 0.05)
      << "incorrect value for gamma, expected 9.09494701773e-13, is "
      << last_msg_->gamma;
  EXPECT_EQ(last_msg_->iod, 100)
      << "incorrect value for iod, expected 100, is " << last_msg_->iod;
  EXPECT_LT((last_msg_->pos[0] * 100 - -12177330.0781 * 100), 0.05)
      << "incorrect value for pos[0], expected -12177330.0781, is "
      << last_msg_->pos[0];
  EXPECT_LT((last_msg_->pos[1] * 100 - 599893.066406 * 100), 0.05)
      << "incorrect value for pos[1], expected 599893.066406, is "
      << last_msg_->pos[1];
  EXPECT_LT((last_msg_->pos[2] * 100 - -22373708.4961 * 100), 0.05)
      << "incorrect value for pos[2], expected -22373708.4961, is "
      << last_msg_->pos[2];
  EXPECT_LT((last_msg_->tau * 100 - -8.36281105876e-05 * 100), 0.05)
      << "incorrect value for tau, expected -8.36281105876e-05, is "
      << last_msg_->tau;
  EXPECT_LT((last_msg_->vel[0] * 100 - -1726.50623322 * 100), 0.05)
      << "incorrect value for vel[0], expected -1726.50623322, is "
      << last_msg_->vel[0];
  EXPECT_LT((last_msg_->vel[1] * 100 - -2542.61493683 * 100), 0.05)
      << "incorrect value for vel[1], expected -2542.61493683, is "
      << last_msg_->vel[1];
  EXPECT_LT((last_msg_->vel[2] * 100 - 869.817733765 * 100), 0.05)
      << "incorrect value for vel[2], expected 869.817733765, is "
      << last_msg_->vel[2];
}
