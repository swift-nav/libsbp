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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEF.yaml by generate.py.
// Do not modify by hand!

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

START_TEST(test_auto_check_sbp_navigation_MsgVelECEF) {
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

    sbp_callback_register(&sbp_state, 0x20d, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  13,  2,   211, 136, 20, 40, 244, 122, 19, 248, 255, 255, 255,
        251, 255, 255, 255, 10,  0,  0,  0,   0,   0,  14,  0,   181, 99,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef.accuracy = 0;

    test_msg.vel_ecef.flags = 0;

    test_msg.vel_ecef.n_sats = 14;

    test_msg.vel_ecef.tow = 326825000;

    test_msg.vel_ecef.x = -8;

    test_msg.vel_ecef.y = -5;

    test_msg.vel_ecef.z = 10;

    sbp_message_send(&sbp_state, SbpMsgVelEcef, 35027, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgVelEcef, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ecef.accuracy == 0,
        "incorrect value for last_msg.msg.vel_ecef.accuracy, expected 0, is %d",
        last_msg.msg.vel_ecef.accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ecef.flags == 0,
        "incorrect value for last_msg.msg.vel_ecef.flags, expected 0, is %d",
        last_msg.msg.vel_ecef.flags);

    ck_assert_msg(
        last_msg.msg.vel_ecef.n_sats == 14,
        "incorrect value for last_msg.msg.vel_ecef.n_sats, expected 14, is %d",
        last_msg.msg.vel_ecef.n_sats);

    ck_assert_msg(last_msg.msg.vel_ecef.tow == 326825000,
                  "incorrect value for last_msg.msg.vel_ecef.tow, expected "
                  "326825000, is %d",
                  last_msg.msg.vel_ecef.tow);

    ck_assert_msg(
        last_msg.msg.vel_ecef.x == -8,
        "incorrect value for last_msg.msg.vel_ecef.x, expected -8, is %d",
        last_msg.msg.vel_ecef.x);

    ck_assert_msg(
        last_msg.msg.vel_ecef.y == -5,
        "incorrect value for last_msg.msg.vel_ecef.y, expected -5, is %d",
        last_msg.msg.vel_ecef.y);

    ck_assert_msg(
        last_msg.msg.vel_ecef.z == 10,
        "incorrect value for last_msg.msg.vel_ecef.z, expected 10, is %d",
        last_msg.msg.vel_ecef.z);
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

    sbp_callback_register(&sbp_state, 0x20d, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  13,  2,   211, 136, 20, 28, 246, 122, 19, 244, 255, 255, 255,
        238, 255, 255, 255, 11,  0,  0,  0,   0,   0,  15,  0,   215, 120,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef.accuracy = 0;

    test_msg.vel_ecef.flags = 0;

    test_msg.vel_ecef.n_sats = 15;

    test_msg.vel_ecef.tow = 326825500;

    test_msg.vel_ecef.x = -12;

    test_msg.vel_ecef.y = -18;

    test_msg.vel_ecef.z = 11;

    sbp_message_send(&sbp_state, SbpMsgVelEcef, 35027, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgVelEcef, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ecef.accuracy == 0,
        "incorrect value for last_msg.msg.vel_ecef.accuracy, expected 0, is %d",
        last_msg.msg.vel_ecef.accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ecef.flags == 0,
        "incorrect value for last_msg.msg.vel_ecef.flags, expected 0, is %d",
        last_msg.msg.vel_ecef.flags);

    ck_assert_msg(
        last_msg.msg.vel_ecef.n_sats == 15,
        "incorrect value for last_msg.msg.vel_ecef.n_sats, expected 15, is %d",
        last_msg.msg.vel_ecef.n_sats);

    ck_assert_msg(last_msg.msg.vel_ecef.tow == 326825500,
                  "incorrect value for last_msg.msg.vel_ecef.tow, expected "
                  "326825500, is %d",
                  last_msg.msg.vel_ecef.tow);

    ck_assert_msg(
        last_msg.msg.vel_ecef.x == -12,
        "incorrect value for last_msg.msg.vel_ecef.x, expected -12, is %d",
        last_msg.msg.vel_ecef.x);

    ck_assert_msg(
        last_msg.msg.vel_ecef.y == -18,
        "incorrect value for last_msg.msg.vel_ecef.y, expected -18, is %d",
        last_msg.msg.vel_ecef.y);

    ck_assert_msg(
        last_msg.msg.vel_ecef.z == 11,
        "incorrect value for last_msg.msg.vel_ecef.z, expected 11, is %d",
        last_msg.msg.vel_ecef.z);
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

    sbp_callback_register(&sbp_state, 0x20d, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  13,  2,   211, 136, 20, 16, 248, 122, 19, 248, 255, 255, 255,
        250, 255, 255, 255, 7,   0,  0,  0,   0,   0,  15,  0,   248, 221,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef.accuracy = 0;

    test_msg.vel_ecef.flags = 0;

    test_msg.vel_ecef.n_sats = 15;

    test_msg.vel_ecef.tow = 326826000;

    test_msg.vel_ecef.x = -8;

    test_msg.vel_ecef.y = -6;

    test_msg.vel_ecef.z = 7;

    sbp_message_send(&sbp_state, SbpMsgVelEcef, 35027, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgVelEcef, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ecef.accuracy == 0,
        "incorrect value for last_msg.msg.vel_ecef.accuracy, expected 0, is %d",
        last_msg.msg.vel_ecef.accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ecef.flags == 0,
        "incorrect value for last_msg.msg.vel_ecef.flags, expected 0, is %d",
        last_msg.msg.vel_ecef.flags);

    ck_assert_msg(
        last_msg.msg.vel_ecef.n_sats == 15,
        "incorrect value for last_msg.msg.vel_ecef.n_sats, expected 15, is %d",
        last_msg.msg.vel_ecef.n_sats);

    ck_assert_msg(last_msg.msg.vel_ecef.tow == 326826000,
                  "incorrect value for last_msg.msg.vel_ecef.tow, expected "
                  "326826000, is %d",
                  last_msg.msg.vel_ecef.tow);

    ck_assert_msg(
        last_msg.msg.vel_ecef.x == -8,
        "incorrect value for last_msg.msg.vel_ecef.x, expected -8, is %d",
        last_msg.msg.vel_ecef.x);

    ck_assert_msg(
        last_msg.msg.vel_ecef.y == -6,
        "incorrect value for last_msg.msg.vel_ecef.y, expected -6, is %d",
        last_msg.msg.vel_ecef.y);

    ck_assert_msg(
        last_msg.msg.vel_ecef.z == 7,
        "incorrect value for last_msg.msg.vel_ecef.z, expected 7, is %d",
        last_msg.msg.vel_ecef.z);
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

    sbp_callback_register(&sbp_state, 0x20d, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  13,  2,   211, 136, 20, 4, 250, 122, 19, 249, 255, 255, 255,
        239, 255, 255, 255, 16,  0,  0, 0,   0,   0,  15,  0,   1,   167,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef.accuracy = 0;

    test_msg.vel_ecef.flags = 0;

    test_msg.vel_ecef.n_sats = 15;

    test_msg.vel_ecef.tow = 326826500;

    test_msg.vel_ecef.x = -7;

    test_msg.vel_ecef.y = -17;

    test_msg.vel_ecef.z = 16;

    sbp_message_send(&sbp_state, SbpMsgVelEcef, 35027, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgVelEcef, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ecef.accuracy == 0,
        "incorrect value for last_msg.msg.vel_ecef.accuracy, expected 0, is %d",
        last_msg.msg.vel_ecef.accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ecef.flags == 0,
        "incorrect value for last_msg.msg.vel_ecef.flags, expected 0, is %d",
        last_msg.msg.vel_ecef.flags);

    ck_assert_msg(
        last_msg.msg.vel_ecef.n_sats == 15,
        "incorrect value for last_msg.msg.vel_ecef.n_sats, expected 15, is %d",
        last_msg.msg.vel_ecef.n_sats);

    ck_assert_msg(last_msg.msg.vel_ecef.tow == 326826500,
                  "incorrect value for last_msg.msg.vel_ecef.tow, expected "
                  "326826500, is %d",
                  last_msg.msg.vel_ecef.tow);

    ck_assert_msg(
        last_msg.msg.vel_ecef.x == -7,
        "incorrect value for last_msg.msg.vel_ecef.x, expected -7, is %d",
        last_msg.msg.vel_ecef.x);

    ck_assert_msg(
        last_msg.msg.vel_ecef.y == -17,
        "incorrect value for last_msg.msg.vel_ecef.y, expected -17, is %d",
        last_msg.msg.vel_ecef.y);

    ck_assert_msg(
        last_msg.msg.vel_ecef.z == 16,
        "incorrect value for last_msg.msg.vel_ecef.z, expected 16, is %d",
        last_msg.msg.vel_ecef.z);
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

    sbp_callback_register(&sbp_state, 0x20d, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  13,  2,   211, 136, 20, 248, 251, 122, 19, 247, 255, 255, 255,
        243, 255, 255, 255, 14,  0,  0,   0,   0,   0,  15,  0,   191, 43,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef.accuracy = 0;

    test_msg.vel_ecef.flags = 0;

    test_msg.vel_ecef.n_sats = 15;

    test_msg.vel_ecef.tow = 326827000;

    test_msg.vel_ecef.x = -9;

    test_msg.vel_ecef.y = -13;

    test_msg.vel_ecef.z = 14;

    sbp_message_send(&sbp_state, SbpMsgVelEcef, 35027, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgVelEcef, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_ecef.accuracy == 0,
        "incorrect value for last_msg.msg.vel_ecef.accuracy, expected 0, is %d",
        last_msg.msg.vel_ecef.accuracy);

    ck_assert_msg(
        last_msg.msg.vel_ecef.flags == 0,
        "incorrect value for last_msg.msg.vel_ecef.flags, expected 0, is %d",
        last_msg.msg.vel_ecef.flags);

    ck_assert_msg(
        last_msg.msg.vel_ecef.n_sats == 15,
        "incorrect value for last_msg.msg.vel_ecef.n_sats, expected 15, is %d",
        last_msg.msg.vel_ecef.n_sats);

    ck_assert_msg(last_msg.msg.vel_ecef.tow == 326827000,
                  "incorrect value for last_msg.msg.vel_ecef.tow, expected "
                  "326827000, is %d",
                  last_msg.msg.vel_ecef.tow);

    ck_assert_msg(
        last_msg.msg.vel_ecef.x == -9,
        "incorrect value for last_msg.msg.vel_ecef.x, expected -9, is %d",
        last_msg.msg.vel_ecef.x);

    ck_assert_msg(
        last_msg.msg.vel_ecef.y == -13,
        "incorrect value for last_msg.msg.vel_ecef.y, expected -13, is %d",
        last_msg.msg.vel_ecef.y);

    ck_assert_msg(
        last_msg.msg.vel_ecef.z == 14,
        "incorrect value for last_msg.msg.vel_ecef.z, expected 14, is %d",
        last_msg.msg.vel_ecef.z);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgVelECEF_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgVelECEF");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgVelECEF");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgVelECEF);
  suite_add_tcase(s, tc_acq);
  return s;
}