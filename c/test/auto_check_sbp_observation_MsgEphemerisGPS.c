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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGPS.yaml by
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

START_TEST(test_auto_check_sbp_observation_MsgEphemerisGPS) {
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

    sbp_callback_register(&sbp_state, 0x8a, &msg_callback,
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
    ck_assert_msg(last_msg.sender_id == 2314,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgEphemerisGps, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.af0 * 100 - -0.00063150189817 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.af0, expected "
        "-0.00063150189817, is %s",
        last_msg.msg.ephemeris_gps.af0);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.af1 * 100 - 8.98126018001e-12 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.af1, expected "
        "8.98126018001e-12, is %s",
        last_msg.msg.ephemeris_gps.af1);

    ck_assert_msg((last_msg.msg.ephemeris_gps.af2 * 100 - 0.0 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gps.af2, "
                  "expected 0.0, is %s",
                  last_msg.msg.ephemeris_gps.af2);

    ck_assert_msg((last_msg.msg.ephemeris_gps.c_ic * 100 -
                   7.45058059692e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gps.c_ic, "
                  "expected 7.45058059692e-09, is %s",
                  last_msg.msg.ephemeris_gps.c_ic);

    ck_assert_msg((last_msg.msg.ephemeris_gps.c_is * 100 -
                   -1.15483999252e-07 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gps.c_is, "
                  "expected -1.15483999252e-07, is %s",
                  last_msg.msg.ephemeris_gps.c_is);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.c_rc * 100 - 308.625 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.c_rc, expected "
        "308.625, is %s",
        last_msg.msg.ephemeris_gps.c_rc);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.c_rs * 100 - -52.3125 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.c_rs, expected "
        "-52.3125, is %s",
        last_msg.msg.ephemeris_gps.c_rs);

    ck_assert_msg((last_msg.msg.ephemeris_gps.c_uc * 100 -
                   -2.74367630482e-06 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gps.c_uc, "
                  "expected -2.74367630482e-06, is %s",
                  last_msg.msg.ephemeris_gps.c_uc);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.c_us * 100 - 3.1366944313e-06 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.c_us, expected "
        "3.1366944313e-06, is %s",
        last_msg.msg.ephemeris_gps.c_us);

    ck_assert_msg(
        last_msg.msg.ephemeris_gps.common.fit_interval == 14400,
        "incorrect value for last_msg.msg.ephemeris_gps.common.fit_interval, "
        "expected 14400, is %d",
        last_msg.msg.ephemeris_gps.common.fit_interval);

    ck_assert_msg(
        last_msg.msg.ephemeris_gps.common.health_bits == 0,
        "incorrect value for last_msg.msg.ephemeris_gps.common.health_bits, "
        "expected 0, is %d",
        last_msg.msg.ephemeris_gps.common.health_bits);

    ck_assert_msg(
        last_msg.msg.ephemeris_gps.common.sid.code == 0,
        "incorrect value for last_msg.msg.ephemeris_gps.common.sid.code, "
        "expected 0, is %d",
        last_msg.msg.ephemeris_gps.common.sid.code);

    ck_assert_msg(
        last_msg.msg.ephemeris_gps.common.sid.sat == 22,
        "incorrect value for last_msg.msg.ephemeris_gps.common.sid.sat, "
        "expected 22, is %d",
        last_msg.msg.ephemeris_gps.common.sid.sat);

    ck_assert_msg(
        last_msg.msg.ephemeris_gps.common.toe.tow == 446384,
        "incorrect value for last_msg.msg.ephemeris_gps.common.toe.tow, "
        "expected 446384, is %d",
        last_msg.msg.ephemeris_gps.common.toe.tow);

    ck_assert_msg(
        last_msg.msg.ephemeris_gps.common.toe.wn == 2154,
        "incorrect value for last_msg.msg.ephemeris_gps.common.toe.wn, "
        "expected 2154, is %d",
        last_msg.msg.ephemeris_gps.common.toe.wn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.common.ura * 100 - 2.0 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.common.ura, expected "
        "2.0, is %s",
        last_msg.msg.ephemeris_gps.common.ura);

    ck_assert_msg(last_msg.msg.ephemeris_gps.common.valid == 1,
                  "incorrect value for "
                  "last_msg.msg.ephemeris_gps.common.valid, expected 1, is %d",
                  last_msg.msg.ephemeris_gps.common.valid);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.dn * 100 - 5.69452291402e-09 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.dn, expected "
        "5.69452291402e-09, is %s",
        last_msg.msg.ephemeris_gps.dn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.ecc * 100 - 0.00707220705226 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.ecc, expected "
        "0.00707220705226, is %s",
        last_msg.msg.ephemeris_gps.ecc);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.inc * 100 - 0.934151448026 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.inc, expected "
        "0.934151448026, is %s",
        last_msg.msg.ephemeris_gps.inc);

    ck_assert_msg((last_msg.msg.ephemeris_gps.inc_dot * 100 -
                   -4.03588239642e-11 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gps.inc_dot, "
                  "expected -4.03588239642e-11, is %s",
                  last_msg.msg.ephemeris_gps.inc_dot);

    ck_assert_msg(last_msg.msg.ephemeris_gps.iodc == 45,
                  "incorrect value for last_msg.msg.ephemeris_gps.iodc, "
                  "expected 45, is %d",
                  last_msg.msg.ephemeris_gps.iodc);

    ck_assert_msg(last_msg.msg.ephemeris_gps.iode == 45,
                  "incorrect value for last_msg.msg.ephemeris_gps.iode, "
                  "expected 45, is %d",
                  last_msg.msg.ephemeris_gps.iode);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.m0 * 100 - -0.0220007884211 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.m0, expected "
        "-0.0220007884211, is %s",
        last_msg.msg.ephemeris_gps.m0);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.omega0 * 100 - -1.87318184488 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.omega0, expected "
        "-1.87318184488, is %s",
        last_msg.msg.ephemeris_gps.omega0);

    ck_assert_msg((last_msg.msg.ephemeris_gps.omegadot * 100 -
                   -8.90358515577e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gps.omegadot, "
                  "expected -8.90358515577e-09, is %s",
                  last_msg.msg.ephemeris_gps.omegadot);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.sqrta * 100 - 5153.55002975 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.sqrta, expected "
        "5153.55002975, is %s",
        last_msg.msg.ephemeris_gps.sqrta);

    ck_assert_msg((last_msg.msg.ephemeris_gps.tgd * 100 -
                   -1.76951289177e-08 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_gps.tgd, "
                  "expected -1.76951289177e-08, is %s",
                  last_msg.msg.ephemeris_gps.tgd);

    ck_assert_msg(last_msg.msg.ephemeris_gps.toc.tow == 446384,
                  "incorrect value for last_msg.msg.ephemeris_gps.toc.tow, "
                  "expected 446384, is %d",
                  last_msg.msg.ephemeris_gps.toc.tow);

    ck_assert_msg(last_msg.msg.ephemeris_gps.toc.wn == 2154,
                  "incorrect value for last_msg.msg.ephemeris_gps.toc.wn, "
                  "expected 2154, is %d",
                  last_msg.msg.ephemeris_gps.toc.wn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_gps.w * 100 - -0.98930366296 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_gps.w, expected "
        "-0.98930366296, is %s",
        last_msg.msg.ephemeris_gps.w);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgEphemerisGPS_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_MsgEphemerisGPS");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_observation_MsgEphemerisGPS");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgEphemerisGPS);
  suite_add_tcase(s, tc_acq);
  return s;
}