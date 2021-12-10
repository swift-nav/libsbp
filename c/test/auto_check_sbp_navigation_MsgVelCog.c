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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelCog.yaml by generate.py.
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

START_TEST(test_auto_check_sbp_navigation_MsgVelCog) {
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

    sbp_callback_register(&sbp_state, 0x21C, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  28,  2, 211, 136, 29,  48, 246, 122, 19,  232, 3, 0,
        0,   208, 7, 0,   0,   184, 11, 0,   0,   160, 15,  0, 0,
        136, 19,  0, 0,   112, 23,  0,  0,   62,  170, 74,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_cog.cog = 1000;

    test_msg.vel_cog.cog_accuracy = 4000;

    test_msg.vel_cog.flags = 62;

    test_msg.vel_cog.sog = 2000;

    test_msg.vel_cog.sog_accuracy = 5000;

    test_msg.vel_cog.tow = 326825520;

    test_msg.vel_cog.vel_d = 3000;

    test_msg.vel_cog.vel_d_accuracy = 6000;

    sbp_message_send(&sbp_state, SbpMsgVelCog, 35027, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgVelCog, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_cog.cog == 1000,
        "incorrect value for last_msg.msg.vel_cog.cog, expected 1000, is %d",
        last_msg.msg.vel_cog.cog);

    ck_assert_msg(last_msg.msg.vel_cog.cog_accuracy == 4000,
                  "incorrect value for last_msg.msg.vel_cog.cog_accuracy, "
                  "expected 4000, is %d",
                  last_msg.msg.vel_cog.cog_accuracy);

    ck_assert_msg(
        last_msg.msg.vel_cog.flags == 62,
        "incorrect value for last_msg.msg.vel_cog.flags, expected 62, is %d",
        last_msg.msg.vel_cog.flags);

    ck_assert_msg(
        last_msg.msg.vel_cog.sog == 2000,
        "incorrect value for last_msg.msg.vel_cog.sog, expected 2000, is %d",
        last_msg.msg.vel_cog.sog);

    ck_assert_msg(last_msg.msg.vel_cog.sog_accuracy == 5000,
                  "incorrect value for last_msg.msg.vel_cog.sog_accuracy, "
                  "expected 5000, is %d",
                  last_msg.msg.vel_cog.sog_accuracy);

    ck_assert_msg(last_msg.msg.vel_cog.tow == 326825520,
                  "incorrect value for last_msg.msg.vel_cog.tow, expected "
                  "326825520, is %d",
                  last_msg.msg.vel_cog.tow);

    ck_assert_msg(
        last_msg.msg.vel_cog.vel_d == 3000,
        "incorrect value for last_msg.msg.vel_cog.vel_d, expected 3000, is %d",
        last_msg.msg.vel_cog.vel_d);

    ck_assert_msg(last_msg.msg.vel_cog.vel_d_accuracy == 6000,
                  "incorrect value for last_msg.msg.vel_cog.vel_d_accuracy, "
                  "expected 6000, is %d",
                  last_msg.msg.vel_cog.vel_d_accuracy);
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

    sbp_callback_register(&sbp_state, 0x21C, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  28,  2, 211, 136, 29, 48,  246, 122, 19,  123, 0,   0,
        0,   200, 1, 0,   0,   24, 252, 255, 255, 0,   149, 186, 10,
        100, 0,   0, 0,   100, 0,  0,   0,   0,   240, 0,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_cog.cog = 123;

    test_msg.vel_cog.cog_accuracy = 180000000;

    test_msg.vel_cog.flags = 0;

    test_msg.vel_cog.sog = 456;

    test_msg.vel_cog.sog_accuracy = 100;

    test_msg.vel_cog.tow = 326825520;

    test_msg.vel_cog.vel_d = -1000;

    test_msg.vel_cog.vel_d_accuracy = 100;

    sbp_message_send(&sbp_state, SbpMsgVelCog, 35027, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgVelCog, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_cog.cog == 123,
        "incorrect value for last_msg.msg.vel_cog.cog, expected 123, is %d",
        last_msg.msg.vel_cog.cog);

    ck_assert_msg(last_msg.msg.vel_cog.cog_accuracy == 180000000,
                  "incorrect value for last_msg.msg.vel_cog.cog_accuracy, "
                  "expected 180000000, is %d",
                  last_msg.msg.vel_cog.cog_accuracy);

    ck_assert_msg(
        last_msg.msg.vel_cog.flags == 0,
        "incorrect value for last_msg.msg.vel_cog.flags, expected 0, is %d",
        last_msg.msg.vel_cog.flags);

    ck_assert_msg(
        last_msg.msg.vel_cog.sog == 456,
        "incorrect value for last_msg.msg.vel_cog.sog, expected 456, is %d",
        last_msg.msg.vel_cog.sog);

    ck_assert_msg(last_msg.msg.vel_cog.sog_accuracy == 100,
                  "incorrect value for last_msg.msg.vel_cog.sog_accuracy, "
                  "expected 100, is %d",
                  last_msg.msg.vel_cog.sog_accuracy);

    ck_assert_msg(last_msg.msg.vel_cog.tow == 326825520,
                  "incorrect value for last_msg.msg.vel_cog.tow, expected "
                  "326825520, is %d",
                  last_msg.msg.vel_cog.tow);

    ck_assert_msg(
        last_msg.msg.vel_cog.vel_d == -1000,
        "incorrect value for last_msg.msg.vel_cog.vel_d, expected -1000, is %d",
        last_msg.msg.vel_cog.vel_d);

    ck_assert_msg(last_msg.msg.vel_cog.vel_d_accuracy == 100,
                  "incorrect value for last_msg.msg.vel_cog.vel_d_accuracy, "
                  "expected 100, is %d",
                  last_msg.msg.vel_cog.vel_d_accuracy);
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

    sbp_callback_register(&sbp_state, 0x21C, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 28, 2, 211, 136, 29, 48, 246, 122, 19, 0, 0, 0, 0, 0, 0, 0,  0,   0,
        0,  0,  0, 0,   0,   0,  0,  0,   0,   0,  0, 0, 0, 0, 0, 0, 94, 119,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_cog.cog = 0;

    test_msg.vel_cog.cog_accuracy = 0;

    test_msg.vel_cog.flags = 0;

    test_msg.vel_cog.sog = 0;

    test_msg.vel_cog.sog_accuracy = 0;

    test_msg.vel_cog.tow = 326825520;

    test_msg.vel_cog.vel_d = 0;

    test_msg.vel_cog.vel_d_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelCog, 35027, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgVelCog, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.vel_cog.cog == 0,
        "incorrect value for last_msg.msg.vel_cog.cog, expected 0, is %d",
        last_msg.msg.vel_cog.cog);

    ck_assert_msg(last_msg.msg.vel_cog.cog_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_cog.cog_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_cog.cog_accuracy);

    ck_assert_msg(
        last_msg.msg.vel_cog.flags == 0,
        "incorrect value for last_msg.msg.vel_cog.flags, expected 0, is %d",
        last_msg.msg.vel_cog.flags);

    ck_assert_msg(
        last_msg.msg.vel_cog.sog == 0,
        "incorrect value for last_msg.msg.vel_cog.sog, expected 0, is %d",
        last_msg.msg.vel_cog.sog);

    ck_assert_msg(last_msg.msg.vel_cog.sog_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_cog.sog_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_cog.sog_accuracy);

    ck_assert_msg(last_msg.msg.vel_cog.tow == 326825520,
                  "incorrect value for last_msg.msg.vel_cog.tow, expected "
                  "326825520, is %d",
                  last_msg.msg.vel_cog.tow);

    ck_assert_msg(
        last_msg.msg.vel_cog.vel_d == 0,
        "incorrect value for last_msg.msg.vel_cog.vel_d, expected 0, is %d",
        last_msg.msg.vel_cog.vel_d);

    ck_assert_msg(last_msg.msg.vel_cog.vel_d_accuracy == 0,
                  "incorrect value for last_msg.msg.vel_cog.vel_d_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.vel_cog.vel_d_accuracy);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgVelCog_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgVelCog");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgVelCog");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgVelCog);
  suite_add_tcase(s, tc_acq);
  return s;
}