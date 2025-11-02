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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCov.yaml by
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

TEST(auto_check_sbp_navigation_MsgPosECEFCov,
     test_auto_check_sbp_navigation_MsgPosECEFCov) {
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

    sbp_callback_register(&sbp_state, SbpMsgPosEcefCov, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  20, 2, 66, 0, 54, 7, 0, 0,   0,  0, 0, 0,   0,   0, 0,
        24,  64, 0, 0,  0, 0,  0, 0, 240, 63, 0, 0, 0,   0,   0, 0,
        16,  64, 0, 0,  0, 65, 0, 0, 224, 64, 0, 0, 0,   64,  0, 0,
        192, 64, 0, 0,  0, 65, 0, 0, 160, 64, 4, 5, 249, 167,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_cov.cov_x_x = 8.0;

    test_msg.pos_ecef_cov.cov_x_y = 7.0;

    test_msg.pos_ecef_cov.cov_x_z = 2.0;

    test_msg.pos_ecef_cov.cov_y_y = 6.0;

    test_msg.pos_ecef_cov.cov_y_z = 8.0;

    test_msg.pos_ecef_cov.cov_z_z = 5.0;

    test_msg.pos_ecef_cov.flags = 5;

    test_msg.pos_ecef_cov.n_sats = 4;

    test_msg.pos_ecef_cov.tow = 7;

    test_msg.pos_ecef_cov.x = 6.0;

    test_msg.pos_ecef_cov.y = 1.0;

    test_msg.pos_ecef_cov.z = 4.0;

    sbp_message_send(&sbp_state, SbpMsgPosEcefCov, 66, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosEcefCov, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.pos_ecef_cov.cov_x_x * 100 - 8.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov.cov_x_x, expected "
           "8.0, is "
        << last_msg.msg.pos_ecef_cov.cov_x_x;

    EXPECT_LE((last_msg.msg.pos_ecef_cov.cov_x_y * 100 - 7.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov.cov_x_y, expected "
           "7.0, is "
        << last_msg.msg.pos_ecef_cov.cov_x_y;

    EXPECT_LE((last_msg.msg.pos_ecef_cov.cov_x_z * 100 - 2.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov.cov_x_z, expected "
           "2.0, is "
        << last_msg.msg.pos_ecef_cov.cov_x_z;

    EXPECT_LE((last_msg.msg.pos_ecef_cov.cov_y_y * 100 - 6.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov.cov_y_y, expected "
           "6.0, is "
        << last_msg.msg.pos_ecef_cov.cov_y_y;

    EXPECT_LE((last_msg.msg.pos_ecef_cov.cov_y_z * 100 - 8.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov.cov_y_z, expected "
           "8.0, is "
        << last_msg.msg.pos_ecef_cov.cov_y_z;

    EXPECT_LE((last_msg.msg.pos_ecef_cov.cov_z_z * 100 - 5.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov.cov_z_z, expected "
           "5.0, is "
        << last_msg.msg.pos_ecef_cov.cov_z_z;

    EXPECT_EQ(last_msg.msg.pos_ecef_cov.flags, 5)
        << "incorrect value for last_msg.msg.pos_ecef_cov.flags, expected 5, "
           "is "
        << (int64_t)last_msg.msg.pos_ecef_cov.flags;

    EXPECT_EQ(last_msg.msg.pos_ecef_cov.n_sats, 4)
        << "incorrect value for last_msg.msg.pos_ecef_cov.n_sats, expected 4, "
           "is "
        << (int64_t)last_msg.msg.pos_ecef_cov.n_sats;

    EXPECT_EQ(last_msg.msg.pos_ecef_cov.tow, 7)
        << "incorrect value for last_msg.msg.pos_ecef_cov.tow, expected 7, is "
        << (int64_t)last_msg.msg.pos_ecef_cov.tow;

    EXPECT_LE((last_msg.msg.pos_ecef_cov.x * 100 - 6.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov.x, expected 6.0, is "
        << last_msg.msg.pos_ecef_cov.x;

    EXPECT_LE((last_msg.msg.pos_ecef_cov.y * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov.y, expected 1.0, is "
        << last_msg.msg.pos_ecef_cov.y;

    EXPECT_LE((last_msg.msg.pos_ecef_cov.z * 100 - 4.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov.z, expected 4.0, is "
        << last_msg.msg.pos_ecef_cov.z;
  }
}

}  // namespace
