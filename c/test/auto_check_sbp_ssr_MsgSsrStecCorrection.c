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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrection.yaml by
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

START_TEST(test_auto_check_sbp_ssr_MsgSsrStecCorrection) {
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

    sbp_callback_register(&sbp_state, 1533, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 253, 5,  66, 0,  38, 180, 0, 0,  0,  3,  0,  1,   1,  10, 0,
        15, 1,   0,  10, 0,  2,  1,   1, 1,  63, 0,  62, 0,   61, 0,  60,
        0,  31,  15, 5,  63, 0,  64,  0, 65, 0,  66, 0,  119, 50,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_stec_correction.n_stub = 38;

    test_msg.ssr_stec_correction.stub[0] = 180;

    test_msg.ssr_stec_correction.stub[1] = 0;

    test_msg.ssr_stec_correction.stub[2] = 0;

    test_msg.ssr_stec_correction.stub[3] = 0;

    test_msg.ssr_stec_correction.stub[4] = 3;

    test_msg.ssr_stec_correction.stub[5] = 0;

    test_msg.ssr_stec_correction.stub[6] = 1;

    test_msg.ssr_stec_correction.stub[7] = 1;

    test_msg.ssr_stec_correction.stub[8] = 10;

    test_msg.ssr_stec_correction.stub[9] = 0;

    test_msg.ssr_stec_correction.stub[10] = 15;

    test_msg.ssr_stec_correction.stub[11] = 1;

    test_msg.ssr_stec_correction.stub[12] = 0;

    test_msg.ssr_stec_correction.stub[13] = 10;

    test_msg.ssr_stec_correction.stub[14] = 0;

    test_msg.ssr_stec_correction.stub[15] = 2;

    test_msg.ssr_stec_correction.stub[16] = 1;

    test_msg.ssr_stec_correction.stub[17] = 1;

    test_msg.ssr_stec_correction.stub[18] = 1;

    test_msg.ssr_stec_correction.stub[19] = 63;

    test_msg.ssr_stec_correction.stub[20] = 0;

    test_msg.ssr_stec_correction.stub[21] = 62;

    test_msg.ssr_stec_correction.stub[22] = 0;

    test_msg.ssr_stec_correction.stub[23] = 61;

    test_msg.ssr_stec_correction.stub[24] = 0;

    test_msg.ssr_stec_correction.stub[25] = 60;

    test_msg.ssr_stec_correction.stub[26] = 0;

    test_msg.ssr_stec_correction.stub[27] = 31;

    test_msg.ssr_stec_correction.stub[28] = 15;

    test_msg.ssr_stec_correction.stub[29] = 5;

    test_msg.ssr_stec_correction.stub[30] = 63;

    test_msg.ssr_stec_correction.stub[31] = 0;

    test_msg.ssr_stec_correction.stub[32] = 64;

    test_msg.ssr_stec_correction.stub[33] = 0;

    test_msg.ssr_stec_correction.stub[34] = 65;

    test_msg.ssr_stec_correction.stub[35] = 0;

    test_msg.ssr_stec_correction.stub[36] = 66;

    test_msg.ssr_stec_correction.stub[37] = 0;

    sbp_message_send(&sbp_state, SbpMsgSsrStecCorrection, 66, &test_msg,
                     &dummy_write);

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

    ck_assert_msg(
        sbp_message_cmp(SbpMsgSsrStecCorrection, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.ssr_stec_correction.n_stub == 38,
                  "incorrect value for "
                  "last_msg.msg.ssr_stec_correction.n_stub, expected 38, is %d",
                  last_msg.msg.ssr_stec_correction.n_stub);

    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[0] == 180,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[0], "
        "expected 180, is %d",
        last_msg.msg.ssr_stec_correction.stub[0]);
    ck_assert_msg(last_msg.msg.ssr_stec_correction.stub[1] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_stec_correction.stub[1], expected 0, is %d",
                  last_msg.msg.ssr_stec_correction.stub[1]);
    ck_assert_msg(last_msg.msg.ssr_stec_correction.stub[2] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_stec_correction.stub[2], expected 0, is %d",
                  last_msg.msg.ssr_stec_correction.stub[2]);
    ck_assert_msg(last_msg.msg.ssr_stec_correction.stub[3] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_stec_correction.stub[3], expected 0, is %d",
                  last_msg.msg.ssr_stec_correction.stub[3]);
    ck_assert_msg(last_msg.msg.ssr_stec_correction.stub[4] == 3,
                  "incorrect value for "
                  "last_msg.msg.ssr_stec_correction.stub[4], expected 3, is %d",
                  last_msg.msg.ssr_stec_correction.stub[4]);
    ck_assert_msg(last_msg.msg.ssr_stec_correction.stub[5] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_stec_correction.stub[5], expected 0, is %d",
                  last_msg.msg.ssr_stec_correction.stub[5]);
    ck_assert_msg(last_msg.msg.ssr_stec_correction.stub[6] == 1,
                  "incorrect value for "
                  "last_msg.msg.ssr_stec_correction.stub[6], expected 1, is %d",
                  last_msg.msg.ssr_stec_correction.stub[6]);
    ck_assert_msg(last_msg.msg.ssr_stec_correction.stub[7] == 1,
                  "incorrect value for "
                  "last_msg.msg.ssr_stec_correction.stub[7], expected 1, is %d",
                  last_msg.msg.ssr_stec_correction.stub[7]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[8] == 10,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[8], "
        "expected 10, is %d",
        last_msg.msg.ssr_stec_correction.stub[8]);
    ck_assert_msg(last_msg.msg.ssr_stec_correction.stub[9] == 0,
                  "incorrect value for "
                  "last_msg.msg.ssr_stec_correction.stub[9], expected 0, is %d",
                  last_msg.msg.ssr_stec_correction.stub[9]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[10] == 15,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[10], "
        "expected 15, is %d",
        last_msg.msg.ssr_stec_correction.stub[10]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[11] == 1,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[11], "
        "expected 1, is %d",
        last_msg.msg.ssr_stec_correction.stub[11]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[12] == 0,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[12], "
        "expected 0, is %d",
        last_msg.msg.ssr_stec_correction.stub[12]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[13] == 10,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[13], "
        "expected 10, is %d",
        last_msg.msg.ssr_stec_correction.stub[13]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[14] == 0,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[14], "
        "expected 0, is %d",
        last_msg.msg.ssr_stec_correction.stub[14]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[15] == 2,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[15], "
        "expected 2, is %d",
        last_msg.msg.ssr_stec_correction.stub[15]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[16] == 1,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[16], "
        "expected 1, is %d",
        last_msg.msg.ssr_stec_correction.stub[16]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[17] == 1,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[17], "
        "expected 1, is %d",
        last_msg.msg.ssr_stec_correction.stub[17]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[18] == 1,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[18], "
        "expected 1, is %d",
        last_msg.msg.ssr_stec_correction.stub[18]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[19] == 63,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[19], "
        "expected 63, is %d",
        last_msg.msg.ssr_stec_correction.stub[19]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[20] == 0,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[20], "
        "expected 0, is %d",
        last_msg.msg.ssr_stec_correction.stub[20]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[21] == 62,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[21], "
        "expected 62, is %d",
        last_msg.msg.ssr_stec_correction.stub[21]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[22] == 0,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[22], "
        "expected 0, is %d",
        last_msg.msg.ssr_stec_correction.stub[22]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[23] == 61,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[23], "
        "expected 61, is %d",
        last_msg.msg.ssr_stec_correction.stub[23]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[24] == 0,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[24], "
        "expected 0, is %d",
        last_msg.msg.ssr_stec_correction.stub[24]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[25] == 60,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[25], "
        "expected 60, is %d",
        last_msg.msg.ssr_stec_correction.stub[25]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[26] == 0,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[26], "
        "expected 0, is %d",
        last_msg.msg.ssr_stec_correction.stub[26]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[27] == 31,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[27], "
        "expected 31, is %d",
        last_msg.msg.ssr_stec_correction.stub[27]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[28] == 15,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[28], "
        "expected 15, is %d",
        last_msg.msg.ssr_stec_correction.stub[28]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[29] == 5,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[29], "
        "expected 5, is %d",
        last_msg.msg.ssr_stec_correction.stub[29]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[30] == 63,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[30], "
        "expected 63, is %d",
        last_msg.msg.ssr_stec_correction.stub[30]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[31] == 0,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[31], "
        "expected 0, is %d",
        last_msg.msg.ssr_stec_correction.stub[31]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[32] == 64,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[32], "
        "expected 64, is %d",
        last_msg.msg.ssr_stec_correction.stub[32]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[33] == 0,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[33], "
        "expected 0, is %d",
        last_msg.msg.ssr_stec_correction.stub[33]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[34] == 65,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[34], "
        "expected 65, is %d",
        last_msg.msg.ssr_stec_correction.stub[34]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[35] == 0,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[35], "
        "expected 0, is %d",
        last_msg.msg.ssr_stec_correction.stub[35]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[36] == 66,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[36], "
        "expected 66, is %d",
        last_msg.msg.ssr_stec_correction.stub[36]);
    ck_assert_msg(
        last_msg.msg.ssr_stec_correction.stub[37] == 0,
        "incorrect value for last_msg.msg.ssr_stec_correction.stub[37], "
        "expected 0, is %d",
        last_msg.msg.ssr_stec_correction.stub[37]);
  }
}
END_TEST

Suite *auto_check_sbp_ssr_MsgSsrStecCorrection_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_ssr_MsgSsrStecCorrection");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_ssr_MsgSsrStecCorrection");
  tcase_add_test(tc_acq, test_auto_check_sbp_ssr_MsgSsrStecCorrection);
  suite_add_tcase(s, tc_acq);
  return s;
}