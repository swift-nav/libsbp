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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBoundsDegradation.yaml
// by generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_ssr_orbit_clock_bounds_degradation_t> {
 public:
  Test_auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_ssr_orbit_clock_bounds_degradation_t>(this),
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
  void handle_sbp_msg(
      uint16_t sender_id,
      const sbp_msg_ssr_orbit_clock_bounds_degradation_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_ssr_orbit_clock_bounds_degradation_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation0, Test) {
  uint8_t encoded_frame[] = {
      85, 223, 5,   66,  0,   28,  180, 0,   0,   0,   3,   0,
      1,  2,   3,   48,  15,  1,   10,  0,   0,   0,   0,   0,
      0,  0,   200, 199, 198, 197, 196, 195, 194, 193, 200, 117,
  };

  sbp_msg_ssr_orbit_clock_bounds_degradation_t test_msg{};
  test_msg.const_id = 1;
  test_msg.header.num_msgs = 1;
  test_msg.header.seq_num = 2;
  test_msg.header.sol_id = 48;
  test_msg.header.time.tow = 180;
  test_msg.header.time.wn = 3;
  test_msg.header.update_interval = 3;
  test_msg.orbit_clock_bounds_degradation.clock_bound_mu_dot = 194;
  test_msg.orbit_clock_bounds_degradation.clock_bound_sig_dot = 193;
  test_msg.orbit_clock_bounds_degradation.orb_along_bound_mu_dot = 199;
  test_msg.orbit_clock_bounds_degradation.orb_along_bound_sig_dot = 196;
  test_msg.orbit_clock_bounds_degradation.orb_cross_bound_mu_dot = 198;
  test_msg.orbit_clock_bounds_degradation.orb_cross_bound_sig_dot = 195;
  test_msg.orbit_clock_bounds_degradation.orb_radial_bound_mu_dot = 200;
  test_msg.orbit_clock_bounds_degradation.orb_radial_bound_sig_dot = 197;
  test_msg.sat_bitmask = 10;
  test_msg.ssr_iod = 15;

  EXPECT_EQ(send_message(66, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.const_id, 1)
      << "incorrect value for last_msg_.const_id, expected 1, is "
      << last_msg_.const_id;
  EXPECT_EQ(last_msg_.header.num_msgs, 1)
      << "incorrect value for last_msg_.header.num_msgs, expected 1, is "
      << last_msg_.header.num_msgs;
  EXPECT_EQ(last_msg_.header.seq_num, 2)
      << "incorrect value for last_msg_.header.seq_num, expected 2, is "
      << last_msg_.header.seq_num;
  EXPECT_EQ(last_msg_.header.sol_id, 48)
      << "incorrect value for last_msg_.header.sol_id, expected 48, is "
      << last_msg_.header.sol_id;
  EXPECT_EQ(last_msg_.header.time.tow, 180)
      << "incorrect value for last_msg_.header.time.tow, expected 180, is "
      << last_msg_.header.time.tow;
  EXPECT_EQ(last_msg_.header.time.wn, 3)
      << "incorrect value for last_msg_.header.time.wn, expected 3, is "
      << last_msg_.header.time.wn;
  EXPECT_EQ(last_msg_.header.update_interval, 3)
      << "incorrect value for last_msg_.header.update_interval, expected 3, is "
      << last_msg_.header.update_interval;
  EXPECT_EQ(last_msg_.orbit_clock_bounds_degradation.clock_bound_mu_dot, 194)
      << "incorrect value for "
         "last_msg_.orbit_clock_bounds_degradation.clock_bound_mu_dot, "
         "expected 194, is "
      << last_msg_.orbit_clock_bounds_degradation.clock_bound_mu_dot;
  EXPECT_EQ(last_msg_.orbit_clock_bounds_degradation.clock_bound_sig_dot, 193)
      << "incorrect value for "
         "last_msg_.orbit_clock_bounds_degradation.clock_bound_sig_dot, "
         "expected 193, is "
      << last_msg_.orbit_clock_bounds_degradation.clock_bound_sig_dot;
  EXPECT_EQ(last_msg_.orbit_clock_bounds_degradation.orb_along_bound_mu_dot,
            199)
      << "incorrect value for "
         "last_msg_.orbit_clock_bounds_degradation.orb_along_bound_mu_dot, "
         "expected 199, is "
      << last_msg_.orbit_clock_bounds_degradation.orb_along_bound_mu_dot;
  EXPECT_EQ(last_msg_.orbit_clock_bounds_degradation.orb_along_bound_sig_dot,
            196)
      << "incorrect value for "
         "last_msg_.orbit_clock_bounds_degradation.orb_along_bound_sig_dot, "
         "expected 196, is "
      << last_msg_.orbit_clock_bounds_degradation.orb_along_bound_sig_dot;
  EXPECT_EQ(last_msg_.orbit_clock_bounds_degradation.orb_cross_bound_mu_dot,
            198)
      << "incorrect value for "
         "last_msg_.orbit_clock_bounds_degradation.orb_cross_bound_mu_dot, "
         "expected 198, is "
      << last_msg_.orbit_clock_bounds_degradation.orb_cross_bound_mu_dot;
  EXPECT_EQ(last_msg_.orbit_clock_bounds_degradation.orb_cross_bound_sig_dot,
            195)
      << "incorrect value for "
         "last_msg_.orbit_clock_bounds_degradation.orb_cross_bound_sig_dot, "
         "expected 195, is "
      << last_msg_.orbit_clock_bounds_degradation.orb_cross_bound_sig_dot;
  EXPECT_EQ(last_msg_.orbit_clock_bounds_degradation.orb_radial_bound_mu_dot,
            200)
      << "incorrect value for "
         "last_msg_.orbit_clock_bounds_degradation.orb_radial_bound_mu_dot, "
         "expected 200, is "
      << last_msg_.orbit_clock_bounds_degradation.orb_radial_bound_mu_dot;
  EXPECT_EQ(last_msg_.orbit_clock_bounds_degradation.orb_radial_bound_sig_dot,
            197)
      << "incorrect value for "
         "last_msg_.orbit_clock_bounds_degradation.orb_radial_bound_sig_dot, "
         "expected 197, is "
      << last_msg_.orbit_clock_bounds_degradation.orb_radial_bound_sig_dot;
  EXPECT_EQ(last_msg_.sat_bitmask, 10)
      << "incorrect value for last_msg_.sat_bitmask, expected 10, is "
      << last_msg_.sat_bitmask;
  EXPECT_EQ(last_msg_.ssr_iod, 15)
      << "incorrect value for last_msg_.ssr_iod, expected 15, is "
      << last_msg_.ssr_iod;
}
