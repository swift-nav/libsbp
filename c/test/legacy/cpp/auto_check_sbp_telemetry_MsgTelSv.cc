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
// spec/tests/yaml/swiftnav/sbp/telemetry/test_MsgTelSv.yaml by generate.py. Do
// not modify by hand!

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
#include <libsbp/legacy/telemetry.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_telemetry_MsgTelSv0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_tel_sv_t> {
 public:
  Test_legacy_auto_check_sbp_telemetry_MsgTelSv0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_tel_sv_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_tel_sv_t *>(last_msg_storage_)),
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
                      const msg_tel_sv_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_tel_sv_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_telemetry_MsgTelSv0, Test) {
  uint8_t encoded_frame[] = {
      85, 32, 1, 148, 38,  20, 175, 8, 208, 221, 62, 24, 16, 1,
      40, 50, 5, 226, 255, 1,  0,   1, 1,   1,   33, 12, 39, 105,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_tel_sv_t *test_msg = (msg_tel_sv_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->n_obs = 16;
  test_msg->origin_flags = 1;
  if (sizeof(test_msg->sv_tel) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->sv_tel[0]));
  }
  test_msg->sv_tel[0].availability_flags = 5;
  test_msg->sv_tel[0].az = 40;
  test_msg->sv_tel[0].correction_flags = 1;
  test_msg->sv_tel[0].el = 50;
  test_msg->sv_tel[0].ephemeris_flags = 1;
  test_msg->sv_tel[0].outlier_flags = 1;
  test_msg->sv_tel[0].phase_residual = 1;
  test_msg->sv_tel[0].pseudorange_residual = -30;
  test_msg->sv_tel[0].sid.code = 12;
  test_msg->sv_tel[0].sid.sat = 33;
  test_msg->tow = 406773200;
  test_msg->wn = 2223;

  EXPECT_EQ(send_message(0x120, 9876, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 9876);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->n_obs)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_obs)),
            16)
      << "incorrect value for n_obs, expected 16, is " << last_msg_->n_obs;
  EXPECT_EQ(get_as<decltype(last_msg_->origin_flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->origin_flags)),
            1)
      << "incorrect value for origin_flags, expected 1, is "
      << last_msg_->origin_flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sv_tel[0].availability_flags)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sv_tel[0].availability_flags)),
            5)
      << "incorrect value for sv_tel[0].availability_flags, expected 5, is "
      << last_msg_->sv_tel[0].availability_flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sv_tel[0].az)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sv_tel[0].az)),
            40)
      << "incorrect value for sv_tel[0].az, expected 40, is "
      << last_msg_->sv_tel[0].az;
  EXPECT_EQ(get_as<decltype(last_msg_->sv_tel[0].correction_flags)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sv_tel[0].correction_flags)),
            1)
      << "incorrect value for sv_tel[0].correction_flags, expected 1, is "
      << last_msg_->sv_tel[0].correction_flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sv_tel[0].el)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sv_tel[0].el)),
            50)
      << "incorrect value for sv_tel[0].el, expected 50, is "
      << last_msg_->sv_tel[0].el;
  EXPECT_EQ(get_as<decltype(last_msg_->sv_tel[0].ephemeris_flags)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sv_tel[0].ephemeris_flags)),
            1)
      << "incorrect value for sv_tel[0].ephemeris_flags, expected 1, is "
      << last_msg_->sv_tel[0].ephemeris_flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sv_tel[0].outlier_flags)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sv_tel[0].outlier_flags)),
            1)
      << "incorrect value for sv_tel[0].outlier_flags, expected 1, is "
      << last_msg_->sv_tel[0].outlier_flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sv_tel[0].phase_residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sv_tel[0].phase_residual)),
            1)
      << "incorrect value for sv_tel[0].phase_residual, expected 1, is "
      << last_msg_->sv_tel[0].phase_residual;
  EXPECT_EQ(get_as<decltype(last_msg_->sv_tel[0].pseudorange_residual)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->sv_tel[0].pseudorange_residual)),
            -30)
      << "incorrect value for sv_tel[0].pseudorange_residual, expected -30, is "
      << last_msg_->sv_tel[0].pseudorange_residual;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sv_tel[0].sid.code)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sv_tel[0].sid.code)),
      12)
      << "incorrect value for sv_tel[0].sid.code, expected 12, is "
      << last_msg_->sv_tel[0].sid.code;
  EXPECT_EQ(
      get_as<decltype(last_msg_->sv_tel[0].sid.sat)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->sv_tel[0].sid.sat)),
      33)
      << "incorrect value for sv_tel[0].sid.sat, expected 33, is "
      << last_msg_->sv_tel[0].sid.sat;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            406773200)
      << "incorrect value for tow, expected 406773200, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->wn)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->wn)),
            2223)
      << "incorrect value for wn, expected 2223, is " << last_msg_->wn;
}
