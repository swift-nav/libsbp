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
// spec/tests/yaml/swiftnav/sbp/test_piksi.yaml by generate.py. Do not modify by
// hand!

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

START_TEST(test_auto_check_sbp_piksi_46) {
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
        85, 23, 0, 195, 4, 26, 109, 97, 105, 110, 0, 0,   0, 0, 0, 0,   0,
        0,  0,  0, 0,   0, 0,  0,   0,  0,   0,   0, 148, 9, 0, 0, 195, 212,
    };
    u8 test_encoded_payload_data[] = {
        109, 97, 105, 110, 0, 0, 0, 0, 0, 0,   0, 0, 0,
        0,   0,  0,   0,   0, 0, 0, 0, 0, 148, 9, 0, 0,
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
    test_msg->stack_free = 2452;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x17, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->stack_free == 2452,
                  "incorrect value for stack_free, expected 2452, is %d",
                  check_msg->stack_free);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x17, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->stack_free == 2452,
                  "incorrect value for stack_free, expected 2452, is %d",
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
        85, 23, 0, 195, 4, 26, 105, 100, 108, 101, 0, 0,  0, 0, 0, 0,   0,
        0,  0,  0, 0,   0, 0,  0,   0,   0,   228, 1, 36, 0, 0, 0, 225, 18,
    };
    u8 test_encoded_payload_data[] = {
        105, 100, 108, 101, 0, 0, 0, 0,   0, 0,  0, 0, 0,
        0,   0,   0,   0,   0, 0, 0, 228, 1, 36, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_thread_state_t *test_msg =
        (sbp_msg_thread_state_t *)&test_msg_storage;
    test_msg->cpu = 484;
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
    sbp_send_message(&sbp_state, 0x17, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->cpu == 484,
                  "incorrect value for cpu, expected 484, is %d",
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

    sbp_send_packed_message(&sbp_state, 0x17, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->cpu == 484,
                  "incorrect value for cpu, expected 484, is %d",
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
        85, 23, 0, 195, 4, 26, 78, 65, 80, 32,  73, 83, 82, 0, 0, 0,   0,
        0,  0,  0, 0,   0, 0,  0,  0,  0,  138, 1,  92, 7,  0, 0, 166, 116,
    };
    u8 test_encoded_payload_data[] = {
        78, 65, 80, 32, 73, 83, 82, 0,   0, 0,  0, 0, 0,
        0,  0,  0,  0,  0,  0,  0,  138, 1, 92, 7, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_thread_state_t *test_msg =
        (sbp_msg_thread_state_t *)&test_msg_storage;
    test_msg->cpu = 394;
    {
      char test_string[] = {(char)78, (char)65, (char)80, (char)32, (char)73,
                            (char)83, (char)82, (char)0,  (char)0,  (char)0,
                            (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
                            (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      memcpy(test_msg->name, test_string, sizeof(test_string));
    }
    test_msg->stack_free = 1884;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x17, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->cpu == 394,
                  "incorrect value for cpu, expected 394, is %d",
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
    ck_assert_msg(check_msg->stack_free == 1884,
                  "incorrect value for stack_free, expected 1884, is %d",
                  check_msg->stack_free);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x17, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->cpu == 394,
                  "incorrect value for cpu, expected 394, is %d",
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
    ck_assert_msg(check_msg->stack_free == 1884,
                  "incorrect value for stack_free, expected 1884, is %d",
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
        85, 23, 0, 195, 4, 26, 83, 66, 80, 0, 0, 0, 0,  0, 0, 0,   0,
        0,  0,  0, 0,   0, 0,  0,  0,  0,  1, 0, 4, 12, 0, 0, 229, 174,
    };
    u8 test_encoded_payload_data[] = {
        83, 66, 80, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0,
        0,  0,  0,  0, 0, 0, 0, 1, 0, 4, 12, 0, 0,
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
    test_msg->stack_free = 3076;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x17, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->stack_free == 3076,
                  "incorrect value for stack_free, expected 3076, is %d",
                  check_msg->stack_free);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x17, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->stack_free == 3076,
                  "incorrect value for stack_free, expected 3076, is %d",
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
        85, 23, 0, 195, 4, 26, 109, 97, 110, 97, 103, 101, 32, 97, 99, 113, 0,
        0,  0,  0, 0,   0, 0,  0,   0,  0,   10, 0,   124, 9,  0,  0,  52,  2,
    };
    u8 test_encoded_payload_data[] = {
        109, 97, 110, 97, 103, 101, 32, 97, 99, 113, 0, 0, 0,
        0,   0,  0,   0,  0,   0,   0,  10, 0,  124, 9, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_thread_state_t *test_msg =
        (sbp_msg_thread_state_t *)&test_msg_storage;
    test_msg->cpu = 10;
    {
      char test_string[] = {(char)109, (char)97, (char)110, (char)97, (char)103,
                            (char)101, (char)32, (char)97,  (char)99, (char)113,
                            (char)0,   (char)0,  (char)0,   (char)0,  (char)0,
                            (char)0,   (char)0,  (char)0,   (char)0,  (char)0};
      memcpy(test_msg->name, test_string, sizeof(test_string));
    }
    test_msg->stack_free = 2428;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x17, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->cpu == 10,
                  "incorrect value for cpu, expected 10, is %d",
                  check_msg->cpu);
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
    ck_assert_msg(check_msg->stack_free == 2428,
                  "incorrect value for stack_free, expected 2428, is %d",
                  check_msg->stack_free);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x17, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->cpu == 10,
                  "incorrect value for cpu, expected 10, is %d",
                  check_msg->cpu);
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
    ck_assert_msg(check_msg->stack_free == 2428,
                  "incorrect value for stack_free, expected 2428, is %d",
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
        85, 23,  0,   195, 4,  26,  109, 97, 110, 97, 103, 101,
        32, 116, 114, 97,  99, 107, 0,   0,  0,   0,  0,   0,
        0,  0,   0,   0,   28, 9,   0,   0,  122, 54,
    };
    u8 test_encoded_payload_data[] = {
        109, 97, 110, 97, 103, 101, 32, 116, 114, 97, 99, 107, 0,
        0,   0,  0,   0,  0,   0,   0,  0,   0,   28, 9,  0,   0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_thread_state_t *test_msg =
        (sbp_msg_thread_state_t *)&test_msg_storage;
    test_msg->cpu = 0;
    {
      char test_string[] = {(char)109, (char)97,  (char)110, (char)97,
                            (char)103, (char)101, (char)32,  (char)116,
                            (char)114, (char)97,  (char)99,  (char)107,
                            (char)0,   (char)0,   (char)0,   (char)0,
                            (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg->name, test_string, sizeof(test_string));
    }
    test_msg->stack_free = 2332;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x17, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
      char check_string[] = {(char)109, (char)97,  (char)110, (char)97,
                             (char)103, (char)101, (char)32,  (char)116,
                             (char)114, (char)97,  (char)99,  (char)107,
                             (char)0,   (char)0,   (char)0,   (char)0,
                             (char)0,   (char)0,   (char)0,   (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)109, (char)97, (char)110, (char)97, (char)103, (char)101,
          (char)32, (char)116, (char)114, (char)97, (char)99, (char)107,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          (char)0, check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 2332,
                  "incorrect value for stack_free, expected 2332, is %d",
                  check_msg->stack_free);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x17, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
      char check_string[] = {(char)109, (char)97,  (char)110, (char)97,
                             (char)103, (char)101, (char)32,  (char)116,
                             (char)114, (char)97,  (char)99,  (char)107,
                             (char)0,   (char)0,   (char)0,   (char)0,
                             (char)0,   (char)0,   (char)0,   (char)0};
      ck_assert_msg(
          memcmp(check_msg->name, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->name, expected string '%s', is '%s'",
          (char)109, (char)97, (char)110, (char)97, (char)103, (char)101,
          (char)32, (char)116, (char)114, (char)97, (char)99, (char)107,
          (char)0, (char)0, (char)0, (char)0, (char)0, (char)0, (char)0,
          (char)0, check_msg->name);
    }
    ck_assert_msg(check_msg->stack_free == 2332,
                  "incorrect value for stack_free, expected 2332, is %d",
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

    sbp_register_callback(&sbp_state, 0x18, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x18, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x18, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   154, 153, 57,  65,  0, 0, 0, 0,
        0,  0,  0, 0,   15,  0,   255, 255, 255, 255, 0, 0, 0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 247, 5,
    };
    u8 test_encoded_payload_data[] = {
        0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,
        0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   154, 153,
        57,  65, 0, 0, 0, 0, 0, 0, 0, 0,   15,  0,   255, 255, 255,
        255, 0,  0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_uart_state_depa_t *test_msg =
        (sbp_msg_uart_state_depa_t *)&test_msg_storage;
    test_msg->latency.avg = -1;
    test_msg->latency.current = -1;
    test_msg->latency.lmax = 0;
    test_msg->latency.lmin = 0;
    test_msg->uart_a.crc_error_count = 0;
    test_msg->uart_a.io_error_count = 0;
    test_msg->uart_a.rx_buffer_level = 0;
    test_msg->uart_a.rx_throughput = 0.0;
    test_msg->uart_a.tx_buffer_level = 0;
    test_msg->uart_a.tx_throughput = 0.0;
    test_msg->uart_b.crc_error_count = 0;
    test_msg->uart_b.io_error_count = 0;
    test_msg->uart_b.rx_buffer_level = 0;
    test_msg->uart_b.rx_throughput = 0.0;
    test_msg->uart_b.tx_buffer_level = 0;
    test_msg->uart_b.tx_throughput = 0.0;
    test_msg->uart_ftdi.crc_error_count = 0;
    test_msg->uart_ftdi.io_error_count = 0;
    test_msg->uart_ftdi.rx_buffer_level = 0;
    test_msg->uart_ftdi.rx_throughput = 0.0;
    test_msg->uart_ftdi.tx_buffer_level = 15;
    test_msg->uart_ftdi.tx_throughput = 11.600000381469727;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x18, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_uart_state_depa_t *check_msg =
        (sbp_msg_uart_state_depa_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 0,
        "incorrect value for uart_a.tx_buffer_level, expected 0, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0, is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 0,
        "incorrect value for uart_b.tx_buffer_level, expected 0, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.0, is %f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 15,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 15, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.tx_throughput * 100 - 11.6000003815 * 100) < 0.05,
        "incorrect value for uart_ftdi.tx_throughput, expected 11.6000003815, "
        "is %f",
        check_msg->uart_ftdi.tx_throughput);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x18, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 0,
        "incorrect value for uart_a.tx_buffer_level, expected 0, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0, is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 0,
        "incorrect value for uart_b.tx_buffer_level, expected 0, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.0, is %f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 15,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 15, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.tx_throughput * 100 - 11.6000003815 * 100) < 0.05,
        "incorrect value for uart_ftdi.tx_throughput, expected 11.6000003815, "
        "is %f",
        check_msg->uart_ftdi.tx_throughput);
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

    sbp_register_callback(&sbp_state, 0x18, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x18, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x18, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   2,   43,  135, 61,  0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   255, 255, 255, 255, 0, 0, 0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 65,  110,
    };
    u8 test_encoded_payload_data[] = {
        0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,
        0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   2,   43,
        135, 61, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   255, 255, 255,
        255, 0,  0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_uart_state_depa_t *test_msg =
        (sbp_msg_uart_state_depa_t *)&test_msg_storage;
    test_msg->latency.avg = -1;
    test_msg->latency.current = -1;
    test_msg->latency.lmax = 0;
    test_msg->latency.lmin = 0;
    test_msg->uart_a.crc_error_count = 0;
    test_msg->uart_a.io_error_count = 0;
    test_msg->uart_a.rx_buffer_level = 0;
    test_msg->uart_a.rx_throughput = 0.0;
    test_msg->uart_a.tx_buffer_level = 0;
    test_msg->uart_a.tx_throughput = 0.0;
    test_msg->uart_b.crc_error_count = 0;
    test_msg->uart_b.io_error_count = 0;
    test_msg->uart_b.rx_buffer_level = 0;
    test_msg->uart_b.rx_throughput = 0.0;
    test_msg->uart_b.tx_buffer_level = 0;
    test_msg->uart_b.tx_throughput = 0.0;
    test_msg->uart_ftdi.crc_error_count = 0;
    test_msg->uart_ftdi.io_error_count = 0;
    test_msg->uart_ftdi.rx_buffer_level = 0;
    test_msg->uart_ftdi.rx_throughput = 0.0;
    test_msg->uart_ftdi.tx_buffer_level = 0;
    test_msg->uart_ftdi.tx_throughput = 0.06599999964237213;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x18, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_uart_state_depa_t *check_msg =
        (sbp_msg_uart_state_depa_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 0,
        "incorrect value for uart_a.tx_buffer_level, expected 0, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0, is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 0,
        "incorrect value for uart_b.tx_buffer_level, expected 0, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.0, is %f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 0,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.tx_throughput * 100 -
                   0.0659999996424 * 100) < 0.05,
                  "incorrect value for uart_ftdi.tx_throughput, expected "
                  "0.0659999996424, is %f",
                  check_msg->uart_ftdi.tx_throughput);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x18, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 0,
        "incorrect value for uart_a.tx_buffer_level, expected 0, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0, is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 0,
        "incorrect value for uart_b.tx_buffer_level, expected 0, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.0, is %f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 0,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.tx_throughput * 100 -
                   0.0659999996424 * 100) < 0.05,
                  "incorrect value for uart_ftdi.tx_throughput, expected "
                  "0.0659999996424, is %f",
                  check_msg->uart_ftdi.tx_throughput);
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

    sbp_register_callback(&sbp_state, 0x18, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x18, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x18, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   4,   86,  14,  62,  0, 0, 0, 0,
        0,  0,  0, 0,   10,  0,   255, 255, 255, 255, 0, 0, 0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 198, 36,
    };
    u8 test_encoded_payload_data[] = {
        0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,
        0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   4,   86,
        14,  62, 0, 0, 0, 0, 0, 0, 0, 0,   10,  0,   255, 255, 255,
        255, 0,  0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_uart_state_depa_t *test_msg =
        (sbp_msg_uart_state_depa_t *)&test_msg_storage;
    test_msg->latency.avg = -1;
    test_msg->latency.current = -1;
    test_msg->latency.lmax = 0;
    test_msg->latency.lmin = 0;
    test_msg->uart_a.crc_error_count = 0;
    test_msg->uart_a.io_error_count = 0;
    test_msg->uart_a.rx_buffer_level = 0;
    test_msg->uart_a.rx_throughput = 0.0;
    test_msg->uart_a.tx_buffer_level = 0;
    test_msg->uart_a.tx_throughput = 0.0;
    test_msg->uart_b.crc_error_count = 0;
    test_msg->uart_b.io_error_count = 0;
    test_msg->uart_b.rx_buffer_level = 0;
    test_msg->uart_b.rx_throughput = 0.0;
    test_msg->uart_b.tx_buffer_level = 0;
    test_msg->uart_b.tx_throughput = 0.0;
    test_msg->uart_ftdi.crc_error_count = 0;
    test_msg->uart_ftdi.io_error_count = 0;
    test_msg->uart_ftdi.rx_buffer_level = 0;
    test_msg->uart_ftdi.rx_throughput = 0.0;
    test_msg->uart_ftdi.tx_buffer_level = 10;
    test_msg->uart_ftdi.tx_throughput = 0.13899999856948853;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x18, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_uart_state_depa_t *check_msg =
        (sbp_msg_uart_state_depa_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 0,
        "incorrect value for uart_a.tx_buffer_level, expected 0, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0, is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 0,
        "incorrect value for uart_b.tx_buffer_level, expected 0, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.0, is %f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 10,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 10, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.tx_throughput * 100 -
                   0.138999998569 * 100) < 0.05,
                  "incorrect value for uart_ftdi.tx_throughput, expected "
                  "0.138999998569, is %f",
                  check_msg->uart_ftdi.tx_throughput);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x18, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 0,
        "incorrect value for uart_a.tx_buffer_level, expected 0, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0, is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 0,
        "incorrect value for uart_b.tx_buffer_level, expected 0, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.0, is %f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 10,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 10, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.tx_throughput * 100 -
                   0.138999998569 * 100) < 0.05,
                  "incorrect value for uart_ftdi.tx_throughput, expected "
                  "0.138999998569, is %f",
                  check_msg->uart_ftdi.tx_throughput);
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

    sbp_register_callback(&sbp_state, 0x18, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x18, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x18, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   2,   43,  135, 61,  0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   255, 255, 255, 255, 0, 0, 0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 65,  110,
    };
    u8 test_encoded_payload_data[] = {
        0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,
        0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   2,   43,
        135, 61, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   255, 255, 255,
        255, 0,  0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_uart_state_depa_t *test_msg =
        (sbp_msg_uart_state_depa_t *)&test_msg_storage;
    test_msg->latency.avg = -1;
    test_msg->latency.current = -1;
    test_msg->latency.lmax = 0;
    test_msg->latency.lmin = 0;
    test_msg->uart_a.crc_error_count = 0;
    test_msg->uart_a.io_error_count = 0;
    test_msg->uart_a.rx_buffer_level = 0;
    test_msg->uart_a.rx_throughput = 0.0;
    test_msg->uart_a.tx_buffer_level = 0;
    test_msg->uart_a.tx_throughput = 0.0;
    test_msg->uart_b.crc_error_count = 0;
    test_msg->uart_b.io_error_count = 0;
    test_msg->uart_b.rx_buffer_level = 0;
    test_msg->uart_b.rx_throughput = 0.0;
    test_msg->uart_b.tx_buffer_level = 0;
    test_msg->uart_b.tx_throughput = 0.0;
    test_msg->uart_ftdi.crc_error_count = 0;
    test_msg->uart_ftdi.io_error_count = 0;
    test_msg->uart_ftdi.rx_buffer_level = 0;
    test_msg->uart_ftdi.rx_throughput = 0.0;
    test_msg->uart_ftdi.tx_buffer_level = 0;
    test_msg->uart_ftdi.tx_throughput = 0.06599999964237213;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x18, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_uart_state_depa_t *check_msg =
        (sbp_msg_uart_state_depa_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 0,
        "incorrect value for uart_a.tx_buffer_level, expected 0, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0, is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 0,
        "incorrect value for uart_b.tx_buffer_level, expected 0, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.0, is %f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 0,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.tx_throughput * 100 -
                   0.0659999996424 * 100) < 0.05,
                  "incorrect value for uart_ftdi.tx_throughput, expected "
                  "0.0659999996424, is %f",
                  check_msg->uart_ftdi.tx_throughput);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x18, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 0,
        "incorrect value for uart_a.tx_buffer_level, expected 0, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0, is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 0,
        "incorrect value for uart_b.tx_buffer_level, expected 0, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.0, is %f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 0,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.tx_throughput * 100 -
                   0.0659999996424 * 100) < 0.05,
                  "incorrect value for uart_ftdi.tx_throughput, expected "
                  "0.0659999996424, is %f",
                  check_msg->uart_ftdi.tx_throughput);
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

    sbp_register_callback(&sbp_state, 0x18, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x18, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x18, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   138, 75, 6, 60,
        0,  0,  0, 0,   0,   0,   80,  113, 201, 61,  0,   0,  0, 0,
        0,  0,  0, 0,   2,   0,   145, 237, 252, 62,  0,   0,  0, 0,
        0,  0,  0, 0,   38,  0,   255, 255, 255, 255, 0,   0,  0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 112, 111,
    };
    u8 test_encoded_payload_data[] = {
        0,   0,   0,  0, 138, 75, 6, 60, 0, 0,   0,   0,   0,   0,   80,
        113, 201, 61, 0, 0,   0,  0, 0,  0, 0,   0,   2,   0,   145, 237,
        252, 62,  0,  0, 0,   0,  0, 0,  0, 0,   38,  0,   255, 255, 255,
        255, 0,   0,  0, 0,   0,  0, 0,  0, 255, 255, 255, 255,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_uart_state_depa_t *test_msg =
        (sbp_msg_uart_state_depa_t *)&test_msg_storage;
    test_msg->latency.avg = -1;
    test_msg->latency.current = -1;
    test_msg->latency.lmax = 0;
    test_msg->latency.lmin = 0;
    test_msg->uart_a.crc_error_count = 0;
    test_msg->uart_a.io_error_count = 0;
    test_msg->uart_a.rx_buffer_level = 0;
    test_msg->uart_a.rx_throughput = 0.008196720853447914;
    test_msg->uart_a.tx_buffer_level = 0;
    test_msg->uart_a.tx_throughput = 0.0;
    test_msg->uart_b.crc_error_count = 0;
    test_msg->uart_b.io_error_count = 0;
    test_msg->uart_b.rx_buffer_level = 0;
    test_msg->uart_b.rx_throughput = 0.0;
    test_msg->uart_b.tx_buffer_level = 2;
    test_msg->uart_b.tx_throughput = 0.09836065769195557;
    test_msg->uart_ftdi.crc_error_count = 0;
    test_msg->uart_ftdi.io_error_count = 0;
    test_msg->uart_ftdi.rx_buffer_level = 0;
    test_msg->uart_ftdi.rx_throughput = 0.0;
    test_msg->uart_ftdi.tx_buffer_level = 38;
    test_msg->uart_ftdi.tx_throughput = 0.49399998784065247;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x18, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_uart_state_depa_t *check_msg =
        (sbp_msg_uart_state_depa_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.00819672085345 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.00819672085345, "
        "is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 0,
        "incorrect value for uart_a.tx_buffer_level, expected 0, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0, is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 2,
        "incorrect value for uart_b.tx_buffer_level, expected 2, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.098360657692 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.098360657692, is "
        "%f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 38,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 38, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.tx_throughput * 100 -
                   0.493999987841 * 100) < 0.05,
                  "incorrect value for uart_ftdi.tx_throughput, expected "
                  "0.493999987841, is %f",
                  check_msg->uart_ftdi.tx_throughput);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x18, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.00819672085345 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.00819672085345, "
        "is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 0,
        "incorrect value for uart_a.tx_buffer_level, expected 0, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0, is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 2,
        "incorrect value for uart_b.tx_buffer_level, expected 2, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.098360657692 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.098360657692, is "
        "%f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 38,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 38, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.tx_throughput * 100 -
                   0.493999987841 * 100) < 0.05,
                  "incorrect value for uart_ftdi.tx_throughput, expected "
                  "0.493999987841, is %f",
                  check_msg->uart_ftdi.tx_throughput);
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

    sbp_register_callback(&sbp_state, 0x18, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x18, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x18, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 24, 0, 195, 4,   58,  166, 155, 68,  60,  0, 0, 0, 0,
        0,  0,  0, 0,   2,   0,   166, 155, 68,  60,  0, 0, 0, 0,
        0,  0,  0, 0,   2,   0,   236, 81,  168, 63,  0, 0, 0, 0,
        0,  0,  0, 0,   50,  0,   255, 255, 255, 255, 0, 0, 0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 22,  72,
    };
    u8 test_encoded_payload_data[] = {
        166, 155, 68, 60, 0, 0, 0, 0, 0, 0,   0,   0,   2,   0,   166,
        155, 68,  60, 0,  0, 0, 0, 0, 0, 0,   0,   2,   0,   236, 81,
        168, 63,  0,  0,  0, 0, 0, 0, 0, 0,   50,  0,   255, 255, 255,
        255, 0,   0,  0,  0, 0, 0, 0, 0, 255, 255, 255, 255,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_uart_state_depa_t *test_msg =
        (sbp_msg_uart_state_depa_t *)&test_msg_storage;
    test_msg->latency.avg = -1;
    test_msg->latency.current = -1;
    test_msg->latency.lmax = 0;
    test_msg->latency.lmin = 0;
    test_msg->uart_a.crc_error_count = 0;
    test_msg->uart_a.io_error_count = 0;
    test_msg->uart_a.rx_buffer_level = 0;
    test_msg->uart_a.rx_throughput = 0.0;
    test_msg->uart_a.tx_buffer_level = 2;
    test_msg->uart_a.tx_throughput = 0.012000000104308128;
    test_msg->uart_b.crc_error_count = 0;
    test_msg->uart_b.io_error_count = 0;
    test_msg->uart_b.rx_buffer_level = 0;
    test_msg->uart_b.rx_throughput = 0.0;
    test_msg->uart_b.tx_buffer_level = 2;
    test_msg->uart_b.tx_throughput = 0.012000000104308128;
    test_msg->uart_ftdi.crc_error_count = 0;
    test_msg->uart_ftdi.io_error_count = 0;
    test_msg->uart_ftdi.rx_buffer_level = 0;
    test_msg->uart_ftdi.rx_throughput = 0.0;
    test_msg->uart_ftdi.tx_buffer_level = 50;
    test_msg->uart_ftdi.tx_throughput = 1.315000057220459;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x18, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_uart_state_depa_t *check_msg =
        (sbp_msg_uart_state_depa_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 2,
        "incorrect value for uart_a.tx_buffer_level, expected 2, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0120000001043 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0120000001043, "
        "is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 2,
        "incorrect value for uart_b.tx_buffer_level, expected 2, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.0120000001043 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.0120000001043, "
        "is %f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 50,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 50, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.tx_throughput * 100 - 1.31500005722 * 100) < 0.05,
        "incorrect value for uart_ftdi.tx_throughput, expected 1.31500005722, "
        "is %f",
        check_msg->uart_ftdi.tx_throughput);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x18, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 2,
        "incorrect value for uart_a.tx_buffer_level, expected 2, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.0120000001043 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.0120000001043, "
        "is %f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 2,
        "incorrect value for uart_b.tx_buffer_level, expected 2, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 0.0120000001043 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 0.0120000001043, "
        "is %f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 0,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f",
        check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 50,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 50, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.tx_throughput * 100 - 1.31500005722 * 100) < 0.05,
        "incorrect value for uart_ftdi.tx_throughput, expected 1.31500005722, "
        "is %f",
        check_msg->uart_ftdi.tx_throughput);
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

    sbp_register_callback(&sbp_state, 0x19, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x19, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x19, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 25, 0, 195, 4, 4, 0, 0, 0, 0, 18, 176,
    };
    u8 test_encoded_payload_data[] = {
        0,
        0,
        0,
        0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_iar_state_t *test_msg = (sbp_msg_iar_state_t *)&test_msg_storage;
    test_msg->num_hyps = 0;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x19, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_iar_state_t *check_msg = (sbp_msg_iar_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->num_hyps == 0,
                  "incorrect value for num_hyps, expected 0, is %d",
                  check_msg->num_hyps);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x19, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->num_hyps == 0,
                  "incorrect value for num_hyps, expected 0, is %d",
                  check_msg->num_hyps);
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

    sbp_register_callback(&sbp_state, 0x19, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x19, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x19, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 25, 0, 195, 4, 4, 1, 0, 0, 0, 166, 198,
    };
    u8 test_encoded_payload_data[] = {
        1,
        0,
        0,
        0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_iar_state_t *test_msg = (sbp_msg_iar_state_t *)&test_msg_storage;
    test_msg->num_hyps = 1;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x19, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_iar_state_t *check_msg = (sbp_msg_iar_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->num_hyps == 1,
                  "incorrect value for num_hyps, expected 1, is %d",
                  check_msg->num_hyps);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x19, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->num_hyps == 1,
                  "incorrect value for num_hyps, expected 1, is %d",
                  check_msg->num_hyps);
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

    sbp_register_callback(&sbp_state, 0x19, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x19, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x19, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 25, 0, 195, 4, 4, 217, 2, 0, 0, 6, 133,
    };
    u8 test_encoded_payload_data[] = {
        217,
        2,
        0,
        0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_iar_state_t *test_msg = (sbp_msg_iar_state_t *)&test_msg_storage;
    test_msg->num_hyps = 729;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x19, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_iar_state_t *check_msg = (sbp_msg_iar_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->num_hyps == 729,
                  "incorrect value for num_hyps, expected 729, is %d",
                  check_msg->num_hyps);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x19, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->num_hyps == 729,
                  "incorrect value for num_hyps, expected 729, is %d",
                  check_msg->num_hyps);
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

    sbp_register_callback(&sbp_state, 0x19, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x19, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x19, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 25, 0, 195, 4, 4, 216, 2, 0, 0, 178, 243,
    };
    u8 test_encoded_payload_data[] = {
        216,
        2,
        0,
        0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_iar_state_t *test_msg = (sbp_msg_iar_state_t *)&test_msg_storage;
    test_msg->num_hyps = 728;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x19, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_iar_state_t *check_msg = (sbp_msg_iar_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->num_hyps == 728,
                  "incorrect value for num_hyps, expected 728, is %d",
                  check_msg->num_hyps);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x19, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->num_hyps == 728,
                  "incorrect value for num_hyps, expected 728, is %d",
                  check_msg->num_hyps);
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

    sbp_register_callback(&sbp_state, 0x19, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x19, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x19, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 25, 0, 195, 4, 4, 215, 2, 0, 0, 92, 39,
    };
    u8 test_encoded_payload_data[] = {
        215,
        2,
        0,
        0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_iar_state_t *test_msg = (sbp_msg_iar_state_t *)&test_msg_storage;
    test_msg->num_hyps = 727;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x19, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_iar_state_t *check_msg = (sbp_msg_iar_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->num_hyps == 727,
                  "incorrect value for num_hyps, expected 727, is %d",
                  check_msg->num_hyps);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x19, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->num_hyps == 727,
                  "incorrect value for num_hyps, expected 727, is %d",
                  check_msg->num_hyps);
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

    sbp_register_callback(&sbp_state, 0x19, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x19, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x19, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 25, 0, 195, 4, 4, 211, 2, 0, 0, 173, 237,
    };
    u8 test_encoded_payload_data[] = {
        211,
        2,
        0,
        0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_iar_state_t *test_msg = (sbp_msg_iar_state_t *)&test_msg_storage;
    test_msg->num_hyps = 723;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x19, 1219, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    sbp_msg_iar_state_t *check_msg = (sbp_msg_iar_state_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->num_hyps == 723,
                  "incorrect value for num_hyps, expected 723, is %d",
                  check_msg->num_hyps);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x19, 1219,
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
    ck_assert_msg(last_payload.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
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
    ck_assert_msg(check_msg->num_hyps == 723,
                  "incorrect value for num_hyps, expected 723, is %d",
                  check_msg->num_hyps);
  }
}
END_TEST

Suite *auto_check_sbp_piksi_46_suite(void) {
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_piksi_46");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_piksi_46");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_46);
  suite_add_tcase(s, tc_acq);
  return s;
}