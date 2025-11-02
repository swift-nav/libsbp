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
// spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientEuler.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/orientation.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_orientation_MsgOrientEuler,
     test_auto_check_sbp_orientation_MsgOrientEuler) {
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

    sbp_callback_register(&sbp_state, SbpMsgOrientEuler, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 33, 2, 66, 0, 29,  1,  0, 0, 0,  1,  0, 0, 0,   2,  0, 0,  0,   8,
        0,  0,  0, 0,  0, 224, 64, 0, 0, 64, 64, 0, 0, 224, 64, 3, 44, 226,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.orient_euler.flags = 3;

    test_msg.orient_euler.pitch = 2;

    test_msg.orient_euler.pitch_accuracy = 3.0;

    test_msg.orient_euler.roll = 1;

    test_msg.orient_euler.roll_accuracy = 7.0;

    test_msg.orient_euler.tow = 1;

    test_msg.orient_euler.yaw = 8;

    test_msg.orient_euler.yaw_accuracy = 7.0;

    sbp_message_send(&sbp_state, SbpMsgOrientEuler, 66, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgOrientEuler, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.orient_euler.flags, 3)
        << "incorrect value for last_msg.msg.orient_euler.flags, expected 3, "
           "is "
        << (int64_t)last_msg.msg.orient_euler.flags;

    EXPECT_EQ(last_msg.msg.orient_euler.pitch, 2)
        << "incorrect value for last_msg.msg.orient_euler.pitch, expected 2, "
           "is "
        << (int64_t)last_msg.msg.orient_euler.pitch;

    EXPECT_LE((last_msg.msg.orient_euler.pitch_accuracy * 100 - 3.0 * 100),
              0.05)
        << "incorrect value for last_msg.msg.orient_euler.pitch_accuracy, "
           "expected 3.0, is "
        << last_msg.msg.orient_euler.pitch_accuracy;

    EXPECT_EQ(last_msg.msg.orient_euler.roll, 1)
        << "incorrect value for last_msg.msg.orient_euler.roll, expected 1, is "
        << (int64_t)last_msg.msg.orient_euler.roll;

    EXPECT_LE((last_msg.msg.orient_euler.roll_accuracy * 100 - 7.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_euler.roll_accuracy, "
           "expected 7.0, is "
        << last_msg.msg.orient_euler.roll_accuracy;

    EXPECT_EQ(last_msg.msg.orient_euler.tow, 1)
        << "incorrect value for last_msg.msg.orient_euler.tow, expected 1, is "
        << (int64_t)last_msg.msg.orient_euler.tow;

    EXPECT_EQ(last_msg.msg.orient_euler.yaw, 8)
        << "incorrect value for last_msg.msg.orient_euler.yaw, expected 8, is "
        << (int64_t)last_msg.msg.orient_euler.yaw;

    EXPECT_LE((last_msg.msg.orient_euler.yaw_accuracy * 100 - 7.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_euler.yaw_accuracy, "
           "expected 7.0, is "
        << last_msg.msg.orient_euler.yaw_accuracy;
  }
}

}  // namespace
