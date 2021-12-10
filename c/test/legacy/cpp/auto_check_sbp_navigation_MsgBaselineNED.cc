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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNED.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgBaselineNED0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ned_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineNED0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ned_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_baseline_ned_t *>(last_msg_storage_)),
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
                      const msg_baseline_ned_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ned_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineNED0, Test) {
  uint8_t encoded_frame[] = {
      85, 12,  2,   211, 136, 22, 40, 244, 122, 19, 201, 115, 12, 0,   179,
      88, 230, 255, 153, 125, 0,  0,  0,   0,   0,  0,   14,  0,  226, 70,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ned_t *test_msg = (msg_baseline_ned_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 32153;
  test_msg->e = -1681229;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = 816073;
  test_msg->n_sats = 14;
  test_msg->tow = 326825000;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x20c, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 32153)
      << "incorrect value for d, expected 32153, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, -1681229)
      << "incorrect value for e, expected -1681229, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, 816073)
      << "incorrect value for n, expected 816073, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 14)
      << "incorrect value for n_sats, expected 14, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 326825000)
      << "incorrect value for tow, expected 326825000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineNED1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ned_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineNED1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ned_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_baseline_ned_t *>(last_msg_storage_)),
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
                      const msg_baseline_ned_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ned_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineNED1, Test) {
  uint8_t encoded_frame[] = {
      85, 12,  2,   211, 136, 22, 16, 248, 122, 19, 98, 115, 12, 0,  194,
      88, 230, 255, 110, 127, 0,  0,  0,   0,   0,  0,  15,  0,  69, 93,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ned_t *test_msg = (msg_baseline_ned_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 32622;
  test_msg->e = -1681214;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = 815970;
  test_msg->n_sats = 15;
  test_msg->tow = 326826000;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x20c, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 32622)
      << "incorrect value for d, expected 32622, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, -1681214)
      << "incorrect value for e, expected -1681214, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, 815970)
      << "incorrect value for n, expected 815970, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 15)
      << "incorrect value for n_sats, expected 15, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 326826000)
      << "incorrect value for tow, expected 326826000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineNED2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ned_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineNED2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ned_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_baseline_ned_t *>(last_msg_storage_)),
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
                      const msg_baseline_ned_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ned_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineNED2, Test) {
  uint8_t encoded_frame[] = {
      85, 12,  2,   211, 136, 22, 248, 251, 122, 19, 143, 114, 12, 0,   173,
      88, 230, 255, 238, 127, 0,  0,   0,   0,   0,  0,   15,  0,  210, 169,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ned_t *test_msg = (msg_baseline_ned_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 32750;
  test_msg->e = -1681235;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = 815759;
  test_msg->n_sats = 15;
  test_msg->tow = 326827000;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x20c, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 32750)
      << "incorrect value for d, expected 32750, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, -1681235)
      << "incorrect value for e, expected -1681235, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, 815759)
      << "incorrect value for n, expected 815759, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 15)
      << "incorrect value for n_sats, expected 15, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 326827000)
      << "incorrect value for tow, expected 326827000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineNED3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ned_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineNED3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ned_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_baseline_ned_t *>(last_msg_storage_)),
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
                      const msg_baseline_ned_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ned_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineNED3, Test) {
  uint8_t encoded_frame[] = {
      85, 12,  2,   211, 136, 22, 224, 255, 122, 19, 86, 112, 12, 0,   51,
      88, 230, 255, 47,  127, 0,  0,   0,   0,   0,  0,  15,  0,  135, 107,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ned_t *test_msg = (msg_baseline_ned_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 32559;
  test_msg->e = -1681357;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = 815190;
  test_msg->n_sats = 15;
  test_msg->tow = 326828000;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x20c, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 32559)
      << "incorrect value for d, expected 32559, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, -1681357)
      << "incorrect value for e, expected -1681357, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, 815190)
      << "incorrect value for n, expected 815190, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 15)
      << "incorrect value for n_sats, expected 15, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 326828000)
      << "incorrect value for tow, expected 326828000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgBaselineNED4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_baseline_ned_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgBaselineNED4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_baseline_ned_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_baseline_ned_t *>(last_msg_storage_)),
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
                      const msg_baseline_ned_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_baseline_ned_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgBaselineNED4, Test) {
  uint8_t encoded_frame[] = {
      85, 12,  2,   211, 136, 22, 200, 3, 123, 19, 214, 110, 12, 0,   220,
      87, 230, 255, 165, 126, 0,  0,   0, 0,   0,  0,   15,  0,  190, 80,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_baseline_ned_t *test_msg = (msg_baseline_ned_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->d = 32421;
  test_msg->e = -1681444;
  test_msg->flags = 0;
  test_msg->h_accuracy = 0;
  test_msg->n = 814806;
  test_msg->n_sats = 15;
  test_msg->tow = 326829000;
  test_msg->v_accuracy = 0;

  EXPECT_EQ(send_message(0x20c, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->d, 32421)
      << "incorrect value for d, expected 32421, is " << last_msg_->d;
  EXPECT_EQ(last_msg_->e, -1681444)
      << "incorrect value for e, expected -1681444, is " << last_msg_->e;
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->h_accuracy, 0)
      << "incorrect value for h_accuracy, expected 0, is "
      << last_msg_->h_accuracy;
  EXPECT_EQ(last_msg_->n, 814806)
      << "incorrect value for n, expected 814806, is " << last_msg_->n;
  EXPECT_EQ(last_msg_->n_sats, 15)
      << "incorrect value for n_sats, expected 15, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 326829000)
      << "incorrect value for tow, expected 326829000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_accuracy, 0)
      << "incorrect value for v_accuracy, expected 0, is "
      << last_msg_->v_accuracy;
}
