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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgSvAzEl.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_observation_MsgSvAzEl0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_sv_az_el_t> {
 public:
  Test_auto_check_sbp_observation_MsgSvAzEl0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_sv_az_el_t>(this),
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
                      const sbp_msg_sv_az_el_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_sv_az_el_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_observation_MsgSvAzEl0, Test) {
  uint8_t encoded_frame[] = {
      85,  151, 0,  207, 121, 132, 8,  0,  160, 12, 10,  0,  139, 66, 13, 0,
      16,  1,   15, 0,   24,  25,  16, 0,  127, 18, 18,  0,  42,  53, 20, 0,
      31,  16,  23, 0,   12,  67,  24, 0,  47,  10, 26,  0,  116, 8,  27, 0,
      153, 43,  29, 0,   77,  10,  32, 0,  94,  26, 1,   3,  16,  58, 2,  3,
      108, 53,  8,  3,   17,  13,  17, 3,  165, 40, 23,  3,  63,  35, 24, 3,
      41,  73,  20, 12,  114, 26,  27, 12, 72,  54, 28,  12, 69,  3,  29, 12,
      158, 14,  30, 12,  152, 68,  32, 12, 120, 82, 2,   14, 131, 6,  4,  14,
      27,  44,  5,  14,  101, 21,  9,  14, 81,  65, 11,  14, 49,  56, 12, 14,
      59,  6,   30, 14,  154, 4,   36, 14, 165, 62, 168, 36,
  };

  sbp_msg_sv_az_el_t test_msg{};

  test_msg.azel[0].az = 160;
  test_msg.azel[0].el = 12;
  test_msg.azel[0].sid.code = 0;
  test_msg.azel[0].sid.sat = 8;

  test_msg.azel[1].az = 139;
  test_msg.azel[1].el = 66;
  test_msg.azel[1].sid.code = 0;
  test_msg.azel[1].sid.sat = 10;

  test_msg.azel[2].az = 16;
  test_msg.azel[2].el = 1;
  test_msg.azel[2].sid.code = 0;
  test_msg.azel[2].sid.sat = 13;

  test_msg.azel[3].az = 24;
  test_msg.azel[3].el = 25;
  test_msg.azel[3].sid.code = 0;
  test_msg.azel[3].sid.sat = 15;

  test_msg.azel[4].az = 127;
  test_msg.azel[4].el = 18;
  test_msg.azel[4].sid.code = 0;
  test_msg.azel[4].sid.sat = 16;

  test_msg.azel[5].az = 42;
  test_msg.azel[5].el = 53;
  test_msg.azel[5].sid.code = 0;
  test_msg.azel[5].sid.sat = 18;

  test_msg.azel[6].az = 31;
  test_msg.azel[6].el = 16;
  test_msg.azel[6].sid.code = 0;
  test_msg.azel[6].sid.sat = 20;

  test_msg.azel[7].az = 12;
  test_msg.azel[7].el = 67;
  test_msg.azel[7].sid.code = 0;
  test_msg.azel[7].sid.sat = 23;

  test_msg.azel[8].az = 47;
  test_msg.azel[8].el = 10;
  test_msg.azel[8].sid.code = 0;
  test_msg.azel[8].sid.sat = 24;

  test_msg.azel[9].az = 116;
  test_msg.azel[9].el = 8;
  test_msg.azel[9].sid.code = 0;
  test_msg.azel[9].sid.sat = 26;

  test_msg.azel[10].az = 153;
  test_msg.azel[10].el = 43;
  test_msg.azel[10].sid.code = 0;
  test_msg.azel[10].sid.sat = 27;

  test_msg.azel[11].az = 77;
  test_msg.azel[11].el = 10;
  test_msg.azel[11].sid.code = 0;
  test_msg.azel[11].sid.sat = 29;

  test_msg.azel[12].az = 94;
  test_msg.azel[12].el = 26;
  test_msg.azel[12].sid.code = 0;
  test_msg.azel[12].sid.sat = 32;

  test_msg.azel[13].az = 16;
  test_msg.azel[13].el = 58;
  test_msg.azel[13].sid.code = 3;
  test_msg.azel[13].sid.sat = 1;

  test_msg.azel[14].az = 108;
  test_msg.azel[14].el = 53;
  test_msg.azel[14].sid.code = 3;
  test_msg.azel[14].sid.sat = 2;

  test_msg.azel[15].az = 17;
  test_msg.azel[15].el = 13;
  test_msg.azel[15].sid.code = 3;
  test_msg.azel[15].sid.sat = 8;

  test_msg.azel[16].az = 165;
  test_msg.azel[16].el = 40;
  test_msg.azel[16].sid.code = 3;
  test_msg.azel[16].sid.sat = 17;

  test_msg.azel[17].az = 63;
  test_msg.azel[17].el = 35;
  test_msg.azel[17].sid.code = 3;
  test_msg.azel[17].sid.sat = 23;

  test_msg.azel[18].az = 41;
  test_msg.azel[18].el = 73;
  test_msg.azel[18].sid.code = 3;
  test_msg.azel[18].sid.sat = 24;

  test_msg.azel[19].az = 114;
  test_msg.azel[19].el = 26;
  test_msg.azel[19].sid.code = 12;
  test_msg.azel[19].sid.sat = 20;

  test_msg.azel[20].az = 72;
  test_msg.azel[20].el = 54;
  test_msg.azel[20].sid.code = 12;
  test_msg.azel[20].sid.sat = 27;

  test_msg.azel[21].az = 69;
  test_msg.azel[21].el = 3;
  test_msg.azel[21].sid.code = 12;
  test_msg.azel[21].sid.sat = 28;

  test_msg.azel[22].az = 158;
  test_msg.azel[22].el = 14;
  test_msg.azel[22].sid.code = 12;
  test_msg.azel[22].sid.sat = 29;

  test_msg.azel[23].az = 152;
  test_msg.azel[23].el = 68;
  test_msg.azel[23].sid.code = 12;
  test_msg.azel[23].sid.sat = 30;

  test_msg.azel[24].az = 120;
  test_msg.azel[24].el = 82;
  test_msg.azel[24].sid.code = 12;
  test_msg.azel[24].sid.sat = 32;

  test_msg.azel[25].az = 131;
  test_msg.azel[25].el = 6;
  test_msg.azel[25].sid.code = 14;
  test_msg.azel[25].sid.sat = 2;

  test_msg.azel[26].az = 27;
  test_msg.azel[26].el = 44;
  test_msg.azel[26].sid.code = 14;
  test_msg.azel[26].sid.sat = 4;

  test_msg.azel[27].az = 101;
  test_msg.azel[27].el = 21;
  test_msg.azel[27].sid.code = 14;
  test_msg.azel[27].sid.sat = 5;

  test_msg.azel[28].az = 81;
  test_msg.azel[28].el = 65;
  test_msg.azel[28].sid.code = 14;
  test_msg.azel[28].sid.sat = 9;

  test_msg.azel[29].az = 49;
  test_msg.azel[29].el = 56;
  test_msg.azel[29].sid.code = 14;
  test_msg.azel[29].sid.sat = 11;

  test_msg.azel[30].az = 59;
  test_msg.azel[30].el = 6;
  test_msg.azel[30].sid.code = 14;
  test_msg.azel[30].sid.sat = 12;

  test_msg.azel[31].az = 154;
  test_msg.azel[31].el = 4;
  test_msg.azel[31].sid.code = 14;
  test_msg.azel[31].sid.sat = 30;

  test_msg.azel[32].az = 165;
  test_msg.azel[32].el = 62;
  test_msg.azel[32].sid.code = 14;
  test_msg.azel[32].sid.sat = 36;
  test_msg.n_azel = 33;

  EXPECT_EQ(send_message(31183, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 31183);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.azel[0].az, 160)
      << "incorrect value for last_msg_.azel[0].az, expected 160, is "
      << last_msg_.azel[0].az;
  EXPECT_EQ(last_msg_.azel[0].el, 12)
      << "incorrect value for last_msg_.azel[0].el, expected 12, is "
      << last_msg_.azel[0].el;
  EXPECT_EQ(last_msg_.azel[0].sid.code, 0)
      << "incorrect value for last_msg_.azel[0].sid.code, expected 0, is "
      << last_msg_.azel[0].sid.code;
  EXPECT_EQ(last_msg_.azel[0].sid.sat, 8)
      << "incorrect value for last_msg_.azel[0].sid.sat, expected 8, is "
      << last_msg_.azel[0].sid.sat;
  EXPECT_EQ(last_msg_.azel[1].az, 139)
      << "incorrect value for last_msg_.azel[1].az, expected 139, is "
      << last_msg_.azel[1].az;
  EXPECT_EQ(last_msg_.azel[1].el, 66)
      << "incorrect value for last_msg_.azel[1].el, expected 66, is "
      << last_msg_.azel[1].el;
  EXPECT_EQ(last_msg_.azel[1].sid.code, 0)
      << "incorrect value for last_msg_.azel[1].sid.code, expected 0, is "
      << last_msg_.azel[1].sid.code;
  EXPECT_EQ(last_msg_.azel[1].sid.sat, 10)
      << "incorrect value for last_msg_.azel[1].sid.sat, expected 10, is "
      << last_msg_.azel[1].sid.sat;
  EXPECT_EQ(last_msg_.azel[2].az, 16)
      << "incorrect value for last_msg_.azel[2].az, expected 16, is "
      << last_msg_.azel[2].az;
  EXPECT_EQ(last_msg_.azel[2].el, 1)
      << "incorrect value for last_msg_.azel[2].el, expected 1, is "
      << last_msg_.azel[2].el;
  EXPECT_EQ(last_msg_.azel[2].sid.code, 0)
      << "incorrect value for last_msg_.azel[2].sid.code, expected 0, is "
      << last_msg_.azel[2].sid.code;
  EXPECT_EQ(last_msg_.azel[2].sid.sat, 13)
      << "incorrect value for last_msg_.azel[2].sid.sat, expected 13, is "
      << last_msg_.azel[2].sid.sat;
  EXPECT_EQ(last_msg_.azel[3].az, 24)
      << "incorrect value for last_msg_.azel[3].az, expected 24, is "
      << last_msg_.azel[3].az;
  EXPECT_EQ(last_msg_.azel[3].el, 25)
      << "incorrect value for last_msg_.azel[3].el, expected 25, is "
      << last_msg_.azel[3].el;
  EXPECT_EQ(last_msg_.azel[3].sid.code, 0)
      << "incorrect value for last_msg_.azel[3].sid.code, expected 0, is "
      << last_msg_.azel[3].sid.code;
  EXPECT_EQ(last_msg_.azel[3].sid.sat, 15)
      << "incorrect value for last_msg_.azel[3].sid.sat, expected 15, is "
      << last_msg_.azel[3].sid.sat;
  EXPECT_EQ(last_msg_.azel[4].az, 127)
      << "incorrect value for last_msg_.azel[4].az, expected 127, is "
      << last_msg_.azel[4].az;
  EXPECT_EQ(last_msg_.azel[4].el, 18)
      << "incorrect value for last_msg_.azel[4].el, expected 18, is "
      << last_msg_.azel[4].el;
  EXPECT_EQ(last_msg_.azel[4].sid.code, 0)
      << "incorrect value for last_msg_.azel[4].sid.code, expected 0, is "
      << last_msg_.azel[4].sid.code;
  EXPECT_EQ(last_msg_.azel[4].sid.sat, 16)
      << "incorrect value for last_msg_.azel[4].sid.sat, expected 16, is "
      << last_msg_.azel[4].sid.sat;
  EXPECT_EQ(last_msg_.azel[5].az, 42)
      << "incorrect value for last_msg_.azel[5].az, expected 42, is "
      << last_msg_.azel[5].az;
  EXPECT_EQ(last_msg_.azel[5].el, 53)
      << "incorrect value for last_msg_.azel[5].el, expected 53, is "
      << last_msg_.azel[5].el;
  EXPECT_EQ(last_msg_.azel[5].sid.code, 0)
      << "incorrect value for last_msg_.azel[5].sid.code, expected 0, is "
      << last_msg_.azel[5].sid.code;
  EXPECT_EQ(last_msg_.azel[5].sid.sat, 18)
      << "incorrect value for last_msg_.azel[5].sid.sat, expected 18, is "
      << last_msg_.azel[5].sid.sat;
  EXPECT_EQ(last_msg_.azel[6].az, 31)
      << "incorrect value for last_msg_.azel[6].az, expected 31, is "
      << last_msg_.azel[6].az;
  EXPECT_EQ(last_msg_.azel[6].el, 16)
      << "incorrect value for last_msg_.azel[6].el, expected 16, is "
      << last_msg_.azel[6].el;
  EXPECT_EQ(last_msg_.azel[6].sid.code, 0)
      << "incorrect value for last_msg_.azel[6].sid.code, expected 0, is "
      << last_msg_.azel[6].sid.code;
  EXPECT_EQ(last_msg_.azel[6].sid.sat, 20)
      << "incorrect value for last_msg_.azel[6].sid.sat, expected 20, is "
      << last_msg_.azel[6].sid.sat;
  EXPECT_EQ(last_msg_.azel[7].az, 12)
      << "incorrect value for last_msg_.azel[7].az, expected 12, is "
      << last_msg_.azel[7].az;
  EXPECT_EQ(last_msg_.azel[7].el, 67)
      << "incorrect value for last_msg_.azel[7].el, expected 67, is "
      << last_msg_.azel[7].el;
  EXPECT_EQ(last_msg_.azel[7].sid.code, 0)
      << "incorrect value for last_msg_.azel[7].sid.code, expected 0, is "
      << last_msg_.azel[7].sid.code;
  EXPECT_EQ(last_msg_.azel[7].sid.sat, 23)
      << "incorrect value for last_msg_.azel[7].sid.sat, expected 23, is "
      << last_msg_.azel[7].sid.sat;
  EXPECT_EQ(last_msg_.azel[8].az, 47)
      << "incorrect value for last_msg_.azel[8].az, expected 47, is "
      << last_msg_.azel[8].az;
  EXPECT_EQ(last_msg_.azel[8].el, 10)
      << "incorrect value for last_msg_.azel[8].el, expected 10, is "
      << last_msg_.azel[8].el;
  EXPECT_EQ(last_msg_.azel[8].sid.code, 0)
      << "incorrect value for last_msg_.azel[8].sid.code, expected 0, is "
      << last_msg_.azel[8].sid.code;
  EXPECT_EQ(last_msg_.azel[8].sid.sat, 24)
      << "incorrect value for last_msg_.azel[8].sid.sat, expected 24, is "
      << last_msg_.azel[8].sid.sat;
  EXPECT_EQ(last_msg_.azel[9].az, 116)
      << "incorrect value for last_msg_.azel[9].az, expected 116, is "
      << last_msg_.azel[9].az;
  EXPECT_EQ(last_msg_.azel[9].el, 8)
      << "incorrect value for last_msg_.azel[9].el, expected 8, is "
      << last_msg_.azel[9].el;
  EXPECT_EQ(last_msg_.azel[9].sid.code, 0)
      << "incorrect value for last_msg_.azel[9].sid.code, expected 0, is "
      << last_msg_.azel[9].sid.code;
  EXPECT_EQ(last_msg_.azel[9].sid.sat, 26)
      << "incorrect value for last_msg_.azel[9].sid.sat, expected 26, is "
      << last_msg_.azel[9].sid.sat;
  EXPECT_EQ(last_msg_.azel[10].az, 153)
      << "incorrect value for last_msg_.azel[10].az, expected 153, is "
      << last_msg_.azel[10].az;
  EXPECT_EQ(last_msg_.azel[10].el, 43)
      << "incorrect value for last_msg_.azel[10].el, expected 43, is "
      << last_msg_.azel[10].el;
  EXPECT_EQ(last_msg_.azel[10].sid.code, 0)
      << "incorrect value for last_msg_.azel[10].sid.code, expected 0, is "
      << last_msg_.azel[10].sid.code;
  EXPECT_EQ(last_msg_.azel[10].sid.sat, 27)
      << "incorrect value for last_msg_.azel[10].sid.sat, expected 27, is "
      << last_msg_.azel[10].sid.sat;
  EXPECT_EQ(last_msg_.azel[11].az, 77)
      << "incorrect value for last_msg_.azel[11].az, expected 77, is "
      << last_msg_.azel[11].az;
  EXPECT_EQ(last_msg_.azel[11].el, 10)
      << "incorrect value for last_msg_.azel[11].el, expected 10, is "
      << last_msg_.azel[11].el;
  EXPECT_EQ(last_msg_.azel[11].sid.code, 0)
      << "incorrect value for last_msg_.azel[11].sid.code, expected 0, is "
      << last_msg_.azel[11].sid.code;
  EXPECT_EQ(last_msg_.azel[11].sid.sat, 29)
      << "incorrect value for last_msg_.azel[11].sid.sat, expected 29, is "
      << last_msg_.azel[11].sid.sat;
  EXPECT_EQ(last_msg_.azel[12].az, 94)
      << "incorrect value for last_msg_.azel[12].az, expected 94, is "
      << last_msg_.azel[12].az;
  EXPECT_EQ(last_msg_.azel[12].el, 26)
      << "incorrect value for last_msg_.azel[12].el, expected 26, is "
      << last_msg_.azel[12].el;
  EXPECT_EQ(last_msg_.azel[12].sid.code, 0)
      << "incorrect value for last_msg_.azel[12].sid.code, expected 0, is "
      << last_msg_.azel[12].sid.code;
  EXPECT_EQ(last_msg_.azel[12].sid.sat, 32)
      << "incorrect value for last_msg_.azel[12].sid.sat, expected 32, is "
      << last_msg_.azel[12].sid.sat;
  EXPECT_EQ(last_msg_.azel[13].az, 16)
      << "incorrect value for last_msg_.azel[13].az, expected 16, is "
      << last_msg_.azel[13].az;
  EXPECT_EQ(last_msg_.azel[13].el, 58)
      << "incorrect value for last_msg_.azel[13].el, expected 58, is "
      << last_msg_.azel[13].el;
  EXPECT_EQ(last_msg_.azel[13].sid.code, 3)
      << "incorrect value for last_msg_.azel[13].sid.code, expected 3, is "
      << last_msg_.azel[13].sid.code;
  EXPECT_EQ(last_msg_.azel[13].sid.sat, 1)
      << "incorrect value for last_msg_.azel[13].sid.sat, expected 1, is "
      << last_msg_.azel[13].sid.sat;
  EXPECT_EQ(last_msg_.azel[14].az, 108)
      << "incorrect value for last_msg_.azel[14].az, expected 108, is "
      << last_msg_.azel[14].az;
  EXPECT_EQ(last_msg_.azel[14].el, 53)
      << "incorrect value for last_msg_.azel[14].el, expected 53, is "
      << last_msg_.azel[14].el;
  EXPECT_EQ(last_msg_.azel[14].sid.code, 3)
      << "incorrect value for last_msg_.azel[14].sid.code, expected 3, is "
      << last_msg_.azel[14].sid.code;
  EXPECT_EQ(last_msg_.azel[14].sid.sat, 2)
      << "incorrect value for last_msg_.azel[14].sid.sat, expected 2, is "
      << last_msg_.azel[14].sid.sat;
  EXPECT_EQ(last_msg_.azel[15].az, 17)
      << "incorrect value for last_msg_.azel[15].az, expected 17, is "
      << last_msg_.azel[15].az;
  EXPECT_EQ(last_msg_.azel[15].el, 13)
      << "incorrect value for last_msg_.azel[15].el, expected 13, is "
      << last_msg_.azel[15].el;
  EXPECT_EQ(last_msg_.azel[15].sid.code, 3)
      << "incorrect value for last_msg_.azel[15].sid.code, expected 3, is "
      << last_msg_.azel[15].sid.code;
  EXPECT_EQ(last_msg_.azel[15].sid.sat, 8)
      << "incorrect value for last_msg_.azel[15].sid.sat, expected 8, is "
      << last_msg_.azel[15].sid.sat;
  EXPECT_EQ(last_msg_.azel[16].az, 165)
      << "incorrect value for last_msg_.azel[16].az, expected 165, is "
      << last_msg_.azel[16].az;
  EXPECT_EQ(last_msg_.azel[16].el, 40)
      << "incorrect value for last_msg_.azel[16].el, expected 40, is "
      << last_msg_.azel[16].el;
  EXPECT_EQ(last_msg_.azel[16].sid.code, 3)
      << "incorrect value for last_msg_.azel[16].sid.code, expected 3, is "
      << last_msg_.azel[16].sid.code;
  EXPECT_EQ(last_msg_.azel[16].sid.sat, 17)
      << "incorrect value for last_msg_.azel[16].sid.sat, expected 17, is "
      << last_msg_.azel[16].sid.sat;
  EXPECT_EQ(last_msg_.azel[17].az, 63)
      << "incorrect value for last_msg_.azel[17].az, expected 63, is "
      << last_msg_.azel[17].az;
  EXPECT_EQ(last_msg_.azel[17].el, 35)
      << "incorrect value for last_msg_.azel[17].el, expected 35, is "
      << last_msg_.azel[17].el;
  EXPECT_EQ(last_msg_.azel[17].sid.code, 3)
      << "incorrect value for last_msg_.azel[17].sid.code, expected 3, is "
      << last_msg_.azel[17].sid.code;
  EXPECT_EQ(last_msg_.azel[17].sid.sat, 23)
      << "incorrect value for last_msg_.azel[17].sid.sat, expected 23, is "
      << last_msg_.azel[17].sid.sat;
  EXPECT_EQ(last_msg_.azel[18].az, 41)
      << "incorrect value for last_msg_.azel[18].az, expected 41, is "
      << last_msg_.azel[18].az;
  EXPECT_EQ(last_msg_.azel[18].el, 73)
      << "incorrect value for last_msg_.azel[18].el, expected 73, is "
      << last_msg_.azel[18].el;
  EXPECT_EQ(last_msg_.azel[18].sid.code, 3)
      << "incorrect value for last_msg_.azel[18].sid.code, expected 3, is "
      << last_msg_.azel[18].sid.code;
  EXPECT_EQ(last_msg_.azel[18].sid.sat, 24)
      << "incorrect value for last_msg_.azel[18].sid.sat, expected 24, is "
      << last_msg_.azel[18].sid.sat;
  EXPECT_EQ(last_msg_.azel[19].az, 114)
      << "incorrect value for last_msg_.azel[19].az, expected 114, is "
      << last_msg_.azel[19].az;
  EXPECT_EQ(last_msg_.azel[19].el, 26)
      << "incorrect value for last_msg_.azel[19].el, expected 26, is "
      << last_msg_.azel[19].el;
  EXPECT_EQ(last_msg_.azel[19].sid.code, 12)
      << "incorrect value for last_msg_.azel[19].sid.code, expected 12, is "
      << last_msg_.azel[19].sid.code;
  EXPECT_EQ(last_msg_.azel[19].sid.sat, 20)
      << "incorrect value for last_msg_.azel[19].sid.sat, expected 20, is "
      << last_msg_.azel[19].sid.sat;
  EXPECT_EQ(last_msg_.azel[20].az, 72)
      << "incorrect value for last_msg_.azel[20].az, expected 72, is "
      << last_msg_.azel[20].az;
  EXPECT_EQ(last_msg_.azel[20].el, 54)
      << "incorrect value for last_msg_.azel[20].el, expected 54, is "
      << last_msg_.azel[20].el;
  EXPECT_EQ(last_msg_.azel[20].sid.code, 12)
      << "incorrect value for last_msg_.azel[20].sid.code, expected 12, is "
      << last_msg_.azel[20].sid.code;
  EXPECT_EQ(last_msg_.azel[20].sid.sat, 27)
      << "incorrect value for last_msg_.azel[20].sid.sat, expected 27, is "
      << last_msg_.azel[20].sid.sat;
  EXPECT_EQ(last_msg_.azel[21].az, 69)
      << "incorrect value for last_msg_.azel[21].az, expected 69, is "
      << last_msg_.azel[21].az;
  EXPECT_EQ(last_msg_.azel[21].el, 3)
      << "incorrect value for last_msg_.azel[21].el, expected 3, is "
      << last_msg_.azel[21].el;
  EXPECT_EQ(last_msg_.azel[21].sid.code, 12)
      << "incorrect value for last_msg_.azel[21].sid.code, expected 12, is "
      << last_msg_.azel[21].sid.code;
  EXPECT_EQ(last_msg_.azel[21].sid.sat, 28)
      << "incorrect value for last_msg_.azel[21].sid.sat, expected 28, is "
      << last_msg_.azel[21].sid.sat;
  EXPECT_EQ(last_msg_.azel[22].az, 158)
      << "incorrect value for last_msg_.azel[22].az, expected 158, is "
      << last_msg_.azel[22].az;
  EXPECT_EQ(last_msg_.azel[22].el, 14)
      << "incorrect value for last_msg_.azel[22].el, expected 14, is "
      << last_msg_.azel[22].el;
  EXPECT_EQ(last_msg_.azel[22].sid.code, 12)
      << "incorrect value for last_msg_.azel[22].sid.code, expected 12, is "
      << last_msg_.azel[22].sid.code;
  EXPECT_EQ(last_msg_.azel[22].sid.sat, 29)
      << "incorrect value for last_msg_.azel[22].sid.sat, expected 29, is "
      << last_msg_.azel[22].sid.sat;
  EXPECT_EQ(last_msg_.azel[23].az, 152)
      << "incorrect value for last_msg_.azel[23].az, expected 152, is "
      << last_msg_.azel[23].az;
  EXPECT_EQ(last_msg_.azel[23].el, 68)
      << "incorrect value for last_msg_.azel[23].el, expected 68, is "
      << last_msg_.azel[23].el;
  EXPECT_EQ(last_msg_.azel[23].sid.code, 12)
      << "incorrect value for last_msg_.azel[23].sid.code, expected 12, is "
      << last_msg_.azel[23].sid.code;
  EXPECT_EQ(last_msg_.azel[23].sid.sat, 30)
      << "incorrect value for last_msg_.azel[23].sid.sat, expected 30, is "
      << last_msg_.azel[23].sid.sat;
  EXPECT_EQ(last_msg_.azel[24].az, 120)
      << "incorrect value for last_msg_.azel[24].az, expected 120, is "
      << last_msg_.azel[24].az;
  EXPECT_EQ(last_msg_.azel[24].el, 82)
      << "incorrect value for last_msg_.azel[24].el, expected 82, is "
      << last_msg_.azel[24].el;
  EXPECT_EQ(last_msg_.azel[24].sid.code, 12)
      << "incorrect value for last_msg_.azel[24].sid.code, expected 12, is "
      << last_msg_.azel[24].sid.code;
  EXPECT_EQ(last_msg_.azel[24].sid.sat, 32)
      << "incorrect value for last_msg_.azel[24].sid.sat, expected 32, is "
      << last_msg_.azel[24].sid.sat;
  EXPECT_EQ(last_msg_.azel[25].az, 131)
      << "incorrect value for last_msg_.azel[25].az, expected 131, is "
      << last_msg_.azel[25].az;
  EXPECT_EQ(last_msg_.azel[25].el, 6)
      << "incorrect value for last_msg_.azel[25].el, expected 6, is "
      << last_msg_.azel[25].el;
  EXPECT_EQ(last_msg_.azel[25].sid.code, 14)
      << "incorrect value for last_msg_.azel[25].sid.code, expected 14, is "
      << last_msg_.azel[25].sid.code;
  EXPECT_EQ(last_msg_.azel[25].sid.sat, 2)
      << "incorrect value for last_msg_.azel[25].sid.sat, expected 2, is "
      << last_msg_.azel[25].sid.sat;
  EXPECT_EQ(last_msg_.azel[26].az, 27)
      << "incorrect value for last_msg_.azel[26].az, expected 27, is "
      << last_msg_.azel[26].az;
  EXPECT_EQ(last_msg_.azel[26].el, 44)
      << "incorrect value for last_msg_.azel[26].el, expected 44, is "
      << last_msg_.azel[26].el;
  EXPECT_EQ(last_msg_.azel[26].sid.code, 14)
      << "incorrect value for last_msg_.azel[26].sid.code, expected 14, is "
      << last_msg_.azel[26].sid.code;
  EXPECT_EQ(last_msg_.azel[26].sid.sat, 4)
      << "incorrect value for last_msg_.azel[26].sid.sat, expected 4, is "
      << last_msg_.azel[26].sid.sat;
  EXPECT_EQ(last_msg_.azel[27].az, 101)
      << "incorrect value for last_msg_.azel[27].az, expected 101, is "
      << last_msg_.azel[27].az;
  EXPECT_EQ(last_msg_.azel[27].el, 21)
      << "incorrect value for last_msg_.azel[27].el, expected 21, is "
      << last_msg_.azel[27].el;
  EXPECT_EQ(last_msg_.azel[27].sid.code, 14)
      << "incorrect value for last_msg_.azel[27].sid.code, expected 14, is "
      << last_msg_.azel[27].sid.code;
  EXPECT_EQ(last_msg_.azel[27].sid.sat, 5)
      << "incorrect value for last_msg_.azel[27].sid.sat, expected 5, is "
      << last_msg_.azel[27].sid.sat;
  EXPECT_EQ(last_msg_.azel[28].az, 81)
      << "incorrect value for last_msg_.azel[28].az, expected 81, is "
      << last_msg_.azel[28].az;
  EXPECT_EQ(last_msg_.azel[28].el, 65)
      << "incorrect value for last_msg_.azel[28].el, expected 65, is "
      << last_msg_.azel[28].el;
  EXPECT_EQ(last_msg_.azel[28].sid.code, 14)
      << "incorrect value for last_msg_.azel[28].sid.code, expected 14, is "
      << last_msg_.azel[28].sid.code;
  EXPECT_EQ(last_msg_.azel[28].sid.sat, 9)
      << "incorrect value for last_msg_.azel[28].sid.sat, expected 9, is "
      << last_msg_.azel[28].sid.sat;
  EXPECT_EQ(last_msg_.azel[29].az, 49)
      << "incorrect value for last_msg_.azel[29].az, expected 49, is "
      << last_msg_.azel[29].az;
  EXPECT_EQ(last_msg_.azel[29].el, 56)
      << "incorrect value for last_msg_.azel[29].el, expected 56, is "
      << last_msg_.azel[29].el;
  EXPECT_EQ(last_msg_.azel[29].sid.code, 14)
      << "incorrect value for last_msg_.azel[29].sid.code, expected 14, is "
      << last_msg_.azel[29].sid.code;
  EXPECT_EQ(last_msg_.azel[29].sid.sat, 11)
      << "incorrect value for last_msg_.azel[29].sid.sat, expected 11, is "
      << last_msg_.azel[29].sid.sat;
  EXPECT_EQ(last_msg_.azel[30].az, 59)
      << "incorrect value for last_msg_.azel[30].az, expected 59, is "
      << last_msg_.azel[30].az;
  EXPECT_EQ(last_msg_.azel[30].el, 6)
      << "incorrect value for last_msg_.azel[30].el, expected 6, is "
      << last_msg_.azel[30].el;
  EXPECT_EQ(last_msg_.azel[30].sid.code, 14)
      << "incorrect value for last_msg_.azel[30].sid.code, expected 14, is "
      << last_msg_.azel[30].sid.code;
  EXPECT_EQ(last_msg_.azel[30].sid.sat, 12)
      << "incorrect value for last_msg_.azel[30].sid.sat, expected 12, is "
      << last_msg_.azel[30].sid.sat;
  EXPECT_EQ(last_msg_.azel[31].az, 154)
      << "incorrect value for last_msg_.azel[31].az, expected 154, is "
      << last_msg_.azel[31].az;
  EXPECT_EQ(last_msg_.azel[31].el, 4)
      << "incorrect value for last_msg_.azel[31].el, expected 4, is "
      << last_msg_.azel[31].el;
  EXPECT_EQ(last_msg_.azel[31].sid.code, 14)
      << "incorrect value for last_msg_.azel[31].sid.code, expected 14, is "
      << last_msg_.azel[31].sid.code;
  EXPECT_EQ(last_msg_.azel[31].sid.sat, 30)
      << "incorrect value for last_msg_.azel[31].sid.sat, expected 30, is "
      << last_msg_.azel[31].sid.sat;
  EXPECT_EQ(last_msg_.azel[32].az, 165)
      << "incorrect value for last_msg_.azel[32].az, expected 165, is "
      << last_msg_.azel[32].az;
  EXPECT_EQ(last_msg_.azel[32].el, 62)
      << "incorrect value for last_msg_.azel[32].el, expected 62, is "
      << last_msg_.azel[32].el;
  EXPECT_EQ(last_msg_.azel[32].sid.code, 14)
      << "incorrect value for last_msg_.azel[32].sid.code, expected 14, is "
      << last_msg_.azel[32].sid.code;
  EXPECT_EQ(last_msg_.azel[32].sid.sat, 36)
      << "incorrect value for last_msg_.azel[32].sid.sat, expected 36, is "
      << last_msg_.azel[32].sid.sat;
  EXPECT_EQ(last_msg_.n_azel, 33)
      << "incorrect value for last_msg_.n_azel, expected 33, is "
      << last_msg_.n_azel;
}
