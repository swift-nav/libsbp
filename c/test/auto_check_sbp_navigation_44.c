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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_navigation.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <sbp.h>
#include <navigation.h>

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
static void* last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset()
{
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(dummy_buff + dummy_wr, buff, real_n);
 dummy_wr += real_n;
 return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(buff, dummy_buff + dummy_rd, real_n);
 dummy_rd += real_n;
 return real_n;
}

static void logging_reset()
{
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void* context)
{
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[], u16 frame_len, u8 frame[], void *context)
{
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST( test_auto_check_sbp_navigation_44 )
{
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
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x100, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x100, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,1,195,4,11,46,7,212,157,67,24,111,147,252,255,0,215,190, };

    dummy_reset();
    msg_gps_time_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.ns_residual = -224401;
    test_msg.tow = 407084500;
    test_msg.wn = 1838;
    sbp_send_message(&sbp_state, 0x100, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x100,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_gps_time_dep_a_t* check_msg = ( msg_gps_time_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->ns_residual == -224401, "incorrect value for ns_residual, expected -224401, is %d", check_msg->ns_residual);
    ck_assert_msg(check_msg->tow == 407084500, "incorrect value for tow, expected 407084500, is %d", check_msg->tow);
    ck_assert_msg(check_msg->wn == 1838, "incorrect value for wn, expected 1838, is %d", check_msg->wn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x100, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x100, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,1,195,4,11,46,7,56,158,67,24,109,103,3,0,0,134,89, };

    dummy_reset();
    msg_gps_time_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.ns_residual = 223085;
    test_msg.tow = 407084600;
    test_msg.wn = 1838;
    sbp_send_message(&sbp_state, 0x100, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x100,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_gps_time_dep_a_t* check_msg = ( msg_gps_time_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->ns_residual == 223085, "incorrect value for ns_residual, expected 223085, is %d", check_msg->ns_residual);
    ck_assert_msg(check_msg->tow == 407084600, "incorrect value for tow, expected 407084600, is %d", check_msg->tow);
    ck_assert_msg(check_msg->wn == 1838, "incorrect value for wn, expected 1838, is %d", check_msg->wn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x100, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x100, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,1,195,4,11,46,7,156,158,67,24,233,152,252,255,0,206,241, };

    dummy_reset();
    msg_gps_time_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.ns_residual = -222999;
    test_msg.tow = 407084700;
    test_msg.wn = 1838;
    sbp_send_message(&sbp_state, 0x100, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x100,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_gps_time_dep_a_t* check_msg = ( msg_gps_time_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->ns_residual == -222999, "incorrect value for ns_residual, expected -222999, is %d", check_msg->ns_residual);
    ck_assert_msg(check_msg->tow == 407084700, "incorrect value for tow, expected 407084700, is %d", check_msg->tow);
    ck_assert_msg(check_msg->wn == 1838, "incorrect value for wn, expected 1838, is %d", check_msg->wn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x100, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x100, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,1,195,4,11,46,7,0,159,67,24,240,154,3,0,0,147,98, };

    dummy_reset();
    msg_gps_time_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.ns_residual = 236272;
    test_msg.tow = 407084800;
    test_msg.wn = 1838;
    sbp_send_message(&sbp_state, 0x100, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x100,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_gps_time_dep_a_t* check_msg = ( msg_gps_time_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->ns_residual == 236272, "incorrect value for ns_residual, expected 236272, is %d", check_msg->ns_residual);
    ck_assert_msg(check_msg->tow == 407084800, "incorrect value for tow, expected 407084800, is %d", check_msg->tow);
    ck_assert_msg(check_msg->wn == 1838, "incorrect value for wn, expected 1838, is %d", check_msg->wn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x100, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x100, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,1,195,4,11,46,7,100,159,67,24,144,101,252,255,0,186,152, };

    dummy_reset();
    msg_gps_time_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.ns_residual = -236144;
    test_msg.tow = 407084900;
    test_msg.wn = 1838;
    sbp_send_message(&sbp_state, 0x100, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x100,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_gps_time_dep_a_t* check_msg = ( msg_gps_time_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->ns_residual == -236144, "incorrect value for ns_residual, expected -236144, is %d", check_msg->ns_residual);
    ck_assert_msg(check_msg->tow == 407084900, "incorrect value for tow, expected 407084900, is %d", check_msg->tow);
    ck_assert_msg(check_msg->wn == 1838, "incorrect value for wn, expected 1838, is %d", check_msg->wn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x100, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x100, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,1,195,4,11,46,7,46,162,68,24,205,230,250,255,0,11,225, };

    dummy_reset();
    msg_gps_time_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.ns_residual = -334131;
    test_msg.tow = 407151150;
    test_msg.wn = 1838;
    sbp_send_message(&sbp_state, 0x100, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x100,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_gps_time_dep_a_t* check_msg = ( msg_gps_time_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->ns_residual == -334131, "incorrect value for ns_residual, expected -334131, is %d", check_msg->ns_residual);
    ck_assert_msg(check_msg->tow == 407151150, "incorrect value for tow, expected 407151150, is %d", check_msg->tow);
    ck_assert_msg(check_msg->wn == 1838, "incorrect value for wn, expected 1838, is %d", check_msg->wn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x200, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,2,195,4,32,212,157,67,24,153,222,105,1,252,161,68,193,254,247,52,112,74,67,80,193,164,207,47,146,44,163,77,65,0,0,8,0,145,4, };

    dummy_reset();
    msg_pos_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 8;
    test_msg.tow = 407084500;
    test_msg.x = -2704376.0110433814;
    test_msg.y = -4263209.753232954;
    test_msg.z = 3884633.142084079;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_ecef_dep_a_t* check_msg = ( msg_pos_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084500, "incorrect value for tow, expected 407084500, is %d", check_msg->tow);
    ck_assert_msg((check_msg->x*100 - -2704376.01104*100) < 0.05, "incorrect value for x, expected -2704376.01104, is %f", check_msg->x);
    ck_assert_msg((check_msg->y*100 - -4263209.75323*100) < 0.05, "incorrect value for y, expected -4263209.75323, is %f", check_msg->y);
    ck_assert_msg((check_msg->z*100 - 3884633.14208*100) < 0.05, "incorrect value for z, expected 3884633.14208, is %f", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x200, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,2,195,4,32,56,158,67,24,215,184,223,246,251,161,68,193,36,126,17,39,74,67,80,193,19,179,70,80,44,163,77,65,0,0,8,0,245,66, };

    dummy_reset();
    msg_pos_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 8;
    test_msg.tow = 407084600;
    test_msg.x = -2704375.9287024545;
    test_msg.y = -4263208.610442672;
    test_msg.z = 3884632.627157578;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_ecef_dep_a_t* check_msg = ( msg_pos_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084600, "incorrect value for tow, expected 407084600, is %d", check_msg->tow);
    ck_assert_msg((check_msg->x*100 - -2704375.9287*100) < 0.05, "incorrect value for x, expected -2704375.9287, is %f", check_msg->x);
    ck_assert_msg((check_msg->y*100 - -4263208.61044*100) < 0.05, "incorrect value for y, expected -4263208.61044, is %f", check_msg->y);
    ck_assert_msg((check_msg->z*100 - 3884632.62716*100) < 0.05, "incorrect value for z, expected 3884632.62716, is %f", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x200, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,2,195,4,32,156,158,67,24,73,74,214,148,251,161,68,193,213,151,184,215,73,67,80,193,110,99,38,164,43,163,77,65,0,0,8,0,5,223, };

    dummy_reset();
    msg_pos_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 8;
    test_msg.tow = 407084700;
    test_msg.x = -2704375.162789617;
    test_msg.y = -4263207.370641668;
    test_msg.z = 3884631.282421521;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_ecef_dep_a_t* check_msg = ( msg_pos_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084700, "incorrect value for tow, expected 407084700, is %d", check_msg->tow);
    ck_assert_msg((check_msg->x*100 - -2704375.16279*100) < 0.05, "incorrect value for x, expected -2704375.16279, is %f", check_msg->x);
    ck_assert_msg((check_msg->y*100 - -4263207.37064*100) < 0.05, "incorrect value for y, expected -4263207.37064, is %f", check_msg->y);
    ck_assert_msg((check_msg->z*100 - 3884631.28242*100) < 0.05, "incorrect value for z, expected 3884631.28242, is %f", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x200, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,2,195,4,32,0,159,67,24,177,111,112,45,252,161,68,193,213,168,198,253,73,67,80,193,245,12,228,12,44,163,77,65,0,0,8,0,143,212, };

    dummy_reset();
    msg_pos_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 8;
    test_msg.tow = 407084800;
    test_msg.x = -2704376.3549937834;
    test_msg.y = -4263207.965250214;
    test_msg.z = 3884632.1007095524;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_ecef_dep_a_t* check_msg = ( msg_pos_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084800, "incorrect value for tow, expected 407084800, is %d", check_msg->tow);
    ck_assert_msg((check_msg->x*100 - -2704376.35499*100) < 0.05, "incorrect value for x, expected -2704376.35499, is %f", check_msg->x);
    ck_assert_msg((check_msg->y*100 - -4263207.96525*100) < 0.05, "incorrect value for y, expected -4263207.96525, is %f", check_msg->y);
    ck_assert_msg((check_msg->z*100 - 3884632.10071*100) < 0.05, "incorrect value for z, expected 3884632.10071, is %f", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x200, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,2,195,4,32,100,159,67,24,67,231,72,165,251,161,68,193,150,210,36,212,73,67,80,193,234,33,25,189,43,163,77,65,0,0,8,0,70,221, };

    dummy_reset();
    msg_pos_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 8;
    test_msg.tow = 407084900;
    test_msg.x = -2704375.291287334;
    test_msg.y = -4263207.314747473;
    test_msg.z = 3884631.4773294823;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_ecef_dep_a_t* check_msg = ( msg_pos_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084900, "incorrect value for tow, expected 407084900, is %d", check_msg->tow);
    ck_assert_msg((check_msg->x*100 - -2704375.29129*100) < 0.05, "incorrect value for x, expected -2704375.29129, is %f", check_msg->x);
    ck_assert_msg((check_msg->y*100 - -4263207.31475*100) < 0.05, "incorrect value for y, expected -4263207.31475, is %f", check_msg->y);
    ck_assert_msg((check_msg->z*100 - 3884631.47733*100) < 0.05, "incorrect value for z, expected 3884631.47733, is %f", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x200, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,0,2,195,4,32,46,162,68,24,224,72,131,215,251,161,68,193,180,123,222,94,74,67,80,193,191,3,131,193,45,163,77,65,0,0,5,0,17,221, };

    dummy_reset();
    msg_pos_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 5;
    test_msg.tow = 407151150;
    test_msg.x = -2704375.68369399;
    test_msg.y = -4263209.482329298;
    test_msg.z = 3884635.5118107493;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_ecef_dep_a_t* check_msg = ( msg_pos_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 5, "incorrect value for n_sats, expected 5, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407151150, "incorrect value for tow, expected 407151150, is %d", check_msg->tow);
    ck_assert_msg((check_msg->x*100 - -2704375.68369*100) < 0.05, "incorrect value for x, expected -2704375.68369, is %f", check_msg->x);
    ck_assert_msg((check_msg->y*100 - -4263209.48233*100) < 0.05, "incorrect value for y, expected -4263209.48233, is %f", check_msg->y);
    ck_assert_msg((check_msg->z*100 - 3884635.51181*100) < 0.05, "incorrect value for z, expected 3884635.51181, is %f", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x202, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x202, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,2,2,195,4,20,156,21,69,24,169,231,255,255,102,208,255,255,251,28,0,0,0,0,6,0,146,168, };

    dummy_reset();
    msg_baseline_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 6;
    test_msg.tow = 407180700;
    test_msg.x = -6231;
    test_msg.y = -12186;
    test_msg.z = 7419;
    sbp_send_message(&sbp_state, 0x202, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x202,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ecef_dep_a_t* check_msg = ( msg_baseline_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407180700, "incorrect value for tow, expected 407180700, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -6231, "incorrect value for x, expected -6231, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == -12186, "incorrect value for y, expected -12186, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 7419, "incorrect value for z, expected 7419, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x202, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x202, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,2,2,195,4,20,0,22,69,24,169,231,255,255,103,208,255,255,252,28,0,0,0,0,6,0,34,116, };

    dummy_reset();
    msg_baseline_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 6;
    test_msg.tow = 407180800;
    test_msg.x = -6231;
    test_msg.y = -12185;
    test_msg.z = 7420;
    sbp_send_message(&sbp_state, 0x202, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x202,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ecef_dep_a_t* check_msg = ( msg_baseline_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407180800, "incorrect value for tow, expected 407180800, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -6231, "incorrect value for x, expected -6231, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == -12185, "incorrect value for y, expected -12185, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 7420, "incorrect value for z, expected 7420, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x202, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x202, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,2,2,195,4,20,100,22,69,24,30,224,255,255,192,183,255,255,239,53,0,0,0,0,6,0,225,15, };

    dummy_reset();
    msg_baseline_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 6;
    test_msg.tow = 407180900;
    test_msg.x = -8162;
    test_msg.y = -18496;
    test_msg.z = 13807;
    sbp_send_message(&sbp_state, 0x202, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x202,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ecef_dep_a_t* check_msg = ( msg_baseline_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407180900, "incorrect value for tow, expected 407180900, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -8162, "incorrect value for x, expected -8162, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == -18496, "incorrect value for y, expected -18496, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 13807, "incorrect value for z, expected 13807, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x202, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x202, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,2,2,195,4,20,200,22,69,24,28,224,255,255,191,183,255,255,242,53,0,0,0,0,6,0,35,100, };

    dummy_reset();
    msg_baseline_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 6;
    test_msg.tow = 407181000;
    test_msg.x = -8164;
    test_msg.y = -18497;
    test_msg.z = 13810;
    sbp_send_message(&sbp_state, 0x202, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x202,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ecef_dep_a_t* check_msg = ( msg_baseline_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407181000, "incorrect value for tow, expected 407181000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -8164, "incorrect value for x, expected -8164, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == -18497, "incorrect value for y, expected -18497, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 13810, "incorrect value for z, expected 13810, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x202, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x202, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,2,2,195,4,20,44,23,69,24,24,227,255,255,25,195,255,255,153,59,0,0,0,0,6,0,66,66, };

    dummy_reset();
    msg_baseline_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 6;
    test_msg.tow = 407181100;
    test_msg.x = -7400;
    test_msg.y = -15591;
    test_msg.z = 15257;
    sbp_send_message(&sbp_state, 0x202, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x202,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ecef_dep_a_t* check_msg = ( msg_baseline_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407181100, "incorrect value for tow, expected 407181100, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -7400, "incorrect value for x, expected -7400, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == -15591, "incorrect value for y, expected -15591, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 15257, "incorrect value for z, expected 15257, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x202, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x202, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,2,2,195,4,20,144,23,69,24,23,227,255,255,25,195,255,255,153,59,0,0,0,0,6,0,35,135, };

    dummy_reset();
    msg_baseline_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 6;
    test_msg.tow = 407181200;
    test_msg.x = -7401;
    test_msg.y = -15591;
    test_msg.z = 15257;
    sbp_send_message(&sbp_state, 0x202, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x202,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ecef_dep_a_t* check_msg = ( msg_baseline_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407181200, "incorrect value for tow, expected 407181200, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -7401, "incorrect value for x, expected -7401, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == -15591, "incorrect value for y, expected -15591, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 15257, "incorrect value for z, expected 15257, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x203, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x203, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,3,2,195,4,22,156,21,69,24,130,246,255,255,241,4,0,0,35,196,255,255,0,0,0,0,6,0,250,21, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = -15325;
    test_msg.e = 1265;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = -2430;
    test_msg.n_sats = 6;
    test_msg.tow = 407180700;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x203,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ned_dep_a_t* check_msg = ( msg_baseline_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -15325, "incorrect value for d, expected -15325, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 1265, "incorrect value for e, expected 1265, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -2430, "incorrect value for n, expected -2430, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407180700, "incorrect value for tow, expected 407180700, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x203, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x203, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,3,2,195,4,22,0,22,69,24,130,246,255,255,241,4,0,0,35,196,255,255,0,0,0,0,6,0,240,133, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = -15325;
    test_msg.e = 1265;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = -2430;
    test_msg.n_sats = 6;
    test_msg.tow = 407180800;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x203,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ned_dep_a_t* check_msg = ( msg_baseline_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -15325, "incorrect value for d, expected -15325, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 1265, "incorrect value for e, expected 1265, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -2430, "incorrect value for n, expected -2430, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407180800, "incorrect value for tow, expected 407180800, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x203, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x203, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,3,2,195,4,22,100,22,69,24,32,251,255,255,199,11,0,0,57,161,255,255,0,0,0,0,6,0,12,181, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = -24263;
    test_msg.e = 3015;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = -1248;
    test_msg.n_sats = 6;
    test_msg.tow = 407180900;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x203,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ned_dep_a_t* check_msg = ( msg_baseline_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -24263, "incorrect value for d, expected -24263, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 3015, "incorrect value for e, expected 3015, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -1248, "incorrect value for n, expected -1248, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407180900, "incorrect value for tow, expected 407180900, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x203, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x203, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,3,2,195,4,22,200,22,69,24,33,251,255,255,199,11,0,0,54,161,255,255,0,0,0,0,6,0,86,58, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = -24266;
    test_msg.e = 3015;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = -1247;
    test_msg.n_sats = 6;
    test_msg.tow = 407181000;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x203,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ned_dep_a_t* check_msg = ( msg_baseline_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -24266, "incorrect value for d, expected -24266, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 3015, "incorrect value for e, expected 3015, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -1247, "incorrect value for n, expected -1247, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407181000, "incorrect value for tow, expected 407181000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x203, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x203, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,3,2,195,4,22,44,23,69,24,110,6,0,0,55,8,0,0,160,166,255,255,0,0,0,0,6,0,51,249, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = -22880;
    test_msg.e = 2103;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = 1646;
    test_msg.n_sats = 6;
    test_msg.tow = 407181100;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x203,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ned_dep_a_t* check_msg = ( msg_baseline_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -22880, "incorrect value for d, expected -22880, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 2103, "incorrect value for e, expected 2103, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == 1646, "incorrect value for n, expected 1646, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407181100, "incorrect value for tow, expected 407181100, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x203, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x203, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,3,2,195,4,22,144,23,69,24,110,6,0,0,54,8,0,0,160,166,255,255,0,0,0,0,6,0,206,22, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = -22880;
    test_msg.e = 2102;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = 1646;
    test_msg.n_sats = 6;
    test_msg.tow = 407181200;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x203,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_baseline_ned_dep_a_t* check_msg = ( msg_baseline_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -22880, "incorrect value for d, expected -22880, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 2102, "incorrect value for e, expected 2102, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == 1646, "incorrect value for n, expected 1646, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 6, "incorrect value for n_sats, expected 6, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407181200, "incorrect value for tow, expected 407181200, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x204, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x204, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,4,2,195,4,20,212,157,67,24,24,0,0,0,245,255,255,255,219,255,255,255,0,0,8,0,68,255, };

    dummy_reset();
    msg_vel_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 8;
    test_msg.tow = 407084500;
    test_msg.x = 24;
    test_msg.y = -11;
    test_msg.z = -37;
    sbp_send_message(&sbp_state, 0x204, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x204,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ecef_dep_a_t* check_msg = ( msg_vel_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084500, "incorrect value for tow, expected 407084500, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == 24, "incorrect value for x, expected 24, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == -11, "incorrect value for y, expected -11, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == -37, "incorrect value for z, expected -37, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x204, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x204, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,4,2,195,4,20,56,158,67,24,4,0,0,0,234,255,255,255,18,0,0,0,0,0,8,0,214,136, };

    dummy_reset();
    msg_vel_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 8;
    test_msg.tow = 407084600;
    test_msg.x = 4;
    test_msg.y = -22;
    test_msg.z = 18;
    sbp_send_message(&sbp_state, 0x204, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x204,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ecef_dep_a_t* check_msg = ( msg_vel_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084600, "incorrect value for tow, expected 407084600, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == 4, "incorrect value for x, expected 4, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == -22, "incorrect value for y, expected -22, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 18, "incorrect value for z, expected 18, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x204, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x204, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,4,2,195,4,20,156,158,67,24,230,255,255,255,4,0,0,0,1,0,0,0,0,0,8,0,122,159, };

    dummy_reset();
    msg_vel_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 8;
    test_msg.tow = 407084700;
    test_msg.x = -26;
    test_msg.y = 4;
    test_msg.z = 1;
    sbp_send_message(&sbp_state, 0x204, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x204,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ecef_dep_a_t* check_msg = ( msg_vel_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084700, "incorrect value for tow, expected 407084700, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -26, "incorrect value for x, expected -26, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == 4, "incorrect value for y, expected 4, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 1, "incorrect value for z, expected 1, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x204, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x204, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,4,2,195,4,20,0,159,67,24,247,255,255,255,237,255,255,255,28,0,0,0,0,0,8,0,232,146, };

    dummy_reset();
    msg_vel_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 8;
    test_msg.tow = 407084800;
    test_msg.x = -9;
    test_msg.y = -19;
    test_msg.z = 28;
    sbp_send_message(&sbp_state, 0x204, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x204,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ecef_dep_a_t* check_msg = ( msg_vel_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084800, "incorrect value for tow, expected 407084800, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -9, "incorrect value for x, expected -9, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == -19, "incorrect value for y, expected -19, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 28, "incorrect value for z, expected 28, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x204, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x204, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,4,2,195,4,20,100,159,67,24,255,255,255,255,2,0,0,0,245,255,255,255,0,0,8,0,171,238, };

    dummy_reset();
    msg_vel_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 8;
    test_msg.tow = 407084900;
    test_msg.x = -1;
    test_msg.y = 2;
    test_msg.z = -11;
    sbp_send_message(&sbp_state, 0x204, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x204,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ecef_dep_a_t* check_msg = ( msg_vel_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084900, "incorrect value for tow, expected 407084900, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -1, "incorrect value for x, expected -1, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == 2, "incorrect value for y, expected 2, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == -11, "incorrect value for z, expected -11, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x204, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x204, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,4,2,195,4,20,46,162,68,24,207,255,255,255,185,255,255,255,65,0,0,0,0,0,5,0,82,154, };

    dummy_reset();
    msg_vel_ecef_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.accuracy = 0;
    test_msg.flags = 0;
    test_msg.n_sats = 5;
    test_msg.tow = 407151150;
    test_msg.x = -49;
    test_msg.y = -71;
    test_msg.z = 65;
    sbp_send_message(&sbp_state, 0x204, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x204,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ecef_dep_a_t* check_msg = ( msg_vel_ecef_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 5, "incorrect value for n_sats, expected 5, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407151150, "incorrect value for tow, expected 407151150, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -49, "incorrect value for x, expected -49, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == -71, "incorrect value for y, expected -71, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 65, "incorrect value for z, expected 65, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x205, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x205, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,5,2,195,4,22,212,157,67,24,229,255,255,255,26,0,0,0,25,0,0,0,0,0,0,0,8,0,132,25, };

    dummy_reset();
    msg_vel_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = 25;
    test_msg.e = 26;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = -27;
    test_msg.n_sats = 8;
    test_msg.tow = 407084500;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x205, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x205,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ned_dep_a_t* check_msg = ( msg_vel_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == 25, "incorrect value for d, expected 25, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 26, "incorrect value for e, expected 26, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -27, "incorrect value for n, expected -27, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084500, "incorrect value for tow, expected 407084500, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x205, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x205, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,5,2,195,4,22,56,158,67,24,4,0,0,0,15,0,0,0,232,255,255,255,0,0,0,0,8,0,42,14, };

    dummy_reset();
    msg_vel_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = -24;
    test_msg.e = 15;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = 4;
    test_msg.n_sats = 8;
    test_msg.tow = 407084600;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x205, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x205,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ned_dep_a_t* check_msg = ( msg_vel_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -24, "incorrect value for d, expected -24, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 15, "incorrect value for e, expected 15, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == 4, "incorrect value for n, expected 4, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084600, "incorrect value for tow, expected 407084600, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x205, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x205, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,5,2,195,4,22,156,158,67,24,251,255,255,255,232,255,255,255,247,255,255,255,0,0,0,0,8,0,218,148, };

    dummy_reset();
    msg_vel_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = -9;
    test_msg.e = -24;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = -5;
    test_msg.n_sats = 8;
    test_msg.tow = 407084700;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x205, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x205,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ned_dep_a_t* check_msg = ( msg_vel_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -9, "incorrect value for d, expected -9, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -24, "incorrect value for e, expected -24, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -5, "incorrect value for n, expected -5, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084700, "incorrect value for tow, expected 407084700, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x205, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x205, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,5,2,195,4,22,0,159,67,24,10,0,0,0,2,0,0,0,222,255,255,255,0,0,0,0,8,0,148,16, };

    dummy_reset();
    msg_vel_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = -34;
    test_msg.e = 2;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = 10;
    test_msg.n_sats = 8;
    test_msg.tow = 407084800;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x205, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x205,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ned_dep_a_t* check_msg = ( msg_vel_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -34, "incorrect value for d, expected -34, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 2, "incorrect value for e, expected 2, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == 10, "incorrect value for n, expected 10, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084800, "incorrect value for tow, expected 407084800, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x205, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x205, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,5,2,195,4,22,100,159,67,24,248,255,255,255,254,255,255,255,7,0,0,0,0,0,0,0,8,0,255,236, };

    dummy_reset();
    msg_vel_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = 7;
    test_msg.e = -2;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = -8;
    test_msg.n_sats = 8;
    test_msg.tow = 407084900;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x205, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x205,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ned_dep_a_t* check_msg = ( msg_vel_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == 7, "incorrect value for d, expected 7, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -2, "incorrect value for e, expected -2, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -8, "incorrect value for n, expected -8, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084900, "incorrect value for tow, expected 407084900, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x205, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x205, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,5,2,195,4,22,46,162,68,24,255,255,255,255,253,255,255,255,148,255,255,255,0,0,0,0,5,0,166,189, };

    dummy_reset();
    msg_vel_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = -108;
    test_msg.e = -3;
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.n = -1;
    test_msg.n_sats = 5;
    test_msg.tow = 407151150;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x205, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x205,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_vel_ned_dep_a_t* check_msg = ( msg_vel_ned_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -108, "incorrect value for d, expected -108, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -3, "incorrect value for e, expected -3, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -1, "incorrect value for n, expected -1, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 5, "incorrect value for n_sats, expected 5, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407151150, "incorrect value for tow, expected 407151150, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x206, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x206, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,6,2,195,4,14,212,157,67,24,247,0,215,0,123,0,17,1,44,0,206,21, };

    dummy_reset();
    msg_dops_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.gdop = 247;
    test_msg.hdop = 273;
    test_msg.pdop = 215;
    test_msg.tdop = 123;
    test_msg.tow = 407084500;
    test_msg.vdop = 44;
    sbp_send_message(&sbp_state, 0x206, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x206,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_dops_dep_a_t* check_msg = ( msg_dops_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->gdop == 247, "incorrect value for gdop, expected 247, is %d", check_msg->gdop);
    ck_assert_msg(check_msg->hdop == 273, "incorrect value for hdop, expected 273, is %d", check_msg->hdop);
    ck_assert_msg(check_msg->pdop == 215, "incorrect value for pdop, expected 215, is %d", check_msg->pdop);
    ck_assert_msg(check_msg->tdop == 123, "incorrect value for tdop, expected 123, is %d", check_msg->tdop);
    ck_assert_msg(check_msg->tow == 407084500, "incorrect value for tow, expected 407084500, is %d", check_msg->tow);
    ck_assert_msg(check_msg->vdop == 44, "incorrect value for vdop, expected 44, is %d", check_msg->vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x206, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x206, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,6,2,195,4,14,0,0,0,0,255,255,255,255,0,0,0,0,0,0,146,12, };

    dummy_reset();
    msg_dops_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.gdop = 65535;
    test_msg.hdop = 0;
    test_msg.pdop = 65535;
    test_msg.tdop = 0;
    test_msg.tow = 0;
    test_msg.vdop = 0;
    sbp_send_message(&sbp_state, 0x206, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x206,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_dops_dep_a_t* check_msg = ( msg_dops_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->gdop == 65535, "incorrect value for gdop, expected 65535, is %d", check_msg->gdop);
    ck_assert_msg(check_msg->hdop == 0, "incorrect value for hdop, expected 0, is %d", check_msg->hdop);
    ck_assert_msg(check_msg->pdop == 65535, "incorrect value for pdop, expected 65535, is %d", check_msg->pdop);
    ck_assert_msg(check_msg->tdop == 0, "incorrect value for tdop, expected 0, is %d", check_msg->tdop);
    ck_assert_msg(check_msg->tow == 0, "incorrect value for tow, expected 0, is %d", check_msg->tow);
    ck_assert_msg(check_msg->vdop == 0, "incorrect value for vdop, expected 0, is %d", check_msg->vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x206, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x206, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,6,2,195,4,14,128,165,68,24,92,1,56,1,155,0,125,2,113,0,129,93, };

    dummy_reset();
    msg_dops_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.gdop = 348;
    test_msg.hdop = 637;
    test_msg.pdop = 312;
    test_msg.tdop = 155;
    test_msg.tow = 407152000;
    test_msg.vdop = 113;
    sbp_send_message(&sbp_state, 0x206, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x206,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_dops_dep_a_t* check_msg = ( msg_dops_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->gdop == 348, "incorrect value for gdop, expected 348, is %d", check_msg->gdop);
    ck_assert_msg(check_msg->hdop == 637, "incorrect value for hdop, expected 637, is %d", check_msg->hdop);
    ck_assert_msg(check_msg->pdop == 312, "incorrect value for pdop, expected 312, is %d", check_msg->pdop);
    ck_assert_msg(check_msg->tdop == 155, "incorrect value for tdop, expected 155, is %d", check_msg->tdop);
    ck_assert_msg(check_msg->tow == 407152000, "incorrect value for tow, expected 407152000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->vdop == 113, "incorrect value for vdop, expected 113, is %d", check_msg->vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x206, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x206, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,6,2,195,4,14,104,169,68,24,92,1,55,1,155,0,125,2,113,0,209,128, };

    dummy_reset();
    msg_dops_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.gdop = 348;
    test_msg.hdop = 637;
    test_msg.pdop = 311;
    test_msg.tdop = 155;
    test_msg.tow = 407153000;
    test_msg.vdop = 113;
    sbp_send_message(&sbp_state, 0x206, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x206,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_dops_dep_a_t* check_msg = ( msg_dops_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->gdop == 348, "incorrect value for gdop, expected 348, is %d", check_msg->gdop);
    ck_assert_msg(check_msg->hdop == 637, "incorrect value for hdop, expected 637, is %d", check_msg->hdop);
    ck_assert_msg(check_msg->pdop == 311, "incorrect value for pdop, expected 311, is %d", check_msg->pdop);
    ck_assert_msg(check_msg->tdop == 155, "incorrect value for tdop, expected 155, is %d", check_msg->tdop);
    ck_assert_msg(check_msg->tow == 407153000, "incorrect value for tow, expected 407153000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->vdop == 113, "incorrect value for vdop, expected 113, is %d", check_msg->vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x206, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x206, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,6,2,195,4,14,80,173,68,24,92,1,55,1,155,0,125,2,112,0,30,6, };

    dummy_reset();
    msg_dops_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.gdop = 348;
    test_msg.hdop = 637;
    test_msg.pdop = 311;
    test_msg.tdop = 155;
    test_msg.tow = 407154000;
    test_msg.vdop = 112;
    sbp_send_message(&sbp_state, 0x206, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x206,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_dops_dep_a_t* check_msg = ( msg_dops_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->gdop == 348, "incorrect value for gdop, expected 348, is %d", check_msg->gdop);
    ck_assert_msg(check_msg->hdop == 637, "incorrect value for hdop, expected 637, is %d", check_msg->hdop);
    ck_assert_msg(check_msg->pdop == 311, "incorrect value for pdop, expected 311, is %d", check_msg->pdop);
    ck_assert_msg(check_msg->tdop == 155, "incorrect value for tdop, expected 155, is %d", check_msg->tdop);
    ck_assert_msg(check_msg->tow == 407154000, "incorrect value for tow, expected 407154000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->vdop == 112, "incorrect value for vdop, expected 112, is %d", check_msg->vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x206, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x206, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,6,2,195,4,14,56,177,68,24,92,1,55,1,155,0,125,2,112,0,70,67, };

    dummy_reset();
    msg_dops_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.gdop = 348;
    test_msg.hdop = 637;
    test_msg.pdop = 311;
    test_msg.tdop = 155;
    test_msg.tow = 407155000;
    test_msg.vdop = 112;
    sbp_send_message(&sbp_state, 0x206, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x206,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_dops_dep_a_t* check_msg = ( msg_dops_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->gdop == 348, "incorrect value for gdop, expected 348, is %d", check_msg->gdop);
    ck_assert_msg(check_msg->hdop == 637, "incorrect value for hdop, expected 637, is %d", check_msg->hdop);
    ck_assert_msg(check_msg->pdop == 311, "incorrect value for pdop, expected 311, is %d", check_msg->pdop);
    ck_assert_msg(check_msg->tdop == 155, "incorrect value for tdop, expected 155, is %d", check_msg->tdop);
    ck_assert_msg(check_msg->tow == 407155000, "incorrect value for tow, expected 407155000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->vdop == 112, "incorrect value for vdop, expected 112, is %d", check_msg->vdop);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,195,4,34,212,157,67,24,8,23,228,8,151,225,66,64,156,174,42,194,230,152,94,192,153,23,72,47,196,40,16,64,0,0,0,0,8,0,237,169, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.height = 4.039810885214956;
    test_msg.lat = 37.76242171418386;
    test_msg.lon = -122.38908437889262;
    test_msg.n_sats = 8;
    test_msg.tow = 407084500;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x201,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_llh_dep_a_t* check_msg = ( msg_pos_llh_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg((check_msg->height*100 - 4.03981088521*100) < 0.05, "incorrect value for height, expected 4.03981088521, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.7624217142*100) < 0.05, "incorrect value for lat, expected 37.7624217142, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.389084379*100) < 0.05, "incorrect value for lon, expected -122.389084379, is %f", check_msg->lon);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084500, "incorrect value for tow, expected 407084500, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,195,4,34,56,158,67,24,220,109,212,24,151,225,66,64,159,231,254,219,230,152,94,192,128,151,67,19,233,105,7,64,0,0,0,0,8,0,152,11, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.height = 2.926714087009657;
    test_msg.lat = 37.76242361423985;
    test_msg.lon = -122.38909053700489;
    test_msg.n_sats = 8;
    test_msg.tow = 407084600;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x201,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_llh_dep_a_t* check_msg = ( msg_pos_llh_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg((check_msg->height*100 - 2.92671408701*100) < 0.05, "incorrect value for height, expected 2.92671408701, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.7624236142*100) < 0.05, "incorrect value for lat, expected 37.7624236142, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.389090537*100) < 0.05, "incorrect value for lon, expected -122.389090537, is %f", check_msg->lon);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084600, "incorrect value for tow, expected 407084600, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,195,4,34,156,158,67,24,13,91,237,11,151,225,66,64,75,113,210,220,230,152,94,192,37,6,145,188,89,112,238,63,0,0,0,0,8,0,221,155, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.height = 0.9512146647395566;
    test_msg.lat = 37.762422076126406;
    test_msg.lon = -122.3890907340148;
    test_msg.n_sats = 8;
    test_msg.tow = 407084700;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x201,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_llh_dep_a_t* check_msg = ( msg_pos_llh_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg((check_msg->height*100 - 0.95121466474*100) < 0.05, "incorrect value for height, expected 0.95121466474, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.7624220761*100) < 0.05, "incorrect value for lat, expected 37.7624220761, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.389090734*100) < 0.05, "incorrect value for lon, expected -122.389090734, is %f", check_msg->lon);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084700, "incorrect value for tow, expected 407084700, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,195,4,34,0,159,67,24,51,183,5,8,151,225,66,64,13,226,148,253,230,152,94,192,187,27,11,32,69,213,2,64,0,0,0,0,8,0,82,94, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.height = 2.354135752047538;
    test_msg.lat = 37.762421610632735;
    test_msg.lon = -122.38909854449612;
    test_msg.n_sats = 8;
    test_msg.tow = 407084800;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x201,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_llh_dep_a_t* check_msg = ( msg_pos_llh_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg((check_msg->height*100 - 2.35413575205*100) < 0.05, "incorrect value for height, expected 2.35413575205, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.7624216106*100) < 0.05, "incorrect value for lat, expected 37.7624216106, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.389098544*100) < 0.05, "incorrect value for lon, expected -122.389098544, is %f", check_msg->lon);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084800, "incorrect value for tow, expected 407084800, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,195,4,34,100,159,67,24,22,77,146,22,151,225,66,64,64,134,105,227,230,152,94,192,37,99,114,72,31,103,241,63,0,0,0,0,8,0,70,60, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.height = 1.0876763181642641;
    test_msg.lat = 37.76242334502801;
    test_msg.lon = -122.38909230523223;
    test_msg.n_sats = 8;
    test_msg.tow = 407084900;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x201,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_llh_dep_a_t* check_msg = ( msg_pos_llh_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg((check_msg->height*100 - 1.08767631816*100) < 0.05, "incorrect value for height, expected 1.08767631816, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.762423345*100) < 0.05, "incorrect value for lat, expected 37.762423345, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.389092305*100) < 0.05, "incorrect value for lon, expected -122.389092305, is %f", check_msg->lon);
    ck_assert_msg(check_msg->n_sats == 8, "incorrect value for n_sats, expected 8, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084900, "incorrect value for tow, expected 407084900, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,195,4,34,46,162,68,24,124,245,46,169,151,225,66,64,135,149,234,187,230,152,94,192,194,201,115,145,166,175,20,64,0,0,0,0,5,0,212,121, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.height = 5.171533844654222;
    test_msg.lat = 37.76244082253376;
    test_msg.lon = -122.38908288868525;
    test_msg.n_sats = 5;
    test_msg.tow = 407151150;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 1219, test_msg_len, (u8*)&test_msg, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 1219,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 1219,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x201,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_llh_dep_a_t* check_msg = ( msg_pos_llh_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg((check_msg->height*100 - 5.17153384465*100) < 0.05, "incorrect value for height, expected 5.17153384465, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.7624408225*100) < 0.05, "incorrect value for lat, expected 37.7624408225, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.389082889*100) < 0.05, "incorrect value for lon, expected -122.389082889, is %f", check_msg->lon);
    ck_assert_msg(check_msg->n_sats == 5, "incorrect value for n_sats, expected 5, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407151150, "incorrect value for tow, expected 407151150, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_44_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_navigation_44");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_44");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_44);
  suite_add_tcase(s, tc_acq);
  return s;
}