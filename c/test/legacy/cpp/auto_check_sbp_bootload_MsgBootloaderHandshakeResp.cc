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
// spec/tests/yaml/swiftnav/sbp/bootload/test_MsgBootloaderHandshakeResp.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_bootload_MsgBootloaderHandshakeResp0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_bootloader_handshake_resp_t> {
 public:
  Test_legacy_auto_check_sbp_bootload_MsgBootloaderHandshakeResp0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_bootloader_handshake_resp_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_bootloader_handshake_resp_t *>(
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
                      const msg_bootloader_handshake_resp_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_bootloader_handshake_resp_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_bootload_MsgBootloaderHandshakeResp0, Test) {
  uint8_t encoded_frame[] = {
      85, 180, 0, 0, 0, 9, 0, 0, 0, 0, 118, 49, 46, 50, 10, 201, 1,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_bootloader_handshake_resp_t *test_msg =
      (msg_bootloader_handshake_resp_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  {
    const char assign_string[] = {(char)118, (char)49, (char)46, (char)50,
                                  (char)10};
    memcpy(test_msg->version, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->version) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }

  EXPECT_EQ(send_message(0xb4, 0, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 0);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  {
    const char check_string[] = {(char)118, (char)49, (char)46, (char)50,
                                 (char)10};
    EXPECT_EQ(memcmp(last_msg_->version, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->version, expected string '"
        << check_string << "', is '" << last_msg_->version << "'";
  }
}
class Test_legacy_auto_check_sbp_bootload_MsgBootloaderHandshakeResp1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_bootloader_handshake_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_bootload_MsgBootloaderHandshakeResp1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_bootloader_handshake_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_bootloader_handshake_dep_a_t *>(
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
                      const msg_bootloader_handshake_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_bootloader_handshake_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_bootload_MsgBootloaderHandshakeResp1, Test) {
  uint8_t encoded_frame[] = {
      85, 176, 0, 195, 4, 4, 118, 49, 46, 50, 1, 206,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_bootloader_handshake_dep_a_t *test_msg =
      (msg_bootloader_handshake_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->handshake) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->handshake[0]));
  }
  test_msg->handshake[0] = 118;
  if (sizeof(test_msg->handshake) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->handshake[0]));
  }
  test_msg->handshake[1] = 49;
  if (sizeof(test_msg->handshake) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->handshake[0]));
  }
  test_msg->handshake[2] = 46;
  if (sizeof(test_msg->handshake) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->handshake[0]));
  }
  test_msg->handshake[3] = 50;

  EXPECT_EQ(send_message(0xb0, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->handshake[0], 118)
      << "incorrect value for handshake[0], expected 118, is "
      << last_msg_->handshake[0];
  EXPECT_EQ(last_msg_->handshake[1], 49)
      << "incorrect value for handshake[1], expected 49, is "
      << last_msg_->handshake[1];
  EXPECT_EQ(last_msg_->handshake[2], 46)
      << "incorrect value for handshake[2], expected 46, is "
      << last_msg_->handshake[2];
  EXPECT_EQ(last_msg_->handshake[3], 50)
      << "incorrect value for handshake[3], expected 50, is "
      << last_msg_->handshake[3];
}
