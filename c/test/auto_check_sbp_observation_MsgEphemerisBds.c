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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisBds.yaml by
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

START_TEST(test_auto_check_sbp_observation_MsgEphemerisBds) {
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

    sbp_callback_register(&sbp_state, 0x89, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  137, 0,   128, 240, 147, 8,   12,  174, 179, 6,   0,   106,
        8,   0,   0,   0,   64,  48,  42,  0,   0,   1,   0,   125, 99,
        52,  50,  207, 46,  151, 176, 0,   112, 96,  67,  0,   164, 106,
        67,  0,   60,  255, 54,  0,   224, 47,  53,  0,   0,   143, 179,
        0,   192, 190, 52,  146, 101, 162, 196, 109, 104, 19,  62,  253,
        87,  86,  202, 62,  28,  251, 63,  0,   0,   0,   96,  151, 60,
        117, 63,  0,   0,   128, 154, 127, 93,  185, 64,  151, 193, 64,
        0,   10,  166, 4,   192, 160, 75,  174, 98,  8,   201, 35,  190,
        205, 29,  12,  71,  189, 150, 5,   192, 176, 72,  249, 189, 193,
        172, 240, 63,  72,  249, 188, 180, 160, 203, 9,   62,  0,   0,
        0,   0,   92,  51,  77,  191, 0,   128, 174, 43,  0,   0,   88,
        161, 174, 179, 6,   0,   106, 8,   6,   5,   0,   157, 249,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ephemeris_bds.af0 = -0.0008911322802305222;

    test_msg.ephemeris_bds.af1 = 1.2398970739013748e-12;

    test_msg.ephemeris_bds.af2 = -7.318364664277155e-19;

    test_msg.ephemeris_bds.c_ic = -6.658956408500671e-08;

    test_msg.ephemeris_bds.c_is = 3.5529956221580505e-07;

    test_msg.ephemeris_bds.c_rc = 234.640625;

    test_msg.ephemeris_bds.c_rs = 224.4375;

    test_msg.ephemeris_bds.c_uc = 7.606577128171921e-06;

    test_msg.ephemeris_bds.c_us = 6.551854312419891e-07;

    test_msg.ephemeris_bds.common.fit_interval = 10800;

    test_msg.ephemeris_bds.common.health_bits = 0;

    test_msg.ephemeris_bds.common.sid.code = 12;

    test_msg.ephemeris_bds.common.sid.sat = 8;

    test_msg.ephemeris_bds.common.toe.tow = 439214;

    test_msg.ephemeris_bds.common.toe.wn = 2154;

    test_msg.ephemeris_bds.common.ura = 2.0;

    test_msg.ephemeris_bds.common.valid = 1;

    test_msg.ephemeris_bds.dn = 1.1296899132622133e-09;

    test_msg.ephemeris_bds.ecc = 0.005184737499803305;

    test_msg.ephemeris_bds.inc = 1.0421769543504915;

    test_msg.ephemeris_bds.inc_dot = 7.507455572801683e-10;

    test_msg.ephemeris_bds.iodc = 5;

    test_msg.ephemeris_bds.iode = 6;

    test_msg.ephemeris_bds.m0 = 1.6943958190727237;

    test_msg.ephemeris_bds.omega0 = -2.581073762870982;

    test_msg.ephemeris_bds.omegadot = -2.303310227830545e-09;

    test_msg.ephemeris_bds.sqrta = 6493.49845123291;

    test_msg.ephemeris_bds.tgd1 = 1.0499999980595476e-08;

    test_msg.ephemeris_bds.tgd2 = -1.0999999799921056e-09;

    test_msg.ephemeris_bds.toc.tow = 439214;

    test_msg.ephemeris_bds.toc.wn = 2154;

    test_msg.ephemeris_bds.w = -2.698603205735458;

    sbp_message_send(&sbp_state, SbpMsgEphemerisBds, 61568, &test_msg,
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
        sbp_message_cmp(SbpMsgEphemerisBds, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg((last_msg.msg.ephemeris_bds.af0 * 100 -
                   -0.000891132280231 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_bds.af0, "
                  "expected -0.000891132280231, is %s",
                  last_msg.msg.ephemeris_bds.af0);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.af1 * 100 - 1.2398970739e-12 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.af1, expected "
        "1.2398970739e-12, is %s",
        last_msg.msg.ephemeris_bds.af1);

    ck_assert_msg((last_msg.msg.ephemeris_bds.af2 * 100 -
                   -7.31836466428e-19 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_bds.af2, "
                  "expected -7.31836466428e-19, is %s",
                  last_msg.msg.ephemeris_bds.af2);

    ck_assert_msg((last_msg.msg.ephemeris_bds.c_ic * 100 -
                   -6.6589564085e-08 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_bds.c_ic, "
                  "expected -6.6589564085e-08, is %s",
                  last_msg.msg.ephemeris_bds.c_ic);

    ck_assert_msg((last_msg.msg.ephemeris_bds.c_is * 100 -
                   3.55299562216e-07 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_bds.c_is, "
                  "expected 3.55299562216e-07, is %s",
                  last_msg.msg.ephemeris_bds.c_is);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.c_rc * 100 - 234.640625 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.c_rc, expected "
        "234.640625, is %s",
        last_msg.msg.ephemeris_bds.c_rc);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.c_rs * 100 - 224.4375 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.c_rs, expected "
        "224.4375, is %s",
        last_msg.msg.ephemeris_bds.c_rs);

    ck_assert_msg((last_msg.msg.ephemeris_bds.c_uc * 100 -
                   7.60657712817e-06 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_bds.c_uc, "
                  "expected 7.60657712817e-06, is %s",
                  last_msg.msg.ephemeris_bds.c_uc);

    ck_assert_msg((last_msg.msg.ephemeris_bds.c_us * 100 -
                   6.55185431242e-07 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_bds.c_us, "
                  "expected 6.55185431242e-07, is %s",
                  last_msg.msg.ephemeris_bds.c_us);

    ck_assert_msg(
        last_msg.msg.ephemeris_bds.common.fit_interval == 10800,
        "incorrect value for last_msg.msg.ephemeris_bds.common.fit_interval, "
        "expected 10800, is %d",
        last_msg.msg.ephemeris_bds.common.fit_interval);

    ck_assert_msg(
        last_msg.msg.ephemeris_bds.common.health_bits == 0,
        "incorrect value for last_msg.msg.ephemeris_bds.common.health_bits, "
        "expected 0, is %d",
        last_msg.msg.ephemeris_bds.common.health_bits);

    ck_assert_msg(
        last_msg.msg.ephemeris_bds.common.sid.code == 12,
        "incorrect value for last_msg.msg.ephemeris_bds.common.sid.code, "
        "expected 12, is %d",
        last_msg.msg.ephemeris_bds.common.sid.code);

    ck_assert_msg(
        last_msg.msg.ephemeris_bds.common.sid.sat == 8,
        "incorrect value for last_msg.msg.ephemeris_bds.common.sid.sat, "
        "expected 8, is %d",
        last_msg.msg.ephemeris_bds.common.sid.sat);

    ck_assert_msg(
        last_msg.msg.ephemeris_bds.common.toe.tow == 439214,
        "incorrect value for last_msg.msg.ephemeris_bds.common.toe.tow, "
        "expected 439214, is %d",
        last_msg.msg.ephemeris_bds.common.toe.tow);

    ck_assert_msg(
        last_msg.msg.ephemeris_bds.common.toe.wn == 2154,
        "incorrect value for last_msg.msg.ephemeris_bds.common.toe.wn, "
        "expected 2154, is %d",
        last_msg.msg.ephemeris_bds.common.toe.wn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.common.ura * 100 - 2.0 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.common.ura, expected "
        "2.0, is %s",
        last_msg.msg.ephemeris_bds.common.ura);

    ck_assert_msg(last_msg.msg.ephemeris_bds.common.valid == 1,
                  "incorrect value for "
                  "last_msg.msg.ephemeris_bds.common.valid, expected 1, is %d",
                  last_msg.msg.ephemeris_bds.common.valid);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.dn * 100 - 1.12968991326e-09 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.dn, expected "
        "1.12968991326e-09, is %s",
        last_msg.msg.ephemeris_bds.dn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.ecc * 100 - 0.0051847374998 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.ecc, expected "
        "0.0051847374998, is %s",
        last_msg.msg.ephemeris_bds.ecc);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.inc * 100 - 1.04217695435 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.inc, expected "
        "1.04217695435, is %s",
        last_msg.msg.ephemeris_bds.inc);

    ck_assert_msg((last_msg.msg.ephemeris_bds.inc_dot * 100 -
                   7.5074555728e-10 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_bds.inc_dot, "
                  "expected 7.5074555728e-10, is %s",
                  last_msg.msg.ephemeris_bds.inc_dot);

    ck_assert_msg(last_msg.msg.ephemeris_bds.iodc == 5,
                  "incorrect value for last_msg.msg.ephemeris_bds.iodc, "
                  "expected 5, is %d",
                  last_msg.msg.ephemeris_bds.iodc);

    ck_assert_msg(last_msg.msg.ephemeris_bds.iode == 6,
                  "incorrect value for last_msg.msg.ephemeris_bds.iode, "
                  "expected 6, is %d",
                  last_msg.msg.ephemeris_bds.iode);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.m0 * 100 - 1.69439581907 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.m0, expected "
        "1.69439581907, is %s",
        last_msg.msg.ephemeris_bds.m0);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.omega0 * 100 - -2.58107376287 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.omega0, expected "
        "-2.58107376287, is %s",
        last_msg.msg.ephemeris_bds.omega0);

    ck_assert_msg((last_msg.msg.ephemeris_bds.omegadot * 100 -
                   -2.30331022783e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_bds.omegadot, "
                  "expected -2.30331022783e-09, is %s",
                  last_msg.msg.ephemeris_bds.omegadot);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.sqrta * 100 - 6493.49845123 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.sqrta, expected "
        "6493.49845123, is %s",
        last_msg.msg.ephemeris_bds.sqrta);

    ck_assert_msg((last_msg.msg.ephemeris_bds.tgd1 * 100 -
                   1.04999999806e-08 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_bds.tgd1, "
                  "expected 1.04999999806e-08, is %s",
                  last_msg.msg.ephemeris_bds.tgd1);

    ck_assert_msg((last_msg.msg.ephemeris_bds.tgd2 * 100 -
                   -1.09999997999e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_bds.tgd2, "
                  "expected -1.09999997999e-09, is %s",
                  last_msg.msg.ephemeris_bds.tgd2);

    ck_assert_msg(last_msg.msg.ephemeris_bds.toc.tow == 439214,
                  "incorrect value for last_msg.msg.ephemeris_bds.toc.tow, "
                  "expected 439214, is %d",
                  last_msg.msg.ephemeris_bds.toc.tow);

    ck_assert_msg(last_msg.msg.ephemeris_bds.toc.wn == 2154,
                  "incorrect value for last_msg.msg.ephemeris_bds.toc.wn, "
                  "expected 2154, is %d",
                  last_msg.msg.ephemeris_bds.toc.wn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_bds.w * 100 - -2.69860320574 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_bds.w, expected "
        "-2.69860320574, is %s",
        last_msg.msg.ephemeris_bds.w);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgEphemerisBds_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_MsgEphemerisBds");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_observation_MsgEphemerisBds");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgEphemerisBds);
  suite_add_tcase(s, tc_acq);
  return s;
}