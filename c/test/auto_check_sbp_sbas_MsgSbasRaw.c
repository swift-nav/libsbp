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
// spec/tests/yaml/swiftnav/sbp/sbas/test_MsgSbasRaw.yaml by generate.py. Do not
// modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/sbas.h>
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

START_TEST(test_auto_check_sbp_sbas_MsgSbasRaw) {
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

    sbp_callback_register(&sbp_state, 0x7777, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  119, 119, 28,  200, 34,  131, 2,   201, 228, 233, 29,  4,   23,
        255, 0,   23,  255, 0,   23,  255, 127, 240, 2,   255, 192, 3,   127,
        247, 255, 127, 247, 255, 229, 229, 238, 170, 175, 255, 240, 167, 14,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.sbas_raw.data[0] = 23;

    test_msg.sbas_raw.data[1] = 255;

    test_msg.sbas_raw.data[2] = 0;

    test_msg.sbas_raw.data[3] = 23;

    test_msg.sbas_raw.data[4] = 255;

    test_msg.sbas_raw.data[5] = 0;

    test_msg.sbas_raw.data[6] = 23;

    test_msg.sbas_raw.data[7] = 255;

    test_msg.sbas_raw.data[8] = 127;

    test_msg.sbas_raw.data[9] = 240;

    test_msg.sbas_raw.data[10] = 2;

    test_msg.sbas_raw.data[11] = 255;

    test_msg.sbas_raw.data[12] = 192;

    test_msg.sbas_raw.data[13] = 3;

    test_msg.sbas_raw.data[14] = 127;

    test_msg.sbas_raw.data[15] = 247;

    test_msg.sbas_raw.data[16] = 255;

    test_msg.sbas_raw.data[17] = 127;

    test_msg.sbas_raw.data[18] = 247;

    test_msg.sbas_raw.data[19] = 255;

    test_msg.sbas_raw.data[20] = 229;

    test_msg.sbas_raw.data[21] = 229;

    test_msg.sbas_raw.data[22] = 238;

    test_msg.sbas_raw.data[23] = 170;

    test_msg.sbas_raw.data[24] = 175;

    test_msg.sbas_raw.data[25] = 255;

    test_msg.sbas_raw.data[26] = 240;

    test_msg.sbas_raw.message_type = 4;

    test_msg.sbas_raw.sid.code = 2;

    test_msg.sbas_raw.sid.sat = 131;

    test_msg.sbas_raw.tow = 501867721;

    sbp_message_send(&sbp_state, SbpMsgSbasRaw, 51228, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 51228,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgSbasRaw, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.sbas_raw.data[0] == 23,
        "incorrect value for last_msg.msg.sbas_raw.data[0], expected 23, is %d",
        last_msg.msg.sbas_raw.data[0]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[1] == 255,
                  "incorrect value for last_msg.msg.sbas_raw.data[1], expected "
                  "255, is %d",
                  last_msg.msg.sbas_raw.data[1]);
    ck_assert_msg(
        last_msg.msg.sbas_raw.data[2] == 0,
        "incorrect value for last_msg.msg.sbas_raw.data[2], expected 0, is %d",
        last_msg.msg.sbas_raw.data[2]);
    ck_assert_msg(
        last_msg.msg.sbas_raw.data[3] == 23,
        "incorrect value for last_msg.msg.sbas_raw.data[3], expected 23, is %d",
        last_msg.msg.sbas_raw.data[3]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[4] == 255,
                  "incorrect value for last_msg.msg.sbas_raw.data[4], expected "
                  "255, is %d",
                  last_msg.msg.sbas_raw.data[4]);
    ck_assert_msg(
        last_msg.msg.sbas_raw.data[5] == 0,
        "incorrect value for last_msg.msg.sbas_raw.data[5], expected 0, is %d",
        last_msg.msg.sbas_raw.data[5]);
    ck_assert_msg(
        last_msg.msg.sbas_raw.data[6] == 23,
        "incorrect value for last_msg.msg.sbas_raw.data[6], expected 23, is %d",
        last_msg.msg.sbas_raw.data[6]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[7] == 255,
                  "incorrect value for last_msg.msg.sbas_raw.data[7], expected "
                  "255, is %d",
                  last_msg.msg.sbas_raw.data[7]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[8] == 127,
                  "incorrect value for last_msg.msg.sbas_raw.data[8], expected "
                  "127, is %d",
                  last_msg.msg.sbas_raw.data[8]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[9] == 240,
                  "incorrect value for last_msg.msg.sbas_raw.data[9], expected "
                  "240, is %d",
                  last_msg.msg.sbas_raw.data[9]);
    ck_assert_msg(
        last_msg.msg.sbas_raw.data[10] == 2,
        "incorrect value for last_msg.msg.sbas_raw.data[10], expected 2, is %d",
        last_msg.msg.sbas_raw.data[10]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[11] == 255,
                  "incorrect value for last_msg.msg.sbas_raw.data[11], "
                  "expected 255, is %d",
                  last_msg.msg.sbas_raw.data[11]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[12] == 192,
                  "incorrect value for last_msg.msg.sbas_raw.data[12], "
                  "expected 192, is %d",
                  last_msg.msg.sbas_raw.data[12]);
    ck_assert_msg(
        last_msg.msg.sbas_raw.data[13] == 3,
        "incorrect value for last_msg.msg.sbas_raw.data[13], expected 3, is %d",
        last_msg.msg.sbas_raw.data[13]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[14] == 127,
                  "incorrect value for last_msg.msg.sbas_raw.data[14], "
                  "expected 127, is %d",
                  last_msg.msg.sbas_raw.data[14]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[15] == 247,
                  "incorrect value for last_msg.msg.sbas_raw.data[15], "
                  "expected 247, is %d",
                  last_msg.msg.sbas_raw.data[15]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[16] == 255,
                  "incorrect value for last_msg.msg.sbas_raw.data[16], "
                  "expected 255, is %d",
                  last_msg.msg.sbas_raw.data[16]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[17] == 127,
                  "incorrect value for last_msg.msg.sbas_raw.data[17], "
                  "expected 127, is %d",
                  last_msg.msg.sbas_raw.data[17]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[18] == 247,
                  "incorrect value for last_msg.msg.sbas_raw.data[18], "
                  "expected 247, is %d",
                  last_msg.msg.sbas_raw.data[18]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[19] == 255,
                  "incorrect value for last_msg.msg.sbas_raw.data[19], "
                  "expected 255, is %d",
                  last_msg.msg.sbas_raw.data[19]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[20] == 229,
                  "incorrect value for last_msg.msg.sbas_raw.data[20], "
                  "expected 229, is %d",
                  last_msg.msg.sbas_raw.data[20]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[21] == 229,
                  "incorrect value for last_msg.msg.sbas_raw.data[21], "
                  "expected 229, is %d",
                  last_msg.msg.sbas_raw.data[21]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[22] == 238,
                  "incorrect value for last_msg.msg.sbas_raw.data[22], "
                  "expected 238, is %d",
                  last_msg.msg.sbas_raw.data[22]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[23] == 170,
                  "incorrect value for last_msg.msg.sbas_raw.data[23], "
                  "expected 170, is %d",
                  last_msg.msg.sbas_raw.data[23]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[24] == 175,
                  "incorrect value for last_msg.msg.sbas_raw.data[24], "
                  "expected 175, is %d",
                  last_msg.msg.sbas_raw.data[24]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[25] == 255,
                  "incorrect value for last_msg.msg.sbas_raw.data[25], "
                  "expected 255, is %d",
                  last_msg.msg.sbas_raw.data[25]);
    ck_assert_msg(last_msg.msg.sbas_raw.data[26] == 240,
                  "incorrect value for last_msg.msg.sbas_raw.data[26], "
                  "expected 240, is %d",
                  last_msg.msg.sbas_raw.data[26]);

    ck_assert_msg(last_msg.msg.sbas_raw.message_type == 4,
                  "incorrect value for last_msg.msg.sbas_raw.message_type, "
                  "expected 4, is %d",
                  last_msg.msg.sbas_raw.message_type);

    ck_assert_msg(
        last_msg.msg.sbas_raw.sid.code == 2,
        "incorrect value for last_msg.msg.sbas_raw.sid.code, expected 2, is %d",
        last_msg.msg.sbas_raw.sid.code);

    ck_assert_msg(last_msg.msg.sbas_raw.sid.sat == 131,
                  "incorrect value for last_msg.msg.sbas_raw.sid.sat, expected "
                  "131, is %d",
                  last_msg.msg.sbas_raw.sid.sat);

    ck_assert_msg(last_msg.msg.sbas_raw.tow == 501867721,
                  "incorrect value for last_msg.msg.sbas_raw.tow, expected "
                  "501867721, is %d",
                  last_msg.msg.sbas_raw.tow);
  }
}
END_TEST

Suite *auto_check_sbp_sbas_MsgSbasRaw_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_sbas_MsgSbasRaw");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_sbas_MsgSbasRaw");
  tcase_add_test(tc_acq, test_auto_check_sbp_sbas_MsgSbasRaw);
  suite_add_tcase(s, tc_acq);
  return s;
}