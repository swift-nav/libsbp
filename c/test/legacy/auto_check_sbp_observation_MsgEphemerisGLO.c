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

START_TEST(test_legacy_auto_check_sbp_observation_MsgEphemerisGLO) {
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

    sbp_payload_callback_register(&sbp_state, 0x8b, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x8b, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

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

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ephemeris_glo_t *test_msg = (msg_ephemeris_glo_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->acc) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->acc[0]);
    }
    test_msg->acc[0] = 9.313225746154785e-07;
    if (sizeof(test_msg->acc) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->acc[0]);
    }
    test_msg->acc[1] = 9.313225746154785e-07;
    if (sizeof(test_msg->acc) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->acc[0]);
    }
    test_msg->acc[2] = 2.7939677238464355e-06;
    test_msg->common.fit_interval = 2400;
    test_msg->common.health_bits = 0;
    test_msg->common.sid.code = 3;
    test_msg->common.sid.sat = 4;
    test_msg->common.toe.tow = 443718;
    test_msg->common.toe.wn = 2154;
    test_msg->common.ura = 5.0;
    test_msg->common.valid = 1;
    test_msg->d_tau = -2.7939677238464355e-09;
    test_msg->fcn = 14;
    test_msg->gamma = 9.094947017729282e-13;
    test_msg->iod = 100;
    if (sizeof(test_msg->pos) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->pos[0]);
    }
    test_msg->pos[0] = -12177330.078125;
    if (sizeof(test_msg->pos) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->pos[0]);
    }
    test_msg->pos[1] = 599893.06640625;
    if (sizeof(test_msg->pos) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->pos[0]);
    }
    test_msg->pos[2] = -22373708.49609375;
    test_msg->tau = -8.36281105875969e-05;
    if (sizeof(test_msg->vel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->vel[0]);
    }
    test_msg->vel[0] = -1726.506233215332;
    if (sizeof(test_msg->vel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->vel[0]);
    }
    test_msg->vel[1] = -2542.6149368286133;
    if (sizeof(test_msg->vel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->vel[0]);
    }
    test_msg->vel[2] = 869.8177337646484;
    sbp_payload_send(&sbp_state, 0x8b, 2314, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 2314,
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
    ck_assert_msg(last_frame.sender_id == 2314,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x8b,
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
    msg_ephemeris_glo_t *check_msg =
        (msg_ephemeris_glo_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        (check_msg->acc[0] * 100 - 9.31322574615e-07 * 100) < 0.05,
        "incorrect value for acc[0], expected 9.31322574615e-07, is %f",
        check_msg->acc[0]);
    ck_assert_msg(
        (check_msg->acc[1] * 100 - 9.31322574615e-07 * 100) < 0.05,
        "incorrect value for acc[1], expected 9.31322574615e-07, is %f",
        check_msg->acc[1]);
    ck_assert_msg(
        (check_msg->acc[2] * 100 - 2.79396772385e-06 * 100) < 0.05,
        "incorrect value for acc[2], expected 2.79396772385e-06, is %f",
        check_msg->acc[2]);
    ck_assert_msg(
        check_msg->common.fit_interval == 2400,
        "incorrect value for common.fit_interval, expected 2400, is %d",
        check_msg->common.fit_interval);
    ck_assert_msg(check_msg->common.health_bits == 0,
                  "incorrect value for common.health_bits, expected 0, is %d",
                  check_msg->common.health_bits);
    ck_assert_msg(check_msg->common.sid.code == 3,
                  "incorrect value for common.sid.code, expected 3, is %d",
                  check_msg->common.sid.code);
    ck_assert_msg(check_msg->common.sid.sat == 4,
                  "incorrect value for common.sid.sat, expected 4, is %d",
                  check_msg->common.sid.sat);
    ck_assert_msg(check_msg->common.toe.tow == 443718,
                  "incorrect value for common.toe.tow, expected 443718, is %d",
                  check_msg->common.toe.tow);
    ck_assert_msg(check_msg->common.toe.wn == 2154,
                  "incorrect value for common.toe.wn, expected 2154, is %d",
                  check_msg->common.toe.wn);
    ck_assert_msg((check_msg->common.ura * 100 - 5.0 * 100) < 0.05,
                  "incorrect value for common.ura, expected 5.0, is %f",
                  check_msg->common.ura);
    ck_assert_msg(check_msg->common.valid == 1,
                  "incorrect value for common.valid, expected 1, is %d",
                  check_msg->common.valid);
    ck_assert_msg(
        (check_msg->d_tau * 100 - -2.79396772385e-09 * 100) < 0.05,
        "incorrect value for d_tau, expected -2.79396772385e-09, is %f",
        check_msg->d_tau);
    ck_assert_msg(check_msg->fcn == 14,
                  "incorrect value for fcn, expected 14, is %d",
                  check_msg->fcn);
    ck_assert_msg(
        (check_msg->gamma * 100 - 9.09494701773e-13 * 100) < 0.05,
        "incorrect value for gamma, expected 9.09494701773e-13, is %f",
        check_msg->gamma);
    ck_assert_msg(check_msg->iod == 100,
                  "incorrect value for iod, expected 100, is %d",
                  check_msg->iod);
    ck_assert_msg((check_msg->pos[0] * 100 - -12177330.0781 * 100) < 0.05,
                  "incorrect value for pos[0], expected -12177330.0781, is %f",
                  check_msg->pos[0]);
    ck_assert_msg((check_msg->pos[1] * 100 - 599893.066406 * 100) < 0.05,
                  "incorrect value for pos[1], expected 599893.066406, is %f",
                  check_msg->pos[1]);
    ck_assert_msg((check_msg->pos[2] * 100 - -22373708.4961 * 100) < 0.05,
                  "incorrect value for pos[2], expected -22373708.4961, is %f",
                  check_msg->pos[2]);
    ck_assert_msg((check_msg->tau * 100 - -8.36281105876e-05 * 100) < 0.05,
                  "incorrect value for tau, expected -8.36281105876e-05, is %f",
                  check_msg->tau);
    ck_assert_msg((check_msg->vel[0] * 100 - -1726.50623322 * 100) < 0.05,
                  "incorrect value for vel[0], expected -1726.50623322, is %f",
                  check_msg->vel[0]);
    ck_assert_msg((check_msg->vel[1] * 100 - -2542.61493683 * 100) < 0.05,
                  "incorrect value for vel[1], expected -2542.61493683, is %f",
                  check_msg->vel[1]);
    ck_assert_msg((check_msg->vel[2] * 100 - 869.817733765 * 100) < 0.05,
                  "incorrect value for vel[2], expected 869.817733765, is %f",
                  check_msg->vel[2]);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_observation_MsgEphemerisGLO_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_observation_MsgEphemerisGLO");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_observation_MsgEphemerisGLO");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_observation_MsgEphemerisGLO);
  suite_add_tcase(s, tc_acq);
  return s;
}