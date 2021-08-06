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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs.yaml by generate.py. Do
// not modify by hand!

#include <check.h>
#include <libsbp/legacy/observation.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void* context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void* context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void* last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8* buff, u32 n, void* context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8* buff, u32 n, void* context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return real_n;
}

static void logging_reset() {
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void* context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void* context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_observation_MsgObs) {
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
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_payload_callback_register(&sbp_state, 0x4a, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x4a, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  74,  0,   129, 240, 249, 152, 202, 226, 25,  0,   0,   0,   0,
        106, 8,   32,  49,  227, 254, 62,  121, 242, 158, 6,   146, 0,   250,
        172, 182, 10,  15,  10,  0,   30,  228, 254, 62,  12,  189, 40,  5,
        59,  83,  251, 172, 178, 10,  15,  10,  1,   215, 205, 144, 72,  106,
        111, 160, 7,   243, 109, 243, 119, 158, 10,  15,  18,  0,   25,  207,
        144, 72,  223, 96,  241, 5,   12,  52,  246, 27,  125, 9,   11,  18,
        1,   34,  184, 223, 74,  150, 138, 222, 7,   53,  13,  11,  245, 114,
        9,   15,  22,  0,   113, 80,  6,   69,  162, 41,  65,  7,   70,  127,
        246, 246, 189, 9,   15,  23,  0,   247, 80,  6,   69,  213, 35,  167,
        5,   221, 152, 248, 231, 158, 9,   11,  23,  1,   8,   146, 166, 64,
        12,  122, 203, 6,   114, 51,  248, 67,  93,  3,   11,  27,  0,   221,
        172, 173, 75,  217, 47,  244, 7,   232, 225, 11,  237, 123, 5,   15,
        31,  0,   250, 174, 173, 75,  216, 163, 50,  6,   40,  70,  9,   62,
        120, 3,   11,  31,  1,   135, 16,  6,   66,  99,  218, 11,  7,   7,
        138, 242, 96,  176, 10,  15,  2,   3,   148, 130, 6,   58,  217, 88,
        54,  6,   203, 21,  252, 96,  170, 10,  15,  3,   3,   186, 108, 197,
        63,  127, 54,  211, 6,   80,  4,   241, 219, 200, 10,  15,  17,  3,
        167, 195, 8,   57,  19,  204, 22,  6,   105, 51,  254, 182, 152, 10,
        15,  18,  3,   237, 248,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_t* test_msg = (msg_obs_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 32;
    test_msg->header.t.ns_residual = 0;
    test_msg->header.t.tow = 434293400;
    test_msg->header.t.wn = 2154;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[0].D.f = 172;
    test_msg->obs[0].D.i = -1536;
    test_msg->obs[0].L.f = 146;
    test_msg->obs[0].L.i = 111080057;
    test_msg->obs[0].P = 1056891697;
    test_msg->obs[0].cn0 = 182;
    test_msg->obs[0].flags = 15;
    test_msg->obs[0].lock = 10;
    test_msg->obs[0].sid.code = 0;
    test_msg->obs[0].sid.sat = 10;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[1].D.f = 172;
    test_msg->obs[1].D.i = -1197;
    test_msg->obs[1].L.f = 59;
    test_msg->obs[1].L.i = 86555916;
    test_msg->obs[1].P = 1056891934;
    test_msg->obs[1].cn0 = 178;
    test_msg->obs[1].flags = 15;
    test_msg->obs[1].lock = 10;
    test_msg->obs[1].sid.code = 1;
    test_msg->obs[1].sid.sat = 10;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[2].D.f = 119;
    test_msg->obs[2].D.i = -3219;
    test_msg->obs[2].L.f = 243;
    test_msg->obs[2].L.i = 127954794;
    test_msg->obs[2].P = 1217449431;
    test_msg->obs[2].cn0 = 158;
    test_msg->obs[2].flags = 15;
    test_msg->obs[2].lock = 10;
    test_msg->obs[2].sid.code = 0;
    test_msg->obs[2].sid.sat = 18;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[3].D.f = 27;
    test_msg->obs[3].D.i = -2508;
    test_msg->obs[3].L.f = 12;
    test_msg->obs[3].L.i = 99705055;
    test_msg->obs[3].P = 1217449753;
    test_msg->obs[3].cn0 = 125;
    test_msg->obs[3].flags = 11;
    test_msg->obs[3].lock = 9;
    test_msg->obs[3].sid.code = 1;
    test_msg->obs[3].sid.sat = 18;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[4].D.f = 245;
    test_msg->obs[4].D.i = 2829;
    test_msg->obs[4].L.f = 53;
    test_msg->obs[4].L.i = 132024982;
    test_msg->obs[4].P = 1256175650;
    test_msg->obs[4].cn0 = 114;
    test_msg->obs[4].flags = 15;
    test_msg->obs[4].lock = 9;
    test_msg->obs[4].sid.code = 0;
    test_msg->obs[4].sid.sat = 22;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[5].D.f = 246;
    test_msg->obs[5].D.i = -2433;
    test_msg->obs[5].L.f = 70;
    test_msg->obs[5].L.i = 121711010;
    test_msg->obs[5].P = 1158041713;
    test_msg->obs[5].cn0 = 189;
    test_msg->obs[5].flags = 15;
    test_msg->obs[5].lock = 9;
    test_msg->obs[5].sid.code = 0;
    test_msg->obs[5].sid.sat = 23;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[6].D.f = 231;
    test_msg->obs[6].D.i = -1896;
    test_msg->obs[6].L.f = 221;
    test_msg->obs[6].L.i = 94839765;
    test_msg->obs[6].P = 1158041847;
    test_msg->obs[6].cn0 = 158;
    test_msg->obs[6].flags = 11;
    test_msg->obs[6].lock = 9;
    test_msg->obs[6].sid.code = 1;
    test_msg->obs[6].sid.sat = 23;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[7].D.f = 67;
    test_msg->obs[7].D.i = -1997;
    test_msg->obs[7].L.f = 114;
    test_msg->obs[7].L.i = 113998348;
    test_msg->obs[7].P = 1084658184;
    test_msg->obs[7].cn0 = 93;
    test_msg->obs[7].flags = 11;
    test_msg->obs[7].lock = 3;
    test_msg->obs[7].sid.code = 0;
    test_msg->obs[7].sid.sat = 27;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[8].D.f = 237;
    test_msg->obs[8].D.i = 3041;
    test_msg->obs[8].L.f = 232;
    test_msg->obs[8].L.i = 133443545;
    test_msg->obs[8].P = 1269673181;
    test_msg->obs[8].cn0 = 123;
    test_msg->obs[8].flags = 15;
    test_msg->obs[8].lock = 5;
    test_msg->obs[8].sid.code = 0;
    test_msg->obs[8].sid.sat = 31;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[9].D.f = 62;
    test_msg->obs[9].D.i = 2374;
    test_msg->obs[9].L.f = 40;
    test_msg->obs[9].L.i = 103982040;
    test_msg->obs[9].P = 1269673722;
    test_msg->obs[9].cn0 = 120;
    test_msg->obs[9].flags = 11;
    test_msg->obs[9].lock = 3;
    test_msg->obs[9].sid.code = 1;
    test_msg->obs[9].sid.sat = 31;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[10].D.f = 96;
    test_msg->obs[10].D.i = -3446;
    test_msg->obs[10].L.f = 7;
    test_msg->obs[10].L.i = 118217315;
    test_msg->obs[10].P = 1107693703;
    test_msg->obs[10].cn0 = 176;
    test_msg->obs[10].flags = 15;
    test_msg->obs[10].lock = 10;
    test_msg->obs[10].sid.code = 3;
    test_msg->obs[10].sid.sat = 2;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[11].D.f = 96;
    test_msg->obs[11].D.i = -1003;
    test_msg->obs[11].L.f = 203;
    test_msg->obs[11].L.i = 104224985;
    test_msg->obs[11].P = 973505172;
    test_msg->obs[11].cn0 = 170;
    test_msg->obs[11].flags = 15;
    test_msg->obs[11].lock = 10;
    test_msg->obs[11].sid.code = 3;
    test_msg->obs[11].sid.sat = 3;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[12].D.f = 219;
    test_msg->obs[12].D.i = -3836;
    test_msg->obs[12].L.f = 80;
    test_msg->obs[12].L.i = 114505343;
    test_msg->obs[12].P = 1069903034;
    test_msg->obs[12].cn0 = 200;
    test_msg->obs[12].flags = 15;
    test_msg->obs[12].lock = 10;
    test_msg->obs[12].sid.code = 3;
    test_msg->obs[12].sid.sat = 17;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[13].D.f = 182;
    test_msg->obs[13].D.i = -461;
    test_msg->obs[13].L.f = 105;
    test_msg->obs[13].L.i = 102157331;
    test_msg->obs[13].P = 956875687;
    test_msg->obs[13].cn0 = 152;
    test_msg->obs[13].flags = 15;
    test_msg->obs[13].lock = 10;
    test_msg->obs[13].sid.code = 3;
    test_msg->obs[13].sid.sat = 18;
    sbp_payload_send(&sbp_state, 0x4a, 61569, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 61569,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 61569,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x4a,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_obs_t* check_msg = (msg_obs_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 32,
                  "incorrect value for header.n_obs, expected 32, is %d",
                  check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.ns_residual == 0,
                  "incorrect value for header.t.ns_residual, expected 0, is %d",
                  check_msg->header.t.ns_residual);
    ck_assert_msg(check_msg->header.t.tow == 434293400,
                  "incorrect value for header.t.tow, expected 434293400, is %d",
                  check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 2154,
                  "incorrect value for header.t.wn, expected 2154, is %d",
                  check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].D.f == 172,
                  "incorrect value for obs[0].D.f, expected 172, is %d",
                  check_msg->obs[0].D.f);
    ck_assert_msg(check_msg->obs[0].D.i == -1536,
                  "incorrect value for obs[0].D.i, expected -1536, is %d",
                  check_msg->obs[0].D.i);
    ck_assert_msg(check_msg->obs[0].L.f == 146,
                  "incorrect value for obs[0].L.f, expected 146, is %d",
                  check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == 111080057,
                  "incorrect value for obs[0].L.i, expected 111080057, is %d",
                  check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 1056891697,
                  "incorrect value for obs[0].P, expected 1056891697, is %d",
                  check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 182,
                  "incorrect value for obs[0].cn0, expected 182, is %d",
                  check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].flags == 15,
                  "incorrect value for obs[0].flags, expected 15, is %d",
                  check_msg->obs[0].flags);
    ck_assert_msg(check_msg->obs[0].lock == 10,
                  "incorrect value for obs[0].lock, expected 10, is %d",
                  check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].sid.code == 0,
                  "incorrect value for obs[0].sid.code, expected 0, is %d",
                  check_msg->obs[0].sid.code);
    ck_assert_msg(check_msg->obs[0].sid.sat == 10,
                  "incorrect value for obs[0].sid.sat, expected 10, is %d",
                  check_msg->obs[0].sid.sat);
    ck_assert_msg(check_msg->obs[1].D.f == 172,
                  "incorrect value for obs[1].D.f, expected 172, is %d",
                  check_msg->obs[1].D.f);
    ck_assert_msg(check_msg->obs[1].D.i == -1197,
                  "incorrect value for obs[1].D.i, expected -1197, is %d",
                  check_msg->obs[1].D.i);
    ck_assert_msg(check_msg->obs[1].L.f == 59,
                  "incorrect value for obs[1].L.f, expected 59, is %d",
                  check_msg->obs[1].L.f);
    ck_assert_msg(check_msg->obs[1].L.i == 86555916,
                  "incorrect value for obs[1].L.i, expected 86555916, is %d",
                  check_msg->obs[1].L.i);
    ck_assert_msg(check_msg->obs[1].P == 1056891934,
                  "incorrect value for obs[1].P, expected 1056891934, is %d",
                  check_msg->obs[1].P);
    ck_assert_msg(check_msg->obs[1].cn0 == 178,
                  "incorrect value for obs[1].cn0, expected 178, is %d",
                  check_msg->obs[1].cn0);
    ck_assert_msg(check_msg->obs[1].flags == 15,
                  "incorrect value for obs[1].flags, expected 15, is %d",
                  check_msg->obs[1].flags);
    ck_assert_msg(check_msg->obs[1].lock == 10,
                  "incorrect value for obs[1].lock, expected 10, is %d",
                  check_msg->obs[1].lock);
    ck_assert_msg(check_msg->obs[1].sid.code == 1,
                  "incorrect value for obs[1].sid.code, expected 1, is %d",
                  check_msg->obs[1].sid.code);
    ck_assert_msg(check_msg->obs[1].sid.sat == 10,
                  "incorrect value for obs[1].sid.sat, expected 10, is %d",
                  check_msg->obs[1].sid.sat);
    ck_assert_msg(check_msg->obs[2].D.f == 119,
                  "incorrect value for obs[2].D.f, expected 119, is %d",
                  check_msg->obs[2].D.f);
    ck_assert_msg(check_msg->obs[2].D.i == -3219,
                  "incorrect value for obs[2].D.i, expected -3219, is %d",
                  check_msg->obs[2].D.i);
    ck_assert_msg(check_msg->obs[2].L.f == 243,
                  "incorrect value for obs[2].L.f, expected 243, is %d",
                  check_msg->obs[2].L.f);
    ck_assert_msg(check_msg->obs[2].L.i == 127954794,
                  "incorrect value for obs[2].L.i, expected 127954794, is %d",
                  check_msg->obs[2].L.i);
    ck_assert_msg(check_msg->obs[2].P == 1217449431,
                  "incorrect value for obs[2].P, expected 1217449431, is %d",
                  check_msg->obs[2].P);
    ck_assert_msg(check_msg->obs[2].cn0 == 158,
                  "incorrect value for obs[2].cn0, expected 158, is %d",
                  check_msg->obs[2].cn0);
    ck_assert_msg(check_msg->obs[2].flags == 15,
                  "incorrect value for obs[2].flags, expected 15, is %d",
                  check_msg->obs[2].flags);
    ck_assert_msg(check_msg->obs[2].lock == 10,
                  "incorrect value for obs[2].lock, expected 10, is %d",
                  check_msg->obs[2].lock);
    ck_assert_msg(check_msg->obs[2].sid.code == 0,
                  "incorrect value for obs[2].sid.code, expected 0, is %d",
                  check_msg->obs[2].sid.code);
    ck_assert_msg(check_msg->obs[2].sid.sat == 18,
                  "incorrect value for obs[2].sid.sat, expected 18, is %d",
                  check_msg->obs[2].sid.sat);
    ck_assert_msg(check_msg->obs[3].D.f == 27,
                  "incorrect value for obs[3].D.f, expected 27, is %d",
                  check_msg->obs[3].D.f);
    ck_assert_msg(check_msg->obs[3].D.i == -2508,
                  "incorrect value for obs[3].D.i, expected -2508, is %d",
                  check_msg->obs[3].D.i);
    ck_assert_msg(check_msg->obs[3].L.f == 12,
                  "incorrect value for obs[3].L.f, expected 12, is %d",
                  check_msg->obs[3].L.f);
    ck_assert_msg(check_msg->obs[3].L.i == 99705055,
                  "incorrect value for obs[3].L.i, expected 99705055, is %d",
                  check_msg->obs[3].L.i);
    ck_assert_msg(check_msg->obs[3].P == 1217449753,
                  "incorrect value for obs[3].P, expected 1217449753, is %d",
                  check_msg->obs[3].P);
    ck_assert_msg(check_msg->obs[3].cn0 == 125,
                  "incorrect value for obs[3].cn0, expected 125, is %d",
                  check_msg->obs[3].cn0);
    ck_assert_msg(check_msg->obs[3].flags == 11,
                  "incorrect value for obs[3].flags, expected 11, is %d",
                  check_msg->obs[3].flags);
    ck_assert_msg(check_msg->obs[3].lock == 9,
                  "incorrect value for obs[3].lock, expected 9, is %d",
                  check_msg->obs[3].lock);
    ck_assert_msg(check_msg->obs[3].sid.code == 1,
                  "incorrect value for obs[3].sid.code, expected 1, is %d",
                  check_msg->obs[3].sid.code);
    ck_assert_msg(check_msg->obs[3].sid.sat == 18,
                  "incorrect value for obs[3].sid.sat, expected 18, is %d",
                  check_msg->obs[3].sid.sat);
    ck_assert_msg(check_msg->obs[4].D.f == 245,
                  "incorrect value for obs[4].D.f, expected 245, is %d",
                  check_msg->obs[4].D.f);
    ck_assert_msg(check_msg->obs[4].D.i == 2829,
                  "incorrect value for obs[4].D.i, expected 2829, is %d",
                  check_msg->obs[4].D.i);
    ck_assert_msg(check_msg->obs[4].L.f == 53,
                  "incorrect value for obs[4].L.f, expected 53, is %d",
                  check_msg->obs[4].L.f);
    ck_assert_msg(check_msg->obs[4].L.i == 132024982,
                  "incorrect value for obs[4].L.i, expected 132024982, is %d",
                  check_msg->obs[4].L.i);
    ck_assert_msg(check_msg->obs[4].P == 1256175650,
                  "incorrect value for obs[4].P, expected 1256175650, is %d",
                  check_msg->obs[4].P);
    ck_assert_msg(check_msg->obs[4].cn0 == 114,
                  "incorrect value for obs[4].cn0, expected 114, is %d",
                  check_msg->obs[4].cn0);
    ck_assert_msg(check_msg->obs[4].flags == 15,
                  "incorrect value for obs[4].flags, expected 15, is %d",
                  check_msg->obs[4].flags);
    ck_assert_msg(check_msg->obs[4].lock == 9,
                  "incorrect value for obs[4].lock, expected 9, is %d",
                  check_msg->obs[4].lock);
    ck_assert_msg(check_msg->obs[4].sid.code == 0,
                  "incorrect value for obs[4].sid.code, expected 0, is %d",
                  check_msg->obs[4].sid.code);
    ck_assert_msg(check_msg->obs[4].sid.sat == 22,
                  "incorrect value for obs[4].sid.sat, expected 22, is %d",
                  check_msg->obs[4].sid.sat);
    ck_assert_msg(check_msg->obs[5].D.f == 246,
                  "incorrect value for obs[5].D.f, expected 246, is %d",
                  check_msg->obs[5].D.f);
    ck_assert_msg(check_msg->obs[5].D.i == -2433,
                  "incorrect value for obs[5].D.i, expected -2433, is %d",
                  check_msg->obs[5].D.i);
    ck_assert_msg(check_msg->obs[5].L.f == 70,
                  "incorrect value for obs[5].L.f, expected 70, is %d",
                  check_msg->obs[5].L.f);
    ck_assert_msg(check_msg->obs[5].L.i == 121711010,
                  "incorrect value for obs[5].L.i, expected 121711010, is %d",
                  check_msg->obs[5].L.i);
    ck_assert_msg(check_msg->obs[5].P == 1158041713,
                  "incorrect value for obs[5].P, expected 1158041713, is %d",
                  check_msg->obs[5].P);
    ck_assert_msg(check_msg->obs[5].cn0 == 189,
                  "incorrect value for obs[5].cn0, expected 189, is %d",
                  check_msg->obs[5].cn0);
    ck_assert_msg(check_msg->obs[5].flags == 15,
                  "incorrect value for obs[5].flags, expected 15, is %d",
                  check_msg->obs[5].flags);
    ck_assert_msg(check_msg->obs[5].lock == 9,
                  "incorrect value for obs[5].lock, expected 9, is %d",
                  check_msg->obs[5].lock);
    ck_assert_msg(check_msg->obs[5].sid.code == 0,
                  "incorrect value for obs[5].sid.code, expected 0, is %d",
                  check_msg->obs[5].sid.code);
    ck_assert_msg(check_msg->obs[5].sid.sat == 23,
                  "incorrect value for obs[5].sid.sat, expected 23, is %d",
                  check_msg->obs[5].sid.sat);
    ck_assert_msg(check_msg->obs[6].D.f == 231,
                  "incorrect value for obs[6].D.f, expected 231, is %d",
                  check_msg->obs[6].D.f);
    ck_assert_msg(check_msg->obs[6].D.i == -1896,
                  "incorrect value for obs[6].D.i, expected -1896, is %d",
                  check_msg->obs[6].D.i);
    ck_assert_msg(check_msg->obs[6].L.f == 221,
                  "incorrect value for obs[6].L.f, expected 221, is %d",
                  check_msg->obs[6].L.f);
    ck_assert_msg(check_msg->obs[6].L.i == 94839765,
                  "incorrect value for obs[6].L.i, expected 94839765, is %d",
                  check_msg->obs[6].L.i);
    ck_assert_msg(check_msg->obs[6].P == 1158041847,
                  "incorrect value for obs[6].P, expected 1158041847, is %d",
                  check_msg->obs[6].P);
    ck_assert_msg(check_msg->obs[6].cn0 == 158,
                  "incorrect value for obs[6].cn0, expected 158, is %d",
                  check_msg->obs[6].cn0);
    ck_assert_msg(check_msg->obs[6].flags == 11,
                  "incorrect value for obs[6].flags, expected 11, is %d",
                  check_msg->obs[6].flags);
    ck_assert_msg(check_msg->obs[6].lock == 9,
                  "incorrect value for obs[6].lock, expected 9, is %d",
                  check_msg->obs[6].lock);
    ck_assert_msg(check_msg->obs[6].sid.code == 1,
                  "incorrect value for obs[6].sid.code, expected 1, is %d",
                  check_msg->obs[6].sid.code);
    ck_assert_msg(check_msg->obs[6].sid.sat == 23,
                  "incorrect value for obs[6].sid.sat, expected 23, is %d",
                  check_msg->obs[6].sid.sat);
    ck_assert_msg(check_msg->obs[7].D.f == 67,
                  "incorrect value for obs[7].D.f, expected 67, is %d",
                  check_msg->obs[7].D.f);
    ck_assert_msg(check_msg->obs[7].D.i == -1997,
                  "incorrect value for obs[7].D.i, expected -1997, is %d",
                  check_msg->obs[7].D.i);
    ck_assert_msg(check_msg->obs[7].L.f == 114,
                  "incorrect value for obs[7].L.f, expected 114, is %d",
                  check_msg->obs[7].L.f);
    ck_assert_msg(check_msg->obs[7].L.i == 113998348,
                  "incorrect value for obs[7].L.i, expected 113998348, is %d",
                  check_msg->obs[7].L.i);
    ck_assert_msg(check_msg->obs[7].P == 1084658184,
                  "incorrect value for obs[7].P, expected 1084658184, is %d",
                  check_msg->obs[7].P);
    ck_assert_msg(check_msg->obs[7].cn0 == 93,
                  "incorrect value for obs[7].cn0, expected 93, is %d",
                  check_msg->obs[7].cn0);
    ck_assert_msg(check_msg->obs[7].flags == 11,
                  "incorrect value for obs[7].flags, expected 11, is %d",
                  check_msg->obs[7].flags);
    ck_assert_msg(check_msg->obs[7].lock == 3,
                  "incorrect value for obs[7].lock, expected 3, is %d",
                  check_msg->obs[7].lock);
    ck_assert_msg(check_msg->obs[7].sid.code == 0,
                  "incorrect value for obs[7].sid.code, expected 0, is %d",
                  check_msg->obs[7].sid.code);
    ck_assert_msg(check_msg->obs[7].sid.sat == 27,
                  "incorrect value for obs[7].sid.sat, expected 27, is %d",
                  check_msg->obs[7].sid.sat);
    ck_assert_msg(check_msg->obs[8].D.f == 237,
                  "incorrect value for obs[8].D.f, expected 237, is %d",
                  check_msg->obs[8].D.f);
    ck_assert_msg(check_msg->obs[8].D.i == 3041,
                  "incorrect value for obs[8].D.i, expected 3041, is %d",
                  check_msg->obs[8].D.i);
    ck_assert_msg(check_msg->obs[8].L.f == 232,
                  "incorrect value for obs[8].L.f, expected 232, is %d",
                  check_msg->obs[8].L.f);
    ck_assert_msg(check_msg->obs[8].L.i == 133443545,
                  "incorrect value for obs[8].L.i, expected 133443545, is %d",
                  check_msg->obs[8].L.i);
    ck_assert_msg(check_msg->obs[8].P == 1269673181,
                  "incorrect value for obs[8].P, expected 1269673181, is %d",
                  check_msg->obs[8].P);
    ck_assert_msg(check_msg->obs[8].cn0 == 123,
                  "incorrect value for obs[8].cn0, expected 123, is %d",
                  check_msg->obs[8].cn0);
    ck_assert_msg(check_msg->obs[8].flags == 15,
                  "incorrect value for obs[8].flags, expected 15, is %d",
                  check_msg->obs[8].flags);
    ck_assert_msg(check_msg->obs[8].lock == 5,
                  "incorrect value for obs[8].lock, expected 5, is %d",
                  check_msg->obs[8].lock);
    ck_assert_msg(check_msg->obs[8].sid.code == 0,
                  "incorrect value for obs[8].sid.code, expected 0, is %d",
                  check_msg->obs[8].sid.code);
    ck_assert_msg(check_msg->obs[8].sid.sat == 31,
                  "incorrect value for obs[8].sid.sat, expected 31, is %d",
                  check_msg->obs[8].sid.sat);
    ck_assert_msg(check_msg->obs[9].D.f == 62,
                  "incorrect value for obs[9].D.f, expected 62, is %d",
                  check_msg->obs[9].D.f);
    ck_assert_msg(check_msg->obs[9].D.i == 2374,
                  "incorrect value for obs[9].D.i, expected 2374, is %d",
                  check_msg->obs[9].D.i);
    ck_assert_msg(check_msg->obs[9].L.f == 40,
                  "incorrect value for obs[9].L.f, expected 40, is %d",
                  check_msg->obs[9].L.f);
    ck_assert_msg(check_msg->obs[9].L.i == 103982040,
                  "incorrect value for obs[9].L.i, expected 103982040, is %d",
                  check_msg->obs[9].L.i);
    ck_assert_msg(check_msg->obs[9].P == 1269673722,
                  "incorrect value for obs[9].P, expected 1269673722, is %d",
                  check_msg->obs[9].P);
    ck_assert_msg(check_msg->obs[9].cn0 == 120,
                  "incorrect value for obs[9].cn0, expected 120, is %d",
                  check_msg->obs[9].cn0);
    ck_assert_msg(check_msg->obs[9].flags == 11,
                  "incorrect value for obs[9].flags, expected 11, is %d",
                  check_msg->obs[9].flags);
    ck_assert_msg(check_msg->obs[9].lock == 3,
                  "incorrect value for obs[9].lock, expected 3, is %d",
                  check_msg->obs[9].lock);
    ck_assert_msg(check_msg->obs[9].sid.code == 1,
                  "incorrect value for obs[9].sid.code, expected 1, is %d",
                  check_msg->obs[9].sid.code);
    ck_assert_msg(check_msg->obs[9].sid.sat == 31,
                  "incorrect value for obs[9].sid.sat, expected 31, is %d",
                  check_msg->obs[9].sid.sat);
    ck_assert_msg(check_msg->obs[10].D.f == 96,
                  "incorrect value for obs[10].D.f, expected 96, is %d",
                  check_msg->obs[10].D.f);
    ck_assert_msg(check_msg->obs[10].D.i == -3446,
                  "incorrect value for obs[10].D.i, expected -3446, is %d",
                  check_msg->obs[10].D.i);
    ck_assert_msg(check_msg->obs[10].L.f == 7,
                  "incorrect value for obs[10].L.f, expected 7, is %d",
                  check_msg->obs[10].L.f);
    ck_assert_msg(check_msg->obs[10].L.i == 118217315,
                  "incorrect value for obs[10].L.i, expected 118217315, is %d",
                  check_msg->obs[10].L.i);
    ck_assert_msg(check_msg->obs[10].P == 1107693703,
                  "incorrect value for obs[10].P, expected 1107693703, is %d",
                  check_msg->obs[10].P);
    ck_assert_msg(check_msg->obs[10].cn0 == 176,
                  "incorrect value for obs[10].cn0, expected 176, is %d",
                  check_msg->obs[10].cn0);
    ck_assert_msg(check_msg->obs[10].flags == 15,
                  "incorrect value for obs[10].flags, expected 15, is %d",
                  check_msg->obs[10].flags);
    ck_assert_msg(check_msg->obs[10].lock == 10,
                  "incorrect value for obs[10].lock, expected 10, is %d",
                  check_msg->obs[10].lock);
    ck_assert_msg(check_msg->obs[10].sid.code == 3,
                  "incorrect value for obs[10].sid.code, expected 3, is %d",
                  check_msg->obs[10].sid.code);
    ck_assert_msg(check_msg->obs[10].sid.sat == 2,
                  "incorrect value for obs[10].sid.sat, expected 2, is %d",
                  check_msg->obs[10].sid.sat);
    ck_assert_msg(check_msg->obs[11].D.f == 96,
                  "incorrect value for obs[11].D.f, expected 96, is %d",
                  check_msg->obs[11].D.f);
    ck_assert_msg(check_msg->obs[11].D.i == -1003,
                  "incorrect value for obs[11].D.i, expected -1003, is %d",
                  check_msg->obs[11].D.i);
    ck_assert_msg(check_msg->obs[11].L.f == 203,
                  "incorrect value for obs[11].L.f, expected 203, is %d",
                  check_msg->obs[11].L.f);
    ck_assert_msg(check_msg->obs[11].L.i == 104224985,
                  "incorrect value for obs[11].L.i, expected 104224985, is %d",
                  check_msg->obs[11].L.i);
    ck_assert_msg(check_msg->obs[11].P == 973505172,
                  "incorrect value for obs[11].P, expected 973505172, is %d",
                  check_msg->obs[11].P);
    ck_assert_msg(check_msg->obs[11].cn0 == 170,
                  "incorrect value for obs[11].cn0, expected 170, is %d",
                  check_msg->obs[11].cn0);
    ck_assert_msg(check_msg->obs[11].flags == 15,
                  "incorrect value for obs[11].flags, expected 15, is %d",
                  check_msg->obs[11].flags);
    ck_assert_msg(check_msg->obs[11].lock == 10,
                  "incorrect value for obs[11].lock, expected 10, is %d",
                  check_msg->obs[11].lock);
    ck_assert_msg(check_msg->obs[11].sid.code == 3,
                  "incorrect value for obs[11].sid.code, expected 3, is %d",
                  check_msg->obs[11].sid.code);
    ck_assert_msg(check_msg->obs[11].sid.sat == 3,
                  "incorrect value for obs[11].sid.sat, expected 3, is %d",
                  check_msg->obs[11].sid.sat);
    ck_assert_msg(check_msg->obs[12].D.f == 219,
                  "incorrect value for obs[12].D.f, expected 219, is %d",
                  check_msg->obs[12].D.f);
    ck_assert_msg(check_msg->obs[12].D.i == -3836,
                  "incorrect value for obs[12].D.i, expected -3836, is %d",
                  check_msg->obs[12].D.i);
    ck_assert_msg(check_msg->obs[12].L.f == 80,
                  "incorrect value for obs[12].L.f, expected 80, is %d",
                  check_msg->obs[12].L.f);
    ck_assert_msg(check_msg->obs[12].L.i == 114505343,
                  "incorrect value for obs[12].L.i, expected 114505343, is %d",
                  check_msg->obs[12].L.i);
    ck_assert_msg(check_msg->obs[12].P == 1069903034,
                  "incorrect value for obs[12].P, expected 1069903034, is %d",
                  check_msg->obs[12].P);
    ck_assert_msg(check_msg->obs[12].cn0 == 200,
                  "incorrect value for obs[12].cn0, expected 200, is %d",
                  check_msg->obs[12].cn0);
    ck_assert_msg(check_msg->obs[12].flags == 15,
                  "incorrect value for obs[12].flags, expected 15, is %d",
                  check_msg->obs[12].flags);
    ck_assert_msg(check_msg->obs[12].lock == 10,
                  "incorrect value for obs[12].lock, expected 10, is %d",
                  check_msg->obs[12].lock);
    ck_assert_msg(check_msg->obs[12].sid.code == 3,
                  "incorrect value for obs[12].sid.code, expected 3, is %d",
                  check_msg->obs[12].sid.code);
    ck_assert_msg(check_msg->obs[12].sid.sat == 17,
                  "incorrect value for obs[12].sid.sat, expected 17, is %d",
                  check_msg->obs[12].sid.sat);
    ck_assert_msg(check_msg->obs[13].D.f == 182,
                  "incorrect value for obs[13].D.f, expected 182, is %d",
                  check_msg->obs[13].D.f);
    ck_assert_msg(check_msg->obs[13].D.i == -461,
                  "incorrect value for obs[13].D.i, expected -461, is %d",
                  check_msg->obs[13].D.i);
    ck_assert_msg(check_msg->obs[13].L.f == 105,
                  "incorrect value for obs[13].L.f, expected 105, is %d",
                  check_msg->obs[13].L.f);
    ck_assert_msg(check_msg->obs[13].L.i == 102157331,
                  "incorrect value for obs[13].L.i, expected 102157331, is %d",
                  check_msg->obs[13].L.i);
    ck_assert_msg(check_msg->obs[13].P == 956875687,
                  "incorrect value for obs[13].P, expected 956875687, is %d",
                  check_msg->obs[13].P);
    ck_assert_msg(check_msg->obs[13].cn0 == 152,
                  "incorrect value for obs[13].cn0, expected 152, is %d",
                  check_msg->obs[13].cn0);
    ck_assert_msg(check_msg->obs[13].flags == 15,
                  "incorrect value for obs[13].flags, expected 15, is %d",
                  check_msg->obs[13].flags);
    ck_assert_msg(check_msg->obs[13].lock == 10,
                  "incorrect value for obs[13].lock, expected 10, is %d",
                  check_msg->obs[13].lock);
    ck_assert_msg(check_msg->obs[13].sid.code == 3,
                  "incorrect value for obs[13].sid.code, expected 3, is %d",
                  check_msg->obs[13].sid.code);
    ck_assert_msg(check_msg->obs[13].sid.sat == 18,
                  "incorrect value for obs[13].sid.sat, expected 18, is %d",
                  check_msg->obs[13].sid.sat);
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

    sbp_payload_callback_register(&sbp_state, 0x4a, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x4a, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 74, 0, 129, 240, 11, 152, 202, 226, 25,
        0,  0,  0, 0,   106, 8,  16,  201, 101,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_t* test_msg = (msg_obs_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 16;
    test_msg->header.t.ns_residual = 0;
    test_msg->header.t.tow = 434293400;
    test_msg->header.t.wn = 2154;
    sbp_payload_send(&sbp_state, 0x4a, 61569, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 61569,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 61569,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x4a,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_obs_t* check_msg = (msg_obs_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 16,
                  "incorrect value for header.n_obs, expected 16, is %d",
                  check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.ns_residual == 0,
                  "incorrect value for header.t.ns_residual, expected 0, is %d",
                  check_msg->header.t.ns_residual);
    ck_assert_msg(check_msg->header.t.tow == 434293400,
                  "incorrect value for header.t.tow, expected 434293400, is %d",
                  check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 2154,
                  "incorrect value for header.t.wn, expected 2154, is %d",
                  check_msg->header.t.wn);
  }
}
END_TEST

Suite* legacy_auto_check_sbp_observation_MsgObs_suite(void) {
  Suite* s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_observation_MsgObs");
  TCase* tc_acq =
      tcase_create("Automated_Suite_legacy_auto_check_sbp_observation_MsgObs");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_observation_MsgObs);
  suite_add_tcase(s, tc_acq);
  return s;
}