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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIq.yaml by generate.py.
// Do not modify by hand!

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
#include <libsbp/legacy/tracking.h>
class Test_legacy_auto_check_sbp_tracking_MsgTrackingIq0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_tracking_iq_t> {
 public:
  Test_legacy_auto_check_sbp_tracking_MsgTrackingIq0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_tracking_iq_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_tracking_iq_t *>(last_msg_storage_)),
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
                      const msg_tracking_iq_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_tracking_iq_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_tracking_MsgTrackingIq0, Test) {
  uint8_t encoded_frame[] = {
      85, 45, 0,  2,   80, 15,  145, 121, 203, 47, 217, 239,
      55, 45, 38, 189, 88, 159, 19,  208, 12,  97, 167,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_tracking_iq_t *test_msg = (msg_tracking_iq_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->channel = 145;
  if (sizeof(test_msg->corrs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->corrs[0]));
  }
  test_msg->corrs[0].I = -9937;
  test_msg->corrs[0].Q = 14319;
  if (sizeof(test_msg->corrs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->corrs[0]));
  }
  test_msg->corrs[1].I = 9773;
  test_msg->corrs[1].Q = 22717;
  if (sizeof(test_msg->corrs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->corrs[0]));
  }
  test_msg->corrs[2].I = 5023;
  test_msg->corrs[2].Q = 3280;
  test_msg->sid.code = 203;
  test_msg->sid.sat = 121;

  EXPECT_EQ(send_message(0x2d, 20482, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 20482);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->channel, 145)
      << "incorrect value for channel, expected 145, is " << last_msg_->channel;
  EXPECT_EQ(last_msg_->corrs[0].I, -9937)
      << "incorrect value for corrs[0].I, expected -9937, is "
      << last_msg_->corrs[0].I;
  EXPECT_EQ(last_msg_->corrs[0].Q, 14319)
      << "incorrect value for corrs[0].Q, expected 14319, is "
      << last_msg_->corrs[0].Q;
  EXPECT_EQ(last_msg_->corrs[1].I, 9773)
      << "incorrect value for corrs[1].I, expected 9773, is "
      << last_msg_->corrs[1].I;
  EXPECT_EQ(last_msg_->corrs[1].Q, 22717)
      << "incorrect value for corrs[1].Q, expected 22717, is "
      << last_msg_->corrs[1].Q;
  EXPECT_EQ(last_msg_->corrs[2].I, 5023)
      << "incorrect value for corrs[2].I, expected 5023, is "
      << last_msg_->corrs[2].I;
  EXPECT_EQ(last_msg_->corrs[2].Q, 3280)
      << "incorrect value for corrs[2].Q, expected 3280, is "
      << last_msg_->corrs[2].Q;
  EXPECT_EQ(last_msg_->sid.code, 203)
      << "incorrect value for sid.code, expected 203, is "
      << last_msg_->sid.code;
  EXPECT_EQ(last_msg_->sid.sat, 121)
      << "incorrect value for sid.sat, expected 121, is " << last_msg_->sid.sat;
}
