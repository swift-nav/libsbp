/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBoundsDegradation.yaml
// by generate.py. Do not modify by hand!

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

START_TEST(test_auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation) {
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

    sbp_callback_register(&sbp_state, 1503, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 223, 5,   66,  0,   28,  180, 0,   0,   0,   3,   0,
        1,  2,   3,   48,  15,  1,   10,  0,   0,   0,   0,   0,
        0,  0,   200, 199, 198, 197, 196, 195, 194, 193, 200, 117,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_orbit_clock_bounds_degradation.const_id = 1;

    test_msg.ssr_orbit_clock_bounds_degradation.header.num_msgs = 1;

    test_msg.ssr_orbit_clock_bounds_degradation.header.seq_num = 2;

    test_msg.ssr_orbit_clock_bounds_degradation.header.sol_id = 48;

    test_msg.ssr_orbit_clock_bounds_degradation.header.time.tow = 180;

    test_msg.ssr_orbit_clock_bounds_degradation.header.time.wn = 3;

    test_msg.ssr_orbit_clock_bounds_degradation.header.update_interval = 3;

    test_msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_degradation
        .clock_bound_mu_dot = 194;

    test_msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_degradation
        .clock_bound_sig_dot = 193;

    test_msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_degradation
        .orb_along_bound_mu_dot = 199;

    test_msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_degradation
        .orb_along_bound_sig_dot = 196;

    test_msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_degradation
        .orb_cross_bound_mu_dot = 198;

    test_msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_degradation
        .orb_cross_bound_sig_dot = 195;

    test_msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_degradation
        .orb_radial_bound_mu_dot = 200;

    test_msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_degradation
        .orb_radial_bound_sig_dot = 197;

    test_msg.ssr_orbit_clock_bounds_degradation.sat_bitmask = 10;

    test_msg.ssr_orbit_clock_bounds_degradation.ssr_iod = 15;

    sbp_message_send(&sbp_state, SbpMsgSsrOrbitClockBoundsDegradation, 66,
                     &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 66,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgSsrOrbitClockBoundsDegradation,
                                  &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.const_id == 1,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.const_id, expected 1, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation.const_id);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.header.num_msgs == 1,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.header.num_msgs, "
        "expected 1, is %" PRId64,
        (int64_t)
            last_msg.msg.ssr_orbit_clock_bounds_degradation.header.num_msgs);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.header.seq_num == 2,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.header.seq_num, "
        "expected 2, is %" PRId64,
        (int64_t)
            last_msg.msg.ssr_orbit_clock_bounds_degradation.header.seq_num);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.header.sol_id == 48,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.header.sol_id, "
        "expected 48, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation.header.sol_id);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.header.time.tow == 180,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.header.time.tow, "
        "expected 180, is %" PRId64,
        (int64_t)
            last_msg.msg.ssr_orbit_clock_bounds_degradation.header.time.tow);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.header.time.wn == 3,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.header.time.wn, "
        "expected 3, is %" PRId64,
        (int64_t)
            last_msg.msg.ssr_orbit_clock_bounds_degradation.header.time.wn);

    ck_assert_msg(last_msg.msg.ssr_orbit_clock_bounds_degradation.header
                          .update_interval == 3,
                  "incorrect value for "
                  "last_msg.msg.ssr_orbit_clock_bounds_degradation.header."
                  "update_interval, expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation
                      .header.update_interval);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation
                .orbit_clock_bounds_degradation.clock_bound_mu_dot == 194,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_"
        "degradation.clock_bound_mu_dot, expected 194, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation
            .orbit_clock_bounds_degradation.clock_bound_mu_dot);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation
                .orbit_clock_bounds_degradation.clock_bound_sig_dot == 193,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_"
        "degradation.clock_bound_sig_dot, expected 193, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation
            .orbit_clock_bounds_degradation.clock_bound_sig_dot);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation
                .orbit_clock_bounds_degradation.orb_along_bound_mu_dot == 199,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_"
        "degradation.orb_along_bound_mu_dot, expected 199, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation
            .orbit_clock_bounds_degradation.orb_along_bound_mu_dot);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation
                .orbit_clock_bounds_degradation.orb_along_bound_sig_dot == 196,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_"
        "degradation.orb_along_bound_sig_dot, expected 196, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation
            .orbit_clock_bounds_degradation.orb_along_bound_sig_dot);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation
                .orbit_clock_bounds_degradation.orb_cross_bound_mu_dot == 198,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_"
        "degradation.orb_cross_bound_mu_dot, expected 198, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation
            .orbit_clock_bounds_degradation.orb_cross_bound_mu_dot);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation
                .orbit_clock_bounds_degradation.orb_cross_bound_sig_dot == 195,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_"
        "degradation.orb_cross_bound_sig_dot, expected 195, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation
            .orbit_clock_bounds_degradation.orb_cross_bound_sig_dot);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation
                .orbit_clock_bounds_degradation.orb_radial_bound_mu_dot == 200,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_"
        "degradation.orb_radial_bound_mu_dot, expected 200, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation
            .orbit_clock_bounds_degradation.orb_radial_bound_mu_dot);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation
                .orbit_clock_bounds_degradation.orb_radial_bound_sig_dot == 197,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.orbit_clock_bounds_"
        "degradation.orb_radial_bound_sig_dot, expected 197, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation
            .orbit_clock_bounds_degradation.orb_radial_bound_sig_dot);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.sat_bitmask == 10,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.sat_bitmask, expected "
        "10, is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation.sat_bitmask);

    ck_assert_msg(
        last_msg.msg.ssr_orbit_clock_bounds_degradation.ssr_iod == 15,
        "incorrect value for "
        "last_msg.msg.ssr_orbit_clock_bounds_degradation.ssr_iod, expected 15, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ssr_orbit_clock_bounds_degradation.ssr_iod);
  }
}
END_TEST

Suite *auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation");
  tcase_add_test(tc_acq,
                 test_auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradation);
  suite_add_tcase(s, tc_acq);
  return s;
}
