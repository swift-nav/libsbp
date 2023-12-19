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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGalDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/legacy_state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/observation.h>
class Test_legacy_auto_check_sbp_observation_MsgEphemerisGalDepA0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ephemeris_gal_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgEphemerisGalDepA0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ephemeris_gal_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_ephemeris_gal_dep_a_t *>(last_msg_storage_)),
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
                      const msg_ephemeris_gal_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ephemeris_gal_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgEphemerisGalDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  149, 0,   195, 4,   152, 27,  14,  32,  217, 6,   0,   106, 8,   102,
      102, 230, 64,  64,  56,  0,   0,   1,   0,   154, 153, 153, 63,  205, 204,
      12,  64,  0,   0,   34,  65,  0,   184, 132, 67,  102, 102, 166, 64,  102,
      102, 198, 64,  205, 204, 76,  64,  102, 102, 134, 64,  217, 204, 130, 105,
      128, 182, 43,  62,  248, 106, 31,  220, 8,   136, 253, 191, 0,   0,   0,
      0,   151, 92,  38,  63,  0,   0,   0,   55,  154, 64,  181, 64,  56,  38,
      1,   141, 255, 182, 242, 63,  222, 147, 136, 39,  79,  186, 56,  190, 80,
      114, 204, 251, 193, 92,  191, 63,  237, 55,  19,  41,  177, 73,  239, 63,
      49,  65,  189, 240, 8,   216, 245, 189, 255, 255, 255, 255, 67,  235, 241,
      190, 255, 255, 255, 255, 255, 255, 161, 189, 205, 204, 76,  62,  32,  217,
      6,   0,   106, 8,   108, 0,   108, 0,   168, 49,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ephemeris_gal_dep_a_t *test_msg =
      (msg_ephemeris_gal_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->af0 = -1.7088896129280325e-05;
  test_msg->af1 = -8.185452315956353e-12;
  test_msg->af2 = 0.20000000298023224;
  test_msg->bgd_e1e5a = 1.2000000476837158;
  test_msg->bgd_e1e5b = 2.200000047683716;
  test_msg->c_ic = 3.200000047683716;
  test_msg->c_is = 4.199999809265137;
  test_msg->c_rc = 265.4375;
  test_msg->c_rs = 10.125;
  test_msg->c_uc = 5.199999809265137;
  test_msg->c_us = 6.199999809265137;
  test_msg->common.fit_interval = 14400;
  test_msg->common.health_bits = 0;
  test_msg->common.sid.code = 14;
  test_msg->common.sid.sat = 27;
  test_msg->common.toe.tow = 448800;
  test_msg->common.toe.wn = 2154;
  test_msg->common.ura = 7.199999809265137;
  test_msg->common.valid = 1;
  test_msg->dn = 3.2262058129932258e-09;
  test_msg->ecc = 0.00017060607206076384;
  test_msg->inc = 0.9777456094977858;
  test_msg->inc_dot = -3.1787038343451465e-10;
  test_msg->iodc = 108;
  test_msg->iode = 108;
  test_msg->m0 = -1.8457115744155868;
  test_msg->omega0 = 1.16967730598334;
  test_msg->omegadot = -5.757382675240872e-09;
  test_msg->sqrta = 5440.602401733398;
  test_msg->toc.tow = 448800;
  test_msg->toc.wn = 2154;
  test_msg->w = 0.12250912091662625;

  EXPECT_EQ(send_message(0x95, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->af0 * 100 - -1.70888961293e-05 * 100), 0.05)
      << "incorrect value for af0, expected -1.70888961293e-05, is "
      << last_msg_->af0;
  EXPECT_LT((last_msg_->af1 * 100 - -8.18545231596e-12 * 100), 0.05)
      << "incorrect value for af1, expected -8.18545231596e-12, is "
      << last_msg_->af1;
  EXPECT_LT((last_msg_->af2 * 100 - 0.20000000298 * 100), 0.05)
      << "incorrect value for af2, expected 0.20000000298, is "
      << last_msg_->af2;
  EXPECT_LT((last_msg_->bgd_e1e5a * 100 - 1.20000004768 * 100), 0.05)
      << "incorrect value for bgd_e1e5a, expected 1.20000004768, is "
      << last_msg_->bgd_e1e5a;
  EXPECT_LT((last_msg_->bgd_e1e5b * 100 - 2.20000004768 * 100), 0.05)
      << "incorrect value for bgd_e1e5b, expected 2.20000004768, is "
      << last_msg_->bgd_e1e5b;
  EXPECT_LT((last_msg_->c_ic * 100 - 3.20000004768 * 100), 0.05)
      << "incorrect value for c_ic, expected 3.20000004768, is "
      << last_msg_->c_ic;
  EXPECT_LT((last_msg_->c_is * 100 - 4.19999980927 * 100), 0.05)
      << "incorrect value for c_is, expected 4.19999980927, is "
      << last_msg_->c_is;
  EXPECT_LT((last_msg_->c_rc * 100 - 265.4375 * 100), 0.05)
      << "incorrect value for c_rc, expected 265.4375, is " << last_msg_->c_rc;
  EXPECT_LT((last_msg_->c_rs * 100 - 10.125 * 100), 0.05)
      << "incorrect value for c_rs, expected 10.125, is " << last_msg_->c_rs;
  EXPECT_LT((last_msg_->c_uc * 100 - 5.19999980927 * 100), 0.05)
      << "incorrect value for c_uc, expected 5.19999980927, is "
      << last_msg_->c_uc;
  EXPECT_LT((last_msg_->c_us * 100 - 6.19999980927 * 100), 0.05)
      << "incorrect value for c_us, expected 6.19999980927, is "
      << last_msg_->c_us;
  EXPECT_EQ(last_msg_->common.fit_interval, 14400)
      << "incorrect value for common.fit_interval, expected 14400, is "
      << last_msg_->common.fit_interval;
  EXPECT_EQ(last_msg_->common.health_bits, 0)
      << "incorrect value for common.health_bits, expected 0, is "
      << last_msg_->common.health_bits;
  EXPECT_EQ(last_msg_->common.sid.code, 14)
      << "incorrect value for common.sid.code, expected 14, is "
      << last_msg_->common.sid.code;
  EXPECT_EQ(last_msg_->common.sid.sat, 27)
      << "incorrect value for common.sid.sat, expected 27, is "
      << last_msg_->common.sid.sat;
  EXPECT_EQ(last_msg_->common.toe.tow, 448800)
      << "incorrect value for common.toe.tow, expected 448800, is "
      << last_msg_->common.toe.tow;
  EXPECT_EQ(last_msg_->common.toe.wn, 2154)
      << "incorrect value for common.toe.wn, expected 2154, is "
      << last_msg_->common.toe.wn;
  EXPECT_LT((last_msg_->common.ura * 100 - 7.19999980927 * 100), 0.05)
      << "incorrect value for common.ura, expected 7.19999980927, is "
      << last_msg_->common.ura;
  EXPECT_EQ(last_msg_->common.valid, 1)
      << "incorrect value for common.valid, expected 1, is "
      << last_msg_->common.valid;
  EXPECT_LT((last_msg_->dn * 100 - 3.22620581299e-09 * 100), 0.05)
      << "incorrect value for dn, expected 3.22620581299e-09, is "
      << last_msg_->dn;
  EXPECT_LT((last_msg_->ecc * 100 - 0.000170606072061 * 100), 0.05)
      << "incorrect value for ecc, expected 0.000170606072061, is "
      << last_msg_->ecc;
  EXPECT_LT((last_msg_->inc * 100 - 0.977745609498 * 100), 0.05)
      << "incorrect value for inc, expected 0.977745609498, is "
      << last_msg_->inc;
  EXPECT_LT((last_msg_->inc_dot * 100 - -3.17870383435e-10 * 100), 0.05)
      << "incorrect value for inc_dot, expected -3.17870383435e-10, is "
      << last_msg_->inc_dot;
  EXPECT_EQ(last_msg_->iodc, 108)
      << "incorrect value for iodc, expected 108, is " << last_msg_->iodc;
  EXPECT_EQ(last_msg_->iode, 108)
      << "incorrect value for iode, expected 108, is " << last_msg_->iode;
  EXPECT_LT((last_msg_->m0 * 100 - -1.84571157442 * 100), 0.05)
      << "incorrect value for m0, expected -1.84571157442, is "
      << last_msg_->m0;
  EXPECT_LT((last_msg_->omega0 * 100 - 1.16967730598 * 100), 0.05)
      << "incorrect value for omega0, expected 1.16967730598, is "
      << last_msg_->omega0;
  EXPECT_LT((last_msg_->omegadot * 100 - -5.75738267524e-09 * 100), 0.05)
      << "incorrect value for omegadot, expected -5.75738267524e-09, is "
      << last_msg_->omegadot;
  EXPECT_LT((last_msg_->sqrta * 100 - 5440.60240173 * 100), 0.05)
      << "incorrect value for sqrta, expected 5440.60240173, is "
      << last_msg_->sqrta;
  EXPECT_EQ(last_msg_->toc.tow, 448800)
      << "incorrect value for toc.tow, expected 448800, is "
      << last_msg_->toc.tow;
  EXPECT_EQ(last_msg_->toc.wn, 2154)
      << "incorrect value for toc.wn, expected 2154, is " << last_msg_->toc.wn;
  EXPECT_LT((last_msg_->w * 100 - 0.122509120917 * 100), 0.05)
      << "incorrect value for w, expected 0.122509120917, is " << last_msg_->w;
}
