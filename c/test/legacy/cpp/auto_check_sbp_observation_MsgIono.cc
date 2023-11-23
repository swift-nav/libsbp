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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgIono.yaml by generate.py. Do
// not modify by hand!

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
class Test_legacy_auto_check_sbp_observation_MsgIono0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_iono_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgIono0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_iono_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_iono_t *>(last_msg_storage_)),
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
                      const msg_iono_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_iono_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgIono0, Test) {
  uint8_t encoded_frame[] = {
      85, 144, 0,   123, 0, 70, 0, 0, 0, 0, 0,   0,   0,   0,  0, 0,
      0,  0,   52,  62,  0, 0,  0, 0, 0, 0, 80,  62,  0,   0,  0, 0,
      0,  0,   112, 190, 0, 0,  0, 0, 0, 0, 112, 190, 0,   0,  0, 0,
      0,  0,   243, 64,  0, 0,  0, 0, 0, 0, 232, 64,  0,   0,  0, 0,
      0,  0,   240, 192, 0, 0,  0, 0, 0, 0, 20,  193, 101, 31,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_iono_t *test_msg = (msg_iono_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->a0 = 4.6566128730773926e-09;
  test_msg->a1 = 1.4901161193847656e-08;
  test_msg->a2 = -5.960464477539063e-08;
  test_msg->a3 = -5.960464477539063e-08;
  test_msg->b0 = 77824.0;
  test_msg->b1 = 49152.0;
  test_msg->b2 = -65536.0;
  test_msg->b3 = -327680.0;
  test_msg->t_nmct.tow = 0;
  test_msg->t_nmct.wn = 0;

  EXPECT_EQ(send_message(0x90, 123, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 123);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->a0 * 100 - 4.65661287308e-09 * 100), 0.05)
      << "incorrect value for a0, expected 4.65661287308e-09, is "
      << last_msg_->a0;
  EXPECT_LT((last_msg_->a1 * 100 - 1.49011611938e-08 * 100), 0.05)
      << "incorrect value for a1, expected 1.49011611938e-08, is "
      << last_msg_->a1;
  EXPECT_LT((last_msg_->a2 * 100 - -5.96046447754e-08 * 100), 0.05)
      << "incorrect value for a2, expected -5.96046447754e-08, is "
      << last_msg_->a2;
  EXPECT_LT((last_msg_->a3 * 100 - -5.96046447754e-08 * 100), 0.05)
      << "incorrect value for a3, expected -5.96046447754e-08, is "
      << last_msg_->a3;
  EXPECT_LT((last_msg_->b0 * 100 - 77824.0 * 100), 0.05)
      << "incorrect value for b0, expected 77824.0, is " << last_msg_->b0;
  EXPECT_LT((last_msg_->b1 * 100 - 49152.0 * 100), 0.05)
      << "incorrect value for b1, expected 49152.0, is " << last_msg_->b1;
  EXPECT_LT((last_msg_->b2 * 100 - -65536.0 * 100), 0.05)
      << "incorrect value for b2, expected -65536.0, is " << last_msg_->b2;
  EXPECT_LT((last_msg_->b3 * 100 - -327680.0 * 100), 0.05)
      << "incorrect value for b3, expected -327680.0, is " << last_msg_->b3;
  EXPECT_EQ(last_msg_->t_nmct.tow, 0)
      << "incorrect value for t_nmct.tow, expected 0, is "
      << last_msg_->t_nmct.tow;
  EXPECT_EQ(last_msg_->t_nmct.wn, 0)
      << "incorrect value for t_nmct.wn, expected 0, is "
      << last_msg_->t_nmct.wn;
}
