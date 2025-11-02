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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGLODepC.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/observation.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_observation_MsgEphemerisGLODepC,
     test_auto_check_sbp_observation_MsgEphemerisGLODepC) {
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

    sbp_callback_register(&sbp_state, SbpMsgEphemerisGloDepC, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  135, 0,   195, 4,   119, 4,   3,   70,  197, 6,   0,   106,
        8,   205, 204, 204, 204, 204, 204, 20,  64,  96,  9,   0,   0,
        1,   0,   0,   0,   0,   0,   0,   0,   112, 61,  0,   0,   0,
        0,   48,  236, 21,  191, 0,   0,   0,   0,   0,   0,   40,  190,
        0,   0,   128, 66,  246, 57,  103, 193, 0,   0,   0,   34,  170,
        78,  34,  65,  0,   0,   240, 199, 84,  86,  117, 193, 0,   0,
        0,   98,  6,   250, 154, 192, 0,   0,   0,   217, 58,  221, 163,
        192, 0,   0,   0,   184, 138, 46,  139, 64,  0,   0,   0,   0,
        0,   64,  175, 62,  0,   0,   0,   0,   0,   64,  175, 62,  0,
        0,   0,   0,   0,   112, 199, 62,  14,  151, 65,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ephemeris_glo_dep_c.acc[0] = 9.313225746154785e-07;

    test_msg.ephemeris_glo_dep_c.acc[1] = 9.313225746154785e-07;

    test_msg.ephemeris_glo_dep_c.acc[2] = 2.7939677238464355e-06;

    test_msg.ephemeris_glo_dep_c.common.fit_interval = 2400;

    test_msg.ephemeris_glo_dep_c.common.health_bits = 0;

    test_msg.ephemeris_glo_dep_c.common.sid.code = 3;

    test_msg.ephemeris_glo_dep_c.common.sid.sat = 4;

    test_msg.ephemeris_glo_dep_c.common.toe.tow = 443718;

    test_msg.ephemeris_glo_dep_c.common.toe.wn = 2154;

    test_msg.ephemeris_glo_dep_c.common.ura = 5.2;

    test_msg.ephemeris_glo_dep_c.common.valid = 1;

    test_msg.ephemeris_glo_dep_c.d_tau = -2.7939677238464355e-09;

    test_msg.ephemeris_glo_dep_c.fcn = 14;

    test_msg.ephemeris_glo_dep_c.gamma = 9.094947017729282e-13;

    test_msg.ephemeris_glo_dep_c.pos[0] = -12177330.078125;

    test_msg.ephemeris_glo_dep_c.pos[1] = 599893.06640625;

    test_msg.ephemeris_glo_dep_c.pos[2] = -22373708.49609375;

    test_msg.ephemeris_glo_dep_c.tau = -8.36281105875969e-05;

    test_msg.ephemeris_glo_dep_c.vel[0] = -1726.506233215332;

    test_msg.ephemeris_glo_dep_c.vel[1] = -2542.6149368286133;

    test_msg.ephemeris_glo_dep_c.vel[2] = 869.8177337646484;

    sbp_message_send(&sbp_state, SbpMsgEphemerisGloDepC, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisGloDepC, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.ephemeris_glo_dep_c.acc[0] * 100 -
               9.31322574615e-07 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.acc[0], "
           "expected 9.31322574615e-07, is "
        << last_msg.msg.ephemeris_glo_dep_c.acc[0];
    EXPECT_LE((last_msg.msg.ephemeris_glo_dep_c.acc[1] * 100 -
               9.31322574615e-07 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.acc[1], "
           "expected 9.31322574615e-07, is "
        << last_msg.msg.ephemeris_glo_dep_c.acc[1];
    EXPECT_LE((last_msg.msg.ephemeris_glo_dep_c.acc[2] * 100 -
               2.79396772385e-06 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.acc[2], "
           "expected 2.79396772385e-06, is "
        << last_msg.msg.ephemeris_glo_dep_c.acc[2];

    EXPECT_EQ(last_msg.msg.ephemeris_glo_dep_c.common.fit_interval, 2400)
        << "incorrect value for "
           "last_msg.msg.ephemeris_glo_dep_c.common.fit_interval, expected "
           "2400, is "
        << (int64_t)last_msg.msg.ephemeris_glo_dep_c.common.fit_interval;

    EXPECT_EQ(last_msg.msg.ephemeris_glo_dep_c.common.health_bits, 0)
        << "incorrect value for "
           "last_msg.msg.ephemeris_glo_dep_c.common.health_bits, expected 0, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_glo_dep_c.common.health_bits;

    EXPECT_EQ(last_msg.msg.ephemeris_glo_dep_c.common.sid.code, 3)
        << "incorrect value for "
           "last_msg.msg.ephemeris_glo_dep_c.common.sid.code, expected 3, is "
        << (int64_t)last_msg.msg.ephemeris_glo_dep_c.common.sid.code;

    EXPECT_EQ(last_msg.msg.ephemeris_glo_dep_c.common.sid.sat, 4)
        << "incorrect value for "
           "last_msg.msg.ephemeris_glo_dep_c.common.sid.sat, expected 4, is "
        << (int64_t)last_msg.msg.ephemeris_glo_dep_c.common.sid.sat;

    EXPECT_EQ(last_msg.msg.ephemeris_glo_dep_c.common.toe.tow, 443718)
        << "incorrect value for "
           "last_msg.msg.ephemeris_glo_dep_c.common.toe.tow, expected 443718, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_glo_dep_c.common.toe.tow;

    EXPECT_EQ(last_msg.msg.ephemeris_glo_dep_c.common.toe.wn, 2154)
        << "incorrect value for "
           "last_msg.msg.ephemeris_glo_dep_c.common.toe.wn, expected 2154, is "
        << (int64_t)last_msg.msg.ephemeris_glo_dep_c.common.toe.wn;

    EXPECT_LE((last_msg.msg.ephemeris_glo_dep_c.common.ura * 100 - 5.2 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.common.ura, "
           "expected 5.2, is "
        << last_msg.msg.ephemeris_glo_dep_c.common.ura;

    EXPECT_EQ(last_msg.msg.ephemeris_glo_dep_c.common.valid, 1)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.common.valid, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ephemeris_glo_dep_c.common.valid;

    EXPECT_LE((last_msg.msg.ephemeris_glo_dep_c.d_tau * 100 -
               -2.79396772385e-09 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.d_tau, "
           "expected -2.79396772385e-09, is "
        << last_msg.msg.ephemeris_glo_dep_c.d_tau;

    EXPECT_EQ(last_msg.msg.ephemeris_glo_dep_c.fcn, 14)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.fcn, expected "
           "14, is "
        << (int64_t)last_msg.msg.ephemeris_glo_dep_c.fcn;

    EXPECT_LE((last_msg.msg.ephemeris_glo_dep_c.gamma * 100 -
               9.09494701773e-13 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.gamma, "
           "expected 9.09494701773e-13, is "
        << last_msg.msg.ephemeris_glo_dep_c.gamma;

    EXPECT_LE(
        (last_msg.msg.ephemeris_glo_dep_c.pos[0] * 100 - -12177330.0781 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.pos[0], "
           "expected -12177330.0781, is "
        << last_msg.msg.ephemeris_glo_dep_c.pos[0];
    EXPECT_LE(
        (last_msg.msg.ephemeris_glo_dep_c.pos[1] * 100 - 599893.066406 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.pos[1], "
           "expected 599893.066406, is "
        << last_msg.msg.ephemeris_glo_dep_c.pos[1];
    EXPECT_LE(
        (last_msg.msg.ephemeris_glo_dep_c.pos[2] * 100 - -22373708.4961 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.pos[2], "
           "expected -22373708.4961, is "
        << last_msg.msg.ephemeris_glo_dep_c.pos[2];

    EXPECT_LE(
        (last_msg.msg.ephemeris_glo_dep_c.tau * 100 - -8.36281105876e-05 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.tau, expected "
           "-8.36281105876e-05, is "
        << last_msg.msg.ephemeris_glo_dep_c.tau;

    EXPECT_LE(
        (last_msg.msg.ephemeris_glo_dep_c.vel[0] * 100 - -1726.50623322 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.vel[0], "
           "expected -1726.50623322, is "
        << last_msg.msg.ephemeris_glo_dep_c.vel[0];
    EXPECT_LE(
        (last_msg.msg.ephemeris_glo_dep_c.vel[1] * 100 - -2542.61493683 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.vel[1], "
           "expected -2542.61493683, is "
        << last_msg.msg.ephemeris_glo_dep_c.vel[1];
    EXPECT_LE(
        (last_msg.msg.ephemeris_glo_dep_c.vel[2] * 100 - 869.817733765 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_glo_dep_c.vel[2], "
           "expected 869.817733765, is "
        << last_msg.msg.ephemeris_glo_dep_c.vel[2];
  }
}

}  // namespace
