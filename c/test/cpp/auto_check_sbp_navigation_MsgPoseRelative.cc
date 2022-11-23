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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPoseRelative.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgPoseRelative0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pose_relative_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPoseRelative0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pose_relative_t>(this),
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
                      const sbp_msg_pose_relative_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pose_relative_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPoseRelative0, Test) {
  uint8_t encoded_frame[] = {
      85,  69,  2,  66,  0,  90,  86,  4,   0,   0,   0,   86,  4,   0,
      0,   172, 8,  0,   0,  76,  4,   0,   0,   38,  2,   0,   0,   100,
      0,   0,   0,  100, 3,  200, 204, 252, 168, 157, 255, 115, 53,  186,
      144, 190, 48, 34,  37, 0,   0,   128, 63,  0,   0,   0,   0,   0,
      0,   0,   0,  0,   0,  128, 63,  0,   0,   0,   0,   0,   0,   128,
      63,  0,   0,  0,   64, 0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   64, 0,   0,  0,   0,   0,   0,   0,   64,  5,   171, 187,
  };

  sbp_msg_pose_relative_t test_msg{};
  test_msg.cov_c_x_x = 2.0;
  test_msg.cov_c_x_y = 0.0;
  test_msg.cov_c_x_z = 0.0;
  test_msg.cov_c_y_y = 2.0;
  test_msg.cov_c_y_z = 0.0;
  test_msg.cov_c_z_z = 2.0;
  test_msg.cov_r_x_x = 1.0;
  test_msg.cov_r_x_y = 0.0;
  test_msg.cov_r_x_z = 0.0;
  test_msg.cov_r_y_y = 1.0;
  test_msg.cov_r_y_z = 0.0;
  test_msg.cov_r_z_z = 1.0;
  test_msg.flags = 5;
  test_msg.sensor_id = 0;
  test_msg.timestamp_1 = 1110;
  test_msg.timestamp_2 = 2220;
  test_msg.tow = 1110;

  test_msg.trans[0] = 1100;

  test_msg.trans[1] = 550;

  test_msg.trans[2] = 100;
  test_msg.w = -859307164;
  test_msg.x = -6444804;
  test_msg.y = -1866844813;
  test_msg.z = 622997694;

  EXPECT_EQ(send_message(66, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cov_c_x_x * 100 - 2.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_c_x_x, expected 2.0, is "
      << last_msg_.cov_c_x_x;
  EXPECT_LT((last_msg_.cov_c_x_y * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_c_x_y, expected 0.0, is "
      << last_msg_.cov_c_x_y;
  EXPECT_LT((last_msg_.cov_c_x_z * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_c_x_z, expected 0.0, is "
      << last_msg_.cov_c_x_z;
  EXPECT_LT((last_msg_.cov_c_y_y * 100 - 2.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_c_y_y, expected 2.0, is "
      << last_msg_.cov_c_y_y;
  EXPECT_LT((last_msg_.cov_c_y_z * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_c_y_z, expected 0.0, is "
      << last_msg_.cov_c_y_z;
  EXPECT_LT((last_msg_.cov_c_z_z * 100 - 2.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_c_z_z, expected 2.0, is "
      << last_msg_.cov_c_z_z;
  EXPECT_LT((last_msg_.cov_r_x_x * 100 - 1.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_r_x_x, expected 1.0, is "
      << last_msg_.cov_r_x_x;
  EXPECT_LT((last_msg_.cov_r_x_y * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_r_x_y, expected 0.0, is "
      << last_msg_.cov_r_x_y;
  EXPECT_LT((last_msg_.cov_r_x_z * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_r_x_z, expected 0.0, is "
      << last_msg_.cov_r_x_z;
  EXPECT_LT((last_msg_.cov_r_y_y * 100 - 1.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_r_y_y, expected 1.0, is "
      << last_msg_.cov_r_y_y;
  EXPECT_LT((last_msg_.cov_r_y_z * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_r_y_z, expected 0.0, is "
      << last_msg_.cov_r_y_z;
  EXPECT_LT((last_msg_.cov_r_z_z * 100 - 1.0 * 100), 0.05)
      << "incorrect value for last_msg_.cov_r_z_z, expected 1.0, is "
      << last_msg_.cov_r_z_z;
  EXPECT_EQ(last_msg_.flags, 5)
      << "incorrect value for last_msg_.flags, expected 5, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.sensor_id, 0)
      << "incorrect value for last_msg_.sensor_id, expected 0, is "
      << last_msg_.sensor_id;
  EXPECT_EQ(last_msg_.timestamp_1, 1110)
      << "incorrect value for last_msg_.timestamp_1, expected 1110, is "
      << last_msg_.timestamp_1;
  EXPECT_EQ(last_msg_.timestamp_2, 2220)
      << "incorrect value for last_msg_.timestamp_2, expected 2220, is "
      << last_msg_.timestamp_2;
  EXPECT_EQ(last_msg_.tow, 1110)
      << "incorrect value for last_msg_.tow, expected 1110, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.trans[0], 1100)
      << "incorrect value for last_msg_.trans[0], expected 1100, is "
      << last_msg_.trans[0];
  EXPECT_EQ(last_msg_.trans[1], 550)
      << "incorrect value for last_msg_.trans[1], expected 550, is "
      << last_msg_.trans[1];
  EXPECT_EQ(last_msg_.trans[2], 100)
      << "incorrect value for last_msg_.trans[2], expected 100, is "
      << last_msg_.trans[2];
  EXPECT_EQ(last_msg_.w, -859307164)
      << "incorrect value for last_msg_.w, expected -859307164, is "
      << last_msg_.w;
  EXPECT_EQ(last_msg_.x, -6444804)
      << "incorrect value for last_msg_.x, expected -6444804, is "
      << last_msg_.x;
  EXPECT_EQ(last_msg_.y, -1866844813)
      << "incorrect value for last_msg_.y, expected -1866844813, is "
      << last_msg_.y;
  EXPECT_EQ(last_msg_.z, 622997694)
      << "incorrect value for last_msg_.z, expected 622997694, is "
      << last_msg_.z;
}
