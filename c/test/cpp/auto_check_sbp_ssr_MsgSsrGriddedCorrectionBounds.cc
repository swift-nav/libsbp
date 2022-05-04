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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionBounds.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_ssr_gridded_correction_bounds_t> {
 public:
  Test_auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_ssr_gridded_correction_bounds_t>(this),
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
      const sbp_msg_ssr_gridded_correction_bounds_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_ssr_gridded_correction_bounds_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds0, Test) {
  uint8_t encoded_frame[] = {
      85,  254, 5,   66,  0, 43, 180, 0,  0,  0,   3,   0,   1,
      1,   10,  0,   15,  1, 0,  10,  0,  39, 232, 3,   244, 1,
      100, 200, 150, 100, 2, 5,  10,  16, 0,  17,  18,  19,  20,
      21,  6,   10,  22,  0, 23, 24,  25, 26, 27,  112, 145,
  };

  sbp_msg_ssr_gridded_correction_bounds_t test_msg{};
  test_msg.n_stub = 43;

  test_msg.stub[0] = 180;

  test_msg.stub[1] = 0;

  test_msg.stub[2] = 0;

  test_msg.stub[3] = 0;

  test_msg.stub[4] = 3;

  test_msg.stub[5] = 0;

  test_msg.stub[6] = 1;

  test_msg.stub[7] = 1;

  test_msg.stub[8] = 10;

  test_msg.stub[9] = 0;

  test_msg.stub[10] = 15;

  test_msg.stub[11] = 1;

  test_msg.stub[12] = 0;

  test_msg.stub[13] = 10;

  test_msg.stub[14] = 0;

  test_msg.stub[15] = 39;

  test_msg.stub[16] = 232;

  test_msg.stub[17] = 3;

  test_msg.stub[18] = 244;

  test_msg.stub[19] = 1;

  test_msg.stub[20] = 100;

  test_msg.stub[21] = 200;

  test_msg.stub[22] = 150;

  test_msg.stub[23] = 100;

  test_msg.stub[24] = 2;

  test_msg.stub[25] = 5;

  test_msg.stub[26] = 10;

  test_msg.stub[27] = 16;

  test_msg.stub[28] = 0;

  test_msg.stub[29] = 17;

  test_msg.stub[30] = 18;

  test_msg.stub[31] = 19;

  test_msg.stub[32] = 20;

  test_msg.stub[33] = 21;

  test_msg.stub[34] = 6;

  test_msg.stub[35] = 10;

  test_msg.stub[36] = 22;

  test_msg.stub[37] = 0;

  test_msg.stub[38] = 23;

  test_msg.stub[39] = 24;

  test_msg.stub[40] = 25;

  test_msg.stub[41] = 26;

  test_msg.stub[42] = 27;

  EXPECT_EQ(send_message(66, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.n_stub, 43)
      << "incorrect value for last_msg_.n_stub, expected 43, is "
      << last_msg_.n_stub;
  EXPECT_EQ(last_msg_.stub[0], 180)
      << "incorrect value for last_msg_.stub[0], expected 180, is "
      << last_msg_.stub[0];
  EXPECT_EQ(last_msg_.stub[1], 0)
      << "incorrect value for last_msg_.stub[1], expected 0, is "
      << last_msg_.stub[1];
  EXPECT_EQ(last_msg_.stub[2], 0)
      << "incorrect value for last_msg_.stub[2], expected 0, is "
      << last_msg_.stub[2];
  EXPECT_EQ(last_msg_.stub[3], 0)
      << "incorrect value for last_msg_.stub[3], expected 0, is "
      << last_msg_.stub[3];
  EXPECT_EQ(last_msg_.stub[4], 3)
      << "incorrect value for last_msg_.stub[4], expected 3, is "
      << last_msg_.stub[4];
  EXPECT_EQ(last_msg_.stub[5], 0)
      << "incorrect value for last_msg_.stub[5], expected 0, is "
      << last_msg_.stub[5];
  EXPECT_EQ(last_msg_.stub[6], 1)
      << "incorrect value for last_msg_.stub[6], expected 1, is "
      << last_msg_.stub[6];
  EXPECT_EQ(last_msg_.stub[7], 1)
      << "incorrect value for last_msg_.stub[7], expected 1, is "
      << last_msg_.stub[7];
  EXPECT_EQ(last_msg_.stub[8], 10)
      << "incorrect value for last_msg_.stub[8], expected 10, is "
      << last_msg_.stub[8];
  EXPECT_EQ(last_msg_.stub[9], 0)
      << "incorrect value for last_msg_.stub[9], expected 0, is "
      << last_msg_.stub[9];
  EXPECT_EQ(last_msg_.stub[10], 15)
      << "incorrect value for last_msg_.stub[10], expected 15, is "
      << last_msg_.stub[10];
  EXPECT_EQ(last_msg_.stub[11], 1)
      << "incorrect value for last_msg_.stub[11], expected 1, is "
      << last_msg_.stub[11];
  EXPECT_EQ(last_msg_.stub[12], 0)
      << "incorrect value for last_msg_.stub[12], expected 0, is "
      << last_msg_.stub[12];
  EXPECT_EQ(last_msg_.stub[13], 10)
      << "incorrect value for last_msg_.stub[13], expected 10, is "
      << last_msg_.stub[13];
  EXPECT_EQ(last_msg_.stub[14], 0)
      << "incorrect value for last_msg_.stub[14], expected 0, is "
      << last_msg_.stub[14];
  EXPECT_EQ(last_msg_.stub[15], 39)
      << "incorrect value for last_msg_.stub[15], expected 39, is "
      << last_msg_.stub[15];
  EXPECT_EQ(last_msg_.stub[16], 232)
      << "incorrect value for last_msg_.stub[16], expected 232, is "
      << last_msg_.stub[16];
  EXPECT_EQ(last_msg_.stub[17], 3)
      << "incorrect value for last_msg_.stub[17], expected 3, is "
      << last_msg_.stub[17];
  EXPECT_EQ(last_msg_.stub[18], 244)
      << "incorrect value for last_msg_.stub[18], expected 244, is "
      << last_msg_.stub[18];
  EXPECT_EQ(last_msg_.stub[19], 1)
      << "incorrect value for last_msg_.stub[19], expected 1, is "
      << last_msg_.stub[19];
  EXPECT_EQ(last_msg_.stub[20], 100)
      << "incorrect value for last_msg_.stub[20], expected 100, is "
      << last_msg_.stub[20];
  EXPECT_EQ(last_msg_.stub[21], 200)
      << "incorrect value for last_msg_.stub[21], expected 200, is "
      << last_msg_.stub[21];
  EXPECT_EQ(last_msg_.stub[22], 150)
      << "incorrect value for last_msg_.stub[22], expected 150, is "
      << last_msg_.stub[22];
  EXPECT_EQ(last_msg_.stub[23], 100)
      << "incorrect value for last_msg_.stub[23], expected 100, is "
      << last_msg_.stub[23];
  EXPECT_EQ(last_msg_.stub[24], 2)
      << "incorrect value for last_msg_.stub[24], expected 2, is "
      << last_msg_.stub[24];
  EXPECT_EQ(last_msg_.stub[25], 5)
      << "incorrect value for last_msg_.stub[25], expected 5, is "
      << last_msg_.stub[25];
  EXPECT_EQ(last_msg_.stub[26], 10)
      << "incorrect value for last_msg_.stub[26], expected 10, is "
      << last_msg_.stub[26];
  EXPECT_EQ(last_msg_.stub[27], 16)
      << "incorrect value for last_msg_.stub[27], expected 16, is "
      << last_msg_.stub[27];
  EXPECT_EQ(last_msg_.stub[28], 0)
      << "incorrect value for last_msg_.stub[28], expected 0, is "
      << last_msg_.stub[28];
  EXPECT_EQ(last_msg_.stub[29], 17)
      << "incorrect value for last_msg_.stub[29], expected 17, is "
      << last_msg_.stub[29];
  EXPECT_EQ(last_msg_.stub[30], 18)
      << "incorrect value for last_msg_.stub[30], expected 18, is "
      << last_msg_.stub[30];
  EXPECT_EQ(last_msg_.stub[31], 19)
      << "incorrect value for last_msg_.stub[31], expected 19, is "
      << last_msg_.stub[31];
  EXPECT_EQ(last_msg_.stub[32], 20)
      << "incorrect value for last_msg_.stub[32], expected 20, is "
      << last_msg_.stub[32];
  EXPECT_EQ(last_msg_.stub[33], 21)
      << "incorrect value for last_msg_.stub[33], expected 21, is "
      << last_msg_.stub[33];
  EXPECT_EQ(last_msg_.stub[34], 6)
      << "incorrect value for last_msg_.stub[34], expected 6, is "
      << last_msg_.stub[34];
  EXPECT_EQ(last_msg_.stub[35], 10)
      << "incorrect value for last_msg_.stub[35], expected 10, is "
      << last_msg_.stub[35];
  EXPECT_EQ(last_msg_.stub[36], 22)
      << "incorrect value for last_msg_.stub[36], expected 22, is "
      << last_msg_.stub[36];
  EXPECT_EQ(last_msg_.stub[37], 0)
      << "incorrect value for last_msg_.stub[37], expected 0, is "
      << last_msg_.stub[37];
  EXPECT_EQ(last_msg_.stub[38], 23)
      << "incorrect value for last_msg_.stub[38], expected 23, is "
      << last_msg_.stub[38];
  EXPECT_EQ(last_msg_.stub[39], 24)
      << "incorrect value for last_msg_.stub[39], expected 24, is "
      << last_msg_.stub[39];
  EXPECT_EQ(last_msg_.stub[40], 25)
      << "incorrect value for last_msg_.stub[40], expected 25, is "
      << last_msg_.stub[40];
  EXPECT_EQ(last_msg_.stub[41], 26)
      << "incorrect value for last_msg_.stub[41], expected 26, is "
      << last_msg_.stub[41];
  EXPECT_EQ(last_msg_.stub[42], 27)
      << "incorrect value for last_msg_.stub[42], expected 27, is "
      << last_msg_.stub[42];
}
