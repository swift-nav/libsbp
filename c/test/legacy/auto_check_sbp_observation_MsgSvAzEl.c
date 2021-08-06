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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgSvAzEl.yaml by generate.py.
// Do not modify by hand!

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
static void *last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
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

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_observation_MsgSvAzEl) {
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

    sbp_payload_callback_register(&sbp_state, 0x97, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x97, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  151, 0,  207, 121, 132, 8,  0,  160, 12, 10,  0,  139, 66, 13, 0,
        16,  1,   15, 0,   24,  25,  16, 0,  127, 18, 18,  0,  42,  53, 20, 0,
        31,  16,  23, 0,   12,  67,  24, 0,  47,  10, 26,  0,  116, 8,  27, 0,
        153, 43,  29, 0,   77,  10,  32, 0,  94,  26, 1,   3,  16,  58, 2,  3,
        108, 53,  8,  3,   17,  13,  17, 3,  165, 40, 23,  3,  63,  35, 24, 3,
        41,  73,  20, 12,  114, 26,  27, 12, 72,  54, 28,  12, 69,  3,  29, 12,
        158, 14,  30, 12,  152, 68,  32, 12, 120, 82, 2,   14, 131, 6,  4,  14,
        27,  44,  5,  14,  101, 21,  9,  14, 81,  65, 11,  14, 49,  56, 12, 14,
        59,  6,   30, 14,  154, 4,   36, 14, 165, 62, 168, 36,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_sv_az_el_t *test_msg = (msg_sv_az_el_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[0].az = 160;
    test_msg->azel[0].el = 12;
    test_msg->azel[0].sid.code = 0;
    test_msg->azel[0].sid.sat = 8;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[1].az = 139;
    test_msg->azel[1].el = 66;
    test_msg->azel[1].sid.code = 0;
    test_msg->azel[1].sid.sat = 10;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[2].az = 16;
    test_msg->azel[2].el = 1;
    test_msg->azel[2].sid.code = 0;
    test_msg->azel[2].sid.sat = 13;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[3].az = 24;
    test_msg->azel[3].el = 25;
    test_msg->azel[3].sid.code = 0;
    test_msg->azel[3].sid.sat = 15;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[4].az = 127;
    test_msg->azel[4].el = 18;
    test_msg->azel[4].sid.code = 0;
    test_msg->azel[4].sid.sat = 16;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[5].az = 42;
    test_msg->azel[5].el = 53;
    test_msg->azel[5].sid.code = 0;
    test_msg->azel[5].sid.sat = 18;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[6].az = 31;
    test_msg->azel[6].el = 16;
    test_msg->azel[6].sid.code = 0;
    test_msg->azel[6].sid.sat = 20;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[7].az = 12;
    test_msg->azel[7].el = 67;
    test_msg->azel[7].sid.code = 0;
    test_msg->azel[7].sid.sat = 23;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[8].az = 47;
    test_msg->azel[8].el = 10;
    test_msg->azel[8].sid.code = 0;
    test_msg->azel[8].sid.sat = 24;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[9].az = 116;
    test_msg->azel[9].el = 8;
    test_msg->azel[9].sid.code = 0;
    test_msg->azel[9].sid.sat = 26;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[10].az = 153;
    test_msg->azel[10].el = 43;
    test_msg->azel[10].sid.code = 0;
    test_msg->azel[10].sid.sat = 27;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[11].az = 77;
    test_msg->azel[11].el = 10;
    test_msg->azel[11].sid.code = 0;
    test_msg->azel[11].sid.sat = 29;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[12].az = 94;
    test_msg->azel[12].el = 26;
    test_msg->azel[12].sid.code = 0;
    test_msg->azel[12].sid.sat = 32;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[13].az = 16;
    test_msg->azel[13].el = 58;
    test_msg->azel[13].sid.code = 3;
    test_msg->azel[13].sid.sat = 1;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[14].az = 108;
    test_msg->azel[14].el = 53;
    test_msg->azel[14].sid.code = 3;
    test_msg->azel[14].sid.sat = 2;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[15].az = 17;
    test_msg->azel[15].el = 13;
    test_msg->azel[15].sid.code = 3;
    test_msg->azel[15].sid.sat = 8;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[16].az = 165;
    test_msg->azel[16].el = 40;
    test_msg->azel[16].sid.code = 3;
    test_msg->azel[16].sid.sat = 17;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[17].az = 63;
    test_msg->azel[17].el = 35;
    test_msg->azel[17].sid.code = 3;
    test_msg->azel[17].sid.sat = 23;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[18].az = 41;
    test_msg->azel[18].el = 73;
    test_msg->azel[18].sid.code = 3;
    test_msg->azel[18].sid.sat = 24;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[19].az = 114;
    test_msg->azel[19].el = 26;
    test_msg->azel[19].sid.code = 12;
    test_msg->azel[19].sid.sat = 20;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[20].az = 72;
    test_msg->azel[20].el = 54;
    test_msg->azel[20].sid.code = 12;
    test_msg->azel[20].sid.sat = 27;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[21].az = 69;
    test_msg->azel[21].el = 3;
    test_msg->azel[21].sid.code = 12;
    test_msg->azel[21].sid.sat = 28;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[22].az = 158;
    test_msg->azel[22].el = 14;
    test_msg->azel[22].sid.code = 12;
    test_msg->azel[22].sid.sat = 29;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[23].az = 152;
    test_msg->azel[23].el = 68;
    test_msg->azel[23].sid.code = 12;
    test_msg->azel[23].sid.sat = 30;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[24].az = 120;
    test_msg->azel[24].el = 82;
    test_msg->azel[24].sid.code = 12;
    test_msg->azel[24].sid.sat = 32;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[25].az = 131;
    test_msg->azel[25].el = 6;
    test_msg->azel[25].sid.code = 14;
    test_msg->azel[25].sid.sat = 2;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[26].az = 27;
    test_msg->azel[26].el = 44;
    test_msg->azel[26].sid.code = 14;
    test_msg->azel[26].sid.sat = 4;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[27].az = 101;
    test_msg->azel[27].el = 21;
    test_msg->azel[27].sid.code = 14;
    test_msg->azel[27].sid.sat = 5;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[28].az = 81;
    test_msg->azel[28].el = 65;
    test_msg->azel[28].sid.code = 14;
    test_msg->azel[28].sid.sat = 9;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[29].az = 49;
    test_msg->azel[29].el = 56;
    test_msg->azel[29].sid.code = 14;
    test_msg->azel[29].sid.sat = 11;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[30].az = 59;
    test_msg->azel[30].el = 6;
    test_msg->azel[30].sid.code = 14;
    test_msg->azel[30].sid.sat = 12;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[31].az = 154;
    test_msg->azel[31].el = 4;
    test_msg->azel[31].sid.code = 14;
    test_msg->azel[31].sid.sat = 30;
    if (sizeof(test_msg->azel) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->azel[0]);
    }
    test_msg->azel[32].az = 165;
    test_msg->azel[32].el = 62;
    test_msg->azel[32].sid.code = 14;
    test_msg->azel[32].sid.sat = 36;
    sbp_payload_send(&sbp_state, 0x97, 31183, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 31183,
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
    ck_assert_msg(last_frame.sender_id == 31183,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x97,
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
    msg_sv_az_el_t *check_msg = (msg_sv_az_el_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->azel[0].az == 160,
                  "incorrect value for azel[0].az, expected 160, is %d",
                  check_msg->azel[0].az);
    ck_assert_msg(check_msg->azel[0].el == 12,
                  "incorrect value for azel[0].el, expected 12, is %d",
                  check_msg->azel[0].el);
    ck_assert_msg(check_msg->azel[0].sid.code == 0,
                  "incorrect value for azel[0].sid.code, expected 0, is %d",
                  check_msg->azel[0].sid.code);
    ck_assert_msg(check_msg->azel[0].sid.sat == 8,
                  "incorrect value for azel[0].sid.sat, expected 8, is %d",
                  check_msg->azel[0].sid.sat);
    ck_assert_msg(check_msg->azel[1].az == 139,
                  "incorrect value for azel[1].az, expected 139, is %d",
                  check_msg->azel[1].az);
    ck_assert_msg(check_msg->azel[1].el == 66,
                  "incorrect value for azel[1].el, expected 66, is %d",
                  check_msg->azel[1].el);
    ck_assert_msg(check_msg->azel[1].sid.code == 0,
                  "incorrect value for azel[1].sid.code, expected 0, is %d",
                  check_msg->azel[1].sid.code);
    ck_assert_msg(check_msg->azel[1].sid.sat == 10,
                  "incorrect value for azel[1].sid.sat, expected 10, is %d",
                  check_msg->azel[1].sid.sat);
    ck_assert_msg(check_msg->azel[2].az == 16,
                  "incorrect value for azel[2].az, expected 16, is %d",
                  check_msg->azel[2].az);
    ck_assert_msg(check_msg->azel[2].el == 1,
                  "incorrect value for azel[2].el, expected 1, is %d",
                  check_msg->azel[2].el);
    ck_assert_msg(check_msg->azel[2].sid.code == 0,
                  "incorrect value for azel[2].sid.code, expected 0, is %d",
                  check_msg->azel[2].sid.code);
    ck_assert_msg(check_msg->azel[2].sid.sat == 13,
                  "incorrect value for azel[2].sid.sat, expected 13, is %d",
                  check_msg->azel[2].sid.sat);
    ck_assert_msg(check_msg->azel[3].az == 24,
                  "incorrect value for azel[3].az, expected 24, is %d",
                  check_msg->azel[3].az);
    ck_assert_msg(check_msg->azel[3].el == 25,
                  "incorrect value for azel[3].el, expected 25, is %d",
                  check_msg->azel[3].el);
    ck_assert_msg(check_msg->azel[3].sid.code == 0,
                  "incorrect value for azel[3].sid.code, expected 0, is %d",
                  check_msg->azel[3].sid.code);
    ck_assert_msg(check_msg->azel[3].sid.sat == 15,
                  "incorrect value for azel[3].sid.sat, expected 15, is %d",
                  check_msg->azel[3].sid.sat);
    ck_assert_msg(check_msg->azel[4].az == 127,
                  "incorrect value for azel[4].az, expected 127, is %d",
                  check_msg->azel[4].az);
    ck_assert_msg(check_msg->azel[4].el == 18,
                  "incorrect value for azel[4].el, expected 18, is %d",
                  check_msg->azel[4].el);
    ck_assert_msg(check_msg->azel[4].sid.code == 0,
                  "incorrect value for azel[4].sid.code, expected 0, is %d",
                  check_msg->azel[4].sid.code);
    ck_assert_msg(check_msg->azel[4].sid.sat == 16,
                  "incorrect value for azel[4].sid.sat, expected 16, is %d",
                  check_msg->azel[4].sid.sat);
    ck_assert_msg(check_msg->azel[5].az == 42,
                  "incorrect value for azel[5].az, expected 42, is %d",
                  check_msg->azel[5].az);
    ck_assert_msg(check_msg->azel[5].el == 53,
                  "incorrect value for azel[5].el, expected 53, is %d",
                  check_msg->azel[5].el);
    ck_assert_msg(check_msg->azel[5].sid.code == 0,
                  "incorrect value for azel[5].sid.code, expected 0, is %d",
                  check_msg->azel[5].sid.code);
    ck_assert_msg(check_msg->azel[5].sid.sat == 18,
                  "incorrect value for azel[5].sid.sat, expected 18, is %d",
                  check_msg->azel[5].sid.sat);
    ck_assert_msg(check_msg->azel[6].az == 31,
                  "incorrect value for azel[6].az, expected 31, is %d",
                  check_msg->azel[6].az);
    ck_assert_msg(check_msg->azel[6].el == 16,
                  "incorrect value for azel[6].el, expected 16, is %d",
                  check_msg->azel[6].el);
    ck_assert_msg(check_msg->azel[6].sid.code == 0,
                  "incorrect value for azel[6].sid.code, expected 0, is %d",
                  check_msg->azel[6].sid.code);
    ck_assert_msg(check_msg->azel[6].sid.sat == 20,
                  "incorrect value for azel[6].sid.sat, expected 20, is %d",
                  check_msg->azel[6].sid.sat);
    ck_assert_msg(check_msg->azel[7].az == 12,
                  "incorrect value for azel[7].az, expected 12, is %d",
                  check_msg->azel[7].az);
    ck_assert_msg(check_msg->azel[7].el == 67,
                  "incorrect value for azel[7].el, expected 67, is %d",
                  check_msg->azel[7].el);
    ck_assert_msg(check_msg->azel[7].sid.code == 0,
                  "incorrect value for azel[7].sid.code, expected 0, is %d",
                  check_msg->azel[7].sid.code);
    ck_assert_msg(check_msg->azel[7].sid.sat == 23,
                  "incorrect value for azel[7].sid.sat, expected 23, is %d",
                  check_msg->azel[7].sid.sat);
    ck_assert_msg(check_msg->azel[8].az == 47,
                  "incorrect value for azel[8].az, expected 47, is %d",
                  check_msg->azel[8].az);
    ck_assert_msg(check_msg->azel[8].el == 10,
                  "incorrect value for azel[8].el, expected 10, is %d",
                  check_msg->azel[8].el);
    ck_assert_msg(check_msg->azel[8].sid.code == 0,
                  "incorrect value for azel[8].sid.code, expected 0, is %d",
                  check_msg->azel[8].sid.code);
    ck_assert_msg(check_msg->azel[8].sid.sat == 24,
                  "incorrect value for azel[8].sid.sat, expected 24, is %d",
                  check_msg->azel[8].sid.sat);
    ck_assert_msg(check_msg->azel[9].az == 116,
                  "incorrect value for azel[9].az, expected 116, is %d",
                  check_msg->azel[9].az);
    ck_assert_msg(check_msg->azel[9].el == 8,
                  "incorrect value for azel[9].el, expected 8, is %d",
                  check_msg->azel[9].el);
    ck_assert_msg(check_msg->azel[9].sid.code == 0,
                  "incorrect value for azel[9].sid.code, expected 0, is %d",
                  check_msg->azel[9].sid.code);
    ck_assert_msg(check_msg->azel[9].sid.sat == 26,
                  "incorrect value for azel[9].sid.sat, expected 26, is %d",
                  check_msg->azel[9].sid.sat);
    ck_assert_msg(check_msg->azel[10].az == 153,
                  "incorrect value for azel[10].az, expected 153, is %d",
                  check_msg->azel[10].az);
    ck_assert_msg(check_msg->azel[10].el == 43,
                  "incorrect value for azel[10].el, expected 43, is %d",
                  check_msg->azel[10].el);
    ck_assert_msg(check_msg->azel[10].sid.code == 0,
                  "incorrect value for azel[10].sid.code, expected 0, is %d",
                  check_msg->azel[10].sid.code);
    ck_assert_msg(check_msg->azel[10].sid.sat == 27,
                  "incorrect value for azel[10].sid.sat, expected 27, is %d",
                  check_msg->azel[10].sid.sat);
    ck_assert_msg(check_msg->azel[11].az == 77,
                  "incorrect value for azel[11].az, expected 77, is %d",
                  check_msg->azel[11].az);
    ck_assert_msg(check_msg->azel[11].el == 10,
                  "incorrect value for azel[11].el, expected 10, is %d",
                  check_msg->azel[11].el);
    ck_assert_msg(check_msg->azel[11].sid.code == 0,
                  "incorrect value for azel[11].sid.code, expected 0, is %d",
                  check_msg->azel[11].sid.code);
    ck_assert_msg(check_msg->azel[11].sid.sat == 29,
                  "incorrect value for azel[11].sid.sat, expected 29, is %d",
                  check_msg->azel[11].sid.sat);
    ck_assert_msg(check_msg->azel[12].az == 94,
                  "incorrect value for azel[12].az, expected 94, is %d",
                  check_msg->azel[12].az);
    ck_assert_msg(check_msg->azel[12].el == 26,
                  "incorrect value for azel[12].el, expected 26, is %d",
                  check_msg->azel[12].el);
    ck_assert_msg(check_msg->azel[12].sid.code == 0,
                  "incorrect value for azel[12].sid.code, expected 0, is %d",
                  check_msg->azel[12].sid.code);
    ck_assert_msg(check_msg->azel[12].sid.sat == 32,
                  "incorrect value for azel[12].sid.sat, expected 32, is %d",
                  check_msg->azel[12].sid.sat);
    ck_assert_msg(check_msg->azel[13].az == 16,
                  "incorrect value for azel[13].az, expected 16, is %d",
                  check_msg->azel[13].az);
    ck_assert_msg(check_msg->azel[13].el == 58,
                  "incorrect value for azel[13].el, expected 58, is %d",
                  check_msg->azel[13].el);
    ck_assert_msg(check_msg->azel[13].sid.code == 3,
                  "incorrect value for azel[13].sid.code, expected 3, is %d",
                  check_msg->azel[13].sid.code);
    ck_assert_msg(check_msg->azel[13].sid.sat == 1,
                  "incorrect value for azel[13].sid.sat, expected 1, is %d",
                  check_msg->azel[13].sid.sat);
    ck_assert_msg(check_msg->azel[14].az == 108,
                  "incorrect value for azel[14].az, expected 108, is %d",
                  check_msg->azel[14].az);
    ck_assert_msg(check_msg->azel[14].el == 53,
                  "incorrect value for azel[14].el, expected 53, is %d",
                  check_msg->azel[14].el);
    ck_assert_msg(check_msg->azel[14].sid.code == 3,
                  "incorrect value for azel[14].sid.code, expected 3, is %d",
                  check_msg->azel[14].sid.code);
    ck_assert_msg(check_msg->azel[14].sid.sat == 2,
                  "incorrect value for azel[14].sid.sat, expected 2, is %d",
                  check_msg->azel[14].sid.sat);
    ck_assert_msg(check_msg->azel[15].az == 17,
                  "incorrect value for azel[15].az, expected 17, is %d",
                  check_msg->azel[15].az);
    ck_assert_msg(check_msg->azel[15].el == 13,
                  "incorrect value for azel[15].el, expected 13, is %d",
                  check_msg->azel[15].el);
    ck_assert_msg(check_msg->azel[15].sid.code == 3,
                  "incorrect value for azel[15].sid.code, expected 3, is %d",
                  check_msg->azel[15].sid.code);
    ck_assert_msg(check_msg->azel[15].sid.sat == 8,
                  "incorrect value for azel[15].sid.sat, expected 8, is %d",
                  check_msg->azel[15].sid.sat);
    ck_assert_msg(check_msg->azel[16].az == 165,
                  "incorrect value for azel[16].az, expected 165, is %d",
                  check_msg->azel[16].az);
    ck_assert_msg(check_msg->azel[16].el == 40,
                  "incorrect value for azel[16].el, expected 40, is %d",
                  check_msg->azel[16].el);
    ck_assert_msg(check_msg->azel[16].sid.code == 3,
                  "incorrect value for azel[16].sid.code, expected 3, is %d",
                  check_msg->azel[16].sid.code);
    ck_assert_msg(check_msg->azel[16].sid.sat == 17,
                  "incorrect value for azel[16].sid.sat, expected 17, is %d",
                  check_msg->azel[16].sid.sat);
    ck_assert_msg(check_msg->azel[17].az == 63,
                  "incorrect value for azel[17].az, expected 63, is %d",
                  check_msg->azel[17].az);
    ck_assert_msg(check_msg->azel[17].el == 35,
                  "incorrect value for azel[17].el, expected 35, is %d",
                  check_msg->azel[17].el);
    ck_assert_msg(check_msg->azel[17].sid.code == 3,
                  "incorrect value for azel[17].sid.code, expected 3, is %d",
                  check_msg->azel[17].sid.code);
    ck_assert_msg(check_msg->azel[17].sid.sat == 23,
                  "incorrect value for azel[17].sid.sat, expected 23, is %d",
                  check_msg->azel[17].sid.sat);
    ck_assert_msg(check_msg->azel[18].az == 41,
                  "incorrect value for azel[18].az, expected 41, is %d",
                  check_msg->azel[18].az);
    ck_assert_msg(check_msg->azel[18].el == 73,
                  "incorrect value for azel[18].el, expected 73, is %d",
                  check_msg->azel[18].el);
    ck_assert_msg(check_msg->azel[18].sid.code == 3,
                  "incorrect value for azel[18].sid.code, expected 3, is %d",
                  check_msg->azel[18].sid.code);
    ck_assert_msg(check_msg->azel[18].sid.sat == 24,
                  "incorrect value for azel[18].sid.sat, expected 24, is %d",
                  check_msg->azel[18].sid.sat);
    ck_assert_msg(check_msg->azel[19].az == 114,
                  "incorrect value for azel[19].az, expected 114, is %d",
                  check_msg->azel[19].az);
    ck_assert_msg(check_msg->azel[19].el == 26,
                  "incorrect value for azel[19].el, expected 26, is %d",
                  check_msg->azel[19].el);
    ck_assert_msg(check_msg->azel[19].sid.code == 12,
                  "incorrect value for azel[19].sid.code, expected 12, is %d",
                  check_msg->azel[19].sid.code);
    ck_assert_msg(check_msg->azel[19].sid.sat == 20,
                  "incorrect value for azel[19].sid.sat, expected 20, is %d",
                  check_msg->azel[19].sid.sat);
    ck_assert_msg(check_msg->azel[20].az == 72,
                  "incorrect value for azel[20].az, expected 72, is %d",
                  check_msg->azel[20].az);
    ck_assert_msg(check_msg->azel[20].el == 54,
                  "incorrect value for azel[20].el, expected 54, is %d",
                  check_msg->azel[20].el);
    ck_assert_msg(check_msg->azel[20].sid.code == 12,
                  "incorrect value for azel[20].sid.code, expected 12, is %d",
                  check_msg->azel[20].sid.code);
    ck_assert_msg(check_msg->azel[20].sid.sat == 27,
                  "incorrect value for azel[20].sid.sat, expected 27, is %d",
                  check_msg->azel[20].sid.sat);
    ck_assert_msg(check_msg->azel[21].az == 69,
                  "incorrect value for azel[21].az, expected 69, is %d",
                  check_msg->azel[21].az);
    ck_assert_msg(check_msg->azel[21].el == 3,
                  "incorrect value for azel[21].el, expected 3, is %d",
                  check_msg->azel[21].el);
    ck_assert_msg(check_msg->azel[21].sid.code == 12,
                  "incorrect value for azel[21].sid.code, expected 12, is %d",
                  check_msg->azel[21].sid.code);
    ck_assert_msg(check_msg->azel[21].sid.sat == 28,
                  "incorrect value for azel[21].sid.sat, expected 28, is %d",
                  check_msg->azel[21].sid.sat);
    ck_assert_msg(check_msg->azel[22].az == 158,
                  "incorrect value for azel[22].az, expected 158, is %d",
                  check_msg->azel[22].az);
    ck_assert_msg(check_msg->azel[22].el == 14,
                  "incorrect value for azel[22].el, expected 14, is %d",
                  check_msg->azel[22].el);
    ck_assert_msg(check_msg->azel[22].sid.code == 12,
                  "incorrect value for azel[22].sid.code, expected 12, is %d",
                  check_msg->azel[22].sid.code);
    ck_assert_msg(check_msg->azel[22].sid.sat == 29,
                  "incorrect value for azel[22].sid.sat, expected 29, is %d",
                  check_msg->azel[22].sid.sat);
    ck_assert_msg(check_msg->azel[23].az == 152,
                  "incorrect value for azel[23].az, expected 152, is %d",
                  check_msg->azel[23].az);
    ck_assert_msg(check_msg->azel[23].el == 68,
                  "incorrect value for azel[23].el, expected 68, is %d",
                  check_msg->azel[23].el);
    ck_assert_msg(check_msg->azel[23].sid.code == 12,
                  "incorrect value for azel[23].sid.code, expected 12, is %d",
                  check_msg->azel[23].sid.code);
    ck_assert_msg(check_msg->azel[23].sid.sat == 30,
                  "incorrect value for azel[23].sid.sat, expected 30, is %d",
                  check_msg->azel[23].sid.sat);
    ck_assert_msg(check_msg->azel[24].az == 120,
                  "incorrect value for azel[24].az, expected 120, is %d",
                  check_msg->azel[24].az);
    ck_assert_msg(check_msg->azel[24].el == 82,
                  "incorrect value for azel[24].el, expected 82, is %d",
                  check_msg->azel[24].el);
    ck_assert_msg(check_msg->azel[24].sid.code == 12,
                  "incorrect value for azel[24].sid.code, expected 12, is %d",
                  check_msg->azel[24].sid.code);
    ck_assert_msg(check_msg->azel[24].sid.sat == 32,
                  "incorrect value for azel[24].sid.sat, expected 32, is %d",
                  check_msg->azel[24].sid.sat);
    ck_assert_msg(check_msg->azel[25].az == 131,
                  "incorrect value for azel[25].az, expected 131, is %d",
                  check_msg->azel[25].az);
    ck_assert_msg(check_msg->azel[25].el == 6,
                  "incorrect value for azel[25].el, expected 6, is %d",
                  check_msg->azel[25].el);
    ck_assert_msg(check_msg->azel[25].sid.code == 14,
                  "incorrect value for azel[25].sid.code, expected 14, is %d",
                  check_msg->azel[25].sid.code);
    ck_assert_msg(check_msg->azel[25].sid.sat == 2,
                  "incorrect value for azel[25].sid.sat, expected 2, is %d",
                  check_msg->azel[25].sid.sat);
    ck_assert_msg(check_msg->azel[26].az == 27,
                  "incorrect value for azel[26].az, expected 27, is %d",
                  check_msg->azel[26].az);
    ck_assert_msg(check_msg->azel[26].el == 44,
                  "incorrect value for azel[26].el, expected 44, is %d",
                  check_msg->azel[26].el);
    ck_assert_msg(check_msg->azel[26].sid.code == 14,
                  "incorrect value for azel[26].sid.code, expected 14, is %d",
                  check_msg->azel[26].sid.code);
    ck_assert_msg(check_msg->azel[26].sid.sat == 4,
                  "incorrect value for azel[26].sid.sat, expected 4, is %d",
                  check_msg->azel[26].sid.sat);
    ck_assert_msg(check_msg->azel[27].az == 101,
                  "incorrect value for azel[27].az, expected 101, is %d",
                  check_msg->azel[27].az);
    ck_assert_msg(check_msg->azel[27].el == 21,
                  "incorrect value for azel[27].el, expected 21, is %d",
                  check_msg->azel[27].el);
    ck_assert_msg(check_msg->azel[27].sid.code == 14,
                  "incorrect value for azel[27].sid.code, expected 14, is %d",
                  check_msg->azel[27].sid.code);
    ck_assert_msg(check_msg->azel[27].sid.sat == 5,
                  "incorrect value for azel[27].sid.sat, expected 5, is %d",
                  check_msg->azel[27].sid.sat);
    ck_assert_msg(check_msg->azel[28].az == 81,
                  "incorrect value for azel[28].az, expected 81, is %d",
                  check_msg->azel[28].az);
    ck_assert_msg(check_msg->azel[28].el == 65,
                  "incorrect value for azel[28].el, expected 65, is %d",
                  check_msg->azel[28].el);
    ck_assert_msg(check_msg->azel[28].sid.code == 14,
                  "incorrect value for azel[28].sid.code, expected 14, is %d",
                  check_msg->azel[28].sid.code);
    ck_assert_msg(check_msg->azel[28].sid.sat == 9,
                  "incorrect value for azel[28].sid.sat, expected 9, is %d",
                  check_msg->azel[28].sid.sat);
    ck_assert_msg(check_msg->azel[29].az == 49,
                  "incorrect value for azel[29].az, expected 49, is %d",
                  check_msg->azel[29].az);
    ck_assert_msg(check_msg->azel[29].el == 56,
                  "incorrect value for azel[29].el, expected 56, is %d",
                  check_msg->azel[29].el);
    ck_assert_msg(check_msg->azel[29].sid.code == 14,
                  "incorrect value for azel[29].sid.code, expected 14, is %d",
                  check_msg->azel[29].sid.code);
    ck_assert_msg(check_msg->azel[29].sid.sat == 11,
                  "incorrect value for azel[29].sid.sat, expected 11, is %d",
                  check_msg->azel[29].sid.sat);
    ck_assert_msg(check_msg->azel[30].az == 59,
                  "incorrect value for azel[30].az, expected 59, is %d",
                  check_msg->azel[30].az);
    ck_assert_msg(check_msg->azel[30].el == 6,
                  "incorrect value for azel[30].el, expected 6, is %d",
                  check_msg->azel[30].el);
    ck_assert_msg(check_msg->azel[30].sid.code == 14,
                  "incorrect value for azel[30].sid.code, expected 14, is %d",
                  check_msg->azel[30].sid.code);
    ck_assert_msg(check_msg->azel[30].sid.sat == 12,
                  "incorrect value for azel[30].sid.sat, expected 12, is %d",
                  check_msg->azel[30].sid.sat);
    ck_assert_msg(check_msg->azel[31].az == 154,
                  "incorrect value for azel[31].az, expected 154, is %d",
                  check_msg->azel[31].az);
    ck_assert_msg(check_msg->azel[31].el == 4,
                  "incorrect value for azel[31].el, expected 4, is %d",
                  check_msg->azel[31].el);
    ck_assert_msg(check_msg->azel[31].sid.code == 14,
                  "incorrect value for azel[31].sid.code, expected 14, is %d",
                  check_msg->azel[31].sid.code);
    ck_assert_msg(check_msg->azel[31].sid.sat == 30,
                  "incorrect value for azel[31].sid.sat, expected 30, is %d",
                  check_msg->azel[31].sid.sat);
    ck_assert_msg(check_msg->azel[32].az == 165,
                  "incorrect value for azel[32].az, expected 165, is %d",
                  check_msg->azel[32].az);
    ck_assert_msg(check_msg->azel[32].el == 62,
                  "incorrect value for azel[32].el, expected 62, is %d",
                  check_msg->azel[32].el);
    ck_assert_msg(check_msg->azel[32].sid.code == 14,
                  "incorrect value for azel[32].sid.code, expected 14, is %d",
                  check_msg->azel[32].sid.code);
    ck_assert_msg(check_msg->azel[32].sid.sat == 36,
                  "incorrect value for azel[32].sid.sat, expected 36, is %d",
                  check_msg->azel[32].sid.sat);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_observation_MsgSvAzEl_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_observation_MsgSvAzEl");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_observation_MsgSvAzEl");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_observation_MsgSvAzEl);
  suite_add_tcase(s, tc_acq);
  return s;
}