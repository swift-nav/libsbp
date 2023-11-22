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
// spec/tests/yaml/swiftnav/sbp/flash/test_MsgStmUniqueIdResp.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_flash_MsgStmUniqueIdResp0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_stm_unique_id_resp_t> {
 public:
  Test_legacy_auto_check_sbp_flash_MsgStmUniqueIdResp0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_stm_unique_id_resp_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_stm_unique_id_resp_t *>(last_msg_storage_)),
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
                      const msg_stm_unique_id_resp_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_stm_unique_id_resp_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_flash_MsgStmUniqueIdResp0, Test) {
  uint8_t encoded_frame[] = {
      85, 229, 0,   195, 4,  12,  196, 16,  15,  163,
      85, 221, 119, 102, 32, 194, 56,  144, 221, 196,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_stm_unique_id_resp_t *test_msg =
      (msg_stm_unique_id_resp_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[0] = 196;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[1] = 16;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[2] = 15;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[3] = 163;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[4] = 85;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[5] = 221;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[6] = 119;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[7] = 102;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[8] = 32;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[9] = 194;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[10] = 56;
  if (sizeof(test_msg->stm_id) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stm_id[0]));
  }
  test_msg->stm_id[11] = 144;

  EXPECT_EQ(send_message(0xe5, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->stm_id[0], 196)
      << "incorrect value for stm_id[0], expected 196, is "
      << last_msg_->stm_id[0];
  EXPECT_EQ(last_msg_->stm_id[1], 16)
      << "incorrect value for stm_id[1], expected 16, is "
      << last_msg_->stm_id[1];
  EXPECT_EQ(last_msg_->stm_id[2], 15)
      << "incorrect value for stm_id[2], expected 15, is "
      << last_msg_->stm_id[2];
  EXPECT_EQ(last_msg_->stm_id[3], 163)
      << "incorrect value for stm_id[3], expected 163, is "
      << last_msg_->stm_id[3];
  EXPECT_EQ(last_msg_->stm_id[4], 85)
      << "incorrect value for stm_id[4], expected 85, is "
      << last_msg_->stm_id[4];
  EXPECT_EQ(last_msg_->stm_id[5], 221)
      << "incorrect value for stm_id[5], expected 221, is "
      << last_msg_->stm_id[5];
  EXPECT_EQ(last_msg_->stm_id[6], 119)
      << "incorrect value for stm_id[6], expected 119, is "
      << last_msg_->stm_id[6];
  EXPECT_EQ(last_msg_->stm_id[7], 102)
      << "incorrect value for stm_id[7], expected 102, is "
      << last_msg_->stm_id[7];
  EXPECT_EQ(last_msg_->stm_id[8], 32)
      << "incorrect value for stm_id[8], expected 32, is "
      << last_msg_->stm_id[8];
  EXPECT_EQ(last_msg_->stm_id[9], 194)
      << "incorrect value for stm_id[9], expected 194, is "
      << last_msg_->stm_id[9];
  EXPECT_EQ(last_msg_->stm_id[10], 56)
      << "incorrect value for stm_id[10], expected 56, is "
      << last_msg_->stm_id[10];
  EXPECT_EQ(last_msg_->stm_id[11], 144)
      << "incorrect value for stm_id[11], expected 144, is "
      << last_msg_->stm_id[11];
}
