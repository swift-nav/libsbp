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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCovGNSS.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/navigation.h>
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

START_TEST(test_auto_check_sbp_navigation_MsgPosECEFCovGNSS) {
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

    sbp_callback_register(&sbp_state, 0x234, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  52,  2,   0,   16,  54,  24,  229, 233, 29,  52, 254, 158,
        218, 42,  142, 68,  193, 69,  162, 89,  91,  34,  68, 80,  193,
        131, 21,  176, 129, 239, 174, 77,  65,  158, 232, 30, 60,  218,
        221, 20,  60,  129, 136, 198, 187, 205, 120, 166, 60, 5,   166,
        35,  188, 122, 177, 115, 60,  18,  4,   159, 102,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_cov_gnss.cov_x_x = 0.009699014946818352;

    test_msg.pos_ecef_cov_gnss.cov_x_y = 0.009086096659302711;

    test_msg.pos_ecef_cov_gnss.cov_x_z = -0.006058753002434969;

    test_msg.pos_ecef_cov_gnss.cov_y_y = 0.020321274176239967;

    test_msg.pos_ecef_cov_gnss.cov_y_z = -0.009988312609493732;

    test_msg.pos_ecef_cov_gnss.cov_z_z = 0.01487385667860508;

    test_msg.pos_ecef_cov_gnss.flags = 4;

    test_msg.pos_ecef_cov_gnss.n_sats = 18;

    test_msg.pos_ecef_cov_gnss.tow = 501867800;

    test_msg.pos_ecef_cov_gnss.x = -2694229.7079770807;

    test_msg.pos_ecef_cov_gnss.y = -4264073.427345817;

    test_msg.pos_ecef_cov_gnss.z = 3890655.013186158;

    sbp_message_send(&sbp_state, SbpMsgPosEcefCovGnss, 4096, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 4096,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefCovGnss, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg((last_msg.msg.pos_ecef_cov_gnss.cov_x_x * 100 -
                   0.00969901494682 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_x_x, "
                  "expected 0.00969901494682, is %s",
                  last_msg.msg.pos_ecef_cov_gnss.cov_x_x);

    ck_assert_msg((last_msg.msg.pos_ecef_cov_gnss.cov_x_y * 100 -
                   0.0090860966593 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_x_y, "
                  "expected 0.0090860966593, is %s",
                  last_msg.msg.pos_ecef_cov_gnss.cov_x_y);

    ck_assert_msg((last_msg.msg.pos_ecef_cov_gnss.cov_x_z * 100 -
                   -0.00605875300243 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_x_z, "
                  "expected -0.00605875300243, is %s",
                  last_msg.msg.pos_ecef_cov_gnss.cov_x_z);

    ck_assert_msg((last_msg.msg.pos_ecef_cov_gnss.cov_y_y * 100 -
                   0.0203212741762 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_y_y, "
                  "expected 0.0203212741762, is %s",
                  last_msg.msg.pos_ecef_cov_gnss.cov_y_y);

    ck_assert_msg((last_msg.msg.pos_ecef_cov_gnss.cov_y_z * 100 -
                   -0.00998831260949 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_y_z, "
                  "expected -0.00998831260949, is %s",
                  last_msg.msg.pos_ecef_cov_gnss.cov_y_z);

    ck_assert_msg((last_msg.msg.pos_ecef_cov_gnss.cov_z_z * 100 -
                   0.0148738566786 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_z_z, "
                  "expected 0.0148738566786, is %s",
                  last_msg.msg.pos_ecef_cov_gnss.cov_z_z);

    ck_assert_msg(last_msg.msg.pos_ecef_cov_gnss.flags == 4,
                  "incorrect value for last_msg.msg.pos_ecef_cov_gnss.flags, "
                  "expected 4, is %d",
                  last_msg.msg.pos_ecef_cov_gnss.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_cov_gnss.n_sats == 18,
                  "incorrect value for last_msg.msg.pos_ecef_cov_gnss.n_sats, "
                  "expected 18, is %d",
                  last_msg.msg.pos_ecef_cov_gnss.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_cov_gnss.tow == 501867800,
                  "incorrect value for last_msg.msg.pos_ecef_cov_gnss.tow, "
                  "expected 501867800, is %d",
                  last_msg.msg.pos_ecef_cov_gnss.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_cov_gnss.x * 100 - -2694229.70798 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_cov_gnss.x, expected "
        "-2694229.70798, is %s",
        last_msg.msg.pos_ecef_cov_gnss.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_cov_gnss.y * 100 - -4264073.42735 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_cov_gnss.y, expected "
        "-4264073.42735, is %s",
        last_msg.msg.pos_ecef_cov_gnss.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_cov_gnss.z * 100 - 3890655.01319 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_cov_gnss.z, expected "
        "3890655.01319, is %s",
        last_msg.msg.pos_ecef_cov_gnss.z);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgPosECEFCovGNSS_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgPosECEFCovGNSS");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_navigation_MsgPosECEFCovGNSS");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgPosECEFCovGNSS);
  suite_add_tcase(s, tc_acq);
  return s;
}