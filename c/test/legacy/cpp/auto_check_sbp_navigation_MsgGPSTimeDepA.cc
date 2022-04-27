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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA0, Test) {
  uint8_t encoded_frame[] = {
      85, 0, 1, 246, 215, 11, 251, 6, 120, 46, 39, 0, 0, 0, 0, 0, 0, 133, 36,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 0;
  test_msg->tow = 2567800;
  test_msg->wn = 1787;

  EXPECT_EQ(send_message(0x100, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 0)
      << "incorrect value for ns_residual, expected 0, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 2567800)
      << "incorrect value for tow, expected 2567800, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1787)
      << "incorrect value for wn, expected 1787, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA1, Test) {
  uint8_t encoded_frame[] = {
      85, 0, 1, 246, 215, 11, 251, 6, 220, 46, 39, 0, 0, 0, 0, 0, 0, 36, 160,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 0;
  test_msg->tow = 2567900;
  test_msg->wn = 1787;

  EXPECT_EQ(send_message(0x100, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 0)
      << "incorrect value for ns_residual, expected 0, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 2567900)
      << "incorrect value for tow, expected 2567900, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1787)
      << "incorrect value for wn, expected 1787, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA2, Test) {
  uint8_t encoded_frame[] = {
      85, 0, 1, 246, 215, 11, 251, 6, 64, 47, 39, 0, 0, 0, 0, 0, 0, 171, 190,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 0;
  test_msg->tow = 2568000;
  test_msg->wn = 1787;

  EXPECT_EQ(send_message(0x100, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 0)
      << "incorrect value for ns_residual, expected 0, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 2568000)
      << "incorrect value for tow, expected 2568000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1787)
      << "incorrect value for wn, expected 1787, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA3, Test) {
  uint8_t encoded_frame[] = {
      85, 0, 1, 246, 215, 11, 251, 6, 164, 47, 39, 0, 0, 0, 0, 0, 0, 211, 101,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 0;
  test_msg->tow = 2568100;
  test_msg->wn = 1787;

  EXPECT_EQ(send_message(0x100, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 0)
      << "incorrect value for ns_residual, expected 0, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 2568100)
      << "incorrect value for tow, expected 2568100, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1787)
      << "incorrect value for wn, expected 1787, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA4, Test) {
  uint8_t encoded_frame[] = {
      85, 0, 1, 246, 215, 11, 251, 6, 8, 48, 39, 0, 0, 0, 0, 0, 0, 251, 44,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 0;
  test_msg->tow = 2568200;
  test_msg->wn = 1787;

  EXPECT_EQ(send_message(0x100, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 0)
      << "incorrect value for ns_residual, expected 0, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 2568200)
      << "incorrect value for tow, expected 2568200, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1787)
      << "incorrect value for wn, expected 1787, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA5, Test) {
  uint8_t encoded_frame[] = {
      85, 0,  1,   195, 4,   11,  46, 7,   212, 157,
      67, 24, 111, 147, 252, 255, 0,  215, 190,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = -224401;
  test_msg->tow = 407084500;
  test_msg->wn = 1838;

  EXPECT_EQ(send_message(0x100, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, -224401)
      << "incorrect value for ns_residual, expected -224401, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 407084500)
      << "incorrect value for tow, expected 407084500, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1838)
      << "incorrect value for wn, expected 1838, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA6
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA6()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA6, Test) {
  uint8_t encoded_frame[] = {
      85, 0, 1, 195, 4, 11, 46, 7, 56, 158, 67, 24, 109, 103, 3, 0, 0, 134, 89,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 223085;
  test_msg->tow = 407084600;
  test_msg->wn = 1838;

  EXPECT_EQ(send_message(0x100, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 223085)
      << "incorrect value for ns_residual, expected 223085, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 407084600)
      << "incorrect value for tow, expected 407084600, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1838)
      << "incorrect value for wn, expected 1838, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA7
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA7()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA7, Test) {
  uint8_t encoded_frame[] = {
      85, 0,  1,   195, 4,   11,  46, 7,   156, 158,
      67, 24, 233, 152, 252, 255, 0,  206, 241,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = -222999;
  test_msg->tow = 407084700;
  test_msg->wn = 1838;

  EXPECT_EQ(send_message(0x100, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, -222999)
      << "incorrect value for ns_residual, expected -222999, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 407084700)
      << "incorrect value for tow, expected 407084700, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1838)
      << "incorrect value for wn, expected 1838, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA8
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA8()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA8, Test) {
  uint8_t encoded_frame[] = {
      85, 0, 1, 195, 4, 11, 46, 7, 0, 159, 67, 24, 240, 154, 3, 0, 0, 147, 98,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 236272;
  test_msg->tow = 407084800;
  test_msg->wn = 1838;

  EXPECT_EQ(send_message(0x100, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 236272)
      << "incorrect value for ns_residual, expected 236272, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 407084800)
      << "incorrect value for tow, expected 407084800, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1838)
      << "incorrect value for wn, expected 1838, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA9
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA9()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA9, Test) {
  uint8_t encoded_frame[] = {
      85, 0,  1,   195, 4,   11,  46, 7,   100, 159,
      67, 24, 144, 101, 252, 255, 0,  186, 152,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = -236144;
  test_msg->tow = 407084900;
  test_msg->wn = 1838;

  EXPECT_EQ(send_message(0x100, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, -236144)
      << "incorrect value for ns_residual, expected -236144, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 407084900)
      << "incorrect value for tow, expected 407084900, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1838)
      << "incorrect value for wn, expected 1838, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA10
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA10()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_dep_a_t *>(last_msg_storage_)),
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
                      const msg_gps_time_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTimeDepA10, Test) {
  uint8_t encoded_frame[] = {
      85, 0,  1,   195, 4,   11,  46, 7,  46,  162,
      68, 24, 205, 230, 250, 255, 0,  11, 225,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_dep_a_t *test_msg = (msg_gps_time_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = -334131;
  test_msg->tow = 407151150;
  test_msg->wn = 1838;

  EXPECT_EQ(send_message(0x100, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, -334131)
      << "incorrect value for ns_residual, expected -334131, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 407151150)
      << "incorrect value for tow, expected 407151150, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1838)
      << "incorrect value for wn, expected 1838, is " << last_msg_->wn;
}
