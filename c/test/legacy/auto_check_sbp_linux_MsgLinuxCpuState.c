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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxCpuState.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/api.h>
#include <libsbp/legacy/compat.h>
#include <libsbp/legacy/linux.h>

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return real_n;
}

static void logging_reset() {
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_linux_MsgLinuxCpuState) {
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;

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

    sbp_payload_callback_register(&sbp_state, 0x7f08, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x7f08, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  8,   127, 148, 133, 70,  101, 122, 195, 98,  215, 35,  94,
        235, 20,  112, 114, 111, 99,  101, 115, 115, 45,  110, 97,  109,
        101, 0,   0,   0,   47,  112, 97,  116, 104, 47,  116, 111, 47,
        112, 114, 111, 99,  101, 115, 115, 45,  110, 97,  109, 101, 32,
        97,  114, 103, 48,  32,  97,  114, 103, 49,  32,  97,  114, 103,
        50,  32,  97,  114, 103, 51,  32,  97,  114, 103, 52,  68,  229,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_linux_cpu_state_t *test_msg = (msg_linux_cpu_state_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    {
      const char assign_string[] = {
          (char)47,  (char)112, (char)97,  (char)116, (char)104, (char)47,
          (char)116, (char)111, (char)47,  (char)112, (char)114, (char)111,
          (char)99,  (char)101, (char)115, (char)115, (char)45,  (char)110,
          (char)97,  (char)109, (char)101, (char)32,  (char)97,  (char)114,
          (char)103, (char)48,  (char)32,  (char)97,  (char)114, (char)103,
          (char)49,  (char)32,  (char)97,  (char)114, (char)103, (char)50,
          (char)32,  (char)97,  (char)114, (char)103, (char)51,  (char)32,
          (char)97,  (char)114, (char)103, (char)52};
      memcpy(test_msg->cmdline, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->cmdline) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    test_msg->flags = 20;
    test_msg->index = 101;
    test_msg->pcpu = 98;
    test_msg->pid = 50042;
    test_msg->time = 3948815319;
    {
      const char assign_string[] = {(char)112, (char)114, (char)111, (char)99,
                                    (char)101, (char)115, (char)115, (char)45,
                                    (char)110, (char)97,  (char)109, (char)101,
                                    (char)0,   (char)0,   (char)0};
      memcpy(test_msg->tname, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->tname) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_payload_send(&sbp_state, 0x7f08, 34196, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 34196,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 34196,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x7f08,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_linux_cpu_state_t *check_msg =
        (msg_linux_cpu_state_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    {
      const char check_string[] = {
          (char)47,  (char)112, (char)97,  (char)116, (char)104, (char)47,
          (char)116, (char)111, (char)47,  (char)112, (char)114, (char)111,
          (char)99,  (char)101, (char)115, (char)115, (char)45,  (char)110,
          (char)97,  (char)109, (char)101, (char)32,  (char)97,  (char)114,
          (char)103, (char)48,  (char)32,  (char)97,  (char)114, (char)103,
          (char)49,  (char)32,  (char)97,  (char)114, (char)103, (char)50,
          (char)32,  (char)97,  (char)114, (char)103, (char)51,  (char)32,
          (char)97,  (char)114, (char)103, (char)52};
      ck_assert_msg(
          memcmp(check_msg->cmdline, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->cmdline, expected string '%s', is "
          "'%s'",
          check_string, check_msg->cmdline);
    }
    ck_assert_msg(check_msg->flags == 20,
                  "incorrect value for flags, expected 20, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->index == 101,
                  "incorrect value for index, expected 101, is %d",
                  check_msg->index);
    ck_assert_msg(check_msg->pcpu == 98,
                  "incorrect value for pcpu, expected 98, is %d",
                  check_msg->pcpu);
    ck_assert_msg(check_msg->pid == 50042,
                  "incorrect value for pid, expected 50042, is %d",
                  check_msg->pid);
    ck_assert_msg(check_msg->time == 3948815319,
                  "incorrect value for time, expected 3948815319, is %d",
                  check_msg->time);
    {
      const char check_string[] = {(char)112, (char)114, (char)111, (char)99,
                                   (char)101, (char)115, (char)115, (char)45,
                                   (char)110, (char)97,  (char)109, (char)101,
                                   (char)0,   (char)0,   (char)0};
      ck_assert_msg(
          memcmp(check_msg->tname, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->tname, expected string '%s', is '%s'",
          check_string, check_msg->tname);
    }
  }
}
END_TEST

Suite *legacy_auto_check_sbp_linux_MsgLinuxCpuState_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_linux_MsgLinuxCpuState");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_linux_MsgLinuxCpuState");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_linux_MsgLinuxCpuState);
  suite_add_tcase(s, tc_acq);
  return s;
}