/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swiftnav.com>
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

static u32 n_callbacks_logged;
static u16 last_sender_id;
static u8 last_len;
static u8 last_msg[256];
static void* last_context;

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

static u32 dummy_write(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(dummy_buff + dummy_wr, buff, real_n);
 dummy_wr += real_n;
 return real_n;
}

static u32 dummy_read(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(buff, dummy_buff + dummy_rd, real_n);
 dummy_rd += real_n;
 return real_n;
}

static void logging_reset()
{
  n_callbacks_logged = 0;
  last_context = 0;
  memset(last_msg, 0, sizeof(last_msg));
}

static void logging_callback(u16 sender_id, u8 len, u8 msg[], void* context)
{
  n_callbacks_logged++;
  last_sender_id = sender_id;
  last_len = len;
  last_context = context;
  memcpy(last_msg, msg, len);

  /*printy_callback(sender_id, len, msg);*/
}

START_TEST( test_auto_check_sbp_observation_23 )
{
  static sbp_msg_callbacks_node_t n;
  //static sbp_msg_callbacks_node_t n2;

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

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,98,56,158,67,24,46,7,32,56,235,249,121,244,114,255,255,33,46,67,218,0,238,203,70,124,22,25,3,0,98,43,184,157,2,176,133,197,125,126,71,253,255,185,39,68,55,3,60,173,162,131,98,231,253,255,139,30,33,16,10,128,178,248,136,42,113,253,255,40,20,42,71,13,246,246,17,135,255,51,3,0,64,27,108,249,22,210,41,114,118,131,48,255,255,31,52,226,58,30,23,217, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header.n_obs, expected 32, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 407084600, "incorrect value for header.t.tow, expected 407084600, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].P == 2046421816, "incorrect value for obs[0].P, expected 2046421816, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].prn == 0, "incorrect value for obs[0].prn, expected 0, is %d", msg->obs[0].prn);
    fail_unless(msg->obs[0].L.i == -36108, "incorrect value for obs[0].L.i, expected -36108, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 33, "incorrect value for obs[0].L.f, expected 33, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 46, "incorrect value for obs[0].cn0, expected 46, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].lock == 55875, "incorrect value for obs[0].lock, expected 55875, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[1].P == 2085014510, "incorrect value for obs[1].P, expected 2085014510, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].prn == 2, "incorrect value for obs[1].prn, expected 2, is %d", msg->obs[1].prn);
    fail_unless(msg->obs[1].L.i == 203030, "incorrect value for obs[1].L.i, expected 203030, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 98, "incorrect value for obs[1].L.f, expected 98, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 43, "incorrect value for obs[1].cn0, expected 43, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].lock == 40376, "incorrect value for obs[1].lock, expected 40376, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[2].P == 2110096816, "incorrect value for obs[2].P, expected 2110096816, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].prn == 3, "incorrect value for obs[2].prn, expected 3, is %d", msg->obs[2].prn);
    fail_unless(msg->obs[2].L.i == -178306, "incorrect value for obs[2].L.i, expected -178306, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 185, "incorrect value for obs[2].L.f, expected 185, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 39, "incorrect value for obs[2].cn0, expected 39, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].lock == 14148, "incorrect value for obs[2].lock, expected 14148, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[3].P == 2208476476, "incorrect value for obs[3].P, expected 2208476476, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].prn == 10, "incorrect value for obs[3].prn, expected 10, is %d", msg->obs[3].prn);
    fail_unless(msg->obs[3].L.i == -137374, "incorrect value for obs[3].L.i, expected -137374, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 139, "incorrect value for obs[3].L.f, expected 139, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 30, "incorrect value for obs[3].cn0, expected 30, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].lock == 4129, "incorrect value for obs[3].lock, expected 4129, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[4].P == 2298000000, "incorrect value for obs[4].P, expected 2298000000, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].prn == 13, "incorrect value for obs[4].prn, expected 13, is %d", msg->obs[4].prn);
    fail_unless(msg->obs[4].L.i == -167638, "incorrect value for obs[4].L.i, expected -167638, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 40, "incorrect value for obs[4].L.f, expected 40, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 20, "incorrect value for obs[4].cn0, expected 20, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].lock == 18218, "incorrect value for obs[4].lock, expected 18218, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[5].P == 2266101494, "incorrect value for obs[5].P, expected 2266101494, is %d", msg->obs[5].P);
    fail_unless(msg->obs[5].prn == 22, "incorrect value for obs[5].prn, expected 22, is %d", msg->obs[5].prn);
    fail_unless(msg->obs[5].L.i == 209919, "incorrect value for obs[5].L.i, expected 209919, is %d", msg->obs[5].L.i);
    fail_unless(msg->obs[5].L.f == 64, "incorrect value for obs[5].L.f, expected 64, is %d", msg->obs[5].L.f);
    fail_unless(msg->obs[5].cn0 == 27, "incorrect value for obs[5].cn0, expected 27, is %d", msg->obs[5].cn0);
    fail_unless(msg->obs[5].lock == 63852, "incorrect value for obs[5].lock, expected 63852, is %d", msg->obs[5].lock);
    fail_unless(msg->obs[6].P == 1987193298, "incorrect value for obs[6].P, expected 1987193298, is %d", msg->obs[6].P);
    fail_unless(msg->obs[6].prn == 30, "incorrect value for obs[6].prn, expected 30, is %d", msg->obs[6].prn);
    fail_unless(msg->obs[6].L.i == -53117, "incorrect value for obs[6].L.i, expected -53117, is %d", msg->obs[6].L.i);
    fail_unless(msg->obs[6].L.f == 31, "incorrect value for obs[6].L.f, expected 31, is %d", msg->obs[6].L.f);
    fail_unless(msg->obs[6].cn0 == 52, "incorrect value for obs[6].cn0, expected 52, is %d", msg->obs[6].cn0);
    fail_unless(msg->obs[6].lock == 15074, "incorrect value for obs[6].lock, expected 15074, is %d", msg->obs[6].lock);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,20,56,158,67,24,46,7,33,84,52,164,117,102,32,0,0,147,62,62,250,31,234,14, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 33, "incorrect value for header.n_obs, expected 33, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 407084600, "incorrect value for header.t.tow, expected 407084600, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].P == 1973695572, "incorrect value for obs[0].P, expected 1973695572, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].prn == 31, "incorrect value for obs[0].prn, expected 31, is %d", msg->obs[0].prn);
    fail_unless(msg->obs[0].L.i == 8294, "incorrect value for obs[0].L.i, expected 8294, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 147, "incorrect value for obs[0].L.f, expected 147, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 62, "incorrect value for obs[0].cn0, expected 62, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].lock == 64062, "incorrect value for obs[0].lock, expected 64062, is %d", msg->obs[0].lock);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,98,0,159,67,24,46,7,32,32,209,249,121,145,114,255,255,141,45,67,218,0,177,128,70,124,79,27,3,0,159,44,184,157,2,59,135,197,125,175,69,253,255,77,40,68,55,3,211,172,162,131,177,229,253,255,20,31,33,16,10,128,178,248,136,116,111,253,255,94,21,42,71,13,182,173,17,135,37,54,3,0,214,27,108,249,22,91,20,114,118,240,47,255,255,129,52,226,58,30,200,119, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header.n_obs, expected 32, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 407084800, "incorrect value for header.t.tow, expected 407084800, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].P == 2046415136, "incorrect value for obs[0].P, expected 2046415136, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].prn == 0, "incorrect value for obs[0].prn, expected 0, is %d", msg->obs[0].prn);
    fail_unless(msg->obs[0].L.i == -36207, "incorrect value for obs[0].L.i, expected -36207, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 141, "incorrect value for obs[0].L.f, expected 141, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 45, "incorrect value for obs[0].cn0, expected 45, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].lock == 55875, "incorrect value for obs[0].lock, expected 55875, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[1].P == 2084995249, "incorrect value for obs[1].P, expected 2084995249, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].prn == 2, "incorrect value for obs[1].prn, expected 2, is %d", msg->obs[1].prn);
    fail_unless(msg->obs[1].L.i == 203599, "incorrect value for obs[1].L.i, expected 203599, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 159, "incorrect value for obs[1].L.f, expected 159, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 44, "incorrect value for obs[1].cn0, expected 44, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].lock == 40376, "incorrect value for obs[1].lock, expected 40376, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[2].P == 2110097211, "incorrect value for obs[2].P, expected 2110097211, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].prn == 3, "incorrect value for obs[2].prn, expected 3, is %d", msg->obs[2].prn);
    fail_unless(msg->obs[2].L.i == -178769, "incorrect value for obs[2].L.i, expected -178769, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 77, "incorrect value for obs[2].L.f, expected 77, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 40, "incorrect value for obs[2].cn0, expected 40, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].lock == 14148, "incorrect value for obs[2].lock, expected 14148, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[3].P == 2208476371, "incorrect value for obs[3].P, expected 2208476371, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].prn == 10, "incorrect value for obs[3].prn, expected 10, is %d", msg->obs[3].prn);
    fail_unless(msg->obs[3].L.i == -137807, "incorrect value for obs[3].L.i, expected -137807, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 20, "incorrect value for obs[3].L.f, expected 20, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 31, "incorrect value for obs[3].cn0, expected 31, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].lock == 4129, "incorrect value for obs[3].lock, expected 4129, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[4].P == 2298000000, "incorrect value for obs[4].P, expected 2298000000, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].prn == 13, "incorrect value for obs[4].prn, expected 13, is %d", msg->obs[4].prn);
    fail_unless(msg->obs[4].L.i == -168076, "incorrect value for obs[4].L.i, expected -168076, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 94, "incorrect value for obs[4].L.f, expected 94, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 21, "incorrect value for obs[4].cn0, expected 21, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].lock == 18218, "incorrect value for obs[4].lock, expected 18218, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[5].P == 2266082742, "incorrect value for obs[5].P, expected 2266082742, is %d", msg->obs[5].P);
    fail_unless(msg->obs[5].prn == 22, "incorrect value for obs[5].prn, expected 22, is %d", msg->obs[5].prn);
    fail_unless(msg->obs[5].L.i == 210469, "incorrect value for obs[5].L.i, expected 210469, is %d", msg->obs[5].L.i);
    fail_unless(msg->obs[5].L.f == 214, "incorrect value for obs[5].L.f, expected 214, is %d", msg->obs[5].L.f);
    fail_unless(msg->obs[5].cn0 == 27, "incorrect value for obs[5].cn0, expected 27, is %d", msg->obs[5].cn0);
    fail_unless(msg->obs[5].lock == 63852, "incorrect value for obs[5].lock, expected 63852, is %d", msg->obs[5].lock);
    fail_unless(msg->obs[6].P == 1987187803, "incorrect value for obs[6].P, expected 1987187803, is %d", msg->obs[6].P);
    fail_unless(msg->obs[6].prn == 30, "incorrect value for obs[6].prn, expected 30, is %d", msg->obs[6].prn);
    fail_unless(msg->obs[6].L.i == -53264, "incorrect value for obs[6].L.i, expected -53264, is %d", msg->obs[6].L.i);
    fail_unless(msg->obs[6].L.f == 129, "incorrect value for obs[6].L.f, expected 129, is %d", msg->obs[6].L.f);
    fail_unless(msg->obs[6].cn0 == 52, "incorrect value for obs[6].cn0, expected 52, is %d", msg->obs[6].cn0);
    fail_unless(msg->obs[6].lock == 15074, "incorrect value for obs[6].lock, expected 15074, is %d", msg->obs[6].lock);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,20,0,159,67,24,46,7,33,49,19,164,117,120,32,0,0,222,63,62,250,31,11,231, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 33, "incorrect value for header.n_obs, expected 33, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 407084800, "incorrect value for header.t.tow, expected 407084800, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].P == 1973687089, "incorrect value for obs[0].P, expected 1973687089, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].prn == 31, "incorrect value for obs[0].prn, expected 31, is %d", msg->obs[0].prn);
    fail_unless(msg->obs[0].L.i == 8312, "incorrect value for obs[0].L.i, expected 8312, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 222, "incorrect value for obs[0].L.f, expected 222, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 63, "incorrect value for obs[0].cn0, expected 63, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].lock == 64062, "incorrect value for obs[0].lock, expected 64062, is %d", msg->obs[0].lock);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,72,96,162,68,24,46,7,16,87,132,217,121,121,148,255,255,189,43,175,147,0,132,64,200,125,106,31,254,255,1,41,14,177,3,128,178,248,136,70,68,254,255,166,18,184,133,13,24,127,178,134,6,25,2,0,249,28,33,96,22,170,104,86,118,67,112,255,255,203,56,208,88,30,43,107, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 16, "incorrect value for header.n_obs, expected 16, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 407151200, "incorrect value for header.t.tow, expected 407151200, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].P == 2044298327, "incorrect value for obs[0].P, expected 2044298327, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].prn == 0, "incorrect value for obs[0].prn, expected 0, is %d", msg->obs[0].prn);
    fail_unless(msg->obs[0].L.i == -27527, "incorrect value for obs[0].L.i, expected -27527, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 189, "incorrect value for obs[0].L.f, expected 189, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 43, "incorrect value for obs[0].cn0, expected 43, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].lock == 37807, "incorrect value for obs[0].lock, expected 37807, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[1].P == 2110275716, "incorrect value for obs[1].P, expected 2110275716, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].prn == 3, "incorrect value for obs[1].prn, expected 3, is %d", msg->obs[1].prn);
    fail_unless(msg->obs[1].L.i == -123030, "incorrect value for obs[1].L.i, expected -123030, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 1, "incorrect value for obs[1].L.f, expected 1, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 41, "incorrect value for obs[1].cn0, expected 41, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].lock == 45326, "incorrect value for obs[1].lock, expected 45326, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[2].P == 2298000000, "incorrect value for obs[2].P, expected 2298000000, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].prn == 13, "incorrect value for obs[2].prn, expected 13, is %d", msg->obs[2].prn);
    fail_unless(msg->obs[2].L.i == -113594, "incorrect value for obs[2].L.i, expected -113594, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 166, "incorrect value for obs[2].L.f, expected 166, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 18, "incorrect value for obs[2].cn0, expected 18, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].lock == 34232, "incorrect value for obs[2].lock, expected 34232, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[3].P == 2259844888, "incorrect value for obs[3].P, expected 2259844888, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].prn == 22, "incorrect value for obs[3].prn, expected 22, is %d", msg->obs[3].prn);
    fail_unless(msg->obs[3].L.i == 137478, "incorrect value for obs[3].L.i, expected 137478, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 249, "incorrect value for obs[3].L.f, expected 249, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 28, "incorrect value for obs[3].cn0, expected 28, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].lock == 24609, "incorrect value for obs[3].lock, expected 24609, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[4].P == 1985374378, "incorrect value for obs[4].P, expected 1985374378, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].prn == 30, "incorrect value for obs[4].prn, expected 30, is %d", msg->obs[4].prn);
    fail_unless(msg->obs[4].L.i == -36797, "incorrect value for obs[4].L.i, expected -36797, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 203, "incorrect value for obs[4].L.f, expected 203, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 56, "incorrect value for obs[4].cn0, expected 56, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].lock == 22736, "incorrect value for obs[4].lock, expected 22736, is %d", msg->obs[4].lock);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,72,40,163,68,24,46,7,16,132,107,217,121,14,148,255,255,1,44,175,147,0,129,66,200,125,148,29,254,255,153,41,14,177,3,128,178,248,136,143,66,254,255,222,18,184,133,13,158,53,178,134,42,27,2,0,237,30,33,96,22,38,83,86,118,168,111,255,255,45,56,208,88,30,1,175, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 16, "incorrect value for header.n_obs, expected 16, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 407151400, "incorrect value for header.t.tow, expected 407151400, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].P == 2044291972, "incorrect value for obs[0].P, expected 2044291972, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].prn == 0, "incorrect value for obs[0].prn, expected 0, is %d", msg->obs[0].prn);
    fail_unless(msg->obs[0].L.i == -27634, "incorrect value for obs[0].L.i, expected -27634, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 1, "incorrect value for obs[0].L.f, expected 1, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 44, "incorrect value for obs[0].cn0, expected 44, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].lock == 37807, "incorrect value for obs[0].lock, expected 37807, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[1].P == 2110276225, "incorrect value for obs[1].P, expected 2110276225, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].prn == 3, "incorrect value for obs[1].prn, expected 3, is %d", msg->obs[1].prn);
    fail_unless(msg->obs[1].L.i == -123500, "incorrect value for obs[1].L.i, expected -123500, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 153, "incorrect value for obs[1].L.f, expected 153, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 41, "incorrect value for obs[1].cn0, expected 41, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].lock == 45326, "incorrect value for obs[1].lock, expected 45326, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[2].P == 2298000000, "incorrect value for obs[2].P, expected 2298000000, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].prn == 13, "incorrect value for obs[2].prn, expected 13, is %d", msg->obs[2].prn);
    fail_unless(msg->obs[2].L.i == -114033, "incorrect value for obs[2].L.i, expected -114033, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 222, "incorrect value for obs[2].L.f, expected 222, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 18, "incorrect value for obs[2].cn0, expected 18, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].lock == 34232, "incorrect value for obs[2].lock, expected 34232, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[3].P == 2259826078, "incorrect value for obs[3].P, expected 2259826078, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].prn == 22, "incorrect value for obs[3].prn, expected 22, is %d", msg->obs[3].prn);
    fail_unless(msg->obs[3].L.i == 138026, "incorrect value for obs[3].L.i, expected 138026, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 237, "incorrect value for obs[3].L.f, expected 237, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 30, "incorrect value for obs[3].cn0, expected 30, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].lock == 24609, "incorrect value for obs[3].lock, expected 24609, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[4].P == 1985368870, "incorrect value for obs[4].P, expected 1985368870, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].prn == 30, "incorrect value for obs[4].prn, expected 30, is %d", msg->obs[4].prn);
    fail_unless(msg->obs[4].L.i == -36952, "incorrect value for obs[4].L.i, expected -36952, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 45, "incorrect value for obs[4].L.f, expected 45, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 56, "incorrect value for obs[4].cn0, expected 56, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].lock == 22736, "incorrect value for obs[4].lock, expected 22736, is %d", msg->obs[4].lock);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,0,60,190,0,0,0,0,0,186,82,192,0,0,0,0,0,76,109,64,0,0,0,0,0,132,208,190,0,0,0,0,0,254,220,62,0,0,0,0,0,0,113,62,0,0,0,0,0,0,133,190,28,36,25,81,223,254,52,62,220,116,216,39,33,189,3,64,0,0,0,156,177,204,134,63,0,0,160,220,182,33,180,64,152,225,192,44,254,76,238,191,41,150,24,2,148,156,65,190,252,90,119,48,15,215,240,63,124,127,115,94,208,16,238,63,165,115,52,74,97,167,246,189,0,0,0,0,192,180,229,190,0,0,0,0,0,0,112,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,3,0,225,156, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->dn*100 - 4.88841790794e-09*100) < 0.05, "incorrect value for dn, expected 4.88841790794e-09, is %f", msg->dn);
    fail_unless(msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", msg->toc_wn);
    fail_unless((msg->c_is*100 - -1.56462192535e-07*100) < 0.05, "incorrect value for c_is, expected -1.56462192535e-07, is %f", msg->c_is);
    fail_unless((msg->c_ic*100 - 6.33299350739e-08*100) < 0.05, "incorrect value for c_ic, expected 6.33299350739e-08, is %f", msg->c_ic);
    fail_unless((msg->c_rs*100 - -74.90625*100) < 0.05, "incorrect value for c_rs, expected -74.90625, is %f", msg->c_rs);
    fail_unless(msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", msg->toe_wn);
    fail_unless(msg->prn == 3, "incorrect value for prn, expected 3, is %d", msg->prn);
    fail_unless((msg->inc_dot*100 - -3.29656588663e-10*100) < 0.05, "incorrect value for inc_dot, expected -3.29656588663e-10, is %f", msg->inc_dot);
    fail_unless((msg->tgd*100 - -6.51925802231e-09*100) < 0.05, "incorrect value for tgd, expected -6.51925802231e-09, is %f", msg->tgd);
    fail_unless((msg->c_rc*100 - 234.375*100) < 0.05, "incorrect value for c_rc, expected 234.375, is %f", msg->c_rc);
    fail_unless((msg->ecc*100 - 0.0111326099141*100) < 0.05, "incorrect value for ecc, expected 0.0111326099141, is %f", msg->ecc);
    fail_unless((msg->sqrta*100 - 5153.71430397*100) < 0.05, "incorrect value for sqrta, expected 5153.71430397, is %f", msg->sqrta);
    fail_unless((msg->omegadot*100 - -8.20105589261e-09*100) < 0.05, "incorrect value for omegadot, expected -8.20105589261e-09, is %f", msg->omegadot);
    fail_unless((msg->inc*100 - 0.939552483058*100) < 0.05, "incorrect value for inc, expected 0.939552483058, is %f", msg->inc);
    fail_unless((msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", msg->toe_tow);
    fail_unless((msg->c_uc*100 - -3.93763184547e-06*100) < 0.05, "incorrect value for c_uc, expected -3.93763184547e-06, is %f", msg->c_uc);
    fail_unless(msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", msg->healthy);
    fail_unless(msg->iode == 0, "incorrect value for iode, expected 0, is %d", msg->iode);
    fail_unless((msg->omega0*100 - -0.946898543748*100) < 0.05, "incorrect value for omega0, expected -0.946898543748, is %f", msg->omega0);
    fail_unless((msg->c_us*100 - 6.9122761488e-06*100) < 0.05, "incorrect value for c_us, expected 6.9122761488e-06, is %f", msg->c_us);
    fail_unless(msg->valid == 1, "incorrect value for valid, expected 1, is %d", msg->valid);
    fail_unless((msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", msg->af2);
    fail_unless((msg->m0*100 - 2.46734839563*100) < 0.05, "incorrect value for m0, expected 2.46734839563, is %f", msg->m0);
    fail_unless((msg->w*100 - 1.05250472004*100) < 0.05, "incorrect value for w, expected 1.05250472004, is %f", msg->w);
    fail_unless((msg->af0*100 - -1.0350253433e-05*100) < 0.05, "incorrect value for af0, expected -1.0350253433e-05, is %f", msg->af0);
    fail_unless((msg->af1*100 - -9.09494701773e-13*100) < 0.05, "incorrect value for af1, expected -9.09494701773e-13, is %f", msg->af1);
    fail_unless((msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", msg->toc_tow);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,0,68,190,0,0,0,0,0,72,66,64,0,0,0,0,128,188,115,64,0,0,0,0,0,80,193,62,0,0,0,0,0,164,204,62,0,0,0,0,0,0,130,62,0,0,0,0,0,0,128,62,72,181,127,6,208,225,52,62,158,174,129,91,27,105,249,191,0,0,0,96,204,57,128,63,0,0,160,35,146,33,180,64,247,169,1,36,133,206,243,63,79,11,109,92,156,208,65,190,103,78,3,253,223,147,255,191,164,214,90,250,218,240,238,63,94,239,187,37,36,10,242,61,0,0,0,0,176,91,19,63,0,0,0,0,0,0,137,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,13,0,180,21, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->dn*100 - 4.86198823561e-09*100) < 0.05, "incorrect value for dn, expected 4.86198823561e-09, is %f", msg->dn);
    fail_unless(msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", msg->toc_wn);
    fail_unless((msg->c_is*100 - 1.19209289551e-07*100) < 0.05, "incorrect value for c_is, expected 1.19209289551e-07, is %f", msg->c_is);
    fail_unless((msg->c_ic*100 - 1.34110450745e-07*100) < 0.05, "incorrect value for c_ic, expected 1.34110450745e-07, is %f", msg->c_ic);
    fail_unless((msg->c_rs*100 - 36.5625*100) < 0.05, "incorrect value for c_rs, expected 36.5625, is %f", msg->c_rs);
    fail_unless(msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", msg->toe_wn);
    fail_unless(msg->prn == 13, "incorrect value for prn, expected 13, is %d", msg->prn);
    fail_unless((msg->inc_dot*100 - 2.62510934634e-10*100) < 0.05, "incorrect value for inc_dot, expected 2.62510934634e-10, is %f", msg->inc_dot);
    fail_unless((msg->tgd*100 - -9.31322574615e-09*100) < 0.05, "incorrect value for tgd, expected -9.31322574615e-09, is %f", msg->tgd);
    fail_unless((msg->c_rc*100 - 315.78125*100) < 0.05, "incorrect value for c_rc, expected 315.78125, is %f", msg->c_rc);
    fail_unless((msg->ecc*100 - 0.00792274158448*100) < 0.05, "incorrect value for ecc, expected 0.00792274158448, is %f", msg->ecc);
    fail_unless((msg->sqrta*100 - 5153.57085609*100) < 0.05, "incorrect value for sqrta, expected 5153.57085609, is %f", msg->sqrta);
    fail_unless((msg->omegadot*100 - -8.29570269217e-09*100) < 0.05, "incorrect value for omegadot, expected -8.29570269217e-09, is %f", msg->omegadot);
    fail_unless((msg->inc*100 - 0.966901291823*100) < 0.05, "incorrect value for inc, expected 0.966901291823, is %f", msg->inc);
    fail_unless((msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", msg->toe_tow);
    fail_unless((msg->c_uc*100 - 2.06381082535e-06*100) < 0.05, "incorrect value for c_uc, expected 2.06381082535e-06, is %f", msg->c_uc);
    fail_unless(msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", msg->healthy);
    fail_unless(msg->iode == 0, "incorrect value for iode, expected 0, is %d", msg->iode);
    fail_unless((msg->omega0*100 - 1.23791994157*100) < 0.05, "incorrect value for omega0, expected 1.23791994157, is %f", msg->omega0);
    fail_unless((msg->c_us*100 - 3.41422855854e-06*100) < 0.05, "incorrect value for c_us, expected 3.41422855854e-06, is %f", msg->c_us);
    fail_unless(msg->valid == 1, "incorrect value for valid, expected 1, is %d", msg->valid);
    fail_unless((msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", msg->af2);
    fail_unless((msg->m0*100 - -1.58816085572*100) < 0.05, "incorrect value for m0, expected -1.58816085572, is %f", msg->m0);
    fail_unless((msg->w*100 - -1.97360228379*100) < 0.05, "incorrect value for w, expected -1.97360228379, is %f", msg->w);
    fail_unless((msg->af0*100 - 7.38454982638e-05*100) < 0.05, "incorrect value for af0, expected 7.38454982638e-05, is %f", msg->af0);
    fail_unless((msg->af1*100 - -2.84217094304e-12*100) < 0.05, "incorrect value for af1, expected -2.84217094304e-12, is %f", msg->af1);
    fail_unless((msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", msg->toc_tow);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,0,56,62,0,0,0,0,0,40,81,192,0,0,0,0,0,129,109,64,0,0,0,0,0,28,205,190,0,0,0,0,0,76,223,62,0,0,0,0,0,0,105,190,0,0,0,0,0,0,92,190,134,161,223,255,243,43,51,62,146,176,113,142,234,164,5,64,0,0,0,56,175,140,112,63,0,0,192,90,171,33,180,64,36,38,237,255,200,160,237,191,204,92,63,154,49,91,65,190,125,94,251,132,52,61,216,63,2,139,28,27,231,199,238,63,124,183,4,180,194,30,247,189,0,0,0,0,0,104,222,190,0,0,0,0,0,0,96,61,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,0,0,222,152, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->dn*100 - 4.46375736198e-09*100) < 0.05, "incorrect value for dn, expected 4.46375736198e-09, is %f", msg->dn);
    fail_unless(msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", msg->toc_wn);
    fail_unless((msg->c_is*100 - -2.60770320892e-08*100) < 0.05, "incorrect value for c_is, expected -2.60770320892e-08, is %f", msg->c_is);
    fail_unless((msg->c_ic*100 - -4.65661287308e-08*100) < 0.05, "incorrect value for c_ic, expected -4.65661287308e-08, is %f", msg->c_ic);
    fail_unless((msg->c_rs*100 - -68.625*100) < 0.05, "incorrect value for c_rs, expected -68.625, is %f", msg->c_rs);
    fail_unless(msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", msg->toe_wn);
    fail_unless(msg->prn == 0, "incorrect value for prn, expected 0, is %d", msg->prn);
    fail_unless((msg->inc_dot*100 - -3.36442585613e-10*100) < 0.05, "incorrect value for inc_dot, expected -3.36442585613e-10, is %f", msg->inc_dot);
    fail_unless((msg->tgd*100 - 5.58793544769e-09*100) < 0.05, "incorrect value for tgd, expected 5.58793544769e-09, is %f", msg->tgd);
    fail_unless((msg->c_rc*100 - 236.03125*100) < 0.05, "incorrect value for c_rc, expected 236.03125, is %f", msg->c_rc);
    fail_unless((msg->ecc*100 - 0.00404041714501*100) < 0.05, "incorrect value for ecc, expected 0.00404041714501, is %f", msg->ecc);
    fail_unless((msg->sqrta*100 - 5153.66935349*100) < 0.05, "incorrect value for sqrta, expected 5153.66935349, is %f", msg->sqrta);
    fail_unless((msg->omegadot*100 - -8.08212236712e-09*100) < 0.05, "incorrect value for omegadot, expected -8.08212236712e-09, is %f", msg->omegadot);
    fail_unless((msg->inc*100 - 0.96190219207*100) < 0.05, "incorrect value for inc, expected 0.96190219207, is %f", msg->inc);
    fail_unless((msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", msg->toe_tow);
    fail_unless((msg->c_uc*100 - -3.47010791302e-06*100) < 0.05, "incorrect value for c_uc, expected -3.47010791302e-06, is %f", msg->c_uc);
    fail_unless(msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", msg->healthy);
    fail_unless(msg->iode == 0, "incorrect value for iode, expected 0, is %d", msg->iode);
    fail_unless((msg->omega0*100 - -0.925877094132*100) < 0.05, "incorrect value for omega0, expected -0.925877094132, is %f", msg->omega0);
    fail_unless((msg->c_us*100 - 7.46175646782e-06*100) < 0.05, "incorrect value for c_us, expected 7.46175646782e-06, is %f", msg->c_us);
    fail_unless(msg->valid == 1, "incorrect value for valid, expected 1, is %d", msg->valid);
    fail_unless((msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", msg->af2);
    fail_unless((msg->m0*100 - 2.70552550587*100) < 0.05, "incorrect value for m0, expected 2.70552550587, is %f", msg->m0);
    fail_unless((msg->w*100 - 0.378735666146*100) < 0.05, "incorrect value for w, expected 0.378735666146, is %f", msg->w);
    fail_unless((msg->af0*100 - -7.24941492081e-06*100) < 0.05, "incorrect value for af0, expected -7.24941492081e-06, is %f", msg->af0);
    fail_unless((msg->af1*100 - 4.54747350886e-13*100) < 0.05, "incorrect value for af1, expected 4.54747350886e-13, is %f", msg->af1);
    fail_unless((msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", msg->toc_tow);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,0,68,190,0,0,0,0,0,72,66,64,0,0,0,0,128,188,115,64,0,0,0,0,0,80,193,62,0,0,0,0,0,164,204,62,0,0,0,0,0,0,130,62,0,0,0,0,0,0,128,62,72,181,127,6,208,225,52,62,158,174,129,91,27,105,249,191,0,0,0,96,204,57,128,63,0,0,160,35,146,33,180,64,247,169,1,36,133,206,243,63,79,11,109,92,156,208,65,190,103,78,3,253,223,147,255,191,164,214,90,250,218,240,238,63,94,239,187,37,36,10,242,61,0,0,0,0,176,91,19,63,0,0,0,0,0,0,137,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,13,0,180,21, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->dn*100 - 4.86198823561e-09*100) < 0.05, "incorrect value for dn, expected 4.86198823561e-09, is %f", msg->dn);
    fail_unless(msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", msg->toc_wn);
    fail_unless((msg->c_is*100 - 1.19209289551e-07*100) < 0.05, "incorrect value for c_is, expected 1.19209289551e-07, is %f", msg->c_is);
    fail_unless((msg->c_ic*100 - 1.34110450745e-07*100) < 0.05, "incorrect value for c_ic, expected 1.34110450745e-07, is %f", msg->c_ic);
    fail_unless((msg->c_rs*100 - 36.5625*100) < 0.05, "incorrect value for c_rs, expected 36.5625, is %f", msg->c_rs);
    fail_unless(msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", msg->toe_wn);
    fail_unless(msg->prn == 13, "incorrect value for prn, expected 13, is %d", msg->prn);
    fail_unless((msg->inc_dot*100 - 2.62510934634e-10*100) < 0.05, "incorrect value for inc_dot, expected 2.62510934634e-10, is %f", msg->inc_dot);
    fail_unless((msg->tgd*100 - -9.31322574615e-09*100) < 0.05, "incorrect value for tgd, expected -9.31322574615e-09, is %f", msg->tgd);
    fail_unless((msg->c_rc*100 - 315.78125*100) < 0.05, "incorrect value for c_rc, expected 315.78125, is %f", msg->c_rc);
    fail_unless((msg->ecc*100 - 0.00792274158448*100) < 0.05, "incorrect value for ecc, expected 0.00792274158448, is %f", msg->ecc);
    fail_unless((msg->sqrta*100 - 5153.57085609*100) < 0.05, "incorrect value for sqrta, expected 5153.57085609, is %f", msg->sqrta);
    fail_unless((msg->omegadot*100 - -8.29570269217e-09*100) < 0.05, "incorrect value for omegadot, expected -8.29570269217e-09, is %f", msg->omegadot);
    fail_unless((msg->inc*100 - 0.966901291823*100) < 0.05, "incorrect value for inc, expected 0.966901291823, is %f", msg->inc);
    fail_unless((msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", msg->toe_tow);
    fail_unless((msg->c_uc*100 - 2.06381082535e-06*100) < 0.05, "incorrect value for c_uc, expected 2.06381082535e-06, is %f", msg->c_uc);
    fail_unless(msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", msg->healthy);
    fail_unless(msg->iode == 0, "incorrect value for iode, expected 0, is %d", msg->iode);
    fail_unless((msg->omega0*100 - 1.23791994157*100) < 0.05, "incorrect value for omega0, expected 1.23791994157, is %f", msg->omega0);
    fail_unless((msg->c_us*100 - 3.41422855854e-06*100) < 0.05, "incorrect value for c_us, expected 3.41422855854e-06, is %f", msg->c_us);
    fail_unless(msg->valid == 1, "incorrect value for valid, expected 1, is %d", msg->valid);
    fail_unless((msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", msg->af2);
    fail_unless((msg->m0*100 - -1.58816085572*100) < 0.05, "incorrect value for m0, expected -1.58816085572, is %f", msg->m0);
    fail_unless((msg->w*100 - -1.97360228379*100) < 0.05, "incorrect value for w, expected -1.97360228379, is %f", msg->w);
    fail_unless((msg->af0*100 - 7.38454982638e-05*100) < 0.05, "incorrect value for af0, expected 7.38454982638e-05, is %f", msg->af0);
    fail_unless((msg->af1*100 - -2.84217094304e-12*100) < 0.05, "incorrect value for af1, expected -2.84217094304e-12, is %f", msg->af1);
    fail_unless((msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", msg->toc_tow);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,128,85,190,0,0,0,0,0,156,69,64,0,0,0,0,128,19,115,64,0,0,0,0,0,160,193,62,0,0,0,0,0,152,207,62,0,0,0,0,0,0,97,190,0,0,0,0,0,192,139,190,26,26,13,149,16,152,54,62,104,7,46,214,75,84,5,192,0,0,0,128,230,82,132,63,0,0,160,252,162,33,180,64,73,6,130,54,217,171,242,63,81,224,163,123,238,42,66,190,206,43,141,67,243,157,5,192,113,179,153,187,43,92,238,63,254,236,31,43,224,157,244,61,0,0,0,0,232,4,26,191,0,0,0,0,0,0,134,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,22,0,99,61, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->dn*100 - 5.26057626697e-09*100) < 0.05, "incorrect value for dn, expected 5.26057626697e-09, is %f", msg->dn);
    fail_unless(msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", msg->toc_wn);
    fail_unless((msg->c_is*100 - -2.06753611565e-07*100) < 0.05, "incorrect value for c_is, expected -2.06753611565e-07, is %f", msg->c_is);
    fail_unless((msg->c_ic*100 - -3.16649675369e-08*100) < 0.05, "incorrect value for c_ic, expected -3.16649675369e-08, is %f", msg->c_ic);
    fail_unless((msg->c_rs*100 - 43.21875*100) < 0.05, "incorrect value for c_rs, expected 43.21875, is %f", msg->c_rs);
    fail_unless(msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", msg->toe_wn);
    fail_unless(msg->prn == 22, "incorrect value for prn, expected 22, is %d", msg->prn);
    fail_unless((msg->inc_dot*100 - 3.00012496725e-10*100) < 0.05, "incorrect value for inc_dot, expected 3.00012496725e-10, is %f", msg->inc_dot);
    fail_unless((msg->tgd*100 - -2.00234353542e-08*100) < 0.05, "incorrect value for tgd, expected -2.00234353542e-08, is %f", msg->tgd);
    fail_unless((msg->c_rc*100 - 305.21875*100) < 0.05, "incorrect value for c_rc, expected 305.21875, is %f", msg->c_rc);
    fail_unless((msg->ecc*100 - 0.00992374494672*100) < 0.05, "incorrect value for ecc, expected 0.00992374494672, is %f", msg->ecc);
    fail_unless((msg->sqrta*100 - 5153.63666725*100) < 0.05, "incorrect value for sqrta, expected 5153.63666725, is %f", msg->sqrta);
    fail_unless((msg->omegadot*100 - -8.4599952499e-09*100) < 0.05, "incorrect value for omegadot, expected -8.4599952499e-09, is %f", msg->omegadot);
    fail_unless((msg->inc*100 - 0.948751322181*100) < 0.05, "incorrect value for inc, expected 0.948751322181, is %f", msg->inc);
    fail_unless((msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", msg->toe_tow);
    fail_unless((msg->c_uc*100 - 2.10106372833e-06*100) < 0.05, "incorrect value for c_uc, expected 2.10106372833e-06, is %f", msg->c_uc);
    fail_unless(msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", msg->healthy);
    fail_unless(msg->iode == 0, "incorrect value for iode, expected 0, is %d", msg->iode);
    fail_unless((msg->omega0*100 - 1.16695519726*100) < 0.05, "incorrect value for omega0, expected 1.16695519726, is %f", msg->omega0);
    fail_unless((msg->c_us*100 - 3.76626849174e-06*100) < 0.05, "incorrect value for c_us, expected 3.76626849174e-06, is %f", msg->c_us);
    fail_unless(msg->valid == 1, "incorrect value for valid, expected 1, is %d", msg->valid);
    fail_unless((msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", msg->af2);
    fail_unless((msg->m0*100 - -2.66616027191*100) < 0.05, "incorrect value for m0, expected -2.66616027191, is %f", msg->m0);
    fail_unless((msg->w*100 - -2.70212414527*100) < 0.05, "incorrect value for w, expected -2.70212414527, is %f", msg->w);
    fail_unless((msg->af0*100 - -9.92552377284e-05*100) < 0.05, "incorrect value for af0, expected -9.92552377284e-05, is %f", msg->af0);
    fail_unless((msg->af1*100 - -2.50111042988e-12*100) < 0.05, "incorrect value for af1, expected -2.50111042988e-12, is %f", msg->af1);
    fail_unless((msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", msg->toc_tow);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,0,77,190,0,0,0,0,0,122,83,192,0,0,0,0,0,233,110,64,0,0,0,0,0,60,207,190,0,0,0,0,0,28,222,62,0,0,0,0,0,128,120,62,0,0,0,0,0,0,108,62,10,230,183,140,214,230,50,62,54,86,196,164,252,10,255,63,0,0,0,36,247,191,128,63,0,0,160,5,193,33,180,64,186,138,81,129,88,239,1,64,94,210,120,170,106,25,65,190,103,213,32,155,227,194,224,191,156,47,104,93,101,55,239,63,196,83,100,254,51,54,4,190,0,0,0,0,50,242,52,63,0,0,0,0,0,0,114,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,30,0,170,33, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->dn*100 - 4.40089760076e-09*100) < 0.05, "incorrect value for dn, expected 4.40089760076e-09, is %f", msg->dn);
    fail_unless(msg->toc_wn == 1838, "incorrect value for toc_wn, expected 1838, is %d", msg->toc_wn);
    fail_unless((msg->c_is*100 - 5.21540641785e-08*100) < 0.05, "incorrect value for c_is, expected 5.21540641785e-08, is %f", msg->c_is);
    fail_unless((msg->c_ic*100 - 9.12696123123e-08*100) < 0.05, "incorrect value for c_ic, expected 9.12696123123e-08, is %f", msg->c_ic);
    fail_unless((msg->c_rs*100 - -77.90625*100) < 0.05, "incorrect value for c_rs, expected -77.90625, is %f", msg->c_rs);
    fail_unless(msg->toe_wn == 1838, "incorrect value for toe_wn, expected 1838, is %d", msg->toe_wn);
    fail_unless(msg->prn == 30, "incorrect value for prn, expected 30, is %d", msg->prn);
    fail_unless((msg->inc_dot*100 - -5.88238788221e-10*100) < 0.05, "incorrect value for inc_dot, expected -5.88238788221e-10, is %f", msg->inc_dot);
    fail_unless((msg->tgd*100 - -1.35041773319e-08*100) < 0.05, "incorrect value for tgd, expected -1.35041773319e-08, is %f", msg->tgd);
    fail_unless((msg->c_rc*100 - 247.28125*100) < 0.05, "incorrect value for c_rc, expected 247.28125, is %f", msg->c_rc);
    fail_unless((msg->ecc*100 - 0.00817864493001*100) < 0.05, "incorrect value for ecc, expected 0.00817864493001, is %f", msg->ecc);
    fail_unless((msg->sqrta*100 - 5153.75399208*100) < 0.05, "incorrect value for sqrta, expected 5153.75399208, is %f", msg->sqrta);
    fail_unless((msg->omegadot*100 - -7.96247452617e-09*100) < 0.05, "incorrect value for omegadot, expected -7.96247452617e-09, is %f", msg->omegadot);
    fail_unless((msg->inc*100 - 0.975512201725*100) < 0.05, "incorrect value for inc, expected 0.975512201725, is %f", msg->inc);
    fail_unless((msg->toe_tow*100 - 410400.0*100) < 0.05, "incorrect value for toe_tow, expected 410400.0, is %f", msg->toe_tow);
    fail_unless((msg->c_uc*100 - -3.72342765331e-06*100) < 0.05, "incorrect value for c_uc, expected -3.72342765331e-06, is %f", msg->c_uc);
    fail_unless(msg->healthy == 1, "incorrect value for healthy, expected 1, is %d", msg->healthy);
    fail_unless(msg->iode == 0, "incorrect value for iode, expected 0, is %d", msg->iode);
    fail_unless((msg->omega0*100 - 2.24186802893*100) < 0.05, "incorrect value for omega0, expected 2.24186802893, is %f", msg->omega0);
    fail_unless((msg->c_us*100 - 7.17863440514e-06*100) < 0.05, "incorrect value for c_us, expected 7.17863440514e-06, is %f", msg->c_us);
    fail_unless(msg->valid == 1, "incorrect value for valid, expected 1, is %d", msg->valid);
    fail_unless((msg->af2*100 - 0.0*100) < 0.05, "incorrect value for af2, expected 0.0, is %f", msg->af2);
    fail_unless((msg->m0*100 - 1.94018234598*100) < 0.05, "incorrect value for m0, expected 1.94018234598, is %f", msg->m0);
    fail_unless((msg->w*100 - -0.523790171609*100) < 0.05, "incorrect value for w, expected -0.523790171609, is %f", msg->w);
    fail_unless((msg->af0*100 - 0.000319611746818*100) < 0.05, "incorrect value for af0, expected 0.000319611746818, is %f", msg->af0);
    fail_unless((msg->af1*100 - -1.02318153949e-12*100) < 0.05, "incorrect value for af1, expected -1.02318153949e-12, is %f", msg->af1);
    fail_unless((msg->toc_tow*100 - 410400.0*100) < 0.05, "incorrect value for toc_tow, expected 410400.0, is %f", msg->toc_tow);
  }
}
END_TEST

Suite* auto_check_sbp_observation_23_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_observation_23");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_observation_23");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_23);
  suite_add_tcase(s, tc_acq);
  return s;
}