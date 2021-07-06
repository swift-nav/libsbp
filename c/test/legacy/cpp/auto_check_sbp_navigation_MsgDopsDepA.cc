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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDopsDepA.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgDopsDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_dops_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgDopsDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_dops_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_dops_dep_a_t *>(last_msg_storage_)),
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
                      const msg_dops_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_dops_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgDopsDepA0, Test) {
  uint8_t encoded_frame[] = {
      85, 6,   2, 246, 215, 14,  8, 48,  39, 0,   180,
      0,  190, 0, 170, 0,   160, 0, 150, 0,  121, 170,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_dops_dep_a_t *test_msg = (msg_dops_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->gdop = 180;
  test_msg->hdop = 160;
  test_msg->pdop = 190;
  test_msg->tdop = 170;
  test_msg->tow = 2568200;
  test_msg->vdop = 150;

  EXPECT_EQ(send_message(0x206, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->gdop, 180)
      << "incorrect value for gdop, expected 180, is " << last_msg_->gdop;
  EXPECT_EQ(last_msg_->hdop, 160)
      << "incorrect value for hdop, expected 160, is " << last_msg_->hdop;
  EXPECT_EQ(last_msg_->pdop, 190)
      << "incorrect value for pdop, expected 190, is " << last_msg_->pdop;
  EXPECT_EQ(last_msg_->tdop, 170)
      << "incorrect value for tdop, expected 170, is " << last_msg_->tdop;
  EXPECT_EQ(last_msg_->tow, 2568200)
      << "incorrect value for tow, expected 2568200, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->vdop, 150)
      << "incorrect value for vdop, expected 150, is " << last_msg_->vdop;
}
class Test_legacy_auto_check_sbp_navigation_MsgDopsDepA1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_dops_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgDopsDepA1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_dops_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_dops_dep_a_t *>(last_msg_storage_)),
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
                      const msg_dops_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_dops_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgDopsDepA1, Test) {
  uint8_t encoded_frame[] = {
      85, 6,   2, 246, 215, 14,  240, 51,  39, 0,  180,
      0,  190, 0, 170, 0,   160, 0,   150, 0,  78, 169,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_dops_dep_a_t *test_msg = (msg_dops_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->gdop = 180;
  test_msg->hdop = 160;
  test_msg->pdop = 190;
  test_msg->tdop = 170;
  test_msg->tow = 2569200;
  test_msg->vdop = 150;

  EXPECT_EQ(send_message(0x206, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->gdop, 180)
      << "incorrect value for gdop, expected 180, is " << last_msg_->gdop;
  EXPECT_EQ(last_msg_->hdop, 160)
      << "incorrect value for hdop, expected 160, is " << last_msg_->hdop;
  EXPECT_EQ(last_msg_->pdop, 190)
      << "incorrect value for pdop, expected 190, is " << last_msg_->pdop;
  EXPECT_EQ(last_msg_->tdop, 170)
      << "incorrect value for tdop, expected 170, is " << last_msg_->tdop;
  EXPECT_EQ(last_msg_->tow, 2569200)
      << "incorrect value for tow, expected 2569200, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->vdop, 150)
      << "incorrect value for vdop, expected 150, is " << last_msg_->vdop;
}
class Test_legacy_auto_check_sbp_navigation_MsgDopsDepA2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_dops_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgDopsDepA2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_dops_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_dops_dep_a_t *>(last_msg_storage_)),
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
                      const msg_dops_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_dops_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgDopsDepA2, Test) {
  uint8_t encoded_frame[] = {
      85, 6,   2, 246, 215, 14,  216, 55,  39, 0,  180,
      0,  190, 0, 170, 0,   160, 0,   150, 0,  71, 218,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_dops_dep_a_t *test_msg = (msg_dops_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->gdop = 180;
  test_msg->hdop = 160;
  test_msg->pdop = 190;
  test_msg->tdop = 170;
  test_msg->tow = 2570200;
  test_msg->vdop = 150;

  EXPECT_EQ(send_message(0x206, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->gdop, 180)
      << "incorrect value for gdop, expected 180, is " << last_msg_->gdop;
  EXPECT_EQ(last_msg_->hdop, 160)
      << "incorrect value for hdop, expected 160, is " << last_msg_->hdop;
  EXPECT_EQ(last_msg_->pdop, 190)
      << "incorrect value for pdop, expected 190, is " << last_msg_->pdop;
  EXPECT_EQ(last_msg_->tdop, 170)
      << "incorrect value for tdop, expected 170, is " << last_msg_->tdop;
  EXPECT_EQ(last_msg_->tow, 2570200)
      << "incorrect value for tow, expected 2570200, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->vdop, 150)
      << "incorrect value for vdop, expected 150, is " << last_msg_->vdop;
}
class Test_legacy_auto_check_sbp_navigation_MsgDopsDepA3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_dops_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgDopsDepA3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_dops_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_dops_dep_a_t *>(last_msg_storage_)),
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
                      const msg_dops_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_dops_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgDopsDepA3, Test) {
  uint8_t encoded_frame[] = {
      85, 6,   2, 195, 4, 14, 212, 157, 67, 24,  247,
      0,  215, 0, 123, 0, 17, 1,   44,  0,  206, 21,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_dops_dep_a_t *test_msg = (msg_dops_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->gdop = 247;
  test_msg->hdop = 273;
  test_msg->pdop = 215;
  test_msg->tdop = 123;
  test_msg->tow = 407084500;
  test_msg->vdop = 44;

  EXPECT_EQ(send_message(0x206, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->gdop, 247)
      << "incorrect value for gdop, expected 247, is " << last_msg_->gdop;
  EXPECT_EQ(last_msg_->hdop, 273)
      << "incorrect value for hdop, expected 273, is " << last_msg_->hdop;
  EXPECT_EQ(last_msg_->pdop, 215)
      << "incorrect value for pdop, expected 215, is " << last_msg_->pdop;
  EXPECT_EQ(last_msg_->tdop, 123)
      << "incorrect value for tdop, expected 123, is " << last_msg_->tdop;
  EXPECT_EQ(last_msg_->tow, 407084500)
      << "incorrect value for tow, expected 407084500, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->vdop, 44)
      << "incorrect value for vdop, expected 44, is " << last_msg_->vdop;
}
class Test_legacy_auto_check_sbp_navigation_MsgDopsDepA4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_dops_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgDopsDepA4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_dops_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_dops_dep_a_t *>(last_msg_storage_)),
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
                      const msg_dops_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_dops_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgDopsDepA4, Test) {
  uint8_t encoded_frame[] = {
      85,  6,   2,   195, 4, 14, 0, 0, 0, 0,   255,
      255, 255, 255, 0,   0, 0,  0, 0, 0, 146, 12,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_dops_dep_a_t *test_msg = (msg_dops_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->gdop = 65535;
  test_msg->hdop = 0;
  test_msg->pdop = 65535;
  test_msg->tdop = 0;
  test_msg->tow = 0;
  test_msg->vdop = 0;

  EXPECT_EQ(send_message(0x206, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->gdop, 65535)
      << "incorrect value for gdop, expected 65535, is " << last_msg_->gdop;
  EXPECT_EQ(last_msg_->hdop, 0)
      << "incorrect value for hdop, expected 0, is " << last_msg_->hdop;
  EXPECT_EQ(last_msg_->pdop, 65535)
      << "incorrect value for pdop, expected 65535, is " << last_msg_->pdop;
  EXPECT_EQ(last_msg_->tdop, 0)
      << "incorrect value for tdop, expected 0, is " << last_msg_->tdop;
  EXPECT_EQ(last_msg_->tow, 0)
      << "incorrect value for tow, expected 0, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->vdop, 0)
      << "incorrect value for vdop, expected 0, is " << last_msg_->vdop;
}
class Test_legacy_auto_check_sbp_navigation_MsgDopsDepA5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_dops_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgDopsDepA5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_dops_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_dops_dep_a_t *>(last_msg_storage_)),
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
                      const msg_dops_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_dops_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgDopsDepA5, Test) {
  uint8_t encoded_frame[] = {
      85, 6,  2, 195, 4, 14,  128, 165, 68, 24,  92,
      1,  56, 1, 155, 0, 125, 2,   113, 0,  129, 93,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_dops_dep_a_t *test_msg = (msg_dops_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->gdop = 348;
  test_msg->hdop = 637;
  test_msg->pdop = 312;
  test_msg->tdop = 155;
  test_msg->tow = 407152000;
  test_msg->vdop = 113;

  EXPECT_EQ(send_message(0x206, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->gdop, 348)
      << "incorrect value for gdop, expected 348, is " << last_msg_->gdop;
  EXPECT_EQ(last_msg_->hdop, 637)
      << "incorrect value for hdop, expected 637, is " << last_msg_->hdop;
  EXPECT_EQ(last_msg_->pdop, 312)
      << "incorrect value for pdop, expected 312, is " << last_msg_->pdop;
  EXPECT_EQ(last_msg_->tdop, 155)
      << "incorrect value for tdop, expected 155, is " << last_msg_->tdop;
  EXPECT_EQ(last_msg_->tow, 407152000)
      << "incorrect value for tow, expected 407152000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->vdop, 113)
      << "incorrect value for vdop, expected 113, is " << last_msg_->vdop;
}
class Test_legacy_auto_check_sbp_navigation_MsgDopsDepA6
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_dops_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgDopsDepA6()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_dops_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_dops_dep_a_t *>(last_msg_storage_)),
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
                      const msg_dops_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_dops_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgDopsDepA6, Test) {
  uint8_t encoded_frame[] = {
      85, 6,  2, 195, 4, 14,  104, 169, 68, 24,  92,
      1,  55, 1, 155, 0, 125, 2,   113, 0,  209, 128,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_dops_dep_a_t *test_msg = (msg_dops_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->gdop = 348;
  test_msg->hdop = 637;
  test_msg->pdop = 311;
  test_msg->tdop = 155;
  test_msg->tow = 407153000;
  test_msg->vdop = 113;

  EXPECT_EQ(send_message(0x206, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->gdop, 348)
      << "incorrect value for gdop, expected 348, is " << last_msg_->gdop;
  EXPECT_EQ(last_msg_->hdop, 637)
      << "incorrect value for hdop, expected 637, is " << last_msg_->hdop;
  EXPECT_EQ(last_msg_->pdop, 311)
      << "incorrect value for pdop, expected 311, is " << last_msg_->pdop;
  EXPECT_EQ(last_msg_->tdop, 155)
      << "incorrect value for tdop, expected 155, is " << last_msg_->tdop;
  EXPECT_EQ(last_msg_->tow, 407153000)
      << "incorrect value for tow, expected 407153000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->vdop, 113)
      << "incorrect value for vdop, expected 113, is " << last_msg_->vdop;
}
class Test_legacy_auto_check_sbp_navigation_MsgDopsDepA7
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_dops_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgDopsDepA7()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_dops_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_dops_dep_a_t *>(last_msg_storage_)),
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
                      const msg_dops_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_dops_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgDopsDepA7, Test) {
  uint8_t encoded_frame[] = {
      85, 6,  2, 195, 4, 14,  80, 173, 68, 24, 92,
      1,  55, 1, 155, 0, 125, 2,  112, 0,  30, 6,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_dops_dep_a_t *test_msg = (msg_dops_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->gdop = 348;
  test_msg->hdop = 637;
  test_msg->pdop = 311;
  test_msg->tdop = 155;
  test_msg->tow = 407154000;
  test_msg->vdop = 112;

  EXPECT_EQ(send_message(0x206, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->gdop, 348)
      << "incorrect value for gdop, expected 348, is " << last_msg_->gdop;
  EXPECT_EQ(last_msg_->hdop, 637)
      << "incorrect value for hdop, expected 637, is " << last_msg_->hdop;
  EXPECT_EQ(last_msg_->pdop, 311)
      << "incorrect value for pdop, expected 311, is " << last_msg_->pdop;
  EXPECT_EQ(last_msg_->tdop, 155)
      << "incorrect value for tdop, expected 155, is " << last_msg_->tdop;
  EXPECT_EQ(last_msg_->tow, 407154000)
      << "incorrect value for tow, expected 407154000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->vdop, 112)
      << "incorrect value for vdop, expected 112, is " << last_msg_->vdop;
}
class Test_legacy_auto_check_sbp_navigation_MsgDopsDepA8
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_dops_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgDopsDepA8()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_dops_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_dops_dep_a_t *>(last_msg_storage_)),
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
                      const msg_dops_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_dops_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgDopsDepA8, Test) {
  uint8_t encoded_frame[] = {
      85, 6,  2, 195, 4, 14,  56, 177, 68, 24, 92,
      1,  55, 1, 155, 0, 125, 2,  112, 0,  70, 67,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_dops_dep_a_t *test_msg = (msg_dops_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->gdop = 348;
  test_msg->hdop = 637;
  test_msg->pdop = 311;
  test_msg->tdop = 155;
  test_msg->tow = 407155000;
  test_msg->vdop = 112;

  EXPECT_EQ(send_message(0x206, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->gdop, 348)
      << "incorrect value for gdop, expected 348, is " << last_msg_->gdop;
  EXPECT_EQ(last_msg_->hdop, 637)
      << "incorrect value for hdop, expected 637, is " << last_msg_->hdop;
  EXPECT_EQ(last_msg_->pdop, 311)
      << "incorrect value for pdop, expected 311, is " << last_msg_->pdop;
  EXPECT_EQ(last_msg_->tdop, 155)
      << "incorrect value for tdop, expected 155, is " << last_msg_->tdop;
  EXPECT_EQ(last_msg_->tow, 407155000)
      << "incorrect value for tow, expected 407155000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->vdop, 112)
      << "incorrect value for vdop, expected 112, is " << last_msg_->vdop;
}
