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
// spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientQuatCov.yaml by
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

TEST(auto_check_sbp_orientation_MsgOrientQuatCov,
     test_auto_check_sbp_orientation_MsgOrientQuatCov) {
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

    sbp_callback_register(&sbp_state, SbpMsgOrientQuatCov, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  35, 2, 66, 0, 45, 0, 0, 0, 0,  3,   0,  0,   0,  7, 0,  0,  0,
        8,   0,  0, 0,  4, 0,  0, 0, 0, 0,  128, 63, 0,   0,  0, 63, 0,  0,
        128, 62, 0, 0,  0, 64, 0, 0, 0, 62, 0,   0,  128, 64, 1, 46, 73,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.orient_quat_cov.cov_xx = 1.0;

    test_msg.orient_quat_cov.cov_xy = 0.5;

    test_msg.orient_quat_cov.cov_xz = 0.25;

    test_msg.orient_quat_cov.cov_yy = 2.0;

    test_msg.orient_quat_cov.cov_yz = 0.125;

    test_msg.orient_quat_cov.cov_zz = 4.0;

    test_msg.orient_quat_cov.flags = 1;

    test_msg.orient_quat_cov.tow = 0;

    test_msg.orient_quat_cov.w = 3;

    test_msg.orient_quat_cov.x = 7;

    test_msg.orient_quat_cov.y = 8;

    test_msg.orient_quat_cov.z = 4;

    sbp_message_send(&sbp_state, SbpMsgOrientQuatCov, 66, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgOrientQuatCov, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.orient_quat_cov.cov_xx * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_quat_cov.cov_xx, expected "
           "1.0, is "
        << last_msg.msg.orient_quat_cov.cov_xx;

    EXPECT_LE((last_msg.msg.orient_quat_cov.cov_xy * 100 - 0.5 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_quat_cov.cov_xy, expected "
           "0.5, is "
        << last_msg.msg.orient_quat_cov.cov_xy;

    EXPECT_LE((last_msg.msg.orient_quat_cov.cov_xz * 100 - 0.25 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_quat_cov.cov_xz, expected "
           "0.25, is "
        << last_msg.msg.orient_quat_cov.cov_xz;

    EXPECT_LE((last_msg.msg.orient_quat_cov.cov_yy * 100 - 2.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_quat_cov.cov_yy, expected "
           "2.0, is "
        << last_msg.msg.orient_quat_cov.cov_yy;

    EXPECT_LE((last_msg.msg.orient_quat_cov.cov_yz * 100 - 0.125 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_quat_cov.cov_yz, expected "
           "0.125, is "
        << last_msg.msg.orient_quat_cov.cov_yz;

    EXPECT_LE((last_msg.msg.orient_quat_cov.cov_zz * 100 - 4.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.orient_quat_cov.cov_zz, expected "
           "4.0, is "
        << last_msg.msg.orient_quat_cov.cov_zz;

    EXPECT_EQ(last_msg.msg.orient_quat_cov.flags, 1)
        << "incorrect value for last_msg.msg.orient_quat_cov.flags, expected "
           "1, is "
        << (int64_t)last_msg.msg.orient_quat_cov.flags;

    EXPECT_EQ(last_msg.msg.orient_quat_cov.tow, 0)
        << "incorrect value for last_msg.msg.orient_quat_cov.tow, expected 0, "
           "is "
        << (int64_t)last_msg.msg.orient_quat_cov.tow;

    EXPECT_EQ(last_msg.msg.orient_quat_cov.w, 3)
        << "incorrect value for last_msg.msg.orient_quat_cov.w, expected 3, is "
        << (int64_t)last_msg.msg.orient_quat_cov.w;

    EXPECT_EQ(last_msg.msg.orient_quat_cov.x, 7)
        << "incorrect value for last_msg.msg.orient_quat_cov.x, expected 7, is "
        << (int64_t)last_msg.msg.orient_quat_cov.x;

    EXPECT_EQ(last_msg.msg.orient_quat_cov.y, 8)
        << "incorrect value for last_msg.msg.orient_quat_cov.y, expected 8, is "
        << (int64_t)last_msg.msg.orient_quat_cov.y;

    EXPECT_EQ(last_msg.msg.orient_quat_cov.z, 4)
        << "incorrect value for last_msg.msg.orient_quat_cov.z, expected 4, is "
        << (int64_t)last_msg.msg.orient_quat_cov.z;
  }
}

}  // namespace
