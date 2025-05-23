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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgtrackingStateDepA.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/tracking.h>
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

START_TEST(test_auto_check_sbp_tracking_MsgtrackingStateDepA) {
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

    sbp_callback_register(&sbp_state, 0x16, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  22,  0,   195, 4,  66,  1,   0,   204, 177, 51,  65,  1,
        2,   198, 4,   39,  65, 1,   3,   219, 182, 27,  65,  1,   7,
        132, 120, 101, 65,  1,  10,  91,  91,  251, 64,  1,   13,  42,
        37,  163, 64,  1,   22, 130, 184, 215, 64,  1,   30,  115, 53,
        75,  65,  1,   31,  16, 74,  126, 65,  1,   25,  132, 196, 135,
        64,  1,   6,   100, 59, 223, 64,  17,  225,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_a.n_states = 11;

    test_msg.tracking_state_dep_a.states[0].cn0 = 11.230907440185547;

    test_msg.tracking_state_dep_a.states[0].prn = 0;

    test_msg.tracking_state_dep_a.states[0].state = 1;

    test_msg.tracking_state_dep_a.states[1].cn0 = 10.438665390014648;

    test_msg.tracking_state_dep_a.states[1].prn = 2;

    test_msg.tracking_state_dep_a.states[1].state = 1;

    test_msg.tracking_state_dep_a.states[2].cn0 = 9.732142448425293;

    test_msg.tracking_state_dep_a.states[2].prn = 3;

    test_msg.tracking_state_dep_a.states[2].state = 1;

    test_msg.tracking_state_dep_a.states[3].cn0 = 14.341922760009766;

    test_msg.tracking_state_dep_a.states[3].prn = 7;

    test_msg.tracking_state_dep_a.states[3].state = 1;

    test_msg.tracking_state_dep_a.states[4].cn0 = 7.8549017906188965;

    test_msg.tracking_state_dep_a.states[4].prn = 10;

    test_msg.tracking_state_dep_a.states[4].state = 1;

    test_msg.tracking_state_dep_a.states[5].cn0 = 5.0982866287231445;

    test_msg.tracking_state_dep_a.states[5].prn = 13;

    test_msg.tracking_state_dep_a.states[5].state = 1;

    test_msg.tracking_state_dep_a.states[6].cn0 = 6.741272926330566;

    test_msg.tracking_state_dep_a.states[6].prn = 22;

    test_msg.tracking_state_dep_a.states[6].state = 1;

    test_msg.tracking_state_dep_a.states[7].cn0 = 12.700549125671387;

    test_msg.tracking_state_dep_a.states[7].prn = 30;

    test_msg.tracking_state_dep_a.states[7].state = 1;

    test_msg.tracking_state_dep_a.states[8].cn0 = 15.893081665039062;

    test_msg.tracking_state_dep_a.states[8].prn = 31;

    test_msg.tracking_state_dep_a.states[8].state = 1;

    test_msg.tracking_state_dep_a.states[9].cn0 = 4.242738723754883;

    test_msg.tracking_state_dep_a.states[9].prn = 25;

    test_msg.tracking_state_dep_a.states[9].state = 1;

    test_msg.tracking_state_dep_a.states[10].cn0 = 6.97599983215332;

    test_msg.tracking_state_dep_a.states[10].prn = 6;

    test_msg.tracking_state_dep_a.states[10].state = 1;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgTrackingStateDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.n_states == 11,
        "incorrect value for last_msg.msg.tracking_state_dep_a.n_states, "
        "expected 11, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.n_states);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[0].cn0 * 100 -
         11.2309074402 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].cn0, "
        "expected 11.2309074402, is %f",
        last_msg.msg.tracking_state_dep_a.states[0].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[0].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[0].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[0].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[0].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[0].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[1].cn0 * 100 -
         10.43866539 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].cn0, "
        "expected 10.43866539, is %f",
        last_msg.msg.tracking_state_dep_a.states[1].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[1].prn == 2,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].prn, "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[1].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[1].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[1].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[1].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[2].cn0 * 100 -
         9.73214244843 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].cn0, "
        "expected 9.73214244843, is %f",
        last_msg.msg.tracking_state_dep_a.states[2].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[2].prn == 3,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].prn, "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[2].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[2].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[2].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[2].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[3].cn0 * 100 -
         14.34192276 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].cn0, "
        "expected 14.34192276, is %f",
        last_msg.msg.tracking_state_dep_a.states[3].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[3].prn == 7,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].prn, "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[3].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[3].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[3].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[3].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[4].cn0 * 100 -
         7.85490179062 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].cn0, "
        "expected 7.85490179062, is %f",
        last_msg.msg.tracking_state_dep_a.states[4].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[4].prn == 10,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].prn, "
        "expected 10, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[4].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[4].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[4].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[4].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[5].cn0 * 100 -
         5.09828662872 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].cn0, "
        "expected 5.09828662872, is %f",
        last_msg.msg.tracking_state_dep_a.states[5].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[5].prn == 13,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].prn, "
        "expected 13, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[5].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[5].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[5].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[5].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[6].cn0 * 100 -
         6.74127292633 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].cn0, "
        "expected 6.74127292633, is %f",
        last_msg.msg.tracking_state_dep_a.states[6].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[6].prn == 22,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].prn, "
        "expected 22, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[6].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[6].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[6].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[6].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[7].cn0 * 100 -
         12.7005491257 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].cn0, "
        "expected 12.7005491257, is %f",
        last_msg.msg.tracking_state_dep_a.states[7].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[7].prn == 30,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].prn, "
        "expected 30, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[7].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[7].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[7].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[7].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[8].cn0 * 100 -
         15.893081665 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].cn0, "
        "expected 15.893081665, is %f",
        last_msg.msg.tracking_state_dep_a.states[8].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[8].prn == 31,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].prn, "
        "expected 31, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[8].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[8].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[8].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[8].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[9].cn0 * 100 -
         4.24273872375 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].cn0, "
        "expected 4.24273872375, is %f",
        last_msg.msg.tracking_state_dep_a.states[9].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[9].prn == 25,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].prn, "
        "expected 25, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[9].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[9].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[9].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[9].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[10].cn0 * 100 -
         6.97599983215 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].cn0, "
        "expected 6.97599983215, is %f",
        last_msg.msg.tracking_state_dep_a.states[10].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[10].prn == 6,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].prn, "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[10].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[10].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[10].state, "
                  "expected 1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[10].state);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x16, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 22,  0,  195, 4,   66,  1,   0,  216, 57,  48,  65,  1,   2,   145,
        41, 46,  65, 1,   3,   4,   26,  34, 65,  1,   7,   177, 67,  109, 65,
        1,  10,  61, 80,  249, 64,  1,   13, 250, 199, 155, 64,  1,   22,  55,
        19, 215, 64, 1,   30,  138, 138, 79, 65,  1,   31,  214, 179, 119, 65,
        1,  25,  53, 138, 120, 64,  1,   6,  183, 247, 129, 64,  168, 173,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_a.n_states = 11;

    test_msg.tracking_state_dep_a.states[0].cn0 = 11.014122009277344;

    test_msg.tracking_state_dep_a.states[0].prn = 0;

    test_msg.tracking_state_dep_a.states[0].state = 1;

    test_msg.tracking_state_dep_a.states[1].cn0 = 10.885148048400879;

    test_msg.tracking_state_dep_a.states[1].prn = 2;

    test_msg.tracking_state_dep_a.states[1].state = 1;

    test_msg.tracking_state_dep_a.states[2].cn0 = 10.131351470947266;

    test_msg.tracking_state_dep_a.states[2].prn = 3;

    test_msg.tracking_state_dep_a.states[2].state = 1;

    test_msg.tracking_state_dep_a.states[3].cn0 = 14.829026222229004;

    test_msg.tracking_state_dep_a.states[3].prn = 7;

    test_msg.tracking_state_dep_a.states[3].state = 1;

    test_msg.tracking_state_dep_a.states[4].cn0 = 7.79104471206665;

    test_msg.tracking_state_dep_a.states[4].prn = 10;

    test_msg.tracking_state_dep_a.states[4].state = 1;

    test_msg.tracking_state_dep_a.states[5].cn0 = 4.868161201477051;

    test_msg.tracking_state_dep_a.states[5].prn = 13;

    test_msg.tracking_state_dep_a.states[5].state = 1;

    test_msg.tracking_state_dep_a.states[6].cn0 = 6.721095561981201;

    test_msg.tracking_state_dep_a.states[6].prn = 22;

    test_msg.tracking_state_dep_a.states[6].state = 1;

    test_msg.tracking_state_dep_a.states[7].cn0 = 12.971323013305664;

    test_msg.tracking_state_dep_a.states[7].prn = 30;

    test_msg.tracking_state_dep_a.states[7].state = 1;

    test_msg.tracking_state_dep_a.states[8].cn0 = 15.481405258178711;

    test_msg.tracking_state_dep_a.states[8].prn = 31;

    test_msg.tracking_state_dep_a.states[8].state = 1;

    test_msg.tracking_state_dep_a.states[9].cn0 = 3.8834354877471924;

    test_msg.tracking_state_dep_a.states[9].prn = 25;

    test_msg.tracking_state_dep_a.states[9].state = 1;

    test_msg.tracking_state_dep_a.states[10].cn0 = 4.061488628387451;

    test_msg.tracking_state_dep_a.states[10].prn = 6;

    test_msg.tracking_state_dep_a.states[10].state = 1;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgTrackingStateDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.n_states == 11,
        "incorrect value for last_msg.msg.tracking_state_dep_a.n_states, "
        "expected 11, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.n_states);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[0].cn0 * 100 -
         11.0141220093 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].cn0, "
        "expected 11.0141220093, is %f",
        last_msg.msg.tracking_state_dep_a.states[0].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[0].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[0].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[0].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[0].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[0].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[1].cn0 * 100 -
         10.8851480484 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].cn0, "
        "expected 10.8851480484, is %f",
        last_msg.msg.tracking_state_dep_a.states[1].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[1].prn == 2,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].prn, "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[1].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[1].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[1].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[1].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[2].cn0 * 100 -
         10.1313514709 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].cn0, "
        "expected 10.1313514709, is %f",
        last_msg.msg.tracking_state_dep_a.states[2].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[2].prn == 3,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].prn, "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[2].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[2].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[2].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[2].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[3].cn0 * 100 -
         14.8290262222 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].cn0, "
        "expected 14.8290262222, is %f",
        last_msg.msg.tracking_state_dep_a.states[3].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[3].prn == 7,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].prn, "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[3].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[3].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[3].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[3].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[4].cn0 * 100 -
         7.79104471207 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].cn0, "
        "expected 7.79104471207, is %f",
        last_msg.msg.tracking_state_dep_a.states[4].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[4].prn == 10,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].prn, "
        "expected 10, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[4].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[4].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[4].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[4].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[5].cn0 * 100 -
         4.86816120148 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].cn0, "
        "expected 4.86816120148, is %f",
        last_msg.msg.tracking_state_dep_a.states[5].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[5].prn == 13,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].prn, "
        "expected 13, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[5].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[5].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[5].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[5].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[6].cn0 * 100 -
         6.72109556198 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].cn0, "
        "expected 6.72109556198, is %f",
        last_msg.msg.tracking_state_dep_a.states[6].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[6].prn == 22,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].prn, "
        "expected 22, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[6].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[6].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[6].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[6].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[7].cn0 * 100 -
         12.9713230133 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].cn0, "
        "expected 12.9713230133, is %f",
        last_msg.msg.tracking_state_dep_a.states[7].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[7].prn == 30,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].prn, "
        "expected 30, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[7].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[7].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[7].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[7].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[8].cn0 * 100 -
         15.4814052582 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].cn0, "
        "expected 15.4814052582, is %f",
        last_msg.msg.tracking_state_dep_a.states[8].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[8].prn == 31,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].prn, "
        "expected 31, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[8].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[8].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[8].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[8].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[9].cn0 * 100 -
         3.88343548775 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].cn0, "
        "expected 3.88343548775, is %f",
        last_msg.msg.tracking_state_dep_a.states[9].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[9].prn == 25,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].prn, "
        "expected 25, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[9].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[9].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[9].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[9].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[10].cn0 * 100 -
         4.06148862839 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].cn0, "
        "expected 4.06148862839, is %f",
        last_msg.msg.tracking_state_dep_a.states[10].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[10].prn == 6,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].prn, "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[10].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[10].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[10].state, "
                  "expected 1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[10].state);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x16, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  22,  0,   195, 4,   66,  1,   0,  141, 76,  60,  65,  1,   2,   69,
        139, 46,  65,  1,   3,   146, 27,  30, 65,  1,   7,   235, 56,  97,  65,
        1,   10,  141, 213, 243, 64,  1,   13, 250, 170, 166, 64,  1,   22,  17,
        101, 201, 64,  1,   30,  172, 183, 83, 65,  1,   31,  238, 193, 120, 65,
        1,   25,  220, 48,  132, 64,  1,   6,  49,  214, 54,  64,  110, 179,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_a.n_states = 11;

    test_msg.tracking_state_dep_a.states[0].cn0 = 11.768689155578613;

    test_msg.tracking_state_dep_a.states[0].prn = 0;

    test_msg.tracking_state_dep_a.states[0].state = 1;

    test_msg.tracking_state_dep_a.states[1].cn0 = 10.909001350402832;

    test_msg.tracking_state_dep_a.states[1].prn = 2;

    test_msg.tracking_state_dep_a.states[1].state = 1;

    test_msg.tracking_state_dep_a.states[2].cn0 = 9.881731033325195;

    test_msg.tracking_state_dep_a.states[2].prn = 3;

    test_msg.tracking_state_dep_a.states[2].state = 1;

    test_msg.tracking_state_dep_a.states[3].cn0 = 14.076395988464355;

    test_msg.tracking_state_dep_a.states[3].prn = 7;

    test_msg.tracking_state_dep_a.states[3].state = 1;

    test_msg.tracking_state_dep_a.states[4].cn0 = 7.619818210601807;

    test_msg.tracking_state_dep_a.states[4].prn = 10;

    test_msg.tracking_state_dep_a.states[4].state = 1;

    test_msg.tracking_state_dep_a.states[5].cn0 = 5.208371162414551;

    test_msg.tracking_state_dep_a.states[5].prn = 13;

    test_msg.tracking_state_dep_a.states[5].state = 1;

    test_msg.tracking_state_dep_a.states[6].cn0 = 6.2935872077941895;

    test_msg.tracking_state_dep_a.states[6].prn = 22;

    test_msg.tracking_state_dep_a.states[6].state = 1;

    test_msg.tracking_state_dep_a.states[7].cn0 = 13.232341766357422;

    test_msg.tracking_state_dep_a.states[7].prn = 30;

    test_msg.tracking_state_dep_a.states[7].state = 1;

    test_msg.tracking_state_dep_a.states[8].cn0 = 15.547346115112305;

    test_msg.tracking_state_dep_a.states[8].prn = 31;

    test_msg.tracking_state_dep_a.states[8].state = 1;

    test_msg.tracking_state_dep_a.states[9].cn0 = 4.130964279174805;

    test_msg.tracking_state_dep_a.states[9].prn = 25;

    test_msg.tracking_state_dep_a.states[9].state = 1;

    test_msg.tracking_state_dep_a.states[10].cn0 = 2.856823205947876;

    test_msg.tracking_state_dep_a.states[10].prn = 6;

    test_msg.tracking_state_dep_a.states[10].state = 1;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgTrackingStateDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.n_states == 11,
        "incorrect value for last_msg.msg.tracking_state_dep_a.n_states, "
        "expected 11, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.n_states);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[0].cn0 * 100 -
         11.7686891556 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].cn0, "
        "expected 11.7686891556, is %f",
        last_msg.msg.tracking_state_dep_a.states[0].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[0].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[0].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[0].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[0].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[0].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[1].cn0 * 100 -
         10.9090013504 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].cn0, "
        "expected 10.9090013504, is %f",
        last_msg.msg.tracking_state_dep_a.states[1].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[1].prn == 2,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].prn, "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[1].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[1].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[1].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[1].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[2].cn0 * 100 -
         9.88173103333 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].cn0, "
        "expected 9.88173103333, is %f",
        last_msg.msg.tracking_state_dep_a.states[2].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[2].prn == 3,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].prn, "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[2].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[2].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[2].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[2].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[3].cn0 * 100 -
         14.0763959885 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].cn0, "
        "expected 14.0763959885, is %f",
        last_msg.msg.tracking_state_dep_a.states[3].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[3].prn == 7,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].prn, "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[3].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[3].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[3].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[3].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[4].cn0 * 100 -
         7.6198182106 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].cn0, "
        "expected 7.6198182106, is %f",
        last_msg.msg.tracking_state_dep_a.states[4].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[4].prn == 10,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].prn, "
        "expected 10, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[4].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[4].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[4].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[4].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[5].cn0 * 100 -
         5.20837116241 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].cn0, "
        "expected 5.20837116241, is %f",
        last_msg.msg.tracking_state_dep_a.states[5].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[5].prn == 13,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].prn, "
        "expected 13, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[5].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[5].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[5].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[5].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[6].cn0 * 100 -
         6.29358720779 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].cn0, "
        "expected 6.29358720779, is %f",
        last_msg.msg.tracking_state_dep_a.states[6].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[6].prn == 22,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].prn, "
        "expected 22, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[6].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[6].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[6].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[6].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[7].cn0 * 100 -
         13.2323417664 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].cn0, "
        "expected 13.2323417664, is %f",
        last_msg.msg.tracking_state_dep_a.states[7].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[7].prn == 30,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].prn, "
        "expected 30, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[7].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[7].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[7].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[7].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[8].cn0 * 100 -
         15.5473461151 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].cn0, "
        "expected 15.5473461151, is %f",
        last_msg.msg.tracking_state_dep_a.states[8].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[8].prn == 31,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].prn, "
        "expected 31, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[8].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[8].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[8].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[8].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[9].cn0 * 100 -
         4.13096427917 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].cn0, "
        "expected 4.13096427917, is %f",
        last_msg.msg.tracking_state_dep_a.states[9].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[9].prn == 25,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].prn, "
        "expected 25, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[9].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[9].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[9].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[9].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[10].cn0 * 100 -
         2.85682320595 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].cn0, "
        "expected 2.85682320595, is %f",
        last_msg.msg.tracking_state_dep_a.states[10].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[10].prn == 6,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].prn, "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[10].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[10].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[10].state, "
                  "expected 1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[10].state);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x16, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 22,  0,   195, 4,   66,  1, 0,   55,  143, 120, 66,  0,   0,   0,
        0,  128, 191, 0,   0,   0,   0, 128, 191, 0,   0,   0,   0,   128, 191,
        0,  0,   0,   0,   128, 191, 0, 0,   0,   0,   128, 191, 0,   0,   0,
        0,  128, 191, 0,   0,   0,   0, 128, 191, 0,   0,   0,   0,   128, 191,
        0,  0,   0,   0,   128, 191, 0, 0,   0,   0,   128, 191, 248, 89,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_a.n_states = 11;

    test_msg.tracking_state_dep_a.states[0].cn0 = 62.13985824584961;

    test_msg.tracking_state_dep_a.states[0].prn = 0;

    test_msg.tracking_state_dep_a.states[0].state = 1;

    test_msg.tracking_state_dep_a.states[1].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[1].prn = 0;

    test_msg.tracking_state_dep_a.states[1].state = 0;

    test_msg.tracking_state_dep_a.states[2].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[2].prn = 0;

    test_msg.tracking_state_dep_a.states[2].state = 0;

    test_msg.tracking_state_dep_a.states[3].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[3].prn = 0;

    test_msg.tracking_state_dep_a.states[3].state = 0;

    test_msg.tracking_state_dep_a.states[4].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[4].prn = 0;

    test_msg.tracking_state_dep_a.states[4].state = 0;

    test_msg.tracking_state_dep_a.states[5].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[5].prn = 0;

    test_msg.tracking_state_dep_a.states[5].state = 0;

    test_msg.tracking_state_dep_a.states[6].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[6].prn = 0;

    test_msg.tracking_state_dep_a.states[6].state = 0;

    test_msg.tracking_state_dep_a.states[7].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[7].prn = 0;

    test_msg.tracking_state_dep_a.states[7].state = 0;

    test_msg.tracking_state_dep_a.states[8].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[8].prn = 0;

    test_msg.tracking_state_dep_a.states[8].state = 0;

    test_msg.tracking_state_dep_a.states[9].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[9].prn = 0;

    test_msg.tracking_state_dep_a.states[9].state = 0;

    test_msg.tracking_state_dep_a.states[10].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[10].prn = 0;

    test_msg.tracking_state_dep_a.states[10].state = 0;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgTrackingStateDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.n_states == 11,
        "incorrect value for last_msg.msg.tracking_state_dep_a.n_states, "
        "expected 11, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.n_states);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[0].cn0 * 100 -
         62.1398582458 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].cn0, "
        "expected 62.1398582458, is %f",
        last_msg.msg.tracking_state_dep_a.states[0].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[0].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[0].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[0].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[0].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[0].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[1].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[1].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[1].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[1].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[1].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[1].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[1].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[2].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[2].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[2].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[2].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[2].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[2].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[2].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[3].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[3].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[3].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[3].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[3].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[3].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[3].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[4].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[4].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[4].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[4].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[4].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[4].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[4].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[5].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[5].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[5].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[5].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[5].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[5].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[5].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[6].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[6].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[6].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[6].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[6].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[6].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[6].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[7].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[7].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[7].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[7].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[7].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[7].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[7].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[8].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[8].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[8].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[8].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[8].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[8].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[8].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[9].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[9].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[9].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[9].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[9].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[9].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[9].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[10].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[10].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[10].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[10].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[10].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[10].state, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[10].state);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x16, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 22,  0,   195, 4,   66,  1,   0,   218, 14, 19,  66,  1,  2,   210,
        3,  21,  65,  1,   3,   234, 214, 134, 65,  0,  0,   0,   0,  128, 191,
        0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 0,  0,   0,
        0,  128, 191, 0,   0,   0,   0,   128, 191, 0,  0,   0,   0,  128, 191,
        0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 84, 101,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_a.n_states = 11;

    test_msg.tracking_state_dep_a.states[0].cn0 = 36.764503479003906;

    test_msg.tracking_state_dep_a.states[0].prn = 0;

    test_msg.tracking_state_dep_a.states[0].state = 1;

    test_msg.tracking_state_dep_a.states[1].cn0 = 9.313432693481445;

    test_msg.tracking_state_dep_a.states[1].prn = 2;

    test_msg.tracking_state_dep_a.states[1].state = 1;

    test_msg.tracking_state_dep_a.states[2].cn0 = 16.854938507080078;

    test_msg.tracking_state_dep_a.states[2].prn = 3;

    test_msg.tracking_state_dep_a.states[2].state = 1;

    test_msg.tracking_state_dep_a.states[3].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[3].prn = 0;

    test_msg.tracking_state_dep_a.states[3].state = 0;

    test_msg.tracking_state_dep_a.states[4].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[4].prn = 0;

    test_msg.tracking_state_dep_a.states[4].state = 0;

    test_msg.tracking_state_dep_a.states[5].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[5].prn = 0;

    test_msg.tracking_state_dep_a.states[5].state = 0;

    test_msg.tracking_state_dep_a.states[6].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[6].prn = 0;

    test_msg.tracking_state_dep_a.states[6].state = 0;

    test_msg.tracking_state_dep_a.states[7].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[7].prn = 0;

    test_msg.tracking_state_dep_a.states[7].state = 0;

    test_msg.tracking_state_dep_a.states[8].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[8].prn = 0;

    test_msg.tracking_state_dep_a.states[8].state = 0;

    test_msg.tracking_state_dep_a.states[9].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[9].prn = 0;

    test_msg.tracking_state_dep_a.states[9].state = 0;

    test_msg.tracking_state_dep_a.states[10].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[10].prn = 0;

    test_msg.tracking_state_dep_a.states[10].state = 0;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgTrackingStateDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.n_states == 11,
        "incorrect value for last_msg.msg.tracking_state_dep_a.n_states, "
        "expected 11, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.n_states);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[0].cn0 * 100 -
         36.764503479 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].cn0, "
        "expected 36.764503479, is %f",
        last_msg.msg.tracking_state_dep_a.states[0].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[0].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[0].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[0].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[0].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[0].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[1].cn0 * 100 -
         9.31343269348 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].cn0, "
        "expected 9.31343269348, is %f",
        last_msg.msg.tracking_state_dep_a.states[1].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[1].prn == 2,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].prn, "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[1].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[1].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[1].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[1].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[2].cn0 * 100 -
         16.8549385071 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].cn0, "
        "expected 16.8549385071, is %f",
        last_msg.msg.tracking_state_dep_a.states[2].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[2].prn == 3,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].prn, "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[2].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[2].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[2].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[2].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[3].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[3].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[3].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[3].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[3].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[3].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[3].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[4].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[4].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[4].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[4].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[4].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[4].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[4].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[5].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[5].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[5].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[5].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[5].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[5].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[5].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[6].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[6].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[6].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[6].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[6].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[6].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[6].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[7].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[7].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[7].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[7].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[7].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[7].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[7].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[8].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[8].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[8].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[8].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[8].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[8].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[8].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[9].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[9].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[9].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[9].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[9].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[9].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[9].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[10].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[10].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[10].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[10].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[10].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[10].state, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[10].state);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x16, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 22,  0,   195, 4,   66,  1,   0,   98,  39, 219, 65,  1,  2,   0,
        0,  56,  64,  1,   3,   121, 123, 7,   65,  0,  0,   0,   0,  128, 191,
        0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 0,  0,   0,
        0,  128, 191, 0,   0,   0,   0,   128, 191, 0,  0,   0,   0,  128, 191,
        0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 37, 123,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_a.n_states = 11;

    test_msg.tracking_state_dep_a.states[0].cn0 = 27.394229888916016;

    test_msg.tracking_state_dep_a.states[0].prn = 0;

    test_msg.tracking_state_dep_a.states[0].state = 1;

    test_msg.tracking_state_dep_a.states[1].cn0 = 2.875;

    test_msg.tracking_state_dep_a.states[1].prn = 2;

    test_msg.tracking_state_dep_a.states[1].state = 1;

    test_msg.tracking_state_dep_a.states[2].cn0 = 8.467644691467285;

    test_msg.tracking_state_dep_a.states[2].prn = 3;

    test_msg.tracking_state_dep_a.states[2].state = 1;

    test_msg.tracking_state_dep_a.states[3].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[3].prn = 0;

    test_msg.tracking_state_dep_a.states[3].state = 0;

    test_msg.tracking_state_dep_a.states[4].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[4].prn = 0;

    test_msg.tracking_state_dep_a.states[4].state = 0;

    test_msg.tracking_state_dep_a.states[5].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[5].prn = 0;

    test_msg.tracking_state_dep_a.states[5].state = 0;

    test_msg.tracking_state_dep_a.states[6].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[6].prn = 0;

    test_msg.tracking_state_dep_a.states[6].state = 0;

    test_msg.tracking_state_dep_a.states[7].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[7].prn = 0;

    test_msg.tracking_state_dep_a.states[7].state = 0;

    test_msg.tracking_state_dep_a.states[8].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[8].prn = 0;

    test_msg.tracking_state_dep_a.states[8].state = 0;

    test_msg.tracking_state_dep_a.states[9].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[9].prn = 0;

    test_msg.tracking_state_dep_a.states[9].state = 0;

    test_msg.tracking_state_dep_a.states[10].cn0 = -1.0;

    test_msg.tracking_state_dep_a.states[10].prn = 0;

    test_msg.tracking_state_dep_a.states[10].state = 0;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgTrackingStateDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.n_states == 11,
        "incorrect value for last_msg.msg.tracking_state_dep_a.n_states, "
        "expected 11, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.n_states);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[0].cn0 * 100 -
         27.3942298889 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].cn0, "
        "expected 27.3942298889, is %f",
        last_msg.msg.tracking_state_dep_a.states[0].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[0].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[0].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[0].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[0].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[0].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[0].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[1].cn0 * 100 - 2.875 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].cn0, "
        "expected 2.875, is %f",
        last_msg.msg.tracking_state_dep_a.states[1].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[1].prn == 2,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[1].prn, "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[1].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[1].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[1].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[1].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[2].cn0 * 100 -
         8.46764469147 * 100) < 0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].cn0, "
        "expected 8.46764469147, is %f",
        last_msg.msg.tracking_state_dep_a.states[2].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[2].prn == 3,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[2].prn, "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[2].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[2].state == 1,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[2].state, expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[2].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[3].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[3].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[3].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[3].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[3].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[3].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[3].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[3].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[4].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[4].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[4].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[4].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[4].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[4].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[4].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[4].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[5].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[5].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[5].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[5].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[5].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[5].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[5].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[5].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[6].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[6].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[6].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[6].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[6].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[6].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[6].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[6].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[7].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[7].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[7].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[7].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[7].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[7].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[7].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[7].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[8].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[8].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[8].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[8].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[8].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[8].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[8].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[8].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[9].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[9].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[9].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[9].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[9].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[9].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[9].state, expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[9].state);

    ck_assert_msg(
        (last_msg.msg.tracking_state_dep_a.states[10].cn0 * 100 - -1.0 * 100) <
            0.05,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].cn0, "
        "expected -1.0, is %f",
        last_msg.msg.tracking_state_dep_a.states[10].cn0);

    ck_assert_msg(
        last_msg.msg.tracking_state_dep_a.states[10].prn == 0,
        "incorrect value for last_msg.msg.tracking_state_dep_a.states[10].prn, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.tracking_state_dep_a.states[10].prn);

    ck_assert_msg(last_msg.msg.tracking_state_dep_a.states[10].state == 0,
                  "incorrect value for "
                  "last_msg.msg.tracking_state_dep_a.states[10].state, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.tracking_state_dep_a.states[10].state);
  }
}
END_TEST

Suite *auto_check_sbp_tracking_MsgtrackingStateDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_tracking_MsgtrackingStateDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_tracking_MsgtrackingStateDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_tracking_MsgtrackingStateDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}
