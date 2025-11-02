/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionBounds.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/ssr.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds,
     test_auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds) {
  sbp_msg_callbacks_node_t n;

  // State of the SBP message parser.
  sbp_state_t sbp_state;

  //
  // Run tests:
  //
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, SbpMsgSsrGriddedCorrectionBounds,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  254, 5,   66,  0,  45, 180, 0,  0,   0,   3,   0,  1,   0,
        10,  0,   15,  1,   0,  10, 0,   39, 232, 3,   244, 1,  100, 200,
        150, 100, 150, 100, 2,  5,  10,  16, 0,   17,  18,  19, 20,  21,
        6,   10,  22,  0,   23, 24, 25,  26, 27,  236, 182,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_gridded_correction_bounds.grid_point_id = 1000;

    test_msg.ssr_gridded_correction_bounds.header.num_msgs = 1;

    test_msg.ssr_gridded_correction_bounds.header.seq_num = 0;

    test_msg.ssr_gridded_correction_bounds.header.sol_id = 0;

    test_msg.ssr_gridded_correction_bounds.header.time.tow = 180;

    test_msg.ssr_gridded_correction_bounds.header.time.wn = 3;

    test_msg.ssr_gridded_correction_bounds.header.update_interval = 10;

    test_msg.ssr_gridded_correction_bounds.n_sats = 2;

    test_msg.ssr_gridded_correction_bounds.ssr_iod_atmo = 15;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_bound_mu = 18;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_bound_mu_dot =
        20;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_bound_sig = 19;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_bound_sig_dot =
        21;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[0]
        .stec_residual.residual = 16;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[0]
        .stec_residual.stddev = 17;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[0]
        .stec_residual.sv_id.constellation = 10;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[0]
        .stec_residual.sv_id.satId = 5;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_bound_mu = 24;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_bound_mu_dot =
        26;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_bound_sig = 25;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_bound_sig_dot =
        27;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[1]
        .stec_residual.residual = 22;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[1]
        .stec_residual.stddev = 23;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[1]
        .stec_residual.sv_id.constellation = 10;

    test_msg.ssr_gridded_correction_bounds.stec_sat_list[1]
        .stec_residual.sv_id.satId = 6;

    test_msg.ssr_gridded_correction_bounds.tile_id = 10;

    test_msg.ssr_gridded_correction_bounds.tile_set_id = 1;

    test_msg.ssr_gridded_correction_bounds.tropo_delay_correction.hydro = 500;

    test_msg.ssr_gridded_correction_bounds.tropo_delay_correction.stddev = 200;

    test_msg.ssr_gridded_correction_bounds.tropo_delay_correction.wet = 100;

    test_msg.ssr_gridded_correction_bounds.tropo_qi = 39;

    test_msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_mu = 150;

    test_msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_sig = 100;

    test_msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_mu = 150;

    test_msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_sig = 100;

    sbp_message_send(&sbp_state, SbpMsgSsrGriddedCorrectionBounds, 66,
                     &test_msg, &dummy_write);

    EXPECT_EQ(dummy_wr, sizeof(encoded_frame))
        << "not enough data was written to dummy_buff (expected: "
        << sizeof(encoded_frame) << ", actual: " << dummy_wr << ")";
    EXPECT_EQ(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)), 0)
        << "frame was not encoded properly";

    while (dummy_rd < dummy_wr) {
      EXPECT_GE(sbp_process(&sbp_state, &dummy_read), SBP_OK)
          << "sbp_process threw an error!";
    }

    EXPECT_EQ(last_msg.n_callbacks_logged, 1)
        << "msg_callback: one callback should have been logged";
    EXPECT_EQ(last_msg.sender_id, 66)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGriddedCorrectionBounds, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.grid_point_id, 1000)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.grid_point_id, expected "
           "1000, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.grid_point_id;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.num_msgs, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.num_msgs, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header.num_msgs;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.seq_num, 0)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.seq_num, "
           "expected 0, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header.seq_num;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.sol_id, 0)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.sol_id, expected "
           "0, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header.sol_id;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.time.tow, 180)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.time.tow, "
           "expected 180, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header.time.tow;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.time.wn, 3)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.time.wn, "
           "expected 3, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header.time.wn;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.update_interval,
              10)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.update_interval, "
           "expected 10, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header
               .update_interval;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.n_sats, 2)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.n_sats, expected 2, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.n_sats;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.ssr_iod_atmo, 15)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.ssr_iod_atmo, expected "
           "15, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.ssr_iod_atmo;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
                  .stec_bound_mu,
              18)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_"
           "bound_mu, expected 18, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
               .stec_bound_mu;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
                  .stec_bound_mu_dot,
              20)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_"
           "bound_mu_dot, expected 20, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
               .stec_bound_mu_dot;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
                  .stec_bound_sig,
              19)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_"
           "bound_sig, expected 19, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
               .stec_bound_sig;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
                  .stec_bound_sig_dot,
              21)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_"
           "bound_sig_dot, expected 21, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
               .stec_bound_sig_dot;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
                  .stec_residual.residual,
              16)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_"
           "residual.residual, expected 16, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
               .stec_residual.residual;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
                  .stec_residual.stddev,
              17)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_"
           "residual.stddev, expected 17, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
               .stec_residual.stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
                  .stec_residual.sv_id.constellation,
              10)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_"
           "residual.sv_id.constellation, expected 10, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
               .stec_residual.sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
                  .stec_residual.sv_id.satId,
              5)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0].stec_"
           "residual.sv_id.satId, expected 5, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[0]
               .stec_residual.sv_id.satId;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
                  .stec_bound_mu,
              24)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_"
           "bound_mu, expected 24, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
               .stec_bound_mu;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
                  .stec_bound_mu_dot,
              26)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_"
           "bound_mu_dot, expected 26, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
               .stec_bound_mu_dot;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
                  .stec_bound_sig,
              25)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_"
           "bound_sig, expected 25, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
               .stec_bound_sig;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
                  .stec_bound_sig_dot,
              27)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_"
           "bound_sig_dot, expected 27, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
               .stec_bound_sig_dot;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
                  .stec_residual.residual,
              22)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_"
           "residual.residual, expected 22, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
               .stec_residual.residual;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
                  .stec_residual.stddev,
              23)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_"
           "residual.stddev, expected 23, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
               .stec_residual.stddev;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
                  .stec_residual.sv_id.constellation,
              10)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_"
           "residual.sv_id.constellation, expected 10, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
               .stec_residual.sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
                  .stec_residual.sv_id.satId,
              6)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1].stec_"
           "residual.sv_id.satId, expected 6, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.stec_sat_list[1]
               .stec_residual.sv_id.satId;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tile_id, 10)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tile_id, expected 10, "
           "is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.tile_id;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tile_set_id, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tile_set_id, expected "
           "1, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.tile_set_id;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction.hydro,
        500)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction."
           "hydro, expected 500, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds
               .tropo_delay_correction.hydro;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction
                  .stddev,
              200)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction."
           "stddev, expected 200, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds
               .tropo_delay_correction.stddev;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction.wet,
        100)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction."
           "wet, expected 100, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds
               .tropo_delay_correction.wet;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tropo_qi, 39)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_qi, expected 39, "
           "is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.tropo_qi;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_mu,
              150)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_mu, "
           "expected 150, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds
               .tropo_v_hydro_bound_mu;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_sig, 100)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_sig,"
           " expected 100, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds
               .tropo_v_hydro_bound_sig;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_mu,
              150)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_mu, "
           "expected 150, is "
        << (int64_t)
               last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_mu;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_sig,
              100)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_sig, "
           "expected 100, is "
        << (int64_t)
               last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_sig;
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, SbpMsgSsrGriddedCorrectionBounds,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  254, 5,   66,  0,   27,  180, 0,   0, 0,   3,   0,
        1,   0,   10,  0,   15,  1,   0,   10,  0, 39,  232, 3,
        244, 1,   100, 200, 150, 100, 150, 100, 0, 155, 36,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_gridded_correction_bounds.grid_point_id = 1000;

    test_msg.ssr_gridded_correction_bounds.header.num_msgs = 1;

    test_msg.ssr_gridded_correction_bounds.header.seq_num = 0;

    test_msg.ssr_gridded_correction_bounds.header.sol_id = 0;

    test_msg.ssr_gridded_correction_bounds.header.time.tow = 180;

    test_msg.ssr_gridded_correction_bounds.header.time.wn = 3;

    test_msg.ssr_gridded_correction_bounds.header.update_interval = 10;

    test_msg.ssr_gridded_correction_bounds.n_sats = 0;

    test_msg.ssr_gridded_correction_bounds.ssr_iod_atmo = 15;

    test_msg.ssr_gridded_correction_bounds.tile_id = 10;

    test_msg.ssr_gridded_correction_bounds.tile_set_id = 1;

    test_msg.ssr_gridded_correction_bounds.tropo_delay_correction.hydro = 500;

    test_msg.ssr_gridded_correction_bounds.tropo_delay_correction.stddev = 200;

    test_msg.ssr_gridded_correction_bounds.tropo_delay_correction.wet = 100;

    test_msg.ssr_gridded_correction_bounds.tropo_qi = 39;

    test_msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_mu = 150;

    test_msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_sig = 100;

    test_msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_mu = 150;

    test_msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_sig = 100;

    sbp_message_send(&sbp_state, SbpMsgSsrGriddedCorrectionBounds, 66,
                     &test_msg, &dummy_write);

    EXPECT_EQ(dummy_wr, sizeof(encoded_frame))
        << "not enough data was written to dummy_buff (expected: "
        << sizeof(encoded_frame) << ", actual: " << dummy_wr << ")";
    EXPECT_EQ(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)), 0)
        << "frame was not encoded properly";

    while (dummy_rd < dummy_wr) {
      EXPECT_GE(sbp_process(&sbp_state, &dummy_read), SBP_OK)
          << "sbp_process threw an error!";
    }

    EXPECT_EQ(last_msg.n_callbacks_logged, 1)
        << "msg_callback: one callback should have been logged";
    EXPECT_EQ(last_msg.sender_id, 66)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGriddedCorrectionBounds, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.grid_point_id, 1000)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.grid_point_id, expected "
           "1000, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.grid_point_id;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.num_msgs, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.num_msgs, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header.num_msgs;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.seq_num, 0)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.seq_num, "
           "expected 0, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header.seq_num;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.sol_id, 0)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.sol_id, expected "
           "0, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header.sol_id;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.time.tow, 180)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.time.tow, "
           "expected 180, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header.time.tow;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.time.wn, 3)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.time.wn, "
           "expected 3, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header.time.wn;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.header.update_interval,
              10)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.header.update_interval, "
           "expected 10, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.header
               .update_interval;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.n_sats, 0)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.n_sats, expected 0, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.n_sats;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.ssr_iod_atmo, 15)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.ssr_iod_atmo, expected "
           "15, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.ssr_iod_atmo;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tile_id, 10)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tile_id, expected 10, "
           "is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.tile_id;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tile_set_id, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tile_set_id, expected "
           "1, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.tile_set_id;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction.hydro,
        500)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction."
           "hydro, expected 500, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds
               .tropo_delay_correction.hydro;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction
                  .stddev,
              200)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction."
           "stddev, expected 200, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds
               .tropo_delay_correction.stddev;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction.wet,
        100)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_delay_correction."
           "wet, expected 100, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds
               .tropo_delay_correction.wet;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tropo_qi, 39)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_qi, expected 39, "
           "is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds.tropo_qi;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_mu,
              150)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_mu, "
           "expected 150, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds
               .tropo_v_hydro_bound_mu;

    EXPECT_EQ(
        last_msg.msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_sig, 100)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_v_hydro_bound_sig,"
           " expected 100, is "
        << (int64_t)last_msg.msg.ssr_gridded_correction_bounds
               .tropo_v_hydro_bound_sig;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_mu,
              150)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_mu, "
           "expected 150, is "
        << (int64_t)
               last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_mu;

    EXPECT_EQ(last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_sig,
              100)
        << "incorrect value for "
           "last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_sig, "
           "expected 100, is "
        << (int64_t)
               last_msg.msg.ssr_gridded_correction_bounds.tropo_v_wet_bound_sig;
  }
}

}  // namespace
