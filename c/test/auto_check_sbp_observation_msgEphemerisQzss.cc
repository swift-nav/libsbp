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
// spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisQzss.yaml by
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

TEST(auto_check_sbp_observation_msgEphemerisQzss,
     test_auto_check_sbp_observation_msgEphemerisQzss) {
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

    sbp_callback_register(&sbp_state, SbpMsgEphemerisQzss, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  142, 0,   128, 240, 139, 193, 31,  208, 221, 6,   0,   106, 8,
        0,   0,   0,   64,  64,  56,  0,   0,   0,   0,   0,   0,   192, 177,
        0,   232, 228, 195, 0,   160, 19,  194, 0,   224, 135, 183, 0,   96,
        10,  55,  0,   192, 157, 181, 0,   0,   46,  52,  167, 72,  107, 105,
        179, 1,   39,  62,  15,  224, 158, 211, 241, 164, 211, 63,  0,   0,
        0,   24,  251, 83,  179, 63,  0,   0,   0,   34,  44,  93,  185, 64,
        143, 62,  206, 232, 193, 181, 242, 191, 207, 216, 69,  106, 98,  255,
        39,  190, 65,  132, 95,  22,  48,  15,  249, 191, 249, 82,  67,  94,
        30,  100, 231, 63,  117, 167, 187, 233, 187, 253, 181, 61,  160, 129,
        193, 185, 0,   0,   168, 172, 0,   0,   0,   0,   208, 221, 6,   0,
        106, 8,   49,  49,  3,   126, 23,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ephemeris_qzss.af0 = -0.00036908406764268875;

    test_msg.ephemeris_qzss.af1 = -4.774847184307873e-12;

    test_msg.ephemeris_qzss.af2 = 0.0;

    test_msg.ephemeris_qzss.c_ic = -1.1753290891647339e-06;

    test_msg.ephemeris_qzss.c_is = 1.6205012798309326e-07;

    test_msg.ephemeris_qzss.c_rc = -36.90625;

    test_msg.ephemeris_qzss.c_rs = -457.8125;

    test_msg.ephemeris_qzss.c_uc = -1.6197562217712402e-05;

    test_msg.ephemeris_qzss.c_us = 8.247792720794678e-06;

    test_msg.ephemeris_qzss.common.fit_interval = 14400;

    test_msg.ephemeris_qzss.common.health_bits = 0;

    test_msg.ephemeris_qzss.common.sid.code = 31;

    test_msg.ephemeris_qzss.common.sid.sat = 193;

    test_msg.ephemeris_qzss.common.toe.tow = 450000;

    test_msg.ephemeris_qzss.common.toe.wn = 2154;

    test_msg.ephemeris_qzss.common.ura = 2.0;

    test_msg.ephemeris_qzss.common.valid = 0;

    test_msg.ephemeris_qzss.dn = 2.678325848736433e-09;

    test_msg.ephemeris_qzss.ecc = 0.07550019584596157;

    test_msg.ephemeris_qzss.inc = 0.7309715119432375;

    test_msg.ephemeris_qzss.inc_dot = 2.0000833114980698e-11;

    test_msg.ephemeris_qzss.iodc = 817;

    test_msg.ephemeris_qzss.iode = 49;

    test_msg.ephemeris_qzss.m0 = 0.30694242158961144;

    test_msg.ephemeris_qzss.omega0 = -1.1693743795366662;

    test_msg.ephemeris_qzss.omegadot = -2.7936877968817684e-09;

    test_msg.ephemeris_qzss.sqrta = 6493.172393798828;

    test_msg.ephemeris_qzss.tgd = -5.587935447692871e-09;

    test_msg.ephemeris_qzss.toc.tow = 450000;

    test_msg.ephemeris_qzss.toc.wn = 2154;

    test_msg.ephemeris_qzss.w = -1.5662079690885238;

    sbp_message_send(&sbp_state, SbpMsgEphemerisQzss, 61568, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 61568)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisQzss, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE(
        (last_msg.msg.ephemeris_qzss.af0 * 100 - -0.000369084067643 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.af0, expected "
           "-0.000369084067643, is "
        << last_msg.msg.ephemeris_qzss.af0;

    EXPECT_LE(
        (last_msg.msg.ephemeris_qzss.af1 * 100 - -4.77484718431e-12 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.af1, expected "
           "-4.77484718431e-12, is "
        << last_msg.msg.ephemeris_qzss.af1;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.af2 * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.af2, expected 0.0, "
           "is "
        << last_msg.msg.ephemeris_qzss.af2;

    EXPECT_LE(
        (last_msg.msg.ephemeris_qzss.c_ic * 100 - -1.17532908916e-06 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.c_ic, expected "
           "-1.17532908916e-06, is "
        << last_msg.msg.ephemeris_qzss.c_ic;

    EXPECT_LE(
        (last_msg.msg.ephemeris_qzss.c_is * 100 - 1.62050127983e-07 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.c_is, expected "
           "1.62050127983e-07, is "
        << last_msg.msg.ephemeris_qzss.c_is;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.c_rc * 100 - -36.90625 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.c_rc, expected "
           "-36.90625, is "
        << last_msg.msg.ephemeris_qzss.c_rc;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.c_rs * 100 - -457.8125 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.c_rs, expected "
           "-457.8125, is "
        << last_msg.msg.ephemeris_qzss.c_rs;

    EXPECT_LE(
        (last_msg.msg.ephemeris_qzss.c_uc * 100 - -1.61975622177e-05 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.c_uc, expected "
           "-1.61975622177e-05, is "
        << last_msg.msg.ephemeris_qzss.c_uc;

    EXPECT_LE(
        (last_msg.msg.ephemeris_qzss.c_us * 100 - 8.24779272079e-06 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.c_us, expected "
           "8.24779272079e-06, is "
        << last_msg.msg.ephemeris_qzss.c_us;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.common.fit_interval, 14400)
        << "incorrect value for "
           "last_msg.msg.ephemeris_qzss.common.fit_interval, expected 14400, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_qzss.common.fit_interval;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.common.health_bits, 0)
        << "incorrect value for "
           "last_msg.msg.ephemeris_qzss.common.health_bits, expected 0, is "
        << (int64_t)last_msg.msg.ephemeris_qzss.common.health_bits;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.common.sid.code, 31)
        << "incorrect value for last_msg.msg.ephemeris_qzss.common.sid.code, "
           "expected 31, is "
        << (int64_t)last_msg.msg.ephemeris_qzss.common.sid.code;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.common.sid.sat, 193)
        << "incorrect value for last_msg.msg.ephemeris_qzss.common.sid.sat, "
           "expected 193, is "
        << (int64_t)last_msg.msg.ephemeris_qzss.common.sid.sat;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.common.toe.tow, 450000)
        << "incorrect value for last_msg.msg.ephemeris_qzss.common.toe.tow, "
           "expected 450000, is "
        << (int64_t)last_msg.msg.ephemeris_qzss.common.toe.tow;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.common.toe.wn, 2154)
        << "incorrect value for last_msg.msg.ephemeris_qzss.common.toe.wn, "
           "expected 2154, is "
        << (int64_t)last_msg.msg.ephemeris_qzss.common.toe.wn;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.common.ura * 100 - 2.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.common.ura, "
           "expected 2.0, is "
        << last_msg.msg.ephemeris_qzss.common.ura;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.common.valid, 0)
        << "incorrect value for last_msg.msg.ephemeris_qzss.common.valid, "
           "expected 0, is "
        << (int64_t)last_msg.msg.ephemeris_qzss.common.valid;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.dn * 100 - 2.67832584874e-09 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.dn, expected "
           "2.67832584874e-09, is "
        << last_msg.msg.ephemeris_qzss.dn;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.ecc * 100 - 0.075500195846 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.ecc, expected "
           "0.075500195846, is "
        << last_msg.msg.ephemeris_qzss.ecc;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.inc * 100 - 0.730971511943 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.inc, expected "
           "0.730971511943, is "
        << last_msg.msg.ephemeris_qzss.inc;

    EXPECT_LE(
        (last_msg.msg.ephemeris_qzss.inc_dot * 100 - 2.0000833115e-11 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.inc_dot, expected "
           "2.0000833115e-11, is "
        << last_msg.msg.ephemeris_qzss.inc_dot;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.iodc, 817)
        << "incorrect value for last_msg.msg.ephemeris_qzss.iodc, expected "
           "817, is "
        << (int64_t)last_msg.msg.ephemeris_qzss.iodc;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.iode, 49)
        << "incorrect value for last_msg.msg.ephemeris_qzss.iode, expected 49, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_qzss.iode;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.m0 * 100 - 0.30694242159 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.m0, expected "
           "0.30694242159, is "
        << last_msg.msg.ephemeris_qzss.m0;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.omega0 * 100 - -1.16937437954 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.omega0, expected "
           "-1.16937437954, is "
        << last_msg.msg.ephemeris_qzss.omega0;

    EXPECT_LE(
        (last_msg.msg.ephemeris_qzss.omegadot * 100 - -2.79368779688e-09 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.omegadot, expected "
           "-2.79368779688e-09, is "
        << last_msg.msg.ephemeris_qzss.omegadot;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.sqrta * 100 - 6493.1723938 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.sqrta, expected "
           "6493.1723938, is "
        << last_msg.msg.ephemeris_qzss.sqrta;

    EXPECT_LE(
        (last_msg.msg.ephemeris_qzss.tgd * 100 - -5.58793544769e-09 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.tgd, expected "
           "-5.58793544769e-09, is "
        << last_msg.msg.ephemeris_qzss.tgd;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.toc.tow, 450000)
        << "incorrect value for last_msg.msg.ephemeris_qzss.toc.tow, expected "
           "450000, is "
        << (int64_t)last_msg.msg.ephemeris_qzss.toc.tow;

    EXPECT_EQ(last_msg.msg.ephemeris_qzss.toc.wn, 2154)
        << "incorrect value for last_msg.msg.ephemeris_qzss.toc.wn, expected "
           "2154, is "
        << (int64_t)last_msg.msg.ephemeris_qzss.toc.wn;

    EXPECT_LE((last_msg.msg.ephemeris_qzss.w * 100 - -1.56620796909 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_qzss.w, expected "
           "-1.56620796909, is "
        << last_msg.msg.ephemeris_qzss.w;
  }
}

}  // namespace
