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
// spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientQuat.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_orientation_MsgOrientQuat0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_orient_quat_t> {
 public:
  Test_legacy_auto_check_sbp_orientation_MsgOrientQuat0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_orient_quat_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_orient_quat_t *>(last_msg_storage_)),
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
                      const msg_orient_quat_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_orient_quat_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_orientation_MsgOrientQuat0, Test) {
  uint8_t encoded_frame[] = {
      85, 32, 2,   66, 0, 37, 0, 0,  0, 0, 3,  0,  0, 0,   7,
      0,  0,  0,   8,  0, 0,  0, 4,  0, 0, 0,  0,  0, 64,  64,
      0,  0,  128, 64, 0, 0,  0, 65, 0, 0, 64, 64, 1, 186, 6,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_orient_quat_t *test_msg = (msg_orient_quat_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 1;
  test_msg->tow = 0;
  test_msg->w = 3;
  test_msg->w_accuracy = 3.0;
  test_msg->x = 7;
  test_msg->x_accuracy = 4.0;
  test_msg->y = 8;
  test_msg->y_accuracy = 8.0;
  test_msg->z = 4;
  test_msg->z_accuracy = 3.0;

  EXPECT_EQ(send_message(0x220, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 1)
      << "incorrect value for flags, expected 1, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->tow, 0)
      << "incorrect value for tow, expected 0, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->w, 3)
      << "incorrect value for w, expected 3, is " << last_msg_->w;
  EXPECT_LT((last_msg_->w_accuracy * 100 - 3.0 * 100), 0.05)
      << "incorrect value for w_accuracy, expected 3.0, is "
      << last_msg_->w_accuracy;
  EXPECT_EQ(last_msg_->x, 7)
      << "incorrect value for x, expected 7, is " << last_msg_->x;
  EXPECT_LT((last_msg_->x_accuracy * 100 - 4.0 * 100), 0.05)
      << "incorrect value for x_accuracy, expected 4.0, is "
      << last_msg_->x_accuracy;
  EXPECT_EQ(last_msg_->y, 8)
      << "incorrect value for y, expected 8, is " << last_msg_->y;
  EXPECT_LT((last_msg_->y_accuracy * 100 - 8.0 * 100), 0.05)
      << "incorrect value for y_accuracy, expected 8.0, is "
      << last_msg_->y_accuracy;
  EXPECT_EQ(last_msg_->z, 4)
      << "incorrect value for z, expected 4, is " << last_msg_->z;
  EXPECT_LT((last_msg_->z_accuracy * 100 - 3.0 * 100), 0.05)
      << "incorrect value for z_accuracy, expected 3.0, is "
      << last_msg_->z_accuracy;
}
