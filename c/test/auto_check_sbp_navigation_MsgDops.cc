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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDops.yaml by generate.py. Do
// not modify by hand!

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

TEST(auto_check_sbp_navigation_MsgDops,
     test_auto_check_sbp_navigation_MsgDops) {
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

    sbp_callback_register(&sbp_state, SbpMsgDops, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 8, 2, 66, 0, 15, 100, 0, 0, 0,   2, 0,
        6,  0, 5, 0,  5, 0,  5,   0, 0, 244, 4,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.dops.flags = 0;

    test_msg.dops.gdop = 2;

    test_msg.dops.hdop = 5;

    test_msg.dops.pdop = 6;

    test_msg.dops.tdop = 5;

    test_msg.dops.tow = 100;

    test_msg.dops.vdop = 5;

    sbp_message_send(&sbp_state, SbpMsgDops, 66, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgDops, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.dops.flags, 0)
        << "incorrect value for last_msg.msg.dops.flags, expected 0, is "
        << (int64_t)last_msg.msg.dops.flags;

    EXPECT_EQ(last_msg.msg.dops.gdop, 2)
        << "incorrect value for last_msg.msg.dops.gdop, expected 2, is "
        << (int64_t)last_msg.msg.dops.gdop;

    EXPECT_EQ(last_msg.msg.dops.hdop, 5)
        << "incorrect value for last_msg.msg.dops.hdop, expected 5, is "
        << (int64_t)last_msg.msg.dops.hdop;

    EXPECT_EQ(last_msg.msg.dops.pdop, 6)
        << "incorrect value for last_msg.msg.dops.pdop, expected 6, is "
        << (int64_t)last_msg.msg.dops.pdop;

    EXPECT_EQ(last_msg.msg.dops.tdop, 5)
        << "incorrect value for last_msg.msg.dops.tdop, expected 5, is "
        << (int64_t)last_msg.msg.dops.tdop;

    EXPECT_EQ(last_msg.msg.dops.tow, 100)
        << "incorrect value for last_msg.msg.dops.tow, expected 100, is "
        << (int64_t)last_msg.msg.dops.tow;

    EXPECT_EQ(last_msg.msg.dops.vdop, 5)
        << "incorrect value for last_msg.msg.dops.vdop, expected 5, is "
        << (int64_t)last_msg.msg.dops.vdop;
  }
}

}  // namespace
