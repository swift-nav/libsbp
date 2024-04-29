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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockDepA.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/ssr.h>
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

START_TEST(test_auto_check_sbp_ssr_MsgSsrOrbitClockDepA) {
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

    sbp_callback_register(&sbp_state, 0x5dc, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  220, 5,   33,  166, 47,  225, 114, 31,  189, 43,  30,  1,   30,
        194, 211, 193, 175, 161, 143, 254, 56,  63,  232, 7,   216, 69,  1,
        110, 165, 124, 196, 189, 27,  116, 88,  4,   61,  3,   151, 18,  171,
        147, 46,  198, 85,  243, 245, 225, 235, 123, 181, 210, 157, 252,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_orbit_clock_dep_a.along = 132661048;

    test_msg.ssr_orbit_clock_dep_a.c0 = -970026069;

    test_msg.ssr_orbit_clock_dep_a.c1 = -503975083;

    test_msg.ssr_orbit_clock_dep_a.c2 = -759858197;

    test_msg.ssr_orbit_clock_dep_a.cross = 1845577176;

    test_msg.ssr_orbit_clock_dep_a.dot_along = 72905755;

    test_msg.ssr_orbit_clock_dep_a.dot_cross = 311886653;

    test_msg.ssr_orbit_clock_dep_a.dot_radial = -1111196507;

    test_msg.ssr_orbit_clock_dep_a.iod = 193;

    test_msg.ssr_orbit_clock_dep_a.iod_ssr = 211;

    test_msg.ssr_orbit_clock_dep_a.radial = -24141393;

    test_msg.ssr_orbit_clock_dep_a.sid.code = 30;

    test_msg.ssr_orbit_clock_dep_a.sid.sat = 1;

    test_msg.ssr_orbit_clock_dep_a.time.tow = 3172954849;

    test_msg.ssr_orbit_clock_dep_a.time.wn = 7723;

    test_msg.ssr_orbit_clock_dep_a.update_interval = 194;

    sbp_message_send(&sbp_state, SbpMsgSsrOrbitClockDepA, 42529, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 42529,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgSsrOrbitClockDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.along == 132661048,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.along, "
        "expected 132661048, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.along);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock_dep_a.c0 == -970026069,
                  "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.c0, "
                  "expected -970026069, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.c0);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock_dep_a.c1 == -503975083,
                  "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.c1, "
                  "expected -503975083, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.c1);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock_dep_a.c2 == -759858197,
                  "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.c2, "
                  "expected -759858197, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.c2);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.cross == 1845577176,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.cross, "
        "expected 1845577176, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.cross);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.dot_along == 72905755,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.dot_along, "
        "expected 72905755, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.dot_along);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.dot_cross == 311886653,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.dot_cross, "
        "expected 311886653, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.dot_cross);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.dot_radial == -1111196507,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.dot_radial, "
        "expected -1111196507, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.dot_radial);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock_dep_a.iod == 193,
                  "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.iod, "
                  "expected 193, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.iod);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.iod_ssr == 211,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.iod_ssr, "
        "expected 211, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.iod_ssr);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.radial == -24141393,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.radial, "
        "expected -24141393, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.radial);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.sid.code == 30,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.sid.code, "
        "expected 30, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.sid.code);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.sid.sat == 1,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.sid.sat, "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.sid.sat);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.time.tow == 3172954849,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.time.tow, "
        "expected 3172954849, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.time.tow);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_dep_a.time.wn == 7723,
        "incorrect value for last_msg.msg.ssr_orbit_clock_dep_a.time.wn, "
        "expected 7723, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.time.wn);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock_dep_a.update_interval == 194,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_dep_a.update_interval, "
                  "expected 194, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_orbit_clock_dep_a.update_interval);
  }
}
END_TEST

Suite *auto_check_sbp_ssr_MsgSsrOrbitClockDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_ssr_MsgSsrOrbitClockDepA");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_ssr_MsgSsrOrbitClockDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_ssr_MsgSsrOrbitClockDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}