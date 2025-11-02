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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDepA.yaml
// by generate.py. Do not modify by hand!

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

TEST(auto_check_sbp_tracking_MsgTrackingStateDetailedDepA,
     test_auto_check_sbp_tracking_MsgTrackingStateDetailedDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingStateDetailedDepA,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 33,  0,   155, 110, 57,  46,  31,  180, 38,  219, 0,   0,
        0,  133, 100, 71,  94,  192, 2,   160, 207, 212, 255, 135, 139,
        62, 62,  179, 83,  227, 245, 134, 160, 204, 78,  95,  255, 38,
        59, 161, 15,  255, 86,  189, 248, 31,  191, 136, 194, 124, 23,
        15, 91,  249, 117, 142, 90,  219, 67,  25,  83,  62,  122, 100,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_detailed_dep_a.L.f = 204;

    test_msg.tracking_state_detailed_dep_a.L.i = -1601767965;

    test_msg.tracking_state_detailed_dep_a.P = 1044286343;

    test_msg.tracking_state_detailed_dep_a.P_std = 21427;

    test_msg.tracking_state_detailed_dep_a.acceleration = -114;

    test_msg.tracking_state_detailed_dep_a.clock_drift = 23311;

    test_msg.tracking_state_detailed_dep_a.clock_offset = 6012;

    test_msg.tracking_state_detailed_dep_a.cn0 = 78;

    test_msg.tracking_state_detailed_dep_a.corr_spacing = 30201;

    test_msg.tracking_state_detailed_dep_a.doppler = 1459556257;

    test_msg.tracking_state_detailed_dep_a.doppler_std = 63677;

    test_msg.tracking_state_detailed_dep_a.lock = 65375;

    test_msg.tracking_state_detailed_dep_a.misc_flags = 62;

    test_msg.tracking_state_detailed_dep_a.nav_flags = 25;

    test_msg.tracking_state_detailed_dep_a.pset_flags = 83;

    test_msg.tracking_state_detailed_dep_a.recv_time = 941247176494;

    test_msg.tracking_state_detailed_dep_a.sid.code = 59;

    test_msg.tracking_state_detailed_dep_a.sid.sat = 38;

    test_msg.tracking_state_detailed_dep_a.sync_flags = 90;

    test_msg.tracking_state_detailed_dep_a.tot.ns_residual = -811597120;

    test_msg.tracking_state_detailed_dep_a.tot.tow = 1581737093;

    test_msg.tracking_state_detailed_dep_a.tot.wn = 65492;

    test_msg.tracking_state_detailed_dep_a.tow_flags = 219;

    test_msg.tracking_state_detailed_dep_a.track_flags = 67;

    test_msg.tracking_state_detailed_dep_a.uptime = 3263741727;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDetailedDepA, 28315,
                     &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 28315)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDepA, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.L.f, 204)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.L.f, expected 204, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.L.f;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.L.i, -1601767965)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.L.i, expected "
           "-1601767965, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.L.i;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.P, 1044286343)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep_a.P, "
           "expected 1044286343, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.P;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.P_std, 21427)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.P_std, expected 21427, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.P_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.acceleration, -114)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.acceleration, expected "
           "-114, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.acceleration;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.clock_drift, 23311)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.clock_drift, expected "
           "23311, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.clock_drift;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.clock_offset, 6012)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.clock_offset, expected "
           "6012, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.clock_offset;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.cn0, 78)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.cn0, expected 78, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.corr_spacing, 30201)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.corr_spacing, expected "
           "30201, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.corr_spacing;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.doppler, 1459556257)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.doppler, expected "
           "1459556257, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.doppler;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.doppler_std, 63677)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.doppler_std, expected "
           "63677, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.doppler_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.lock, 65375)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.lock, expected 65375, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.lock;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.misc_flags, 62)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.misc_flags, expected "
           "62, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.misc_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.nav_flags, 25)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.nav_flags, expected 25, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.nav_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.pset_flags, 83)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.pset_flags, expected "
           "83, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.pset_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.recv_time,
              941247176494)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.recv_time, expected "
           "941247176494, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.recv_time;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.sid.code, 59)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.sid.code, expected 59, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.sid.sat, 38)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.sid.sat, expected 38, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.sync_flags, 90)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.sync_flags, expected "
           "90, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.sync_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.tot.ns_residual,
              -811597120)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.tot.ns_residual, "
           "expected -811597120, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.tot.ns_residual;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.tot.tow, 1581737093)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.tot.tow, expected "
           "1581737093, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.tot.tow;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.tot.wn, 65492)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.tot.wn, expected 65492, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.tot.wn;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.tow_flags, 219)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.tow_flags, expected "
           "219, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.tow_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.track_flags, 67)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.track_flags, expected "
           "67, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.track_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep_a.uptime, 3263741727)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep_a.uptime, expected "
           "3263741727, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep_a.uptime;
  }
}

}  // namespace
