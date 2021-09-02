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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedCovGnss.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgVelNedCovGnss0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_vel_ned_cov_gnss_t> {
 public:
  Test_auto_check_sbp_navigation_MsgVelNedCovGnss0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_vel_ned_cov_gnss_t>(this),
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
                      const sbp_msg_vel_ned_cov_gnss_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_cov_gnss_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgVelNedCovGnss0, Test) {
  uint8_t encoded_frame[] = {
      85,  50,  2,   0,   16,  42,  168, 230, 233, 29,  251, 255, 255,
      255, 0,   0,   0,   0,   246, 255, 255, 255, 15,  58,  207, 58,
      248, 139, 116, 55,  103, 197, 57,  57,  203, 186, 129, 58,  109,
      171, 44,  57,  135, 39,  1,   60,  21,  2,   155, 3,
  };

  sbp_msg_vel_ned_cov_gnss_t test_msg{};
  test_msg.cov_d_d = 0.007882959209382534;
  test_msg.cov_e_d = 0.00016467059322167188;
  test_msg.cov_e_e = 0.0009897587588056922;
  test_msg.cov_n_d = 0.00017716512957122177;
  test_msg.cov_n_e = 1.457612233934924e-05;
  test_msg.cov_n_n = 0.0015810149488970637;
  test_msg.d = -10;
  test_msg.e = 0;
  test_msg.flags = 2;
  test_msg.n = -5;
  test_msg.n_sats = 21;
  test_msg.tow = 501868200;

  EXPECT_EQ(send_message(4096, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4096);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cov_d_d * 100 - 0.00788295920938 * 100), 0.05)
      << "incorrect value for last_msg_.cov_d_d, expected 0.00788295920938, is "
      << last_msg_.cov_d_d;
  EXPECT_LT((last_msg_.cov_e_d * 100 - 0.000164670593222 * 100), 0.05)
      << "incorrect value for last_msg_.cov_e_d, expected 0.000164670593222, "
         "is "
      << last_msg_.cov_e_d;
  EXPECT_LT((last_msg_.cov_e_e * 100 - 0.000989758758806 * 100), 0.05)
      << "incorrect value for last_msg_.cov_e_e, expected 0.000989758758806, "
         "is "
      << last_msg_.cov_e_e;
  EXPECT_LT((last_msg_.cov_n_d * 100 - 0.000177165129571 * 100), 0.05)
      << "incorrect value for last_msg_.cov_n_d, expected 0.000177165129571, "
         "is "
      << last_msg_.cov_n_d;
  EXPECT_LT((last_msg_.cov_n_e * 100 - 1.45761223393e-05 * 100), 0.05)
      << "incorrect value for last_msg_.cov_n_e, expected 1.45761223393e-05, "
         "is "
      << last_msg_.cov_n_e;
  EXPECT_LT((last_msg_.cov_n_n * 100 - 0.0015810149489 * 100), 0.05)
      << "incorrect value for last_msg_.cov_n_n, expected 0.0015810149489, is "
      << last_msg_.cov_n_n;
  EXPECT_EQ(last_msg_.d, -10)
      << "incorrect value for last_msg_.d, expected -10, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, 0)
      << "incorrect value for last_msg_.e, expected 0, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n, -5)
      << "incorrect value for last_msg_.n, expected -5, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 21)
      << "incorrect value for last_msg_.n_sats, expected 21, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 501868200)
      << "incorrect value for last_msg_.tow, expected 501868200, is "
      << last_msg_.tow;
}
