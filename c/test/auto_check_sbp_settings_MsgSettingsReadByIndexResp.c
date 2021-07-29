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
// spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadByIndexResp.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <sbp.h>
#include <settings.h>
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

START_TEST(test_auto_check_sbp_settings_MsgSettingsReadByIndexResp) {
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

    sbp_register_callback(&sbp_state, 0xa7, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0xa7, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  167, 0,   246, 215, 78,  0,   0,   116, 101, 108, 101, 109,
        101, 116, 114, 121, 95,  114, 97,  100, 105, 111, 0,   99,  111,
        110, 102, 105, 103, 117, 114, 97,  116, 105, 111, 110, 95,  115,
        116, 114, 105, 110, 103, 0,   65,  84,  38,  70,  44,  65,  84,
        83,  49,  61,  49,  49,  53,  44,  65,  84,  83,  50,  61,  49,
        50,  56,  44,  65,  84,  83,  53,  61,  48,  44,  65,  84,  38,
        87,  44,  65,  84,  90,  0,   248, 233,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_settings_read_by_index_resp_t* test_msg =
        (msg_settings_read_by_index_resp_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->index = 0;
    {
      const char assign_string[] = {
          (char)116, (char)101, (char)108, (char)101, (char)109, (char)101,
          (char)116, (char)114, (char)121, (char)95,  (char)114, (char)97,
          (char)100, (char)105, (char)111, (char)0,   (char)99,  (char)111,
          (char)110, (char)102, (char)105, (char)103, (char)117, (char)114,
          (char)97,  (char)116, (char)105, (char)111, (char)110, (char)95,
          (char)115, (char)116, (char)114, (char)105, (char)110, (char)103,
          (char)0,   (char)65,  (char)84,  (char)38,  (char)70,  (char)44,
          (char)65,  (char)84,  (char)83,  (char)49,  (char)61,  (char)49,
          (char)49,  (char)53,  (char)44,  (char)65,  (char)84,  (char)83,
          (char)50,  (char)61,  (char)49,  (char)50,  (char)56,  (char)44,
          (char)65,  (char)84,  (char)83,  (char)53,  (char)61,  (char)48,
          (char)44,  (char)65,  (char)84,  (char)38,  (char)87,  (char)44,
          (char)65,  (char)84,  (char)90,  (char)0};
      memcpy(test_msg->setting, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->setting) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_send_message(&sbp_state, 0xa7, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xa7,
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
    msg_settings_read_by_index_resp_t* check_msg =
        (msg_settings_read_by_index_resp_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->index == 0,
                  "incorrect value for index, expected 0, is %d",
                  check_msg->index);
    {
      const char check_string[] = {
          (char)116, (char)101, (char)108, (char)101, (char)109, (char)101,
          (char)116, (char)114, (char)121, (char)95,  (char)114, (char)97,
          (char)100, (char)105, (char)111, (char)0,   (char)99,  (char)111,
          (char)110, (char)102, (char)105, (char)103, (char)117, (char)114,
          (char)97,  (char)116, (char)105, (char)111, (char)110, (char)95,
          (char)115, (char)116, (char)114, (char)105, (char)110, (char)103,
          (char)0,   (char)65,  (char)84,  (char)38,  (char)70,  (char)44,
          (char)65,  (char)84,  (char)83,  (char)49,  (char)61,  (char)49,
          (char)49,  (char)53,  (char)44,  (char)65,  (char)84,  (char)83,
          (char)50,  (char)61,  (char)49,  (char)50,  (char)56,  (char)44,
          (char)65,  (char)84,  (char)83,  (char)53,  (char)61,  (char)48,
          (char)44,  (char)65,  (char)84,  (char)38,  (char)87,  (char)44,
          (char)65,  (char)84,  (char)90,  (char)0};
      ck_assert_msg(
          memcmp(check_msg->setting, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->setting, expected string '%s', is "
          "'%s'",
          check_string, check_msg->setting);
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

    sbp_register_callback(&sbp_state, 0xa7, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0xa7, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  167, 0,  246, 215, 35,  1,   0,  117, 97, 114, 116, 95,  102, 116,
        100, 105, 0,  109, 111, 100, 101, 0,  83,  66, 80,  0,   101, 110, 117,
        109, 58,  83, 66,  80,  44,  78,  77, 69,  65, 0,   167, 243,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_settings_read_by_index_resp_t* test_msg =
        (msg_settings_read_by_index_resp_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->index = 1;
    {
      const char assign_string[] = {
          (char)117, (char)97,  (char)114, (char)116, (char)95,  (char)102,
          (char)116, (char)100, (char)105, (char)0,   (char)109, (char)111,
          (char)100, (char)101, (char)0,   (char)83,  (char)66,  (char)80,
          (char)0,   (char)101, (char)110, (char)117, (char)109, (char)58,
          (char)83,  (char)66,  (char)80,  (char)44,  (char)78,  (char)77,
          (char)69,  (char)65,  (char)0};
      memcpy(test_msg->setting, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->setting) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_send_message(&sbp_state, 0xa7, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xa7,
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
    msg_settings_read_by_index_resp_t* check_msg =
        (msg_settings_read_by_index_resp_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->index == 1,
                  "incorrect value for index, expected 1, is %d",
                  check_msg->index);
    {
      const char check_string[] = {
          (char)117, (char)97,  (char)114, (char)116, (char)95,  (char)102,
          (char)116, (char)100, (char)105, (char)0,   (char)109, (char)111,
          (char)100, (char)101, (char)0,   (char)83,  (char)66,  (char)80,
          (char)0,   (char)101, (char)110, (char)117, (char)109, (char)58,
          (char)83,  (char)66,  (char)80,  (char)44,  (char)78,  (char)77,
          (char)69,  (char)65,  (char)0};
      ck_assert_msg(
          memcmp(check_msg->setting, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->setting, expected string '%s', is "
          "'%s'",
          check_string, check_msg->setting);
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

    sbp_register_callback(&sbp_state, 0xa7, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0xa7, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  167, 0,   246, 215, 35,  2,   0,   117, 97,  114,
        116, 95,  102, 116, 100, 105, 0,   115, 98,  112, 95,
        109, 101, 115, 115, 97,  103, 101, 95,  109, 97,  115,
        107, 0,   54,  53,  53,  51,  53,  0,   4,   56,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_settings_read_by_index_resp_t* test_msg =
        (msg_settings_read_by_index_resp_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->index = 2;
    {
      const char assign_string[] = {
          (char)117, (char)97,  (char)114, (char)116, (char)95,  (char)102,
          (char)116, (char)100, (char)105, (char)0,   (char)115, (char)98,
          (char)112, (char)95,  (char)109, (char)101, (char)115, (char)115,
          (char)97,  (char)103, (char)101, (char)95,  (char)109, (char)97,
          (char)115, (char)107, (char)0,   (char)54,  (char)53,  (char)53,
          (char)51,  (char)53,  (char)0};
      memcpy(test_msg->setting, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->setting) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_send_message(&sbp_state, 0xa7, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xa7,
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
    msg_settings_read_by_index_resp_t* check_msg =
        (msg_settings_read_by_index_resp_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->index == 2,
                  "incorrect value for index, expected 2, is %d",
                  check_msg->index);
    {
      const char check_string[] = {
          (char)117, (char)97,  (char)114, (char)116, (char)95,  (char)102,
          (char)116, (char)100, (char)105, (char)0,   (char)115, (char)98,
          (char)112, (char)95,  (char)109, (char)101, (char)115, (char)115,
          (char)97,  (char)103, (char)101, (char)95,  (char)109, (char)97,
          (char)115, (char)107, (char)0,   (char)54,  (char)53,  (char)53,
          (char)51,  (char)53,  (char)0};
      ck_assert_msg(
          memcmp(check_msg->setting, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->setting, expected string '%s', is "
          "'%s'",
          check_string, check_msg->setting);
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

    sbp_register_callback(&sbp_state, 0xa7, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0xa7, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  167, 0,   246, 215, 29, 3,  0,   117, 97,  114, 116, 95,
        102, 116, 100, 105, 0,   98, 97, 117, 100, 114, 97,  116, 101,
        0,   49,  48,  48,  48,  48, 48, 48,  0,   242, 146,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_settings_read_by_index_resp_t* test_msg =
        (msg_settings_read_by_index_resp_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->index = 3;
    {
      const char assign_string[] = {
          (char)117, (char)97,  (char)114, (char)116, (char)95,  (char)102,
          (char)116, (char)100, (char)105, (char)0,   (char)98,  (char)97,
          (char)117, (char)100, (char)114, (char)97,  (char)116, (char)101,
          (char)0,   (char)49,  (char)48,  (char)48,  (char)48,  (char)48,
          (char)48,  (char)48,  (char)0};
      memcpy(test_msg->setting, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->setting) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_send_message(&sbp_state, 0xa7, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xa7,
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
    msg_settings_read_by_index_resp_t* check_msg =
        (msg_settings_read_by_index_resp_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->index == 3,
                  "incorrect value for index, expected 3, is %d",
                  check_msg->index);
    {
      const char check_string[] = {
          (char)117, (char)97,  (char)114, (char)116, (char)95,  (char)102,
          (char)116, (char)100, (char)105, (char)0,   (char)98,  (char)97,
          (char)117, (char)100, (char)114, (char)97,  (char)116, (char)101,
          (char)0,   (char)49,  (char)48,  (char)48,  (char)48,  (char)48,
          (char)48,  (char)48,  (char)0};
      ck_assert_msg(
          memcmp(check_msg->setting, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->setting, expected string '%s', is "
          "'%s'",
          check_string, check_msg->setting);
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

    sbp_register_callback(&sbp_state, 0xa7, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0xa7, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  167, 0,  246, 215, 36,  4,   0,   117, 97, 114, 116, 95, 117, 97,
        114, 116, 97, 0,   109, 111, 100, 101, 0,   83, 66,  80,  0,  101, 110,
        117, 109, 58, 83,  66,  80,  44,  78,  77,  69, 65,  0,   22, 4,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_settings_read_by_index_resp_t* test_msg =
        (msg_settings_read_by_index_resp_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->index = 4;
    {
      const char assign_string[] = {
          (char)117, (char)97,  (char)114, (char)116, (char)95,  (char)117,
          (char)97,  (char)114, (char)116, (char)97,  (char)0,   (char)109,
          (char)111, (char)100, (char)101, (char)0,   (char)83,  (char)66,
          (char)80,  (char)0,   (char)101, (char)110, (char)117, (char)109,
          (char)58,  (char)83,  (char)66,  (char)80,  (char)44,  (char)78,
          (char)77,  (char)69,  (char)65,  (char)0};
      memcpy(test_msg->setting, assign_string, sizeof(assign_string));
      if (sizeof(test_msg->setting) == 0) {
        test_msg_len += sizeof(assign_string);
      }
    }
    sbp_send_message(&sbp_state, 0xa7, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xa7,
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
    msg_settings_read_by_index_resp_t* check_msg =
        (msg_settings_read_by_index_resp_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->index == 4,
                  "incorrect value for index, expected 4, is %d",
                  check_msg->index);
    {
      const char check_string[] = {
          (char)117, (char)97,  (char)114, (char)116, (char)95,  (char)117,
          (char)97,  (char)114, (char)116, (char)97,  (char)0,   (char)109,
          (char)111, (char)100, (char)101, (char)0,   (char)83,  (char)66,
          (char)80,  (char)0,   (char)101, (char)110, (char)117, (char)109,
          (char)58,  (char)83,  (char)66,  (char)80,  (char)44,  (char)78,
          (char)77,  (char)69,  (char)65,  (char)0};
      ck_assert_msg(
          memcmp(check_msg->setting, check_string, sizeof(check_string)) == 0,
          "incorrect value for check_msg->setting, expected string '%s', is "
          "'%s'",
          check_string, check_msg->setting);
    }
  }
}
END_TEST

Suite* auto_check_sbp_settings_MsgSettingsReadByIndexResp_suite(void) {
  Suite* s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_settings_MsgSettingsReadByIndexResp");
  TCase* tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_settings_MsgSettingsReadByIndexResp");
  tcase_add_test(tc_acq,
                 test_auto_check_sbp_settings_MsgSettingsReadByIndexResp);
  suite_add_tcase(s, tc_acq);
  return s;
}