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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefCovGnss.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgVelEcefCovGnss0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_vel_ecef_cov_gnss_t> {
 public:
  Test_auto_check_sbp_navigation_MsgVelEcefCovGnss0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_vel_ecef_cov_gnss_t>(this),
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
                      const sbp_msg_vel_ecef_cov_gnss_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_cov_gnss_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgVelEcefCovGnss0, Test) {
  uint8_t encoded_frame[] = {
      85,  53,  2,   0,  16,  42,  224, 229, 233, 29, 253, 255, 255,
      255, 1,   0,   0,  0,   4,   0,   0,   0,   46, 224, 32,  59,
      32,  214, 14,  59, 150, 147, 220, 186, 19,  63, 138, 59,  26,
      150, 35,  187, 11, 193, 119, 59,  21,  2,   22, 230,
  };

  sbp_msg_vel_ecef_cov_gnss_t test_msg{};
  test_msg.cov_x_x = 0.0024547684006392956;
  test_msg.cov_x_y = 0.0021795108914375305;
  test_msg.cov_x_z = -0.0016828652005642653;
  test_msg.cov_y_y = 0.004218944814056158;
  test_msg.cov_y_z = -0.0024961293675005436;
  test_msg.cov_z_z = 0.0037804271560162306;
  test_msg.flags = 2;
  test_msg.n_sats = 21;
  test_msg.tow = 501868000;
  test_msg.x = -3;
  test_msg.y = 1;
  test_msg.z = 4;

  EXPECT_EQ(send_message(4096, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4096);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cov_x_x * 100 - 0.00245476840064 * 100), 0.05)
      << "incorrect value for last_msg_.cov_x_x, expected 0.00245476840064, is "
      << last_msg_.cov_x_x;
  EXPECT_LT((last_msg_.cov_x_y * 100 - 0.00217951089144 * 100), 0.05)
      << "incorrect value for last_msg_.cov_x_y, expected 0.00217951089144, is "
      << last_msg_.cov_x_y;
  EXPECT_LT((last_msg_.cov_x_z * 100 - -0.00168286520056 * 100), 0.05)
      << "incorrect value for last_msg_.cov_x_z, expected -0.00168286520056, "
         "is "
      << last_msg_.cov_x_z;
  EXPECT_LT((last_msg_.cov_y_y * 100 - 0.00421894481406 * 100), 0.05)
      << "incorrect value for last_msg_.cov_y_y, expected 0.00421894481406, is "
      << last_msg_.cov_y_y;
  EXPECT_LT((last_msg_.cov_y_z * 100 - -0.0024961293675 * 100), 0.05)
      << "incorrect value for last_msg_.cov_y_z, expected -0.0024961293675, is "
      << last_msg_.cov_y_z;
  EXPECT_LT((last_msg_.cov_z_z * 100 - 0.00378042715602 * 100), 0.05)
      << "incorrect value for last_msg_.cov_z_z, expected 0.00378042715602, is "
      << last_msg_.cov_z_z;
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 21)
      << "incorrect value for last_msg_.n_sats, expected 21, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 501868000)
      << "incorrect value for last_msg_.tow, expected 501868000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.x, -3)
      << "incorrect value for last_msg_.x, expected -3, is " << last_msg_.x;
  EXPECT_EQ(last_msg_.y, 1)
      << "incorrect value for last_msg_.y, expected 1, is " << last_msg_.y;
  EXPECT_EQ(last_msg_.z, 4)
      << "incorrect value for last_msg_.z, expected 4, is " << last_msg_.z;
}
