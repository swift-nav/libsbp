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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCTime.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgUTCTime0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_utc_time_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgUTCTime0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_utc_time_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_utc_time_t *>(last_msg_storage_)),
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
                      const msg_utc_time_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_utc_time_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgUTCTime0, Test) {
  uint8_t encoded_frame[] = {
      85, 3, 1, 21, 3,  16, 1, 24, 229, 233, 29,  229,
      7,  4, 9, 19, 24, 9,  0, 8,  175, 47,  199, 253,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_utc_time_t *test_msg = (msg_utc_time_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->day = 9;
  test_msg->flags = 1;
  test_msg->hours = 19;
  test_msg->minutes = 24;
  test_msg->month = 4;
  test_msg->ns = 800000000;
  test_msg->seconds = 9;
  test_msg->tow = 501867800;
  test_msg->year = 2021;

  EXPECT_EQ(send_message(0x103, 789, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 789);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->day, 9)
      << "incorrect value for day, expected 9, is " << last_msg_->day;
  EXPECT_EQ(last_msg_->flags, 1)
      << "incorrect value for flags, expected 1, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->hours, 19)
      << "incorrect value for hours, expected 19, is " << last_msg_->hours;
  EXPECT_EQ(last_msg_->minutes, 24)
      << "incorrect value for minutes, expected 24, is " << last_msg_->minutes;
  EXPECT_EQ(last_msg_->month, 4)
      << "incorrect value for month, expected 4, is " << last_msg_->month;
  EXPECT_EQ(last_msg_->ns, 800000000)
      << "incorrect value for ns, expected 800000000, is " << last_msg_->ns;
  EXPECT_EQ(last_msg_->seconds, 9)
      << "incorrect value for seconds, expected 9, is " << last_msg_->seconds;
  EXPECT_EQ(last_msg_->tow, 501867800)
      << "incorrect value for tow, expected 501867800, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->year, 2021)
      << "incorrect value for year, expected 2021, is " << last_msg_->year;
}
