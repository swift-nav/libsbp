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
// spec/tests/yaml/swiftnav/sbp/logging/test_MsgFwd.yaml by generate.py. Do not
// modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_logging_MsgFwd0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_fwd_t> {
 public:
  Test_legacy_auto_check_sbp_logging_MsgFwd0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_fwd_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_fwd_t *>(last_msg_storage_)),
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
                      const msg_fwd_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_fwd_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_logging_MsgFwd0, Test) {
  uint8_t encoded_frame[] = {
      85,  2,  4,  66, 0,  18, 0,  0,  86, 81, 68,  47,  81,
      103, 65, 69, 65, 65, 65, 65, 65, 69, 97, 103, 125, 95,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_fwd_t *test_msg = (msg_fwd_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[0] = 86;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[1] = 81;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[2] = 68;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[3] = 47;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[4] = 81;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[5] = 103;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[6] = 65;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[7] = 69;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[8] = 65;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[9] = 65;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[10] = 65;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[11] = 65;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[12] = 65;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[13] = 69;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[14] = 97;
  if (sizeof(test_msg->fwd_payload) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->fwd_payload[0]));
  }
  test_msg->fwd_payload[15] = 103;
  test_msg->protocol = 0;
  test_msg->source = 0;

  EXPECT_EQ(send_message(0x402, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->fwd_payload[0], 86)
      << "incorrect value for fwd_payload[0], expected 86, is "
      << last_msg_->fwd_payload[0];
  EXPECT_EQ(last_msg_->fwd_payload[1], 81)
      << "incorrect value for fwd_payload[1], expected 81, is "
      << last_msg_->fwd_payload[1];
  EXPECT_EQ(last_msg_->fwd_payload[2], 68)
      << "incorrect value for fwd_payload[2], expected 68, is "
      << last_msg_->fwd_payload[2];
  EXPECT_EQ(last_msg_->fwd_payload[3], 47)
      << "incorrect value for fwd_payload[3], expected 47, is "
      << last_msg_->fwd_payload[3];
  EXPECT_EQ(last_msg_->fwd_payload[4], 81)
      << "incorrect value for fwd_payload[4], expected 81, is "
      << last_msg_->fwd_payload[4];
  EXPECT_EQ(last_msg_->fwd_payload[5], 103)
      << "incorrect value for fwd_payload[5], expected 103, is "
      << last_msg_->fwd_payload[5];
  EXPECT_EQ(last_msg_->fwd_payload[6], 65)
      << "incorrect value for fwd_payload[6], expected 65, is "
      << last_msg_->fwd_payload[6];
  EXPECT_EQ(last_msg_->fwd_payload[7], 69)
      << "incorrect value for fwd_payload[7], expected 69, is "
      << last_msg_->fwd_payload[7];
  EXPECT_EQ(last_msg_->fwd_payload[8], 65)
      << "incorrect value for fwd_payload[8], expected 65, is "
      << last_msg_->fwd_payload[8];
  EXPECT_EQ(last_msg_->fwd_payload[9], 65)
      << "incorrect value for fwd_payload[9], expected 65, is "
      << last_msg_->fwd_payload[9];
  EXPECT_EQ(last_msg_->fwd_payload[10], 65)
      << "incorrect value for fwd_payload[10], expected 65, is "
      << last_msg_->fwd_payload[10];
  EXPECT_EQ(last_msg_->fwd_payload[11], 65)
      << "incorrect value for fwd_payload[11], expected 65, is "
      << last_msg_->fwd_payload[11];
  EXPECT_EQ(last_msg_->fwd_payload[12], 65)
      << "incorrect value for fwd_payload[12], expected 65, is "
      << last_msg_->fwd_payload[12];
  EXPECT_EQ(last_msg_->fwd_payload[13], 69)
      << "incorrect value for fwd_payload[13], expected 69, is "
      << last_msg_->fwd_payload[13];
  EXPECT_EQ(last_msg_->fwd_payload[14], 97)
      << "incorrect value for fwd_payload[14], expected 97, is "
      << last_msg_->fwd_payload[14];
  EXPECT_EQ(last_msg_->fwd_payload[15], 103)
      << "incorrect value for fwd_payload[15], expected 103, is "
      << last_msg_->fwd_payload[15];
  EXPECT_EQ(last_msg_->protocol, 0)
      << "incorrect value for protocol, expected 0, is " << last_msg_->protocol;
  EXPECT_EQ(last_msg_->source, 0)
      << "incorrect value for source, expected 0, is " << last_msg_->source;
}
