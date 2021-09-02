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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEF.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_baseline_ecef_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF0, Test) {
  uint8_t encoded_frame[] = {
      85,  11, 2,  211, 136, 20,  40, 244, 122, 19, 150, 98, 238, 255,
      190, 64, 20, 0,   246, 163, 9,  0,   0,   0,  14,  0,  219, 191,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_t *test_msg = (msg_baseline_ecef_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 14;
  test_msg->tow = 326825000;
  test_msg->x = -1154410;
  test_msg->y = 1327294;
  test_msg->z = 631798;

  EXPECT_EQ(send_message(0x20b, 35027, test_msg_len, test_msg_storage), SBP_OK);

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
  EXPECT_EQ(last_msg_->x, -1154410)
      << "incorrect value for x, expected -1154410, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, 1327294)
      << "incorrect value for y, expected 1327294, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 631798)
      << "incorrect value for z, expected 631798, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_baseline_ecef_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF1, Test) {
  uint8_t encoded_frame[] = {
      85,  11, 2,  211, 136, 20,  16, 248, 122, 19, 72, 99, 238, 255,
      191, 65, 20, 0,   138, 162, 9,  0,   0,   0,  15, 0,  240, 78,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_t *test_msg = (msg_baseline_ecef_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 15;
  test_msg->tow = 326826000;
  test_msg->x = -1154232;
  test_msg->y = 1327551;
  test_msg->z = 631434;

  EXPECT_EQ(send_message(0x20b, 35027, test_msg_len, test_msg_storage), SBP_OK);

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
  EXPECT_EQ(last_msg_->x, -1154232)
      << "incorrect value for x, expected -1154232, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, 1327551)
      << "incorrect value for y, expected 1327551, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 631434)
      << "incorrect value for z, expected 631434, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_baseline_ecef_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF2, Test) {
  uint8_t encoded_frame[] = {
      85,  11, 2,  211, 136, 20,  248, 251, 122, 19, 41, 99, 238, 255,
      181, 65, 20, 0,   148, 161, 9,   0,   0,   0,  15, 0,  4,   132,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_t *test_msg = (msg_baseline_ecef_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 15;
  test_msg->tow = 326827000;
  test_msg->x = -1154263;
  test_msg->y = 1327541;
  test_msg->z = 631188;

  EXPECT_EQ(send_message(0x20b, 35027, test_msg_len, test_msg_storage), SBP_OK);

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
  EXPECT_EQ(last_msg_->x, -1154263)
      << "incorrect value for x, expected -1154263, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, 1327541)
      << "incorrect value for y, expected 1327541, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 631188)
      << "incorrect value for z, expected 631188, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_baseline_ecef_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF3, Test) {
  uint8_t encoded_frame[] = {
      85, 11, 2,  211, 136, 20,  224, 255, 122, 19, 188, 97, 238, 255,
      81, 64, 20, 0,   65,  160, 9,   0,   0,   0,  15,  0,  67,  94,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_t *test_msg = (msg_baseline_ecef_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 15;
  test_msg->tow = 326828000;
  test_msg->x = -1154628;
  test_msg->y = 1327185;
  test_msg->z = 630849;

  EXPECT_EQ(send_message(0x20b, 35027, test_msg_len, test_msg_storage), SBP_OK);

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
  EXPECT_EQ(last_msg_->tow, 326828000)
      << "incorrect value for tow, expected 326828000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -1154628)
      << "incorrect value for x, expected -1154628, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, 1327185)
      << "incorrect value for y, expected 1327185, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 630849)
      << "incorrect value for z, expected 630849, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ecef_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ecef_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_baseline_ecef_t *>(last_msg_storage_)),
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
                      const msg_baseline_ecef_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ecef_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineECEF4, Test) {
  uint8_t encoded_frame[] = {
      85, 11, 2,  211, 136, 20,  200, 3, 123, 19, 189, 96, 238, 255,
      93, 63, 20, 0,   98,  159, 9,   0, 0,   0,  15,  0,  106, 94,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ecef_t *test_msg = (msg_baseline_ecef_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 15;
  test_msg->tow = 326829000;
  test_msg->x = -1154883;
  test_msg->y = 1326941;
  test_msg->z = 630626;

  EXPECT_EQ(send_message(0x20b, 35027, test_msg_len, test_msg_storage), SBP_OK);

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
  EXPECT_EQ(last_msg_->tow, 326829000)
      << "incorrect value for tow, expected 326829000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, -1154883)
      << "incorrect value for x, expected -1154883, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, 1326941)
      << "incorrect value for y, expected 1326941, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 630626)
      << "incorrect value for z, expected 630626, is " << last_msg_->z;
}
