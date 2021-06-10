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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNED.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgVelNED0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_vel_ned_t> {
 public:
  Test_auto_check_sbp_navigation_MsgVelNED0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_vel_ned_t>(this),
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
                      const sbp_msg_vel_ned_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgVelNED0, Test) {
  uint8_t encoded_frame[] = {
      85,  14,  2,   211, 136, 22,  40,  244, 122, 19, 3, 0,  0, 0,  252,
      255, 255, 255, 243, 255, 255, 255, 0,   0,   0,  0, 14, 0, 86, 209,
  };

  sbp_msg_vel_ned_t test_msg{};
  test_msg.d = -13;
  test_msg.e = -4;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = 3;
  test_msg.n_sats = 14;
  test_msg.tow = 326825000;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -13)
      << "incorrect value for last_msg_.d, expected -13, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, -4)
      << "incorrect value for last_msg_.e, expected -4, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, 3)
      << "incorrect value for last_msg_.n, expected 3, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 14)
      << "incorrect value for last_msg_.n_sats, expected 14, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326825000)
      << "incorrect value for last_msg_.tow, expected 326825000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgVelNED1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_vel_ned_t> {
 public:
  Test_auto_check_sbp_navigation_MsgVelNED1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_vel_ned_t>(this),
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
                      const sbp_msg_vel_ned_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgVelNED1, Test) {
  uint8_t encoded_frame[] = {
      85,  14,  2,   211, 136, 22,  28,  246, 122, 19, 252, 255, 255, 255, 255,
      255, 255, 255, 232, 255, 255, 255, 0,   0,   0,  0,   15,  0,   16,  228,
  };

  sbp_msg_vel_ned_t test_msg{};
  test_msg.d = -24;
  test_msg.e = -1;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = -4;
  test_msg.n_sats = 15;
  test_msg.tow = 326825500;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -24)
      << "incorrect value for last_msg_.d, expected -24, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, -1)
      << "incorrect value for last_msg_.e, expected -1, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, -4)
      << "incorrect value for last_msg_.n, expected -4, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326825500)
      << "incorrect value for last_msg_.tow, expected 326825500, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgVelNED2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_vel_ned_t> {
 public:
  Test_auto_check_sbp_navigation_MsgVelNED2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_vel_ned_t>(this),
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
                      const sbp_msg_vel_ned_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgVelNED2, Test) {
  uint8_t encoded_frame[] = {
      85,  14,  2,   211, 136, 22,  16,  248, 122, 19, 0, 0,  0, 0,  253,
      255, 255, 255, 244, 255, 255, 255, 0,   0,   0,  0, 15, 0, 11, 164,
  };

  sbp_msg_vel_ned_t test_msg{};
  test_msg.d = -12;
  test_msg.e = -3;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = 0;
  test_msg.n_sats = 15;
  test_msg.tow = 326826000;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -12)
      << "incorrect value for last_msg_.d, expected -12, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, -3)
      << "incorrect value for last_msg_.e, expected -3, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, 0)
      << "incorrect value for last_msg_.n, expected 0, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326826000)
      << "incorrect value for last_msg_.tow, expected 326826000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgVelNED3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_vel_ned_t> {
 public:
  Test_auto_check_sbp_navigation_MsgVelNED3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_vel_ned_t>(this),
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
                      const sbp_msg_vel_ned_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgVelNED3, Test) {
  uint8_t encoded_frame[] = {
      85, 14, 2, 211, 136, 22,  4,   250, 122, 19, 2, 0,  0, 0,   3,
      0,  0,  0, 232, 255, 255, 255, 0,   0,   0,  0, 15, 0, 152, 208,
  };

  sbp_msg_vel_ned_t test_msg{};
  test_msg.d = -24;
  test_msg.e = 3;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = 2;
  test_msg.n_sats = 15;
  test_msg.tow = 326826500;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -24)
      << "incorrect value for last_msg_.d, expected -24, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, 3)
      << "incorrect value for last_msg_.e, expected 3, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, 2)
      << "incorrect value for last_msg_.n, expected 2, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326826500)
      << "incorrect value for last_msg_.tow, expected 326826500, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgVelNED4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_vel_ned_t> {
 public:
  Test_auto_check_sbp_navigation_MsgVelNED4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_vel_ned_t>(this),
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
                      const sbp_msg_vel_ned_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgVelNED4, Test) {
  uint8_t encoded_frame[] = {
      85, 14, 2, 211, 136, 22,  248, 251, 122, 19, 1, 0,  0, 0,   0,
      0,  0,  0, 235, 255, 255, 255, 0,   0,   0,  0, 15, 0, 182, 120,
  };

  sbp_msg_vel_ned_t test_msg{};
  test_msg.d = -21;
  test_msg.e = 0;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = 1;
  test_msg.n_sats = 15;
  test_msg.tow = 326827000;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -21)
      << "incorrect value for last_msg_.d, expected -21, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, 0)
      << "incorrect value for last_msg_.e, expected 0, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, 1)
      << "incorrect value for last_msg_.n, expected 1, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326827000)
      << "incorrect value for last_msg_.tow, expected 326827000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
