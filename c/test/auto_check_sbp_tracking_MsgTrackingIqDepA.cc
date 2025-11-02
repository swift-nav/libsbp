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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIqDepA.yaml by
// generate.py. Do not modify by hand!

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

TEST(auto_check_sbp_tracking_MsgTrackingIqDepA,
     test_auto_check_sbp_tracking_MsgTrackingIqDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingIqDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  28, 0,  184, 67,  29,  139, 28,  250, 15,  0,  99, 90,
        170, 96, 71, 121, 33,  161, 52,  211, 162, 101, 41, 36, 226,
        99,  71, 75, 14,  240, 134, 82,  175, 83,  17,  34,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_iq_dep_a.channel = 139;

    test_msg.tracking_iq_dep_a.corrs[0].I = 1621776995;

    test_msg.tracking_iq_dep_a.corrs[0].Q = -1591641785;

    test_msg.tracking_iq_dep_a.corrs[1].I = 1705169716;

    test_msg.tracking_iq_dep_a.corrs[1].Q = 1675764777;

    test_msg.tracking_iq_dep_a.corrs[2].I = -267498681;

    test_msg.tracking_iq_dep_a.corrs[2].Q = 1403998854;

    test_msg.tracking_iq_dep_a.sid.code = 15;

    test_msg.tracking_iq_dep_a.sid.reserved = 0;

    test_msg.tracking_iq_dep_a.sid.sat = 64028;

    sbp_message_send(&sbp_state, SbpMsgTrackingIqDepA, 17336, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 17336)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingIqDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_a.channel, 139)
        << "incorrect value for last_msg.msg.tracking_iq_dep_a.channel, "
           "expected 139, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_a.channel;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_a.corrs[0].I, 1621776995)
        << "incorrect value for last_msg.msg.tracking_iq_dep_a.corrs[0].I, "
           "expected 1621776995, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_a.corrs[0].I;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_a.corrs[0].Q, -1591641785)
        << "incorrect value for last_msg.msg.tracking_iq_dep_a.corrs[0].Q, "
           "expected -1591641785, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_a.corrs[0].Q;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_a.corrs[1].I, 1705169716)
        << "incorrect value for last_msg.msg.tracking_iq_dep_a.corrs[1].I, "
           "expected 1705169716, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_a.corrs[1].I;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_a.corrs[1].Q, 1675764777)
        << "incorrect value for last_msg.msg.tracking_iq_dep_a.corrs[1].Q, "
           "expected 1675764777, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_a.corrs[1].Q;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_a.corrs[2].I, -267498681)
        << "incorrect value for last_msg.msg.tracking_iq_dep_a.corrs[2].I, "
           "expected -267498681, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_a.corrs[2].I;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_a.corrs[2].Q, 1403998854)
        << "incorrect value for last_msg.msg.tracking_iq_dep_a.corrs[2].Q, "
           "expected 1403998854, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_a.corrs[2].Q;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_a.sid.code, 15)
        << "incorrect value for last_msg.msg.tracking_iq_dep_a.sid.code, "
           "expected 15, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_a.sid.code;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_a.sid.reserved, 0)
        << "incorrect value for last_msg.msg.tracking_iq_dep_a.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_a.sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_a.sid.sat, 64028)
        << "incorrect value for last_msg.msg.tracking_iq_dep_a.sid.sat, "
           "expected 64028, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_a.sid.sat;
  }
}

}  // namespace
