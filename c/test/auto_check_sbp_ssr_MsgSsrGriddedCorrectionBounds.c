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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionBounds.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/ssr.h>
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

START_TEST(test_auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds) {
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

    sbp_callback_register(&sbp_state, 1534, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  254, 5,   66,  0, 43, 180, 0,  0,  0,   3,   0,   1,
        1,   10,  0,   15,  1, 0,  10,  0,  39, 232, 3,   244, 1,
        100, 200, 150, 100, 2, 5,  10,  16, 0,  17,  18,  19,  20,
        21,  6,   10,  22,  0, 23, 24,  25, 26, 27,  112, 145,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_gridded_correction_bounds.n_stub = 43;

    test_msg.ssr_gridded_correction_bounds.stub[0] = 180;

    test_msg.ssr_gridded_correction_bounds.stub[1] = 0;

    test_msg.ssr_gridded_correction_bounds.stub[2] = 0;

    test_msg.ssr_gridded_correction_bounds.stub[3] = 0;

    test_msg.ssr_gridded_correction_bounds.stub[4] = 3;

    test_msg.ssr_gridded_correction_bounds.stub[5] = 0;

    test_msg.ssr_gridded_correction_bounds.stub[6] = 1;

    test_msg.ssr_gridded_correction_bounds.stub[7] = 1;

    test_msg.ssr_gridded_correction_bounds.stub[8] = 10;

    test_msg.ssr_gridded_correction_bounds.stub[9] = 0;

    test_msg.ssr_gridded_correction_bounds.stub[10] = 15;

    test_msg.ssr_gridded_correction_bounds.stub[11] = 1;

    test_msg.ssr_gridded_correction_bounds.stub[12] = 0;

    test_msg.ssr_gridded_correction_bounds.stub[13] = 10;

    test_msg.ssr_gridded_correction_bounds.stub[14] = 0;

    test_msg.ssr_gridded_correction_bounds.stub[15] = 39;

    test_msg.ssr_gridded_correction_bounds.stub[16] = 232;

    test_msg.ssr_gridded_correction_bounds.stub[17] = 3;

    test_msg.ssr_gridded_correction_bounds.stub[18] = 244;

    test_msg.ssr_gridded_correction_bounds.stub[19] = 1;

    test_msg.ssr_gridded_correction_bounds.stub[20] = 100;

    test_msg.ssr_gridded_correction_bounds.stub[21] = 200;

    test_msg.ssr_gridded_correction_bounds.stub[22] = 150;

    test_msg.ssr_gridded_correction_bounds.stub[23] = 100;

    test_msg.ssr_gridded_correction_bounds.stub[24] = 2;

    test_msg.ssr_gridded_correction_bounds.stub[25] = 5;

    test_msg.ssr_gridded_correction_bounds.stub[26] = 10;

    test_msg.ssr_gridded_correction_bounds.stub[27] = 16;

    test_msg.ssr_gridded_correction_bounds.stub[28] = 0;

    test_msg.ssr_gridded_correction_bounds.stub[29] = 17;

    test_msg.ssr_gridded_correction_bounds.stub[30] = 18;

    test_msg.ssr_gridded_correction_bounds.stub[31] = 19;

    test_msg.ssr_gridded_correction_bounds.stub[32] = 20;

    test_msg.ssr_gridded_correction_bounds.stub[33] = 21;

    test_msg.ssr_gridded_correction_bounds.stub[34] = 6;

    test_msg.ssr_gridded_correction_bounds.stub[35] = 10;

    test_msg.ssr_gridded_correction_bounds.stub[36] = 22;

    test_msg.ssr_gridded_correction_bounds.stub[37] = 0;

    test_msg.ssr_gridded_correction_bounds.stub[38] = 23;

    test_msg.ssr_gridded_correction_bounds.stub[39] = 24;

    test_msg.ssr_gridded_correction_bounds.stub[40] = 25;

    test_msg.ssr_gridded_correction_bounds.stub[41] = 26;

    test_msg.ssr_gridded_correction_bounds.stub[42] = 27;

    sbp_message_send(&sbp_state, SbpMsgSsrGriddedCorrectionBounds, 66,
                     &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 66,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgSsrGriddedCorrectionBounds,
                                  &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_bounds.n_stub == 43,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_bounds.n_stub, expected 43, is %d",
        last_msg.msg.ssr_gridded_correction_bounds.n_stub);

    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[0] == 180,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[0], "
                  "expected 180, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[0]);
    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_bounds.stub[1] == 0,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_bounds.stub[1], expected 0, is %d",
        last_msg.msg.ssr_gridded_correction_bounds.stub[1]);
    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_bounds.stub[2] == 0,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_bounds.stub[2], expected 0, is %d",
        last_msg.msg.ssr_gridded_correction_bounds.stub[2]);
    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_bounds.stub[3] == 0,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_bounds.stub[3], expected 0, is %d",
        last_msg.msg.ssr_gridded_correction_bounds.stub[3]);
    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_bounds.stub[4] == 3,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_bounds.stub[4], expected 3, is %d",
        last_msg.msg.ssr_gridded_correction_bounds.stub[4]);
    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_bounds.stub[5] == 0,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_bounds.stub[5], expected 0, is %d",
        last_msg.msg.ssr_gridded_correction_bounds.stub[5]);
    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_bounds.stub[6] == 1,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_bounds.stub[6], expected 1, is %d",
        last_msg.msg.ssr_gridded_correction_bounds.stub[6]);
    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_bounds.stub[7] == 1,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_bounds.stub[7], expected 1, is %d",
        last_msg.msg.ssr_gridded_correction_bounds.stub[7]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[8] == 10,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[8], "
                  "expected 10, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[8]);
    ck_assert_msg(
        last_msg.msg.ssr_gridded_correction_bounds.stub[9] == 0,
        "incorrect value for "
        "last_msg.msg.ssr_gridded_correction_bounds.stub[9], expected 0, is %d",
        last_msg.msg.ssr_gridded_correction_bounds.stub[9]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[10] == 15,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[10], "
                  "expected 15, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[10]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[11] == 1,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[11], "
                  "expected 1, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[11]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[12] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[12], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[12]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[13] == 10,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[13], "
                  "expected 10, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[13]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[14] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[14], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[14]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[15] == 39,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[15], "
                  "expected 39, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[15]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[16] == 232,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[16], "
                  "expected 232, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[16]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[17] == 3,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[17], "
                  "expected 3, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[17]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[18] == 244,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[18], "
                  "expected 244, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[18]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[19] == 1,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[19], "
                  "expected 1, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[19]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[20] == 100,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[20], "
                  "expected 100, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[20]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[21] == 200,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[21], "
                  "expected 200, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[21]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[22] == 150,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[22], "
                  "expected 150, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[22]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[23] == 100,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[23], "
                  "expected 100, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[23]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[24] == 2,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[24], "
                  "expected 2, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[24]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[25] == 5,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[25], "
                  "expected 5, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[25]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[26] == 10,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[26], "
                  "expected 10, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[26]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[27] == 16,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[27], "
                  "expected 16, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[27]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[28] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[28], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[28]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[29] == 17,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[29], "
                  "expected 17, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[29]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[30] == 18,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[30], "
                  "expected 18, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[30]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[31] == 19,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[31], "
                  "expected 19, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[31]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[32] == 20,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[32], "
                  "expected 20, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[32]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[33] == 21,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[33], "
                  "expected 21, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[33]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[34] == 6,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[34], "
                  "expected 6, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[34]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[35] == 10,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[35], "
                  "expected 10, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[35]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[36] == 22,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[36], "
                  "expected 22, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[36]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[37] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[37], "
                  "expected 0, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[37]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[38] == 23,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[38], "
                  "expected 23, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[38]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[39] == 24,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[39], "
                  "expected 24, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[39]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[40] == 25,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[40], "
                  "expected 25, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[40]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[41] == 26,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[41], "
                  "expected 26, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[41]);
    ck_assert_msg(last_msg.msg.ssr_gridded_correction_bounds.stub[42] == 27,
                  "incorrect value for "
                  "last_msg.msg.ssr_gridded_correction_bounds.stub[42], "
                  "expected 27, is %d",
                  last_msg.msg.ssr_gridded_correction_bounds.stub[42]);
  }
}
END_TEST

Suite *auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds");
  tcase_add_test(tc_acq, test_auto_check_sbp_ssr_MsgSsrGriddedCorrectionBounds);
  suite_add_tcase(s, tc_acq);
  return s;
}