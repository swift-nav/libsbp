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
// spec/tests/yaml/swiftnav/sbp/logging/test_MsgPrintDep.yaml by generate.py. Do
// not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/logging.h>
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

START_TEST(test_auto_check_sbp_logging_MsgPrintDep) {
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

    sbp_callback_register(&sbp_state, 0x10, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  16,  0,   34, 34, 43, 73, 78, 70, 79, 58,  32,  97,
        99,  113, 58,  32, 80, 82, 78, 32, 49, 53, 32,  102, 111,
        117, 110, 100, 32, 64, 32, 45, 50, 52, 57, 55,  32,  72,
        122, 44,  32,  50, 48, 32, 83, 78, 82, 10, 116, 103,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    ck_assert_msg(
        sbp_msg_print_dep_text_set(
            &test_msg.print_dep, "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n",
            false, &written),
        "Can't assign text");
    ck_assert_msg(
        written == strlen("INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n"),
        "Wrote different to expected");
    ck_assert_msg(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep) == 43,
                  "String not encoded properly");

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 8738,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep) == 43,
        "Invalid encoded len");
    ck_assert_msg(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                         "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n") == 0,
                  "String not decoded properly");
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

    sbp_callback_register(&sbp_state, 0x10, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  16,  0,   34, 34, 42, 73, 78, 70, 79,  58, 32,  97,
        99,  113, 58,  32, 80, 82, 78, 32, 51, 49,  32, 102, 111,
        117, 110, 100, 32, 64, 32, 52, 50, 52, 53,  32, 72,  122,
        44,  32,  50,  49, 32, 83, 78, 82, 10, 140, 43,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    ck_assert_msg(
        sbp_msg_print_dep_text_set(
            &test_msg.print_dep, "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n",
            false, &written),
        "Can't assign text");
    ck_assert_msg(
        written == strlen("INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n"),
        "Wrote different to expected");
    ck_assert_msg(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep) == 42,
                  "String not encoded properly");

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 8738,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep) == 42,
        "Invalid encoded len");
    ck_assert_msg(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                         "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n") == 0,
                  "String not decoded properly");
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

    sbp_callback_register(&sbp_state, 0x10, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
        97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
        48, 32, 40,  80,  82,  78,  32, 49, 49,  41, 10,  23,  143,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    ck_assert_msg(sbp_msg_print_dep_text_set(
                      &test_msg.print_dep,
                      "INFO: Disabling channel 0 (PRN 11)\n", false, &written),
                  "Can't assign text");
    ck_assert_msg(written == strlen("INFO: Disabling channel 0 (PRN 11)\n"),
                  "Wrote different to expected");
    ck_assert_msg(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep) == 35,
                  "String not encoded properly");

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 8738,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep) == 35,
        "Invalid encoded len");
    ck_assert_msg(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                         "INFO: Disabling channel 0 (PRN 11)\n") == 0,
                  "String not decoded properly");
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

    sbp_callback_register(&sbp_state, 0x10, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  16,  0,  34, 34, 41, 73, 78, 70,  79, 58,  32,  97,
        99,  113, 58, 32, 80, 82, 78, 32, 50,  32, 102, 111, 117,
        110, 100, 32, 64, 32, 51, 57, 57, 54,  32, 72,  122, 44,
        32,  50,  48, 32, 83, 78, 82, 10, 239, 48,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    ck_assert_msg(
        sbp_msg_print_dep_text_set(&test_msg.print_dep,
                                   "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n",
                                   false, &written),
        "Can't assign text");
    ck_assert_msg(
        written == strlen("INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n"),
        "Wrote different to expected");
    ck_assert_msg(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep) == 41,
                  "String not encoded properly");

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 8738,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep) == 41,
        "Invalid encoded len");
    ck_assert_msg(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                         "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n") == 0,
                  "String not decoded properly");
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

    sbp_callback_register(&sbp_state, 0x10, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  16,  0,  34, 34, 42, 73, 78, 70, 79, 58,  32,  97,
        99,  113, 58, 32, 80, 82, 78, 32, 52, 32, 102, 111, 117,
        110, 100, 32, 64, 32, 45, 55, 52, 57, 50, 32,  72,  122,
        44,  32,  50, 48, 32, 83, 78, 82, 10, 47, 248,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    ck_assert_msg(
        sbp_msg_print_dep_text_set(
            &test_msg.print_dep, "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n",
            false, &written),
        "Can't assign text");
    ck_assert_msg(
        written == strlen("INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n"),
        "Wrote different to expected");
    ck_assert_msg(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep) == 42,
                  "String not encoded properly");

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 8738,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep) == 42,
        "Invalid encoded len");
    ck_assert_msg(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                         "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n") == 0,
                  "String not decoded properly");
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

    sbp_callback_register(&sbp_state, 0x10, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
        97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
        49, 32, 40,  80,  82,  78,  32, 49, 53,  41, 10,  158, 139,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    ck_assert_msg(sbp_msg_print_dep_text_set(
                      &test_msg.print_dep,
                      "INFO: Disabling channel 1 (PRN 15)\n", false, &written),
                  "Can't assign text");
    ck_assert_msg(written == strlen("INFO: Disabling channel 1 (PRN 15)\n"),
                  "Wrote different to expected");
    ck_assert_msg(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep) == 35,
                  "String not encoded properly");

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 8738,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep) == 35,
        "Invalid encoded len");
    ck_assert_msg(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                         "INFO: Disabling channel 1 (PRN 15)\n") == 0,
                  "String not decoded properly");
  }
}
END_TEST

Suite *auto_check_sbp_logging_MsgPrintDep_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_logging_MsgPrintDep");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_logging_MsgPrintDep");
  tcase_add_test(tc_acq, test_auto_check_sbp_logging_MsgPrintDep);
  suite_add_tcase(s, tc_acq);
  return s;
}