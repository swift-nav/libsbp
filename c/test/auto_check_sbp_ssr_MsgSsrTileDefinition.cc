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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinition.yaml by
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

TEST(auto_check_sbp_ssr_MsgSsrTileDefinition,
     test_auto_check_sbp_ssr_MsgSsrTileDefinition) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrTileDefinition,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 248, 5, 0,   0, 33,  127, 58, 9,   0,   174, 8,   1,  2,
        3,  4,   0, 5,   0, 186, 28,  59, 167, 100, 0,   100, 0,  6,
        0,  6,   0, 210, 2, 150, 73,  0,  0,   0,   0,   204, 94,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_tile_definition.bitmask = 1234567890;

    test_msg.ssr_tile_definition.cols = 6;

    test_msg.ssr_tile_definition.corner_nw_lat = 7354;

    test_msg.ssr_tile_definition.corner_nw_lon = -22725;

    test_msg.ssr_tile_definition.iod_atmo = 3;

    test_msg.ssr_tile_definition.rows = 6;

    test_msg.ssr_tile_definition.sol_id = 2;

    test_msg.ssr_tile_definition.spacing_lat = 100;

    test_msg.ssr_tile_definition.spacing_lon = 100;

    test_msg.ssr_tile_definition.tile_id = 5;

    test_msg.ssr_tile_definition.tile_set_id = 4;

    test_msg.ssr_tile_definition.time.tow = 604799;

    test_msg.ssr_tile_definition.time.wn = 2222;

    test_msg.ssr_tile_definition.update_interval = 1;

    sbp_message_send(&sbp_state, SbpMsgSsrTileDefinition, 0, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 0)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgSsrTileDefinition, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.bitmask, 1234567890)
        << "incorrect value for last_msg.msg.ssr_tile_definition.bitmask, "
           "expected 1234567890, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.bitmask;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.cols, 6)
        << "incorrect value for last_msg.msg.ssr_tile_definition.cols, "
           "expected 6, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.cols;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.corner_nw_lat, 7354)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition.corner_nw_lat, expected 7354, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.corner_nw_lat;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.corner_nw_lon, -22725)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition.corner_nw_lon, expected -22725, "
           "is "
        << (int64_t)last_msg.msg.ssr_tile_definition.corner_nw_lon;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.iod_atmo, 3)
        << "incorrect value for last_msg.msg.ssr_tile_definition.iod_atmo, "
           "expected 3, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.iod_atmo;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.rows, 6)
        << "incorrect value for last_msg.msg.ssr_tile_definition.rows, "
           "expected 6, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.rows;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.sol_id, 2)
        << "incorrect value for last_msg.msg.ssr_tile_definition.sol_id, "
           "expected 2, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.sol_id;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.spacing_lat, 100)
        << "incorrect value for last_msg.msg.ssr_tile_definition.spacing_lat, "
           "expected 100, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.spacing_lat;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.spacing_lon, 100)
        << "incorrect value for last_msg.msg.ssr_tile_definition.spacing_lon, "
           "expected 100, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.spacing_lon;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.tile_id, 5)
        << "incorrect value for last_msg.msg.ssr_tile_definition.tile_id, "
           "expected 5, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.tile_id;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.tile_set_id, 4)
        << "incorrect value for last_msg.msg.ssr_tile_definition.tile_set_id, "
           "expected 4, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.tile_set_id;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.time.tow, 604799)
        << "incorrect value for last_msg.msg.ssr_tile_definition.time.tow, "
           "expected 604799, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.time.tow;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.time.wn, 2222)
        << "incorrect value for last_msg.msg.ssr_tile_definition.time.wn, "
           "expected 2222, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.time.wn;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition.update_interval, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition.update_interval, expected 1, is "
        << (int64_t)last_msg.msg.ssr_tile_definition.update_interval;
  }
}

}  // namespace
