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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgPosECEFDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA0, Test) {
  uint8_t encoded_frame[] = {
      85, 0,   2,   246, 215, 32, 20,  46,  39,  0,  195, 122, 175, 75,
      33, 154, 68,  193, 164, 14, 230, 176, 231, 95, 80,  193, 78,  220,
      22, 253, 254, 105, 77,  65, 0,   0,   9,   0,  13,  86,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 0;
  test_msg.n_sats = 9;
  test_msg.tow = 2567700;
  test_msg.x = -2700354.5912927105;
  test_msg.y = -4292510.764041577;
  test_msg.z = 3855357.977260149;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567700)
      << "incorrect value for last_msg_.tow, expected 2567700, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2700354.59129 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2700354.59129, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4292510.76404 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4292510.76404, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3855357.97726 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3855357.97726, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEFDepA1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA1, Test) {
  uint8_t encoded_frame[] = {
      85, 0,   2,   246, 215, 32,  20,  46,  39,  0,  212, 196, 12, 42,
      34, 154, 68,  193, 9,   113, 112, 123, 231, 95, 80,  193, 54, 97,
      38, 192, 254, 105, 77,  65,  0,   0,   9,   1,  75,  143,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 1;
  test_msg.n_sats = 9;
  test_msg.tow = 2567700;
  test_msg.x = -2700356.3285146747;
  test_msg.y = -4292509.928737887;
  test_msg.z = 3855357.5011712564;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 1)
      << "incorrect value for last_msg_.flags, expected 1, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567700)
      << "incorrect value for last_msg_.tow, expected 2567700, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2700356.32851 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2700356.32851, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4292509.92874 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4292509.92874, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3855357.50117 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3855357.50117, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEFDepA2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA2, Test) {
  uint8_t encoded_frame[] = {
      85, 0,   2,   246, 215, 32, 120, 46,  39,  0,  112, 97,  39, 190,
      34, 154, 68,  193, 230, 43, 119, 115, 231, 95, 80,  193, 50, 199,
      76, 66,  254, 105, 77,  65, 0,   0,   9,   0,  204, 113,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 0;
  test_msg.n_sats = 9;
  test_msg.tow = 2567800;
  test_msg.x = -2700357.485576801;
  test_msg.y = -4292509.80414865;
  test_msg.z = 3855356.517968082;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567800)
      << "incorrect value for last_msg_.tow, expected 2567800, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2700357.48558 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2700357.48558, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4292509.80415 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4292509.80415, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3855356.51797 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3855356.51797, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEFDepA3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA3, Test) {
  uint8_t encoded_frame[] = {
      85,  0,   2,   246, 215, 32,  120, 46,  39,  0,  194, 82,  121, 4,
      34,  154, 68,  193, 223, 186, 1,   140, 231, 95, 80,  193, 176, 152,
      147, 181, 254, 105, 77,  65,  0,   0,   9,   1,  97,  71,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 1;
  test_msg.n_sats = 9;
  test_msg.tow = 2567800;
  test_msg.x = -2700356.0349524925;
  test_msg.y = -4292510.187605589;
  test_msg.z = 3855357.4185667858;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 1)
      << "incorrect value for last_msg_.flags, expected 1, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567800)
      << "incorrect value for last_msg_.tow, expected 2567800, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2700356.03495 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2700356.03495, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4292510.18761 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4292510.18761, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3855357.41857 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3855357.41857, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEFDepA4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA4, Test) {
  uint8_t encoded_frame[] = {
      85,  0,   2,   246, 215, 32,  220, 46,  39,  0,  216, 41,  227, 254,
      33,  154, 68,  193, 9,   151, 154, 124, 231, 95, 80,  193, 1,   183,
      214, 139, 255, 105, 77,  65,  0,   0,   9,   0,  7,   98,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 0;
  test_msg.n_sats = 9;
  test_msg.tow = 2567900;
  test_msg.x = -2700355.9913074784;
  test_msg.y = -4292509.946935424;
  test_msg.z = 3855359.0924900775;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567900)
      << "incorrect value for last_msg_.tow, expected 2567900, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2700355.99131 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2700355.99131, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4292509.94694 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4292509.94694, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3855359.09249 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3855359.09249, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEFDepA5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA5, Test) {
  uint8_t encoded_frame[] = {
      85,  0,   2,  195, 4,   32,  212, 157, 67, 24, 153, 222, 105, 1,
      252, 161, 68, 193, 254, 247, 52,  112, 74, 67, 80,  193, 164, 207,
      47,  146, 44, 163, 77,  65,  0,   0,   8,  0,  145, 4,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 0;
  test_msg.n_sats = 8;
  test_msg.tow = 407084500;
  test_msg.x = -2704376.0110433814;
  test_msg.y = -4263209.753232954;
  test_msg.z = 3884633.142084079;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 8)
      << "incorrect value for last_msg_.n_sats, expected 8, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407084500)
      << "incorrect value for last_msg_.tow, expected 407084500, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2704376.01104 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2704376.01104, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4263209.75323 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4263209.75323, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3884633.14208 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3884633.14208, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEFDepA6
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA6()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA6, Test) {
  uint8_t encoded_frame[] = {
      85,  0,   2,  195, 4,  32,  56, 158, 67, 24, 215, 184, 223, 246,
      251, 161, 68, 193, 36, 126, 17, 39,  74, 67, 80,  193, 19,  179,
      70,  80,  44, 163, 77, 65,  0,  0,   8,  0,  245, 66,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 0;
  test_msg.n_sats = 8;
  test_msg.tow = 407084600;
  test_msg.x = -2704375.9287024545;
  test_msg.y = -4263208.610442672;
  test_msg.z = 3884632.627157578;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 8)
      << "incorrect value for last_msg_.n_sats, expected 8, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407084600)
      << "incorrect value for last_msg_.tow, expected 407084600, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2704375.9287 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2704375.9287, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4263208.61044 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4263208.61044, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3884632.62716 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3884632.62716, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEFDepA7
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA7()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA7, Test) {
  uint8_t encoded_frame[] = {
      85,  0,   2,  195, 4,   32,  156, 158, 67, 24, 73, 74,  214, 148,
      251, 161, 68, 193, 213, 151, 184, 215, 73, 67, 80, 193, 110, 99,
      38,  164, 43, 163, 77,  65,  0,   0,   8,  0,  5,  223,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 0;
  test_msg.n_sats = 8;
  test_msg.tow = 407084700;
  test_msg.x = -2704375.162789617;
  test_msg.y = -4263207.370641668;
  test_msg.z = 3884631.282421521;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 8)
      << "incorrect value for last_msg_.n_sats, expected 8, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407084700)
      << "incorrect value for last_msg_.tow, expected 407084700, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2704375.16279 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2704375.16279, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4263207.37064 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4263207.37064, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3884631.28242 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3884631.28242, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEFDepA8
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA8()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA8, Test) {
  uint8_t encoded_frame[] = {
      85,  0,   2,  195, 4,   32,  0,   159, 67, 24, 177, 111, 112, 45,
      252, 161, 68, 193, 213, 168, 198, 253, 73, 67, 80,  193, 245, 12,
      228, 12,  44, 163, 77,  65,  0,   0,   8,  0,  143, 212,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 0;
  test_msg.n_sats = 8;
  test_msg.tow = 407084800;
  test_msg.x = -2704376.3549937834;
  test_msg.y = -4263207.965250214;
  test_msg.z = 3884632.1007095524;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 8)
      << "incorrect value for last_msg_.n_sats, expected 8, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407084800)
      << "incorrect value for last_msg_.tow, expected 407084800, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2704376.35499 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2704376.35499, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4263207.96525 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4263207.96525, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3884632.10071 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3884632.10071, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEFDepA9
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA9()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA9, Test) {
  uint8_t encoded_frame[] = {
      85,  0,   2,  195, 4,   32,  100, 159, 67, 24, 67, 231, 72,  165,
      251, 161, 68, 193, 150, 210, 36,  212, 73, 67, 80, 193, 234, 33,
      25,  189, 43, 163, 77,  65,  0,   0,   8,  0,  70, 221,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 0;
  test_msg.n_sats = 8;
  test_msg.tow = 407084900;
  test_msg.x = -2704375.291287334;
  test_msg.y = -4263207.314747473;
  test_msg.z = 3884631.4773294823;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 8)
      << "incorrect value for last_msg_.n_sats, expected 8, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407084900)
      << "incorrect value for last_msg_.tow, expected 407084900, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2704375.29129 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2704375.29129, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4263207.31475 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4263207.31475, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3884631.47733 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3884631.47733, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEFDepA10
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEFDepA10()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_dep_a_t>(this),
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
                      const sbp_msg_pos_ecef_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEFDepA10, Test) {
  uint8_t encoded_frame[] = {
      85,  0,   2,  195, 4,   32,  46,  162, 68, 24, 224, 72,  131, 215,
      251, 161, 68, 193, 180, 123, 222, 94,  74, 67, 80,  193, 191, 3,
      131, 193, 45, 163, 77,  65,  0,   0,   5,  0,  17,  221,
  };

  sbp_msg_pos_ecef_dep_a_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 0;
  test_msg.n_sats = 5;
  test_msg.tow = 407151150;
  test_msg.x = -2704375.68369399;
  test_msg.y = -4263209.482329298;
  test_msg.z = 3884635.5118107493;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 5)
      << "incorrect value for last_msg_.n_sats, expected 5, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407151150)
      << "incorrect value for last_msg_.tow, expected 407151150, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2704375.68369 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2704375.68369, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4263209.48233 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4263209.48233, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3884635.51181 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3884635.51181, is "
      << last_msg_.z;
}
