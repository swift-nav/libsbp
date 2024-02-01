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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingResourceCounter.yaml
// by generate.py. Do not modify by hand!

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
class Test_legacy_auto_check_sbp_profiling_MsgProfilingResourceCounter0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_profiling_resource_counter_t> {
 public:
  Test_legacy_auto_check_sbp_profiling_MsgProfilingResourceCounter0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_profiling_resource_counter_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_profiling_resource_counter_t *>(
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
                      const msg_profiling_resource_counter_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_profiling_resource_counter_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_profiling_MsgProfilingResourceCounter0,
       Test) {
  uint8_t encoded_frame[] = {
      85,  3,   207, 0,   16,  248, 1,   3,   70, 117, 115, 105, 111, 110, 32,
      101, 110, 103, 105, 110, 101, 0,   0,   0,  0,   0,   0,   0,   0,   1,
      2,   2,   0,   248, 38,  14,  0,   0,   0,  0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   78,  84,  82,  73,  80, 32,  99,  108, 105, 101, 110,
      116, 0,   0,   0,   0,   0,   0,   0,   0,  0,   1,   1,   1,   1,   230,
      73,  1,   0,   0,   0,   0,   0,   111, 3,  0,   0,   64,  76,  0,   0,
      83,  83,  82,  50,  79,  83,  82,  0,   0,  0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   1,   1,   1,  0,   72,  13,  66,  0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   80,  101, 114, 105,
      111, 100, 105, 99,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,
      0,   0,   1,   2,   1,   0,   72,  197, 3,  0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   73,  77, 85,  0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   1,   1,
      1,   1,   129, 71,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   95,
      102, 0,   0,   115, 98,  112, 0,   0,   0,  0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,  5,   2,   2,   2,   243, 169,
      0,   0,   0,   0,   0,   0,   187, 151, 3,  0,   242, 1,   0,   0,   181,
      153,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_profiling_resource_counter_t *test_msg =
      (msg_profiling_resource_counter_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->buckets) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->buckets[0]));
  }
  test_msg->buckets[0].cv = 2;
  test_msg->buckets[0].heap_bytes_alloc = 927480;
  test_msg->buckets[0].heap_bytes_free = 0;
  test_msg->buckets[0].io = 0;
  test_msg->buckets[0].io_read = 0;
  test_msg->buckets[0].io_write = 0;
  test_msg->buckets[0].mutex = 2;
  {
    const char assign_string[] = {
        (char)70,  (char)117, (char)115, (char)105, (char)111, (char)110,
        (char)32,  (char)101, (char)110, (char)103, (char)105, (char)110,
        (char)101, (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
        (char)0,   (char)0,   (char)0};
    memcpy(test_msg->buckets[0].name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->buckets[0].name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->buckets[0].thread = 1;
  if (sizeof(test_msg->buckets) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->buckets[0]));
  }
  test_msg->buckets[1].cv = 1;
  test_msg->buckets[1].heap_bytes_alloc = 84454;
  test_msg->buckets[1].heap_bytes_free = 0;
  test_msg->buckets[1].io = 1;
  test_msg->buckets[1].io_read = 19520;
  test_msg->buckets[1].io_write = 879;
  test_msg->buckets[1].mutex = 1;
  {
    const char assign_string[] = {
        (char)78, (char)84,  (char)82,  (char)73,  (char)80,  (char)32,
        (char)99, (char)108, (char)105, (char)101, (char)110, (char)116,
        (char)0,  (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
        (char)0,  (char)0,   (char)0};
    memcpy(test_msg->buckets[1].name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->buckets[1].name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->buckets[1].thread = 1;
  if (sizeof(test_msg->buckets) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->buckets[0]));
  }
  test_msg->buckets[2].cv = 1;
  test_msg->buckets[2].heap_bytes_alloc = 4328776;
  test_msg->buckets[2].heap_bytes_free = 0;
  test_msg->buckets[2].io = 0;
  test_msg->buckets[2].io_read = 0;
  test_msg->buckets[2].io_write = 0;
  test_msg->buckets[2].mutex = 1;
  {
    const char assign_string[] = {
        (char)83, (char)83, (char)82, (char)50, (char)79, (char)83, (char)82,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
    memcpy(test_msg->buckets[2].name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->buckets[2].name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->buckets[2].thread = 1;
  if (sizeof(test_msg->buckets) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->buckets[0]));
  }
  test_msg->buckets[3].cv = 1;
  test_msg->buckets[3].heap_bytes_alloc = 247112;
  test_msg->buckets[3].heap_bytes_free = 0;
  test_msg->buckets[3].io = 0;
  test_msg->buckets[3].io_read = 0;
  test_msg->buckets[3].io_write = 0;
  test_msg->buckets[3].mutex = 2;
  {
    const char assign_string[] = {
        (char)80,  (char)101, (char)114, (char)105, (char)111, (char)100,
        (char)105, (char)99,  (char)0,   (char)0,   (char)0,   (char)0,
        (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
        (char)0,   (char)0,   (char)0};
    memcpy(test_msg->buckets[3].name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->buckets[3].name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->buckets[3].thread = 1;
  if (sizeof(test_msg->buckets) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->buckets[0]));
  }
  test_msg->buckets[4].cv = 1;
  test_msg->buckets[4].heap_bytes_alloc = 18305;
  test_msg->buckets[4].heap_bytes_free = 0;
  test_msg->buckets[4].io = 1;
  test_msg->buckets[4].io_read = 26207;
  test_msg->buckets[4].io_write = 0;
  test_msg->buckets[4].mutex = 1;
  {
    const char assign_string[] = {
        (char)73, (char)77, (char)85, (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0};
    memcpy(test_msg->buckets[4].name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->buckets[4].name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->buckets[4].thread = 1;
  if (sizeof(test_msg->buckets) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->buckets[0]));
  }
  test_msg->buckets[5].cv = 2;
  test_msg->buckets[5].heap_bytes_alloc = 43507;
  test_msg->buckets[5].heap_bytes_free = 0;
  test_msg->buckets[5].io = 2;
  test_msg->buckets[5].io_read = 498;
  test_msg->buckets[5].io_write = 235451;
  test_msg->buckets[5].mutex = 2;
  {
    const char assign_string[] = {
        (char)115, (char)98, (char)112, (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0};
    memcpy(test_msg->buckets[5].name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->buckets[5].name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->buckets[5].thread = 5;
  test_msg->seq_len = 3;
  test_msg->seq_no = 1;

  EXPECT_EQ(send_message(0xcf03, 4096, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4096);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->buckets[0].cv, 2)
      << "incorrect value for buckets[0].cv, expected 2, is "
      << last_msg_->buckets[0].cv;
  EXPECT_EQ(last_msg_->buckets[0].heap_bytes_alloc, 927480)
      << "incorrect value for buckets[0].heap_bytes_alloc, expected 927480, is "
      << last_msg_->buckets[0].heap_bytes_alloc;
  EXPECT_EQ(last_msg_->buckets[0].heap_bytes_free, 0)
      << "incorrect value for buckets[0].heap_bytes_free, expected 0, is "
      << last_msg_->buckets[0].heap_bytes_free;
  EXPECT_EQ(last_msg_->buckets[0].io, 0)
      << "incorrect value for buckets[0].io, expected 0, is "
      << last_msg_->buckets[0].io;
  EXPECT_EQ(last_msg_->buckets[0].io_read, 0)
      << "incorrect value for buckets[0].io_read, expected 0, is "
      << last_msg_->buckets[0].io_read;
  EXPECT_EQ(last_msg_->buckets[0].io_write, 0)
      << "incorrect value for buckets[0].io_write, expected 0, is "
      << last_msg_->buckets[0].io_write;
  EXPECT_EQ(last_msg_->buckets[0].mutex, 2)
      << "incorrect value for buckets[0].mutex, expected 2, is "
      << last_msg_->buckets[0].mutex;
  {
    const char check_string[] = {
        (char)70,  (char)117, (char)115, (char)105, (char)111, (char)110,
        (char)32,  (char)101, (char)110, (char)103, (char)105, (char)110,
        (char)101, (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
        (char)0,   (char)0,   (char)0};
    EXPECT_EQ(
        memcmp(last_msg_->buckets[0].name, check_string, sizeof(check_string)),
        0)
        << "incorrect value for last_msg_->buckets[0].name, expected string '"
        << check_string << "', is '" << last_msg_->buckets[0].name << "'";
  }
  EXPECT_EQ(last_msg_->buckets[0].thread, 1)
      << "incorrect value for buckets[0].thread, expected 1, is "
      << last_msg_->buckets[0].thread;
  EXPECT_EQ(last_msg_->buckets[1].cv, 1)
      << "incorrect value for buckets[1].cv, expected 1, is "
      << last_msg_->buckets[1].cv;
  EXPECT_EQ(last_msg_->buckets[1].heap_bytes_alloc, 84454)
      << "incorrect value for buckets[1].heap_bytes_alloc, expected 84454, is "
      << last_msg_->buckets[1].heap_bytes_alloc;
  EXPECT_EQ(last_msg_->buckets[1].heap_bytes_free, 0)
      << "incorrect value for buckets[1].heap_bytes_free, expected 0, is "
      << last_msg_->buckets[1].heap_bytes_free;
  EXPECT_EQ(last_msg_->buckets[1].io, 1)
      << "incorrect value for buckets[1].io, expected 1, is "
      << last_msg_->buckets[1].io;
  EXPECT_EQ(last_msg_->buckets[1].io_read, 19520)
      << "incorrect value for buckets[1].io_read, expected 19520, is "
      << last_msg_->buckets[1].io_read;
  EXPECT_EQ(last_msg_->buckets[1].io_write, 879)
      << "incorrect value for buckets[1].io_write, expected 879, is "
      << last_msg_->buckets[1].io_write;
  EXPECT_EQ(last_msg_->buckets[1].mutex, 1)
      << "incorrect value for buckets[1].mutex, expected 1, is "
      << last_msg_->buckets[1].mutex;
  {
    const char check_string[] = {
        (char)78, (char)84,  (char)82,  (char)73,  (char)80,  (char)32,
        (char)99, (char)108, (char)105, (char)101, (char)110, (char)116,
        (char)0,  (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
        (char)0,  (char)0,   (char)0};
    EXPECT_EQ(
        memcmp(last_msg_->buckets[1].name, check_string, sizeof(check_string)),
        0)
        << "incorrect value for last_msg_->buckets[1].name, expected string '"
        << check_string << "', is '" << last_msg_->buckets[1].name << "'";
  }
  EXPECT_EQ(last_msg_->buckets[1].thread, 1)
      << "incorrect value for buckets[1].thread, expected 1, is "
      << last_msg_->buckets[1].thread;
  EXPECT_EQ(last_msg_->buckets[2].cv, 1)
      << "incorrect value for buckets[2].cv, expected 1, is "
      << last_msg_->buckets[2].cv;
  EXPECT_EQ(last_msg_->buckets[2].heap_bytes_alloc, 4328776)
      << "incorrect value for buckets[2].heap_bytes_alloc, expected 4328776, "
         "is "
      << last_msg_->buckets[2].heap_bytes_alloc;
  EXPECT_EQ(last_msg_->buckets[2].heap_bytes_free, 0)
      << "incorrect value for buckets[2].heap_bytes_free, expected 0, is "
      << last_msg_->buckets[2].heap_bytes_free;
  EXPECT_EQ(last_msg_->buckets[2].io, 0)
      << "incorrect value for buckets[2].io, expected 0, is "
      << last_msg_->buckets[2].io;
  EXPECT_EQ(last_msg_->buckets[2].io_read, 0)
      << "incorrect value for buckets[2].io_read, expected 0, is "
      << last_msg_->buckets[2].io_read;
  EXPECT_EQ(last_msg_->buckets[2].io_write, 0)
      << "incorrect value for buckets[2].io_write, expected 0, is "
      << last_msg_->buckets[2].io_write;
  EXPECT_EQ(last_msg_->buckets[2].mutex, 1)
      << "incorrect value for buckets[2].mutex, expected 1, is "
      << last_msg_->buckets[2].mutex;
  {
    const char check_string[] = {
        (char)83, (char)83, (char)82, (char)50, (char)79, (char)83, (char)82,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
    EXPECT_EQ(
        memcmp(last_msg_->buckets[2].name, check_string, sizeof(check_string)),
        0)
        << "incorrect value for last_msg_->buckets[2].name, expected string '"
        << check_string << "', is '" << last_msg_->buckets[2].name << "'";
  }
  EXPECT_EQ(last_msg_->buckets[2].thread, 1)
      << "incorrect value for buckets[2].thread, expected 1, is "
      << last_msg_->buckets[2].thread;
  EXPECT_EQ(last_msg_->buckets[3].cv, 1)
      << "incorrect value for buckets[3].cv, expected 1, is "
      << last_msg_->buckets[3].cv;
  EXPECT_EQ(last_msg_->buckets[3].heap_bytes_alloc, 247112)
      << "incorrect value for buckets[3].heap_bytes_alloc, expected 247112, is "
      << last_msg_->buckets[3].heap_bytes_alloc;
  EXPECT_EQ(last_msg_->buckets[3].heap_bytes_free, 0)
      << "incorrect value for buckets[3].heap_bytes_free, expected 0, is "
      << last_msg_->buckets[3].heap_bytes_free;
  EXPECT_EQ(last_msg_->buckets[3].io, 0)
      << "incorrect value for buckets[3].io, expected 0, is "
      << last_msg_->buckets[3].io;
  EXPECT_EQ(last_msg_->buckets[3].io_read, 0)
      << "incorrect value for buckets[3].io_read, expected 0, is "
      << last_msg_->buckets[3].io_read;
  EXPECT_EQ(last_msg_->buckets[3].io_write, 0)
      << "incorrect value for buckets[3].io_write, expected 0, is "
      << last_msg_->buckets[3].io_write;
  EXPECT_EQ(last_msg_->buckets[3].mutex, 2)
      << "incorrect value for buckets[3].mutex, expected 2, is "
      << last_msg_->buckets[3].mutex;
  {
    const char check_string[] = {
        (char)80,  (char)101, (char)114, (char)105, (char)111, (char)100,
        (char)105, (char)99,  (char)0,   (char)0,   (char)0,   (char)0,
        (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
        (char)0,   (char)0,   (char)0};
    EXPECT_EQ(
        memcmp(last_msg_->buckets[3].name, check_string, sizeof(check_string)),
        0)
        << "incorrect value for last_msg_->buckets[3].name, expected string '"
        << check_string << "', is '" << last_msg_->buckets[3].name << "'";
  }
  EXPECT_EQ(last_msg_->buckets[3].thread, 1)
      << "incorrect value for buckets[3].thread, expected 1, is "
      << last_msg_->buckets[3].thread;
  EXPECT_EQ(last_msg_->buckets[4].cv, 1)
      << "incorrect value for buckets[4].cv, expected 1, is "
      << last_msg_->buckets[4].cv;
  EXPECT_EQ(last_msg_->buckets[4].heap_bytes_alloc, 18305)
      << "incorrect value for buckets[4].heap_bytes_alloc, expected 18305, is "
      << last_msg_->buckets[4].heap_bytes_alloc;
  EXPECT_EQ(last_msg_->buckets[4].heap_bytes_free, 0)
      << "incorrect value for buckets[4].heap_bytes_free, expected 0, is "
      << last_msg_->buckets[4].heap_bytes_free;
  EXPECT_EQ(last_msg_->buckets[4].io, 1)
      << "incorrect value for buckets[4].io, expected 1, is "
      << last_msg_->buckets[4].io;
  EXPECT_EQ(last_msg_->buckets[4].io_read, 26207)
      << "incorrect value for buckets[4].io_read, expected 26207, is "
      << last_msg_->buckets[4].io_read;
  EXPECT_EQ(last_msg_->buckets[4].io_write, 0)
      << "incorrect value for buckets[4].io_write, expected 0, is "
      << last_msg_->buckets[4].io_write;
  EXPECT_EQ(last_msg_->buckets[4].mutex, 1)
      << "incorrect value for buckets[4].mutex, expected 1, is "
      << last_msg_->buckets[4].mutex;
  {
    const char check_string[] = {
        (char)73, (char)77, (char)85, (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0};
    EXPECT_EQ(
        memcmp(last_msg_->buckets[4].name, check_string, sizeof(check_string)),
        0)
        << "incorrect value for last_msg_->buckets[4].name, expected string '"
        << check_string << "', is '" << last_msg_->buckets[4].name << "'";
  }
  EXPECT_EQ(last_msg_->buckets[4].thread, 1)
      << "incorrect value for buckets[4].thread, expected 1, is "
      << last_msg_->buckets[4].thread;
  EXPECT_EQ(last_msg_->buckets[5].cv, 2)
      << "incorrect value for buckets[5].cv, expected 2, is "
      << last_msg_->buckets[5].cv;
  EXPECT_EQ(last_msg_->buckets[5].heap_bytes_alloc, 43507)
      << "incorrect value for buckets[5].heap_bytes_alloc, expected 43507, is "
      << last_msg_->buckets[5].heap_bytes_alloc;
  EXPECT_EQ(last_msg_->buckets[5].heap_bytes_free, 0)
      << "incorrect value for buckets[5].heap_bytes_free, expected 0, is "
      << last_msg_->buckets[5].heap_bytes_free;
  EXPECT_EQ(last_msg_->buckets[5].io, 2)
      << "incorrect value for buckets[5].io, expected 2, is "
      << last_msg_->buckets[5].io;
  EXPECT_EQ(last_msg_->buckets[5].io_read, 498)
      << "incorrect value for buckets[5].io_read, expected 498, is "
      << last_msg_->buckets[5].io_read;
  EXPECT_EQ(last_msg_->buckets[5].io_write, 235451)
      << "incorrect value for buckets[5].io_write, expected 235451, is "
      << last_msg_->buckets[5].io_write;
  EXPECT_EQ(last_msg_->buckets[5].mutex, 2)
      << "incorrect value for buckets[5].mutex, expected 2, is "
      << last_msg_->buckets[5].mutex;
  {
    const char check_string[] = {
        (char)115, (char)98, (char)112, (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0};
    EXPECT_EQ(
        memcmp(last_msg_->buckets[5].name, check_string, sizeof(check_string)),
        0)
        << "incorrect value for last_msg_->buckets[5].name, expected string '"
        << check_string << "', is '" << last_msg_->buckets[5].name << "'";
  }
  EXPECT_EQ(last_msg_->buckets[5].thread, 5)
      << "incorrect value for buckets[5].thread, expected 5, is "
      << last_msg_->buckets[5].thread;
  EXPECT_EQ(last_msg_->seq_len, 3)
      << "incorrect value for seq_len, expected 3, is " << last_msg_->seq_len;
  EXPECT_EQ(last_msg_->seq_no, 1)
      << "incorrect value for seq_no, expected 1, is " << last_msg_->seq_no;
}
