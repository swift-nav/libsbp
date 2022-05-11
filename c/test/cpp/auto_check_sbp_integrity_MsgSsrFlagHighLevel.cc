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
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagHighLevel.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_integrity_MsgSsrFlagHighLevel0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_ssr_flag_high_level_t> {
 public:
  Test_auto_check_sbp_integrity_MsgSsrFlagHighLevel0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_ssr_flag_high_level_t>(this),
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
                      const sbp_msg_ssr_flag_high_level_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_ssr_flag_high_level_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_integrity_MsgSsrFlagHighLevel0, Test) {
  uint8_t encoded_frame[] = {
      85, 185, 11, 66, 0, 31, 180, 0, 0, 0, 3, 0, 104, 1, 0, 0, 6, 0,   10, 20,
      0,  30,  0,  40, 1, 2,  3,   0, 0, 0, 0, 0, 0,   4, 5, 6, 7, 102, 67,
  };

  sbp_msg_ssr_flag_high_level_t test_msg{};
  test_msg.chain_id = 40;
  test_msg.corr_time.tow = 360;
  test_msg.corr_time.wn = 6;
  test_msg.obs_time.tow = 180;
  test_msg.obs_time.wn = 3;

  test_msg.reserved[0] = 0;

  test_msg.reserved[1] = 0;

  test_msg.reserved[2] = 0;

  test_msg.reserved[3] = 0;

  test_msg.reserved[4] = 0;

  test_msg.reserved[5] = 0;
  test_msg.ssr_sol_id = 10;
  test_msg.tile_id = 30;
  test_msg.tile_set_id = 20;
  test_msg.use_bds_sat = 3;
  test_msg.use_gal_sat = 2;
  test_msg.use_gps_sat = 1;
  test_msg.use_iono_grid_point_sat_los = 7;
  test_msg.use_iono_grid_points = 5;
  test_msg.use_iono_tile_sat_los = 6;
  test_msg.use_tropo_grid_points = 4;

  EXPECT_EQ(send_message(66, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.chain_id, 40)
      << "incorrect value for last_msg_.chain_id, expected 40, is "
      << last_msg_.chain_id;
  EXPECT_EQ(last_msg_.corr_time.tow, 360)
      << "incorrect value for last_msg_.corr_time.tow, expected 360, is "
      << last_msg_.corr_time.tow;
  EXPECT_EQ(last_msg_.corr_time.wn, 6)
      << "incorrect value for last_msg_.corr_time.wn, expected 6, is "
      << last_msg_.corr_time.wn;
  EXPECT_EQ(last_msg_.obs_time.tow, 180)
      << "incorrect value for last_msg_.obs_time.tow, expected 180, is "
      << last_msg_.obs_time.tow;
  EXPECT_EQ(last_msg_.obs_time.wn, 3)
      << "incorrect value for last_msg_.obs_time.wn, expected 3, is "
      << last_msg_.obs_time.wn;
  EXPECT_EQ(last_msg_.reserved[0], 0)
      << "incorrect value for last_msg_.reserved[0], expected 0, is "
      << last_msg_.reserved[0];
  EXPECT_EQ(last_msg_.reserved[1], 0)
      << "incorrect value for last_msg_.reserved[1], expected 0, is "
      << last_msg_.reserved[1];
  EXPECT_EQ(last_msg_.reserved[2], 0)
      << "incorrect value for last_msg_.reserved[2], expected 0, is "
      << last_msg_.reserved[2];
  EXPECT_EQ(last_msg_.reserved[3], 0)
      << "incorrect value for last_msg_.reserved[3], expected 0, is "
      << last_msg_.reserved[3];
  EXPECT_EQ(last_msg_.reserved[4], 0)
      << "incorrect value for last_msg_.reserved[4], expected 0, is "
      << last_msg_.reserved[4];
  EXPECT_EQ(last_msg_.reserved[5], 0)
      << "incorrect value for last_msg_.reserved[5], expected 0, is "
      << last_msg_.reserved[5];
  EXPECT_EQ(last_msg_.ssr_sol_id, 10)
      << "incorrect value for last_msg_.ssr_sol_id, expected 10, is "
      << last_msg_.ssr_sol_id;
  EXPECT_EQ(last_msg_.tile_id, 30)
      << "incorrect value for last_msg_.tile_id, expected 30, is "
      << last_msg_.tile_id;
  EXPECT_EQ(last_msg_.tile_set_id, 20)
      << "incorrect value for last_msg_.tile_set_id, expected 20, is "
      << last_msg_.tile_set_id;
  EXPECT_EQ(last_msg_.use_bds_sat, 3)
      << "incorrect value for last_msg_.use_bds_sat, expected 3, is "
      << last_msg_.use_bds_sat;
  EXPECT_EQ(last_msg_.use_gal_sat, 2)
      << "incorrect value for last_msg_.use_gal_sat, expected 2, is "
      << last_msg_.use_gal_sat;
  EXPECT_EQ(last_msg_.use_gps_sat, 1)
      << "incorrect value for last_msg_.use_gps_sat, expected 1, is "
      << last_msg_.use_gps_sat;
  EXPECT_EQ(last_msg_.use_iono_grid_point_sat_los, 7)
      << "incorrect value for last_msg_.use_iono_grid_point_sat_los, expected "
         "7, is "
      << last_msg_.use_iono_grid_point_sat_los;
  EXPECT_EQ(last_msg_.use_iono_grid_points, 5)
      << "incorrect value for last_msg_.use_iono_grid_points, expected 5, is "
      << last_msg_.use_iono_grid_points;
  EXPECT_EQ(last_msg_.use_iono_tile_sat_los, 6)
      << "incorrect value for last_msg_.use_iono_tile_sat_los, expected 6, is "
      << last_msg_.use_iono_tile_sat_los;
  EXPECT_EQ(last_msg_.use_tropo_grid_points, 4)
      << "incorrect value for last_msg_.use_tropo_grid_points, expected 4, is "
      << last_msg_.use_tropo_grid_points;
}
