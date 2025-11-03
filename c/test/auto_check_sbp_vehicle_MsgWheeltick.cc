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
// spec/tests/yaml/swiftnav/sbp/vehicle/test_MsgWheeltick.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/vehicle.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_vehicle_MsgWheeltick,
     test_auto_check_sbp_vehicle_MsgWheeltick) {
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

    sbp_callback_register(&sbp_state, SbpMsgWheeltick, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 4, 9, 107, 69,  14,  254, 27, 114, 44, 26,
        0,  0, 0, 1,   146, 225, 51,  9,  210, 36, 56,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.wheeltick.flags = 1;

    test_msg.wheeltick.source = 146;

    test_msg.wheeltick.ticks = -771148831;

    test_msg.wheeltick.time = 112414825470;

    sbp_message_send(&sbp_state, SbpMsgWheeltick, 17771, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 17771)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgWheeltick, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.wheeltick.flags, 1)
        << "incorrect value for last_msg.msg.wheeltick.flags, expected 1, is "
        << (int64_t)last_msg.msg.wheeltick.flags;

    EXPECT_EQ(last_msg.msg.wheeltick.source, 146)
        << "incorrect value for last_msg.msg.wheeltick.source, expected 146, "
           "is "
        << (int64_t)last_msg.msg.wheeltick.source;

    EXPECT_EQ(last_msg.msg.wheeltick.ticks, -771148831)
        << "incorrect value for last_msg.msg.wheeltick.ticks, expected "
           "-771148831, is "
        << (int64_t)last_msg.msg.wheeltick.ticks;

    EXPECT_EQ(last_msg.msg.wheeltick.time, 112414825470)
        << "incorrect value for last_msg.msg.wheeltick.time, expected "
           "112414825470, is "
        << (int64_t)last_msg.msg.wheeltick.time;
  }
}

}  // namespace
