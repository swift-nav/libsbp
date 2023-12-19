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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgEphemerisDepD.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/api.h>
#include <libsbp/legacy/compat.h>
#include <libsbp/legacy/observation.h>

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

START_TEST(test_legacy_auto_check_sbp_observation_MsgEphemerisDepD) {
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

    sbp_payload_callback_register(&sbp_state, 0x80, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x80, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  128, 0,   195, 4,   185, 0,   0,   0,   0,   0,   0,   83,  190,
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
        0,   0,   45,  45,  0,   0,   0,   0,   0,   95,  7,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ephemeris_dep_d_t *test_msg = (msg_ephemeris_dep_d_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->af0 = -0.0006315018981695175;
    test_msg->af1 = 8.981260180007666e-12;
    test_msg->af2 = 0.2;
    test_msg->c_ic = 7.450580596923828e-09;
    test_msg->c_is = -1.1548399925231934e-07;
    test_msg->c_rc = 308.625;
    test_msg->c_rs = -52.3125;
    test_msg->c_uc = -2.7436763048171997e-06;
    test_msg->c_us = 3.1366944313049316e-06;
    test_msg->dn = 5.694522914022375e-09;
    test_msg->ecc = 0.007072207052260637;
    test_msg->healthy = 0;
    test_msg->inc = 0.9341514480259797;
    test_msg->inc_dot = -4.035882396415757e-11;
    test_msg->iodc = 45;
    test_msg->iode = 45;
    test_msg->m0 = -0.02200078842114688;
    test_msg->omega0 = -1.8731818448797617;
    test_msg->omegadot = -8.903585155774196e-09;
    test_msg->reserved = 0;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 22;
    test_msg->sqrta = 5153.550029754639;
    test_msg->tgd = -1.7695128917694092e-08;
    test_msg->toc_tow = 446384.2;
    test_msg->toc_wn = 2154;
    test_msg->toe_tow = 446384.2;
    test_msg->toe_wn = 2154;
    test_msg->valid = 1;
    test_msg->w = -0.9893036629599647;
    sbp_payload_send(&sbp_state, 0x80, 1219, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_frame.msg_type == 0x80,
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
    msg_ephemeris_dep_d_t *check_msg =
        (msg_ephemeris_dep_d_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((check_msg->af0 * 100 - -0.00063150189817 * 100) < 0.05,
                  "incorrect value for af0, expected -0.00063150189817, is %f",
                  check_msg->af0);
    ck_assert_msg((check_msg->af1 * 100 - 8.98126018001e-12 * 100) < 0.05,
                  "incorrect value for af1, expected 8.98126018001e-12, is %f",
                  check_msg->af1);
    ck_assert_msg((check_msg->af2 * 100 - 0.2 * 100) < 0.05,
                  "incorrect value for af2, expected 0.2, is %f",
                  check_msg->af2);
    ck_assert_msg((check_msg->c_ic * 100 - 7.45058059692e-09 * 100) < 0.05,
                  "incorrect value for c_ic, expected 7.45058059692e-09, is %f",
                  check_msg->c_ic);
    ck_assert_msg(
        (check_msg->c_is * 100 - -1.15483999252e-07 * 100) < 0.05,
        "incorrect value for c_is, expected -1.15483999252e-07, is %f",
        check_msg->c_is);
    ck_assert_msg((check_msg->c_rc * 100 - 308.625 * 100) < 0.05,
                  "incorrect value for c_rc, expected 308.625, is %f",
                  check_msg->c_rc);
    ck_assert_msg((check_msg->c_rs * 100 - -52.3125 * 100) < 0.05,
                  "incorrect value for c_rs, expected -52.3125, is %f",
                  check_msg->c_rs);
    ck_assert_msg(
        (check_msg->c_uc * 100 - -2.74367630482e-06 * 100) < 0.05,
        "incorrect value for c_uc, expected -2.74367630482e-06, is %f",
        check_msg->c_uc);
    ck_assert_msg((check_msg->c_us * 100 - 3.1366944313e-06 * 100) < 0.05,
                  "incorrect value for c_us, expected 3.1366944313e-06, is %f",
                  check_msg->c_us);
    ck_assert_msg((check_msg->dn * 100 - 5.69452291402e-09 * 100) < 0.05,
                  "incorrect value for dn, expected 5.69452291402e-09, is %f",
                  check_msg->dn);
    ck_assert_msg((check_msg->ecc * 100 - 0.00707220705226 * 100) < 0.05,
                  "incorrect value for ecc, expected 0.00707220705226, is %f",
                  check_msg->ecc);
    ck_assert_msg(check_msg->healthy == 0,
                  "incorrect value for healthy, expected 0, is %d",
                  check_msg->healthy);
    ck_assert_msg((check_msg->inc * 100 - 0.934151448026 * 100) < 0.05,
                  "incorrect value for inc, expected 0.934151448026, is %f",
                  check_msg->inc);
    ck_assert_msg(
        (check_msg->inc_dot * 100 - -4.03588239642e-11 * 100) < 0.05,
        "incorrect value for inc_dot, expected -4.03588239642e-11, is %f",
        check_msg->inc_dot);
    ck_assert_msg(check_msg->iodc == 45,
                  "incorrect value for iodc, expected 45, is %d",
                  check_msg->iodc);
    ck_assert_msg(check_msg->iode == 45,
                  "incorrect value for iode, expected 45, is %d",
                  check_msg->iode);
    ck_assert_msg((check_msg->m0 * 100 - -0.0220007884211 * 100) < 0.05,
                  "incorrect value for m0, expected -0.0220007884211, is %f",
                  check_msg->m0);
    ck_assert_msg((check_msg->omega0 * 100 - -1.87318184488 * 100) < 0.05,
                  "incorrect value for omega0, expected -1.87318184488, is %f",
                  check_msg->omega0);
    ck_assert_msg(
        (check_msg->omegadot * 100 - -8.90358515577e-09 * 100) < 0.05,
        "incorrect value for omegadot, expected -8.90358515577e-09, is %f",
        check_msg->omegadot);
    ck_assert_msg(check_msg->reserved == 0,
                  "incorrect value for reserved, expected 0, is %d",
                  check_msg->reserved);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 22,
                  "incorrect value for sid.sat, expected 22, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->sqrta * 100 - 5153.55002975 * 100) < 0.05,
                  "incorrect value for sqrta, expected 5153.55002975, is %f",
                  check_msg->sqrta);
    ck_assert_msg((check_msg->tgd * 100 - -1.76951289177e-08 * 100) < 0.05,
                  "incorrect value for tgd, expected -1.76951289177e-08, is %f",
                  check_msg->tgd);
    ck_assert_msg((check_msg->toc_tow * 100 - 446384.2 * 100) < 0.05,
                  "incorrect value for toc_tow, expected 446384.2, is %f",
                  check_msg->toc_tow);
    ck_assert_msg(check_msg->toc_wn == 2154,
                  "incorrect value for toc_wn, expected 2154, is %d",
                  check_msg->toc_wn);
    ck_assert_msg((check_msg->toe_tow * 100 - 446384.2 * 100) < 0.05,
                  "incorrect value for toe_tow, expected 446384.2, is %f",
                  check_msg->toe_tow);
    ck_assert_msg(check_msg->toe_wn == 2154,
                  "incorrect value for toe_wn, expected 2154, is %d",
                  check_msg->toe_wn);
    ck_assert_msg(check_msg->valid == 1,
                  "incorrect value for valid, expected 1, is %d",
                  check_msg->valid);
    ck_assert_msg((check_msg->w * 100 - -0.98930366296 * 100) < 0.05,
                  "incorrect value for w, expected -0.98930366296, is %f",
                  check_msg->w);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_observation_MsgEphemerisDepD_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_observation_MsgEphemerisDepD");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_observation_MsgEphemerisDepD");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_observation_MsgEphemerisDepD);
  suite_add_tcase(s, tc_acq);
  return s;
}