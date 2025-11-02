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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGalDepA.yaml by
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

TEST(auto_check_sbp_observation_MsgEphemerisGalDepA,
     test_auto_check_sbp_observation_MsgEphemerisGalDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgEphemerisGalDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  149, 0,   195, 4,   152, 27,  14,  32,  217, 6,   0,   106, 8,
        102, 102, 230, 64,  64,  56,  0,   0,   1,   0,   154, 153, 153, 63,
        205, 204, 12,  64,  0,   0,   34,  65,  0,   184, 132, 67,  102, 102,
        166, 64,  102, 102, 198, 64,  205, 204, 76,  64,  102, 102, 134, 64,
        217, 204, 130, 105, 128, 182, 43,  62,  248, 106, 31,  220, 8,   136,
        253, 191, 0,   0,   0,   0,   151, 92,  38,  63,  0,   0,   0,   55,
        154, 64,  181, 64,  56,  38,  1,   141, 255, 182, 242, 63,  222, 147,
        136, 39,  79,  186, 56,  190, 80,  114, 204, 251, 193, 92,  191, 63,
        237, 55,  19,  41,  177, 73,  239, 63,  49,  65,  189, 240, 8,   216,
        245, 189, 255, 255, 255, 255, 67,  235, 241, 190, 255, 255, 255, 255,
        255, 255, 161, 189, 205, 204, 76,  62,  32,  217, 6,   0,   106, 8,
        108, 0,   108, 0,   168, 49,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ephemeris_gal_dep_a.af0 = -1.7088896129280325e-05;

    test_msg.ephemeris_gal_dep_a.af1 = -8.185452315956353e-12;

    test_msg.ephemeris_gal_dep_a.af2 = 0.20000000298023224;

    test_msg.ephemeris_gal_dep_a.bgd_e1e5a = 1.2000000476837158;

    test_msg.ephemeris_gal_dep_a.bgd_e1e5b = 2.200000047683716;

    test_msg.ephemeris_gal_dep_a.c_ic = 3.200000047683716;

    test_msg.ephemeris_gal_dep_a.c_is = 4.199999809265137;

    test_msg.ephemeris_gal_dep_a.c_rc = 265.4375;

    test_msg.ephemeris_gal_dep_a.c_rs = 10.125;

    test_msg.ephemeris_gal_dep_a.c_uc = 5.199999809265137;

    test_msg.ephemeris_gal_dep_a.c_us = 6.199999809265137;

    test_msg.ephemeris_gal_dep_a.common.fit_interval = 14400;

    test_msg.ephemeris_gal_dep_a.common.health_bits = 0;

    test_msg.ephemeris_gal_dep_a.common.sid.code = 14;

    test_msg.ephemeris_gal_dep_a.common.sid.sat = 27;

    test_msg.ephemeris_gal_dep_a.common.toe.tow = 448800;

    test_msg.ephemeris_gal_dep_a.common.toe.wn = 2154;

    test_msg.ephemeris_gal_dep_a.common.ura = 7.199999809265137;

    test_msg.ephemeris_gal_dep_a.common.valid = 1;

    test_msg.ephemeris_gal_dep_a.dn = 3.2262058129932258e-09;

    test_msg.ephemeris_gal_dep_a.ecc = 0.00017060607206076384;

    test_msg.ephemeris_gal_dep_a.inc = 0.9777456094977858;

    test_msg.ephemeris_gal_dep_a.inc_dot = -3.1787038343451465e-10;

    test_msg.ephemeris_gal_dep_a.iodc = 108;

    test_msg.ephemeris_gal_dep_a.iode = 108;

    test_msg.ephemeris_gal_dep_a.m0 = -1.8457115744155868;

    test_msg.ephemeris_gal_dep_a.omega0 = 1.16967730598334;

    test_msg.ephemeris_gal_dep_a.omegadot = -5.757382675240872e-09;

    test_msg.ephemeris_gal_dep_a.sqrta = 5440.602401733398;

    test_msg.ephemeris_gal_dep_a.toc.tow = 448800;

    test_msg.ephemeris_gal_dep_a.toc.wn = 2154;

    test_msg.ephemeris_gal_dep_a.w = 0.12250912091662625;

    sbp_message_send(&sbp_state, SbpMsgEphemerisGalDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisGalDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.af0 * 100 - -1.70888961293e-05 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.af0, expected "
           "-1.70888961293e-05, is "
        << last_msg.msg.ephemeris_gal_dep_a.af0;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.af1 * 100 - -8.18545231596e-12 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.af1, expected "
           "-8.18545231596e-12, is "
        << last_msg.msg.ephemeris_gal_dep_a.af1;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.af2 * 100 - 0.20000000298 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.af2, expected "
           "0.20000000298, is "
        << last_msg.msg.ephemeris_gal_dep_a.af2;

    EXPECT_LE((last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5a * 100 -
               1.20000004768 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5a, "
           "expected 1.20000004768, is "
        << last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5a;

    EXPECT_LE((last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5b * 100 -
               2.20000004768 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5b, "
           "expected 2.20000004768, is "
        << last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5b;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.c_ic * 100 - 3.20000004768 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_ic, "
           "expected 3.20000004768, is "
        << last_msg.msg.ephemeris_gal_dep_a.c_ic;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.c_is * 100 - 4.19999980927 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_is, "
           "expected 4.19999980927, is "
        << last_msg.msg.ephemeris_gal_dep_a.c_is;

    EXPECT_LE((last_msg.msg.ephemeris_gal_dep_a.c_rc * 100 - 265.4375 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_rc, "
           "expected 265.4375, is "
        << last_msg.msg.ephemeris_gal_dep_a.c_rc;

    EXPECT_LE((last_msg.msg.ephemeris_gal_dep_a.c_rs * 100 - 10.125 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_rs, "
           "expected 10.125, is "
        << last_msg.msg.ephemeris_gal_dep_a.c_rs;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.c_uc * 100 - 5.19999980927 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_uc, "
           "expected 5.19999980927, is "
        << last_msg.msg.ephemeris_gal_dep_a.c_uc;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.c_us * 100 - 6.19999980927 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_us, "
           "expected 6.19999980927, is "
        << last_msg.msg.ephemeris_gal_dep_a.c_us;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.common.fit_interval, 14400)
        << "incorrect value for "
           "last_msg.msg.ephemeris_gal_dep_a.common.fit_interval, expected "
           "14400, is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.common.fit_interval;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.common.health_bits, 0)
        << "incorrect value for "
           "last_msg.msg.ephemeris_gal_dep_a.common.health_bits, expected 0, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.common.health_bits;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.common.sid.code, 14)
        << "incorrect value for "
           "last_msg.msg.ephemeris_gal_dep_a.common.sid.code, expected 14, is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.common.sid.code;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.common.sid.sat, 27)
        << "incorrect value for "
           "last_msg.msg.ephemeris_gal_dep_a.common.sid.sat, expected 27, is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.common.sid.sat;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.common.toe.tow, 448800)
        << "incorrect value for "
           "last_msg.msg.ephemeris_gal_dep_a.common.toe.tow, expected 448800, "
           "is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.common.toe.tow;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.common.toe.wn, 2154)
        << "incorrect value for "
           "last_msg.msg.ephemeris_gal_dep_a.common.toe.wn, expected 2154, is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.common.toe.wn;

    EXPECT_LE((last_msg.msg.ephemeris_gal_dep_a.common.ura * 100 -
               7.19999980927 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.common.ura, "
           "expected 7.19999980927, is "
        << last_msg.msg.ephemeris_gal_dep_a.common.ura;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.common.valid, 1)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.common.valid, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.common.valid;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.dn * 100 - 3.22620581299e-09 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.dn, expected "
           "3.22620581299e-09, is "
        << last_msg.msg.ephemeris_gal_dep_a.dn;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.ecc * 100 - 0.000170606072061 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.ecc, expected "
           "0.000170606072061, is "
        << last_msg.msg.ephemeris_gal_dep_a.ecc;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.inc * 100 - 0.977745609498 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.inc, expected "
           "0.977745609498, is "
        << last_msg.msg.ephemeris_gal_dep_a.inc;

    EXPECT_LE((last_msg.msg.ephemeris_gal_dep_a.inc_dot * 100 -
               -3.17870383435e-10 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.inc_dot, "
           "expected -3.17870383435e-10, is "
        << last_msg.msg.ephemeris_gal_dep_a.inc_dot;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.iodc, 108)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.iodc, "
           "expected 108, is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.iodc;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.iode, 108)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.iode, "
           "expected 108, is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.iode;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.m0 * 100 - -1.84571157442 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.m0, expected "
           "-1.84571157442, is "
        << last_msg.msg.ephemeris_gal_dep_a.m0;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.omega0 * 100 - 1.16967730598 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.omega0, "
           "expected 1.16967730598, is "
        << last_msg.msg.ephemeris_gal_dep_a.omega0;

    EXPECT_LE((last_msg.msg.ephemeris_gal_dep_a.omegadot * 100 -
               -5.75738267524e-09 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.omegadot, "
           "expected -5.75738267524e-09, is "
        << last_msg.msg.ephemeris_gal_dep_a.omegadot;

    EXPECT_LE(
        (last_msg.msg.ephemeris_gal_dep_a.sqrta * 100 - 5440.60240173 * 100),
        0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.sqrta, "
           "expected 5440.60240173, is "
        << last_msg.msg.ephemeris_gal_dep_a.sqrta;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.toc.tow, 448800)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.toc.tow, "
           "expected 448800, is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.toc.tow;

    EXPECT_EQ(last_msg.msg.ephemeris_gal_dep_a.toc.wn, 2154)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.toc.wn, "
           "expected 2154, is "
        << (int64_t)last_msg.msg.ephemeris_gal_dep_a.toc.wn;

    EXPECT_LE((last_msg.msg.ephemeris_gal_dep_a.w * 100 - 0.122509120917 * 100),
              0.05)
        << "incorrect value for last_msg.msg.ephemeris_gal_dep_a.w, expected "
           "0.122509120917, is "
        << last_msg.msg.ephemeris_gal_dep_a.w;
  }
}

}  // namespace
