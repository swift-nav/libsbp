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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApc.yaml by generate.py.
// Do not modify by hand!

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

START_TEST(test_auto_check_sbp_ssr_MsgSsrSatelliteApc) {
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

    sbp_callback_register(&sbp_state, 0x605, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5,  6,  0,  0,  41,  127, 58,  9,   0,   174, 8,   1,
        2,  3,  2,  0,  4,  61,  0,   1,   0,   255, 255, 217, 2,
        11, 10, 8,  5,  1,  252, 248, 246, 246, 246, 249, 252, 0,
        6,  12, 22, 30, 41, 41,  41,  41,  144, 161,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_satellite_apc.apc[0].pco[0] = 1;

    test_msg.ssr_satellite_apc.apc[0].pco[1] = -1;

    test_msg.ssr_satellite_apc.apc[0].pco[2] = 729;

    test_msg.ssr_satellite_apc.apc[0].pcv[0] = 11;

    test_msg.ssr_satellite_apc.apc[0].pcv[1] = 10;

    test_msg.ssr_satellite_apc.apc[0].pcv[2] = 8;

    test_msg.ssr_satellite_apc.apc[0].pcv[3] = 5;

    test_msg.ssr_satellite_apc.apc[0].pcv[4] = 1;

    test_msg.ssr_satellite_apc.apc[0].pcv[5] = -4;

    test_msg.ssr_satellite_apc.apc[0].pcv[6] = -8;

    test_msg.ssr_satellite_apc.apc[0].pcv[7] = -10;

    test_msg.ssr_satellite_apc.apc[0].pcv[8] = -10;

    test_msg.ssr_satellite_apc.apc[0].pcv[9] = -10;

    test_msg.ssr_satellite_apc.apc[0].pcv[10] = -7;

    test_msg.ssr_satellite_apc.apc[0].pcv[11] = -4;

    test_msg.ssr_satellite_apc.apc[0].pcv[12] = 0;

    test_msg.ssr_satellite_apc.apc[0].pcv[13] = 6;

    test_msg.ssr_satellite_apc.apc[0].pcv[14] = 12;

    test_msg.ssr_satellite_apc.apc[0].pcv[15] = 22;

    test_msg.ssr_satellite_apc.apc[0].pcv[16] = 30;

    test_msg.ssr_satellite_apc.apc[0].pcv[17] = 41;

    test_msg.ssr_satellite_apc.apc[0].pcv[18] = 41;

    test_msg.ssr_satellite_apc.apc[0].pcv[19] = 41;

    test_msg.ssr_satellite_apc.apc[0].pcv[20] = 41;

    test_msg.ssr_satellite_apc.apc[0].sat_info = 4;

    test_msg.ssr_satellite_apc.apc[0].sid.code = 0;

    test_msg.ssr_satellite_apc.apc[0].sid.sat = 2;

    test_msg.ssr_satellite_apc.apc[0].svn = 61;

    test_msg.ssr_satellite_apc.iod_ssr = 3;

    test_msg.ssr_satellite_apc.sol_id = 2;

    test_msg.ssr_satellite_apc.time.tow = 604799;

    test_msg.ssr_satellite_apc.time.wn = 2222;

    test_msg.ssr_satellite_apc.update_interval = 1;

    sbp_message_send(&sbp_state, SbpMsgSsrSatelliteApc, 0, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 0,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgSsrSatelliteApc, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pco[0] == 1,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pco[0], "
        "expected 1, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pco[0]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pco[1] == -1,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pco[1], "
        "expected -1, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pco[1]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pco[2] == 729,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pco[2], "
        "expected 729, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pco[2]);

    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[0] == 11,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[0], "
        "expected 11, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[0]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[1] == 10,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[1], "
        "expected 10, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[1]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[2] == 8,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[2], "
        "expected 8, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[2]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[3] == 5,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[3], "
        "expected 5, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[3]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[4] == 1,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[4], "
        "expected 1, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[4]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[5] == -4,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[5], "
        "expected -4, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[5]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[6] == -8,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[6], "
        "expected -8, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[6]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[7] == -10,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[7], "
        "expected -10, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[7]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[8] == -10,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[8], "
        "expected -10, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[8]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[9] == -10,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[9], "
        "expected -10, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[9]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[10] == -7,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[10], "
        "expected -7, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[10]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[11] == -4,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[11], "
        "expected -4, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[11]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[12] == 0,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[12], "
        "expected 0, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[12]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[13] == 6,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[13], "
        "expected 6, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[13]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[14] == 12,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[14], "
        "expected 12, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[14]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[15] == 22,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[15], "
        "expected 22, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[15]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[16] == 30,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[16], "
        "expected 30, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[16]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[17] == 41,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[17], "
        "expected 41, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[17]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[18] == 41,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[18], "
        "expected 41, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[18]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[19] == 41,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[19], "
        "expected 41, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[19]);
    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[20] == 41,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].pcv[20], "
        "expected 41, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].pcv[20]);

    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].sat_info == 4,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].sat_info, "
        "expected 4, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].sat_info);

    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].sid.code == 0,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].sid.code, "
        "expected 0, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].sid.code);

    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].sid.sat == 2,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].sid.sat, "
        "expected 2, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].sid.sat);

    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.apc[0].svn == 61,
        "incorrect value for last_msg.msg.ssr_satellite_apc.apc[0].svn, "
        "expected 61, is %d",
        last_msg.msg.ssr_satellite_apc.apc[0].svn);

    ck_assert_msg(last_msg.msg.ssr_satellite_apc.iod_ssr == 3,
                  "incorrect value for last_msg.msg.ssr_satellite_apc.iod_ssr, "
                  "expected 3, is %d",
                  last_msg.msg.ssr_satellite_apc.iod_ssr);

    ck_assert_msg(last_msg.msg.ssr_satellite_apc.sol_id == 2,
                  "incorrect value for last_msg.msg.ssr_satellite_apc.sol_id, "
                  "expected 2, is %d",
                  last_msg.msg.ssr_satellite_apc.sol_id);

    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.time.tow == 604799,
        "incorrect value for last_msg.msg.ssr_satellite_apc.time.tow, expected "
        "604799, is %d",
        last_msg.msg.ssr_satellite_apc.time.tow);

    ck_assert_msg(last_msg.msg.ssr_satellite_apc.time.wn == 2222,
                  "incorrect value for last_msg.msg.ssr_satellite_apc.time.wn, "
                  "expected 2222, is %d",
                  last_msg.msg.ssr_satellite_apc.time.wn);

    ck_assert_msg(
        last_msg.msg.ssr_satellite_apc.update_interval == 1,
        "incorrect value for last_msg.msg.ssr_satellite_apc.update_interval, "
        "expected 1, is %d",
        last_msg.msg.ssr_satellite_apc.update_interval);
  }
}
END_TEST

Suite *auto_check_sbp_ssr_MsgSsrSatelliteApc_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_ssr_MsgSsrSatelliteApc");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_ssr_MsgSsrSatelliteApc");
  tcase_add_test(tc_acq, test_auto_check_sbp_ssr_MsgSsrSatelliteApc);
  suite_add_tcase(s, tc_acq);
  return s;
}