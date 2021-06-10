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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNEDDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  3,   2,   246, 215, 22, 20, 46, 39, 0, 243, 134, 254, 255, 234,
      153, 255, 255, 0,   0,   0,  0,  0,  0,  0, 0,   9,   1,   93,  193,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = 0;
  test_msg.e = -26134;
  test_msg.flags = 1;
  test_msg.h_accuracy = 0;
  test_msg.n = -96525;
  test_msg.n_sats = 9;
  test_msg.tow = 2567700;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, 0)
      << "incorrect value for last_msg_.d, expected 0, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, -26134)
      << "incorrect value for last_msg_.e, expected -26134, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 1)
      << "incorrect value for last_msg_.flags, expected 1, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, -96525)
      << "incorrect value for last_msg_.n, expected -96525, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567700)
      << "incorrect value for last_msg_.tow, expected 2567700, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA1, Test) {
  uint8_t encoded_frame[] = {
      85,  3,   2,   246, 215, 22, 120, 46, 39, 0, 139, 134, 254, 255, 109,
      155, 255, 255, 0,   0,   0,  0,   0,  0,  0, 0,   9,   1,   38,  39,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = 0;
  test_msg.e = -25747;
  test_msg.flags = 1;
  test_msg.h_accuracy = 0;
  test_msg.n = -96629;
  test_msg.n_sats = 9;
  test_msg.tow = 2567800;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, 0)
      << "incorrect value for last_msg_.d, expected 0, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, -25747)
      << "incorrect value for last_msg_.e, expected -25747, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 1)
      << "incorrect value for last_msg_.flags, expected 1, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, -96629)
      << "incorrect value for last_msg_.n, expected -96629, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567800)
      << "incorrect value for last_msg_.tow, expected 2567800, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA2, Test) {
  uint8_t encoded_frame[] = {
      85,  3,   2,   246, 215, 22, 220, 46, 39, 0, 37, 134, 254, 255, 240,
      156, 255, 255, 0,   0,   0,  0,   0,  0,  0, 0,  9,   1,   58,  133,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = 0;
  test_msg.e = -25360;
  test_msg.flags = 1;
  test_msg.h_accuracy = 0;
  test_msg.n = -96731;
  test_msg.n_sats = 9;
  test_msg.tow = 2567900;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, 0)
      << "incorrect value for last_msg_.d, expected 0, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, -25360)
      << "incorrect value for last_msg_.e, expected -25360, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 1)
      << "incorrect value for last_msg_.flags, expected 1, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, -96731)
      << "incorrect value for last_msg_.n, expected -96731, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567900)
      << "incorrect value for last_msg_.tow, expected 2567900, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA3, Test) {
  uint8_t encoded_frame[] = {
      85,  3,   2,   246, 215, 22, 64, 47, 39, 0, 193, 133, 254, 255, 115,
      158, 255, 255, 0,   0,   0,  0,  0,  0,  0, 0,   9,   1,   56,  214,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = 0;
  test_msg.e = -24973;
  test_msg.flags = 1;
  test_msg.h_accuracy = 0;
  test_msg.n = -96831;
  test_msg.n_sats = 9;
  test_msg.tow = 2568000;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, 0)
      << "incorrect value for last_msg_.d, expected 0, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, -24973)
      << "incorrect value for last_msg_.e, expected -24973, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 1)
      << "incorrect value for last_msg_.flags, expected 1, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, -96831)
      << "incorrect value for last_msg_.n, expected -96831, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2568000)
      << "incorrect value for last_msg_.tow, expected 2568000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA4, Test) {
  uint8_t encoded_frame[] = {
      85,  3,   2,   246, 215, 22, 164, 47, 39, 0, 93, 133, 254, 255, 246,
      159, 255, 255, 0,   0,   0,  0,   0,  0,  0, 0,  9,   1,   234, 244,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = 0;
  test_msg.e = -24586;
  test_msg.flags = 1;
  test_msg.h_accuracy = 0;
  test_msg.n = -96931;
  test_msg.n_sats = 9;
  test_msg.tow = 2568100;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, 0)
      << "incorrect value for last_msg_.d, expected 0, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, -24586)
      << "incorrect value for last_msg_.e, expected -24586, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 1)
      << "incorrect value for last_msg_.flags, expected 1, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, -96931)
      << "incorrect value for last_msg_.n, expected -96931, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2568100)
      << "incorrect value for last_msg_.tow, expected 2568100, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA5, Test) {
  uint8_t encoded_frame[] = {
      85, 3, 2, 195, 4,   22,  156, 21, 69, 24, 130, 246, 255, 255, 241,
      4,  0, 0, 35,  196, 255, 255, 0,  0,  0,  0,   6,   0,   250, 21,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = -15325;
  test_msg.e = 1265;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = -2430;
  test_msg.n_sats = 6;
  test_msg.tow = 407180700;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -15325)
      << "incorrect value for last_msg_.d, expected -15325, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, 1265)
      << "incorrect value for last_msg_.e, expected 1265, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, -2430)
      << "incorrect value for last_msg_.n, expected -2430, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 6)
      << "incorrect value for last_msg_.n_sats, expected 6, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407180700)
      << "incorrect value for last_msg_.tow, expected 407180700, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA6
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA6()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA6, Test) {
  uint8_t encoded_frame[] = {
      85, 3, 2, 195, 4,   22,  0,   22, 69, 24, 130, 246, 255, 255, 241,
      4,  0, 0, 35,  196, 255, 255, 0,  0,  0,  0,   6,   0,   240, 133,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = -15325;
  test_msg.e = 1265;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = -2430;
  test_msg.n_sats = 6;
  test_msg.tow = 407180800;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -15325)
      << "incorrect value for last_msg_.d, expected -15325, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, 1265)
      << "incorrect value for last_msg_.e, expected 1265, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, -2430)
      << "incorrect value for last_msg_.n, expected -2430, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 6)
      << "incorrect value for last_msg_.n_sats, expected 6, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407180800)
      << "incorrect value for last_msg_.tow, expected 407180800, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA7
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA7()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA7, Test) {
  uint8_t encoded_frame[] = {
      85, 3, 2, 195, 4,   22,  100, 22, 69, 24, 32, 251, 255, 255, 199,
      11, 0, 0, 57,  161, 255, 255, 0,  0,  0,  0,  6,   0,   12,  181,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = -24263;
  test_msg.e = 3015;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = -1248;
  test_msg.n_sats = 6;
  test_msg.tow = 407180900;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -24263)
      << "incorrect value for last_msg_.d, expected -24263, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, 3015)
      << "incorrect value for last_msg_.e, expected 3015, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, -1248)
      << "incorrect value for last_msg_.n, expected -1248, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 6)
      << "incorrect value for last_msg_.n_sats, expected 6, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407180900)
      << "incorrect value for last_msg_.tow, expected 407180900, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA8
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA8()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA8, Test) {
  uint8_t encoded_frame[] = {
      85, 3, 2, 195, 4,   22,  200, 22, 69, 24, 33, 251, 255, 255, 199,
      11, 0, 0, 54,  161, 255, 255, 0,  0,  0,  0,  6,   0,   86,  58,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = -24266;
  test_msg.e = 3015;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = -1247;
  test_msg.n_sats = 6;
  test_msg.tow = 407181000;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -24266)
      << "incorrect value for last_msg_.d, expected -24266, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, 3015)
      << "incorrect value for last_msg_.e, expected 3015, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, -1247)
      << "incorrect value for last_msg_.n, expected -1247, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 6)
      << "incorrect value for last_msg_.n_sats, expected 6, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407181000)
      << "incorrect value for last_msg_.tow, expected 407181000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA9
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA9()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA9, Test) {
  uint8_t encoded_frame[] = {
      85, 3, 2, 195, 4,   22,  44,  23, 69, 24, 110, 6, 0, 0,  55,
      8,  0, 0, 160, 166, 255, 255, 0,  0,  0,  0,   6, 0, 51, 249,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = -22880;
  test_msg.e = 2103;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = 1646;
  test_msg.n_sats = 6;
  test_msg.tow = 407181100;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -22880)
      << "incorrect value for last_msg_.d, expected -22880, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, 2103)
      << "incorrect value for last_msg_.e, expected 2103, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, 1646)
      << "incorrect value for last_msg_.n, expected 1646, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 6)
      << "incorrect value for last_msg_.n_sats, expected 6, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407181100)
      << "incorrect value for last_msg_.tow, expected 407181100, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgBaselineNEDDepA10
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgBaselineNEDDepA10()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this),
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
                      const sbp_msg_baseline_ned_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgBaselineNEDDepA10, Test) {
  uint8_t encoded_frame[] = {
      85, 3, 2, 195, 4,   22,  144, 23, 69, 24, 110, 6, 0, 0,   54,
      8,  0, 0, 160, 166, 255, 255, 0,  0,  0,  0,   6, 0, 206, 22,
  };

  sbp_msg_baseline_ned_dep_a_t test_msg{};
  test_msg.d = -22880;
  test_msg.e = 2102;
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.n = 1646;
  test_msg.n_sats = 6;
  test_msg.tow = 407181200;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.d, -22880)
      << "incorrect value for last_msg_.d, expected -22880, is " << last_msg_.d;
  EXPECT_EQ(last_msg_.e, 2102)
      << "incorrect value for last_msg_.e, expected 2102, is " << last_msg_.e;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_EQ(last_msg_.n, 1646)
      << "incorrect value for last_msg_.n, expected 1646, is " << last_msg_.n;
  EXPECT_EQ(last_msg_.n_sats, 6)
      << "incorrect value for last_msg_.n_sats, expected 6, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407181200)
      << "incorrect value for last_msg_.tow, expected 407181200, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
