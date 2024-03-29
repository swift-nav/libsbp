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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelCog.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/legacy_state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/navigation.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelCog0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_cog_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelCog0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_cog_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_cog_t *>(last_msg_storage_)),
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
                      const msg_vel_cog_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_cog_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelCog0, Test) {
  uint8_t encoded_frame[] = {
      85,  28,  2, 211, 136, 30,  48, 246, 122, 19,  232, 3,   0,
      0,   208, 7, 0,   0,   184, 11, 0,   0,   160, 15,  0,   0,
      136, 19,  0, 0,   112, 23,  0,  0,   62,  0,   212, 193,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_cog_t *test_msg = (msg_vel_cog_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cog = 1000;
  test_msg->cog_accuracy = 4000;
  test_msg->flags = 62;
  test_msg->sog = 2000;
  test_msg->sog_accuracy = 5000;
  test_msg->tow = 326825520;
  test_msg->v_up = 3000;
  test_msg->v_up_accuracy = 6000;

  EXPECT_EQ(send_message(0x21C, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->cog)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->cog)),
            1000)
      << "incorrect value for cog, expected 1000, is " << last_msg_->cog;
  EXPECT_EQ(get_as<decltype(last_msg_->cog_accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->cog_accuracy)),
            4000)
      << "incorrect value for cog_accuracy, expected 4000, is "
      << last_msg_->cog_accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            62)
      << "incorrect value for flags, expected 62, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sog)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sog)),
            2000)
      << "incorrect value for sog, expected 2000, is " << last_msg_->sog;
  EXPECT_EQ(get_as<decltype(last_msg_->sog_accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sog_accuracy)),
            5000)
      << "incorrect value for sog_accuracy, expected 5000, is "
      << last_msg_->sog_accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            326825520)
      << "incorrect value for tow, expected 326825520, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->v_up)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->v_up)),
            3000)
      << "incorrect value for v_up, expected 3000, is " << last_msg_->v_up;
  EXPECT_EQ(get_as<decltype(last_msg_->v_up_accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->v_up_accuracy)),
            6000)
      << "incorrect value for v_up_accuracy, expected 6000, is "
      << last_msg_->v_up_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelCog1
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_cog_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelCog1()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_cog_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_cog_t *>(last_msg_storage_)),
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
                      const msg_vel_cog_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_cog_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelCog1, Test) {
  uint8_t encoded_frame[] = {
      85,  28,  2, 211, 136, 30, 48,  246, 122, 19, 123, 0,   0,
      0,   200, 1, 0,   0,   24, 252, 255, 255, 0,  149, 186, 10,
      100, 0,   0, 0,   100, 0,  0,   0,   0,   0,  90,  114,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_cog_t *test_msg = (msg_vel_cog_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cog = 123;
  test_msg->cog_accuracy = 180000000;
  test_msg->flags = 0;
  test_msg->sog = 456;
  test_msg->sog_accuracy = 100;
  test_msg->tow = 326825520;
  test_msg->v_up = -1000;
  test_msg->v_up_accuracy = 100;

  EXPECT_EQ(send_message(0x21C, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->cog)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->cog)),
            123)
      << "incorrect value for cog, expected 123, is " << last_msg_->cog;
  EXPECT_EQ(get_as<decltype(last_msg_->cog_accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->cog_accuracy)),
            180000000)
      << "incorrect value for cog_accuracy, expected 180000000, is "
      << last_msg_->cog_accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sog)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sog)),
            456)
      << "incorrect value for sog, expected 456, is " << last_msg_->sog;
  EXPECT_EQ(get_as<decltype(last_msg_->sog_accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sog_accuracy)),
            100)
      << "incorrect value for sog_accuracy, expected 100, is "
      << last_msg_->sog_accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            326825520)
      << "incorrect value for tow, expected 326825520, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->v_up)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->v_up)),
            -1000)
      << "incorrect value for v_up, expected -1000, is " << last_msg_->v_up;
  EXPECT_EQ(get_as<decltype(last_msg_->v_up_accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->v_up_accuracy)),
            100)
      << "incorrect value for v_up_accuracy, expected 100, is "
      << last_msg_->v_up_accuracy;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelCog2
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_cog_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelCog2()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_cog_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_cog_t *>(last_msg_storage_)),
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
                      const msg_vel_cog_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_cog_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelCog2, Test) {
  uint8_t encoded_frame[] = {
      85, 28, 2, 211, 136, 30, 48, 246, 122, 19, 0, 0, 0, 0, 0, 0, 0, 0,  0,
      0,  0,  0, 0,   0,   0,  0,  0,   0,   0,  0, 0, 0, 0, 0, 0, 0, 42, 210,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_cog_t *test_msg = (msg_vel_cog_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cog = 0;
  test_msg->cog_accuracy = 0;
  test_msg->flags = 0;
  test_msg->sog = 0;
  test_msg->sog_accuracy = 0;
  test_msg->tow = 326825520;
  test_msg->v_up = 0;
  test_msg->v_up_accuracy = 0;

  EXPECT_EQ(send_message(0x21C, 35027, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->cog)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->cog)),
            0)
      << "incorrect value for cog, expected 0, is " << last_msg_->cog;
  EXPECT_EQ(get_as<decltype(last_msg_->cog_accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->cog_accuracy)),
            0)
      << "incorrect value for cog_accuracy, expected 0, is "
      << last_msg_->cog_accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->sog)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sog)),
            0)
      << "incorrect value for sog, expected 0, is " << last_msg_->sog;
  EXPECT_EQ(get_as<decltype(last_msg_->sog_accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sog_accuracy)),
            0)
      << "incorrect value for sog_accuracy, expected 0, is "
      << last_msg_->sog_accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            326825520)
      << "incorrect value for tow, expected 326825520, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->v_up)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->v_up)),
            0)
      << "incorrect value for v_up, expected 0, is " << last_msg_->v_up;
  EXPECT_EQ(get_as<decltype(last_msg_->v_up_accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->v_up_accuracy)),
            0)
      << "incorrect value for v_up_accuracy, expected 0, is "
      << last_msg_->v_up_accuracy;
}
