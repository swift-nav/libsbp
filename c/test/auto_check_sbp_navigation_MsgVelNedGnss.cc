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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedGnss.yaml by
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

TEST(auto_check_sbp_navigation_MsgVelNedGnss,
     test_auto_check_sbp_navigation_MsgVelNedGnss) {
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

    sbp_callback_register(&sbp_state, SbpMsgVelNedGnss, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 46, 2, 0,   16,  22,  168, 230, 233, 29, 251, 255, 255, 255, 0,
        0,  0,  0, 246, 255, 255, 255, 40,  0,   89, 0,   21,  2,   99,  171,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_gnss.d = -10;

    test_msg.vel_ned_gnss.e = 0;

    test_msg.vel_ned_gnss.flags = 2;

    test_msg.vel_ned_gnss.h_accuracy = 40;

    test_msg.vel_ned_gnss.n = -5;

    test_msg.vel_ned_gnss.n_sats = 21;

    test_msg.vel_ned_gnss.tow = 501868200;

    test_msg.vel_ned_gnss.v_accuracy = 89;

    sbp_message_send(&sbp_state, SbpMsgVelNedGnss, 4096, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelNedGnss, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ned_gnss.d, -10)
        << "incorrect value for last_msg.msg.vel_ned_gnss.d, expected -10, is "
        << (int64_t)last_msg.msg.vel_ned_gnss.d;

    EXPECT_EQ(last_msg.msg.vel_ned_gnss.e, 0)
        << "incorrect value for last_msg.msg.vel_ned_gnss.e, expected 0, is "
        << (int64_t)last_msg.msg.vel_ned_gnss.e;

    EXPECT_EQ(last_msg.msg.vel_ned_gnss.flags, 2)
        << "incorrect value for last_msg.msg.vel_ned_gnss.flags, expected 2, "
           "is "
        << (int64_t)last_msg.msg.vel_ned_gnss.flags;

    EXPECT_EQ(last_msg.msg.vel_ned_gnss.h_accuracy, 40)
        << "incorrect value for last_msg.msg.vel_ned_gnss.h_accuracy, expected "
           "40, is "
        << (int64_t)last_msg.msg.vel_ned_gnss.h_accuracy;

    EXPECT_EQ(last_msg.msg.vel_ned_gnss.n, -5)
        << "incorrect value for last_msg.msg.vel_ned_gnss.n, expected -5, is "
        << (int64_t)last_msg.msg.vel_ned_gnss.n;

    EXPECT_EQ(last_msg.msg.vel_ned_gnss.n_sats, 21)
        << "incorrect value for last_msg.msg.vel_ned_gnss.n_sats, expected 21, "
           "is "
        << (int64_t)last_msg.msg.vel_ned_gnss.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ned_gnss.tow, 501868200)
        << "incorrect value for last_msg.msg.vel_ned_gnss.tow, expected "
           "501868200, is "
        << (int64_t)last_msg.msg.vel_ned_gnss.tow;

    EXPECT_EQ(last_msg.msg.vel_ned_gnss.v_accuracy, 89)
        << "incorrect value for last_msg.msg.vel_ned_gnss.v_accuracy, expected "
           "89, is "
        << (int64_t)last_msg.msg.vel_ned_gnss.v_accuracy;
  }
}

}  // namespace
