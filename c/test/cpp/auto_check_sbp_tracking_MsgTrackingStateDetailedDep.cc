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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDep.yaml
// by generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t> {
 public:
  Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>(this),
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
      const sbp_msg_tracking_state_detailed_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_detailed_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep0, Test) {
  uint8_t encoded_frame[] = {
      85,  17, 0,  59, 103, 55, 163, 151, 112, 215, 1,  0, 0, 0,   0,   0,
      0,   0,  0,  0,  0,   0,  0,   0,   0,   0,   39, 5, 0, 0,   169, 177,
      208, 54, 15, 0,  0,   0,  85,  61,  0,   0,   39, 0, 1, 0,   0,   0,
      0,   0,  0,  0,  40,  0,  108, 1,   0,   11,  0,  0, 9, 166, 214,
  };

  sbp_msg_tracking_state_detailed_dep_t test_msg{};
  test_msg.L.f = 169;
  test_msg.L.i = 1319;
  test_msg.P = 0;
  test_msg.P_std = 0;
  test_msg.acceleration = 108;
  test_msg.clock_drift = 0;
  test_msg.clock_offset = 0;
  test_msg.cn0 = 177;
  test_msg.corr_spacing = 40;
  test_msg.doppler = 15701;
  test_msg.doppler_std = 39;
  test_msg.lock = 14032;
  test_msg.misc_flags = 9;
  test_msg.nav_flags = 0;
  test_msg.pset_flags = 0;
  test_msg.recv_time = 7909447587;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 15;
  test_msg.sync_flags = 1;
  test_msg.tot.tow = 0;
  test_msg.tot.wn = 0;
  test_msg.tow_flags = 0;
  test_msg.track_flags = 11;
  test_msg.uptime = 1;

  EXPECT_EQ(send_message(26427, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 26427);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.L.f, 169)
      << "incorrect value for last_msg_.L.f, expected 169, is "
      << last_msg_.L.f;
  EXPECT_EQ(last_msg_.L.i, 1319)
      << "incorrect value for last_msg_.L.i, expected 1319, is "
      << last_msg_.L.i;
  EXPECT_EQ(last_msg_.P, 0)
      << "incorrect value for last_msg_.P, expected 0, is " << last_msg_.P;
  EXPECT_EQ(last_msg_.P_std, 0)
      << "incorrect value for last_msg_.P_std, expected 0, is "
      << last_msg_.P_std;
  EXPECT_EQ(last_msg_.acceleration, 108)
      << "incorrect value for last_msg_.acceleration, expected 108, is "
      << last_msg_.acceleration;
  EXPECT_EQ(last_msg_.clock_drift, 0)
      << "incorrect value for last_msg_.clock_drift, expected 0, is "
      << last_msg_.clock_drift;
  EXPECT_EQ(last_msg_.clock_offset, 0)
      << "incorrect value for last_msg_.clock_offset, expected 0, is "
      << last_msg_.clock_offset;
  EXPECT_EQ(last_msg_.cn0, 177)
      << "incorrect value for last_msg_.cn0, expected 177, is "
      << last_msg_.cn0;
  EXPECT_EQ(last_msg_.corr_spacing, 40)
      << "incorrect value for last_msg_.corr_spacing, expected 40, is "
      << last_msg_.corr_spacing;
  EXPECT_EQ(last_msg_.doppler, 15701)
      << "incorrect value for last_msg_.doppler, expected 15701, is "
      << last_msg_.doppler;
  EXPECT_EQ(last_msg_.doppler_std, 39)
      << "incorrect value for last_msg_.doppler_std, expected 39, is "
      << last_msg_.doppler_std;
  EXPECT_EQ(last_msg_.lock, 14032)
      << "incorrect value for last_msg_.lock, expected 14032, is "
      << last_msg_.lock;
  EXPECT_EQ(last_msg_.misc_flags, 9)
      << "incorrect value for last_msg_.misc_flags, expected 9, is "
      << last_msg_.misc_flags;
  EXPECT_EQ(last_msg_.nav_flags, 0)
      << "incorrect value for last_msg_.nav_flags, expected 0, is "
      << last_msg_.nav_flags;
  EXPECT_EQ(last_msg_.pset_flags, 0)
      << "incorrect value for last_msg_.pset_flags, expected 0, is "
      << last_msg_.pset_flags;
  EXPECT_EQ(last_msg_.recv_time, 7909447587)
      << "incorrect value for last_msg_.recv_time, expected 7909447587, is "
      << last_msg_.recv_time;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 15)
      << "incorrect value for last_msg_.sid.sat, expected 15, is "
      << last_msg_.sid.sat;
  EXPECT_EQ(last_msg_.sync_flags, 1)
      << "incorrect value for last_msg_.sync_flags, expected 1, is "
      << last_msg_.sync_flags;
  EXPECT_EQ(last_msg_.tot.tow, 0)
      << "incorrect value for last_msg_.tot.tow, expected 0, is "
      << last_msg_.tot.tow;
  EXPECT_EQ(last_msg_.tot.wn, 0)
      << "incorrect value for last_msg_.tot.wn, expected 0, is "
      << last_msg_.tot.wn;
  EXPECT_EQ(last_msg_.tow_flags, 0)
      << "incorrect value for last_msg_.tow_flags, expected 0, is "
      << last_msg_.tow_flags;
  EXPECT_EQ(last_msg_.track_flags, 11)
      << "incorrect value for last_msg_.track_flags, expected 11, is "
      << last_msg_.track_flags;
  EXPECT_EQ(last_msg_.uptime, 1)
      << "incorrect value for last_msg_.uptime, expected 1, is "
      << last_msg_.uptime;
}
class Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t> {
 public:
  Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>(this),
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
      const sbp_msg_tracking_state_detailed_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_detailed_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep1, Test) {
  uint8_t encoded_frame[] = {
      85,  17, 0,  59, 103, 55, 97,  251, 61, 245, 1,  0, 0, 0,   0,   0,
      0,   0,  0,  0,  0,   0,  0,   0,   0,  0,   18, 7, 0, 0,   14,  175,
      208, 54, 15, 0,  0,   0,  51,  61,  0,  0,   30, 0, 1, 0,   0,   0,
      0,   0,  0,  0,  40,  0,  224, 1,   0,  11,  0,  0, 9, 136, 179,
  };

  sbp_msg_tracking_state_detailed_dep_t test_msg{};
  test_msg.L.f = 14;
  test_msg.L.i = 1810;
  test_msg.P = 0;
  test_msg.P_std = 0;
  test_msg.acceleration = -32;
  test_msg.clock_drift = 0;
  test_msg.clock_offset = 0;
  test_msg.cn0 = 175;
  test_msg.corr_spacing = 40;
  test_msg.doppler = 15667;
  test_msg.doppler_std = 30;
  test_msg.lock = 14032;
  test_msg.misc_flags = 9;
  test_msg.nav_flags = 0;
  test_msg.pset_flags = 0;
  test_msg.recv_time = 8409447265;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 15;
  test_msg.sync_flags = 1;
  test_msg.tot.tow = 0;
  test_msg.tot.wn = 0;
  test_msg.tow_flags = 0;
  test_msg.track_flags = 11;
  test_msg.uptime = 1;

  EXPECT_EQ(send_message(26427, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 26427);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.L.f, 14)
      << "incorrect value for last_msg_.L.f, expected 14, is " << last_msg_.L.f;
  EXPECT_EQ(last_msg_.L.i, 1810)
      << "incorrect value for last_msg_.L.i, expected 1810, is "
      << last_msg_.L.i;
  EXPECT_EQ(last_msg_.P, 0)
      << "incorrect value for last_msg_.P, expected 0, is " << last_msg_.P;
  EXPECT_EQ(last_msg_.P_std, 0)
      << "incorrect value for last_msg_.P_std, expected 0, is "
      << last_msg_.P_std;
  EXPECT_EQ(last_msg_.acceleration, -32)
      << "incorrect value for last_msg_.acceleration, expected -32, is "
      << last_msg_.acceleration;
  EXPECT_EQ(last_msg_.clock_drift, 0)
      << "incorrect value for last_msg_.clock_drift, expected 0, is "
      << last_msg_.clock_drift;
  EXPECT_EQ(last_msg_.clock_offset, 0)
      << "incorrect value for last_msg_.clock_offset, expected 0, is "
      << last_msg_.clock_offset;
  EXPECT_EQ(last_msg_.cn0, 175)
      << "incorrect value for last_msg_.cn0, expected 175, is "
      << last_msg_.cn0;
  EXPECT_EQ(last_msg_.corr_spacing, 40)
      << "incorrect value for last_msg_.corr_spacing, expected 40, is "
      << last_msg_.corr_spacing;
  EXPECT_EQ(last_msg_.doppler, 15667)
      << "incorrect value for last_msg_.doppler, expected 15667, is "
      << last_msg_.doppler;
  EXPECT_EQ(last_msg_.doppler_std, 30)
      << "incorrect value for last_msg_.doppler_std, expected 30, is "
      << last_msg_.doppler_std;
  EXPECT_EQ(last_msg_.lock, 14032)
      << "incorrect value for last_msg_.lock, expected 14032, is "
      << last_msg_.lock;
  EXPECT_EQ(last_msg_.misc_flags, 9)
      << "incorrect value for last_msg_.misc_flags, expected 9, is "
      << last_msg_.misc_flags;
  EXPECT_EQ(last_msg_.nav_flags, 0)
      << "incorrect value for last_msg_.nav_flags, expected 0, is "
      << last_msg_.nav_flags;
  EXPECT_EQ(last_msg_.pset_flags, 0)
      << "incorrect value for last_msg_.pset_flags, expected 0, is "
      << last_msg_.pset_flags;
  EXPECT_EQ(last_msg_.recv_time, 8409447265)
      << "incorrect value for last_msg_.recv_time, expected 8409447265, is "
      << last_msg_.recv_time;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 15)
      << "incorrect value for last_msg_.sid.sat, expected 15, is "
      << last_msg_.sid.sat;
  EXPECT_EQ(last_msg_.sync_flags, 1)
      << "incorrect value for last_msg_.sync_flags, expected 1, is "
      << last_msg_.sync_flags;
  EXPECT_EQ(last_msg_.tot.tow, 0)
      << "incorrect value for last_msg_.tot.tow, expected 0, is "
      << last_msg_.tot.tow;
  EXPECT_EQ(last_msg_.tot.wn, 0)
      << "incorrect value for last_msg_.tot.wn, expected 0, is "
      << last_msg_.tot.wn;
  EXPECT_EQ(last_msg_.tow_flags, 0)
      << "incorrect value for last_msg_.tow_flags, expected 0, is "
      << last_msg_.tow_flags;
  EXPECT_EQ(last_msg_.track_flags, 11)
      << "incorrect value for last_msg_.track_flags, expected 11, is "
      << last_msg_.track_flags;
  EXPECT_EQ(last_msg_.uptime, 1)
      << "incorrect value for last_msg_.uptime, expected 1, is "
      << last_msg_.uptime;
}
class Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t> {
 public:
  Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>(this),
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
      const sbp_msg_tracking_state_detailed_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_detailed_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep2, Test) {
  uint8_t encoded_frame[] = {
      85,  17, 0,  59, 103, 55, 139, 218, 236, 18, 2,   0, 0, 0,   0,   0,
      0,   0,  0,  0,  0,   0,  0,   0,   0,   0,  250, 8, 0, 0,   8,   179,
      208, 54, 15, 0,  0,   0,  67,  61,  0,   0,  22,  0, 2, 0,   0,   0,
      0,   0,  0,  0,  40,  0,  27,  1,   0,   11, 0,   2, 9, 217, 159,
  };

  sbp_msg_tracking_state_detailed_dep_t test_msg{};
  test_msg.L.f = 8;
  test_msg.L.i = 2298;
  test_msg.P = 0;
  test_msg.P_std = 0;
  test_msg.acceleration = 27;
  test_msg.clock_drift = 0;
  test_msg.clock_offset = 0;
  test_msg.cn0 = 179;
  test_msg.corr_spacing = 40;
  test_msg.doppler = 15683;
  test_msg.doppler_std = 22;
  test_msg.lock = 14032;
  test_msg.misc_flags = 9;
  test_msg.nav_flags = 0;
  test_msg.pset_flags = 2;
  test_msg.recv_time = 8907446923;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 15;
  test_msg.sync_flags = 1;
  test_msg.tot.tow = 0;
  test_msg.tot.wn = 0;
  test_msg.tow_flags = 0;
  test_msg.track_flags = 11;
  test_msg.uptime = 2;

  EXPECT_EQ(send_message(26427, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 26427);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.L.f, 8)
      << "incorrect value for last_msg_.L.f, expected 8, is " << last_msg_.L.f;
  EXPECT_EQ(last_msg_.L.i, 2298)
      << "incorrect value for last_msg_.L.i, expected 2298, is "
      << last_msg_.L.i;
  EXPECT_EQ(last_msg_.P, 0)
      << "incorrect value for last_msg_.P, expected 0, is " << last_msg_.P;
  EXPECT_EQ(last_msg_.P_std, 0)
      << "incorrect value for last_msg_.P_std, expected 0, is "
      << last_msg_.P_std;
  EXPECT_EQ(last_msg_.acceleration, 27)
      << "incorrect value for last_msg_.acceleration, expected 27, is "
      << last_msg_.acceleration;
  EXPECT_EQ(last_msg_.clock_drift, 0)
      << "incorrect value for last_msg_.clock_drift, expected 0, is "
      << last_msg_.clock_drift;
  EXPECT_EQ(last_msg_.clock_offset, 0)
      << "incorrect value for last_msg_.clock_offset, expected 0, is "
      << last_msg_.clock_offset;
  EXPECT_EQ(last_msg_.cn0, 179)
      << "incorrect value for last_msg_.cn0, expected 179, is "
      << last_msg_.cn0;
  EXPECT_EQ(last_msg_.corr_spacing, 40)
      << "incorrect value for last_msg_.corr_spacing, expected 40, is "
      << last_msg_.corr_spacing;
  EXPECT_EQ(last_msg_.doppler, 15683)
      << "incorrect value for last_msg_.doppler, expected 15683, is "
      << last_msg_.doppler;
  EXPECT_EQ(last_msg_.doppler_std, 22)
      << "incorrect value for last_msg_.doppler_std, expected 22, is "
      << last_msg_.doppler_std;
  EXPECT_EQ(last_msg_.lock, 14032)
      << "incorrect value for last_msg_.lock, expected 14032, is "
      << last_msg_.lock;
  EXPECT_EQ(last_msg_.misc_flags, 9)
      << "incorrect value for last_msg_.misc_flags, expected 9, is "
      << last_msg_.misc_flags;
  EXPECT_EQ(last_msg_.nav_flags, 0)
      << "incorrect value for last_msg_.nav_flags, expected 0, is "
      << last_msg_.nav_flags;
  EXPECT_EQ(last_msg_.pset_flags, 2)
      << "incorrect value for last_msg_.pset_flags, expected 2, is "
      << last_msg_.pset_flags;
  EXPECT_EQ(last_msg_.recv_time, 8907446923)
      << "incorrect value for last_msg_.recv_time, expected 8907446923, is "
      << last_msg_.recv_time;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 15)
      << "incorrect value for last_msg_.sid.sat, expected 15, is "
      << last_msg_.sid.sat;
  EXPECT_EQ(last_msg_.sync_flags, 1)
      << "incorrect value for last_msg_.sync_flags, expected 1, is "
      << last_msg_.sync_flags;
  EXPECT_EQ(last_msg_.tot.tow, 0)
      << "incorrect value for last_msg_.tot.tow, expected 0, is "
      << last_msg_.tot.tow;
  EXPECT_EQ(last_msg_.tot.wn, 0)
      << "incorrect value for last_msg_.tot.wn, expected 0, is "
      << last_msg_.tot.wn;
  EXPECT_EQ(last_msg_.tow_flags, 0)
      << "incorrect value for last_msg_.tow_flags, expected 0, is "
      << last_msg_.tow_flags;
  EXPECT_EQ(last_msg_.track_flags, 11)
      << "incorrect value for last_msg_.track_flags, expected 11, is "
      << last_msg_.track_flags;
  EXPECT_EQ(last_msg_.uptime, 2)
      << "incorrect value for last_msg_.uptime, expected 2, is "
      << last_msg_.uptime;
}
class Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t> {
 public:
  Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>(this),
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
      const sbp_msg_tracking_state_detailed_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_detailed_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep3, Test) {
  uint8_t encoded_frame[] = {
      85,  17, 0,  59, 103, 55, 255, 251, 170, 48, 2,   0,  0, 0,  0,   0,
      0,   0,  0,  0,  0,   0,  0,   0,   0,   0,  226, 10, 0, 0,  125, 181,
      208, 54, 15, 0,  0,   0,  29,  61,  0,   0,  10,  0,  2, 0,  0,   0,
      0,   0,  0,  0,  40,  0,  220, 1,   0,   11, 0,   3,  9, 66, 95,
  };

  sbp_msg_tracking_state_detailed_dep_t test_msg{};
  test_msg.L.f = 125;
  test_msg.L.i = 2786;
  test_msg.P = 0;
  test_msg.P_std = 0;
  test_msg.acceleration = -36;
  test_msg.clock_drift = 0;
  test_msg.clock_offset = 0;
  test_msg.cn0 = 181;
  test_msg.corr_spacing = 40;
  test_msg.doppler = 15645;
  test_msg.doppler_std = 10;
  test_msg.lock = 14032;
  test_msg.misc_flags = 9;
  test_msg.nav_flags = 0;
  test_msg.pset_flags = 3;
  test_msg.recv_time = 9406446591;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 15;
  test_msg.sync_flags = 1;
  test_msg.tot.tow = 0;
  test_msg.tot.wn = 0;
  test_msg.tow_flags = 0;
  test_msg.track_flags = 11;
  test_msg.uptime = 2;

  EXPECT_EQ(send_message(26427, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 26427);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.L.f, 125)
      << "incorrect value for last_msg_.L.f, expected 125, is "
      << last_msg_.L.f;
  EXPECT_EQ(last_msg_.L.i, 2786)
      << "incorrect value for last_msg_.L.i, expected 2786, is "
      << last_msg_.L.i;
  EXPECT_EQ(last_msg_.P, 0)
      << "incorrect value for last_msg_.P, expected 0, is " << last_msg_.P;
  EXPECT_EQ(last_msg_.P_std, 0)
      << "incorrect value for last_msg_.P_std, expected 0, is "
      << last_msg_.P_std;
  EXPECT_EQ(last_msg_.acceleration, -36)
      << "incorrect value for last_msg_.acceleration, expected -36, is "
      << last_msg_.acceleration;
  EXPECT_EQ(last_msg_.clock_drift, 0)
      << "incorrect value for last_msg_.clock_drift, expected 0, is "
      << last_msg_.clock_drift;
  EXPECT_EQ(last_msg_.clock_offset, 0)
      << "incorrect value for last_msg_.clock_offset, expected 0, is "
      << last_msg_.clock_offset;
  EXPECT_EQ(last_msg_.cn0, 181)
      << "incorrect value for last_msg_.cn0, expected 181, is "
      << last_msg_.cn0;
  EXPECT_EQ(last_msg_.corr_spacing, 40)
      << "incorrect value for last_msg_.corr_spacing, expected 40, is "
      << last_msg_.corr_spacing;
  EXPECT_EQ(last_msg_.doppler, 15645)
      << "incorrect value for last_msg_.doppler, expected 15645, is "
      << last_msg_.doppler;
  EXPECT_EQ(last_msg_.doppler_std, 10)
      << "incorrect value for last_msg_.doppler_std, expected 10, is "
      << last_msg_.doppler_std;
  EXPECT_EQ(last_msg_.lock, 14032)
      << "incorrect value for last_msg_.lock, expected 14032, is "
      << last_msg_.lock;
  EXPECT_EQ(last_msg_.misc_flags, 9)
      << "incorrect value for last_msg_.misc_flags, expected 9, is "
      << last_msg_.misc_flags;
  EXPECT_EQ(last_msg_.nav_flags, 0)
      << "incorrect value for last_msg_.nav_flags, expected 0, is "
      << last_msg_.nav_flags;
  EXPECT_EQ(last_msg_.pset_flags, 3)
      << "incorrect value for last_msg_.pset_flags, expected 3, is "
      << last_msg_.pset_flags;
  EXPECT_EQ(last_msg_.recv_time, 9406446591)
      << "incorrect value for last_msg_.recv_time, expected 9406446591, is "
      << last_msg_.recv_time;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 15)
      << "incorrect value for last_msg_.sid.sat, expected 15, is "
      << last_msg_.sid.sat;
  EXPECT_EQ(last_msg_.sync_flags, 1)
      << "incorrect value for last_msg_.sync_flags, expected 1, is "
      << last_msg_.sync_flags;
  EXPECT_EQ(last_msg_.tot.tow, 0)
      << "incorrect value for last_msg_.tot.tow, expected 0, is "
      << last_msg_.tot.tow;
  EXPECT_EQ(last_msg_.tot.wn, 0)
      << "incorrect value for last_msg_.tot.wn, expected 0, is "
      << last_msg_.tot.wn;
  EXPECT_EQ(last_msg_.tow_flags, 0)
      << "incorrect value for last_msg_.tow_flags, expected 0, is "
      << last_msg_.tow_flags;
  EXPECT_EQ(last_msg_.track_flags, 11)
      << "incorrect value for last_msg_.track_flags, expected 11, is "
      << last_msg_.track_flags;
  EXPECT_EQ(last_msg_.uptime, 2)
      << "incorrect value for last_msg_.uptime, expected 2, is "
      << last_msg_.uptime;
}
class Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t> {
 public:
  Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>(this),
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
      const sbp_msg_tracking_state_detailed_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_detailed_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep4, Test) {
  uint8_t encoded_frame[] = {
      85,  17, 0,  59, 103, 55, 189, 95, 120, 78, 2,   0,  0, 0,   0,   0,
      0,   0,  0,  0,  0,   0,  0,   0,  0,   0,  203, 12, 0, 0,   64,  184,
      208, 54, 15, 0,  0,   0,  24,  61, 0,   0,  4,   0,  3, 0,   0,   0,
      0,   0,  0,  0,  40,  0,  2,   1,  0,   11, 0,   3,  9, 194, 206,
  };

  sbp_msg_tracking_state_detailed_dep_t test_msg{};
  test_msg.L.f = 64;
  test_msg.L.i = 3275;
  test_msg.P = 0;
  test_msg.P_std = 0;
  test_msg.acceleration = 2;
  test_msg.clock_drift = 0;
  test_msg.clock_offset = 0;
  test_msg.cn0 = 184;
  test_msg.corr_spacing = 40;
  test_msg.doppler = 15640;
  test_msg.doppler_std = 4;
  test_msg.lock = 14032;
  test_msg.misc_flags = 9;
  test_msg.nav_flags = 0;
  test_msg.pset_flags = 3;
  test_msg.recv_time = 9906446269;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 15;
  test_msg.sync_flags = 1;
  test_msg.tot.tow = 0;
  test_msg.tot.wn = 0;
  test_msg.tow_flags = 0;
  test_msg.track_flags = 11;
  test_msg.uptime = 3;

  EXPECT_EQ(send_message(26427, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 26427);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.L.f, 64)
      << "incorrect value for last_msg_.L.f, expected 64, is " << last_msg_.L.f;
  EXPECT_EQ(last_msg_.L.i, 3275)
      << "incorrect value for last_msg_.L.i, expected 3275, is "
      << last_msg_.L.i;
  EXPECT_EQ(last_msg_.P, 0)
      << "incorrect value for last_msg_.P, expected 0, is " << last_msg_.P;
  EXPECT_EQ(last_msg_.P_std, 0)
      << "incorrect value for last_msg_.P_std, expected 0, is "
      << last_msg_.P_std;
  EXPECT_EQ(last_msg_.acceleration, 2)
      << "incorrect value for last_msg_.acceleration, expected 2, is "
      << last_msg_.acceleration;
  EXPECT_EQ(last_msg_.clock_drift, 0)
      << "incorrect value for last_msg_.clock_drift, expected 0, is "
      << last_msg_.clock_drift;
  EXPECT_EQ(last_msg_.clock_offset, 0)
      << "incorrect value for last_msg_.clock_offset, expected 0, is "
      << last_msg_.clock_offset;
  EXPECT_EQ(last_msg_.cn0, 184)
      << "incorrect value for last_msg_.cn0, expected 184, is "
      << last_msg_.cn0;
  EXPECT_EQ(last_msg_.corr_spacing, 40)
      << "incorrect value for last_msg_.corr_spacing, expected 40, is "
      << last_msg_.corr_spacing;
  EXPECT_EQ(last_msg_.doppler, 15640)
      << "incorrect value for last_msg_.doppler, expected 15640, is "
      << last_msg_.doppler;
  EXPECT_EQ(last_msg_.doppler_std, 4)
      << "incorrect value for last_msg_.doppler_std, expected 4, is "
      << last_msg_.doppler_std;
  EXPECT_EQ(last_msg_.lock, 14032)
      << "incorrect value for last_msg_.lock, expected 14032, is "
      << last_msg_.lock;
  EXPECT_EQ(last_msg_.misc_flags, 9)
      << "incorrect value for last_msg_.misc_flags, expected 9, is "
      << last_msg_.misc_flags;
  EXPECT_EQ(last_msg_.nav_flags, 0)
      << "incorrect value for last_msg_.nav_flags, expected 0, is "
      << last_msg_.nav_flags;
  EXPECT_EQ(last_msg_.pset_flags, 3)
      << "incorrect value for last_msg_.pset_flags, expected 3, is "
      << last_msg_.pset_flags;
  EXPECT_EQ(last_msg_.recv_time, 9906446269)
      << "incorrect value for last_msg_.recv_time, expected 9906446269, is "
      << last_msg_.recv_time;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 15)
      << "incorrect value for last_msg_.sid.sat, expected 15, is "
      << last_msg_.sid.sat;
  EXPECT_EQ(last_msg_.sync_flags, 1)
      << "incorrect value for last_msg_.sync_flags, expected 1, is "
      << last_msg_.sync_flags;
  EXPECT_EQ(last_msg_.tot.tow, 0)
      << "incorrect value for last_msg_.tot.tow, expected 0, is "
      << last_msg_.tot.tow;
  EXPECT_EQ(last_msg_.tot.wn, 0)
      << "incorrect value for last_msg_.tot.wn, expected 0, is "
      << last_msg_.tot.wn;
  EXPECT_EQ(last_msg_.tow_flags, 0)
      << "incorrect value for last_msg_.tow_flags, expected 0, is "
      << last_msg_.tow_flags;
  EXPECT_EQ(last_msg_.track_flags, 11)
      << "incorrect value for last_msg_.track_flags, expected 11, is "
      << last_msg_.track_flags;
  EXPECT_EQ(last_msg_.uptime, 3)
      << "incorrect value for last_msg_.uptime, expected 3, is "
      << last_msg_.uptime;
}
