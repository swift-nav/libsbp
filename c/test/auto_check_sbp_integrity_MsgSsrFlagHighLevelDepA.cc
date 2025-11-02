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
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagHighLevelDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/integrity.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_integrity_MsgSsrFlagHighLevelDepA,
     test_auto_check_sbp_integrity_MsgSsrFlagHighLevelDepA) {
  static sbp_msg_callbacks_node_t n;

  // State of the SBP message parser.
  // Must be statically allocated.
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

    sbp_callback_register(&sbp_state, SbpMsgSsrFlagHighLevelDepA,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 185, 11, 66, 0, 31, 180, 0, 0,  0, 3,  0,   104,
        1,  0,   0,  6,  0, 10, 20,  0, 30, 0, 40, 1,   2,
        3,  4,   0,  0,  0, 0,  0,   5, 6,  7, 8,  105, 3,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_flag_high_level_dep_a.chain_id = 40;

    test_msg.ssr_flag_high_level_dep_a.corr_time.tow = 360;

    test_msg.ssr_flag_high_level_dep_a.corr_time.wn = 6;

    test_msg.ssr_flag_high_level_dep_a.obs_time.tow = 180;

    test_msg.ssr_flag_high_level_dep_a.obs_time.wn = 3;

    test_msg.ssr_flag_high_level_dep_a.reserved[0] = 0;

    test_msg.ssr_flag_high_level_dep_a.reserved[1] = 0;

    test_msg.ssr_flag_high_level_dep_a.reserved[2] = 0;

    test_msg.ssr_flag_high_level_dep_a.reserved[3] = 0;

    test_msg.ssr_flag_high_level_dep_a.reserved[4] = 0;

    test_msg.ssr_flag_high_level_dep_a.ssr_sol_id = 10;

    test_msg.ssr_flag_high_level_dep_a.tile_id = 30;

    test_msg.ssr_flag_high_level_dep_a.tile_set_id = 20;

    test_msg.ssr_flag_high_level_dep_a.use_bds_sat = 3;

    test_msg.ssr_flag_high_level_dep_a.use_gal_sat = 2;

    test_msg.ssr_flag_high_level_dep_a.use_gps_sat = 1;

    test_msg.ssr_flag_high_level_dep_a.use_iono_grid_point_sat_los = 8;

    test_msg.ssr_flag_high_level_dep_a.use_iono_grid_points = 6;

    test_msg.ssr_flag_high_level_dep_a.use_iono_tile_sat_los = 7;

    test_msg.ssr_flag_high_level_dep_a.use_qzss_sat = 4;

    test_msg.ssr_flag_high_level_dep_a.use_tropo_grid_points = 5;

    sbp_message_send(&sbp_state, SbpMsgSsrFlagHighLevelDepA, 66, &test_msg,
                     &dummy_write);

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

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgSsrFlagHighLevelDepA, &last_msg.msg, &test_msg),
        0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.chain_id, 40)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.chain_id, expected 40, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.chain_id;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.corr_time.tow, 360)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.corr_time.tow, expected "
           "360, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.corr_time.tow;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.corr_time.wn, 6)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.corr_time.wn, expected 6, "
           "is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.corr_time.wn;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.obs_time.tow, 180)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.obs_time.tow, expected 180, "
           "is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.obs_time.tow;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.obs_time.wn, 3)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.obs_time.wn, expected 3, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.obs_time.wn;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.reserved[0], 0)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.reserved[0], expected 0, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.reserved[0];
    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.reserved[1], 0)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.reserved[1], expected 0, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.reserved[1];
    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.reserved[2], 0)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.reserved[2], expected 0, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.reserved[2];
    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.reserved[3], 0)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.reserved[3], expected 0, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.reserved[3];
    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.reserved[4], 0)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.reserved[4], expected 0, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.reserved[4];

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.ssr_sol_id, 10)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.ssr_sol_id, expected 10, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.ssr_sol_id;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.tile_id, 30)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.tile_id, expected 30, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.tile_id;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.tile_set_id, 20)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.tile_set_id, expected 20, "
           "is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.tile_set_id;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.use_bds_sat, 3)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.use_bds_sat, expected 3, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.use_bds_sat;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.use_gal_sat, 2)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.use_gal_sat, expected 2, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.use_gal_sat;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.use_gps_sat, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.use_gps_sat, expected 1, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.use_gps_sat;

    EXPECT_EQ(
        last_msg.msg.ssr_flag_high_level_dep_a.use_iono_grid_point_sat_los, 8)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.use_iono_grid_point_sat_los,"
           " expected 8, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a
               .use_iono_grid_point_sat_los;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.use_iono_grid_points, 6)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.use_iono_grid_points, "
           "expected 6, is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.use_iono_grid_points;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.use_iono_tile_sat_los, 7)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.use_iono_tile_sat_los, "
           "expected 7, is "
        << (int64_t)
               last_msg.msg.ssr_flag_high_level_dep_a.use_iono_tile_sat_los;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.use_qzss_sat, 4)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.use_qzss_sat, expected 4, "
           "is "
        << (int64_t)last_msg.msg.ssr_flag_high_level_dep_a.use_qzss_sat;

    EXPECT_EQ(last_msg.msg.ssr_flag_high_level_dep_a.use_tropo_grid_points, 5)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_high_level_dep_a.use_tropo_grid_points, "
           "expected 5, is "
        << (int64_t)
               last_msg.msg.ssr_flag_high_level_dep_a.use_tropo_grid_points;
  }
}

}  // namespace
