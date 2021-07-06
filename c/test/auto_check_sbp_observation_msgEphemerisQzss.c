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
// spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisQzss.yaml by
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

START_TEST(test_auto_check_sbp_observation_msgEphemerisQzss) {
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

    sbp_callback_register(&sbp_state, 0x8e, &msg_callback,
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

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 61568,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgEphemerisQzss, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg((last_msg.msg.ephemeris_qzss.af0 * 100 -
                   -0.000369084067643 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.af0, "
                  "expected -0.000369084067643, is %s",
                  last_msg.msg.ephemeris_qzss.af0);

    ck_assert_msg((last_msg.msg.ephemeris_qzss.af1 * 100 -
                   -4.77484718431e-12 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.af1, "
                  "expected -4.77484718431e-12, is %s",
                  last_msg.msg.ephemeris_qzss.af1);

    ck_assert_msg((last_msg.msg.ephemeris_qzss.af2 * 100 - 0.0 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.af2, "
                  "expected 0.0, is %s",
                  last_msg.msg.ephemeris_qzss.af2);

    ck_assert_msg((last_msg.msg.ephemeris_qzss.c_ic * 100 -
                   -1.17532908916e-06 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.c_ic, "
                  "expected -1.17532908916e-06, is %s",
                  last_msg.msg.ephemeris_qzss.c_ic);

    ck_assert_msg((last_msg.msg.ephemeris_qzss.c_is * 100 -
                   1.62050127983e-07 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.c_is, "
                  "expected 1.62050127983e-07, is %s",
                  last_msg.msg.ephemeris_qzss.c_is);

    ck_assert_msg(
        (last_msg.msg.ephemeris_qzss.c_rc * 100 - -36.90625 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_qzss.c_rc, expected "
        "-36.90625, is %s",
        last_msg.msg.ephemeris_qzss.c_rc);

    ck_assert_msg(
        (last_msg.msg.ephemeris_qzss.c_rs * 100 - -457.8125 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_qzss.c_rs, expected "
        "-457.8125, is %s",
        last_msg.msg.ephemeris_qzss.c_rs);

    ck_assert_msg((last_msg.msg.ephemeris_qzss.c_uc * 100 -
                   -1.61975622177e-05 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.c_uc, "
                  "expected -1.61975622177e-05, is %s",
                  last_msg.msg.ephemeris_qzss.c_uc);

    ck_assert_msg((last_msg.msg.ephemeris_qzss.c_us * 100 -
                   8.24779272079e-06 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.c_us, "
                  "expected 8.24779272079e-06, is %s",
                  last_msg.msg.ephemeris_qzss.c_us);

    ck_assert_msg(
        last_msg.msg.ephemeris_qzss.common.fit_interval == 14400,
        "incorrect value for last_msg.msg.ephemeris_qzss.common.fit_interval, "
        "expected 14400, is %d",
        last_msg.msg.ephemeris_qzss.common.fit_interval);

    ck_assert_msg(
        last_msg.msg.ephemeris_qzss.common.health_bits == 0,
        "incorrect value for last_msg.msg.ephemeris_qzss.common.health_bits, "
        "expected 0, is %d",
        last_msg.msg.ephemeris_qzss.common.health_bits);

    ck_assert_msg(
        last_msg.msg.ephemeris_qzss.common.sid.code == 31,
        "incorrect value for last_msg.msg.ephemeris_qzss.common.sid.code, "
        "expected 31, is %d",
        last_msg.msg.ephemeris_qzss.common.sid.code);

    ck_assert_msg(
        last_msg.msg.ephemeris_qzss.common.sid.sat == 193,
        "incorrect value for last_msg.msg.ephemeris_qzss.common.sid.sat, "
        "expected 193, is %d",
        last_msg.msg.ephemeris_qzss.common.sid.sat);

    ck_assert_msg(
        last_msg.msg.ephemeris_qzss.common.toe.tow == 450000,
        "incorrect value for last_msg.msg.ephemeris_qzss.common.toe.tow, "
        "expected 450000, is %d",
        last_msg.msg.ephemeris_qzss.common.toe.tow);

    ck_assert_msg(
        last_msg.msg.ephemeris_qzss.common.toe.wn == 2154,
        "incorrect value for last_msg.msg.ephemeris_qzss.common.toe.wn, "
        "expected 2154, is %d",
        last_msg.msg.ephemeris_qzss.common.toe.wn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_qzss.common.ura * 100 - 2.0 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_qzss.common.ura, expected "
        "2.0, is %s",
        last_msg.msg.ephemeris_qzss.common.ura);

    ck_assert_msg(last_msg.msg.ephemeris_qzss.common.valid == 0,
                  "incorrect value for "
                  "last_msg.msg.ephemeris_qzss.common.valid, expected 0, is %d",
                  last_msg.msg.ephemeris_qzss.common.valid);

    ck_assert_msg(
        (last_msg.msg.ephemeris_qzss.dn * 100 - 2.67832584874e-09 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_qzss.dn, expected "
        "2.67832584874e-09, is %s",
        last_msg.msg.ephemeris_qzss.dn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_qzss.ecc * 100 - 0.075500195846 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_qzss.ecc, expected "
        "0.075500195846, is %s",
        last_msg.msg.ephemeris_qzss.ecc);

    ck_assert_msg(
        (last_msg.msg.ephemeris_qzss.inc * 100 - 0.730971511943 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_qzss.inc, expected "
        "0.730971511943, is %s",
        last_msg.msg.ephemeris_qzss.inc);

    ck_assert_msg((last_msg.msg.ephemeris_qzss.inc_dot * 100 -
                   2.0000833115e-11 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.inc_dot, "
                  "expected 2.0000833115e-11, is %s",
                  last_msg.msg.ephemeris_qzss.inc_dot);

    ck_assert_msg(last_msg.msg.ephemeris_qzss.iodc == 817,
                  "incorrect value for last_msg.msg.ephemeris_qzss.iodc, "
                  "expected 817, is %d",
                  last_msg.msg.ephemeris_qzss.iodc);

    ck_assert_msg(last_msg.msg.ephemeris_qzss.iode == 49,
                  "incorrect value for last_msg.msg.ephemeris_qzss.iode, "
                  "expected 49, is %d",
                  last_msg.msg.ephemeris_qzss.iode);

    ck_assert_msg(
        (last_msg.msg.ephemeris_qzss.m0 * 100 - 0.30694242159 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_qzss.m0, expected "
        "0.30694242159, is %s",
        last_msg.msg.ephemeris_qzss.m0);

    ck_assert_msg((last_msg.msg.ephemeris_qzss.omega0 * 100 -
                   -1.16937437954 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.omega0, "
                  "expected -1.16937437954, is %s",
                  last_msg.msg.ephemeris_qzss.omega0);

    ck_assert_msg((last_msg.msg.ephemeris_qzss.omegadot * 100 -
                   -2.79368779688e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.omegadot, "
                  "expected -2.79368779688e-09, is %s",
                  last_msg.msg.ephemeris_qzss.omegadot);

    ck_assert_msg(
        (last_msg.msg.ephemeris_qzss.sqrta * 100 - 6493.1723938 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_qzss.sqrta, expected "
        "6493.1723938, is %s",
        last_msg.msg.ephemeris_qzss.sqrta);

    ck_assert_msg((last_msg.msg.ephemeris_qzss.tgd * 100 -
                   -5.58793544769e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_qzss.tgd, "
                  "expected -5.58793544769e-09, is %s",
                  last_msg.msg.ephemeris_qzss.tgd);

    ck_assert_msg(last_msg.msg.ephemeris_qzss.toc.tow == 450000,
                  "incorrect value for last_msg.msg.ephemeris_qzss.toc.tow, "
                  "expected 450000, is %d",
                  last_msg.msg.ephemeris_qzss.toc.tow);

    ck_assert_msg(last_msg.msg.ephemeris_qzss.toc.wn == 2154,
                  "incorrect value for last_msg.msg.ephemeris_qzss.toc.wn, "
                  "expected 2154, is %d",
                  last_msg.msg.ephemeris_qzss.toc.wn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_qzss.w * 100 - -1.56620796909 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_qzss.w, expected "
        "-1.56620796909, is %s",
        last_msg.msg.ephemeris_qzss.w);
  }
}
END_TEST

Suite *auto_check_sbp_observation_msgEphemerisQzss_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_msgEphemerisQzss");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_observation_msgEphemerisQzss");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_msgEphemerisQzss);
  suite_add_tcase(s, tc_acq);
  return s;
}