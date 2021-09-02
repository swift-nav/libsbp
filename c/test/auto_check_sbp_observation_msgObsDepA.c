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
// spec/tests/yaml/swiftnav/sbp/observation/test_msgObsDepA.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/observation.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static void *DUMMY_MEMORY_FOR_CALLBACKS = (void *)0xdeadbeef;
static void *DUMMY_MEMORY_FOR_IO = (void *)0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return (s32)real_n;
}

static void logging_reset() { memset(&last_msg, 0, sizeof(last_msg)); }

static void msg_callback(u16 sender_id, sbp_msg_type_t msg_type,
                         const sbp_msg_t *msg, void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.msg_type = msg_type;
  last_msg.msg = *msg;
  last_msg.context = context;
}

START_TEST(test_auto_check_sbp_observation_msgObsDepA) {
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
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x45, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  69,  0,   195, 4,   98,  56,  158, 67,  24,  46,  7,   32,  56,
        235, 249, 121, 244, 114, 255, 255, 33,  46,  67,  218, 0,   238, 203,
        70,  124, 22,  25,  3,   0,   98,  43,  184, 157, 2,   176, 133, 197,
        125, 126, 71,  253, 255, 185, 39,  68,  55,  3,   60,  173, 162, 131,
        98,  231, 253, 255, 139, 30,  33,  16,  10,  128, 178, 248, 136, 42,
        113, 253, 255, 40,  20,  42,  71,  13,  246, 246, 17,  135, 255, 51,
        3,   0,   64,  27,  108, 249, 22,  210, 41,  114, 118, 131, 48,  255,
        255, 31,  52,  226, 58,  30,  23,  217,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_a.header.n_obs = 32;

    test_msg.obs_dep_a.header.t.tow = 407084600;

    test_msg.obs_dep_a.header.t.wn = 1838;

    test_msg.obs_dep_a.n_obs = 7;

    test_msg.obs_dep_a.obs[0].L.f = 33;

    test_msg.obs_dep_a.obs[0].L.i = -36108;

    test_msg.obs_dep_a.obs[0].P = 2046421816;

    test_msg.obs_dep_a.obs[0].cn0 = 46;

    test_msg.obs_dep_a.obs[0].lock = 55875;

    test_msg.obs_dep_a.obs[0].prn = 0;

    test_msg.obs_dep_a.obs[1].L.f = 98;

    test_msg.obs_dep_a.obs[1].L.i = 203030;

    test_msg.obs_dep_a.obs[1].P = 2085014510;

    test_msg.obs_dep_a.obs[1].cn0 = 43;

    test_msg.obs_dep_a.obs[1].lock = 40376;

    test_msg.obs_dep_a.obs[1].prn = 2;

    test_msg.obs_dep_a.obs[2].L.f = 185;

    test_msg.obs_dep_a.obs[2].L.i = -178306;

    test_msg.obs_dep_a.obs[2].P = 2110096816;

    test_msg.obs_dep_a.obs[2].cn0 = 39;

    test_msg.obs_dep_a.obs[2].lock = 14148;

    test_msg.obs_dep_a.obs[2].prn = 3;

    test_msg.obs_dep_a.obs[3].L.f = 139;

    test_msg.obs_dep_a.obs[3].L.i = -137374;

    test_msg.obs_dep_a.obs[3].P = 2208476476;

    test_msg.obs_dep_a.obs[3].cn0 = 30;

    test_msg.obs_dep_a.obs[3].lock = 4129;

    test_msg.obs_dep_a.obs[3].prn = 10;

    test_msg.obs_dep_a.obs[4].L.f = 40;

    test_msg.obs_dep_a.obs[4].L.i = -167638;

    test_msg.obs_dep_a.obs[4].P = 2298000000;

    test_msg.obs_dep_a.obs[4].cn0 = 20;

    test_msg.obs_dep_a.obs[4].lock = 18218;

    test_msg.obs_dep_a.obs[4].prn = 13;

    test_msg.obs_dep_a.obs[5].L.f = 64;

    test_msg.obs_dep_a.obs[5].L.i = 209919;

    test_msg.obs_dep_a.obs[5].P = 2266101494;

    test_msg.obs_dep_a.obs[5].cn0 = 27;

    test_msg.obs_dep_a.obs[5].lock = 63852;

    test_msg.obs_dep_a.obs[5].prn = 22;

    test_msg.obs_dep_a.obs[6].L.f = 31;

    test_msg.obs_dep_a.obs[6].L.i = -53117;

    test_msg.obs_dep_a.obs[6].P = 1987193298;

    test_msg.obs_dep_a.obs[6].cn0 = 52;

    test_msg.obs_dep_a.obs[6].lock = 15074;

    test_msg.obs_dep_a.obs[6].prn = 30;

    sbp_message_send(&sbp_state, SbpMsgObsDepA, 1219, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepA, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_a.header.n_obs == 32,
                  "incorrect value for last_msg.msg.obs_dep_a.header.n_obs, "
                  "expected 32, is %d",
                  last_msg.msg.obs_dep_a.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.tow == 407084600,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.tow, "
                  "expected 407084600, is %d",
                  last_msg.msg.obs_dep_a.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.wn == 1838,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.obs_dep_a.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_a.n_obs == 7,
        "incorrect value for last_msg.msg.obs_dep_a.n_obs, expected 7, is %d",
        last_msg.msg.obs_dep_a.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.f == 33,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.f, "
                  "expected 33, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.i == -36108,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.i, "
                  "expected -36108, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].P == 2046421816,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].P, "
                  "expected 2046421816, is %d",
                  last_msg.msg.obs_dep_a.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].cn0 == 46,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].cn0, "
                  "expected 46, is %d",
                  last_msg.msg.obs_dep_a.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].lock == 55875,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].lock, "
                  "expected 55875, is %d",
                  last_msg.msg.obs_dep_a.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].prn == 0,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].prn, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_a.obs[0].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].L.f == 98,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].L.f, "
                  "expected 98, is %d",
                  last_msg.msg.obs_dep_a.obs[1].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].L.i == 203030,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].L.i, "
                  "expected 203030, is %d",
                  last_msg.msg.obs_dep_a.obs[1].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].P == 2085014510,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].P, "
                  "expected 2085014510, is %d",
                  last_msg.msg.obs_dep_a.obs[1].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].cn0 == 43,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].cn0, "
                  "expected 43, is %d",
                  last_msg.msg.obs_dep_a.obs[1].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].lock == 40376,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].lock, "
                  "expected 40376, is %d",
                  last_msg.msg.obs_dep_a.obs[1].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].prn == 2,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].prn, "
                  "expected 2, is %d",
                  last_msg.msg.obs_dep_a.obs[1].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].L.f == 185,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].L.f, "
                  "expected 185, is %d",
                  last_msg.msg.obs_dep_a.obs[2].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].L.i == -178306,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].L.i, "
                  "expected -178306, is %d",
                  last_msg.msg.obs_dep_a.obs[2].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].P == 2110096816,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].P, "
                  "expected 2110096816, is %d",
                  last_msg.msg.obs_dep_a.obs[2].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].cn0 == 39,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].cn0, "
                  "expected 39, is %d",
                  last_msg.msg.obs_dep_a.obs[2].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].lock == 14148,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].lock, "
                  "expected 14148, is %d",
                  last_msg.msg.obs_dep_a.obs[2].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].prn == 3,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].prn, "
                  "expected 3, is %d",
                  last_msg.msg.obs_dep_a.obs[2].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].L.f == 139,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].L.f, "
                  "expected 139, is %d",
                  last_msg.msg.obs_dep_a.obs[3].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].L.i == -137374,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].L.i, "
                  "expected -137374, is %d",
                  last_msg.msg.obs_dep_a.obs[3].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].P == 2208476476,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].P, "
                  "expected 2208476476, is %d",
                  last_msg.msg.obs_dep_a.obs[3].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].cn0 == 30,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].cn0, "
                  "expected 30, is %d",
                  last_msg.msg.obs_dep_a.obs[3].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].lock == 4129,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].lock, "
                  "expected 4129, is %d",
                  last_msg.msg.obs_dep_a.obs[3].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].prn == 10,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].prn, "
                  "expected 10, is %d",
                  last_msg.msg.obs_dep_a.obs[3].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].L.f == 40,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].L.f, "
                  "expected 40, is %d",
                  last_msg.msg.obs_dep_a.obs[4].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].L.i == -167638,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].L.i, "
                  "expected -167638, is %d",
                  last_msg.msg.obs_dep_a.obs[4].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].P == 2298000000,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].P, "
                  "expected 2298000000, is %d",
                  last_msg.msg.obs_dep_a.obs[4].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].cn0 == 20,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].cn0, "
                  "expected 20, is %d",
                  last_msg.msg.obs_dep_a.obs[4].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].lock == 18218,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].lock, "
                  "expected 18218, is %d",
                  last_msg.msg.obs_dep_a.obs[4].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].prn == 13,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].prn, "
                  "expected 13, is %d",
                  last_msg.msg.obs_dep_a.obs[4].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].L.f == 64,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].L.f, "
                  "expected 64, is %d",
                  last_msg.msg.obs_dep_a.obs[5].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].L.i == 209919,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].L.i, "
                  "expected 209919, is %d",
                  last_msg.msg.obs_dep_a.obs[5].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].P == 2266101494,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].P, "
                  "expected 2266101494, is %d",
                  last_msg.msg.obs_dep_a.obs[5].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].cn0 == 27,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].cn0, "
                  "expected 27, is %d",
                  last_msg.msg.obs_dep_a.obs[5].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].lock == 63852,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].lock, "
                  "expected 63852, is %d",
                  last_msg.msg.obs_dep_a.obs[5].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].prn == 22,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].prn, "
                  "expected 22, is %d",
                  last_msg.msg.obs_dep_a.obs[5].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].L.f == 31,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].L.f, "
                  "expected 31, is %d",
                  last_msg.msg.obs_dep_a.obs[6].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].L.i == -53117,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].L.i, "
                  "expected -53117, is %d",
                  last_msg.msg.obs_dep_a.obs[6].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].P == 1987193298,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].P, "
                  "expected 1987193298, is %d",
                  last_msg.msg.obs_dep_a.obs[6].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].cn0 == 52,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].cn0, "
                  "expected 52, is %d",
                  last_msg.msg.obs_dep_a.obs[6].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].lock == 15074,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].lock, "
                  "expected 15074, is %d",
                  last_msg.msg.obs_dep_a.obs[6].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].prn == 30,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].prn, "
                  "expected 30, is %d",
                  last_msg.msg.obs_dep_a.obs[6].prn);
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

    sbp_callback_register(&sbp_state, 0x45, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 69,  0,   195, 4,  20, 56, 158, 67, 24, 46,  7,  33,  84,
        52, 164, 117, 102, 32, 0,  0,  147, 62, 62, 250, 31, 234, 14,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_a.header.n_obs = 33;

    test_msg.obs_dep_a.header.t.tow = 407084600;

    test_msg.obs_dep_a.header.t.wn = 1838;

    test_msg.obs_dep_a.n_obs = 1;

    test_msg.obs_dep_a.obs[0].L.f = 147;

    test_msg.obs_dep_a.obs[0].L.i = 8294;

    test_msg.obs_dep_a.obs[0].P = 1973695572;

    test_msg.obs_dep_a.obs[0].cn0 = 62;

    test_msg.obs_dep_a.obs[0].lock = 64062;

    test_msg.obs_dep_a.obs[0].prn = 31;

    sbp_message_send(&sbp_state, SbpMsgObsDepA, 1219, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepA, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_a.header.n_obs == 33,
                  "incorrect value for last_msg.msg.obs_dep_a.header.n_obs, "
                  "expected 33, is %d",
                  last_msg.msg.obs_dep_a.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.tow == 407084600,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.tow, "
                  "expected 407084600, is %d",
                  last_msg.msg.obs_dep_a.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.wn == 1838,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.obs_dep_a.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_a.n_obs == 1,
        "incorrect value for last_msg.msg.obs_dep_a.n_obs, expected 1, is %d",
        last_msg.msg.obs_dep_a.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.f == 147,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.f, "
                  "expected 147, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.i == 8294,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.i, "
                  "expected 8294, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].P == 1973695572,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].P, "
                  "expected 1973695572, is %d",
                  last_msg.msg.obs_dep_a.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].cn0 == 62,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].cn0, "
                  "expected 62, is %d",
                  last_msg.msg.obs_dep_a.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].lock == 64062,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].lock, "
                  "expected 64062, is %d",
                  last_msg.msg.obs_dep_a.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].prn == 31,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].prn, "
                  "expected 31, is %d",
                  last_msg.msg.obs_dep_a.obs[0].prn);
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

    sbp_callback_register(&sbp_state, 0x45, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  69,  0,   195, 4,   98,  0,   159, 67,  24,  46,  7,   32,  32,
        209, 249, 121, 145, 114, 255, 255, 141, 45,  67,  218, 0,   177, 128,
        70,  124, 79,  27,  3,   0,   159, 44,  184, 157, 2,   59,  135, 197,
        125, 175, 69,  253, 255, 77,  40,  68,  55,  3,   211, 172, 162, 131,
        177, 229, 253, 255, 20,  31,  33,  16,  10,  128, 178, 248, 136, 116,
        111, 253, 255, 94,  21,  42,  71,  13,  182, 173, 17,  135, 37,  54,
        3,   0,   214, 27,  108, 249, 22,  91,  20,  114, 118, 240, 47,  255,
        255, 129, 52,  226, 58,  30,  200, 119,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_a.header.n_obs = 32;

    test_msg.obs_dep_a.header.t.tow = 407084800;

    test_msg.obs_dep_a.header.t.wn = 1838;

    test_msg.obs_dep_a.n_obs = 7;

    test_msg.obs_dep_a.obs[0].L.f = 141;

    test_msg.obs_dep_a.obs[0].L.i = -36207;

    test_msg.obs_dep_a.obs[0].P = 2046415136;

    test_msg.obs_dep_a.obs[0].cn0 = 45;

    test_msg.obs_dep_a.obs[0].lock = 55875;

    test_msg.obs_dep_a.obs[0].prn = 0;

    test_msg.obs_dep_a.obs[1].L.f = 159;

    test_msg.obs_dep_a.obs[1].L.i = 203599;

    test_msg.obs_dep_a.obs[1].P = 2084995249;

    test_msg.obs_dep_a.obs[1].cn0 = 44;

    test_msg.obs_dep_a.obs[1].lock = 40376;

    test_msg.obs_dep_a.obs[1].prn = 2;

    test_msg.obs_dep_a.obs[2].L.f = 77;

    test_msg.obs_dep_a.obs[2].L.i = -178769;

    test_msg.obs_dep_a.obs[2].P = 2110097211;

    test_msg.obs_dep_a.obs[2].cn0 = 40;

    test_msg.obs_dep_a.obs[2].lock = 14148;

    test_msg.obs_dep_a.obs[2].prn = 3;

    test_msg.obs_dep_a.obs[3].L.f = 20;

    test_msg.obs_dep_a.obs[3].L.i = -137807;

    test_msg.obs_dep_a.obs[3].P = 2208476371;

    test_msg.obs_dep_a.obs[3].cn0 = 31;

    test_msg.obs_dep_a.obs[3].lock = 4129;

    test_msg.obs_dep_a.obs[3].prn = 10;

    test_msg.obs_dep_a.obs[4].L.f = 94;

    test_msg.obs_dep_a.obs[4].L.i = -168076;

    test_msg.obs_dep_a.obs[4].P = 2298000000;

    test_msg.obs_dep_a.obs[4].cn0 = 21;

    test_msg.obs_dep_a.obs[4].lock = 18218;

    test_msg.obs_dep_a.obs[4].prn = 13;

    test_msg.obs_dep_a.obs[5].L.f = 214;

    test_msg.obs_dep_a.obs[5].L.i = 210469;

    test_msg.obs_dep_a.obs[5].P = 2266082742;

    test_msg.obs_dep_a.obs[5].cn0 = 27;

    test_msg.obs_dep_a.obs[5].lock = 63852;

    test_msg.obs_dep_a.obs[5].prn = 22;

    test_msg.obs_dep_a.obs[6].L.f = 129;

    test_msg.obs_dep_a.obs[6].L.i = -53264;

    test_msg.obs_dep_a.obs[6].P = 1987187803;

    test_msg.obs_dep_a.obs[6].cn0 = 52;

    test_msg.obs_dep_a.obs[6].lock = 15074;

    test_msg.obs_dep_a.obs[6].prn = 30;

    sbp_message_send(&sbp_state, SbpMsgObsDepA, 1219, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepA, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_a.header.n_obs == 32,
                  "incorrect value for last_msg.msg.obs_dep_a.header.n_obs, "
                  "expected 32, is %d",
                  last_msg.msg.obs_dep_a.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.tow == 407084800,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.tow, "
                  "expected 407084800, is %d",
                  last_msg.msg.obs_dep_a.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.wn == 1838,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.obs_dep_a.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_a.n_obs == 7,
        "incorrect value for last_msg.msg.obs_dep_a.n_obs, expected 7, is %d",
        last_msg.msg.obs_dep_a.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.f == 141,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.f, "
                  "expected 141, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.i == -36207,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.i, "
                  "expected -36207, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].P == 2046415136,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].P, "
                  "expected 2046415136, is %d",
                  last_msg.msg.obs_dep_a.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].cn0 == 45,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].cn0, "
                  "expected 45, is %d",
                  last_msg.msg.obs_dep_a.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].lock == 55875,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].lock, "
                  "expected 55875, is %d",
                  last_msg.msg.obs_dep_a.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].prn == 0,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].prn, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_a.obs[0].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].L.f == 159,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].L.f, "
                  "expected 159, is %d",
                  last_msg.msg.obs_dep_a.obs[1].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].L.i == 203599,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].L.i, "
                  "expected 203599, is %d",
                  last_msg.msg.obs_dep_a.obs[1].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].P == 2084995249,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].P, "
                  "expected 2084995249, is %d",
                  last_msg.msg.obs_dep_a.obs[1].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].cn0 == 44,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].cn0, "
                  "expected 44, is %d",
                  last_msg.msg.obs_dep_a.obs[1].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].lock == 40376,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].lock, "
                  "expected 40376, is %d",
                  last_msg.msg.obs_dep_a.obs[1].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].prn == 2,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].prn, "
                  "expected 2, is %d",
                  last_msg.msg.obs_dep_a.obs[1].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].L.f == 77,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].L.f, "
                  "expected 77, is %d",
                  last_msg.msg.obs_dep_a.obs[2].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].L.i == -178769,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].L.i, "
                  "expected -178769, is %d",
                  last_msg.msg.obs_dep_a.obs[2].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].P == 2110097211,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].P, "
                  "expected 2110097211, is %d",
                  last_msg.msg.obs_dep_a.obs[2].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].cn0 == 40,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].cn0, "
                  "expected 40, is %d",
                  last_msg.msg.obs_dep_a.obs[2].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].lock == 14148,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].lock, "
                  "expected 14148, is %d",
                  last_msg.msg.obs_dep_a.obs[2].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].prn == 3,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].prn, "
                  "expected 3, is %d",
                  last_msg.msg.obs_dep_a.obs[2].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].L.f == 20,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].L.f, "
                  "expected 20, is %d",
                  last_msg.msg.obs_dep_a.obs[3].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].L.i == -137807,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].L.i, "
                  "expected -137807, is %d",
                  last_msg.msg.obs_dep_a.obs[3].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].P == 2208476371,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].P, "
                  "expected 2208476371, is %d",
                  last_msg.msg.obs_dep_a.obs[3].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].cn0 == 31,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].cn0, "
                  "expected 31, is %d",
                  last_msg.msg.obs_dep_a.obs[3].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].lock == 4129,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].lock, "
                  "expected 4129, is %d",
                  last_msg.msg.obs_dep_a.obs[3].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].prn == 10,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].prn, "
                  "expected 10, is %d",
                  last_msg.msg.obs_dep_a.obs[3].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].L.f == 94,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].L.f, "
                  "expected 94, is %d",
                  last_msg.msg.obs_dep_a.obs[4].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].L.i == -168076,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].L.i, "
                  "expected -168076, is %d",
                  last_msg.msg.obs_dep_a.obs[4].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].P == 2298000000,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].P, "
                  "expected 2298000000, is %d",
                  last_msg.msg.obs_dep_a.obs[4].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].cn0 == 21,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].cn0, "
                  "expected 21, is %d",
                  last_msg.msg.obs_dep_a.obs[4].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].lock == 18218,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].lock, "
                  "expected 18218, is %d",
                  last_msg.msg.obs_dep_a.obs[4].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].prn == 13,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].prn, "
                  "expected 13, is %d",
                  last_msg.msg.obs_dep_a.obs[4].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].L.f == 214,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].L.f, "
                  "expected 214, is %d",
                  last_msg.msg.obs_dep_a.obs[5].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].L.i == 210469,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].L.i, "
                  "expected 210469, is %d",
                  last_msg.msg.obs_dep_a.obs[5].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].P == 2266082742,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].P, "
                  "expected 2266082742, is %d",
                  last_msg.msg.obs_dep_a.obs[5].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].cn0 == 27,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].cn0, "
                  "expected 27, is %d",
                  last_msg.msg.obs_dep_a.obs[5].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].lock == 63852,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].lock, "
                  "expected 63852, is %d",
                  last_msg.msg.obs_dep_a.obs[5].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[5].prn == 22,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[5].prn, "
                  "expected 22, is %d",
                  last_msg.msg.obs_dep_a.obs[5].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].L.f == 129,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].L.f, "
                  "expected 129, is %d",
                  last_msg.msg.obs_dep_a.obs[6].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].L.i == -53264,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].L.i, "
                  "expected -53264, is %d",
                  last_msg.msg.obs_dep_a.obs[6].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].P == 1987187803,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].P, "
                  "expected 1987187803, is %d",
                  last_msg.msg.obs_dep_a.obs[6].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].cn0 == 52,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].cn0, "
                  "expected 52, is %d",
                  last_msg.msg.obs_dep_a.obs[6].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].lock == 15074,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].lock, "
                  "expected 15074, is %d",
                  last_msg.msg.obs_dep_a.obs[6].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[6].prn == 30,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[6].prn, "
                  "expected 30, is %d",
                  last_msg.msg.obs_dep_a.obs[6].prn);
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

    sbp_callback_register(&sbp_state, 0x45, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 69,  0,   195, 4,  20, 0, 159, 67, 24, 46,  7,  33, 49,
        19, 164, 117, 120, 32, 0,  0, 222, 63, 62, 250, 31, 11, 231,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_a.header.n_obs = 33;

    test_msg.obs_dep_a.header.t.tow = 407084800;

    test_msg.obs_dep_a.header.t.wn = 1838;

    test_msg.obs_dep_a.n_obs = 1;

    test_msg.obs_dep_a.obs[0].L.f = 222;

    test_msg.obs_dep_a.obs[0].L.i = 8312;

    test_msg.obs_dep_a.obs[0].P = 1973687089;

    test_msg.obs_dep_a.obs[0].cn0 = 63;

    test_msg.obs_dep_a.obs[0].lock = 64062;

    test_msg.obs_dep_a.obs[0].prn = 31;

    sbp_message_send(&sbp_state, SbpMsgObsDepA, 1219, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepA, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_a.header.n_obs == 33,
                  "incorrect value for last_msg.msg.obs_dep_a.header.n_obs, "
                  "expected 33, is %d",
                  last_msg.msg.obs_dep_a.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.tow == 407084800,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.tow, "
                  "expected 407084800, is %d",
                  last_msg.msg.obs_dep_a.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.wn == 1838,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.obs_dep_a.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_a.n_obs == 1,
        "incorrect value for last_msg.msg.obs_dep_a.n_obs, expected 1, is %d",
        last_msg.msg.obs_dep_a.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.f == 222,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.f, "
                  "expected 222, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.i == 8312,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.i, "
                  "expected 8312, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].P == 1973687089,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].P, "
                  "expected 1973687089, is %d",
                  last_msg.msg.obs_dep_a.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].cn0 == 63,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].cn0, "
                  "expected 63, is %d",
                  last_msg.msg.obs_dep_a.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].lock == 64062,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].lock, "
                  "expected 64062, is %d",
                  last_msg.msg.obs_dep_a.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].prn == 31,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].prn, "
                  "expected 31, is %d",
                  last_msg.msg.obs_dep_a.obs[0].prn);
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

    sbp_callback_register(&sbp_state, 0x45, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  69,  0,   195, 4,   72,  96,  162, 68,  24,  46,  7,   16,  87,
        132, 217, 121, 121, 148, 255, 255, 189, 43,  175, 147, 0,   132, 64,
        200, 125, 106, 31,  254, 255, 1,   41,  14,  177, 3,   128, 178, 248,
        136, 70,  68,  254, 255, 166, 18,  184, 133, 13,  24,  127, 178, 134,
        6,   25,  2,   0,   249, 28,  33,  96,  22,  170, 104, 86,  118, 67,
        112, 255, 255, 203, 56,  208, 88,  30,  43,  107,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_a.header.n_obs = 16;

    test_msg.obs_dep_a.header.t.tow = 407151200;

    test_msg.obs_dep_a.header.t.wn = 1838;

    test_msg.obs_dep_a.n_obs = 5;

    test_msg.obs_dep_a.obs[0].L.f = 189;

    test_msg.obs_dep_a.obs[0].L.i = -27527;

    test_msg.obs_dep_a.obs[0].P = 2044298327;

    test_msg.obs_dep_a.obs[0].cn0 = 43;

    test_msg.obs_dep_a.obs[0].lock = 37807;

    test_msg.obs_dep_a.obs[0].prn = 0;

    test_msg.obs_dep_a.obs[1].L.f = 1;

    test_msg.obs_dep_a.obs[1].L.i = -123030;

    test_msg.obs_dep_a.obs[1].P = 2110275716;

    test_msg.obs_dep_a.obs[1].cn0 = 41;

    test_msg.obs_dep_a.obs[1].lock = 45326;

    test_msg.obs_dep_a.obs[1].prn = 3;

    test_msg.obs_dep_a.obs[2].L.f = 166;

    test_msg.obs_dep_a.obs[2].L.i = -113594;

    test_msg.obs_dep_a.obs[2].P = 2298000000;

    test_msg.obs_dep_a.obs[2].cn0 = 18;

    test_msg.obs_dep_a.obs[2].lock = 34232;

    test_msg.obs_dep_a.obs[2].prn = 13;

    test_msg.obs_dep_a.obs[3].L.f = 249;

    test_msg.obs_dep_a.obs[3].L.i = 137478;

    test_msg.obs_dep_a.obs[3].P = 2259844888;

    test_msg.obs_dep_a.obs[3].cn0 = 28;

    test_msg.obs_dep_a.obs[3].lock = 24609;

    test_msg.obs_dep_a.obs[3].prn = 22;

    test_msg.obs_dep_a.obs[4].L.f = 203;

    test_msg.obs_dep_a.obs[4].L.i = -36797;

    test_msg.obs_dep_a.obs[4].P = 1985374378;

    test_msg.obs_dep_a.obs[4].cn0 = 56;

    test_msg.obs_dep_a.obs[4].lock = 22736;

    test_msg.obs_dep_a.obs[4].prn = 30;

    sbp_message_send(&sbp_state, SbpMsgObsDepA, 1219, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepA, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_a.header.n_obs == 16,
                  "incorrect value for last_msg.msg.obs_dep_a.header.n_obs, "
                  "expected 16, is %d",
                  last_msg.msg.obs_dep_a.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.tow == 407151200,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.tow, "
                  "expected 407151200, is %d",
                  last_msg.msg.obs_dep_a.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.wn == 1838,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.obs_dep_a.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_a.n_obs == 5,
        "incorrect value for last_msg.msg.obs_dep_a.n_obs, expected 5, is %d",
        last_msg.msg.obs_dep_a.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.f == 189,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.f, "
                  "expected 189, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.i == -27527,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.i, "
                  "expected -27527, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].P == 2044298327,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].P, "
                  "expected 2044298327, is %d",
                  last_msg.msg.obs_dep_a.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].cn0 == 43,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].cn0, "
                  "expected 43, is %d",
                  last_msg.msg.obs_dep_a.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].lock == 37807,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].lock, "
                  "expected 37807, is %d",
                  last_msg.msg.obs_dep_a.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].prn == 0,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].prn, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_a.obs[0].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].L.f == 1,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].L.f, "
                  "expected 1, is %d",
                  last_msg.msg.obs_dep_a.obs[1].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].L.i == -123030,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].L.i, "
                  "expected -123030, is %d",
                  last_msg.msg.obs_dep_a.obs[1].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].P == 2110275716,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].P, "
                  "expected 2110275716, is %d",
                  last_msg.msg.obs_dep_a.obs[1].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].cn0 == 41,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].cn0, "
                  "expected 41, is %d",
                  last_msg.msg.obs_dep_a.obs[1].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].lock == 45326,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].lock, "
                  "expected 45326, is %d",
                  last_msg.msg.obs_dep_a.obs[1].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].prn == 3,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].prn, "
                  "expected 3, is %d",
                  last_msg.msg.obs_dep_a.obs[1].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].L.f == 166,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].L.f, "
                  "expected 166, is %d",
                  last_msg.msg.obs_dep_a.obs[2].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].L.i == -113594,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].L.i, "
                  "expected -113594, is %d",
                  last_msg.msg.obs_dep_a.obs[2].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].P == 2298000000,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].P, "
                  "expected 2298000000, is %d",
                  last_msg.msg.obs_dep_a.obs[2].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].cn0 == 18,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].cn0, "
                  "expected 18, is %d",
                  last_msg.msg.obs_dep_a.obs[2].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].lock == 34232,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].lock, "
                  "expected 34232, is %d",
                  last_msg.msg.obs_dep_a.obs[2].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].prn == 13,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].prn, "
                  "expected 13, is %d",
                  last_msg.msg.obs_dep_a.obs[2].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].L.f == 249,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].L.f, "
                  "expected 249, is %d",
                  last_msg.msg.obs_dep_a.obs[3].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].L.i == 137478,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].L.i, "
                  "expected 137478, is %d",
                  last_msg.msg.obs_dep_a.obs[3].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].P == 2259844888,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].P, "
                  "expected 2259844888, is %d",
                  last_msg.msg.obs_dep_a.obs[3].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].cn0 == 28,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].cn0, "
                  "expected 28, is %d",
                  last_msg.msg.obs_dep_a.obs[3].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].lock == 24609,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].lock, "
                  "expected 24609, is %d",
                  last_msg.msg.obs_dep_a.obs[3].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].prn == 22,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].prn, "
                  "expected 22, is %d",
                  last_msg.msg.obs_dep_a.obs[3].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].L.f == 203,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].L.f, "
                  "expected 203, is %d",
                  last_msg.msg.obs_dep_a.obs[4].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].L.i == -36797,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].L.i, "
                  "expected -36797, is %d",
                  last_msg.msg.obs_dep_a.obs[4].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].P == 1985374378,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].P, "
                  "expected 1985374378, is %d",
                  last_msg.msg.obs_dep_a.obs[4].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].cn0 == 56,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].cn0, "
                  "expected 56, is %d",
                  last_msg.msg.obs_dep_a.obs[4].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].lock == 22736,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].lock, "
                  "expected 22736, is %d",
                  last_msg.msg.obs_dep_a.obs[4].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].prn == 30,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].prn, "
                  "expected 30, is %d",
                  last_msg.msg.obs_dep_a.obs[4].prn);
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

    sbp_callback_register(&sbp_state, 0x45, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  69,  0,   195, 4,   72,  40,  163, 68,  24,  46,  7,   16,  132,
        107, 217, 121, 14,  148, 255, 255, 1,   44,  175, 147, 0,   129, 66,
        200, 125, 148, 29,  254, 255, 153, 41,  14,  177, 3,   128, 178, 248,
        136, 143, 66,  254, 255, 222, 18,  184, 133, 13,  158, 53,  178, 134,
        42,  27,  2,   0,   237, 30,  33,  96,  22,  38,  83,  86,  118, 168,
        111, 255, 255, 45,  56,  208, 88,  30,  1,   175,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_a.header.n_obs = 16;

    test_msg.obs_dep_a.header.t.tow = 407151400;

    test_msg.obs_dep_a.header.t.wn = 1838;

    test_msg.obs_dep_a.n_obs = 5;

    test_msg.obs_dep_a.obs[0].L.f = 1;

    test_msg.obs_dep_a.obs[0].L.i = -27634;

    test_msg.obs_dep_a.obs[0].P = 2044291972;

    test_msg.obs_dep_a.obs[0].cn0 = 44;

    test_msg.obs_dep_a.obs[0].lock = 37807;

    test_msg.obs_dep_a.obs[0].prn = 0;

    test_msg.obs_dep_a.obs[1].L.f = 153;

    test_msg.obs_dep_a.obs[1].L.i = -123500;

    test_msg.obs_dep_a.obs[1].P = 2110276225;

    test_msg.obs_dep_a.obs[1].cn0 = 41;

    test_msg.obs_dep_a.obs[1].lock = 45326;

    test_msg.obs_dep_a.obs[1].prn = 3;

    test_msg.obs_dep_a.obs[2].L.f = 222;

    test_msg.obs_dep_a.obs[2].L.i = -114033;

    test_msg.obs_dep_a.obs[2].P = 2298000000;

    test_msg.obs_dep_a.obs[2].cn0 = 18;

    test_msg.obs_dep_a.obs[2].lock = 34232;

    test_msg.obs_dep_a.obs[2].prn = 13;

    test_msg.obs_dep_a.obs[3].L.f = 237;

    test_msg.obs_dep_a.obs[3].L.i = 138026;

    test_msg.obs_dep_a.obs[3].P = 2259826078;

    test_msg.obs_dep_a.obs[3].cn0 = 30;

    test_msg.obs_dep_a.obs[3].lock = 24609;

    test_msg.obs_dep_a.obs[3].prn = 22;

    test_msg.obs_dep_a.obs[4].L.f = 45;

    test_msg.obs_dep_a.obs[4].L.i = -36952;

    test_msg.obs_dep_a.obs[4].P = 1985368870;

    test_msg.obs_dep_a.obs[4].cn0 = 56;

    test_msg.obs_dep_a.obs[4].lock = 22736;

    test_msg.obs_dep_a.obs[4].prn = 30;

    sbp_message_send(&sbp_state, SbpMsgObsDepA, 1219, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepA, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_a.header.n_obs == 16,
                  "incorrect value for last_msg.msg.obs_dep_a.header.n_obs, "
                  "expected 16, is %d",
                  last_msg.msg.obs_dep_a.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.tow == 407151400,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.tow, "
                  "expected 407151400, is %d",
                  last_msg.msg.obs_dep_a.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_a.header.t.wn == 1838,
                  "incorrect value for last_msg.msg.obs_dep_a.header.t.wn, "
                  "expected 1838, is %d",
                  last_msg.msg.obs_dep_a.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_a.n_obs == 5,
        "incorrect value for last_msg.msg.obs_dep_a.n_obs, expected 5, is %d",
        last_msg.msg.obs_dep_a.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.f == 1,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.f, "
                  "expected 1, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].L.i == -27634,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].L.i, "
                  "expected -27634, is %d",
                  last_msg.msg.obs_dep_a.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].P == 2044291972,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].P, "
                  "expected 2044291972, is %d",
                  last_msg.msg.obs_dep_a.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].cn0 == 44,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].cn0, "
                  "expected 44, is %d",
                  last_msg.msg.obs_dep_a.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].lock == 37807,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].lock, "
                  "expected 37807, is %d",
                  last_msg.msg.obs_dep_a.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[0].prn == 0,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[0].prn, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_a.obs[0].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].L.f == 153,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].L.f, "
                  "expected 153, is %d",
                  last_msg.msg.obs_dep_a.obs[1].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].L.i == -123500,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].L.i, "
                  "expected -123500, is %d",
                  last_msg.msg.obs_dep_a.obs[1].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].P == 2110276225,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].P, "
                  "expected 2110276225, is %d",
                  last_msg.msg.obs_dep_a.obs[1].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].cn0 == 41,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].cn0, "
                  "expected 41, is %d",
                  last_msg.msg.obs_dep_a.obs[1].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].lock == 45326,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].lock, "
                  "expected 45326, is %d",
                  last_msg.msg.obs_dep_a.obs[1].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[1].prn == 3,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[1].prn, "
                  "expected 3, is %d",
                  last_msg.msg.obs_dep_a.obs[1].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].L.f == 222,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].L.f, "
                  "expected 222, is %d",
                  last_msg.msg.obs_dep_a.obs[2].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].L.i == -114033,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].L.i, "
                  "expected -114033, is %d",
                  last_msg.msg.obs_dep_a.obs[2].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].P == 2298000000,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].P, "
                  "expected 2298000000, is %d",
                  last_msg.msg.obs_dep_a.obs[2].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].cn0 == 18,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].cn0, "
                  "expected 18, is %d",
                  last_msg.msg.obs_dep_a.obs[2].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].lock == 34232,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].lock, "
                  "expected 34232, is %d",
                  last_msg.msg.obs_dep_a.obs[2].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[2].prn == 13,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[2].prn, "
                  "expected 13, is %d",
                  last_msg.msg.obs_dep_a.obs[2].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].L.f == 237,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].L.f, "
                  "expected 237, is %d",
                  last_msg.msg.obs_dep_a.obs[3].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].L.i == 138026,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].L.i, "
                  "expected 138026, is %d",
                  last_msg.msg.obs_dep_a.obs[3].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].P == 2259826078,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].P, "
                  "expected 2259826078, is %d",
                  last_msg.msg.obs_dep_a.obs[3].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].cn0 == 30,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].cn0, "
                  "expected 30, is %d",
                  last_msg.msg.obs_dep_a.obs[3].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].lock == 24609,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].lock, "
                  "expected 24609, is %d",
                  last_msg.msg.obs_dep_a.obs[3].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[3].prn == 22,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[3].prn, "
                  "expected 22, is %d",
                  last_msg.msg.obs_dep_a.obs[3].prn);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].L.f == 45,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].L.f, "
                  "expected 45, is %d",
                  last_msg.msg.obs_dep_a.obs[4].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].L.i == -36952,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].L.i, "
                  "expected -36952, is %d",
                  last_msg.msg.obs_dep_a.obs[4].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].P == 1985368870,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].P, "
                  "expected 1985368870, is %d",
                  last_msg.msg.obs_dep_a.obs[4].P);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].cn0 == 56,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].cn0, "
                  "expected 56, is %d",
                  last_msg.msg.obs_dep_a.obs[4].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].lock == 22736,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].lock, "
                  "expected 22736, is %d",
                  last_msg.msg.obs_dep_a.obs[4].lock);

    ck_assert_msg(last_msg.msg.obs_dep_a.obs[4].prn == 30,
                  "incorrect value for last_msg.msg.obs_dep_a.obs[4].prn, "
                  "expected 30, is %d",
                  last_msg.msg.obs_dep_a.obs[4].prn);
  }
}
END_TEST

Suite *auto_check_sbp_observation_msgObsDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_msgObsDepA");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_observation_msgObsDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_msgObsDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}