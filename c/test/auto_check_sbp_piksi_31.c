/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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
#include <piksi.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 payload[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_payload;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 payload_len;
  u8 payload[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  sbp_msg_t msg;
  void *context;
} last_unpacked;

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
  memset(&last_payload, 0, sizeof(last_payload));
  memset(&last_frame, 0, sizeof(last_frame));
  memset(&last_unpacked, 0, sizeof(last_unpacked));
}

static void payload_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_payload.n_callbacks_logged++;
  last_payload.sender_id = sender_id;
  last_payload.len = len;
  last_payload.context = context;
  memcpy(last_payload.payload, msg, len);

  /*printy_callback(sender_id, len, msg);*/
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 payload_len,
                           u8 payload[], u16 frame_len, u8 frame[],
                           void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.payload_len = payload_len;
  memcpy(last_frame.payload, payload, payload_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

static void unpacked_callback(u16 sender_id, u16 msg_type, const sbp_msg_t *msg,
                              void *context) {
  last_unpacked.n_callbacks_logged++;
  last_unpacked.sender_id = sender_id;
  last_unpacked.msg_type = msg_type;
  memcpy(&last_unpacked.msg, msg, sizeof(*msg));
  last_unpacked.context = context;
}

START_TEST(test_auto_check_sbp_piksi_31) {
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;
  static sbp_msg_callbacks_node_t n3;

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

    sbp_register_callback(&sbp_state, 0x17, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x17, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x17, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 23, 0, 246, 215, 26, 109, 97, 105, 110, 0, 0,   0, 0, 0, 0,  0,
        0,  0,  0, 0,   0,   0,  0,   0,  0,   0,   0, 156, 9, 0, 0, 73, 138,
    };
    u8 test_encoded_payload_data[] = {
        109, 97, 105, 110, 0, 0, 0, 0, 0, 0,   0, 0, 0,
        0,   0,  0,   0,   0, 0, 0, 0, 0, 156, 9, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_thread_state_t *test_msg =
        (sbp_msg_thread_state_t *)&test_msg_storage;
    test_msg->cpu = 0;
    {
      char test_string[] = {(char)109, (char)97, (char)105, (char)110, (char)0,
                            (char)0,   (char)0,  (char)0,   (char)0,   (char)0,
                            (char)0,   (char)0,  (char)0,   (char)0,   (char)0,
                            (char)0,   (char)0,  (char)0,   (char)0,   (char)0};
      memcpy(test_msg->name, test_string, sizeof(test_string));
    }
    test_msg->stack_free = 2460;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x17, 55286, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_thread_state_t *check_msg =
        (sbp_msg_thread_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->cpu == 0,
                  "incorrect value for cpu, expected 0, is %d", check_msg->cpu);
    {
      char check_string[] = {
          (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 2460,
                  "incorrect value for stack_free, expected 2460, is %d",
                  check_msg->stack_free);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x17, 55286,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->cpu == 0,
                  "incorrect value for cpu, expected 0, is %d", check_msg->cpu);
    {
      char check_string[] = {
          (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0,   (char)0, (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)109, (char)97, (char)105, (char)110, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 2460,
                  "incorrect value for stack_free, expected 2460, is %d",
                  check_msg->stack_free);
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

    sbp_register_callback(&sbp_state, 0x17, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x17, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x17, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 23, 0, 246, 215, 26, 105, 100, 108, 101, 0, 0,  0, 0, 0, 0,   0,
        0,  0,  0, 0,   0,   0,  0,   0,   0,   83,  2, 36, 0, 0, 0, 151, 20,
    };
    u8 test_encoded_payload_data[] = {
        105, 100, 108, 101, 0, 0, 0, 0,  0, 0,  0, 0, 0,
        0,   0,   0,   0,   0, 0, 0, 83, 2, 36, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_thread_state_t *test_msg =
        (sbp_msg_thread_state_t *)&test_msg_storage;
    test_msg->cpu = 595;
    {
      char test_string[] = {
          (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
      memcpy(test_msg->name, test_string, sizeof(test_string));
    }
    test_msg->stack_free = 36;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x17, 55286, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_thread_state_t *check_msg =
        (sbp_msg_thread_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->cpu == 595,
                  "incorrect value for cpu, expected 595, is %d",
                  check_msg->cpu);
    {
      char check_string[] = {
          (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 36,
                  "incorrect value for stack_free, expected 36, is %d",
                  check_msg->stack_free);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x17, 55286,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->cpu == 595,
                  "incorrect value for cpu, expected 595, is %d",
                  check_msg->cpu);
    {
      char check_string[] = {
          (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0, (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)105, (char)100, (char)108, (char)101, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 36,
                  "incorrect value for stack_free, expected 36, is %d",
                  check_msg->stack_free);
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

    sbp_register_callback(&sbp_state, 0x17, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x17, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x17, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 23, 0, 246, 215, 26, 78, 65, 80, 32, 73, 83,  82, 0, 0, 0,   0,
        0,  0,  0, 0,   0,   0,  0,  0,  0,  14, 0,  116, 4,  0, 0, 226, 60,
    };
    u8 test_encoded_payload_data[] = {
        78, 65, 80, 32, 73, 83, 82, 0,  0, 0,   0, 0, 0,
        0,  0,  0,  0,  0,  0,  0,  14, 0, 116, 4, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_thread_state_t *test_msg =
        (sbp_msg_thread_state_t *)&test_msg_storage;
    test_msg->cpu = 14;
    {
      char test_string[] = {(char)78, (char)65, (char)80, (char)32, (char)73,
                            (char)83, (char)82, (char)0,  (char)0,  (char)0,
                            (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
                            (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      memcpy(test_msg->name, test_string, sizeof(test_string));
    }
    test_msg->stack_free = 1140;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x17, 55286, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_thread_state_t *check_msg =
        (sbp_msg_thread_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->cpu == 14,
                  "incorrect value for cpu, expected 14, is %d",
                  check_msg->cpu);
    {
      char check_string[] = {(char)78, (char)65, (char)80, (char)32, (char)73,
                             (char)83, (char)82, (char)0,  (char)0,  (char)0,
                             (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
                             (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)78, (char)65, (char)80, (char)32, (char)73, (char)83, (char)82,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 1140,
                  "incorrect value for stack_free, expected 1140, is %d",
                  check_msg->stack_free);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x17, 55286,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->cpu == 14,
                  "incorrect value for cpu, expected 14, is %d",
                  check_msg->cpu);
    {
      char check_string[] = {(char)78, (char)65, (char)80, (char)32, (char)73,
                             (char)83, (char)82, (char)0,  (char)0,  (char)0,
                             (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
                             (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)78, (char)65, (char)80, (char)32, (char)73, (char)83, (char)82,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 1140,
                  "incorrect value for stack_free, expected 1140, is %d",
                  check_msg->stack_free);
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

    sbp_register_callback(&sbp_state, 0x17, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x17, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x17, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 23, 0, 246, 215, 26, 83, 66, 80, 0, 0, 0,   0,  0, 0, 0,  0,
        0,  0,  0, 0,   0,   0,  0,  0,  0,  1, 0, 196, 19, 0, 0, 90, 169,
    };
    u8 test_encoded_payload_data[] = {
        83, 66, 80, 0, 0, 0, 0, 0, 0, 0,   0,  0, 0,
        0,  0,  0,  0, 0, 0, 0, 1, 0, 196, 19, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_thread_state_t *test_msg =
        (sbp_msg_thread_state_t *)&test_msg_storage;
    test_msg->cpu = 1;
    {
      char test_string[] = {(char)83, (char)66, (char)80, (char)0, (char)0,
                            (char)0,  (char)0,  (char)0,  (char)0, (char)0,
                            (char)0,  (char)0,  (char)0,  (char)0, (char)0,
                            (char)0,  (char)0,  (char)0,  (char)0, (char)0};
      memcpy(test_msg->name, test_string, sizeof(test_string));
    }
    test_msg->stack_free = 5060;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x17, 55286, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_thread_state_t *check_msg =
        (sbp_msg_thread_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->cpu == 1,
                  "incorrect value for cpu, expected 1, is %d", check_msg->cpu);
    {
      char check_string[] = {(char)83, (char)66, (char)80, (char)0, (char)0,
                             (char)0,  (char)0,  (char)0,  (char)0, (char)0,
                             (char)0,  (char)0,  (char)0,  (char)0, (char)0,
                             (char)0,  (char)0,  (char)0,  (char)0, (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)83, (char)66, (char)80, (char)0, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 5060,
                  "incorrect value for stack_free, expected 5060, is %d",
                  check_msg->stack_free);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x17, 55286,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->cpu == 1,
                  "incorrect value for cpu, expected 1, is %d", check_msg->cpu);
    {
      char check_string[] = {(char)83, (char)66, (char)80, (char)0, (char)0,
                             (char)0,  (char)0,  (char)0,  (char)0, (char)0,
                             (char)0,  (char)0,  (char)0,  (char)0, (char)0,
                             (char)0,  (char)0,  (char)0,  (char)0, (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)83, (char)66, (char)80, (char)0, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 5060,
                  "incorrect value for stack_free, expected 5060, is %d",
                  check_msg->stack_free);
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

    sbp_register_callback(&sbp_state, 0x17, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x17, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x17, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 23, 0,  246, 215, 26, 109, 97, 110, 97, 103, 101,
        32, 97, 99, 113, 0,   0,  0,   0,  0,   0,  0,   0,
        0,  0,  7,  0,   20,  9,  0,   0,  47,  75,
    };
    u8 test_encoded_payload_data[] = {
        109, 97, 110, 97, 103, 101, 32, 97, 99, 113, 0, 0, 0,
        0,   0,  0,   0,  0,   0,   0,  7,  0,  20,  9, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_thread_state_t *test_msg =
        (sbp_msg_thread_state_t *)&test_msg_storage;
    test_msg->cpu = 7;
    {
      char test_string[] = {(char)109, (char)97, (char)110, (char)97, (char)103,
                            (char)101, (char)32, (char)97,  (char)99, (char)113,
                            (char)0,   (char)0,  (char)0,   (char)0,  (char)0,
                            (char)0,   (char)0,  (char)0,   (char)0,  (char)0};
      memcpy(test_msg->name, test_string, sizeof(test_string));
    }
    test_msg->stack_free = 2324;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x17, 55286, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_thread_state_t *check_msg =
        (sbp_msg_thread_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->cpu == 7,
                  "incorrect value for cpu, expected 7, is %d", check_msg->cpu);
    {
      char check_string[] = {(char)109, (char)97,  (char)110, (char)97,
                             (char)103, (char)101, (char)32,  (char)97,
                             (char)99,  (char)113, (char)0,   (char)0,
                             (char)0,   (char)0,   (char)0,   (char)0,
                             (char)0,   (char)0,   (char)0,   (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)109, (char)97, (char)110, (char)97, (char)103, (char)101,
          (char)32, (char)97, (char)99, (char)113, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 2324,
                  "incorrect value for stack_free, expected 2324, is %d",
                  check_msg->stack_free);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x17, 55286,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->cpu == 7,
                  "incorrect value for cpu, expected 7, is %d", check_msg->cpu);
    {
      char check_string[] = {(char)109, (char)97,  (char)110, (char)97,
                             (char)103, (char)101, (char)32,  (char)97,
                             (char)99,  (char)113, (char)0,   (char)0,
                             (char)0,   (char)0,   (char)0,   (char)0,
                             (char)0,   (char)0,   (char)0,   (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)109, (char)97, (char)110, (char)97, (char)103, (char)101,
          (char)32, (char)97, (char)99, (char)113, (char)0, (char)0, (char)0,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 2324,
                  "incorrect value for stack_free, expected 2324, is %d",
                  check_msg->stack_free);
  }
}
END_TEST

Suite *auto_check_sbp_piksi_31_suite(void) {
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_piksi_31");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_piksi_31");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_31);
  suite_add_tcase(s, tc_acq);
  return s;
}