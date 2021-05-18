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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEF.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_packed_auto_check_sbp_navigation_MsgBaselineECEF )
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

    sbp_register_callback(&sbp_state, 0x20b, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20b, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,11,2,211,136,20,40,244,122,19,150,98,238,255,190,64,20,0,246,163,9,0,0,0,14,0,219,191, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_baseline_ecef_t* test_msg = ( msg_baseline_ecef_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 14;
    test_msg->tow = 326825000;
    test_msg->x = -1154410;
    test_msg->y = 1327294;
    test_msg->z = 631798;
    sbp_send_message(&sbp_state, 0x20b, 35027, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x20b,
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
    msg_baseline_ecef_t* check_msg = ( msg_baseline_ecef_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 14, "incorrect value for n_sats, expected 14, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326825000, "incorrect value for tow, expected 326825000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -1154410, "incorrect value for x, expected -1154410, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == 1327294, "incorrect value for y, expected 1327294, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 631798, "incorrect value for z, expected 631798, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20b, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20b, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,11,2,211,136,20,16,248,122,19,72,99,238,255,191,65,20,0,138,162,9,0,0,0,15,0,240,78, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_baseline_ecef_t* test_msg = ( msg_baseline_ecef_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326826000;
    test_msg->x = -1154232;
    test_msg->y = 1327551;
    test_msg->z = 631434;
    sbp_send_message(&sbp_state, 0x20b, 35027, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x20b,
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
    msg_baseline_ecef_t* check_msg = ( msg_baseline_ecef_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326826000, "incorrect value for tow, expected 326826000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -1154232, "incorrect value for x, expected -1154232, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == 1327551, "incorrect value for y, expected 1327551, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 631434, "incorrect value for z, expected 631434, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20b, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20b, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,11,2,211,136,20,248,251,122,19,41,99,238,255,181,65,20,0,148,161,9,0,0,0,15,0,4,132, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_baseline_ecef_t* test_msg = ( msg_baseline_ecef_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326827000;
    test_msg->x = -1154263;
    test_msg->y = 1327541;
    test_msg->z = 631188;
    sbp_send_message(&sbp_state, 0x20b, 35027, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x20b,
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
    msg_baseline_ecef_t* check_msg = ( msg_baseline_ecef_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326827000, "incorrect value for tow, expected 326827000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -1154263, "incorrect value for x, expected -1154263, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == 1327541, "incorrect value for y, expected 1327541, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 631188, "incorrect value for z, expected 631188, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20b, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20b, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,11,2,211,136,20,224,255,122,19,188,97,238,255,81,64,20,0,65,160,9,0,0,0,15,0,67,94, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_baseline_ecef_t* test_msg = ( msg_baseline_ecef_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326828000;
    test_msg->x = -1154628;
    test_msg->y = 1327185;
    test_msg->z = 630849;
    sbp_send_message(&sbp_state, 0x20b, 35027, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x20b,
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
    msg_baseline_ecef_t* check_msg = ( msg_baseline_ecef_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326828000, "incorrect value for tow, expected 326828000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -1154628, "incorrect value for x, expected -1154628, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == 1327185, "incorrect value for y, expected 1327185, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 630849, "incorrect value for z, expected 630849, is %d", check_msg->z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20b, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20b, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,11,2,211,136,20,200,3,123,19,189,96,238,255,93,63,20,0,98,159,9,0,0,0,15,0,106,94, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_baseline_ecef_t* test_msg = ( msg_baseline_ecef_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326829000;
    test_msg->x = -1154883;
    test_msg->y = 1326941;
    test_msg->z = 630626;
    sbp_send_message(&sbp_state, 0x20b, 35027, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x20b,
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
    msg_baseline_ecef_t* check_msg = ( msg_baseline_ecef_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0, "incorrect value for flags, expected 0, is %d", check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326829000, "incorrect value for tow, expected 326829000, is %d", check_msg->tow);
    ck_assert_msg(check_msg->x == -1154883, "incorrect value for x, expected -1154883, is %d", check_msg->x);
    ck_assert_msg(check_msg->y == 1326941, "incorrect value for y, expected 1326941, is %d", check_msg->y);
    ck_assert_msg(check_msg->z == 630626, "incorrect value for z, expected 630626, is %d", check_msg->z);
  }
}
END_TEST

START_TEST( test_unpacked_auto_check_sbp_navigation_MsgBaselineECEF )
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

    sbp_register_unpacked_callback(&sbp_state, 0x20b, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,11,2,211,136,20,40,244,122,19,150,98,238,255,190,64,20,0,246,163,9,0,0,0,14,0,219,191, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.baseline_ecef.accuracy = 0;
    test_unpacked_msg.baseline_ecef.flags = 0;
    test_unpacked_msg.baseline_ecef.n_sats = 14;
    test_unpacked_msg.baseline_ecef.tow = 326825000;
    test_unpacked_msg.baseline_ecef.x = -1154410;
    test_unpacked_msg.baseline_ecef.y = 1327294;
    test_unpacked_msg.baseline_ecef.z = 631798;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_BASELINE_ECEF, 35027, &test_unpacked_msg, &dummy_write);

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
    const msg_baseline_ecef_t* check_msg = ( msg_baseline_ecef_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->baseline_ecef.accuracy == 0, "incorrect value for check_unpacked_msg->baseline_ecef.accuracy, expected 0, is %d", check_unpacked_msg->baseline_ecef.accuracy);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.flags == 0, "incorrect value for check_unpacked_msg->baseline_ecef.flags, expected 0, is %d", check_unpacked_msg->baseline_ecef.flags);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.n_sats == 14, "incorrect value for check_unpacked_msg->baseline_ecef.n_sats, expected 14, is %d", check_unpacked_msg->baseline_ecef.n_sats);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.tow == 326825000, "incorrect value for check_unpacked_msg->baseline_ecef.tow, expected 326825000, is %d", check_unpacked_msg->baseline_ecef.tow);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.x == -1154410, "incorrect value for check_unpacked_msg->baseline_ecef.x, expected -1154410, is %d", check_unpacked_msg->baseline_ecef.x);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.y == 1327294, "incorrect value for check_unpacked_msg->baseline_ecef.y, expected 1327294, is %d", check_unpacked_msg->baseline_ecef.y);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.z == 631798, "incorrect value for check_unpacked_msg->baseline_ecef.z, expected 631798, is %d", check_unpacked_msg->baseline_ecef.z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0x20b, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,11,2,211,136,20,16,248,122,19,72,99,238,255,191,65,20,0,138,162,9,0,0,0,15,0,240,78, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.baseline_ecef.accuracy = 0;
    test_unpacked_msg.baseline_ecef.flags = 0;
    test_unpacked_msg.baseline_ecef.n_sats = 15;
    test_unpacked_msg.baseline_ecef.tow = 326826000;
    test_unpacked_msg.baseline_ecef.x = -1154232;
    test_unpacked_msg.baseline_ecef.y = 1327551;
    test_unpacked_msg.baseline_ecef.z = 631434;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_BASELINE_ECEF, 35027, &test_unpacked_msg, &dummy_write);

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
    const msg_baseline_ecef_t* check_msg = ( msg_baseline_ecef_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->baseline_ecef.accuracy == 0, "incorrect value for check_unpacked_msg->baseline_ecef.accuracy, expected 0, is %d", check_unpacked_msg->baseline_ecef.accuracy);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.flags == 0, "incorrect value for check_unpacked_msg->baseline_ecef.flags, expected 0, is %d", check_unpacked_msg->baseline_ecef.flags);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.n_sats == 15, "incorrect value for check_unpacked_msg->baseline_ecef.n_sats, expected 15, is %d", check_unpacked_msg->baseline_ecef.n_sats);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.tow == 326826000, "incorrect value for check_unpacked_msg->baseline_ecef.tow, expected 326826000, is %d", check_unpacked_msg->baseline_ecef.tow);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.x == -1154232, "incorrect value for check_unpacked_msg->baseline_ecef.x, expected -1154232, is %d", check_unpacked_msg->baseline_ecef.x);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.y == 1327551, "incorrect value for check_unpacked_msg->baseline_ecef.y, expected 1327551, is %d", check_unpacked_msg->baseline_ecef.y);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.z == 631434, "incorrect value for check_unpacked_msg->baseline_ecef.z, expected 631434, is %d", check_unpacked_msg->baseline_ecef.z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0x20b, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,11,2,211,136,20,248,251,122,19,41,99,238,255,181,65,20,0,148,161,9,0,0,0,15,0,4,132, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.baseline_ecef.accuracy = 0;
    test_unpacked_msg.baseline_ecef.flags = 0;
    test_unpacked_msg.baseline_ecef.n_sats = 15;
    test_unpacked_msg.baseline_ecef.tow = 326827000;
    test_unpacked_msg.baseline_ecef.x = -1154263;
    test_unpacked_msg.baseline_ecef.y = 1327541;
    test_unpacked_msg.baseline_ecef.z = 631188;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_BASELINE_ECEF, 35027, &test_unpacked_msg, &dummy_write);

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
    const msg_baseline_ecef_t* check_msg = ( msg_baseline_ecef_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->baseline_ecef.accuracy == 0, "incorrect value for check_unpacked_msg->baseline_ecef.accuracy, expected 0, is %d", check_unpacked_msg->baseline_ecef.accuracy);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.flags == 0, "incorrect value for check_unpacked_msg->baseline_ecef.flags, expected 0, is %d", check_unpacked_msg->baseline_ecef.flags);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.n_sats == 15, "incorrect value for check_unpacked_msg->baseline_ecef.n_sats, expected 15, is %d", check_unpacked_msg->baseline_ecef.n_sats);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.tow == 326827000, "incorrect value for check_unpacked_msg->baseline_ecef.tow, expected 326827000, is %d", check_unpacked_msg->baseline_ecef.tow);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.x == -1154263, "incorrect value for check_unpacked_msg->baseline_ecef.x, expected -1154263, is %d", check_unpacked_msg->baseline_ecef.x);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.y == 1327541, "incorrect value for check_unpacked_msg->baseline_ecef.y, expected 1327541, is %d", check_unpacked_msg->baseline_ecef.y);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.z == 631188, "incorrect value for check_unpacked_msg->baseline_ecef.z, expected 631188, is %d", check_unpacked_msg->baseline_ecef.z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0x20b, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,11,2,211,136,20,224,255,122,19,188,97,238,255,81,64,20,0,65,160,9,0,0,0,15,0,67,94, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.baseline_ecef.accuracy = 0;
    test_unpacked_msg.baseline_ecef.flags = 0;
    test_unpacked_msg.baseline_ecef.n_sats = 15;
    test_unpacked_msg.baseline_ecef.tow = 326828000;
    test_unpacked_msg.baseline_ecef.x = -1154628;
    test_unpacked_msg.baseline_ecef.y = 1327185;
    test_unpacked_msg.baseline_ecef.z = 630849;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_BASELINE_ECEF, 35027, &test_unpacked_msg, &dummy_write);

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
    const msg_baseline_ecef_t* check_msg = ( msg_baseline_ecef_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->baseline_ecef.accuracy == 0, "incorrect value for check_unpacked_msg->baseline_ecef.accuracy, expected 0, is %d", check_unpacked_msg->baseline_ecef.accuracy);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.flags == 0, "incorrect value for check_unpacked_msg->baseline_ecef.flags, expected 0, is %d", check_unpacked_msg->baseline_ecef.flags);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.n_sats == 15, "incorrect value for check_unpacked_msg->baseline_ecef.n_sats, expected 15, is %d", check_unpacked_msg->baseline_ecef.n_sats);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.tow == 326828000, "incorrect value for check_unpacked_msg->baseline_ecef.tow, expected 326828000, is %d", check_unpacked_msg->baseline_ecef.tow);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.x == -1154628, "incorrect value for check_unpacked_msg->baseline_ecef.x, expected -1154628, is %d", check_unpacked_msg->baseline_ecef.x);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.y == 1327185, "incorrect value for check_unpacked_msg->baseline_ecef.y, expected 1327185, is %d", check_unpacked_msg->baseline_ecef.y);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.z == 630849, "incorrect value for check_unpacked_msg->baseline_ecef.z, expected 630849, is %d", check_unpacked_msg->baseline_ecef.z);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_unpacked_callback(&sbp_state, 0x20b, &unpacked_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {85,11,2,211,136,20,200,3,123,19,189,96,238,255,93,63,20,0,98,159,9,0,0,0,15,0,106,94, };

    dummy_reset();

    sbp_msg_t test_unpacked_msg;
    memset(&test_unpacked_msg, 0, sizeof(test_unpacked_msg));
    test_unpacked_msg.baseline_ecef.accuracy = 0;
    test_unpacked_msg.baseline_ecef.flags = 0;
    test_unpacked_msg.baseline_ecef.n_sats = 15;
    test_unpacked_msg.baseline_ecef.tow = 326829000;
    test_unpacked_msg.baseline_ecef.x = -1154883;
    test_unpacked_msg.baseline_ecef.y = 1326941;
    test_unpacked_msg.baseline_ecef.z = 630626;

    sbp_pack_and_send_message(&sbp_state, SBP_MSG_BASELINE_ECEF, 35027, &test_unpacked_msg, &dummy_write);

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
    const msg_baseline_ecef_t* check_msg = ( msg_baseline_ecef_t *)((void *)last_msg.msg);
    const sbp_msg_t *check_unpacked_msg = &last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_unpacked_msg->baseline_ecef.accuracy == 0, "incorrect value for check_unpacked_msg->baseline_ecef.accuracy, expected 0, is %d", check_unpacked_msg->baseline_ecef.accuracy);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.flags == 0, "incorrect value for check_unpacked_msg->baseline_ecef.flags, expected 0, is %d", check_unpacked_msg->baseline_ecef.flags);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.n_sats == 15, "incorrect value for check_unpacked_msg->baseline_ecef.n_sats, expected 15, is %d", check_unpacked_msg->baseline_ecef.n_sats);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.tow == 326829000, "incorrect value for check_unpacked_msg->baseline_ecef.tow, expected 326829000, is %d", check_unpacked_msg->baseline_ecef.tow);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.x == -1154883, "incorrect value for check_unpacked_msg->baseline_ecef.x, expected -1154883, is %d", check_unpacked_msg->baseline_ecef.x);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.y == 1326941, "incorrect value for check_unpacked_msg->baseline_ecef.y, expected 1326941, is %d", check_unpacked_msg->baseline_ecef.y);
    ck_assert_msg(check_unpacked_msg->baseline_ecef.z == 630626, "incorrect value for check_unpacked_msg->baseline_ecef.z, expected 630626, is %d", check_unpacked_msg->baseline_ecef.z);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_MsgBaselineECEF_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_navigation_MsgBaselineECEF");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgBaselineECEF");
  tcase_add_test(tc_acq, test_packed_auto_check_sbp_navigation_MsgBaselineECEF);
  tcase_add_test(tc_acq, test_unpacked_auto_check_sbp_navigation_MsgBaselineECEF);
  suite_add_tcase(s, tc_acq);
  return s;
}