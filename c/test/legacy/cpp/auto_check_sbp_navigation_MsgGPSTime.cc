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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTime.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgGPSTime0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTime0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_t *>(last_msg_storage_)),
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
                      const msg_gps_time_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTime0, Test) {
  uint8_t encoded_frame[] = {
      85,  2,  1,   211, 136, 11, 128, 7,  40,  244,
      122, 19, 244, 139, 2,   0,  0,   34, 152,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_t *test_msg = (msg_gps_time_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 166900;
  test_msg->tow = 326825000;
  test_msg->wn = 1920;

  EXPECT_EQ(send_message(0x102, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 166900)
      << "incorrect value for ns_residual, expected 166900, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 326825000)
      << "incorrect value for tow, expected 326825000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1920)
      << "incorrect value for wn, expected 1920, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTime1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTime1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_t *>(last_msg_storage_)),
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
                      const msg_gps_time_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTime1, Test) {
  uint8_t encoded_frame[] = {
      85,  2,  1,   211, 136, 11, 128, 7,  28, 246,
      122, 19, 126, 234, 3,   0,  0,   65, 3,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_t *test_msg = (msg_gps_time_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 256638;
  test_msg->tow = 326825500;
  test_msg->wn = 1920;

  EXPECT_EQ(send_message(0x102, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 256638)
      << "incorrect value for ns_residual, expected 256638, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 326825500)
      << "incorrect value for tow, expected 326825500, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1920)
      << "incorrect value for wn, expected 1920, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTime2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTime2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_t *>(last_msg_storage_)),
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
                      const msg_gps_time_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTime2, Test) {
  uint8_t encoded_frame[] = {
      85,  2,  1,   211, 136, 11, 128, 7,  16, 248,
      122, 19, 129, 12,  4,   0,  0,   12, 84,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_t *test_msg = (msg_gps_time_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 265345;
  test_msg->tow = 326826000;
  test_msg->wn = 1920;

  EXPECT_EQ(send_message(0x102, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 265345)
      << "incorrect value for ns_residual, expected 265345, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 326826000)
      << "incorrect value for tow, expected 326826000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1920)
      << "incorrect value for wn, expected 1920, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTime3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTime3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_t *>(last_msg_storage_)),
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
                      const msg_gps_time_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTime3, Test) {
  uint8_t encoded_frame[] = {
      85,  2,  1,   211, 136, 11, 128, 7,  4,   250,
      122, 19, 137, 204, 4,   0,  0,   50, 165,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_t *test_msg = (msg_gps_time_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 314505;
  test_msg->tow = 326826500;
  test_msg->wn = 1920;

  EXPECT_EQ(send_message(0x102, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 314505)
      << "incorrect value for ns_residual, expected 314505, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 326826500)
      << "incorrect value for tow, expected 326826500, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1920)
      << "incorrect value for wn, expected 1920, is " << last_msg_->wn;
}
class Test_legacy_auto_check_sbp_navigation_MsgGPSTime4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gps_time_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgGPSTime4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gps_time_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gps_time_t *>(last_msg_storage_)),
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
                      const msg_gps_time_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gps_time_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgGPSTime4, Test) {
  uint8_t encoded_frame[] = {
      85,  2,  1,   211, 136, 11, 128, 7,   248, 251,
      122, 19, 181, 137, 5,   0,  0,   180, 33,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gps_time_t *test_msg = (msg_gps_time_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 0;
  test_msg->ns_residual = 362933;
  test_msg->tow = 326827000;
  test_msg->wn = 1920;

  EXPECT_EQ(send_message(0x102, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->ns_residual, 362933)
      << "incorrect value for ns_residual, expected 362933, is "
      << last_msg_->ns_residual;
  EXPECT_EQ(last_msg_->tow, 326827000)
      << "incorrect value for tow, expected 326827000, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->wn, 1920)
      << "incorrect value for wn, expected 1920, is " << last_msg_->wn;
}
