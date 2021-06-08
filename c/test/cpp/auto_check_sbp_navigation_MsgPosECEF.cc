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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEF.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgPosECEF0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEF0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_t>(this),
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
                      const sbp_msg_pos_ecef_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEF0, Test) {
  uint8_t encoded_frame[] = {
      85,  9,   2,  211, 136, 32,  16, 248, 122, 19,  73, 29,  46, 132,
      182, 122, 68, 193, 219, 192, 29, 176, 121, 119, 80, 193, 83, 11,
      210, 90,  79, 75,  77,  65,  0,  0,   15,  2,   84, 6,
  };

  sbp_msg_pos_ecef_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 2;
  test_msg.n_sats = 15;
  test_msg.tow = 326826000;
  test_msg.x = -2684269.0326572997;
  test_msg.y = -4316646.751816;
  test_msg.z = 3839646.7095350414;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326826000)
      << "incorrect value for last_msg_.tow, expected 326826000, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2684269.03266 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2684269.03266, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4316646.75182 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4316646.75182, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3839646.70954 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3839646.70954, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEF1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEF1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_t>(this),
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
                      const sbp_msg_pos_ecef_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEF1, Test) {
  uint8_t encoded_frame[] = {
      85,  9,   2,  211, 136, 32,  248, 251, 122, 19,  103, 106, 57,  136,
      182, 122, 68, 193, 176, 242, 200, 176, 121, 119, 80,  193, 244, 135,
      97,  59,  79, 75,  77,  65,  0,   0,   15,  2,   147, 216,
  };

  sbp_msg_pos_ecef_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 2;
  test_msg.n_sats = 15;
  test_msg.tow = 326827000;
  test_msg.x = -2684269.064252186;
  test_msg.y = -4316646.762264892;
  test_msg.z = 3839646.463913912;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326827000)
      << "incorrect value for last_msg_.tow, expected 326827000, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2684269.06425 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2684269.06425, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4316646.76226 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4316646.76226, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3839646.46391 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3839646.46391, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEF2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEF2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_t>(this),
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
                      const sbp_msg_pos_ecef_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEF2, Test) {
  uint8_t encoded_frame[] = {
      85,  9,   2,  211, 136, 32,  224, 255, 122, 19,  101, 179, 242, 182,
      182, 122, 68, 193, 130, 196, 145, 199, 121, 119, 80,  193, 212, 10,
      253, 15,  79, 75,  77,  65,  0,   0,   15,  2,   40,  201,
  };

  sbp_msg_pos_ecef_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 2;
  test_msg.n_sats = 15;
  test_msg.tow = 326828000;
  test_msg.x = -2684269.4292816394;
  test_msg.y = -4316647.118271949;
  test_msg.z = 3839646.124909738;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326828000)
      << "incorrect value for last_msg_.tow, expected 326828000, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2684269.42928 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2684269.42928, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4316647.11827 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4316647.11827, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3839646.12491 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3839646.12491, is "
      << last_msg_.z;
}
class Test_auto_check_sbp_navigation_MsgPosECEF3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_ecef_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosECEF3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_ecef_t>(this),
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
                      const sbp_msg_pos_ecef_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosECEF3, Test) {
  uint8_t encoded_frame[] = {
      85,  9,   2,  211, 136, 32, 200, 3,   123, 19,  146, 214, 132, 215,
      182, 122, 68, 193, 213, 68, 49,  215, 121, 119, 80,  193, 71,  34,
      110, 243, 78, 75,  77,  65, 0,   0,   15,  2,   187, 86,
  };

  sbp_msg_pos_ecef_t test_msg{};
  test_msg.accuracy = 0;
  test_msg.flags = 2;
  test_msg.n_sats = 15;
  test_msg.tow = 326829000;
  test_msg.x = -2684269.683741399;
  test_msg.y = -4316647.3623821335;
  test_msg.z = 3839645.90179852;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.accuracy, 0)
      << "incorrect value for last_msg_.accuracy, expected 0, is "
      << last_msg_.accuracy;
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326829000)
      << "incorrect value for last_msg_.tow, expected 326829000, is "
      << last_msg_.tow;
  EXPECT_LT((last_msg_.x * 100 - -2684269.68374 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2684269.68374, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4316647.36238 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4316647.36238, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3839645.9018 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3839645.9018, is "
      << last_msg_.z;
}
