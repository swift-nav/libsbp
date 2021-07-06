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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgThreadState.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_piksi_MsgThreadState0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState0, Test) {
  uint8_t encoded_frame[] = {
      85, 23, 0, 246, 215, 26, 109, 97, 105, 110, 0, 0,   0, 0, 0, 0,  0,
      0,  0,  0, 0,   0,   0,  0,   0,  0,   0,   0, 156, 9, 0, 0, 73, 138,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 0;
  {
    const char assign_string[] = {
        (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 2460;

  EXPECT_EQ(send_message(0x17, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 0)
      << "incorrect value for cpu, expected 0, is " << last_msg_->cpu;
  {
    const char check_string[] = {
        (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 2460)
      << "incorrect value for stack_free, expected 2460, is "
      << last_msg_->stack_free;
}
class Test_legacy_auto_check_sbp_piksi_MsgThreadState1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState1, Test) {
  uint8_t encoded_frame[] = {
      85, 23, 0, 246, 215, 26, 105, 100, 108, 101, 0, 0,  0, 0, 0, 0,   0,
      0,  0,  0, 0,   0,   0,  0,   0,   0,   83,  2, 36, 0, 0, 0, 151, 20,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 595;
  {
    const char assign_string[] = {
        (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 36;

  EXPECT_EQ(send_message(0x17, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 595)
      << "incorrect value for cpu, expected 595, is " << last_msg_->cpu;
  {
    const char check_string[] = {
        (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 36)
      << "incorrect value for stack_free, expected 36, is "
      << last_msg_->stack_free;
}
class Test_legacy_auto_check_sbp_piksi_MsgThreadState2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState2, Test) {
  uint8_t encoded_frame[] = {
      85, 23, 0, 246, 215, 26, 78, 65, 80, 32, 73, 83,  82, 0, 0, 0,   0,
      0,  0,  0, 0,   0,   0,  0,  0,  0,  14, 0,  116, 4,  0, 0, 226, 60,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 14;
  {
    const char assign_string[] = {
        (char)78, (char)65, (char)80, (char)32, (char)73, (char)83, (char)82,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 1140;

  EXPECT_EQ(send_message(0x17, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 14)
      << "incorrect value for cpu, expected 14, is " << last_msg_->cpu;
  {
    const char check_string[] = {
        (char)78, (char)65, (char)80, (char)32, (char)73, (char)83, (char)82,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 1140)
      << "incorrect value for stack_free, expected 1140, is "
      << last_msg_->stack_free;
}
class Test_legacy_auto_check_sbp_piksi_MsgThreadState3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState3, Test) {
  uint8_t encoded_frame[] = {
      85, 23, 0, 246, 215, 26, 83, 66, 80, 0, 0, 0,   0,  0, 0, 0,  0,
      0,  0,  0, 0,   0,   0,  0,  0,  0,  1, 0, 196, 19, 0, 0, 90, 169,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 1;
  {
    const char assign_string[] = {
        (char)83, (char)66, (char)80, (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 5060;

  EXPECT_EQ(send_message(0x17, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 1)
      << "incorrect value for cpu, expected 1, is " << last_msg_->cpu;
  {
    const char check_string[] = {
        (char)83, (char)66, (char)80, (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 5060)
      << "incorrect value for stack_free, expected 5060, is "
      << last_msg_->stack_free;
}
class Test_legacy_auto_check_sbp_piksi_MsgThreadState4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState4, Test) {
  uint8_t encoded_frame[] = {
      85, 23, 0, 246, 215, 26, 109, 97, 110, 97, 103, 101, 32, 97, 99, 113, 0,
      0,  0,  0, 0,   0,   0,  0,   0,  0,   7,  0,   20,  9,  0,  0,  47,  75,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 7;
  {
    const char assign_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                  (char)103, (char)101, (char)32,  (char)97,
                                  (char)99,  (char)113, (char)0,   (char)0,
                                  (char)0,   (char)0,   (char)0,   (char)0,
                                  (char)0,   (char)0,   (char)0,   (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 2324;

  EXPECT_EQ(send_message(0x17, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 7)
      << "incorrect value for cpu, expected 7, is " << last_msg_->cpu;
  {
    const char check_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                 (char)103, (char)101, (char)32,  (char)97,
                                 (char)99,  (char)113, (char)0,   (char)0,
                                 (char)0,   (char)0,   (char)0,   (char)0,
                                 (char)0,   (char)0,   (char)0,   (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 2324)
      << "incorrect value for stack_free, expected 2324, is "
      << last_msg_->stack_free;
}
class Test_legacy_auto_check_sbp_piksi_MsgThreadState5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState5, Test) {
  uint8_t encoded_frame[] = {
      85, 23, 0, 195, 4, 26, 109, 97, 105, 110, 0, 0,   0, 0, 0, 0,   0,
      0,  0,  0, 0,   0, 0,  0,   0,  0,   0,   0, 148, 9, 0, 0, 195, 212,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 0;
  {
    const char assign_string[] = {
        (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 2452;

  EXPECT_EQ(send_message(0x17, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 0)
      << "incorrect value for cpu, expected 0, is " << last_msg_->cpu;
  {
    const char check_string[] = {
        (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0, (char)0,
        (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 2452)
      << "incorrect value for stack_free, expected 2452, is "
      << last_msg_->stack_free;
}
class Test_legacy_auto_check_sbp_piksi_MsgThreadState6
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState6()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState6, Test) {
  uint8_t encoded_frame[] = {
      85, 23, 0, 195, 4, 26, 105, 100, 108, 101, 0, 0,  0, 0, 0, 0,   0,
      0,  0,  0, 0,   0, 0,  0,   0,   0,   228, 1, 36, 0, 0, 0, 225, 18,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 484;
  {
    const char assign_string[] = {
        (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 36;

  EXPECT_EQ(send_message(0x17, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 484)
      << "incorrect value for cpu, expected 484, is " << last_msg_->cpu;
  {
    const char check_string[] = {
        (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 36)
      << "incorrect value for stack_free, expected 36, is "
      << last_msg_->stack_free;
}
class Test_legacy_auto_check_sbp_piksi_MsgThreadState7
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState7()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState7, Test) {
  uint8_t encoded_frame[] = {
      85, 23, 0, 195, 4, 26, 78, 65, 80, 32,  73, 83, 82, 0, 0, 0,   0,
      0,  0,  0, 0,   0, 0,  0,  0,  0,  138, 1,  92, 7,  0, 0, 166, 116,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 394;
  {
    const char assign_string[] = {
        (char)78, (char)65, (char)80, (char)32, (char)73, (char)83, (char)82,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 1884;

  EXPECT_EQ(send_message(0x17, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 394)
      << "incorrect value for cpu, expected 394, is " << last_msg_->cpu;
  {
    const char check_string[] = {
        (char)78, (char)65, (char)80, (char)32, (char)73, (char)83, (char)82,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
        (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 1884)
      << "incorrect value for stack_free, expected 1884, is "
      << last_msg_->stack_free;
}
class Test_legacy_auto_check_sbp_piksi_MsgThreadState8
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState8()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState8, Test) {
  uint8_t encoded_frame[] = {
      85, 23, 0, 195, 4, 26, 83, 66, 80, 0, 0, 0, 0,  0, 0, 0,   0,
      0,  0,  0, 0,   0, 0,  0,  0,  0,  1, 0, 4, 12, 0, 0, 229, 174,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 1;
  {
    const char assign_string[] = {
        (char)83, (char)66, (char)80, (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 3076;

  EXPECT_EQ(send_message(0x17, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 1)
      << "incorrect value for cpu, expected 1, is " << last_msg_->cpu;
  {
    const char check_string[] = {
        (char)83, (char)66, (char)80, (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 3076)
      << "incorrect value for stack_free, expected 3076, is "
      << last_msg_->stack_free;
}
class Test_legacy_auto_check_sbp_piksi_MsgThreadState9
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState9()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState9, Test) {
  uint8_t encoded_frame[] = {
      85, 23, 0, 195, 4, 26, 109, 97, 110, 97, 103, 101, 32, 97, 99, 113, 0,
      0,  0,  0, 0,   0, 0,  0,   0,  0,   10, 0,   124, 9,  0,  0,  52,  2,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 10;
  {
    const char assign_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                  (char)103, (char)101, (char)32,  (char)97,
                                  (char)99,  (char)113, (char)0,   (char)0,
                                  (char)0,   (char)0,   (char)0,   (char)0,
                                  (char)0,   (char)0,   (char)0,   (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 2428;

  EXPECT_EQ(send_message(0x17, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 10)
      << "incorrect value for cpu, expected 10, is " << last_msg_->cpu;
  {
    const char check_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                 (char)103, (char)101, (char)32,  (char)97,
                                 (char)99,  (char)113, (char)0,   (char)0,
                                 (char)0,   (char)0,   (char)0,   (char)0,
                                 (char)0,   (char)0,   (char)0,   (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 2428)
      << "incorrect value for stack_free, expected 2428, is "
      << last_msg_->stack_free;
}
class Test_legacy_auto_check_sbp_piksi_MsgThreadState10
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_thread_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgThreadState10()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_thread_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_thread_state_t *>(last_msg_storage_)),
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
                      const msg_thread_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_thread_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgThreadState10, Test) {
  uint8_t encoded_frame[] = {
      85,  23, 0, 195, 4, 26, 109, 97, 110, 97, 103, 101, 32, 116, 114, 97,  99,
      107, 0,  0, 0,   0, 0,  0,   0,  0,   0,  0,   28,  9,  0,   0,   122, 54,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_thread_state_t *test_msg = (msg_thread_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cpu = 0;
  {
    const char assign_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                  (char)103, (char)101, (char)32,  (char)116,
                                  (char)114, (char)97,  (char)99,  (char)107,
                                  (char)0,   (char)0,   (char)0,   (char)0,
                                  (char)0,   (char)0,   (char)0,   (char)0};
    memcpy(test_msg->name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->stack_free = 2332;

  EXPECT_EQ(send_message(0x17, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->cpu, 0)
      << "incorrect value for cpu, expected 0, is " << last_msg_->cpu;
  {
    const char check_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                 (char)103, (char)101, (char)32,  (char)116,
                                 (char)114, (char)97,  (char)99,  (char)107,
                                 (char)0,   (char)0,   (char)0,   (char)0,
                                 (char)0,   (char)0,   (char)0,   (char)0};
    EXPECT_EQ(memcmp(last_msg_->name, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->name, expected string '"
        << check_string << "', is '" << last_msg_->name << "'";
  }
  EXPECT_EQ(last_msg_->stack_free, 2332)
      << "incorrect value for stack_free, expected 2332, is "
      << last_msg_->stack_free;
}
