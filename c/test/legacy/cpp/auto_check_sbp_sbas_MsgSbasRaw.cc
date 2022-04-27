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
// spec/tests/yaml/swiftnav/sbp/sbas/test_MsgSbasRaw.yaml by generate.py. Do not
// modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_sbas_MsgSbasRaw0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_sbas_raw_t> {
 public:
  Test_legacy_auto_check_sbp_sbas_MsgSbasRaw0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_sbas_raw_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_sbas_raw_t *>(last_msg_storage_)),
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
                      const msg_sbas_raw_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_sbas_raw_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_sbas_MsgSbasRaw0, Test) {
  uint8_t encoded_frame[] = {
      85,  119, 119, 28,  200, 34,  131, 2,   201, 228, 233, 29,  4,   23,
      255, 0,   23,  255, 0,   23,  255, 127, 240, 2,   255, 192, 3,   127,
      247, 255, 127, 247, 255, 229, 229, 238, 170, 175, 255, 240, 167, 14,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_sbas_raw_t *test_msg = (msg_sbas_raw_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[0] = 23;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[1] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[2] = 0;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[3] = 23;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[4] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[5] = 0;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[6] = 23;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[7] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[8] = 127;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[9] = 240;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[10] = 2;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[11] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[12] = 192;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[13] = 3;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[14] = 127;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[15] = 247;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[16] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[17] = 127;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[18] = 247;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[19] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[20] = 229;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[21] = 229;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[22] = 238;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[23] = 170;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[24] = 175;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[25] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[26] = 240;
  test_msg->message_type = 4;
  test_msg->sid.code = 2;
  test_msg->sid.sat = 131;
  test_msg->tow = 501867721;

  EXPECT_EQ(send_message(0x7777, 51228, test_msg_len, test_msg_storage),
            SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 51228);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->data[0], 23)
      << "incorrect value for data[0], expected 23, is " << last_msg_->data[0];
  EXPECT_EQ(last_msg_->data[1], 255)
      << "incorrect value for data[1], expected 255, is " << last_msg_->data[1];
  EXPECT_EQ(last_msg_->data[2], 0)
      << "incorrect value for data[2], expected 0, is " << last_msg_->data[2];
  EXPECT_EQ(last_msg_->data[3], 23)
      << "incorrect value for data[3], expected 23, is " << last_msg_->data[3];
  EXPECT_EQ(last_msg_->data[4], 255)
      << "incorrect value for data[4], expected 255, is " << last_msg_->data[4];
  EXPECT_EQ(last_msg_->data[5], 0)
      << "incorrect value for data[5], expected 0, is " << last_msg_->data[5];
  EXPECT_EQ(last_msg_->data[6], 23)
      << "incorrect value for data[6], expected 23, is " << last_msg_->data[6];
  EXPECT_EQ(last_msg_->data[7], 255)
      << "incorrect value for data[7], expected 255, is " << last_msg_->data[7];
  EXPECT_EQ(last_msg_->data[8], 127)
      << "incorrect value for data[8], expected 127, is " << last_msg_->data[8];
  EXPECT_EQ(last_msg_->data[9], 240)
      << "incorrect value for data[9], expected 240, is " << last_msg_->data[9];
  EXPECT_EQ(last_msg_->data[10], 2)
      << "incorrect value for data[10], expected 2, is " << last_msg_->data[10];
  EXPECT_EQ(last_msg_->data[11], 255)
      << "incorrect value for data[11], expected 255, is "
      << last_msg_->data[11];
  EXPECT_EQ(last_msg_->data[12], 192)
      << "incorrect value for data[12], expected 192, is "
      << last_msg_->data[12];
  EXPECT_EQ(last_msg_->data[13], 3)
      << "incorrect value for data[13], expected 3, is " << last_msg_->data[13];
  EXPECT_EQ(last_msg_->data[14], 127)
      << "incorrect value for data[14], expected 127, is "
      << last_msg_->data[14];
  EXPECT_EQ(last_msg_->data[15], 247)
      << "incorrect value for data[15], expected 247, is "
      << last_msg_->data[15];
  EXPECT_EQ(last_msg_->data[16], 255)
      << "incorrect value for data[16], expected 255, is "
      << last_msg_->data[16];
  EXPECT_EQ(last_msg_->data[17], 127)
      << "incorrect value for data[17], expected 127, is "
      << last_msg_->data[17];
  EXPECT_EQ(last_msg_->data[18], 247)
      << "incorrect value for data[18], expected 247, is "
      << last_msg_->data[18];
  EXPECT_EQ(last_msg_->data[19], 255)
      << "incorrect value for data[19], expected 255, is "
      << last_msg_->data[19];
  EXPECT_EQ(last_msg_->data[20], 229)
      << "incorrect value for data[20], expected 229, is "
      << last_msg_->data[20];
  EXPECT_EQ(last_msg_->data[21], 229)
      << "incorrect value for data[21], expected 229, is "
      << last_msg_->data[21];
  EXPECT_EQ(last_msg_->data[22], 238)
      << "incorrect value for data[22], expected 238, is "
      << last_msg_->data[22];
  EXPECT_EQ(last_msg_->data[23], 170)
      << "incorrect value for data[23], expected 170, is "
      << last_msg_->data[23];
  EXPECT_EQ(last_msg_->data[24], 175)
      << "incorrect value for data[24], expected 175, is "
      << last_msg_->data[24];
  EXPECT_EQ(last_msg_->data[25], 255)
      << "incorrect value for data[25], expected 255, is "
      << last_msg_->data[25];
  EXPECT_EQ(last_msg_->data[26], 240)
      << "incorrect value for data[26], expected 240, is "
      << last_msg_->data[26];
  EXPECT_EQ(last_msg_->message_type, 4)
      << "incorrect value for message_type, expected 4, is "
      << last_msg_->message_type;
  EXPECT_EQ(last_msg_->sid.code, 2)
      << "incorrect value for sid.code, expected 2, is " << last_msg_->sid.code;
  EXPECT_EQ(last_msg_->sid.sat, 131)
      << "incorrect value for sid.sat, expected 131, is " << last_msg_->sid.sat;
  EXPECT_EQ(last_msg_->tow, 501867721)
      << "incorrect value for tow, expected 501867721, is " << last_msg_->tow;
}
