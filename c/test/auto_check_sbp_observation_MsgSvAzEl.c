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

START_TEST(test_auto_check_sbp_observation_MsgSvAzEl) {
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

    sbp_callback_register(&sbp_state, 0x97, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

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

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.sv_az_el.azel[0].az = 160;

    test_msg.sv_az_el.azel[0].el = 12;

    test_msg.sv_az_el.azel[0].sid.code = 0;

    test_msg.sv_az_el.azel[0].sid.sat = 8;

    test_msg.sv_az_el.azel[1].az = 139;

    test_msg.sv_az_el.azel[1].el = 66;

    test_msg.sv_az_el.azel[1].sid.code = 0;

    test_msg.sv_az_el.azel[1].sid.sat = 10;

    test_msg.sv_az_el.azel[2].az = 16;

    test_msg.sv_az_el.azel[2].el = 1;

    test_msg.sv_az_el.azel[2].sid.code = 0;

    test_msg.sv_az_el.azel[2].sid.sat = 13;

    test_msg.sv_az_el.azel[3].az = 24;

    test_msg.sv_az_el.azel[3].el = 25;

    test_msg.sv_az_el.azel[3].sid.code = 0;

    test_msg.sv_az_el.azel[3].sid.sat = 15;

    test_msg.sv_az_el.azel[4].az = 127;

    test_msg.sv_az_el.azel[4].el = 18;

    test_msg.sv_az_el.azel[4].sid.code = 0;

    test_msg.sv_az_el.azel[4].sid.sat = 16;

    test_msg.sv_az_el.azel[5].az = 42;

    test_msg.sv_az_el.azel[5].el = 53;

    test_msg.sv_az_el.azel[5].sid.code = 0;

    test_msg.sv_az_el.azel[5].sid.sat = 18;

    test_msg.sv_az_el.azel[6].az = 31;

    test_msg.sv_az_el.azel[6].el = 16;

    test_msg.sv_az_el.azel[6].sid.code = 0;

    test_msg.sv_az_el.azel[6].sid.sat = 20;

    test_msg.sv_az_el.azel[7].az = 12;

    test_msg.sv_az_el.azel[7].el = 67;

    test_msg.sv_az_el.azel[7].sid.code = 0;

    test_msg.sv_az_el.azel[7].sid.sat = 23;

    test_msg.sv_az_el.azel[8].az = 47;

    test_msg.sv_az_el.azel[8].el = 10;

    test_msg.sv_az_el.azel[8].sid.code = 0;

    test_msg.sv_az_el.azel[8].sid.sat = 24;

    test_msg.sv_az_el.azel[9].az = 116;

    test_msg.sv_az_el.azel[9].el = 8;

    test_msg.sv_az_el.azel[9].sid.code = 0;

    test_msg.sv_az_el.azel[9].sid.sat = 26;

    test_msg.sv_az_el.azel[10].az = 153;

    test_msg.sv_az_el.azel[10].el = 43;

    test_msg.sv_az_el.azel[10].sid.code = 0;

    test_msg.sv_az_el.azel[10].sid.sat = 27;

    test_msg.sv_az_el.azel[11].az = 77;

    test_msg.sv_az_el.azel[11].el = 10;

    test_msg.sv_az_el.azel[11].sid.code = 0;

    test_msg.sv_az_el.azel[11].sid.sat = 29;

    test_msg.sv_az_el.azel[12].az = 94;

    test_msg.sv_az_el.azel[12].el = 26;

    test_msg.sv_az_el.azel[12].sid.code = 0;

    test_msg.sv_az_el.azel[12].sid.sat = 32;

    test_msg.sv_az_el.azel[13].az = 16;

    test_msg.sv_az_el.azel[13].el = 58;

    test_msg.sv_az_el.azel[13].sid.code = 3;

    test_msg.sv_az_el.azel[13].sid.sat = 1;

    test_msg.sv_az_el.azel[14].az = 108;

    test_msg.sv_az_el.azel[14].el = 53;

    test_msg.sv_az_el.azel[14].sid.code = 3;

    test_msg.sv_az_el.azel[14].sid.sat = 2;

    test_msg.sv_az_el.azel[15].az = 17;

    test_msg.sv_az_el.azel[15].el = 13;

    test_msg.sv_az_el.azel[15].sid.code = 3;

    test_msg.sv_az_el.azel[15].sid.sat = 8;

    test_msg.sv_az_el.azel[16].az = 165;

    test_msg.sv_az_el.azel[16].el = 40;

    test_msg.sv_az_el.azel[16].sid.code = 3;

    test_msg.sv_az_el.azel[16].sid.sat = 17;

    test_msg.sv_az_el.azel[17].az = 63;

    test_msg.sv_az_el.azel[17].el = 35;

    test_msg.sv_az_el.azel[17].sid.code = 3;

    test_msg.sv_az_el.azel[17].sid.sat = 23;

    test_msg.sv_az_el.azel[18].az = 41;

    test_msg.sv_az_el.azel[18].el = 73;

    test_msg.sv_az_el.azel[18].sid.code = 3;

    test_msg.sv_az_el.azel[18].sid.sat = 24;

    test_msg.sv_az_el.azel[19].az = 114;

    test_msg.sv_az_el.azel[19].el = 26;

    test_msg.sv_az_el.azel[19].sid.code = 12;

    test_msg.sv_az_el.azel[19].sid.sat = 20;

    test_msg.sv_az_el.azel[20].az = 72;

    test_msg.sv_az_el.azel[20].el = 54;

    test_msg.sv_az_el.azel[20].sid.code = 12;

    test_msg.sv_az_el.azel[20].sid.sat = 27;

    test_msg.sv_az_el.azel[21].az = 69;

    test_msg.sv_az_el.azel[21].el = 3;

    test_msg.sv_az_el.azel[21].sid.code = 12;

    test_msg.sv_az_el.azel[21].sid.sat = 28;

    test_msg.sv_az_el.azel[22].az = 158;

    test_msg.sv_az_el.azel[22].el = 14;

    test_msg.sv_az_el.azel[22].sid.code = 12;

    test_msg.sv_az_el.azel[22].sid.sat = 29;

    test_msg.sv_az_el.azel[23].az = 152;

    test_msg.sv_az_el.azel[23].el = 68;

    test_msg.sv_az_el.azel[23].sid.code = 12;

    test_msg.sv_az_el.azel[23].sid.sat = 30;

    test_msg.sv_az_el.azel[24].az = 120;

    test_msg.sv_az_el.azel[24].el = 82;

    test_msg.sv_az_el.azel[24].sid.code = 12;

    test_msg.sv_az_el.azel[24].sid.sat = 32;

    test_msg.sv_az_el.azel[25].az = 131;

    test_msg.sv_az_el.azel[25].el = 6;

    test_msg.sv_az_el.azel[25].sid.code = 14;

    test_msg.sv_az_el.azel[25].sid.sat = 2;

    test_msg.sv_az_el.azel[26].az = 27;

    test_msg.sv_az_el.azel[26].el = 44;

    test_msg.sv_az_el.azel[26].sid.code = 14;

    test_msg.sv_az_el.azel[26].sid.sat = 4;

    test_msg.sv_az_el.azel[27].az = 101;

    test_msg.sv_az_el.azel[27].el = 21;

    test_msg.sv_az_el.azel[27].sid.code = 14;

    test_msg.sv_az_el.azel[27].sid.sat = 5;

    test_msg.sv_az_el.azel[28].az = 81;

    test_msg.sv_az_el.azel[28].el = 65;

    test_msg.sv_az_el.azel[28].sid.code = 14;

    test_msg.sv_az_el.azel[28].sid.sat = 9;

    test_msg.sv_az_el.azel[29].az = 49;

    test_msg.sv_az_el.azel[29].el = 56;

    test_msg.sv_az_el.azel[29].sid.code = 14;

    test_msg.sv_az_el.azel[29].sid.sat = 11;

    test_msg.sv_az_el.azel[30].az = 59;

    test_msg.sv_az_el.azel[30].el = 6;

    test_msg.sv_az_el.azel[30].sid.code = 14;

    test_msg.sv_az_el.azel[30].sid.sat = 12;

    test_msg.sv_az_el.azel[31].az = 154;

    test_msg.sv_az_el.azel[31].el = 4;

    test_msg.sv_az_el.azel[31].sid.code = 14;

    test_msg.sv_az_el.azel[31].sid.sat = 30;

    test_msg.sv_az_el.azel[32].az = 165;

    test_msg.sv_az_el.azel[32].el = 62;

    test_msg.sv_az_el.azel[32].sid.code = 14;

    test_msg.sv_az_el.azel[32].sid.sat = 36;

    test_msg.sv_az_el.n_azel = 33;

    sbp_message_send(&sbp_state, SbpMsgSvAzEl, 31183, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgSvAzEl, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.sv_az_el.azel[0].az == 160,
                  "incorrect value for last_msg.msg.sv_az_el.azel[0].az, "
                  "expected 160, is %d",
                  last_msg.msg.sv_az_el.azel[0].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[0].el == 12,
                  "incorrect value for last_msg.msg.sv_az_el.azel[0].el, "
                  "expected 12, is %d",
                  last_msg.msg.sv_az_el.azel[0].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[0].sid.code == 0,
                  "incorrect value for last_msg.msg.sv_az_el.azel[0].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[0].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[0].sid.sat == 8,
                  "incorrect value for last_msg.msg.sv_az_el.azel[0].sid.sat, "
                  "expected 8, is %d",
                  last_msg.msg.sv_az_el.azel[0].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[1].az == 139,
                  "incorrect value for last_msg.msg.sv_az_el.azel[1].az, "
                  "expected 139, is %d",
                  last_msg.msg.sv_az_el.azel[1].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[1].el == 66,
                  "incorrect value for last_msg.msg.sv_az_el.azel[1].el, "
                  "expected 66, is %d",
                  last_msg.msg.sv_az_el.azel[1].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[1].sid.code == 0,
                  "incorrect value for last_msg.msg.sv_az_el.azel[1].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[1].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[1].sid.sat == 10,
                  "incorrect value for last_msg.msg.sv_az_el.azel[1].sid.sat, "
                  "expected 10, is %d",
                  last_msg.msg.sv_az_el.azel[1].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[2].az == 16,
                  "incorrect value for last_msg.msg.sv_az_el.azel[2].az, "
                  "expected 16, is %d",
                  last_msg.msg.sv_az_el.azel[2].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[2].el == 1,
                  "incorrect value for last_msg.msg.sv_az_el.azel[2].el, "
                  "expected 1, is %d",
                  last_msg.msg.sv_az_el.azel[2].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[2].sid.code == 0,
                  "incorrect value for last_msg.msg.sv_az_el.azel[2].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[2].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[2].sid.sat == 13,
                  "incorrect value for last_msg.msg.sv_az_el.azel[2].sid.sat, "
                  "expected 13, is %d",
                  last_msg.msg.sv_az_el.azel[2].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[3].az == 24,
                  "incorrect value for last_msg.msg.sv_az_el.azel[3].az, "
                  "expected 24, is %d",
                  last_msg.msg.sv_az_el.azel[3].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[3].el == 25,
                  "incorrect value for last_msg.msg.sv_az_el.azel[3].el, "
                  "expected 25, is %d",
                  last_msg.msg.sv_az_el.azel[3].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[3].sid.code == 0,
                  "incorrect value for last_msg.msg.sv_az_el.azel[3].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[3].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[3].sid.sat == 15,
                  "incorrect value for last_msg.msg.sv_az_el.azel[3].sid.sat, "
                  "expected 15, is %d",
                  last_msg.msg.sv_az_el.azel[3].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[4].az == 127,
                  "incorrect value for last_msg.msg.sv_az_el.azel[4].az, "
                  "expected 127, is %d",
                  last_msg.msg.sv_az_el.azel[4].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[4].el == 18,
                  "incorrect value for last_msg.msg.sv_az_el.azel[4].el, "
                  "expected 18, is %d",
                  last_msg.msg.sv_az_el.azel[4].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[4].sid.code == 0,
                  "incorrect value for last_msg.msg.sv_az_el.azel[4].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[4].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[4].sid.sat == 16,
                  "incorrect value for last_msg.msg.sv_az_el.azel[4].sid.sat, "
                  "expected 16, is %d",
                  last_msg.msg.sv_az_el.azel[4].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[5].az == 42,
                  "incorrect value for last_msg.msg.sv_az_el.azel[5].az, "
                  "expected 42, is %d",
                  last_msg.msg.sv_az_el.azel[5].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[5].el == 53,
                  "incorrect value for last_msg.msg.sv_az_el.azel[5].el, "
                  "expected 53, is %d",
                  last_msg.msg.sv_az_el.azel[5].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[5].sid.code == 0,
                  "incorrect value for last_msg.msg.sv_az_el.azel[5].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[5].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[5].sid.sat == 18,
                  "incorrect value for last_msg.msg.sv_az_el.azel[5].sid.sat, "
                  "expected 18, is %d",
                  last_msg.msg.sv_az_el.azel[5].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[6].az == 31,
                  "incorrect value for last_msg.msg.sv_az_el.azel[6].az, "
                  "expected 31, is %d",
                  last_msg.msg.sv_az_el.azel[6].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[6].el == 16,
                  "incorrect value for last_msg.msg.sv_az_el.azel[6].el, "
                  "expected 16, is %d",
                  last_msg.msg.sv_az_el.azel[6].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[6].sid.code == 0,
                  "incorrect value for last_msg.msg.sv_az_el.azel[6].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[6].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[6].sid.sat == 20,
                  "incorrect value for last_msg.msg.sv_az_el.azel[6].sid.sat, "
                  "expected 20, is %d",
                  last_msg.msg.sv_az_el.azel[6].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[7].az == 12,
                  "incorrect value for last_msg.msg.sv_az_el.azel[7].az, "
                  "expected 12, is %d",
                  last_msg.msg.sv_az_el.azel[7].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[7].el == 67,
                  "incorrect value for last_msg.msg.sv_az_el.azel[7].el, "
                  "expected 67, is %d",
                  last_msg.msg.sv_az_el.azel[7].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[7].sid.code == 0,
                  "incorrect value for last_msg.msg.sv_az_el.azel[7].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[7].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[7].sid.sat == 23,
                  "incorrect value for last_msg.msg.sv_az_el.azel[7].sid.sat, "
                  "expected 23, is %d",
                  last_msg.msg.sv_az_el.azel[7].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[8].az == 47,
                  "incorrect value for last_msg.msg.sv_az_el.azel[8].az, "
                  "expected 47, is %d",
                  last_msg.msg.sv_az_el.azel[8].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[8].el == 10,
                  "incorrect value for last_msg.msg.sv_az_el.azel[8].el, "
                  "expected 10, is %d",
                  last_msg.msg.sv_az_el.azel[8].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[8].sid.code == 0,
                  "incorrect value for last_msg.msg.sv_az_el.azel[8].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[8].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[8].sid.sat == 24,
                  "incorrect value for last_msg.msg.sv_az_el.azel[8].sid.sat, "
                  "expected 24, is %d",
                  last_msg.msg.sv_az_el.azel[8].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[9].az == 116,
                  "incorrect value for last_msg.msg.sv_az_el.azel[9].az, "
                  "expected 116, is %d",
                  last_msg.msg.sv_az_el.azel[9].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[9].el == 8,
                  "incorrect value for last_msg.msg.sv_az_el.azel[9].el, "
                  "expected 8, is %d",
                  last_msg.msg.sv_az_el.azel[9].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[9].sid.code == 0,
                  "incorrect value for last_msg.msg.sv_az_el.azel[9].sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[9].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[9].sid.sat == 26,
                  "incorrect value for last_msg.msg.sv_az_el.azel[9].sid.sat, "
                  "expected 26, is %d",
                  last_msg.msg.sv_az_el.azel[9].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[10].az == 153,
                  "incorrect value for last_msg.msg.sv_az_el.azel[10].az, "
                  "expected 153, is %d",
                  last_msg.msg.sv_az_el.azel[10].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[10].el == 43,
                  "incorrect value for last_msg.msg.sv_az_el.azel[10].el, "
                  "expected 43, is %d",
                  last_msg.msg.sv_az_el.azel[10].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[10].sid.code == 0,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[10].sid.code, expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[10].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[10].sid.sat == 27,
                  "incorrect value for last_msg.msg.sv_az_el.azel[10].sid.sat, "
                  "expected 27, is %d",
                  last_msg.msg.sv_az_el.azel[10].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[11].az == 77,
                  "incorrect value for last_msg.msg.sv_az_el.azel[11].az, "
                  "expected 77, is %d",
                  last_msg.msg.sv_az_el.azel[11].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[11].el == 10,
                  "incorrect value for last_msg.msg.sv_az_el.azel[11].el, "
                  "expected 10, is %d",
                  last_msg.msg.sv_az_el.azel[11].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[11].sid.code == 0,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[11].sid.code, expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[11].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[11].sid.sat == 29,
                  "incorrect value for last_msg.msg.sv_az_el.azel[11].sid.sat, "
                  "expected 29, is %d",
                  last_msg.msg.sv_az_el.azel[11].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[12].az == 94,
                  "incorrect value for last_msg.msg.sv_az_el.azel[12].az, "
                  "expected 94, is %d",
                  last_msg.msg.sv_az_el.azel[12].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[12].el == 26,
                  "incorrect value for last_msg.msg.sv_az_el.azel[12].el, "
                  "expected 26, is %d",
                  last_msg.msg.sv_az_el.azel[12].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[12].sid.code == 0,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[12].sid.code, expected 0, is %d",
                  last_msg.msg.sv_az_el.azel[12].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[12].sid.sat == 32,
                  "incorrect value for last_msg.msg.sv_az_el.azel[12].sid.sat, "
                  "expected 32, is %d",
                  last_msg.msg.sv_az_el.azel[12].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[13].az == 16,
                  "incorrect value for last_msg.msg.sv_az_el.azel[13].az, "
                  "expected 16, is %d",
                  last_msg.msg.sv_az_el.azel[13].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[13].el == 58,
                  "incorrect value for last_msg.msg.sv_az_el.azel[13].el, "
                  "expected 58, is %d",
                  last_msg.msg.sv_az_el.azel[13].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[13].sid.code == 3,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[13].sid.code, expected 3, is %d",
                  last_msg.msg.sv_az_el.azel[13].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[13].sid.sat == 1,
                  "incorrect value for last_msg.msg.sv_az_el.azel[13].sid.sat, "
                  "expected 1, is %d",
                  last_msg.msg.sv_az_el.azel[13].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[14].az == 108,
                  "incorrect value for last_msg.msg.sv_az_el.azel[14].az, "
                  "expected 108, is %d",
                  last_msg.msg.sv_az_el.azel[14].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[14].el == 53,
                  "incorrect value for last_msg.msg.sv_az_el.azel[14].el, "
                  "expected 53, is %d",
                  last_msg.msg.sv_az_el.azel[14].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[14].sid.code == 3,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[14].sid.code, expected 3, is %d",
                  last_msg.msg.sv_az_el.azel[14].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[14].sid.sat == 2,
                  "incorrect value for last_msg.msg.sv_az_el.azel[14].sid.sat, "
                  "expected 2, is %d",
                  last_msg.msg.sv_az_el.azel[14].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[15].az == 17,
                  "incorrect value for last_msg.msg.sv_az_el.azel[15].az, "
                  "expected 17, is %d",
                  last_msg.msg.sv_az_el.azel[15].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[15].el == 13,
                  "incorrect value for last_msg.msg.sv_az_el.azel[15].el, "
                  "expected 13, is %d",
                  last_msg.msg.sv_az_el.azel[15].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[15].sid.code == 3,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[15].sid.code, expected 3, is %d",
                  last_msg.msg.sv_az_el.azel[15].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[15].sid.sat == 8,
                  "incorrect value for last_msg.msg.sv_az_el.azel[15].sid.sat, "
                  "expected 8, is %d",
                  last_msg.msg.sv_az_el.azel[15].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[16].az == 165,
                  "incorrect value for last_msg.msg.sv_az_el.azel[16].az, "
                  "expected 165, is %d",
                  last_msg.msg.sv_az_el.azel[16].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[16].el == 40,
                  "incorrect value for last_msg.msg.sv_az_el.azel[16].el, "
                  "expected 40, is %d",
                  last_msg.msg.sv_az_el.azel[16].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[16].sid.code == 3,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[16].sid.code, expected 3, is %d",
                  last_msg.msg.sv_az_el.azel[16].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[16].sid.sat == 17,
                  "incorrect value for last_msg.msg.sv_az_el.azel[16].sid.sat, "
                  "expected 17, is %d",
                  last_msg.msg.sv_az_el.azel[16].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[17].az == 63,
                  "incorrect value for last_msg.msg.sv_az_el.azel[17].az, "
                  "expected 63, is %d",
                  last_msg.msg.sv_az_el.azel[17].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[17].el == 35,
                  "incorrect value for last_msg.msg.sv_az_el.azel[17].el, "
                  "expected 35, is %d",
                  last_msg.msg.sv_az_el.azel[17].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[17].sid.code == 3,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[17].sid.code, expected 3, is %d",
                  last_msg.msg.sv_az_el.azel[17].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[17].sid.sat == 23,
                  "incorrect value for last_msg.msg.sv_az_el.azel[17].sid.sat, "
                  "expected 23, is %d",
                  last_msg.msg.sv_az_el.azel[17].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[18].az == 41,
                  "incorrect value for last_msg.msg.sv_az_el.azel[18].az, "
                  "expected 41, is %d",
                  last_msg.msg.sv_az_el.azel[18].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[18].el == 73,
                  "incorrect value for last_msg.msg.sv_az_el.azel[18].el, "
                  "expected 73, is %d",
                  last_msg.msg.sv_az_el.azel[18].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[18].sid.code == 3,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[18].sid.code, expected 3, is %d",
                  last_msg.msg.sv_az_el.azel[18].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[18].sid.sat == 24,
                  "incorrect value for last_msg.msg.sv_az_el.azel[18].sid.sat, "
                  "expected 24, is %d",
                  last_msg.msg.sv_az_el.azel[18].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[19].az == 114,
                  "incorrect value for last_msg.msg.sv_az_el.azel[19].az, "
                  "expected 114, is %d",
                  last_msg.msg.sv_az_el.azel[19].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[19].el == 26,
                  "incorrect value for last_msg.msg.sv_az_el.azel[19].el, "
                  "expected 26, is %d",
                  last_msg.msg.sv_az_el.azel[19].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[19].sid.code == 12,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[19].sid.code, expected 12, is %d",
                  last_msg.msg.sv_az_el.azel[19].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[19].sid.sat == 20,
                  "incorrect value for last_msg.msg.sv_az_el.azel[19].sid.sat, "
                  "expected 20, is %d",
                  last_msg.msg.sv_az_el.azel[19].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[20].az == 72,
                  "incorrect value for last_msg.msg.sv_az_el.azel[20].az, "
                  "expected 72, is %d",
                  last_msg.msg.sv_az_el.azel[20].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[20].el == 54,
                  "incorrect value for last_msg.msg.sv_az_el.azel[20].el, "
                  "expected 54, is %d",
                  last_msg.msg.sv_az_el.azel[20].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[20].sid.code == 12,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[20].sid.code, expected 12, is %d",
                  last_msg.msg.sv_az_el.azel[20].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[20].sid.sat == 27,
                  "incorrect value for last_msg.msg.sv_az_el.azel[20].sid.sat, "
                  "expected 27, is %d",
                  last_msg.msg.sv_az_el.azel[20].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[21].az == 69,
                  "incorrect value for last_msg.msg.sv_az_el.azel[21].az, "
                  "expected 69, is %d",
                  last_msg.msg.sv_az_el.azel[21].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[21].el == 3,
                  "incorrect value for last_msg.msg.sv_az_el.azel[21].el, "
                  "expected 3, is %d",
                  last_msg.msg.sv_az_el.azel[21].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[21].sid.code == 12,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[21].sid.code, expected 12, is %d",
                  last_msg.msg.sv_az_el.azel[21].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[21].sid.sat == 28,
                  "incorrect value for last_msg.msg.sv_az_el.azel[21].sid.sat, "
                  "expected 28, is %d",
                  last_msg.msg.sv_az_el.azel[21].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[22].az == 158,
                  "incorrect value for last_msg.msg.sv_az_el.azel[22].az, "
                  "expected 158, is %d",
                  last_msg.msg.sv_az_el.azel[22].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[22].el == 14,
                  "incorrect value for last_msg.msg.sv_az_el.azel[22].el, "
                  "expected 14, is %d",
                  last_msg.msg.sv_az_el.azel[22].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[22].sid.code == 12,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[22].sid.code, expected 12, is %d",
                  last_msg.msg.sv_az_el.azel[22].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[22].sid.sat == 29,
                  "incorrect value for last_msg.msg.sv_az_el.azel[22].sid.sat, "
                  "expected 29, is %d",
                  last_msg.msg.sv_az_el.azel[22].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[23].az == 152,
                  "incorrect value for last_msg.msg.sv_az_el.azel[23].az, "
                  "expected 152, is %d",
                  last_msg.msg.sv_az_el.azel[23].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[23].el == 68,
                  "incorrect value for last_msg.msg.sv_az_el.azel[23].el, "
                  "expected 68, is %d",
                  last_msg.msg.sv_az_el.azel[23].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[23].sid.code == 12,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[23].sid.code, expected 12, is %d",
                  last_msg.msg.sv_az_el.azel[23].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[23].sid.sat == 30,
                  "incorrect value for last_msg.msg.sv_az_el.azel[23].sid.sat, "
                  "expected 30, is %d",
                  last_msg.msg.sv_az_el.azel[23].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[24].az == 120,
                  "incorrect value for last_msg.msg.sv_az_el.azel[24].az, "
                  "expected 120, is %d",
                  last_msg.msg.sv_az_el.azel[24].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[24].el == 82,
                  "incorrect value for last_msg.msg.sv_az_el.azel[24].el, "
                  "expected 82, is %d",
                  last_msg.msg.sv_az_el.azel[24].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[24].sid.code == 12,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[24].sid.code, expected 12, is %d",
                  last_msg.msg.sv_az_el.azel[24].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[24].sid.sat == 32,
                  "incorrect value for last_msg.msg.sv_az_el.azel[24].sid.sat, "
                  "expected 32, is %d",
                  last_msg.msg.sv_az_el.azel[24].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[25].az == 131,
                  "incorrect value for last_msg.msg.sv_az_el.azel[25].az, "
                  "expected 131, is %d",
                  last_msg.msg.sv_az_el.azel[25].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[25].el == 6,
                  "incorrect value for last_msg.msg.sv_az_el.azel[25].el, "
                  "expected 6, is %d",
                  last_msg.msg.sv_az_el.azel[25].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[25].sid.code == 14,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[25].sid.code, expected 14, is %d",
                  last_msg.msg.sv_az_el.azel[25].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[25].sid.sat == 2,
                  "incorrect value for last_msg.msg.sv_az_el.azel[25].sid.sat, "
                  "expected 2, is %d",
                  last_msg.msg.sv_az_el.azel[25].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[26].az == 27,
                  "incorrect value for last_msg.msg.sv_az_el.azel[26].az, "
                  "expected 27, is %d",
                  last_msg.msg.sv_az_el.azel[26].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[26].el == 44,
                  "incorrect value for last_msg.msg.sv_az_el.azel[26].el, "
                  "expected 44, is %d",
                  last_msg.msg.sv_az_el.azel[26].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[26].sid.code == 14,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[26].sid.code, expected 14, is %d",
                  last_msg.msg.sv_az_el.azel[26].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[26].sid.sat == 4,
                  "incorrect value for last_msg.msg.sv_az_el.azel[26].sid.sat, "
                  "expected 4, is %d",
                  last_msg.msg.sv_az_el.azel[26].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[27].az == 101,
                  "incorrect value for last_msg.msg.sv_az_el.azel[27].az, "
                  "expected 101, is %d",
                  last_msg.msg.sv_az_el.azel[27].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[27].el == 21,
                  "incorrect value for last_msg.msg.sv_az_el.azel[27].el, "
                  "expected 21, is %d",
                  last_msg.msg.sv_az_el.azel[27].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[27].sid.code == 14,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[27].sid.code, expected 14, is %d",
                  last_msg.msg.sv_az_el.azel[27].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[27].sid.sat == 5,
                  "incorrect value for last_msg.msg.sv_az_el.azel[27].sid.sat, "
                  "expected 5, is %d",
                  last_msg.msg.sv_az_el.azel[27].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[28].az == 81,
                  "incorrect value for last_msg.msg.sv_az_el.azel[28].az, "
                  "expected 81, is %d",
                  last_msg.msg.sv_az_el.azel[28].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[28].el == 65,
                  "incorrect value for last_msg.msg.sv_az_el.azel[28].el, "
                  "expected 65, is %d",
                  last_msg.msg.sv_az_el.azel[28].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[28].sid.code == 14,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[28].sid.code, expected 14, is %d",
                  last_msg.msg.sv_az_el.azel[28].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[28].sid.sat == 9,
                  "incorrect value for last_msg.msg.sv_az_el.azel[28].sid.sat, "
                  "expected 9, is %d",
                  last_msg.msg.sv_az_el.azel[28].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[29].az == 49,
                  "incorrect value for last_msg.msg.sv_az_el.azel[29].az, "
                  "expected 49, is %d",
                  last_msg.msg.sv_az_el.azel[29].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[29].el == 56,
                  "incorrect value for last_msg.msg.sv_az_el.azel[29].el, "
                  "expected 56, is %d",
                  last_msg.msg.sv_az_el.azel[29].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[29].sid.code == 14,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[29].sid.code, expected 14, is %d",
                  last_msg.msg.sv_az_el.azel[29].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[29].sid.sat == 11,
                  "incorrect value for last_msg.msg.sv_az_el.azel[29].sid.sat, "
                  "expected 11, is %d",
                  last_msg.msg.sv_az_el.azel[29].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[30].az == 59,
                  "incorrect value for last_msg.msg.sv_az_el.azel[30].az, "
                  "expected 59, is %d",
                  last_msg.msg.sv_az_el.azel[30].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[30].el == 6,
                  "incorrect value for last_msg.msg.sv_az_el.azel[30].el, "
                  "expected 6, is %d",
                  last_msg.msg.sv_az_el.azel[30].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[30].sid.code == 14,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[30].sid.code, expected 14, is %d",
                  last_msg.msg.sv_az_el.azel[30].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[30].sid.sat == 12,
                  "incorrect value for last_msg.msg.sv_az_el.azel[30].sid.sat, "
                  "expected 12, is %d",
                  last_msg.msg.sv_az_el.azel[30].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[31].az == 154,
                  "incorrect value for last_msg.msg.sv_az_el.azel[31].az, "
                  "expected 154, is %d",
                  last_msg.msg.sv_az_el.azel[31].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[31].el == 4,
                  "incorrect value for last_msg.msg.sv_az_el.azel[31].el, "
                  "expected 4, is %d",
                  last_msg.msg.sv_az_el.azel[31].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[31].sid.code == 14,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[31].sid.code, expected 14, is %d",
                  last_msg.msg.sv_az_el.azel[31].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[31].sid.sat == 30,
                  "incorrect value for last_msg.msg.sv_az_el.azel[31].sid.sat, "
                  "expected 30, is %d",
                  last_msg.msg.sv_az_el.azel[31].sid.sat);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[32].az == 165,
                  "incorrect value for last_msg.msg.sv_az_el.azel[32].az, "
                  "expected 165, is %d",
                  last_msg.msg.sv_az_el.azel[32].az);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[32].el == 62,
                  "incorrect value for last_msg.msg.sv_az_el.azel[32].el, "
                  "expected 62, is %d",
                  last_msg.msg.sv_az_el.azel[32].el);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[32].sid.code == 14,
                  "incorrect value for "
                  "last_msg.msg.sv_az_el.azel[32].sid.code, expected 14, is %d",
                  last_msg.msg.sv_az_el.azel[32].sid.code);

    ck_assert_msg(last_msg.msg.sv_az_el.azel[32].sid.sat == 36,
                  "incorrect value for last_msg.msg.sv_az_el.azel[32].sid.sat, "
                  "expected 36, is %d",
                  last_msg.msg.sv_az_el.azel[32].sid.sat);

    ck_assert_msg(
        last_msg.msg.sv_az_el.n_azel == 33,
        "incorrect value for last_msg.msg.sv_az_el.n_azel, expected 33, is %d",
        last_msg.msg.sv_az_el.n_azel);
  }
}
END_TEST

Suite *auto_check_sbp_observation_MsgSvAzEl_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_observation_MsgSvAzEl");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_observation_MsgSvAzEl");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_MsgSvAzEl);
  suite_add_tcase(s, tc_acq);
  return s;
}