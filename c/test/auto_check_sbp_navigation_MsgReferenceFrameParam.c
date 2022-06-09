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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgReferenceFrameParam.yaml by
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

START_TEST(test_auto_check_sbp_navigation_MsgReferenceFrameParam) {
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

    sbp_callback_register(&sbp_state, 580, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 68, 2,  66, 0, 124, 1,  102, 111, 111, 0,  0,  0,   0, 0,  0,  0,
        0,  0,  0,  0,  0, 0,   0,  0,   0,   0,   0,  0,  0,   0, 0,  0,  0,
        0,  0,  0,  0,  0, 98,  97, 114, 0,   0,   0,  0,  0,   0, 0,  0,  0,
        0,  0,  0,  0,  0, 0,   0,  0,   0,   0,   0,  0,  0,   0, 0,  0,  0,
        0,  0,  0,  4,  5, 0,   6,  0,   7,   0,   0,  0,  8,   0, 0,  0,  9,
        0,  0,  0,  10, 0, 0,   0,  11,  0,   0,   0,  12, 0,   0, 0,  13, 0,
        0,  0,  14, 0,  0, 0,   15, 0,   0,   0,   16, 0,  0,   0, 17, 0,  0,
        0,  18, 0,  0,  0, 19,  0,  0,   0,   20,  0,  6,  161,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.reference_frame_param.delta_X0 = 7;

    test_msg.reference_frame_param.delta_Y0 = 8;

    test_msg.reference_frame_param.delta_Z0 = 9;

    test_msg.reference_frame_param.dot_delta_X0 = 14;

    test_msg.reference_frame_param.dot_delta_Y0 = 15;

    test_msg.reference_frame_param.dot_delta_Z0 = 16;

    test_msg.reference_frame_param.dot_scale = 20;

    test_msg.reference_frame_param.dot_theta_01 = 17;

    test_msg.reference_frame_param.dot_theta_02 = 18;

    test_msg.reference_frame_param.dot_theta_03 = 19;

    test_msg.reference_frame_param.re_t0 = 6;

    test_msg.reference_frame_param.scale = 13;

    test_msg.reference_frame_param.sin = 4;

    {
      const char assign_string[] = {
          (char)102, (char)111, (char)111, (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.reference_frame_param.sn, assign_string,
             sizeof(assign_string));
    }

    test_msg.reference_frame_param.ssr_iod = 1;

    test_msg.reference_frame_param.theta_01 = 10;

    test_msg.reference_frame_param.theta_02 = 11;

    test_msg.reference_frame_param.theta_03 = 12;

    {
      const char assign_string[] = {
          (char)98, (char)97, (char)114, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0};
      memcpy(test_msg.reference_frame_param.tn, assign_string,
             sizeof(assign_string));
    }

    test_msg.reference_frame_param.utn = 5;

    sbp_message_send(&sbp_state, SbpMsgReferenceFrameParam, 66, &test_msg,
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

    ck_assert_msg(sbp_message_cmp(SbpMsgReferenceFrameParam, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.reference_frame_param.delta_X0 == 7,
        "incorrect value for last_msg.msg.reference_frame_param.delta_X0, "
        "expected 7, is %d",
        last_msg.msg.reference_frame_param.delta_X0);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.delta_Y0 == 8,
        "incorrect value for last_msg.msg.reference_frame_param.delta_Y0, "
        "expected 8, is %d",
        last_msg.msg.reference_frame_param.delta_Y0);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.delta_Z0 == 9,
        "incorrect value for last_msg.msg.reference_frame_param.delta_Z0, "
        "expected 9, is %d",
        last_msg.msg.reference_frame_param.delta_Z0);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.dot_delta_X0 == 14,
        "incorrect value for last_msg.msg.reference_frame_param.dot_delta_X0, "
        "expected 14, is %d",
        last_msg.msg.reference_frame_param.dot_delta_X0);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.dot_delta_Y0 == 15,
        "incorrect value for last_msg.msg.reference_frame_param.dot_delta_Y0, "
        "expected 15, is %d",
        last_msg.msg.reference_frame_param.dot_delta_Y0);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.dot_delta_Z0 == 16,
        "incorrect value for last_msg.msg.reference_frame_param.dot_delta_Z0, "
        "expected 16, is %d",
        last_msg.msg.reference_frame_param.dot_delta_Z0);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.dot_scale == 20,
        "incorrect value for last_msg.msg.reference_frame_param.dot_scale, "
        "expected 20, is %d",
        last_msg.msg.reference_frame_param.dot_scale);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.dot_theta_01 == 17,
        "incorrect value for last_msg.msg.reference_frame_param.dot_theta_01, "
        "expected 17, is %d",
        last_msg.msg.reference_frame_param.dot_theta_01);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.dot_theta_02 == 18,
        "incorrect value for last_msg.msg.reference_frame_param.dot_theta_02, "
        "expected 18, is %d",
        last_msg.msg.reference_frame_param.dot_theta_02);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.dot_theta_03 == 19,
        "incorrect value for last_msg.msg.reference_frame_param.dot_theta_03, "
        "expected 19, is %d",
        last_msg.msg.reference_frame_param.dot_theta_03);

    ck_assert_msg(last_msg.msg.reference_frame_param.re_t0 == 6,
                  "incorrect value for "
                  "last_msg.msg.reference_frame_param.re_t0, expected 6, is %d",
                  last_msg.msg.reference_frame_param.re_t0);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.scale == 13,
        "incorrect value for last_msg.msg.reference_frame_param.scale, "
        "expected 13, is %d",
        last_msg.msg.reference_frame_param.scale);

    ck_assert_msg(last_msg.msg.reference_frame_param.sin == 4,
                  "incorrect value for last_msg.msg.reference_frame_param.sin, "
                  "expected 4, is %d",
                  last_msg.msg.reference_frame_param.sin);

    {
      const char check_string[] = {
          (char)102, (char)111, (char)111, (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.reference_frame_param.sn, check_string,
                 sizeof(check_string)) == 0,
          "incorrect value for last_msg.msg.reference_frame_param.sn, expected "
          "string '%s', is '%s'",
          check_string, last_msg.msg.reference_frame_param.sn);
    }

    ck_assert_msg(
        last_msg.msg.reference_frame_param.ssr_iod == 1,
        "incorrect value for last_msg.msg.reference_frame_param.ssr_iod, "
        "expected 1, is %d",
        last_msg.msg.reference_frame_param.ssr_iod);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.theta_01 == 10,
        "incorrect value for last_msg.msg.reference_frame_param.theta_01, "
        "expected 10, is %d",
        last_msg.msg.reference_frame_param.theta_01);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.theta_02 == 11,
        "incorrect value for last_msg.msg.reference_frame_param.theta_02, "
        "expected 11, is %d",
        last_msg.msg.reference_frame_param.theta_02);

    ck_assert_msg(
        last_msg.msg.reference_frame_param.theta_03 == 12,
        "incorrect value for last_msg.msg.reference_frame_param.theta_03, "
        "expected 12, is %d",
        last_msg.msg.reference_frame_param.theta_03);

    {
      const char check_string[] = {
          (char)98, (char)97, (char)114, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.reference_frame_param.tn, check_string,
                 sizeof(check_string)) == 0,
          "incorrect value for last_msg.msg.reference_frame_param.tn, expected "
          "string '%s', is '%s'",
          check_string, last_msg.msg.reference_frame_param.tn);
    }

    ck_assert_msg(last_msg.msg.reference_frame_param.utn == 5,
                  "incorrect value for last_msg.msg.reference_frame_param.utn, "
                  "expected 5, is %d",
                  last_msg.msg.reference_frame_param.utn);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgReferenceFrameParam_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_navigation_MsgReferenceFrameParam");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_navigation_MsgReferenceFrameParam");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgReferenceFrameParam);
  suite_add_tcase(s, tc_acq);
  return s;
}