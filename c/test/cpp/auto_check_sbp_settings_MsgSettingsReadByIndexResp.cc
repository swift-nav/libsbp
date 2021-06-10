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
// spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexResp.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t> {
 public:
  Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>(this),
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
  void handle_sbp_msg(
      uint16_t sender_id,
      const sbp_msg_settings_read_by_index_resp_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_settings_read_by_index_resp_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp0, Test) {
  uint8_t encoded_frame[] = {
      85,  167, 0,  246, 215, 78,  0,   0,   116, 101, 108, 101, 109, 101, 116,
      114, 121, 95, 114, 97,  100, 105, 111, 0,   99,  111, 110, 102, 105, 103,
      117, 114, 97, 116, 105, 111, 110, 95,  115, 116, 114, 105, 110, 103, 0,
      65,  84,  38, 70,  44,  65,  84,  83,  49,  61,  49,  49,  53,  44,  65,
      84,  83,  50, 61,  49,  50,  56,  44,  65,  84,  83,  53,  61,  48,  44,
      65,  84,  38, 87,  44,  65,  84,  90,  0,   248, 233,
  };

  sbp_msg_settings_read_by_index_resp_t test_msg{};
  test_msg.index = 0;

  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "telemetry_radio"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "configuration_string"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ"));
  EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(&test_msg),
            76);

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.index, 0)
      << "incorrect value for last_msg_.index, expected 0, is "
      << last_msg_.index;

  EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(&last_msg_),
            76);
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 0),
      "telemetry_radio");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 1),
      "configuration_string");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 2),
      "AT&F,ATS1=115,ATS2=128,ATS5=0,AT&W,ATZ");
}
class Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t> {
 public:
  Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>(this),
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
  void handle_sbp_msg(
      uint16_t sender_id,
      const sbp_msg_settings_read_by_index_resp_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_settings_read_by_index_resp_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp1, Test) {
  uint8_t encoded_frame[] = {
      85,  167, 0,  246, 215, 35,  1,   0,  117, 97, 114, 116, 95,  102, 116,
      100, 105, 0,  109, 111, 100, 101, 0,  83,  66, 80,  0,   101, 110, 117,
      109, 58,  83, 66,  80,  44,  78,  77, 69,  65, 0,   167, 243,
  };

  sbp_msg_settings_read_by_index_resp_t test_msg{};
  test_msg.index = 1;

  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "uart_ftdi"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(&test_msg,
                                                                      "mode"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(&test_msg,
                                                                      "SBP"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "enum:SBP,NMEA"));
  EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(&test_msg),
            33);

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.index, 1)
      << "incorrect value for last_msg_.index, expected 1, is "
      << last_msg_.index;

  EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(&last_msg_),
            33);
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 0),
      "uart_ftdi");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 1),
      "mode");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 2),
      "SBP");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 3),
      "enum:SBP,NMEA");
}
class Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t> {
 public:
  Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>(this),
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
  void handle_sbp_msg(
      uint16_t sender_id,
      const sbp_msg_settings_read_by_index_resp_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_settings_read_by_index_resp_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp2, Test) {
  uint8_t encoded_frame[] = {
      85,  167, 0,   246, 215, 35,  2,  0,   117, 97,  114, 116, 95,  102, 116,
      100, 105, 0,   115, 98,  112, 95, 109, 101, 115, 115, 97,  103, 101, 95,
      109, 97,  115, 107, 0,   54,  53, 53,  51,  53,  0,   4,   56,
  };

  sbp_msg_settings_read_by_index_resp_t test_msg{};
  test_msg.index = 2;

  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "uart_ftdi"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "sbp_message_mask"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(&test_msg,
                                                                      "65535"));
  EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(&test_msg),
            33);

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.index, 2)
      << "incorrect value for last_msg_.index, expected 2, is "
      << last_msg_.index;

  EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(&last_msg_),
            33);
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 0),
      "uart_ftdi");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 1),
      "sbp_message_mask");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 2),
      "65535");
}
class Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t> {
 public:
  Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>(this),
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
  void handle_sbp_msg(
      uint16_t sender_id,
      const sbp_msg_settings_read_by_index_resp_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_settings_read_by_index_resp_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp3, Test) {
  uint8_t encoded_frame[] = {
      85,  167, 0,   246, 215, 29, 3,  0,   117, 97,  114, 116, 95,
      102, 116, 100, 105, 0,   98, 97, 117, 100, 114, 97,  116, 101,
      0,   49,  48,  48,  48,  48, 48, 48,  0,   242, 146,
  };

  sbp_msg_settings_read_by_index_resp_t test_msg{};
  test_msg.index = 3;

  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "uart_ftdi"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "baudrate"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "1000000"));
  EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(&test_msg),
            27);

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.index, 3)
      << "incorrect value for last_msg_.index, expected 3, is "
      << last_msg_.index;

  EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(&last_msg_),
            27);
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 0),
      "uart_ftdi");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 1),
      "baudrate");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 2),
      "1000000");
}
class Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t> {
 public:
  Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>(this),
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
  void handle_sbp_msg(
      uint16_t sender_id,
      const sbp_msg_settings_read_by_index_resp_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_settings_read_by_index_resp_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_settings_MsgSettingsReadByIndexResp4, Test) {
  uint8_t encoded_frame[] = {
      85,  167, 0,  246, 215, 36,  4,   0,   117, 97, 114, 116, 95, 117, 97,
      114, 116, 97, 0,   109, 111, 100, 101, 0,   83, 66,  80,  0,  101, 110,
      117, 109, 58, 83,  66,  80,  44,  78,  77,  69, 65,  0,   22, 4,
  };

  sbp_msg_settings_read_by_index_resp_t test_msg{};
  test_msg.index = 4;

  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "uart_uarta"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(&test_msg,
                                                                      "mode"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(&test_msg,
                                                                      "SBP"));
  EXPECT_TRUE(sbp_msg_settings_read_by_index_resp_setting_add_section(
      &test_msg, "enum:SBP,NMEA"));
  EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(&test_msg),
            34);

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.index, 4)
      << "incorrect value for last_msg_.index, expected 4, is "
      << last_msg_.index;

  EXPECT_EQ(sbp_msg_settings_read_by_index_resp_setting_encoded_len(&last_msg_),
            34);
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 0),
      "uart_uarta");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 1),
      "mode");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 2),
      "SBP");
  EXPECT_STREQ(
      sbp_msg_settings_read_by_index_resp_setting_get_section(&last_msg_, 3),
      "enum:SBP,NMEA");
}
