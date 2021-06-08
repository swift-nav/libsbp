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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevel.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgProtectionLevel0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_protection_level_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgProtectionLevel0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_protection_level_dep_a_t>(this),
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
                      const sbp_msg_protection_level_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_protection_level_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgProtectionLevel0, Test) {
  uint8_t encoded_frame[] = {
      85, 22, 2, 0, 16, 33, 136, 227, 233, 29, 0, 0,  0,   0,
      0,  0,  0, 0, 0,  0,  0,   0,   0,   0,  0, 0,  0,   0,
      0,  0,  0, 0, 0,  0,  0,   0,   0,   0,  0, 82, 195,
  };

  sbp_msg_protection_level_dep_a_t test_msg{};
  test_msg.flags = 0;
  test_msg.height = 0.0;
  test_msg.hpl = 0;
  test_msg.lat = 0.0;
  test_msg.lon = 0.0;
  test_msg.tow = 501867400;
  test_msg.vpl = 0;

  EXPECT_EQ(send_message(4096, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4096);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_LT((last_msg_.height * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 0.0, is "
      << last_msg_.height;
  EXPECT_EQ(last_msg_.hpl, 0)
      << "incorrect value for last_msg_.hpl, expected 0, is " << last_msg_.hpl;
  EXPECT_LT((last_msg_.lat * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 0.0, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected 0.0, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.tow, 501867400)
      << "incorrect value for last_msg_.tow, expected 501867400, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.vpl, 0)
      << "incorrect value for last_msg_.vpl, expected 0, is " << last_msg_.vpl;
}
