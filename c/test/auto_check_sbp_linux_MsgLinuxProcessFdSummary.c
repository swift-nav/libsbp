/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessFdSummary.yaml by
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

static size_t dummy_wr = 0;
static size_t dummy_rd = 0;
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
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
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

START_TEST(test_auto_check_sbp_linux_MsgLinuxProcessFdSummary) {
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

    sbp_callback_register(&sbp_state, 0x7f07, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  7,   127, 103, 248, 29,  19,  131, 200, 77,  102, 100, 49,
        0,   102, 100, 50,  0,   102, 100, 51,  0,   102, 100, 52,  0,
        102, 100, 53,  0,   102, 100, 54,  0,   0,   129, 80,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    ck_assert_msg(sbp_msg_linux_process_fd_summary_most_opened_add_section(
                      &test_msg.linux_process_fd_summary, "fd1") == true,
                  "Can't assign section 0");
    ck_assert_msg(sbp_msg_linux_process_fd_summary_most_opened_add_section(
                      &test_msg.linux_process_fd_summary, "fd2") == true,
                  "Can't assign section 1");
    ck_assert_msg(sbp_msg_linux_process_fd_summary_most_opened_add_section(
                      &test_msg.linux_process_fd_summary, "fd3") == true,
                  "Can't assign section 2");
    ck_assert_msg(sbp_msg_linux_process_fd_summary_most_opened_add_section(
                      &test_msg.linux_process_fd_summary, "fd4") == true,
                  "Can't assign section 3");
    ck_assert_msg(sbp_msg_linux_process_fd_summary_most_opened_add_section(
                      &test_msg.linux_process_fd_summary, "fd5") == true,
                  "Can't assign section 4");
    ck_assert_msg(sbp_msg_linux_process_fd_summary_most_opened_add_section(
                      &test_msg.linux_process_fd_summary, "fd6") == true,
                  "Can't assign section 5");
    ck_assert_msg(sbp_msg_linux_process_fd_summary_most_opened_encoded_len(
                      &test_msg.linux_process_fd_summary) == 25,
                  "String not encoded properly");

    test_msg.linux_process_fd_summary.sys_fd_count = 1304986387;

    sbp_message_send(&sbp_state, SbpMsgLinuxProcessFdSummary, 63591, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 63591,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgLinuxProcessFdSummary, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(sbp_msg_linux_process_fd_summary_most_opened_encoded_len(
                      &last_msg.msg.linux_process_fd_summary) == 25,
                  "Invalid encoded len");
    ck_assert_msg(
        strcmp(sbp_msg_linux_process_fd_summary_most_opened_get_section(
                   &last_msg.msg.linux_process_fd_summary, 0),
               "fd1") == 0,
        "Section 0 not decoded properly");
    ck_assert_msg(
        strcmp(sbp_msg_linux_process_fd_summary_most_opened_get_section(
                   &last_msg.msg.linux_process_fd_summary, 1),
               "fd2") == 0,
        "Section 1 not decoded properly");
    ck_assert_msg(
        strcmp(sbp_msg_linux_process_fd_summary_most_opened_get_section(
                   &last_msg.msg.linux_process_fd_summary, 2),
               "fd3") == 0,
        "Section 2 not decoded properly");
    ck_assert_msg(
        strcmp(sbp_msg_linux_process_fd_summary_most_opened_get_section(
                   &last_msg.msg.linux_process_fd_summary, 3),
               "fd4") == 0,
        "Section 3 not decoded properly");
    ck_assert_msg(
        strcmp(sbp_msg_linux_process_fd_summary_most_opened_get_section(
                   &last_msg.msg.linux_process_fd_summary, 4),
               "fd5") == 0,
        "Section 4 not decoded properly");
    ck_assert_msg(
        strcmp(sbp_msg_linux_process_fd_summary_most_opened_get_section(
                   &last_msg.msg.linux_process_fd_summary, 5),
               "fd6") == 0,
        "Section 5 not decoded properly");

    ck_assert_msg(
        last_msg.msg.linux_process_fd_summary.sys_fd_count == 1304986387,
        "incorrect value for "
        "last_msg.msg.linux_process_fd_summary.sys_fd_count, expected "
        "1304986387, is %" PRId64,
        (int64_t)last_msg.msg.linux_process_fd_summary.sys_fd_count);
  }
}
END_TEST

Suite *auto_check_sbp_linux_MsgLinuxProcessFdSummary_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_linux_MsgLinuxProcessFdSummary");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_linux_MsgLinuxProcessFdSummary");
  tcase_add_test(tc_acq, test_auto_check_sbp_linux_MsgLinuxProcessFdSummary);
  suite_add_tcase(s, tc_acq);
  return s;
}
