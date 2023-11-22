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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevelDepA.yaml by
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

START_TEST(test_auto_check_sbp_navigation_MsgProtectionLevelDepA) {
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

    sbp_callback_register(&sbp_state, 0x216, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  22, 2,   148, 22,  33,  52,  126, 69,  185, 47,  85,  4,   139,
        51,  51, 51,  51,  51,  244, 190, 64,  102, 102, 102, 102, 102, 204,
        168, 64, 154, 153, 153, 153, 25,  39,  192, 64,  248, 81,  104,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.protection_level_dep_a.flags = 248;

    test_msg.protection_level_dep_a.height = 8270.2;

    test_msg.protection_level_dep_a.hpl = 35588;

    test_msg.protection_level_dep_a.lat = 7924.2;

    test_msg.protection_level_dep_a.lon = 3174.2;

    test_msg.protection_level_dep_a.tow = 3108339252;

    test_msg.protection_level_dep_a.vpl = 21807;

    sbp_message_send(&sbp_state, SbpMsgProtectionLevelDepA, 5780, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 5780,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgProtectionLevelDepA, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.protection_level_dep_a.flags == 248,
        "incorrect value for last_msg.msg.protection_level_dep_a.flags, "
        "expected 248, is %d",
        last_msg.msg.protection_level_dep_a.flags);

    ck_assert_msg(
        (last_msg.msg.protection_level_dep_a.height * 100 - 8270.2 * 100) <
            0.05,
        "incorrect value for last_msg.msg.protection_level_dep_a.height, "
        "expected 8270.2, is %s",
        last_msg.msg.protection_level_dep_a.height);

    ck_assert_msg(
        last_msg.msg.protection_level_dep_a.hpl == 35588,
        "incorrect value for last_msg.msg.protection_level_dep_a.hpl, expected "
        "35588, is %d",
        last_msg.msg.protection_level_dep_a.hpl);

    ck_assert_msg(
        (last_msg.msg.protection_level_dep_a.lat * 100 - 7924.2 * 100) < 0.05,
        "incorrect value for last_msg.msg.protection_level_dep_a.lat, expected "
        "7924.2, is %s",
        last_msg.msg.protection_level_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.protection_level_dep_a.lon * 100 - 3174.2 * 100) < 0.05,
        "incorrect value for last_msg.msg.protection_level_dep_a.lon, expected "
        "3174.2, is %s",
        last_msg.msg.protection_level_dep_a.lon);

    ck_assert_msg(
        last_msg.msg.protection_level_dep_a.tow == 3108339252,
        "incorrect value for last_msg.msg.protection_level_dep_a.tow, expected "
        "3108339252, is %d",
        last_msg.msg.protection_level_dep_a.tow);

    ck_assert_msg(
        last_msg.msg.protection_level_dep_a.vpl == 21807,
        "incorrect value for last_msg.msg.protection_level_dep_a.vpl, expected "
        "21807, is %d",
        last_msg.msg.protection_level_dep_a.vpl);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgProtectionLevelDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_navigation_MsgProtectionLevelDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_navigation_MsgProtectionLevelDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgProtectionLevelDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}