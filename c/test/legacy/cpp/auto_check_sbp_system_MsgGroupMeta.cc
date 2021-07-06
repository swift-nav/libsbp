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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgGroupMeta.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_system_MsgGroupMeta0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_group_meta_t> {
 public:
  Test_legacy_auto_check_sbp_system_MsgGroupMeta0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_group_meta_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_group_meta_t *>(last_msg_storage_)),
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
                      const msg_group_meta_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_group_meta_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_system_MsgGroupMeta0, Test) {
  uint8_t encoded_frame[] = {
      85, 10, 255, 238, 238, 9, 1, 2, 3, 10, 255, 10, 2, 2, 255, 2, 14,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_group_meta_t *test_msg = (msg_group_meta_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 2;
  test_msg->group_id = 1;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[0] = 65290;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[1] = 522;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[2] = 65282;
  test_msg->n_group_msgs = 3;

  EXPECT_EQ(send_message(0xFF0A, 61166, test_msg_len, test_msg_storage),
            SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 61166);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 2)
      << "incorrect value for flags, expected 2, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->group_id, 1)
      << "incorrect value for group_id, expected 1, is " << last_msg_->group_id;
  EXPECT_EQ(last_msg_->group_msgs[0], 65290)
      << "incorrect value for group_msgs[0], expected 65290, is "
      << last_msg_->group_msgs[0];
  EXPECT_EQ(last_msg_->group_msgs[1], 522)
      << "incorrect value for group_msgs[1], expected 522, is "
      << last_msg_->group_msgs[1];
  EXPECT_EQ(last_msg_->group_msgs[2], 65282)
      << "incorrect value for group_msgs[2], expected 65282, is "
      << last_msg_->group_msgs[2];
  EXPECT_EQ(last_msg_->n_group_msgs, 3)
      << "incorrect value for n_group_msgs, expected 3, is "
      << last_msg_->n_group_msgs;
}
class Test_legacy_auto_check_sbp_system_MsgGroupMeta1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_group_meta_t> {
 public:
  Test_legacy_auto_check_sbp_system_MsgGroupMeta1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_group_meta_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_group_meta_t *>(last_msg_storage_)),
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
                      const msg_group_meta_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_group_meta_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_system_MsgGroupMeta1, Test) {
  uint8_t encoded_frame[] = {
      85, 10, 255, 21, 3, 31, 1,   1, 14,  2,  1,   3,  1,
      10, 2,  17,  2,  9, 2,  20,  2, 14,  2,  18,  2,  13,
      2,  21, 2,   33, 2, 3,  255, 6, 255, 14, 255, 82, 154,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_group_meta_t *test_msg = (msg_group_meta_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 1;
  test_msg->group_id = 1;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[0] = 258;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[1] = 259;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[2] = 522;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[3] = 529;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[4] = 521;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[5] = 532;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[6] = 526;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[7] = 530;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[8] = 525;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[9] = 533;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[10] = 545;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[11] = 65283;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[12] = 65286;
  if (sizeof(test_msg->group_msgs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->group_msgs[0]));
  }
  test_msg->group_msgs[13] = 65294;
  test_msg->n_group_msgs = 14;

  EXPECT_EQ(send_message(0xFF0A, 789, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 789);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 1)
      << "incorrect value for flags, expected 1, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->group_id, 1)
      << "incorrect value for group_id, expected 1, is " << last_msg_->group_id;
  EXPECT_EQ(last_msg_->group_msgs[0], 258)
      << "incorrect value for group_msgs[0], expected 258, is "
      << last_msg_->group_msgs[0];
  EXPECT_EQ(last_msg_->group_msgs[1], 259)
      << "incorrect value for group_msgs[1], expected 259, is "
      << last_msg_->group_msgs[1];
  EXPECT_EQ(last_msg_->group_msgs[2], 522)
      << "incorrect value for group_msgs[2], expected 522, is "
      << last_msg_->group_msgs[2];
  EXPECT_EQ(last_msg_->group_msgs[3], 529)
      << "incorrect value for group_msgs[3], expected 529, is "
      << last_msg_->group_msgs[3];
  EXPECT_EQ(last_msg_->group_msgs[4], 521)
      << "incorrect value for group_msgs[4], expected 521, is "
      << last_msg_->group_msgs[4];
  EXPECT_EQ(last_msg_->group_msgs[5], 532)
      << "incorrect value for group_msgs[5], expected 532, is "
      << last_msg_->group_msgs[5];
  EXPECT_EQ(last_msg_->group_msgs[6], 526)
      << "incorrect value for group_msgs[6], expected 526, is "
      << last_msg_->group_msgs[6];
  EXPECT_EQ(last_msg_->group_msgs[7], 530)
      << "incorrect value for group_msgs[7], expected 530, is "
      << last_msg_->group_msgs[7];
  EXPECT_EQ(last_msg_->group_msgs[8], 525)
      << "incorrect value for group_msgs[8], expected 525, is "
      << last_msg_->group_msgs[8];
  EXPECT_EQ(last_msg_->group_msgs[9], 533)
      << "incorrect value for group_msgs[9], expected 533, is "
      << last_msg_->group_msgs[9];
  EXPECT_EQ(last_msg_->group_msgs[10], 545)
      << "incorrect value for group_msgs[10], expected 545, is "
      << last_msg_->group_msgs[10];
  EXPECT_EQ(last_msg_->group_msgs[11], 65283)
      << "incorrect value for group_msgs[11], expected 65283, is "
      << last_msg_->group_msgs[11];
  EXPECT_EQ(last_msg_->group_msgs[12], 65286)
      << "incorrect value for group_msgs[12], expected 65286, is "
      << last_msg_->group_msgs[12];
  EXPECT_EQ(last_msg_->group_msgs[13], 65294)
      << "incorrect value for group_msgs[13], expected 65294, is "
      << last_msg_->group_msgs[13];
  EXPECT_EQ(last_msg_->n_group_msgs, 14)
      << "incorrect value for n_group_msgs, expected 14, is "
      << last_msg_->n_group_msgs;
}
