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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIq.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/tracking.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_tracking_MsgTrackingIq,
     test_auto_check_sbp_tracking_MsgTrackingIq) {
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingIq, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 45, 0,  2,   80, 15,  145, 121, 203, 47, 217, 239,
        55, 45, 38, 189, 88, 159, 19,  208, 12,  97, 167,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_iq.channel = 145;

    test_msg.tracking_iq.corrs[0].I = -9937;

    test_msg.tracking_iq.corrs[0].Q = 14319;

    test_msg.tracking_iq.corrs[1].I = 9773;

    test_msg.tracking_iq.corrs[1].Q = 22717;

    test_msg.tracking_iq.corrs[2].I = 5023;

    test_msg.tracking_iq.corrs[2].Q = 3280;

    test_msg.tracking_iq.sid.code = 203;

    test_msg.tracking_iq.sid.sat = 121;

    sbp_message_send(&sbp_state, SbpMsgTrackingIq, 20482, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 20482)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingIq, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_iq.channel, 145)
        << "incorrect value for last_msg.msg.tracking_iq.channel, expected "
           "145, is "
        << (int64_t)last_msg.msg.tracking_iq.channel;

    EXPECT_EQ(last_msg.msg.tracking_iq.corrs[0].I, -9937)
        << "incorrect value for last_msg.msg.tracking_iq.corrs[0].I, expected "
           "-9937, is "
        << (int64_t)last_msg.msg.tracking_iq.corrs[0].I;

    EXPECT_EQ(last_msg.msg.tracking_iq.corrs[0].Q, 14319)
        << "incorrect value for last_msg.msg.tracking_iq.corrs[0].Q, expected "
           "14319, is "
        << (int64_t)last_msg.msg.tracking_iq.corrs[0].Q;

    EXPECT_EQ(last_msg.msg.tracking_iq.corrs[1].I, 9773)
        << "incorrect value for last_msg.msg.tracking_iq.corrs[1].I, expected "
           "9773, is "
        << (int64_t)last_msg.msg.tracking_iq.corrs[1].I;

    EXPECT_EQ(last_msg.msg.tracking_iq.corrs[1].Q, 22717)
        << "incorrect value for last_msg.msg.tracking_iq.corrs[1].Q, expected "
           "22717, is "
        << (int64_t)last_msg.msg.tracking_iq.corrs[1].Q;

    EXPECT_EQ(last_msg.msg.tracking_iq.corrs[2].I, 5023)
        << "incorrect value for last_msg.msg.tracking_iq.corrs[2].I, expected "
           "5023, is "
        << (int64_t)last_msg.msg.tracking_iq.corrs[2].I;

    EXPECT_EQ(last_msg.msg.tracking_iq.corrs[2].Q, 3280)
        << "incorrect value for last_msg.msg.tracking_iq.corrs[2].Q, expected "
           "3280, is "
        << (int64_t)last_msg.msg.tracking_iq.corrs[2].Q;

    EXPECT_EQ(last_msg.msg.tracking_iq.sid.code, 203)
        << "incorrect value for last_msg.msg.tracking_iq.sid.code, expected "
           "203, is "
        << (int64_t)last_msg.msg.tracking_iq.sid.code;

    EXPECT_EQ(last_msg.msg.tracking_iq.sid.sat, 121)
        << "incorrect value for last_msg.msg.tracking_iq.sid.sat, expected "
           "121, is "
        << (int64_t)last_msg.msg.tracking_iq.sid.sat;
  }
}

}  // namespace
