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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisGLO.yaml by
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

START_TEST(test_auto_check_sbp_observation_MsgEphemerisGLO) {
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

    sbp_callback_register(&sbp_state, 0x8b, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  139, 0,   10,  9,   92,  4,   3,   70,  197, 6,   0,  106,
        8,   0,   0,   160, 64,  96,  9,   0,   0,   1,   0,   0,  0,
        128, 43,  128, 97,  175, 184, 0,   0,   64,  177, 0,   0,  128,
        66,  246, 57,  103, 193, 0,   0,   0,   34,  170, 78,  34, 65,
        0,   0,   240, 199, 84,  86,  117, 193, 0,   0,   0,   98, 6,
        250, 154, 192, 0,   0,   0,   217, 58,  221, 163, 192, 0,  0,
        0,   184, 138, 46,  139, 64,  0,   0,   122, 53,  0,   0,  122,
        53,  0,   128, 59,  54,  14,  100, 89,  149,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ephemeris_glo.acc[0] = 9.313225746154785e-07;

    test_msg.ephemeris_glo.acc[1] = 9.313225746154785e-07;

    test_msg.ephemeris_glo.acc[2] = 2.7939677238464355e-06;

    test_msg.ephemeris_glo.common.fit_interval = 2400;

    test_msg.ephemeris_glo.common.health_bits = 0;

    test_msg.ephemeris_glo.common.sid.code = 3;

    test_msg.ephemeris_glo.common.sid.sat = 4;

    test_msg.ephemeris_glo.common.toe.tow = 443718;

    test_msg.ephemeris_glo.common.toe.wn = 2154;

    test_msg.ephemeris_glo.common.ura = 5.0;

    test_msg.ephemeris_glo.common.valid = 1;

    test_msg.ephemeris_glo.d_tau = -2.7939677238464355e-09;

    test_msg.ephemeris_glo.fcn = 14;

    test_msg.ephemeris_glo.gamma = 9.094947017729282e-13;

    test_msg.ephemeris_glo.iod = 100;

    test_msg.ephemeris_glo.pos[0] = -12177330.078125;

    test_msg.ephemeris_glo.pos[1] = 599893.06640625;

    test_msg.ephemeris_glo.pos[2] = -22373708.49609375;

    test_msg.ephemeris_glo.tau = -8.36281105875969e-05;

    test_msg.ephemeris_glo.vel[0] = -1726.506233215332;

    test_msg.ephemeris_glo.vel[1] = -2542.6149368286133;

    test_msg.ephemeris_glo.vel[2] = 869.8177337646484;

    sbp_message_send(&sbp_state, SbpMsgEphemerisGlo, 2314, &test_msg,
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
        sbp_message_cmp(SbpMsgEphemerisGlo, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg((last_msg.msg.ephemeris_glo.acc[0] * 100 -
                   9.31322574615e-07 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_glo.acc[0], "
                  "expected 9.31322574615e-07, is %s",
                  last_msg.msg.ephemeris_glo.acc[0]);
    ck_assert_msg((last_msg.msg.ephemeris_glo.acc[1] * 100 -
                   9.31322574615e-07 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_glo.acc[1], "
                  "expected 9.31322574615e-07, is %s",
                  last_msg.msg.ephemeris_glo.acc[1]);
    ck_assert_msg((last_msg.msg.ephemeris_glo.acc[2] * 100 -
                   2.79396772385e-06 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_glo.acc[2], "
                  "expected 2.79396772385e-06, is %s",
                  last_msg.msg.ephemeris_glo.acc[2]);

    ck_assert_msg(
        last_msg.msg.ephemeris_glo.common.fit_interval == 2400,
        "incorrect value for last_msg.msg.ephemeris_glo.common.fit_interval, "
        "expected 2400, is %d",
        last_msg.msg.ephemeris_glo.common.fit_interval);

    ck_assert_msg(
        last_msg.msg.ephemeris_glo.common.health_bits == 0,
        "incorrect value for last_msg.msg.ephemeris_glo.common.health_bits, "
        "expected 0, is %d",
        last_msg.msg.ephemeris_glo.common.health_bits);

    ck_assert_msg(
        last_msg.msg.ephemeris_glo.common.sid.code == 3,
        "incorrect value for last_msg.msg.ephemeris_glo.common.sid.code, "
        "expected 3, is %d",
        last_msg.msg.ephemeris_glo.common.sid.code);

    ck_assert_msg(
        last_msg.msg.ephemeris_glo.common.sid.sat == 4,
        "incorrect value for last_msg.msg.ephemeris_glo.common.sid.sat, "
        "expected 4, is %d",
        last_msg.msg.ephemeris_glo.common.sid.sat);

    ck_assert_msg(
        last_msg.msg.ephemeris_glo.common.toe.tow == 443718,
        "incorrect value for last_msg.msg.ephemeris_glo.common.toe.tow, "
        "expected 443718, is %d",
        last_msg.msg.ephemeris_glo.common.toe.tow);

    ck_assert_msg(
        last_msg.msg.ephemeris_glo.common.toe.wn == 2154,
        "incorrect value for last_msg.msg.ephemeris_glo.common.toe.wn, "
        "expected 2154, is %d",
        last_msg.msg.ephemeris_glo.common.toe.wn);

    ck_assert_msg(
        (last_msg.msg.ephemeris_glo.common.ura * 100 - 5.0 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_glo.common.ura, expected "
        "5.0, is %s",
        last_msg.msg.ephemeris_glo.common.ura);

    ck_assert_msg(last_msg.msg.ephemeris_glo.common.valid == 1,
                  "incorrect value for "
                  "last_msg.msg.ephemeris_glo.common.valid, expected 1, is %d",
                  last_msg.msg.ephemeris_glo.common.valid);

    ck_assert_msg((last_msg.msg.ephemeris_glo.d_tau * 100 -
                   -2.79396772385e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_glo.d_tau, "
                  "expected -2.79396772385e-09, is %s",
                  last_msg.msg.ephemeris_glo.d_tau);

    ck_assert_msg(last_msg.msg.ephemeris_glo.fcn == 14,
                  "incorrect value for last_msg.msg.ephemeris_glo.fcn, "
                  "expected 14, is %d",
                  last_msg.msg.ephemeris_glo.fcn);

    ck_assert_msg((last_msg.msg.ephemeris_glo.gamma * 100 -
                   9.09494701773e-13 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_glo.gamma, "
                  "expected 9.09494701773e-13, is %s",
                  last_msg.msg.ephemeris_glo.gamma);

    ck_assert_msg(last_msg.msg.ephemeris_glo.iod == 100,
                  "incorrect value for last_msg.msg.ephemeris_glo.iod, "
                  "expected 100, is %d",
                  last_msg.msg.ephemeris_glo.iod);

    ck_assert_msg(
        (last_msg.msg.ephemeris_glo.pos[0] * 100 - -12177330.0781 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_glo.pos[0], expected "
        "-12177330.0781, is %s",
        last_msg.msg.ephemeris_glo.pos[0]);
    ck_assert_msg(
        (last_msg.msg.ephemeris_glo.pos[1] * 100 - 599893.066406 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_glo.pos[1], expected "
        "599893.066406, is %s",
        last_msg.msg.ephemeris_glo.pos[1]);
    ck_assert_msg(
        (last_msg.msg.ephemeris_glo.pos[2] * 100 - -22373708.4961 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_glo.pos[2], expected "
        "-22373708.4961, is %s",
        last_msg.msg.ephemeris_glo.pos[2]);

    ck_assert_msg((last_msg.msg.ephemeris_glo.tau * 100 -
                   -8.36281105876e-05 * 100) < 0.05,
                  "incorrect value for last_msg.msg.ephemeris_glo.tau, "
                  "expected -8.36281105876e-05, is %s",
                  last_msg.msg.ephemeris_glo.tau);

    ck_assert_msg(
        (last_msg.msg.ephemeris_glo.vel[0] * 100 - -1726.50623322 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_glo.vel[0], expected "
        "-1726.50623322, is %s",
        last_msg.msg.ephemeris_glo.vel[0]);
    ck_assert_msg(
        (last_msg.msg.ephemeris_glo.vel[1] * 100 - -2542.61493683 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_glo.vel[1], expected "
        "-2542.61493683, is %s",
        last_msg.msg.ephemeris_glo.vel[1]);
    ck_assert_msg(
        (last_msg.msg.ephemeris_glo.vel[2] * 100 - 869.817733765 * 100) < 0.05,
        "incorrect value for last_msg.msg.ephemeris_glo.vel[2], expected "
        "869.817733765, is %s",
        last_msg.msg.ephemeris_glo.vel[2]);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgEphemerisGLO_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_MsgEphemerisGLO");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_observation_MsgEphemerisGLO");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgEphemerisGLO);
  suite_add_tcase(s, tc_acq);
  return s;
}