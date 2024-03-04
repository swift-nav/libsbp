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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingThreadInfo.yaml by
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
#include <libsbp/legacy/profiling.h>
class Test_legacy_auto_check_sbp_profiling_MsgProfilingThreadInfo0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_profiling_thread_info_t> {
 public:
  Test_legacy_auto_check_sbp_profiling_MsgProfilingThreadInfo0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_profiling_thread_info_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_profiling_thread_info_t *>(last_msg_storage_)),
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
                      const msg_profiling_thread_info_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_profiling_thread_info_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_profiling_MsgProfilingThreadInfo0, Test) {
  uint8_t encoded_frame[] = {
      85,  2,   207, 0,   16,  39,  119, 91,  10,  0,   0,   0,
      0,   0,   110, 5,   155, 0,   0,   0,   0,   0,   1,   0,
      0,   128, 0,   208, 53,  4,   0,   70,  117, 115, 105, 111,
      110, 32,  101, 110, 103, 105, 110, 101, 0,   242, 170,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_profiling_thread_info_t *test_msg =
      (msg_profiling_thread_info_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->age = 10159470;
  {
    const char assign_string[] = {(char)70,  (char)117, (char)115, (char)105,
                                  (char)111, (char)110, (char)32,  (char)101,
                                  (char)110, (char)103, (char)105, (char)110,
                                  (char)101, (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_size = 8388608;
  test_msg->stack_usage = 275920;
  test_msg->state = 1;
  test_msg->total_cpu_time = 678775;

  EXPECT_EQ(send_message(0xcf02, 4096, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4096);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->age, 10159470)
      << "incorrect value for age, expected 10159470, is " << last_msg_->age;
  {
    const char check_string[] = {(char)70,  (char)117, (char)115, (char)105,
                                 (char)111, (char)110, (char)32,  (char)101,
                                 (char)110, (char)103, (char)105, (char)110,
                                 (char)101, (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_size, 8388608)
      << "incorrect value for stack_size, expected 8388608, is "
      << last_msg_->stack_size;
  EXPECT_EQ(last_msg_->stack_usage, 275920)
      << "incorrect value for stack_usage, expected 275920, is "
      << last_msg_->stack_usage;
  EXPECT_EQ(last_msg_->state, 1)
      << "incorrect value for state, expected 1, is " << last_msg_->state;
  EXPECT_EQ(last_msg_->total_cpu_time, 678775)
      << "incorrect value for total_cpu_time, expected 678775, is "
      << last_msg_->total_cpu_time;
}
