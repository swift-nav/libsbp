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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinitionDepA.yaml by
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

TEST(auto_check_sbp_ssr_MsgSsrTileDefinitionDepA,
     test_auto_check_sbp_ssr_MsgSsrTileDefinitionDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrTileDefinitionDepA,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  246, 5,   200, 133, 24, 57, 190, 178, 247, 8,
        185, 9,   181, 162, 240, 65, 19, 255, 143, 21,  191,
        239, 205, 171, 0,   0,   0,  0,  0,   65,  154,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_tile_definition_dep_a.bitmask = 11259375;

    test_msg.ssr_tile_definition_dep_a.cols = 48917;

    test_msg.ssr_tile_definition_dep_a.corner_nw_lat = -18168;

    test_msg.ssr_tile_definition_dep_a.corner_nw_lon = -19191;

    test_msg.ssr_tile_definition_dep_a.rows = 36863;

    test_msg.ssr_tile_definition_dep_a.spacing_lat = 61602;

    test_msg.ssr_tile_definition_dep_a.spacing_lon = 4929;

    test_msg.ssr_tile_definition_dep_a.tile_id = 63410;

    test_msg.ssr_tile_definition_dep_a.tile_set_id = 48697;

    sbp_message_send(&sbp_state, SbpMsgSsrTileDefinitionDepA, 34248, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 34248)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgSsrTileDefinitionDepA, &last_msg.msg, &test_msg),
        0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_a.bitmask, 11259375)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_a.bitmask, expected 11259375, "
           "is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_a.bitmask;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_a.cols, 48917)
        << "incorrect value for last_msg.msg.ssr_tile_definition_dep_a.cols, "
           "expected 48917, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_a.cols;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_a.corner_nw_lat, -18168)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_a.corner_nw_lat, expected "
           "-18168, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_a.corner_nw_lat;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_a.corner_nw_lon, -19191)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_a.corner_nw_lon, expected "
           "-19191, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_a.corner_nw_lon;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_a.rows, 36863)
        << "incorrect value for last_msg.msg.ssr_tile_definition_dep_a.rows, "
           "expected 36863, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_a.rows;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_a.spacing_lat, 61602)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_a.spacing_lat, expected "
           "61602, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_a.spacing_lat;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_a.spacing_lon, 4929)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_a.spacing_lon, expected 4929, "
           "is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_a.spacing_lon;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_a.tile_id, 63410)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_a.tile_id, expected 63410, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_a.tile_id;

    EXPECT_EQ(last_msg.msg.ssr_tile_definition_dep_a.tile_set_id, 48697)
        << "incorrect value for "
           "last_msg.msg.ssr_tile_definition_dep_a.tile_set_id, expected "
           "48697, is "
        << (int64_t)last_msg.msg.ssr_tile_definition_dep_a.tile_set_id;
  }
}

}  // namespace
