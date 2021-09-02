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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeDepA.yaml by
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

START_TEST(test_auto_check_sbp_navigation_MsgGPSTimeDepA) {
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0, 1, 246, 215, 11, 251, 6, 120, 46, 39, 0, 0, 0, 0, 0, 0, 133, 36,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = 0;

    test_msg.gps_time_dep_a.tow = 2567800;

    test_msg.gps_time_dep_a.wn = 1787;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 55286, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.ns_residual == 0,
                  "incorrect value for "
                  "last_msg.msg.gps_time_dep_a.ns_residual, expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 2567800,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 2567800, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1787,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1787, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0, 1, 246, 215, 11, 251, 6, 220, 46, 39, 0, 0, 0, 0, 0, 0, 36, 160,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = 0;

    test_msg.gps_time_dep_a.tow = 2567900;

    test_msg.gps_time_dep_a.wn = 1787;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 55286, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.ns_residual == 0,
                  "incorrect value for "
                  "last_msg.msg.gps_time_dep_a.ns_residual, expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 2567900,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 2567900, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1787,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1787, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0, 1, 246, 215, 11, 251, 6, 64, 47, 39, 0, 0, 0, 0, 0, 0, 171, 190,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = 0;

    test_msg.gps_time_dep_a.tow = 2568000;

    test_msg.gps_time_dep_a.wn = 1787;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 55286, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.ns_residual == 0,
                  "incorrect value for "
                  "last_msg.msg.gps_time_dep_a.ns_residual, expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 2568000,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 2568000, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1787,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1787, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0, 1, 246, 215, 11, 251, 6, 164, 47, 39, 0, 0, 0, 0, 0, 0, 211, 101,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = 0;

    test_msg.gps_time_dep_a.tow = 2568100;

    test_msg.gps_time_dep_a.wn = 1787;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 55286, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.ns_residual == 0,
                  "incorrect value for "
                  "last_msg.msg.gps_time_dep_a.ns_residual, expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 2568100,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 2568100, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1787,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1787, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0, 1, 246, 215, 11, 251, 6, 8, 48, 39, 0, 0, 0, 0, 0, 0, 251, 44,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = 0;

    test_msg.gps_time_dep_a.tow = 2568200;

    test_msg.gps_time_dep_a.wn = 1787;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 55286, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.ns_residual == 0,
                  "incorrect value for "
                  "last_msg.msg.gps_time_dep_a.ns_residual, expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 2568200,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 2568200, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1787,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1787, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,  1,   195, 4,   11,  46, 7,   212, 157,
        67, 24, 111, 147, 252, 255, 0,  215, 190,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = -224401;

    test_msg.gps_time_dep_a.tow = 407084500;

    test_msg.gps_time_dep_a.wn = 1838;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.gps_time_dep_a.ns_residual == -224401,
        "incorrect value for last_msg.msg.gps_time_dep_a.ns_residual, expected "
        "-224401, is %d",
        last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 407084500,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 407084500, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1838,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,  1,   195, 4, 11, 46, 7,   56, 158,
        67, 24, 109, 103, 3, 0,  0,  134, 89,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = 223085;

    test_msg.gps_time_dep_a.tow = 407084600;

    test_msg.gps_time_dep_a.wn = 1838;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.gps_time_dep_a.ns_residual == 223085,
        "incorrect value for last_msg.msg.gps_time_dep_a.ns_residual, expected "
        "223085, is %d",
        last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 407084600,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 407084600, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1838,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,  1,   195, 4,   11,  46, 7,   156, 158,
        67, 24, 233, 152, 252, 255, 0,  206, 241,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = -222999;

    test_msg.gps_time_dep_a.tow = 407084700;

    test_msg.gps_time_dep_a.wn = 1838;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.gps_time_dep_a.ns_residual == -222999,
        "incorrect value for last_msg.msg.gps_time_dep_a.ns_residual, expected "
        "-222999, is %d",
        last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 407084700,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 407084700, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1838,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0, 1, 195, 4, 11, 46, 7, 0, 159, 67, 24, 240, 154, 3, 0, 0, 147, 98,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = 236272;

    test_msg.gps_time_dep_a.tow = 407084800;

    test_msg.gps_time_dep_a.wn = 1838;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.gps_time_dep_a.ns_residual == 236272,
        "incorrect value for last_msg.msg.gps_time_dep_a.ns_residual, expected "
        "236272, is %d",
        last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 407084800,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 407084800, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1838,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,  1,   195, 4,   11,  46, 7,   100, 159,
        67, 24, 144, 101, 252, 255, 0,  186, 152,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = -236144;

    test_msg.gps_time_dep_a.tow = 407084900;

    test_msg.gps_time_dep_a.wn = 1838;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.gps_time_dep_a.ns_residual == -236144,
        "incorrect value for last_msg.msg.gps_time_dep_a.ns_residual, expected "
        "-236144, is %d",
        last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 407084900,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 407084900, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1838,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
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

    sbp_callback_register(&sbp_state, 0x100, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,  1,   195, 4,   11,  46, 7,  46,  162,
        68, 24, 205, 230, 250, 255, 0,  11, 225,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_dep_a.flags = 0;

    test_msg.gps_time_dep_a.ns_residual = -334131;

    test_msg.gps_time_dep_a.tow = 407151150;

    test_msg.gps_time_dep_a.wn = 1838;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgGpsTimeDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_dep_a.flags);

    ck_assert_msg(
        last_msg.msg.gps_time_dep_a.ns_residual == -334131,
        "incorrect value for last_msg.msg.gps_time_dep_a.ns_residual, expected "
        "-334131, is %d",
        last_msg.msg.gps_time_dep_a.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.tow == 407151150,
                  "incorrect value for last_msg.msg.gps_time_dep_a.tow, "
                  "expected 407151150, is %d",
                  last_msg.msg.gps_time_dep_a.tow);

    ck_assert_msg(last_msg.msg.gps_time_dep_a.wn == 1838,
                  "incorrect value for last_msg.msg.gps_time_dep_a.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.gps_time_dep_a.wn);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgGPSTimeDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgGPSTimeDepA");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgGPSTimeDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgGPSTimeDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}