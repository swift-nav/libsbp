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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHDepA.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_navigation_17 )
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

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,246,215,34,20,46,39,0,250,29,226,186,235,182,66,64,19,203,51,196,24,139,94,192,31,157,160,232,122,115,81,64,0,0,0,0,9,0,236,139, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.height = 69.80437675175607;
    test_msg.lat = 37.42906890908121;
    test_msg.lon = -122.17338662202773;
    test_msg.n_sats = 9;
    test_msg.tow = 2567700;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 55286, test_msg_len, (u8*)&test_msg, &dummy_write);

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
    ck_assert_msg((check_msg->height*100 - 69.8043767518*100) < 0.05, "incorrect value for height, expected 69.8043767518, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.4290689091*100) < 0.05, "incorrect value for lat, expected 37.4290689091, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.173386622*100) < 0.05, "incorrect value for lon, expected -122.173386622, is %f", check_msg->lon);
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

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,246,215,34,20,46,39,0,161,51,75,148,235,182,66,64,36,41,246,30,25,139,94,192,254,218,49,127,10,108,81,64,0,0,0,0,9,1,25,117, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 1;
    test_msg.h_accuracy = 0;
    test_msg.height = 69.68814067715354;
    test_msg.lat = 37.42906430885274;
    test_msg.lon = -122.17340826071865;
    test_msg.n_sats = 9;
    test_msg.tow = 2567700;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 55286, test_msg_len, (u8*)&test_msg, &dummy_write);

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
    ck_assert_msg(check_msg->flags == 1, "incorrect value for flags, expected 1, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg((check_msg->height*100 - 69.6881406772*100) < 0.05, "incorrect value for height, expected 69.6881406772, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.4290643089*100) < 0.05, "incorrect value for lat, expected 37.4290643089, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.173408261*100) < 0.05, "incorrect value for lon, expected -122.173408261, is %f", check_msg->lon);
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

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,246,215,34,120,46,39,0,56,214,210,65,235,182,66,64,13,46,132,80,25,139,94,192,22,143,46,234,191,95,81,64,0,0,0,0,9,0,174,105, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.height = 69.49608854815264;
    test_msg.lat = 37.42905447764173;
    test_msg.lon = -122.17342007549469;
    test_msg.n_sats = 9;
    test_msg.tow = 2567800;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 55286, test_msg_len, (u8*)&test_msg, &dummy_write);

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
    ck_assert_msg((check_msg->height*100 - 69.4960885482*100) < 0.05, "incorrect value for height, expected 69.4960885482, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.4290544776*100) < 0.05, "incorrect value for lat, expected 37.4290544776, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.173420075*100) < 0.05, "incorrect value for lon, expected -122.173420075, is %f", check_msg->lon);
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

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,246,215,34,120,46,39,0,251,117,115,140,235,182,66,64,152,134,167,12,25,139,94,192,160,22,137,253,4,108,81,64,0,0,0,0,9,1,122,127, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 1;
    test_msg.h_accuracy = 0;
    test_msg.height = 69.68780458819901;
    test_msg.lat = 37.429063373925565;
    test_msg.lon = -122.17340389594972;
    test_msg.n_sats = 9;
    test_msg.tow = 2567800;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 55286, test_msg_len, (u8*)&test_msg, &dummy_write);

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
    ck_assert_msg(check_msg->flags == 1, "incorrect value for flags, expected 1, is %d", check_msg->flags);
    ck_assert_msg(check_msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", check_msg->h_accuracy);
    ck_assert_msg((check_msg->height*100 - 69.6878045882*100) < 0.05, "incorrect value for height, expected 69.6878045882, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.4290633739*100) < 0.05, "incorrect value for lat, expected 37.4290633739, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.173403896*100) < 0.05, "incorrect value for lon, expected -122.173403896, is %f", check_msg->lon);
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

    sbp_register_callback(&sbp_state, 0x201, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x201, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,1,2,246,215,34,220,46,39,0,51,124,88,251,235,182,66,64,153,5,250,16,25,139,94,192,146,60,187,219,152,161,81,64,0,0,0,0,9,0,194,158, };

    dummy_reset();
    msg_pos_llh_dep_a_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));
    u8 test_msg_len = sizeof(test_msg);
    test_msg.flags = 0;
    test_msg.h_accuracy = 0;
    test_msg.height = 70.5249547317965;
    test_msg.lat = 37.42907659359516;
    test_msg.lon = -122.17340492645452;
    test_msg.n_sats = 9;
    test_msg.tow = 2567900;
    test_msg.v_accuracy = 0;
    sbp_send_message(&sbp_state, 0x201, 55286, test_msg_len, (u8*)&test_msg, &dummy_write);

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
    ck_assert_msg((check_msg->height*100 - 70.5249547318*100) < 0.05, "incorrect value for height, expected 70.5249547318, is %f", check_msg->height);
    ck_assert_msg((check_msg->lat*100 - 37.4290765936*100) < 0.05, "incorrect value for lat, expected 37.4290765936, is %f", check_msg->lat);
    ck_assert_msg((check_msg->lon*100 - -122.173404926*100) < 0.05, "incorrect value for lon, expected -122.173404926, is %f", check_msg->lon);
    ck_assert_msg(check_msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2567900, "incorrect value for tow, expected 2567900, is %d", check_msg->tow);
    ck_assert_msg(check_msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", check_msg->v_accuracy);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_17_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_navigation_17");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_17");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_17);
  suite_add_tcase(s, tc_acq);
  return s;
}