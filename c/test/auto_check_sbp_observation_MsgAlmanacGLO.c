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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgAlmanacGLO.yaml by
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

static size_t dummy_wr = 0;
static size_t dummy_rd = 0;
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
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
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

START_TEST(test_auto_check_sbp_observation_MsgAlmanacGLO) {
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

    sbp_callback_register(&sbp_state, 0x73, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  115, 0,   195, 4,   78,  22,  0,   176, 207, 6,   0,   106,
        8,   154, 153, 153, 153, 153, 153, 1,   64,  64,  56,  0,   0,
        1,   0,   142, 41,  5,   235, 95,  135, 150, 191, 0,   0,   0,
        32,  191, 247, 124, 63,  0,   0,   192, 206, 140, 33,  180, 64,
        41,  131, 179, 134, 141, 248, 253, 191, 227, 133, 81,  54,  204,
        30,  67,  190, 216, 59,  199, 39,  96,  168, 239, 191, 71,  11,
        217, 147, 145, 228, 237, 63,  155, 87,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.almanac_glo.common.fit_interval = 14400;

    test_msg.almanac_glo.common.health_bits = 0;

    test_msg.almanac_glo.common.sid.code = 0;

    test_msg.almanac_glo.common.sid.sat = 22;

    test_msg.almanac_glo.common.toa.tow = 446384;

    test_msg.almanac_glo.common.toa.wn = 2154;

    test_msg.almanac_glo.common.ura = 2.2;

    test_msg.almanac_glo.common.valid = 1;

    test_msg.almanac_glo.epsilon = -0.9893036629599647;

    test_msg.almanac_glo.i = 5153.550029754639;

    test_msg.almanac_glo.lambda_na = -0.02200078842114688;

    test_msg.almanac_glo.omega = 0.9341514480259797;

    test_msg.almanac_glo.t = -1.8731818448797617;

    test_msg.almanac_glo.t_dot = -8.903585155774196e-09;

    test_msg.almanac_glo.t_lambda_na = 0.007072207052260637;

    sbp_message_send(&sbp_state, SbpMsgAlmanacGlo, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgAlmanacGlo, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.almanac_glo.common.fit_interval == 14400,
        "incorrect value for last_msg.msg.almanac_glo.common.fit_interval, "
        "expected 14400, is %" PRId64,
        (int64_t)last_msg.msg.almanac_glo.common.fit_interval);

    ck_assert_msg(
        last_msg.msg.almanac_glo.common.health_bits == 0,
        "incorrect value for last_msg.msg.almanac_glo.common.health_bits, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.almanac_glo.common.health_bits);

    ck_assert_msg(
        last_msg.msg.almanac_glo.common.sid.code == 0,
        "incorrect value for last_msg.msg.almanac_glo.common.sid.code, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.almanac_glo.common.sid.code);

    ck_assert_msg(
        last_msg.msg.almanac_glo.common.sid.sat == 22,
        "incorrect value for last_msg.msg.almanac_glo.common.sid.sat, expected "
        "22, is %" PRId64,
        (int64_t)last_msg.msg.almanac_glo.common.sid.sat);

    ck_assert_msg(
        last_msg.msg.almanac_glo.common.toa.tow == 446384,
        "incorrect value for last_msg.msg.almanac_glo.common.toa.tow, expected "
        "446384, is %" PRId64,
        (int64_t)last_msg.msg.almanac_glo.common.toa.tow);

    ck_assert_msg(last_msg.msg.almanac_glo.common.toa.wn == 2154,
                  "incorrect value for last_msg.msg.almanac_glo.common.toa.wn, "
                  "expected 2154, is %" PRId64,
                  (int64_t)last_msg.msg.almanac_glo.common.toa.wn);

    ck_assert_msg(
        (last_msg.msg.almanac_glo.common.ura * 100 - 2.2 * 100) < 0.05,
        "incorrect value for last_msg.msg.almanac_glo.common.ura, expected "
        "2.2, is %f",
        last_msg.msg.almanac_glo.common.ura);

    ck_assert_msg(last_msg.msg.almanac_glo.common.valid == 1,
                  "incorrect value for last_msg.msg.almanac_glo.common.valid, "
                  "expected 1, is %" PRId64,
                  (int64_t)last_msg.msg.almanac_glo.common.valid);

    ck_assert_msg(
        (last_msg.msg.almanac_glo.epsilon * 100 - -0.98930366296 * 100) < 0.05,
        "incorrect value for last_msg.msg.almanac_glo.epsilon, expected "
        "-0.98930366296, is %f",
        last_msg.msg.almanac_glo.epsilon);

    ck_assert_msg(
        (last_msg.msg.almanac_glo.i * 100 - 5153.55002975 * 100) < 0.05,
        "incorrect value for last_msg.msg.almanac_glo.i, expected "
        "5153.55002975, is %f",
        last_msg.msg.almanac_glo.i);

    ck_assert_msg((last_msg.msg.almanac_glo.lambda_na * 100 -
                   -0.0220007884211 * 100) < 0.05,
                  "incorrect value for last_msg.msg.almanac_glo.lambda_na, "
                  "expected -0.0220007884211, is %f",
                  last_msg.msg.almanac_glo.lambda_na);

    ck_assert_msg(
        (last_msg.msg.almanac_glo.omega * 100 - 0.934151448026 * 100) < 0.05,
        "incorrect value for last_msg.msg.almanac_glo.omega, expected "
        "0.934151448026, is %f",
        last_msg.msg.almanac_glo.omega);

    ck_assert_msg(
        (last_msg.msg.almanac_glo.t * 100 - -1.87318184488 * 100) < 0.05,
        "incorrect value for last_msg.msg.almanac_glo.t, expected "
        "-1.87318184488, is %f",
        last_msg.msg.almanac_glo.t);

    ck_assert_msg((last_msg.msg.almanac_glo.t_dot * 100 -
                   -8.90358515577e-09 * 100) < 0.05,
                  "incorrect value for last_msg.msg.almanac_glo.t_dot, "
                  "expected -8.90358515577e-09, is %f",
                  last_msg.msg.almanac_glo.t_dot);

    ck_assert_msg((last_msg.msg.almanac_glo.t_lambda_na * 100 -
                   0.00707220705226 * 100) < 0.05,
                  "incorrect value for last_msg.msg.almanac_glo.t_lambda_na, "
                  "expected 0.00707220705226, is %f",
                  last_msg.msg.almanac_glo.t_lambda_na);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgAlmanacGLO_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_MsgAlmanacGLO");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_observation_MsgAlmanacGLO");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgAlmanacGLO);
  suite_add_tcase(s, tc_acq);
  return s;
}