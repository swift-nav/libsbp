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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNED.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <libsbp/sbp.h>
#include <libsbp/unpacked/navigation.h>
#include <libsbp/packed/navigation.h>

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
  memset(&last_unpacked, 0, sizeof(last_unpacked));
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

static void unpacked_callback(u16 sender_id, u16 msg_type, const sbp_msg_t *msg, void *context)
{
  last_unpacked.n_callbacks_logged++;
  last_unpacked.sender_id = sender_id;
  last_unpacked.msg_type = msg_type;
  last_unpacked.msg = *msg;
  last_unpacked.context = context;
}

START_TEST( test_packed_auto_check_sbp_navigation_MsgVelNED )
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

    sbp_register_callback(&sbp_state, 0x20e, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20e, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,14,2,211,136,22,40,244,122,19,3,0,0,0,252,255,255,255,243,255,255,255,0,0,0,0,14,0,86,209, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_vel_ned_t* test_msg = ( msg_vel_ned_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->d = -13;
    test_msg->e = -4;
    test_msg->flags = 0;
    test_msg->h_accuracy = 0;
    test_msg->n = 3;
    test_msg->n_sats = 14;
    test_msg->tow = 326825000;
    test_msg->v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x20e, 35027, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
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
    ck_assert_msg(last_frame.sender_id == 35027,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x20e,
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
    msg_vel_ned_t* check_msg = ( msg_vel_ned_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -13, "incorrect value for d, expected -13, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -4, "incorrect value for e, expected -4, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == 3, "incorrect value for n, expected 3, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 14, "incorrect value for n_sats, expected 14, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326825000, "incorrect value for tow, expected 326825000, is %d", check_msg->tow);
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

    sbp_register_callback(&sbp_state, 0x20e, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20e, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,14,2,211,136,22,28,246,122,19,252,255,255,255,255,255,255,255,232,255,255,255,0,0,0,0,15,0,16,228, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_vel_ned_t* test_msg = ( msg_vel_ned_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->d = -24;
    test_msg->e = -1;
    test_msg->flags = 0;
    test_msg->h_accuracy = 0;
    test_msg->n = -4;
    test_msg->n_sats = 15;
    test_msg->tow = 326825500;
    test_msg->v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x20e, 35027, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
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
    ck_assert_msg(last_frame.sender_id == 35027,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x20e,
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
    msg_vel_ned_t* check_msg = ( msg_vel_ned_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -24, "incorrect value for d, expected -24, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -1, "incorrect value for e, expected -1, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == -4, "incorrect value for n, expected -4, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326825500, "incorrect value for tow, expected 326825500, is %d", check_msg->tow);
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

    sbp_register_callback(&sbp_state, 0x20e, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20e, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,14,2,211,136,22,16,248,122,19,0,0,0,0,253,255,255,255,244,255,255,255,0,0,0,0,15,0,11,164, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_vel_ned_t* test_msg = ( msg_vel_ned_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->d = -12;
    test_msg->e = -3;
    test_msg->flags = 0;
    test_msg->h_accuracy = 0;
    test_msg->n = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326826000;
    test_msg->v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x20e, 35027, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
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
    ck_assert_msg(last_frame.sender_id == 35027,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x20e,
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
    msg_vel_ned_t* check_msg = ( msg_vel_ned_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -12, "incorrect value for d, expected -12, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == -3, "incorrect value for e, expected -3, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == 0, "incorrect value for n, expected 0, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326826000, "incorrect value for tow, expected 326826000, is %d", check_msg->tow);
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

    sbp_register_callback(&sbp_state, 0x20e, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20e, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,14,2,211,136,22,4,250,122,19,2,0,0,0,3,0,0,0,232,255,255,255,0,0,0,0,15,0,152,208, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_vel_ned_t* test_msg = ( msg_vel_ned_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->d = -24;
    test_msg->e = 3;
    test_msg->flags = 0;
    test_msg->h_accuracy = 0;
    test_msg->n = 2;
    test_msg->n_sats = 15;
    test_msg->tow = 326826500;
    test_msg->v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x20e, 35027, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
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
    ck_assert_msg(last_frame.sender_id == 35027,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x20e,
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
    msg_vel_ned_t* check_msg = ( msg_vel_ned_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -24, "incorrect value for d, expected -24, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 3, "incorrect value for e, expected 3, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == 2, "incorrect value for n, expected 2, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326826500, "incorrect value for tow, expected 326826500, is %d", check_msg->tow);
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

    sbp_register_callback(&sbp_state, 0x20e, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20e, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,14,2,211,136,22,248,251,122,19,1,0,0,0,0,0,0,0,235,255,255,255,0,0,0,0,15,0,182,120, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_vel_ned_t* test_msg = ( msg_vel_ned_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->d = -21;
    test_msg->e = 0;
    test_msg->flags = 0;
    test_msg->h_accuracy = 0;
    test_msg->n = 1;
    test_msg->n_sats = 15;
    test_msg->tow = 326827000;
    test_msg->v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x20e, 35027, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
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
    ck_assert_msg(last_frame.sender_id == 35027,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x20e,
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
    msg_vel_ned_t* check_msg = ( msg_vel_ned_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->d == -21, "incorrect value for d, expected -21, is %d", check_msg->d);
    ck_assert_msg(check_msg->e == 0, "incorrect value for e, expected 0, is %d", check_msg->e);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg(check_msg->n == 1, "incorrect value for n, expected 1, is %d", check_msg->n);
    ck_assert_msg(check_msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326827000, "incorrect value for tow, expected 326827000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
}
END_TEST

START_TEST( test_unpacked_auto_check_sbp_navigation_MsgVelNED )
{
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
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0x20e, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,14,2,211,136,22,40,244,122,19,3,0,0,0,252,255,255,255,243,255,255,255,0,0,0,0,14,0,86,209, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.vel_ned.d = -13;
    test_unpacked_msg.vel_ned.e = -4;
    test_unpacked_msg.vel_ned.flags = 0;
    test_unpacked_msg.vel_ned.h_accuracy = 0;
    test_unpacked_msg.vel_ned.n = 3;
    test_unpacked_msg.vel_ned.n_sats = 14;
    test_unpacked_msg.vel_ned.tow = 326825000;
    test_unpacked_msg.vel_ned.v_accuracy = 0;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_VEL_NED, 35027, &test_unpacked_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
        "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    ck_assert_msg(last_unpacked.n_callbacks_logged == 1,
        "unpacked_callback: one callback should have been logged");
    ck_assert_msg(last_unpacked.sender_id == 35027,
        "unpacked_callback: sender_id decoded incorrectly");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    const msg_vel_ned_t* check_msg = ( msg_vel_ned_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->vel_ned.d == -13, "incorrect value for check_unpacked_msg->vel_ned.d, expected -13, is %d", check_unpacked_msg->vel_ned.d);
    ck_assert_msg(check_unpacked_msg->vel_ned.e == -4, "incorrect value for check_unpacked_msg->vel_ned.e, expected -4, is %d", check_unpacked_msg->vel_ned.e);
    ck_assert_msg(check_unpacked_msg->vel_ned.flags == 0, "incorrect value for check_unpacked_msg->vel_ned.flags, expected 0, is %d", check_unpacked_msg->vel_ned.flags);
    ck_assert_msg(check_unpacked_msg->vel_ned.h_accuracy == 0, "incorrect value for check_unpacked_msg->vel_ned.h_accuracy, expected 0, is %d", check_unpacked_msg->vel_ned.h_accuracy);
    ck_assert_msg(check_unpacked_msg->vel_ned.n == 3, "incorrect value for check_unpacked_msg->vel_ned.n, expected 3, is %d", check_unpacked_msg->vel_ned.n);
    ck_assert_msg(check_unpacked_msg->vel_ned.n_sats == 14, "incorrect value for check_unpacked_msg->vel_ned.n_sats, expected 14, is %d", check_unpacked_msg->vel_ned.n_sats);
    ck_assert_msg(check_unpacked_msg->vel_ned.tow == 326825000, "incorrect value for check_unpacked_msg->vel_ned.tow, expected 326825000, is %d", check_unpacked_msg->vel_ned.tow);
    ck_assert_msg(check_unpacked_msg->vel_ned.v_accuracy == 0, "incorrect value for check_unpacked_msg->vel_ned.v_accuracy, expected 0, is %d", check_unpacked_msg->vel_ned.v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0x20e, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,14,2,211,136,22,28,246,122,19,252,255,255,255,255,255,255,255,232,255,255,255,0,0,0,0,15,0,16,228, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.vel_ned.d = -24;
    test_unpacked_msg.vel_ned.e = -1;
    test_unpacked_msg.vel_ned.flags = 0;
    test_unpacked_msg.vel_ned.h_accuracy = 0;
    test_unpacked_msg.vel_ned.n = -4;
    test_unpacked_msg.vel_ned.n_sats = 15;
    test_unpacked_msg.vel_ned.tow = 326825500;
    test_unpacked_msg.vel_ned.v_accuracy = 0;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_VEL_NED, 35027, &test_unpacked_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
        "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    ck_assert_msg(last_unpacked.n_callbacks_logged == 1,
        "unpacked_callback: one callback should have been logged");
    ck_assert_msg(last_unpacked.sender_id == 35027,
        "unpacked_callback: sender_id decoded incorrectly");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    const msg_vel_ned_t* check_msg = ( msg_vel_ned_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->vel_ned.d == -24, "incorrect value for check_unpacked_msg->vel_ned.d, expected -24, is %d", check_unpacked_msg->vel_ned.d);
    ck_assert_msg(check_unpacked_msg->vel_ned.e == -1, "incorrect value for check_unpacked_msg->vel_ned.e, expected -1, is %d", check_unpacked_msg->vel_ned.e);
    ck_assert_msg(check_unpacked_msg->vel_ned.flags == 0, "incorrect value for check_unpacked_msg->vel_ned.flags, expected 0, is %d", check_unpacked_msg->vel_ned.flags);
    ck_assert_msg(check_unpacked_msg->vel_ned.h_accuracy == 0, "incorrect value for check_unpacked_msg->vel_ned.h_accuracy, expected 0, is %d", check_unpacked_msg->vel_ned.h_accuracy);
    ck_assert_msg(check_unpacked_msg->vel_ned.n == -4, "incorrect value for check_unpacked_msg->vel_ned.n, expected -4, is %d", check_unpacked_msg->vel_ned.n);
    ck_assert_msg(check_unpacked_msg->vel_ned.n_sats == 15, "incorrect value for check_unpacked_msg->vel_ned.n_sats, expected 15, is %d", check_unpacked_msg->vel_ned.n_sats);
    ck_assert_msg(check_unpacked_msg->vel_ned.tow == 326825500, "incorrect value for check_unpacked_msg->vel_ned.tow, expected 326825500, is %d", check_unpacked_msg->vel_ned.tow);
    ck_assert_msg(check_unpacked_msg->vel_ned.v_accuracy == 0, "incorrect value for check_unpacked_msg->vel_ned.v_accuracy, expected 0, is %d", check_unpacked_msg->vel_ned.v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0x20e, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,14,2,211,136,22,16,248,122,19,0,0,0,0,253,255,255,255,244,255,255,255,0,0,0,0,15,0,11,164, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.vel_ned.d = -12;
    test_unpacked_msg.vel_ned.e = -3;
    test_unpacked_msg.vel_ned.flags = 0;
    test_unpacked_msg.vel_ned.h_accuracy = 0;
    test_unpacked_msg.vel_ned.n = 0;
    test_unpacked_msg.vel_ned.n_sats = 15;
    test_unpacked_msg.vel_ned.tow = 326826000;
    test_unpacked_msg.vel_ned.v_accuracy = 0;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_VEL_NED, 35027, &test_unpacked_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
        "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    ck_assert_msg(last_unpacked.n_callbacks_logged == 1,
        "unpacked_callback: one callback should have been logged");
    ck_assert_msg(last_unpacked.sender_id == 35027,
        "unpacked_callback: sender_id decoded incorrectly");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    const msg_vel_ned_t* check_msg = ( msg_vel_ned_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->vel_ned.d == -12, "incorrect value for check_unpacked_msg->vel_ned.d, expected -12, is %d", check_unpacked_msg->vel_ned.d);
    ck_assert_msg(check_unpacked_msg->vel_ned.e == -3, "incorrect value for check_unpacked_msg->vel_ned.e, expected -3, is %d", check_unpacked_msg->vel_ned.e);
    ck_assert_msg(check_unpacked_msg->vel_ned.flags == 0, "incorrect value for check_unpacked_msg->vel_ned.flags, expected 0, is %d", check_unpacked_msg->vel_ned.flags);
    ck_assert_msg(check_unpacked_msg->vel_ned.h_accuracy == 0, "incorrect value for check_unpacked_msg->vel_ned.h_accuracy, expected 0, is %d", check_unpacked_msg->vel_ned.h_accuracy);
    ck_assert_msg(check_unpacked_msg->vel_ned.n == 0, "incorrect value for check_unpacked_msg->vel_ned.n, expected 0, is %d", check_unpacked_msg->vel_ned.n);
    ck_assert_msg(check_unpacked_msg->vel_ned.n_sats == 15, "incorrect value for check_unpacked_msg->vel_ned.n_sats, expected 15, is %d", check_unpacked_msg->vel_ned.n_sats);
    ck_assert_msg(check_unpacked_msg->vel_ned.tow == 326826000, "incorrect value for check_unpacked_msg->vel_ned.tow, expected 326826000, is %d", check_unpacked_msg->vel_ned.tow);
    ck_assert_msg(check_unpacked_msg->vel_ned.v_accuracy == 0, "incorrect value for check_unpacked_msg->vel_ned.v_accuracy, expected 0, is %d", check_unpacked_msg->vel_ned.v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0x20e, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,14,2,211,136,22,4,250,122,19,2,0,0,0,3,0,0,0,232,255,255,255,0,0,0,0,15,0,152,208, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.vel_ned.d = -24;
    test_unpacked_msg.vel_ned.e = 3;
    test_unpacked_msg.vel_ned.flags = 0;
    test_unpacked_msg.vel_ned.h_accuracy = 0;
    test_unpacked_msg.vel_ned.n = 2;
    test_unpacked_msg.vel_ned.n_sats = 15;
    test_unpacked_msg.vel_ned.tow = 326826500;
    test_unpacked_msg.vel_ned.v_accuracy = 0;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_VEL_NED, 35027, &test_unpacked_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
        "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    ck_assert_msg(last_unpacked.n_callbacks_logged == 1,
        "unpacked_callback: one callback should have been logged");
    ck_assert_msg(last_unpacked.sender_id == 35027,
        "unpacked_callback: sender_id decoded incorrectly");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    const msg_vel_ned_t* check_msg = ( msg_vel_ned_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->vel_ned.d == -24, "incorrect value for check_unpacked_msg->vel_ned.d, expected -24, is %d", check_unpacked_msg->vel_ned.d);
    ck_assert_msg(check_unpacked_msg->vel_ned.e == 3, "incorrect value for check_unpacked_msg->vel_ned.e, expected 3, is %d", check_unpacked_msg->vel_ned.e);
    ck_assert_msg(check_unpacked_msg->vel_ned.flags == 0, "incorrect value for check_unpacked_msg->vel_ned.flags, expected 0, is %d", check_unpacked_msg->vel_ned.flags);
    ck_assert_msg(check_unpacked_msg->vel_ned.h_accuracy == 0, "incorrect value for check_unpacked_msg->vel_ned.h_accuracy, expected 0, is %d", check_unpacked_msg->vel_ned.h_accuracy);
    ck_assert_msg(check_unpacked_msg->vel_ned.n == 2, "incorrect value for check_unpacked_msg->vel_ned.n, expected 2, is %d", check_unpacked_msg->vel_ned.n);
    ck_assert_msg(check_unpacked_msg->vel_ned.n_sats == 15, "incorrect value for check_unpacked_msg->vel_ned.n_sats, expected 15, is %d", check_unpacked_msg->vel_ned.n_sats);
    ck_assert_msg(check_unpacked_msg->vel_ned.tow == 326826500, "incorrect value for check_unpacked_msg->vel_ned.tow, expected 326826500, is %d", check_unpacked_msg->vel_ned.tow);
    ck_assert_msg(check_unpacked_msg->vel_ned.v_accuracy == 0, "incorrect value for check_unpacked_msg->vel_ned.v_accuracy, expected 0, is %d", check_unpacked_msg->vel_ned.v_accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0x20e, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,14,2,211,136,22,248,251,122,19,1,0,0,0,0,0,0,0,235,255,255,255,0,0,0,0,15,0,182,120, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.vel_ned.d = -21;
    test_unpacked_msg.vel_ned.e = 0;
    test_unpacked_msg.vel_ned.flags = 0;
    test_unpacked_msg.vel_ned.h_accuracy = 0;
    test_unpacked_msg.vel_ned.n = 1;
    test_unpacked_msg.vel_ned.n_sats = 15;
    test_unpacked_msg.vel_ned.tow = 326827000;
    test_unpacked_msg.vel_ned.v_accuracy = 0;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_VEL_NED, 35027, &test_unpacked_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
        "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    ck_assert_msg(last_unpacked.n_callbacks_logged == 1,
        "unpacked_callback: one callback should have been logged");
    ck_assert_msg(last_unpacked.sender_id == 35027,
        "unpacked_callback: sender_id decoded incorrectly");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    const msg_vel_ned_t* check_msg = ( msg_vel_ned_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->vel_ned.d == -21, "incorrect value for check_unpacked_msg->vel_ned.d, expected -21, is %d", check_unpacked_msg->vel_ned.d);
    ck_assert_msg(check_unpacked_msg->vel_ned.e == 0, "incorrect value for check_unpacked_msg->vel_ned.e, expected 0, is %d", check_unpacked_msg->vel_ned.e);
    ck_assert_msg(check_unpacked_msg->vel_ned.flags == 0, "incorrect value for check_unpacked_msg->vel_ned.flags, expected 0, is %d", check_unpacked_msg->vel_ned.flags);
    ck_assert_msg(check_unpacked_msg->vel_ned.h_accuracy == 0, "incorrect value for check_unpacked_msg->vel_ned.h_accuracy, expected 0, is %d", check_unpacked_msg->vel_ned.h_accuracy);
    ck_assert_msg(check_unpacked_msg->vel_ned.n == 1, "incorrect value for check_unpacked_msg->vel_ned.n, expected 1, is %d", check_unpacked_msg->vel_ned.n);
    ck_assert_msg(check_unpacked_msg->vel_ned.n_sats == 15, "incorrect value for check_unpacked_msg->vel_ned.n_sats, expected 15, is %d", check_unpacked_msg->vel_ned.n_sats);
    ck_assert_msg(check_unpacked_msg->vel_ned.tow == 326827000, "incorrect value for check_unpacked_msg->vel_ned.tow, expected 326827000, is %d", check_unpacked_msg->vel_ned.tow);
    ck_assert_msg(check_unpacked_msg->vel_ned.v_accuracy == 0, "incorrect value for check_unpacked_msg->vel_ned.v_accuracy, expected 0, is %d", check_unpacked_msg->vel_ned.v_accuracy);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_MsgVelNED_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_navigation_MsgVelNED");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgVelNED");
  tcase_add_test(tc_acq, test_packed_auto_check_sbp_navigation_MsgVelNED);
  tcase_add_test(tc_acq, test_unpacked_auto_check_sbp_navigation_MsgVelNED);
  suite_add_tcase(s, tc_acq);
  return s;
}