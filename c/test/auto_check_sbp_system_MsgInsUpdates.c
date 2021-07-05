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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgInsUpdates.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/system.h>
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

START_TEST(test_auto_check_sbp_system_MsgInsUpdates) {
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

    sbp_callback_register(&sbp_state, 0xff06, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 6, 255, 21, 3, 10, 84, 229, 17, 30, 0, 0, 0, 0, 0, 0, 81, 63,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ins_updates.gnsspos = 0;

    test_msg.ins_updates.gnssvel = 0;

    test_msg.ins_updates.nhc = 0;

    test_msg.ins_updates.speed = 0;

    test_msg.ins_updates.tow = 504489300;

    test_msg.ins_updates.wheelticks = 0;

    test_msg.ins_updates.zerovel = 0;

    sbp_message_send(&sbp_state, SbpMsgInsUpdates, 789, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 789,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgInsUpdates, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.ins_updates.gnsspos == 0,
                  "incorrect value for last_msg.msg.ins_updates.gnsspos, "
                  "expected 0, is %d",
                  last_msg.msg.ins_updates.gnsspos);

    ck_assert_msg(last_msg.msg.ins_updates.gnssvel == 0,
                  "incorrect value for last_msg.msg.ins_updates.gnssvel, "
                  "expected 0, is %d",
                  last_msg.msg.ins_updates.gnssvel);

    ck_assert_msg(
        last_msg.msg.ins_updates.nhc == 0,
        "incorrect value for last_msg.msg.ins_updates.nhc, expected 0, is %d",
        last_msg.msg.ins_updates.nhc);

    ck_assert_msg(
        last_msg.msg.ins_updates.speed == 0,
        "incorrect value for last_msg.msg.ins_updates.speed, expected 0, is %d",
        last_msg.msg.ins_updates.speed);

    ck_assert_msg(last_msg.msg.ins_updates.tow == 504489300,
                  "incorrect value for last_msg.msg.ins_updates.tow, expected "
                  "504489300, is %d",
                  last_msg.msg.ins_updates.tow);

    ck_assert_msg(last_msg.msg.ins_updates.wheelticks == 0,
                  "incorrect value for last_msg.msg.ins_updates.wheelticks, "
                  "expected 0, is %d",
                  last_msg.msg.ins_updates.wheelticks);

    ck_assert_msg(last_msg.msg.ins_updates.zerovel == 0,
                  "incorrect value for last_msg.msg.ins_updates.zerovel, "
                  "expected 0, is %d",
                  last_msg.msg.ins_updates.zerovel);
  }
}
END_TEST

Suite *auto_check_sbp_system_MsgInsUpdates_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_system_MsgInsUpdates");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_system_MsgInsUpdates");
  tcase_add_test(tc_acq, test_auto_check_sbp_system_MsgInsUpdates);
  suite_add_tcase(s, tc_acq);
  return s;
}