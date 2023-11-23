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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSocketUsage.yaml by
// generate.py. Do not modify by hand!

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
#include <libsbp/legacy/linux.h>
class Test_legacy_auto_check_sbp_linux_MsgLinuxSocketUsage0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_linux_socket_usage_t> {
 public:
  Test_legacy_auto_check_sbp_linux_MsgLinuxSocketUsage0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_linux_socket_usage_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_linux_socket_usage_t *>(last_msg_storage_)),
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
                      const msg_linux_socket_usage_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_linux_socket_usage_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_linux_MsgLinuxSocketUsage0, Test) {
  uint8_t encoded_frame[] = {
      85,  5,   127, 114, 138, 72,  13,  196, 69,  173, 67,  222, 186, 181,
      246, 154, 251, 17,  224, 179, 26,  169, 177, 90,  149, 213, 214, 6,
      126, 64,  120, 185, 84,  131, 200, 111, 32,  141, 217, 209, 52,  14,
      190, 147, 159, 246, 141, 122, 212, 119, 131, 30,  120, 47,  25,  109,
      154, 65,  132, 164, 39,  30,  30,  175, 8,   44,  28,  111, 236, 240,
      176, 74,  159, 129, 154, 153, 162, 229, 130, 154,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_linux_socket_usage_t *test_msg =
      (msg_linux_socket_usage_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->avg_queue_depth = 2907030541;
  test_msg->max_queue_depth = 3048922691;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[0] = 39670;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[1] = 4603;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[2] = 46048;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[3] = 43290;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[4] = 23217;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[5] = 54677;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[6] = 1750;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[7] = 16510;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[8] = 47480;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[9] = 33620;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[10] = 28616;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[11] = 36128;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[12] = 53721;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[13] = 3636;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[14] = 37822;
  if (sizeof(test_msg->socket_state_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_state_counts[0]));
  }
  test_msg->socket_state_counts[15] = 63135;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[0] = 31373;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[1] = 30676;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[2] = 7811;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[3] = 12152;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[4] = 27929;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[5] = 16794;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[6] = 42116;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[7] = 7719;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[8] = 44830;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[9] = 11272;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[10] = 28444;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[11] = 61676;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[12] = 19120;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[13] = 33183;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[14] = 39322;
  if (sizeof(test_msg->socket_type_counts) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->socket_type_counts[0]));
  }
  test_msg->socket_type_counts[15] = 58786;

  EXPECT_EQ(send_message(0x7f05, 35442, test_msg_len, test_msg_storage),
            SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35442);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->avg_queue_depth, 2907030541)
      << "incorrect value for avg_queue_depth, expected 2907030541, is "
      << last_msg_->avg_queue_depth;
  EXPECT_EQ(last_msg_->max_queue_depth, 3048922691)
      << "incorrect value for max_queue_depth, expected 3048922691, is "
      << last_msg_->max_queue_depth;
  EXPECT_EQ(last_msg_->socket_state_counts[0], 39670)
      << "incorrect value for socket_state_counts[0], expected 39670, is "
      << last_msg_->socket_state_counts[0];
  EXPECT_EQ(last_msg_->socket_state_counts[1], 4603)
      << "incorrect value for socket_state_counts[1], expected 4603, is "
      << last_msg_->socket_state_counts[1];
  EXPECT_EQ(last_msg_->socket_state_counts[2], 46048)
      << "incorrect value for socket_state_counts[2], expected 46048, is "
      << last_msg_->socket_state_counts[2];
  EXPECT_EQ(last_msg_->socket_state_counts[3], 43290)
      << "incorrect value for socket_state_counts[3], expected 43290, is "
      << last_msg_->socket_state_counts[3];
  EXPECT_EQ(last_msg_->socket_state_counts[4], 23217)
      << "incorrect value for socket_state_counts[4], expected 23217, is "
      << last_msg_->socket_state_counts[4];
  EXPECT_EQ(last_msg_->socket_state_counts[5], 54677)
      << "incorrect value for socket_state_counts[5], expected 54677, is "
      << last_msg_->socket_state_counts[5];
  EXPECT_EQ(last_msg_->socket_state_counts[6], 1750)
      << "incorrect value for socket_state_counts[6], expected 1750, is "
      << last_msg_->socket_state_counts[6];
  EXPECT_EQ(last_msg_->socket_state_counts[7], 16510)
      << "incorrect value for socket_state_counts[7], expected 16510, is "
      << last_msg_->socket_state_counts[7];
  EXPECT_EQ(last_msg_->socket_state_counts[8], 47480)
      << "incorrect value for socket_state_counts[8], expected 47480, is "
      << last_msg_->socket_state_counts[8];
  EXPECT_EQ(last_msg_->socket_state_counts[9], 33620)
      << "incorrect value for socket_state_counts[9], expected 33620, is "
      << last_msg_->socket_state_counts[9];
  EXPECT_EQ(last_msg_->socket_state_counts[10], 28616)
      << "incorrect value for socket_state_counts[10], expected 28616, is "
      << last_msg_->socket_state_counts[10];
  EXPECT_EQ(last_msg_->socket_state_counts[11], 36128)
      << "incorrect value for socket_state_counts[11], expected 36128, is "
      << last_msg_->socket_state_counts[11];
  EXPECT_EQ(last_msg_->socket_state_counts[12], 53721)
      << "incorrect value for socket_state_counts[12], expected 53721, is "
      << last_msg_->socket_state_counts[12];
  EXPECT_EQ(last_msg_->socket_state_counts[13], 3636)
      << "incorrect value for socket_state_counts[13], expected 3636, is "
      << last_msg_->socket_state_counts[13];
  EXPECT_EQ(last_msg_->socket_state_counts[14], 37822)
      << "incorrect value for socket_state_counts[14], expected 37822, is "
      << last_msg_->socket_state_counts[14];
  EXPECT_EQ(last_msg_->socket_state_counts[15], 63135)
      << "incorrect value for socket_state_counts[15], expected 63135, is "
      << last_msg_->socket_state_counts[15];
  EXPECT_EQ(last_msg_->socket_type_counts[0], 31373)
      << "incorrect value for socket_type_counts[0], expected 31373, is "
      << last_msg_->socket_type_counts[0];
  EXPECT_EQ(last_msg_->socket_type_counts[1], 30676)
      << "incorrect value for socket_type_counts[1], expected 30676, is "
      << last_msg_->socket_type_counts[1];
  EXPECT_EQ(last_msg_->socket_type_counts[2], 7811)
      << "incorrect value for socket_type_counts[2], expected 7811, is "
      << last_msg_->socket_type_counts[2];
  EXPECT_EQ(last_msg_->socket_type_counts[3], 12152)
      << "incorrect value for socket_type_counts[3], expected 12152, is "
      << last_msg_->socket_type_counts[3];
  EXPECT_EQ(last_msg_->socket_type_counts[4], 27929)
      << "incorrect value for socket_type_counts[4], expected 27929, is "
      << last_msg_->socket_type_counts[4];
  EXPECT_EQ(last_msg_->socket_type_counts[5], 16794)
      << "incorrect value for socket_type_counts[5], expected 16794, is "
      << last_msg_->socket_type_counts[5];
  EXPECT_EQ(last_msg_->socket_type_counts[6], 42116)
      << "incorrect value for socket_type_counts[6], expected 42116, is "
      << last_msg_->socket_type_counts[6];
  EXPECT_EQ(last_msg_->socket_type_counts[7], 7719)
      << "incorrect value for socket_type_counts[7], expected 7719, is "
      << last_msg_->socket_type_counts[7];
  EXPECT_EQ(last_msg_->socket_type_counts[8], 44830)
      << "incorrect value for socket_type_counts[8], expected 44830, is "
      << last_msg_->socket_type_counts[8];
  EXPECT_EQ(last_msg_->socket_type_counts[9], 11272)
      << "incorrect value for socket_type_counts[9], expected 11272, is "
      << last_msg_->socket_type_counts[9];
  EXPECT_EQ(last_msg_->socket_type_counts[10], 28444)
      << "incorrect value for socket_type_counts[10], expected 28444, is "
      << last_msg_->socket_type_counts[10];
  EXPECT_EQ(last_msg_->socket_type_counts[11], 61676)
      << "incorrect value for socket_type_counts[11], expected 61676, is "
      << last_msg_->socket_type_counts[11];
  EXPECT_EQ(last_msg_->socket_type_counts[12], 19120)
      << "incorrect value for socket_type_counts[12], expected 19120, is "
      << last_msg_->socket_type_counts[12];
  EXPECT_EQ(last_msg_->socket_type_counts[13], 33183)
      << "incorrect value for socket_type_counts[13], expected 33183, is "
      << last_msg_->socket_type_counts[13];
  EXPECT_EQ(last_msg_->socket_type_counts[14], 39322)
      << "incorrect value for socket_type_counts[14], expected 39322, is "
      << last_msg_->socket_type_counts[14];
  EXPECT_EQ(last_msg_->socket_type_counts[15], 58786)
      << "incorrect value for socket_type_counts[15], expected 58786, is "
      << last_msg_->socket_type_counts[15];
}
