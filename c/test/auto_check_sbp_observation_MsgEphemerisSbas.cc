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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisSbas.yaml by
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

TEST(auto_check_sbp_observation_MsgEphemerisSbas,
     test_auto_check_sbp_observation_MsgEphemerisSbas) {
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

    sbp_callback_register(&sbp_state, SbpMsgEphemerisSbas, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  140, 0,   195, 4,   74,  22,  6,   176, 207, 6,   0,   106, 8,
        0,   0,   64,  177, 0,   0,   0,   0,   1,   0,   0,   0,   128, 66,
        246, 57,  103, 193, 0,   0,   0,   34,  170, 78,  34,  65,  0,   0,
        240, 199, 84,  86,  117, 193, 51,  208, 215, 196, 215, 233, 30,  197,
        86,  116, 89,  68,  0,   0,   122, 53,  0,   0,   122, 53,  0,   128,
        59,  54,  96,  139, 37,  186, 0,   0,   30,  45,  192, 147,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ephemeris_sbas.a_gf0 = -0.0006315018981695175;

    test_msg.ephemeris_sbas.a_gf1 = 8.981260180007666e-12;

    test_msg.ephemeris_sbas.acc[0] = 9.313225746154785e-07;

    test_msg.ephemeris_sbas.acc[1] = 9.313225746154785e-07;

    test_msg.ephemeris_sbas.acc[2] = 2.7939677238464355e-06;

    test_msg.ephemeris_sbas.common.fit_interval = 0;

    test_msg.ephemeris_sbas.common.health_bits = 0;

    test_msg.ephemeris_sbas.common.sid.code = 6;

    test_msg.ephemeris_sbas.common.sid.sat = 22;

    test_msg.ephemeris_sbas.common.toe.tow = 446384;

    test_msg.ephemeris_sbas.common.toe.wn = 2154;

    test_msg.ephemeris_sbas.common.ura = -2.7939677238464355e-09;

    test_msg.ephemeris_sbas.common.valid = 1;

    test_msg.ephemeris_sbas.pos[0] = -12177330.078125;

    test_msg.ephemeris_sbas.pos[1] = 599893.06640625;

    test_msg.ephemeris_sbas.pos[2] = -22373708.49609375;

    test_msg.ephemeris_sbas.vel[0] = -1726.5062255859375;

    test_msg.ephemeris_sbas.vel[1] = -2542.614990234375;

    test_msg.ephemeris_sbas.vel[2] = 869.8177490234375;

    sbp_message_send(&sbp_state, SbpMsgEphemerisSbas, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisSbas, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE(
        (last_msg.msg.ephemeris_sbas.a_gf0 * 100 - -0.00063150189817 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.a_gf0, expected "
           "-0.00063150189817, is "
        << last_msg.msg.ephemeris_sbas.a_gf0;

    EXPECT_LE(
        (last_msg.msg.ephemeris_sbas.a_gf1 * 100 - 8.98126018001e-12 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.a_gf1, expected "
           "8.98126018001e-12, is "
        << last_msg.msg.ephemeris_sbas.a_gf1;

    EXPECT_LE(
        (last_msg.msg.ephemeris_sbas.acc[0] * 100 - 9.31322574615e-07 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.acc[0], expected "
           "9.31322574615e-07, is "
        << last_msg.msg.ephemeris_sbas.acc[0];
    EXPECT_LE(
        (last_msg.msg.ephemeris_sbas.acc[1] * 100 - 9.31322574615e-07 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.acc[1], expected "
           "9.31322574615e-07, is "
        << last_msg.msg.ephemeris_sbas.acc[1];
    EXPECT_LE(
        (last_msg.msg.ephemeris_sbas.acc[2] * 100 - 2.79396772385e-06 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.acc[2], expected "
           "2.79396772385e-06, is "
        << last_msg.msg.ephemeris_sbas.acc[2];

    EXPECT_EQ(last_msg.msg.ephemeris_sbas.common.fit_interval, 0)
        << "incorrect value for "
           "last_msg.msg.ephemeris_sbas.common.fit_interval, expected 0, is "
        << (int64_t)last_msg.msg.ephemeris_sbas.common.fit_interval;

    EXPECT_EQ(last_msg.msg.ephemeris_sbas.common.health_bits, 0)
        << "incorrect value for "
           "last_msg.msg.ephemeris_sbas.common.health_bits, expected 0, is "
        << (int64_t)last_msg.msg.ephemeris_sbas.common.health_bits;

    EXPECT_EQ(last_msg.msg.ephemeris_sbas.common.sid.code, 6)
        << "incorrect value for last_msg.msg.ephemeris_sbas.common.sid.code, "
           "expected 6, is "
        << (int64_t)last_msg.msg.ephemeris_sbas.common.sid.code;

    EXPECT_EQ(last_msg.msg.ephemeris_sbas.common.sid.sat, 22)
        << "incorrect value for last_msg.msg.ephemeris_sbas.common.sid.sat, "
           "expected 22, is "
        << (int64_t)last_msg.msg.ephemeris_sbas.common.sid.sat;

    EXPECT_EQ(last_msg.msg.ephemeris_sbas.common.toe.tow, 446384)
        << "incorrect value for last_msg.msg.ephemeris_sbas.common.toe.tow, "
           "expected 446384, is "
        << (int64_t)last_msg.msg.ephemeris_sbas.common.toe.tow;

    EXPECT_EQ(last_msg.msg.ephemeris_sbas.common.toe.wn, 2154)
        << "incorrect value for last_msg.msg.ephemeris_sbas.common.toe.wn, "
           "expected 2154, is "
        << (int64_t)last_msg.msg.ephemeris_sbas.common.toe.wn;

    EXPECT_LE((last_msg.msg.ephemeris_sbas.common.ura * 100 -
               -2.79396772385e-09 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.common.ura, "
           "expected -2.79396772385e-09, is "
        << last_msg.msg.ephemeris_sbas.common.ura;

    EXPECT_EQ(last_msg.msg.ephemeris_sbas.common.valid, 1)
        << "incorrect value for last_msg.msg.ephemeris_sbas.common.valid, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ephemeris_sbas.common.valid;

    EXPECT_LE((last_msg.msg.ephemeris_sbas.pos[0] * 100 - -12177330.0781 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.pos[0], expected "
           "-12177330.0781, is "
        << last_msg.msg.ephemeris_sbas.pos[0];
    EXPECT_LE((last_msg.msg.ephemeris_sbas.pos[1] * 100 - 599893.066406 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.pos[1], expected "
           "599893.066406, is "
        << last_msg.msg.ephemeris_sbas.pos[1];
    EXPECT_LE((last_msg.msg.ephemeris_sbas.pos[2] * 100 - -22373708.4961 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.pos[2], expected "
           "-22373708.4961, is "
        << last_msg.msg.ephemeris_sbas.pos[2];

    EXPECT_LE((last_msg.msg.ephemeris_sbas.vel[0] * 100 - -1726.50622559 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.vel[0], expected "
           "-1726.50622559, is "
        << last_msg.msg.ephemeris_sbas.vel[0];
    EXPECT_LE((last_msg.msg.ephemeris_sbas.vel[1] * 100 - -2542.61499023 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.vel[1], expected "
           "-2542.61499023, is "
        << last_msg.msg.ephemeris_sbas.vel[1];
    EXPECT_LE((last_msg.msg.ephemeris_sbas.vel[2] * 100 - 869.817749023 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_sbas.vel[2], expected "
           "869.817749023, is "
        << last_msg.msg.ephemeris_sbas.vel[2];
  }
}

}  // namespace
