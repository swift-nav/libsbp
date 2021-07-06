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
// spec/tests/yaml/swiftnav/sbp/logging/test_MsgPrintDep.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_logging_MsgPrintDep0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_print_dep_t> {
 public:
  Test_legacy_auto_check_sbp_logging_MsgPrintDep0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_print_dep_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_print_dep_t *>(last_msg_storage_)),
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
                      const msg_print_dep_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_print_dep_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_logging_MsgPrintDep0, Test) {
  uint8_t encoded_frame[] = {
      85,  16,  0,   34, 34, 43, 73, 78, 70, 79, 58,  32,  97,
      99,  113, 58,  32, 80, 82, 78, 32, 49, 53, 32,  102, 111,
      117, 110, 100, 32, 64, 32, 45, 50, 52, 57, 55,  32,  72,
      122, 44,  32,  50, 48, 32, 83, 78, 82, 10, 116, 103,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_print_dep_t *test_msg = (msg_print_dep_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  {
    const char assign_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
        (char)97,  (char)99,  (char)113, (char)58,  (char)32,  (char)80,
        (char)82,  (char)78,  (char)32,  (char)49,  (char)53,  (char)32,
        (char)102, (char)111, (char)117, (char)110, (char)100, (char)32,
        (char)64,  (char)32,  (char)45,  (char)50,  (char)52,  (char)57,
        (char)55,  (char)32,  (char)72,  (char)122, (char)44,  (char)32,
        (char)50,  (char)48,  (char)32,  (char)83,  (char)78,  (char)82,
        (char)10};
    memcpy(test_msg->text, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->text) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }

  EXPECT_EQ(send_message(0x10, 8738, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  {
    const char check_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
        (char)97,  (char)99,  (char)113, (char)58,  (char)32,  (char)80,
        (char)82,  (char)78,  (char)32,  (char)49,  (char)53,  (char)32,
        (char)102, (char)111, (char)117, (char)110, (char)100, (char)32,
        (char)64,  (char)32,  (char)45,  (char)50,  (char)52,  (char)57,
        (char)55,  (char)32,  (char)72,  (char)122, (char)44,  (char)32,
        (char)50,  (char)48,  (char)32,  (char)83,  (char)78,  (char)82,
        (char)10};
    EXPECT_EQ(memcmp(last_msg_->text, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->text, expected string '"
        << check_string << "', is '" << last_msg_->text << "'";
  }
}
class Test_legacy_auto_check_sbp_logging_MsgPrintDep1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_print_dep_t> {
 public:
  Test_legacy_auto_check_sbp_logging_MsgPrintDep1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_print_dep_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_print_dep_t *>(last_msg_storage_)),
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
                      const msg_print_dep_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_print_dep_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_logging_MsgPrintDep1, Test) {
  uint8_t encoded_frame[] = {
      85, 16, 0,  34, 34,  42, 73, 78,  70,  79,  58,  32,  97, 99, 113, 58, 32,
      80, 82, 78, 32, 51,  49, 32, 102, 111, 117, 110, 100, 32, 64, 32,  52, 50,
      52, 53, 32, 72, 122, 44, 32, 50,  49,  32,  83,  78,  82, 10, 140, 43,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_print_dep_t *test_msg = (msg_print_dep_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  {
    const char assign_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
        (char)97,  (char)99,  (char)113, (char)58,  (char)32,  (char)80,
        (char)82,  (char)78,  (char)32,  (char)51,  (char)49,  (char)32,
        (char)102, (char)111, (char)117, (char)110, (char)100, (char)32,
        (char)64,  (char)32,  (char)52,  (char)50,  (char)52,  (char)53,
        (char)32,  (char)72,  (char)122, (char)44,  (char)32,  (char)50,
        (char)49,  (char)32,  (char)83,  (char)78,  (char)82,  (char)10};
    memcpy(test_msg->text, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->text) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }

  EXPECT_EQ(send_message(0x10, 8738, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  {
    const char check_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
        (char)97,  (char)99,  (char)113, (char)58,  (char)32,  (char)80,
        (char)82,  (char)78,  (char)32,  (char)51,  (char)49,  (char)32,
        (char)102, (char)111, (char)117, (char)110, (char)100, (char)32,
        (char)64,  (char)32,  (char)52,  (char)50,  (char)52,  (char)53,
        (char)32,  (char)72,  (char)122, (char)44,  (char)32,  (char)50,
        (char)49,  (char)32,  (char)83,  (char)78,  (char)82,  (char)10};
    EXPECT_EQ(memcmp(last_msg_->text, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->text, expected string '"
        << check_string << "', is '" << last_msg_->text << "'";
  }
}
class Test_legacy_auto_check_sbp_logging_MsgPrintDep2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_print_dep_t> {
 public:
  Test_legacy_auto_check_sbp_logging_MsgPrintDep2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_print_dep_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_print_dep_t *>(last_msg_storage_)),
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
                      const msg_print_dep_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_print_dep_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_logging_MsgPrintDep2, Test) {
  uint8_t encoded_frame[] = {
      85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
      97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
      48, 32, 40,  80,  82,  78,  32, 49, 49,  41, 10,  23,  143,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_print_dep_t *test_msg = (msg_print_dep_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  {
    const char assign_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
        (char)68,  (char)105, (char)115, (char)97,  (char)98,  (char)108,
        (char)105, (char)110, (char)103, (char)32,  (char)99,  (char)104,
        (char)97,  (char)110, (char)110, (char)101, (char)108, (char)32,
        (char)48,  (char)32,  (char)40,  (char)80,  (char)82,  (char)78,
        (char)32,  (char)49,  (char)49,  (char)41,  (char)10};
    memcpy(test_msg->text, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->text) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }

  EXPECT_EQ(send_message(0x10, 8738, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  {
    const char check_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
        (char)68,  (char)105, (char)115, (char)97,  (char)98,  (char)108,
        (char)105, (char)110, (char)103, (char)32,  (char)99,  (char)104,
        (char)97,  (char)110, (char)110, (char)101, (char)108, (char)32,
        (char)48,  (char)32,  (char)40,  (char)80,  (char)82,  (char)78,
        (char)32,  (char)49,  (char)49,  (char)41,  (char)10};
    EXPECT_EQ(memcmp(last_msg_->text, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->text, expected string '"
        << check_string << "', is '" << last_msg_->text << "'";
  }
}
class Test_legacy_auto_check_sbp_logging_MsgPrintDep3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_print_dep_t> {
 public:
  Test_legacy_auto_check_sbp_logging_MsgPrintDep3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_print_dep_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_print_dep_t *>(last_msg_storage_)),
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
                      const msg_print_dep_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_print_dep_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_logging_MsgPrintDep3, Test) {
  uint8_t encoded_frame[] = {
      85,  16,  0,  34, 34, 41, 73, 78, 70,  79, 58,  32,  97,
      99,  113, 58, 32, 80, 82, 78, 32, 50,  32, 102, 111, 117,
      110, 100, 32, 64, 32, 51, 57, 57, 54,  32, 72,  122, 44,
      32,  50,  48, 32, 83, 78, 82, 10, 239, 48,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_print_dep_t *test_msg = (msg_print_dep_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  {
    const char assign_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58, (char)32,
        (char)97,  (char)99,  (char)113, (char)58,  (char)32, (char)80,
        (char)82,  (char)78,  (char)32,  (char)50,  (char)32, (char)102,
        (char)111, (char)117, (char)110, (char)100, (char)32, (char)64,
        (char)32,  (char)51,  (char)57,  (char)57,  (char)54, (char)32,
        (char)72,  (char)122, (char)44,  (char)32,  (char)50, (char)48,
        (char)32,  (char)83,  (char)78,  (char)82,  (char)10};
    memcpy(test_msg->text, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->text) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }

  EXPECT_EQ(send_message(0x10, 8738, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  {
    const char check_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58, (char)32,
        (char)97,  (char)99,  (char)113, (char)58,  (char)32, (char)80,
        (char)82,  (char)78,  (char)32,  (char)50,  (char)32, (char)102,
        (char)111, (char)117, (char)110, (char)100, (char)32, (char)64,
        (char)32,  (char)51,  (char)57,  (char)57,  (char)54, (char)32,
        (char)72,  (char)122, (char)44,  (char)32,  (char)50, (char)48,
        (char)32,  (char)83,  (char)78,  (char)82,  (char)10};
    EXPECT_EQ(memcmp(last_msg_->text, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->text, expected string '"
        << check_string << "', is '" << last_msg_->text << "'";
  }
}
class Test_legacy_auto_check_sbp_logging_MsgPrintDep4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_print_dep_t> {
 public:
  Test_legacy_auto_check_sbp_logging_MsgPrintDep4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_print_dep_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_print_dep_t *>(last_msg_storage_)),
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
                      const msg_print_dep_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_print_dep_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_logging_MsgPrintDep4, Test) {
  uint8_t encoded_frame[] = {
      85,  16,  0,  34, 34, 42, 73, 78, 70, 79, 58,  32,  97,
      99,  113, 58, 32, 80, 82, 78, 32, 52, 32, 102, 111, 117,
      110, 100, 32, 64, 32, 45, 55, 52, 57, 50, 32,  72,  122,
      44,  32,  50, 48, 32, 83, 78, 82, 10, 47, 248,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_print_dep_t *test_msg = (msg_print_dep_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  {
    const char assign_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58, (char)32,
        (char)97,  (char)99,  (char)113, (char)58,  (char)32, (char)80,
        (char)82,  (char)78,  (char)32,  (char)52,  (char)32, (char)102,
        (char)111, (char)117, (char)110, (char)100, (char)32, (char)64,
        (char)32,  (char)45,  (char)55,  (char)52,  (char)57, (char)50,
        (char)32,  (char)72,  (char)122, (char)44,  (char)32, (char)50,
        (char)48,  (char)32,  (char)83,  (char)78,  (char)82, (char)10};
    memcpy(test_msg->text, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->text) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }

  EXPECT_EQ(send_message(0x10, 8738, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  {
    const char check_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58, (char)32,
        (char)97,  (char)99,  (char)113, (char)58,  (char)32, (char)80,
        (char)82,  (char)78,  (char)32,  (char)52,  (char)32, (char)102,
        (char)111, (char)117, (char)110, (char)100, (char)32, (char)64,
        (char)32,  (char)45,  (char)55,  (char)52,  (char)57, (char)50,
        (char)32,  (char)72,  (char)122, (char)44,  (char)32, (char)50,
        (char)48,  (char)32,  (char)83,  (char)78,  (char)82, (char)10};
    EXPECT_EQ(memcmp(last_msg_->text, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->text, expected string '"
        << check_string << "', is '" << last_msg_->text << "'";
  }
}
class Test_legacy_auto_check_sbp_logging_MsgPrintDep5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_print_dep_t> {
 public:
  Test_legacy_auto_check_sbp_logging_MsgPrintDep5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_print_dep_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_print_dep_t *>(last_msg_storage_)),
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
                      const msg_print_dep_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_print_dep_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_logging_MsgPrintDep5, Test) {
  uint8_t encoded_frame[] = {
      85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
      97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
      49, 32, 40,  80,  82,  78,  32, 49, 53,  41, 10,  158, 139,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_print_dep_t *test_msg = (msg_print_dep_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  {
    const char assign_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
        (char)68,  (char)105, (char)115, (char)97,  (char)98,  (char)108,
        (char)105, (char)110, (char)103, (char)32,  (char)99,  (char)104,
        (char)97,  (char)110, (char)110, (char)101, (char)108, (char)32,
        (char)49,  (char)32,  (char)40,  (char)80,  (char)82,  (char)78,
        (char)32,  (char)49,  (char)53,  (char)41,  (char)10};
    memcpy(test_msg->text, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->text) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }

  EXPECT_EQ(send_message(0x10, 8738, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  {
    const char check_string[] = {
        (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
        (char)68,  (char)105, (char)115, (char)97,  (char)98,  (char)108,
        (char)105, (char)110, (char)103, (char)32,  (char)99,  (char)104,
        (char)97,  (char)110, (char)110, (char)101, (char)108, (char)32,
        (char)49,  (char)32,  (char)40,  (char)80,  (char)82,  (char)78,
        (char)32,  (char)49,  (char)53,  (char)41,  (char)10};
    EXPECT_EQ(memcmp(last_msg_->text, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->text, expected string '"
        << check_string << "', is '" << last_msg_->text << "'";
  }
}
