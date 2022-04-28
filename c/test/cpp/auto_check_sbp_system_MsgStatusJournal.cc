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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusJournal.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
class Test_auto_check_sbp_system_MsgStatusJournal0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<msg_status_journal_t> {
 public:
  Test_auto_check_sbp_system_MsgStatusJournal0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<msg_status_journal_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_status_journal_t *>(last_msg_storage_)),
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
                      const msg_status_journal_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_status_journal_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_system_MsgStatusJournal0, Test) {
  uint8_t encoded_frame[] = {
      85, 253, 255, 211, 136, 34, 1, 0, 1, 4,  100, 0,  0,  0,
      7,  3,   146, 16,  0,   0,  6, 0, 1, 13, 186, 19, 0,  0,
      6,  0,   1,   14,  184, 34, 0, 0, 6, 0,  1,   15, 11, 55,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_status_journal_t *test_msg = (msg_status_journal_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->journal) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->journal[0]));
  }
  test_msg->journal[0].component = 6;
  test_msg->journal[0].generic = 1;
  test_msg->journal[0].specific = 13;
  test_msg->journal[0].uptime = 4242;
  if (sizeof(test_msg->journal) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->journal[0]));
  }
  test_msg->journal[1].component = 6;
  test_msg->journal[1].generic = 1;
  test_msg->journal[1].specific = 14;
  test_msg->journal[1].uptime = 5050;
  if (sizeof(test_msg->journal) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->journal[0]));
  }
  test_msg->journal[2].component = 6;
  test_msg->journal[2].generic = 1;
  test_msg->journal[2].specific = 15;
  test_msg->journal[2].uptime = 8888;
  test_msg->n_packets = 3;
  test_msg->n_status_reports = 100;
  test_msg->packet_index = 7;
  test_msg->reporting_system = 1;
  test_msg->sbp_version = 1025;

  EXPECT_EQ(send_message(0xFFFD, 35027, test_msg_len, test_msg_storage),
            SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->journal[0].component, 6)
      << "incorrect value for journal[0].component, expected 6, is "
      << last_msg_->journal[0].component;
  EXPECT_EQ(last_msg_->journal[0].generic, 1)
      << "incorrect value for journal[0].generic, expected 1, is "
      << last_msg_->journal[0].generic;
  EXPECT_EQ(last_msg_->journal[0].specific, 13)
      << "incorrect value for journal[0].specific, expected 13, is "
      << last_msg_->journal[0].specific;
  EXPECT_EQ(last_msg_->journal[0].uptime, 4242)
      << "incorrect value for journal[0].uptime, expected 4242, is "
      << last_msg_->journal[0].uptime;
  EXPECT_EQ(last_msg_->journal[1].component, 6)
      << "incorrect value for journal[1].component, expected 6, is "
      << last_msg_->journal[1].component;
  EXPECT_EQ(last_msg_->journal[1].generic, 1)
      << "incorrect value for journal[1].generic, expected 1, is "
      << last_msg_->journal[1].generic;
  EXPECT_EQ(last_msg_->journal[1].specific, 14)
      << "incorrect value for journal[1].specific, expected 14, is "
      << last_msg_->journal[1].specific;
  EXPECT_EQ(last_msg_->journal[1].uptime, 5050)
      << "incorrect value for journal[1].uptime, expected 5050, is "
      << last_msg_->journal[1].uptime;
  EXPECT_EQ(last_msg_->journal[2].component, 6)
      << "incorrect value for journal[2].component, expected 6, is "
      << last_msg_->journal[2].component;
  EXPECT_EQ(last_msg_->journal[2].generic, 1)
      << "incorrect value for journal[2].generic, expected 1, is "
      << last_msg_->journal[2].generic;
  EXPECT_EQ(last_msg_->journal[2].specific, 15)
      << "incorrect value for journal[2].specific, expected 15, is "
      << last_msg_->journal[2].specific;
  EXPECT_EQ(last_msg_->journal[2].uptime, 8888)
      << "incorrect value for journal[2].uptime, expected 8888, is "
      << last_msg_->journal[2].uptime;
  EXPECT_EQ(last_msg_->n_packets, 3)
      << "incorrect value for n_packets, expected 3, is "
      << last_msg_->n_packets;
  EXPECT_EQ(last_msg_->n_status_reports, 100)
      << "incorrect value for n_status_reports, expected 100, is "
      << last_msg_->n_status_reports;
  EXPECT_EQ(last_msg_->packet_index, 7)
      << "incorrect value for packet_index, expected 7, is "
      << last_msg_->packet_index;
  EXPECT_EQ(last_msg_->reporting_system, 1)
      << "incorrect value for reporting_system, expected 1, is "
      << last_msg_->reporting_system;
  EXPECT_EQ(last_msg_->sbp_version, 1025)
      << "incorrect value for sbp_version, expected 1025, is "
      << last_msg_->sbp_version;
}
class Test_auto_check_sbp_system_MsgStatusJournal1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<msg_status_journal_t> {
 public:
  Test_auto_check_sbp_system_MsgStatusJournal1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<msg_status_journal_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_status_journal_t *>(last_msg_storage_)),
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
                      const msg_status_journal_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_status_journal_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_system_MsgStatusJournal1, Test) {
  uint8_t encoded_frame[] = {
      85, 253, 255, 211, 136, 18, 1, 0, 1, 4, 100, 0,   0,
      0,  7,   1,   146, 16,  0,  0, 6, 0, 1, 13,  106, 72,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_status_journal_t *test_msg = (msg_status_journal_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->journal) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->journal[0]));
  }
  test_msg->journal[0].component = 6;
  test_msg->journal[0].generic = 1;
  test_msg->journal[0].specific = 13;
  test_msg->journal[0].uptime = 4242;
  test_msg->n_packets = 1;
  test_msg->n_status_reports = 100;
  test_msg->packet_index = 7;
  test_msg->reporting_system = 1;
  test_msg->sbp_version = 1025;

  EXPECT_EQ(send_message(0xFFFD, 35027, test_msg_len, test_msg_storage),
            SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->journal[0].component, 6)
      << "incorrect value for journal[0].component, expected 6, is "
      << last_msg_->journal[0].component;
  EXPECT_EQ(last_msg_->journal[0].generic, 1)
      << "incorrect value for journal[0].generic, expected 1, is "
      << last_msg_->journal[0].generic;
  EXPECT_EQ(last_msg_->journal[0].specific, 13)
      << "incorrect value for journal[0].specific, expected 13, is "
      << last_msg_->journal[0].specific;
  EXPECT_EQ(last_msg_->journal[0].uptime, 4242)
      << "incorrect value for journal[0].uptime, expected 4242, is "
      << last_msg_->journal[0].uptime;
  EXPECT_EQ(last_msg_->n_packets, 1)
      << "incorrect value for n_packets, expected 1, is "
      << last_msg_->n_packets;
  EXPECT_EQ(last_msg_->n_status_reports, 100)
      << "incorrect value for n_status_reports, expected 100, is "
      << last_msg_->n_status_reports;
  EXPECT_EQ(last_msg_->packet_index, 7)
      << "incorrect value for packet_index, expected 7, is "
      << last_msg_->packet_index;
  EXPECT_EQ(last_msg_->reporting_system, 1)
      << "incorrect value for reporting_system, expected 1, is "
      << last_msg_->reporting_system;
  EXPECT_EQ(last_msg_->sbp_version, 1025)
      << "incorrect value for sbp_version, expected 1025, is "
      << last_msg_->sbp_version;
}
