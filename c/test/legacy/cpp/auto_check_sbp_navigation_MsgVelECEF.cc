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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEF.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgVelECEF0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEF0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEF0, Test) {
  uint8_t encoded_frame[] = {
      85,  13,  2,   211, 136, 20, 40, 244, 122, 19, 248, 255, 255, 255,
      251, 255, 255, 255, 10,  0,  0,  0,   0,   0,  14,  0,   181, 99,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_t *test_msg = (msg_vel_ecef_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 14;
  test_msg->tow = 326825000;
  test_msg->x = -8;
  test_msg->y = -5;
  test_msg->z = 10;

  EXPECT_EQ(send_message(0x20d, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 14)
      << "incorrect value for n_sats, expected 14, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 326825000)
      << "incorrect value for tow, expected 326825000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -8)
      << "incorrect value for x, expected -8, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -5)
      << "incorrect value for y, expected -5, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 10)
      << "incorrect value for z, expected 10, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEF1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEF1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEF1, Test) {
  uint8_t encoded_frame[] = {
      85,  13,  2,   211, 136, 20, 28, 246, 122, 19, 244, 255, 255, 255,
      238, 255, 255, 255, 11,  0,  0,  0,   0,   0,  15,  0,   215, 120,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_t *test_msg = (msg_vel_ecef_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 15;
  test_msg->tow = 326825500;
  test_msg->x = -12;
  test_msg->y = -18;
  test_msg->z = 11;

  EXPECT_EQ(send_message(0x20d, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 15)
      << "incorrect value for n_sats, expected 15, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 326825500)
      << "incorrect value for tow, expected 326825500, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -12)
      << "incorrect value for x, expected -12, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -18)
      << "incorrect value for y, expected -18, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 11)
      << "incorrect value for z, expected 11, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEF2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEF2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEF2, Test) {
  uint8_t encoded_frame[] = {
      85,  13,  2,   211, 136, 20, 16, 248, 122, 19, 248, 255, 255, 255,
      250, 255, 255, 255, 7,   0,  0,  0,   0,   0,  15,  0,   248, 221,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_t *test_msg = (msg_vel_ecef_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 15;
  test_msg->tow = 326826000;
  test_msg->x = -8;
  test_msg->y = -6;
  test_msg->z = 7;

  EXPECT_EQ(send_message(0x20d, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 15)
      << "incorrect value for n_sats, expected 15, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 326826000)
      << "incorrect value for tow, expected 326826000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -8)
      << "incorrect value for x, expected -8, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -6)
      << "incorrect value for y, expected -6, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 7)
      << "incorrect value for z, expected 7, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEF3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEF3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEF3, Test) {
  uint8_t encoded_frame[] = {
      85,  13,  2,   211, 136, 20, 4, 250, 122, 19, 249, 255, 255, 255,
      239, 255, 255, 255, 16,  0,  0, 0,   0,   0,  15,  0,   1,   167,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_t *test_msg = (msg_vel_ecef_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 15;
  test_msg->tow = 326826500;
  test_msg->x = -7;
  test_msg->y = -17;
  test_msg->z = 16;

  EXPECT_EQ(send_message(0x20d, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 15)
      << "incorrect value for n_sats, expected 15, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 326826500)
      << "incorrect value for tow, expected 326826500, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -7)
      << "incorrect value for x, expected -7, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -17)
      << "incorrect value for y, expected -17, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 16)
      << "incorrect value for z, expected 16, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEF4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEF4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEF4, Test) {
  uint8_t encoded_frame[] = {
      85,  13,  2,   211, 136, 20, 248, 251, 122, 19, 247, 255, 255, 255,
      243, 255, 255, 255, 14,  0,  0,   0,   0,   0,  15,  0,   191, 43,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_t *test_msg = (msg_vel_ecef_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 15;
  test_msg->tow = 326827000;
  test_msg->x = -9;
  test_msg->y = -13;
  test_msg->z = 14;

  EXPECT_EQ(send_message(0x20d, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 15)
      << "incorrect value for n_sats, expected 15, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 326827000)
      << "incorrect value for tow, expected 326827000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -9)
      << "incorrect value for x, expected -9, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -13)
      << "incorrect value for y, expected -13, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 14)
      << "incorrect value for z, expected 14, is " << last_msg_->z;
}
