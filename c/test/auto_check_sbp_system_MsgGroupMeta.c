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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgGroupMeta.yaml by generate.py. Do
// not modify by hand!

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

START_TEST(test_auto_check_sbp_system_MsgGroupMeta) {
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

    sbp_callback_register(&sbp_state, 0xFF0A, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 10, 255, 238, 238, 9, 1, 2, 3, 10, 255, 10, 2, 2, 255, 2, 14,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.group_meta.flags = 2;

    test_msg.group_meta.group_id = 1;

    test_msg.group_meta.group_msgs[0] = 65290;

    test_msg.group_meta.group_msgs[1] = 522;

    test_msg.group_meta.group_msgs[2] = 65282;

    test_msg.group_meta.n_group_msgs = 3;

    sbp_message_send(&sbp_state, SbpMsgGroupMeta, 61166, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 61166,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgGroupMeta, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.group_meta.flags == 2,
        "incorrect value for last_msg.msg.group_meta.flags, expected 2, is %d",
        last_msg.msg.group_meta.flags);

    ck_assert_msg(last_msg.msg.group_meta.group_id == 1,
                  "incorrect value for last_msg.msg.group_meta.group_id, "
                  "expected 1, is %d",
                  last_msg.msg.group_meta.group_id);

    ck_assert_msg(last_msg.msg.group_meta.group_msgs[0] == 65290,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[0], "
                  "expected 65290, is %d",
                  last_msg.msg.group_meta.group_msgs[0]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[1] == 522,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[1], "
                  "expected 522, is %d",
                  last_msg.msg.group_meta.group_msgs[1]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[2] == 65282,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[2], "
                  "expected 65282, is %d",
                  last_msg.msg.group_meta.group_msgs[2]);

    ck_assert_msg(last_msg.msg.group_meta.n_group_msgs == 3,
                  "incorrect value for last_msg.msg.group_meta.n_group_msgs, "
                  "expected 3, is %d",
                  last_msg.msg.group_meta.n_group_msgs);
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

    sbp_callback_register(&sbp_state, 0xFF0A, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 10, 255, 21, 3, 31, 1,   1, 14,  2,  1,   3,  1,
        10, 2,  17,  2,  9, 2,  20,  2, 14,  2,  18,  2,  13,
        2,  21, 2,   33, 2, 3,  255, 6, 255, 14, 255, 82, 154,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.group_meta.flags = 1;

    test_msg.group_meta.group_id = 1;

    test_msg.group_meta.group_msgs[0] = 258;

    test_msg.group_meta.group_msgs[1] = 259;

    test_msg.group_meta.group_msgs[2] = 522;

    test_msg.group_meta.group_msgs[3] = 529;

    test_msg.group_meta.group_msgs[4] = 521;

    test_msg.group_meta.group_msgs[5] = 532;

    test_msg.group_meta.group_msgs[6] = 526;

    test_msg.group_meta.group_msgs[7] = 530;

    test_msg.group_meta.group_msgs[8] = 525;

    test_msg.group_meta.group_msgs[9] = 533;

    test_msg.group_meta.group_msgs[10] = 545;

    test_msg.group_meta.group_msgs[11] = 65283;

    test_msg.group_meta.group_msgs[12] = 65286;

    test_msg.group_meta.group_msgs[13] = 65294;

    test_msg.group_meta.n_group_msgs = 14;

    sbp_message_send(&sbp_state, SbpMsgGroupMeta, 789, &test_msg, &dummy_write);

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
        sbp_message_cmp(SbpMsgGroupMeta, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.group_meta.flags == 1,
        "incorrect value for last_msg.msg.group_meta.flags, expected 1, is %d",
        last_msg.msg.group_meta.flags);

    ck_assert_msg(last_msg.msg.group_meta.group_id == 1,
                  "incorrect value for last_msg.msg.group_meta.group_id, "
                  "expected 1, is %d",
                  last_msg.msg.group_meta.group_id);

    ck_assert_msg(last_msg.msg.group_meta.group_msgs[0] == 258,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[0], "
                  "expected 258, is %d",
                  last_msg.msg.group_meta.group_msgs[0]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[1] == 259,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[1], "
                  "expected 259, is %d",
                  last_msg.msg.group_meta.group_msgs[1]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[2] == 522,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[2], "
                  "expected 522, is %d",
                  last_msg.msg.group_meta.group_msgs[2]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[3] == 529,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[3], "
                  "expected 529, is %d",
                  last_msg.msg.group_meta.group_msgs[3]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[4] == 521,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[4], "
                  "expected 521, is %d",
                  last_msg.msg.group_meta.group_msgs[4]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[5] == 532,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[5], "
                  "expected 532, is %d",
                  last_msg.msg.group_meta.group_msgs[5]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[6] == 526,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[6], "
                  "expected 526, is %d",
                  last_msg.msg.group_meta.group_msgs[6]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[7] == 530,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[7], "
                  "expected 530, is %d",
                  last_msg.msg.group_meta.group_msgs[7]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[8] == 525,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[8], "
                  "expected 525, is %d",
                  last_msg.msg.group_meta.group_msgs[8]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[9] == 533,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[9], "
                  "expected 533, is %d",
                  last_msg.msg.group_meta.group_msgs[9]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[10] == 545,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[10], "
                  "expected 545, is %d",
                  last_msg.msg.group_meta.group_msgs[10]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[11] == 65283,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[11], "
                  "expected 65283, is %d",
                  last_msg.msg.group_meta.group_msgs[11]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[12] == 65286,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[12], "
                  "expected 65286, is %d",
                  last_msg.msg.group_meta.group_msgs[12]);
    ck_assert_msg(last_msg.msg.group_meta.group_msgs[13] == 65294,
                  "incorrect value for last_msg.msg.group_meta.group_msgs[13], "
                  "expected 65294, is %d",
                  last_msg.msg.group_meta.group_msgs[13]);

    ck_assert_msg(last_msg.msg.group_meta.n_group_msgs == 14,
                  "incorrect value for last_msg.msg.group_meta.n_group_msgs, "
                  "expected 14, is %d",
                  last_msg.msg.group_meta.n_group_msgs);
  }
}
END_TEST

Suite *auto_check_sbp_system_MsgGroupMeta_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_system_MsgGroupMeta");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_system_MsgGroupMeta");
  tcase_add_test(tc_acq, test_auto_check_sbp_system_MsgGroupMeta);
  suite_add_tcase(s, tc_acq);
  return s;
}