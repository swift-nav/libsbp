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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGal.yaml by
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

TEST(auto_check_sbp_observation_MsgEphemerisGal,
     test_auto_check_sbp_observation_MsgEphemerisGal) {
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

    sbp_callback_register(&sbp_state, SbpMsgEphemerisGal, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  141, 0,   128, 240, 153, 27,  14,  32,  217, 6,   0,   106, 8,
        20,  174, 71,  64,  64,  56,  0,   0,   1,   0,   0,   0,   16,  49,
        0,   0,   16,  49,  0,   0,   34,  65,  0,   184, 132, 67,  0,   0,
        16,  53,  0,   0,   134, 54,  0,   0,   8,   179, 0,   0,   8,   179,
        217, 204, 130, 105, 128, 182, 43,  62,  248, 106, 31,  220, 8,   136,
        253, 191, 0,   0,   0,   0,   151, 92,  38,  63,  0,   0,   0,   55,
        154, 64,  181, 64,  56,  38,  1,   141, 255, 182, 242, 63,  222, 147,
        136, 39,  79,  186, 56,  190, 80,  114, 204, 251, 193, 92,  191, 63,
        237, 55,  19,  41,  177, 73,  239, 63,  49,  65,  189, 240, 8,   216,
        245, 189, 255, 255, 255, 255, 67,  235, 241, 190, 255, 255, 255, 255,
        255, 255, 161, 189, 0,   0,   0,   0,   32,  217, 6,   0,   106, 8,
        108, 0,   108, 0,   0,   71,  208,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ephemeris_gal.af0 = -1.7088896129280325e-05;

    test_msg.ephemeris_gal.af1 = -8.185452315956353e-12;

    test_msg.ephemeris_gal.af2 = 0.0;

    test_msg.ephemeris_gal.bgd_e1e5a = 2.0954757928848267e-09;

    test_msg.ephemeris_gal.bgd_e1e5b = 2.0954757928848267e-09;

    test_msg.ephemeris_gal.c_ic = -3.166496753692627e-08;

    test_msg.ephemeris_gal.c_is = -3.166496753692627e-08;

    test_msg.ephemeris_gal.c_rc = 265.4375;

    test_msg.ephemeris_gal.c_rs = 10.125;

    test_msg.ephemeris_gal.c_uc = 5.364418029785156e-07;

    test_msg.ephemeris_gal.c_us = 3.993511199951172e-06;

    test_msg.ephemeris_gal.common.fit_interval = 14400;

    test_msg.ephemeris_gal.common.health_bits = 0;

    test_msg.ephemeris_gal.common.sid.code = 14;

    test_msg.ephemeris_gal.common.sid.sat = 27;

    test_msg.ephemeris_gal.common.toe.tow = 448800;

    test_msg.ephemeris_gal.common.toe.wn = 2154;

    test_msg.ephemeris_gal.common.ura = 3.119999885559082;

    test_msg.ephemeris_gal.common.valid = 1;

    test_msg.ephemeris_gal.dn = 3.2262058129932258e-09;

    test_msg.ephemeris_gal.ecc = 0.00017060607206076384;

    test_msg.ephemeris_gal.inc = 0.9777456094977858;

    test_msg.ephemeris_gal.inc_dot = -3.1787038343451465e-10;

    test_msg.ephemeris_gal.iodc = 108;

    test_msg.ephemeris_gal.iode = 108;

    test_msg.ephemeris_gal.m0 = -1.8457115744155868;

    test_msg.ephemeris_gal.omega0 = 1.16967730598334;

    test_msg.ephemeris_gal.omegadot = -5.757382675240872e-09;

    test_msg.ephemeris_gal.source = 0;

    test_msg.ephemeris_gal.sqrta = 5440.602401733398;

    test_msg.ephemeris_gal.toc.tow = 448800;

    test_msg.ephemeris_gal.toc.wn = 2154;

    test_msg.ephemeris_gal.w = 0.12250912091662625;

    sbp_message_send(&sbp_state, SbpMsgEphemerisGal, 61568, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisGal, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.ephemeris_gal.af0 * 100 - -1.70888961293e-05 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.af0, expected "
           "-1.70888961293e-05, is "
        << last_msg.msg.ephemeris_gal.af0;

    EXPECT_LE((last_msg.msg.ephemeris_gal.af1 * 100 - -8.18545231596e-12 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.af1, expected "
           "-8.18545231596e-12, is "
        << last_msg.msg.ephemeris_gal.af1;

    EXPECT_LE((last_msg.msg.ephemeris_gal.af2 * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.af2, expected 0.0, "
           "is "
        << last_msg.msg.ephemeris_gal.af2;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal.bgd_e1e5a * 100 - 2.09547579288e-09 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.bgd_e1e5a, expected "
           "2.09547579288e-09, is "
        << last_msg.msg.ephemeris_gal.bgd_e1e5a;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal.bgd_e1e5b * 100 - 2.09547579288e-09 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.bgd_e1e5b, expected "
           "2.09547579288e-09, is "
        << last_msg.msg.ephemeris_gal.bgd_e1e5b;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal.c_ic * 100 - -3.16649675369e-08 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.c_ic, expected "
           "-3.16649675369e-08, is "
        << last_msg.msg.ephemeris_gal.c_ic;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal.c_is * 100 - -3.16649675369e-08 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.c_is, expected "
           "-3.16649675369e-08, is "
        << last_msg.msg.ephemeris_gal.c_is;

    EXPECT_LE((last_msg.msg.ephemeris_gal.c_rc * 100 - 265.4375 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.c_rc, expected "
           "265.4375, is "
        << last_msg.msg.ephemeris_gal.c_rc;

    EXPECT_LE((last_msg.msg.ephemeris_gal.c_rs * 100 - 10.125 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.c_rs, expected "
           "10.125, is "
        << last_msg.msg.ephemeris_gal.c_rs;

    EXPECT_LE((last_msg.msg.ephemeris_gal.c_uc * 100 - 5.36441802979e-07 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.c_uc, expected "
           "5.36441802979e-07, is "
        << last_msg.msg.ephemeris_gal.c_uc;

    EXPECT_LE((last_msg.msg.ephemeris_gal.c_us * 100 - 3.99351119995e-06 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.c_us, expected "
           "3.99351119995e-06, is "
        << last_msg.msg.ephemeris_gal.c_us;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.common.fit_interval, 14400)
        << "incorrect value for "
           "last_msg.msg.ephemeris_gal.common.fit_interval, expected 14400, is "
        << (int64_t)last_msg.msg.ephemeris_gal.common.fit_interval;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.common.health_bits, 0)
        << "incorrect value for last_msg.msg.ephemeris_gal.common.health_bits, "
           "expected 0, is "
        << (int64_t)last_msg.msg.ephemeris_gal.common.health_bits;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.common.sid.code, 14)
        << "incorrect value for last_msg.msg.ephemeris_gal.common.sid.code, "
           "expected 14, is "
        << (int64_t)last_msg.msg.ephemeris_gal.common.sid.code;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.common.sid.sat, 27)
        << "incorrect value for last_msg.msg.ephemeris_gal.common.sid.sat, "
           "expected 27, is "
        << (int64_t)last_msg.msg.ephemeris_gal.common.sid.sat;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.common.toe.tow, 448800)
        << "incorrect value for last_msg.msg.ephemeris_gal.common.toe.tow, "
           "expected 448800, is "
        << (int64_t)last_msg.msg.ephemeris_gal.common.toe.tow;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.common.toe.wn, 2154)
        << "incorrect value for last_msg.msg.ephemeris_gal.common.toe.wn, "
           "expected 2154, is "
        << (int64_t)last_msg.msg.ephemeris_gal.common.toe.wn;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal.common.ura * 100 - 3.11999988556 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.common.ura, "
           "expected 3.11999988556, is "
        << last_msg.msg.ephemeris_gal.common.ura;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.common.valid, 1)
        << "incorrect value for last_msg.msg.ephemeris_gal.common.valid, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ephemeris_gal.common.valid;

    EXPECT_LE((last_msg.msg.ephemeris_gal.dn * 100 - 3.22620581299e-09 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.dn, expected "
           "3.22620581299e-09, is "
        << last_msg.msg.ephemeris_gal.dn;

    EXPECT_LE((last_msg.msg.ephemeris_gal.ecc * 100 - 0.000170606072061 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.ecc, expected "
           "0.000170606072061, is "
        << last_msg.msg.ephemeris_gal.ecc;

    EXPECT_LE((last_msg.msg.ephemeris_gal.inc * 100 - 0.977745609498 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.inc, expected "
           "0.977745609498, is "
        << last_msg.msg.ephemeris_gal.inc;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal.inc_dot * 100 - -3.17870383435e-10 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.inc_dot, expected "
           "-3.17870383435e-10, is "
        << last_msg.msg.ephemeris_gal.inc_dot;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.iodc, 108)
        << "incorrect value for last_msg.msg.ephemeris_gal.iodc, expected 108, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_gal.iodc;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.iode, 108)
        << "incorrect value for last_msg.msg.ephemeris_gal.iode, expected 108, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_gal.iode;

    EXPECT_LE((last_msg.msg.ephemeris_gal.m0 * 100 - -1.84571157442 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.m0, expected "
           "-1.84571157442, is "
        << last_msg.msg.ephemeris_gal.m0;

    EXPECT_LE((last_msg.msg.ephemeris_gal.omega0 * 100 - 1.16967730598 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.omega0, expected "
           "1.16967730598, is "
        << last_msg.msg.ephemeris_gal.omega0;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal.omegadot * 100 - -5.75738267524e-09 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.omegadot, expected "
           "-5.75738267524e-09, is "
        << last_msg.msg.ephemeris_gal.omegadot;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.source, 0)
        << "incorrect value for last_msg.msg.ephemeris_gal.source, expected 0, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_gal.source;

    EXPECT_LE((last_msg.msg.ephemeris_gal.sqrta * 100 - 5440.60240173 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.sqrta, expected "
           "5440.60240173, is "
        << last_msg.msg.ephemeris_gal.sqrta;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.toc.tow, 448800)
        << "incorrect value for last_msg.msg.ephemeris_gal.toc.tow, expected "
           "448800, is "
        << (int64_t)last_msg.msg.ephemeris_gal.toc.tow;

    EXPECT_EQ(last_msg.msg.ephemeris_gal.toc.wn, 2154)
        << "incorrect value for last_msg.msg.ephemeris_gal.toc.wn, expected "
           "2154, is "
        << (int64_t)last_msg.msg.ephemeris_gal.toc.wn;

    EXPECT_LE((last_msg.msg.ephemeris_gal.w * 100 - 0.122509120917 * 100), 0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal.w, expected "
           "0.122509120917, is "
        << last_msg.msg.ephemeris_gal.w;
  }
}

}  // namespace
