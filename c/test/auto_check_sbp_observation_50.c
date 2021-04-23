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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_observation.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <sbp.h>
#include <observation.h>

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

START_TEST( test_auto_check_sbp_observation_50 )
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

    sbp_register_callback(&sbp_state, 0x45, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x45, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,69,0,195,4,98,56,158,67,24,46,7,32,56,235,249,121,244,114,255,255,33,46,67,218,0,238,203,70,124,22,25,3,0,98,43,184,157,2,176,133,197,125,126,71,253,255,185,39,68,55,3,60,173,162,131,98,231,253,255,139,30,33,16,10,128,178,248,136,42,113,253,255,40,20,42,71,13,246,246,17,135,255,51,3,0,64,27,108,249,22,210,41,114,118,131,48,255,255,31,52,226,58,30,23,217, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_a_t* test_msg = ( msg_obs_dep_a_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 32;
    test_msg->header.t.tow = 407084600;
    test_msg->header.t.wn = 1838;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[0].L.f = 33;
    test_msg->obs[0].L.i = -36108;
    test_msg->obs[0].P = 2046421816;
    test_msg->obs[0].cn0 = 46;
    test_msg->obs[0].lock = 55875;
    test_msg->obs[0].prn = 0;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[1].L.f = 98;
    test_msg->obs[1].L.i = 203030;
    test_msg->obs[1].P = 2085014510;
    test_msg->obs[1].cn0 = 43;
    test_msg->obs[1].lock = 40376;
    test_msg->obs[1].prn = 2;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[2].L.f = 185;
    test_msg->obs[2].L.i = -178306;
    test_msg->obs[2].P = 2110096816;
    test_msg->obs[2].cn0 = 39;
    test_msg->obs[2].lock = 14148;
    test_msg->obs[2].prn = 3;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[3].L.f = 139;
    test_msg->obs[3].L.i = -137374;
    test_msg->obs[3].P = 2208476476;
    test_msg->obs[3].cn0 = 30;
    test_msg->obs[3].lock = 4129;
    test_msg->obs[3].prn = 10;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[4].L.f = 40;
    test_msg->obs[4].L.i = -167638;
    test_msg->obs[4].P = 2298000000;
    test_msg->obs[4].cn0 = 20;
    test_msg->obs[4].lock = 18218;
    test_msg->obs[4].prn = 13;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[5].L.f = 64;
    test_msg->obs[5].L.i = 209919;
    test_msg->obs[5].P = 2266101494;
    test_msg->obs[5].cn0 = 27;
    test_msg->obs[5].lock = 63852;
    test_msg->obs[5].prn = 22;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[6].L.f = 31;
    test_msg->obs[6].L.i = -53117;
    test_msg->obs[6].P = 1987193298;
    test_msg->obs[6].cn0 = 52;
    test_msg->obs[6].lock = 15074;
    test_msg->obs[6].prn = 30;
    sbp_send_message(&sbp_state, 0x45, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x45,
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
    msg_obs_dep_a_t* check_msg = ( msg_obs_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 32, "incorrect value for header.n_obs, expected 32, is %d", check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 407084600, "incorrect value for header.t.tow, expected 407084600, is %d", check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 33, "incorrect value for obs[0].L.f, expected 33, is %d", check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == -36108, "incorrect value for obs[0].L.i, expected -36108, is %d", check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 2046421816, "incorrect value for obs[0].P, expected 2046421816, is %d", check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 46, "incorrect value for obs[0].cn0, expected 46, is %d", check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 55875, "incorrect value for obs[0].lock, expected 55875, is %d", check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].prn == 0, "incorrect value for obs[0].prn, expected 0, is %d", check_msg->obs[0].prn);
    ck_assert_msg(check_msg->obs[1].L.f == 98, "incorrect value for obs[1].L.f, expected 98, is %d", check_msg->obs[1].L.f);
    ck_assert_msg(check_msg->obs[1].L.i == 203030, "incorrect value for obs[1].L.i, expected 203030, is %d", check_msg->obs[1].L.i);
    ck_assert_msg(check_msg->obs[1].P == 2085014510, "incorrect value for obs[1].P, expected 2085014510, is %d", check_msg->obs[1].P);
    ck_assert_msg(check_msg->obs[1].cn0 == 43, "incorrect value for obs[1].cn0, expected 43, is %d", check_msg->obs[1].cn0);
    ck_assert_msg(check_msg->obs[1].lock == 40376, "incorrect value for obs[1].lock, expected 40376, is %d", check_msg->obs[1].lock);
    ck_assert_msg(check_msg->obs[1].prn == 2, "incorrect value for obs[1].prn, expected 2, is %d", check_msg->obs[1].prn);
    ck_assert_msg(check_msg->obs[2].L.f == 185, "incorrect value for obs[2].L.f, expected 185, is %d", check_msg->obs[2].L.f);
    ck_assert_msg(check_msg->obs[2].L.i == -178306, "incorrect value for obs[2].L.i, expected -178306, is %d", check_msg->obs[2].L.i);
    ck_assert_msg(check_msg->obs[2].P == 2110096816, "incorrect value for obs[2].P, expected 2110096816, is %d", check_msg->obs[2].P);
    ck_assert_msg(check_msg->obs[2].cn0 == 39, "incorrect value for obs[2].cn0, expected 39, is %d", check_msg->obs[2].cn0);
    ck_assert_msg(check_msg->obs[2].lock == 14148, "incorrect value for obs[2].lock, expected 14148, is %d", check_msg->obs[2].lock);
    ck_assert_msg(check_msg->obs[2].prn == 3, "incorrect value for obs[2].prn, expected 3, is %d", check_msg->obs[2].prn);
    ck_assert_msg(check_msg->obs[3].L.f == 139, "incorrect value for obs[3].L.f, expected 139, is %d", check_msg->obs[3].L.f);
    ck_assert_msg(check_msg->obs[3].L.i == -137374, "incorrect value for obs[3].L.i, expected -137374, is %d", check_msg->obs[3].L.i);
    ck_assert_msg(check_msg->obs[3].P == 2208476476, "incorrect value for obs[3].P, expected 2208476476, is %d", check_msg->obs[3].P);
    ck_assert_msg(check_msg->obs[3].cn0 == 30, "incorrect value for obs[3].cn0, expected 30, is %d", check_msg->obs[3].cn0);
    ck_assert_msg(check_msg->obs[3].lock == 4129, "incorrect value for obs[3].lock, expected 4129, is %d", check_msg->obs[3].lock);
    ck_assert_msg(check_msg->obs[3].prn == 10, "incorrect value for obs[3].prn, expected 10, is %d", check_msg->obs[3].prn);
    ck_assert_msg(check_msg->obs[4].L.f == 40, "incorrect value for obs[4].L.f, expected 40, is %d", check_msg->obs[4].L.f);
    ck_assert_msg(check_msg->obs[4].L.i == -167638, "incorrect value for obs[4].L.i, expected -167638, is %d", check_msg->obs[4].L.i);
    ck_assert_msg(check_msg->obs[4].P == 2298000000, "incorrect value for obs[4].P, expected 2298000000, is %d", check_msg->obs[4].P);
    ck_assert_msg(check_msg->obs[4].cn0 == 20, "incorrect value for obs[4].cn0, expected 20, is %d", check_msg->obs[4].cn0);
    ck_assert_msg(check_msg->obs[4].lock == 18218, "incorrect value for obs[4].lock, expected 18218, is %d", check_msg->obs[4].lock);
    ck_assert_msg(check_msg->obs[4].prn == 13, "incorrect value for obs[4].prn, expected 13, is %d", check_msg->obs[4].prn);
    ck_assert_msg(check_msg->obs[5].L.f == 64, "incorrect value for obs[5].L.f, expected 64, is %d", check_msg->obs[5].L.f);
    ck_assert_msg(check_msg->obs[5].L.i == 209919, "incorrect value for obs[5].L.i, expected 209919, is %d", check_msg->obs[5].L.i);
    ck_assert_msg(check_msg->obs[5].P == 2266101494, "incorrect value for obs[5].P, expected 2266101494, is %d", check_msg->obs[5].P);
    ck_assert_msg(check_msg->obs[5].cn0 == 27, "incorrect value for obs[5].cn0, expected 27, is %d", check_msg->obs[5].cn0);
    ck_assert_msg(check_msg->obs[5].lock == 63852, "incorrect value for obs[5].lock, expected 63852, is %d", check_msg->obs[5].lock);
    ck_assert_msg(check_msg->obs[5].prn == 22, "incorrect value for obs[5].prn, expected 22, is %d", check_msg->obs[5].prn);
    ck_assert_msg(check_msg->obs[6].L.f == 31, "incorrect value for obs[6].L.f, expected 31, is %d", check_msg->obs[6].L.f);
    ck_assert_msg(check_msg->obs[6].L.i == -53117, "incorrect value for obs[6].L.i, expected -53117, is %d", check_msg->obs[6].L.i);
    ck_assert_msg(check_msg->obs[6].P == 1987193298, "incorrect value for obs[6].P, expected 1987193298, is %d", check_msg->obs[6].P);
    ck_assert_msg(check_msg->obs[6].cn0 == 52, "incorrect value for obs[6].cn0, expected 52, is %d", check_msg->obs[6].cn0);
    ck_assert_msg(check_msg->obs[6].lock == 15074, "incorrect value for obs[6].lock, expected 15074, is %d", check_msg->obs[6].lock);
    ck_assert_msg(check_msg->obs[6].prn == 30, "incorrect value for obs[6].prn, expected 30, is %d", check_msg->obs[6].prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x45, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x45, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,69,0,195,4,20,56,158,67,24,46,7,33,84,52,164,117,102,32,0,0,147,62,62,250,31,234,14, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_a_t* test_msg = ( msg_obs_dep_a_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 33;
    test_msg->header.t.tow = 407084600;
    test_msg->header.t.wn = 1838;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[0].L.f = 147;
    test_msg->obs[0].L.i = 8294;
    test_msg->obs[0].P = 1973695572;
    test_msg->obs[0].cn0 = 62;
    test_msg->obs[0].lock = 64062;
    test_msg->obs[0].prn = 31;
    sbp_send_message(&sbp_state, 0x45, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x45,
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
    msg_obs_dep_a_t* check_msg = ( msg_obs_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 33, "incorrect value for header.n_obs, expected 33, is %d", check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 407084600, "incorrect value for header.t.tow, expected 407084600, is %d", check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 147, "incorrect value for obs[0].L.f, expected 147, is %d", check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == 8294, "incorrect value for obs[0].L.i, expected 8294, is %d", check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 1973695572, "incorrect value for obs[0].P, expected 1973695572, is %d", check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 62, "incorrect value for obs[0].cn0, expected 62, is %d", check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 64062, "incorrect value for obs[0].lock, expected 64062, is %d", check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].prn == 31, "incorrect value for obs[0].prn, expected 31, is %d", check_msg->obs[0].prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x45, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x45, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,69,0,195,4,98,0,159,67,24,46,7,32,32,209,249,121,145,114,255,255,141,45,67,218,0,177,128,70,124,79,27,3,0,159,44,184,157,2,59,135,197,125,175,69,253,255,77,40,68,55,3,211,172,162,131,177,229,253,255,20,31,33,16,10,128,178,248,136,116,111,253,255,94,21,42,71,13,182,173,17,135,37,54,3,0,214,27,108,249,22,91,20,114,118,240,47,255,255,129,52,226,58,30,200,119, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_a_t* test_msg = ( msg_obs_dep_a_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 32;
    test_msg->header.t.tow = 407084800;
    test_msg->header.t.wn = 1838;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[0].L.f = 141;
    test_msg->obs[0].L.i = -36207;
    test_msg->obs[0].P = 2046415136;
    test_msg->obs[0].cn0 = 45;
    test_msg->obs[0].lock = 55875;
    test_msg->obs[0].prn = 0;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[1].L.f = 159;
    test_msg->obs[1].L.i = 203599;
    test_msg->obs[1].P = 2084995249;
    test_msg->obs[1].cn0 = 44;
    test_msg->obs[1].lock = 40376;
    test_msg->obs[1].prn = 2;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[2].L.f = 77;
    test_msg->obs[2].L.i = -178769;
    test_msg->obs[2].P = 2110097211;
    test_msg->obs[2].cn0 = 40;
    test_msg->obs[2].lock = 14148;
    test_msg->obs[2].prn = 3;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[3].L.f = 20;
    test_msg->obs[3].L.i = -137807;
    test_msg->obs[3].P = 2208476371;
    test_msg->obs[3].cn0 = 31;
    test_msg->obs[3].lock = 4129;
    test_msg->obs[3].prn = 10;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[4].L.f = 94;
    test_msg->obs[4].L.i = -168076;
    test_msg->obs[4].P = 2298000000;
    test_msg->obs[4].cn0 = 21;
    test_msg->obs[4].lock = 18218;
    test_msg->obs[4].prn = 13;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[5].L.f = 214;
    test_msg->obs[5].L.i = 210469;
    test_msg->obs[5].P = 2266082742;
    test_msg->obs[5].cn0 = 27;
    test_msg->obs[5].lock = 63852;
    test_msg->obs[5].prn = 22;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[6].L.f = 129;
    test_msg->obs[6].L.i = -53264;
    test_msg->obs[6].P = 1987187803;
    test_msg->obs[6].cn0 = 52;
    test_msg->obs[6].lock = 15074;
    test_msg->obs[6].prn = 30;
    sbp_send_message(&sbp_state, 0x45, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x45,
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
    msg_obs_dep_a_t* check_msg = ( msg_obs_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 32, "incorrect value for header.n_obs, expected 32, is %d", check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 407084800, "incorrect value for header.t.tow, expected 407084800, is %d", check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 141, "incorrect value for obs[0].L.f, expected 141, is %d", check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == -36207, "incorrect value for obs[0].L.i, expected -36207, is %d", check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 2046415136, "incorrect value for obs[0].P, expected 2046415136, is %d", check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 45, "incorrect value for obs[0].cn0, expected 45, is %d", check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 55875, "incorrect value for obs[0].lock, expected 55875, is %d", check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].prn == 0, "incorrect value for obs[0].prn, expected 0, is %d", check_msg->obs[0].prn);
    ck_assert_msg(check_msg->obs[1].L.f == 159, "incorrect value for obs[1].L.f, expected 159, is %d", check_msg->obs[1].L.f);
    ck_assert_msg(check_msg->obs[1].L.i == 203599, "incorrect value for obs[1].L.i, expected 203599, is %d", check_msg->obs[1].L.i);
    ck_assert_msg(check_msg->obs[1].P == 2084995249, "incorrect value for obs[1].P, expected 2084995249, is %d", check_msg->obs[1].P);
    ck_assert_msg(check_msg->obs[1].cn0 == 44, "incorrect value for obs[1].cn0, expected 44, is %d", check_msg->obs[1].cn0);
    ck_assert_msg(check_msg->obs[1].lock == 40376, "incorrect value for obs[1].lock, expected 40376, is %d", check_msg->obs[1].lock);
    ck_assert_msg(check_msg->obs[1].prn == 2, "incorrect value for obs[1].prn, expected 2, is %d", check_msg->obs[1].prn);
    ck_assert_msg(check_msg->obs[2].L.f == 77, "incorrect value for obs[2].L.f, expected 77, is %d", check_msg->obs[2].L.f);
    ck_assert_msg(check_msg->obs[2].L.i == -178769, "incorrect value for obs[2].L.i, expected -178769, is %d", check_msg->obs[2].L.i);
    ck_assert_msg(check_msg->obs[2].P == 2110097211, "incorrect value for obs[2].P, expected 2110097211, is %d", check_msg->obs[2].P);
    ck_assert_msg(check_msg->obs[2].cn0 == 40, "incorrect value for obs[2].cn0, expected 40, is %d", check_msg->obs[2].cn0);
    ck_assert_msg(check_msg->obs[2].lock == 14148, "incorrect value for obs[2].lock, expected 14148, is %d", check_msg->obs[2].lock);
    ck_assert_msg(check_msg->obs[2].prn == 3, "incorrect value for obs[2].prn, expected 3, is %d", check_msg->obs[2].prn);
    ck_assert_msg(check_msg->obs[3].L.f == 20, "incorrect value for obs[3].L.f, expected 20, is %d", check_msg->obs[3].L.f);
    ck_assert_msg(check_msg->obs[3].L.i == -137807, "incorrect value for obs[3].L.i, expected -137807, is %d", check_msg->obs[3].L.i);
    ck_assert_msg(check_msg->obs[3].P == 2208476371, "incorrect value for obs[3].P, expected 2208476371, is %d", check_msg->obs[3].P);
    ck_assert_msg(check_msg->obs[3].cn0 == 31, "incorrect value for obs[3].cn0, expected 31, is %d", check_msg->obs[3].cn0);
    ck_assert_msg(check_msg->obs[3].lock == 4129, "incorrect value for obs[3].lock, expected 4129, is %d", check_msg->obs[3].lock);
    ck_assert_msg(check_msg->obs[3].prn == 10, "incorrect value for obs[3].prn, expected 10, is %d", check_msg->obs[3].prn);
    ck_assert_msg(check_msg->obs[4].L.f == 94, "incorrect value for obs[4].L.f, expected 94, is %d", check_msg->obs[4].L.f);
    ck_assert_msg(check_msg->obs[4].L.i == -168076, "incorrect value for obs[4].L.i, expected -168076, is %d", check_msg->obs[4].L.i);
    ck_assert_msg(check_msg->obs[4].P == 2298000000, "incorrect value for obs[4].P, expected 2298000000, is %d", check_msg->obs[4].P);
    ck_assert_msg(check_msg->obs[4].cn0 == 21, "incorrect value for obs[4].cn0, expected 21, is %d", check_msg->obs[4].cn0);
    ck_assert_msg(check_msg->obs[4].lock == 18218, "incorrect value for obs[4].lock, expected 18218, is %d", check_msg->obs[4].lock);
    ck_assert_msg(check_msg->obs[4].prn == 13, "incorrect value for obs[4].prn, expected 13, is %d", check_msg->obs[4].prn);
    ck_assert_msg(check_msg->obs[5].L.f == 214, "incorrect value for obs[5].L.f, expected 214, is %d", check_msg->obs[5].L.f);
    ck_assert_msg(check_msg->obs[5].L.i == 210469, "incorrect value for obs[5].L.i, expected 210469, is %d", check_msg->obs[5].L.i);
    ck_assert_msg(check_msg->obs[5].P == 2266082742, "incorrect value for obs[5].P, expected 2266082742, is %d", check_msg->obs[5].P);
    ck_assert_msg(check_msg->obs[5].cn0 == 27, "incorrect value for obs[5].cn0, expected 27, is %d", check_msg->obs[5].cn0);
    ck_assert_msg(check_msg->obs[5].lock == 63852, "incorrect value for obs[5].lock, expected 63852, is %d", check_msg->obs[5].lock);
    ck_assert_msg(check_msg->obs[5].prn == 22, "incorrect value for obs[5].prn, expected 22, is %d", check_msg->obs[5].prn);
    ck_assert_msg(check_msg->obs[6].L.f == 129, "incorrect value for obs[6].L.f, expected 129, is %d", check_msg->obs[6].L.f);
    ck_assert_msg(check_msg->obs[6].L.i == -53264, "incorrect value for obs[6].L.i, expected -53264, is %d", check_msg->obs[6].L.i);
    ck_assert_msg(check_msg->obs[6].P == 1987187803, "incorrect value for obs[6].P, expected 1987187803, is %d", check_msg->obs[6].P);
    ck_assert_msg(check_msg->obs[6].cn0 == 52, "incorrect value for obs[6].cn0, expected 52, is %d", check_msg->obs[6].cn0);
    ck_assert_msg(check_msg->obs[6].lock == 15074, "incorrect value for obs[6].lock, expected 15074, is %d", check_msg->obs[6].lock);
    ck_assert_msg(check_msg->obs[6].prn == 30, "incorrect value for obs[6].prn, expected 30, is %d", check_msg->obs[6].prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x45, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x45, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,69,0,195,4,20,0,159,67,24,46,7,33,49,19,164,117,120,32,0,0,222,63,62,250,31,11,231, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_a_t* test_msg = ( msg_obs_dep_a_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 33;
    test_msg->header.t.tow = 407084800;
    test_msg->header.t.wn = 1838;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[0].L.f = 222;
    test_msg->obs[0].L.i = 8312;
    test_msg->obs[0].P = 1973687089;
    test_msg->obs[0].cn0 = 63;
    test_msg->obs[0].lock = 64062;
    test_msg->obs[0].prn = 31;
    sbp_send_message(&sbp_state, 0x45, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x45,
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
    msg_obs_dep_a_t* check_msg = ( msg_obs_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 33, "incorrect value for header.n_obs, expected 33, is %d", check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 407084800, "incorrect value for header.t.tow, expected 407084800, is %d", check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 222, "incorrect value for obs[0].L.f, expected 222, is %d", check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == 8312, "incorrect value for obs[0].L.i, expected 8312, is %d", check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 1973687089, "incorrect value for obs[0].P, expected 1973687089, is %d", check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 63, "incorrect value for obs[0].cn0, expected 63, is %d", check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 64062, "incorrect value for obs[0].lock, expected 64062, is %d", check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].prn == 31, "incorrect value for obs[0].prn, expected 31, is %d", check_msg->obs[0].prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x45, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x45, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,69,0,195,4,72,96,162,68,24,46,7,16,87,132,217,121,121,148,255,255,189,43,175,147,0,132,64,200,125,106,31,254,255,1,41,14,177,3,128,178,248,136,70,68,254,255,166,18,184,133,13,24,127,178,134,6,25,2,0,249,28,33,96,22,170,104,86,118,67,112,255,255,203,56,208,88,30,43,107, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_a_t* test_msg = ( msg_obs_dep_a_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 16;
    test_msg->header.t.tow = 407151200;
    test_msg->header.t.wn = 1838;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[0].L.f = 189;
    test_msg->obs[0].L.i = -27527;
    test_msg->obs[0].P = 2044298327;
    test_msg->obs[0].cn0 = 43;
    test_msg->obs[0].lock = 37807;
    test_msg->obs[0].prn = 0;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[1].L.f = 1;
    test_msg->obs[1].L.i = -123030;
    test_msg->obs[1].P = 2110275716;
    test_msg->obs[1].cn0 = 41;
    test_msg->obs[1].lock = 45326;
    test_msg->obs[1].prn = 3;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[2].L.f = 166;
    test_msg->obs[2].L.i = -113594;
    test_msg->obs[2].P = 2298000000;
    test_msg->obs[2].cn0 = 18;
    test_msg->obs[2].lock = 34232;
    test_msg->obs[2].prn = 13;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[3].L.f = 249;
    test_msg->obs[3].L.i = 137478;
    test_msg->obs[3].P = 2259844888;
    test_msg->obs[3].cn0 = 28;
    test_msg->obs[3].lock = 24609;
    test_msg->obs[3].prn = 22;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[4].L.f = 203;
    test_msg->obs[4].L.i = -36797;
    test_msg->obs[4].P = 1985374378;
    test_msg->obs[4].cn0 = 56;
    test_msg->obs[4].lock = 22736;
    test_msg->obs[4].prn = 30;
    sbp_send_message(&sbp_state, 0x45, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x45,
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
    msg_obs_dep_a_t* check_msg = ( msg_obs_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 16, "incorrect value for header.n_obs, expected 16, is %d", check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 407151200, "incorrect value for header.t.tow, expected 407151200, is %d", check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 189, "incorrect value for obs[0].L.f, expected 189, is %d", check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == -27527, "incorrect value for obs[0].L.i, expected -27527, is %d", check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 2044298327, "incorrect value for obs[0].P, expected 2044298327, is %d", check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 43, "incorrect value for obs[0].cn0, expected 43, is %d", check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 37807, "incorrect value for obs[0].lock, expected 37807, is %d", check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].prn == 0, "incorrect value for obs[0].prn, expected 0, is %d", check_msg->obs[0].prn);
    ck_assert_msg(check_msg->obs[1].L.f == 1, "incorrect value for obs[1].L.f, expected 1, is %d", check_msg->obs[1].L.f);
    ck_assert_msg(check_msg->obs[1].L.i == -123030, "incorrect value for obs[1].L.i, expected -123030, is %d", check_msg->obs[1].L.i);
    ck_assert_msg(check_msg->obs[1].P == 2110275716, "incorrect value for obs[1].P, expected 2110275716, is %d", check_msg->obs[1].P);
    ck_assert_msg(check_msg->obs[1].cn0 == 41, "incorrect value for obs[1].cn0, expected 41, is %d", check_msg->obs[1].cn0);
    ck_assert_msg(check_msg->obs[1].lock == 45326, "incorrect value for obs[1].lock, expected 45326, is %d", check_msg->obs[1].lock);
    ck_assert_msg(check_msg->obs[1].prn == 3, "incorrect value for obs[1].prn, expected 3, is %d", check_msg->obs[1].prn);
    ck_assert_msg(check_msg->obs[2].L.f == 166, "incorrect value for obs[2].L.f, expected 166, is %d", check_msg->obs[2].L.f);
    ck_assert_msg(check_msg->obs[2].L.i == -113594, "incorrect value for obs[2].L.i, expected -113594, is %d", check_msg->obs[2].L.i);
    ck_assert_msg(check_msg->obs[2].P == 2298000000, "incorrect value for obs[2].P, expected 2298000000, is %d", check_msg->obs[2].P);
    ck_assert_msg(check_msg->obs[2].cn0 == 18, "incorrect value for obs[2].cn0, expected 18, is %d", check_msg->obs[2].cn0);
    ck_assert_msg(check_msg->obs[2].lock == 34232, "incorrect value for obs[2].lock, expected 34232, is %d", check_msg->obs[2].lock);
    ck_assert_msg(check_msg->obs[2].prn == 13, "incorrect value for obs[2].prn, expected 13, is %d", check_msg->obs[2].prn);
    ck_assert_msg(check_msg->obs[3].L.f == 249, "incorrect value for obs[3].L.f, expected 249, is %d", check_msg->obs[3].L.f);
    ck_assert_msg(check_msg->obs[3].L.i == 137478, "incorrect value for obs[3].L.i, expected 137478, is %d", check_msg->obs[3].L.i);
    ck_assert_msg(check_msg->obs[3].P == 2259844888, "incorrect value for obs[3].P, expected 2259844888, is %d", check_msg->obs[3].P);
    ck_assert_msg(check_msg->obs[3].cn0 == 28, "incorrect value for obs[3].cn0, expected 28, is %d", check_msg->obs[3].cn0);
    ck_assert_msg(check_msg->obs[3].lock == 24609, "incorrect value for obs[3].lock, expected 24609, is %d", check_msg->obs[3].lock);
    ck_assert_msg(check_msg->obs[3].prn == 22, "incorrect value for obs[3].prn, expected 22, is %d", check_msg->obs[3].prn);
    ck_assert_msg(check_msg->obs[4].L.f == 203, "incorrect value for obs[4].L.f, expected 203, is %d", check_msg->obs[4].L.f);
    ck_assert_msg(check_msg->obs[4].L.i == -36797, "incorrect value for obs[4].L.i, expected -36797, is %d", check_msg->obs[4].L.i);
    ck_assert_msg(check_msg->obs[4].P == 1985374378, "incorrect value for obs[4].P, expected 1985374378, is %d", check_msg->obs[4].P);
    ck_assert_msg(check_msg->obs[4].cn0 == 56, "incorrect value for obs[4].cn0, expected 56, is %d", check_msg->obs[4].cn0);
    ck_assert_msg(check_msg->obs[4].lock == 22736, "incorrect value for obs[4].lock, expected 22736, is %d", check_msg->obs[4].lock);
    ck_assert_msg(check_msg->obs[4].prn == 30, "incorrect value for obs[4].prn, expected 30, is %d", check_msg->obs[4].prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x45, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x45, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,69,0,195,4,72,40,163,68,24,46,7,16,132,107,217,121,14,148,255,255,1,44,175,147,0,129,66,200,125,148,29,254,255,153,41,14,177,3,128,178,248,136,143,66,254,255,222,18,184,133,13,158,53,178,134,42,27,2,0,237,30,33,96,22,38,83,86,118,168,111,255,255,45,56,208,88,30,1,175, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_a_t* test_msg = ( msg_obs_dep_a_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 16;
    test_msg->header.t.tow = 407151400;
    test_msg->header.t.wn = 1838;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[0].L.f = 1;
    test_msg->obs[0].L.i = -27634;
    test_msg->obs[0].P = 2044291972;
    test_msg->obs[0].cn0 = 44;
    test_msg->obs[0].lock = 37807;
    test_msg->obs[0].prn = 0;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[1].L.f = 153;
    test_msg->obs[1].L.i = -123500;
    test_msg->obs[1].P = 2110276225;
    test_msg->obs[1].cn0 = 41;
    test_msg->obs[1].lock = 45326;
    test_msg->obs[1].prn = 3;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[2].L.f = 222;
    test_msg->obs[2].L.i = -114033;
    test_msg->obs[2].P = 2298000000;
    test_msg->obs[2].cn0 = 18;
    test_msg->obs[2].lock = 34232;
    test_msg->obs[2].prn = 13;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[3].L.f = 237;
    test_msg->obs[3].L.i = 138026;
    test_msg->obs[3].P = 2259826078;
    test_msg->obs[3].cn0 = 30;
    test_msg->obs[3].lock = 24609;
    test_msg->obs[3].prn = 22;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    
    test_msg->obs[4].L.f = 45;
    test_msg->obs[4].L.i = -36952;
    test_msg->obs[4].P = 1985368870;
    test_msg->obs[4].cn0 = 56;
    test_msg->obs[4].lock = 22736;
    test_msg->obs[4].prn = 30;
    sbp_send_message(&sbp_state, 0x45, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x45,
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
    msg_obs_dep_a_t* check_msg = ( msg_obs_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 16, "incorrect value for header.n_obs, expected 16, is %d", check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 407151400, "incorrect value for header.t.tow, expected 407151400, is %d", check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 1, "incorrect value for obs[0].L.f, expected 1, is %d", check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == -27634, "incorrect value for obs[0].L.i, expected -27634, is %d", check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 2044291972, "incorrect value for obs[0].P, expected 2044291972, is %d", check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 44, "incorrect value for obs[0].cn0, expected 44, is %d", check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 37807, "incorrect value for obs[0].lock, expected 37807, is %d", check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].prn == 0, "incorrect value for obs[0].prn, expected 0, is %d", check_msg->obs[0].prn);
    ck_assert_msg(check_msg->obs[1].L.f == 153, "incorrect value for obs[1].L.f, expected 153, is %d", check_msg->obs[1].L.f);
    ck_assert_msg(check_msg->obs[1].L.i == -123500, "incorrect value for obs[1].L.i, expected -123500, is %d", check_msg->obs[1].L.i);
    ck_assert_msg(check_msg->obs[1].P == 2110276225, "incorrect value for obs[1].P, expected 2110276225, is %d", check_msg->obs[1].P);
    ck_assert_msg(check_msg->obs[1].cn0 == 41, "incorrect value for obs[1].cn0, expected 41, is %d", check_msg->obs[1].cn0);
    ck_assert_msg(check_msg->obs[1].lock == 45326, "incorrect value for obs[1].lock, expected 45326, is %d", check_msg->obs[1].lock);
    ck_assert_msg(check_msg->obs[1].prn == 3, "incorrect value for obs[1].prn, expected 3, is %d", check_msg->obs[1].prn);
    ck_assert_msg(check_msg->obs[2].L.f == 222, "incorrect value for obs[2].L.f, expected 222, is %d", check_msg->obs[2].L.f);
    ck_assert_msg(check_msg->obs[2].L.i == -114033, "incorrect value for obs[2].L.i, expected -114033, is %d", check_msg->obs[2].L.i);
    ck_assert_msg(check_msg->obs[2].P == 2298000000, "incorrect value for obs[2].P, expected 2298000000, is %d", check_msg->obs[2].P);
    ck_assert_msg(check_msg->obs[2].cn0 == 18, "incorrect value for obs[2].cn0, expected 18, is %d", check_msg->obs[2].cn0);
    ck_assert_msg(check_msg->obs[2].lock == 34232, "incorrect value for obs[2].lock, expected 34232, is %d", check_msg->obs[2].lock);
    ck_assert_msg(check_msg->obs[2].prn == 13, "incorrect value for obs[2].prn, expected 13, is %d", check_msg->obs[2].prn);
    ck_assert_msg(check_msg->obs[3].L.f == 237, "incorrect value for obs[3].L.f, expected 237, is %d", check_msg->obs[3].L.f);
    ck_assert_msg(check_msg->obs[3].L.i == 138026, "incorrect value for obs[3].L.i, expected 138026, is %d", check_msg->obs[3].L.i);
    ck_assert_msg(check_msg->obs[3].P == 2259826078, "incorrect value for obs[3].P, expected 2259826078, is %d", check_msg->obs[3].P);
    ck_assert_msg(check_msg->obs[3].cn0 == 30, "incorrect value for obs[3].cn0, expected 30, is %d", check_msg->obs[3].cn0);
    ck_assert_msg(check_msg->obs[3].lock == 24609, "incorrect value for obs[3].lock, expected 24609, is %d", check_msg->obs[3].lock);
    ck_assert_msg(check_msg->obs[3].prn == 22, "incorrect value for obs[3].prn, expected 22, is %d", check_msg->obs[3].prn);
    ck_assert_msg(check_msg->obs[4].L.f == 45, "incorrect value for obs[4].L.f, expected 45, is %d", check_msg->obs[4].L.f);
    ck_assert_msg(check_msg->obs[4].L.i == -36952, "incorrect value for obs[4].L.i, expected -36952, is %d", check_msg->obs[4].L.i);
    ck_assert_msg(check_msg->obs[4].P == 1985368870, "incorrect value for obs[4].P, expected 1985368870, is %d", check_msg->obs[4].P);
    ck_assert_msg(check_msg->obs[4].cn0 == 56, "incorrect value for obs[4].cn0, expected 56, is %d", check_msg->obs[4].cn0);
    ck_assert_msg(check_msg->obs[4].lock == 22736, "incorrect value for obs[4].lock, expected 22736, is %d", check_msg->obs[4].lock);
    ck_assert_msg(check_msg->obs[4].prn == 30, "incorrect value for obs[4].prn, expected 30, is %d", check_msg->obs[4].prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x46, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,70,0,195,4,176,0,0,0,0,0,0,60,190,0,0,0,0,0,186,82,192,0,0,0,0,0,76,109,64,0,0,0,0,0,132,208,190,0,0,0,0,0,254,220,62,0,0,0,0,0,0,113,62,0,0,0,0,0,0,133,190,28,36,25,81,223,254,52,62,220,116,216,39,33,189,3,64,0,0,0,156,177,204,134,63,0,0,160,220,182,33,180,64,152,225,192,44,254,76,238,191,41,150,24,2,148,156,65,190,252,90,119,48,15,215,240,63,124,127,115,94,208,16,238,63,165,115,52,74,97,167,246,189,0,0,0,0,192,180,229,190,0,0,0,0,0,0,112,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,3,0,225,156, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ephemeris_dep_b_t* test_msg = ( msg_ephemeris_dep_b_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->af0 = -1.035025343298912e-05;
    test_msg->af1 = -9.094947017729282e-13;
    test_msg->af2 = 0.0;
    test_msg->c_ic = 6.332993507385254e-08;
    test_msg->c_is = -1.564621925354004e-07;
    test_msg->c_rc = 234.375;
    test_msg->c_rs = -74.90625;
    test_msg->c_uc = -3.937631845474243e-06;
    test_msg->c_us = 6.9122761487960815e-06;
    test_msg->dn = 4.8884179079418005e-09;
    test_msg->ecc = 0.011132609914056957;
    test_msg->healthy = 1;
    test_msg->inc = 0.9395524830579087;
    test_msg->inc_dot = -3.296565886629854e-10;
    test_msg->iode = 0;
    test_msg->m0 = 2.467348395627239;
    test_msg->omega0 = -0.9468985437479658;
    test_msg->omegadot = -8.201055892610478e-09;
    test_msg->prn = 3;
    test_msg->sqrta = 5153.714303970337;
    test_msg->tgd = -6.51925802230835e-09;
    test_msg->toc_tow = 410400.0;
    test_msg->toc_wn = 1838;
    test_msg->toe_tow = 410400.0;
    test_msg->toe_wn = 1838;
    test_msg->valid = 1;
    test_msg->w = 1.0525047200405302;
    sbp_send_message(&sbp_state, 0x46, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x46,
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
    msg_ephemeris_dep_b_t* check_msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((check_msg->af0*100 - -1.0350253433e-05*100) < 0.05, "incorrect value for af0, expected -1.0350253433e-05, is %f", check_msg->af0);
    ck_assert_msg((check_msg->af1*100 - -9.09494701773e-13*100) < 0.05, "incorrect value for af1, expected -9.09494701773e-13, is %f", check_msg->af1);
    ck_assert_msg((check_msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", check_msg->af2);
    ck_assert_msg((check_msg->c_ic*100 - 6.33299350739e-08*100) < 0.05, "incorrect value for c_ic, expected 6.33299350739e-08, is %f", check_msg->c_ic);
    ck_assert_msg((check_msg->c_is*100 - -1.56462192535e-07*100) < 0.05, "incorrect value for c_is, expected -1.56462192535e-07, is %f", check_msg->c_is);
    ck_assert_msg((check_msg->c_rc*100 - 234.375*100) < 0.05, "incorrect value for c_rc, expected 234.375, is %f", check_msg->c_rc);
    ck_assert_msg((check_msg->c_rs*100 - -74.90625*100) < 0.05, "incorrect value for c_rs, expected -74.90625, is %f", check_msg->c_rs);
    ck_assert_msg((check_msg->c_uc*100 - -3.93763184547e-06*100) < 0.05, "incorrect value for c_uc, expected -3.93763184547e-06, is %f", check_msg->c_uc);
    ck_assert_msg((check_msg->c_us*100 - 6.9122761488e-06*100) < 0.05, "incorrect value for c_us, expected 6.9122761488e-06, is %f", check_msg->c_us);
    ck_assert_msg((check_msg->dn*100 - 4.88841790794e-09*100) < 0.05, "incorrect value for dn, expected 4.88841790794e-09, is %f", check_msg->dn);
    ck_assert_msg((check_msg->ecc*100 - 0.0111326099141*100) < 0.05, "incorrect value for ecc, expected 0.0111326099141, is %f", check_msg->ecc);
    ck_assert_msg(check_msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", check_msg->healthy);
    ck_assert_msg((check_msg->inc*100 - 0.939552483058*100) < 0.05, "incorrect value for inc, expected 0.939552483058, is %f", check_msg->inc);
    ck_assert_msg((check_msg->inc_dot*100 - -3.29656588663e-10*100) < 0.05, "incorrect value for inc_dot, expected -3.29656588663e-10, is %f", check_msg->inc_dot);
    ck_assert_msg(check_msg->iode == 0, "incorrect value for iode, expected 0, is %d", check_msg->iode);
    ck_assert_msg((check_msg->m0*100 - 2.46734839563*100) < 0.05, "incorrect value for m0, expected 2.46734839563, is %f", check_msg->m0);
    ck_assert_msg((check_msg->omega0*100 - -0.946898543748*100) < 0.05, "incorrect value for omega0, expected -0.946898543748, is %f", check_msg->omega0);
    ck_assert_msg((check_msg->omegadot*100 - -8.20105589261e-09*100) < 0.05, "incorrect value for omegadot, expected -8.20105589261e-09, is %f", check_msg->omegadot);
    ck_assert_msg(check_msg->prn == 3, "incorrect value for prn, expected 3, is %d", check_msg->prn);
    ck_assert_msg((check_msg->sqrta*100 - 5153.71430397*100) < 0.05, "incorrect value for sqrta, expected 5153.71430397, is %f", check_msg->sqrta);
    ck_assert_msg((check_msg->tgd*100 - -6.51925802231e-09*100) < 0.05, "incorrect value for tgd, expected -6.51925802231e-09, is %f", check_msg->tgd);
    ck_assert_msg((check_msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", check_msg->toc_tow);
    ck_assert_msg(check_msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", check_msg->toc_wn);
    ck_assert_msg((check_msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", check_msg->toe_tow);
    ck_assert_msg(check_msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", check_msg->toe_wn);
    ck_assert_msg(check_msg->valid == 1, "incorrect value for valid, expected 1, is %d", check_msg->valid);
    ck_assert_msg((check_msg->w*100 - 1.05250472004*100) < 0.05, "incorrect value for w, expected 1.05250472004, is %f", check_msg->w);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x46, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,70,0,195,4,176,0,0,0,0,0,0,68,190,0,0,0,0,0,72,66,64,0,0,0,0,128,188,115,64,0,0,0,0,0,80,193,62,0,0,0,0,0,164,204,62,0,0,0,0,0,0,130,62,0,0,0,0,0,0,128,62,72,181,127,6,208,225,52,62,158,174,129,91,27,105,249,191,0,0,0,96,204,57,128,63,0,0,160,35,146,33,180,64,247,169,1,36,133,206,243,63,79,11,109,92,156,208,65,190,103,78,3,253,223,147,255,191,164,214,90,250,218,240,238,63,94,239,187,37,36,10,242,61,0,0,0,0,176,91,19,63,0,0,0,0,0,0,137,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,13,0,180,21, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ephemeris_dep_b_t* test_msg = ( msg_ephemeris_dep_b_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->af0 = 7.384549826383591e-05;
    test_msg->af1 = -2.8421709430404007e-12;
    test_msg->af2 = 0.0;
    test_msg->c_ic = 1.341104507446289e-07;
    test_msg->c_is = 1.1920928955078125e-07;
    test_msg->c_rc = 315.78125;
    test_msg->c_rs = 36.5625;
    test_msg->c_uc = 2.0638108253479004e-06;
    test_msg->c_us = 3.4142285585403442e-06;
    test_msg->dn = 4.86198823561129e-09;
    test_msg->ecc = 0.007922741584479809;
    test_msg->healthy = 1;
    test_msg->inc = 0.9669012918227122;
    test_msg->inc_dot = 2.6251093463412166e-10;
    test_msg->iode = 0;
    test_msg->m0 = -1.588160855720083;
    test_msg->omega0 = 1.237919941568746;
    test_msg->omegadot = -8.295702692172441e-09;
    test_msg->prn = 13;
    test_msg->sqrta = 5153.57085609436;
    test_msg->tgd = -9.313225746154785e-09;
    test_msg->toc_tow = 410400.0;
    test_msg->toc_wn = 1838;
    test_msg->toe_tow = 410400.0;
    test_msg->toe_wn = 1838;
    test_msg->valid = 1;
    test_msg->w = -1.9736022837941165;
    sbp_send_message(&sbp_state, 0x46, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x46,
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
    msg_ephemeris_dep_b_t* check_msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((check_msg->af0*100 - 7.38454982638e-05*100) < 0.05, "incorrect value for af0, expected 7.38454982638e-05, is %f", check_msg->af0);
    ck_assert_msg((check_msg->af1*100 - -2.84217094304e-12*100) < 0.05, "incorrect value for af1, expected -2.84217094304e-12, is %f", check_msg->af1);
    ck_assert_msg((check_msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", check_msg->af2);
    ck_assert_msg((check_msg->c_ic*100 - 1.34110450745e-07*100) < 0.05, "incorrect value for c_ic, expected 1.34110450745e-07, is %f", check_msg->c_ic);
    ck_assert_msg((check_msg->c_is*100 - 1.19209289551e-07*100) < 0.05, "incorrect value for c_is, expected 1.19209289551e-07, is %f", check_msg->c_is);
    ck_assert_msg((check_msg->c_rc*100 - 315.78125*100) < 0.05, "incorrect value for c_rc, expected 315.78125, is %f", check_msg->c_rc);
    ck_assert_msg((check_msg->c_rs*100 - 36.5625*100) < 0.05, "incorrect value for c_rs, expected 36.5625, is %f", check_msg->c_rs);
    ck_assert_msg((check_msg->c_uc*100 - 2.06381082535e-06*100) < 0.05, "incorrect value for c_uc, expected 2.06381082535e-06, is %f", check_msg->c_uc);
    ck_assert_msg((check_msg->c_us*100 - 3.41422855854e-06*100) < 0.05, "incorrect value for c_us, expected 3.41422855854e-06, is %f", check_msg->c_us);
    ck_assert_msg((check_msg->dn*100 - 4.86198823561e-09*100) < 0.05, "incorrect value for dn, expected 4.86198823561e-09, is %f", check_msg->dn);
    ck_assert_msg((check_msg->ecc*100 - 0.00792274158448*100) < 0.05, "incorrect value for ecc, expected 0.00792274158448, is %f", check_msg->ecc);
    ck_assert_msg(check_msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", check_msg->healthy);
    ck_assert_msg((check_msg->inc*100 - 0.966901291823*100) < 0.05, "incorrect value for inc, expected 0.966901291823, is %f", check_msg->inc);
    ck_assert_msg((check_msg->inc_dot*100 - 2.62510934634e-10*100) < 0.05, "incorrect value for inc_dot, expected 2.62510934634e-10, is %f", check_msg->inc_dot);
    ck_assert_msg(check_msg->iode == 0, "incorrect value for iode, expected 0, is %d", check_msg->iode);
    ck_assert_msg((check_msg->m0*100 - -1.58816085572*100) < 0.05, "incorrect value for m0, expected -1.58816085572, is %f", check_msg->m0);
    ck_assert_msg((check_msg->omega0*100 - 1.23791994157*100) < 0.05, "incorrect value for omega0, expected 1.23791994157, is %f", check_msg->omega0);
    ck_assert_msg((check_msg->omegadot*100 - -8.29570269217e-09*100) < 0.05, "incorrect value for omegadot, expected -8.29570269217e-09, is %f", check_msg->omegadot);
    ck_assert_msg(check_msg->prn == 13, "incorrect value for prn, expected 13, is %d", check_msg->prn);
    ck_assert_msg((check_msg->sqrta*100 - 5153.57085609*100) < 0.05, "incorrect value for sqrta, expected 5153.57085609, is %f", check_msg->sqrta);
    ck_assert_msg((check_msg->tgd*100 - -9.31322574615e-09*100) < 0.05, "incorrect value for tgd, expected -9.31322574615e-09, is %f", check_msg->tgd);
    ck_assert_msg((check_msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", check_msg->toc_tow);
    ck_assert_msg(check_msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", check_msg->toc_wn);
    ck_assert_msg((check_msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", check_msg->toe_tow);
    ck_assert_msg(check_msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", check_msg->toe_wn);
    ck_assert_msg(check_msg->valid == 1, "incorrect value for valid, expected 1, is %d", check_msg->valid);
    ck_assert_msg((check_msg->w*100 - -1.97360228379*100) < 0.05, "incorrect value for w, expected -1.97360228379, is %f", check_msg->w);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x46, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,70,0,195,4,176,0,0,0,0,0,0,56,62,0,0,0,0,0,40,81,192,0,0,0,0,0,129,109,64,0,0,0,0,0,28,205,190,0,0,0,0,0,76,223,62,0,0,0,0,0,0,105,190,0,0,0,0,0,0,92,190,134,161,223,255,243,43,51,62,146,176,113,142,234,164,5,64,0,0,0,56,175,140,112,63,0,0,192,90,171,33,180,64,36,38,237,255,200,160,237,191,204,92,63,154,49,91,65,190,125,94,251,132,52,61,216,63,2,139,28,27,231,199,238,63,124,183,4,180,194,30,247,189,0,0,0,0,0,104,222,190,0,0,0,0,0,0,96,61,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,0,0,222,152, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ephemeris_dep_b_t* test_msg = ( msg_ephemeris_dep_b_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->af0 = -7.249414920806885e-06;
    test_msg->af1 = 4.547473508864641e-13;
    test_msg->af2 = 0.0;
    test_msg->c_ic = -4.6566128730773926e-08;
    test_msg->c_is = -2.60770320892334e-08;
    test_msg->c_rc = 236.03125;
    test_msg->c_rs = -68.625;
    test_msg->c_uc = -3.470107913017273e-06;
    test_msg->c_us = 7.461756467819214e-06;
    test_msg->dn = 4.4637573619826565e-09;
    test_msg->ecc = 0.004040417145006359;
    test_msg->healthy = 1;
    test_msg->inc = 0.9619021920701416;
    test_msg->inc_dot = -3.3644258561271105e-10;
    test_msg->iode = 0;
    test_msg->m0 = 2.7055255058713295;
    test_msg->omega0 = -0.9258770941316397;
    test_msg->omegadot = -8.082122367123182e-09;
    test_msg->prn = 0;
    test_msg->sqrta = 5153.669353485107;
    test_msg->tgd = 5.587935447692871e-09;
    test_msg->toc_tow = 410400.0;
    test_msg->toc_wn = 1838;
    test_msg->toe_tow = 410400.0;
    test_msg->toe_wn = 1838;
    test_msg->valid = 1;
    test_msg->w = 0.37873566614641857;
    sbp_send_message(&sbp_state, 0x46, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x46,
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
    msg_ephemeris_dep_b_t* check_msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((check_msg->af0*100 - -7.24941492081e-06*100) < 0.05, "incorrect value for af0, expected -7.24941492081e-06, is %f", check_msg->af0);
    ck_assert_msg((check_msg->af1*100 - 4.54747350886e-13*100) < 0.05, "incorrect value for af1, expected 4.54747350886e-13, is %f", check_msg->af1);
    ck_assert_msg((check_msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", check_msg->af2);
    ck_assert_msg((check_msg->c_ic*100 - -4.65661287308e-08*100) < 0.05, "incorrect value for c_ic, expected -4.65661287308e-08, is %f", check_msg->c_ic);
    ck_assert_msg((check_msg->c_is*100 - -2.60770320892e-08*100) < 0.05, "incorrect value for c_is, expected -2.60770320892e-08, is %f", check_msg->c_is);
    ck_assert_msg((check_msg->c_rc*100 - 236.03125*100) < 0.05, "incorrect value for c_rc, expected 236.03125, is %f", check_msg->c_rc);
    ck_assert_msg((check_msg->c_rs*100 - -68.625*100) < 0.05, "incorrect value for c_rs, expected -68.625, is %f", check_msg->c_rs);
    ck_assert_msg((check_msg->c_uc*100 - -3.47010791302e-06*100) < 0.05, "incorrect value for c_uc, expected -3.47010791302e-06, is %f", check_msg->c_uc);
    ck_assert_msg((check_msg->c_us*100 - 7.46175646782e-06*100) < 0.05, "incorrect value for c_us, expected 7.46175646782e-06, is %f", check_msg->c_us);
    ck_assert_msg((check_msg->dn*100 - 4.46375736198e-09*100) < 0.05, "incorrect value for dn, expected 4.46375736198e-09, is %f", check_msg->dn);
    ck_assert_msg((check_msg->ecc*100 - 0.00404041714501*100) < 0.05, "incorrect value for ecc, expected 0.00404041714501, is %f", check_msg->ecc);
    ck_assert_msg(check_msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", check_msg->healthy);
    ck_assert_msg((check_msg->inc*100 - 0.96190219207*100) < 0.05, "incorrect value for inc, expected 0.96190219207, is %f", check_msg->inc);
    ck_assert_msg((check_msg->inc_dot*100 - -3.36442585613e-10*100) < 0.05, "incorrect value for inc_dot, expected -3.36442585613e-10, is %f", check_msg->inc_dot);
    ck_assert_msg(check_msg->iode == 0, "incorrect value for iode, expected 0, is %d", check_msg->iode);
    ck_assert_msg((check_msg->m0*100 - 2.70552550587*100) < 0.05, "incorrect value for m0, expected 2.70552550587, is %f", check_msg->m0);
    ck_assert_msg((check_msg->omega0*100 - -0.925877094132*100) < 0.05, "incorrect value for omega0, expected -0.925877094132, is %f", check_msg->omega0);
    ck_assert_msg((check_msg->omegadot*100 - -8.08212236712e-09*100) < 0.05, "incorrect value for omegadot, expected -8.08212236712e-09, is %f", check_msg->omegadot);
    ck_assert_msg(check_msg->prn == 0, "incorrect value for prn, expected 0, is %d", check_msg->prn);
    ck_assert_msg((check_msg->sqrta*100 - 5153.66935349*100) < 0.05, "incorrect value for sqrta, expected 5153.66935349, is %f", check_msg->sqrta);
    ck_assert_msg((check_msg->tgd*100 - 5.58793544769e-09*100) < 0.05, "incorrect value for tgd, expected 5.58793544769e-09, is %f", check_msg->tgd);
    ck_assert_msg((check_msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", check_msg->toc_tow);
    ck_assert_msg(check_msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", check_msg->toc_wn);
    ck_assert_msg((check_msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", check_msg->toe_tow);
    ck_assert_msg(check_msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", check_msg->toe_wn);
    ck_assert_msg(check_msg->valid == 1, "incorrect value for valid, expected 1, is %d", check_msg->valid);
    ck_assert_msg((check_msg->w*100 - 0.378735666146*100) < 0.05, "incorrect value for w, expected 0.378735666146, is %f", check_msg->w);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x46, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,70,0,195,4,176,0,0,0,0,0,0,68,190,0,0,0,0,0,72,66,64,0,0,0,0,128,188,115,64,0,0,0,0,0,80,193,62,0,0,0,0,0,164,204,62,0,0,0,0,0,0,130,62,0,0,0,0,0,0,128,62,72,181,127,6,208,225,52,62,158,174,129,91,27,105,249,191,0,0,0,96,204,57,128,63,0,0,160,35,146,33,180,64,247,169,1,36,133,206,243,63,79,11,109,92,156,208,65,190,103,78,3,253,223,147,255,191,164,214,90,250,218,240,238,63,94,239,187,37,36,10,242,61,0,0,0,0,176,91,19,63,0,0,0,0,0,0,137,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,13,0,180,21, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ephemeris_dep_b_t* test_msg = ( msg_ephemeris_dep_b_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->af0 = 7.384549826383591e-05;
    test_msg->af1 = -2.8421709430404007e-12;
    test_msg->af2 = 0.0;
    test_msg->c_ic = 1.341104507446289e-07;
    test_msg->c_is = 1.1920928955078125e-07;
    test_msg->c_rc = 315.78125;
    test_msg->c_rs = 36.5625;
    test_msg->c_uc = 2.0638108253479004e-06;
    test_msg->c_us = 3.4142285585403442e-06;
    test_msg->dn = 4.86198823561129e-09;
    test_msg->ecc = 0.007922741584479809;
    test_msg->healthy = 1;
    test_msg->inc = 0.9669012918227122;
    test_msg->inc_dot = 2.6251093463412166e-10;
    test_msg->iode = 0;
    test_msg->m0 = -1.588160855720083;
    test_msg->omega0 = 1.237919941568746;
    test_msg->omegadot = -8.295702692172441e-09;
    test_msg->prn = 13;
    test_msg->sqrta = 5153.57085609436;
    test_msg->tgd = -9.313225746154785e-09;
    test_msg->toc_tow = 410400.0;
    test_msg->toc_wn = 1838;
    test_msg->toe_tow = 410400.0;
    test_msg->toe_wn = 1838;
    test_msg->valid = 1;
    test_msg->w = -1.9736022837941165;
    sbp_send_message(&sbp_state, 0x46, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x46,
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
    msg_ephemeris_dep_b_t* check_msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((check_msg->af0*100 - 7.38454982638e-05*100) < 0.05, "incorrect value for af0, expected 7.38454982638e-05, is %f", check_msg->af0);
    ck_assert_msg((check_msg->af1*100 - -2.84217094304e-12*100) < 0.05, "incorrect value for af1, expected -2.84217094304e-12, is %f", check_msg->af1);
    ck_assert_msg((check_msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", check_msg->af2);
    ck_assert_msg((check_msg->c_ic*100 - 1.34110450745e-07*100) < 0.05, "incorrect value for c_ic, expected 1.34110450745e-07, is %f", check_msg->c_ic);
    ck_assert_msg((check_msg->c_is*100 - 1.19209289551e-07*100) < 0.05, "incorrect value for c_is, expected 1.19209289551e-07, is %f", check_msg->c_is);
    ck_assert_msg((check_msg->c_rc*100 - 315.78125*100) < 0.05, "incorrect value for c_rc, expected 315.78125, is %f", check_msg->c_rc);
    ck_assert_msg((check_msg->c_rs*100 - 36.5625*100) < 0.05, "incorrect value for c_rs, expected 36.5625, is %f", check_msg->c_rs);
    ck_assert_msg((check_msg->c_uc*100 - 2.06381082535e-06*100) < 0.05, "incorrect value for c_uc, expected 2.06381082535e-06, is %f", check_msg->c_uc);
    ck_assert_msg((check_msg->c_us*100 - 3.41422855854e-06*100) < 0.05, "incorrect value for c_us, expected 3.41422855854e-06, is %f", check_msg->c_us);
    ck_assert_msg((check_msg->dn*100 - 4.86198823561e-09*100) < 0.05, "incorrect value for dn, expected 4.86198823561e-09, is %f", check_msg->dn);
    ck_assert_msg((check_msg->ecc*100 - 0.00792274158448*100) < 0.05, "incorrect value for ecc, expected 0.00792274158448, is %f", check_msg->ecc);
    ck_assert_msg(check_msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", check_msg->healthy);
    ck_assert_msg((check_msg->inc*100 - 0.966901291823*100) < 0.05, "incorrect value for inc, expected 0.966901291823, is %f", check_msg->inc);
    ck_assert_msg((check_msg->inc_dot*100 - 2.62510934634e-10*100) < 0.05, "incorrect value for inc_dot, expected 2.62510934634e-10, is %f", check_msg->inc_dot);
    ck_assert_msg(check_msg->iode == 0, "incorrect value for iode, expected 0, is %d", check_msg->iode);
    ck_assert_msg((check_msg->m0*100 - -1.58816085572*100) < 0.05, "incorrect value for m0, expected -1.58816085572, is %f", check_msg->m0);
    ck_assert_msg((check_msg->omega0*100 - 1.23791994157*100) < 0.05, "incorrect value for omega0, expected 1.23791994157, is %f", check_msg->omega0);
    ck_assert_msg((check_msg->omegadot*100 - -8.29570269217e-09*100) < 0.05, "incorrect value for omegadot, expected -8.29570269217e-09, is %f", check_msg->omegadot);
    ck_assert_msg(check_msg->prn == 13, "incorrect value for prn, expected 13, is %d", check_msg->prn);
    ck_assert_msg((check_msg->sqrta*100 - 5153.57085609*100) < 0.05, "incorrect value for sqrta, expected 5153.57085609, is %f", check_msg->sqrta);
    ck_assert_msg((check_msg->tgd*100 - -9.31322574615e-09*100) < 0.05, "incorrect value for tgd, expected -9.31322574615e-09, is %f", check_msg->tgd);
    ck_assert_msg((check_msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", check_msg->toc_tow);
    ck_assert_msg(check_msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", check_msg->toc_wn);
    ck_assert_msg((check_msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", check_msg->toe_tow);
    ck_assert_msg(check_msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", check_msg->toe_wn);
    ck_assert_msg(check_msg->valid == 1, "incorrect value for valid, expected 1, is %d", check_msg->valid);
    ck_assert_msg((check_msg->w*100 - -1.97360228379*100) < 0.05, "incorrect value for w, expected -1.97360228379, is %f", check_msg->w);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x46, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,70,0,195,4,176,0,0,0,0,0,128,85,190,0,0,0,0,0,156,69,64,0,0,0,0,128,19,115,64,0,0,0,0,0,160,193,62,0,0,0,0,0,152,207,62,0,0,0,0,0,0,97,190,0,0,0,0,0,192,139,190,26,26,13,149,16,152,54,62,104,7,46,214,75,84,5,192,0,0,0,128,230,82,132,63,0,0,160,252,162,33,180,64,73,6,130,54,217,171,242,63,81,224,163,123,238,42,66,190,206,43,141,67,243,157,5,192,113,179,153,187,43,92,238,63,254,236,31,43,224,157,244,61,0,0,0,0,232,4,26,191,0,0,0,0,0,0,134,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,22,0,99,61, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ephemeris_dep_b_t* test_msg = ( msg_ephemeris_dep_b_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->af0 = -9.925523772835732e-05;
    test_msg->af1 = -2.5011104298755527e-12;
    test_msg->af2 = 0.0;
    test_msg->c_ic = -3.166496753692627e-08;
    test_msg->c_is = -2.0675361156463623e-07;
    test_msg->c_rc = 305.21875;
    test_msg->c_rs = 43.21875;
    test_msg->c_uc = 2.1010637283325195e-06;
    test_msg->c_us = 3.766268491744995e-06;
    test_msg->dn = 5.26057626697412e-09;
    test_msg->ecc = 0.009923744946718216;
    test_msg->healthy = 1;
    test_msg->inc = 0.9487513221807672;
    test_msg->inc_dot = 3.000124967247105e-10;
    test_msg->iode = 0;
    test_msg->m0 = -2.666160271911327;
    test_msg->omega0 = 1.1669551972594425;
    test_msg->omegadot = -8.45999524990264e-09;
    test_msg->prn = 22;
    test_msg->sqrta = 5153.636667251587;
    test_msg->tgd = -2.0023435354232788e-08;
    test_msg->toc_tow = 410400.0;
    test_msg->toc_wn = 1838;
    test_msg->toe_tow = 410400.0;
    test_msg->toe_wn = 1838;
    test_msg->valid = 1;
    test_msg->w = -2.7021241452652935;
    sbp_send_message(&sbp_state, 0x46, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x46,
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
    msg_ephemeris_dep_b_t* check_msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((check_msg->af0*100 - -9.92552377284e-05*100) < 0.05, "incorrect value for af0, expected -9.92552377284e-05, is %f", check_msg->af0);
    ck_assert_msg((check_msg->af1*100 - -2.50111042988e-12*100) < 0.05, "incorrect value for af1, expected -2.50111042988e-12, is %f", check_msg->af1);
    ck_assert_msg((check_msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", check_msg->af2);
    ck_assert_msg((check_msg->c_ic*100 - -3.16649675369e-08*100) < 0.05, "incorrect value for c_ic, expected -3.16649675369e-08, is %f", check_msg->c_ic);
    ck_assert_msg((check_msg->c_is*100 - -2.06753611565e-07*100) < 0.05, "incorrect value for c_is, expected -2.06753611565e-07, is %f", check_msg->c_is);
    ck_assert_msg((check_msg->c_rc*100 - 305.21875*100) < 0.05, "incorrect value for c_rc, expected 305.21875, is %f", check_msg->c_rc);
    ck_assert_msg((check_msg->c_rs*100 - 43.21875*100) < 0.05, "incorrect value for c_rs, expected 43.21875, is %f", check_msg->c_rs);
    ck_assert_msg((check_msg->c_uc*100 - 2.10106372833e-06*100) < 0.05, "incorrect value for c_uc, expected 2.10106372833e-06, is %f", check_msg->c_uc);
    ck_assert_msg((check_msg->c_us*100 - 3.76626849174e-06*100) < 0.05, "incorrect value for c_us, expected 3.76626849174e-06, is %f", check_msg->c_us);
    ck_assert_msg((check_msg->dn*100 - 5.26057626697e-09*100) < 0.05, "incorrect value for dn, expected 5.26057626697e-09, is %f", check_msg->dn);
    ck_assert_msg((check_msg->ecc*100 - 0.00992374494672*100) < 0.05, "incorrect value for ecc, expected 0.00992374494672, is %f", check_msg->ecc);
    ck_assert_msg(check_msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", check_msg->healthy);
    ck_assert_msg((check_msg->inc*100 - 0.948751322181*100) < 0.05, "incorrect value for inc, expected 0.948751322181, is %f", check_msg->inc);
    ck_assert_msg((check_msg->inc_dot*100 - 3.00012496725e-10*100) < 0.05, "incorrect value for inc_dot, expected 3.00012496725e-10, is %f", check_msg->inc_dot);
    ck_assert_msg(check_msg->iode == 0, "incorrect value for iode, expected 0, is %d", check_msg->iode);
    ck_assert_msg((check_msg->m0*100 - -2.66616027191*100) < 0.05, "incorrect value for m0, expected -2.66616027191, is %f", check_msg->m0);
    ck_assert_msg((check_msg->omega0*100 - 1.16695519726*100) < 0.05, "incorrect value for omega0, expected 1.16695519726, is %f", check_msg->omega0);
    ck_assert_msg((check_msg->omegadot*100 - -8.4599952499e-09*100) < 0.05, "incorrect value for omegadot, expected -8.4599952499e-09, is %f", check_msg->omegadot);
    ck_assert_msg(check_msg->prn == 22, "incorrect value for prn, expected 22, is %d", check_msg->prn);
    ck_assert_msg((check_msg->sqrta*100 - 5153.63666725*100) < 0.05, "incorrect value for sqrta, expected 5153.63666725, is %f", check_msg->sqrta);
    ck_assert_msg((check_msg->tgd*100 - -2.00234353542e-08*100) < 0.05, "incorrect value for tgd, expected -2.00234353542e-08, is %f", check_msg->tgd);
    ck_assert_msg((check_msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", check_msg->toc_tow);
    ck_assert_msg(check_msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", check_msg->toc_wn);
    ck_assert_msg((check_msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", check_msg->toe_tow);
    ck_assert_msg(check_msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", check_msg->toe_wn);
    ck_assert_msg(check_msg->valid == 1, "incorrect value for valid, expected 1, is %d", check_msg->valid);
    ck_assert_msg((check_msg->w*100 - -2.70212414527*100) < 0.05, "incorrect value for w, expected -2.70212414527, is %f", check_msg->w);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x46, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,70,0,195,4,176,0,0,0,0,0,0,77,190,0,0,0,0,0,122,83,192,0,0,0,0,0,233,110,64,0,0,0,0,0,60,207,190,0,0,0,0,0,28,222,62,0,0,0,0,0,128,120,62,0,0,0,0,0,0,108,62,10,230,183,140,214,230,50,62,54,86,196,164,252,10,255,63,0,0,0,36,247,191,128,63,0,0,160,5,193,33,180,64,186,138,81,129,88,239,1,64,94,210,120,170,106,25,65,190,103,213,32,155,227,194,224,191,156,47,104,93,101,55,239,63,196,83,100,254,51,54,4,190,0,0,0,0,50,242,52,63,0,0,0,0,0,0,114,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,30,0,170,33, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ephemeris_dep_b_t* test_msg = ( msg_ephemeris_dep_b_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->af0 = 0.0003196117468178272;
    test_msg->af1 = -1.0231815394945443e-12;
    test_msg->af2 = 0.0;
    test_msg->c_ic = 9.12696123123169e-08;
    test_msg->c_is = 5.21540641784668e-08;
    test_msg->c_rc = 247.28125;
    test_msg->c_rs = -77.90625;
    test_msg->c_uc = -3.723427653312683e-06;
    test_msg->c_us = 7.178634405136108e-06;
    test_msg->dn = 4.400897600764146e-09;
    test_msg->ecc = 0.008178644930012524;
    test_msg->healthy = 1;
    test_msg->inc = 0.9755122017245301;
    test_msg->inc_dot = -5.882387882209502e-10;
    test_msg->iode = 0;
    test_msg->m0 = 1.9401823459824192;
    test_msg->omega0 = 2.241868028927766;
    test_msg->omegadot = -7.962474526167494e-09;
    test_msg->prn = 30;
    test_msg->sqrta = 5153.7539920806885;
    test_msg->tgd = -1.3504177331924438e-08;
    test_msg->toc_tow = 410400.0;
    test_msg->toc_wn = 1838;
    test_msg->toe_tow = 410400.0;
    test_msg->toe_wn = 1838;
    test_msg->valid = 1;
    test_msg->w = -0.5237901716088061;
    sbp_send_message(&sbp_state, 0x46, 1219, test_msg_len, test_msg_storage, &dummy_write);

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
    ck_assert_msg(last_frame.msg_type == 0x46,
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
    msg_ephemeris_dep_b_t* check_msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((check_msg->af0*100 - 0.000319611746818*100) < 0.05, "incorrect value for af0, expected 0.000319611746818, is %f", check_msg->af0);
    ck_assert_msg((check_msg->af1*100 - -1.02318153949e-12*100) < 0.05, "incorrect value for af1, expected -1.02318153949e-12, is %f", check_msg->af1);
    ck_assert_msg((check_msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", check_msg->af2);
    ck_assert_msg((check_msg->c_ic*100 - 9.12696123123e-08*100) < 0.05, "incorrect value for c_ic, expected 9.12696123123e-08, is %f", check_msg->c_ic);
    ck_assert_msg((check_msg->c_is*100 - 5.21540641785e-08*100) < 0.05, "incorrect value for c_is, expected 5.21540641785e-08, is %f", check_msg->c_is);
    ck_assert_msg((check_msg->c_rc*100 - 247.28125*100) < 0.05, "incorrect value for c_rc, expected 247.28125, is %f", check_msg->c_rc);
    ck_assert_msg((check_msg->c_rs*100 - -77.90625*100) < 0.05, "incorrect value for c_rs, expected -77.90625, is %f", check_msg->c_rs);
    ck_assert_msg((check_msg->c_uc*100 - -3.72342765331e-06*100) < 0.05, "incorrect value for c_uc, expected -3.72342765331e-06, is %f", check_msg->c_uc);
    ck_assert_msg((check_msg->c_us*100 - 7.17863440514e-06*100) < 0.05, "incorrect value for c_us, expected 7.17863440514e-06, is %f", check_msg->c_us);
    ck_assert_msg((check_msg->dn*100 - 4.40089760076e-09*100) < 0.05, "incorrect value for dn, expected 4.40089760076e-09, is %f", check_msg->dn);
    ck_assert_msg((check_msg->ecc*100 - 0.00817864493001*100) < 0.05, "incorrect value for ecc, expected 0.00817864493001, is %f", check_msg->ecc);
    ck_assert_msg(check_msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", check_msg->healthy);
    ck_assert_msg((check_msg->inc*100 - 0.975512201725*100) < 0.05, "incorrect value for inc, expected 0.975512201725, is %f", check_msg->inc);
    ck_assert_msg((check_msg->inc_dot*100 - -5.88238788221e-10*100) < 0.05, "incorrect value for inc_dot, expected -5.88238788221e-10, is %f", check_msg->inc_dot);
    ck_assert_msg(check_msg->iode == 0, "incorrect value for iode, expected 0, is %d", check_msg->iode);
    ck_assert_msg((check_msg->m0*100 - 1.94018234598*100) < 0.05, "incorrect value for m0, expected 1.94018234598, is %f", check_msg->m0);
    ck_assert_msg((check_msg->omega0*100 - 2.24186802893*100) < 0.05, "incorrect value for omega0, expected 2.24186802893, is %f", check_msg->omega0);
    ck_assert_msg((check_msg->omegadot*100 - -7.96247452617e-09*100) < 0.05, "incorrect value for omegadot, expected -7.96247452617e-09, is %f", check_msg->omegadot);
    ck_assert_msg(check_msg->prn == 30, "incorrect value for prn, expected 30, is %d", check_msg->prn);
    ck_assert_msg((check_msg->sqrta*100 - 5153.75399208*100) < 0.05, "incorrect value for sqrta, expected 5153.75399208, is %f", check_msg->sqrta);
    ck_assert_msg((check_msg->tgd*100 - -1.35041773319e-08*100) < 0.05, "incorrect value for tgd, expected -1.35041773319e-08, is %f", check_msg->tgd);
    ck_assert_msg((check_msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", check_msg->toc_tow);
    ck_assert_msg(check_msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", check_msg->toc_wn);
    ck_assert_msg((check_msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", check_msg->toe_tow);
    ck_assert_msg(check_msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", check_msg->toe_wn);
    ck_assert_msg(check_msg->valid == 1, "incorrect value for valid, expected 1, is %d", check_msg->valid);
    ck_assert_msg((check_msg->w*100 - -0.523790171609*100) < 0.05, "incorrect value for w, expected -0.523790171609, is %f", check_msg->w);
  }
}
END_TEST

Suite* auto_check_sbp_observation_50_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_observation_50");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_observation_50");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_50);
  suite_add_tcase(s, tc_acq);
  return s;
}