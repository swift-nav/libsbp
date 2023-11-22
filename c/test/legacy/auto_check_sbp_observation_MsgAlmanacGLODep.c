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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgAlmanacGLODep.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/observation.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return real_n;
}

static void logging_reset() {
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_observation_MsgAlmanacGLODep) {
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;

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

    sbp_payload_callback_register(&sbp_state, 0x71, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x71, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  113, 0,   195, 4,   80,  22,  0,   0,   0,   176, 207, 6,
        0,   106, 8,   154, 153, 153, 153, 153, 153, 1,   64,  64,  56,
        0,   0,   1,   0,   142, 41,  5,   235, 95,  135, 150, 191, 0,
        0,   0,   32,  191, 247, 124, 63,  0,   0,   192, 206, 140, 33,
        180, 64,  41,  131, 179, 134, 141, 248, 253, 191, 227, 133, 81,
        54,  204, 30,  67,  190, 216, 59,  199, 39,  96,  168, 239, 191,
        71,  11,  217, 147, 145, 228, 237, 63,  203, 178,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_almanac_glo_dep_t *test_msg = (msg_almanac_glo_dep_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->common.fit_interval = 14400;
    test_msg->common.health_bits = 0;
    test_msg->common.sid.code = 0;
    test_msg->common.sid.reserved = 0;
    test_msg->common.sid.sat = 22;
    test_msg->common.toa.tow = 446384;
    test_msg->common.toa.wn = 2154;
    test_msg->common.ura = 2.2;
    test_msg->common.valid = 1;
    test_msg->epsilon = -0.9893036629599647;
    test_msg->i = 5153.550029754639;
    test_msg->lambda_na = -0.02200078842114688;
    test_msg->omega = 0.9341514480259797;
    test_msg->t = -1.8731818448797617;
    test_msg->t_dot = -8.903585155774196e-09;
    test_msg->t_lambda_na = 0.007072207052260637;
    sbp_payload_send(&sbp_state, 0x71, 1219, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x71,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_almanac_glo_dep_t *check_msg =
        (msg_almanac_glo_dep_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        check_msg->common.fit_interval == 14400,
        "incorrect value for common.fit_interval, expected 14400, is %d",
        check_msg->common.fit_interval);
    ck_assert_msg(check_msg->common.health_bits == 0,
                  "incorrect value for common.health_bits, expected 0, is %d",
                  check_msg->common.health_bits);
    ck_assert_msg(check_msg->common.sid.code == 0,
                  "incorrect value for common.sid.code, expected 0, is %d",
                  check_msg->common.sid.code);
    ck_assert_msg(check_msg->common.sid.reserved == 0,
                  "incorrect value for common.sid.reserved, expected 0, is %d",
                  check_msg->common.sid.reserved);
    ck_assert_msg(check_msg->common.sid.sat == 22,
                  "incorrect value for common.sid.sat, expected 22, is %d",
                  check_msg->common.sid.sat);
    ck_assert_msg(check_msg->common.toa.tow == 446384,
                  "incorrect value for common.toa.tow, expected 446384, is %d",
                  check_msg->common.toa.tow);
    ck_assert_msg(check_msg->common.toa.wn == 2154,
                  "incorrect value for common.toa.wn, expected 2154, is %d",
                  check_msg->common.toa.wn);
    ck_assert_msg((check_msg->common.ura * 100 - 2.2 * 100) < 0.05,
                  "incorrect value for common.ura, expected 2.2, is %f",
                  check_msg->common.ura);
    ck_assert_msg(check_msg->common.valid == 1,
                  "incorrect value for common.valid, expected 1, is %d",
                  check_msg->common.valid);
    ck_assert_msg((check_msg->epsilon * 100 - -0.98930366296 * 100) < 0.05,
                  "incorrect value for epsilon, expected -0.98930366296, is %f",
                  check_msg->epsilon);
    ck_assert_msg((check_msg->i * 100 - 5153.55002975 * 100) < 0.05,
                  "incorrect value for i, expected 5153.55002975, is %f",
                  check_msg->i);
    ck_assert_msg(
        (check_msg->lambda_na * 100 - -0.0220007884211 * 100) < 0.05,
        "incorrect value for lambda_na, expected -0.0220007884211, is %f",
        check_msg->lambda_na);
    ck_assert_msg((check_msg->omega * 100 - 0.934151448026 * 100) < 0.05,
                  "incorrect value for omega, expected 0.934151448026, is %f",
                  check_msg->omega);
    ck_assert_msg((check_msg->t * 100 - -1.87318184488 * 100) < 0.05,
                  "incorrect value for t, expected -1.87318184488, is %f",
                  check_msg->t);
    ck_assert_msg(
        (check_msg->t_dot * 100 - -8.90358515577e-09 * 100) < 0.05,
        "incorrect value for t_dot, expected -8.90358515577e-09, is %f",
        check_msg->t_dot);
    ck_assert_msg(
        (check_msg->t_lambda_na * 100 - 0.00707220705226 * 100) < 0.05,
        "incorrect value for t_lambda_na, expected 0.00707220705226, is %f",
        check_msg->t_lambda_na);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_observation_MsgAlmanacGLODep_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_observation_MsgAlmanacGLODep");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_observation_MsgAlmanacGLODep");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_observation_MsgAlmanacGLODep);
  suite_add_tcase(s, tc_acq);
  return s;
}