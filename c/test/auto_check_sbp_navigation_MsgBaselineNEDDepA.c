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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNEDDepA.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/navigation.h>
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

START_TEST(test_auto_check_sbp_navigation_MsgBaselineNEDDepA) {
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  3,   2,   246, 215, 22, 20, 46, 39, 0, 243, 134, 254, 255, 234,
        153, 255, 255, 0,   0,   0,  0,  0,  0,  0, 0,   9,   1,   93,  193,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = 0;

    test_msg.baseline_ned_dep_a.e = -26134;

    test_msg.baseline_ned_dep_a.flags = 1;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = -96525;

    test_msg.baseline_ned_dep_a.n_sats = 9;

    test_msg.baseline_ned_dep_a.tow = 2567700;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == -26134,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected -26134, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 1,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 1, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == -96525,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected -96525, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 2567700,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 2567700, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  3,   2,   246, 215, 22, 120, 46, 39, 0, 139, 134, 254, 255, 109,
        155, 255, 255, 0,   0,   0,  0,   0,  0,  0, 0,   9,   1,   38,  39,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = 0;

    test_msg.baseline_ned_dep_a.e = -25747;

    test_msg.baseline_ned_dep_a.flags = 1;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = -96629;

    test_msg.baseline_ned_dep_a.n_sats = 9;

    test_msg.baseline_ned_dep_a.tow = 2567800;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == -25747,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected -25747, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 1,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 1, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == -96629,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected -96629, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 2567800,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 2567800, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  3,   2,   246, 215, 22, 220, 46, 39, 0, 37, 134, 254, 255, 240,
        156, 255, 255, 0,   0,   0,  0,   0,  0,  0, 0,  9,   1,   58,  133,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = 0;

    test_msg.baseline_ned_dep_a.e = -25360;

    test_msg.baseline_ned_dep_a.flags = 1;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = -96731;

    test_msg.baseline_ned_dep_a.n_sats = 9;

    test_msg.baseline_ned_dep_a.tow = 2567900;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == -25360,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected -25360, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 1,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 1, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == -96731,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected -96731, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 2567900,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 2567900, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  3,   2,   246, 215, 22, 64, 47, 39, 0, 193, 133, 254, 255, 115,
        158, 255, 255, 0,   0,   0,  0,  0,  0,  0, 0,   9,   1,   56,  214,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = 0;

    test_msg.baseline_ned_dep_a.e = -24973;

    test_msg.baseline_ned_dep_a.flags = 1;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = -96831;

    test_msg.baseline_ned_dep_a.n_sats = 9;

    test_msg.baseline_ned_dep_a.tow = 2568000;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == -24973,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected -24973, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 1,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 1, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == -96831,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected -96831, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 2568000,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 2568000, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  3,   2,   246, 215, 22, 164, 47, 39, 0, 93, 133, 254, 255, 246,
        159, 255, 255, 0,   0,   0,  0,   0,  0,  0, 0,  9,   1,   234, 244,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = 0;

    test_msg.baseline_ned_dep_a.e = -24586;

    test_msg.baseline_ned_dep_a.flags = 1;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = -96931;

    test_msg.baseline_ned_dep_a.n_sats = 9;

    test_msg.baseline_ned_dep_a.tow = 2568100;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == -24586,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected -24586, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 1,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 1, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == -96931,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected -96931, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 2568100,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 2568100, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 3, 2, 195, 4,   22,  156, 21, 69, 24, 130, 246, 255, 255, 241,
        4,  0, 0, 35,  196, 255, 255, 0,  0,  0,  0,   6,   0,   250, 21,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = -15325;

    test_msg.baseline_ned_dep_a.e = 1265;

    test_msg.baseline_ned_dep_a.flags = 0;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = -2430;

    test_msg.baseline_ned_dep_a.n_sats = 6;

    test_msg.baseline_ned_dep_a.tow = 407180700;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == -15325,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected -15325, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == 1265,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected 1265, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == -2430,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected -2430, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 6,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 6, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 407180700,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 407180700, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 3, 2, 195, 4,   22,  0,   22, 69, 24, 130, 246, 255, 255, 241,
        4,  0, 0, 35,  196, 255, 255, 0,  0,  0,  0,   6,   0,   240, 133,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = -15325;

    test_msg.baseline_ned_dep_a.e = 1265;

    test_msg.baseline_ned_dep_a.flags = 0;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = -2430;

    test_msg.baseline_ned_dep_a.n_sats = 6;

    test_msg.baseline_ned_dep_a.tow = 407180800;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == -15325,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected -15325, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == 1265,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected 1265, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == -2430,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected -2430, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 6,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 6, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 407180800,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 407180800, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 3, 2, 195, 4,   22,  100, 22, 69, 24, 32, 251, 255, 255, 199,
        11, 0, 0, 57,  161, 255, 255, 0,  0,  0,  0,  6,   0,   12,  181,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = -24263;

    test_msg.baseline_ned_dep_a.e = 3015;

    test_msg.baseline_ned_dep_a.flags = 0;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = -1248;

    test_msg.baseline_ned_dep_a.n_sats = 6;

    test_msg.baseline_ned_dep_a.tow = 407180900;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == -24263,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected -24263, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == 3015,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected 3015, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == -1248,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected -1248, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 6,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 6, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 407180900,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 407180900, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 3, 2, 195, 4,   22,  200, 22, 69, 24, 33, 251, 255, 255, 199,
        11, 0, 0, 54,  161, 255, 255, 0,  0,  0,  0,  6,   0,   86,  58,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = -24266;

    test_msg.baseline_ned_dep_a.e = 3015;

    test_msg.baseline_ned_dep_a.flags = 0;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = -1247;

    test_msg.baseline_ned_dep_a.n_sats = 6;

    test_msg.baseline_ned_dep_a.tow = 407181000;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == -24266,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected -24266, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == 3015,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected 3015, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == -1247,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected -1247, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 6,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 6, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 407181000,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 407181000, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 3, 2, 195, 4,   22,  44,  23, 69, 24, 110, 6, 0, 0,  55,
        8,  0, 0, 160, 166, 255, 255, 0,  0,  0,  0,   6, 0, 51, 249,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = -22880;

    test_msg.baseline_ned_dep_a.e = 2103;

    test_msg.baseline_ned_dep_a.flags = 0;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = 1646;

    test_msg.baseline_ned_dep_a.n_sats = 6;

    test_msg.baseline_ned_dep_a.tow = 407181100;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == -22880,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected -22880, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == 2103,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected 2103, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == 1646,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected 1646, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 6,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 6, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 407181100,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 407181100, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x203, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 3, 2, 195, 4,   22,  144, 23, 69, 24, 110, 6, 0, 0,   54,
        8,  0, 0, 160, 166, 255, 255, 0,  0,  0,  0,   6, 0, 206, 22,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned_dep_a.d = -22880;

    test_msg.baseline_ned_dep_a.e = 2102;

    test_msg.baseline_ned_dep_a.flags = 0;

    test_msg.baseline_ned_dep_a.h_accuracy = 0;

    test_msg.baseline_ned_dep_a.n = 1646;

    test_msg.baseline_ned_dep_a.n_sats = 6;

    test_msg.baseline_ned_dep_a.tow = 407181200;

    test_msg.baseline_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNedDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgBaselineNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.d == -22880,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.d, "
                  "expected -22880, is %d",
                  last_msg.msg.baseline_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.e == 2102,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.e, "
                  "expected 2102, is %d",
                  last_msg.msg.baseline_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.baseline_ned_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.h_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.h_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n == 1646,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n, "
                  "expected 1646, is %d",
                  last_msg.msg.baseline_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.n_sats == 6,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.n_sats, "
                  "expected 6, is %d",
                  last_msg.msg.baseline_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.baseline_ned_dep_a.tow == 407181200,
                  "incorrect value for last_msg.msg.baseline_ned_dep_a.tow, "
                  "expected 407181200, is %d",
                  last_msg.msg.baseline_ned_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.baseline_ned_dep_a.v_accuracy == 0,
        "incorrect value for last_msg.msg.baseline_ned_dep_a.v_accuracy, "
        "expected 0, is %d",
        last_msg.msg.baseline_ned_dep_a.v_accuracy);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgBaselineNEDDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgBaselineNEDDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_navigation_MsgBaselineNEDDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgBaselineNEDDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}