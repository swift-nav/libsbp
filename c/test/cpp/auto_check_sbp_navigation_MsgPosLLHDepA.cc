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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgPosLLHDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,   246, 215, 34,  20, 46,  39, 0,   250, 29,  226, 186,
      235, 182, 66,  64,  19,  203, 51, 196, 24, 139, 94,  192, 31,  157,
      160, 232, 122, 115, 81,  64,  0,  0,   0,  0,   9,   0,   236, 139,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.height = 69.80437675175607;
  test_msg.lat = 37.42906890908121;
  test_msg.lon = -122.17338662202773;
  test_msg.n_sats = 9;
  test_msg.tow = 2567700;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 69.8043767518 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 69.8043767518, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.4290689091 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.4290689091, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.173386622 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.173386622, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567700)
      << "incorrect value for last_msg_.tow, expected 2567700, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLHDepA1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA1, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,  246, 215, 34, 20,  46, 39, 0,   161, 51,  75,  148,
      235, 182, 66, 64,  36,  41, 246, 30, 25, 139, 94,  192, 254, 218,
      49,  127, 10, 108, 81,  64, 0,   0,  0,  0,   9,   1,   25,  117,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 1;
  test_msg.h_accuracy = 0;
  test_msg.height = 69.68814067715354;
  test_msg.lat = 37.42906430885274;
  test_msg.lon = -122.17340826071865;
  test_msg.n_sats = 9;
  test_msg.tow = 2567700;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 1)
      << "incorrect value for last_msg_.flags, expected 1, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 69.6881406772 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 69.6881406772, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.4290643089 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.4290643089, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.173408261 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.173408261, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567700)
      << "incorrect value for last_msg_.tow, expected 2567700, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLHDepA2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA2, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,   246, 215, 34, 120, 46, 39, 0,   56, 214, 210, 65,
      235, 182, 66,  64,  13,  46, 132, 80, 25, 139, 94, 192, 22,  143,
      46,  234, 191, 95,  81,  64, 0,   0,  0,  0,   9,  0,   174, 105,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.height = 69.49608854815264;
  test_msg.lat = 37.42905447764173;
  test_msg.lon = -122.17342007549469;
  test_msg.n_sats = 9;
  test_msg.tow = 2567800;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 69.4960885482 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 69.4960885482, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.4290544776 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.4290544776, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.173420075 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.173420075, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567800)
      << "incorrect value for last_msg_.tow, expected 2567800, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLHDepA3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA3, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,  246, 215, 34,  120, 46, 39, 0,   251, 117, 115, 140,
      235, 182, 66, 64,  152, 134, 167, 12, 25, 139, 94,  192, 160, 22,
      137, 253, 4,  108, 81,  64,  0,   0,  0,  0,   9,   1,   122, 127,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 1;
  test_msg.h_accuracy = 0;
  test_msg.height = 69.68780458819901;
  test_msg.lat = 37.429063373925565;
  test_msg.lon = -122.17340389594972;
  test_msg.n_sats = 9;
  test_msg.tow = 2567800;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 1)
      << "incorrect value for last_msg_.flags, expected 1, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 69.6878045882 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 69.6878045882, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.4290633739 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.4290633739, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.173403896 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.173403896, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567800)
      << "incorrect value for last_msg_.tow, expected 2567800, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLHDepA4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA4, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,   246, 215, 34, 220, 46, 39, 0,   51, 124, 88,  251,
      235, 182, 66,  64,  153, 5,  250, 16, 25, 139, 94, 192, 146, 60,
      187, 219, 152, 161, 81,  64, 0,   0,  0,  0,   9,  0,   194, 158,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.height = 70.5249547317965;
  test_msg.lat = 37.42907659359516;
  test_msg.lon = -122.17340492645452;
  test_msg.n_sats = 9;
  test_msg.tow = 2567900;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 70.5249547318 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 70.5249547318, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.4290765936 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.4290765936, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.173404926 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.173404926, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 9)
      << "incorrect value for last_msg_.n_sats, expected 9, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 2567900)
      << "incorrect value for last_msg_.tow, expected 2567900, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLHDepA5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA5, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,   195, 4,   34,  212, 157, 67,  24,  8,  23,  228, 8,
      151, 225, 66,  64,  156, 174, 42,  194, 230, 152, 94, 192, 153, 23,
      72,  47,  196, 40,  16,  64,  0,   0,   0,   0,   8,  0,   237, 169,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.height = 4.039810885214956;
  test_msg.lat = 37.76242171418386;
  test_msg.lon = -122.38908437889262;
  test_msg.n_sats = 8;
  test_msg.tow = 407084500;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 4.03981088521 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 4.03981088521, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.7624217142 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.7624217142, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.389084379 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.389084379, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 8)
      << "incorrect value for last_msg_.n_sats, expected 8, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407084500)
      << "incorrect value for last_msg_.tow, expected 407084500, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLHDepA6
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA6()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA6, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,   195, 4,   34,  56,  158, 67,  24,  220, 109, 212, 24,
      151, 225, 66,  64,  159, 231, 254, 219, 230, 152, 94,  192, 128, 151,
      67,  19,  233, 105, 7,   64,  0,   0,   0,   0,   8,   0,   152, 11,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.height = 2.926714087009657;
  test_msg.lat = 37.76242361423985;
  test_msg.lon = -122.38909053700489;
  test_msg.n_sats = 8;
  test_msg.tow = 407084600;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 2.92671408701 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 2.92671408701, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.7624236142 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.7624236142, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.389090537 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.389090537, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 8)
      << "incorrect value for last_msg_.n_sats, expected 8, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407084600)
      << "incorrect value for last_msg_.tow, expected 407084600, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLHDepA7
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA7()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA7, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,  195, 4,   34,  156, 158, 67,  24,  13, 91,  237, 11,
      151, 225, 66, 64,  75,  113, 210, 220, 230, 152, 94, 192, 37,  6,
      145, 188, 89, 112, 238, 63,  0,   0,   0,   0,   8,  0,   221, 155,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.height = 0.9512146647395566;
  test_msg.lat = 37.762422076126406;
  test_msg.lon = -122.3890907340148;
  test_msg.n_sats = 8;
  test_msg.tow = 407084700;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 0.95121466474 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 0.95121466474, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.7624220761 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.7624220761, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.389090734 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.389090734, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 8)
      << "incorrect value for last_msg_.n_sats, expected 8, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407084700)
      << "incorrect value for last_msg_.tow, expected 407084700, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLHDepA8
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA8()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA8, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,  195, 4,  34,  0,   159, 67,  24,  51, 183, 5,   8,
      151, 225, 66, 64,  13, 226, 148, 253, 230, 152, 94, 192, 187, 27,
      11,  32,  69, 213, 2,  64,  0,   0,   0,   0,   8,  0,   82,  94,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.height = 2.354135752047538;
  test_msg.lat = 37.762421610632735;
  test_msg.lon = -122.38909854449612;
  test_msg.n_sats = 8;
  test_msg.tow = 407084800;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 2.35413575205 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 2.35413575205, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.7624216106 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.7624216106, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.389098544 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.389098544, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 8)
      << "incorrect value for last_msg_.n_sats, expected 8, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407084800)
      << "incorrect value for last_msg_.tow, expected 407084800, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLHDepA9
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA9()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA9, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,  195, 4,   34,  100, 159, 67,  24,  22, 77,  146, 22,
      151, 225, 66, 64,  64,  134, 105, 227, 230, 152, 94, 192, 37,  99,
      114, 72,  31, 103, 241, 63,  0,   0,   0,   0,   8,  0,   70,  60,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.height = 1.0876763181642641;
  test_msg.lat = 37.76242334502801;
  test_msg.lon = -122.38909230523223;
  test_msg.n_sats = 8;
  test_msg.tow = 407084900;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 1.08767631816 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 1.08767631816, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.762423345 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.762423345, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.389092305 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.389092305, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 8)
      << "incorrect value for last_msg_.n_sats, expected 8, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407084900)
      << "incorrect value for last_msg_.tow, expected 407084900, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLHDepA10
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLHDepA10()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_dep_a_t>(this),
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
                      const sbp_msg_pos_llh_dep_a_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLHDepA10, Test) {
  uint8_t encoded_frame[] = {
      85,  1,   2,   195, 4,   34,  46,  162, 68,  24,  124, 245, 46,  169,
      151, 225, 66,  64,  135, 149, 234, 187, 230, 152, 94,  192, 194, 201,
      115, 145, 166, 175, 20,  64,  0,   0,   0,   0,   5,   0,   212, 121,
  };

  sbp_msg_pos_llh_dep_a_t test_msg{};
  test_msg.flags = 0;
  test_msg.h_accuracy = 0;
  test_msg.height = 5.171533844654222;
  test_msg.lat = 37.76244082253376;
  test_msg.lon = -122.38908288868525;
  test_msg.n_sats = 5;
  test_msg.tow = 407151150;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(1219, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 0)
      << "incorrect value for last_msg_.flags, expected 0, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 5.17153384465 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 5.17153384465, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.7624408225 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.7624408225, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.389082889 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.389082889, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 5)
      << "incorrect value for last_msg_.n_sats, expected 5, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 407151150)
      << "incorrect value for last_msg_.tow, expected 407151150, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
