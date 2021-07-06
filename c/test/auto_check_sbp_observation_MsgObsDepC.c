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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepC.yaml by generate.py.
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

START_TEST(test_auto_check_sbp_observation_MsgObsDepC) {
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

    sbp_callback_register(&sbp_state, 0x49, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  73,  0,   70,  152, 87,  8,   95,  183, 24,  106, 7,   32,  126,
        250, 73,  80,  113, 94,  247, 255, 231, 163, 229, 229, 4,   0,   0,
        0,   60,  220, 96,  70,  81,  147, 250, 255, 196, 208, 20,  28,  6,
        0,   0,   0,   248, 61,  62,  77,  28,  60,  242, 255, 110, 171, 180,
        178, 7,   0,   0,   0,   237, 84,  190, 77,  172, 37,  13,  0,   41,
        170, 233, 164, 10,  0,   0,   0,   36,  85,  9,   75,  240, 188, 21,
        0,   19,  182, 196, 209, 12,  0,   0,   0,   190, 175,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_c.header.n_obs = 32;

    test_msg.obs_dep_c.header.t.tow = 414670600;

    test_msg.obs_dep_c.header.t.wn = 1898;

    test_msg.obs_dep_c.n_obs = 5;

    test_msg.obs_dep_c.obs[0].L.f = 231;

    test_msg.obs_dep_c.obs[0].L.i = -565647;

    test_msg.obs_dep_c.obs[0].P = 1347025534;

    test_msg.obs_dep_c.obs[0].cn0 = 163;

    test_msg.obs_dep_c.obs[0].lock = 58853;

    test_msg.obs_dep_c.obs[0].sid.code = 0;

    test_msg.obs_dep_c.obs[0].sid.reserved = 0;

    test_msg.obs_dep_c.obs[0].sid.sat = 4;

    test_msg.obs_dep_c.obs[1].L.f = 196;

    test_msg.obs_dep_c.obs[1].L.i = -355503;

    test_msg.obs_dep_c.obs[1].P = 1180752956;

    test_msg.obs_dep_c.obs[1].cn0 = 208;

    test_msg.obs_dep_c.obs[1].lock = 7188;

    test_msg.obs_dep_c.obs[1].sid.code = 0;

    test_msg.obs_dep_c.obs[1].sid.reserved = 0;

    test_msg.obs_dep_c.obs[1].sid.sat = 6;

    test_msg.obs_dep_c.obs[2].L.f = 110;

    test_msg.obs_dep_c.obs[2].L.i = -902116;

    test_msg.obs_dep_c.obs[2].P = 1295924728;

    test_msg.obs_dep_c.obs[2].cn0 = 171;

    test_msg.obs_dep_c.obs[2].lock = 45748;

    test_msg.obs_dep_c.obs[2].sid.code = 0;

    test_msg.obs_dep_c.obs[2].sid.reserved = 0;

    test_msg.obs_dep_c.obs[2].sid.sat = 7;

    test_msg.obs_dep_c.obs[3].L.f = 41;

    test_msg.obs_dep_c.obs[3].L.i = 861612;

    test_msg.obs_dep_c.obs[3].P = 1304319213;

    test_msg.obs_dep_c.obs[3].cn0 = 170;

    test_msg.obs_dep_c.obs[3].lock = 42217;

    test_msg.obs_dep_c.obs[3].sid.code = 0;

    test_msg.obs_dep_c.obs[3].sid.reserved = 0;

    test_msg.obs_dep_c.obs[3].sid.sat = 10;

    test_msg.obs_dep_c.obs[4].L.f = 19;

    test_msg.obs_dep_c.obs[4].L.i = 1424624;

    test_msg.obs_dep_c.obs[4].P = 1258902820;

    test_msg.obs_dep_c.obs[4].cn0 = 182;

    test_msg.obs_dep_c.obs[4].lock = 53700;

    test_msg.obs_dep_c.obs[4].sid.code = 0;

    test_msg.obs_dep_c.obs[4].sid.reserved = 0;

    test_msg.obs_dep_c.obs[4].sid.sat = 12;

    sbp_message_send(&sbp_state, SbpMsgObsDepC, 38982, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 38982,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepC, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_c.header.n_obs == 32,
                  "incorrect value for last_msg.msg.obs_dep_c.header.n_obs, "
                  "expected 32, is %d",
                  last_msg.msg.obs_dep_c.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_c.header.t.tow == 414670600,
                  "incorrect value for last_msg.msg.obs_dep_c.header.t.tow, "
                  "expected 414670600, is %d",
                  last_msg.msg.obs_dep_c.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_c.header.t.wn == 1898,
                  "incorrect value for last_msg.msg.obs_dep_c.header.t.wn, "
                  "expected 1898, is %d",
                  last_msg.msg.obs_dep_c.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.n_obs == 5,
        "incorrect value for last_msg.msg.obs_dep_c.n_obs, expected 5, is %d",
        last_msg.msg.obs_dep_c.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].L.f == 231,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].L.f, "
                  "expected 231, is %d",
                  last_msg.msg.obs_dep_c.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].L.i == -565647,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].L.i, "
                  "expected -565647, is %d",
                  last_msg.msg.obs_dep_c.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].P == 1347025534,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].P, "
                  "expected 1347025534, is %d",
                  last_msg.msg.obs_dep_c.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].cn0 == 163,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].cn0, "
                  "expected 163, is %d",
                  last_msg.msg.obs_dep_c.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].lock == 58853,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].lock, "
                  "expected 58853, is %d",
                  last_msg.msg.obs_dep_c.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[0].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[0].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[0].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].sid.sat == 4,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.sat, "
                  "expected 4, is %d",
                  last_msg.msg.obs_dep_c.obs[0].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].L.f == 196,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].L.f, "
                  "expected 196, is %d",
                  last_msg.msg.obs_dep_c.obs[1].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].L.i == -355503,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].L.i, "
                  "expected -355503, is %d",
                  last_msg.msg.obs_dep_c.obs[1].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].P == 1180752956,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].P, "
                  "expected 1180752956, is %d",
                  last_msg.msg.obs_dep_c.obs[1].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].cn0 == 208,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].cn0, "
                  "expected 208, is %d",
                  last_msg.msg.obs_dep_c.obs[1].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].lock == 7188,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].lock, "
                  "expected 7188, is %d",
                  last_msg.msg.obs_dep_c.obs[1].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[1].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[1].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[1].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].sid.sat == 6,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.sat, "
                  "expected 6, is %d",
                  last_msg.msg.obs_dep_c.obs[1].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].L.f == 110,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].L.f, "
                  "expected 110, is %d",
                  last_msg.msg.obs_dep_c.obs[2].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].L.i == -902116,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].L.i, "
                  "expected -902116, is %d",
                  last_msg.msg.obs_dep_c.obs[2].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].P == 1295924728,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].P, "
                  "expected 1295924728, is %d",
                  last_msg.msg.obs_dep_c.obs[2].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].cn0 == 171,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].cn0, "
                  "expected 171, is %d",
                  last_msg.msg.obs_dep_c.obs[2].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].lock == 45748,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].lock, "
                  "expected 45748, is %d",
                  last_msg.msg.obs_dep_c.obs[2].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[2].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[2].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[2].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].sid.sat == 7,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.sat, "
                  "expected 7, is %d",
                  last_msg.msg.obs_dep_c.obs[2].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].L.f == 41,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].L.f, "
                  "expected 41, is %d",
                  last_msg.msg.obs_dep_c.obs[3].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].L.i == 861612,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].L.i, "
                  "expected 861612, is %d",
                  last_msg.msg.obs_dep_c.obs[3].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].P == 1304319213,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].P, "
                  "expected 1304319213, is %d",
                  last_msg.msg.obs_dep_c.obs[3].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].cn0 == 170,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].cn0, "
                  "expected 170, is %d",
                  last_msg.msg.obs_dep_c.obs[3].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].lock == 42217,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].lock, "
                  "expected 42217, is %d",
                  last_msg.msg.obs_dep_c.obs[3].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[3].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[3].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[3].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[3].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].sid.sat == 10,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].sid.sat, "
                  "expected 10, is %d",
                  last_msg.msg.obs_dep_c.obs[3].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].L.f == 19,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].L.f, "
                  "expected 19, is %d",
                  last_msg.msg.obs_dep_c.obs[4].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].L.i == 1424624,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].L.i, "
                  "expected 1424624, is %d",
                  last_msg.msg.obs_dep_c.obs[4].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].P == 1258902820,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].P, "
                  "expected 1258902820, is %d",
                  last_msg.msg.obs_dep_c.obs[4].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].cn0 == 182,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].cn0, "
                  "expected 182, is %d",
                  last_msg.msg.obs_dep_c.obs[4].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].lock == 53700,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].lock, "
                  "expected 53700, is %d",
                  last_msg.msg.obs_dep_c.obs[4].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[4].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[4].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[4].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[4].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].sid.sat == 12,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].sid.sat, "
                  "expected 12, is %d",
                  last_msg.msg.obs_dep_c.obs[4].sid.sat);
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

    sbp_callback_register(&sbp_state, 0x49, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 73,  0,   70, 152, 55,  8,   95,  183, 24, 106, 7, 33, 68, 166, 75,
        77, 186, 230, 24, 0,   101, 186, 162, 102, 16, 0,   0, 0,  87, 255, 155,
        69, 74,  158, 5,  0,   26,  190, 206, 30,  27, 0,   0, 0,  64, 89,  124,
        68, 26,  22,  3,  0,   114, 217, 225, 73,  29, 0,   0, 0,  37, 179,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_c.header.n_obs = 33;

    test_msg.obs_dep_c.header.t.tow = 414670600;

    test_msg.obs_dep_c.header.t.wn = 1898;

    test_msg.obs_dep_c.n_obs = 3;

    test_msg.obs_dep_c.obs[0].L.f = 101;

    test_msg.obs_dep_c.obs[0].L.i = 1631930;

    test_msg.obs_dep_c.obs[0].P = 1296803396;

    test_msg.obs_dep_c.obs[0].cn0 = 186;

    test_msg.obs_dep_c.obs[0].lock = 26274;

    test_msg.obs_dep_c.obs[0].sid.code = 0;

    test_msg.obs_dep_c.obs[0].sid.reserved = 0;

    test_msg.obs_dep_c.obs[0].sid.sat = 16;

    test_msg.obs_dep_c.obs[1].L.f = 26;

    test_msg.obs_dep_c.obs[1].L.i = 368202;

    test_msg.obs_dep_c.obs[1].P = 1167851351;

    test_msg.obs_dep_c.obs[1].cn0 = 190;

    test_msg.obs_dep_c.obs[1].lock = 7886;

    test_msg.obs_dep_c.obs[1].sid.code = 0;

    test_msg.obs_dep_c.obs[1].sid.reserved = 0;

    test_msg.obs_dep_c.obs[1].sid.sat = 27;

    test_msg.obs_dep_c.obs[2].L.f = 114;

    test_msg.obs_dep_c.obs[2].L.i = 202266;

    test_msg.obs_dep_c.obs[2].P = 1149000000;

    test_msg.obs_dep_c.obs[2].cn0 = 217;

    test_msg.obs_dep_c.obs[2].lock = 18913;

    test_msg.obs_dep_c.obs[2].sid.code = 0;

    test_msg.obs_dep_c.obs[2].sid.reserved = 0;

    test_msg.obs_dep_c.obs[2].sid.sat = 29;

    sbp_message_send(&sbp_state, SbpMsgObsDepC, 38982, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 38982,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepC, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_c.header.n_obs == 33,
                  "incorrect value for last_msg.msg.obs_dep_c.header.n_obs, "
                  "expected 33, is %d",
                  last_msg.msg.obs_dep_c.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_c.header.t.tow == 414670600,
                  "incorrect value for last_msg.msg.obs_dep_c.header.t.tow, "
                  "expected 414670600, is %d",
                  last_msg.msg.obs_dep_c.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_c.header.t.wn == 1898,
                  "incorrect value for last_msg.msg.obs_dep_c.header.t.wn, "
                  "expected 1898, is %d",
                  last_msg.msg.obs_dep_c.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.n_obs == 3,
        "incorrect value for last_msg.msg.obs_dep_c.n_obs, expected 3, is %d",
        last_msg.msg.obs_dep_c.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].L.f == 101,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].L.f, "
                  "expected 101, is %d",
                  last_msg.msg.obs_dep_c.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].L.i == 1631930,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].L.i, "
                  "expected 1631930, is %d",
                  last_msg.msg.obs_dep_c.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].P == 1296803396,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].P, "
                  "expected 1296803396, is %d",
                  last_msg.msg.obs_dep_c.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].cn0 == 186,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].cn0, "
                  "expected 186, is %d",
                  last_msg.msg.obs_dep_c.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].lock == 26274,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].lock, "
                  "expected 26274, is %d",
                  last_msg.msg.obs_dep_c.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[0].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[0].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[0].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].sid.sat == 16,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.sat, "
                  "expected 16, is %d",
                  last_msg.msg.obs_dep_c.obs[0].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].L.f == 26,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].L.f, "
                  "expected 26, is %d",
                  last_msg.msg.obs_dep_c.obs[1].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].L.i == 368202,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].L.i, "
                  "expected 368202, is %d",
                  last_msg.msg.obs_dep_c.obs[1].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].P == 1167851351,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].P, "
                  "expected 1167851351, is %d",
                  last_msg.msg.obs_dep_c.obs[1].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].cn0 == 190,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].cn0, "
                  "expected 190, is %d",
                  last_msg.msg.obs_dep_c.obs[1].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].lock == 7886,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].lock, "
                  "expected 7886, is %d",
                  last_msg.msg.obs_dep_c.obs[1].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[1].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[1].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[1].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].sid.sat == 27,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.sat, "
                  "expected 27, is %d",
                  last_msg.msg.obs_dep_c.obs[1].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].L.f == 114,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].L.f, "
                  "expected 114, is %d",
                  last_msg.msg.obs_dep_c.obs[2].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].L.i == 202266,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].L.i, "
                  "expected 202266, is %d",
                  last_msg.msg.obs_dep_c.obs[2].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].P == 1149000000,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].P, "
                  "expected 1149000000, is %d",
                  last_msg.msg.obs_dep_c.obs[2].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].cn0 == 217,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].cn0, "
                  "expected 217, is %d",
                  last_msg.msg.obs_dep_c.obs[2].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].lock == 18913,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].lock, "
                  "expected 18913, is %d",
                  last_msg.msg.obs_dep_c.obs[2].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[2].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[2].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[2].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].sid.sat == 29,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.sat, "
                  "expected 29, is %d",
                  last_msg.msg.obs_dep_c.obs[2].sid.sat);
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

    sbp_callback_register(&sbp_state, 0x49, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  73,  0,   0,   0,   87,  8,   95,  183, 24,  106, 7,   32,  217,
        251, 73,  80,  9,   72,  248, 255, 30,  168, 113, 81,  4,   0,   0,
        0,   211, 220, 96,  70,  198, 107, 251, 255, 115, 195, 53,  144, 6,
        0,   0,   0,   77,  61,  62,  77,  40,  161, 243, 255, 130, 176, 93,
        142, 7,   0,   0,   0,   1,   86,  190, 77,  88,  77,  12,  0,   116,
        199, 229, 213, 10,  0,   0,   0,   93,  85,  9,   75,  64,  139, 20,
        0,   120, 177, 196, 194, 12,  0,   0,   0,   141, 161,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_c.header.n_obs = 32;

    test_msg.obs_dep_c.header.t.tow = 414670600;

    test_msg.obs_dep_c.header.t.wn = 1898;

    test_msg.obs_dep_c.n_obs = 5;

    test_msg.obs_dep_c.obs[0].L.f = 30;

    test_msg.obs_dep_c.obs[0].L.i = -505847;

    test_msg.obs_dep_c.obs[0].P = 1347025881;

    test_msg.obs_dep_c.obs[0].cn0 = 168;

    test_msg.obs_dep_c.obs[0].lock = 20849;

    test_msg.obs_dep_c.obs[0].sid.code = 0;

    test_msg.obs_dep_c.obs[0].sid.reserved = 0;

    test_msg.obs_dep_c.obs[0].sid.sat = 4;

    test_msg.obs_dep_c.obs[1].L.f = 115;

    test_msg.obs_dep_c.obs[1].L.i = -300090;

    test_msg.obs_dep_c.obs[1].P = 1180753107;

    test_msg.obs_dep_c.obs[1].cn0 = 195;

    test_msg.obs_dep_c.obs[1].lock = 36917;

    test_msg.obs_dep_c.obs[1].sid.code = 0;

    test_msg.obs_dep_c.obs[1].sid.reserved = 0;

    test_msg.obs_dep_c.obs[1].sid.sat = 6;

    test_msg.obs_dep_c.obs[2].L.f = 130;

    test_msg.obs_dep_c.obs[2].L.i = -810712;

    test_msg.obs_dep_c.obs[2].P = 1295924557;

    test_msg.obs_dep_c.obs[2].cn0 = 176;

    test_msg.obs_dep_c.obs[2].lock = 36445;

    test_msg.obs_dep_c.obs[2].sid.code = 0;

    test_msg.obs_dep_c.obs[2].sid.reserved = 0;

    test_msg.obs_dep_c.obs[2].sid.sat = 7;

    test_msg.obs_dep_c.obs[3].L.f = 116;

    test_msg.obs_dep_c.obs[3].L.i = 806232;

    test_msg.obs_dep_c.obs[3].P = 1304319489;

    test_msg.obs_dep_c.obs[3].cn0 = 199;

    test_msg.obs_dep_c.obs[3].lock = 54757;

    test_msg.obs_dep_c.obs[3].sid.code = 0;

    test_msg.obs_dep_c.obs[3].sid.reserved = 0;

    test_msg.obs_dep_c.obs[3].sid.sat = 10;

    test_msg.obs_dep_c.obs[4].L.f = 120;

    test_msg.obs_dep_c.obs[4].L.i = 1346368;

    test_msg.obs_dep_c.obs[4].P = 1258902877;

    test_msg.obs_dep_c.obs[4].cn0 = 177;

    test_msg.obs_dep_c.obs[4].lock = 49860;

    test_msg.obs_dep_c.obs[4].sid.code = 0;

    test_msg.obs_dep_c.obs[4].sid.reserved = 0;

    test_msg.obs_dep_c.obs[4].sid.sat = 12;

    sbp_message_send(&sbp_state, SbpMsgObsDepC, 0, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 0,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepC, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_c.header.n_obs == 32,
                  "incorrect value for last_msg.msg.obs_dep_c.header.n_obs, "
                  "expected 32, is %d",
                  last_msg.msg.obs_dep_c.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_c.header.t.tow == 414670600,
                  "incorrect value for last_msg.msg.obs_dep_c.header.t.tow, "
                  "expected 414670600, is %d",
                  last_msg.msg.obs_dep_c.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_c.header.t.wn == 1898,
                  "incorrect value for last_msg.msg.obs_dep_c.header.t.wn, "
                  "expected 1898, is %d",
                  last_msg.msg.obs_dep_c.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.n_obs == 5,
        "incorrect value for last_msg.msg.obs_dep_c.n_obs, expected 5, is %d",
        last_msg.msg.obs_dep_c.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].L.f == 30,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].L.f, "
                  "expected 30, is %d",
                  last_msg.msg.obs_dep_c.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].L.i == -505847,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].L.i, "
                  "expected -505847, is %d",
                  last_msg.msg.obs_dep_c.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].P == 1347025881,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].P, "
                  "expected 1347025881, is %d",
                  last_msg.msg.obs_dep_c.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].cn0 == 168,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].cn0, "
                  "expected 168, is %d",
                  last_msg.msg.obs_dep_c.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].lock == 20849,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].lock, "
                  "expected 20849, is %d",
                  last_msg.msg.obs_dep_c.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[0].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[0].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[0].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].sid.sat == 4,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.sat, "
                  "expected 4, is %d",
                  last_msg.msg.obs_dep_c.obs[0].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].L.f == 115,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].L.f, "
                  "expected 115, is %d",
                  last_msg.msg.obs_dep_c.obs[1].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].L.i == -300090,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].L.i, "
                  "expected -300090, is %d",
                  last_msg.msg.obs_dep_c.obs[1].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].P == 1180753107,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].P, "
                  "expected 1180753107, is %d",
                  last_msg.msg.obs_dep_c.obs[1].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].cn0 == 195,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].cn0, "
                  "expected 195, is %d",
                  last_msg.msg.obs_dep_c.obs[1].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].lock == 36917,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].lock, "
                  "expected 36917, is %d",
                  last_msg.msg.obs_dep_c.obs[1].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[1].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[1].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[1].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].sid.sat == 6,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.sat, "
                  "expected 6, is %d",
                  last_msg.msg.obs_dep_c.obs[1].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].L.f == 130,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].L.f, "
                  "expected 130, is %d",
                  last_msg.msg.obs_dep_c.obs[2].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].L.i == -810712,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].L.i, "
                  "expected -810712, is %d",
                  last_msg.msg.obs_dep_c.obs[2].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].P == 1295924557,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].P, "
                  "expected 1295924557, is %d",
                  last_msg.msg.obs_dep_c.obs[2].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].cn0 == 176,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].cn0, "
                  "expected 176, is %d",
                  last_msg.msg.obs_dep_c.obs[2].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].lock == 36445,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].lock, "
                  "expected 36445, is %d",
                  last_msg.msg.obs_dep_c.obs[2].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[2].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[2].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[2].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].sid.sat == 7,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.sat, "
                  "expected 7, is %d",
                  last_msg.msg.obs_dep_c.obs[2].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].L.f == 116,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].L.f, "
                  "expected 116, is %d",
                  last_msg.msg.obs_dep_c.obs[3].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].L.i == 806232,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].L.i, "
                  "expected 806232, is %d",
                  last_msg.msg.obs_dep_c.obs[3].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].P == 1304319489,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].P, "
                  "expected 1304319489, is %d",
                  last_msg.msg.obs_dep_c.obs[3].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].cn0 == 199,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].cn0, "
                  "expected 199, is %d",
                  last_msg.msg.obs_dep_c.obs[3].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].lock == 54757,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].lock, "
                  "expected 54757, is %d",
                  last_msg.msg.obs_dep_c.obs[3].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[3].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[3].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[3].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[3].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].sid.sat == 10,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].sid.sat, "
                  "expected 10, is %d",
                  last_msg.msg.obs_dep_c.obs[3].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].L.f == 120,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].L.f, "
                  "expected 120, is %d",
                  last_msg.msg.obs_dep_c.obs[4].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].L.i == 1346368,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].L.i, "
                  "expected 1346368, is %d",
                  last_msg.msg.obs_dep_c.obs[4].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].P == 1258902877,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].P, "
                  "expected 1258902877, is %d",
                  last_msg.msg.obs_dep_c.obs[4].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].cn0 == 177,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].cn0, "
                  "expected 177, is %d",
                  last_msg.msg.obs_dep_c.obs[4].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].lock == 49860,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].lock, "
                  "expected 49860, is %d",
                  last_msg.msg.obs_dep_c.obs[4].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[4].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[4].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[4].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[4].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].sid.sat == 12,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].sid.sat, "
                  "expected 12, is %d",
                  last_msg.msg.obs_dep_c.obs[4].sid.sat);
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

    sbp_callback_register(&sbp_state, 0x49, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 73,  0,   0,  0, 55, 8,   95,  183, 24, 106, 7, 33, 70,  167, 75,
        77, 140, 136, 23, 0, 90, 187, 158, 129, 16, 0,   0, 0,  232, 255, 155,
        69, 45,  175, 5,  0, 17, 208, 175, 56,  27, 0,   0, 0,  64,  89,  124,
        68, 45,  96,  3,  0, 75, 185, 73,  206, 29, 0,   0, 0,  220, 158,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_c.header.n_obs = 33;

    test_msg.obs_dep_c.header.t.tow = 414670600;

    test_msg.obs_dep_c.header.t.wn = 1898;

    test_msg.obs_dep_c.n_obs = 3;

    test_msg.obs_dep_c.obs[0].L.f = 90;

    test_msg.obs_dep_c.obs[0].L.i = 1542284;

    test_msg.obs_dep_c.obs[0].P = 1296803654;

    test_msg.obs_dep_c.obs[0].cn0 = 187;

    test_msg.obs_dep_c.obs[0].lock = 33182;

    test_msg.obs_dep_c.obs[0].sid.code = 0;

    test_msg.obs_dep_c.obs[0].sid.reserved = 0;

    test_msg.obs_dep_c.obs[0].sid.sat = 16;

    test_msg.obs_dep_c.obs[1].L.f = 17;

    test_msg.obs_dep_c.obs[1].L.i = 372525;

    test_msg.obs_dep_c.obs[1].P = 1167851496;

    test_msg.obs_dep_c.obs[1].cn0 = 208;

    test_msg.obs_dep_c.obs[1].lock = 14511;

    test_msg.obs_dep_c.obs[1].sid.code = 0;

    test_msg.obs_dep_c.obs[1].sid.reserved = 0;

    test_msg.obs_dep_c.obs[1].sid.sat = 27;

    test_msg.obs_dep_c.obs[2].L.f = 75;

    test_msg.obs_dep_c.obs[2].L.i = 221229;

    test_msg.obs_dep_c.obs[2].P = 1149000000;

    test_msg.obs_dep_c.obs[2].cn0 = 185;

    test_msg.obs_dep_c.obs[2].lock = 52809;

    test_msg.obs_dep_c.obs[2].sid.code = 0;

    test_msg.obs_dep_c.obs[2].sid.reserved = 0;

    test_msg.obs_dep_c.obs[2].sid.sat = 29;

    sbp_message_send(&sbp_state, SbpMsgObsDepC, 0, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 0,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepC, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_c.header.n_obs == 33,
                  "incorrect value for last_msg.msg.obs_dep_c.header.n_obs, "
                  "expected 33, is %d",
                  last_msg.msg.obs_dep_c.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_c.header.t.tow == 414670600,
                  "incorrect value for last_msg.msg.obs_dep_c.header.t.tow, "
                  "expected 414670600, is %d",
                  last_msg.msg.obs_dep_c.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_c.header.t.wn == 1898,
                  "incorrect value for last_msg.msg.obs_dep_c.header.t.wn, "
                  "expected 1898, is %d",
                  last_msg.msg.obs_dep_c.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.n_obs == 3,
        "incorrect value for last_msg.msg.obs_dep_c.n_obs, expected 3, is %d",
        last_msg.msg.obs_dep_c.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].L.f == 90,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].L.f, "
                  "expected 90, is %d",
                  last_msg.msg.obs_dep_c.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].L.i == 1542284,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].L.i, "
                  "expected 1542284, is %d",
                  last_msg.msg.obs_dep_c.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].P == 1296803654,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].P, "
                  "expected 1296803654, is %d",
                  last_msg.msg.obs_dep_c.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].cn0 == 187,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].cn0, "
                  "expected 187, is %d",
                  last_msg.msg.obs_dep_c.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].lock == 33182,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].lock, "
                  "expected 33182, is %d",
                  last_msg.msg.obs_dep_c.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[0].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[0].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[0].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].sid.sat == 16,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.sat, "
                  "expected 16, is %d",
                  last_msg.msg.obs_dep_c.obs[0].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].L.f == 17,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].L.f, "
                  "expected 17, is %d",
                  last_msg.msg.obs_dep_c.obs[1].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].L.i == 372525,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].L.i, "
                  "expected 372525, is %d",
                  last_msg.msg.obs_dep_c.obs[1].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].P == 1167851496,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].P, "
                  "expected 1167851496, is %d",
                  last_msg.msg.obs_dep_c.obs[1].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].cn0 == 208,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].cn0, "
                  "expected 208, is %d",
                  last_msg.msg.obs_dep_c.obs[1].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].lock == 14511,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].lock, "
                  "expected 14511, is %d",
                  last_msg.msg.obs_dep_c.obs[1].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[1].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[1].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[1].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].sid.sat == 27,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.sat, "
                  "expected 27, is %d",
                  last_msg.msg.obs_dep_c.obs[1].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].L.f == 75,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].L.f, "
                  "expected 75, is %d",
                  last_msg.msg.obs_dep_c.obs[2].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].L.i == 221229,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].L.i, "
                  "expected 221229, is %d",
                  last_msg.msg.obs_dep_c.obs[2].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].P == 1149000000,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].P, "
                  "expected 1149000000, is %d",
                  last_msg.msg.obs_dep_c.obs[2].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].cn0 == 185,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].cn0, "
                  "expected 185, is %d",
                  last_msg.msg.obs_dep_c.obs[2].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].lock == 52809,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].lock, "
                  "expected 52809, is %d",
                  last_msg.msg.obs_dep_c.obs[2].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[2].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[2].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[2].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].sid.sat == 29,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.sat, "
                  "expected 29, is %d",
                  last_msg.msg.obs_dep_c.obs[2].sid.sat);
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

    sbp_callback_register(&sbp_state, 0x49, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  73,  0,   70,  152, 87,  208, 95,  183, 24,  106, 7,   32,  44,
        8,   74,  80,  86,  93,  247, 255, 57,  158, 229, 229, 4,   0,   0,
        0,   224, 229, 96,  70,  156, 146, 250, 255, 221, 200, 20,  28,  6,
        0,   0,   0,   60,  82,  62,  77,  93,  58,  242, 255, 39,  164, 180,
        178, 7,   0,   0,   0,   222, 73,  190, 77,  46,  39,  13,  0,   202,
        181, 233, 164, 10,  0,   0,   0,   149, 64,  9,   75,  114, 191, 21,
        0,   249, 182, 196, 209, 12,  0,   0,   0,   112, 8,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs_dep_c.header.n_obs = 32;

    test_msg.obs_dep_c.header.t.tow = 414670800;

    test_msg.obs_dep_c.header.t.wn = 1898;

    test_msg.obs_dep_c.n_obs = 5;

    test_msg.obs_dep_c.obs[0].L.f = 57;

    test_msg.obs_dep_c.obs[0].L.i = -565930;

    test_msg.obs_dep_c.obs[0].P = 1347029036;

    test_msg.obs_dep_c.obs[0].cn0 = 158;

    test_msg.obs_dep_c.obs[0].lock = 58853;

    test_msg.obs_dep_c.obs[0].sid.code = 0;

    test_msg.obs_dep_c.obs[0].sid.reserved = 0;

    test_msg.obs_dep_c.obs[0].sid.sat = 4;

    test_msg.obs_dep_c.obs[1].L.f = 221;

    test_msg.obs_dep_c.obs[1].L.i = -355684;

    test_msg.obs_dep_c.obs[1].P = 1180755424;

    test_msg.obs_dep_c.obs[1].cn0 = 200;

    test_msg.obs_dep_c.obs[1].lock = 7188;

    test_msg.obs_dep_c.obs[1].sid.code = 0;

    test_msg.obs_dep_c.obs[1].sid.reserved = 0;

    test_msg.obs_dep_c.obs[1].sid.sat = 6;

    test_msg.obs_dep_c.obs[2].L.f = 39;

    test_msg.obs_dep_c.obs[2].L.i = -902563;

    test_msg.obs_dep_c.obs[2].P = 1295929916;

    test_msg.obs_dep_c.obs[2].cn0 = 164;

    test_msg.obs_dep_c.obs[2].lock = 45748;

    test_msg.obs_dep_c.obs[2].sid.code = 0;

    test_msg.obs_dep_c.obs[2].sid.reserved = 0;

    test_msg.obs_dep_c.obs[2].sid.sat = 7;

    test_msg.obs_dep_c.obs[3].L.f = 202;

    test_msg.obs_dep_c.obs[3].L.i = 861998;

    test_msg.obs_dep_c.obs[3].P = 1304316382;

    test_msg.obs_dep_c.obs[3].cn0 = 181;

    test_msg.obs_dep_c.obs[3].lock = 42217;

    test_msg.obs_dep_c.obs[3].sid.code = 0;

    test_msg.obs_dep_c.obs[3].sid.reserved = 0;

    test_msg.obs_dep_c.obs[3].sid.sat = 10;

    test_msg.obs_dep_c.obs[4].L.f = 249;

    test_msg.obs_dep_c.obs[4].L.i = 1425266;

    test_msg.obs_dep_c.obs[4].P = 1258897557;

    test_msg.obs_dep_c.obs[4].cn0 = 182;

    test_msg.obs_dep_c.obs[4].lock = 53700;

    test_msg.obs_dep_c.obs[4].sid.code = 0;

    test_msg.obs_dep_c.obs[4].sid.reserved = 0;

    test_msg.obs_dep_c.obs[4].sid.sat = 12;

    sbp_message_send(&sbp_state, SbpMsgObsDepC, 38982, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 38982,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgObsDepC, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.obs_dep_c.header.n_obs == 32,
                  "incorrect value for last_msg.msg.obs_dep_c.header.n_obs, "
                  "expected 32, is %d",
                  last_msg.msg.obs_dep_c.header.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_c.header.t.tow == 414670800,
                  "incorrect value for last_msg.msg.obs_dep_c.header.t.tow, "
                  "expected 414670800, is %d",
                  last_msg.msg.obs_dep_c.header.t.tow);

    ck_assert_msg(last_msg.msg.obs_dep_c.header.t.wn == 1898,
                  "incorrect value for last_msg.msg.obs_dep_c.header.t.wn, "
                  "expected 1898, is %d",
                  last_msg.msg.obs_dep_c.header.t.wn);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.n_obs == 5,
        "incorrect value for last_msg.msg.obs_dep_c.n_obs, expected 5, is %d",
        last_msg.msg.obs_dep_c.n_obs);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].L.f == 57,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].L.f, "
                  "expected 57, is %d",
                  last_msg.msg.obs_dep_c.obs[0].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].L.i == -565930,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].L.i, "
                  "expected -565930, is %d",
                  last_msg.msg.obs_dep_c.obs[0].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].P == 1347029036,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].P, "
                  "expected 1347029036, is %d",
                  last_msg.msg.obs_dep_c.obs[0].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].cn0 == 158,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].cn0, "
                  "expected 158, is %d",
                  last_msg.msg.obs_dep_c.obs[0].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].lock == 58853,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].lock, "
                  "expected 58853, is %d",
                  last_msg.msg.obs_dep_c.obs[0].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[0].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[0].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[0].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[0].sid.sat == 4,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[0].sid.sat, "
                  "expected 4, is %d",
                  last_msg.msg.obs_dep_c.obs[0].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].L.f == 221,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].L.f, "
                  "expected 221, is %d",
                  last_msg.msg.obs_dep_c.obs[1].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].L.i == -355684,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].L.i, "
                  "expected -355684, is %d",
                  last_msg.msg.obs_dep_c.obs[1].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].P == 1180755424,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].P, "
                  "expected 1180755424, is %d",
                  last_msg.msg.obs_dep_c.obs[1].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].cn0 == 200,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].cn0, "
                  "expected 200, is %d",
                  last_msg.msg.obs_dep_c.obs[1].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].lock == 7188,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].lock, "
                  "expected 7188, is %d",
                  last_msg.msg.obs_dep_c.obs[1].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[1].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[1].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[1].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[1].sid.sat == 6,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[1].sid.sat, "
                  "expected 6, is %d",
                  last_msg.msg.obs_dep_c.obs[1].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].L.f == 39,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].L.f, "
                  "expected 39, is %d",
                  last_msg.msg.obs_dep_c.obs[2].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].L.i == -902563,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].L.i, "
                  "expected -902563, is %d",
                  last_msg.msg.obs_dep_c.obs[2].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].P == 1295929916,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].P, "
                  "expected 1295929916, is %d",
                  last_msg.msg.obs_dep_c.obs[2].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].cn0 == 164,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].cn0, "
                  "expected 164, is %d",
                  last_msg.msg.obs_dep_c.obs[2].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].lock == 45748,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].lock, "
                  "expected 45748, is %d",
                  last_msg.msg.obs_dep_c.obs[2].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[2].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[2].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[2].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[2].sid.sat == 7,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[2].sid.sat, "
                  "expected 7, is %d",
                  last_msg.msg.obs_dep_c.obs[2].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].L.f == 202,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].L.f, "
                  "expected 202, is %d",
                  last_msg.msg.obs_dep_c.obs[3].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].L.i == 861998,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].L.i, "
                  "expected 861998, is %d",
                  last_msg.msg.obs_dep_c.obs[3].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].P == 1304316382,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].P, "
                  "expected 1304316382, is %d",
                  last_msg.msg.obs_dep_c.obs[3].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].cn0 == 181,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].cn0, "
                  "expected 181, is %d",
                  last_msg.msg.obs_dep_c.obs[3].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].lock == 42217,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].lock, "
                  "expected 42217, is %d",
                  last_msg.msg.obs_dep_c.obs[3].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[3].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[3].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[3].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[3].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[3].sid.sat == 10,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[3].sid.sat, "
                  "expected 10, is %d",
                  last_msg.msg.obs_dep_c.obs[3].sid.sat);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].L.f == 249,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].L.f, "
                  "expected 249, is %d",
                  last_msg.msg.obs_dep_c.obs[4].L.f);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].L.i == 1425266,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].L.i, "
                  "expected 1425266, is %d",
                  last_msg.msg.obs_dep_c.obs[4].L.i);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].P == 1258897557,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].P, "
                  "expected 1258897557, is %d",
                  last_msg.msg.obs_dep_c.obs[4].P);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].cn0 == 182,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].cn0, "
                  "expected 182, is %d",
                  last_msg.msg.obs_dep_c.obs[4].cn0);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].lock == 53700,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].lock, "
                  "expected 53700, is %d",
                  last_msg.msg.obs_dep_c.obs[4].lock);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].sid.code == 0,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.obs_dep_c.obs[4].sid.code);

    ck_assert_msg(
        last_msg.msg.obs_dep_c.obs[4].sid.reserved == 0,
        "incorrect value for last_msg.msg.obs_dep_c.obs[4].sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.obs_dep_c.obs[4].sid.reserved);

    ck_assert_msg(last_msg.msg.obs_dep_c.obs[4].sid.sat == 12,
                  "incorrect value for last_msg.msg.obs_dep_c.obs[4].sid.sat, "
                  "expected 12, is %d",
                  last_msg.msg.obs_dep_c.obs[4].sid.sat);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgObsDepC_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_MsgObsDepC");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_observation_MsgObsDepC");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgObsDepC);
  suite_add_tcase(s, tc_acq);
  return s;
}