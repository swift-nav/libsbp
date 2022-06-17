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
      85,  254, 5,   66,  0,  45, 180, 0,  0,   0,   3,   0,  1,   1,
      10,  0,   15,  1,   0,  10, 0,   39, 232, 3,   244, 1,  100, 200,
      150, 100, 150, 100, 2,  5,  10,  16, 0,   17,  18,  19, 20,  21,
      6,   10,  22,  0,   23, 24, 25,  26, 27,  119, 82,
  };

  sbp_msg_ssr_gridded_correction_bounds_t test_msg{};
  test_msg.grid_point_id = 1000;
  test_msg.header.num_msgs = 1;
  test_msg.header.seq_num = 1;
  test_msg.header.sol_id = 0;
  test_msg.header.time.tow = 180;
  test_msg.header.time.wn = 3;
  test_msg.header.update_interval = 10;
  test_msg.n_sats = 2;
  test_msg.ssr_iod_atmo = 15;

  test_msg.stec_sat_list[0].stec_bound_mu = 18;
  test_msg.stec_sat_list[0].stec_bound_mu_dot = 20;
  test_msg.stec_sat_list[0].stec_bound_sig = 19;
  test_msg.stec_sat_list[0].stec_bound_sig_dot = 21;
  test_msg.stec_sat_list[0].stec_residual.residual = 16;
  test_msg.stec_sat_list[0].stec_residual.stddev = 17;
  test_msg.stec_sat_list[0].stec_residual.sv_id.constellation = 10;
  test_msg.stec_sat_list[0].stec_residual.sv_id.satId = 5;

  test_msg.stec_sat_list[1].stec_bound_mu = 24;
  test_msg.stec_sat_list[1].stec_bound_mu_dot = 26;
  test_msg.stec_sat_list[1].stec_bound_sig = 25;
  test_msg.stec_sat_list[1].stec_bound_sig_dot = 27;
  test_msg.stec_sat_list[1].stec_residual.residual = 22;
  test_msg.stec_sat_list[1].stec_residual.stddev = 23;
  test_msg.stec_sat_list[1].stec_residual.sv_id.constellation = 10;
  test_msg.stec_sat_list[1].stec_residual.sv_id.satId = 6;
  test_msg.tile_id = 10;
  test_msg.tile_set_id = 1;
  test_msg.tropo_delay_correction.hydro = 500;
  test_msg.tropo_delay_correction.stddev = 200;
  test_msg.tropo_delay_correction.wet = 100;
  test_msg.tropo_qi = 39;
  test_msg.tropo_v_hydro_bound_mu = 150;
  test_msg.tropo_v_hydro_bound_sig = 100;
  test_msg.tropo_v_wet_bound_mu = 150;
  test_msg.tropo_v_wet_bound_sig = 100;

  EXPECT_EQ(send_message(66, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.grid_point_id, 1000)
      << "incorrect value for last_msg_.grid_point_id, expected 1000, is "
      << last_msg_.grid_point_id;
  EXPECT_EQ(last_msg_.header.num_msgs, 1)
      << "incorrect value for last_msg_.header.num_msgs, expected 1, is "
      << last_msg_.header.num_msgs;
  EXPECT_EQ(last_msg_.header.seq_num, 1)
      << "incorrect value for last_msg_.header.seq_num, expected 1, is "
      << last_msg_.header.seq_num;
  EXPECT_EQ(last_msg_.header.sol_id, 0)
      << "incorrect value for last_msg_.header.sol_id, expected 0, is "
      << last_msg_.header.sol_id;
  EXPECT_EQ(last_msg_.header.time.tow, 180)
      << "incorrect value for last_msg_.header.time.tow, expected 180, is "
      << last_msg_.header.time.tow;
  EXPECT_EQ(last_msg_.header.time.wn, 3)
      << "incorrect value for last_msg_.header.time.wn, expected 3, is "
      << last_msg_.header.time.wn;
  EXPECT_EQ(last_msg_.header.update_interval, 10)
      << "incorrect value for last_msg_.header.update_interval, expected 10, "
         "is "
      << last_msg_.header.update_interval;
  EXPECT_EQ(last_msg_.n_sats, 2)
      << "incorrect value for last_msg_.n_sats, expected 2, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.ssr_iod_atmo, 15)
      << "incorrect value for last_msg_.ssr_iod_atmo, expected 15, is "
      << last_msg_.ssr_iod_atmo;
  EXPECT_EQ(last_msg_.stec_sat_list[0].stec_bound_mu, 18)
      << "incorrect value for last_msg_.stec_sat_list[0].stec_bound_mu, "
         "expected 18, is "
      << last_msg_.stec_sat_list[0].stec_bound_mu;
  EXPECT_EQ(last_msg_.stec_sat_list[0].stec_bound_mu_dot, 20)
      << "incorrect value for last_msg_.stec_sat_list[0].stec_bound_mu_dot, "
         "expected 20, is "
      << last_msg_.stec_sat_list[0].stec_bound_mu_dot;
  EXPECT_EQ(last_msg_.stec_sat_list[0].stec_bound_sig, 19)
      << "incorrect value for last_msg_.stec_sat_list[0].stec_bound_sig, "
         "expected 19, is "
      << last_msg_.stec_sat_list[0].stec_bound_sig;
  EXPECT_EQ(last_msg_.stec_sat_list[0].stec_bound_sig_dot, 21)
      << "incorrect value for last_msg_.stec_sat_list[0].stec_bound_sig_dot, "
         "expected 21, is "
      << last_msg_.stec_sat_list[0].stec_bound_sig_dot;
  EXPECT_EQ(last_msg_.stec_sat_list[0].stec_residual.residual, 16)
      << "incorrect value for "
         "last_msg_.stec_sat_list[0].stec_residual.residual, expected 16, is "
      << last_msg_.stec_sat_list[0].stec_residual.residual;
  EXPECT_EQ(last_msg_.stec_sat_list[0].stec_residual.stddev, 17)
      << "incorrect value for last_msg_.stec_sat_list[0].stec_residual.stddev, "
         "expected 17, is "
      << last_msg_.stec_sat_list[0].stec_residual.stddev;
  EXPECT_EQ(last_msg_.stec_sat_list[0].stec_residual.sv_id.constellation, 10)
      << "incorrect value for "
         "last_msg_.stec_sat_list[0].stec_residual.sv_id.constellation, "
         "expected 10, is "
      << last_msg_.stec_sat_list[0].stec_residual.sv_id.constellation;
  EXPECT_EQ(last_msg_.stec_sat_list[0].stec_residual.sv_id.satId, 5)
      << "incorrect value for "
         "last_msg_.stec_sat_list[0].stec_residual.sv_id.satId, expected 5, is "
      << last_msg_.stec_sat_list[0].stec_residual.sv_id.satId;
  EXPECT_EQ(last_msg_.stec_sat_list[1].stec_bound_mu, 24)
      << "incorrect value for last_msg_.stec_sat_list[1].stec_bound_mu, "
         "expected 24, is "
      << last_msg_.stec_sat_list[1].stec_bound_mu;
  EXPECT_EQ(last_msg_.stec_sat_list[1].stec_bound_mu_dot, 26)
      << "incorrect value for last_msg_.stec_sat_list[1].stec_bound_mu_dot, "
         "expected 26, is "
      << last_msg_.stec_sat_list[1].stec_bound_mu_dot;
  EXPECT_EQ(last_msg_.stec_sat_list[1].stec_bound_sig, 25)
      << "incorrect value for last_msg_.stec_sat_list[1].stec_bound_sig, "
         "expected 25, is "
      << last_msg_.stec_sat_list[1].stec_bound_sig;
  EXPECT_EQ(last_msg_.stec_sat_list[1].stec_bound_sig_dot, 27)
      << "incorrect value for last_msg_.stec_sat_list[1].stec_bound_sig_dot, "
         "expected 27, is "
      << last_msg_.stec_sat_list[1].stec_bound_sig_dot;
  EXPECT_EQ(last_msg_.stec_sat_list[1].stec_residual.residual, 22)
      << "incorrect value for "
         "last_msg_.stec_sat_list[1].stec_residual.residual, expected 22, is "
      << last_msg_.stec_sat_list[1].stec_residual.residual;
  EXPECT_EQ(last_msg_.stec_sat_list[1].stec_residual.stddev, 23)
      << "incorrect value for last_msg_.stec_sat_list[1].stec_residual.stddev, "
         "expected 23, is "
      << last_msg_.stec_sat_list[1].stec_residual.stddev;
  EXPECT_EQ(last_msg_.stec_sat_list[1].stec_residual.sv_id.constellation, 10)
      << "incorrect value for "
         "last_msg_.stec_sat_list[1].stec_residual.sv_id.constellation, "
         "expected 10, is "
      << last_msg_.stec_sat_list[1].stec_residual.sv_id.constellation;
  EXPECT_EQ(last_msg_.stec_sat_list[1].stec_residual.sv_id.satId, 6)
      << "incorrect value for "
         "last_msg_.stec_sat_list[1].stec_residual.sv_id.satId, expected 6, is "
      << last_msg_.stec_sat_list[1].stec_residual.sv_id.satId;
  EXPECT_EQ(last_msg_.tile_id, 10)
      << "incorrect value for last_msg_.tile_id, expected 10, is "
      << last_msg_.tile_id;
  EXPECT_EQ(last_msg_.tile_set_id, 1)
      << "incorrect value for last_msg_.tile_set_id, expected 1, is "
      << last_msg_.tile_set_id;
  EXPECT_EQ(last_msg_.tropo_delay_correction.hydro, 500)
      << "incorrect value for last_msg_.tropo_delay_correction.hydro, expected "
         "500, is "
      << last_msg_.tropo_delay_correction.hydro;
  EXPECT_EQ(last_msg_.tropo_delay_correction.stddev, 200)
      << "incorrect value for last_msg_.tropo_delay_correction.stddev, "
         "expected 200, is "
      << last_msg_.tropo_delay_correction.stddev;
  EXPECT_EQ(last_msg_.tropo_delay_correction.wet, 100)
      << "incorrect value for last_msg_.tropo_delay_correction.wet, expected "
         "100, is "
      << last_msg_.tropo_delay_correction.wet;
  EXPECT_EQ(last_msg_.tropo_qi, 39)
      << "incorrect value for last_msg_.tropo_qi, expected 39, is "
      << last_msg_.tropo_qi;
  EXPECT_EQ(last_msg_.tropo_v_hydro_bound_mu, 150)
      << "incorrect value for last_msg_.tropo_v_hydro_bound_mu, expected 150, "
         "is "
      << last_msg_.tropo_v_hydro_bound_mu;
  EXPECT_EQ(last_msg_.tropo_v_hydro_bound_sig, 100)
      << "incorrect value for last_msg_.tropo_v_hydro_bound_sig, expected 100, "
         "is "
      << last_msg_.tropo_v_hydro_bound_sig;
  EXPECT_EQ(last_msg_.tropo_v_wet_bound_mu, 150)
      << "incorrect value for last_msg_.tropo_v_wet_bound_mu, expected 150, is "
      << last_msg_.tropo_v_wet_bound_mu;
  EXPECT_EQ(last_msg_.tropo_v_wet_bound_sig, 100)
      << "incorrect value for last_msg_.tropo_v_wet_bound_sig, expected 100, "
         "is "
      << last_msg_.tropo_v_wet_bound_sig;
}
