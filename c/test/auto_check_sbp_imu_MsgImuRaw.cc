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
// spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuRaw.yaml by generate.py. Do not
// modify by hand!

#include <gtest/gtest.h>
#include <libsbp/imu.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_imu_MsgImuRaw, test_auto_check_sbp_imu_MsgImuRaw) {
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

    sbp_callback_register(&sbp_state, SbpMsgImuRaw, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  0,   9,  52, 18, 17, 26,  1,   0,   192, 206, 96,  0,
        223, 255, 44, 16, 60, 0,  208, 254, 238, 255, 70,  135,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.imu_raw.acc_x = 96;

    test_msg.imu_raw.acc_y = -33;

    test_msg.imu_raw.acc_z = 4140;

    test_msg.imu_raw.gyr_x = 60;

    test_msg.imu_raw.gyr_y = -304;

    test_msg.imu_raw.gyr_z = -18;

    test_msg.imu_raw.tow = 3221225754;

    test_msg.imu_raw.tow_f = 206;

    sbp_message_send(&sbp_state, SbpMsgImuRaw, 4660, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 4660)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgImuRaw, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.imu_raw.acc_x, 96)
        << "incorrect value for last_msg.msg.imu_raw.acc_x, expected 96, is "
        << (int64_t)last_msg.msg.imu_raw.acc_x;

    EXPECT_EQ(last_msg.msg.imu_raw.acc_y, -33)
        << "incorrect value for last_msg.msg.imu_raw.acc_y, expected -33, is "
        << (int64_t)last_msg.msg.imu_raw.acc_y;

    EXPECT_EQ(last_msg.msg.imu_raw.acc_z, 4140)
        << "incorrect value for last_msg.msg.imu_raw.acc_z, expected 4140, is "
        << (int64_t)last_msg.msg.imu_raw.acc_z;

    EXPECT_EQ(last_msg.msg.imu_raw.gyr_x, 60)
        << "incorrect value for last_msg.msg.imu_raw.gyr_x, expected 60, is "
        << (int64_t)last_msg.msg.imu_raw.gyr_x;

    EXPECT_EQ(last_msg.msg.imu_raw.gyr_y, -304)
        << "incorrect value for last_msg.msg.imu_raw.gyr_y, expected -304, is "
        << (int64_t)last_msg.msg.imu_raw.gyr_y;

    EXPECT_EQ(last_msg.msg.imu_raw.gyr_z, -18)
        << "incorrect value for last_msg.msg.imu_raw.gyr_z, expected -18, is "
        << (int64_t)last_msg.msg.imu_raw.gyr_z;

    EXPECT_EQ(last_msg.msg.imu_raw.tow, 3221225754)
        << "incorrect value for last_msg.msg.imu_raw.tow, expected 3221225754, "
           "is "
        << (int64_t)last_msg.msg.imu_raw.tow;

    EXPECT_EQ(last_msg.msg.imu_raw.tow_f, 206)
        << "incorrect value for last_msg.msg.imu_raw.tow_f, expected 206, is "
        << (int64_t)last_msg.msg.imu_raw.tow_f;
  }
}

}  // namespace
