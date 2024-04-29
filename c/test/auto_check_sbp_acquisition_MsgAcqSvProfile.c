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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfile.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/acquisition.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static size_t dummy_wr = 0;
static size_t dummy_rd = 0;
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
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
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

START_TEST(test_auto_check_sbp_acquisition_MsgAcqSvProfile) {
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

    sbp_callback_register(&sbp_state, 0x2e, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  46,  0,   195, 4,   99, 7,   13,  38,  0,   97,  22,  0,   174,
        0,   52,  0,   0,   0,   49, 0,   0,   0,   61,  0,   0,   0,   147,
        0,   0,   0,   47,  0,   0,  0,   140, 0,   0,   0,   166, 210, 59,
        0,   253, 23,  1,   121, 0,  190, 0,   0,   0,   175, 0,   0,   0,
        175, 0,   0,   0,   142, 0,  0,   0,   237, 0,   0,   0,   12,  0,
        0,   0,   126, 88,  21,  0,  153, 24,  0,   8,   0,   130, 0,   0,
        0,   172, 0,   0,   0,   91, 0,   0,   0,   191, 0,   0,   0,   84,
        0,   0,   0,   82,  0,   0,  0,   168, 177,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_sv_profile.acq_sv_profile[0].bin_width = 174;

    test_msg.acq_sv_profile.acq_sv_profile[0].cf = 47;

    test_msg.acq_sv_profile.acq_sv_profile[0].cf_max = 147;

    test_msg.acq_sv_profile.acq_sv_profile[0].cf_min = 61;

    test_msg.acq_sv_profile.acq_sv_profile[0].cn0 = 38;

    test_msg.acq_sv_profile.acq_sv_profile[0].cp = 140;

    test_msg.acq_sv_profile.acq_sv_profile[0].int_time = 97;

    test_msg.acq_sv_profile.acq_sv_profile[0].job_type = 7;

    test_msg.acq_sv_profile.acq_sv_profile[0].sid.code = 0;

    test_msg.acq_sv_profile.acq_sv_profile[0].sid.sat = 22;

    test_msg.acq_sv_profile.acq_sv_profile[0].status = 13;

    test_msg.acq_sv_profile.acq_sv_profile[0].time_spent = 49;

    test_msg.acq_sv_profile.acq_sv_profile[0].timestamp = 52;

    test_msg.acq_sv_profile.acq_sv_profile[1].bin_width = 121;

    test_msg.acq_sv_profile.acq_sv_profile[1].cf = 237;

    test_msg.acq_sv_profile.acq_sv_profile[1].cf_max = 142;

    test_msg.acq_sv_profile.acq_sv_profile[1].cf_min = 175;

    test_msg.acq_sv_profile.acq_sv_profile[1].cn0 = 59;

    test_msg.acq_sv_profile.acq_sv_profile[1].cp = 12;

    test_msg.acq_sv_profile.acq_sv_profile[1].int_time = 253;

    test_msg.acq_sv_profile.acq_sv_profile[1].job_type = 166;

    test_msg.acq_sv_profile.acq_sv_profile[1].sid.code = 1;

    test_msg.acq_sv_profile.acq_sv_profile[1].sid.sat = 23;

    test_msg.acq_sv_profile.acq_sv_profile[1].status = 210;

    test_msg.acq_sv_profile.acq_sv_profile[1].time_spent = 175;

    test_msg.acq_sv_profile.acq_sv_profile[1].timestamp = 190;

    test_msg.acq_sv_profile.acq_sv_profile[2].bin_width = 8;

    test_msg.acq_sv_profile.acq_sv_profile[2].cf = 84;

    test_msg.acq_sv_profile.acq_sv_profile[2].cf_max = 191;

    test_msg.acq_sv_profile.acq_sv_profile[2].cf_min = 91;

    test_msg.acq_sv_profile.acq_sv_profile[2].cn0 = 21;

    test_msg.acq_sv_profile.acq_sv_profile[2].cp = 82;

    test_msg.acq_sv_profile.acq_sv_profile[2].int_time = 153;

    test_msg.acq_sv_profile.acq_sv_profile[2].job_type = 126;

    test_msg.acq_sv_profile.acq_sv_profile[2].sid.code = 0;

    test_msg.acq_sv_profile.acq_sv_profile[2].sid.sat = 24;

    test_msg.acq_sv_profile.acq_sv_profile[2].status = 88;

    test_msg.acq_sv_profile.acq_sv_profile[2].time_spent = 172;

    test_msg.acq_sv_profile.acq_sv_profile[2].timestamp = 130;

    test_msg.acq_sv_profile.n_acq_sv_profile = 3;

    sbp_message_send(&sbp_state, SbpMsgAcqSvProfile, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgAcqSvProfile, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].bin_width == 174,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[0].bin_width, expected "
        "174, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].bin_width);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].cf == 47,
        "incorrect value for last_msg.msg.acq_sv_profile.acq_sv_profile[0].cf, "
        "expected 47, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].cf);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].cf_max == 147,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[0].cf_max, expected 147, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].cf_max);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].cf_min == 61,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[0].cf_min, expected 61, is "
        "%" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].cf_min);

    ck_assert_msg(last_msg.msg.acq_sv_profile.acq_sv_profile[0].cn0 == 38,
                  "incorrect value for "
                  "last_msg.msg.acq_sv_profile.acq_sv_profile[0].cn0, expected "
                  "38, is %" PRId64,
                  (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].cn0);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].cp == 140,
        "incorrect value for last_msg.msg.acq_sv_profile.acq_sv_profile[0].cp, "
        "expected 140, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].cp);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].int_time == 97,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[0].int_time, expected 97, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].int_time);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].job_type == 7,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[0].job_type, expected 7, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].job_type);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].sid.code == 0,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[0].sid.code, expected 0, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].sid.code);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].sid.sat == 22,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[0].sid.sat, expected 22, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].sid.sat);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].status == 13,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[0].status, expected 13, is "
        "%" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].status);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].time_spent == 49,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[0].time_spent, expected "
        "49, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].time_spent);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[0].timestamp == 52,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[0].timestamp, expected 52, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[0].timestamp);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].bin_width == 121,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[1].bin_width, expected "
        "121, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].bin_width);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].cf == 237,
        "incorrect value for last_msg.msg.acq_sv_profile.acq_sv_profile[1].cf, "
        "expected 237, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].cf);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].cf_max == 142,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[1].cf_max, expected 142, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].cf_max);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].cf_min == 175,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[1].cf_min, expected 175, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].cf_min);

    ck_assert_msg(last_msg.msg.acq_sv_profile.acq_sv_profile[1].cn0 == 59,
                  "incorrect value for "
                  "last_msg.msg.acq_sv_profile.acq_sv_profile[1].cn0, expected "
                  "59, is %" PRId64,
                  (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].cn0);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].cp == 12,
        "incorrect value for last_msg.msg.acq_sv_profile.acq_sv_profile[1].cp, "
        "expected 12, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].cp);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].int_time == 253,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[1].int_time, expected 253, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].int_time);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].job_type == 166,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[1].job_type, expected 166, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].job_type);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].sid.code == 1,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[1].sid.code, expected 1, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].sid.code);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].sid.sat == 23,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[1].sid.sat, expected 23, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].sid.sat);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].status == 210,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[1].status, expected 210, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].status);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].time_spent == 175,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[1].time_spent, expected "
        "175, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].time_spent);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[1].timestamp == 190,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[1].timestamp, expected "
        "190, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[1].timestamp);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].bin_width == 8,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[2].bin_width, expected 8, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].bin_width);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].cf == 84,
        "incorrect value for last_msg.msg.acq_sv_profile.acq_sv_profile[2].cf, "
        "expected 84, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].cf);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].cf_max == 191,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[2].cf_max, expected 191, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].cf_max);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].cf_min == 91,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[2].cf_min, expected 91, is "
        "%" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].cf_min);

    ck_assert_msg(last_msg.msg.acq_sv_profile.acq_sv_profile[2].cn0 == 21,
                  "incorrect value for "
                  "last_msg.msg.acq_sv_profile.acq_sv_profile[2].cn0, expected "
                  "21, is %" PRId64,
                  (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].cn0);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].cp == 82,
        "incorrect value for last_msg.msg.acq_sv_profile.acq_sv_profile[2].cp, "
        "expected 82, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].cp);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].int_time == 153,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[2].int_time, expected 153, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].int_time);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].job_type == 126,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[2].job_type, expected 126, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].job_type);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].sid.code == 0,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[2].sid.code, expected 0, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].sid.code);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].sid.sat == 24,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[2].sid.sat, expected 24, "
        "is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].sid.sat);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].status == 88,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[2].status, expected 88, is "
        "%" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].status);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].time_spent == 172,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[2].time_spent, expected "
        "172, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].time_spent);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.acq_sv_profile[2].timestamp == 130,
        "incorrect value for "
        "last_msg.msg.acq_sv_profile.acq_sv_profile[2].timestamp, expected "
        "130, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.acq_sv_profile[2].timestamp);

    ck_assert_msg(
        last_msg.msg.acq_sv_profile.n_acq_sv_profile == 3,
        "incorrect value for last_msg.msg.acq_sv_profile.n_acq_sv_profile, "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.acq_sv_profile.n_acq_sv_profile);
  }
}
END_TEST

Suite *auto_check_sbp_acquisition_MsgAcqSvProfile_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_acquisition_MsgAcqSvProfile");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_acquisition_MsgAcqSvProfile");
  tcase_add_test(tc_acq, test_auto_check_sbp_acquisition_MsgAcqSvProfile);
  suite_add_tcase(s, tc_acq);
  return s;
}