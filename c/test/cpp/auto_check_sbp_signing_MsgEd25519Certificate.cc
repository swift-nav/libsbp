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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519Certificate.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_signing_MsgEd25519Certificate0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_ed25519_certificate_t> {
 public:
  Test_auto_check_sbp_signing_MsgEd25519Certificate0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_ed25519_certificate_t>(this),
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
                      const sbp_msg_ed25519_certificate_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_ed25519_certificate_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_signing_MsgEd25519Certificate0, Test) {
  uint8_t encoded_frame[] = {
      85,  2,   12,  66,  0,   106, 16,  100, 101, 102, 103, 104, 105, 106, 107,
      108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 0,   3,   6,
      9,   12,  15,  18,  21,  24,  27,  30,  33,  36,  39,  42,  45,  48,  51,
      54,  57,  60,  63,  66,  69,  72,  75,  78,  81,  84,  87,  90,  93,  96,
      99,  102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141,
      144, 147, 150, 153, 156, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186,
      189, 192, 195, 198, 201, 204, 207, 210, 213, 216, 219, 222, 225, 228, 231,
      234, 237, 240, 243, 246, 249, 252, 218, 148,
  };

  sbp_msg_ed25519_certificate_t test_msg{};

  test_msg.certificate_bytes[0] = 0;

  test_msg.certificate_bytes[1] = 3;

  test_msg.certificate_bytes[2] = 6;

  test_msg.certificate_bytes[3] = 9;

  test_msg.certificate_bytes[4] = 12;

  test_msg.certificate_bytes[5] = 15;

  test_msg.certificate_bytes[6] = 18;

  test_msg.certificate_bytes[7] = 21;

  test_msg.certificate_bytes[8] = 24;

  test_msg.certificate_bytes[9] = 27;

  test_msg.certificate_bytes[10] = 30;

  test_msg.certificate_bytes[11] = 33;

  test_msg.certificate_bytes[12] = 36;

  test_msg.certificate_bytes[13] = 39;

  test_msg.certificate_bytes[14] = 42;

  test_msg.certificate_bytes[15] = 45;

  test_msg.certificate_bytes[16] = 48;

  test_msg.certificate_bytes[17] = 51;

  test_msg.certificate_bytes[18] = 54;

  test_msg.certificate_bytes[19] = 57;

  test_msg.certificate_bytes[20] = 60;

  test_msg.certificate_bytes[21] = 63;

  test_msg.certificate_bytes[22] = 66;

  test_msg.certificate_bytes[23] = 69;

  test_msg.certificate_bytes[24] = 72;

  test_msg.certificate_bytes[25] = 75;

  test_msg.certificate_bytes[26] = 78;

  test_msg.certificate_bytes[27] = 81;

  test_msg.certificate_bytes[28] = 84;

  test_msg.certificate_bytes[29] = 87;

  test_msg.certificate_bytes[30] = 90;

  test_msg.certificate_bytes[31] = 93;

  test_msg.certificate_bytes[32] = 96;

  test_msg.certificate_bytes[33] = 99;

  test_msg.certificate_bytes[34] = 102;

  test_msg.certificate_bytes[35] = 105;

  test_msg.certificate_bytes[36] = 108;

  test_msg.certificate_bytes[37] = 111;

  test_msg.certificate_bytes[38] = 114;

  test_msg.certificate_bytes[39] = 117;

  test_msg.certificate_bytes[40] = 120;

  test_msg.certificate_bytes[41] = 123;

  test_msg.certificate_bytes[42] = 126;

  test_msg.certificate_bytes[43] = 129;

  test_msg.certificate_bytes[44] = 132;

  test_msg.certificate_bytes[45] = 135;

  test_msg.certificate_bytes[46] = 138;

  test_msg.certificate_bytes[47] = 141;

  test_msg.certificate_bytes[48] = 144;

  test_msg.certificate_bytes[49] = 147;

  test_msg.certificate_bytes[50] = 150;

  test_msg.certificate_bytes[51] = 153;

  test_msg.certificate_bytes[52] = 156;

  test_msg.certificate_bytes[53] = 159;

  test_msg.certificate_bytes[54] = 162;

  test_msg.certificate_bytes[55] = 165;

  test_msg.certificate_bytes[56] = 168;

  test_msg.certificate_bytes[57] = 171;

  test_msg.certificate_bytes[58] = 174;

  test_msg.certificate_bytes[59] = 177;

  test_msg.certificate_bytes[60] = 180;

  test_msg.certificate_bytes[61] = 183;

  test_msg.certificate_bytes[62] = 186;

  test_msg.certificate_bytes[63] = 189;

  test_msg.certificate_bytes[64] = 192;

  test_msg.certificate_bytes[65] = 195;

  test_msg.certificate_bytes[66] = 198;

  test_msg.certificate_bytes[67] = 201;

  test_msg.certificate_bytes[68] = 204;

  test_msg.certificate_bytes[69] = 207;

  test_msg.certificate_bytes[70] = 210;

  test_msg.certificate_bytes[71] = 213;

  test_msg.certificate_bytes[72] = 216;

  test_msg.certificate_bytes[73] = 219;

  test_msg.certificate_bytes[74] = 222;

  test_msg.certificate_bytes[75] = 225;

  test_msg.certificate_bytes[76] = 228;

  test_msg.certificate_bytes[77] = 231;

  test_msg.certificate_bytes[78] = 234;

  test_msg.certificate_bytes[79] = 237;

  test_msg.certificate_bytes[80] = 240;

  test_msg.certificate_bytes[81] = 243;

  test_msg.certificate_bytes[82] = 246;

  test_msg.certificate_bytes[83] = 249;

  test_msg.certificate_bytes[84] = 252;

  test_msg.fingerprint[0] = 100;

  test_msg.fingerprint[1] = 101;

  test_msg.fingerprint[2] = 102;

  test_msg.fingerprint[3] = 103;

  test_msg.fingerprint[4] = 104;

  test_msg.fingerprint[5] = 105;

  test_msg.fingerprint[6] = 106;

  test_msg.fingerprint[7] = 107;

  test_msg.fingerprint[8] = 108;

  test_msg.fingerprint[9] = 109;

  test_msg.fingerprint[10] = 110;

  test_msg.fingerprint[11] = 111;

  test_msg.fingerprint[12] = 112;

  test_msg.fingerprint[13] = 113;

  test_msg.fingerprint[14] = 114;

  test_msg.fingerprint[15] = 115;

  test_msg.fingerprint[16] = 116;

  test_msg.fingerprint[17] = 117;

  test_msg.fingerprint[18] = 118;

  test_msg.fingerprint[19] = 119;
  test_msg.n_certificate_bytes = 85;
  test_msg.n_msg = 16;

  EXPECT_EQ(send_message(66, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.certificate_bytes[0], 0)
      << "incorrect value for last_msg_.certificate_bytes[0], expected 0, is "
      << last_msg_.certificate_bytes[0];
  EXPECT_EQ(last_msg_.certificate_bytes[1], 3)
      << "incorrect value for last_msg_.certificate_bytes[1], expected 3, is "
      << last_msg_.certificate_bytes[1];
  EXPECT_EQ(last_msg_.certificate_bytes[2], 6)
      << "incorrect value for last_msg_.certificate_bytes[2], expected 6, is "
      << last_msg_.certificate_bytes[2];
  EXPECT_EQ(last_msg_.certificate_bytes[3], 9)
      << "incorrect value for last_msg_.certificate_bytes[3], expected 9, is "
      << last_msg_.certificate_bytes[3];
  EXPECT_EQ(last_msg_.certificate_bytes[4], 12)
      << "incorrect value for last_msg_.certificate_bytes[4], expected 12, is "
      << last_msg_.certificate_bytes[4];
  EXPECT_EQ(last_msg_.certificate_bytes[5], 15)
      << "incorrect value for last_msg_.certificate_bytes[5], expected 15, is "
      << last_msg_.certificate_bytes[5];
  EXPECT_EQ(last_msg_.certificate_bytes[6], 18)
      << "incorrect value for last_msg_.certificate_bytes[6], expected 18, is "
      << last_msg_.certificate_bytes[6];
  EXPECT_EQ(last_msg_.certificate_bytes[7], 21)
      << "incorrect value for last_msg_.certificate_bytes[7], expected 21, is "
      << last_msg_.certificate_bytes[7];
  EXPECT_EQ(last_msg_.certificate_bytes[8], 24)
      << "incorrect value for last_msg_.certificate_bytes[8], expected 24, is "
      << last_msg_.certificate_bytes[8];
  EXPECT_EQ(last_msg_.certificate_bytes[9], 27)
      << "incorrect value for last_msg_.certificate_bytes[9], expected 27, is "
      << last_msg_.certificate_bytes[9];
  EXPECT_EQ(last_msg_.certificate_bytes[10], 30)
      << "incorrect value for last_msg_.certificate_bytes[10], expected 30, is "
      << last_msg_.certificate_bytes[10];
  EXPECT_EQ(last_msg_.certificate_bytes[11], 33)
      << "incorrect value for last_msg_.certificate_bytes[11], expected 33, is "
      << last_msg_.certificate_bytes[11];
  EXPECT_EQ(last_msg_.certificate_bytes[12], 36)
      << "incorrect value for last_msg_.certificate_bytes[12], expected 36, is "
      << last_msg_.certificate_bytes[12];
  EXPECT_EQ(last_msg_.certificate_bytes[13], 39)
      << "incorrect value for last_msg_.certificate_bytes[13], expected 39, is "
      << last_msg_.certificate_bytes[13];
  EXPECT_EQ(last_msg_.certificate_bytes[14], 42)
      << "incorrect value for last_msg_.certificate_bytes[14], expected 42, is "
      << last_msg_.certificate_bytes[14];
  EXPECT_EQ(last_msg_.certificate_bytes[15], 45)
      << "incorrect value for last_msg_.certificate_bytes[15], expected 45, is "
      << last_msg_.certificate_bytes[15];
  EXPECT_EQ(last_msg_.certificate_bytes[16], 48)
      << "incorrect value for last_msg_.certificate_bytes[16], expected 48, is "
      << last_msg_.certificate_bytes[16];
  EXPECT_EQ(last_msg_.certificate_bytes[17], 51)
      << "incorrect value for last_msg_.certificate_bytes[17], expected 51, is "
      << last_msg_.certificate_bytes[17];
  EXPECT_EQ(last_msg_.certificate_bytes[18], 54)
      << "incorrect value for last_msg_.certificate_bytes[18], expected 54, is "
      << last_msg_.certificate_bytes[18];
  EXPECT_EQ(last_msg_.certificate_bytes[19], 57)
      << "incorrect value for last_msg_.certificate_bytes[19], expected 57, is "
      << last_msg_.certificate_bytes[19];
  EXPECT_EQ(last_msg_.certificate_bytes[20], 60)
      << "incorrect value for last_msg_.certificate_bytes[20], expected 60, is "
      << last_msg_.certificate_bytes[20];
  EXPECT_EQ(last_msg_.certificate_bytes[21], 63)
      << "incorrect value for last_msg_.certificate_bytes[21], expected 63, is "
      << last_msg_.certificate_bytes[21];
  EXPECT_EQ(last_msg_.certificate_bytes[22], 66)
      << "incorrect value for last_msg_.certificate_bytes[22], expected 66, is "
      << last_msg_.certificate_bytes[22];
  EXPECT_EQ(last_msg_.certificate_bytes[23], 69)
      << "incorrect value for last_msg_.certificate_bytes[23], expected 69, is "
      << last_msg_.certificate_bytes[23];
  EXPECT_EQ(last_msg_.certificate_bytes[24], 72)
      << "incorrect value for last_msg_.certificate_bytes[24], expected 72, is "
      << last_msg_.certificate_bytes[24];
  EXPECT_EQ(last_msg_.certificate_bytes[25], 75)
      << "incorrect value for last_msg_.certificate_bytes[25], expected 75, is "
      << last_msg_.certificate_bytes[25];
  EXPECT_EQ(last_msg_.certificate_bytes[26], 78)
      << "incorrect value for last_msg_.certificate_bytes[26], expected 78, is "
      << last_msg_.certificate_bytes[26];
  EXPECT_EQ(last_msg_.certificate_bytes[27], 81)
      << "incorrect value for last_msg_.certificate_bytes[27], expected 81, is "
      << last_msg_.certificate_bytes[27];
  EXPECT_EQ(last_msg_.certificate_bytes[28], 84)
      << "incorrect value for last_msg_.certificate_bytes[28], expected 84, is "
      << last_msg_.certificate_bytes[28];
  EXPECT_EQ(last_msg_.certificate_bytes[29], 87)
      << "incorrect value for last_msg_.certificate_bytes[29], expected 87, is "
      << last_msg_.certificate_bytes[29];
  EXPECT_EQ(last_msg_.certificate_bytes[30], 90)
      << "incorrect value for last_msg_.certificate_bytes[30], expected 90, is "
      << last_msg_.certificate_bytes[30];
  EXPECT_EQ(last_msg_.certificate_bytes[31], 93)
      << "incorrect value for last_msg_.certificate_bytes[31], expected 93, is "
      << last_msg_.certificate_bytes[31];
  EXPECT_EQ(last_msg_.certificate_bytes[32], 96)
      << "incorrect value for last_msg_.certificate_bytes[32], expected 96, is "
      << last_msg_.certificate_bytes[32];
  EXPECT_EQ(last_msg_.certificate_bytes[33], 99)
      << "incorrect value for last_msg_.certificate_bytes[33], expected 99, is "
      << last_msg_.certificate_bytes[33];
  EXPECT_EQ(last_msg_.certificate_bytes[34], 102)
      << "incorrect value for last_msg_.certificate_bytes[34], expected 102, "
         "is "
      << last_msg_.certificate_bytes[34];
  EXPECT_EQ(last_msg_.certificate_bytes[35], 105)
      << "incorrect value for last_msg_.certificate_bytes[35], expected 105, "
         "is "
      << last_msg_.certificate_bytes[35];
  EXPECT_EQ(last_msg_.certificate_bytes[36], 108)
      << "incorrect value for last_msg_.certificate_bytes[36], expected 108, "
         "is "
      << last_msg_.certificate_bytes[36];
  EXPECT_EQ(last_msg_.certificate_bytes[37], 111)
      << "incorrect value for last_msg_.certificate_bytes[37], expected 111, "
         "is "
      << last_msg_.certificate_bytes[37];
  EXPECT_EQ(last_msg_.certificate_bytes[38], 114)
      << "incorrect value for last_msg_.certificate_bytes[38], expected 114, "
         "is "
      << last_msg_.certificate_bytes[38];
  EXPECT_EQ(last_msg_.certificate_bytes[39], 117)
      << "incorrect value for last_msg_.certificate_bytes[39], expected 117, "
         "is "
      << last_msg_.certificate_bytes[39];
  EXPECT_EQ(last_msg_.certificate_bytes[40], 120)
      << "incorrect value for last_msg_.certificate_bytes[40], expected 120, "
         "is "
      << last_msg_.certificate_bytes[40];
  EXPECT_EQ(last_msg_.certificate_bytes[41], 123)
      << "incorrect value for last_msg_.certificate_bytes[41], expected 123, "
         "is "
      << last_msg_.certificate_bytes[41];
  EXPECT_EQ(last_msg_.certificate_bytes[42], 126)
      << "incorrect value for last_msg_.certificate_bytes[42], expected 126, "
         "is "
      << last_msg_.certificate_bytes[42];
  EXPECT_EQ(last_msg_.certificate_bytes[43], 129)
      << "incorrect value for last_msg_.certificate_bytes[43], expected 129, "
         "is "
      << last_msg_.certificate_bytes[43];
  EXPECT_EQ(last_msg_.certificate_bytes[44], 132)
      << "incorrect value for last_msg_.certificate_bytes[44], expected 132, "
         "is "
      << last_msg_.certificate_bytes[44];
  EXPECT_EQ(last_msg_.certificate_bytes[45], 135)
      << "incorrect value for last_msg_.certificate_bytes[45], expected 135, "
         "is "
      << last_msg_.certificate_bytes[45];
  EXPECT_EQ(last_msg_.certificate_bytes[46], 138)
      << "incorrect value for last_msg_.certificate_bytes[46], expected 138, "
         "is "
      << last_msg_.certificate_bytes[46];
  EXPECT_EQ(last_msg_.certificate_bytes[47], 141)
      << "incorrect value for last_msg_.certificate_bytes[47], expected 141, "
         "is "
      << last_msg_.certificate_bytes[47];
  EXPECT_EQ(last_msg_.certificate_bytes[48], 144)
      << "incorrect value for last_msg_.certificate_bytes[48], expected 144, "
         "is "
      << last_msg_.certificate_bytes[48];
  EXPECT_EQ(last_msg_.certificate_bytes[49], 147)
      << "incorrect value for last_msg_.certificate_bytes[49], expected 147, "
         "is "
      << last_msg_.certificate_bytes[49];
  EXPECT_EQ(last_msg_.certificate_bytes[50], 150)
      << "incorrect value for last_msg_.certificate_bytes[50], expected 150, "
         "is "
      << last_msg_.certificate_bytes[50];
  EXPECT_EQ(last_msg_.certificate_bytes[51], 153)
      << "incorrect value for last_msg_.certificate_bytes[51], expected 153, "
         "is "
      << last_msg_.certificate_bytes[51];
  EXPECT_EQ(last_msg_.certificate_bytes[52], 156)
      << "incorrect value for last_msg_.certificate_bytes[52], expected 156, "
         "is "
      << last_msg_.certificate_bytes[52];
  EXPECT_EQ(last_msg_.certificate_bytes[53], 159)
      << "incorrect value for last_msg_.certificate_bytes[53], expected 159, "
         "is "
      << last_msg_.certificate_bytes[53];
  EXPECT_EQ(last_msg_.certificate_bytes[54], 162)
      << "incorrect value for last_msg_.certificate_bytes[54], expected 162, "
         "is "
      << last_msg_.certificate_bytes[54];
  EXPECT_EQ(last_msg_.certificate_bytes[55], 165)
      << "incorrect value for last_msg_.certificate_bytes[55], expected 165, "
         "is "
      << last_msg_.certificate_bytes[55];
  EXPECT_EQ(last_msg_.certificate_bytes[56], 168)
      << "incorrect value for last_msg_.certificate_bytes[56], expected 168, "
         "is "
      << last_msg_.certificate_bytes[56];
  EXPECT_EQ(last_msg_.certificate_bytes[57], 171)
      << "incorrect value for last_msg_.certificate_bytes[57], expected 171, "
         "is "
      << last_msg_.certificate_bytes[57];
  EXPECT_EQ(last_msg_.certificate_bytes[58], 174)
      << "incorrect value for last_msg_.certificate_bytes[58], expected 174, "
         "is "
      << last_msg_.certificate_bytes[58];
  EXPECT_EQ(last_msg_.certificate_bytes[59], 177)
      << "incorrect value for last_msg_.certificate_bytes[59], expected 177, "
         "is "
      << last_msg_.certificate_bytes[59];
  EXPECT_EQ(last_msg_.certificate_bytes[60], 180)
      << "incorrect value for last_msg_.certificate_bytes[60], expected 180, "
         "is "
      << last_msg_.certificate_bytes[60];
  EXPECT_EQ(last_msg_.certificate_bytes[61], 183)
      << "incorrect value for last_msg_.certificate_bytes[61], expected 183, "
         "is "
      << last_msg_.certificate_bytes[61];
  EXPECT_EQ(last_msg_.certificate_bytes[62], 186)
      << "incorrect value for last_msg_.certificate_bytes[62], expected 186, "
         "is "
      << last_msg_.certificate_bytes[62];
  EXPECT_EQ(last_msg_.certificate_bytes[63], 189)
      << "incorrect value for last_msg_.certificate_bytes[63], expected 189, "
         "is "
      << last_msg_.certificate_bytes[63];
  EXPECT_EQ(last_msg_.certificate_bytes[64], 192)
      << "incorrect value for last_msg_.certificate_bytes[64], expected 192, "
         "is "
      << last_msg_.certificate_bytes[64];
  EXPECT_EQ(last_msg_.certificate_bytes[65], 195)
      << "incorrect value for last_msg_.certificate_bytes[65], expected 195, "
         "is "
      << last_msg_.certificate_bytes[65];
  EXPECT_EQ(last_msg_.certificate_bytes[66], 198)
      << "incorrect value for last_msg_.certificate_bytes[66], expected 198, "
         "is "
      << last_msg_.certificate_bytes[66];
  EXPECT_EQ(last_msg_.certificate_bytes[67], 201)
      << "incorrect value for last_msg_.certificate_bytes[67], expected 201, "
         "is "
      << last_msg_.certificate_bytes[67];
  EXPECT_EQ(last_msg_.certificate_bytes[68], 204)
      << "incorrect value for last_msg_.certificate_bytes[68], expected 204, "
         "is "
      << last_msg_.certificate_bytes[68];
  EXPECT_EQ(last_msg_.certificate_bytes[69], 207)
      << "incorrect value for last_msg_.certificate_bytes[69], expected 207, "
         "is "
      << last_msg_.certificate_bytes[69];
  EXPECT_EQ(last_msg_.certificate_bytes[70], 210)
      << "incorrect value for last_msg_.certificate_bytes[70], expected 210, "
         "is "
      << last_msg_.certificate_bytes[70];
  EXPECT_EQ(last_msg_.certificate_bytes[71], 213)
      << "incorrect value for last_msg_.certificate_bytes[71], expected 213, "
         "is "
      << last_msg_.certificate_bytes[71];
  EXPECT_EQ(last_msg_.certificate_bytes[72], 216)
      << "incorrect value for last_msg_.certificate_bytes[72], expected 216, "
         "is "
      << last_msg_.certificate_bytes[72];
  EXPECT_EQ(last_msg_.certificate_bytes[73], 219)
      << "incorrect value for last_msg_.certificate_bytes[73], expected 219, "
         "is "
      << last_msg_.certificate_bytes[73];
  EXPECT_EQ(last_msg_.certificate_bytes[74], 222)
      << "incorrect value for last_msg_.certificate_bytes[74], expected 222, "
         "is "
      << last_msg_.certificate_bytes[74];
  EXPECT_EQ(last_msg_.certificate_bytes[75], 225)
      << "incorrect value for last_msg_.certificate_bytes[75], expected 225, "
         "is "
      << last_msg_.certificate_bytes[75];
  EXPECT_EQ(last_msg_.certificate_bytes[76], 228)
      << "incorrect value for last_msg_.certificate_bytes[76], expected 228, "
         "is "
      << last_msg_.certificate_bytes[76];
  EXPECT_EQ(last_msg_.certificate_bytes[77], 231)
      << "incorrect value for last_msg_.certificate_bytes[77], expected 231, "
         "is "
      << last_msg_.certificate_bytes[77];
  EXPECT_EQ(last_msg_.certificate_bytes[78], 234)
      << "incorrect value for last_msg_.certificate_bytes[78], expected 234, "
         "is "
      << last_msg_.certificate_bytes[78];
  EXPECT_EQ(last_msg_.certificate_bytes[79], 237)
      << "incorrect value for last_msg_.certificate_bytes[79], expected 237, "
         "is "
      << last_msg_.certificate_bytes[79];
  EXPECT_EQ(last_msg_.certificate_bytes[80], 240)
      << "incorrect value for last_msg_.certificate_bytes[80], expected 240, "
         "is "
      << last_msg_.certificate_bytes[80];
  EXPECT_EQ(last_msg_.certificate_bytes[81], 243)
      << "incorrect value for last_msg_.certificate_bytes[81], expected 243, "
         "is "
      << last_msg_.certificate_bytes[81];
  EXPECT_EQ(last_msg_.certificate_bytes[82], 246)
      << "incorrect value for last_msg_.certificate_bytes[82], expected 246, "
         "is "
      << last_msg_.certificate_bytes[82];
  EXPECT_EQ(last_msg_.certificate_bytes[83], 249)
      << "incorrect value for last_msg_.certificate_bytes[83], expected 249, "
         "is "
      << last_msg_.certificate_bytes[83];
  EXPECT_EQ(last_msg_.certificate_bytes[84], 252)
      << "incorrect value for last_msg_.certificate_bytes[84], expected 252, "
         "is "
      << last_msg_.certificate_bytes[84];
  EXPECT_EQ(last_msg_.fingerprint[0], 100)
      << "incorrect value for last_msg_.fingerprint[0], expected 100, is "
      << last_msg_.fingerprint[0];
  EXPECT_EQ(last_msg_.fingerprint[1], 101)
      << "incorrect value for last_msg_.fingerprint[1], expected 101, is "
      << last_msg_.fingerprint[1];
  EXPECT_EQ(last_msg_.fingerprint[2], 102)
      << "incorrect value for last_msg_.fingerprint[2], expected 102, is "
      << last_msg_.fingerprint[2];
  EXPECT_EQ(last_msg_.fingerprint[3], 103)
      << "incorrect value for last_msg_.fingerprint[3], expected 103, is "
      << last_msg_.fingerprint[3];
  EXPECT_EQ(last_msg_.fingerprint[4], 104)
      << "incorrect value for last_msg_.fingerprint[4], expected 104, is "
      << last_msg_.fingerprint[4];
  EXPECT_EQ(last_msg_.fingerprint[5], 105)
      << "incorrect value for last_msg_.fingerprint[5], expected 105, is "
      << last_msg_.fingerprint[5];
  EXPECT_EQ(last_msg_.fingerprint[6], 106)
      << "incorrect value for last_msg_.fingerprint[6], expected 106, is "
      << last_msg_.fingerprint[6];
  EXPECT_EQ(last_msg_.fingerprint[7], 107)
      << "incorrect value for last_msg_.fingerprint[7], expected 107, is "
      << last_msg_.fingerprint[7];
  EXPECT_EQ(last_msg_.fingerprint[8], 108)
      << "incorrect value for last_msg_.fingerprint[8], expected 108, is "
      << last_msg_.fingerprint[8];
  EXPECT_EQ(last_msg_.fingerprint[9], 109)
      << "incorrect value for last_msg_.fingerprint[9], expected 109, is "
      << last_msg_.fingerprint[9];
  EXPECT_EQ(last_msg_.fingerprint[10], 110)
      << "incorrect value for last_msg_.fingerprint[10], expected 110, is "
      << last_msg_.fingerprint[10];
  EXPECT_EQ(last_msg_.fingerprint[11], 111)
      << "incorrect value for last_msg_.fingerprint[11], expected 111, is "
      << last_msg_.fingerprint[11];
  EXPECT_EQ(last_msg_.fingerprint[12], 112)
      << "incorrect value for last_msg_.fingerprint[12], expected 112, is "
      << last_msg_.fingerprint[12];
  EXPECT_EQ(last_msg_.fingerprint[13], 113)
      << "incorrect value for last_msg_.fingerprint[13], expected 113, is "
      << last_msg_.fingerprint[13];
  EXPECT_EQ(last_msg_.fingerprint[14], 114)
      << "incorrect value for last_msg_.fingerprint[14], expected 114, is "
      << last_msg_.fingerprint[14];
  EXPECT_EQ(last_msg_.fingerprint[15], 115)
      << "incorrect value for last_msg_.fingerprint[15], expected 115, is "
      << last_msg_.fingerprint[15];
  EXPECT_EQ(last_msg_.fingerprint[16], 116)
      << "incorrect value for last_msg_.fingerprint[16], expected 116, is "
      << last_msg_.fingerprint[16];
  EXPECT_EQ(last_msg_.fingerprint[17], 117)
      << "incorrect value for last_msg_.fingerprint[17], expected 117, is "
      << last_msg_.fingerprint[17];
  EXPECT_EQ(last_msg_.fingerprint[18], 118)
      << "incorrect value for last_msg_.fingerprint[18], expected 118, is "
      << last_msg_.fingerprint[18];
  EXPECT_EQ(last_msg_.fingerprint[19], 119)
      << "incorrect value for last_msg_.fingerprint[19], expected 119, is "
      << last_msg_.fingerprint[19];
  EXPECT_EQ(last_msg_.n_certificate_bytes, 85)
      << "incorrect value for last_msg_.n_certificate_bytes, expected 85, is "
      << last_msg_.n_certificate_bytes;
  EXPECT_EQ(last_msg_.n_msg, 16)
      << "incorrect value for last_msg_.n_msg, expected 16, is "
      << last_msg_.n_msg;
}
