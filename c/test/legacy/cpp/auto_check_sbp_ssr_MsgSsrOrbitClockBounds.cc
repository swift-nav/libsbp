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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBounds.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClockBounds0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_orbit_clock_bounds_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClockBounds0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_orbit_clock_bounds_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ssr_orbit_clock_bounds_t *>(
            last_msg_storage_)),
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
                      const msg_ssr_orbit_clock_bounds_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_orbit_clock_bounds_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClockBounds0, Test) {
  uint8_t encoded_frame[] = {
      85, 222, 5,  66, 0,  31, 180, 0,  0,  0,  3, 0,  1,
      2,  3,   48, 15, 1,  2,  24,  39, 38, 37, 1, 2,  3,
      39, 1,   3,  39, 38, 37, 1,   2,  3,  39, 1, 21, 85,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_orbit_clock_bounds_t *test_msg =
      (msg_ssr_orbit_clock_bounds_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->const_id = 1;
  test_msg->header.num_msgs = 1;
  test_msg->header.seq_num = 2;
  test_msg->header.sol_id = 48;
  test_msg->header.time.tow = 180;
  test_msg->header.time.wn = 3;
  test_msg->header.update_interval = 3;
  test_msg->n_sats = 2;
  if (sizeof(test_msg->orbit_clock_bounds) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->orbit_clock_bounds[0]));
  }
  test_msg->orbit_clock_bounds[0].clock_bound_mu = 39;
  test_msg->orbit_clock_bounds[0].clock_bound_sig = 1;
  test_msg->orbit_clock_bounds[0].orb_along_bound_mu = 38;
  test_msg->orbit_clock_bounds[0].orb_along_bound_sig = 2;
  test_msg->orbit_clock_bounds[0].orb_cross_bound_mu = 37;
  test_msg->orbit_clock_bounds[0].orb_cross_bound_sig = 3;
  test_msg->orbit_clock_bounds[0].orb_radial_bound_mu = 39;
  test_msg->orbit_clock_bounds[0].orb_radial_bound_sig = 1;
  test_msg->orbit_clock_bounds[0].sat_id = 24;
  if (sizeof(test_msg->orbit_clock_bounds) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->orbit_clock_bounds[0]));
  }
  test_msg->orbit_clock_bounds[1].clock_bound_mu = 39;
  test_msg->orbit_clock_bounds[1].clock_bound_sig = 1;
  test_msg->orbit_clock_bounds[1].orb_along_bound_mu = 38;
  test_msg->orbit_clock_bounds[1].orb_along_bound_sig = 2;
  test_msg->orbit_clock_bounds[1].orb_cross_bound_mu = 37;
  test_msg->orbit_clock_bounds[1].orb_cross_bound_sig = 3;
  test_msg->orbit_clock_bounds[1].orb_radial_bound_mu = 39;
  test_msg->orbit_clock_bounds[1].orb_radial_bound_sig = 1;
  test_msg->orbit_clock_bounds[1].sat_id = 3;
  test_msg->ssr_iod = 15;

  EXPECT_EQ(send_message(1502, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->const_id, 1)
      << "incorrect value for const_id, expected 1, is " << last_msg_->const_id;
  EXPECT_EQ(last_msg_->header.num_msgs, 1)
      << "incorrect value for header.num_msgs, expected 1, is "
      << last_msg_->header.num_msgs;
  EXPECT_EQ(last_msg_->header.seq_num, 2)
      << "incorrect value for header.seq_num, expected 2, is "
      << last_msg_->header.seq_num;
  EXPECT_EQ(last_msg_->header.sol_id, 48)
      << "incorrect value for header.sol_id, expected 48, is "
      << last_msg_->header.sol_id;
  EXPECT_EQ(last_msg_->header.time.tow, 180)
      << "incorrect value for header.time.tow, expected 180, is "
      << last_msg_->header.time.tow;
  EXPECT_EQ(last_msg_->header.time.wn, 3)
      << "incorrect value for header.time.wn, expected 3, is "
      << last_msg_->header.time.wn;
  EXPECT_EQ(last_msg_->header.update_interval, 3)
      << "incorrect value for header.update_interval, expected 3, is "
      << last_msg_->header.update_interval;
  EXPECT_EQ(last_msg_->n_sats, 2)
      << "incorrect value for n_sats, expected 2, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[0].clock_bound_mu, 39)
      << "incorrect value for orbit_clock_bounds[0].clock_bound_mu, expected "
         "39, is "
      << last_msg_->orbit_clock_bounds[0].clock_bound_mu;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[0].clock_bound_sig, 1)
      << "incorrect value for orbit_clock_bounds[0].clock_bound_sig, expected "
         "1, is "
      << last_msg_->orbit_clock_bounds[0].clock_bound_sig;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[0].orb_along_bound_mu, 38)
      << "incorrect value for orbit_clock_bounds[0].orb_along_bound_mu, "
         "expected 38, is "
      << last_msg_->orbit_clock_bounds[0].orb_along_bound_mu;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[0].orb_along_bound_sig, 2)
      << "incorrect value for orbit_clock_bounds[0].orb_along_bound_sig, "
         "expected 2, is "
      << last_msg_->orbit_clock_bounds[0].orb_along_bound_sig;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[0].orb_cross_bound_mu, 37)
      << "incorrect value for orbit_clock_bounds[0].orb_cross_bound_mu, "
         "expected 37, is "
      << last_msg_->orbit_clock_bounds[0].orb_cross_bound_mu;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[0].orb_cross_bound_sig, 3)
      << "incorrect value for orbit_clock_bounds[0].orb_cross_bound_sig, "
         "expected 3, is "
      << last_msg_->orbit_clock_bounds[0].orb_cross_bound_sig;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[0].orb_radial_bound_mu, 39)
      << "incorrect value for orbit_clock_bounds[0].orb_radial_bound_mu, "
         "expected 39, is "
      << last_msg_->orbit_clock_bounds[0].orb_radial_bound_mu;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[0].orb_radial_bound_sig, 1)
      << "incorrect value for orbit_clock_bounds[0].orb_radial_bound_sig, "
         "expected 1, is "
      << last_msg_->orbit_clock_bounds[0].orb_radial_bound_sig;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[0].sat_id, 24)
      << "incorrect value for orbit_clock_bounds[0].sat_id, expected 24, is "
      << last_msg_->orbit_clock_bounds[0].sat_id;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[1].clock_bound_mu, 39)
      << "incorrect value for orbit_clock_bounds[1].clock_bound_mu, expected "
         "39, is "
      << last_msg_->orbit_clock_bounds[1].clock_bound_mu;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[1].clock_bound_sig, 1)
      << "incorrect value for orbit_clock_bounds[1].clock_bound_sig, expected "
         "1, is "
      << last_msg_->orbit_clock_bounds[1].clock_bound_sig;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[1].orb_along_bound_mu, 38)
      << "incorrect value for orbit_clock_bounds[1].orb_along_bound_mu, "
         "expected 38, is "
      << last_msg_->orbit_clock_bounds[1].orb_along_bound_mu;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[1].orb_along_bound_sig, 2)
      << "incorrect value for orbit_clock_bounds[1].orb_along_bound_sig, "
         "expected 2, is "
      << last_msg_->orbit_clock_bounds[1].orb_along_bound_sig;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[1].orb_cross_bound_mu, 37)
      << "incorrect value for orbit_clock_bounds[1].orb_cross_bound_mu, "
         "expected 37, is "
      << last_msg_->orbit_clock_bounds[1].orb_cross_bound_mu;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[1].orb_cross_bound_sig, 3)
      << "incorrect value for orbit_clock_bounds[1].orb_cross_bound_sig, "
         "expected 3, is "
      << last_msg_->orbit_clock_bounds[1].orb_cross_bound_sig;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[1].orb_radial_bound_mu, 39)
      << "incorrect value for orbit_clock_bounds[1].orb_radial_bound_mu, "
         "expected 39, is "
      << last_msg_->orbit_clock_bounds[1].orb_radial_bound_mu;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[1].orb_radial_bound_sig, 1)
      << "incorrect value for orbit_clock_bounds[1].orb_radial_bound_sig, "
         "expected 1, is "
      << last_msg_->orbit_clock_bounds[1].orb_radial_bound_sig;
  EXPECT_EQ(last_msg_->orbit_clock_bounds[1].sat_id, 3)
      << "incorrect value for orbit_clock_bounds[1].sat_id, expected 3, is "
      << last_msg_->orbit_clock_bounds[1].sat_id;
  EXPECT_EQ(last_msg_->ssr_iod, 15)
      << "incorrect value for ssr_iod, expected 15, is " << last_msg_->ssr_iod;
}
