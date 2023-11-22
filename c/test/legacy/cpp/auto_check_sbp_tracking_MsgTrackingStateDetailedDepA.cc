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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDepA.yaml
// by generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_tracking_MsgTrackingStateDetailedDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_tracking_state_detailed_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_tracking_MsgTrackingStateDetailedDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_tracking_state_detailed_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_tracking_state_detailed_dep_a_t *>(
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
                      const msg_tracking_state_detailed_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_tracking_state_detailed_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_tracking_MsgTrackingStateDetailedDepA0,
       Test) {
  uint8_t encoded_frame[] = {
      85, 33,  0,   155, 110, 57,  46,  31,  180, 38,  219, 0,   0,
      0,  133, 100, 71,  94,  192, 2,   160, 207, 212, 255, 135, 139,
      62, 62,  179, 83,  227, 245, 134, 160, 204, 78,  95,  255, 38,
      59, 161, 15,  255, 86,  189, 248, 31,  191, 136, 194, 124, 23,
      15, 91,  249, 117, 142, 90,  219, 67,  25,  83,  62,  122, 100,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_tracking_state_detailed_dep_a_t *test_msg =
      (msg_tracking_state_detailed_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->L.f = 204;
  test_msg->L.i = -1601767965;
  test_msg->P = 1044286343;
  test_msg->P_std = 21427;
  test_msg->acceleration = -114;
  test_msg->clock_drift = 23311;
  test_msg->clock_offset = 6012;
  test_msg->cn0 = 78;
  test_msg->corr_spacing = 30201;
  test_msg->doppler = 1459556257;
  test_msg->doppler_std = 63677;
  test_msg->lock = 65375;
  test_msg->misc_flags = 62;
  test_msg->nav_flags = 25;
  test_msg->pset_flags = 83;
  test_msg->recv_time = 941247176494;
  test_msg->sid.code = 59;
  test_msg->sid.sat = 38;
  test_msg->sync_flags = 90;
  test_msg->tot.ns_residual = -811597120;
  test_msg->tot.tow = 1581737093;
  test_msg->tot.wn = 65492;
  test_msg->tow_flags = 219;
  test_msg->track_flags = 67;
  test_msg->uptime = 3263741727;

  EXPECT_EQ(send_message(0x21, 28315, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 28315);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->L.f, 204)
      << "incorrect value for L.f, expected 204, is " << last_msg_->L.f;
  EXPECT_EQ(last_msg_->L.i, -1601767965)
      << "incorrect value for L.i, expected -1601767965, is " << last_msg_->L.i;
  EXPECT_EQ(last_msg_->P, 1044286343)
      << "incorrect value for P, expected 1044286343, is " << last_msg_->P;
  EXPECT_EQ(last_msg_->P_std, 21427)
      << "incorrect value for P_std, expected 21427, is " << last_msg_->P_std;
  EXPECT_EQ(last_msg_->acceleration, -114)
      << "incorrect value for acceleration, expected -114, is "
      << last_msg_->acceleration;
  EXPECT_EQ(last_msg_->clock_drift, 23311)
      << "incorrect value for clock_drift, expected 23311, is "
      << last_msg_->clock_drift;
  EXPECT_EQ(last_msg_->clock_offset, 6012)
      << "incorrect value for clock_offset, expected 6012, is "
      << last_msg_->clock_offset;
  EXPECT_EQ(last_msg_->cn0, 78)
      << "incorrect value for cn0, expected 78, is " << last_msg_->cn0;
  EXPECT_EQ(last_msg_->corr_spacing, 30201)
      << "incorrect value for corr_spacing, expected 30201, is "
      << last_msg_->corr_spacing;
  EXPECT_EQ(last_msg_->doppler, 1459556257)
      << "incorrect value for doppler, expected 1459556257, is "
      << last_msg_->doppler;
  EXPECT_EQ(last_msg_->doppler_std, 63677)
      << "incorrect value for doppler_std, expected 63677, is "
      << last_msg_->doppler_std;
  EXPECT_EQ(last_msg_->lock, 65375)
      << "incorrect value for lock, expected 65375, is " << last_msg_->lock;
  EXPECT_EQ(last_msg_->misc_flags, 62)
      << "incorrect value for misc_flags, expected 62, is "
      << last_msg_->misc_flags;
  EXPECT_EQ(last_msg_->nav_flags, 25)
      << "incorrect value for nav_flags, expected 25, is "
      << last_msg_->nav_flags;
  EXPECT_EQ(last_msg_->pset_flags, 83)
      << "incorrect value for pset_flags, expected 83, is "
      << last_msg_->pset_flags;
  EXPECT_EQ(last_msg_->recv_time, 941247176494)
      << "incorrect value for recv_time, expected 941247176494, is "
      << last_msg_->recv_time;
  EXPECT_EQ(last_msg_->sid.code, 59)
      << "incorrect value for sid.code, expected 59, is "
      << last_msg_->sid.code;
  EXPECT_EQ(last_msg_->sid.sat, 38)
      << "incorrect value for sid.sat, expected 38, is " << last_msg_->sid.sat;
  EXPECT_EQ(last_msg_->sync_flags, 90)
      << "incorrect value for sync_flags, expected 90, is "
      << last_msg_->sync_flags;
  EXPECT_EQ(last_msg_->tot.ns_residual, -811597120)
      << "incorrect value for tot.ns_residual, expected -811597120, is "
      << last_msg_->tot.ns_residual;
  EXPECT_EQ(last_msg_->tot.tow, 1581737093)
      << "incorrect value for tot.tow, expected 1581737093, is "
      << last_msg_->tot.tow;
  EXPECT_EQ(last_msg_->tot.wn, 65492)
      << "incorrect value for tot.wn, expected 65492, is " << last_msg_->tot.wn;
  EXPECT_EQ(last_msg_->tow_flags, 219)
      << "incorrect value for tow_flags, expected 219, is "
      << last_msg_->tow_flags;
  EXPECT_EQ(last_msg_->track_flags, 67)
      << "incorrect value for track_flags, expected 67, is "
      << last_msg_->track_flags;
  EXPECT_EQ(last_msg_->uptime, 3263741727)
      << "incorrect value for uptime, expected 3263741727, is "
      << last_msg_->uptime;
}
