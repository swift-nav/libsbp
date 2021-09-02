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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDDepA.yaml by
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

START_TEST(test_auto_check_sbp_navigation_MsgVelNEDDepA) {
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5, 2, 246, 215, 22, 20, 46, 39, 0, 198, 251, 255, 255, 156,
        15, 0, 0, 0,   0,   0,  0,  0,  0,  0, 0,   9,   0,   161, 92,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = 0;

    test_msg.vel_ned_dep_a.e = 3996;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = -1082;

    test_msg.vel_ned_dep_a.n_sats = 9;

    test_msg.vel_ned_dep_a.tow = 2567700;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.d == 0,
        "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected 0, is %d",
        last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.e == 3996,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected "
                  "3996, is %d",
                  last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n == -1082,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected "
                  "-1082, is %d",
                  last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 2567700,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 2567700, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5, 2, 246, 215, 22, 120, 46, 39, 0, 14, 252, 255, 255, 207,
        14, 0, 0, 0,   0,   0,  0,   0,  0,  0, 0,  9,   0,   125, 160,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = 0;

    test_msg.vel_ned_dep_a.e = 3791;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = -1010;

    test_msg.vel_ned_dep_a.n_sats = 9;

    test_msg.vel_ned_dep_a.tow = 2567800;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.d == 0,
        "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected 0, is %d",
        last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.e == 3791,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected "
                  "3791, is %d",
                  last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n == -1010,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected "
                  "-1010, is %d",
                  last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 2567800,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 2567800, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5, 2, 246, 215, 22, 220, 46, 39, 0, 48, 252, 255, 255, 140,
        14, 0, 0, 0,   0,   0,  0,   0,  0,  0, 0,  9,   0,   179, 135,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = 0;

    test_msg.vel_ned_dep_a.e = 3724;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = -976;

    test_msg.vel_ned_dep_a.n_sats = 9;

    test_msg.vel_ned_dep_a.tow = 2567900;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.d == 0,
        "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected 0, is %d",
        last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.e == 3724,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected "
                  "3724, is %d",
                  last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n == -976,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected "
                  "-976, is %d",
                  last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 2567900,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 2567900, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5, 2, 246, 215, 22, 64, 47, 39, 0, 32, 252, 255, 255, 8,
        15, 0, 0, 0,   0,   0,  0,  0,  0,  0, 0,  9,   0,   51,  177,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = 0;

    test_msg.vel_ned_dep_a.e = 3848;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = -992;

    test_msg.vel_ned_dep_a.n_sats = 9;

    test_msg.vel_ned_dep_a.tow = 2568000;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.d == 0,
        "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected 0, is %d",
        last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.e == 3848,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected "
                  "3848, is %d",
                  last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n == -992,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected "
                  "-992, is %d",
                  last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 2568000,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 2568000, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5, 2, 246, 215, 22, 164, 47, 39, 0, 80, 252, 255, 255, 140,
        14, 0, 0, 0,   0,   0,  0,   0,  0,  0, 0,  9,   0,   23,  0,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = 0;

    test_msg.vel_ned_dep_a.e = 3724;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = -944;

    test_msg.vel_ned_dep_a.n_sats = 9;

    test_msg.vel_ned_dep_a.tow = 2568100;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.d == 0,
        "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected 0, is %d",
        last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.e == 3724,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected "
                  "3724, is %d",
                  last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n == -944,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected "
                  "-944, is %d",
                  last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 2568100,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 2568100, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5, 2, 195, 4, 22, 212, 157, 67, 24, 229, 255, 255, 255, 26,
        0,  0, 0, 25,  0, 0,  0,   0,   0,  0,  0,   8,   0,   132, 25,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = 25;

    test_msg.vel_ned_dep_a.e = 26;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = -27;

    test_msg.vel_ned_dep_a.n_sats = 8;

    test_msg.vel_ned_dep_a.tow = 407084500;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.d == 25,
        "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected 25, is %d",
        last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.e == 26,
        "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected 26, is %d",
        last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.n == -27,
        "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected -27, is %d",
        last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 407084500,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 407084500, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5, 2, 195, 4,   22,  56,  158, 67, 24, 4, 0, 0, 0,  15,
        0,  0, 0, 232, 255, 255, 255, 0,   0,  0,  0, 8, 0, 42, 14,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = -24;

    test_msg.vel_ned_dep_a.e = 15;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = 4;

    test_msg.vel_ned_dep_a.n_sats = 8;

    test_msg.vel_ned_dep_a.tow = 407084600;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.d == -24,
        "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected -24, is %d",
        last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.e == 15,
        "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected 15, is %d",
        last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.n == 4,
        "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected 4, is %d",
        last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 407084600,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 407084600, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  5,   2,   195, 4,   22,  156, 158, 67, 24, 251, 255, 255, 255, 232,
        255, 255, 255, 247, 255, 255, 255, 0,   0,  0,  0,   8,   0,   218, 148,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = -9;

    test_msg.vel_ned_dep_a.e = -24;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = -5;

    test_msg.vel_ned_dep_a.n_sats = 8;

    test_msg.vel_ned_dep_a.tow = 407084700;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.d == -9,
        "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected -9, is %d",
        last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.e == -24,
        "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected -24, is %d",
        last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.n == -5,
        "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected -5, is %d",
        last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 407084700,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 407084700, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5, 2, 195, 4,   22,  0,   159, 67, 24, 10, 0, 0, 0,   2,
        0,  0, 0, 222, 255, 255, 255, 0,   0,  0,  0,  8, 0, 148, 16,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = -34;

    test_msg.vel_ned_dep_a.e = 2;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = 10;

    test_msg.vel_ned_dep_a.n_sats = 8;

    test_msg.vel_ned_dep_a.tow = 407084800;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.d == -34,
        "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected -34, is %d",
        last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.e == 2,
        "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected 2, is %d",
        last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.n == 10,
        "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected 10, is %d",
        last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 407084800,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 407084800, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  5,   2,   195, 4, 22, 100, 159, 67, 24, 248, 255, 255, 255, 254,
        255, 255, 255, 7,   0, 0,  0,   0,   0,  0,  0,   8,   0,   255, 236,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = 7;

    test_msg.vel_ned_dep_a.e = -2;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = -8;

    test_msg.vel_ned_dep_a.n_sats = 8;

    test_msg.vel_ned_dep_a.tow = 407084900;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.d == 7,
        "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected 7, is %d",
        last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.e == -2,
        "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected -2, is %d",
        last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.n == -8,
        "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected -8, is %d",
        last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 407084900,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 407084900, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x205, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  5,   2,   195, 4,   22,  46,  162, 68, 24, 255, 255, 255, 255, 253,
        255, 255, 255, 148, 255, 255, 255, 0,   0,  0,  0,   5,   0,   166, 189,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned_dep_a.d = -108;

    test_msg.vel_ned_dep_a.e = -3;

    test_msg.vel_ned_dep_a.flags = 0;

    test_msg.vel_ned_dep_a.h_accuracy = 0;

    test_msg.vel_ned_dep_a.n = -1;

    test_msg.vel_ned_dep_a.n_sats = 5;

    test_msg.vel_ned_dep_a.tow = 407151150;

    test_msg.vel_ned_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNedDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgVelNedDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.d == -108,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.d, expected "
                  "-108, is %d",
                  last_msg.msg.vel_ned_dep_a.d);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.e == -3,
        "incorrect value for last_msg.msg.vel_ned_dep_a.e, expected -3, is %d",
        last_msg.msg.vel_ned_dep_a.e);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.flags);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.h_accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ned_dep_a.n == -1,
        "incorrect value for last_msg.msg.vel_ned_dep_a.n, expected -1, is %d",
        last_msg.msg.vel_ned_dep_a.n);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.n_sats == 5,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.n_sats, "
                  "expected 5, is %d",
                  last_msg.msg.vel_ned_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.tow == 407151150,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.tow, "
                  "expected 407151150, is %d",
                  last_msg.msg.vel_ned_dep_a.tow);

    ck_assert_msg(last_msg.msg.vel_ned_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_ned_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_ned_dep_a.v_accuracy);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgVelNEDDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgVelNEDDepA");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgVelNEDDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgVelNEDDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}