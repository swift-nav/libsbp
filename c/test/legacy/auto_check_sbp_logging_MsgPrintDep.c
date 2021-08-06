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
#include <libsbp/legacy/logging.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void* context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void* context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void* last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8* buff, u32 n, void* context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8* buff, u32 n, void* context) {
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

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void* context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void* context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_logging_MsgPrintDep) {
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

    sbp_payload_callback_register(&sbp_state, 0x10, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x10, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  16,  0,   34, 34, 43, 73, 78, 70, 79, 58,  32,  97,
        99,  113, 58,  32, 80, 82, 78, 32, 49, 53, 32,  102, 111,
        117, 110, 100, 32, 64, 32, 45, 50, 52, 57, 55,  32,  72,
        122, 44,  32,  50, 48, 32, 83, 78, 82, 10, 116, 103,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_print_dep_t* test_msg = (msg_print_dep_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    {
      const char assign_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
          (char)97,  (char)99,  (char)113, (char)58,  (char)32,  (char)80,
          (char)82,  (char)78,  (char)32,  (char)49,  (char)53,  (char)32,
          (char)102, (char)111, (char)117, (char)110, (char)100, (char)32,
          (char)64,  (char)32,  (char)45,  (char)50,  (char)52,  (char)57,
          (char)55,  (char)32,  (char)72,  (char)122, (char)44,  (char)32,
          (char)50,  (char)48,  (char)32,  (char)83,  (char)78,  (char)82,
          (char)10};
      memcpy(test_msg->text, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->text) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_payload_send(&sbp_state, 0x10, 8738, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 8738,
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
    ck_assert_msg(last_frame.sender_id == 8738,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x10,
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
    msg_print_dep_t* check_msg = (msg_print_dep_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    {
      const char check_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
          (char)97,  (char)99,  (char)113, (char)58,  (char)32,  (char)80,
          (char)82,  (char)78,  (char)32,  (char)49,  (char)53,  (char)32,
          (char)102, (char)111, (char)117, (char)110, (char)100, (char)32,
          (char)64,  (char)32,  (char)45,  (char)50,  (char)52,  (char)57,
          (char)55,  (char)32,  (char)72,  (char)122, (char)44,  (char)32,
          (char)50,  (char)48,  (char)32,  (char)83,  (char)78,  (char)82,
          (char)10};
      ck_assert_msg(
          memcmp(check_msg->text, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->text, expected string '%s', is '%s'",
          check_string, check_msg->text);
    }
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

    sbp_payload_callback_register(&sbp_state, 0x10, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x10, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  16,  0,   34, 34, 42, 73, 78, 70, 79,  58, 32,  97,
        99,  113, 58,  32, 80, 82, 78, 32, 51, 49,  32, 102, 111,
        117, 110, 100, 32, 64, 32, 52, 50, 52, 53,  32, 72,  122,
        44,  32,  50,  49, 32, 83, 78, 82, 10, 140, 43,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_print_dep_t* test_msg = (msg_print_dep_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    {
      const char assign_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
          (char)97,  (char)99,  (char)113, (char)58,  (char)32,  (char)80,
          (char)82,  (char)78,  (char)32,  (char)51,  (char)49,  (char)32,
          (char)102, (char)111, (char)117, (char)110, (char)100, (char)32,
          (char)64,  (char)32,  (char)52,  (char)50,  (char)52,  (char)53,
          (char)32,  (char)72,  (char)122, (char)44,  (char)32,  (char)50,
          (char)49,  (char)32,  (char)83,  (char)78,  (char)82,  (char)10};
      memcpy(test_msg->text, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->text) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_payload_send(&sbp_state, 0x10, 8738, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 8738,
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
    ck_assert_msg(last_frame.sender_id == 8738,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x10,
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
    msg_print_dep_t* check_msg = (msg_print_dep_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    {
      const char check_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
          (char)97,  (char)99,  (char)113, (char)58,  (char)32,  (char)80,
          (char)82,  (char)78,  (char)32,  (char)51,  (char)49,  (char)32,
          (char)102, (char)111, (char)117, (char)110, (char)100, (char)32,
          (char)64,  (char)32,  (char)52,  (char)50,  (char)52,  (char)53,
          (char)32,  (char)72,  (char)122, (char)44,  (char)32,  (char)50,
          (char)49,  (char)32,  (char)83,  (char)78,  (char)82,  (char)10};
      ck_assert_msg(
          memcmp(check_msg->text, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->text, expected string '%s', is '%s'",
          check_string, check_msg->text);
    }
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

    sbp_payload_callback_register(&sbp_state, 0x10, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x10, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
        97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
        48, 32, 40,  80,  82,  78,  32, 49, 49,  41, 10,  23,  143,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_print_dep_t* test_msg = (msg_print_dep_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    {
      const char assign_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
          (char)68,  (char)105, (char)115, (char)97,  (char)98,  (char)108,
          (char)105, (char)110, (char)103, (char)32,  (char)99,  (char)104,
          (char)97,  (char)110, (char)110, (char)101, (char)108, (char)32,
          (char)48,  (char)32,  (char)40,  (char)80,  (char)82,  (char)78,
          (char)32,  (char)49,  (char)49,  (char)41,  (char)10};
      memcpy(test_msg->text, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->text) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_payload_send(&sbp_state, 0x10, 8738, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 8738,
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
    ck_assert_msg(last_frame.sender_id == 8738,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x10,
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
    msg_print_dep_t* check_msg = (msg_print_dep_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    {
      const char check_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
          (char)68,  (char)105, (char)115, (char)97,  (char)98,  (char)108,
          (char)105, (char)110, (char)103, (char)32,  (char)99,  (char)104,
          (char)97,  (char)110, (char)110, (char)101, (char)108, (char)32,
          (char)48,  (char)32,  (char)40,  (char)80,  (char)82,  (char)78,
          (char)32,  (char)49,  (char)49,  (char)41,  (char)10};
      ck_assert_msg(
          memcmp(check_msg->text, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->text, expected string '%s', is '%s'",
          check_string, check_msg->text);
    }
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

    sbp_payload_callback_register(&sbp_state, 0x10, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x10, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  16,  0,  34, 34, 41, 73, 78, 70,  79, 58,  32,  97,
        99,  113, 58, 32, 80, 82, 78, 32, 50,  32, 102, 111, 117,
        110, 100, 32, 64, 32, 51, 57, 57, 54,  32, 72,  122, 44,
        32,  50,  48, 32, 83, 78, 82, 10, 239, 48,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_print_dep_t* test_msg = (msg_print_dep_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    {
      const char assign_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58, (char)32,
          (char)97,  (char)99,  (char)113, (char)58,  (char)32, (char)80,
          (char)82,  (char)78,  (char)32,  (char)50,  (char)32, (char)102,
          (char)111, (char)117, (char)110, (char)100, (char)32, (char)64,
          (char)32,  (char)51,  (char)57,  (char)57,  (char)54, (char)32,
          (char)72,  (char)122, (char)44,  (char)32,  (char)50, (char)48,
          (char)32,  (char)83,  (char)78,  (char)82,  (char)10};
      memcpy(test_msg->text, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->text) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_payload_send(&sbp_state, 0x10, 8738, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 8738,
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
    ck_assert_msg(last_frame.sender_id == 8738,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x10,
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
    msg_print_dep_t* check_msg = (msg_print_dep_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    {
      const char check_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58, (char)32,
          (char)97,  (char)99,  (char)113, (char)58,  (char)32, (char)80,
          (char)82,  (char)78,  (char)32,  (char)50,  (char)32, (char)102,
          (char)111, (char)117, (char)110, (char)100, (char)32, (char)64,
          (char)32,  (char)51,  (char)57,  (char)57,  (char)54, (char)32,
          (char)72,  (char)122, (char)44,  (char)32,  (char)50, (char)48,
          (char)32,  (char)83,  (char)78,  (char)82,  (char)10};
      ck_assert_msg(
          memcmp(check_msg->text, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->text, expected string '%s', is '%s'",
          check_string, check_msg->text);
    }
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

    sbp_payload_callback_register(&sbp_state, 0x10, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x10, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  16,  0,  34, 34, 42, 73, 78, 70, 79, 58,  32,  97,
        99,  113, 58, 32, 80, 82, 78, 32, 52, 32, 102, 111, 117,
        110, 100, 32, 64, 32, 45, 55, 52, 57, 50, 32,  72,  122,
        44,  32,  50, 48, 32, 83, 78, 82, 10, 47, 248,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_print_dep_t* test_msg = (msg_print_dep_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    {
      const char assign_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58, (char)32,
          (char)97,  (char)99,  (char)113, (char)58,  (char)32, (char)80,
          (char)82,  (char)78,  (char)32,  (char)52,  (char)32, (char)102,
          (char)111, (char)117, (char)110, (char)100, (char)32, (char)64,
          (char)32,  (char)45,  (char)55,  (char)52,  (char)57, (char)50,
          (char)32,  (char)72,  (char)122, (char)44,  (char)32, (char)50,
          (char)48,  (char)32,  (char)83,  (char)78,  (char)82, (char)10};
      memcpy(test_msg->text, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->text) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_payload_send(&sbp_state, 0x10, 8738, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 8738,
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
    ck_assert_msg(last_frame.sender_id == 8738,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x10,
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
    msg_print_dep_t* check_msg = (msg_print_dep_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    {
      const char check_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58, (char)32,
          (char)97,  (char)99,  (char)113, (char)58,  (char)32, (char)80,
          (char)82,  (char)78,  (char)32,  (char)52,  (char)32, (char)102,
          (char)111, (char)117, (char)110, (char)100, (char)32, (char)64,
          (char)32,  (char)45,  (char)55,  (char)52,  (char)57, (char)50,
          (char)32,  (char)72,  (char)122, (char)44,  (char)32, (char)50,
          (char)48,  (char)32,  (char)83,  (char)78,  (char)82, (char)10};
      ck_assert_msg(
          memcmp(check_msg->text, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->text, expected string '%s', is '%s'",
          check_string, check_msg->text);
    }
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

    sbp_payload_callback_register(&sbp_state, 0x10, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x10, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
        97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
        49, 32, 40,  80,  82,  78,  32, 49, 53,  41, 10,  158, 139,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_print_dep_t* test_msg = (msg_print_dep_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    {
      const char assign_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
          (char)68,  (char)105, (char)115, (char)97,  (char)98,  (char)108,
          (char)105, (char)110, (char)103, (char)32,  (char)99,  (char)104,
          (char)97,  (char)110, (char)110, (char)101, (char)108, (char)32,
          (char)49,  (char)32,  (char)40,  (char)80,  (char)82,  (char)78,
          (char)32,  (char)49,  (char)53,  (char)41,  (char)10};
      memcpy(test_msg->text, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->text) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_payload_send(&sbp_state, 0x10, 8738, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 8738,
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
    ck_assert_msg(last_frame.sender_id == 8738,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x10,
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
    msg_print_dep_t* check_msg = (msg_print_dep_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    {
      const char check_string[] = {
          (char)73,  (char)78,  (char)70,  (char)79,  (char)58,  (char)32,
          (char)68,  (char)105, (char)115, (char)97,  (char)98,  (char)108,
          (char)105, (char)110, (char)103, (char)32,  (char)99,  (char)104,
          (char)97,  (char)110, (char)110, (char)101, (char)108, (char)32,
          (char)49,  (char)32,  (char)40,  (char)80,  (char)82,  (char)78,
          (char)32,  (char)49,  (char)53,  (char)41,  (char)10};
      ck_assert_msg(
          memcmp(check_msg->text, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->text, expected string '%s', is '%s'",
          check_string, check_msg->text);
    }
  }
}
END_TEST

Suite* legacy_auto_check_sbp_logging_MsgPrintDep_suite(void) {
  Suite* s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_logging_MsgPrintDep");
  TCase* tc_acq =
      tcase_create("Automated_Suite_legacy_auto_check_sbp_logging_MsgPrintDep");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_logging_MsgPrintDep);
  suite_add_tcase(s, tc_acq);
  return s;
}