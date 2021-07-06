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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_observation_MsgObs0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_obs_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgObs0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_obs_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_obs_t *>(last_msg_storage_)),
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
                      const msg_obs_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_obs_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgObs0, Test) {
  uint8_t encoded_frame[] = {
      85,  74,  0,   129, 240, 249, 152, 202, 226, 25,  0,   0,   0,   0,   106,
      8,   32,  49,  227, 254, 62,  121, 242, 158, 6,   146, 0,   250, 172, 182,
      10,  15,  10,  0,   30,  228, 254, 62,  12,  189, 40,  5,   59,  83,  251,
      172, 178, 10,  15,  10,  1,   215, 205, 144, 72,  106, 111, 160, 7,   243,
      109, 243, 119, 158, 10,  15,  18,  0,   25,  207, 144, 72,  223, 96,  241,
      5,   12,  52,  246, 27,  125, 9,   11,  18,  1,   34,  184, 223, 74,  150,
      138, 222, 7,   53,  13,  11,  245, 114, 9,   15,  22,  0,   113, 80,  6,
      69,  162, 41,  65,  7,   70,  127, 246, 246, 189, 9,   15,  23,  0,   247,
      80,  6,   69,  213, 35,  167, 5,   221, 152, 248, 231, 158, 9,   11,  23,
      1,   8,   146, 166, 64,  12,  122, 203, 6,   114, 51,  248, 67,  93,  3,
      11,  27,  0,   221, 172, 173, 75,  217, 47,  244, 7,   232, 225, 11,  237,
      123, 5,   15,  31,  0,   250, 174, 173, 75,  216, 163, 50,  6,   40,  70,
      9,   62,  120, 3,   11,  31,  1,   135, 16,  6,   66,  99,  218, 11,  7,
      7,   138, 242, 96,  176, 10,  15,  2,   3,   148, 130, 6,   58,  217, 88,
      54,  6,   203, 21,  252, 96,  170, 10,  15,  3,   3,   186, 108, 197, 63,
      127, 54,  211, 6,   80,  4,   241, 219, 200, 10,  15,  17,  3,   167, 195,
      8,   57,  19,  204, 22,  6,   105, 51,  254, 182, 152, 10,  15,  18,  3,
      237, 248,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_obs_t *test_msg = (msg_obs_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->header.n_obs = 32;
  test_msg->header.t.ns_residual = 0;
  test_msg->header.t.tow = 434293400;
  test_msg->header.t.wn = 2154;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[0].D.f = 172;
  test_msg->obs[0].D.i = -1536;
  test_msg->obs[0].L.f = 146;
  test_msg->obs[0].L.i = 111080057;
  test_msg->obs[0].P = 1056891697;
  test_msg->obs[0].cn0 = 182;
  test_msg->obs[0].flags = 15;
  test_msg->obs[0].lock = 10;
  test_msg->obs[0].sid.code = 0;
  test_msg->obs[0].sid.sat = 10;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[1].D.f = 172;
  test_msg->obs[1].D.i = -1197;
  test_msg->obs[1].L.f = 59;
  test_msg->obs[1].L.i = 86555916;
  test_msg->obs[1].P = 1056891934;
  test_msg->obs[1].cn0 = 178;
  test_msg->obs[1].flags = 15;
  test_msg->obs[1].lock = 10;
  test_msg->obs[1].sid.code = 1;
  test_msg->obs[1].sid.sat = 10;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[2].D.f = 119;
  test_msg->obs[2].D.i = -3219;
  test_msg->obs[2].L.f = 243;
  test_msg->obs[2].L.i = 127954794;
  test_msg->obs[2].P = 1217449431;
  test_msg->obs[2].cn0 = 158;
  test_msg->obs[2].flags = 15;
  test_msg->obs[2].lock = 10;
  test_msg->obs[2].sid.code = 0;
  test_msg->obs[2].sid.sat = 18;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[3].D.f = 27;
  test_msg->obs[3].D.i = -2508;
  test_msg->obs[3].L.f = 12;
  test_msg->obs[3].L.i = 99705055;
  test_msg->obs[3].P = 1217449753;
  test_msg->obs[3].cn0 = 125;
  test_msg->obs[3].flags = 11;
  test_msg->obs[3].lock = 9;
  test_msg->obs[3].sid.code = 1;
  test_msg->obs[3].sid.sat = 18;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[4].D.f = 245;
  test_msg->obs[4].D.i = 2829;
  test_msg->obs[4].L.f = 53;
  test_msg->obs[4].L.i = 132024982;
  test_msg->obs[4].P = 1256175650;
  test_msg->obs[4].cn0 = 114;
  test_msg->obs[4].flags = 15;
  test_msg->obs[4].lock = 9;
  test_msg->obs[4].sid.code = 0;
  test_msg->obs[4].sid.sat = 22;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[5].D.f = 246;
  test_msg->obs[5].D.i = -2433;
  test_msg->obs[5].L.f = 70;
  test_msg->obs[5].L.i = 121711010;
  test_msg->obs[5].P = 1158041713;
  test_msg->obs[5].cn0 = 189;
  test_msg->obs[5].flags = 15;
  test_msg->obs[5].lock = 9;
  test_msg->obs[5].sid.code = 0;
  test_msg->obs[5].sid.sat = 23;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[6].D.f = 231;
  test_msg->obs[6].D.i = -1896;
  test_msg->obs[6].L.f = 221;
  test_msg->obs[6].L.i = 94839765;
  test_msg->obs[6].P = 1158041847;
  test_msg->obs[6].cn0 = 158;
  test_msg->obs[6].flags = 11;
  test_msg->obs[6].lock = 9;
  test_msg->obs[6].sid.code = 1;
  test_msg->obs[6].sid.sat = 23;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[7].D.f = 67;
  test_msg->obs[7].D.i = -1997;
  test_msg->obs[7].L.f = 114;
  test_msg->obs[7].L.i = 113998348;
  test_msg->obs[7].P = 1084658184;
  test_msg->obs[7].cn0 = 93;
  test_msg->obs[7].flags = 11;
  test_msg->obs[7].lock = 3;
  test_msg->obs[7].sid.code = 0;
  test_msg->obs[7].sid.sat = 27;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[8].D.f = 237;
  test_msg->obs[8].D.i = 3041;
  test_msg->obs[8].L.f = 232;
  test_msg->obs[8].L.i = 133443545;
  test_msg->obs[8].P = 1269673181;
  test_msg->obs[8].cn0 = 123;
  test_msg->obs[8].flags = 15;
  test_msg->obs[8].lock = 5;
  test_msg->obs[8].sid.code = 0;
  test_msg->obs[8].sid.sat = 31;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[9].D.f = 62;
  test_msg->obs[9].D.i = 2374;
  test_msg->obs[9].L.f = 40;
  test_msg->obs[9].L.i = 103982040;
  test_msg->obs[9].P = 1269673722;
  test_msg->obs[9].cn0 = 120;
  test_msg->obs[9].flags = 11;
  test_msg->obs[9].lock = 3;
  test_msg->obs[9].sid.code = 1;
  test_msg->obs[9].sid.sat = 31;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[10].D.f = 96;
  test_msg->obs[10].D.i = -3446;
  test_msg->obs[10].L.f = 7;
  test_msg->obs[10].L.i = 118217315;
  test_msg->obs[10].P = 1107693703;
  test_msg->obs[10].cn0 = 176;
  test_msg->obs[10].flags = 15;
  test_msg->obs[10].lock = 10;
  test_msg->obs[10].sid.code = 3;
  test_msg->obs[10].sid.sat = 2;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[11].D.f = 96;
  test_msg->obs[11].D.i = -1003;
  test_msg->obs[11].L.f = 203;
  test_msg->obs[11].L.i = 104224985;
  test_msg->obs[11].P = 973505172;
  test_msg->obs[11].cn0 = 170;
  test_msg->obs[11].flags = 15;
  test_msg->obs[11].lock = 10;
  test_msg->obs[11].sid.code = 3;
  test_msg->obs[11].sid.sat = 3;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[12].D.f = 219;
  test_msg->obs[12].D.i = -3836;
  test_msg->obs[12].L.f = 80;
  test_msg->obs[12].L.i = 114505343;
  test_msg->obs[12].P = 1069903034;
  test_msg->obs[12].cn0 = 200;
  test_msg->obs[12].flags = 15;
  test_msg->obs[12].lock = 10;
  test_msg->obs[12].sid.code = 3;
  test_msg->obs[12].sid.sat = 17;
  if (sizeof(test_msg->obs) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->obs[0]));
  }
  test_msg->obs[13].D.f = 182;
  test_msg->obs[13].D.i = -461;
  test_msg->obs[13].L.f = 105;
  test_msg->obs[13].L.i = 102157331;
  test_msg->obs[13].P = 956875687;
  test_msg->obs[13].cn0 = 152;
  test_msg->obs[13].flags = 15;
  test_msg->obs[13].lock = 10;
  test_msg->obs[13].sid.code = 3;
  test_msg->obs[13].sid.sat = 18;

  EXPECT_EQ(send_message(0x4a, 61569, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 61569);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->header.n_obs, 32)
      << "incorrect value for header.n_obs, expected 32, is "
      << last_msg_->header.n_obs;
  EXPECT_EQ(last_msg_->header.t.ns_residual, 0)
      << "incorrect value for header.t.ns_residual, expected 0, is "
      << last_msg_->header.t.ns_residual;
  EXPECT_EQ(last_msg_->header.t.tow, 434293400)
      << "incorrect value for header.t.tow, expected 434293400, is "
      << last_msg_->header.t.tow;
  EXPECT_EQ(last_msg_->header.t.wn, 2154)
      << "incorrect value for header.t.wn, expected 2154, is "
      << last_msg_->header.t.wn;
  EXPECT_EQ(last_msg_->obs[0].D.f, 172)
      << "incorrect value for obs[0].D.f, expected 172, is "
      << last_msg_->obs[0].D.f;
  EXPECT_EQ(last_msg_->obs[0].D.i, -1536)
      << "incorrect value for obs[0].D.i, expected -1536, is "
      << last_msg_->obs[0].D.i;
  EXPECT_EQ(last_msg_->obs[0].L.f, 146)
      << "incorrect value for obs[0].L.f, expected 146, is "
      << last_msg_->obs[0].L.f;
  EXPECT_EQ(last_msg_->obs[0].L.i, 111080057)
      << "incorrect value for obs[0].L.i, expected 111080057, is "
      << last_msg_->obs[0].L.i;
  EXPECT_EQ(last_msg_->obs[0].P, 1056891697)
      << "incorrect value for obs[0].P, expected 1056891697, is "
      << last_msg_->obs[0].P;
  EXPECT_EQ(last_msg_->obs[0].cn0, 182)
      << "incorrect value for obs[0].cn0, expected 182, is "
      << last_msg_->obs[0].cn0;
  EXPECT_EQ(last_msg_->obs[0].flags, 15)
      << "incorrect value for obs[0].flags, expected 15, is "
      << last_msg_->obs[0].flags;
  EXPECT_EQ(last_msg_->obs[0].lock, 10)
      << "incorrect value for obs[0].lock, expected 10, is "
      << last_msg_->obs[0].lock;
  EXPECT_EQ(last_msg_->obs[0].sid.code, 0)
      << "incorrect value for obs[0].sid.code, expected 0, is "
      << last_msg_->obs[0].sid.code;
  EXPECT_EQ(last_msg_->obs[0].sid.sat, 10)
      << "incorrect value for obs[0].sid.sat, expected 10, is "
      << last_msg_->obs[0].sid.sat;
  EXPECT_EQ(last_msg_->obs[1].D.f, 172)
      << "incorrect value for obs[1].D.f, expected 172, is "
      << last_msg_->obs[1].D.f;
  EXPECT_EQ(last_msg_->obs[1].D.i, -1197)
      << "incorrect value for obs[1].D.i, expected -1197, is "
      << last_msg_->obs[1].D.i;
  EXPECT_EQ(last_msg_->obs[1].L.f, 59)
      << "incorrect value for obs[1].L.f, expected 59, is "
      << last_msg_->obs[1].L.f;
  EXPECT_EQ(last_msg_->obs[1].L.i, 86555916)
      << "incorrect value for obs[1].L.i, expected 86555916, is "
      << last_msg_->obs[1].L.i;
  EXPECT_EQ(last_msg_->obs[1].P, 1056891934)
      << "incorrect value for obs[1].P, expected 1056891934, is "
      << last_msg_->obs[1].P;
  EXPECT_EQ(last_msg_->obs[1].cn0, 178)
      << "incorrect value for obs[1].cn0, expected 178, is "
      << last_msg_->obs[1].cn0;
  EXPECT_EQ(last_msg_->obs[1].flags, 15)
      << "incorrect value for obs[1].flags, expected 15, is "
      << last_msg_->obs[1].flags;
  EXPECT_EQ(last_msg_->obs[1].lock, 10)
      << "incorrect value for obs[1].lock, expected 10, is "
      << last_msg_->obs[1].lock;
  EXPECT_EQ(last_msg_->obs[1].sid.code, 1)
      << "incorrect value for obs[1].sid.code, expected 1, is "
      << last_msg_->obs[1].sid.code;
  EXPECT_EQ(last_msg_->obs[1].sid.sat, 10)
      << "incorrect value for obs[1].sid.sat, expected 10, is "
      << last_msg_->obs[1].sid.sat;
  EXPECT_EQ(last_msg_->obs[2].D.f, 119)
      << "incorrect value for obs[2].D.f, expected 119, is "
      << last_msg_->obs[2].D.f;
  EXPECT_EQ(last_msg_->obs[2].D.i, -3219)
      << "incorrect value for obs[2].D.i, expected -3219, is "
      << last_msg_->obs[2].D.i;
  EXPECT_EQ(last_msg_->obs[2].L.f, 243)
      << "incorrect value for obs[2].L.f, expected 243, is "
      << last_msg_->obs[2].L.f;
  EXPECT_EQ(last_msg_->obs[2].L.i, 127954794)
      << "incorrect value for obs[2].L.i, expected 127954794, is "
      << last_msg_->obs[2].L.i;
  EXPECT_EQ(last_msg_->obs[2].P, 1217449431)
      << "incorrect value for obs[2].P, expected 1217449431, is "
      << last_msg_->obs[2].P;
  EXPECT_EQ(last_msg_->obs[2].cn0, 158)
      << "incorrect value for obs[2].cn0, expected 158, is "
      << last_msg_->obs[2].cn0;
  EXPECT_EQ(last_msg_->obs[2].flags, 15)
      << "incorrect value for obs[2].flags, expected 15, is "
      << last_msg_->obs[2].flags;
  EXPECT_EQ(last_msg_->obs[2].lock, 10)
      << "incorrect value for obs[2].lock, expected 10, is "
      << last_msg_->obs[2].lock;
  EXPECT_EQ(last_msg_->obs[2].sid.code, 0)
      << "incorrect value for obs[2].sid.code, expected 0, is "
      << last_msg_->obs[2].sid.code;
  EXPECT_EQ(last_msg_->obs[2].sid.sat, 18)
      << "incorrect value for obs[2].sid.sat, expected 18, is "
      << last_msg_->obs[2].sid.sat;
  EXPECT_EQ(last_msg_->obs[3].D.f, 27)
      << "incorrect value for obs[3].D.f, expected 27, is "
      << last_msg_->obs[3].D.f;
  EXPECT_EQ(last_msg_->obs[3].D.i, -2508)
      << "incorrect value for obs[3].D.i, expected -2508, is "
      << last_msg_->obs[3].D.i;
  EXPECT_EQ(last_msg_->obs[3].L.f, 12)
      << "incorrect value for obs[3].L.f, expected 12, is "
      << last_msg_->obs[3].L.f;
  EXPECT_EQ(last_msg_->obs[3].L.i, 99705055)
      << "incorrect value for obs[3].L.i, expected 99705055, is "
      << last_msg_->obs[3].L.i;
  EXPECT_EQ(last_msg_->obs[3].P, 1217449753)
      << "incorrect value for obs[3].P, expected 1217449753, is "
      << last_msg_->obs[3].P;
  EXPECT_EQ(last_msg_->obs[3].cn0, 125)
      << "incorrect value for obs[3].cn0, expected 125, is "
      << last_msg_->obs[3].cn0;
  EXPECT_EQ(last_msg_->obs[3].flags, 11)
      << "incorrect value for obs[3].flags, expected 11, is "
      << last_msg_->obs[3].flags;
  EXPECT_EQ(last_msg_->obs[3].lock, 9)
      << "incorrect value for obs[3].lock, expected 9, is "
      << last_msg_->obs[3].lock;
  EXPECT_EQ(last_msg_->obs[3].sid.code, 1)
      << "incorrect value for obs[3].sid.code, expected 1, is "
      << last_msg_->obs[3].sid.code;
  EXPECT_EQ(last_msg_->obs[3].sid.sat, 18)
      << "incorrect value for obs[3].sid.sat, expected 18, is "
      << last_msg_->obs[3].sid.sat;
  EXPECT_EQ(last_msg_->obs[4].D.f, 245)
      << "incorrect value for obs[4].D.f, expected 245, is "
      << last_msg_->obs[4].D.f;
  EXPECT_EQ(last_msg_->obs[4].D.i, 2829)
      << "incorrect value for obs[4].D.i, expected 2829, is "
      << last_msg_->obs[4].D.i;
  EXPECT_EQ(last_msg_->obs[4].L.f, 53)
      << "incorrect value for obs[4].L.f, expected 53, is "
      << last_msg_->obs[4].L.f;
  EXPECT_EQ(last_msg_->obs[4].L.i, 132024982)
      << "incorrect value for obs[4].L.i, expected 132024982, is "
      << last_msg_->obs[4].L.i;
  EXPECT_EQ(last_msg_->obs[4].P, 1256175650)
      << "incorrect value for obs[4].P, expected 1256175650, is "
      << last_msg_->obs[4].P;
  EXPECT_EQ(last_msg_->obs[4].cn0, 114)
      << "incorrect value for obs[4].cn0, expected 114, is "
      << last_msg_->obs[4].cn0;
  EXPECT_EQ(last_msg_->obs[4].flags, 15)
      << "incorrect value for obs[4].flags, expected 15, is "
      << last_msg_->obs[4].flags;
  EXPECT_EQ(last_msg_->obs[4].lock, 9)
      << "incorrect value for obs[4].lock, expected 9, is "
      << last_msg_->obs[4].lock;
  EXPECT_EQ(last_msg_->obs[4].sid.code, 0)
      << "incorrect value for obs[4].sid.code, expected 0, is "
      << last_msg_->obs[4].sid.code;
  EXPECT_EQ(last_msg_->obs[4].sid.sat, 22)
      << "incorrect value for obs[4].sid.sat, expected 22, is "
      << last_msg_->obs[4].sid.sat;
  EXPECT_EQ(last_msg_->obs[5].D.f, 246)
      << "incorrect value for obs[5].D.f, expected 246, is "
      << last_msg_->obs[5].D.f;
  EXPECT_EQ(last_msg_->obs[5].D.i, -2433)
      << "incorrect value for obs[5].D.i, expected -2433, is "
      << last_msg_->obs[5].D.i;
  EXPECT_EQ(last_msg_->obs[5].L.f, 70)
      << "incorrect value for obs[5].L.f, expected 70, is "
      << last_msg_->obs[5].L.f;
  EXPECT_EQ(last_msg_->obs[5].L.i, 121711010)
      << "incorrect value for obs[5].L.i, expected 121711010, is "
      << last_msg_->obs[5].L.i;
  EXPECT_EQ(last_msg_->obs[5].P, 1158041713)
      << "incorrect value for obs[5].P, expected 1158041713, is "
      << last_msg_->obs[5].P;
  EXPECT_EQ(last_msg_->obs[5].cn0, 189)
      << "incorrect value for obs[5].cn0, expected 189, is "
      << last_msg_->obs[5].cn0;
  EXPECT_EQ(last_msg_->obs[5].flags, 15)
      << "incorrect value for obs[5].flags, expected 15, is "
      << last_msg_->obs[5].flags;
  EXPECT_EQ(last_msg_->obs[5].lock, 9)
      << "incorrect value for obs[5].lock, expected 9, is "
      << last_msg_->obs[5].lock;
  EXPECT_EQ(last_msg_->obs[5].sid.code, 0)
      << "incorrect value for obs[5].sid.code, expected 0, is "
      << last_msg_->obs[5].sid.code;
  EXPECT_EQ(last_msg_->obs[5].sid.sat, 23)
      << "incorrect value for obs[5].sid.sat, expected 23, is "
      << last_msg_->obs[5].sid.sat;
  EXPECT_EQ(last_msg_->obs[6].D.f, 231)
      << "incorrect value for obs[6].D.f, expected 231, is "
      << last_msg_->obs[6].D.f;
  EXPECT_EQ(last_msg_->obs[6].D.i, -1896)
      << "incorrect value for obs[6].D.i, expected -1896, is "
      << last_msg_->obs[6].D.i;
  EXPECT_EQ(last_msg_->obs[6].L.f, 221)
      << "incorrect value for obs[6].L.f, expected 221, is "
      << last_msg_->obs[6].L.f;
  EXPECT_EQ(last_msg_->obs[6].L.i, 94839765)
      << "incorrect value for obs[6].L.i, expected 94839765, is "
      << last_msg_->obs[6].L.i;
  EXPECT_EQ(last_msg_->obs[6].P, 1158041847)
      << "incorrect value for obs[6].P, expected 1158041847, is "
      << last_msg_->obs[6].P;
  EXPECT_EQ(last_msg_->obs[6].cn0, 158)
      << "incorrect value for obs[6].cn0, expected 158, is "
      << last_msg_->obs[6].cn0;
  EXPECT_EQ(last_msg_->obs[6].flags, 11)
      << "incorrect value for obs[6].flags, expected 11, is "
      << last_msg_->obs[6].flags;
  EXPECT_EQ(last_msg_->obs[6].lock, 9)
      << "incorrect value for obs[6].lock, expected 9, is "
      << last_msg_->obs[6].lock;
  EXPECT_EQ(last_msg_->obs[6].sid.code, 1)
      << "incorrect value for obs[6].sid.code, expected 1, is "
      << last_msg_->obs[6].sid.code;
  EXPECT_EQ(last_msg_->obs[6].sid.sat, 23)
      << "incorrect value for obs[6].sid.sat, expected 23, is "
      << last_msg_->obs[6].sid.sat;
  EXPECT_EQ(last_msg_->obs[7].D.f, 67)
      << "incorrect value for obs[7].D.f, expected 67, is "
      << last_msg_->obs[7].D.f;
  EXPECT_EQ(last_msg_->obs[7].D.i, -1997)
      << "incorrect value for obs[7].D.i, expected -1997, is "
      << last_msg_->obs[7].D.i;
  EXPECT_EQ(last_msg_->obs[7].L.f, 114)
      << "incorrect value for obs[7].L.f, expected 114, is "
      << last_msg_->obs[7].L.f;
  EXPECT_EQ(last_msg_->obs[7].L.i, 113998348)
      << "incorrect value for obs[7].L.i, expected 113998348, is "
      << last_msg_->obs[7].L.i;
  EXPECT_EQ(last_msg_->obs[7].P, 1084658184)
      << "incorrect value for obs[7].P, expected 1084658184, is "
      << last_msg_->obs[7].P;
  EXPECT_EQ(last_msg_->obs[7].cn0, 93)
      << "incorrect value for obs[7].cn0, expected 93, is "
      << last_msg_->obs[7].cn0;
  EXPECT_EQ(last_msg_->obs[7].flags, 11)
      << "incorrect value for obs[7].flags, expected 11, is "
      << last_msg_->obs[7].flags;
  EXPECT_EQ(last_msg_->obs[7].lock, 3)
      << "incorrect value for obs[7].lock, expected 3, is "
      << last_msg_->obs[7].lock;
  EXPECT_EQ(last_msg_->obs[7].sid.code, 0)
      << "incorrect value for obs[7].sid.code, expected 0, is "
      << last_msg_->obs[7].sid.code;
  EXPECT_EQ(last_msg_->obs[7].sid.sat, 27)
      << "incorrect value for obs[7].sid.sat, expected 27, is "
      << last_msg_->obs[7].sid.sat;
  EXPECT_EQ(last_msg_->obs[8].D.f, 237)
      << "incorrect value for obs[8].D.f, expected 237, is "
      << last_msg_->obs[8].D.f;
  EXPECT_EQ(last_msg_->obs[8].D.i, 3041)
      << "incorrect value for obs[8].D.i, expected 3041, is "
      << last_msg_->obs[8].D.i;
  EXPECT_EQ(last_msg_->obs[8].L.f, 232)
      << "incorrect value for obs[8].L.f, expected 232, is "
      << last_msg_->obs[8].L.f;
  EXPECT_EQ(last_msg_->obs[8].L.i, 133443545)
      << "incorrect value for obs[8].L.i, expected 133443545, is "
      << last_msg_->obs[8].L.i;
  EXPECT_EQ(last_msg_->obs[8].P, 1269673181)
      << "incorrect value for obs[8].P, expected 1269673181, is "
      << last_msg_->obs[8].P;
  EXPECT_EQ(last_msg_->obs[8].cn0, 123)
      << "incorrect value for obs[8].cn0, expected 123, is "
      << last_msg_->obs[8].cn0;
  EXPECT_EQ(last_msg_->obs[8].flags, 15)
      << "incorrect value for obs[8].flags, expected 15, is "
      << last_msg_->obs[8].flags;
  EXPECT_EQ(last_msg_->obs[8].lock, 5)
      << "incorrect value for obs[8].lock, expected 5, is "
      << last_msg_->obs[8].lock;
  EXPECT_EQ(last_msg_->obs[8].sid.code, 0)
      << "incorrect value for obs[8].sid.code, expected 0, is "
      << last_msg_->obs[8].sid.code;
  EXPECT_EQ(last_msg_->obs[8].sid.sat, 31)
      << "incorrect value for obs[8].sid.sat, expected 31, is "
      << last_msg_->obs[8].sid.sat;
  EXPECT_EQ(last_msg_->obs[9].D.f, 62)
      << "incorrect value for obs[9].D.f, expected 62, is "
      << last_msg_->obs[9].D.f;
  EXPECT_EQ(last_msg_->obs[9].D.i, 2374)
      << "incorrect value for obs[9].D.i, expected 2374, is "
      << last_msg_->obs[9].D.i;
  EXPECT_EQ(last_msg_->obs[9].L.f, 40)
      << "incorrect value for obs[9].L.f, expected 40, is "
      << last_msg_->obs[9].L.f;
  EXPECT_EQ(last_msg_->obs[9].L.i, 103982040)
      << "incorrect value for obs[9].L.i, expected 103982040, is "
      << last_msg_->obs[9].L.i;
  EXPECT_EQ(last_msg_->obs[9].P, 1269673722)
      << "incorrect value for obs[9].P, expected 1269673722, is "
      << last_msg_->obs[9].P;
  EXPECT_EQ(last_msg_->obs[9].cn0, 120)
      << "incorrect value for obs[9].cn0, expected 120, is "
      << last_msg_->obs[9].cn0;
  EXPECT_EQ(last_msg_->obs[9].flags, 11)
      << "incorrect value for obs[9].flags, expected 11, is "
      << last_msg_->obs[9].flags;
  EXPECT_EQ(last_msg_->obs[9].lock, 3)
      << "incorrect value for obs[9].lock, expected 3, is "
      << last_msg_->obs[9].lock;
  EXPECT_EQ(last_msg_->obs[9].sid.code, 1)
      << "incorrect value for obs[9].sid.code, expected 1, is "
      << last_msg_->obs[9].sid.code;
  EXPECT_EQ(last_msg_->obs[9].sid.sat, 31)
      << "incorrect value for obs[9].sid.sat, expected 31, is "
      << last_msg_->obs[9].sid.sat;
  EXPECT_EQ(last_msg_->obs[10].D.f, 96)
      << "incorrect value for obs[10].D.f, expected 96, is "
      << last_msg_->obs[10].D.f;
  EXPECT_EQ(last_msg_->obs[10].D.i, -3446)
      << "incorrect value for obs[10].D.i, expected -3446, is "
      << last_msg_->obs[10].D.i;
  EXPECT_EQ(last_msg_->obs[10].L.f, 7)
      << "incorrect value for obs[10].L.f, expected 7, is "
      << last_msg_->obs[10].L.f;
  EXPECT_EQ(last_msg_->obs[10].L.i, 118217315)
      << "incorrect value for obs[10].L.i, expected 118217315, is "
      << last_msg_->obs[10].L.i;
  EXPECT_EQ(last_msg_->obs[10].P, 1107693703)
      << "incorrect value for obs[10].P, expected 1107693703, is "
      << last_msg_->obs[10].P;
  EXPECT_EQ(last_msg_->obs[10].cn0, 176)
      << "incorrect value for obs[10].cn0, expected 176, is "
      << last_msg_->obs[10].cn0;
  EXPECT_EQ(last_msg_->obs[10].flags, 15)
      << "incorrect value for obs[10].flags, expected 15, is "
      << last_msg_->obs[10].flags;
  EXPECT_EQ(last_msg_->obs[10].lock, 10)
      << "incorrect value for obs[10].lock, expected 10, is "
      << last_msg_->obs[10].lock;
  EXPECT_EQ(last_msg_->obs[10].sid.code, 3)
      << "incorrect value for obs[10].sid.code, expected 3, is "
      << last_msg_->obs[10].sid.code;
  EXPECT_EQ(last_msg_->obs[10].sid.sat, 2)
      << "incorrect value for obs[10].sid.sat, expected 2, is "
      << last_msg_->obs[10].sid.sat;
  EXPECT_EQ(last_msg_->obs[11].D.f, 96)
      << "incorrect value for obs[11].D.f, expected 96, is "
      << last_msg_->obs[11].D.f;
  EXPECT_EQ(last_msg_->obs[11].D.i, -1003)
      << "incorrect value for obs[11].D.i, expected -1003, is "
      << last_msg_->obs[11].D.i;
  EXPECT_EQ(last_msg_->obs[11].L.f, 203)
      << "incorrect value for obs[11].L.f, expected 203, is "
      << last_msg_->obs[11].L.f;
  EXPECT_EQ(last_msg_->obs[11].L.i, 104224985)
      << "incorrect value for obs[11].L.i, expected 104224985, is "
      << last_msg_->obs[11].L.i;
  EXPECT_EQ(last_msg_->obs[11].P, 973505172)
      << "incorrect value for obs[11].P, expected 973505172, is "
      << last_msg_->obs[11].P;
  EXPECT_EQ(last_msg_->obs[11].cn0, 170)
      << "incorrect value for obs[11].cn0, expected 170, is "
      << last_msg_->obs[11].cn0;
  EXPECT_EQ(last_msg_->obs[11].flags, 15)
      << "incorrect value for obs[11].flags, expected 15, is "
      << last_msg_->obs[11].flags;
  EXPECT_EQ(last_msg_->obs[11].lock, 10)
      << "incorrect value for obs[11].lock, expected 10, is "
      << last_msg_->obs[11].lock;
  EXPECT_EQ(last_msg_->obs[11].sid.code, 3)
      << "incorrect value for obs[11].sid.code, expected 3, is "
      << last_msg_->obs[11].sid.code;
  EXPECT_EQ(last_msg_->obs[11].sid.sat, 3)
      << "incorrect value for obs[11].sid.sat, expected 3, is "
      << last_msg_->obs[11].sid.sat;
  EXPECT_EQ(last_msg_->obs[12].D.f, 219)
      << "incorrect value for obs[12].D.f, expected 219, is "
      << last_msg_->obs[12].D.f;
  EXPECT_EQ(last_msg_->obs[12].D.i, -3836)
      << "incorrect value for obs[12].D.i, expected -3836, is "
      << last_msg_->obs[12].D.i;
  EXPECT_EQ(last_msg_->obs[12].L.f, 80)
      << "incorrect value for obs[12].L.f, expected 80, is "
      << last_msg_->obs[12].L.f;
  EXPECT_EQ(last_msg_->obs[12].L.i, 114505343)
      << "incorrect value for obs[12].L.i, expected 114505343, is "
      << last_msg_->obs[12].L.i;
  EXPECT_EQ(last_msg_->obs[12].P, 1069903034)
      << "incorrect value for obs[12].P, expected 1069903034, is "
      << last_msg_->obs[12].P;
  EXPECT_EQ(last_msg_->obs[12].cn0, 200)
      << "incorrect value for obs[12].cn0, expected 200, is "
      << last_msg_->obs[12].cn0;
  EXPECT_EQ(last_msg_->obs[12].flags, 15)
      << "incorrect value for obs[12].flags, expected 15, is "
      << last_msg_->obs[12].flags;
  EXPECT_EQ(last_msg_->obs[12].lock, 10)
      << "incorrect value for obs[12].lock, expected 10, is "
      << last_msg_->obs[12].lock;
  EXPECT_EQ(last_msg_->obs[12].sid.code, 3)
      << "incorrect value for obs[12].sid.code, expected 3, is "
      << last_msg_->obs[12].sid.code;
  EXPECT_EQ(last_msg_->obs[12].sid.sat, 17)
      << "incorrect value for obs[12].sid.sat, expected 17, is "
      << last_msg_->obs[12].sid.sat;
  EXPECT_EQ(last_msg_->obs[13].D.f, 182)
      << "incorrect value for obs[13].D.f, expected 182, is "
      << last_msg_->obs[13].D.f;
  EXPECT_EQ(last_msg_->obs[13].D.i, -461)
      << "incorrect value for obs[13].D.i, expected -461, is "
      << last_msg_->obs[13].D.i;
  EXPECT_EQ(last_msg_->obs[13].L.f, 105)
      << "incorrect value for obs[13].L.f, expected 105, is "
      << last_msg_->obs[13].L.f;
  EXPECT_EQ(last_msg_->obs[13].L.i, 102157331)
      << "incorrect value for obs[13].L.i, expected 102157331, is "
      << last_msg_->obs[13].L.i;
  EXPECT_EQ(last_msg_->obs[13].P, 956875687)
      << "incorrect value for obs[13].P, expected 956875687, is "
      << last_msg_->obs[13].P;
  EXPECT_EQ(last_msg_->obs[13].cn0, 152)
      << "incorrect value for obs[13].cn0, expected 152, is "
      << last_msg_->obs[13].cn0;
  EXPECT_EQ(last_msg_->obs[13].flags, 15)
      << "incorrect value for obs[13].flags, expected 15, is "
      << last_msg_->obs[13].flags;
  EXPECT_EQ(last_msg_->obs[13].lock, 10)
      << "incorrect value for obs[13].lock, expected 10, is "
      << last_msg_->obs[13].lock;
  EXPECT_EQ(last_msg_->obs[13].sid.code, 3)
      << "incorrect value for obs[13].sid.code, expected 3, is "
      << last_msg_->obs[13].sid.code;
  EXPECT_EQ(last_msg_->obs[13].sid.sat, 18)
      << "incorrect value for obs[13].sid.sat, expected 18, is "
      << last_msg_->obs[13].sid.sat;
}
class Test_legacy_auto_check_sbp_observation_MsgObs1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_obs_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgObs1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_obs_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_obs_t *>(last_msg_storage_)),
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
                      const msg_obs_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_obs_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgObs1, Test) {
  uint8_t encoded_frame[] = {
      85, 74, 0, 129, 240, 11, 152, 202, 226, 25,
      0,  0,  0, 0,   106, 8,  16,  201, 101,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_obs_t *test_msg = (msg_obs_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->header.n_obs = 16;
  test_msg->header.t.ns_residual = 0;
  test_msg->header.t.tow = 434293400;
  test_msg->header.t.wn = 2154;

  EXPECT_EQ(send_message(0x4a, 61569, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 61569);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->header.n_obs, 16)
      << "incorrect value for header.n_obs, expected 16, is "
      << last_msg_->header.n_obs;
  EXPECT_EQ(last_msg_->header.t.ns_residual, 0)
      << "incorrect value for header.t.ns_residual, expected 0, is "
      << last_msg_->header.t.ns_residual;
  EXPECT_EQ(last_msg_->header.t.tow, 434293400)
      << "incorrect value for header.t.tow, expected 434293400, is "
      << last_msg_->header.t.tow;
  EXPECT_EQ(last_msg_->header.t.wn, 2154)
      << "incorrect value for header.t.wn, expected 2154, is "
      << last_msg_->header.t.wn;
}
