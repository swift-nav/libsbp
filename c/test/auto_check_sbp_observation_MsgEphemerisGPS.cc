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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGPS.yaml by
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

TEST(auto_check_sbp_observation_MsgEphemerisGPS,
     test_auto_check_sbp_observation_MsgEphemerisGPS) {
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

    sbp_callback_register(&sbp_state, SbpMsgEphemerisGps, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  138, 0,   10,  9,   139, 22,  0,   176, 207, 6,   0,   106, 8,
        0,   0,   0,   64,  64,  56,  0,   0,   1,   0,   0,   0,   152, 178,
        0,   64,  81,  194, 0,   80,  154, 67,  0,   32,  56,  182, 0,   128,
        82,  54,  0,   0,   0,   50,  0,   0,   248, 179, 114, 216, 96,  180,
        49,  117, 56,  62,  142, 41,  5,   235, 95,  135, 150, 191, 0,   0,
        0,   32,  191, 247, 124, 63,  0,   0,   192, 206, 140, 33,  180, 64,
        41,  131, 179, 134, 141, 248, 253, 191, 227, 133, 81,  54,  204, 30,
        67,  190, 216, 59,  199, 39,  96,  168, 239, 191, 71,  11,  217, 147,
        145, 228, 237, 63,  221, 47,  100, 224, 255, 47,  198, 189, 96,  139,
        37,  186, 0,   0,   30,  45,  0,   0,   0,   0,   176, 207, 6,   0,
        106, 8,   45,  45,  0,   170, 4,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ephemeris_gps.af0 = -0.0006315018981695175;

    test_msg.ephemeris_gps.af1 = 8.981260180007666e-12;

    test_msg.ephemeris_gps.af2 = 0.0;

    test_msg.ephemeris_gps.c_ic = 7.450580596923828e-09;

    test_msg.ephemeris_gps.c_is = -1.1548399925231934e-07;

    test_msg.ephemeris_gps.c_rc = 308.625;

    test_msg.ephemeris_gps.c_rs = -52.3125;

    test_msg.ephemeris_gps.c_uc = -2.7436763048171997e-06;

    test_msg.ephemeris_gps.c_us = 3.1366944313049316e-06;

    test_msg.ephemeris_gps.common.fit_interval = 14400;

    test_msg.ephemeris_gps.common.health_bits = 0;

    test_msg.ephemeris_gps.common.sid.code = 0;

    test_msg.ephemeris_gps.common.sid.sat = 22;

    test_msg.ephemeris_gps.common.toe.tow = 446384;

    test_msg.ephemeris_gps.common.toe.wn = 2154;

    test_msg.ephemeris_gps.common.ura = 2.0;

    test_msg.ephemeris_gps.common.valid = 1;

    test_msg.ephemeris_gps.dn = 5.694522914022375e-09;

    test_msg.ephemeris_gps.ecc = 0.007072207052260637;

    test_msg.ephemeris_gps.inc = 0.9341514480259797;

    test_msg.ephemeris_gps.inc_dot = -4.035882396415757e-11;

    test_msg.ephemeris_gps.iodc = 45;

    test_msg.ephemeris_gps.iode = 45;

    test_msg.ephemeris_gps.m0 = -0.02200078842114688;

    test_msg.ephemeris_gps.omega0 = -1.8731818448797617;

    test_msg.ephemeris_gps.omegadot = -8.903585155774196e-09;

    test_msg.ephemeris_gps.sqrta = 5153.550029754639;

    test_msg.ephemeris_gps.tgd = -1.7695128917694092e-08;

    test_msg.ephemeris_gps.toc.tow = 446384;

    test_msg.ephemeris_gps.toc.wn = 2154;

    test_msg.ephemeris_gps.w = -0.9893036629599647;

    sbp_message_send(&sbp_state, SbpMsgEphemerisGps, 2314, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 2314)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisGps, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.ephemeris_gps.af0 * 100 - -0.00063150189817 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.af0, expected "
           "-0.00063150189817, is "
        << last_msg.msg.ephemeris_gps.af0;

    EXPECT_LE((last_msg.msg.ephemeris_gps.af1 * 100 - 8.98126018001e-12 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.af1, expected "
           "8.98126018001e-12, is "
        << last_msg.msg.ephemeris_gps.af1;

    EXPECT_LE((last_msg.msg.ephemeris_gps.af2 * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.af2, expected 0.0, "
           "is "
        << last_msg.msg.ephemeris_gps.af2;

    EXPECT_LE((last_msg.msg.ephemeris_gps.c_ic * 100 - 7.45058059692e-09 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.c_ic, expected "
           "7.45058059692e-09, is "
        << last_msg.msg.ephemeris_gps.c_ic;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gps.c_is * 100 - -1.15483999252e-07 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.c_is, expected "
           "-1.15483999252e-07, is "
        << last_msg.msg.ephemeris_gps.c_is;

    EXPECT_LE((last_msg.msg.ephemeris_gps.c_rc * 100 - 308.625 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.c_rc, expected "
           "308.625, is "
        << last_msg.msg.ephemeris_gps.c_rc;

    EXPECT_LE((last_msg.msg.ephemeris_gps.c_rs * 100 - -52.3125 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.c_rs, expected "
           "-52.3125, is "
        << last_msg.msg.ephemeris_gps.c_rs;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gps.c_uc * 100 - -2.74367630482e-06 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.c_uc, expected "
           "-2.74367630482e-06, is "
        << last_msg.msg.ephemeris_gps.c_uc;

    EXPECT_LE((last_msg.msg.ephemeris_gps.c_us * 100 - 3.1366944313e-06 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.c_us, expected "
           "3.1366944313e-06, is "
        << last_msg.msg.ephemeris_gps.c_us;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.common.fit_interval, 14400)
        << "incorrect value for "
           "last_msg.msg.ephemeris_gps.common.fit_interval, expected 14400, is "
        << (int64_t)last_msg.msg.ephemeris_gps.common.fit_interval;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.common.health_bits, 0)
        << "incorrect value for last_msg.msg.ephemeris_gps.common.health_bits, "
           "expected 0, is "
        << (int64_t)last_msg.msg.ephemeris_gps.common.health_bits;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.common.sid.code, 0)
        << "incorrect value for last_msg.msg.ephemeris_gps.common.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.ephemeris_gps.common.sid.code;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.common.sid.sat, 22)
        << "incorrect value for last_msg.msg.ephemeris_gps.common.sid.sat, "
           "expected 22, is "
        << (int64_t)last_msg.msg.ephemeris_gps.common.sid.sat;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.common.toe.tow, 446384)
        << "incorrect value for last_msg.msg.ephemeris_gps.common.toe.tow, "
           "expected 446384, is "
        << (int64_t)last_msg.msg.ephemeris_gps.common.toe.tow;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.common.toe.wn, 2154)
        << "incorrect value for last_msg.msg.ephemeris_gps.common.toe.wn, "
           "expected 2154, is "
        << (int64_t)last_msg.msg.ephemeris_gps.common.toe.wn;

    EXPECT_LE((last_msg.msg.ephemeris_gps.common.ura * 100 - 2.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.common.ura, "
           "expected 2.0, is "
        << last_msg.msg.ephemeris_gps.common.ura;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.common.valid, 1)
        << "incorrect value for last_msg.msg.ephemeris_gps.common.valid, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ephemeris_gps.common.valid;

    EXPECT_LE((last_msg.msg.ephemeris_gps.dn * 100 - 5.69452291402e-09 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.dn, expected "
           "5.69452291402e-09, is "
        << last_msg.msg.ephemeris_gps.dn;

    EXPECT_LE((last_msg.msg.ephemeris_gps.ecc * 100 - 0.00707220705226 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.ecc, expected "
           "0.00707220705226, is "
        << last_msg.msg.ephemeris_gps.ecc;

    EXPECT_LE((last_msg.msg.ephemeris_gps.inc * 100 - 0.934151448026 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.inc, expected "
           "0.934151448026, is "
        << last_msg.msg.ephemeris_gps.inc;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gps.inc_dot * 100 - -4.03588239642e-11 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.inc_dot, expected "
           "-4.03588239642e-11, is "
        << last_msg.msg.ephemeris_gps.inc_dot;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.iodc, 45)
        << "incorrect value for last_msg.msg.ephemeris_gps.iodc, expected 45, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_gps.iodc;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.iode, 45)
        << "incorrect value for last_msg.msg.ephemeris_gps.iode, expected 45, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_gps.iode;

    EXPECT_LE((last_msg.msg.ephemeris_gps.m0 * 100 - -0.0220007884211 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.m0, expected "
           "-0.0220007884211, is "
        << last_msg.msg.ephemeris_gps.m0;

    EXPECT_LE((last_msg.msg.ephemeris_gps.omega0 * 100 - -1.87318184488 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.omega0, expected "
           "-1.87318184488, is "
        << last_msg.msg.ephemeris_gps.omega0;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gps.omegadot * 100 - -8.90358515577e-09 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.omegadot, expected "
           "-8.90358515577e-09, is "
        << last_msg.msg.ephemeris_gps.omegadot;

    EXPECT_LE((last_msg.msg.ephemeris_gps.sqrta * 100 - 5153.55002975 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.sqrta, expected "
           "5153.55002975, is "
        << last_msg.msg.ephemeris_gps.sqrta;

    EXPECT_LE((last_msg.msg.ephemeris_gps.tgd * 100 - -1.76951289177e-08 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.tgd, expected "
           "-1.76951289177e-08, is "
        << last_msg.msg.ephemeris_gps.tgd;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.toc.tow, 446384)
        << "incorrect value for last_msg.msg.ephemeris_gps.toc.tow, expected "
           "446384, is "
        << (int64_t)last_msg.msg.ephemeris_gps.toc.tow;

    EXPECT_EQ(last_msg.msg.ephemeris_gps.toc.wn, 2154)
        << "incorrect value for last_msg.msg.ephemeris_gps.toc.wn, expected "
           "2154, is "
        << (int64_t)last_msg.msg.ephemeris_gps.toc.wn;

    EXPECT_LE((last_msg.msg.ephemeris_gps.w * 100 - -0.98930366296 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_gps.w, expected "
           "-0.98930366296, is "
        << last_msg.msg.ephemeris_gps.w;
  }
}

}  // namespace
