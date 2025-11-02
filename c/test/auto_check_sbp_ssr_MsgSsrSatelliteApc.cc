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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApc.yaml by generate.py.
// Do not modify by hand!

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

TEST(auto_check_sbp_ssr_MsgSsrSatelliteApc,
     test_auto_check_sbp_ssr_MsgSsrSatelliteApc) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrSatelliteApc, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5,  6,  0,  0,  41,  127, 58,  9,   0,   174, 8,   1,
        2,  3,  2,  0,  4,  61,  0,   1,   0,   255, 255, 217, 2,
        11, 10, 8,  5,  1,  252, 248, 246, 246, 246, 249, 252, 0,
        6,  12, 22, 30, 41, 41,  41,  41,  144, 161,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_satellite_apc.apc[0].pco[0] = 1;

    test_msg.ssr_satellite_apc.apc[0].pco[1] = -1;

    test_msg.ssr_satellite_apc.apc[0].pco[2] = 729;

    test_msg.ssr_satellite_apc.apc[0].pcv[0] = 11;

    test_msg.ssr_satellite_apc.apc[0].pcv[1] = 10;

    test_msg.ssr_satellite_apc.apc[0].pcv[2] = 8;

    test_msg.ssr_satellite_apc.apc[0].pcv[3] = 5;

    test_msg.ssr_satellite_apc.apc[0].pcv[4] = 1;

    test_msg.ssr_satellite_apc.apc[0].pcv[5] = -4;

    test_msg.ssr_satellite_apc.apc[0].pcv[6] = -8;

    test_msg.ssr_satellite_apc.apc[0].pcv[7] = -10;

    test_msg.ssr_satellite_apc.apc[0].pcv[8] = -10;

    test_msg.ssr_satellite_apc.apc[0].pcv[9] = -10;

    test_msg.ssr_satellite_apc.apc[0].pcv[10] = -7;

    test_msg.ssr_satellite_apc.apc[0].pcv[11] = -4;

    test_msg.ssr_satellite_apc.apc[0].pcv[12] = 0;

    test_msg.ssr_satellite_apc.apc[0].pcv[13] = 6;

    test_msg.ssr_satellite_apc.apc[0].pcv[14] = 12;

    test_msg.ssr_satellite_apc.apc[0].pcv[15] = 22;

    test_msg.ssr_satellite_apc.apc[0].pcv[16] = 30;

    test_msg.ssr_satellite_apc.apc[0].pcv[17] = 41;

    test_msg.ssr_satellite_apc.apc[0].pcv[18] = 41;

    test_msg.ssr_satellite_apc.apc[0].pcv[19] = 41;

    test_msg.ssr_satellite_apc.apc[0].pcv[20] = 41;

    test_msg.ssr_satellite_apc.apc[0].sat_info = 4;

    test_msg.ssr_satellite_apc.apc[0].sid.code = 0;

    test_msg.ssr_satellite_apc.apc[0].sid.sat = 2;

    test_msg.ssr_satellite_apc.apc[0].svn = 61;

    test_msg.ssr_satellite_apc.iod_ssr = 3;

    test_msg.ssr_satellite_apc.n_apc = 1;

    test_msg.ssr_satellite_apc.sol_id = 2;

    test_msg.ssr_satellite_apc.time.tow = 604799;

    test_msg.ssr_satellite_apc.time.wn = 2222;

    test_msg.ssr_satellite_apc.update_interval = 1;

    sbp_message_send(&sbp_state, SbpMsgSsrSatelliteApc, 0, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrSatelliteApc, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pco[0], 1)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pco[0], "
           "expected 1, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pco[0];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pco[1], -1)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pco[1], "
           "expected -1, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pco[1];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pco[2], 729)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pco[2], "
           "expected 729, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pco[2];

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[0], 11)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[0], "
           "expected 11, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[0];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[1], 10)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[1], "
           "expected 10, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[1];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[2], 8)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[2], "
           "expected 8, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[2];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[3], 5)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[3], "
           "expected 5, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[3];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[4], 1)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[4], "
           "expected 1, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[4];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[5], -4)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[5], "
           "expected -4, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[5];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[6], -8)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[6], "
           "expected -8, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[6];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[7], -10)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[7], "
           "expected -10, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[7];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[8], -10)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[8], "
           "expected -10, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[8];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[9], -10)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[9], "
           "expected -10, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[9];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[10], -7)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[10], "
           "expected -7, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[10];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[11], -4)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[11], "
           "expected -4, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[11];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[12], 0)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[12], "
           "expected 0, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[12];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[13], 6)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[13], "
           "expected 6, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[13];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[14], 12)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[14], "
           "expected 12, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[14];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[15], 22)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[15], "
           "expected 22, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[15];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[16], 30)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[16], "
           "expected 30, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[16];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[17], 41)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[17], "
           "expected 41, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[17];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[18], 41)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[18], "
           "expected 41, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[18];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[19], 41)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[19], "
           "expected 41, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[19];
    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].pcv[20], 41)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[20], "
           "expected 41, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].pcv[20];

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].sat_info, 4)
        << "incorrect value for "
           "last_msg.msg.ssr_satellite_apc.apc[0].sat_info, expected 4, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].sat_info;

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.ssr_satellite_apc.apc[0].sid.code, expected 0, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].sid.code;

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].sid.sat, 2)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].sid.sat, "
           "expected 2, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].sid.sat;

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.apc[0].svn, 61)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].svn, "
           "expected 61, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.apc[0].svn;

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.iod_ssr, 3)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.iod_ssr, "
           "expected 3, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.iod_ssr;

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.n_apc, 1)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.n_apc, expected "
           "1, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.n_apc;

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.sol_id, 2)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.sol_id, "
           "expected 2, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.sol_id;

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.time.tow, 604799)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.time.tow, "
           "expected 604799, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.time.tow;

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.time.wn, 2222)
        << "incorrect value for last_msg.msg.ssr_satellite_apc.time.wn, "
           "expected 2222, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.time.wn;

    EXPECT_EQ(last_msg.msg.ssr_satellite_apc.update_interval, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_satellite_apc.update_interval, expected 1, is "
        << (int64_t)last_msg.msg.ssr_satellite_apc.update_interval;
  }
}

}  // namespace
