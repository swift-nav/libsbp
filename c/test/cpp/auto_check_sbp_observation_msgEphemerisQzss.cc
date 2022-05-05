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
// spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisQzss.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_observation_msgEphemerisQzss0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_ephemeris_qzss_t> {
 public:
  Test_auto_check_sbp_observation_msgEphemerisQzss0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_ephemeris_qzss_t>(this),
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
                      const sbp_msg_ephemeris_qzss_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_ephemeris_qzss_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_observation_msgEphemerisQzss0, Test) {
  uint8_t encoded_frame[] = {
      85,  142, 0,   128, 240, 139, 193, 31,  208, 221, 6,   0,   106, 8,   0,
      0,   0,   64,  64,  56,  0,   0,   0,   0,   0,   0,   192, 177, 0,   232,
      228, 195, 0,   160, 19,  194, 0,   224, 135, 183, 0,   96,  10,  55,  0,
      192, 157, 181, 0,   0,   46,  52,  167, 72,  107, 105, 179, 1,   39,  62,
      15,  224, 158, 211, 241, 164, 211, 63,  0,   0,   0,   24,  251, 83,  179,
      63,  0,   0,   0,   34,  44,  93,  185, 64,  143, 62,  206, 232, 193, 181,
      242, 191, 207, 216, 69,  106, 98,  255, 39,  190, 65,  132, 95,  22,  48,
      15,  249, 191, 249, 82,  67,  94,  30,  100, 231, 63,  117, 167, 187, 233,
      187, 253, 181, 61,  160, 129, 193, 185, 0,   0,   168, 172, 0,   0,   0,
      0,   208, 221, 6,   0,   106, 8,   49,  49,  3,   126, 23,
  };

  sbp_msg_ephemeris_qzss_t test_msg{};
  test_msg.af0 = -0.00036908406764268875;
  test_msg.af1 = -4.774847184307873e-12;
  test_msg.af2 = 0.0;
  test_msg.c_ic = -1.1753290891647339e-06;
  test_msg.c_is = 1.6205012798309326e-07;
  test_msg.c_rc = -36.90625;
  test_msg.c_rs = -457.8125;
  test_msg.c_uc = -1.6197562217712402e-05;
  test_msg.c_us = 8.247792720794678e-06;
  test_msg.common.fit_interval = 14400;
  test_msg.common.health_bits = 0;
  test_msg.common.sid.code = 31;
  test_msg.common.sid.sat = 193;
  test_msg.common.toe.tow = 450000;
  test_msg.common.toe.wn = 2154;
  test_msg.common.ura = 2.0;
  test_msg.common.valid = 0;
  test_msg.dn = 2.678325848736433e-09;
  test_msg.ecc = 0.07550019584596157;
  test_msg.inc = 0.7309715119432375;
  test_msg.inc_dot = 2.0000833114980698e-11;
  test_msg.iodc = 817;
  test_msg.iode = 49;
  test_msg.m0 = 0.30694242158961144;
  test_msg.omega0 = -1.1693743795366662;
  test_msg.omegadot = -2.7936877968817684e-09;
  test_msg.sqrta = 6493.172393798828;
  test_msg.tgd = -5.587935447692871e-09;
  test_msg.toc.tow = 450000;
  test_msg.toc.wn = 2154;
  test_msg.w = -1.5662079690885238;

  EXPECT_EQ(send_message(61568, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 61568);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.af0 * 100 - -0.000369084067643 * 100), 0.05)
      << "incorrect value for last_msg_.af0, expected -0.000369084067643, is "
      << last_msg_.af0;
  EXPECT_LT((last_msg_.af1 * 100 - -4.77484718431e-12 * 100), 0.05)
      << "incorrect value for last_msg_.af1, expected -4.77484718431e-12, is "
      << last_msg_.af1;
  EXPECT_LT((last_msg_.af2 * 100 - 0.0 * 100), 0.05)
      << "incorrect value for last_msg_.af2, expected 0.0, is "
      << last_msg_.af2;
  EXPECT_LT((last_msg_.c_ic * 100 - -1.17532908916e-06 * 100), 0.05)
      << "incorrect value for last_msg_.c_ic, expected -1.17532908916e-06, is "
      << last_msg_.c_ic;
  EXPECT_LT((last_msg_.c_is * 100 - 1.62050127983e-07 * 100), 0.05)
      << "incorrect value for last_msg_.c_is, expected 1.62050127983e-07, is "
      << last_msg_.c_is;
  EXPECT_LT((last_msg_.c_rc * 100 - -36.90625 * 100), 0.05)
      << "incorrect value for last_msg_.c_rc, expected -36.90625, is "
      << last_msg_.c_rc;
  EXPECT_LT((last_msg_.c_rs * 100 - -457.8125 * 100), 0.05)
      << "incorrect value for last_msg_.c_rs, expected -457.8125, is "
      << last_msg_.c_rs;
  EXPECT_LT((last_msg_.c_uc * 100 - -1.61975622177e-05 * 100), 0.05)
      << "incorrect value for last_msg_.c_uc, expected -1.61975622177e-05, is "
      << last_msg_.c_uc;
  EXPECT_LT((last_msg_.c_us * 100 - 8.24779272079e-06 * 100), 0.05)
      << "incorrect value for last_msg_.c_us, expected 8.24779272079e-06, is "
      << last_msg_.c_us;
  EXPECT_EQ(last_msg_.common.fit_interval, 14400)
      << "incorrect value for last_msg_.common.fit_interval, expected 14400, "
         "is "
      << last_msg_.common.fit_interval;
  EXPECT_EQ(last_msg_.common.health_bits, 0)
      << "incorrect value for last_msg_.common.health_bits, expected 0, is "
      << last_msg_.common.health_bits;
  EXPECT_EQ(last_msg_.common.sid.code, 31)
      << "incorrect value for last_msg_.common.sid.code, expected 31, is "
      << last_msg_.common.sid.code;
  EXPECT_EQ(last_msg_.common.sid.sat, 193)
      << "incorrect value for last_msg_.common.sid.sat, expected 193, is "
      << last_msg_.common.sid.sat;
  EXPECT_EQ(last_msg_.common.toe.tow, 450000)
      << "incorrect value for last_msg_.common.toe.tow, expected 450000, is "
      << last_msg_.common.toe.tow;
  EXPECT_EQ(last_msg_.common.toe.wn, 2154)
      << "incorrect value for last_msg_.common.toe.wn, expected 2154, is "
      << last_msg_.common.toe.wn;
  EXPECT_LT((last_msg_.common.ura * 100 - 2.0 * 100), 0.05)
      << "incorrect value for last_msg_.common.ura, expected 2.0, is "
      << last_msg_.common.ura;
  EXPECT_EQ(last_msg_.common.valid, 0)
      << "incorrect value for last_msg_.common.valid, expected 0, is "
      << last_msg_.common.valid;
  EXPECT_LT((last_msg_.dn * 100 - 2.67832584874e-09 * 100), 0.05)
      << "incorrect value for last_msg_.dn, expected 2.67832584874e-09, is "
      << last_msg_.dn;
  EXPECT_LT((last_msg_.ecc * 100 - 0.075500195846 * 100), 0.05)
      << "incorrect value for last_msg_.ecc, expected 0.075500195846, is "
      << last_msg_.ecc;
  EXPECT_LT((last_msg_.inc * 100 - 0.730971511943 * 100), 0.05)
      << "incorrect value for last_msg_.inc, expected 0.730971511943, is "
      << last_msg_.inc;
  EXPECT_LT((last_msg_.inc_dot * 100 - 2.0000833115e-11 * 100), 0.05)
      << "incorrect value for last_msg_.inc_dot, expected 2.0000833115e-11, is "
      << last_msg_.inc_dot;
  EXPECT_EQ(last_msg_.iodc, 817)
      << "incorrect value for last_msg_.iodc, expected 817, is "
      << last_msg_.iodc;
  EXPECT_EQ(last_msg_.iode, 49)
      << "incorrect value for last_msg_.iode, expected 49, is "
      << last_msg_.iode;
  EXPECT_LT((last_msg_.m0 * 100 - 0.30694242159 * 100), 0.05)
      << "incorrect value for last_msg_.m0, expected 0.30694242159, is "
      << last_msg_.m0;
  EXPECT_LT((last_msg_.omega0 * 100 - -1.16937437954 * 100), 0.05)
      << "incorrect value for last_msg_.omega0, expected -1.16937437954, is "
      << last_msg_.omega0;
  EXPECT_LT((last_msg_.omegadot * 100 - -2.79368779688e-09 * 100), 0.05)
      << "incorrect value for last_msg_.omegadot, expected -2.79368779688e-09, "
         "is "
      << last_msg_.omegadot;
  EXPECT_LT((last_msg_.sqrta * 100 - 6493.1723938 * 100), 0.05)
      << "incorrect value for last_msg_.sqrta, expected 6493.1723938, is "
      << last_msg_.sqrta;
  EXPECT_LT((last_msg_.tgd * 100 - -5.58793544769e-09 * 100), 0.05)
      << "incorrect value for last_msg_.tgd, expected -5.58793544769e-09, is "
      << last_msg_.tgd;
  EXPECT_EQ(last_msg_.toc.tow, 450000)
      << "incorrect value for last_msg_.toc.tow, expected 450000, is "
      << last_msg_.toc.tow;
  EXPECT_EQ(last_msg_.toc.wn, 2154)
      << "incorrect value for last_msg_.toc.wn, expected 2154, is "
      << last_msg_.toc.wn;
  EXPECT_LT((last_msg_.w * 100 - -1.56620796909 * 100), 0.05)
      << "incorrect value for last_msg_.w, expected -1.56620796909, is "
      << last_msg_.w;
}
