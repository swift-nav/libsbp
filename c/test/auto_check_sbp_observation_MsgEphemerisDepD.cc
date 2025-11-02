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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisDepD.yaml by
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

TEST(auto_check_sbp_observation_MsgEphemerisDepD,
     test_auto_check_sbp_observation_MsgEphemerisDepD) {
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

    sbp_callback_register(&sbp_state, SbpMsgEphemerisDepD, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  128, 0,   195, 4,   185, 0,   0,   0,   0,   0,   0,   83,  190,
        0,   0,   0,   0,   0,   40,  74,  192, 0,   0,   0,   0,   0,   74,
        115, 64,  0,   0,   0,   0,   0,   4,   199, 190, 0,   0,   0,   0,
        0,   80,  202, 62,  0,   0,   0,   0,   0,   0,   64,  62,  0,   0,
        0,   0,   0,   0,   127, 190, 114, 216, 96,  180, 49,  117, 56,  62,
        142, 41,  5,   235, 95,  135, 150, 191, 0,   0,   0,   32,  191, 247,
        124, 63,  0,   0,   192, 206, 140, 33,  180, 64,  41,  131, 179, 134,
        141, 248, 253, 191, 227, 133, 81,  54,  204, 30,  67,  190, 216, 59,
        199, 39,  96,  168, 239, 191, 71,  11,  217, 147, 145, 228, 237, 63,
        221, 47,  100, 224, 255, 47,  198, 189, 0,   0,   0,   0,   108, 177,
        68,  191, 0,   0,   0,   0,   0,   192, 163, 61,  154, 153, 153, 153,
        153, 153, 201, 63,  205, 204, 204, 204, 192, 62,  27,  65,  106, 8,
        205, 204, 204, 204, 192, 62,  27,  65,  106, 8,   1,   0,   22,  0,
        0,   0,   45,  45,  0,   0,   0,   0,   0,   95,  7,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ephemeris_dep_d.af0 = -0.0006315018981695175;

    test_msg.ephemeris_dep_d.af1 = 8.981260180007666e-12;

    test_msg.ephemeris_dep_d.af2 = 0.2;

    test_msg.ephemeris_dep_d.c_ic = 7.450580596923828e-09;

    test_msg.ephemeris_dep_d.c_is = -1.1548399925231934e-07;

    test_msg.ephemeris_dep_d.c_rc = 308.625;

    test_msg.ephemeris_dep_d.c_rs = -52.3125;

    test_msg.ephemeris_dep_d.c_uc = -2.7436763048171997e-06;

    test_msg.ephemeris_dep_d.c_us = 3.1366944313049316e-06;

    test_msg.ephemeris_dep_d.dn = 5.694522914022375e-09;

    test_msg.ephemeris_dep_d.ecc = 0.007072207052260637;

    test_msg.ephemeris_dep_d.healthy = 0;

    test_msg.ephemeris_dep_d.inc = 0.9341514480259797;

    test_msg.ephemeris_dep_d.inc_dot = -4.035882396415757e-11;

    test_msg.ephemeris_dep_d.iodc = 45;

    test_msg.ephemeris_dep_d.iode = 45;

    test_msg.ephemeris_dep_d.m0 = -0.02200078842114688;

    test_msg.ephemeris_dep_d.omega0 = -1.8731818448797617;

    test_msg.ephemeris_dep_d.omegadot = -8.903585155774196e-09;

    test_msg.ephemeris_dep_d.reserved = 0;

    test_msg.ephemeris_dep_d.sid.code = 0;

    test_msg.ephemeris_dep_d.sid.reserved = 0;

    test_msg.ephemeris_dep_d.sid.sat = 22;

    test_msg.ephemeris_dep_d.sqrta = 5153.550029754639;

    test_msg.ephemeris_dep_d.tgd = -1.7695128917694092e-08;

    test_msg.ephemeris_dep_d.toc_tow = 446384.2;

    test_msg.ephemeris_dep_d.toc_wn = 2154;

    test_msg.ephemeris_dep_d.toe_tow = 446384.2;

    test_msg.ephemeris_dep_d.toe_wn = 2154;

    test_msg.ephemeris_dep_d.valid = 1;

    test_msg.ephemeris_dep_d.w = -0.9893036629599647;

    sbp_message_send(&sbp_state, SbpMsgEphemerisDepD, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisDepD, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE(
        (last_msg.msg.ephemeris_dep_d.af0 * 100 - -0.00063150189817 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.af0, expected "
           "-0.00063150189817, is "
        << last_msg.msg.ephemeris_dep_d.af0;

    EXPECT_LE(
        (last_msg.msg.ephemeris_dep_d.af1 * 100 - 8.98126018001e-12 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.af1, expected "
           "8.98126018001e-12, is "
        << last_msg.msg.ephemeris_dep_d.af1;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.af2 * 100 - 0.2 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.af2, expected "
           "0.2, is "
        << last_msg.msg.ephemeris_dep_d.af2;

    EXPECT_LE(
        (last_msg.msg.ephemeris_dep_d.c_ic * 100 - 7.45058059692e-09 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.c_ic, expected "
           "7.45058059692e-09, is "
        << last_msg.msg.ephemeris_dep_d.c_ic;

    EXPECT_LE(
        (last_msg.msg.ephemeris_dep_d.c_is * 100 - -1.15483999252e-07 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.c_is, expected "
           "-1.15483999252e-07, is "
        << last_msg.msg.ephemeris_dep_d.c_is;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.c_rc * 100 - 308.625 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.c_rc, expected "
           "308.625, is "
        << last_msg.msg.ephemeris_dep_d.c_rc;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.c_rs * 100 - -52.3125 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.c_rs, expected "
           "-52.3125, is "
        << last_msg.msg.ephemeris_dep_d.c_rs;

    EXPECT_LE(
        (last_msg.msg.ephemeris_dep_d.c_uc * 100 - -2.74367630482e-06 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.c_uc, expected "
           "-2.74367630482e-06, is "
        << last_msg.msg.ephemeris_dep_d.c_uc;

    EXPECT_LE(
        (last_msg.msg.ephemeris_dep_d.c_us * 100 - 3.1366944313e-06 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.c_us, expected "
           "3.1366944313e-06, is "
        << last_msg.msg.ephemeris_dep_d.c_us;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.dn * 100 - 5.69452291402e-09 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.dn, expected "
           "5.69452291402e-09, is "
        << last_msg.msg.ephemeris_dep_d.dn;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.ecc * 100 - 0.00707220705226 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.ecc, expected "
           "0.00707220705226, is "
        << last_msg.msg.ephemeris_dep_d.ecc;

    EXPECT_EQ(last_msg.msg.ephemeris_dep_d.healthy, 0)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.healthy, expected "
           "0, is "
        << (int64_t)last_msg.msg.ephemeris_dep_d.healthy;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.inc * 100 - 0.934151448026 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.inc, expected "
           "0.934151448026, is "
        << last_msg.msg.ephemeris_dep_d.inc;

    EXPECT_LE(
        (last_msg.msg.ephemeris_dep_d.inc_dot * 100 - -4.03588239642e-11 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.inc_dot, expected "
           "-4.03588239642e-11, is "
        << last_msg.msg.ephemeris_dep_d.inc_dot;

    EXPECT_EQ(last_msg.msg.ephemeris_dep_d.iodc, 45)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.iodc, expected "
           "45, is "
        << (int64_t)last_msg.msg.ephemeris_dep_d.iodc;

    EXPECT_EQ(last_msg.msg.ephemeris_dep_d.iode, 45)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.iode, expected "
           "45, is "
        << (int64_t)last_msg.msg.ephemeris_dep_d.iode;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.m0 * 100 - -0.0220007884211 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.m0, expected "
           "-0.0220007884211, is "
        << last_msg.msg.ephemeris_dep_d.m0;

    EXPECT_LE(
        (last_msg.msg.ephemeris_dep_d.omega0 * 100 - -1.87318184488 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.omega0, expected "
           "-1.87318184488, is "
        << last_msg.msg.ephemeris_dep_d.omega0;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.omegadot * 100 -
               -8.90358515577e-09 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.omegadot, "
           "expected -8.90358515577e-09, is "
        << last_msg.msg.ephemeris_dep_d.omegadot;

    EXPECT_EQ(last_msg.msg.ephemeris_dep_d.reserved, 0)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.ephemeris_dep_d.reserved;

    EXPECT_EQ(last_msg.msg.ephemeris_dep_d.sid.code, 0)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.ephemeris_dep_d.sid.code;

    EXPECT_EQ(last_msg.msg.ephemeris_dep_d.sid.reserved, 0)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.ephemeris_dep_d.sid.reserved;

    EXPECT_EQ(last_msg.msg.ephemeris_dep_d.sid.sat, 22)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.sid.sat, expected "
           "22, is "
        << (int64_t)last_msg.msg.ephemeris_dep_d.sid.sat;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.sqrta * 100 - 5153.55002975 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.sqrta, expected "
           "5153.55002975, is "
        << last_msg.msg.ephemeris_dep_d.sqrta;

    EXPECT_LE(
        (last_msg.msg.ephemeris_dep_d.tgd * 100 - -1.76951289177e-08 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.tgd, expected "
           "-1.76951289177e-08, is "
        << last_msg.msg.ephemeris_dep_d.tgd;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.toc_tow * 100 - 446384.2 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.toc_tow, expected "
           "446384.2, is "
        << last_msg.msg.ephemeris_dep_d.toc_tow;

    EXPECT_EQ(last_msg.msg.ephemeris_dep_d.toc_wn, 2154)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.toc_wn, expected "
           "2154, is "
        << (int64_t)last_msg.msg.ephemeris_dep_d.toc_wn;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.toe_tow * 100 - 446384.2 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.toe_tow, expected "
           "446384.2, is "
        << last_msg.msg.ephemeris_dep_d.toe_tow;

    EXPECT_EQ(last_msg.msg.ephemeris_dep_d.toe_wn, 2154)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.toe_wn, expected "
           "2154, is "
        << (int64_t)last_msg.msg.ephemeris_dep_d.toe_wn;

    EXPECT_EQ(last_msg.msg.ephemeris_dep_d.valid, 1)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.valid, expected "
           "1, is "
        << (int64_t)last_msg.msg.ephemeris_dep_d.valid;

    EXPECT_LE((last_msg.msg.ephemeris_dep_d.w * 100 - -0.98930366296 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_dep_d.w, expected "
           "-0.98930366296, is "
        << last_msg.msg.ephemeris_dep_d.w;
  }
}

}  // namespace
