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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisDepC.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/observation.h>
#include <libsbp/sbp.h>
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

START_TEST(test_auto_check_sbp_observation_MsgEphemerisDepC) {
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

    sbp_callback_register(&sbp_state, 0x47, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  71,  0,   195, 4,   185, 0,   0,   0,   0,   0,   0,   83,  190,
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
        0,   0,   45,  45,  0,   0,   0,   0,   0,   23,  170,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ephemeris_dep_c.af0 = -0.0006315018981695175;

    test_msg.ephemeris_dep_c.af1 = 8.981260180007666e-12;

    test_msg.ephemeris_dep_c.af2 = 0.2;

    test_msg.ephemeris_dep_c.c_ic = 7.450580596923828e-09;

    test_msg.ephemeris_dep_c.c_is = -1.1548399925231934e-07;

    test_msg.ephemeris_dep_c.c_rc = 308.625;

    test_msg.ephemeris_dep_c.c_rs = -52.3125;

    test_msg.ephemeris_dep_c.c_uc = -2.7436763048171997e-06;

    test_msg.ephemeris_dep_c.c_us = 3.1366944313049316e-06;

    test_msg.ephemeris_dep_c.dn = 5.694522914022375e-09;

    test_msg.ephemeris_dep_c.ecc = 0.007072207052260637;

    test_msg.ephemeris_dep_c.healthy = 0;

    test_msg.ephemeris_dep_c.inc = 0.9341514480259797;

    test_msg.ephemeris_dep_c.inc_dot = -4.035882396415757e-11;

    test_msg.ephemeris_dep_c.iodc = 45;

    test_msg.ephemeris_dep_c.iode = 45;

    test_msg.ephemeris_dep_c.m0 = -0.02200078842114688;

    test_msg.ephemeris_dep_c.omega0 = -1.8731818448797617;

    test_msg.ephemeris_dep_c.omegadot = -8.903585155774196e-09;

    test_msg.ephemeris_dep_c.reserved = 0;

    test_msg.ephemeris_dep_c.sid.code = 0;

    test_msg.ephemeris_dep_c.sid.reserved = 0;

    test_msg.ephemeris_dep_c.sid.sat = 22;

    test_msg.ephemeris_dep_c.sqrta = 5153.550029754639;

    test_msg.ephemeris_dep_c.tgd = -1.7695128917694092e-08;

    test_msg.ephemeris_dep_c.toc_tow = 446384.2;

    test_msg.ephemeris_dep_c.toc_wn = 2154;

    test_msg.ephemeris_dep_c.toe_tow = 446384.2;

    test_msg.ephemeris_dep_c.toe_wn = 2154;

    test_msg.ephemeris_dep_c.valid = 1;

    test_msg.ephemeris_dep_c.w = -0.9893036629599647;

    sbp_message_send(&sbp_state, SbpMsgEphemerisDepC, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgEphemerisDepC, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.af0 * 100 -
                   -0.00063150189817 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.af0, "
                  "expected -0.00063150189817, is %s",
                  last_msg.msg.ephemeris_dep_c.af0);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.af1 * 100 -
                   8.98126018001e-12 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.af1, "
                  "expected 8.98126018001e-12, is %s",
                  last_msg.msg.ephemeris_dep_c.af1);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.af2 * 100 - 0.2 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.af2, "
                  "expected 0.2, is %s",
                  last_msg.msg.ephemeris_dep_c.af2);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.c_ic * 100 -
                   7.45058059692e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.c_ic, "
                  "expected 7.45058059692e-09, is %s",
                  last_msg.msg.ephemeris_dep_c.c_ic);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.c_is * 100 -
                   -1.15483999252e-07 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.c_is, "
                  "expected -1.15483999252e-07, is %s",
                  last_msg.msg.ephemeris_dep_c.c_is);

    ck_assert_msg(
        (last_msg.msg.ephemeris_dep_c.c_rc * 100 - 308.625 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_dep_c.c_rc, expected "
        "308.625, is %s",
        last_msg.msg.ephemeris_dep_c.c_rc);

    ck_assert_msg(
        (last_msg.msg.ephemeris_dep_c.c_rs * 100 - -52.3125 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_dep_c.c_rs, expected "
        "-52.3125, is %s",
        last_msg.msg.ephemeris_dep_c.c_rs);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.c_uc * 100 -
                   -2.74367630482e-06 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.c_uc, "
                  "expected -2.74367630482e-06, is %s",
                  last_msg.msg.ephemeris_dep_c.c_uc);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.c_us * 100 -
                   3.1366944313e-06 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.c_us, "
                  "expected 3.1366944313e-06, is %s",
                  last_msg.msg.ephemeris_dep_c.c_us);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.dn * 100 -
                   5.69452291402e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.dn, "
                  "expected 5.69452291402e-09, is %s",
                  last_msg.msg.ephemeris_dep_c.dn);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.ecc * 100 -
                   0.00707220705226 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.ecc, "
                  "expected 0.00707220705226, is %s",
                  last_msg.msg.ephemeris_dep_c.ecc);

    ck_assert_msg(last_msg.msg.ephemeris_dep_c.healthy == 0,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.healthy, "
                  "expected 0, is %d",
                  last_msg.msg.ephemeris_dep_c.healthy);

    ck_assert_msg(
        (last_msg.msg.ephemeris_dep_c.inc * 100 - 0.934151448026 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_dep_c.inc, expected "
        "0.934151448026, is %s",
        last_msg.msg.ephemeris_dep_c.inc);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.inc_dot * 100 -
                   -4.03588239642e-11 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.inc_dot, "
                  "expected -4.03588239642e-11, is %s",
                  last_msg.msg.ephemeris_dep_c.inc_dot);

    ck_assert_msg(last_msg.msg.ephemeris_dep_c.iodc == 45,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.iodc, "
                  "expected 45, is %d",
                  last_msg.msg.ephemeris_dep_c.iodc);

    ck_assert_msg(last_msg.msg.ephemeris_dep_c.iode == 45,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.iode, "
                  "expected 45, is %d",
                  last_msg.msg.ephemeris_dep_c.iode);

    ck_assert_msg(
        (last_msg.msg.ephemeris_dep_c.m0 * 100 - -0.0220007884211 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_dep_c.m0, expected "
        "-0.0220007884211, is %s",
        last_msg.msg.ephemeris_dep_c.m0);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.omega0 * 100 -
                   -1.87318184488 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.omega0, "
                  "expected -1.87318184488, is %s",
                  last_msg.msg.ephemeris_dep_c.omega0);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.omegadot * 100 -
                   -8.90358515577e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.omegadot, "
                  "expected -8.90358515577e-09, is %s",
                  last_msg.msg.ephemeris_dep_c.omegadot);

    ck_assert_msg(last_msg.msg.ephemeris_dep_c.reserved == 0,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.reserved, "
                  "expected 0, is %d",
                  last_msg.msg.ephemeris_dep_c.reserved);

    ck_assert_msg(last_msg.msg.ephemeris_dep_c.sid.code == 0,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.ephemeris_dep_c.sid.code);

    ck_assert_msg(
        last_msg.msg.ephemeris_dep_c.sid.reserved == 0,
        "incorrect value for last_msg.msg.ephemeris_dep_c.sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.ephemeris_dep_c.sid.reserved);

    ck_assert_msg(last_msg.msg.ephemeris_dep_c.sid.sat == 22,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.sid.sat, "
                  "expected 22, is %d",
                  last_msg.msg.ephemeris_dep_c.sid.sat);

    ck_assert_msg(
        (last_msg.msg.ephemeris_dep_c.sqrta * 100 - 5153.55002975 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_dep_c.sqrta, expected "
        "5153.55002975, is %s",
        last_msg.msg.ephemeris_dep_c.sqrta);

    ck_assert_msg((last_msg.msg.ephemeris_dep_c.tgd * 100 -
                   -1.76951289177e-08 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.tgd, "
                  "expected -1.76951289177e-08, is %s",
                  last_msg.msg.ephemeris_dep_c.tgd);

    ck_assert_msg(
        (last_msg.msg.ephemeris_dep_c.toc_tow * 100 - 446384.2 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_dep_c.toc_tow, expected "
        "446384.2, is %s",
        last_msg.msg.ephemeris_dep_c.toc_tow);

    ck_assert_msg(last_msg.msg.ephemeris_dep_c.toc_wn == 2154,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.toc_wn, "
                  "expected 2154, is %d",
                  last_msg.msg.ephemeris_dep_c.toc_wn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_dep_c.toe_tow * 100 - 446384.2 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_dep_c.toe_tow, expected "
        "446384.2, is %s",
        last_msg.msg.ephemeris_dep_c.toe_tow);

    ck_assert_msg(last_msg.msg.ephemeris_dep_c.toe_wn == 2154,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.toe_wn, "
                  "expected 2154, is %d",
                  last_msg.msg.ephemeris_dep_c.toe_wn);

    ck_assert_msg(last_msg.msg.ephemeris_dep_c.valid == 1,
                  "incorrect value for last_msg.msg.ephemeris_dep_c.valid, "
                  "expected 1, is %d",
                  last_msg.msg.ephemeris_dep_c.valid);

    ck_assert_msg(
        (last_msg.msg.ephemeris_dep_c.w * 100 - -0.98930366296 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_dep_c.w, expected "
        "-0.98930366296, is %s",
        last_msg.msg.ephemeris_dep_c.w);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgEphemerisDepC_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_MsgEphemerisDepC");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_observation_MsgEphemerisDepC");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgEphemerisDepC);
  suite_add_tcase(s, tc_acq);
  return s;
}