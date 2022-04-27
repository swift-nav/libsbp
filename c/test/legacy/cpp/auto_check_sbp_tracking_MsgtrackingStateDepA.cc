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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgtrackingStateDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_tracking_state_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_tracking_state_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_tracking_state_dep_a_t *>(last_msg_storage_)),
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
                      const msg_tracking_state_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_tracking_state_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  22,  0,   195, 4,   66,  1,   0,  204, 177, 51,  65,  1,   2,   198,
      4,   39,  65,  1,   3,   219, 182, 27, 65,  1,   7,   132, 120, 101, 65,
      1,   10,  91,  91,  251, 64,  1,   13, 42,  37,  163, 64,  1,   22,  130,
      184, 215, 64,  1,   30,  115, 53,  75, 65,  1,   31,  16,  74,  126, 65,
      1,   25,  132, 196, 135, 64,  1,   6,  100, 59,  223, 64,  17,  225,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_tracking_state_dep_a_t *test_msg =
      (msg_tracking_state_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[0].cn0 = 11.230907440185547;
  test_msg->states[0].prn = 0;
  test_msg->states[0].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[1].cn0 = 10.438665390014648;
  test_msg->states[1].prn = 2;
  test_msg->states[1].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[2].cn0 = 9.732142448425293;
  test_msg->states[2].prn = 3;
  test_msg->states[2].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[3].cn0 = 14.341922760009766;
  test_msg->states[3].prn = 7;
  test_msg->states[3].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[4].cn0 = 7.8549017906188965;
  test_msg->states[4].prn = 10;
  test_msg->states[4].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[5].cn0 = 5.0982866287231445;
  test_msg->states[5].prn = 13;
  test_msg->states[5].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[6].cn0 = 6.741272926330566;
  test_msg->states[6].prn = 22;
  test_msg->states[6].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[7].cn0 = 12.700549125671387;
  test_msg->states[7].prn = 30;
  test_msg->states[7].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[8].cn0 = 15.893081665039062;
  test_msg->states[8].prn = 31;
  test_msg->states[8].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[9].cn0 = 4.242738723754883;
  test_msg->states[9].prn = 25;
  test_msg->states[9].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[10].cn0 = 6.97599983215332;
  test_msg->states[10].prn = 6;
  test_msg->states[10].state = 1;

  EXPECT_EQ(send_message(0x16, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->states[0].cn0 * 100 - 11.2309074402 * 100), 0.05)
      << "incorrect value for states[0].cn0, expected 11.2309074402, is "
      << last_msg_->states[0].cn0;
  EXPECT_EQ(last_msg_->states[0].prn, 0)
      << "incorrect value for states[0].prn, expected 0, is "
      << last_msg_->states[0].prn;
  EXPECT_EQ(last_msg_->states[0].state, 1)
      << "incorrect value for states[0].state, expected 1, is "
      << last_msg_->states[0].state;
  EXPECT_LT((last_msg_->states[1].cn0 * 100 - 10.43866539 * 100), 0.05)
      << "incorrect value for states[1].cn0, expected 10.43866539, is "
      << last_msg_->states[1].cn0;
  EXPECT_EQ(last_msg_->states[1].prn, 2)
      << "incorrect value for states[1].prn, expected 2, is "
      << last_msg_->states[1].prn;
  EXPECT_EQ(last_msg_->states[1].state, 1)
      << "incorrect value for states[1].state, expected 1, is "
      << last_msg_->states[1].state;
  EXPECT_LT((last_msg_->states[2].cn0 * 100 - 9.73214244843 * 100), 0.05)
      << "incorrect value for states[2].cn0, expected 9.73214244843, is "
      << last_msg_->states[2].cn0;
  EXPECT_EQ(last_msg_->states[2].prn, 3)
      << "incorrect value for states[2].prn, expected 3, is "
      << last_msg_->states[2].prn;
  EXPECT_EQ(last_msg_->states[2].state, 1)
      << "incorrect value for states[2].state, expected 1, is "
      << last_msg_->states[2].state;
  EXPECT_LT((last_msg_->states[3].cn0 * 100 - 14.34192276 * 100), 0.05)
      << "incorrect value for states[3].cn0, expected 14.34192276, is "
      << last_msg_->states[3].cn0;
  EXPECT_EQ(last_msg_->states[3].prn, 7)
      << "incorrect value for states[3].prn, expected 7, is "
      << last_msg_->states[3].prn;
  EXPECT_EQ(last_msg_->states[3].state, 1)
      << "incorrect value for states[3].state, expected 1, is "
      << last_msg_->states[3].state;
  EXPECT_LT((last_msg_->states[4].cn0 * 100 - 7.85490179062 * 100), 0.05)
      << "incorrect value for states[4].cn0, expected 7.85490179062, is "
      << last_msg_->states[4].cn0;
  EXPECT_EQ(last_msg_->states[4].prn, 10)
      << "incorrect value for states[4].prn, expected 10, is "
      << last_msg_->states[4].prn;
  EXPECT_EQ(last_msg_->states[4].state, 1)
      << "incorrect value for states[4].state, expected 1, is "
      << last_msg_->states[4].state;
  EXPECT_LT((last_msg_->states[5].cn0 * 100 - 5.09828662872 * 100), 0.05)
      << "incorrect value for states[5].cn0, expected 5.09828662872, is "
      << last_msg_->states[5].cn0;
  EXPECT_EQ(last_msg_->states[5].prn, 13)
      << "incorrect value for states[5].prn, expected 13, is "
      << last_msg_->states[5].prn;
  EXPECT_EQ(last_msg_->states[5].state, 1)
      << "incorrect value for states[5].state, expected 1, is "
      << last_msg_->states[5].state;
  EXPECT_LT((last_msg_->states[6].cn0 * 100 - 6.74127292633 * 100), 0.05)
      << "incorrect value for states[6].cn0, expected 6.74127292633, is "
      << last_msg_->states[6].cn0;
  EXPECT_EQ(last_msg_->states[6].prn, 22)
      << "incorrect value for states[6].prn, expected 22, is "
      << last_msg_->states[6].prn;
  EXPECT_EQ(last_msg_->states[6].state, 1)
      << "incorrect value for states[6].state, expected 1, is "
      << last_msg_->states[6].state;
  EXPECT_LT((last_msg_->states[7].cn0 * 100 - 12.7005491257 * 100), 0.05)
      << "incorrect value for states[7].cn0, expected 12.7005491257, is "
      << last_msg_->states[7].cn0;
  EXPECT_EQ(last_msg_->states[7].prn, 30)
      << "incorrect value for states[7].prn, expected 30, is "
      << last_msg_->states[7].prn;
  EXPECT_EQ(last_msg_->states[7].state, 1)
      << "incorrect value for states[7].state, expected 1, is "
      << last_msg_->states[7].state;
  EXPECT_LT((last_msg_->states[8].cn0 * 100 - 15.893081665 * 100), 0.05)
      << "incorrect value for states[8].cn0, expected 15.893081665, is "
      << last_msg_->states[8].cn0;
  EXPECT_EQ(last_msg_->states[8].prn, 31)
      << "incorrect value for states[8].prn, expected 31, is "
      << last_msg_->states[8].prn;
  EXPECT_EQ(last_msg_->states[8].state, 1)
      << "incorrect value for states[8].state, expected 1, is "
      << last_msg_->states[8].state;
  EXPECT_LT((last_msg_->states[9].cn0 * 100 - 4.24273872375 * 100), 0.05)
      << "incorrect value for states[9].cn0, expected 4.24273872375, is "
      << last_msg_->states[9].cn0;
  EXPECT_EQ(last_msg_->states[9].prn, 25)
      << "incorrect value for states[9].prn, expected 25, is "
      << last_msg_->states[9].prn;
  EXPECT_EQ(last_msg_->states[9].state, 1)
      << "incorrect value for states[9].state, expected 1, is "
      << last_msg_->states[9].state;
  EXPECT_LT((last_msg_->states[10].cn0 * 100 - 6.97599983215 * 100), 0.05)
      << "incorrect value for states[10].cn0, expected 6.97599983215, is "
      << last_msg_->states[10].cn0;
  EXPECT_EQ(last_msg_->states[10].prn, 6)
      << "incorrect value for states[10].prn, expected 6, is "
      << last_msg_->states[10].prn;
  EXPECT_EQ(last_msg_->states[10].state, 1)
      << "incorrect value for states[10].state, expected 1, is "
      << last_msg_->states[10].state;
}
class Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_tracking_state_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_tracking_state_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_tracking_state_dep_a_t *>(last_msg_storage_)),
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
                      const msg_tracking_state_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_tracking_state_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA1, Test) {
  uint8_t encoded_frame[] = {
      85, 22,  0,  195, 4,   66,  1,   0,  216, 57,  48,  65,  1,   2,   145,
      41, 46,  65, 1,   3,   4,   26,  34, 65,  1,   7,   177, 67,  109, 65,
      1,  10,  61, 80,  249, 64,  1,   13, 250, 199, 155, 64,  1,   22,  55,
      19, 215, 64, 1,   30,  138, 138, 79, 65,  1,   31,  214, 179, 119, 65,
      1,  25,  53, 138, 120, 64,  1,   6,  183, 247, 129, 64,  168, 173,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_tracking_state_dep_a_t *test_msg =
      (msg_tracking_state_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[0].cn0 = 11.014122009277344;
  test_msg->states[0].prn = 0;
  test_msg->states[0].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[1].cn0 = 10.885148048400879;
  test_msg->states[1].prn = 2;
  test_msg->states[1].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[2].cn0 = 10.131351470947266;
  test_msg->states[2].prn = 3;
  test_msg->states[2].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[3].cn0 = 14.829026222229004;
  test_msg->states[3].prn = 7;
  test_msg->states[3].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[4].cn0 = 7.79104471206665;
  test_msg->states[4].prn = 10;
  test_msg->states[4].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[5].cn0 = 4.868161201477051;
  test_msg->states[5].prn = 13;
  test_msg->states[5].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[6].cn0 = 6.721095561981201;
  test_msg->states[6].prn = 22;
  test_msg->states[6].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[7].cn0 = 12.971323013305664;
  test_msg->states[7].prn = 30;
  test_msg->states[7].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[8].cn0 = 15.481405258178711;
  test_msg->states[8].prn = 31;
  test_msg->states[8].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[9].cn0 = 3.8834354877471924;
  test_msg->states[9].prn = 25;
  test_msg->states[9].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[10].cn0 = 4.061488628387451;
  test_msg->states[10].prn = 6;
  test_msg->states[10].state = 1;

  EXPECT_EQ(send_message(0x16, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->states[0].cn0 * 100 - 11.0141220093 * 100), 0.05)
      << "incorrect value for states[0].cn0, expected 11.0141220093, is "
      << last_msg_->states[0].cn0;
  EXPECT_EQ(last_msg_->states[0].prn, 0)
      << "incorrect value for states[0].prn, expected 0, is "
      << last_msg_->states[0].prn;
  EXPECT_EQ(last_msg_->states[0].state, 1)
      << "incorrect value for states[0].state, expected 1, is "
      << last_msg_->states[0].state;
  EXPECT_LT((last_msg_->states[1].cn0 * 100 - 10.8851480484 * 100), 0.05)
      << "incorrect value for states[1].cn0, expected 10.8851480484, is "
      << last_msg_->states[1].cn0;
  EXPECT_EQ(last_msg_->states[1].prn, 2)
      << "incorrect value for states[1].prn, expected 2, is "
      << last_msg_->states[1].prn;
  EXPECT_EQ(last_msg_->states[1].state, 1)
      << "incorrect value for states[1].state, expected 1, is "
      << last_msg_->states[1].state;
  EXPECT_LT((last_msg_->states[2].cn0 * 100 - 10.1313514709 * 100), 0.05)
      << "incorrect value for states[2].cn0, expected 10.1313514709, is "
      << last_msg_->states[2].cn0;
  EXPECT_EQ(last_msg_->states[2].prn, 3)
      << "incorrect value for states[2].prn, expected 3, is "
      << last_msg_->states[2].prn;
  EXPECT_EQ(last_msg_->states[2].state, 1)
      << "incorrect value for states[2].state, expected 1, is "
      << last_msg_->states[2].state;
  EXPECT_LT((last_msg_->states[3].cn0 * 100 - 14.8290262222 * 100), 0.05)
      << "incorrect value for states[3].cn0, expected 14.8290262222, is "
      << last_msg_->states[3].cn0;
  EXPECT_EQ(last_msg_->states[3].prn, 7)
      << "incorrect value for states[3].prn, expected 7, is "
      << last_msg_->states[3].prn;
  EXPECT_EQ(last_msg_->states[3].state, 1)
      << "incorrect value for states[3].state, expected 1, is "
      << last_msg_->states[3].state;
  EXPECT_LT((last_msg_->states[4].cn0 * 100 - 7.79104471207 * 100), 0.05)
      << "incorrect value for states[4].cn0, expected 7.79104471207, is "
      << last_msg_->states[4].cn0;
  EXPECT_EQ(last_msg_->states[4].prn, 10)
      << "incorrect value for states[4].prn, expected 10, is "
      << last_msg_->states[4].prn;
  EXPECT_EQ(last_msg_->states[4].state, 1)
      << "incorrect value for states[4].state, expected 1, is "
      << last_msg_->states[4].state;
  EXPECT_LT((last_msg_->states[5].cn0 * 100 - 4.86816120148 * 100), 0.05)
      << "incorrect value for states[5].cn0, expected 4.86816120148, is "
      << last_msg_->states[5].cn0;
  EXPECT_EQ(last_msg_->states[5].prn, 13)
      << "incorrect value for states[5].prn, expected 13, is "
      << last_msg_->states[5].prn;
  EXPECT_EQ(last_msg_->states[5].state, 1)
      << "incorrect value for states[5].state, expected 1, is "
      << last_msg_->states[5].state;
  EXPECT_LT((last_msg_->states[6].cn0 * 100 - 6.72109556198 * 100), 0.05)
      << "incorrect value for states[6].cn0, expected 6.72109556198, is "
      << last_msg_->states[6].cn0;
  EXPECT_EQ(last_msg_->states[6].prn, 22)
      << "incorrect value for states[6].prn, expected 22, is "
      << last_msg_->states[6].prn;
  EXPECT_EQ(last_msg_->states[6].state, 1)
      << "incorrect value for states[6].state, expected 1, is "
      << last_msg_->states[6].state;
  EXPECT_LT((last_msg_->states[7].cn0 * 100 - 12.9713230133 * 100), 0.05)
      << "incorrect value for states[7].cn0, expected 12.9713230133, is "
      << last_msg_->states[7].cn0;
  EXPECT_EQ(last_msg_->states[7].prn, 30)
      << "incorrect value for states[7].prn, expected 30, is "
      << last_msg_->states[7].prn;
  EXPECT_EQ(last_msg_->states[7].state, 1)
      << "incorrect value for states[7].state, expected 1, is "
      << last_msg_->states[7].state;
  EXPECT_LT((last_msg_->states[8].cn0 * 100 - 15.4814052582 * 100), 0.05)
      << "incorrect value for states[8].cn0, expected 15.4814052582, is "
      << last_msg_->states[8].cn0;
  EXPECT_EQ(last_msg_->states[8].prn, 31)
      << "incorrect value for states[8].prn, expected 31, is "
      << last_msg_->states[8].prn;
  EXPECT_EQ(last_msg_->states[8].state, 1)
      << "incorrect value for states[8].state, expected 1, is "
      << last_msg_->states[8].state;
  EXPECT_LT((last_msg_->states[9].cn0 * 100 - 3.88343548775 * 100), 0.05)
      << "incorrect value for states[9].cn0, expected 3.88343548775, is "
      << last_msg_->states[9].cn0;
  EXPECT_EQ(last_msg_->states[9].prn, 25)
      << "incorrect value for states[9].prn, expected 25, is "
      << last_msg_->states[9].prn;
  EXPECT_EQ(last_msg_->states[9].state, 1)
      << "incorrect value for states[9].state, expected 1, is "
      << last_msg_->states[9].state;
  EXPECT_LT((last_msg_->states[10].cn0 * 100 - 4.06148862839 * 100), 0.05)
      << "incorrect value for states[10].cn0, expected 4.06148862839, is "
      << last_msg_->states[10].cn0;
  EXPECT_EQ(last_msg_->states[10].prn, 6)
      << "incorrect value for states[10].prn, expected 6, is "
      << last_msg_->states[10].prn;
  EXPECT_EQ(last_msg_->states[10].state, 1)
      << "incorrect value for states[10].state, expected 1, is "
      << last_msg_->states[10].state;
}
class Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_tracking_state_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_tracking_state_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_tracking_state_dep_a_t *>(last_msg_storage_)),
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
                      const msg_tracking_state_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_tracking_state_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA2, Test) {
  uint8_t encoded_frame[] = {
      85,  22,  0,   195, 4,   66,  1,   0,  141, 76,  60,  65,  1,   2,   69,
      139, 46,  65,  1,   3,   146, 27,  30, 65,  1,   7,   235, 56,  97,  65,
      1,   10,  141, 213, 243, 64,  1,   13, 250, 170, 166, 64,  1,   22,  17,
      101, 201, 64,  1,   30,  172, 183, 83, 65,  1,   31,  238, 193, 120, 65,
      1,   25,  220, 48,  132, 64,  1,   6,  49,  214, 54,  64,  110, 179,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_tracking_state_dep_a_t *test_msg =
      (msg_tracking_state_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[0].cn0 = 11.768689155578613;
  test_msg->states[0].prn = 0;
  test_msg->states[0].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[1].cn0 = 10.909001350402832;
  test_msg->states[1].prn = 2;
  test_msg->states[1].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[2].cn0 = 9.881731033325195;
  test_msg->states[2].prn = 3;
  test_msg->states[2].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[3].cn0 = 14.076395988464355;
  test_msg->states[3].prn = 7;
  test_msg->states[3].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[4].cn0 = 7.619818210601807;
  test_msg->states[4].prn = 10;
  test_msg->states[4].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[5].cn0 = 5.208371162414551;
  test_msg->states[5].prn = 13;
  test_msg->states[5].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[6].cn0 = 6.2935872077941895;
  test_msg->states[6].prn = 22;
  test_msg->states[6].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[7].cn0 = 13.232341766357422;
  test_msg->states[7].prn = 30;
  test_msg->states[7].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[8].cn0 = 15.547346115112305;
  test_msg->states[8].prn = 31;
  test_msg->states[8].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[9].cn0 = 4.130964279174805;
  test_msg->states[9].prn = 25;
  test_msg->states[9].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[10].cn0 = 2.856823205947876;
  test_msg->states[10].prn = 6;
  test_msg->states[10].state = 1;

  EXPECT_EQ(send_message(0x16, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->states[0].cn0 * 100 - 11.7686891556 * 100), 0.05)
      << "incorrect value for states[0].cn0, expected 11.7686891556, is "
      << last_msg_->states[0].cn0;
  EXPECT_EQ(last_msg_->states[0].prn, 0)
      << "incorrect value for states[0].prn, expected 0, is "
      << last_msg_->states[0].prn;
  EXPECT_EQ(last_msg_->states[0].state, 1)
      << "incorrect value for states[0].state, expected 1, is "
      << last_msg_->states[0].state;
  EXPECT_LT((last_msg_->states[1].cn0 * 100 - 10.9090013504 * 100), 0.05)
      << "incorrect value for states[1].cn0, expected 10.9090013504, is "
      << last_msg_->states[1].cn0;
  EXPECT_EQ(last_msg_->states[1].prn, 2)
      << "incorrect value for states[1].prn, expected 2, is "
      << last_msg_->states[1].prn;
  EXPECT_EQ(last_msg_->states[1].state, 1)
      << "incorrect value for states[1].state, expected 1, is "
      << last_msg_->states[1].state;
  EXPECT_LT((last_msg_->states[2].cn0 * 100 - 9.88173103333 * 100), 0.05)
      << "incorrect value for states[2].cn0, expected 9.88173103333, is "
      << last_msg_->states[2].cn0;
  EXPECT_EQ(last_msg_->states[2].prn, 3)
      << "incorrect value for states[2].prn, expected 3, is "
      << last_msg_->states[2].prn;
  EXPECT_EQ(last_msg_->states[2].state, 1)
      << "incorrect value for states[2].state, expected 1, is "
      << last_msg_->states[2].state;
  EXPECT_LT((last_msg_->states[3].cn0 * 100 - 14.0763959885 * 100), 0.05)
      << "incorrect value for states[3].cn0, expected 14.0763959885, is "
      << last_msg_->states[3].cn0;
  EXPECT_EQ(last_msg_->states[3].prn, 7)
      << "incorrect value for states[3].prn, expected 7, is "
      << last_msg_->states[3].prn;
  EXPECT_EQ(last_msg_->states[3].state, 1)
      << "incorrect value for states[3].state, expected 1, is "
      << last_msg_->states[3].state;
  EXPECT_LT((last_msg_->states[4].cn0 * 100 - 7.6198182106 * 100), 0.05)
      << "incorrect value for states[4].cn0, expected 7.6198182106, is "
      << last_msg_->states[4].cn0;
  EXPECT_EQ(last_msg_->states[4].prn, 10)
      << "incorrect value for states[4].prn, expected 10, is "
      << last_msg_->states[4].prn;
  EXPECT_EQ(last_msg_->states[4].state, 1)
      << "incorrect value for states[4].state, expected 1, is "
      << last_msg_->states[4].state;
  EXPECT_LT((last_msg_->states[5].cn0 * 100 - 5.20837116241 * 100), 0.05)
      << "incorrect value for states[5].cn0, expected 5.20837116241, is "
      << last_msg_->states[5].cn0;
  EXPECT_EQ(last_msg_->states[5].prn, 13)
      << "incorrect value for states[5].prn, expected 13, is "
      << last_msg_->states[5].prn;
  EXPECT_EQ(last_msg_->states[5].state, 1)
      << "incorrect value for states[5].state, expected 1, is "
      << last_msg_->states[5].state;
  EXPECT_LT((last_msg_->states[6].cn0 * 100 - 6.29358720779 * 100), 0.05)
      << "incorrect value for states[6].cn0, expected 6.29358720779, is "
      << last_msg_->states[6].cn0;
  EXPECT_EQ(last_msg_->states[6].prn, 22)
      << "incorrect value for states[6].prn, expected 22, is "
      << last_msg_->states[6].prn;
  EXPECT_EQ(last_msg_->states[6].state, 1)
      << "incorrect value for states[6].state, expected 1, is "
      << last_msg_->states[6].state;
  EXPECT_LT((last_msg_->states[7].cn0 * 100 - 13.2323417664 * 100), 0.05)
      << "incorrect value for states[7].cn0, expected 13.2323417664, is "
      << last_msg_->states[7].cn0;
  EXPECT_EQ(last_msg_->states[7].prn, 30)
      << "incorrect value for states[7].prn, expected 30, is "
      << last_msg_->states[7].prn;
  EXPECT_EQ(last_msg_->states[7].state, 1)
      << "incorrect value for states[7].state, expected 1, is "
      << last_msg_->states[7].state;
  EXPECT_LT((last_msg_->states[8].cn0 * 100 - 15.5473461151 * 100), 0.05)
      << "incorrect value for states[8].cn0, expected 15.5473461151, is "
      << last_msg_->states[8].cn0;
  EXPECT_EQ(last_msg_->states[8].prn, 31)
      << "incorrect value for states[8].prn, expected 31, is "
      << last_msg_->states[8].prn;
  EXPECT_EQ(last_msg_->states[8].state, 1)
      << "incorrect value for states[8].state, expected 1, is "
      << last_msg_->states[8].state;
  EXPECT_LT((last_msg_->states[9].cn0 * 100 - 4.13096427917 * 100), 0.05)
      << "incorrect value for states[9].cn0, expected 4.13096427917, is "
      << last_msg_->states[9].cn0;
  EXPECT_EQ(last_msg_->states[9].prn, 25)
      << "incorrect value for states[9].prn, expected 25, is "
      << last_msg_->states[9].prn;
  EXPECT_EQ(last_msg_->states[9].state, 1)
      << "incorrect value for states[9].state, expected 1, is "
      << last_msg_->states[9].state;
  EXPECT_LT((last_msg_->states[10].cn0 * 100 - 2.85682320595 * 100), 0.05)
      << "incorrect value for states[10].cn0, expected 2.85682320595, is "
      << last_msg_->states[10].cn0;
  EXPECT_EQ(last_msg_->states[10].prn, 6)
      << "incorrect value for states[10].prn, expected 6, is "
      << last_msg_->states[10].prn;
  EXPECT_EQ(last_msg_->states[10].state, 1)
      << "incorrect value for states[10].state, expected 1, is "
      << last_msg_->states[10].state;
}
class Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_tracking_state_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_tracking_state_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_tracking_state_dep_a_t *>(last_msg_storage_)),
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
                      const msg_tracking_state_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_tracking_state_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA3, Test) {
  uint8_t encoded_frame[] = {
      85, 22,  0,   195, 4,   66,  1, 0,   55,  143, 120, 66,  0,   0,   0,
      0,  128, 191, 0,   0,   0,   0, 128, 191, 0,   0,   0,   0,   128, 191,
      0,  0,   0,   0,   128, 191, 0, 0,   0,   0,   128, 191, 0,   0,   0,
      0,  128, 191, 0,   0,   0,   0, 128, 191, 0,   0,   0,   0,   128, 191,
      0,  0,   0,   0,   128, 191, 0, 0,   0,   0,   128, 191, 248, 89,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_tracking_state_dep_a_t *test_msg =
      (msg_tracking_state_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[0].cn0 = 62.13985824584961;
  test_msg->states[0].prn = 0;
  test_msg->states[0].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[1].cn0 = -1.0;
  test_msg->states[1].prn = 0;
  test_msg->states[1].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[2].cn0 = -1.0;
  test_msg->states[2].prn = 0;
  test_msg->states[2].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[3].cn0 = -1.0;
  test_msg->states[3].prn = 0;
  test_msg->states[3].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[4].cn0 = -1.0;
  test_msg->states[4].prn = 0;
  test_msg->states[4].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[5].cn0 = -1.0;
  test_msg->states[5].prn = 0;
  test_msg->states[5].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[6].cn0 = -1.0;
  test_msg->states[6].prn = 0;
  test_msg->states[6].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[7].cn0 = -1.0;
  test_msg->states[7].prn = 0;
  test_msg->states[7].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[8].cn0 = -1.0;
  test_msg->states[8].prn = 0;
  test_msg->states[8].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[9].cn0 = -1.0;
  test_msg->states[9].prn = 0;
  test_msg->states[9].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[10].cn0 = -1.0;
  test_msg->states[10].prn = 0;
  test_msg->states[10].state = 0;

  EXPECT_EQ(send_message(0x16, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->states[0].cn0 * 100 - 62.1398582458 * 100), 0.05)
      << "incorrect value for states[0].cn0, expected 62.1398582458, is "
      << last_msg_->states[0].cn0;
  EXPECT_EQ(last_msg_->states[0].prn, 0)
      << "incorrect value for states[0].prn, expected 0, is "
      << last_msg_->states[0].prn;
  EXPECT_EQ(last_msg_->states[0].state, 1)
      << "incorrect value for states[0].state, expected 1, is "
      << last_msg_->states[0].state;
  EXPECT_LT((last_msg_->states[1].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[1].cn0, expected -1.0, is "
      << last_msg_->states[1].cn0;
  EXPECT_EQ(last_msg_->states[1].prn, 0)
      << "incorrect value for states[1].prn, expected 0, is "
      << last_msg_->states[1].prn;
  EXPECT_EQ(last_msg_->states[1].state, 0)
      << "incorrect value for states[1].state, expected 0, is "
      << last_msg_->states[1].state;
  EXPECT_LT((last_msg_->states[2].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[2].cn0, expected -1.0, is "
      << last_msg_->states[2].cn0;
  EXPECT_EQ(last_msg_->states[2].prn, 0)
      << "incorrect value for states[2].prn, expected 0, is "
      << last_msg_->states[2].prn;
  EXPECT_EQ(last_msg_->states[2].state, 0)
      << "incorrect value for states[2].state, expected 0, is "
      << last_msg_->states[2].state;
  EXPECT_LT((last_msg_->states[3].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[3].cn0, expected -1.0, is "
      << last_msg_->states[3].cn0;
  EXPECT_EQ(last_msg_->states[3].prn, 0)
      << "incorrect value for states[3].prn, expected 0, is "
      << last_msg_->states[3].prn;
  EXPECT_EQ(last_msg_->states[3].state, 0)
      << "incorrect value for states[3].state, expected 0, is "
      << last_msg_->states[3].state;
  EXPECT_LT((last_msg_->states[4].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[4].cn0, expected -1.0, is "
      << last_msg_->states[4].cn0;
  EXPECT_EQ(last_msg_->states[4].prn, 0)
      << "incorrect value for states[4].prn, expected 0, is "
      << last_msg_->states[4].prn;
  EXPECT_EQ(last_msg_->states[4].state, 0)
      << "incorrect value for states[4].state, expected 0, is "
      << last_msg_->states[4].state;
  EXPECT_LT((last_msg_->states[5].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[5].cn0, expected -1.0, is "
      << last_msg_->states[5].cn0;
  EXPECT_EQ(last_msg_->states[5].prn, 0)
      << "incorrect value for states[5].prn, expected 0, is "
      << last_msg_->states[5].prn;
  EXPECT_EQ(last_msg_->states[5].state, 0)
      << "incorrect value for states[5].state, expected 0, is "
      << last_msg_->states[5].state;
  EXPECT_LT((last_msg_->states[6].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[6].cn0, expected -1.0, is "
      << last_msg_->states[6].cn0;
  EXPECT_EQ(last_msg_->states[6].prn, 0)
      << "incorrect value for states[6].prn, expected 0, is "
      << last_msg_->states[6].prn;
  EXPECT_EQ(last_msg_->states[6].state, 0)
      << "incorrect value for states[6].state, expected 0, is "
      << last_msg_->states[6].state;
  EXPECT_LT((last_msg_->states[7].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[7].cn0, expected -1.0, is "
      << last_msg_->states[7].cn0;
  EXPECT_EQ(last_msg_->states[7].prn, 0)
      << "incorrect value for states[7].prn, expected 0, is "
      << last_msg_->states[7].prn;
  EXPECT_EQ(last_msg_->states[7].state, 0)
      << "incorrect value for states[7].state, expected 0, is "
      << last_msg_->states[7].state;
  EXPECT_LT((last_msg_->states[8].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[8].cn0, expected -1.0, is "
      << last_msg_->states[8].cn0;
  EXPECT_EQ(last_msg_->states[8].prn, 0)
      << "incorrect value for states[8].prn, expected 0, is "
      << last_msg_->states[8].prn;
  EXPECT_EQ(last_msg_->states[8].state, 0)
      << "incorrect value for states[8].state, expected 0, is "
      << last_msg_->states[8].state;
  EXPECT_LT((last_msg_->states[9].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[9].cn0, expected -1.0, is "
      << last_msg_->states[9].cn0;
  EXPECT_EQ(last_msg_->states[9].prn, 0)
      << "incorrect value for states[9].prn, expected 0, is "
      << last_msg_->states[9].prn;
  EXPECT_EQ(last_msg_->states[9].state, 0)
      << "incorrect value for states[9].state, expected 0, is "
      << last_msg_->states[9].state;
  EXPECT_LT((last_msg_->states[10].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[10].cn0, expected -1.0, is "
      << last_msg_->states[10].cn0;
  EXPECT_EQ(last_msg_->states[10].prn, 0)
      << "incorrect value for states[10].prn, expected 0, is "
      << last_msg_->states[10].prn;
  EXPECT_EQ(last_msg_->states[10].state, 0)
      << "incorrect value for states[10].state, expected 0, is "
      << last_msg_->states[10].state;
}
class Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_tracking_state_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_tracking_state_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_tracking_state_dep_a_t *>(last_msg_storage_)),
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
                      const msg_tracking_state_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_tracking_state_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA4, Test) {
  uint8_t encoded_frame[] = {
      85, 22,  0,   195, 4,   66,  1,   0,   218, 14, 19,  66,  1,  2,   210,
      3,  21,  65,  1,   3,   234, 214, 134, 65,  0,  0,   0,   0,  128, 191,
      0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 0,  0,   0,
      0,  128, 191, 0,   0,   0,   0,   128, 191, 0,  0,   0,   0,  128, 191,
      0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 84, 101,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_tracking_state_dep_a_t *test_msg =
      (msg_tracking_state_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[0].cn0 = 36.764503479003906;
  test_msg->states[0].prn = 0;
  test_msg->states[0].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[1].cn0 = 9.313432693481445;
  test_msg->states[1].prn = 2;
  test_msg->states[1].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[2].cn0 = 16.854938507080078;
  test_msg->states[2].prn = 3;
  test_msg->states[2].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[3].cn0 = -1.0;
  test_msg->states[3].prn = 0;
  test_msg->states[3].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[4].cn0 = -1.0;
  test_msg->states[4].prn = 0;
  test_msg->states[4].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[5].cn0 = -1.0;
  test_msg->states[5].prn = 0;
  test_msg->states[5].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[6].cn0 = -1.0;
  test_msg->states[6].prn = 0;
  test_msg->states[6].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[7].cn0 = -1.0;
  test_msg->states[7].prn = 0;
  test_msg->states[7].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[8].cn0 = -1.0;
  test_msg->states[8].prn = 0;
  test_msg->states[8].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[9].cn0 = -1.0;
  test_msg->states[9].prn = 0;
  test_msg->states[9].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[10].cn0 = -1.0;
  test_msg->states[10].prn = 0;
  test_msg->states[10].state = 0;

  EXPECT_EQ(send_message(0x16, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->states[0].cn0 * 100 - 36.764503479 * 100), 0.05)
      << "incorrect value for states[0].cn0, expected 36.764503479, is "
      << last_msg_->states[0].cn0;
  EXPECT_EQ(last_msg_->states[0].prn, 0)
      << "incorrect value for states[0].prn, expected 0, is "
      << last_msg_->states[0].prn;
  EXPECT_EQ(last_msg_->states[0].state, 1)
      << "incorrect value for states[0].state, expected 1, is "
      << last_msg_->states[0].state;
  EXPECT_LT((last_msg_->states[1].cn0 * 100 - 9.31343269348 * 100), 0.05)
      << "incorrect value for states[1].cn0, expected 9.31343269348, is "
      << last_msg_->states[1].cn0;
  EXPECT_EQ(last_msg_->states[1].prn, 2)
      << "incorrect value for states[1].prn, expected 2, is "
      << last_msg_->states[1].prn;
  EXPECT_EQ(last_msg_->states[1].state, 1)
      << "incorrect value for states[1].state, expected 1, is "
      << last_msg_->states[1].state;
  EXPECT_LT((last_msg_->states[2].cn0 * 100 - 16.8549385071 * 100), 0.05)
      << "incorrect value for states[2].cn0, expected 16.8549385071, is "
      << last_msg_->states[2].cn0;
  EXPECT_EQ(last_msg_->states[2].prn, 3)
      << "incorrect value for states[2].prn, expected 3, is "
      << last_msg_->states[2].prn;
  EXPECT_EQ(last_msg_->states[2].state, 1)
      << "incorrect value for states[2].state, expected 1, is "
      << last_msg_->states[2].state;
  EXPECT_LT((last_msg_->states[3].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[3].cn0, expected -1.0, is "
      << last_msg_->states[3].cn0;
  EXPECT_EQ(last_msg_->states[3].prn, 0)
      << "incorrect value for states[3].prn, expected 0, is "
      << last_msg_->states[3].prn;
  EXPECT_EQ(last_msg_->states[3].state, 0)
      << "incorrect value for states[3].state, expected 0, is "
      << last_msg_->states[3].state;
  EXPECT_LT((last_msg_->states[4].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[4].cn0, expected -1.0, is "
      << last_msg_->states[4].cn0;
  EXPECT_EQ(last_msg_->states[4].prn, 0)
      << "incorrect value for states[4].prn, expected 0, is "
      << last_msg_->states[4].prn;
  EXPECT_EQ(last_msg_->states[4].state, 0)
      << "incorrect value for states[4].state, expected 0, is "
      << last_msg_->states[4].state;
  EXPECT_LT((last_msg_->states[5].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[5].cn0, expected -1.0, is "
      << last_msg_->states[5].cn0;
  EXPECT_EQ(last_msg_->states[5].prn, 0)
      << "incorrect value for states[5].prn, expected 0, is "
      << last_msg_->states[5].prn;
  EXPECT_EQ(last_msg_->states[5].state, 0)
      << "incorrect value for states[5].state, expected 0, is "
      << last_msg_->states[5].state;
  EXPECT_LT((last_msg_->states[6].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[6].cn0, expected -1.0, is "
      << last_msg_->states[6].cn0;
  EXPECT_EQ(last_msg_->states[6].prn, 0)
      << "incorrect value for states[6].prn, expected 0, is "
      << last_msg_->states[6].prn;
  EXPECT_EQ(last_msg_->states[6].state, 0)
      << "incorrect value for states[6].state, expected 0, is "
      << last_msg_->states[6].state;
  EXPECT_LT((last_msg_->states[7].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[7].cn0, expected -1.0, is "
      << last_msg_->states[7].cn0;
  EXPECT_EQ(last_msg_->states[7].prn, 0)
      << "incorrect value for states[7].prn, expected 0, is "
      << last_msg_->states[7].prn;
  EXPECT_EQ(last_msg_->states[7].state, 0)
      << "incorrect value for states[7].state, expected 0, is "
      << last_msg_->states[7].state;
  EXPECT_LT((last_msg_->states[8].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[8].cn0, expected -1.0, is "
      << last_msg_->states[8].cn0;
  EXPECT_EQ(last_msg_->states[8].prn, 0)
      << "incorrect value for states[8].prn, expected 0, is "
      << last_msg_->states[8].prn;
  EXPECT_EQ(last_msg_->states[8].state, 0)
      << "incorrect value for states[8].state, expected 0, is "
      << last_msg_->states[8].state;
  EXPECT_LT((last_msg_->states[9].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[9].cn0, expected -1.0, is "
      << last_msg_->states[9].cn0;
  EXPECT_EQ(last_msg_->states[9].prn, 0)
      << "incorrect value for states[9].prn, expected 0, is "
      << last_msg_->states[9].prn;
  EXPECT_EQ(last_msg_->states[9].state, 0)
      << "incorrect value for states[9].state, expected 0, is "
      << last_msg_->states[9].state;
  EXPECT_LT((last_msg_->states[10].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[10].cn0, expected -1.0, is "
      << last_msg_->states[10].cn0;
  EXPECT_EQ(last_msg_->states[10].prn, 0)
      << "incorrect value for states[10].prn, expected 0, is "
      << last_msg_->states[10].prn;
  EXPECT_EQ(last_msg_->states[10].state, 0)
      << "incorrect value for states[10].state, expected 0, is "
      << last_msg_->states[10].state;
}
class Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_tracking_state_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_tracking_state_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_tracking_state_dep_a_t *>(last_msg_storage_)),
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
                      const msg_tracking_state_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_tracking_state_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_tracking_MsgtrackingStateDepA5, Test) {
  uint8_t encoded_frame[] = {
      85, 22,  0,   195, 4,   66,  1,   0,   98,  39, 219, 65,  1,  2,   0,
      0,  56,  64,  1,   3,   121, 123, 7,   65,  0,  0,   0,   0,  128, 191,
      0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 0,  0,   0,
      0,  128, 191, 0,   0,   0,   0,   128, 191, 0,  0,   0,   0,  128, 191,
      0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 37, 123,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_tracking_state_dep_a_t *test_msg =
      (msg_tracking_state_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[0].cn0 = 27.394229888916016;
  test_msg->states[0].prn = 0;
  test_msg->states[0].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[1].cn0 = 2.875;
  test_msg->states[1].prn = 2;
  test_msg->states[1].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[2].cn0 = 8.467644691467285;
  test_msg->states[2].prn = 3;
  test_msg->states[2].state = 1;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[3].cn0 = -1.0;
  test_msg->states[3].prn = 0;
  test_msg->states[3].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[4].cn0 = -1.0;
  test_msg->states[4].prn = 0;
  test_msg->states[4].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[5].cn0 = -1.0;
  test_msg->states[5].prn = 0;
  test_msg->states[5].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[6].cn0 = -1.0;
  test_msg->states[6].prn = 0;
  test_msg->states[6].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[7].cn0 = -1.0;
  test_msg->states[7].prn = 0;
  test_msg->states[7].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[8].cn0 = -1.0;
  test_msg->states[8].prn = 0;
  test_msg->states[8].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[9].cn0 = -1.0;
  test_msg->states[9].prn = 0;
  test_msg->states[9].state = 0;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[10].cn0 = -1.0;
  test_msg->states[10].prn = 0;
  test_msg->states[10].state = 0;

  EXPECT_EQ(send_message(0x16, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->states[0].cn0 * 100 - 27.3942298889 * 100), 0.05)
      << "incorrect value for states[0].cn0, expected 27.3942298889, is "
      << last_msg_->states[0].cn0;
  EXPECT_EQ(last_msg_->states[0].prn, 0)
      << "incorrect value for states[0].prn, expected 0, is "
      << last_msg_->states[0].prn;
  EXPECT_EQ(last_msg_->states[0].state, 1)
      << "incorrect value for states[0].state, expected 1, is "
      << last_msg_->states[0].state;
  EXPECT_LT((last_msg_->states[1].cn0 * 100 - 2.875 * 100), 0.05)
      << "incorrect value for states[1].cn0, expected 2.875, is "
      << last_msg_->states[1].cn0;
  EXPECT_EQ(last_msg_->states[1].prn, 2)
      << "incorrect value for states[1].prn, expected 2, is "
      << last_msg_->states[1].prn;
  EXPECT_EQ(last_msg_->states[1].state, 1)
      << "incorrect value for states[1].state, expected 1, is "
      << last_msg_->states[1].state;
  EXPECT_LT((last_msg_->states[2].cn0 * 100 - 8.46764469147 * 100), 0.05)
      << "incorrect value for states[2].cn0, expected 8.46764469147, is "
      << last_msg_->states[2].cn0;
  EXPECT_EQ(last_msg_->states[2].prn, 3)
      << "incorrect value for states[2].prn, expected 3, is "
      << last_msg_->states[2].prn;
  EXPECT_EQ(last_msg_->states[2].state, 1)
      << "incorrect value for states[2].state, expected 1, is "
      << last_msg_->states[2].state;
  EXPECT_LT((last_msg_->states[3].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[3].cn0, expected -1.0, is "
      << last_msg_->states[3].cn0;
  EXPECT_EQ(last_msg_->states[3].prn, 0)
      << "incorrect value for states[3].prn, expected 0, is "
      << last_msg_->states[3].prn;
  EXPECT_EQ(last_msg_->states[3].state, 0)
      << "incorrect value for states[3].state, expected 0, is "
      << last_msg_->states[3].state;
  EXPECT_LT((last_msg_->states[4].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[4].cn0, expected -1.0, is "
      << last_msg_->states[4].cn0;
  EXPECT_EQ(last_msg_->states[4].prn, 0)
      << "incorrect value for states[4].prn, expected 0, is "
      << last_msg_->states[4].prn;
  EXPECT_EQ(last_msg_->states[4].state, 0)
      << "incorrect value for states[4].state, expected 0, is "
      << last_msg_->states[4].state;
  EXPECT_LT((last_msg_->states[5].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[5].cn0, expected -1.0, is "
      << last_msg_->states[5].cn0;
  EXPECT_EQ(last_msg_->states[5].prn, 0)
      << "incorrect value for states[5].prn, expected 0, is "
      << last_msg_->states[5].prn;
  EXPECT_EQ(last_msg_->states[5].state, 0)
      << "incorrect value for states[5].state, expected 0, is "
      << last_msg_->states[5].state;
  EXPECT_LT((last_msg_->states[6].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[6].cn0, expected -1.0, is "
      << last_msg_->states[6].cn0;
  EXPECT_EQ(last_msg_->states[6].prn, 0)
      << "incorrect value for states[6].prn, expected 0, is "
      << last_msg_->states[6].prn;
  EXPECT_EQ(last_msg_->states[6].state, 0)
      << "incorrect value for states[6].state, expected 0, is "
      << last_msg_->states[6].state;
  EXPECT_LT((last_msg_->states[7].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[7].cn0, expected -1.0, is "
      << last_msg_->states[7].cn0;
  EXPECT_EQ(last_msg_->states[7].prn, 0)
      << "incorrect value for states[7].prn, expected 0, is "
      << last_msg_->states[7].prn;
  EXPECT_EQ(last_msg_->states[7].state, 0)
      << "incorrect value for states[7].state, expected 0, is "
      << last_msg_->states[7].state;
  EXPECT_LT((last_msg_->states[8].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[8].cn0, expected -1.0, is "
      << last_msg_->states[8].cn0;
  EXPECT_EQ(last_msg_->states[8].prn, 0)
      << "incorrect value for states[8].prn, expected 0, is "
      << last_msg_->states[8].prn;
  EXPECT_EQ(last_msg_->states[8].state, 0)
      << "incorrect value for states[8].state, expected 0, is "
      << last_msg_->states[8].state;
  EXPECT_LT((last_msg_->states[9].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[9].cn0, expected -1.0, is "
      << last_msg_->states[9].cn0;
  EXPECT_EQ(last_msg_->states[9].prn, 0)
      << "incorrect value for states[9].prn, expected 0, is "
      << last_msg_->states[9].prn;
  EXPECT_EQ(last_msg_->states[9].state, 0)
      << "incorrect value for states[9].state, expected 0, is "
      << last_msg_->states[9].state;
  EXPECT_LT((last_msg_->states[10].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for states[10].cn0, expected -1.0, is "
      << last_msg_->states[10].cn0;
  EXPECT_EQ(last_msg_->states[10].prn, 0)
      << "incorrect value for states[10].prn, expected 0, is "
      << last_msg_->states[10].prn;
  EXPECT_EQ(last_msg_->states[10].state, 0)
      << "incorrect value for states[10].state, expected 0, is "
      << last_msg_->states[10].state;
}
