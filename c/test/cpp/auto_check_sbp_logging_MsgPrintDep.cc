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
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_logging_MsgPrintDep0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_print_dep_t> {
 public:
  Test_auto_check_sbp_logging_MsgPrintDep0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_print_dep_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_print_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_logging_MsgPrintDep0, Test) {
  uint8_t encoded_frame[] = {
      85,  16,  0,   34, 34, 43, 73, 78, 70, 79, 58,  32,  97,
      99,  113, 58,  32, 80, 82, 78, 32, 49, 53, 32,  102, 111,
      117, 110, 100, 32, 64, 32, 45, 50, 52, 57, 55,  32,  72,
      122, 44,  32,  50, 48, 32, 83, 78, 82, 10, 116, 103,
  };

  sbp_msg_print_dep_t test_msg{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &test_msg, "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n", false,
      &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg), 43);

  EXPECT_EQ(send_message(8738, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_, test_msg);

  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg_), 43);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&last_msg_),
               "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n");
}
class Test_auto_check_sbp_logging_MsgPrintDep1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_print_dep_t> {
 public:
  Test_auto_check_sbp_logging_MsgPrintDep1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_print_dep_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_print_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_logging_MsgPrintDep1, Test) {
  uint8_t encoded_frame[] = {
      85, 16, 0,  34, 34,  42, 73, 78,  70,  79,  58,  32,  97, 99, 113, 58, 32,
      80, 82, 78, 32, 51,  49, 32, 102, 111, 117, 110, 100, 32, 64, 32,  52, 50,
      52, 53, 32, 72, 122, 44, 32, 50,  49,  32,  83,  78,  82, 10, 140, 43,
  };

  sbp_msg_print_dep_t test_msg{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &test_msg, "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n", false,
      &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg), 42);

  EXPECT_EQ(send_message(8738, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_, test_msg);

  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg_), 42);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&last_msg_),
               "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n");
}
class Test_auto_check_sbp_logging_MsgPrintDep2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_print_dep_t> {
 public:
  Test_auto_check_sbp_logging_MsgPrintDep2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_print_dep_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_print_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_logging_MsgPrintDep2, Test) {
  uint8_t encoded_frame[] = {
      85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
      97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
      48, 32, 40,  80,  82,  78,  32, 49, 49,  41, 10,  23,  143,
  };

  sbp_msg_print_dep_t test_msg{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &test_msg, "INFO: Disabling channel 0 (PRN 11)\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: Disabling channel 0 (PRN 11)\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg), 35);

  EXPECT_EQ(send_message(8738, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_, test_msg);

  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg_), 35);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&last_msg_),
               "INFO: Disabling channel 0 (PRN 11)\n");
}
class Test_auto_check_sbp_logging_MsgPrintDep3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_print_dep_t> {
 public:
  Test_auto_check_sbp_logging_MsgPrintDep3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_print_dep_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_print_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_logging_MsgPrintDep3, Test) {
  uint8_t encoded_frame[] = {
      85,  16,  0,  34, 34, 41, 73, 78, 70,  79, 58,  32,  97,
      99,  113, 58, 32, 80, 82, 78, 32, 50,  32, 102, 111, 117,
      110, 100, 32, 64, 32, 51, 57, 57, 54,  32, 72,  122, 44,
      32,  50,  48, 32, 83, 78, 82, 10, 239, 48,
  };

  sbp_msg_print_dep_t test_msg{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &test_msg, "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n", false,
      &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg), 41);

  EXPECT_EQ(send_message(8738, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_, test_msg);

  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg_), 41);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&last_msg_),
               "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n");
}
class Test_auto_check_sbp_logging_MsgPrintDep4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_print_dep_t> {
 public:
  Test_auto_check_sbp_logging_MsgPrintDep4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_print_dep_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_print_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_logging_MsgPrintDep4, Test) {
  uint8_t encoded_frame[] = {
      85,  16,  0,  34, 34, 42, 73, 78, 70, 79, 58,  32,  97,
      99,  113, 58, 32, 80, 82, 78, 32, 52, 32, 102, 111, 117,
      110, 100, 32, 64, 32, 45, 55, 52, 57, 50, 32,  72,  122,
      44,  32,  50, 48, 32, 83, 78, 82, 10, 47, 248,
  };

  sbp_msg_print_dep_t test_msg{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &test_msg, "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n", false,
      &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg), 42);

  EXPECT_EQ(send_message(8738, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_, test_msg);

  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg_), 42);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&last_msg_),
               "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n");
}
class Test_auto_check_sbp_logging_MsgPrintDep5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_print_dep_t> {
 public:
  Test_auto_check_sbp_logging_MsgPrintDep5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_print_dep_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_print_dep_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_logging_MsgPrintDep5, Test) {
  uint8_t encoded_frame[] = {
      85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
      97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
      49, 32, 40,  80,  82,  78,  32, 49, 53,  41, 10,  158, 139,
  };

  sbp_msg_print_dep_t test_msg{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &test_msg, "INFO: Disabling channel 1 (PRN 15)\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: Disabling channel 1 (PRN 15)\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg), 35);

  EXPECT_EQ(send_message(8738, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 8738);
  EXPECT_EQ(last_msg_, test_msg);

  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg_), 35);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&last_msg_),
               "INFO: Disabling channel 1 (PRN 15)\n");
}
