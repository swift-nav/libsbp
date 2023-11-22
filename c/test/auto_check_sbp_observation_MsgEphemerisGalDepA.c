/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGalDepA.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/observation.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static void *DUMMY_MEMORY_FOR_CALLBACKS = (void *)0xdeadbeef;
static void *DUMMY_MEMORY_FOR_IO = (void *)0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return (s32)real_n;
}

static void logging_reset() { memset(&last_msg, 0, sizeof(last_msg)); }

static void msg_callback(u16 sender_id, sbp_msg_type_t msg_type,
                         const sbp_msg_t *msg, void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.msg_type = msg_type;
  last_msg.msg = *msg;
  last_msg.context = context;
}

START_TEST(test_auto_check_sbp_observation_MsgEphemerisGalDepA) {
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

    sbp_callback_register(&sbp_state, 0x95, &msg_callback,
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

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff (expected: %zu, "
                  "actual: %zu)",
                  sizeof(encoded_frame), dummy_wr);
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgEphemerisGalDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.af0 * 100 -
                   -1.70888961293e-05 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.af0, "
                  "expected -1.70888961293e-05, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.af0);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.af1 * 100 -
                   -8.18545231596e-12 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.af1, "
                  "expected -8.18545231596e-12, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.af1);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.af2 * 100 -
                   0.20000000298 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.af2, "
                  "expected 0.20000000298, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.af2);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5a * 100 -
         1.20000004768 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5a, "
        "expected 1.20000004768, is %s",
        last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5a);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5b * 100 -
         2.20000004768 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5b, "
        "expected 2.20000004768, is %s",
        last_msg.msg.ephemeris_gal_dep_a.bgd_e1e5b);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.c_ic * 100 -
                   3.20000004768 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_ic, "
                  "expected 3.20000004768, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.c_ic);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.c_is * 100 -
                   4.19999980927 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_is, "
                  "expected 4.19999980927, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.c_is);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gal_dep_a.c_rc * 100 - 265.4375 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_rc, expected "
        "265.4375, is %s",
        last_msg.msg.ephemeris_gal_dep_a.c_rc);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gal_dep_a.c_rs * 100 - 10.125 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_rs, expected "
        "10.125, is %s",
        last_msg.msg.ephemeris_gal_dep_a.c_rs);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.c_uc * 100 -
                   5.19999980927 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_uc, "
                  "expected 5.19999980927, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.c_uc);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.c_us * 100 -
                   6.19999980927 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.c_us, "
                  "expected 6.19999980927, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.c_us);

    ck_assert_msg(last_msg.msg.ephemeris_gal_dep_a.common.fit_interval == 14400,
                  "incorrect value for "
                  "last_msg.msg.ephemeris_gal_dep_a.common.fit_interval, "
                  "expected 14400, is %d",
                  last_msg.msg.ephemeris_gal_dep_a.common.fit_interval);

    ck_assert_msg(last_msg.msg.ephemeris_gal_dep_a.common.health_bits == 0,
                  "incorrect value for "
                  "last_msg.msg.ephemeris_gal_dep_a.common.health_bits, "
                  "expected 0, is %d",
                  last_msg.msg.ephemeris_gal_dep_a.common.health_bits);

    ck_assert_msg(
        last_msg.msg.ephemeris_gal_dep_a.common.sid.code == 14,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.common.sid.code, "
        "expected 14, is %d",
        last_msg.msg.ephemeris_gal_dep_a.common.sid.code);

    ck_assert_msg(
        last_msg.msg.ephemeris_gal_dep_a.common.sid.sat == 27,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.common.sid.sat, "
        "expected 27, is %d",
        last_msg.msg.ephemeris_gal_dep_a.common.sid.sat);

    ck_assert_msg(
        last_msg.msg.ephemeris_gal_dep_a.common.toe.tow == 448800,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.common.toe.tow, "
        "expected 448800, is %d",
        last_msg.msg.ephemeris_gal_dep_a.common.toe.tow);

    ck_assert_msg(
        last_msg.msg.ephemeris_gal_dep_a.common.toe.wn == 2154,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.common.toe.wn, "
        "expected 2154, is %d",
        last_msg.msg.ephemeris_gal_dep_a.common.toe.wn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gal_dep_a.common.ura * 100 -
         7.19999980927 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.common.ura, "
        "expected 7.19999980927, is %s",
        last_msg.msg.ephemeris_gal_dep_a.common.ura);

    ck_assert_msg(
        last_msg.msg.ephemeris_gal_dep_a.common.valid == 1,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.common.valid, "
        "expected 1, is %d",
        last_msg.msg.ephemeris_gal_dep_a.common.valid);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.dn * 100 -
                   3.22620581299e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.dn, "
                  "expected 3.22620581299e-09, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.dn);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.ecc * 100 -
                   0.000170606072061 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.ecc, "
                  "expected 0.000170606072061, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.ecc);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.inc * 100 -
                   0.977745609498 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.inc, "
                  "expected 0.977745609498, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.inc);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gal_dep_a.inc_dot * 100 -
         -3.17870383435e-10 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.inc_dot, "
        "expected -3.17870383435e-10, is %s",
        last_msg.msg.ephemeris_gal_dep_a.inc_dot);

    ck_assert_msg(last_msg.msg.ephemeris_gal_dep_a.iodc == 108,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.iodc, "
                  "expected 108, is %d",
                  last_msg.msg.ephemeris_gal_dep_a.iodc);

    ck_assert_msg(last_msg.msg.ephemeris_gal_dep_a.iode == 108,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.iode, "
                  "expected 108, is %d",
                  last_msg.msg.ephemeris_gal_dep_a.iode);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.m0 * 100 -
                   -1.84571157442 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.m0, "
                  "expected -1.84571157442, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.m0);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gal_dep_a.omega0 * 100 - 1.16967730598 * 100) <
            0.05,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.omega0, expected "
        "1.16967730598, is %s",
        last_msg.msg.ephemeris_gal_dep_a.omega0);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gal_dep_a.omegadot * 100 -
         -5.75738267524e-09 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.omegadot, "
        "expected -5.75738267524e-09, is %s",
        last_msg.msg.ephemeris_gal_dep_a.omegadot);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.sqrta * 100 -
                   5440.60240173 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.sqrta, "
                  "expected 5440.60240173, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.sqrta);

    ck_assert_msg(
        last_msg.msg.ephemeris_gal_dep_a.toc.tow == 448800,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.toc.tow, "
        "expected 448800, is %d",
        last_msg.msg.ephemeris_gal_dep_a.toc.tow);

    ck_assert_msg(
        last_msg.msg.ephemeris_gal_dep_a.toc.wn == 2154,
        "incorrect value for last_msg.msg.ephemeris_gal_dep_a.toc.wn, expected "
        "2154, is %d",
        last_msg.msg.ephemeris_gal_dep_a.toc.wn);

    ck_assert_msg((last_msg.msg.ephemeris_gal_dep_a.w * 100 -
                   0.122509120917 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gal_dep_a.w, "
                  "expected 0.122509120917, is %s",
                  last_msg.msg.ephemeris_gal_dep_a.w);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgEphemerisGalDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_observation_MsgEphemerisGalDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_observation_MsgEphemerisGalDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgEphemerisGalDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}