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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/ssr.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_ssr_MsgSsrOrbitClockDepA,
     test_auto_check_sbp_ssr_MsgSsrOrbitClockDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrOrbitClockDepA,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  220, 5,   33,  166, 47,  225, 114, 31,  189, 43,  30,  1,   30,
        194, 211, 193, 175, 161, 143, 254, 56,  63,  232, 7,   216, 69,  1,
        110, 165, 124, 196, 189, 27,  116, 88,  4,   61,  3,   151, 18,  171,
        147, 46,  198, 85,  243, 245, 225, 235, 123, 181, 210, 157, 252,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_orbit_clock_dep_a.along = 132661048;

    test_msg.ssr_orbit_clock_dep_a.c0 = -970026069;

    test_msg.ssr_orbit_clock_dep_a.c1 = -503975083;

    test_msg.ssr_orbit_clock_dep_a.c2 = -759858197;

    test_msg.ssr_orbit_clock_dep_a.cross = 1845577176;

    test_msg.ssr_orbit_clock_dep_a.dot_along = 72905755;

    test_msg.ssr_orbit_clock_dep_a.dot_cross = 311886653;

    test_msg.ssr_orbit_clock_dep_a.dot_radial = -1111196507;

    test_msg.ssr_orbit_clock_dep_a.iod = 193;

    test_msg.ssr_orbit_clock_dep_a.iod_ssr = 211;

    test_msg.ssr_orbit_clock_dep_a.radial = -24141393;

    test_msg.ssr_orbit_clock_dep_a.sid.code = 30;

    test_msg.ssr_orbit_clock_dep_a.sid.sat = 1;

    test_msg.ssr_orbit_clock_dep_a.time.tow = 3172954849;

    test_msg.ssr_orbit_clock_dep_a.time.wn = 7723;

    test_msg.ssr_orbit_clock_dep_a.update_interval = 194;

    sbp_message_send(&sbp_state, SbpMsgSsrOrbitClockDepA, 42529, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 42529)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgSsrOrbitClockDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.along, 132661048)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.along, "
           "expected 132661048, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.along;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.c0, -970026069)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.c0, "
           "expected -970026069, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.c0;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.c1, -503975083)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.c1, "
           "expected -503975083, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.c1;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.c2, -759858197)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.c2, "
           "expected -759858197, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.c2;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.cross, 1845577176)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.cross, "
           "expected 1845577176, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.cross;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.dot_along, 72905755)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.dot_along, "
           "expected 72905755, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.dot_along;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.dot_cross, 311886653)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.dot_cross, "
           "expected 311886653, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.dot_cross;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.dot_radial, -1111196507)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.dot_radial, "
           "expected -1111196507, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.dot_radial;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.iod, 193)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.iod, "
           "expected 193, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.iod;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.iod_ssr, 211)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.iod_ssr, "
           "expected 211, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.iod_ssr;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.radial, -24141393)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.radial, "
           "expected -24141393, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.radial;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.sid.code, 30)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.sid.code, "
           "expected 30, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.sid.code;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.sid.sat, 1)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.sid.sat, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.sid.sat;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.time.tow, 3172954849)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.time.tow, "
           "expected 3172954849, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.time.tow;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.time.wn, 7723)
        << "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.time.wn, "
           "expected 7723, is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.time.wn;

    EXPECT_EQ(last_msg.msg.ssr_orbit_clock_dep_a.update_interval, 194)
        << "incorrect value for "
           "last_msg.msg.ssr_orbit_clock_dep_a.update_interval, expected 194, "
           "is "
        << (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.update_interval;
  }
}

}  // namespace
