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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelBody.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgVelBody0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_vel_body_t> {
 public:
  Test_auto_check_sbp_navigation_MsgVelBody0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_vel_body_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_vel_body_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_body_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgVelBody0, Test) {
  uint8_t encoded_frame[] = {
      85, 19, 2,   66, 0, 42, 1,  0,  0, 0, 4, 0,   0,  0, 2,   0,   0,
      0,  1,  0,   0,  0, 0,  0,  0,  0, 0, 0, 160, 64, 0, 0,   224, 64,
      0,  0,  224, 64, 0, 0,  64, 64, 0, 0, 0, 64,  3,  8, 120, 144,
  };

  sbp_msg_vel_body_t test_msg{};
  test_msg.cov_x_x = 0.0;
  test_msg.cov_x_y = 5.0;
  test_msg.cov_x_z = 7.0;
  test_msg.cov_y_y = 7.0;
  test_msg.cov_y_z = 3.0;
  test_msg.cov_z_z = 2.0;
  test_msg.flags = 8;
  test_msg.n_sats = 3;
  test_msg.tow = 1;
  test_msg.x = 4;
  test_msg.y = 2;
  test_msg.z = 1;

  EXPECT_EQ(send_message(66, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cov_x_x * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_x_x, expected 0.0, is "
      << last_msg_.cov_x_x;
  EXPECT_LT((last_msg_.cov_x_y * 100 - 5.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_x_y, expected 5.0, is "
      << last_msg_.cov_x_y;
  EXPECT_LT((last_msg_.cov_x_z * 100 - 7.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_x_z, expected 7.0, is "
      << last_msg_.cov_x_z;
  EXPECT_LT((last_msg_.cov_y_y * 100 - 7.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_y_y, expected 7.0, is "
      << last_msg_.cov_y_y;
  EXPECT_LT((last_msg_.cov_y_z * 100 - 3.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_y_z, expected 3.0, is "
      << last_msg_.cov_y_z;
  EXPECT_LT((last_msg_.cov_z_z * 100 - 2.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_z_z, expected 2.0, is "
      << last_msg_.cov_z_z;
  EXPECT_EQ(last_msg_.flags, 8)
      << "incorrect value for last_msg_.flags, expected 8, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 3)
      << "incorrect value for last_msg_.n_sats, expected 3, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 1)
      << "incorrect value for last_msg_.tow, expected 1, is " << last_msg_.tow;
  EXPECT_EQ(last_msg_.x, 4)
      << "incorrect value for last_msg_.x, expected 4, is " << last_msg_.x;
  EXPECT_EQ(last_msg_.y, 2)
      << "incorrect value for last_msg_.y, expected 2, is " << last_msg_.y;
  EXPECT_EQ(last_msg_.z, 1)
      << "incorrect value for last_msg_.z, expected 1, is " << last_msg_.z;
}
