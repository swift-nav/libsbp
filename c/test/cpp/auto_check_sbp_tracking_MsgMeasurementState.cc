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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgMeasurementState.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_tracking_MsgMeasurementState0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_measurement_state_t> {
 public:
  Test_auto_check_sbp_tracking_MsgMeasurementState0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_measurement_state_t>(this),
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
                      const sbp_msg_measurement_state_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_measurement_state_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgMeasurementState0, Test) {
  uint8_t encoded_frame[] = {
      85,  97, 0,   207, 121, 237, 29,  0,  162, 0,   0,  0,   0,   0,  0,
      27,  0,  201, 20,  0,   168, 32,  0,  184, 15,  0,  187, 0,   0,  0,
      18,  0,  210, 16,  0,   167, 0,   0,  0,   23,  0,  213, 10,  0,  223,
      0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   131, 2,  202,
      27,  1,  192, 15,  1,   165, 29,  1,  146, 32,  1,  170, 18,  1,  201,
      0,   0,  0,   0,   0,   0,   0,   0,  0,   23,  1,  212, 10,  1,  205,
      0,   0,  0,   96,  3,   230, 0,   0,  0,   101, 3,  214, 103, 3,  212,
      104, 3,  209, 106, 3,   157, 102, 3,  230, 0,   0,  0,   0,   0,  0,
      101, 4,  189, 96,  4,   207, 106, 4,  164, 104, 4,  193, 0,   0,  0,
      102, 4,  208, 0,   0,   0,   27,  12, 212, 29,  12, 161, 32,  12, 216,
      30,  12, 216, 20,  12,  178, 0,   0,  0,   0,   0,  0,   0,   0,  0,
      0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   0,   0,  0,
      0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   0,   0,  0,
      36,  14, 203, 0,   0,   0,   5,   14, 158, 4,   14, 194, 11,  14, 192,
      9,   14, 207, 0,   0,   0,   0,   0,  0,   0,   0,  0,   9,   20, 218,
      5,   20, 176, 36,  20,  217, 11,  20, 200, 4,   20, 205, 0,   0,  0,
      0,   0,  0,   35,  54,
  };

  sbp_msg_measurement_state_t test_msg{};
  test_msg.n_states = 79;

  test_msg.states[0].cn0 = 162;
  test_msg.states[0].mesid.code = 0;
  test_msg.states[0].mesid.sat = 29;

  test_msg.states[1].cn0 = 0;
  test_msg.states[1].mesid.code = 0;
  test_msg.states[1].mesid.sat = 0;

  test_msg.states[2].cn0 = 0;
  test_msg.states[2].mesid.code = 0;
  test_msg.states[2].mesid.sat = 0;

  test_msg.states[3].cn0 = 201;
  test_msg.states[3].mesid.code = 0;
  test_msg.states[3].mesid.sat = 27;

  test_msg.states[4].cn0 = 168;
  test_msg.states[4].mesid.code = 0;
  test_msg.states[4].mesid.sat = 20;

  test_msg.states[5].cn0 = 184;
  test_msg.states[5].mesid.code = 0;
  test_msg.states[5].mesid.sat = 32;

  test_msg.states[6].cn0 = 187;
  test_msg.states[6].mesid.code = 0;
  test_msg.states[6].mesid.sat = 15;

  test_msg.states[7].cn0 = 0;
  test_msg.states[7].mesid.code = 0;
  test_msg.states[7].mesid.sat = 0;

  test_msg.states[8].cn0 = 210;
  test_msg.states[8].mesid.code = 0;
  test_msg.states[8].mesid.sat = 18;

  test_msg.states[9].cn0 = 167;
  test_msg.states[9].mesid.code = 0;
  test_msg.states[9].mesid.sat = 16;

  test_msg.states[10].cn0 = 0;
  test_msg.states[10].mesid.code = 0;
  test_msg.states[10].mesid.sat = 0;

  test_msg.states[11].cn0 = 213;
  test_msg.states[11].mesid.code = 0;
  test_msg.states[11].mesid.sat = 23;

  test_msg.states[12].cn0 = 223;
  test_msg.states[12].mesid.code = 0;
  test_msg.states[12].mesid.sat = 10;

  test_msg.states[13].cn0 = 0;
  test_msg.states[13].mesid.code = 0;
  test_msg.states[13].mesid.sat = 0;

  test_msg.states[14].cn0 = 0;
  test_msg.states[14].mesid.code = 0;
  test_msg.states[14].mesid.sat = 0;

  test_msg.states[15].cn0 = 0;
  test_msg.states[15].mesid.code = 0;
  test_msg.states[15].mesid.sat = 0;

  test_msg.states[16].cn0 = 0;
  test_msg.states[16].mesid.code = 0;
  test_msg.states[16].mesid.sat = 0;

  test_msg.states[17].cn0 = 202;
  test_msg.states[17].mesid.code = 2;
  test_msg.states[17].mesid.sat = 131;

  test_msg.states[18].cn0 = 192;
  test_msg.states[18].mesid.code = 1;
  test_msg.states[18].mesid.sat = 27;

  test_msg.states[19].cn0 = 165;
  test_msg.states[19].mesid.code = 1;
  test_msg.states[19].mesid.sat = 15;

  test_msg.states[20].cn0 = 146;
  test_msg.states[20].mesid.code = 1;
  test_msg.states[20].mesid.sat = 29;

  test_msg.states[21].cn0 = 170;
  test_msg.states[21].mesid.code = 1;
  test_msg.states[21].mesid.sat = 32;

  test_msg.states[22].cn0 = 201;
  test_msg.states[22].mesid.code = 1;
  test_msg.states[22].mesid.sat = 18;

  test_msg.states[23].cn0 = 0;
  test_msg.states[23].mesid.code = 0;
  test_msg.states[23].mesid.sat = 0;

  test_msg.states[24].cn0 = 0;
  test_msg.states[24].mesid.code = 0;
  test_msg.states[24].mesid.sat = 0;

  test_msg.states[25].cn0 = 0;
  test_msg.states[25].mesid.code = 0;
  test_msg.states[25].mesid.sat = 0;

  test_msg.states[26].cn0 = 212;
  test_msg.states[26].mesid.code = 1;
  test_msg.states[26].mesid.sat = 23;

  test_msg.states[27].cn0 = 205;
  test_msg.states[27].mesid.code = 1;
  test_msg.states[27].mesid.sat = 10;

  test_msg.states[28].cn0 = 0;
  test_msg.states[28].mesid.code = 0;
  test_msg.states[28].mesid.sat = 0;

  test_msg.states[29].cn0 = 230;
  test_msg.states[29].mesid.code = 3;
  test_msg.states[29].mesid.sat = 96;

  test_msg.states[30].cn0 = 0;
  test_msg.states[30].mesid.code = 0;
  test_msg.states[30].mesid.sat = 0;

  test_msg.states[31].cn0 = 214;
  test_msg.states[31].mesid.code = 3;
  test_msg.states[31].mesid.sat = 101;

  test_msg.states[32].cn0 = 212;
  test_msg.states[32].mesid.code = 3;
  test_msg.states[32].mesid.sat = 103;

  test_msg.states[33].cn0 = 209;
  test_msg.states[33].mesid.code = 3;
  test_msg.states[33].mesid.sat = 104;

  test_msg.states[34].cn0 = 157;
  test_msg.states[34].mesid.code = 3;
  test_msg.states[34].mesid.sat = 106;

  test_msg.states[35].cn0 = 230;
  test_msg.states[35].mesid.code = 3;
  test_msg.states[35].mesid.sat = 102;

  test_msg.states[36].cn0 = 0;
  test_msg.states[36].mesid.code = 0;
  test_msg.states[36].mesid.sat = 0;

  test_msg.states[37].cn0 = 0;
  test_msg.states[37].mesid.code = 0;
  test_msg.states[37].mesid.sat = 0;

  test_msg.states[38].cn0 = 189;
  test_msg.states[38].mesid.code = 4;
  test_msg.states[38].mesid.sat = 101;

  test_msg.states[39].cn0 = 207;
  test_msg.states[39].mesid.code = 4;
  test_msg.states[39].mesid.sat = 96;

  test_msg.states[40].cn0 = 164;
  test_msg.states[40].mesid.code = 4;
  test_msg.states[40].mesid.sat = 106;

  test_msg.states[41].cn0 = 193;
  test_msg.states[41].mesid.code = 4;
  test_msg.states[41].mesid.sat = 104;

  test_msg.states[42].cn0 = 0;
  test_msg.states[42].mesid.code = 0;
  test_msg.states[42].mesid.sat = 0;

  test_msg.states[43].cn0 = 208;
  test_msg.states[43].mesid.code = 4;
  test_msg.states[43].mesid.sat = 102;

  test_msg.states[44].cn0 = 0;
  test_msg.states[44].mesid.code = 0;
  test_msg.states[44].mesid.sat = 0;

  test_msg.states[45].cn0 = 212;
  test_msg.states[45].mesid.code = 12;
  test_msg.states[45].mesid.sat = 27;

  test_msg.states[46].cn0 = 161;
  test_msg.states[46].mesid.code = 12;
  test_msg.states[46].mesid.sat = 29;

  test_msg.states[47].cn0 = 216;
  test_msg.states[47].mesid.code = 12;
  test_msg.states[47].mesid.sat = 32;

  test_msg.states[48].cn0 = 216;
  test_msg.states[48].mesid.code = 12;
  test_msg.states[48].mesid.sat = 30;

  test_msg.states[49].cn0 = 178;
  test_msg.states[49].mesid.code = 12;
  test_msg.states[49].mesid.sat = 20;

  test_msg.states[50].cn0 = 0;
  test_msg.states[50].mesid.code = 0;
  test_msg.states[50].mesid.sat = 0;

  test_msg.states[51].cn0 = 0;
  test_msg.states[51].mesid.code = 0;
  test_msg.states[51].mesid.sat = 0;

  test_msg.states[52].cn0 = 0;
  test_msg.states[52].mesid.code = 0;
  test_msg.states[52].mesid.sat = 0;

  test_msg.states[53].cn0 = 0;
  test_msg.states[53].mesid.code = 0;
  test_msg.states[53].mesid.sat = 0;

  test_msg.states[54].cn0 = 0;
  test_msg.states[54].mesid.code = 0;
  test_msg.states[54].mesid.sat = 0;

  test_msg.states[55].cn0 = 0;
  test_msg.states[55].mesid.code = 0;
  test_msg.states[55].mesid.sat = 0;

  test_msg.states[56].cn0 = 0;
  test_msg.states[56].mesid.code = 0;
  test_msg.states[56].mesid.sat = 0;

  test_msg.states[57].cn0 = 0;
  test_msg.states[57].mesid.code = 0;
  test_msg.states[57].mesid.sat = 0;

  test_msg.states[58].cn0 = 0;
  test_msg.states[58].mesid.code = 0;
  test_msg.states[58].mesid.sat = 0;

  test_msg.states[59].cn0 = 0;
  test_msg.states[59].mesid.code = 0;
  test_msg.states[59].mesid.sat = 0;

  test_msg.states[60].cn0 = 0;
  test_msg.states[60].mesid.code = 0;
  test_msg.states[60].mesid.sat = 0;

  test_msg.states[61].cn0 = 0;
  test_msg.states[61].mesid.code = 0;
  test_msg.states[61].mesid.sat = 0;

  test_msg.states[62].cn0 = 0;
  test_msg.states[62].mesid.code = 0;
  test_msg.states[62].mesid.sat = 0;

  test_msg.states[63].cn0 = 203;
  test_msg.states[63].mesid.code = 14;
  test_msg.states[63].mesid.sat = 36;

  test_msg.states[64].cn0 = 0;
  test_msg.states[64].mesid.code = 0;
  test_msg.states[64].mesid.sat = 0;

  test_msg.states[65].cn0 = 158;
  test_msg.states[65].mesid.code = 14;
  test_msg.states[65].mesid.sat = 5;

  test_msg.states[66].cn0 = 194;
  test_msg.states[66].mesid.code = 14;
  test_msg.states[66].mesid.sat = 4;

  test_msg.states[67].cn0 = 192;
  test_msg.states[67].mesid.code = 14;
  test_msg.states[67].mesid.sat = 11;

  test_msg.states[68].cn0 = 207;
  test_msg.states[68].mesid.code = 14;
  test_msg.states[68].mesid.sat = 9;

  test_msg.states[69].cn0 = 0;
  test_msg.states[69].mesid.code = 0;
  test_msg.states[69].mesid.sat = 0;

  test_msg.states[70].cn0 = 0;
  test_msg.states[70].mesid.code = 0;
  test_msg.states[70].mesid.sat = 0;

  test_msg.states[71].cn0 = 0;
  test_msg.states[71].mesid.code = 0;
  test_msg.states[71].mesid.sat = 0;

  test_msg.states[72].cn0 = 218;
  test_msg.states[72].mesid.code = 20;
  test_msg.states[72].mesid.sat = 9;

  test_msg.states[73].cn0 = 176;
  test_msg.states[73].mesid.code = 20;
  test_msg.states[73].mesid.sat = 5;

  test_msg.states[74].cn0 = 217;
  test_msg.states[74].mesid.code = 20;
  test_msg.states[74].mesid.sat = 36;

  test_msg.states[75].cn0 = 200;
  test_msg.states[75].mesid.code = 20;
  test_msg.states[75].mesid.sat = 11;

  test_msg.states[76].cn0 = 205;
  test_msg.states[76].mesid.code = 20;
  test_msg.states[76].mesid.sat = 4;

  test_msg.states[77].cn0 = 0;
  test_msg.states[77].mesid.code = 0;
  test_msg.states[77].mesid.sat = 0;

  test_msg.states[78].cn0 = 0;
  test_msg.states[78].mesid.code = 0;
  test_msg.states[78].mesid.sat = 0;

  EXPECT_EQ(send_message(31183, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 31183);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.n_states, 79)
      << "incorrect value for last_msg_.n_states, expected 79, is "
      << last_msg_.n_states;
  EXPECT_EQ(last_msg_.states[0].cn0, 162)
      << "incorrect value for last_msg_.states[0].cn0, expected 162, is "
      << last_msg_.states[0].cn0;
  EXPECT_EQ(last_msg_.states[0].mesid.code, 0)
      << "incorrect value for last_msg_.states[0].mesid.code, expected 0, is "
      << last_msg_.states[0].mesid.code;
  EXPECT_EQ(last_msg_.states[0].mesid.sat, 29)
      << "incorrect value for last_msg_.states[0].mesid.sat, expected 29, is "
      << last_msg_.states[0].mesid.sat;
  EXPECT_EQ(last_msg_.states[1].cn0, 0)
      << "incorrect value for last_msg_.states[1].cn0, expected 0, is "
      << last_msg_.states[1].cn0;
  EXPECT_EQ(last_msg_.states[1].mesid.code, 0)
      << "incorrect value for last_msg_.states[1].mesid.code, expected 0, is "
      << last_msg_.states[1].mesid.code;
  EXPECT_EQ(last_msg_.states[1].mesid.sat, 0)
      << "incorrect value for last_msg_.states[1].mesid.sat, expected 0, is "
      << last_msg_.states[1].mesid.sat;
  EXPECT_EQ(last_msg_.states[2].cn0, 0)
      << "incorrect value for last_msg_.states[2].cn0, expected 0, is "
      << last_msg_.states[2].cn0;
  EXPECT_EQ(last_msg_.states[2].mesid.code, 0)
      << "incorrect value for last_msg_.states[2].mesid.code, expected 0, is "
      << last_msg_.states[2].mesid.code;
  EXPECT_EQ(last_msg_.states[2].mesid.sat, 0)
      << "incorrect value for last_msg_.states[2].mesid.sat, expected 0, is "
      << last_msg_.states[2].mesid.sat;
  EXPECT_EQ(last_msg_.states[3].cn0, 201)
      << "incorrect value for last_msg_.states[3].cn0, expected 201, is "
      << last_msg_.states[3].cn0;
  EXPECT_EQ(last_msg_.states[3].mesid.code, 0)
      << "incorrect value for last_msg_.states[3].mesid.code, expected 0, is "
      << last_msg_.states[3].mesid.code;
  EXPECT_EQ(last_msg_.states[3].mesid.sat, 27)
      << "incorrect value for last_msg_.states[3].mesid.sat, expected 27, is "
      << last_msg_.states[3].mesid.sat;
  EXPECT_EQ(last_msg_.states[4].cn0, 168)
      << "incorrect value for last_msg_.states[4].cn0, expected 168, is "
      << last_msg_.states[4].cn0;
  EXPECT_EQ(last_msg_.states[4].mesid.code, 0)
      << "incorrect value for last_msg_.states[4].mesid.code, expected 0, is "
      << last_msg_.states[4].mesid.code;
  EXPECT_EQ(last_msg_.states[4].mesid.sat, 20)
      << "incorrect value for last_msg_.states[4].mesid.sat, expected 20, is "
      << last_msg_.states[4].mesid.sat;
  EXPECT_EQ(last_msg_.states[5].cn0, 184)
      << "incorrect value for last_msg_.states[5].cn0, expected 184, is "
      << last_msg_.states[5].cn0;
  EXPECT_EQ(last_msg_.states[5].mesid.code, 0)
      << "incorrect value for last_msg_.states[5].mesid.code, expected 0, is "
      << last_msg_.states[5].mesid.code;
  EXPECT_EQ(last_msg_.states[5].mesid.sat, 32)
      << "incorrect value for last_msg_.states[5].mesid.sat, expected 32, is "
      << last_msg_.states[5].mesid.sat;
  EXPECT_EQ(last_msg_.states[6].cn0, 187)
      << "incorrect value for last_msg_.states[6].cn0, expected 187, is "
      << last_msg_.states[6].cn0;
  EXPECT_EQ(last_msg_.states[6].mesid.code, 0)
      << "incorrect value for last_msg_.states[6].mesid.code, expected 0, is "
      << last_msg_.states[6].mesid.code;
  EXPECT_EQ(last_msg_.states[6].mesid.sat, 15)
      << "incorrect value for last_msg_.states[6].mesid.sat, expected 15, is "
      << last_msg_.states[6].mesid.sat;
  EXPECT_EQ(last_msg_.states[7].cn0, 0)
      << "incorrect value for last_msg_.states[7].cn0, expected 0, is "
      << last_msg_.states[7].cn0;
  EXPECT_EQ(last_msg_.states[7].mesid.code, 0)
      << "incorrect value for last_msg_.states[7].mesid.code, expected 0, is "
      << last_msg_.states[7].mesid.code;
  EXPECT_EQ(last_msg_.states[7].mesid.sat, 0)
      << "incorrect value for last_msg_.states[7].mesid.sat, expected 0, is "
      << last_msg_.states[7].mesid.sat;
  EXPECT_EQ(last_msg_.states[8].cn0, 210)
      << "incorrect value for last_msg_.states[8].cn0, expected 210, is "
      << last_msg_.states[8].cn0;
  EXPECT_EQ(last_msg_.states[8].mesid.code, 0)
      << "incorrect value for last_msg_.states[8].mesid.code, expected 0, is "
      << last_msg_.states[8].mesid.code;
  EXPECT_EQ(last_msg_.states[8].mesid.sat, 18)
      << "incorrect value for last_msg_.states[8].mesid.sat, expected 18, is "
      << last_msg_.states[8].mesid.sat;
  EXPECT_EQ(last_msg_.states[9].cn0, 167)
      << "incorrect value for last_msg_.states[9].cn0, expected 167, is "
      << last_msg_.states[9].cn0;
  EXPECT_EQ(last_msg_.states[9].mesid.code, 0)
      << "incorrect value for last_msg_.states[9].mesid.code, expected 0, is "
      << last_msg_.states[9].mesid.code;
  EXPECT_EQ(last_msg_.states[9].mesid.sat, 16)
      << "incorrect value for last_msg_.states[9].mesid.sat, expected 16, is "
      << last_msg_.states[9].mesid.sat;
  EXPECT_EQ(last_msg_.states[10].cn0, 0)
      << "incorrect value for last_msg_.states[10].cn0, expected 0, is "
      << last_msg_.states[10].cn0;
  EXPECT_EQ(last_msg_.states[10].mesid.code, 0)
      << "incorrect value for last_msg_.states[10].mesid.code, expected 0, is "
      << last_msg_.states[10].mesid.code;
  EXPECT_EQ(last_msg_.states[10].mesid.sat, 0)
      << "incorrect value for last_msg_.states[10].mesid.sat, expected 0, is "
      << last_msg_.states[10].mesid.sat;
  EXPECT_EQ(last_msg_.states[11].cn0, 213)
      << "incorrect value for last_msg_.states[11].cn0, expected 213, is "
      << last_msg_.states[11].cn0;
  EXPECT_EQ(last_msg_.states[11].mesid.code, 0)
      << "incorrect value for last_msg_.states[11].mesid.code, expected 0, is "
      << last_msg_.states[11].mesid.code;
  EXPECT_EQ(last_msg_.states[11].mesid.sat, 23)
      << "incorrect value for last_msg_.states[11].mesid.sat, expected 23, is "
      << last_msg_.states[11].mesid.sat;
  EXPECT_EQ(last_msg_.states[12].cn0, 223)
      << "incorrect value for last_msg_.states[12].cn0, expected 223, is "
      << last_msg_.states[12].cn0;
  EXPECT_EQ(last_msg_.states[12].mesid.code, 0)
      << "incorrect value for last_msg_.states[12].mesid.code, expected 0, is "
      << last_msg_.states[12].mesid.code;
  EXPECT_EQ(last_msg_.states[12].mesid.sat, 10)
      << "incorrect value for last_msg_.states[12].mesid.sat, expected 10, is "
      << last_msg_.states[12].mesid.sat;
  EXPECT_EQ(last_msg_.states[13].cn0, 0)
      << "incorrect value for last_msg_.states[13].cn0, expected 0, is "
      << last_msg_.states[13].cn0;
  EXPECT_EQ(last_msg_.states[13].mesid.code, 0)
      << "incorrect value for last_msg_.states[13].mesid.code, expected 0, is "
      << last_msg_.states[13].mesid.code;
  EXPECT_EQ(last_msg_.states[13].mesid.sat, 0)
      << "incorrect value for last_msg_.states[13].mesid.sat, expected 0, is "
      << last_msg_.states[13].mesid.sat;
  EXPECT_EQ(last_msg_.states[14].cn0, 0)
      << "incorrect value for last_msg_.states[14].cn0, expected 0, is "
      << last_msg_.states[14].cn0;
  EXPECT_EQ(last_msg_.states[14].mesid.code, 0)
      << "incorrect value for last_msg_.states[14].mesid.code, expected 0, is "
      << last_msg_.states[14].mesid.code;
  EXPECT_EQ(last_msg_.states[14].mesid.sat, 0)
      << "incorrect value for last_msg_.states[14].mesid.sat, expected 0, is "
      << last_msg_.states[14].mesid.sat;
  EXPECT_EQ(last_msg_.states[15].cn0, 0)
      << "incorrect value for last_msg_.states[15].cn0, expected 0, is "
      << last_msg_.states[15].cn0;
  EXPECT_EQ(last_msg_.states[15].mesid.code, 0)
      << "incorrect value for last_msg_.states[15].mesid.code, expected 0, is "
      << last_msg_.states[15].mesid.code;
  EXPECT_EQ(last_msg_.states[15].mesid.sat, 0)
      << "incorrect value for last_msg_.states[15].mesid.sat, expected 0, is "
      << last_msg_.states[15].mesid.sat;
  EXPECT_EQ(last_msg_.states[16].cn0, 0)
      << "incorrect value for last_msg_.states[16].cn0, expected 0, is "
      << last_msg_.states[16].cn0;
  EXPECT_EQ(last_msg_.states[16].mesid.code, 0)
      << "incorrect value for last_msg_.states[16].mesid.code, expected 0, is "
      << last_msg_.states[16].mesid.code;
  EXPECT_EQ(last_msg_.states[16].mesid.sat, 0)
      << "incorrect value for last_msg_.states[16].mesid.sat, expected 0, is "
      << last_msg_.states[16].mesid.sat;
  EXPECT_EQ(last_msg_.states[17].cn0, 202)
      << "incorrect value for last_msg_.states[17].cn0, expected 202, is "
      << last_msg_.states[17].cn0;
  EXPECT_EQ(last_msg_.states[17].mesid.code, 2)
      << "incorrect value for last_msg_.states[17].mesid.code, expected 2, is "
      << last_msg_.states[17].mesid.code;
  EXPECT_EQ(last_msg_.states[17].mesid.sat, 131)
      << "incorrect value for last_msg_.states[17].mesid.sat, expected 131, is "
      << last_msg_.states[17].mesid.sat;
  EXPECT_EQ(last_msg_.states[18].cn0, 192)
      << "incorrect value for last_msg_.states[18].cn0, expected 192, is "
      << last_msg_.states[18].cn0;
  EXPECT_EQ(last_msg_.states[18].mesid.code, 1)
      << "incorrect value for last_msg_.states[18].mesid.code, expected 1, is "
      << last_msg_.states[18].mesid.code;
  EXPECT_EQ(last_msg_.states[18].mesid.sat, 27)
      << "incorrect value for last_msg_.states[18].mesid.sat, expected 27, is "
      << last_msg_.states[18].mesid.sat;
  EXPECT_EQ(last_msg_.states[19].cn0, 165)
      << "incorrect value for last_msg_.states[19].cn0, expected 165, is "
      << last_msg_.states[19].cn0;
  EXPECT_EQ(last_msg_.states[19].mesid.code, 1)
      << "incorrect value for last_msg_.states[19].mesid.code, expected 1, is "
      << last_msg_.states[19].mesid.code;
  EXPECT_EQ(last_msg_.states[19].mesid.sat, 15)
      << "incorrect value for last_msg_.states[19].mesid.sat, expected 15, is "
      << last_msg_.states[19].mesid.sat;
  EXPECT_EQ(last_msg_.states[20].cn0, 146)
      << "incorrect value for last_msg_.states[20].cn0, expected 146, is "
      << last_msg_.states[20].cn0;
  EXPECT_EQ(last_msg_.states[20].mesid.code, 1)
      << "incorrect value for last_msg_.states[20].mesid.code, expected 1, is "
      << last_msg_.states[20].mesid.code;
  EXPECT_EQ(last_msg_.states[20].mesid.sat, 29)
      << "incorrect value for last_msg_.states[20].mesid.sat, expected 29, is "
      << last_msg_.states[20].mesid.sat;
  EXPECT_EQ(last_msg_.states[21].cn0, 170)
      << "incorrect value for last_msg_.states[21].cn0, expected 170, is "
      << last_msg_.states[21].cn0;
  EXPECT_EQ(last_msg_.states[21].mesid.code, 1)
      << "incorrect value for last_msg_.states[21].mesid.code, expected 1, is "
      << last_msg_.states[21].mesid.code;
  EXPECT_EQ(last_msg_.states[21].mesid.sat, 32)
      << "incorrect value for last_msg_.states[21].mesid.sat, expected 32, is "
      << last_msg_.states[21].mesid.sat;
  EXPECT_EQ(last_msg_.states[22].cn0, 201)
      << "incorrect value for last_msg_.states[22].cn0, expected 201, is "
      << last_msg_.states[22].cn0;
  EXPECT_EQ(last_msg_.states[22].mesid.code, 1)
      << "incorrect value for last_msg_.states[22].mesid.code, expected 1, is "
      << last_msg_.states[22].mesid.code;
  EXPECT_EQ(last_msg_.states[22].mesid.sat, 18)
      << "incorrect value for last_msg_.states[22].mesid.sat, expected 18, is "
      << last_msg_.states[22].mesid.sat;
  EXPECT_EQ(last_msg_.states[23].cn0, 0)
      << "incorrect value for last_msg_.states[23].cn0, expected 0, is "
      << last_msg_.states[23].cn0;
  EXPECT_EQ(last_msg_.states[23].mesid.code, 0)
      << "incorrect value for last_msg_.states[23].mesid.code, expected 0, is "
      << last_msg_.states[23].mesid.code;
  EXPECT_EQ(last_msg_.states[23].mesid.sat, 0)
      << "incorrect value for last_msg_.states[23].mesid.sat, expected 0, is "
      << last_msg_.states[23].mesid.sat;
  EXPECT_EQ(last_msg_.states[24].cn0, 0)
      << "incorrect value for last_msg_.states[24].cn0, expected 0, is "
      << last_msg_.states[24].cn0;
  EXPECT_EQ(last_msg_.states[24].mesid.code, 0)
      << "incorrect value for last_msg_.states[24].mesid.code, expected 0, is "
      << last_msg_.states[24].mesid.code;
  EXPECT_EQ(last_msg_.states[24].mesid.sat, 0)
      << "incorrect value for last_msg_.states[24].mesid.sat, expected 0, is "
      << last_msg_.states[24].mesid.sat;
  EXPECT_EQ(last_msg_.states[25].cn0, 0)
      << "incorrect value for last_msg_.states[25].cn0, expected 0, is "
      << last_msg_.states[25].cn0;
  EXPECT_EQ(last_msg_.states[25].mesid.code, 0)
      << "incorrect value for last_msg_.states[25].mesid.code, expected 0, is "
      << last_msg_.states[25].mesid.code;
  EXPECT_EQ(last_msg_.states[25].mesid.sat, 0)
      << "incorrect value for last_msg_.states[25].mesid.sat, expected 0, is "
      << last_msg_.states[25].mesid.sat;
  EXPECT_EQ(last_msg_.states[26].cn0, 212)
      << "incorrect value for last_msg_.states[26].cn0, expected 212, is "
      << last_msg_.states[26].cn0;
  EXPECT_EQ(last_msg_.states[26].mesid.code, 1)
      << "incorrect value for last_msg_.states[26].mesid.code, expected 1, is "
      << last_msg_.states[26].mesid.code;
  EXPECT_EQ(last_msg_.states[26].mesid.sat, 23)
      << "incorrect value for last_msg_.states[26].mesid.sat, expected 23, is "
      << last_msg_.states[26].mesid.sat;
  EXPECT_EQ(last_msg_.states[27].cn0, 205)
      << "incorrect value for last_msg_.states[27].cn0, expected 205, is "
      << last_msg_.states[27].cn0;
  EXPECT_EQ(last_msg_.states[27].mesid.code, 1)
      << "incorrect value for last_msg_.states[27].mesid.code, expected 1, is "
      << last_msg_.states[27].mesid.code;
  EXPECT_EQ(last_msg_.states[27].mesid.sat, 10)
      << "incorrect value for last_msg_.states[27].mesid.sat, expected 10, is "
      << last_msg_.states[27].mesid.sat;
  EXPECT_EQ(last_msg_.states[28].cn0, 0)
      << "incorrect value for last_msg_.states[28].cn0, expected 0, is "
      << last_msg_.states[28].cn0;
  EXPECT_EQ(last_msg_.states[28].mesid.code, 0)
      << "incorrect value for last_msg_.states[28].mesid.code, expected 0, is "
      << last_msg_.states[28].mesid.code;
  EXPECT_EQ(last_msg_.states[28].mesid.sat, 0)
      << "incorrect value for last_msg_.states[28].mesid.sat, expected 0, is "
      << last_msg_.states[28].mesid.sat;
  EXPECT_EQ(last_msg_.states[29].cn0, 230)
      << "incorrect value for last_msg_.states[29].cn0, expected 230, is "
      << last_msg_.states[29].cn0;
  EXPECT_EQ(last_msg_.states[29].mesid.code, 3)
      << "incorrect value for last_msg_.states[29].mesid.code, expected 3, is "
      << last_msg_.states[29].mesid.code;
  EXPECT_EQ(last_msg_.states[29].mesid.sat, 96)
      << "incorrect value for last_msg_.states[29].mesid.sat, expected 96, is "
      << last_msg_.states[29].mesid.sat;
  EXPECT_EQ(last_msg_.states[30].cn0, 0)
      << "incorrect value for last_msg_.states[30].cn0, expected 0, is "
      << last_msg_.states[30].cn0;
  EXPECT_EQ(last_msg_.states[30].mesid.code, 0)
      << "incorrect value for last_msg_.states[30].mesid.code, expected 0, is "
      << last_msg_.states[30].mesid.code;
  EXPECT_EQ(last_msg_.states[30].mesid.sat, 0)
      << "incorrect value for last_msg_.states[30].mesid.sat, expected 0, is "
      << last_msg_.states[30].mesid.sat;
  EXPECT_EQ(last_msg_.states[31].cn0, 214)
      << "incorrect value for last_msg_.states[31].cn0, expected 214, is "
      << last_msg_.states[31].cn0;
  EXPECT_EQ(last_msg_.states[31].mesid.code, 3)
      << "incorrect value for last_msg_.states[31].mesid.code, expected 3, is "
      << last_msg_.states[31].mesid.code;
  EXPECT_EQ(last_msg_.states[31].mesid.sat, 101)
      << "incorrect value for last_msg_.states[31].mesid.sat, expected 101, is "
      << last_msg_.states[31].mesid.sat;
  EXPECT_EQ(last_msg_.states[32].cn0, 212)
      << "incorrect value for last_msg_.states[32].cn0, expected 212, is "
      << last_msg_.states[32].cn0;
  EXPECT_EQ(last_msg_.states[32].mesid.code, 3)
      << "incorrect value for last_msg_.states[32].mesid.code, expected 3, is "
      << last_msg_.states[32].mesid.code;
  EXPECT_EQ(last_msg_.states[32].mesid.sat, 103)
      << "incorrect value for last_msg_.states[32].mesid.sat, expected 103, is "
      << last_msg_.states[32].mesid.sat;
  EXPECT_EQ(last_msg_.states[33].cn0, 209)
      << "incorrect value for last_msg_.states[33].cn0, expected 209, is "
      << last_msg_.states[33].cn0;
  EXPECT_EQ(last_msg_.states[33].mesid.code, 3)
      << "incorrect value for last_msg_.states[33].mesid.code, expected 3, is "
      << last_msg_.states[33].mesid.code;
  EXPECT_EQ(last_msg_.states[33].mesid.sat, 104)
      << "incorrect value for last_msg_.states[33].mesid.sat, expected 104, is "
      << last_msg_.states[33].mesid.sat;
  EXPECT_EQ(last_msg_.states[34].cn0, 157)
      << "incorrect value for last_msg_.states[34].cn0, expected 157, is "
      << last_msg_.states[34].cn0;
  EXPECT_EQ(last_msg_.states[34].mesid.code, 3)
      << "incorrect value for last_msg_.states[34].mesid.code, expected 3, is "
      << last_msg_.states[34].mesid.code;
  EXPECT_EQ(last_msg_.states[34].mesid.sat, 106)
      << "incorrect value for last_msg_.states[34].mesid.sat, expected 106, is "
      << last_msg_.states[34].mesid.sat;
  EXPECT_EQ(last_msg_.states[35].cn0, 230)
      << "incorrect value for last_msg_.states[35].cn0, expected 230, is "
      << last_msg_.states[35].cn0;
  EXPECT_EQ(last_msg_.states[35].mesid.code, 3)
      << "incorrect value for last_msg_.states[35].mesid.code, expected 3, is "
      << last_msg_.states[35].mesid.code;
  EXPECT_EQ(last_msg_.states[35].mesid.sat, 102)
      << "incorrect value for last_msg_.states[35].mesid.sat, expected 102, is "
      << last_msg_.states[35].mesid.sat;
  EXPECT_EQ(last_msg_.states[36].cn0, 0)
      << "incorrect value for last_msg_.states[36].cn0, expected 0, is "
      << last_msg_.states[36].cn0;
  EXPECT_EQ(last_msg_.states[36].mesid.code, 0)
      << "incorrect value for last_msg_.states[36].mesid.code, expected 0, is "
      << last_msg_.states[36].mesid.code;
  EXPECT_EQ(last_msg_.states[36].mesid.sat, 0)
      << "incorrect value for last_msg_.states[36].mesid.sat, expected 0, is "
      << last_msg_.states[36].mesid.sat;
  EXPECT_EQ(last_msg_.states[37].cn0, 0)
      << "incorrect value for last_msg_.states[37].cn0, expected 0, is "
      << last_msg_.states[37].cn0;
  EXPECT_EQ(last_msg_.states[37].mesid.code, 0)
      << "incorrect value for last_msg_.states[37].mesid.code, expected 0, is "
      << last_msg_.states[37].mesid.code;
  EXPECT_EQ(last_msg_.states[37].mesid.sat, 0)
      << "incorrect value for last_msg_.states[37].mesid.sat, expected 0, is "
      << last_msg_.states[37].mesid.sat;
  EXPECT_EQ(last_msg_.states[38].cn0, 189)
      << "incorrect value for last_msg_.states[38].cn0, expected 189, is "
      << last_msg_.states[38].cn0;
  EXPECT_EQ(last_msg_.states[38].mesid.code, 4)
      << "incorrect value for last_msg_.states[38].mesid.code, expected 4, is "
      << last_msg_.states[38].mesid.code;
  EXPECT_EQ(last_msg_.states[38].mesid.sat, 101)
      << "incorrect value for last_msg_.states[38].mesid.sat, expected 101, is "
      << last_msg_.states[38].mesid.sat;
  EXPECT_EQ(last_msg_.states[39].cn0, 207)
      << "incorrect value for last_msg_.states[39].cn0, expected 207, is "
      << last_msg_.states[39].cn0;
  EXPECT_EQ(last_msg_.states[39].mesid.code, 4)
      << "incorrect value for last_msg_.states[39].mesid.code, expected 4, is "
      << last_msg_.states[39].mesid.code;
  EXPECT_EQ(last_msg_.states[39].mesid.sat, 96)
      << "incorrect value for last_msg_.states[39].mesid.sat, expected 96, is "
      << last_msg_.states[39].mesid.sat;
  EXPECT_EQ(last_msg_.states[40].cn0, 164)
      << "incorrect value for last_msg_.states[40].cn0, expected 164, is "
      << last_msg_.states[40].cn0;
  EXPECT_EQ(last_msg_.states[40].mesid.code, 4)
      << "incorrect value for last_msg_.states[40].mesid.code, expected 4, is "
      << last_msg_.states[40].mesid.code;
  EXPECT_EQ(last_msg_.states[40].mesid.sat, 106)
      << "incorrect value for last_msg_.states[40].mesid.sat, expected 106, is "
      << last_msg_.states[40].mesid.sat;
  EXPECT_EQ(last_msg_.states[41].cn0, 193)
      << "incorrect value for last_msg_.states[41].cn0, expected 193, is "
      << last_msg_.states[41].cn0;
  EXPECT_EQ(last_msg_.states[41].mesid.code, 4)
      << "incorrect value for last_msg_.states[41].mesid.code, expected 4, is "
      << last_msg_.states[41].mesid.code;
  EXPECT_EQ(last_msg_.states[41].mesid.sat, 104)
      << "incorrect value for last_msg_.states[41].mesid.sat, expected 104, is "
      << last_msg_.states[41].mesid.sat;
  EXPECT_EQ(last_msg_.states[42].cn0, 0)
      << "incorrect value for last_msg_.states[42].cn0, expected 0, is "
      << last_msg_.states[42].cn0;
  EXPECT_EQ(last_msg_.states[42].mesid.code, 0)
      << "incorrect value for last_msg_.states[42].mesid.code, expected 0, is "
      << last_msg_.states[42].mesid.code;
  EXPECT_EQ(last_msg_.states[42].mesid.sat, 0)
      << "incorrect value for last_msg_.states[42].mesid.sat, expected 0, is "
      << last_msg_.states[42].mesid.sat;
  EXPECT_EQ(last_msg_.states[43].cn0, 208)
      << "incorrect value for last_msg_.states[43].cn0, expected 208, is "
      << last_msg_.states[43].cn0;
  EXPECT_EQ(last_msg_.states[43].mesid.code, 4)
      << "incorrect value for last_msg_.states[43].mesid.code, expected 4, is "
      << last_msg_.states[43].mesid.code;
  EXPECT_EQ(last_msg_.states[43].mesid.sat, 102)
      << "incorrect value for last_msg_.states[43].mesid.sat, expected 102, is "
      << last_msg_.states[43].mesid.sat;
  EXPECT_EQ(last_msg_.states[44].cn0, 0)
      << "incorrect value for last_msg_.states[44].cn0, expected 0, is "
      << last_msg_.states[44].cn0;
  EXPECT_EQ(last_msg_.states[44].mesid.code, 0)
      << "incorrect value for last_msg_.states[44].mesid.code, expected 0, is "
      << last_msg_.states[44].mesid.code;
  EXPECT_EQ(last_msg_.states[44].mesid.sat, 0)
      << "incorrect value for last_msg_.states[44].mesid.sat, expected 0, is "
      << last_msg_.states[44].mesid.sat;
  EXPECT_EQ(last_msg_.states[45].cn0, 212)
      << "incorrect value for last_msg_.states[45].cn0, expected 212, is "
      << last_msg_.states[45].cn0;
  EXPECT_EQ(last_msg_.states[45].mesid.code, 12)
      << "incorrect value for last_msg_.states[45].mesid.code, expected 12, is "
      << last_msg_.states[45].mesid.code;
  EXPECT_EQ(last_msg_.states[45].mesid.sat, 27)
      << "incorrect value for last_msg_.states[45].mesid.sat, expected 27, is "
      << last_msg_.states[45].mesid.sat;
  EXPECT_EQ(last_msg_.states[46].cn0, 161)
      << "incorrect value for last_msg_.states[46].cn0, expected 161, is "
      << last_msg_.states[46].cn0;
  EXPECT_EQ(last_msg_.states[46].mesid.code, 12)
      << "incorrect value for last_msg_.states[46].mesid.code, expected 12, is "
      << last_msg_.states[46].mesid.code;
  EXPECT_EQ(last_msg_.states[46].mesid.sat, 29)
      << "incorrect value for last_msg_.states[46].mesid.sat, expected 29, is "
      << last_msg_.states[46].mesid.sat;
  EXPECT_EQ(last_msg_.states[47].cn0, 216)
      << "incorrect value for last_msg_.states[47].cn0, expected 216, is "
      << last_msg_.states[47].cn0;
  EXPECT_EQ(last_msg_.states[47].mesid.code, 12)
      << "incorrect value for last_msg_.states[47].mesid.code, expected 12, is "
      << last_msg_.states[47].mesid.code;
  EXPECT_EQ(last_msg_.states[47].mesid.sat, 32)
      << "incorrect value for last_msg_.states[47].mesid.sat, expected 32, is "
      << last_msg_.states[47].mesid.sat;
  EXPECT_EQ(last_msg_.states[48].cn0, 216)
      << "incorrect value for last_msg_.states[48].cn0, expected 216, is "
      << last_msg_.states[48].cn0;
  EXPECT_EQ(last_msg_.states[48].mesid.code, 12)
      << "incorrect value for last_msg_.states[48].mesid.code, expected 12, is "
      << last_msg_.states[48].mesid.code;
  EXPECT_EQ(last_msg_.states[48].mesid.sat, 30)
      << "incorrect value for last_msg_.states[48].mesid.sat, expected 30, is "
      << last_msg_.states[48].mesid.sat;
  EXPECT_EQ(last_msg_.states[49].cn0, 178)
      << "incorrect value for last_msg_.states[49].cn0, expected 178, is "
      << last_msg_.states[49].cn0;
  EXPECT_EQ(last_msg_.states[49].mesid.code, 12)
      << "incorrect value for last_msg_.states[49].mesid.code, expected 12, is "
      << last_msg_.states[49].mesid.code;
  EXPECT_EQ(last_msg_.states[49].mesid.sat, 20)
      << "incorrect value for last_msg_.states[49].mesid.sat, expected 20, is "
      << last_msg_.states[49].mesid.sat;
  EXPECT_EQ(last_msg_.states[50].cn0, 0)
      << "incorrect value for last_msg_.states[50].cn0, expected 0, is "
      << last_msg_.states[50].cn0;
  EXPECT_EQ(last_msg_.states[50].mesid.code, 0)
      << "incorrect value for last_msg_.states[50].mesid.code, expected 0, is "
      << last_msg_.states[50].mesid.code;
  EXPECT_EQ(last_msg_.states[50].mesid.sat, 0)
      << "incorrect value for last_msg_.states[50].mesid.sat, expected 0, is "
      << last_msg_.states[50].mesid.sat;
  EXPECT_EQ(last_msg_.states[51].cn0, 0)
      << "incorrect value for last_msg_.states[51].cn0, expected 0, is "
      << last_msg_.states[51].cn0;
  EXPECT_EQ(last_msg_.states[51].mesid.code, 0)
      << "incorrect value for last_msg_.states[51].mesid.code, expected 0, is "
      << last_msg_.states[51].mesid.code;
  EXPECT_EQ(last_msg_.states[51].mesid.sat, 0)
      << "incorrect value for last_msg_.states[51].mesid.sat, expected 0, is "
      << last_msg_.states[51].mesid.sat;
  EXPECT_EQ(last_msg_.states[52].cn0, 0)
      << "incorrect value for last_msg_.states[52].cn0, expected 0, is "
      << last_msg_.states[52].cn0;
  EXPECT_EQ(last_msg_.states[52].mesid.code, 0)
      << "incorrect value for last_msg_.states[52].mesid.code, expected 0, is "
      << last_msg_.states[52].mesid.code;
  EXPECT_EQ(last_msg_.states[52].mesid.sat, 0)
      << "incorrect value for last_msg_.states[52].mesid.sat, expected 0, is "
      << last_msg_.states[52].mesid.sat;
  EXPECT_EQ(last_msg_.states[53].cn0, 0)
      << "incorrect value for last_msg_.states[53].cn0, expected 0, is "
      << last_msg_.states[53].cn0;
  EXPECT_EQ(last_msg_.states[53].mesid.code, 0)
      << "incorrect value for last_msg_.states[53].mesid.code, expected 0, is "
      << last_msg_.states[53].mesid.code;
  EXPECT_EQ(last_msg_.states[53].mesid.sat, 0)
      << "incorrect value for last_msg_.states[53].mesid.sat, expected 0, is "
      << last_msg_.states[53].mesid.sat;
  EXPECT_EQ(last_msg_.states[54].cn0, 0)
      << "incorrect value for last_msg_.states[54].cn0, expected 0, is "
      << last_msg_.states[54].cn0;
  EXPECT_EQ(last_msg_.states[54].mesid.code, 0)
      << "incorrect value for last_msg_.states[54].mesid.code, expected 0, is "
      << last_msg_.states[54].mesid.code;
  EXPECT_EQ(last_msg_.states[54].mesid.sat, 0)
      << "incorrect value for last_msg_.states[54].mesid.sat, expected 0, is "
      << last_msg_.states[54].mesid.sat;
  EXPECT_EQ(last_msg_.states[55].cn0, 0)
      << "incorrect value for last_msg_.states[55].cn0, expected 0, is "
      << last_msg_.states[55].cn0;
  EXPECT_EQ(last_msg_.states[55].mesid.code, 0)
      << "incorrect value for last_msg_.states[55].mesid.code, expected 0, is "
      << last_msg_.states[55].mesid.code;
  EXPECT_EQ(last_msg_.states[55].mesid.sat, 0)
      << "incorrect value for last_msg_.states[55].mesid.sat, expected 0, is "
      << last_msg_.states[55].mesid.sat;
  EXPECT_EQ(last_msg_.states[56].cn0, 0)
      << "incorrect value for last_msg_.states[56].cn0, expected 0, is "
      << last_msg_.states[56].cn0;
  EXPECT_EQ(last_msg_.states[56].mesid.code, 0)
      << "incorrect value for last_msg_.states[56].mesid.code, expected 0, is "
      << last_msg_.states[56].mesid.code;
  EXPECT_EQ(last_msg_.states[56].mesid.sat, 0)
      << "incorrect value for last_msg_.states[56].mesid.sat, expected 0, is "
      << last_msg_.states[56].mesid.sat;
  EXPECT_EQ(last_msg_.states[57].cn0, 0)
      << "incorrect value for last_msg_.states[57].cn0, expected 0, is "
      << last_msg_.states[57].cn0;
  EXPECT_EQ(last_msg_.states[57].mesid.code, 0)
      << "incorrect value for last_msg_.states[57].mesid.code, expected 0, is "
      << last_msg_.states[57].mesid.code;
  EXPECT_EQ(last_msg_.states[57].mesid.sat, 0)
      << "incorrect value for last_msg_.states[57].mesid.sat, expected 0, is "
      << last_msg_.states[57].mesid.sat;
  EXPECT_EQ(last_msg_.states[58].cn0, 0)
      << "incorrect value for last_msg_.states[58].cn0, expected 0, is "
      << last_msg_.states[58].cn0;
  EXPECT_EQ(last_msg_.states[58].mesid.code, 0)
      << "incorrect value for last_msg_.states[58].mesid.code, expected 0, is "
      << last_msg_.states[58].mesid.code;
  EXPECT_EQ(last_msg_.states[58].mesid.sat, 0)
      << "incorrect value for last_msg_.states[58].mesid.sat, expected 0, is "
      << last_msg_.states[58].mesid.sat;
  EXPECT_EQ(last_msg_.states[59].cn0, 0)
      << "incorrect value for last_msg_.states[59].cn0, expected 0, is "
      << last_msg_.states[59].cn0;
  EXPECT_EQ(last_msg_.states[59].mesid.code, 0)
      << "incorrect value for last_msg_.states[59].mesid.code, expected 0, is "
      << last_msg_.states[59].mesid.code;
  EXPECT_EQ(last_msg_.states[59].mesid.sat, 0)
      << "incorrect value for last_msg_.states[59].mesid.sat, expected 0, is "
      << last_msg_.states[59].mesid.sat;
  EXPECT_EQ(last_msg_.states[60].cn0, 0)
      << "incorrect value for last_msg_.states[60].cn0, expected 0, is "
      << last_msg_.states[60].cn0;
  EXPECT_EQ(last_msg_.states[60].mesid.code, 0)
      << "incorrect value for last_msg_.states[60].mesid.code, expected 0, is "
      << last_msg_.states[60].mesid.code;
  EXPECT_EQ(last_msg_.states[60].mesid.sat, 0)
      << "incorrect value for last_msg_.states[60].mesid.sat, expected 0, is "
      << last_msg_.states[60].mesid.sat;
  EXPECT_EQ(last_msg_.states[61].cn0, 0)
      << "incorrect value for last_msg_.states[61].cn0, expected 0, is "
      << last_msg_.states[61].cn0;
  EXPECT_EQ(last_msg_.states[61].mesid.code, 0)
      << "incorrect value for last_msg_.states[61].mesid.code, expected 0, is "
      << last_msg_.states[61].mesid.code;
  EXPECT_EQ(last_msg_.states[61].mesid.sat, 0)
      << "incorrect value for last_msg_.states[61].mesid.sat, expected 0, is "
      << last_msg_.states[61].mesid.sat;
  EXPECT_EQ(last_msg_.states[62].cn0, 0)
      << "incorrect value for last_msg_.states[62].cn0, expected 0, is "
      << last_msg_.states[62].cn0;
  EXPECT_EQ(last_msg_.states[62].mesid.code, 0)
      << "incorrect value for last_msg_.states[62].mesid.code, expected 0, is "
      << last_msg_.states[62].mesid.code;
  EXPECT_EQ(last_msg_.states[62].mesid.sat, 0)
      << "incorrect value for last_msg_.states[62].mesid.sat, expected 0, is "
      << last_msg_.states[62].mesid.sat;
  EXPECT_EQ(last_msg_.states[63].cn0, 203)
      << "incorrect value for last_msg_.states[63].cn0, expected 203, is "
      << last_msg_.states[63].cn0;
  EXPECT_EQ(last_msg_.states[63].mesid.code, 14)
      << "incorrect value for last_msg_.states[63].mesid.code, expected 14, is "
      << last_msg_.states[63].mesid.code;
  EXPECT_EQ(last_msg_.states[63].mesid.sat, 36)
      << "incorrect value for last_msg_.states[63].mesid.sat, expected 36, is "
      << last_msg_.states[63].mesid.sat;
  EXPECT_EQ(last_msg_.states[64].cn0, 0)
      << "incorrect value for last_msg_.states[64].cn0, expected 0, is "
      << last_msg_.states[64].cn0;
  EXPECT_EQ(last_msg_.states[64].mesid.code, 0)
      << "incorrect value for last_msg_.states[64].mesid.code, expected 0, is "
      << last_msg_.states[64].mesid.code;
  EXPECT_EQ(last_msg_.states[64].mesid.sat, 0)
      << "incorrect value for last_msg_.states[64].mesid.sat, expected 0, is "
      << last_msg_.states[64].mesid.sat;
  EXPECT_EQ(last_msg_.states[65].cn0, 158)
      << "incorrect value for last_msg_.states[65].cn0, expected 158, is "
      << last_msg_.states[65].cn0;
  EXPECT_EQ(last_msg_.states[65].mesid.code, 14)
      << "incorrect value for last_msg_.states[65].mesid.code, expected 14, is "
      << last_msg_.states[65].mesid.code;
  EXPECT_EQ(last_msg_.states[65].mesid.sat, 5)
      << "incorrect value for last_msg_.states[65].mesid.sat, expected 5, is "
      << last_msg_.states[65].mesid.sat;
  EXPECT_EQ(last_msg_.states[66].cn0, 194)
      << "incorrect value for last_msg_.states[66].cn0, expected 194, is "
      << last_msg_.states[66].cn0;
  EXPECT_EQ(last_msg_.states[66].mesid.code, 14)
      << "incorrect value for last_msg_.states[66].mesid.code, expected 14, is "
      << last_msg_.states[66].mesid.code;
  EXPECT_EQ(last_msg_.states[66].mesid.sat, 4)
      << "incorrect value for last_msg_.states[66].mesid.sat, expected 4, is "
      << last_msg_.states[66].mesid.sat;
  EXPECT_EQ(last_msg_.states[67].cn0, 192)
      << "incorrect value for last_msg_.states[67].cn0, expected 192, is "
      << last_msg_.states[67].cn0;
  EXPECT_EQ(last_msg_.states[67].mesid.code, 14)
      << "incorrect value for last_msg_.states[67].mesid.code, expected 14, is "
      << last_msg_.states[67].mesid.code;
  EXPECT_EQ(last_msg_.states[67].mesid.sat, 11)
      << "incorrect value for last_msg_.states[67].mesid.sat, expected 11, is "
      << last_msg_.states[67].mesid.sat;
  EXPECT_EQ(last_msg_.states[68].cn0, 207)
      << "incorrect value for last_msg_.states[68].cn0, expected 207, is "
      << last_msg_.states[68].cn0;
  EXPECT_EQ(last_msg_.states[68].mesid.code, 14)
      << "incorrect value for last_msg_.states[68].mesid.code, expected 14, is "
      << last_msg_.states[68].mesid.code;
  EXPECT_EQ(last_msg_.states[68].mesid.sat, 9)
      << "incorrect value for last_msg_.states[68].mesid.sat, expected 9, is "
      << last_msg_.states[68].mesid.sat;
  EXPECT_EQ(last_msg_.states[69].cn0, 0)
      << "incorrect value for last_msg_.states[69].cn0, expected 0, is "
      << last_msg_.states[69].cn0;
  EXPECT_EQ(last_msg_.states[69].mesid.code, 0)
      << "incorrect value for last_msg_.states[69].mesid.code, expected 0, is "
      << last_msg_.states[69].mesid.code;
  EXPECT_EQ(last_msg_.states[69].mesid.sat, 0)
      << "incorrect value for last_msg_.states[69].mesid.sat, expected 0, is "
      << last_msg_.states[69].mesid.sat;
  EXPECT_EQ(last_msg_.states[70].cn0, 0)
      << "incorrect value for last_msg_.states[70].cn0, expected 0, is "
      << last_msg_.states[70].cn0;
  EXPECT_EQ(last_msg_.states[70].mesid.code, 0)
      << "incorrect value for last_msg_.states[70].mesid.code, expected 0, is "
      << last_msg_.states[70].mesid.code;
  EXPECT_EQ(last_msg_.states[70].mesid.sat, 0)
      << "incorrect value for last_msg_.states[70].mesid.sat, expected 0, is "
      << last_msg_.states[70].mesid.sat;
  EXPECT_EQ(last_msg_.states[71].cn0, 0)
      << "incorrect value for last_msg_.states[71].cn0, expected 0, is "
      << last_msg_.states[71].cn0;
  EXPECT_EQ(last_msg_.states[71].mesid.code, 0)
      << "incorrect value for last_msg_.states[71].mesid.code, expected 0, is "
      << last_msg_.states[71].mesid.code;
  EXPECT_EQ(last_msg_.states[71].mesid.sat, 0)
      << "incorrect value for last_msg_.states[71].mesid.sat, expected 0, is "
      << last_msg_.states[71].mesid.sat;
  EXPECT_EQ(last_msg_.states[72].cn0, 218)
      << "incorrect value for last_msg_.states[72].cn0, expected 218, is "
      << last_msg_.states[72].cn0;
  EXPECT_EQ(last_msg_.states[72].mesid.code, 20)
      << "incorrect value for last_msg_.states[72].mesid.code, expected 20, is "
      << last_msg_.states[72].mesid.code;
  EXPECT_EQ(last_msg_.states[72].mesid.sat, 9)
      << "incorrect value for last_msg_.states[72].mesid.sat, expected 9, is "
      << last_msg_.states[72].mesid.sat;
  EXPECT_EQ(last_msg_.states[73].cn0, 176)
      << "incorrect value for last_msg_.states[73].cn0, expected 176, is "
      << last_msg_.states[73].cn0;
  EXPECT_EQ(last_msg_.states[73].mesid.code, 20)
      << "incorrect value for last_msg_.states[73].mesid.code, expected 20, is "
      << last_msg_.states[73].mesid.code;
  EXPECT_EQ(last_msg_.states[73].mesid.sat, 5)
      << "incorrect value for last_msg_.states[73].mesid.sat, expected 5, is "
      << last_msg_.states[73].mesid.sat;
  EXPECT_EQ(last_msg_.states[74].cn0, 217)
      << "incorrect value for last_msg_.states[74].cn0, expected 217, is "
      << last_msg_.states[74].cn0;
  EXPECT_EQ(last_msg_.states[74].mesid.code, 20)
      << "incorrect value for last_msg_.states[74].mesid.code, expected 20, is "
      << last_msg_.states[74].mesid.code;
  EXPECT_EQ(last_msg_.states[74].mesid.sat, 36)
      << "incorrect value for last_msg_.states[74].mesid.sat, expected 36, is "
      << last_msg_.states[74].mesid.sat;
  EXPECT_EQ(last_msg_.states[75].cn0, 200)
      << "incorrect value for last_msg_.states[75].cn0, expected 200, is "
      << last_msg_.states[75].cn0;
  EXPECT_EQ(last_msg_.states[75].mesid.code, 20)
      << "incorrect value for last_msg_.states[75].mesid.code, expected 20, is "
      << last_msg_.states[75].mesid.code;
  EXPECT_EQ(last_msg_.states[75].mesid.sat, 11)
      << "incorrect value for last_msg_.states[75].mesid.sat, expected 11, is "
      << last_msg_.states[75].mesid.sat;
  EXPECT_EQ(last_msg_.states[76].cn0, 205)
      << "incorrect value for last_msg_.states[76].cn0, expected 205, is "
      << last_msg_.states[76].cn0;
  EXPECT_EQ(last_msg_.states[76].mesid.code, 20)
      << "incorrect value for last_msg_.states[76].mesid.code, expected 20, is "
      << last_msg_.states[76].mesid.code;
  EXPECT_EQ(last_msg_.states[76].mesid.sat, 4)
      << "incorrect value for last_msg_.states[76].mesid.sat, expected 4, is "
      << last_msg_.states[76].mesid.sat;
  EXPECT_EQ(last_msg_.states[77].cn0, 0)
      << "incorrect value for last_msg_.states[77].cn0, expected 0, is "
      << last_msg_.states[77].cn0;
  EXPECT_EQ(last_msg_.states[77].mesid.code, 0)
      << "incorrect value for last_msg_.states[77].mesid.code, expected 0, is "
      << last_msg_.states[77].mesid.code;
  EXPECT_EQ(last_msg_.states[77].mesid.sat, 0)
      << "incorrect value for last_msg_.states[77].mesid.sat, expected 0, is "
      << last_msg_.states[77].mesid.sat;
  EXPECT_EQ(last_msg_.states[78].cn0, 0)
      << "incorrect value for last_msg_.states[78].cn0, expected 0, is "
      << last_msg_.states[78].cn0;
  EXPECT_EQ(last_msg_.states[78].mesid.code, 0)
      << "incorrect value for last_msg_.states[78].mesid.code, expected 0, is "
      << last_msg_.states[78].mesid.code;
  EXPECT_EQ(last_msg_.states[78].mesid.sat, 0)
      << "incorrect value for last_msg_.states[78].mesid.sat, expected 0, is "
      << last_msg_.states[78].mesid.sat;
}
