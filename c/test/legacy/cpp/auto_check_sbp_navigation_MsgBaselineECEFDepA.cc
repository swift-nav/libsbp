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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEFDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA0, Test) {
  uint8_t encoded_frame[] = {
      85, 2,   2,   246, 215, 20,  20,  46,  39, 0, 21, 48, 255, 255,
      52, 117, 255, 255, 216, 211, 254, 255, 0,  0, 9,  1,  50,  137,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 1;
  test_msg->n_sats = 9;
  test_msg->tow = 2567700;
  test_msg->x = -53227;
  test_msg->y = -35532;
  test_msg->z = -76840;

  EXPECT_EQ(send_message(0x202, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 1)
      << "incorrect value for flags, expected 1, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2567700)
      << "incorrect value for tow, expected 2567700, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -53227)
      << "incorrect value for x, expected -53227, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -35532)
      << "incorrect value for y, expected -35532, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, -76840)
      << "incorrect value for z, expected -76840, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA1, Test) {
  uint8_t encoded_frame[] = {
      85, 2,   2,   246, 215, 20,  120, 46,  39, 0, 58, 49, 255, 255,
      49, 116, 255, 255, 134, 211, 254, 255, 0,  0, 9,  1,  227, 155,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 1;
  test_msg->n_sats = 9;
  test_msg->tow = 2567800;
  test_msg->x = -52934;
  test_msg->y = -35791;
  test_msg->z = -76922;

  EXPECT_EQ(send_message(0x202, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 1)
      << "incorrect value for flags, expected 1, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2567800)
      << "incorrect value for tow, expected 2567800, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -52934)
      << "incorrect value for x, expected -52934, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -35791)
      << "incorrect value for y, expected -35791, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, -76922)
      << "incorrect value for z, expected -76922, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA2, Test) {
  uint8_t encoded_frame[] = {
      85, 2,   2,   246, 215, 20,  220, 46,  39, 0, 97, 50, 255, 255,
      47, 115, 255, 255, 52,  211, 254, 255, 0,  0, 9,  1,  61,  126,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 1;
  test_msg->n_sats = 9;
  test_msg->tow = 2567900;
  test_msg->x = -52639;
  test_msg->y = -36049;
  test_msg->z = -77004;

  EXPECT_EQ(send_message(0x202, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 1)
      << "incorrect value for flags, expected 1, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2567900)
      << "incorrect value for tow, expected 2567900, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -52639)
      << "incorrect value for x, expected -52639, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -36049)
      << "incorrect value for y, expected -36049, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, -77004)
      << "incorrect value for z, expected -77004, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA3, Test) {
  uint8_t encoded_frame[] = {
      85, 2,   2,   246, 215, 20,  64,  47,  39, 0, 136, 51, 255, 255,
      45, 114, 255, 255, 228, 210, 254, 255, 0,  0, 9,   1,  200, 79,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 1;
  test_msg->n_sats = 9;
  test_msg->tow = 2568000;
  test_msg->x = -52344;
  test_msg->y = -36307;
  test_msg->z = -77084;

  EXPECT_EQ(send_message(0x202, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 1)
      << "incorrect value for flags, expected 1, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2568000)
      << "incorrect value for tow, expected 2568000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -52344)
      << "incorrect value for x, expected -52344, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -36307)
      << "incorrect value for y, expected -36307, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, -77084)
      << "incorrect value for z, expected -77084, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA4, Test) {
  uint8_t encoded_frame[] = {
      85, 2,   2,   246, 215, 20,  164, 47,  39, 0, 176, 52, 255, 255,
      44, 113, 255, 255, 149, 210, 254, 255, 0,  0, 9,   1,  104, 24,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 1;
  test_msg->n_sats = 9;
  test_msg->tow = 2568100;
  test_msg->x = -52048;
  test_msg->y = -36564;
  test_msg->z = -77163;

  EXPECT_EQ(send_message(0x202, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 1)
      << "incorrect value for flags, expected 1, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2568100)
      << "incorrect value for tow, expected 2568100, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -52048)
      << "incorrect value for x, expected -52048, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -36564)
      << "incorrect value for y, expected -36564, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, -77163)
      << "incorrect value for z, expected -77163, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA5, Test) {
  uint8_t encoded_frame[] = {
      85,  2,   2,   195, 4,   20, 156, 21, 69, 24, 169, 231, 255, 255,
      102, 208, 255, 255, 251, 28, 0,   0,  0,  0,  6,   0,   146, 168,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 6;
  test_msg->tow = 407180700;
  test_msg->x = -6231;
  test_msg->y = -12186;
  test_msg->z = 7419;

  EXPECT_EQ(send_message(0x202, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 6)
      << "incorrect value for n_sats, expected 6, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407180700)
      << "incorrect value for tow, expected 407180700, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -6231)
      << "incorrect value for x, expected -6231, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -12186)
      << "incorrect value for y, expected -12186, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 7419)
      << "incorrect value for z, expected 7419, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA6
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA6()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA6, Test) {
  uint8_t encoded_frame[] = {
      85,  2,   2,   195, 4,   20, 0, 22, 69, 24, 169, 231, 255, 255,
      103, 208, 255, 255, 252, 28, 0, 0,  0,  0,  6,   0,   34,  116,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 6;
  test_msg->tow = 407180800;
  test_msg->x = -6231;
  test_msg->y = -12185;
  test_msg->z = 7420;

  EXPECT_EQ(send_message(0x202, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 6)
      << "incorrect value for n_sats, expected 6, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407180800)
      << "incorrect value for tow, expected 407180800, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -6231)
      << "incorrect value for x, expected -6231, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -12185)
      << "incorrect value for y, expected -12185, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 7420)
      << "incorrect value for z, expected 7420, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA7
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA7()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA7, Test) {
  uint8_t encoded_frame[] = {
      85,  2,   2,   195, 4,   20, 100, 22, 69, 24, 30, 224, 255, 255,
      192, 183, 255, 255, 239, 53, 0,   0,  0,  0,  6,  0,   225, 15,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 6;
  test_msg->tow = 407180900;
  test_msg->x = -8162;
  test_msg->y = -18496;
  test_msg->z = 13807;

  EXPECT_EQ(send_message(0x202, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 6)
      << "incorrect value for n_sats, expected 6, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407180900)
      << "incorrect value for tow, expected 407180900, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -8162)
      << "incorrect value for x, expected -8162, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -18496)
      << "incorrect value for y, expected -18496, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 13807)
      << "incorrect value for z, expected 13807, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA8
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA8()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA8, Test) {
  uint8_t encoded_frame[] = {
      85,  2,   2,   195, 4,   20, 200, 22, 69, 24, 28, 224, 255, 255,
      191, 183, 255, 255, 242, 53, 0,   0,  0,  0,  6,  0,   35,  100,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 6;
  test_msg->tow = 407181000;
  test_msg->x = -8164;
  test_msg->y = -18497;
  test_msg->z = 13810;

  EXPECT_EQ(send_message(0x202, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 6)
      << "incorrect value for n_sats, expected 6, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407181000)
      << "incorrect value for tow, expected 407181000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -8164)
      << "incorrect value for x, expected -8164, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -18497)
      << "incorrect value for y, expected -18497, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 13810)
      << "incorrect value for z, expected 13810, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA9
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA9()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA9, Test) {
  uint8_t encoded_frame[] = {
      85, 2,   2,   195, 4,   20, 44, 23, 69, 24, 24, 227, 255, 255,
      25, 195, 255, 255, 153, 59, 0,  0,  0,  0,  6,  0,   66,  66,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 6;
  test_msg->tow = 407181100;
  test_msg->x = -7400;
  test_msg->y = -15591;
  test_msg->z = 15257;

  EXPECT_EQ(send_message(0x202, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 6)
      << "incorrect value for n_sats, expected 6, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407181100)
      << "incorrect value for tow, expected 407181100, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -7400)
      << "incorrect value for x, expected -7400, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -15591)
      << "incorrect value for y, expected -15591, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 15257)
      << "incorrect value for z, expected 15257, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA10
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA10()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_baseline_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEFDepA10, Test) {
  uint8_t encoded_frame[] = {
      85, 2,   2,   195, 4,   20, 144, 23, 69, 24, 23, 227, 255, 255,
      25, 195, 255, 255, 153, 59, 0,   0,  0,  0,  6,  0,   35,  135,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_dep_a_t *test_msg =
      (msg_baseline_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 6;
  test_msg->tow = 407181200;
  test_msg->x = -7401;
  test_msg->y = -15591;
  test_msg->z = 15257;

  EXPECT_EQ(send_message(0x202, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->accuracy, 0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 6)
      << "incorrect value for n_sats, expected 6, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 407181200)
      << "incorrect value for tow, expected 407181200, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -7401)
      << "incorrect value for x, expected -7401, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, -15591)
      << "incorrect value for y, expected -15591, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 15257)
      << "incorrect value for z, expected 15257, is " << last_msg_->z;
}
