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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClock.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>
#include <libsbp/cpp/state.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/ssr.h>
class Test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClock0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_orbit_clock_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClock0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_orbit_clock_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ssr_orbit_clock_t *>(last_msg_storage_)),
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
                      const msg_ssr_orbit_clock_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_orbit_clock_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClock0, Test) {
  uint8_t encoded_frame[] = {
      85,  221, 5,   53,  229, 50,  83,  208, 102, 207, 164, 29,  203, 212, 236,
      255, 152, 233, 207, 55,  94,  54,  58,  128, 68,  27,  117, 176, 110, 251,
      61,  244, 122, 50,  95,  52,  144, 232, 24,  10,  37,  127, 163, 66,  177,
      105, 156, 245, 10,  249, 107, 218, 17,  186, 56,  72,  14,  22,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_orbit_clock_t *test_msg = (msg_ssr_orbit_clock_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->along = -1334502588;
  test_msg->c0 = -174298703;
  test_msg->c1 = -630458102;
  test_msg->c2 = 1211677201;
  test_msg->cross = -197264530;
  test_msg->dot_along = 169404560;
  test_msg->dot_cross = 1118011173;
  test_msg->dot_radial = 878654074;
  test_msg->iod = 936372632;
  test_msg->iod_ssr = 255;
  test_msg->radial = -2143668642;
  test_msg->sid.code = 212;
  test_msg->sid.sat = 203;
  test_msg->time.tow = 3479621715;
  test_msg->time.wn = 7588;
  test_msg->update_interval = 236;

  EXPECT_EQ(send_message(0x5dd, 58677, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 58677);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->along, -1334502588)
      << "incorrect value for along, expected -1334502588, is "
      << last_msg_->along;
  EXPECT_EQ(last_msg_->c0, -174298703)
      << "incorrect value for c0, expected -174298703, is " << last_msg_->c0;
  EXPECT_EQ(last_msg_->c1, -630458102)
      << "incorrect value for c1, expected -630458102, is " << last_msg_->c1;
  EXPECT_EQ(last_msg_->c2, 1211677201)
      << "incorrect value for c2, expected 1211677201, is " << last_msg_->c2;
  EXPECT_EQ(last_msg_->cross, -197264530)
      << "incorrect value for cross, expected -197264530, is "
      << last_msg_->cross;
  EXPECT_EQ(last_msg_->dot_along, 169404560)
      << "incorrect value for dot_along, expected 169404560, is "
      << last_msg_->dot_along;
  EXPECT_EQ(last_msg_->dot_cross, 1118011173)
      << "incorrect value for dot_cross, expected 1118011173, is "
      << last_msg_->dot_cross;
  EXPECT_EQ(last_msg_->dot_radial, 878654074)
      << "incorrect value for dot_radial, expected 878654074, is "
      << last_msg_->dot_radial;
  EXPECT_EQ(last_msg_->iod, 936372632)
      << "incorrect value for iod, expected 936372632, is " << last_msg_->iod;
  EXPECT_EQ(last_msg_->iod_ssr, 255)
      << "incorrect value for iod_ssr, expected 255, is " << last_msg_->iod_ssr;
  EXPECT_EQ(last_msg_->radial, -2143668642)
      << "incorrect value for radial, expected -2143668642, is "
      << last_msg_->radial;
  EXPECT_EQ(last_msg_->sid.code, 212)
      << "incorrect value for sid.code, expected 212, is "
      << last_msg_->sid.code;
  EXPECT_EQ(last_msg_->sid.sat, 203)
      << "incorrect value for sid.sat, expected 203, is " << last_msg_->sid.sat;
  EXPECT_EQ(last_msg_->time.tow, 3479621715)
      << "incorrect value for time.tow, expected 3479621715, is "
      << last_msg_->time.tow;
  EXPECT_EQ(last_msg_->time.wn, 7588)
      << "incorrect value for time.wn, expected 7588, is "
      << last_msg_->time.wn;
  EXPECT_EQ(last_msg_->update_interval, 236)
      << "incorrect value for update_interval, expected 236, is "
      << last_msg_->update_interval;
}
