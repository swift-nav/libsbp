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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgUTCTime.yaml by generate.py.
// Do not modify by hand!

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

TEST(auto_check_sbp_navigation_MsgUTCTime,
     test_auto_check_sbp_navigation_MsgUTCTime) {
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

    sbp_callback_register(&sbp_state, SbpMsgUtcTime, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 3, 1, 21, 3,  16, 1, 24, 229, 233, 29,  229,
        7,  4, 9, 19, 24, 9,  0, 8,  175, 47,  199, 253,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.utc_time.day = 9;

    test_msg.utc_time.flags = 1;

    test_msg.utc_time.hours = 19;

    test_msg.utc_time.minutes = 24;

    test_msg.utc_time.month = 4;

    test_msg.utc_time.ns = 800000000;

    test_msg.utc_time.seconds = 9;

    test_msg.utc_time.tow = 501867800;

    test_msg.utc_time.year = 2021;

    sbp_message_send(&sbp_state, SbpMsgUtcTime, 789, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 789)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgUtcTime, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.utc_time.day, 9)
        << "incorrect value for last_msg.msg.utc_time.day, expected 9, is "
        << (int64_t)last_msg.msg.utc_time.day;

    EXPECT_EQ(last_msg.msg.utc_time.flags, 1)
        << "incorrect value for last_msg.msg.utc_time.flags, expected 1, is "
        << (int64_t)last_msg.msg.utc_time.flags;

    EXPECT_EQ(last_msg.msg.utc_time.hours, 19)
        << "incorrect value for last_msg.msg.utc_time.hours, expected 19, is "
        << (int64_t)last_msg.msg.utc_time.hours;

    EXPECT_EQ(last_msg.msg.utc_time.minutes, 24)
        << "incorrect value for last_msg.msg.utc_time.minutes, expected 24, is "
        << (int64_t)last_msg.msg.utc_time.minutes;

    EXPECT_EQ(last_msg.msg.utc_time.month, 4)
        << "incorrect value for last_msg.msg.utc_time.month, expected 4, is "
        << (int64_t)last_msg.msg.utc_time.month;

    EXPECT_EQ(last_msg.msg.utc_time.ns, 800000000)
        << "incorrect value for last_msg.msg.utc_time.ns, expected 800000000, "
           "is "
        << (int64_t)last_msg.msg.utc_time.ns;

    EXPECT_EQ(last_msg.msg.utc_time.seconds, 9)
        << "incorrect value for last_msg.msg.utc_time.seconds, expected 9, is "
        << (int64_t)last_msg.msg.utc_time.seconds;

    EXPECT_EQ(last_msg.msg.utc_time.tow, 501867800)
        << "incorrect value for last_msg.msg.utc_time.tow, expected 501867800, "
           "is "
        << (int64_t)last_msg.msg.utc_time.tow;

    EXPECT_EQ(last_msg.msg.utc_time.year, 2021)
        << "incorrect value for last_msg.msg.utc_time.year, expected 2021, is "
        << (int64_t)last_msg.msg.utc_time.year;
  }
}

}  // namespace
