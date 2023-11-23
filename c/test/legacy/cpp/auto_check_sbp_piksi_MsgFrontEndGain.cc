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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgFrontEndGain.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>
#include <libsbp/cpp/state.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/piksi.h>
class Test_legacy_auto_check_sbp_piksi_MsgFrontEndGain0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_front_end_gain_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgFrontEndGain0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_front_end_gain_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_front_end_gain_t *>(last_msg_storage_)),
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
                      const msg_front_end_gain_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_front_end_gain_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgFrontEndGain0, Test) {
  uint8_t encoded_frame[] = {
      85, 191, 0,   175, 245, 16, 41,  133, 134, 10, 105, 20,
      38, 38,  246, 233, 216, 80, 187, 213, 85,  2,  235, 135,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_front_end_gain_t *test_msg = (msg_front_end_gain_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->if_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->if_gain[0]));
  }
  test_msg->if_gain[0] = -10;
  if (sizeof(test_msg->if_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->if_gain[0]));
  }
  test_msg->if_gain[1] = -23;
  if (sizeof(test_msg->if_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->if_gain[0]));
  }
  test_msg->if_gain[2] = -40;
  if (sizeof(test_msg->if_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->if_gain[0]));
  }
  test_msg->if_gain[3] = 80;
  if (sizeof(test_msg->if_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->if_gain[0]));
  }
  test_msg->if_gain[4] = -69;
  if (sizeof(test_msg->if_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->if_gain[0]));
  }
  test_msg->if_gain[5] = -43;
  if (sizeof(test_msg->if_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->if_gain[0]));
  }
  test_msg->if_gain[6] = 85;
  if (sizeof(test_msg->if_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->if_gain[0]));
  }
  test_msg->if_gain[7] = 2;
  if (sizeof(test_msg->rf_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rf_gain[0]));
  }
  test_msg->rf_gain[0] = 41;
  if (sizeof(test_msg->rf_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rf_gain[0]));
  }
  test_msg->rf_gain[1] = -123;
  if (sizeof(test_msg->rf_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rf_gain[0]));
  }
  test_msg->rf_gain[2] = -122;
  if (sizeof(test_msg->rf_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rf_gain[0]));
  }
  test_msg->rf_gain[3] = 10;
  if (sizeof(test_msg->rf_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rf_gain[0]));
  }
  test_msg->rf_gain[4] = 105;
  if (sizeof(test_msg->rf_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rf_gain[0]));
  }
  test_msg->rf_gain[5] = 20;
  if (sizeof(test_msg->rf_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rf_gain[0]));
  }
  test_msg->rf_gain[6] = 38;
  if (sizeof(test_msg->rf_gain) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rf_gain[0]));
  }
  test_msg->rf_gain[7] = 38;

  EXPECT_EQ(send_message(0xbf, 62895, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 62895);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->if_gain[0], -10)
      << "incorrect value for if_gain[0], expected -10, is "
      << last_msg_->if_gain[0];
  EXPECT_EQ(last_msg_->if_gain[1], -23)
      << "incorrect value for if_gain[1], expected -23, is "
      << last_msg_->if_gain[1];
  EXPECT_EQ(last_msg_->if_gain[2], -40)
      << "incorrect value for if_gain[2], expected -40, is "
      << last_msg_->if_gain[2];
  EXPECT_EQ(last_msg_->if_gain[3], 80)
      << "incorrect value for if_gain[3], expected 80, is "
      << last_msg_->if_gain[3];
  EXPECT_EQ(last_msg_->if_gain[4], -69)
      << "incorrect value for if_gain[4], expected -69, is "
      << last_msg_->if_gain[4];
  EXPECT_EQ(last_msg_->if_gain[5], -43)
      << "incorrect value for if_gain[5], expected -43, is "
      << last_msg_->if_gain[5];
  EXPECT_EQ(last_msg_->if_gain[6], 85)
      << "incorrect value for if_gain[6], expected 85, is "
      << last_msg_->if_gain[6];
  EXPECT_EQ(last_msg_->if_gain[7], 2)
      << "incorrect value for if_gain[7], expected 2, is "
      << last_msg_->if_gain[7];
  EXPECT_EQ(last_msg_->rf_gain[0], 41)
      << "incorrect value for rf_gain[0], expected 41, is "
      << last_msg_->rf_gain[0];
  EXPECT_EQ(last_msg_->rf_gain[1], -123)
      << "incorrect value for rf_gain[1], expected -123, is "
      << last_msg_->rf_gain[1];
  EXPECT_EQ(last_msg_->rf_gain[2], -122)
      << "incorrect value for rf_gain[2], expected -122, is "
      << last_msg_->rf_gain[2];
  EXPECT_EQ(last_msg_->rf_gain[3], 10)
      << "incorrect value for rf_gain[3], expected 10, is "
      << last_msg_->rf_gain[3];
  EXPECT_EQ(last_msg_->rf_gain[4], 105)
      << "incorrect value for rf_gain[4], expected 105, is "
      << last_msg_->rf_gain[4];
  EXPECT_EQ(last_msg_->rf_gain[5], 20)
      << "incorrect value for rf_gain[5], expected 20, is "
      << last_msg_->rf_gain[5];
  EXPECT_EQ(last_msg_->rf_gain[6], 38)
      << "incorrect value for rf_gain[6], expected 38, is "
      << last_msg_->rf_gain[6];
  EXPECT_EQ(last_msg_->rf_gain[7], 38)
      << "incorrect value for rf_gain[7], expected 38, is "
      << last_msg_->rf_gain[7];
}
