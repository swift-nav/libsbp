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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgAlmanacGLO.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>
#include <libsbp/cpp/state.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/observation.h>
class Test_legacy_auto_check_sbp_observation_MsgAlmanacGLO0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_almanac_glo_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgAlmanacGLO0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_almanac_glo_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_almanac_glo_t *>(last_msg_storage_)),
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
                      const msg_almanac_glo_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_almanac_glo_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgAlmanacGLO0, Test) {
  uint8_t encoded_frame[] = {
      85,  115, 0,   195, 4,   78,  22,  0,   176, 207, 6,   0,   106, 8,   154,
      153, 153, 153, 153, 153, 1,   64,  64,  56,  0,   0,   1,   0,   142, 41,
      5,   235, 95,  135, 150, 191, 0,   0,   0,   32,  191, 247, 124, 63,  0,
      0,   192, 206, 140, 33,  180, 64,  41,  131, 179, 134, 141, 248, 253, 191,
      227, 133, 81,  54,  204, 30,  67,  190, 216, 59,  199, 39,  96,  168, 239,
      191, 71,  11,  217, 147, 145, 228, 237, 63,  155, 87,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_almanac_glo_t *test_msg = (msg_almanac_glo_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->common.fit_interval = 14400;
  test_msg->common.health_bits = 0;
  test_msg->common.sid.code = 0;
  test_msg->common.sid.sat = 22;
  test_msg->common.toa.tow = 446384;
  test_msg->common.toa.wn = 2154;
  test_msg->common.ura = 2.2;
  test_msg->common.valid = 1;
  test_msg->epsilon = -0.9893036629599647;
  test_msg->i = 5153.550029754639;
  test_msg->lambda_na = -0.02200078842114688;
  test_msg->omega = 0.9341514480259797;
  test_msg->t = -1.8731818448797617;
  test_msg->t_dot = -8.903585155774196e-09;
  test_msg->t_lambda_na = 0.007072207052260637;

  EXPECT_EQ(send_message(0x73, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->common.fit_interval, 14400)
      << "incorrect value for common.fit_interval, expected 14400, is "
      << last_msg_->common.fit_interval;
  EXPECT_EQ(last_msg_->common.health_bits, 0)
      << "incorrect value for common.health_bits, expected 0, is "
      << last_msg_->common.health_bits;
  EXPECT_EQ(last_msg_->common.sid.code, 0)
      << "incorrect value for common.sid.code, expected 0, is "
      << last_msg_->common.sid.code;
  EXPECT_EQ(last_msg_->common.sid.sat, 22)
      << "incorrect value for common.sid.sat, expected 22, is "
      << last_msg_->common.sid.sat;
  EXPECT_EQ(last_msg_->common.toa.tow, 446384)
      << "incorrect value for common.toa.tow, expected 446384, is "
      << last_msg_->common.toa.tow;
  EXPECT_EQ(last_msg_->common.toa.wn, 2154)
      << "incorrect value for common.toa.wn, expected 2154, is "
      << last_msg_->common.toa.wn;
  EXPECT_LT((last_msg_->common.ura * 100 - 2.2 * 100), 0.05)
      << "incorrect value for common.ura, expected 2.2, is "
      << last_msg_->common.ura;
  EXPECT_EQ(last_msg_->common.valid, 1)
      << "incorrect value for common.valid, expected 1, is "
      << last_msg_->common.valid;
  EXPECT_LT((last_msg_->epsilon * 100 - -0.98930366296 * 100), 0.05)
      << "incorrect value for epsilon, expected -0.98930366296, is "
      << last_msg_->epsilon;
  EXPECT_LT((last_msg_->i * 100 - 5153.55002975 * 100), 0.05)
      << "incorrect value for i, expected 5153.55002975, is " << last_msg_->i;
  EXPECT_LT((last_msg_->lambda_na * 100 - -0.0220007884211 * 100), 0.05)
      << "incorrect value for lambda_na, expected -0.0220007884211, is "
      << last_msg_->lambda_na;
  EXPECT_LT((last_msg_->omega * 100 - 0.934151448026 * 100), 0.05)
      << "incorrect value for omega, expected 0.934151448026, is "
      << last_msg_->omega;
  EXPECT_LT((last_msg_->t * 100 - -1.87318184488 * 100), 0.05)
      << "incorrect value for t, expected -1.87318184488, is " << last_msg_->t;
  EXPECT_LT((last_msg_->t_dot * 100 - -8.90358515577e-09 * 100), 0.05)
      << "incorrect value for t_dot, expected -8.90358515577e-09, is "
      << last_msg_->t_dot;
  EXPECT_LT((last_msg_->t_lambda_na * 100 - 0.00707220705226 * 100), 0.05)
      << "incorrect value for t_lambda_na, expected 0.00707220705226, is "
      << last_msg_->t_lambda_na;
}
