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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNEDDepA.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_navigation_7 )
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

    sbp_register_callback(&sbp_state, 0x203, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x203, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,3,2,246,215,22,20,46,39,0,243,134,254,255,234,153,255,255,0,0,0,0,0,0,0,0,9,1,93,193, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = 0;
    test_msg.e = -26134;
    test_msg.flags = 1;
    test_msg.h_accuracy = 0;
    test_msg.n = -96525;
    test_msg.n_sats = 9;
    test_msg.tow = 2567700;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 55286, test_msg_len, (u8*)&test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    ck_assert_msg(check_msg->d == 0, "incorrect value for d, expected 0, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -26134, "incorrect value for e, expected -26134, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 1, "incorrect value for flags, expected 1, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -96525, "incorrect value for n, expected -96525, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2567700, "incorrect value for tow, expected 2567700, is %d", check_msg->tow);
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

    u8 encoded_frame[] = {85,3,2,246,215,22,120,46,39,0,139,134,254,255,109,155,255,255,0,0,0,0,0,0,0,0,9,1,38,39, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = 0;
    test_msg.e = -25747;
    test_msg.flags = 1;
    test_msg.h_accuracy = 0;
    test_msg.n = -96629;
    test_msg.n_sats = 9;
    test_msg.tow = 2567800;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 55286, test_msg_len, (u8*)&test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    ck_assert_msg(check_msg->d == 0, "incorrect value for d, expected 0, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -25747, "incorrect value for e, expected -25747, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 1, "incorrect value for flags, expected 1, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -96629, "incorrect value for n, expected -96629, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2567800, "incorrect value for tow, expected 2567800, is %d", check_msg->tow);
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

    u8 encoded_frame[] = {85,3,2,246,215,22,220,46,39,0,37,134,254,255,240,156,255,255,0,0,0,0,0,0,0,0,9,1,58,133, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = 0;
    test_msg.e = -25360;
    test_msg.flags = 1;
    test_msg.h_accuracy = 0;
    test_msg.n = -96731;
    test_msg.n_sats = 9;
    test_msg.tow = 2567900;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 55286, test_msg_len, (u8*)&test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    ck_assert_msg(check_msg->d == 0, "incorrect value for d, expected 0, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -25360, "incorrect value for e, expected -25360, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 1, "incorrect value for flags, expected 1, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -96731, "incorrect value for n, expected -96731, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2567900, "incorrect value for tow, expected 2567900, is %d", check_msg->tow);
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

    u8 encoded_frame[] = {85,3,2,246,215,22,64,47,39,0,193,133,254,255,115,158,255,255,0,0,0,0,0,0,0,0,9,1,56,214, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = 0;
    test_msg.e = -24973;
    test_msg.flags = 1;
    test_msg.h_accuracy = 0;
    test_msg.n = -96831;
    test_msg.n_sats = 9;
    test_msg.tow = 2568000;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 55286, test_msg_len, (u8*)&test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    ck_assert_msg(check_msg->d == 0, "incorrect value for d, expected 0, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -24973, "incorrect value for e, expected -24973, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 1, "incorrect value for flags, expected 1, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -96831, "incorrect value for n, expected -96831, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2568000, "incorrect value for tow, expected 2568000, is %d", check_msg->tow);
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

    u8 encoded_frame[] = {85,3,2,246,215,22,164,47,39,0,93,133,254,255,246,159,255,255,0,0,0,0,0,0,0,0,9,1,234,244, };

    dummy_reset();
    msg_baseline_ned_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.d = 0;
    test_msg.e = -24586;
    test_msg.flags = 1;
    test_msg.h_accuracy = 0;
    test_msg.n = -96931;
    test_msg.n_sats = 9;
    test_msg.tow = 2568100;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x203, 55286, test_msg_len, (u8*)&test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    ck_assert_msg(check_msg->d == 0, "incorrect value for d, expected 0, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -24586, "incorrect value for e, expected -24586, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 1, "incorrect value for flags, expected 1, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -96931, "incorrect value for n, expected -96931, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2568100, "incorrect value for tow, expected 2568100, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_7_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_navigation_7");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_7");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_7);
  suite_add_tcase(s, tc_acq);
  return s;
}