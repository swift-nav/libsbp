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
// spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientQuat.yaml by
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

TEST(auto_check_sbp_orientation_MsgOrientQuat,
     test_auto_check_sbp_orientation_MsgOrientQuat) {
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

    sbp_callback_register(&sbp_state, SbpMsgOrientQuat, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 32, 2,   66, 0, 37, 0, 0,  0, 0, 3,  0,  0, 0,   7,
        0,  0,  0,   8,  0, 0,  0, 4,  0, 0, 0,  0,  0, 64,  64,
        0,  0,  128, 64, 0, 0,  0, 65, 0, 0, 64, 64, 1, 186, 6,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.orient_quat.flags = 1;

    test_msg.orient_quat.tow = 0;

    test_msg.orient_quat.w = 3;

    test_msg.orient_quat.w_accuracy = 3.0;

    test_msg.orient_quat.x = 7;

    test_msg.orient_quat.x_accuracy = 4.0;

    test_msg.orient_quat.y = 8;

    test_msg.orient_quat.y_accuracy = 8.0;

    test_msg.orient_quat.z = 4;

    test_msg.orient_quat.z_accuracy = 3.0;

    sbp_message_send(&sbp_state, SbpMsgOrientQuat, 66, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgOrientQuat, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.orient_quat.flags, 1)
        << "incorrect value for last_msg.msg.orient_quat.flags, expected 1, is "
        << (int64_t)last_msg.msg.orient_quat.flags;

    EXPECT_EQ(last_msg.msg.orient_quat.tow, 0)
        << "incorrect value for last_msg.msg.orient_quat.tow, expected 0, is "
        << (int64_t)last_msg.msg.orient_quat.tow;

    EXPECT_EQ(last_msg.msg.orient_quat.w, 3)
        << "incorrect value for last_msg.msg.orient_quat.w, expected 3, is "
        << (int64_t)last_msg.msg.orient_quat.w;

    EXPECT_LE((last_msg.msg.orient_quat.w_accuracy * 100 - 3.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_quat.w_accuracy, expected "
           "3.0, is "
        << last_msg.msg.orient_quat.w_accuracy;

    EXPECT_EQ(last_msg.msg.orient_quat.x, 7)
        << "incorrect value for last_msg.msg.orient_quat.x, expected 7, is "
        << (int64_t)last_msg.msg.orient_quat.x;

    EXPECT_LE((last_msg.msg.orient_quat.x_accuracy * 100 - 4.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_quat.x_accuracy, expected "
           "4.0, is "
        << last_msg.msg.orient_quat.x_accuracy;

    EXPECT_EQ(last_msg.msg.orient_quat.y, 8)
        << "incorrect value for last_msg.msg.orient_quat.y, expected 8, is "
        << (int64_t)last_msg.msg.orient_quat.y;

    EXPECT_LE((last_msg.msg.orient_quat.y_accuracy * 100 - 8.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_quat.y_accuracy, expected "
           "8.0, is "
        << last_msg.msg.orient_quat.y_accuracy;

    EXPECT_EQ(last_msg.msg.orient_quat.z, 4)
        << "incorrect value for last_msg.msg.orient_quat.z, expected 4, is "
        << (int64_t)last_msg.msg.orient_quat.z;

    EXPECT_LE((last_msg.msg.orient_quat.z_accuracy * 100 - 3.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_quat.z_accuracy, expected "
           "3.0, is "
        << last_msg.msg.orient_quat.z_accuracy;
  }
}

}  // namespace
