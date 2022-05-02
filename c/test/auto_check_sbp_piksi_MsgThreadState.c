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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgThreadState.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/piksi.h>
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

START_TEST(test_auto_check_sbp_piksi_MsgThreadState) {
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23, 0, 246, 215, 26, 109, 97, 105, 110, 0, 0,   0, 0, 0, 0,  0,
        0,  0,  0, 0,   0,   0,  0,   0,  0,   0,   0, 156, 9, 0, 0, 73, 138,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 0;

    {
      const char assign_string[] = {
          (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 2460;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.thread_state.cpu == 0,
        "incorrect value for last_msg.msg.thread_state.cpu, expected 0, is %d",
        last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {
          (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 2460,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 2460, is %d",
                  last_msg.msg.thread_state.stack_free);
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23, 0, 246, 215, 26, 105, 100, 108, 101, 0, 0,  0, 0, 0, 0,   0,
        0,  0,  0, 0,   0,   0,  0,   0,   0,   83,  2, 36, 0, 0, 0, 151, 20,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 595;

    {
      const char assign_string[] = {
          (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 36;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.thread_state.cpu == 595,
                  "incorrect value for last_msg.msg.thread_state.cpu, expected "
                  "595, is %d",
                  last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {
          (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 36,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 36, is %d",
                  last_msg.msg.thread_state.stack_free);
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23, 0, 246, 215, 26, 78, 65, 80, 32, 73, 83,  82, 0, 0, 0,   0,
        0,  0,  0, 0,   0,   0,  0,  0,  0,  14, 0,  116, 4,  0, 0, 226, 60,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 14;

    {
      const char assign_string[] = {
          (char)78, (char)65, (char)80, (char)32, (char)73, (char)83, (char)82,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 1140;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.thread_state.cpu == 14,
        "incorrect value for last_msg.msg.thread_state.cpu, expected 14, is %d",
        last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {
          (char)78, (char)65, (char)80, (char)32, (char)73, (char)83, (char)82,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 1140,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 1140, is %d",
                  last_msg.msg.thread_state.stack_free);
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23, 0, 246, 215, 26, 83, 66, 80, 0, 0, 0,   0,  0, 0, 0,  0,
        0,  0,  0, 0,   0,   0,  0,  0,  0,  1, 0, 196, 19, 0, 0, 90, 169,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 1;

    {
      const char assign_string[] = {
          (char)83, (char)66, (char)80, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 5060;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.thread_state.cpu == 1,
        "incorrect value for last_msg.msg.thread_state.cpu, expected 1, is %d",
        last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {
          (char)83, (char)66, (char)80, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 5060,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 5060, is %d",
                  last_msg.msg.thread_state.stack_free);
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23, 0,  246, 215, 26, 109, 97, 110, 97, 103, 101,
        32, 97, 99, 113, 0,   0,  0,   0,  0,   0,  0,   0,
        0,  0,  7,  0,   20,  9,  0,   0,  47,  75,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 7;

    {
      const char assign_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                    (char)103, (char)101, (char)32,  (char)97,
                                    (char)99,  (char)113, (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 2324;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.thread_state.cpu == 7,
        "incorrect value for last_msg.msg.thread_state.cpu, expected 7, is %d",
        last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                   (char)103, (char)101, (char)32,  (char)97,
                                   (char)99,  (char)113, (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 2324,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 2324, is %d",
                  last_msg.msg.thread_state.stack_free);
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23, 0, 195, 4, 26, 109, 97, 105, 110, 0, 0,   0, 0, 0, 0,   0,
        0,  0,  0, 0,   0, 0,  0,   0,  0,   0,   0, 148, 9, 0, 0, 195, 212,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 0;

    {
      const char assign_string[] = {
          (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 2452;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.thread_state.cpu == 0,
        "incorrect value for last_msg.msg.thread_state.cpu, expected 0, is %d",
        last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {
          (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 2452,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 2452, is %d",
                  last_msg.msg.thread_state.stack_free);
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23, 0, 195, 4, 26, 105, 100, 108, 101, 0, 0,  0, 0, 0, 0,   0,
        0,  0,  0, 0,   0, 0,  0,   0,   0,   228, 1, 36, 0, 0, 0, 225, 18,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 484;

    {
      const char assign_string[] = {
          (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 36;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.thread_state.cpu == 484,
                  "incorrect value for last_msg.msg.thread_state.cpu, expected "
                  "484, is %d",
                  last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {
          (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 36,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 36, is %d",
                  last_msg.msg.thread_state.stack_free);
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23, 0, 195, 4, 26, 78, 65, 80, 32,  73, 83, 82, 0, 0, 0,   0,
        0,  0,  0, 0,   0, 0,  0,  0,  0,  138, 1,  92, 7,  0, 0, 166, 116,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 394;

    {
      const char assign_string[] = {
          (char)78, (char)65, (char)80, (char)32, (char)73, (char)83, (char)82,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 1884;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.thread_state.cpu == 394,
                  "incorrect value for last_msg.msg.thread_state.cpu, expected "
                  "394, is %d",
                  last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {
          (char)78, (char)65, (char)80, (char)32, (char)73, (char)83, (char)82,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 1884,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 1884, is %d",
                  last_msg.msg.thread_state.stack_free);
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23, 0, 195, 4, 26, 83, 66, 80, 0, 0, 0, 0,  0, 0, 0,   0,
        0,  0,  0, 0,   0, 0,  0,  0,  0,  1, 0, 4, 12, 0, 0, 229, 174,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 1;

    {
      const char assign_string[] = {
          (char)83, (char)66, (char)80, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 3076;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.thread_state.cpu == 1,
        "incorrect value for last_msg.msg.thread_state.cpu, expected 1, is %d",
        last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {
          (char)83, (char)66, (char)80, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 3076,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 3076, is %d",
                  last_msg.msg.thread_state.stack_free);
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23, 0, 195, 4, 26, 109, 97, 110, 97, 103, 101, 32, 97, 99, 113, 0,
        0,  0,  0, 0,   0, 0,  0,   0,  0,   10, 0,   124, 9,  0,  0,  52,  2,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 10;

    {
      const char assign_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                    (char)103, (char)101, (char)32,  (char)97,
                                    (char)99,  (char)113, (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 2428;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.thread_state.cpu == 10,
        "incorrect value for last_msg.msg.thread_state.cpu, expected 10, is %d",
        last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                   (char)103, (char)101, (char)32,  (char)97,
                                   (char)99,  (char)113, (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 2428,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 2428, is %d",
                  last_msg.msg.thread_state.stack_free);
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

    sbp_callback_register(&sbp_state, 0x17, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 23,  0,   195, 4,  26,  109, 97, 110, 97, 103, 101,
        32, 116, 114, 97,  99, 107, 0,   0,  0,   0,  0,   0,
        0,  0,   0,   0,   28, 9,   0,   0,  122, 54,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.thread_state.cpu = 0;

    {
      const char assign_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                    (char)103, (char)101, (char)32,  (char)116,
                                    (char)114, (char)97,  (char)99,  (char)107,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.thread_state.name, assign_string, sizeof(assign_string));
    }

    test_msg.thread_state.stack_free = 2332;

    sbp_message_send(&sbp_state, SbpMsgThreadState, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgThreadState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.thread_state.cpu == 0,
        "incorrect value for last_msg.msg.thread_state.cpu, expected 0, is %d",
        last_msg.msg.thread_state.cpu);

    {
      const char check_string[] = {(char)109, (char)97,  (char)110, (char)97,
                                   (char)103, (char)101, (char)32,  (char)116,
                                   (char)114, (char)97,  (char)99,  (char)107,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0};
      ck_assert_msg(memcmp(&last_msg.msg.thread_state.name, check_string,
                           sizeof(check_string)) == 0,
                    "incorrect value for last_msg.msg.thread_state.name, "
                    "expected string '%s', is '%s'",
                    check_string, last_msg.msg.thread_state.name);
    }

    ck_assert_msg(last_msg.msg.thread_state.stack_free == 2332,
                  "incorrect value for last_msg.msg.thread_state.stack_free, "
                  "expected 2332, is %d",
                  last_msg.msg.thread_state.stack_free);
  }
}
END_TEST

Suite *auto_check_sbp_piksi_MsgThreadState_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_piksi_MsgThreadState");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_piksi_MsgThreadState");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_MsgThreadState);
  suite_add_tcase(s, tc_acq);
  return s;
}