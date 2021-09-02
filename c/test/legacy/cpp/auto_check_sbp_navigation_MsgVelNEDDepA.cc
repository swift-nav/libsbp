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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA0, Test) {
  uint8_t encoded_frame[] = {
      85, 5, 2, 246, 215, 22, 20, 46, 39, 0, 198, 251, 255, 255, 156,
      15, 0, 0, 0,   0,   0,  0,  0,  0,  0, 0,   9,   0,   161, 92,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 0;
  test_msg->e = 3996;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = -1082;
  test_msg->n_sats = 9;
  test_msg->tow = 2567700;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 0)
      << "incorrect value for d, expected 0, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, 3996)
      << "incorrect value for e, expected 3996, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, -1082)
      << "incorrect value for n, expected -1082, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2567700)
      << "incorrect value for tow, expected 2567700, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA1, Test) {
  uint8_t encoded_frame[] = {
      85, 5, 2, 246, 215, 22, 120, 46, 39, 0, 14, 252, 255, 255, 207,
      14, 0, 0, 0,   0,   0,  0,   0,  0,  0, 0,  9,   0,   125, 160,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 0;
  test_msg->e = 3791;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = -1010;
  test_msg->n_sats = 9;
  test_msg->tow = 2567800;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 0)
      << "incorrect value for d, expected 0, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, 3791)
      << "incorrect value for e, expected 3791, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, -1010)
      << "incorrect value for n, expected -1010, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2567800)
      << "incorrect value for tow, expected 2567800, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA2, Test) {
  uint8_t encoded_frame[] = {
      85, 5, 2, 246, 215, 22, 220, 46, 39, 0, 48, 252, 255, 255, 140,
      14, 0, 0, 0,   0,   0,  0,   0,  0,  0, 0,  9,   0,   179, 135,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 0;
  test_msg->e = 3724;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = -976;
  test_msg->n_sats = 9;
  test_msg->tow = 2567900;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 0)
      << "incorrect value for d, expected 0, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, 3724)
      << "incorrect value for e, expected 3724, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, -976)
      << "incorrect value for n, expected -976, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2567900)
      << "incorrect value for tow, expected 2567900, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA3, Test) {
  uint8_t encoded_frame[] = {
      85, 5, 2, 246, 215, 22, 64, 47, 39, 0, 32, 252, 255, 255, 8,
      15, 0, 0, 0,   0,   0,  0,  0,  0,  0, 0,  9,   0,   51,  177,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 0;
  test_msg->e = 3848;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = -992;
  test_msg->n_sats = 9;
  test_msg->tow = 2568000;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 0)
      << "incorrect value for d, expected 0, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, 3848)
      << "incorrect value for e, expected 3848, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, -992)
      << "incorrect value for n, expected -992, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2568000)
      << "incorrect value for tow, expected 2568000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA4, Test) {
  uint8_t encoded_frame[] = {
      85, 5, 2, 246, 215, 22, 164, 47, 39, 0, 80, 252, 255, 255, 140,
      14, 0, 0, 0,   0,   0,  0,   0,  0,  0, 0,  9,   0,   23,  0,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 0;
  test_msg->e = 3724;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = -944;
  test_msg->n_sats = 9;
  test_msg->tow = 2568100;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 0)
      << "incorrect value for d, expected 0, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, 3724)
      << "incorrect value for e, expected 3724, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, -944)
      << "incorrect value for n, expected -944, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2568100)
      << "incorrect value for tow, expected 2568100, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA5, Test) {
  uint8_t encoded_frame[] = {
      85, 5, 2, 195, 4, 22, 212, 157, 67, 24, 229, 255, 255, 255, 26,
      0,  0, 0, 25,  0, 0,  0,   0,   0,  0,  0,   8,   0,   132, 25,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 25;
  test_msg->e = 26;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = -27;
  test_msg->n_sats = 8;
  test_msg->tow = 407084500;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 25)
      << "incorrect value for d, expected 25, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, 26)
      << "incorrect value for e, expected 26, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, -27)
      << "incorrect value for n, expected -27, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 8)
      << "incorrect value for n_sats, expected 8, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407084500)
      << "incorrect value for tow, expected 407084500, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA6
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA6()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA6, Test) {
  uint8_t encoded_frame[] = {
      85, 5, 2, 195, 4,   22,  56,  158, 67, 24, 4, 0, 0, 0,  15,
      0,  0, 0, 232, 255, 255, 255, 0,   0,  0,  0, 8, 0, 42, 14,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = -24;
  test_msg->e = 15;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = 4;
  test_msg->n_sats = 8;
  test_msg->tow = 407084600;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, -24)
      << "incorrect value for d, expected -24, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, 15)
      << "incorrect value for e, expected 15, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, 4)
      << "incorrect value for n, expected 4, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 8)
      << "incorrect value for n_sats, expected 8, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407084600)
      << "incorrect value for tow, expected 407084600, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA7
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA7()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA7, Test) {
  uint8_t encoded_frame[] = {
      85,  5,   2,   195, 4,   22,  156, 158, 67, 24, 251, 255, 255, 255, 232,
      255, 255, 255, 247, 255, 255, 255, 0,   0,  0,  0,   8,   0,   218, 148,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = -9;
  test_msg->e = -24;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = -5;
  test_msg->n_sats = 8;
  test_msg->tow = 407084700;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, -9)
      << "incorrect value for d, expected -9, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, -24)
      << "incorrect value for e, expected -24, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, -5)
      << "incorrect value for n, expected -5, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 8)
      << "incorrect value for n_sats, expected 8, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407084700)
      << "incorrect value for tow, expected 407084700, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA8
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA8()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA8, Test) {
  uint8_t encoded_frame[] = {
      85, 5, 2, 195, 4,   22,  0,   159, 67, 24, 10, 0, 0, 0,   2,
      0,  0, 0, 222, 255, 255, 255, 0,   0,  0,  0,  8, 0, 148, 16,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = -34;
  test_msg->e = 2;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = 10;
  test_msg->n_sats = 8;
  test_msg->tow = 407084800;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, -34)
      << "incorrect value for d, expected -34, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, 2)
      << "incorrect value for e, expected 2, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, 10)
      << "incorrect value for n, expected 10, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 8)
      << "incorrect value for n_sats, expected 8, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407084800)
      << "incorrect value for tow, expected 407084800, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA9
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA9()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA9, Test) {
  uint8_t encoded_frame[] = {
      85,  5,   2,   195, 4, 22, 100, 159, 67, 24, 248, 255, 255, 255, 254,
      255, 255, 255, 7,   0, 0,  0,   0,   0,  0,  0,   8,   0,   255, 236,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 7;
  test_msg->e = -2;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = -8;
  test_msg->n_sats = 8;
  test_msg->tow = 407084900;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 7)
      << "incorrect value for d, expected 7, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, -2)
      << "incorrect value for e, expected -2, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, -8)
      << "incorrect value for n, expected -8, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 8)
      << "incorrect value for n_sats, expected 8, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407084900)
      << "incorrect value for tow, expected 407084900, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA10
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ned_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA10()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ned_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ned_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ned_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ned_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelNEDDepA10, Test) {
  uint8_t encoded_frame[] = {
      85,  5,   2,   195, 4,   22,  46,  162, 68, 24, 255, 255, 255, 255, 253,
      255, 255, 255, 148, 255, 255, 255, 0,   0,  0,  0,   5,   0,   166, 189,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ned_dep_a_t *test_msg = (msg_vel_ned_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = -108;
  test_msg->e = -3;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = -1;
  test_msg->n_sats = 5;
  test_msg->tow = 407151150;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x205, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, -108)
      << "incorrect value for d, expected -108, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, -3)
      << "incorrect value for e, expected -3, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, -1)
      << "incorrect value for n, expected -1, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 5)
      << "incorrect value for n_sats, expected 5, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407151150)
      << "incorrect value for tow, expected 407151150, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
