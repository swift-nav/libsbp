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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepB.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_observation_MsgObsDepB0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_obs_dep_b_t> {
 public:
  Test_auto_check_sbp_observation_MsgObsDepB0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_obs_dep_b_t>(this),
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
                      const sbp_msg_obs_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_observation_MsgObsDepB0, Test) {
  uint8_t encoded_frame[] = {
      85,  67,  0,   246, 215, 103, 120, 46, 39, 0,   251, 6, 32, 180, 175, 187,
      133, 223, 53,  7,   7,   27,  157, 0,  0,  202, 0,   0, 0,  58,  140, 85,
      147, 88,  28,  190, 7,   175, 144, 0,  0,  203, 0,   0, 0,  220, 140, 248,
      138, 208, 172, 77,  7,   135, 151, 0,  0,  208, 0,   0, 0,  173, 194, 72,
      135, 115, 18,  28,  7,   242, 156, 0,  0,  212, 0,   0, 0,  164, 144, 105,
      124, 18,  196, 137, 6,   120, 168, 0,  0,  217, 0,   0, 0,  30,  232, 228,
      139, 210, 7,   90,  7,   87,  150, 0,  0,  218, 0,   0, 0,  169, 85,
  };

  sbp_msg_obs_dep_b_t test_msg{};
  test_msg.header.n_obs = 32;
  test_msg.header.t.tow = 2567800;
  test_msg.header.t.wn = 1787;
  test_msg.n_obs = 6;

  test_msg.obs[0].L.f = 27;
  test_msg.obs[0].L.i = 117913055;
  test_msg.obs[0].P = 2243669940;
  test_msg.obs[0].cn0 = 157;
  test_msg.obs[0].lock = 0;
  test_msg.obs[0].sid.code = 0;
  test_msg.obs[0].sid.reserved = 0;
  test_msg.obs[0].sid.sat = 202;

  test_msg.obs[1].L.f = 175;
  test_msg.obs[1].L.i = 129899608;
  test_msg.obs[1].P = 2471857210;
  test_msg.obs[1].cn0 = 144;
  test_msg.obs[1].lock = 0;
  test_msg.obs[1].sid.code = 0;
  test_msg.obs[1].sid.reserved = 0;
  test_msg.obs[1].sid.sat = 203;

  test_msg.obs[2].L.f = 135;
  test_msg.obs[2].L.i = 122531024;
  test_msg.obs[2].P = 2331544796;
  test_msg.obs[2].cn0 = 151;
  test_msg.obs[2].lock = 0;
  test_msg.obs[2].sid.code = 0;
  test_msg.obs[2].sid.reserved = 0;
  test_msg.obs[2].sid.sat = 208;

  test_msg.obs[3].L.f = 242;
  test_msg.obs[3].L.i = 119280243;
  test_msg.obs[3].P = 2269692589;
  test_msg.obs[3].cn0 = 156;
  test_msg.obs[3].lock = 0;
  test_msg.obs[3].sid.code = 0;
  test_msg.obs[3].sid.reserved = 0;
  test_msg.obs[3].sid.sat = 212;

  test_msg.obs[4].L.f = 120;
  test_msg.obs[4].L.i = 109691922;
  test_msg.obs[4].P = 2087293092;
  test_msg.obs[4].cn0 = 168;
  test_msg.obs[4].lock = 0;
  test_msg.obs[4].sid.code = 0;
  test_msg.obs[4].sid.reserved = 0;
  test_msg.obs[4].sid.sat = 217;

  test_msg.obs[5].L.f = 87;
  test_msg.obs[5].L.i = 123340754;
  test_msg.obs[5].P = 2347034654;
  test_msg.obs[5].cn0 = 150;
  test_msg.obs[5].lock = 0;
  test_msg.obs[5].sid.code = 0;
  test_msg.obs[5].sid.reserved = 0;
  test_msg.obs[5].sid.sat = 218;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.header.n_obs, 32)
      << "incorrect value for last_msg_.header.n_obs, expected 32, is "
      << last_msg_.header.n_obs;
  EXPECT_EQ(last_msg_.header.t.tow, 2567800)
      << "incorrect value for last_msg_.header.t.tow, expected 2567800, is "
      << last_msg_.header.t.tow;
  EXPECT_EQ(last_msg_.header.t.wn, 1787)
      << "incorrect value for last_msg_.header.t.wn, expected 1787, is "
      << last_msg_.header.t.wn;
  EXPECT_EQ(last_msg_.n_obs, 6)
      << "incorrect value for last_msg_.n_obs, expected 6, is "
      << last_msg_.n_obs;
  EXPECT_EQ(last_msg_.obs[0].L.f, 27)
      << "incorrect value for last_msg_.obs[0].L.f, expected 27, is "
      << last_msg_.obs[0].L.f;
  EXPECT_EQ(last_msg_.obs[0].L.i, 117913055)
      << "incorrect value for last_msg_.obs[0].L.i, expected 117913055, is "
      << last_msg_.obs[0].L.i;
  EXPECT_EQ(last_msg_.obs[0].P, 2243669940)
      << "incorrect value for last_msg_.obs[0].P, expected 2243669940, is "
      << last_msg_.obs[0].P;
  EXPECT_EQ(last_msg_.obs[0].cn0, 157)
      << "incorrect value for last_msg_.obs[0].cn0, expected 157, is "
      << last_msg_.obs[0].cn0;
  EXPECT_EQ(last_msg_.obs[0].lock, 0)
      << "incorrect value for last_msg_.obs[0].lock, expected 0, is "
      << last_msg_.obs[0].lock;
  EXPECT_EQ(last_msg_.obs[0].sid.code, 0)
      << "incorrect value for last_msg_.obs[0].sid.code, expected 0, is "
      << last_msg_.obs[0].sid.code;
  EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[0].sid.reserved, expected 0, is "
      << last_msg_.obs[0].sid.reserved;
  EXPECT_EQ(last_msg_.obs[0].sid.sat, 202)
      << "incorrect value for last_msg_.obs[0].sid.sat, expected 202, is "
      << last_msg_.obs[0].sid.sat;
  EXPECT_EQ(last_msg_.obs[1].L.f, 175)
      << "incorrect value for last_msg_.obs[1].L.f, expected 175, is "
      << last_msg_.obs[1].L.f;
  EXPECT_EQ(last_msg_.obs[1].L.i, 129899608)
      << "incorrect value for last_msg_.obs[1].L.i, expected 129899608, is "
      << last_msg_.obs[1].L.i;
  EXPECT_EQ(last_msg_.obs[1].P, 2471857210)
      << "incorrect value for last_msg_.obs[1].P, expected 2471857210, is "
      << last_msg_.obs[1].P;
  EXPECT_EQ(last_msg_.obs[1].cn0, 144)
      << "incorrect value for last_msg_.obs[1].cn0, expected 144, is "
      << last_msg_.obs[1].cn0;
  EXPECT_EQ(last_msg_.obs[1].lock, 0)
      << "incorrect value for last_msg_.obs[1].lock, expected 0, is "
      << last_msg_.obs[1].lock;
  EXPECT_EQ(last_msg_.obs[1].sid.code, 0)
      << "incorrect value for last_msg_.obs[1].sid.code, expected 0, is "
      << last_msg_.obs[1].sid.code;
  EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[1].sid.reserved, expected 0, is "
      << last_msg_.obs[1].sid.reserved;
  EXPECT_EQ(last_msg_.obs[1].sid.sat, 203)
      << "incorrect value for last_msg_.obs[1].sid.sat, expected 203, is "
      << last_msg_.obs[1].sid.sat;
  EXPECT_EQ(last_msg_.obs[2].L.f, 135)
      << "incorrect value for last_msg_.obs[2].L.f, expected 135, is "
      << last_msg_.obs[2].L.f;
  EXPECT_EQ(last_msg_.obs[2].L.i, 122531024)
      << "incorrect value for last_msg_.obs[2].L.i, expected 122531024, is "
      << last_msg_.obs[2].L.i;
  EXPECT_EQ(last_msg_.obs[2].P, 2331544796)
      << "incorrect value for last_msg_.obs[2].P, expected 2331544796, is "
      << last_msg_.obs[2].P;
  EXPECT_EQ(last_msg_.obs[2].cn0, 151)
      << "incorrect value for last_msg_.obs[2].cn0, expected 151, is "
      << last_msg_.obs[2].cn0;
  EXPECT_EQ(last_msg_.obs[2].lock, 0)
      << "incorrect value for last_msg_.obs[2].lock, expected 0, is "
      << last_msg_.obs[2].lock;
  EXPECT_EQ(last_msg_.obs[2].sid.code, 0)
      << "incorrect value for last_msg_.obs[2].sid.code, expected 0, is "
      << last_msg_.obs[2].sid.code;
  EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[2].sid.reserved, expected 0, is "
      << last_msg_.obs[2].sid.reserved;
  EXPECT_EQ(last_msg_.obs[2].sid.sat, 208)
      << "incorrect value for last_msg_.obs[2].sid.sat, expected 208, is "
      << last_msg_.obs[2].sid.sat;
  EXPECT_EQ(last_msg_.obs[3].L.f, 242)
      << "incorrect value for last_msg_.obs[3].L.f, expected 242, is "
      << last_msg_.obs[3].L.f;
  EXPECT_EQ(last_msg_.obs[3].L.i, 119280243)
      << "incorrect value for last_msg_.obs[3].L.i, expected 119280243, is "
      << last_msg_.obs[3].L.i;
  EXPECT_EQ(last_msg_.obs[3].P, 2269692589)
      << "incorrect value for last_msg_.obs[3].P, expected 2269692589, is "
      << last_msg_.obs[3].P;
  EXPECT_EQ(last_msg_.obs[3].cn0, 156)
      << "incorrect value for last_msg_.obs[3].cn0, expected 156, is "
      << last_msg_.obs[3].cn0;
  EXPECT_EQ(last_msg_.obs[3].lock, 0)
      << "incorrect value for last_msg_.obs[3].lock, expected 0, is "
      << last_msg_.obs[3].lock;
  EXPECT_EQ(last_msg_.obs[3].sid.code, 0)
      << "incorrect value for last_msg_.obs[3].sid.code, expected 0, is "
      << last_msg_.obs[3].sid.code;
  EXPECT_EQ(last_msg_.obs[3].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[3].sid.reserved, expected 0, is "
      << last_msg_.obs[3].sid.reserved;
  EXPECT_EQ(last_msg_.obs[3].sid.sat, 212)
      << "incorrect value for last_msg_.obs[3].sid.sat, expected 212, is "
      << last_msg_.obs[3].sid.sat;
  EXPECT_EQ(last_msg_.obs[4].L.f, 120)
      << "incorrect value for last_msg_.obs[4].L.f, expected 120, is "
      << last_msg_.obs[4].L.f;
  EXPECT_EQ(last_msg_.obs[4].L.i, 109691922)
      << "incorrect value for last_msg_.obs[4].L.i, expected 109691922, is "
      << last_msg_.obs[4].L.i;
  EXPECT_EQ(last_msg_.obs[4].P, 2087293092)
      << "incorrect value for last_msg_.obs[4].P, expected 2087293092, is "
      << last_msg_.obs[4].P;
  EXPECT_EQ(last_msg_.obs[4].cn0, 168)
      << "incorrect value for last_msg_.obs[4].cn0, expected 168, is "
      << last_msg_.obs[4].cn0;
  EXPECT_EQ(last_msg_.obs[4].lock, 0)
      << "incorrect value for last_msg_.obs[4].lock, expected 0, is "
      << last_msg_.obs[4].lock;
  EXPECT_EQ(last_msg_.obs[4].sid.code, 0)
      << "incorrect value for last_msg_.obs[4].sid.code, expected 0, is "
      << last_msg_.obs[4].sid.code;
  EXPECT_EQ(last_msg_.obs[4].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[4].sid.reserved, expected 0, is "
      << last_msg_.obs[4].sid.reserved;
  EXPECT_EQ(last_msg_.obs[4].sid.sat, 217)
      << "incorrect value for last_msg_.obs[4].sid.sat, expected 217, is "
      << last_msg_.obs[4].sid.sat;
  EXPECT_EQ(last_msg_.obs[5].L.f, 87)
      << "incorrect value for last_msg_.obs[5].L.f, expected 87, is "
      << last_msg_.obs[5].L.f;
  EXPECT_EQ(last_msg_.obs[5].L.i, 123340754)
      << "incorrect value for last_msg_.obs[5].L.i, expected 123340754, is "
      << last_msg_.obs[5].L.i;
  EXPECT_EQ(last_msg_.obs[5].P, 2347034654)
      << "incorrect value for last_msg_.obs[5].P, expected 2347034654, is "
      << last_msg_.obs[5].P;
  EXPECT_EQ(last_msg_.obs[5].cn0, 150)
      << "incorrect value for last_msg_.obs[5].cn0, expected 150, is "
      << last_msg_.obs[5].cn0;
  EXPECT_EQ(last_msg_.obs[5].lock, 0)
      << "incorrect value for last_msg_.obs[5].lock, expected 0, is "
      << last_msg_.obs[5].lock;
  EXPECT_EQ(last_msg_.obs[5].sid.code, 0)
      << "incorrect value for last_msg_.obs[5].sid.code, expected 0, is "
      << last_msg_.obs[5].sid.code;
  EXPECT_EQ(last_msg_.obs[5].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[5].sid.reserved, expected 0, is "
      << last_msg_.obs[5].sid.reserved;
  EXPECT_EQ(last_msg_.obs[5].sid.sat, 218)
      << "incorrect value for last_msg_.obs[5].sid.sat, expected 218, is "
      << last_msg_.obs[5].sid.sat;
}
class Test_auto_check_sbp_observation_MsgObsDepB1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_obs_dep_b_t> {
 public:
  Test_auto_check_sbp_observation_MsgObsDepB1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_obs_dep_b_t>(this),
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
                      const sbp_msg_obs_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_observation_MsgObsDepB1, Test) {
  uint8_t encoded_frame[] = {
      85,  67,  0,   246, 215, 55,  120, 46, 39, 0,   251, 6, 33, 68,  199, 101,
      136, 133, 247, 42,  7,   219, 154, 0,  0,  220, 0,   0, 0,  219, 14,  123,
      133, 96,  215, 3,   7,   235, 156, 0,  0,  222, 0,   0, 0,  87,  166, 81,
      122, 5,   173, 109, 6,   174, 170, 0,  0,  225, 0,   0, 0,  11,  233,
  };

  sbp_msg_obs_dep_b_t test_msg{};
  test_msg.header.n_obs = 33;
  test_msg.header.t.tow = 2567800;
  test_msg.header.t.wn = 1787;
  test_msg.n_obs = 3;

  test_msg.obs[0].L.f = 219;
  test_msg.obs[0].L.i = 120256389;
  test_msg.obs[0].P = 2288371524;
  test_msg.obs[0].cn0 = 154;
  test_msg.obs[0].lock = 0;
  test_msg.obs[0].sid.code = 0;
  test_msg.obs[0].sid.reserved = 0;
  test_msg.obs[0].sid.sat = 220;

  test_msg.obs[1].L.f = 235;
  test_msg.obs[1].L.i = 117692256;
  test_msg.obs[1].P = 2239434459;
  test_msg.obs[1].cn0 = 156;
  test_msg.obs[1].lock = 0;
  test_msg.obs[1].sid.code = 0;
  test_msg.obs[1].sid.reserved = 0;
  test_msg.obs[1].sid.sat = 222;

  test_msg.obs[2].L.f = 174;
  test_msg.obs[2].L.i = 107851013;
  test_msg.obs[2].P = 2052171351;
  test_msg.obs[2].cn0 = 170;
  test_msg.obs[2].lock = 0;
  test_msg.obs[2].sid.code = 0;
  test_msg.obs[2].sid.reserved = 0;
  test_msg.obs[2].sid.sat = 225;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.header.n_obs, 33)
      << "incorrect value for last_msg_.header.n_obs, expected 33, is "
      << last_msg_.header.n_obs;
  EXPECT_EQ(last_msg_.header.t.tow, 2567800)
      << "incorrect value for last_msg_.header.t.tow, expected 2567800, is "
      << last_msg_.header.t.tow;
  EXPECT_EQ(last_msg_.header.t.wn, 1787)
      << "incorrect value for last_msg_.header.t.wn, expected 1787, is "
      << last_msg_.header.t.wn;
  EXPECT_EQ(last_msg_.n_obs, 3)
      << "incorrect value for last_msg_.n_obs, expected 3, is "
      << last_msg_.n_obs;
  EXPECT_EQ(last_msg_.obs[0].L.f, 219)
      << "incorrect value for last_msg_.obs[0].L.f, expected 219, is "
      << last_msg_.obs[0].L.f;
  EXPECT_EQ(last_msg_.obs[0].L.i, 120256389)
      << "incorrect value for last_msg_.obs[0].L.i, expected 120256389, is "
      << last_msg_.obs[0].L.i;
  EXPECT_EQ(last_msg_.obs[0].P, 2288371524)
      << "incorrect value for last_msg_.obs[0].P, expected 2288371524, is "
      << last_msg_.obs[0].P;
  EXPECT_EQ(last_msg_.obs[0].cn0, 154)
      << "incorrect value for last_msg_.obs[0].cn0, expected 154, is "
      << last_msg_.obs[0].cn0;
  EXPECT_EQ(last_msg_.obs[0].lock, 0)
      << "incorrect value for last_msg_.obs[0].lock, expected 0, is "
      << last_msg_.obs[0].lock;
  EXPECT_EQ(last_msg_.obs[0].sid.code, 0)
      << "incorrect value for last_msg_.obs[0].sid.code, expected 0, is "
      << last_msg_.obs[0].sid.code;
  EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[0].sid.reserved, expected 0, is "
      << last_msg_.obs[0].sid.reserved;
  EXPECT_EQ(last_msg_.obs[0].sid.sat, 220)
      << "incorrect value for last_msg_.obs[0].sid.sat, expected 220, is "
      << last_msg_.obs[0].sid.sat;
  EXPECT_EQ(last_msg_.obs[1].L.f, 235)
      << "incorrect value for last_msg_.obs[1].L.f, expected 235, is "
      << last_msg_.obs[1].L.f;
  EXPECT_EQ(last_msg_.obs[1].L.i, 117692256)
      << "incorrect value for last_msg_.obs[1].L.i, expected 117692256, is "
      << last_msg_.obs[1].L.i;
  EXPECT_EQ(last_msg_.obs[1].P, 2239434459)
      << "incorrect value for last_msg_.obs[1].P, expected 2239434459, is "
      << last_msg_.obs[1].P;
  EXPECT_EQ(last_msg_.obs[1].cn0, 156)
      << "incorrect value for last_msg_.obs[1].cn0, expected 156, is "
      << last_msg_.obs[1].cn0;
  EXPECT_EQ(last_msg_.obs[1].lock, 0)
      << "incorrect value for last_msg_.obs[1].lock, expected 0, is "
      << last_msg_.obs[1].lock;
  EXPECT_EQ(last_msg_.obs[1].sid.code, 0)
      << "incorrect value for last_msg_.obs[1].sid.code, expected 0, is "
      << last_msg_.obs[1].sid.code;
  EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[1].sid.reserved, expected 0, is "
      << last_msg_.obs[1].sid.reserved;
  EXPECT_EQ(last_msg_.obs[1].sid.sat, 222)
      << "incorrect value for last_msg_.obs[1].sid.sat, expected 222, is "
      << last_msg_.obs[1].sid.sat;
  EXPECT_EQ(last_msg_.obs[2].L.f, 174)
      << "incorrect value for last_msg_.obs[2].L.f, expected 174, is "
      << last_msg_.obs[2].L.f;
  EXPECT_EQ(last_msg_.obs[2].L.i, 107851013)
      << "incorrect value for last_msg_.obs[2].L.i, expected 107851013, is "
      << last_msg_.obs[2].L.i;
  EXPECT_EQ(last_msg_.obs[2].P, 2052171351)
      << "incorrect value for last_msg_.obs[2].P, expected 2052171351, is "
      << last_msg_.obs[2].P;
  EXPECT_EQ(last_msg_.obs[2].cn0, 170)
      << "incorrect value for last_msg_.obs[2].cn0, expected 170, is "
      << last_msg_.obs[2].cn0;
  EXPECT_EQ(last_msg_.obs[2].lock, 0)
      << "incorrect value for last_msg_.obs[2].lock, expected 0, is "
      << last_msg_.obs[2].lock;
  EXPECT_EQ(last_msg_.obs[2].sid.code, 0)
      << "incorrect value for last_msg_.obs[2].sid.code, expected 0, is "
      << last_msg_.obs[2].sid.code;
  EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[2].sid.reserved, expected 0, is "
      << last_msg_.obs[2].sid.reserved;
  EXPECT_EQ(last_msg_.obs[2].sid.sat, 225)
      << "incorrect value for last_msg_.obs[2].sid.sat, expected 225, is "
      << last_msg_.obs[2].sid.sat;
}
class Test_auto_check_sbp_observation_MsgObsDepB2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_obs_dep_b_t> {
 public:
  Test_auto_check_sbp_observation_MsgObsDepB2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_obs_dep_b_t>(this),
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
                      const sbp_msg_obs_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_observation_MsgObsDepB2, Test) {
  uint8_t encoded_frame[] = {
      85,  67,  0,   246, 215, 103, 64,  47, 39, 0,   251, 6, 32, 100, 132, 187,
      133, 236, 51,  7,   7,   94,  156, 0,  0,  202, 0,   0, 0,  97,  184, 85,
      147, 178, 30,  190, 7,   40,  140, 0,  0,  203, 0,   0, 0,  135, 111, 248,
      138, 90,  171, 77,  7,   2,   150, 0,  0,  208, 0,   0, 0,  180, 238, 72,
      135, 190, 20,  28,  7,   241, 155, 0,  0,  212, 0,   0, 0,  15,  153, 105,
      124, 92,  196, 137, 6,   153, 168, 0,  0,  217, 0,   0, 0,  49,  185, 228,
      139, 144, 5,   90,  7,   41,  150, 0,  0,  218, 0,   0, 0,  241, 98,
  };

  sbp_msg_obs_dep_b_t test_msg{};
  test_msg.header.n_obs = 32;
  test_msg.header.t.tow = 2568000;
  test_msg.header.t.wn = 1787;
  test_msg.n_obs = 6;

  test_msg.obs[0].L.f = 94;
  test_msg.obs[0].L.i = 117912556;
  test_msg.obs[0].P = 2243658852;
  test_msg.obs[0].cn0 = 156;
  test_msg.obs[0].lock = 0;
  test_msg.obs[0].sid.code = 0;
  test_msg.obs[0].sid.reserved = 0;
  test_msg.obs[0].sid.sat = 202;

  test_msg.obs[1].L.f = 40;
  test_msg.obs[1].L.i = 129900210;
  test_msg.obs[1].P = 2471868513;
  test_msg.obs[1].cn0 = 140;
  test_msg.obs[1].lock = 0;
  test_msg.obs[1].sid.code = 0;
  test_msg.obs[1].sid.reserved = 0;
  test_msg.obs[1].sid.sat = 203;

  test_msg.obs[2].L.f = 2;
  test_msg.obs[2].L.i = 122530650;
  test_msg.obs[2].P = 2331537287;
  test_msg.obs[2].cn0 = 150;
  test_msg.obs[2].lock = 0;
  test_msg.obs[2].sid.code = 0;
  test_msg.obs[2].sid.reserved = 0;
  test_msg.obs[2].sid.sat = 208;

  test_msg.obs[3].L.f = 241;
  test_msg.obs[3].L.i = 119280830;
  test_msg.obs[3].P = 2269703860;
  test_msg.obs[3].cn0 = 155;
  test_msg.obs[3].lock = 0;
  test_msg.obs[3].sid.code = 0;
  test_msg.obs[3].sid.reserved = 0;
  test_msg.obs[3].sid.sat = 212;

  test_msg.obs[4].L.f = 153;
  test_msg.obs[4].L.i = 109691996;
  test_msg.obs[4].P = 2087295247;
  test_msg.obs[4].cn0 = 168;
  test_msg.obs[4].lock = 0;
  test_msg.obs[4].sid.code = 0;
  test_msg.obs[4].sid.reserved = 0;
  test_msg.obs[4].sid.sat = 217;

  test_msg.obs[5].L.f = 41;
  test_msg.obs[5].L.i = 123340176;
  test_msg.obs[5].P = 2347022641;
  test_msg.obs[5].cn0 = 150;
  test_msg.obs[5].lock = 0;
  test_msg.obs[5].sid.code = 0;
  test_msg.obs[5].sid.reserved = 0;
  test_msg.obs[5].sid.sat = 218;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.header.n_obs, 32)
      << "incorrect value for last_msg_.header.n_obs, expected 32, is "
      << last_msg_.header.n_obs;
  EXPECT_EQ(last_msg_.header.t.tow, 2568000)
      << "incorrect value for last_msg_.header.t.tow, expected 2568000, is "
      << last_msg_.header.t.tow;
  EXPECT_EQ(last_msg_.header.t.wn, 1787)
      << "incorrect value for last_msg_.header.t.wn, expected 1787, is "
      << last_msg_.header.t.wn;
  EXPECT_EQ(last_msg_.n_obs, 6)
      << "incorrect value for last_msg_.n_obs, expected 6, is "
      << last_msg_.n_obs;
  EXPECT_EQ(last_msg_.obs[0].L.f, 94)
      << "incorrect value for last_msg_.obs[0].L.f, expected 94, is "
      << last_msg_.obs[0].L.f;
  EXPECT_EQ(last_msg_.obs[0].L.i, 117912556)
      << "incorrect value for last_msg_.obs[0].L.i, expected 117912556, is "
      << last_msg_.obs[0].L.i;
  EXPECT_EQ(last_msg_.obs[0].P, 2243658852)
      << "incorrect value for last_msg_.obs[0].P, expected 2243658852, is "
      << last_msg_.obs[0].P;
  EXPECT_EQ(last_msg_.obs[0].cn0, 156)
      << "incorrect value for last_msg_.obs[0].cn0, expected 156, is "
      << last_msg_.obs[0].cn0;
  EXPECT_EQ(last_msg_.obs[0].lock, 0)
      << "incorrect value for last_msg_.obs[0].lock, expected 0, is "
      << last_msg_.obs[0].lock;
  EXPECT_EQ(last_msg_.obs[0].sid.code, 0)
      << "incorrect value for last_msg_.obs[0].sid.code, expected 0, is "
      << last_msg_.obs[0].sid.code;
  EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[0].sid.reserved, expected 0, is "
      << last_msg_.obs[0].sid.reserved;
  EXPECT_EQ(last_msg_.obs[0].sid.sat, 202)
      << "incorrect value for last_msg_.obs[0].sid.sat, expected 202, is "
      << last_msg_.obs[0].sid.sat;
  EXPECT_EQ(last_msg_.obs[1].L.f, 40)
      << "incorrect value for last_msg_.obs[1].L.f, expected 40, is "
      << last_msg_.obs[1].L.f;
  EXPECT_EQ(last_msg_.obs[1].L.i, 129900210)
      << "incorrect value for last_msg_.obs[1].L.i, expected 129900210, is "
      << last_msg_.obs[1].L.i;
  EXPECT_EQ(last_msg_.obs[1].P, 2471868513)
      << "incorrect value for last_msg_.obs[1].P, expected 2471868513, is "
      << last_msg_.obs[1].P;
  EXPECT_EQ(last_msg_.obs[1].cn0, 140)
      << "incorrect value for last_msg_.obs[1].cn0, expected 140, is "
      << last_msg_.obs[1].cn0;
  EXPECT_EQ(last_msg_.obs[1].lock, 0)
      << "incorrect value for last_msg_.obs[1].lock, expected 0, is "
      << last_msg_.obs[1].lock;
  EXPECT_EQ(last_msg_.obs[1].sid.code, 0)
      << "incorrect value for last_msg_.obs[1].sid.code, expected 0, is "
      << last_msg_.obs[1].sid.code;
  EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[1].sid.reserved, expected 0, is "
      << last_msg_.obs[1].sid.reserved;
  EXPECT_EQ(last_msg_.obs[1].sid.sat, 203)
      << "incorrect value for last_msg_.obs[1].sid.sat, expected 203, is "
      << last_msg_.obs[1].sid.sat;
  EXPECT_EQ(last_msg_.obs[2].L.f, 2)
      << "incorrect value for last_msg_.obs[2].L.f, expected 2, is "
      << last_msg_.obs[2].L.f;
  EXPECT_EQ(last_msg_.obs[2].L.i, 122530650)
      << "incorrect value for last_msg_.obs[2].L.i, expected 122530650, is "
      << last_msg_.obs[2].L.i;
  EXPECT_EQ(last_msg_.obs[2].P, 2331537287)
      << "incorrect value for last_msg_.obs[2].P, expected 2331537287, is "
      << last_msg_.obs[2].P;
  EXPECT_EQ(last_msg_.obs[2].cn0, 150)
      << "incorrect value for last_msg_.obs[2].cn0, expected 150, is "
      << last_msg_.obs[2].cn0;
  EXPECT_EQ(last_msg_.obs[2].lock, 0)
      << "incorrect value for last_msg_.obs[2].lock, expected 0, is "
      << last_msg_.obs[2].lock;
  EXPECT_EQ(last_msg_.obs[2].sid.code, 0)
      << "incorrect value for last_msg_.obs[2].sid.code, expected 0, is "
      << last_msg_.obs[2].sid.code;
  EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[2].sid.reserved, expected 0, is "
      << last_msg_.obs[2].sid.reserved;
  EXPECT_EQ(last_msg_.obs[2].sid.sat, 208)
      << "incorrect value for last_msg_.obs[2].sid.sat, expected 208, is "
      << last_msg_.obs[2].sid.sat;
  EXPECT_EQ(last_msg_.obs[3].L.f, 241)
      << "incorrect value for last_msg_.obs[3].L.f, expected 241, is "
      << last_msg_.obs[3].L.f;
  EXPECT_EQ(last_msg_.obs[3].L.i, 119280830)
      << "incorrect value for last_msg_.obs[3].L.i, expected 119280830, is "
      << last_msg_.obs[3].L.i;
  EXPECT_EQ(last_msg_.obs[3].P, 2269703860)
      << "incorrect value for last_msg_.obs[3].P, expected 2269703860, is "
      << last_msg_.obs[3].P;
  EXPECT_EQ(last_msg_.obs[3].cn0, 155)
      << "incorrect value for last_msg_.obs[3].cn0, expected 155, is "
      << last_msg_.obs[3].cn0;
  EXPECT_EQ(last_msg_.obs[3].lock, 0)
      << "incorrect value for last_msg_.obs[3].lock, expected 0, is "
      << last_msg_.obs[3].lock;
  EXPECT_EQ(last_msg_.obs[3].sid.code, 0)
      << "incorrect value for last_msg_.obs[3].sid.code, expected 0, is "
      << last_msg_.obs[3].sid.code;
  EXPECT_EQ(last_msg_.obs[3].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[3].sid.reserved, expected 0, is "
      << last_msg_.obs[3].sid.reserved;
  EXPECT_EQ(last_msg_.obs[3].sid.sat, 212)
      << "incorrect value for last_msg_.obs[3].sid.sat, expected 212, is "
      << last_msg_.obs[3].sid.sat;
  EXPECT_EQ(last_msg_.obs[4].L.f, 153)
      << "incorrect value for last_msg_.obs[4].L.f, expected 153, is "
      << last_msg_.obs[4].L.f;
  EXPECT_EQ(last_msg_.obs[4].L.i, 109691996)
      << "incorrect value for last_msg_.obs[4].L.i, expected 109691996, is "
      << last_msg_.obs[4].L.i;
  EXPECT_EQ(last_msg_.obs[4].P, 2087295247)
      << "incorrect value for last_msg_.obs[4].P, expected 2087295247, is "
      << last_msg_.obs[4].P;
  EXPECT_EQ(last_msg_.obs[4].cn0, 168)
      << "incorrect value for last_msg_.obs[4].cn0, expected 168, is "
      << last_msg_.obs[4].cn0;
  EXPECT_EQ(last_msg_.obs[4].lock, 0)
      << "incorrect value for last_msg_.obs[4].lock, expected 0, is "
      << last_msg_.obs[4].lock;
  EXPECT_EQ(last_msg_.obs[4].sid.code, 0)
      << "incorrect value for last_msg_.obs[4].sid.code, expected 0, is "
      << last_msg_.obs[4].sid.code;
  EXPECT_EQ(last_msg_.obs[4].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[4].sid.reserved, expected 0, is "
      << last_msg_.obs[4].sid.reserved;
  EXPECT_EQ(last_msg_.obs[4].sid.sat, 217)
      << "incorrect value for last_msg_.obs[4].sid.sat, expected 217, is "
      << last_msg_.obs[4].sid.sat;
  EXPECT_EQ(last_msg_.obs[5].L.f, 41)
      << "incorrect value for last_msg_.obs[5].L.f, expected 41, is "
      << last_msg_.obs[5].L.f;
  EXPECT_EQ(last_msg_.obs[5].L.i, 123340176)
      << "incorrect value for last_msg_.obs[5].L.i, expected 123340176, is "
      << last_msg_.obs[5].L.i;
  EXPECT_EQ(last_msg_.obs[5].P, 2347022641)
      << "incorrect value for last_msg_.obs[5].P, expected 2347022641, is "
      << last_msg_.obs[5].P;
  EXPECT_EQ(last_msg_.obs[5].cn0, 150)
      << "incorrect value for last_msg_.obs[5].cn0, expected 150, is "
      << last_msg_.obs[5].cn0;
  EXPECT_EQ(last_msg_.obs[5].lock, 0)
      << "incorrect value for last_msg_.obs[5].lock, expected 0, is "
      << last_msg_.obs[5].lock;
  EXPECT_EQ(last_msg_.obs[5].sid.code, 0)
      << "incorrect value for last_msg_.obs[5].sid.code, expected 0, is "
      << last_msg_.obs[5].sid.code;
  EXPECT_EQ(last_msg_.obs[5].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[5].sid.reserved, expected 0, is "
      << last_msg_.obs[5].sid.reserved;
  EXPECT_EQ(last_msg_.obs[5].sid.sat, 218)
      << "incorrect value for last_msg_.obs[5].sid.sat, expected 218, is "
      << last_msg_.obs[5].sid.sat;
}
class Test_auto_check_sbp_observation_MsgObsDepB3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_obs_dep_b_t> {
 public:
  Test_auto_check_sbp_observation_MsgObsDepB3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_obs_dep_b_t>(this),
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
                      const sbp_msg_obs_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_observation_MsgObsDepB3, Test) {
  uint8_t encoded_frame[] = {
      85,  67, 0,   246, 215, 55, 64,  47, 39, 0,   251, 6, 33, 234, 148, 101,
      136, 15, 245, 42,  7,   20, 154, 0,  0,  220, 0,   0, 0,  208, 247, 122,
      133, 16, 214, 3,   7,   38, 156, 0,  0,  222, 0,   0, 0,  15,  150, 81,
      122, 22, 172, 109, 6,   7,  172, 0,  0,  225, 0,   0, 0,  201, 13,
  };

  sbp_msg_obs_dep_b_t test_msg{};
  test_msg.header.n_obs = 33;
  test_msg.header.t.tow = 2568000;
  test_msg.header.t.wn = 1787;
  test_msg.n_obs = 3;

  test_msg.obs[0].L.f = 20;
  test_msg.obs[0].L.i = 120255759;
  test_msg.obs[0].P = 2288358634;
  test_msg.obs[0].cn0 = 154;
  test_msg.obs[0].lock = 0;
  test_msg.obs[0].sid.code = 0;
  test_msg.obs[0].sid.reserved = 0;
  test_msg.obs[0].sid.sat = 220;

  test_msg.obs[1].L.f = 38;
  test_msg.obs[1].L.i = 117691920;
  test_msg.obs[1].P = 2239428560;
  test_msg.obs[1].cn0 = 156;
  test_msg.obs[1].lock = 0;
  test_msg.obs[1].sid.code = 0;
  test_msg.obs[1].sid.reserved = 0;
  test_msg.obs[1].sid.sat = 222;

  test_msg.obs[2].L.f = 7;
  test_msg.obs[2].L.i = 107850774;
  test_msg.obs[2].P = 2052167183;
  test_msg.obs[2].cn0 = 172;
  test_msg.obs[2].lock = 0;
  test_msg.obs[2].sid.code = 0;
  test_msg.obs[2].sid.reserved = 0;
  test_msg.obs[2].sid.sat = 225;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.header.n_obs, 33)
      << "incorrect value for last_msg_.header.n_obs, expected 33, is "
      << last_msg_.header.n_obs;
  EXPECT_EQ(last_msg_.header.t.tow, 2568000)
      << "incorrect value for last_msg_.header.t.tow, expected 2568000, is "
      << last_msg_.header.t.tow;
  EXPECT_EQ(last_msg_.header.t.wn, 1787)
      << "incorrect value for last_msg_.header.t.wn, expected 1787, is "
      << last_msg_.header.t.wn;
  EXPECT_EQ(last_msg_.n_obs, 3)
      << "incorrect value for last_msg_.n_obs, expected 3, is "
      << last_msg_.n_obs;
  EXPECT_EQ(last_msg_.obs[0].L.f, 20)
      << "incorrect value for last_msg_.obs[0].L.f, expected 20, is "
      << last_msg_.obs[0].L.f;
  EXPECT_EQ(last_msg_.obs[0].L.i, 120255759)
      << "incorrect value for last_msg_.obs[0].L.i, expected 120255759, is "
      << last_msg_.obs[0].L.i;
  EXPECT_EQ(last_msg_.obs[0].P, 2288358634)
      << "incorrect value for last_msg_.obs[0].P, expected 2288358634, is "
      << last_msg_.obs[0].P;
  EXPECT_EQ(last_msg_.obs[0].cn0, 154)
      << "incorrect value for last_msg_.obs[0].cn0, expected 154, is "
      << last_msg_.obs[0].cn0;
  EXPECT_EQ(last_msg_.obs[0].lock, 0)
      << "incorrect value for last_msg_.obs[0].lock, expected 0, is "
      << last_msg_.obs[0].lock;
  EXPECT_EQ(last_msg_.obs[0].sid.code, 0)
      << "incorrect value for last_msg_.obs[0].sid.code, expected 0, is "
      << last_msg_.obs[0].sid.code;
  EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[0].sid.reserved, expected 0, is "
      << last_msg_.obs[0].sid.reserved;
  EXPECT_EQ(last_msg_.obs[0].sid.sat, 220)
      << "incorrect value for last_msg_.obs[0].sid.sat, expected 220, is "
      << last_msg_.obs[0].sid.sat;
  EXPECT_EQ(last_msg_.obs[1].L.f, 38)
      << "incorrect value for last_msg_.obs[1].L.f, expected 38, is "
      << last_msg_.obs[1].L.f;
  EXPECT_EQ(last_msg_.obs[1].L.i, 117691920)
      << "incorrect value for last_msg_.obs[1].L.i, expected 117691920, is "
      << last_msg_.obs[1].L.i;
  EXPECT_EQ(last_msg_.obs[1].P, 2239428560)
      << "incorrect value for last_msg_.obs[1].P, expected 2239428560, is "
      << last_msg_.obs[1].P;
  EXPECT_EQ(last_msg_.obs[1].cn0, 156)
      << "incorrect value for last_msg_.obs[1].cn0, expected 156, is "
      << last_msg_.obs[1].cn0;
  EXPECT_EQ(last_msg_.obs[1].lock, 0)
      << "incorrect value for last_msg_.obs[1].lock, expected 0, is "
      << last_msg_.obs[1].lock;
  EXPECT_EQ(last_msg_.obs[1].sid.code, 0)
      << "incorrect value for last_msg_.obs[1].sid.code, expected 0, is "
      << last_msg_.obs[1].sid.code;
  EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[1].sid.reserved, expected 0, is "
      << last_msg_.obs[1].sid.reserved;
  EXPECT_EQ(last_msg_.obs[1].sid.sat, 222)
      << "incorrect value for last_msg_.obs[1].sid.sat, expected 222, is "
      << last_msg_.obs[1].sid.sat;
  EXPECT_EQ(last_msg_.obs[2].L.f, 7)
      << "incorrect value for last_msg_.obs[2].L.f, expected 7, is "
      << last_msg_.obs[2].L.f;
  EXPECT_EQ(last_msg_.obs[2].L.i, 107850774)
      << "incorrect value for last_msg_.obs[2].L.i, expected 107850774, is "
      << last_msg_.obs[2].L.i;
  EXPECT_EQ(last_msg_.obs[2].P, 2052167183)
      << "incorrect value for last_msg_.obs[2].P, expected 2052167183, is "
      << last_msg_.obs[2].P;
  EXPECT_EQ(last_msg_.obs[2].cn0, 172)
      << "incorrect value for last_msg_.obs[2].cn0, expected 172, is "
      << last_msg_.obs[2].cn0;
  EXPECT_EQ(last_msg_.obs[2].lock, 0)
      << "incorrect value for last_msg_.obs[2].lock, expected 0, is "
      << last_msg_.obs[2].lock;
  EXPECT_EQ(last_msg_.obs[2].sid.code, 0)
      << "incorrect value for last_msg_.obs[2].sid.code, expected 0, is "
      << last_msg_.obs[2].sid.code;
  EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[2].sid.reserved, expected 0, is "
      << last_msg_.obs[2].sid.reserved;
  EXPECT_EQ(last_msg_.obs[2].sid.sat, 225)
      << "incorrect value for last_msg_.obs[2].sid.sat, expected 225, is "
      << last_msg_.obs[2].sid.sat;
}
class Test_auto_check_sbp_observation_MsgObsDepB4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_obs_dep_b_t> {
 public:
  Test_auto_check_sbp_observation_MsgObsDepB4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_obs_dep_b_t>(this),
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
                      const sbp_msg_obs_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_observation_MsgObsDepB4, Test) {
  uint8_t encoded_frame[] = {
      85,  67,  0,   246, 215, 103, 8,   48, 39, 0,   251, 6, 32, 254, 96,  187,
      133, 249, 49,  7,   7,   165, 156, 0,  0,  202, 0,   0, 0,  113, 229, 85,
      147, 11,  33,  190, 7,   106, 143, 0,  0,  203, 0,   0, 0,  182, 85,  248,
      138, 227, 169, 77,  7,   159, 150, 0,  0,  208, 0,   0, 0,  17,  24,  73,
      135, 10,  23,  28,  7,   7,   156, 0,  0,  212, 0,   0, 0,  108, 155, 105,
      124, 166, 196, 137, 6,   186, 170, 0,  0,  217, 0,   0, 0,  214, 142, 228,
      139, 77,  3,   90,  7,   236, 151, 0,  0,  218, 0,   0, 0,  59,  118,
  };

  sbp_msg_obs_dep_b_t test_msg{};
  test_msg.header.n_obs = 32;
  test_msg.header.t.tow = 2568200;
  test_msg.header.t.wn = 1787;
  test_msg.n_obs = 6;

  test_msg.obs[0].L.f = 165;
  test_msg.obs[0].L.i = 117912057;
  test_msg.obs[0].P = 2243649790;
  test_msg.obs[0].cn0 = 156;
  test_msg.obs[0].lock = 0;
  test_msg.obs[0].sid.code = 0;
  test_msg.obs[0].sid.reserved = 0;
  test_msg.obs[0].sid.sat = 202;

  test_msg.obs[1].L.f = 106;
  test_msg.obs[1].L.i = 129900811;
  test_msg.obs[1].P = 2471880049;
  test_msg.obs[1].cn0 = 143;
  test_msg.obs[1].lock = 0;
  test_msg.obs[1].sid.code = 0;
  test_msg.obs[1].sid.reserved = 0;
  test_msg.obs[1].sid.sat = 203;

  test_msg.obs[2].L.f = 159;
  test_msg.obs[2].L.i = 122530275;
  test_msg.obs[2].P = 2331530678;
  test_msg.obs[2].cn0 = 150;
  test_msg.obs[2].lock = 0;
  test_msg.obs[2].sid.code = 0;
  test_msg.obs[2].sid.reserved = 0;
  test_msg.obs[2].sid.sat = 208;

  test_msg.obs[3].L.f = 7;
  test_msg.obs[3].L.i = 119281418;
  test_msg.obs[3].P = 2269714449;
  test_msg.obs[3].cn0 = 156;
  test_msg.obs[3].lock = 0;
  test_msg.obs[3].sid.code = 0;
  test_msg.obs[3].sid.reserved = 0;
  test_msg.obs[3].sid.sat = 212;

  test_msg.obs[4].L.f = 186;
  test_msg.obs[4].L.i = 109692070;
  test_msg.obs[4].P = 2087295852;
  test_msg.obs[4].cn0 = 170;
  test_msg.obs[4].lock = 0;
  test_msg.obs[4].sid.code = 0;
  test_msg.obs[4].sid.reserved = 0;
  test_msg.obs[4].sid.sat = 217;

  test_msg.obs[5].L.f = 236;
  test_msg.obs[5].L.i = 123339597;
  test_msg.obs[5].P = 2347011798;
  test_msg.obs[5].cn0 = 151;
  test_msg.obs[5].lock = 0;
  test_msg.obs[5].sid.code = 0;
  test_msg.obs[5].sid.reserved = 0;
  test_msg.obs[5].sid.sat = 218;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.header.n_obs, 32)
      << "incorrect value for last_msg_.header.n_obs, expected 32, is "
      << last_msg_.header.n_obs;
  EXPECT_EQ(last_msg_.header.t.tow, 2568200)
      << "incorrect value for last_msg_.header.t.tow, expected 2568200, is "
      << last_msg_.header.t.tow;
  EXPECT_EQ(last_msg_.header.t.wn, 1787)
      << "incorrect value for last_msg_.header.t.wn, expected 1787, is "
      << last_msg_.header.t.wn;
  EXPECT_EQ(last_msg_.n_obs, 6)
      << "incorrect value for last_msg_.n_obs, expected 6, is "
      << last_msg_.n_obs;
  EXPECT_EQ(last_msg_.obs[0].L.f, 165)
      << "incorrect value for last_msg_.obs[0].L.f, expected 165, is "
      << last_msg_.obs[0].L.f;
  EXPECT_EQ(last_msg_.obs[0].L.i, 117912057)
      << "incorrect value for last_msg_.obs[0].L.i, expected 117912057, is "
      << last_msg_.obs[0].L.i;
  EXPECT_EQ(last_msg_.obs[0].P, 2243649790)
      << "incorrect value for last_msg_.obs[0].P, expected 2243649790, is "
      << last_msg_.obs[0].P;
  EXPECT_EQ(last_msg_.obs[0].cn0, 156)
      << "incorrect value for last_msg_.obs[0].cn0, expected 156, is "
      << last_msg_.obs[0].cn0;
  EXPECT_EQ(last_msg_.obs[0].lock, 0)
      << "incorrect value for last_msg_.obs[0].lock, expected 0, is "
      << last_msg_.obs[0].lock;
  EXPECT_EQ(last_msg_.obs[0].sid.code, 0)
      << "incorrect value for last_msg_.obs[0].sid.code, expected 0, is "
      << last_msg_.obs[0].sid.code;
  EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[0].sid.reserved, expected 0, is "
      << last_msg_.obs[0].sid.reserved;
  EXPECT_EQ(last_msg_.obs[0].sid.sat, 202)
      << "incorrect value for last_msg_.obs[0].sid.sat, expected 202, is "
      << last_msg_.obs[0].sid.sat;
  EXPECT_EQ(last_msg_.obs[1].L.f, 106)
      << "incorrect value for last_msg_.obs[1].L.f, expected 106, is "
      << last_msg_.obs[1].L.f;
  EXPECT_EQ(last_msg_.obs[1].L.i, 129900811)
      << "incorrect value for last_msg_.obs[1].L.i, expected 129900811, is "
      << last_msg_.obs[1].L.i;
  EXPECT_EQ(last_msg_.obs[1].P, 2471880049)
      << "incorrect value for last_msg_.obs[1].P, expected 2471880049, is "
      << last_msg_.obs[1].P;
  EXPECT_EQ(last_msg_.obs[1].cn0, 143)
      << "incorrect value for last_msg_.obs[1].cn0, expected 143, is "
      << last_msg_.obs[1].cn0;
  EXPECT_EQ(last_msg_.obs[1].lock, 0)
      << "incorrect value for last_msg_.obs[1].lock, expected 0, is "
      << last_msg_.obs[1].lock;
  EXPECT_EQ(last_msg_.obs[1].sid.code, 0)
      << "incorrect value for last_msg_.obs[1].sid.code, expected 0, is "
      << last_msg_.obs[1].sid.code;
  EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[1].sid.reserved, expected 0, is "
      << last_msg_.obs[1].sid.reserved;
  EXPECT_EQ(last_msg_.obs[1].sid.sat, 203)
      << "incorrect value for last_msg_.obs[1].sid.sat, expected 203, is "
      << last_msg_.obs[1].sid.sat;
  EXPECT_EQ(last_msg_.obs[2].L.f, 159)
      << "incorrect value for last_msg_.obs[2].L.f, expected 159, is "
      << last_msg_.obs[2].L.f;
  EXPECT_EQ(last_msg_.obs[2].L.i, 122530275)
      << "incorrect value for last_msg_.obs[2].L.i, expected 122530275, is "
      << last_msg_.obs[2].L.i;
  EXPECT_EQ(last_msg_.obs[2].P, 2331530678)
      << "incorrect value for last_msg_.obs[2].P, expected 2331530678, is "
      << last_msg_.obs[2].P;
  EXPECT_EQ(last_msg_.obs[2].cn0, 150)
      << "incorrect value for last_msg_.obs[2].cn0, expected 150, is "
      << last_msg_.obs[2].cn0;
  EXPECT_EQ(last_msg_.obs[2].lock, 0)
      << "incorrect value for last_msg_.obs[2].lock, expected 0, is "
      << last_msg_.obs[2].lock;
  EXPECT_EQ(last_msg_.obs[2].sid.code, 0)
      << "incorrect value for last_msg_.obs[2].sid.code, expected 0, is "
      << last_msg_.obs[2].sid.code;
  EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[2].sid.reserved, expected 0, is "
      << last_msg_.obs[2].sid.reserved;
  EXPECT_EQ(last_msg_.obs[2].sid.sat, 208)
      << "incorrect value for last_msg_.obs[2].sid.sat, expected 208, is "
      << last_msg_.obs[2].sid.sat;
  EXPECT_EQ(last_msg_.obs[3].L.f, 7)
      << "incorrect value for last_msg_.obs[3].L.f, expected 7, is "
      << last_msg_.obs[3].L.f;
  EXPECT_EQ(last_msg_.obs[3].L.i, 119281418)
      << "incorrect value for last_msg_.obs[3].L.i, expected 119281418, is "
      << last_msg_.obs[3].L.i;
  EXPECT_EQ(last_msg_.obs[3].P, 2269714449)
      << "incorrect value for last_msg_.obs[3].P, expected 2269714449, is "
      << last_msg_.obs[3].P;
  EXPECT_EQ(last_msg_.obs[3].cn0, 156)
      << "incorrect value for last_msg_.obs[3].cn0, expected 156, is "
      << last_msg_.obs[3].cn0;
  EXPECT_EQ(last_msg_.obs[3].lock, 0)
      << "incorrect value for last_msg_.obs[3].lock, expected 0, is "
      << last_msg_.obs[3].lock;
  EXPECT_EQ(last_msg_.obs[3].sid.code, 0)
      << "incorrect value for last_msg_.obs[3].sid.code, expected 0, is "
      << last_msg_.obs[3].sid.code;
  EXPECT_EQ(last_msg_.obs[3].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[3].sid.reserved, expected 0, is "
      << last_msg_.obs[3].sid.reserved;
  EXPECT_EQ(last_msg_.obs[3].sid.sat, 212)
      << "incorrect value for last_msg_.obs[3].sid.sat, expected 212, is "
      << last_msg_.obs[3].sid.sat;
  EXPECT_EQ(last_msg_.obs[4].L.f, 186)
      << "incorrect value for last_msg_.obs[4].L.f, expected 186, is "
      << last_msg_.obs[4].L.f;
  EXPECT_EQ(last_msg_.obs[4].L.i, 109692070)
      << "incorrect value for last_msg_.obs[4].L.i, expected 109692070, is "
      << last_msg_.obs[4].L.i;
  EXPECT_EQ(last_msg_.obs[4].P, 2087295852)
      << "incorrect value for last_msg_.obs[4].P, expected 2087295852, is "
      << last_msg_.obs[4].P;
  EXPECT_EQ(last_msg_.obs[4].cn0, 170)
      << "incorrect value for last_msg_.obs[4].cn0, expected 170, is "
      << last_msg_.obs[4].cn0;
  EXPECT_EQ(last_msg_.obs[4].lock, 0)
      << "incorrect value for last_msg_.obs[4].lock, expected 0, is "
      << last_msg_.obs[4].lock;
  EXPECT_EQ(last_msg_.obs[4].sid.code, 0)
      << "incorrect value for last_msg_.obs[4].sid.code, expected 0, is "
      << last_msg_.obs[4].sid.code;
  EXPECT_EQ(last_msg_.obs[4].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[4].sid.reserved, expected 0, is "
      << last_msg_.obs[4].sid.reserved;
  EXPECT_EQ(last_msg_.obs[4].sid.sat, 217)
      << "incorrect value for last_msg_.obs[4].sid.sat, expected 217, is "
      << last_msg_.obs[4].sid.sat;
  EXPECT_EQ(last_msg_.obs[5].L.f, 236)
      << "incorrect value for last_msg_.obs[5].L.f, expected 236, is "
      << last_msg_.obs[5].L.f;
  EXPECT_EQ(last_msg_.obs[5].L.i, 123339597)
      << "incorrect value for last_msg_.obs[5].L.i, expected 123339597, is "
      << last_msg_.obs[5].L.i;
  EXPECT_EQ(last_msg_.obs[5].P, 2347011798)
      << "incorrect value for last_msg_.obs[5].P, expected 2347011798, is "
      << last_msg_.obs[5].P;
  EXPECT_EQ(last_msg_.obs[5].cn0, 151)
      << "incorrect value for last_msg_.obs[5].cn0, expected 151, is "
      << last_msg_.obs[5].cn0;
  EXPECT_EQ(last_msg_.obs[5].lock, 0)
      << "incorrect value for last_msg_.obs[5].lock, expected 0, is "
      << last_msg_.obs[5].lock;
  EXPECT_EQ(last_msg_.obs[5].sid.code, 0)
      << "incorrect value for last_msg_.obs[5].sid.code, expected 0, is "
      << last_msg_.obs[5].sid.code;
  EXPECT_EQ(last_msg_.obs[5].sid.reserved, 0)
      << "incorrect value for last_msg_.obs[5].sid.reserved, expected 0, is "
      << last_msg_.obs[5].sid.reserved;
  EXPECT_EQ(last_msg_.obs[5].sid.sat, 218)
      << "incorrect value for last_msg_.obs[5].sid.sat, expected 218, is "
      << last_msg_.obs[5].sid.sat;
}
