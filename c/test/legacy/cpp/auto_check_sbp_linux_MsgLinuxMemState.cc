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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxMemState.yaml by generate.py.
// Do not modify by hand!

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
#include <libsbp/legacy/linux.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_linux_MsgLinuxMemState0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_linux_mem_state_t> {
 public:
  Test_legacy_auto_check_sbp_linux_MsgLinuxMemState0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_linux_mem_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_linux_mem_state_t *>(last_msg_storage_)),
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
                      const msg_linux_mem_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_linux_mem_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_linux_MsgLinuxMemState0, Test) {
  uint8_t encoded_frame[] = {
      85,  9,   127, 95,  253, 70,  154, 191, 223, 19,  247, 53,  26,
      187, 76,  112, 114, 111, 99,  101, 115, 115, 45,  110, 97,  109,
      101, 0,   0,   0,   47,  112, 97,  116, 104, 47,  116, 111, 47,
      112, 114, 111, 99,  101, 115, 115, 45,  110, 97,  109, 101, 32,
      97,  114, 103, 48,  32,  97,  114, 103, 49,  32,  97,  114, 103,
      50,  32,  97,  114, 103, 51,  32,  97,  114, 103, 52,  3,   181,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_linux_mem_state_t *test_msg = (msg_linux_mem_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  {
    const char assign_string[] = {
        (char)47,  (char)112, (char)97,  (char)116, (char)104, (char)47,
        (char)116, (char)111, (char)47,  (char)112, (char)114, (char)111,
        (char)99,  (char)101, (char)115, (char)115, (char)45,  (char)110,
        (char)97,  (char)109, (char)101, (char)32,  (char)97,  (char)114,
        (char)103, (char)48,  (char)32,  (char)97,  (char)114, (char)103,
        (char)49,  (char)32,  (char)97,  (char)114, (char)103, (char)50,
        (char)32,  (char)97,  (char)114, (char)103, (char)51,  (char)32,
        (char)97,  (char)114, (char)103, (char)52};
    memcpy(test_msg->cmdline, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->cmdline) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->flags = 76;
  test_msg->index = 154;
  test_msg->pid = 57279;
  test_msg->pmem = 19;
  test_msg->time = 3139057143;
  {
    const char assign_string[] = {(char)112, (char)114, (char)111, (char)99,
                                  (char)101, (char)115, (char)115, (char)45,
                                  (char)110, (char)97,  (char)109, (char)101,
                                  (char)0,   (char)0,   (char)0};
    memcpy(test_msg->tname, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->tname) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }

  EXPECT_EQ(send_message(0x7f09, 64863, test_msg_len, test_msg_storage),
            SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 64863);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  {
    const char check_string[] = {
        (char)47,  (char)112, (char)97,  (char)116, (char)104, (char)47,
        (char)116, (char)111, (char)47,  (char)112, (char)114, (char)111,
        (char)99,  (char)101, (char)115, (char)115, (char)45,  (char)110,
        (char)97,  (char)109, (char)101, (char)32,  (char)97,  (char)114,
        (char)103, (char)48,  (char)32,  (char)97,  (char)114, (char)103,
        (char)49,  (char)32,  (char)97,  (char)114, (char)103, (char)50,
        (char)32,  (char)97,  (char)114, (char)103, (char)51,  (char)32,
        (char)97,  (char)114, (char)103, (char)52};
    EXPECT_EQ(memcmp(last_msg_->cmdline, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->cmdline, expected string '"
        << check_string << "', is '" << last_msg_->cmdline << "'";
  }
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            76)
      << "incorrect value for flags, expected 76, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->index)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->index)),
            154)
      << "incorrect value for index, expected 154, is " << last_msg_->index;
  EXPECT_EQ(get_as<decltype(last_msg_->pid)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->pid)),
            57279)
      << "incorrect value for pid, expected 57279, is " << last_msg_->pid;
  EXPECT_EQ(get_as<decltype(last_msg_->pmem)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->pmem)),
            19)
      << "incorrect value for pmem, expected 19, is " << last_msg_->pmem;
  EXPECT_EQ(get_as<decltype(last_msg_->time)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->time)),
            3139057143)
      << "incorrect value for time, expected 3139057143, is "
      << last_msg_->time;
  {
    const char check_string[] = {(char)112, (char)114, (char)111, (char)99,
                                 (char)101, (char)115, (char)115, (char)45,
                                 (char)110, (char)97,  (char)109, (char)101,
                                 (char)0,   (char)0,   (char)0};
    EXPECT_EQ(memcmp(last_msg_->tname, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->tname, expected string '"
        << check_string << "', is '" << last_msg_->tname << "'";
  }
}
