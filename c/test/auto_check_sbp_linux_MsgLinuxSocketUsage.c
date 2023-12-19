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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSocketUsage.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/linux.h>
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

START_TEST(test_auto_check_sbp_linux_MsgLinuxSocketUsage) {
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

    sbp_callback_register(&sbp_state, 0x7f05, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  5,   127, 114, 138, 72,  13,  196, 69,  173, 67,  222, 186, 181,
        246, 154, 251, 17,  224, 179, 26,  169, 177, 90,  149, 213, 214, 6,
        126, 64,  120, 185, 84,  131, 200, 111, 32,  141, 217, 209, 52,  14,
        190, 147, 159, 246, 141, 122, 212, 119, 131, 30,  120, 47,  25,  109,
        154, 65,  132, 164, 39,  30,  30,  175, 8,   44,  28,  111, 236, 240,
        176, 74,  159, 129, 154, 153, 162, 229, 130, 154,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.linux_socket_usage.avg_queue_depth = 2907030541;

    test_msg.linux_socket_usage.max_queue_depth = 3048922691;

    test_msg.linux_socket_usage.socket_state_counts[0] = 39670;

    test_msg.linux_socket_usage.socket_state_counts[1] = 4603;

    test_msg.linux_socket_usage.socket_state_counts[2] = 46048;

    test_msg.linux_socket_usage.socket_state_counts[3] = 43290;

    test_msg.linux_socket_usage.socket_state_counts[4] = 23217;

    test_msg.linux_socket_usage.socket_state_counts[5] = 54677;

    test_msg.linux_socket_usage.socket_state_counts[6] = 1750;

    test_msg.linux_socket_usage.socket_state_counts[7] = 16510;

    test_msg.linux_socket_usage.socket_state_counts[8] = 47480;

    test_msg.linux_socket_usage.socket_state_counts[9] = 33620;

    test_msg.linux_socket_usage.socket_state_counts[10] = 28616;

    test_msg.linux_socket_usage.socket_state_counts[11] = 36128;

    test_msg.linux_socket_usage.socket_state_counts[12] = 53721;

    test_msg.linux_socket_usage.socket_state_counts[13] = 3636;

    test_msg.linux_socket_usage.socket_state_counts[14] = 37822;

    test_msg.linux_socket_usage.socket_state_counts[15] = 63135;

    test_msg.linux_socket_usage.socket_type_counts[0] = 31373;

    test_msg.linux_socket_usage.socket_type_counts[1] = 30676;

    test_msg.linux_socket_usage.socket_type_counts[2] = 7811;

    test_msg.linux_socket_usage.socket_type_counts[3] = 12152;

    test_msg.linux_socket_usage.socket_type_counts[4] = 27929;

    test_msg.linux_socket_usage.socket_type_counts[5] = 16794;

    test_msg.linux_socket_usage.socket_type_counts[6] = 42116;

    test_msg.linux_socket_usage.socket_type_counts[7] = 7719;

    test_msg.linux_socket_usage.socket_type_counts[8] = 44830;

    test_msg.linux_socket_usage.socket_type_counts[9] = 11272;

    test_msg.linux_socket_usage.socket_type_counts[10] = 28444;

    test_msg.linux_socket_usage.socket_type_counts[11] = 61676;

    test_msg.linux_socket_usage.socket_type_counts[12] = 19120;

    test_msg.linux_socket_usage.socket_type_counts[13] = 33183;

    test_msg.linux_socket_usage.socket_type_counts[14] = 39322;

    test_msg.linux_socket_usage.socket_type_counts[15] = 58786;

    sbp_message_send(&sbp_state, SbpMsgLinuxSocketUsage, 35442, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 35442,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgLinuxSocketUsage, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.linux_socket_usage.avg_queue_depth == 2907030541,
        "incorrect value for last_msg.msg.linux_socket_usage.avg_queue_depth, "
        "expected 2907030541, is %d",
        last_msg.msg.linux_socket_usage.avg_queue_depth);

    ck_assert_msg(
        last_msg.msg.linux_socket_usage.max_queue_depth == 3048922691,
        "incorrect value for last_msg.msg.linux_socket_usage.max_queue_depth, "
        "expected 3048922691, is %d",
        last_msg.msg.linux_socket_usage.max_queue_depth);

    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[0] == 39670,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[0], expected "
        "39670, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[0]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[1] == 4603,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[1], expected "
        "4603, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[1]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[2] == 46048,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[2], expected "
        "46048, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[2]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[3] == 43290,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[3], expected "
        "43290, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[3]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[4] == 23217,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[4], expected "
        "23217, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[4]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[5] == 54677,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[5], expected "
        "54677, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[5]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[6] == 1750,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[6], expected "
        "1750, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[6]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[7] == 16510,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[7], expected "
        "16510, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[7]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[8] == 47480,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[8], expected "
        "47480, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[8]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[9] == 33620,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[9], expected "
        "33620, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[9]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[10] == 28616,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[10], expected "
        "28616, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[10]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[11] == 36128,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[11], expected "
        "36128, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[11]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[12] == 53721,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[12], expected "
        "53721, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[12]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[13] == 3636,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[13], expected "
        "3636, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[13]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[14] == 37822,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[14], expected "
        "37822, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[14]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_state_counts[15] == 63135,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_state_counts[15], expected "
        "63135, is %d",
        last_msg.msg.linux_socket_usage.socket_state_counts[15]);

    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[0] == 31373,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[0], expected "
        "31373, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[0]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[1] == 30676,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[1], expected "
        "30676, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[1]);
    ck_assert_msg(last_msg.msg.linux_socket_usage.socket_type_counts[2] == 7811,
                  "incorrect value for "
                  "last_msg.msg.linux_socket_usage.socket_type_counts[2], "
                  "expected 7811, is %d",
                  last_msg.msg.linux_socket_usage.socket_type_counts[2]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[3] == 12152,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[3], expected "
        "12152, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[3]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[4] == 27929,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[4], expected "
        "27929, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[4]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[5] == 16794,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[5], expected "
        "16794, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[5]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[6] == 42116,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[6], expected "
        "42116, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[6]);
    ck_assert_msg(last_msg.msg.linux_socket_usage.socket_type_counts[7] == 7719,
                  "incorrect value for "
                  "last_msg.msg.linux_socket_usage.socket_type_counts[7], "
                  "expected 7719, is %d",
                  last_msg.msg.linux_socket_usage.socket_type_counts[7]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[8] == 44830,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[8], expected "
        "44830, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[8]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[9] == 11272,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[9], expected "
        "11272, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[9]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[10] == 28444,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[10], expected "
        "28444, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[10]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[11] == 61676,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[11], expected "
        "61676, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[11]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[12] == 19120,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[12], expected "
        "19120, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[12]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[13] == 33183,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[13], expected "
        "33183, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[13]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[14] == 39322,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[14], expected "
        "39322, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[14]);
    ck_assert_msg(
        last_msg.msg.linux_socket_usage.socket_type_counts[15] == 58786,
        "incorrect value for "
        "last_msg.msg.linux_socket_usage.socket_type_counts[15], expected "
        "58786, is %d",
        last_msg.msg.linux_socket_usage.socket_type_counts[15]);
  }
}
END_TEST

Suite *auto_check_sbp_linux_MsgLinuxSocketUsage_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_linux_MsgLinuxSocketUsage");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_linux_MsgLinuxSocketUsage");
  tcase_add_test(tc_acq, test_auto_check_sbp_linux_MsgLinuxSocketUsage);
  suite_add_tcase(s, tc_acq);
  return s;
}