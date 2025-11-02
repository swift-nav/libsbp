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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefGnss.yaml by
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

TEST(auto_check_sbp_navigation_MsgVelEcefGnss,
     test_auto_check_sbp_navigation_MsgVelEcefGnss) {
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefGnss, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 45, 2, 0, 16, 20, 224, 229, 233, 29, 253, 255, 255, 255,
        1,  0,  0, 0, 4,  0,  0,   0,   89,  0,  21,  2,   205, 16,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_gnss.accuracy = 89;

    test_msg.vel_ecef_gnss.flags = 2;

    test_msg.vel_ecef_gnss.n_sats = 21;

    test_msg.vel_ecef_gnss.tow = 501868000;

    test_msg.vel_ecef_gnss.x = -3;

    test_msg.vel_ecef_gnss.y = 1;

    test_msg.vel_ecef_gnss.z = 4;

    sbp_message_send(&sbp_state, SbpMsgVelEcefGnss, 4096, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefGnss, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_gnss.accuracy, 89)
        << "incorrect value for last_msg.msg.vel_ecef_gnss.accuracy, expected "
           "89, is "
        << (int64_t)last_msg.msg.vel_ecef_gnss.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_gnss.flags, 2)
        << "incorrect value for last_msg.msg.vel_ecef_gnss.flags, expected 2, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_gnss.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_gnss.n_sats, 21)
        << "incorrect value for last_msg.msg.vel_ecef_gnss.n_sats, expected "
           "21, is "
        << (int64_t)last_msg.msg.vel_ecef_gnss.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_gnss.tow, 501868000)
        << "incorrect value for last_msg.msg.vel_ecef_gnss.tow, expected "
           "501868000, is "
        << (int64_t)last_msg.msg.vel_ecef_gnss.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_gnss.x, -3)
        << "incorrect value for last_msg.msg.vel_ecef_gnss.x, expected -3, is "
        << (int64_t)last_msg.msg.vel_ecef_gnss.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_gnss.y, 1)
        << "incorrect value for last_msg.msg.vel_ecef_gnss.y, expected 1, is "
        << (int64_t)last_msg.msg.vel_ecef_gnss.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_gnss.z, 4)
        << "incorrect value for last_msg.msg.vel_ecef_gnss.z, expected 4, is "
        << (int64_t)last_msg.msg.vel_ecef_gnss.z;
  }
}

}  // namespace
