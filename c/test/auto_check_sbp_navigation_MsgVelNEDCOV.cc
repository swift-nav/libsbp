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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDCOV.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/navigation.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_navigation_MsgVelNEDCOV,
     test_auto_check_sbp_navigation_MsgVelNEDCOV) {
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

    sbp_callback_register(&sbp_state, SbpMsgVelNedCov, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 18, 2,   66, 0, 42, 100, 0,   0,  0, 1,   0,   0,  0, 1,  0,   0,
        0,  1,  0,   0,  0, 0,  0,   128, 63, 0, 0,   128, 63, 0, 0,  128, 63,
        0,  0,  128, 63, 0, 0,  128, 63,  0,  0, 128, 63,  10, 0, 88, 205,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_cov.cov_d_d = 1.0;

    test_msg.vel_ned_cov.cov_e_d = 1.0;

    test_msg.vel_ned_cov.cov_e_e = 1.0;

    test_msg.vel_ned_cov.cov_n_d = 1.0;

    test_msg.vel_ned_cov.cov_n_e = 1.0;

    test_msg.vel_ned_cov.cov_n_n = 1.0;

    test_msg.vel_ned_cov.d = 1;

    test_msg.vel_ned_cov.e = 1;

    test_msg.vel_ned_cov.flags = 0;

    test_msg.vel_ned_cov.n = 1;

    test_msg.vel_ned_cov.n_sats = 10;

    test_msg.vel_ned_cov.tow = 100;

    sbp_message_send(&sbp_state, SbpMsgVelNedCov, 66, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelNedCov, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.vel_ned_cov.cov_d_d * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov.cov_d_d, expected "
           "1.0, is "
        << last_msg.msg.vel_ned_cov.cov_d_d;

    EXPECT_LE((last_msg.msg.vel_ned_cov.cov_e_d * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov.cov_e_d, expected "
           "1.0, is "
        << last_msg.msg.vel_ned_cov.cov_e_d;

    EXPECT_LE((last_msg.msg.vel_ned_cov.cov_e_e * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov.cov_e_e, expected "
           "1.0, is "
        << last_msg.msg.vel_ned_cov.cov_e_e;

    EXPECT_LE((last_msg.msg.vel_ned_cov.cov_n_d * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov.cov_n_d, expected "
           "1.0, is "
        << last_msg.msg.vel_ned_cov.cov_n_d;

    EXPECT_LE((last_msg.msg.vel_ned_cov.cov_n_e * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov.cov_n_e, expected "
           "1.0, is "
        << last_msg.msg.vel_ned_cov.cov_n_e;

    EXPECT_LE((last_msg.msg.vel_ned_cov.cov_n_n * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov.cov_n_n, expected "
           "1.0, is "
        << last_msg.msg.vel_ned_cov.cov_n_n;

    EXPECT_EQ(last_msg.msg.vel_ned_cov.d, 1)
        << "incorrect value for last_msg.msg.vel_ned_cov.d, expected 1, is "
        << (int64_t)last_msg.msg.vel_ned_cov.d;

    EXPECT_EQ(last_msg.msg.vel_ned_cov.e, 1)
        << "incorrect value for last_msg.msg.vel_ned_cov.e, expected 1, is "
        << (int64_t)last_msg.msg.vel_ned_cov.e;

    EXPECT_EQ(last_msg.msg.vel_ned_cov.flags, 0)
        << "incorrect value for last_msg.msg.vel_ned_cov.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ned_cov.flags;

    EXPECT_EQ(last_msg.msg.vel_ned_cov.n, 1)
        << "incorrect value for last_msg.msg.vel_ned_cov.n, expected 1, is "
        << (int64_t)last_msg.msg.vel_ned_cov.n;

    EXPECT_EQ(last_msg.msg.vel_ned_cov.n_sats, 10)
        << "incorrect value for last_msg.msg.vel_ned_cov.n_sats, expected 10, "
           "is "
        << (int64_t)last_msg.msg.vel_ned_cov.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ned_cov.tow, 100)
        << "incorrect value for last_msg.msg.vel_ned_cov.tow, expected 100, is "
        << (int64_t)last_msg.msg.vel_ned_cov.tow;
  }
}

}  // namespace
