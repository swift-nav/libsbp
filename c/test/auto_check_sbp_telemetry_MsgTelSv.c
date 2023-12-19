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
// spec/tests/yaml/swiftnav/sbp/telemetry/test_MsgTelSv.yaml by generate.py. Do
// not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/telemetry.h>
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

START_TEST(test_auto_check_sbp_telemetry_MsgTelSv) {
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

    sbp_callback_register(&sbp_state, 0x120, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 32, 1, 148, 38,  20, 175, 8, 208, 221, 62, 24, 16, 1,
        40, 50, 5, 226, 255, 1,  0,   1, 1,   1,   33, 12, 39, 105,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tel_sv.n_obs = 16;

    test_msg.tel_sv.n_sv_tel = 1;

    test_msg.tel_sv.origin_flags = 1;

    test_msg.tel_sv.sv_tel[0].availability_flags = 5;

    test_msg.tel_sv.sv_tel[0].az = 40;

    test_msg.tel_sv.sv_tel[0].correction_flags = 1;

    test_msg.tel_sv.sv_tel[0].el = 50;

    test_msg.tel_sv.sv_tel[0].ephemeris_flags = 1;

    test_msg.tel_sv.sv_tel[0].outlier_flags = 1;

    test_msg.tel_sv.sv_tel[0].phase_residual = 1;

    test_msg.tel_sv.sv_tel[0].pseudorange_residual = -30;

    test_msg.tel_sv.sv_tel[0].sid.code = 12;

    test_msg.tel_sv.sv_tel[0].sid.sat = 33;

    test_msg.tel_sv.tow = 406773200;

    test_msg.tel_sv.wn = 2223;

    sbp_message_send(&sbp_state, SbpMsgTelSv, 9876, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 9876,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgTelSv, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.tel_sv.n_obs == 16,
        "incorrect value for last_msg.msg.tel_sv.n_obs, expected 16, is %d",
        last_msg.msg.tel_sv.n_obs);

    ck_assert_msg(
        last_msg.msg.tel_sv.n_sv_tel == 1,
        "incorrect value for last_msg.msg.tel_sv.n_sv_tel, expected 1, is %d",
        last_msg.msg.tel_sv.n_sv_tel);

    ck_assert_msg(last_msg.msg.tel_sv.origin_flags == 1,
                  "incorrect value for last_msg.msg.tel_sv.origin_flags, "
                  "expected 1, is %d",
                  last_msg.msg.tel_sv.origin_flags);

    ck_assert_msg(
        last_msg.msg.tel_sv.sv_tel[0].availability_flags == 5,
        "incorrect value for last_msg.msg.tel_sv.sv_tel[0].availability_flags, "
        "expected 5, is %d",
        last_msg.msg.tel_sv.sv_tel[0].availability_flags);

    ck_assert_msg(last_msg.msg.tel_sv.sv_tel[0].az == 40,
                  "incorrect value for last_msg.msg.tel_sv.sv_tel[0].az, "
                  "expected 40, is %d",
                  last_msg.msg.tel_sv.sv_tel[0].az);

    ck_assert_msg(
        last_msg.msg.tel_sv.sv_tel[0].correction_flags == 1,
        "incorrect value for last_msg.msg.tel_sv.sv_tel[0].correction_flags, "
        "expected 1, is %d",
        last_msg.msg.tel_sv.sv_tel[0].correction_flags);

    ck_assert_msg(last_msg.msg.tel_sv.sv_tel[0].el == 50,
                  "incorrect value for last_msg.msg.tel_sv.sv_tel[0].el, "
                  "expected 50, is %d",
                  last_msg.msg.tel_sv.sv_tel[0].el);

    ck_assert_msg(
        last_msg.msg.tel_sv.sv_tel[0].ephemeris_flags == 1,
        "incorrect value for last_msg.msg.tel_sv.sv_tel[0].ephemeris_flags, "
        "expected 1, is %d",
        last_msg.msg.tel_sv.sv_tel[0].ephemeris_flags);

    ck_assert_msg(
        last_msg.msg.tel_sv.sv_tel[0].outlier_flags == 1,
        "incorrect value for last_msg.msg.tel_sv.sv_tel[0].outlier_flags, "
        "expected 1, is %d",
        last_msg.msg.tel_sv.sv_tel[0].outlier_flags);

    ck_assert_msg(
        last_msg.msg.tel_sv.sv_tel[0].phase_residual == 1,
        "incorrect value for last_msg.msg.tel_sv.sv_tel[0].phase_residual, "
        "expected 1, is %d",
        last_msg.msg.tel_sv.sv_tel[0].phase_residual);

    ck_assert_msg(last_msg.msg.tel_sv.sv_tel[0].pseudorange_residual == -30,
                  "incorrect value for "
                  "last_msg.msg.tel_sv.sv_tel[0].pseudorange_residual, "
                  "expected -30, is %d",
                  last_msg.msg.tel_sv.sv_tel[0].pseudorange_residual);

    ck_assert_msg(last_msg.msg.tel_sv.sv_tel[0].sid.code == 12,
                  "incorrect value for last_msg.msg.tel_sv.sv_tel[0].sid.code, "
                  "expected 12, is %d",
                  last_msg.msg.tel_sv.sv_tel[0].sid.code);

    ck_assert_msg(last_msg.msg.tel_sv.sv_tel[0].sid.sat == 33,
                  "incorrect value for last_msg.msg.tel_sv.sv_tel[0].sid.sat, "
                  "expected 33, is %d",
                  last_msg.msg.tel_sv.sv_tel[0].sid.sat);

    ck_assert_msg(last_msg.msg.tel_sv.tow == 406773200,
                  "incorrect value for last_msg.msg.tel_sv.tow, expected "
                  "406773200, is %d",
                  last_msg.msg.tel_sv.tow);

    ck_assert_msg(
        last_msg.msg.tel_sv.wn == 2223,
        "incorrect value for last_msg.msg.tel_sv.wn, expected 2223, is %d",
        last_msg.msg.tel_sv.wn);
  }
}
END_TEST

Suite *auto_check_sbp_telemetry_MsgTelSv_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_telemetry_MsgTelSv");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_telemetry_MsgTelSv");
  tcase_add_test(tc_acq, test_auto_check_sbp_telemetry_MsgTelSv);
  suite_add_tcase(s, tc_acq);
  return s;
}