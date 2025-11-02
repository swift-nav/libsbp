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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinitionDepB.yaml by
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

TEST(auto_check_sbp_ssr_MsgSsrTileDefinitionDepB,
     test_auto_check_sbp_ssr_MsgSsrTileDefinitionDepB) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrTileDefinitionDepB,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 247, 5, 66, 0, 25,  31,  0, 1,   0,  2, 0, 4, 0, 8,   0,  16,
        0,  32,  0, 64, 0, 128, 210, 2, 150, 73, 0, 0, 0, 0, 214, 71,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_tile_definition_dep_b.bitmask = 1234567890;

    test_msg.ssr_tile_definition_dep_b.cols = 32768;

    test_msg.ssr_tile_definition_dep_b.corner_nw_lat = 1024;

    test_msg.ssr_tile_definition_dep_b.corner_nw_lon = 2048;

    test_msg.ssr_tile_definition_dep_b.rows = 16384;

    test_msg.ssr_tile_definition_dep_b.spacing_lat = 4096;

    test_msg.ssr_tile_definition_dep_b.spacing_lon = 8192;

    test_msg.ssr_tile_definition_dep_b.ssr_sol_id = 31;

    test_msg.ssr_tile_definition_dep_b.tile_id = 512;

    test_msg.ssr_tile_definition_dep_b.tile_set_id = 256;

    sbp_message_send(&sbp_state, SbpMsgSsrTileDefinitionDepB, 66, &test_msg,
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
        sbp_message_cmp(SbpMsgSsrTileDefinitionDepB, &last_msg.msg, &test_msg),
        0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_b.bitmask, 1234567890)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_b.bitmask, expected "
           "1234567890, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_b.bitmask;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_b.cols, 32768)
        << "incorrect value for last_msg.msg.ssr_tile_definition_dep_b.cols, "
           "expected 32768, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_b.cols;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_b.corner_nw_lat, 1024)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_b.corner_nw_lat, expected "
           "1024, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_b.corner_nw_lat;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_b.corner_nw_lon, 2048)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_b.corner_nw_lon, expected "
           "2048, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_b.corner_nw_lon;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_b.rows, 16384)
        << "incorrect value for last_msg.msg.ssr_tile_definition_dep_b.rows, "
           "expected 16384, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_b.rows;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_b.spacing_lat, 4096)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_b.spacing_lat, expected 4096, "
           "is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_b.spacing_lat;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_b.spacing_lon, 8192)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_b.spacing_lon, expected 8192, "
           "is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_b.spacing_lon;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_b.ssr_sol_id, 31)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_b.ssr_sol_id, expected 31, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_b.ssr_sol_id;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_b.tile_id, 512)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_b.tile_id, expected 512, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_b.tile_id;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_b.tile_set_id, 256)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_b.tile_set_id, expected 256, "
           "is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_b.tile_set_id;
  }
}

}  // namespace
