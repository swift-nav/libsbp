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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPoseRelative.yaml by
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

TEST(auto_check_sbp_navigation_MsgPoseRelative,
     test_auto_check_sbp_navigation_MsgPoseRelative) {
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

    sbp_callback_register(&sbp_state, SbpMsgPoseRelative, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  69,  2,  66,  0,  90,  86,  4,   0,   0,   0,   86,  4,   0,
        0,   172, 8,  0,   0,  76,  4,   0,   0,   38,  2,   0,   0,   100,
        0,   0,   0,  100, 3,  200, 204, 252, 168, 157, 255, 115, 53,  186,
        144, 190, 48, 34,  37, 0,   0,   128, 63,  0,   0,   0,   0,   0,
        0,   0,   0,  0,   0,  128, 63,  0,   0,   0,   0,   0,   0,   128,
        63,  0,   0,  0,   64, 0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   64, 0,   0,  0,   0,   0,   0,   0,   64,  5,   171, 187,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pose_relative.cov_c_x_x = 2.0;

    test_msg.pose_relative.cov_c_x_y = 0.0;

    test_msg.pose_relative.cov_c_x_z = 0.0;

    test_msg.pose_relative.cov_c_y_y = 2.0;

    test_msg.pose_relative.cov_c_y_z = 0.0;

    test_msg.pose_relative.cov_c_z_z = 2.0;

    test_msg.pose_relative.cov_r_x_x = 1.0;

    test_msg.pose_relative.cov_r_x_y = 0.0;

    test_msg.pose_relative.cov_r_x_z = 0.0;

    test_msg.pose_relative.cov_r_y_y = 1.0;

    test_msg.pose_relative.cov_r_y_z = 0.0;

    test_msg.pose_relative.cov_r_z_z = 1.0;

    test_msg.pose_relative.flags = 5;

    test_msg.pose_relative.sensor_id = 0;

    test_msg.pose_relative.timestamp_1 = 1110;

    test_msg.pose_relative.timestamp_2 = 2220;

    test_msg.pose_relative.tow = 1110;

    test_msg.pose_relative.trans[0] = 1100;

    test_msg.pose_relative.trans[1] = 550;

    test_msg.pose_relative.trans[2] = 100;

    test_msg.pose_relative.w = -859307164;

    test_msg.pose_relative.x = -6444804;

    test_msg.pose_relative.y = -1866844813;

    test_msg.pose_relative.z = 622997694;

    sbp_message_send(&sbp_state, SbpMsgPoseRelative, 66, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPoseRelative, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.pose_relative.cov_c_x_x * 100 - 2.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_c_x_x, expected "
           "2.0, is "
        << last_msg.msg.pose_relative.cov_c_x_x;

    EXPECT_LE((last_msg.msg.pose_relative.cov_c_x_y * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_c_x_y, expected "
           "0.0, is "
        << last_msg.msg.pose_relative.cov_c_x_y;

    EXPECT_LE((last_msg.msg.pose_relative.cov_c_x_z * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_c_x_z, expected "
           "0.0, is "
        << last_msg.msg.pose_relative.cov_c_x_z;

    EXPECT_LE((last_msg.msg.pose_relative.cov_c_y_y * 100 - 2.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_c_y_y, expected "
           "2.0, is "
        << last_msg.msg.pose_relative.cov_c_y_y;

    EXPECT_LE((last_msg.msg.pose_relative.cov_c_y_z * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_c_y_z, expected "
           "0.0, is "
        << last_msg.msg.pose_relative.cov_c_y_z;

    EXPECT_LE((last_msg.msg.pose_relative.cov_c_z_z * 100 - 2.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_c_z_z, expected "
           "2.0, is "
        << last_msg.msg.pose_relative.cov_c_z_z;

    EXPECT_LE((last_msg.msg.pose_relative.cov_r_x_x * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_r_x_x, expected "
           "1.0, is "
        << last_msg.msg.pose_relative.cov_r_x_x;

    EXPECT_LE((last_msg.msg.pose_relative.cov_r_x_y * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_r_x_y, expected "
           "0.0, is "
        << last_msg.msg.pose_relative.cov_r_x_y;

    EXPECT_LE((last_msg.msg.pose_relative.cov_r_x_z * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_r_x_z, expected "
           "0.0, is "
        << last_msg.msg.pose_relative.cov_r_x_z;

    EXPECT_LE((last_msg.msg.pose_relative.cov_r_y_y * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_r_y_y, expected "
           "1.0, is "
        << last_msg.msg.pose_relative.cov_r_y_y;

    EXPECT_LE((last_msg.msg.pose_relative.cov_r_y_z * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_r_y_z, expected "
           "0.0, is "
        << last_msg.msg.pose_relative.cov_r_y_z;

    EXPECT_LE((last_msg.msg.pose_relative.cov_r_z_z * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pose_relative.cov_r_z_z, expected "
           "1.0, is "
        << last_msg.msg.pose_relative.cov_r_z_z;

    EXPECT_EQ(last_msg.msg.pose_relative.flags, 5)
        << "incorrect value for last_msg.msg.pose_relative.flags, expected 5, "
           "is "
        << (int64_t)last_msg.msg.pose_relative.flags;

    EXPECT_EQ(last_msg.msg.pose_relative.sensor_id, 0)
        << "incorrect value for last_msg.msg.pose_relative.sensor_id, expected "
           "0, is "
        << (int64_t)last_msg.msg.pose_relative.sensor_id;

    EXPECT_EQ(last_msg.msg.pose_relative.timestamp_1, 1110)
        << "incorrect value for last_msg.msg.pose_relative.timestamp_1, "
           "expected 1110, is "
        << (int64_t)last_msg.msg.pose_relative.timestamp_1;

    EXPECT_EQ(last_msg.msg.pose_relative.timestamp_2, 2220)
        << "incorrect value for last_msg.msg.pose_relative.timestamp_2, "
           "expected 2220, is "
        << (int64_t)last_msg.msg.pose_relative.timestamp_2;

    EXPECT_EQ(last_msg.msg.pose_relative.tow, 1110)
        << "incorrect value for last_msg.msg.pose_relative.tow, expected 1110, "
           "is "
        << (int64_t)last_msg.msg.pose_relative.tow;

    EXPECT_EQ(last_msg.msg.pose_relative.trans[0], 1100)
        << "incorrect value for last_msg.msg.pose_relative.trans[0], expected "
           "1100, is "
        << (int64_t)last_msg.msg.pose_relative.trans[0];
    EXPECT_EQ(last_msg.msg.pose_relative.trans[1], 550)
        << "incorrect value for last_msg.msg.pose_relative.trans[1], expected "
           "550, is "
        << (int64_t)last_msg.msg.pose_relative.trans[1];
    EXPECT_EQ(last_msg.msg.pose_relative.trans[2], 100)
        << "incorrect value for last_msg.msg.pose_relative.trans[2], expected "
           "100, is "
        << (int64_t)last_msg.msg.pose_relative.trans[2];

    EXPECT_EQ(last_msg.msg.pose_relative.w, -859307164)
        << "incorrect value for last_msg.msg.pose_relative.w, expected "
           "-859307164, is "
        << (int64_t)last_msg.msg.pose_relative.w;

    EXPECT_EQ(last_msg.msg.pose_relative.x, -6444804)
        << "incorrect value for last_msg.msg.pose_relative.x, expected "
           "-6444804, is "
        << (int64_t)last_msg.msg.pose_relative.x;

    EXPECT_EQ(last_msg.msg.pose_relative.y, -1866844813)
        << "incorrect value for last_msg.msg.pose_relative.y, expected "
           "-1866844813, is "
        << (int64_t)last_msg.msg.pose_relative.y;

    EXPECT_EQ(last_msg.msg.pose_relative.z, 622997694)
        << "incorrect value for last_msg.msg.pose_relative.z, expected "
           "622997694, is "
        << (int64_t)last_msg.msg.pose_relative.z;
  }
}

}  // namespace
