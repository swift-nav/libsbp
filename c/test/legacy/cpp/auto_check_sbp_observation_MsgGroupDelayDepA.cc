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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgGroupDelayDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_observation_MsgGroupDelayDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_group_delay_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgGroupDelayDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_group_delay_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_group_delay_dep_a_t *>(last_msg_storage_)),
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
                      const msg_group_delay_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_group_delay_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgGroupDelayDepA0, Test) {
  uint8_t encoded_frame[] = {
      85, 146, 0, 123, 0,   14,  176, 207, 6,  0,   106,
      8,  22,  1, 254, 253, 165, 255, 237, 23, 162, 91,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_group_delay_dep_a_t *test_msg =
      (msg_group_delay_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->isc_l1ca = -91;
  test_msg->isc_l2c = 6125;
  test_msg->prn = 22;
  test_msg->t_op.tow = 446384;
  test_msg->t_op.wn = 2154;
  test_msg->tgd = -514;
  test_msg->valid = 1;

  EXPECT_EQ(send_message(0x92, 123, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 123);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->isc_l1ca, -91)
      << "incorrect value for isc_l1ca, expected -91, is "
      << last_msg_->isc_l1ca;
  EXPECT_EQ(last_msg_->isc_l2c, 6125)
      << "incorrect value for isc_l2c, expected 6125, is "
      << last_msg_->isc_l2c;
  EXPECT_EQ(last_msg_->prn, 22)
      << "incorrect value for prn, expected 22, is " << last_msg_->prn;
  EXPECT_EQ(last_msg_->t_op.tow, 446384)
      << "incorrect value for t_op.tow, expected 446384, is "
      << last_msg_->t_op.tow;
  EXPECT_EQ(last_msg_->t_op.wn, 2154)
      << "incorrect value for t_op.wn, expected 2154, is "
      << last_msg_->t_op.wn;
  EXPECT_EQ(last_msg_->tgd, -514)
      << "incorrect value for tgd, expected -514, is " << last_msg_->tgd;
  EXPECT_EQ(last_msg_->valid, 1)
      << "incorrect value for valid, expected 1, is " << last_msg_->valid;
}
