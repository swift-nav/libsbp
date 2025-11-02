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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedCovGnss.yaml by
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

TEST(auto_check_sbp_navigation_MsgVelNedCovGnss,
     test_auto_check_sbp_navigation_MsgVelNedCovGnss) {
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

    sbp_callback_register(&sbp_state, SbpMsgVelNedCovGnss, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  50,  2,   0,   16,  42,  168, 230, 233, 29,  251, 255, 255,
        255, 0,   0,   0,   0,   246, 255, 255, 255, 15,  58,  207, 58,
        248, 139, 116, 55,  103, 197, 57,  57,  203, 186, 129, 58,  109,
        171, 44,  57,  135, 39,  1,   60,  21,  2,   155, 3,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_cov_gnss.cov_d_d = 0.007882959209382534;

    test_msg.vel_ned_cov_gnss.cov_e_d = 0.00016467059322167188;

    test_msg.vel_ned_cov_gnss.cov_e_e = 0.0009897587588056922;

    test_msg.vel_ned_cov_gnss.cov_n_d = 0.00017716512957122177;

    test_msg.vel_ned_cov_gnss.cov_n_e = 1.457612233934924e-05;

    test_msg.vel_ned_cov_gnss.cov_n_n = 0.0015810149488970637;

    test_msg.vel_ned_cov_gnss.d = -10;

    test_msg.vel_ned_cov_gnss.e = 0;

    test_msg.vel_ned_cov_gnss.flags = 2;

    test_msg.vel_ned_cov_gnss.n = -5;

    test_msg.vel_ned_cov_gnss.n_sats = 21;

    test_msg.vel_ned_cov_gnss.tow = 501868200;

    sbp_message_send(&sbp_state, SbpMsgVelNedCovGnss, 4096, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 4096)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelNedCovGnss, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE(
        (last_msg.msg.vel_ned_cov_gnss.cov_d_d * 100 - 0.00788295920938 * 100),
        0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.cov_d_d, "
           "expected 0.00788295920938, is "
        << last_msg.msg.vel_ned_cov_gnss.cov_d_d;

    EXPECT_LE(
        (last_msg.msg.vel_ned_cov_gnss.cov_e_d * 100 - 0.000164670593222 * 100),
        0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.cov_e_d, "
           "expected 0.000164670593222, is "
        << last_msg.msg.vel_ned_cov_gnss.cov_e_d;

    EXPECT_LE(
        (last_msg.msg.vel_ned_cov_gnss.cov_e_e * 100 - 0.000989758758806 * 100),
        0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.cov_e_e, "
           "expected 0.000989758758806, is "
        << last_msg.msg.vel_ned_cov_gnss.cov_e_e;

    EXPECT_LE(
        (last_msg.msg.vel_ned_cov_gnss.cov_n_d * 100 - 0.000177165129571 * 100),
        0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.cov_n_d, "
           "expected 0.000177165129571, is "
        << last_msg.msg.vel_ned_cov_gnss.cov_n_d;

    EXPECT_LE(
        (last_msg.msg.vel_ned_cov_gnss.cov_n_e * 100 - 1.45761223393e-05 * 100),
        0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.cov_n_e, "
           "expected 1.45761223393e-05, is "
        << last_msg.msg.vel_ned_cov_gnss.cov_n_e;

    EXPECT_LE(
        (last_msg.msg.vel_ned_cov_gnss.cov_n_n * 100 - 0.0015810149489 * 100),
        0.05)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.cov_n_n, "
           "expected 0.0015810149489, is "
        << last_msg.msg.vel_ned_cov_gnss.cov_n_n;

    EXPECT_EQ(last_msg.msg.vel_ned_cov_gnss.d, -10)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.d, expected -10, "
           "is "
        << (int64_t)last_msg.msg.vel_ned_cov_gnss.d;

    EXPECT_EQ(last_msg.msg.vel_ned_cov_gnss.e, 0)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.e, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned_cov_gnss.e;

    EXPECT_EQ(last_msg.msg.vel_ned_cov_gnss.flags, 2)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.flags, expected "
           "2, is "
        << (int64_t)last_msg.msg.vel_ned_cov_gnss.flags;

    EXPECT_EQ(last_msg.msg.vel_ned_cov_gnss.n, -5)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.n, expected -5, "
           "is "
        << (int64_t)last_msg.msg.vel_ned_cov_gnss.n;

    EXPECT_EQ(last_msg.msg.vel_ned_cov_gnss.n_sats, 21)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.n_sats, expected "
           "21, is "
        << (int64_t)last_msg.msg.vel_ned_cov_gnss.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ned_cov_gnss.tow, 501868200)
        << "incorrect value for last_msg.msg.vel_ned_cov_gnss.tow, expected "
           "501868200, is "
        << (int64_t)last_msg.msg.vel_ned_cov_gnss.tow;
  }
}

}  // namespace
