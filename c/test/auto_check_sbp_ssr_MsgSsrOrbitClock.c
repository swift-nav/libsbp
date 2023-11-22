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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClock.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/ssr.h>
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

START_TEST(test_auto_check_sbp_ssr_MsgSsrOrbitClock) {
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

    sbp_callback_register(&sbp_state, 0x5dd, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  221, 5,   53,  229, 50,  83,  208, 102, 207, 164, 29,
        203, 212, 236, 255, 152, 233, 207, 55,  94,  54,  58,  128,
        68,  27,  117, 176, 110, 251, 61,  244, 122, 50,  95,  52,
        144, 232, 24,  10,  37,  127, 163, 66,  177, 105, 156, 245,
        10,  249, 107, 218, 17,  186, 56,  72,  14,  22,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_orbit_clock.along = -1334502588;

    test_msg.ssr_orbit_clock.c0 = -174298703;

    test_msg.ssr_orbit_clock.c1 = -630458102;

    test_msg.ssr_orbit_clock.c2 = 1211677201;

    test_msg.ssr_orbit_clock.cross = -197264530;

    test_msg.ssr_orbit_clock.dot_along = 169404560;

    test_msg.ssr_orbit_clock.dot_cross = 1118011173;

    test_msg.ssr_orbit_clock.dot_radial = 878654074;

    test_msg.ssr_orbit_clock.iod = 936372632;

    test_msg.ssr_orbit_clock.iod_ssr = 255;

    test_msg.ssr_orbit_clock.radial = -2143668642;

    test_msg.ssr_orbit_clock.sid.code = 212;

    test_msg.ssr_orbit_clock.sid.sat = 203;

    test_msg.ssr_orbit_clock.time.tow = 3479621715;

    test_msg.ssr_orbit_clock.time.wn = 7588;

    test_msg.ssr_orbit_clock.update_interval = 236;

    sbp_message_send(&sbp_state, SbpMsgSsrOrbitClock, 58677, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 58677,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgSsrOrbitClock, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.along == -1334502588,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.along, "
                  "expected -1334502588, is %d",
                  last_msg.msg.ssr_orbit_clock.along);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.c0 == -174298703,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.c0, "
                  "expected -174298703, is %d",
                  last_msg.msg.ssr_orbit_clock.c0);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.c1 == -630458102,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.c1, "
                  "expected -630458102, is %d",
                  last_msg.msg.ssr_orbit_clock.c1);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.c2 == 1211677201,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.c2, "
                  "expected 1211677201, is %d",
                  last_msg.msg.ssr_orbit_clock.c2);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.cross == -197264530,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.cross, "
                  "expected -197264530, is %d",
                  last_msg.msg.ssr_orbit_clock.cross);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.dot_along == 169404560,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.dot_along, "
                  "expected 169404560, is %d",
                  last_msg.msg.ssr_orbit_clock.dot_along);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.dot_cross == 1118011173,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.dot_cross, "
                  "expected 1118011173, is %d",
                  last_msg.msg.ssr_orbit_clock.dot_cross);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock.dot_radial == 878654074,
        "incorrect value for last_msg.msg.ssr_orbit_clock.dot_radial, expected "
        "878654074, is %d",
        last_msg.msg.ssr_orbit_clock.dot_radial);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.iod == 936372632,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.iod, "
                  "expected 936372632, is %d",
                  last_msg.msg.ssr_orbit_clock.iod);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.iod_ssr == 255,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.iod_ssr, "
                  "expected 255, is %d",
                  last_msg.msg.ssr_orbit_clock.iod_ssr);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.radial == -2143668642,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.radial, "
                  "expected -2143668642, is %d",
                  last_msg.msg.ssr_orbit_clock.radial);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.sid.code == 212,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.sid.code, "
                  "expected 212, is %d",
                  last_msg.msg.ssr_orbit_clock.sid.code);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.sid.sat == 203,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.sid.sat, "
                  "expected 203, is %d",
                  last_msg.msg.ssr_orbit_clock.sid.sat);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.time.tow == 3479621715,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.time.tow, "
                  "expected 3479621715, is %d",
                  last_msg.msg.ssr_orbit_clock.time.tow);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock.time.wn == 7588,
                  "incorrect value for last_msg.msg.ssr_orbit_clock.time.wn, "
                  "expected 7588, is %d",
                  last_msg.msg.ssr_orbit_clock.time.wn);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock.update_interval == 236,
        "incorrect value for last_msg.msg.ssr_orbit_clock.update_interval, "
        "expected 236, is %d",
        last_msg.msg.ssr_orbit_clock.update_interval);
  }
}
END_TEST

Suite *auto_check_sbp_ssr_MsgSsrOrbitClock_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_ssr_MsgSsrOrbitClock");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_ssr_MsgSsrOrbitClock");
  tcase_add_test(tc_acq, test_auto_check_sbp_ssr_MsgSsrOrbitClock);
  suite_add_tcase(s, tc_acq);
  return s;
}