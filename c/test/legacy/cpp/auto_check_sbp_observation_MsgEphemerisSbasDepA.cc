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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisSbasDepA.yaml by
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
#include <libsbp/legacy/observation.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_observation_MsgEphemerisSbasDepA0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ephemeris_sbas_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgEphemerisSbasDepA0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ephemeris_sbas_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_ephemeris_sbas_dep_a_t *>(last_msg_storage_)),
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
                      const msg_ephemeris_sbas_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ephemeris_sbas_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgEphemerisSbasDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  130, 0,   123, 0,   112, 22,  0,   6,   0,   176, 207, 6,   0,   106,
      8,   0,   0,   0,   0,   0,   0,   0,   64,  0,   0,   0,   0,   1,   0,
      0,   0,   128, 66,  246, 57,  103, 193, 0,   0,   0,   34,  170, 78,  34,
      65,  0,   0,   240, 199, 84,  86,  117, 193, 0,   0,   0,   98,  6,   250,
      154, 192, 0,   0,   0,   217, 58,  221, 163, 192, 0,   0,   0,   184, 138,
      46,  139, 64,  0,   0,   0,   0,   0,   64,  175, 62,  0,   0,   0,   0,
      0,   64,  175, 62,  0,   0,   0,   0,   0,   112, 199, 62,  0,   0,   0,
      0,   108, 177, 68,  191, 0,   0,   0,   0,   0,   192, 163, 61,  178, 180,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ephemeris_sbas_dep_a_t *test_msg =
      (msg_ephemeris_sbas_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->a_gf0 = -0.0006315018981695175;
  test_msg->a_gf1 = 8.981260180007666e-12;
  if (sizeof(test_msg->acc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->acc[0]));
  }
  test_msg->acc[0] = 9.313225746154785e-07;
  if (sizeof(test_msg->acc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->acc[0]));
  }
  test_msg->acc[1] = 9.313225746154785e-07;
  if (sizeof(test_msg->acc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->acc[0]));
  }
  test_msg->acc[2] = 2.7939677238464355e-06;
  test_msg->common.fit_interval = 0;
  test_msg->common.health_bits = 0;
  test_msg->common.sid.code = 6;
  test_msg->common.sid.reserved = 0;
  test_msg->common.sid.sat = 22;
  test_msg->common.toe.tow = 446384;
  test_msg->common.toe.wn = 2154;
  test_msg->common.ura = 2.0;
  test_msg->common.valid = 1;
  if (sizeof(test_msg->pos) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->pos[0]));
  }
  test_msg->pos[0] = -12177330.078125;
  if (sizeof(test_msg->pos) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->pos[0]));
  }
  test_msg->pos[1] = 599893.06640625;
  if (sizeof(test_msg->pos) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->pos[0]));
  }
  test_msg->pos[2] = -22373708.49609375;
  if (sizeof(test_msg->vel) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->vel[0]));
  }
  test_msg->vel[0] = -1726.506233215332;
  if (sizeof(test_msg->vel) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->vel[0]));
  }
  test_msg->vel[1] = -2542.6149368286133;
  if (sizeof(test_msg->vel) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->vel[0]));
  }
  test_msg->vel[2] = 869.8177337646484;

  EXPECT_EQ(send_message(0x82, 123, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 123);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->a_gf0 * 100 - -0.00063150189817 * 100), 0.05)
      << "incorrect value for a_gf0, expected -0.00063150189817, is "
      << last_msg_->a_gf0;
  EXPECT_LT((last_msg_->a_gf1 * 100 - 8.98126018001e-12 * 100), 0.05)
      << "incorrect value for a_gf1, expected 8.98126018001e-12, is "
      << last_msg_->a_gf1;
  EXPECT_LT((last_msg_->acc[0] * 100 - 9.31322574615e-07 * 100), 0.05)
      << "incorrect value for acc[0], expected 9.31322574615e-07, is "
      << last_msg_->acc[0];
  EXPECT_LT((last_msg_->acc[1] * 100 - 9.31322574615e-07 * 100), 0.05)
      << "incorrect value for acc[1], expected 9.31322574615e-07, is "
      << last_msg_->acc[1];
  EXPECT_LT((last_msg_->acc[2] * 100 - 2.79396772385e-06 * 100), 0.05)
      << "incorrect value for acc[2], expected 2.79396772385e-06, is "
      << last_msg_->acc[2];
  EXPECT_EQ(
      get_as<decltype(last_msg_->common.fit_interval)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->common.fit_interval)),
      0)
      << "incorrect value for common.fit_interval, expected 0, is "
      << last_msg_->common.fit_interval;
  EXPECT_EQ(
      get_as<decltype(last_msg_->common.health_bits)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->common.health_bits)),
      0)
      << "incorrect value for common.health_bits, expected 0, is "
      << last_msg_->common.health_bits;
  EXPECT_EQ(get_as<decltype(last_msg_->common.sid.code)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->common.sid.code)),
            6)
      << "incorrect value for common.sid.code, expected 6, is "
      << last_msg_->common.sid.code;
  EXPECT_EQ(
      get_as<decltype(last_msg_->common.sid.reserved)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->common.sid.reserved)),
      0)
      << "incorrect value for common.sid.reserved, expected 0, is "
      << last_msg_->common.sid.reserved;
  EXPECT_EQ(get_as<decltype(last_msg_->common.sid.sat)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->common.sid.sat)),
            22)
      << "incorrect value for common.sid.sat, expected 22, is "
      << last_msg_->common.sid.sat;
  EXPECT_EQ(get_as<decltype(last_msg_->common.toe.tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->common.toe.tow)),
            446384)
      << "incorrect value for common.toe.tow, expected 446384, is "
      << last_msg_->common.toe.tow;
  EXPECT_EQ(get_as<decltype(last_msg_->common.toe.wn)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->common.toe.wn)),
            2154)
      << "incorrect value for common.toe.wn, expected 2154, is "
      << last_msg_->common.toe.wn;
  EXPECT_LT((last_msg_->common.ura * 100 - 2.0 * 100), 0.05)
      << "incorrect value for common.ura, expected 2.0, is "
      << last_msg_->common.ura;
  EXPECT_EQ(get_as<decltype(last_msg_->common.valid)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->common.valid)),
            1)
      << "incorrect value for common.valid, expected 1, is "
      << last_msg_->common.valid;
  EXPECT_LT((last_msg_->pos[0] * 100 - -12177330.0781 * 100), 0.05)
      << "incorrect value for pos[0], expected -12177330.0781, is "
      << last_msg_->pos[0];
  EXPECT_LT((last_msg_->pos[1] * 100 - 599893.066406 * 100), 0.05)
      << "incorrect value for pos[1], expected 599893.066406, is "
      << last_msg_->pos[1];
  EXPECT_LT((last_msg_->pos[2] * 100 - -22373708.4961 * 100), 0.05)
      << "incorrect value for pos[2], expected -22373708.4961, is "
      << last_msg_->pos[2];
  EXPECT_LT((last_msg_->vel[0] * 100 - -1726.50623322 * 100), 0.05)
      << "incorrect value for vel[0], expected -1726.50623322, is "
      << last_msg_->vel[0];
  EXPECT_LT((last_msg_->vel[1] * 100 - -2542.61493683 * 100), 0.05)
      << "incorrect value for vel[1], expected -2542.61493683, is "
      << last_msg_->vel[1];
  EXPECT_LT((last_msg_->vel[2] * 100 - 869.817733765 * 100), 0.05)
      << "incorrect value for vel[2], expected 869.817733765, is "
      << last_msg_->vel[2];
}
