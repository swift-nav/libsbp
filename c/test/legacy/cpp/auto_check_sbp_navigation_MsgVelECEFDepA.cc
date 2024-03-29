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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFDepA.yaml by
// generate.py. Do not modify by hand!

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
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  4,   2,   246, 215, 20,  20,  46,  39, 0, 218, 11, 0,  0,
      134, 245, 255, 255, 163, 252, 255, 255, 0,  0, 9,   0,  80, 236,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 9;
  test_msg->tow = 2567700;
  test_msg->x = 3034;
  test_msg->y = -2682;
  test_msg->z = -861;

  EXPECT_EQ(send_message(0x204, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            2567700)
      << "incorrect value for tow, expected 2567700, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            3034)
      << "incorrect value for x, expected 3034, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            -2682)
      << "incorrect value for y, expected -2682, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            -861)
      << "incorrect value for z, expected -861, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA1
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA1()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA1, Test) {
  uint8_t encoded_frame[] = {
      85, 4,   2,   246, 215, 20,  120, 46,  39, 0, 68, 11, 0,   0,
      24, 246, 255, 255, 220, 252, 255, 255, 0,  0, 9,  0,  248, 138,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 9;
  test_msg->tow = 2567800;
  test_msg->x = 2884;
  test_msg->y = -2536;
  test_msg->z = -804;

  EXPECT_EQ(send_message(0x204, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            2567800)
      << "incorrect value for tow, expected 2567800, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            2884)
      << "incorrect value for x, expected 2884, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            -2536)
      << "incorrect value for y, expected -2536, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            -804)
      << "incorrect value for z, expected -804, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA2
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA2()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA2, Test) {
  uint8_t encoded_frame[] = {
      85, 4,   2,   246, 215, 20,  220, 46,  39, 0, 21, 11, 0,  0,
      77, 246, 255, 255, 247, 252, 255, 255, 0,  0, 9,  0,  25, 174,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 9;
  test_msg->tow = 2567900;
  test_msg->x = 2837;
  test_msg->y = -2483;
  test_msg->z = -777;

  EXPECT_EQ(send_message(0x204, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            2567900)
      << "incorrect value for tow, expected 2567900, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            2837)
      << "incorrect value for x, expected 2837, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            -2483)
      << "incorrect value for y, expected -2483, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            -777)
      << "incorrect value for z, expected -777, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA3
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA3()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA3, Test) {
  uint8_t encoded_frame[] = {
      85, 4,   2,   246, 215, 20,  64,  47,  39, 0, 121, 11, 0,   0,
      2,  246, 255, 255, 234, 252, 255, 255, 0,  0, 9,   0,  195, 228,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 9;
  test_msg->tow = 2568000;
  test_msg->x = 2937;
  test_msg->y = -2558;
  test_msg->z = -790;

  EXPECT_EQ(send_message(0x204, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            2568000)
      << "incorrect value for tow, expected 2568000, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            2937)
      << "incorrect value for x, expected 2937, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            -2558)
      << "incorrect value for y, expected -2558, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            -790)
      << "incorrect value for z, expected -790, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA4
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA4()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA4, Test) {
  uint8_t encoded_frame[] = {
      85, 4,   2,   246, 215, 20,  164, 47,  39, 0, 31, 11, 0,   0,
      93, 246, 255, 255, 16,  253, 255, 255, 0,  0, 9,  0,  219, 164,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 9;
  test_msg->tow = 2568100;
  test_msg->x = 2847;
  test_msg->y = -2467;
  test_msg->z = -752;

  EXPECT_EQ(send_message(0x204, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            9)
      << "incorrect value for n_sats, expected 9, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            2568100)
      << "incorrect value for tow, expected 2568100, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            2847)
      << "incorrect value for x, expected 2847, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            -2467)
      << "incorrect value for y, expected -2467, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            -752)
      << "incorrect value for z, expected -752, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA5
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA5()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA5, Test) {
  uint8_t encoded_frame[] = {
      85,  4,   2,   195, 4,   20,  212, 157, 67, 24, 24, 0, 0,  0,
      245, 255, 255, 255, 219, 255, 255, 255, 0,  0,  8,  0, 68, 255,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 8;
  test_msg->tow = 407084500;
  test_msg->x = 24;
  test_msg->y = -11;
  test_msg->z = -37;

  EXPECT_EQ(send_message(0x204, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            8)
      << "incorrect value for n_sats, expected 8, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            407084500)
      << "incorrect value for tow, expected 407084500, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            24)
      << "incorrect value for x, expected 24, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            -11)
      << "incorrect value for y, expected -11, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            -37)
      << "incorrect value for z, expected -37, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA6
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA6()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA6, Test) {
  uint8_t encoded_frame[] = {
      85,  4,   2,   195, 4,  20, 56, 158, 67, 24, 4, 0, 0,   0,
      234, 255, 255, 255, 18, 0,  0,  0,   0,  0,  8, 0, 214, 136,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 8;
  test_msg->tow = 407084600;
  test_msg->x = 4;
  test_msg->y = -22;
  test_msg->z = 18;

  EXPECT_EQ(send_message(0x204, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            8)
      << "incorrect value for n_sats, expected 8, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            407084600)
      << "incorrect value for tow, expected 407084600, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            4)
      << "incorrect value for x, expected 4, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            -22)
      << "incorrect value for y, expected -22, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            18)
      << "incorrect value for z, expected 18, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA7
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA7()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA7, Test) {
  uint8_t encoded_frame[] = {
      85, 4, 2, 195, 4, 20, 156, 158, 67, 24, 230, 255, 255, 255,
      4,  0, 0, 0,   1, 0,  0,   0,   0,  0,  8,   0,   122, 159,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 8;
  test_msg->tow = 407084700;
  test_msg->x = -26;
  test_msg->y = 4;
  test_msg->z = 1;

  EXPECT_EQ(send_message(0x204, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            8)
      << "incorrect value for n_sats, expected 8, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            407084700)
      << "incorrect value for tow, expected 407084700, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            -26)
      << "incorrect value for x, expected -26, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            4)
      << "incorrect value for y, expected 4, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            1)
      << "incorrect value for z, expected 1, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA8
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA8()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA8, Test) {
  uint8_t encoded_frame[] = {
      85,  4,   2,   195, 4,  20, 0, 159, 67, 24, 247, 255, 255, 255,
      237, 255, 255, 255, 28, 0,  0, 0,   0,  0,  8,   0,   232, 146,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 8;
  test_msg->tow = 407084800;
  test_msg->x = -9;
  test_msg->y = -19;
  test_msg->z = 28;

  EXPECT_EQ(send_message(0x204, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            8)
      << "incorrect value for n_sats, expected 8, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            407084800)
      << "incorrect value for tow, expected 407084800, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            -9)
      << "incorrect value for x, expected -9, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            -19)
      << "incorrect value for y, expected -19, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            28)
      << "incorrect value for z, expected 28, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA9
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA9()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA9, Test) {
  uint8_t encoded_frame[] = {
      85, 4, 2, 195, 4,   20,  100, 159, 67, 24, 255, 255, 255, 255,
      2,  0, 0, 0,   245, 255, 255, 255, 0,  0,  8,   0,   171, 238,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 8;
  test_msg->tow = 407084900;
  test_msg->x = -1;
  test_msg->y = 2;
  test_msg->z = -11;

  EXPECT_EQ(send_message(0x204, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            8)
      << "incorrect value for n_sats, expected 8, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            407084900)
      << "incorrect value for tow, expected 407084900, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            -1)
      << "incorrect value for x, expected -1, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            2)
      << "incorrect value for y, expected 2, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            -11)
      << "incorrect value for z, expected -11, is " << last_msg_->z;
}
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA10
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA10()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_dep_a_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFDepA10, Test) {
  uint8_t encoded_frame[] = {
      85,  4,   2,   195, 4,  20, 46, 162, 68, 24, 207, 255, 255, 255,
      185, 255, 255, 255, 65, 0,  0,  0,   0,  0,  5,   0,   82,  154,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_dep_a_t *test_msg = (msg_vel_ecef_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->accuracy = 0;
  test_msg->flags = 0;
  test_msg->n_sats = 5;
  test_msg->tow = 407151150;
  test_msg->x = -49;
  test_msg->y = -71;
  test_msg->z = 65;

  EXPECT_EQ(send_message(0x204, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->accuracy)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->accuracy)),
            0)
      << "incorrect value for accuracy, expected 0, is " << last_msg_->accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            5)
      << "incorrect value for n_sats, expected 5, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            407151150)
      << "incorrect value for tow, expected 407151150, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->x)),
            -49)
      << "incorrect value for x, expected -49, is " << last_msg_->x;
  EXPECT_EQ(get_as<decltype(last_msg_->y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->y)),
            -71)
      << "incorrect value for y, expected -71, is " << last_msg_->y;
  EXPECT_EQ(get_as<decltype(last_msg_->z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->z)),
            65)
      << "incorrect value for z, expected 65, is " << last_msg_->z;
}
