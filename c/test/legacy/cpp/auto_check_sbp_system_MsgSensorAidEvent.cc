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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgSensorAidEvent.yaml by
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
#include <libsbp/legacy/system.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_system_MsgSensorAidEvent0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_sensor_aid_event_t> {
 public:
  Test_legacy_auto_check_sbp_system_MsgSensorAidEvent0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_sensor_aid_event_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_sensor_aid_event_t *>(last_msg_storage_)),
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
                      const msg_sensor_aid_event_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_sensor_aid_event_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_system_MsgSensorAidEvent0, Test) {
  uint8_t encoded_frame[] = {
      85, 9, 255, 211, 136, 15, 48, 246, 122, 19, 0,   0,
      0,  0, 0,   0,   0,   0,  0,  0,   0,   33, 236,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_sensor_aid_event_t *test_msg = (msg_sensor_aid_event_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->n_accepted_meas = 0;
  test_msg->n_attempted_meas = 0;
  test_msg->n_available_meas = 0;
  test_msg->sensor_id = 0;
  test_msg->sensor_state = 0;
  test_msg->sensor_type = 0;
  test_msg->time = 326825520;

  EXPECT_EQ(send_message(0xFF09, 35027, test_msg_len, test_msg_storage),
            SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_accepted_meas)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_accepted_meas)),
            0)
      << "incorrect value for n_accepted_meas, expected 0, is "
      << last_msg_->n_accepted_meas;
  EXPECT_EQ(
      get_as<decltype(last_msg_->n_attempted_meas)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->n_attempted_meas)),
      0)
      << "incorrect value for n_attempted_meas, expected 0, is "
      << last_msg_->n_attempted_meas;
  EXPECT_EQ(
      get_as<decltype(last_msg_->n_available_meas)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->n_available_meas)),
      0)
      << "incorrect value for n_available_meas, expected 0, is "
      << last_msg_->n_available_meas;
  EXPECT_EQ(get_as<decltype(last_msg_->sensor_id)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sensor_id)),
            0)
      << "incorrect value for sensor_id, expected 0, is "
      << last_msg_->sensor_id;
  EXPECT_EQ(get_as<decltype(last_msg_->sensor_state)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sensor_state)),
            0)
      << "incorrect value for sensor_state, expected 0, is "
      << last_msg_->sensor_state;
  EXPECT_EQ(get_as<decltype(last_msg_->sensor_type)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sensor_type)),
            0)
      << "incorrect value for sensor_type, expected 0, is "
      << last_msg_->sensor_type;
  EXPECT_EQ(get_as<decltype(last_msg_->time)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->time)),
            326825520)
      << "incorrect value for time, expected 326825520, is " << last_msg_->time;
}
