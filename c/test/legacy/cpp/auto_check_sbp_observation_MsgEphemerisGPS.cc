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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGPS.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_observation_MsgEphemerisGPS0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ephemeris_gps_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgEphemerisGPS0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ephemeris_gps_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ephemeris_gps_t *>(last_msg_storage_)),
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
                      const msg_ephemeris_gps_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ephemeris_gps_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgEphemerisGPS0, Test) {
  uint8_t encoded_frame[] = {
      85,  138, 0,   10,  9,   139, 22,  0,   176, 207, 6,   0,   106, 8,   0,
      0,   0,   64,  64,  56,  0,   0,   1,   0,   0,   0,   152, 178, 0,   64,
      81,  194, 0,   80,  154, 67,  0,   32,  56,  182, 0,   128, 82,  54,  0,
      0,   0,   50,  0,   0,   248, 179, 114, 216, 96,  180, 49,  117, 56,  62,
      142, 41,  5,   235, 95,  135, 150, 191, 0,   0,   0,   32,  191, 247, 124,
      63,  0,   0,   192, 206, 140, 33,  180, 64,  41,  131, 179, 134, 141, 248,
      253, 191, 227, 133, 81,  54,  204, 30,  67,  190, 216, 59,  199, 39,  96,
      168, 239, 191, 71,  11,  217, 147, 145, 228, 237, 63,  221, 47,  100, 224,
      255, 47,  198, 189, 96,  139, 37,  186, 0,   0,   30,  45,  0,   0,   0,
      0,   176, 207, 6,   0,   106, 8,   45,  45,  0,   170, 4,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ephemeris_gps_t *test_msg = (msg_ephemeris_gps_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->af0 = -0.0006315018981695175;
  test_msg->af1 = 8.981260180007666e-12;
  test_msg->af2 = 0.0;
  test_msg->c_ic = 7.450580596923828e-09;
  test_msg->c_is = -1.1548399925231934e-07;
  test_msg->c_rc = 308.625;
  test_msg->c_rs = -52.3125;
  test_msg->c_uc = -2.7436763048171997e-06;
  test_msg->c_us = 3.1366944313049316e-06;
  test_msg->common.fit_interval = 14400;
  test_msg->common.health_bits = 0;
  test_msg->common.sid.code = 0;
  test_msg->common.sid.sat = 22;
  test_msg->common.toe.tow = 446384;
  test_msg->common.toe.wn = 2154;
  test_msg->common.ura = 2.0;
  test_msg->common.valid = 1;
  test_msg->dn = 5.694522914022375e-09;
  test_msg->ecc = 0.007072207052260637;
  test_msg->inc = 0.9341514480259797;
  test_msg->inc_dot = -4.035882396415757e-11;
  test_msg->iodc = 45;
  test_msg->iode = 45;
  test_msg->m0 = -0.02200078842114688;
  test_msg->omega0 = -1.8731818448797617;
  test_msg->omegadot = -8.903585155774196e-09;
  test_msg->sqrta = 5153.550029754639;
  test_msg->tgd = -1.7695128917694092e-08;
  test_msg->toc.tow = 446384;
  test_msg->toc.wn = 2154;
  test_msg->w = -0.9893036629599647;

  EXPECT_EQ(send_message(0x8a, 2314, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 2314);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->af0 * 100 - -0.00063150189817 * 100), 0.05)
      << "incorrect value for af0, expected -0.00063150189817, is "
      << last_msg_->af0;
  EXPECT_LT((last_msg_->af1 * 100 - 8.98126018001e-12 * 100), 0.05)
      << "incorrect value for af1, expected 8.98126018001e-12, is "
      << last_msg_->af1;
  EXPECT_LT((last_msg_->af2 * 100 - 0.0 * 100), 0.05)
      << "incorrect value for af2, expected 0.0, is " << last_msg_->af2;
  EXPECT_LT((last_msg_->c_ic * 100 - 7.45058059692e-09 * 100), 0.05)
      << "incorrect value for c_ic, expected 7.45058059692e-09, is "
      << last_msg_->c_ic;
  EXPECT_LT((last_msg_->c_is * 100 - -1.15483999252e-07 * 100), 0.05)
      << "incorrect value for c_is, expected -1.15483999252e-07, is "
      << last_msg_->c_is;
  EXPECT_LT((last_msg_->c_rc * 100 - 308.625 * 100), 0.05)
      << "incorrect value for c_rc, expected 308.625, is " << last_msg_->c_rc;
  EXPECT_LT((last_msg_->c_rs * 100 - -52.3125 * 100), 0.05)
      << "incorrect value for c_rs, expected -52.3125, is " << last_msg_->c_rs;
  EXPECT_LT((last_msg_->c_uc * 100 - -2.74367630482e-06 * 100), 0.05)
      << "incorrect value for c_uc, expected -2.74367630482e-06, is "
      << last_msg_->c_uc;
  EXPECT_LT((last_msg_->c_us * 100 - 3.1366944313e-06 * 100), 0.05)
      << "incorrect value for c_us, expected 3.1366944313e-06, is "
      << last_msg_->c_us;
  EXPECT_EQ(last_msg_->common.fit_interval, 14400)
      << "incorrect value for common.fit_interval, expected 14400, is "
      << last_msg_->common.fit_interval;
  EXPECT_EQ(last_msg_->common.health_bits, 0)
      << "incorrect value for common.health_bits, expected 0, is "
      << last_msg_->common.health_bits;
  EXPECT_EQ(last_msg_->common.sid.code, 0)
      << "incorrect value for common.sid.code, expected 0, is "
      << last_msg_->common.sid.code;
  EXPECT_EQ(last_msg_->common.sid.sat, 22)
      << "incorrect value for common.sid.sat, expected 22, is "
      << last_msg_->common.sid.sat;
  EXPECT_EQ(last_msg_->common.toe.tow, 446384)
      << "incorrect value for common.toe.tow, expected 446384, is "
      << last_msg_->common.toe.tow;
  EXPECT_EQ(last_msg_->common.toe.wn, 2154)
      << "incorrect value for common.toe.wn, expected 2154, is "
      << last_msg_->common.toe.wn;
  EXPECT_LT((last_msg_->common.ura * 100 - 2.0 * 100), 0.05)
      << "incorrect value for common.ura, expected 2.0, is "
      << last_msg_->common.ura;
  EXPECT_EQ(last_msg_->common.valid, 1)
      << "incorrect value for common.valid, expected 1, is "
      << last_msg_->common.valid;
  EXPECT_LT((last_msg_->dn * 100 - 5.69452291402e-09 * 100), 0.05)
      << "incorrect value for dn, expected 5.69452291402e-09, is "
      << last_msg_->dn;
  EXPECT_LT((last_msg_->ecc * 100 - 0.00707220705226 * 100), 0.05)
      << "incorrect value for ecc, expected 0.00707220705226, is "
      << last_msg_->ecc;
  EXPECT_LT((last_msg_->inc * 100 - 0.934151448026 * 100), 0.05)
      << "incorrect value for inc, expected 0.934151448026, is "
      << last_msg_->inc;
  EXPECT_LT((last_msg_->inc_dot * 100 - -4.03588239642e-11 * 100), 0.05)
      << "incorrect value for inc_dot, expected -4.03588239642e-11, is "
      << last_msg_->inc_dot;
  EXPECT_EQ(last_msg_->iodc, 45)
      << "incorrect value for iodc, expected 45, is " << last_msg_->iodc;
  EXPECT_EQ(last_msg_->iode, 45)
      << "incorrect value for iode, expected 45, is " << last_msg_->iode;
  EXPECT_LT((last_msg_->m0 * 100 - -0.0220007884211 * 100), 0.05)
      << "incorrect value for m0, expected -0.0220007884211, is "
      << last_msg_->m0;
  EXPECT_LT((last_msg_->omega0 * 100 - -1.87318184488 * 100), 0.05)
      << "incorrect value for omega0, expected -1.87318184488, is "
      << last_msg_->omega0;
  EXPECT_LT((last_msg_->omegadot * 100 - -8.90358515577e-09 * 100), 0.05)
      << "incorrect value for omegadot, expected -8.90358515577e-09, is "
      << last_msg_->omegadot;
  EXPECT_LT((last_msg_->sqrta * 100 - 5153.55002975 * 100), 0.05)
      << "incorrect value for sqrta, expected 5153.55002975, is "
      << last_msg_->sqrta;
  EXPECT_LT((last_msg_->tgd * 100 - -1.76951289177e-08 * 100), 0.05)
      << "incorrect value for tgd, expected -1.76951289177e-08, is "
      << last_msg_->tgd;
  EXPECT_EQ(last_msg_->toc.tow, 446384)
      << "incorrect value for toc.tow, expected 446384, is "
      << last_msg_->toc.tow;
  EXPECT_EQ(last_msg_->toc.wn, 2154)
      << "incorrect value for toc.wn, expected 2154, is " << last_msg_->toc.wn;
  EXPECT_LT((last_msg_->w * 100 - -0.98930366296 * 100), 0.05)
      << "incorrect value for w, expected -0.98930366296, is " << last_msg_->w;
}
