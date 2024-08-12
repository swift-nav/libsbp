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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessFdCount.yaml by
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

START_TEST(test_auto_check_sbp_linux_MsgLinuxProcessFdCount) {
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

    sbp_callback_register(&sbp_state, 0x7f06, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  6,   127, 30,  195, 51,  164, 189, 165, 5,   139, 47,
        112, 97,  116, 104, 47,  116, 111, 47,  112, 114, 111, 99,
        101, 115, 115, 45,  110, 97,  109, 101, 32,  97,  114, 103,
        48,  32,  97,  114, 103, 49,  32,  97,  114, 103, 50,  32,
        97,  114, 103, 51,  32,  97,  114, 103, 52,  2,   94,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    ck_assert_msg(
        sbp_msg_linux_process_fd_count_cmdline_set(
            &test_msg.linux_process_fd_count,
            "/path/to/process-name arg0 arg1 arg2 arg3 arg4", false, &written),
        "Can't assign text");
    ck_assert_msg(
        written == strlen("/path/to/process-name arg0 arg1 arg2 arg3 arg4"),
        "Wrote different to expected");
    ck_assert_msg(sbp_msg_linux_process_fd_count_cmdline_encoded_len(
                      &test_msg.linux_process_fd_count) == 46,
                  "String not encoded properly");

    test_msg.linux_process_fd_count.fd_count = 35589;

    test_msg.linux_process_fd_count.index = 164;

    test_msg.linux_process_fd_count.pid = 42429;

    sbp_message_send(&sbp_state, SbpMsgLinuxProcessFdCount, 49950, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 49950,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgLinuxProcessFdCount, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(sbp_msg_linux_process_fd_count_cmdline_encoded_len(
                      &last_msg.msg.linux_process_fd_count) == 46,
                  "Invalid encoded len");
    ck_assert_msg(strcmp(sbp_msg_linux_process_fd_count_cmdline_get(
                             &last_msg.msg.linux_process_fd_count),
                         "/path/to/process-name arg0 arg1 arg2 arg3 arg4") == 0,
                  "String not decoded properly");

    ck_assert_msg(
        last_msg.msg.linux_process_fd_count.fd_count == 35589,
        "incorrect value for last_msg.msg.linux_process_fd_count.fd_count, "
        "expected 35589, is %" PRId64,
        (int64_t)last_msg.msg.linux_process_fd_count.fd_count);

    ck_assert_msg(
        last_msg.msg.linux_process_fd_count.index == 164,
        "incorrect value for last_msg.msg.linux_process_fd_count.index, "
        "expected 164, is %" PRId64,
        (int64_t)last_msg.msg.linux_process_fd_count.index);

    ck_assert_msg(
        last_msg.msg.linux_process_fd_count.pid == 42429,
        "incorrect value for last_msg.msg.linux_process_fd_count.pid, expected "
        "42429, is %" PRId64,
        (int64_t)last_msg.msg.linux_process_fd_count.pid);
  }
}
END_TEST

Suite *auto_check_sbp_linux_MsgLinuxProcessFdCount_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_linux_MsgLinuxProcessFdCount");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_linux_MsgLinuxProcessFdCount");
  tcase_add_test(tc_acq, test_auto_check_sbp_linux_MsgLinuxProcessFdCount);
  suite_add_tcase(s, tc_acq);
  return s;
}