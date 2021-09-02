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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisBds.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_observation_MsgEphemerisBds0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ephemeris_bds_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgEphemerisBds0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ephemeris_bds_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ephemeris_bds_t *>(last_msg_storage_)),
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
                      const msg_ephemeris_bds_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ephemeris_bds_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgEphemerisBds0, Test) {
  uint8_t encoded_frame[] = {
      85,  137, 0,   128, 240, 147, 8,   12,  174, 179, 6,   0,   106, 8,   0,
      0,   0,   64,  48,  42,  0,   0,   1,   0,   125, 99,  52,  50,  207, 46,
      151, 176, 0,   112, 96,  67,  0,   164, 106, 67,  0,   60,  255, 54,  0,
      224, 47,  53,  0,   0,   143, 179, 0,   192, 190, 52,  146, 101, 162, 196,
      109, 104, 19,  62,  253, 87,  86,  202, 62,  28,  251, 63,  0,   0,   0,
      96,  151, 60,  117, 63,  0,   0,   128, 154, 127, 93,  185, 64,  151, 193,
      64,  0,   10,  166, 4,   192, 160, 75,  174, 98,  8,   201, 35,  190, 205,
      29,  12,  71,  189, 150, 5,   192, 176, 72,  249, 189, 193, 172, 240, 63,
      72,  249, 188, 180, 160, 203, 9,   62,  0,   0,   0,   0,   92,  51,  77,
      191, 0,   128, 174, 43,  0,   0,   88,  161, 174, 179, 6,   0,   106, 8,
      6,   5,   0,   157, 249,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ephemeris_bds_t *test_msg = (msg_ephemeris_bds_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->af0 = -0.0008911322802305222;
  test_msg->af1 = 1.2398970739013748e-12;
  test_msg->af2 = -7.318364664277155e-19;
  test_msg->c_ic = -6.658956408500671e-08;
  test_msg->c_is = 3.5529956221580505e-07;
  test_msg->c_rc = 234.640625;
  test_msg->c_rs = 224.4375;
  test_msg->c_uc = 7.606577128171921e-06;
  test_msg->c_us = 6.551854312419891e-07;
  test_msg->common.fit_interval = 10800;
  test_msg->common.health_bits = 0;
  test_msg->common.sid.code = 12;
  test_msg->common.sid.sat = 8;
  test_msg->common.toe.tow = 439214;
  test_msg->common.toe.wn = 2154;
  test_msg->common.ura = 2.0;
  test_msg->common.valid = 1;
  test_msg->dn = 1.1296899132622133e-09;
  test_msg->ecc = 0.005184737499803305;
  test_msg->inc = 1.0421769543504915;
  test_msg->inc_dot = 7.507455572801683e-10;
  test_msg->iodc = 5;
  test_msg->iode = 6;
  test_msg->m0 = 1.6943958190727237;
  test_msg->omega0 = -2.581073762870982;
  test_msg->omegadot = -2.303310227830545e-09;
  test_msg->sqrta = 6493.49845123291;
  test_msg->tgd1 = 1.0499999980595476e-08;
  test_msg->tgd2 = -1.0999999799921056e-09;
  test_msg->toc.tow = 439214;
  test_msg->toc.wn = 2154;
  test_msg->w = -2.698603205735458;

  EXPECT_EQ(send_message(0x89, 61568, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 61568);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->af0 * 100 - -0.000891132280231 * 100), 0.05)
      << "incorrect value for af0, expected -0.000891132280231, is "
      << last_msg_->af0;
  EXPECT_LT((last_msg_->af1 * 100 - 1.2398970739e-12 * 100), 0.05)
      << "incorrect value for af1, expected 1.2398970739e-12, is "
      << last_msg_->af1;
  EXPECT_LT((last_msg_->af2 * 100 - -7.31836466428e-19 * 100), 0.05)
      << "incorrect value for af2, expected -7.31836466428e-19, is "
      << last_msg_->af2;
  EXPECT_LT((last_msg_->c_ic * 100 - -6.6589564085e-08 * 100), 0.05)
      << "incorrect value for c_ic, expected -6.6589564085e-08, is "
      << last_msg_->c_ic;
  EXPECT_LT((last_msg_->c_is * 100 - 3.55299562216e-07 * 100), 0.05)
      << "incorrect value for c_is, expected 3.55299562216e-07, is "
      << last_msg_->c_is;
  EXPECT_LT((last_msg_->c_rc * 100 - 234.640625 * 100), 0.05)
      << "incorrect value for c_rc, expected 234.640625, is "
      << last_msg_->c_rc;
  EXPECT_LT((last_msg_->c_rs * 100 - 224.4375 * 100), 0.05)
      << "incorrect value for c_rs, expected 224.4375, is " << last_msg_->c_rs;
  EXPECT_LT((last_msg_->c_uc * 100 - 7.60657712817e-06 * 100), 0.05)
      << "incorrect value for c_uc, expected 7.60657712817e-06, is "
      << last_msg_->c_uc;
  EXPECT_LT((last_msg_->c_us * 100 - 6.55185431242e-07 * 100), 0.05)
      << "incorrect value for c_us, expected 6.55185431242e-07, is "
      << last_msg_->c_us;
  EXPECT_EQ(last_msg_->common.fit_interval, 10800)
      << "incorrect value for common.fit_interval, expected 10800, is "
      << last_msg_->common.fit_interval;
  EXPECT_EQ(last_msg_->common.health_bits, 0)
      << "incorrect value for common.health_bits, expected 0, is "
      << last_msg_->common.health_bits;
  EXPECT_EQ(last_msg_->common.sid.code, 12)
      << "incorrect value for common.sid.code, expected 12, is "
      << last_msg_->common.sid.code;
  EXPECT_EQ(last_msg_->common.sid.sat, 8)
      << "incorrect value for common.sid.sat, expected 8, is "
      << last_msg_->common.sid.sat;
  EXPECT_EQ(last_msg_->common.toe.tow, 439214)
      << "incorrect value for common.toe.tow, expected 439214, is "
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
  EXPECT_LT((last_msg_->dn * 100 - 1.12968991326e-09 * 100), 0.05)
      << "incorrect value for dn, expected 1.12968991326e-09, is "
      << last_msg_->dn;
  EXPECT_LT((last_msg_->ecc * 100 - 0.0051847374998 * 100), 0.05)
      << "incorrect value for ecc, expected 0.0051847374998, is "
      << last_msg_->ecc;
  EXPECT_LT((last_msg_->inc * 100 - 1.04217695435 * 100), 0.05)
      << "incorrect value for inc, expected 1.04217695435, is "
      << last_msg_->inc;
  EXPECT_LT((last_msg_->inc_dot * 100 - 7.5074555728e-10 * 100), 0.05)
      << "incorrect value for inc_dot, expected 7.5074555728e-10, is "
      << last_msg_->inc_dot;
  EXPECT_EQ(last_msg_->iodc, 5)
      << "incorrect value for iodc, expected 5, is " << last_msg_->iodc;
  EXPECT_EQ(last_msg_->iode, 6)
      << "incorrect value for iode, expected 6, is " << last_msg_->iode;
  EXPECT_LT((last_msg_->m0 * 100 - 1.69439581907 * 100), 0.05)
      << "incorrect value for m0, expected 1.69439581907, is " << last_msg_->m0;
  EXPECT_LT((last_msg_->omega0 * 100 - -2.58107376287 * 100), 0.05)
      << "incorrect value for omega0, expected -2.58107376287, is "
      << last_msg_->omega0;
  EXPECT_LT((last_msg_->omegadot * 100 - -2.30331022783e-09 * 100), 0.05)
      << "incorrect value for omegadot, expected -2.30331022783e-09, is "
      << last_msg_->omegadot;
  EXPECT_LT((last_msg_->sqrta * 100 - 6493.49845123 * 100), 0.05)
      << "incorrect value for sqrta, expected 6493.49845123, is "
      << last_msg_->sqrta;
  EXPECT_LT((last_msg_->tgd1 * 100 - 1.04999999806e-08 * 100), 0.05)
      << "incorrect value for tgd1, expected 1.04999999806e-08, is "
      << last_msg_->tgd1;
  EXPECT_LT((last_msg_->tgd2 * 100 - -1.09999997999e-09 * 100), 0.05)
      << "incorrect value for tgd2, expected -1.09999997999e-09, is "
      << last_msg_->tgd2;
  EXPECT_EQ(last_msg_->toc.tow, 439214)
      << "incorrect value for toc.tow, expected 439214, is "
      << last_msg_->toc.tow;
  EXPECT_EQ(last_msg_->toc.wn, 2154)
      << "incorrect value for toc.wn, expected 2154, is " << last_msg_->toc.wn;
  EXPECT_LT((last_msg_->w * 100 - -2.69860320574 * 100), 0.05)
      << "incorrect value for w, expected -2.69860320574, is " << last_msg_->w;
}
