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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/legacy_state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/ssr.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClockDepA0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_orbit_clock_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClockDepA0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_orbit_clock_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_ssr_orbit_clock_dep_a_t *>(last_msg_storage_)),
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
                      const msg_ssr_orbit_clock_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_orbit_clock_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClockDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  220, 5,   33,  166, 47,  225, 114, 31,  189, 43,  30,  1,   30,
      194, 211, 193, 175, 161, 143, 254, 56,  63,  232, 7,   216, 69,  1,
      110, 165, 124, 196, 189, 27,  116, 88,  4,   61,  3,   151, 18,  171,
      147, 46,  198, 85,  243, 245, 225, 235, 123, 181, 210, 157, 252,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_orbit_clock_dep_a_t *test_msg =
      (msg_ssr_orbit_clock_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->along = 132661048;
  test_msg->c0 = -970026069;
  test_msg->c1 = -503975083;
  test_msg->c2 = -759858197;
  test_msg->cross = 1845577176;
  test_msg->dot_along = 72905755;
  test_msg->dot_cross = 311886653;
  test_msg->dot_radial = -1111196507;
  test_msg->iod = 193;
  test_msg->iod_ssr = 211;
  test_msg->radial = -24141393;
  test_msg->sid.code = 30;
  test_msg->sid.sat = 1;
  test_msg->time.tow = 3172954849;
  test_msg->time.wn = 7723;
  test_msg->update_interval = 194;

  EXPECT_EQ(send_message(0x5dc, 42529, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 42529);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->along)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->along)),
            132661048)
      << "incorrect value for along, expected 132661048, is "
      << last_msg_->along;
  EXPECT_EQ(get_as<decltype(last_msg_->c0)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->c0)),
            -970026069)
      << "incorrect value for c0, expected -970026069, is " << last_msg_->c0;
  EXPECT_EQ(get_as<decltype(last_msg_->c1)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->c1)),
            -503975083)
      << "incorrect value for c1, expected -503975083, is " << last_msg_->c1;
  EXPECT_EQ(get_as<decltype(last_msg_->c2)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->c2)),
            -759858197)
      << "incorrect value for c2, expected -759858197, is " << last_msg_->c2;
  EXPECT_EQ(get_as<decltype(last_msg_->cross)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->cross)),
            1845577176)
      << "incorrect value for cross, expected 1845577176, is "
      << last_msg_->cross;
  EXPECT_EQ(get_as<decltype(last_msg_->dot_along)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dot_along)),
            72905755)
      << "incorrect value for dot_along, expected 72905755, is "
      << last_msg_->dot_along;
  EXPECT_EQ(get_as<decltype(last_msg_->dot_cross)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dot_cross)),
            311886653)
      << "incorrect value for dot_cross, expected 311886653, is "
      << last_msg_->dot_cross;
  EXPECT_EQ(get_as<decltype(last_msg_->dot_radial)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dot_radial)),
            -1111196507)
      << "incorrect value for dot_radial, expected -1111196507, is "
      << last_msg_->dot_radial;
  EXPECT_EQ(get_as<decltype(last_msg_->iod)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->iod)),
            193)
      << "incorrect value for iod, expected 193, is " << last_msg_->iod;
  EXPECT_EQ(get_as<decltype(last_msg_->iod_ssr)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->iod_ssr)),
            211)
      << "incorrect value for iod_ssr, expected 211, is " << last_msg_->iod_ssr;
  EXPECT_EQ(get_as<decltype(last_msg_->radial)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->radial)),
            -24141393)
      << "incorrect value for radial, expected -24141393, is "
      << last_msg_->radial;
  EXPECT_EQ(get_as<decltype(last_msg_->sid.code)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sid.code)),
            30)
      << "incorrect value for sid.code, expected 30, is "
      << last_msg_->sid.code;
  EXPECT_EQ(get_as<decltype(last_msg_->sid.sat)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sid.sat)),
            1)
      << "incorrect value for sid.sat, expected 1, is " << last_msg_->sid.sat;
  EXPECT_EQ(get_as<decltype(last_msg_->time.tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->time.tow)),
            3172954849)
      << "incorrect value for time.tow, expected 3172954849, is "
      << last_msg_->time.tow;
  EXPECT_EQ(get_as<decltype(last_msg_->time.wn)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->time.wn)),
            7723)
      << "incorrect value for time.wn, expected 7723, is "
      << last_msg_->time.wn;
  EXPECT_EQ(get_as<decltype(last_msg_->update_interval)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->update_interval)),
            194)
      << "incorrect value for update_interval, expected 194, is "
      << last_msg_->update_interval;
}
