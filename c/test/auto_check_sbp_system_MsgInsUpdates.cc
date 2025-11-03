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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgInsUpdates.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/system.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_system_MsgInsUpdates,
     test_auto_check_sbp_system_MsgInsUpdates) {
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

    sbp_callback_register(&sbp_state, SbpMsgInsUpdates, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 6, 255, 21, 3, 10, 84, 229, 17, 30, 0, 0, 0, 0, 0, 0, 81, 63,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ins_updates.gnsspos = 0;

    test_msg.ins_updates.gnssvel = 0;

    test_msg.ins_updates.nhc = 0;

    test_msg.ins_updates.speed = 0;

    test_msg.ins_updates.tow = 504489300;

    test_msg.ins_updates.wheelticks = 0;

    test_msg.ins_updates.zerovel = 0;

    sbp_message_send(&sbp_state, SbpMsgInsUpdates, 789, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 789)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgInsUpdates, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ins_updates.gnsspos, 0)
        << "incorrect value for last_msg.msg.ins_updates.gnsspos, expected 0, "
           "is "
        << (int64_t)last_msg.msg.ins_updates.gnsspos;

    EXPECT_EQ(last_msg.msg.ins_updates.gnssvel, 0)
        << "incorrect value for last_msg.msg.ins_updates.gnssvel, expected 0, "
           "is "
        << (int64_t)last_msg.msg.ins_updates.gnssvel;

    EXPECT_EQ(last_msg.msg.ins_updates.nhc, 0)
        << "incorrect value for last_msg.msg.ins_updates.nhc, expected 0, is "
        << (int64_t)last_msg.msg.ins_updates.nhc;

    EXPECT_EQ(last_msg.msg.ins_updates.speed, 0)
        << "incorrect value for last_msg.msg.ins_updates.speed, expected 0, is "
        << (int64_t)last_msg.msg.ins_updates.speed;

    EXPECT_EQ(last_msg.msg.ins_updates.tow, 504489300)
        << "incorrect value for last_msg.msg.ins_updates.tow, expected "
           "504489300, is "
        << (int64_t)last_msg.msg.ins_updates.tow;

    EXPECT_EQ(last_msg.msg.ins_updates.wheelticks, 0)
        << "incorrect value for last_msg.msg.ins_updates.wheelticks, expected "
           "0, is "
        << (int64_t)last_msg.msg.ins_updates.wheelticks;

    EXPECT_EQ(last_msg.msg.ins_updates.zerovel, 0)
        << "incorrect value for last_msg.msg.ins_updates.zerovel, expected 0, "
           "is "
        << (int64_t)last_msg.msg.ins_updates.zerovel;
  }
}

}  // namespace
