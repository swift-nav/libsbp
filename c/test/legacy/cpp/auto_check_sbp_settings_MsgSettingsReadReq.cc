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
// spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadReq.yaml by
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
#include <libsbp/legacy/settings.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_settings_MsgSettingsReadReq0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_settings_read_req_t> {
 public:
  Test_legacy_auto_check_sbp_settings_MsgSettingsReadReq0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_settings_read_req_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_settings_read_req_t *>(last_msg_storage_)),
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
                      const msg_settings_read_req_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_settings_read_req_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_settings_MsgSettingsReadReq0, Test) {
  uint8_t encoded_frame[] = {
      85,  164, 0,   152, 214, 26,  115, 101, 99,  116, 105, 111,
      110, 45,  110, 97,  109, 101, 0,   115, 101, 116, 116, 105,
      110, 103, 45,  110, 97,  109, 101, 0,   181, 228,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_settings_read_req_t *test_msg =
      (msg_settings_read_req_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  {
    const char assign_string[] = {
        (char)115, (char)101, (char)99,  (char)116, (char)105, (char)111,
        (char)110, (char)45,  (char)110, (char)97,  (char)109, (char)101,
        (char)0,   (char)115, (char)101, (char)116, (char)116, (char)105,
        (char)110, (char)103, (char)45,  (char)110, (char)97,  (char)109,
        (char)101, (char)0};
    memcpy(test_msg->setting, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->setting) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }

  EXPECT_EQ(send_message(0xa4, 54936, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 54936);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  {
    const char check_string[] = {
        (char)115, (char)101, (char)99,  (char)116, (char)105, (char)111,
        (char)110, (char)45,  (char)110, (char)97,  (char)109, (char)101,
        (char)0,   (char)115, (char)101, (char)116, (char)116, (char)105,
        (char)110, (char)103, (char)45,  (char)110, (char)97,  (char)109,
        (char)101, (char)0};
    EXPECT_EQ(memcmp(last_msg_->setting, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->setting, expected string '"
        << check_string << "', is '" << last_msg_->setting << "'";
  }
}
