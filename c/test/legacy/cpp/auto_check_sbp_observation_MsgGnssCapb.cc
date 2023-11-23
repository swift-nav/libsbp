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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgGnssCapb.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>
#include <libsbp/cpp/state.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/observation.h>
class Test_legacy_auto_check_sbp_observation_MsgGnssCapb0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_gnss_capb_t> {
 public:
  Test_legacy_auto_check_sbp_observation_MsgGnssCapb0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_gnss_capb_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_gnss_capb_t *>(last_msg_storage_)),
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
                      const msg_gnss_capb_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_gnss_capb_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_observation_MsgGnssCapb0, Test) {
  uint8_t encoded_frame[] = {
      85,  150, 0,  123, 0,  110, 176, 207, 6,   0,  106, 8,   26,  171, 80,
      64,  0,   0,  0,   0,  81,  173, 144, 46,  0,  0,   0,   0,   209, 139,
      93,  108, 0,  0,   0,  0,   252, 204, 200, 0,  205, 92,  30,  49,  240,
      203, 21,  24, 212, 93, 182, 32,  0,   0,   0,  0,   105, 32,  192, 27,
      0,   0,   0,  0,   40, 75,  250, 114, 0,   0,  0,   0,   119, 147, 123,
      81,  0,   0,  0,   0,  85,  89,  4,   2,   0,  0,   0,   0,   233, 116,
      137, 22,  0,  0,   0,  0,   199, 109, 219, 11, 221, 171, 248, 82,  0,
      0,   0,   0,  252, 62, 221, 28,  0,   0,   0,  0,   163, 90,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_gnss_capb_t *test_msg = (msg_gnss_capb_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->gc.bds_active = 1929005864;
  test_msg->gc.bds_b2 = 33839445;
  test_msg->gc.bds_b2a = 378107113;
  test_msg->gc.bds_d2nav = 1367053175;
  test_msg->gc.gal_active = 1392028637;
  test_msg->gc.gal_e5 = 484261628;
  test_msg->gc.glo_active = 13159676;
  test_msg->gc.glo_l2of = 824073421;
  test_msg->gc.glo_l3 = 404081648;
  test_msg->gc.gps_active = 1079028506;
  test_msg->gc.gps_l2c = 781233489;
  test_msg->gc.gps_l5 = 1818069969;
  test_msg->gc.qzss_active = 198929863;
  test_msg->gc.sbas_active = 548822484;
  test_msg->gc.sbas_l5 = 465576041;
  test_msg->t_nmct.tow = 446384;
  test_msg->t_nmct.wn = 2154;

  EXPECT_EQ(send_message(0x96, 123, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 123);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->gc.bds_active, 1929005864)
      << "incorrect value for gc.bds_active, expected 1929005864, is "
      << last_msg_->gc.bds_active;
  EXPECT_EQ(last_msg_->gc.bds_b2, 33839445)
      << "incorrect value for gc.bds_b2, expected 33839445, is "
      << last_msg_->gc.bds_b2;
  EXPECT_EQ(last_msg_->gc.bds_b2a, 378107113)
      << "incorrect value for gc.bds_b2a, expected 378107113, is "
      << last_msg_->gc.bds_b2a;
  EXPECT_EQ(last_msg_->gc.bds_d2nav, 1367053175)
      << "incorrect value for gc.bds_d2nav, expected 1367053175, is "
      << last_msg_->gc.bds_d2nav;
  EXPECT_EQ(last_msg_->gc.gal_active, 1392028637)
      << "incorrect value for gc.gal_active, expected 1392028637, is "
      << last_msg_->gc.gal_active;
  EXPECT_EQ(last_msg_->gc.gal_e5, 484261628)
      << "incorrect value for gc.gal_e5, expected 484261628, is "
      << last_msg_->gc.gal_e5;
  EXPECT_EQ(last_msg_->gc.glo_active, 13159676)
      << "incorrect value for gc.glo_active, expected 13159676, is "
      << last_msg_->gc.glo_active;
  EXPECT_EQ(last_msg_->gc.glo_l2of, 824073421)
      << "incorrect value for gc.glo_l2of, expected 824073421, is "
      << last_msg_->gc.glo_l2of;
  EXPECT_EQ(last_msg_->gc.glo_l3, 404081648)
      << "incorrect value for gc.glo_l3, expected 404081648, is "
      << last_msg_->gc.glo_l3;
  EXPECT_EQ(last_msg_->gc.gps_active, 1079028506)
      << "incorrect value for gc.gps_active, expected 1079028506, is "
      << last_msg_->gc.gps_active;
  EXPECT_EQ(last_msg_->gc.gps_l2c, 781233489)
      << "incorrect value for gc.gps_l2c, expected 781233489, is "
      << last_msg_->gc.gps_l2c;
  EXPECT_EQ(last_msg_->gc.gps_l5, 1818069969)
      << "incorrect value for gc.gps_l5, expected 1818069969, is "
      << last_msg_->gc.gps_l5;
  EXPECT_EQ(last_msg_->gc.qzss_active, 198929863)
      << "incorrect value for gc.qzss_active, expected 198929863, is "
      << last_msg_->gc.qzss_active;
  EXPECT_EQ(last_msg_->gc.sbas_active, 548822484)
      << "incorrect value for gc.sbas_active, expected 548822484, is "
      << last_msg_->gc.sbas_active;
  EXPECT_EQ(last_msg_->gc.sbas_l5, 465576041)
      << "incorrect value for gc.sbas_l5, expected 465576041, is "
      << last_msg_->gc.sbas_l5;
  EXPECT_EQ(last_msg_->t_nmct.tow, 446384)
      << "incorrect value for t_nmct.tow, expected 446384, is "
      << last_msg_->t_nmct.tow;
  EXPECT_EQ(last_msg_->t_nmct.wn, 2154)
      << "incorrect value for t_nmct.wn, expected 2154, is "
      << last_msg_->t_nmct.wn;
}
