/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgOsr.yaml by generate.py. Do
// not modify by hand!

#include <check.h>
#include <libsbp/observation.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static size_t dummy_wr = 0;
static size_t dummy_rd = 0;
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
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
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

START_TEST(test_auto_check_sbp_observation_MsgOsr) {
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

    sbp_callback_register(&sbp_state, 0x640, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  64,  6,   0,   0,   239, 248, 225, 233, 29,  0,   0,   0,   0,
        104, 8,   64,  75,  143, 241, 68,  230, 250, 62,  7,   66,  15,  3,
        1,   0,   13,  0,   7,   0,   7,   0,   206, 232, 105, 63,  236, 49,
        170, 6,   75,  15,  3,   13,  0,   13,  0,   3,   0,   3,   0,   45,
        145, 198, 62,  33,  7,   153, 6,   128, 15,  3,   14,  0,   13,  0,
        3,   0,   3,   0,   89,  132, 204, 67,  143, 46,  32,  7,   127, 15,
        3,   15,  0,   13,  0,   5,   0,   5,   0,   244, 254, 164, 60,  22,
        176, 95,  6,   55,  15,  3,   17,  0,   0,   0,   2,   0,   2,   0,
        106, 157, 101, 62,  151, 214, 142, 6,   108, 15,  3,   19,  0,   13,
        0,   3,   0,   3,   0,   81,  237, 60,  63,  181, 119, 165, 6,   206,
        15,  3,   28,  0,   13,  0,   3,   0,   3,   0,   134, 228, 110, 64,
        183, 159, 197, 6,   200, 15,  3,   30,  0,   13,  0,   3,   0,   3,
        0,   53,  144, 241, 68,  78,  112, 165, 5,   170, 15,  3,   1,   6,
        21,  0,   7,   0,   7,   0,   251, 232, 105, 63,  163, 128, 49,  5,
        129, 15,  3,   13,  6,   21,  0,   3,   0,   3,   0,   112, 145, 198,
        62,  37,  32,  36,  5,   46,  15,  3,   14,  6,   21,  0,   3,   0,
        3,   0,   166, 132, 204, 67,  184, 112, 141, 5,   95,  15,  3,   15,
        6,   21,  0,   5,   0,   5,   0,   121, 227,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.osr.header.n_obs = 64;

    test_msg.osr.header.t.ns_residual = 0;

    test_msg.osr.header.t.tow = 501867000;

    test_msg.osr.header.t.wn = 2152;

    test_msg.osr.n_obs = 12;

    test_msg.osr.obs[0].L.f = 66;

    test_msg.osr.obs[0].L.i = 121567974;

    test_msg.osr.obs[0].P = 1156681547;

    test_msg.osr.obs[0].flags = 3;

    test_msg.osr.obs[0].iono_std = 13;

    test_msg.osr.obs[0].lock = 15;

    test_msg.osr.obs[0].range_std = 7;

    test_msg.osr.obs[0].sid.code = 0;

    test_msg.osr.obs[0].sid.sat = 1;

    test_msg.osr.obs[0].tropo_std = 7;

    test_msg.osr.obs[1].L.f = 75;

    test_msg.osr.obs[1].L.i = 111817196;

    test_msg.osr.obs[1].P = 1063905486;

    test_msg.osr.obs[1].flags = 3;

    test_msg.osr.obs[1].iono_std = 13;

    test_msg.osr.obs[1].lock = 15;

    test_msg.osr.obs[1].range_std = 3;

    test_msg.osr.obs[1].sid.code = 0;

    test_msg.osr.obs[1].sid.sat = 13;

    test_msg.osr.obs[1].tropo_std = 3;

    test_msg.osr.obs[2].L.f = 128;

    test_msg.osr.obs[2].L.i = 110692129;

    test_msg.osr.obs[2].P = 1053200685;

    test_msg.osr.obs[2].flags = 3;

    test_msg.osr.obs[2].iono_std = 13;

    test_msg.osr.obs[2].lock = 15;

    test_msg.osr.obs[2].range_std = 3;

    test_msg.osr.obs[2].sid.code = 0;

    test_msg.osr.obs[2].sid.sat = 14;

    test_msg.osr.obs[2].tropo_std = 3;

    test_msg.osr.obs[3].L.f = 127;

    test_msg.osr.obs[3].L.i = 119549583;

    test_msg.osr.obs[3].P = 1137476697;

    test_msg.osr.obs[3].flags = 3;

    test_msg.osr.obs[3].iono_std = 13;

    test_msg.osr.obs[3].lock = 15;

    test_msg.osr.obs[3].range_std = 5;

    test_msg.osr.obs[3].sid.code = 0;

    test_msg.osr.obs[3].sid.sat = 15;

    test_msg.osr.obs[3].tropo_std = 5;

    test_msg.osr.obs[4].L.f = 55;

    test_msg.osr.obs[4].L.i = 106934294;

    test_msg.osr.obs[4].P = 1017446132;

    test_msg.osr.obs[4].flags = 3;

    test_msg.osr.obs[4].iono_std = 0;

    test_msg.osr.obs[4].lock = 15;

    test_msg.osr.obs[4].range_std = 2;

    test_msg.osr.obs[4].sid.code = 0;

    test_msg.osr.obs[4].sid.sat = 17;

    test_msg.osr.obs[4].tropo_std = 2;

    test_msg.osr.obs[5].L.f = 108;

    test_msg.osr.obs[5].L.i = 110024343;

    test_msg.osr.obs[5].P = 1046846826;

    test_msg.osr.obs[5].flags = 3;

    test_msg.osr.obs[5].iono_std = 13;

    test_msg.osr.obs[5].lock = 15;

    test_msg.osr.obs[5].range_std = 3;

    test_msg.osr.obs[5].sid.code = 0;

    test_msg.osr.obs[5].sid.sat = 19;

    test_msg.osr.obs[5].tropo_std = 3;

    test_msg.osr.obs[6].L.f = 206;

    test_msg.osr.obs[6].L.i = 111507381;

    test_msg.osr.obs[6].P = 1060957521;

    test_msg.osr.obs[6].flags = 3;

    test_msg.osr.obs[6].iono_std = 13;

    test_msg.osr.obs[6].lock = 15;

    test_msg.osr.obs[6].range_std = 3;

    test_msg.osr.obs[6].sid.code = 0;

    test_msg.osr.obs[6].sid.sat = 28;

    test_msg.osr.obs[6].tropo_std = 3;

    test_msg.osr.obs[7].L.f = 200;

    test_msg.osr.obs[7].L.i = 113614775;

    test_msg.osr.obs[7].P = 1081009286;

    test_msg.osr.obs[7].flags = 3;

    test_msg.osr.obs[7].iono_std = 13;

    test_msg.osr.obs[7].lock = 15;

    test_msg.osr.obs[7].range_std = 3;

    test_msg.osr.obs[7].sid.code = 0;

    test_msg.osr.obs[7].sid.sat = 30;

    test_msg.osr.obs[7].tropo_std = 3;

    test_msg.osr.obs[8].L.f = 170;

    test_msg.osr.obs[8].L.i = 94728270;

    test_msg.osr.obs[8].P = 1156681781;

    test_msg.osr.obs[8].flags = 3;

    test_msg.osr.obs[8].iono_std = 21;

    test_msg.osr.obs[8].lock = 15;

    test_msg.osr.obs[8].range_std = 7;

    test_msg.osr.obs[8].sid.code = 6;

    test_msg.osr.obs[8].sid.sat = 1;

    test_msg.osr.obs[8].tropo_std = 7;

    test_msg.osr.obs[9].L.f = 129;

    test_msg.osr.obs[9].L.i = 87130275;

    test_msg.osr.obs[9].P = 1063905531;

    test_msg.osr.obs[9].flags = 3;

    test_msg.osr.obs[9].iono_std = 21;

    test_msg.osr.obs[9].lock = 15;

    test_msg.osr.obs[9].range_std = 3;

    test_msg.osr.obs[9].sid.code = 6;

    test_msg.osr.obs[9].sid.sat = 13;

    test_msg.osr.obs[9].tropo_std = 3;

    test_msg.osr.obs[10].L.f = 46;

    test_msg.osr.obs[10].L.i = 86253605;

    test_msg.osr.obs[10].P = 1053200752;

    test_msg.osr.obs[10].flags = 3;

    test_msg.osr.obs[10].iono_std = 21;

    test_msg.osr.obs[10].lock = 15;

    test_msg.osr.obs[10].range_std = 3;

    test_msg.osr.obs[10].sid.code = 6;

    test_msg.osr.obs[10].sid.sat = 14;

    test_msg.osr.obs[10].tropo_std = 3;

    test_msg.osr.obs[11].L.f = 95;

    test_msg.osr.obs[11].L.i = 93155512;

    test_msg.osr.obs[11].P = 1137476774;

    test_msg.osr.obs[11].flags = 3;

    test_msg.osr.obs[11].iono_std = 21;

    test_msg.osr.obs[11].lock = 15;

    test_msg.osr.obs[11].range_std = 5;

    test_msg.osr.obs[11].sid.code = 6;

    test_msg.osr.obs[11].sid.sat = 15;

    test_msg.osr.obs[11].tropo_std = 5;

    sbp_message_send(&sbp_state, SbpMsgOsr, 0, &test_msg, &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff (expected: %zu, "
                  "actual: %zu)",
                  sizeof(encoded_frame), dummy_wr);
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

    ck_assert_msg(sbp_message_cmp(SbpMsgOsr, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.osr.header.n_obs == 64,
                  "incorrect value for last_msg.msg.osr.header.n_obs, expected "
                  "64, is %" PRId64,
                  (int64_t)last_msg.msg.osr.header.n_obs);

    ck_assert_msg(last_msg.msg.osr.header.t.ns_residual == 0,
                  "incorrect value for last_msg.msg.osr.header.t.ns_residual, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.osr.header.t.ns_residual);

    ck_assert_msg(last_msg.msg.osr.header.t.tow == 501867000,
                  "incorrect value for last_msg.msg.osr.header.t.tow, expected "
                  "501867000, is %" PRId64,
                  (int64_t)last_msg.msg.osr.header.t.tow);

    ck_assert_msg(last_msg.msg.osr.header.t.wn == 2152,
                  "incorrect value for last_msg.msg.osr.header.t.wn, expected "
                  "2152, is %" PRId64,
                  (int64_t)last_msg.msg.osr.header.t.wn);

    ck_assert_msg(
        last_msg.msg.osr.n_obs == 12,
        "incorrect value for last_msg.msg.osr.n_obs, expected 12, is %" PRId64,
        (int64_t)last_msg.msg.osr.n_obs);

    ck_assert_msg(last_msg.msg.osr.obs[0].L.f == 66,
                  "incorrect value for last_msg.msg.osr.obs[0].L.f, expected "
                  "66, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[0].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[0].L.i == 121567974,
                  "incorrect value for last_msg.msg.osr.obs[0].L.i, expected "
                  "121567974, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[0].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[0].P == 1156681547,
                  "incorrect value for last_msg.msg.osr.obs[0].P, expected "
                  "1156681547, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[0].P);

    ck_assert_msg(last_msg.msg.osr.obs[0].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[0].flags, expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[0].flags);

    ck_assert_msg(last_msg.msg.osr.obs[0].iono_std == 13,
                  "incorrect value for last_msg.msg.osr.obs[0].iono_std, "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[0].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[0].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[0].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[0].lock);

    ck_assert_msg(last_msg.msg.osr.obs[0].range_std == 7,
                  "incorrect value for last_msg.msg.osr.obs[0].range_std, "
                  "expected 7, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[0].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[0].sid.code == 0,
                  "incorrect value for last_msg.msg.osr.obs[0].sid.code, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[0].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[0].sid.sat == 1,
                  "incorrect value for last_msg.msg.osr.obs[0].sid.sat, "
                  "expected 1, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[0].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[0].tropo_std == 7,
                  "incorrect value for last_msg.msg.osr.obs[0].tropo_std, "
                  "expected 7, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[0].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[1].L.f == 75,
                  "incorrect value for last_msg.msg.osr.obs[1].L.f, expected "
                  "75, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[1].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[1].L.i == 111817196,
                  "incorrect value for last_msg.msg.osr.obs[1].L.i, expected "
                  "111817196, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[1].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[1].P == 1063905486,
                  "incorrect value for last_msg.msg.osr.obs[1].P, expected "
                  "1063905486, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[1].P);

    ck_assert_msg(last_msg.msg.osr.obs[1].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[1].flags, expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[1].flags);

    ck_assert_msg(last_msg.msg.osr.obs[1].iono_std == 13,
                  "incorrect value for last_msg.msg.osr.obs[1].iono_std, "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[1].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[1].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[1].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[1].lock);

    ck_assert_msg(last_msg.msg.osr.obs[1].range_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[1].range_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[1].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[1].sid.code == 0,
                  "incorrect value for last_msg.msg.osr.obs[1].sid.code, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[1].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[1].sid.sat == 13,
                  "incorrect value for last_msg.msg.osr.obs[1].sid.sat, "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[1].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[1].tropo_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[1].tropo_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[1].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[2].L.f == 128,
                  "incorrect value for last_msg.msg.osr.obs[2].L.f, expected "
                  "128, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[2].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[2].L.i == 110692129,
                  "incorrect value for last_msg.msg.osr.obs[2].L.i, expected "
                  "110692129, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[2].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[2].P == 1053200685,
                  "incorrect value for last_msg.msg.osr.obs[2].P, expected "
                  "1053200685, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[2].P);

    ck_assert_msg(last_msg.msg.osr.obs[2].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[2].flags, expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[2].flags);

    ck_assert_msg(last_msg.msg.osr.obs[2].iono_std == 13,
                  "incorrect value for last_msg.msg.osr.obs[2].iono_std, "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[2].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[2].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[2].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[2].lock);

    ck_assert_msg(last_msg.msg.osr.obs[2].range_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[2].range_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[2].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[2].sid.code == 0,
                  "incorrect value for last_msg.msg.osr.obs[2].sid.code, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[2].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[2].sid.sat == 14,
                  "incorrect value for last_msg.msg.osr.obs[2].sid.sat, "
                  "expected 14, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[2].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[2].tropo_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[2].tropo_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[2].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[3].L.f == 127,
                  "incorrect value for last_msg.msg.osr.obs[3].L.f, expected "
                  "127, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[3].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[3].L.i == 119549583,
                  "incorrect value for last_msg.msg.osr.obs[3].L.i, expected "
                  "119549583, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[3].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[3].P == 1137476697,
                  "incorrect value for last_msg.msg.osr.obs[3].P, expected "
                  "1137476697, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[3].P);

    ck_assert_msg(last_msg.msg.osr.obs[3].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[3].flags, expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[3].flags);

    ck_assert_msg(last_msg.msg.osr.obs[3].iono_std == 13,
                  "incorrect value for last_msg.msg.osr.obs[3].iono_std, "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[3].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[3].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[3].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[3].lock);

    ck_assert_msg(last_msg.msg.osr.obs[3].range_std == 5,
                  "incorrect value for last_msg.msg.osr.obs[3].range_std, "
                  "expected 5, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[3].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[3].sid.code == 0,
                  "incorrect value for last_msg.msg.osr.obs[3].sid.code, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[3].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[3].sid.sat == 15,
                  "incorrect value for last_msg.msg.osr.obs[3].sid.sat, "
                  "expected 15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[3].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[3].tropo_std == 5,
                  "incorrect value for last_msg.msg.osr.obs[3].tropo_std, "
                  "expected 5, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[3].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[4].L.f == 55,
                  "incorrect value for last_msg.msg.osr.obs[4].L.f, expected "
                  "55, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[4].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[4].L.i == 106934294,
                  "incorrect value for last_msg.msg.osr.obs[4].L.i, expected "
                  "106934294, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[4].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[4].P == 1017446132,
                  "incorrect value for last_msg.msg.osr.obs[4].P, expected "
                  "1017446132, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[4].P);

    ck_assert_msg(last_msg.msg.osr.obs[4].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[4].flags, expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[4].flags);

    ck_assert_msg(last_msg.msg.osr.obs[4].iono_std == 0,
                  "incorrect value for last_msg.msg.osr.obs[4].iono_std, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[4].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[4].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[4].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[4].lock);

    ck_assert_msg(last_msg.msg.osr.obs[4].range_std == 2,
                  "incorrect value for last_msg.msg.osr.obs[4].range_std, "
                  "expected 2, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[4].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[4].sid.code == 0,
                  "incorrect value for last_msg.msg.osr.obs[4].sid.code, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[4].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[4].sid.sat == 17,
                  "incorrect value for last_msg.msg.osr.obs[4].sid.sat, "
                  "expected 17, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[4].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[4].tropo_std == 2,
                  "incorrect value for last_msg.msg.osr.obs[4].tropo_std, "
                  "expected 2, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[4].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[5].L.f == 108,
                  "incorrect value for last_msg.msg.osr.obs[5].L.f, expected "
                  "108, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[5].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[5].L.i == 110024343,
                  "incorrect value for last_msg.msg.osr.obs[5].L.i, expected "
                  "110024343, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[5].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[5].P == 1046846826,
                  "incorrect value for last_msg.msg.osr.obs[5].P, expected "
                  "1046846826, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[5].P);

    ck_assert_msg(last_msg.msg.osr.obs[5].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[5].flags, expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[5].flags);

    ck_assert_msg(last_msg.msg.osr.obs[5].iono_std == 13,
                  "incorrect value for last_msg.msg.osr.obs[5].iono_std, "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[5].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[5].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[5].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[5].lock);

    ck_assert_msg(last_msg.msg.osr.obs[5].range_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[5].range_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[5].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[5].sid.code == 0,
                  "incorrect value for last_msg.msg.osr.obs[5].sid.code, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[5].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[5].sid.sat == 19,
                  "incorrect value for last_msg.msg.osr.obs[5].sid.sat, "
                  "expected 19, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[5].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[5].tropo_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[5].tropo_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[5].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[6].L.f == 206,
                  "incorrect value for last_msg.msg.osr.obs[6].L.f, expected "
                  "206, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[6].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[6].L.i == 111507381,
                  "incorrect value for last_msg.msg.osr.obs[6].L.i, expected "
                  "111507381, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[6].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[6].P == 1060957521,
                  "incorrect value for last_msg.msg.osr.obs[6].P, expected "
                  "1060957521, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[6].P);

    ck_assert_msg(last_msg.msg.osr.obs[6].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[6].flags, expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[6].flags);

    ck_assert_msg(last_msg.msg.osr.obs[6].iono_std == 13,
                  "incorrect value for last_msg.msg.osr.obs[6].iono_std, "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[6].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[6].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[6].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[6].lock);

    ck_assert_msg(last_msg.msg.osr.obs[6].range_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[6].range_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[6].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[6].sid.code == 0,
                  "incorrect value for last_msg.msg.osr.obs[6].sid.code, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[6].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[6].sid.sat == 28,
                  "incorrect value for last_msg.msg.osr.obs[6].sid.sat, "
                  "expected 28, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[6].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[6].tropo_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[6].tropo_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[6].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[7].L.f == 200,
                  "incorrect value for last_msg.msg.osr.obs[7].L.f, expected "
                  "200, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[7].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[7].L.i == 113614775,
                  "incorrect value for last_msg.msg.osr.obs[7].L.i, expected "
                  "113614775, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[7].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[7].P == 1081009286,
                  "incorrect value for last_msg.msg.osr.obs[7].P, expected "
                  "1081009286, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[7].P);

    ck_assert_msg(last_msg.msg.osr.obs[7].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[7].flags, expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[7].flags);

    ck_assert_msg(last_msg.msg.osr.obs[7].iono_std == 13,
                  "incorrect value for last_msg.msg.osr.obs[7].iono_std, "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[7].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[7].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[7].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[7].lock);

    ck_assert_msg(last_msg.msg.osr.obs[7].range_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[7].range_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[7].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[7].sid.code == 0,
                  "incorrect value for last_msg.msg.osr.obs[7].sid.code, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[7].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[7].sid.sat == 30,
                  "incorrect value for last_msg.msg.osr.obs[7].sid.sat, "
                  "expected 30, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[7].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[7].tropo_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[7].tropo_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[7].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[8].L.f == 170,
                  "incorrect value for last_msg.msg.osr.obs[8].L.f, expected "
                  "170, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[8].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[8].L.i == 94728270,
                  "incorrect value for last_msg.msg.osr.obs[8].L.i, expected "
                  "94728270, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[8].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[8].P == 1156681781,
                  "incorrect value for last_msg.msg.osr.obs[8].P, expected "
                  "1156681781, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[8].P);

    ck_assert_msg(last_msg.msg.osr.obs[8].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[8].flags, expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[8].flags);

    ck_assert_msg(last_msg.msg.osr.obs[8].iono_std == 21,
                  "incorrect value for last_msg.msg.osr.obs[8].iono_std, "
                  "expected 21, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[8].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[8].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[8].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[8].lock);

    ck_assert_msg(last_msg.msg.osr.obs[8].range_std == 7,
                  "incorrect value for last_msg.msg.osr.obs[8].range_std, "
                  "expected 7, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[8].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[8].sid.code == 6,
                  "incorrect value for last_msg.msg.osr.obs[8].sid.code, "
                  "expected 6, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[8].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[8].sid.sat == 1,
                  "incorrect value for last_msg.msg.osr.obs[8].sid.sat, "
                  "expected 1, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[8].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[8].tropo_std == 7,
                  "incorrect value for last_msg.msg.osr.obs[8].tropo_std, "
                  "expected 7, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[8].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[9].L.f == 129,
                  "incorrect value for last_msg.msg.osr.obs[9].L.f, expected "
                  "129, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[9].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[9].L.i == 87130275,
                  "incorrect value for last_msg.msg.osr.obs[9].L.i, expected "
                  "87130275, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[9].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[9].P == 1063905531,
                  "incorrect value for last_msg.msg.osr.obs[9].P, expected "
                  "1063905531, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[9].P);

    ck_assert_msg(last_msg.msg.osr.obs[9].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[9].flags, expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[9].flags);

    ck_assert_msg(last_msg.msg.osr.obs[9].iono_std == 21,
                  "incorrect value for last_msg.msg.osr.obs[9].iono_std, "
                  "expected 21, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[9].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[9].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[9].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[9].lock);

    ck_assert_msg(last_msg.msg.osr.obs[9].range_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[9].range_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[9].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[9].sid.code == 6,
                  "incorrect value for last_msg.msg.osr.obs[9].sid.code, "
                  "expected 6, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[9].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[9].sid.sat == 13,
                  "incorrect value for last_msg.msg.osr.obs[9].sid.sat, "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[9].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[9].tropo_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[9].tropo_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[9].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[10].L.f == 46,
                  "incorrect value for last_msg.msg.osr.obs[10].L.f, expected "
                  "46, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[10].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[10].L.i == 86253605,
                  "incorrect value for last_msg.msg.osr.obs[10].L.i, expected "
                  "86253605, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[10].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[10].P == 1053200752,
                  "incorrect value for last_msg.msg.osr.obs[10].P, expected "
                  "1053200752, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[10].P);

    ck_assert_msg(last_msg.msg.osr.obs[10].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[10].flags, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[10].flags);

    ck_assert_msg(last_msg.msg.osr.obs[10].iono_std == 21,
                  "incorrect value for last_msg.msg.osr.obs[10].iono_std, "
                  "expected 21, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[10].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[10].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[10].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[10].lock);

    ck_assert_msg(last_msg.msg.osr.obs[10].range_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[10].range_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[10].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[10].sid.code == 6,
                  "incorrect value for last_msg.msg.osr.obs[10].sid.code, "
                  "expected 6, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[10].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[10].sid.sat == 14,
                  "incorrect value for last_msg.msg.osr.obs[10].sid.sat, "
                  "expected 14, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[10].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[10].tropo_std == 3,
                  "incorrect value for last_msg.msg.osr.obs[10].tropo_std, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[10].tropo_std);

    ck_assert_msg(last_msg.msg.osr.obs[11].L.f == 95,
                  "incorrect value for last_msg.msg.osr.obs[11].L.f, expected "
                  "95, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[11].L.f);

    ck_assert_msg(last_msg.msg.osr.obs[11].L.i == 93155512,
                  "incorrect value for last_msg.msg.osr.obs[11].L.i, expected "
                  "93155512, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[11].L.i);

    ck_assert_msg(last_msg.msg.osr.obs[11].P == 1137476774,
                  "incorrect value for last_msg.msg.osr.obs[11].P, expected "
                  "1137476774, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[11].P);

    ck_assert_msg(last_msg.msg.osr.obs[11].flags == 3,
                  "incorrect value for last_msg.msg.osr.obs[11].flags, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[11].flags);

    ck_assert_msg(last_msg.msg.osr.obs[11].iono_std == 21,
                  "incorrect value for last_msg.msg.osr.obs[11].iono_std, "
                  "expected 21, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[11].iono_std);

    ck_assert_msg(last_msg.msg.osr.obs[11].lock == 15,
                  "incorrect value for last_msg.msg.osr.obs[11].lock, expected "
                  "15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[11].lock);

    ck_assert_msg(last_msg.msg.osr.obs[11].range_std == 5,
                  "incorrect value for last_msg.msg.osr.obs[11].range_std, "
                  "expected 5, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[11].range_std);

    ck_assert_msg(last_msg.msg.osr.obs[11].sid.code == 6,
                  "incorrect value for last_msg.msg.osr.obs[11].sid.code, "
                  "expected 6, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[11].sid.code);

    ck_assert_msg(last_msg.msg.osr.obs[11].sid.sat == 15,
                  "incorrect value for last_msg.msg.osr.obs[11].sid.sat, "
                  "expected 15, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[11].sid.sat);

    ck_assert_msg(last_msg.msg.osr.obs[11].tropo_std == 5,
                  "incorrect value for last_msg.msg.osr.obs[11].tropo_std, "
                  "expected 5, is %" PRId64,
                  (int64_t)last_msg.msg.osr.obs[11].tropo_std);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgOsr_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_MsgOsr");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_observation_MsgOsr");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgOsr);
  suite_add_tcase(s, tc_acq);
  return s;
}
