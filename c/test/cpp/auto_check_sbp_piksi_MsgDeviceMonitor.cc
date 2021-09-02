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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgDeviceMonitor.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_piksi_MsgDeviceMonitor0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_device_monitor_t> {
 public:
  Test_auto_check_sbp_piksi_MsgDeviceMonitor0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_device_monitor_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_device_monitor_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_device_monitor_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_piksi_MsgDeviceMonitor0, Test) {
  uint8_t encoded_frame[] = {
      85, 181, 0, 95, 66, 10,  241, 216, 219,
      3,  253, 6, 21, 24, 168, 18,  207, 233,
  };

  sbp_msg_device_monitor_t test_msg{};
  test_msg.cpu_temperature = 6165;
  test_msg.cpu_vaux = 1789;
  test_msg.cpu_vint = 987;
  test_msg.dev_vin = -9999;
  test_msg.fe_temperature = 4776;

  EXPECT_EQ(send_message(16991, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 16991);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.cpu_temperature, 6165)
      << "incorrect value for last_msg_.cpu_temperature, expected 6165, is "
      << last_msg_.cpu_temperature;
  EXPECT_EQ(last_msg_.cpu_vaux, 1789)
      << "incorrect value for last_msg_.cpu_vaux, expected 1789, is "
      << last_msg_.cpu_vaux;
  EXPECT_EQ(last_msg_.cpu_vint, 987)
      << "incorrect value for last_msg_.cpu_vint, expected 987, is "
      << last_msg_.cpu_vint;
  EXPECT_EQ(last_msg_.dev_vin, -9999)
      << "incorrect value for last_msg_.dev_vin, expected -9999, is "
      << last_msg_.dev_vin;
  EXPECT_EQ(last_msg_.fe_temperature, 4776)
      << "incorrect value for last_msg_.fe_temperature, expected 4776, is "
      << last_msg_.fe_temperature;
}
class Test_auto_check_sbp_piksi_MsgDeviceMonitor1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_device_monitor_t> {
 public:
  Test_auto_check_sbp_piksi_MsgDeviceMonitor1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_device_monitor_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_device_monitor_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_device_monitor_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_piksi_MsgDeviceMonitor1, Test) {
  uint8_t encoded_frame[] = {
      85, 181, 0, 95, 66, 10,  241, 216, 219,
      3,  254, 6, 24, 24, 168, 18,  169, 30,
  };

  sbp_msg_device_monitor_t test_msg{};
  test_msg.cpu_temperature = 6168;
  test_msg.cpu_vaux = 1790;
  test_msg.cpu_vint = 987;
  test_msg.dev_vin = -9999;
  test_msg.fe_temperature = 4776;

  EXPECT_EQ(send_message(16991, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 16991);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.cpu_temperature, 6168)
      << "incorrect value for last_msg_.cpu_temperature, expected 6168, is "
      << last_msg_.cpu_temperature;
  EXPECT_EQ(last_msg_.cpu_vaux, 1790)
      << "incorrect value for last_msg_.cpu_vaux, expected 1790, is "
      << last_msg_.cpu_vaux;
  EXPECT_EQ(last_msg_.cpu_vint, 987)
      << "incorrect value for last_msg_.cpu_vint, expected 987, is "
      << last_msg_.cpu_vint;
  EXPECT_EQ(last_msg_.dev_vin, -9999)
      << "incorrect value for last_msg_.dev_vin, expected -9999, is "
      << last_msg_.dev_vin;
  EXPECT_EQ(last_msg_.fe_temperature, 4776)
      << "incorrect value for last_msg_.fe_temperature, expected 4776, is "
      << last_msg_.fe_temperature;
}
class Test_auto_check_sbp_piksi_MsgDeviceMonitor2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_device_monitor_t> {
 public:
  Test_auto_check_sbp_piksi_MsgDeviceMonitor2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_device_monitor_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_device_monitor_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_device_monitor_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_piksi_MsgDeviceMonitor2, Test) {
  uint8_t encoded_frame[] = {
      85, 181, 0, 95, 66, 10,  241, 216, 219,
      3,  253, 6, 22, 24, 168, 18,  19,  114,
  };

  sbp_msg_device_monitor_t test_msg{};
  test_msg.cpu_temperature = 6166;
  test_msg.cpu_vaux = 1789;
  test_msg.cpu_vint = 987;
  test_msg.dev_vin = -9999;
  test_msg.fe_temperature = 4776;

  EXPECT_EQ(send_message(16991, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 16991);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.cpu_temperature, 6166)
      << "incorrect value for last_msg_.cpu_temperature, expected 6166, is "
      << last_msg_.cpu_temperature;
  EXPECT_EQ(last_msg_.cpu_vaux, 1789)
      << "incorrect value for last_msg_.cpu_vaux, expected 1789, is "
      << last_msg_.cpu_vaux;
  EXPECT_EQ(last_msg_.cpu_vint, 987)
      << "incorrect value for last_msg_.cpu_vint, expected 987, is "
      << last_msg_.cpu_vint;
  EXPECT_EQ(last_msg_.dev_vin, -9999)
      << "incorrect value for last_msg_.dev_vin, expected -9999, is "
      << last_msg_.dev_vin;
  EXPECT_EQ(last_msg_.fe_temperature, 4776)
      << "incorrect value for last_msg_.fe_temperature, expected 4776, is "
      << last_msg_.fe_temperature;
}
class Test_auto_check_sbp_piksi_MsgDeviceMonitor3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_device_monitor_t> {
 public:
  Test_auto_check_sbp_piksi_MsgDeviceMonitor3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_device_monitor_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_device_monitor_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_device_monitor_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_piksi_MsgDeviceMonitor3, Test) {
  uint8_t encoded_frame[] = {
      85, 181, 0, 95, 66, 10,  241, 216, 218,
      3,  252, 6, 6,  24, 168, 18,  199, 107,
  };

  sbp_msg_device_monitor_t test_msg{};
  test_msg.cpu_temperature = 6150;
  test_msg.cpu_vaux = 1788;
  test_msg.cpu_vint = 986;
  test_msg.dev_vin = -9999;
  test_msg.fe_temperature = 4776;

  EXPECT_EQ(send_message(16991, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 16991);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.cpu_temperature, 6150)
      << "incorrect value for last_msg_.cpu_temperature, expected 6150, is "
      << last_msg_.cpu_temperature;
  EXPECT_EQ(last_msg_.cpu_vaux, 1788)
      << "incorrect value for last_msg_.cpu_vaux, expected 1788, is "
      << last_msg_.cpu_vaux;
  EXPECT_EQ(last_msg_.cpu_vint, 986)
      << "incorrect value for last_msg_.cpu_vint, expected 986, is "
      << last_msg_.cpu_vint;
  EXPECT_EQ(last_msg_.dev_vin, -9999)
      << "incorrect value for last_msg_.dev_vin, expected -9999, is "
      << last_msg_.dev_vin;
  EXPECT_EQ(last_msg_.fe_temperature, 4776)
      << "incorrect value for last_msg_.fe_temperature, expected 4776, is "
      << last_msg_.fe_temperature;
}
class Test_auto_check_sbp_piksi_MsgDeviceMonitor4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_device_monitor_t> {
 public:
  Test_auto_check_sbp_piksi_MsgDeviceMonitor4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_device_monitor_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_device_monitor_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_device_monitor_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_piksi_MsgDeviceMonitor4, Test) {
  uint8_t encoded_frame[] = {
      85, 181, 0, 95,  66, 10,  241, 216, 220,
      3,  253, 6, 235, 23, 168, 18,  241, 63,
  };

  sbp_msg_device_monitor_t test_msg{};
  test_msg.cpu_temperature = 6123;
  test_msg.cpu_vaux = 1789;
  test_msg.cpu_vint = 988;
  test_msg.dev_vin = -9999;
  test_msg.fe_temperature = 4776;

  EXPECT_EQ(send_message(16991, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 16991);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.cpu_temperature, 6123)
      << "incorrect value for last_msg_.cpu_temperature, expected 6123, is "
      << last_msg_.cpu_temperature;
  EXPECT_EQ(last_msg_.cpu_vaux, 1789)
      << "incorrect value for last_msg_.cpu_vaux, expected 1789, is "
      << last_msg_.cpu_vaux;
  EXPECT_EQ(last_msg_.cpu_vint, 988)
      << "incorrect value for last_msg_.cpu_vint, expected 988, is "
      << last_msg_.cpu_vint;
  EXPECT_EQ(last_msg_.dev_vin, -9999)
      << "incorrect value for last_msg_.dev_vin, expected -9999, is "
      << last_msg_.dev_vin;
  EXPECT_EQ(last_msg_.fe_temperature, 4776)
      << "incorrect value for last_msg_.fe_temperature, expected 4776, is "
      << last_msg_.fe_temperature;
}
