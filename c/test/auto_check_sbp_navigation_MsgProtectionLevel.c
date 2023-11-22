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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevel.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/navigation.h>
#include <libsbp/sbp.h>
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

START_TEST(test_auto_check_sbp_navigation_MsgProtectionLevel) {
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

    sbp_callback_register(&sbp_state, 0x217, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  23,  2,   45,  3,   76, 110, 84,  4,   242, 46,  51,  53,  160,
        89,  84,  167, 41,  57,  21, 217, 244, 61,  161, 83,  104, 140, 137,
        90,  246, 51,  51,  51,  51, 51,  170, 180, 64,  154, 153, 153, 153,
        25,  88,  195, 64,  51,  51, 51,  51,  51,  195, 121, 64,  231, 251,
        38,  221, 208, 183, 167, 80, 223, 26,  97,  164, 45,  46,  186, 60,
        235, 227, 183, 160, 187, 93, 116, 224, 105, 40,  32,  33,  133, 188,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.protection_level.atpl = 10663;

    test_msg.protection_level.ctpl = 5433;

    test_msg.protection_level.flags = 555755625;

    test_msg.protection_level.heading = -529244741;

    test_msg.protection_level.height = 412.2;

    test_msg.protection_level.hopl = 26707;

    test_msg.protection_level.hpl = 41013;

    test_msg.protection_level.hvpl = 62681;

    test_msg.protection_level.lat = 5290.2;

    test_msg.protection_level.lon = 9904.2;

    test_msg.protection_level.pitch = -1598561301;

    test_msg.protection_level.popl = 35212;

    test_msg.protection_level.roll = 1018834477;

    test_msg.protection_level.ropl = 63066;

    test_msg.protection_level.tow = 4060370030;

    test_msg.protection_level.v_x = -584647705;

    test_msg.protection_level.v_y = 1353168848;

    test_msg.protection_level.v_z = -1537140001;

    test_msg.protection_level.vpl = 21593;

    test_msg.protection_level.vvpl = 41277;

    test_msg.protection_level.wn = 13102;

    sbp_message_send(&sbp_state, SbpMsgProtectionLevel, 813, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 813,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgProtectionLevel, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.protection_level.atpl == 10663,
                  "incorrect value for last_msg.msg.protection_level.atpl, "
                  "expected 10663, is %d",
                  last_msg.msg.protection_level.atpl);

    ck_assert_msg(last_msg.msg.protection_level.ctpl == 5433,
                  "incorrect value for last_msg.msg.protection_level.ctpl, "
                  "expected 5433, is %d",
                  last_msg.msg.protection_level.ctpl);

    ck_assert_msg(last_msg.msg.protection_level.flags == 555755625,
                  "incorrect value for last_msg.msg.protection_level.flags, "
                  "expected 555755625, is %d",
                  last_msg.msg.protection_level.flags);

    ck_assert_msg(last_msg.msg.protection_level.heading == -529244741,
                  "incorrect value for last_msg.msg.protection_level.heading, "
                  "expected -529244741, is %d",
                  last_msg.msg.protection_level.heading);

    ck_assert_msg(
        (last_msg.msg.protection_level.height * 100 - 412.2 * 100) < 0.05,
        "incorrect value for last_msg.msg.protection_level.height, expected "
        "412.2, is %s",
        last_msg.msg.protection_level.height);

    ck_assert_msg(last_msg.msg.protection_level.hopl == 26707,
                  "incorrect value for last_msg.msg.protection_level.hopl, "
                  "expected 26707, is %d",
                  last_msg.msg.protection_level.hopl);

    ck_assert_msg(last_msg.msg.protection_level.hpl == 41013,
                  "incorrect value for last_msg.msg.protection_level.hpl, "
                  "expected 41013, is %d",
                  last_msg.msg.protection_level.hpl);

    ck_assert_msg(last_msg.msg.protection_level.hvpl == 62681,
                  "incorrect value for last_msg.msg.protection_level.hvpl, "
                  "expected 62681, is %d",
                  last_msg.msg.protection_level.hvpl);

    ck_assert_msg(
        (last_msg.msg.protection_level.lat * 100 - 5290.2 * 100) < 0.05,
        "incorrect value for last_msg.msg.protection_level.lat, expected "
        "5290.2, is %s",
        last_msg.msg.protection_level.lat);

    ck_assert_msg(
        (last_msg.msg.protection_level.lon * 100 - 9904.2 * 100) < 0.05,
        "incorrect value for last_msg.msg.protection_level.lon, expected "
        "9904.2, is %s",
        last_msg.msg.protection_level.lon);

    ck_assert_msg(last_msg.msg.protection_level.pitch == -1598561301,
                  "incorrect value for last_msg.msg.protection_level.pitch, "
                  "expected -1598561301, is %d",
                  last_msg.msg.protection_level.pitch);

    ck_assert_msg(last_msg.msg.protection_level.popl == 35212,
                  "incorrect value for last_msg.msg.protection_level.popl, "
                  "expected 35212, is %d",
                  last_msg.msg.protection_level.popl);

    ck_assert_msg(last_msg.msg.protection_level.roll == 1018834477,
                  "incorrect value for last_msg.msg.protection_level.roll, "
                  "expected 1018834477, is %d",
                  last_msg.msg.protection_level.roll);

    ck_assert_msg(last_msg.msg.protection_level.ropl == 63066,
                  "incorrect value for last_msg.msg.protection_level.ropl, "
                  "expected 63066, is %d",
                  last_msg.msg.protection_level.ropl);

    ck_assert_msg(last_msg.msg.protection_level.tow == 4060370030,
                  "incorrect value for last_msg.msg.protection_level.tow, "
                  "expected 4060370030, is %d",
                  last_msg.msg.protection_level.tow);

    ck_assert_msg(last_msg.msg.protection_level.v_x == -584647705,
                  "incorrect value for last_msg.msg.protection_level.v_x, "
                  "expected -584647705, is %d",
                  last_msg.msg.protection_level.v_x);

    ck_assert_msg(last_msg.msg.protection_level.v_y == 1353168848,
                  "incorrect value for last_msg.msg.protection_level.v_y, "
                  "expected 1353168848, is %d",
                  last_msg.msg.protection_level.v_y);

    ck_assert_msg(last_msg.msg.protection_level.v_z == -1537140001,
                  "incorrect value for last_msg.msg.protection_level.v_z, "
                  "expected -1537140001, is %d",
                  last_msg.msg.protection_level.v_z);

    ck_assert_msg(last_msg.msg.protection_level.vpl == 21593,
                  "incorrect value for last_msg.msg.protection_level.vpl, "
                  "expected 21593, is %d",
                  last_msg.msg.protection_level.vpl);

    ck_assert_msg(last_msg.msg.protection_level.vvpl == 41277,
                  "incorrect value for last_msg.msg.protection_level.vvpl, "
                  "expected 41277, is %d",
                  last_msg.msg.protection_level.vvpl);

    ck_assert_msg(last_msg.msg.protection_level.wn == 13102,
                  "incorrect value for last_msg.msg.protection_level.wn, "
                  "expected 13102, is %d",
                  last_msg.msg.protection_level.wn);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgProtectionLevel_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgProtectionLevel");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_navigation_MsgProtectionLevel");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgProtectionLevel);
  suite_add_tcase(s, tc_acq);
  return s;
}