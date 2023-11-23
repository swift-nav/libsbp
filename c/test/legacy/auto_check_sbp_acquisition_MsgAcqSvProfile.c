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
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/acquisition.h>
#include <libsbp/legacy/api.h>
#include <libsbp/legacy/compat.h>

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

START_TEST(test_legacy_auto_check_sbp_acquisition_MsgAcqSvProfile) {
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

    sbp_payload_callback_register(&sbp_state, 0x2e, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x2e, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

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

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_acq_sv_profile_t *test_msg = (msg_acq_sv_profile_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->acq_sv_profile) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->acq_sv_profile[0]);
    }
    test_msg->acq_sv_profile[0].bin_width = 174;
    test_msg->acq_sv_profile[0].cf = 47;
    test_msg->acq_sv_profile[0].cf_max = 147;
    test_msg->acq_sv_profile[0].cf_min = 61;
    test_msg->acq_sv_profile[0].cn0 = 38;
    test_msg->acq_sv_profile[0].cp = 140;
    test_msg->acq_sv_profile[0].int_time = 97;
    test_msg->acq_sv_profile[0].job_type = 7;
    test_msg->acq_sv_profile[0].sid.code = 0;
    test_msg->acq_sv_profile[0].sid.sat = 22;
    test_msg->acq_sv_profile[0].status = 13;
    test_msg->acq_sv_profile[0].time_spent = 49;
    test_msg->acq_sv_profile[0].timestamp = 52;
    if (sizeof(test_msg->acq_sv_profile) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->acq_sv_profile[0]);
    }
    test_msg->acq_sv_profile[1].bin_width = 121;
    test_msg->acq_sv_profile[1].cf = 237;
    test_msg->acq_sv_profile[1].cf_max = 142;
    test_msg->acq_sv_profile[1].cf_min = 175;
    test_msg->acq_sv_profile[1].cn0 = 59;
    test_msg->acq_sv_profile[1].cp = 12;
    test_msg->acq_sv_profile[1].int_time = 253;
    test_msg->acq_sv_profile[1].job_type = 166;
    test_msg->acq_sv_profile[1].sid.code = 1;
    test_msg->acq_sv_profile[1].sid.sat = 23;
    test_msg->acq_sv_profile[1].status = 210;
    test_msg->acq_sv_profile[1].time_spent = 175;
    test_msg->acq_sv_profile[1].timestamp = 190;
    if (sizeof(test_msg->acq_sv_profile) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->acq_sv_profile[0]);
    }
    test_msg->acq_sv_profile[2].bin_width = 8;
    test_msg->acq_sv_profile[2].cf = 84;
    test_msg->acq_sv_profile[2].cf_max = 191;
    test_msg->acq_sv_profile[2].cf_min = 91;
    test_msg->acq_sv_profile[2].cn0 = 21;
    test_msg->acq_sv_profile[2].cp = 82;
    test_msg->acq_sv_profile[2].int_time = 153;
    test_msg->acq_sv_profile[2].job_type = 126;
    test_msg->acq_sv_profile[2].sid.code = 0;
    test_msg->acq_sv_profile[2].sid.sat = 24;
    test_msg->acq_sv_profile[2].status = 88;
    test_msg->acq_sv_profile[2].time_spent = 172;
    test_msg->acq_sv_profile[2].timestamp = 130;
    sbp_payload_send(&sbp_state, 0x2e, 1219, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x2e,
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
    msg_acq_sv_profile_t *check_msg =
        (msg_acq_sv_profile_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        check_msg->acq_sv_profile[0].bin_width == 174,
        "incorrect value for acq_sv_profile[0].bin_width, expected 174, is %d",
        check_msg->acq_sv_profile[0].bin_width);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].cf == 47,
        "incorrect value for acq_sv_profile[0].cf, expected 47, is %d",
        check_msg->acq_sv_profile[0].cf);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].cf_max == 147,
        "incorrect value for acq_sv_profile[0].cf_max, expected 147, is %d",
        check_msg->acq_sv_profile[0].cf_max);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].cf_min == 61,
        "incorrect value for acq_sv_profile[0].cf_min, expected 61, is %d",
        check_msg->acq_sv_profile[0].cf_min);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].cn0 == 38,
        "incorrect value for acq_sv_profile[0].cn0, expected 38, is %d",
        check_msg->acq_sv_profile[0].cn0);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].cp == 140,
        "incorrect value for acq_sv_profile[0].cp, expected 140, is %d",
        check_msg->acq_sv_profile[0].cp);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].int_time == 97,
        "incorrect value for acq_sv_profile[0].int_time, expected 97, is %d",
        check_msg->acq_sv_profile[0].int_time);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].job_type == 7,
        "incorrect value for acq_sv_profile[0].job_type, expected 7, is %d",
        check_msg->acq_sv_profile[0].job_type);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].sid.code == 0,
        "incorrect value for acq_sv_profile[0].sid.code, expected 0, is %d",
        check_msg->acq_sv_profile[0].sid.code);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].sid.sat == 22,
        "incorrect value for acq_sv_profile[0].sid.sat, expected 22, is %d",
        check_msg->acq_sv_profile[0].sid.sat);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].status == 13,
        "incorrect value for acq_sv_profile[0].status, expected 13, is %d",
        check_msg->acq_sv_profile[0].status);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].time_spent == 49,
        "incorrect value for acq_sv_profile[0].time_spent, expected 49, is %d",
        check_msg->acq_sv_profile[0].time_spent);
    ck_assert_msg(
        check_msg->acq_sv_profile[0].timestamp == 52,
        "incorrect value for acq_sv_profile[0].timestamp, expected 52, is %d",
        check_msg->acq_sv_profile[0].timestamp);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].bin_width == 121,
        "incorrect value for acq_sv_profile[1].bin_width, expected 121, is %d",
        check_msg->acq_sv_profile[1].bin_width);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].cf == 237,
        "incorrect value for acq_sv_profile[1].cf, expected 237, is %d",
        check_msg->acq_sv_profile[1].cf);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].cf_max == 142,
        "incorrect value for acq_sv_profile[1].cf_max, expected 142, is %d",
        check_msg->acq_sv_profile[1].cf_max);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].cf_min == 175,
        "incorrect value for acq_sv_profile[1].cf_min, expected 175, is %d",
        check_msg->acq_sv_profile[1].cf_min);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].cn0 == 59,
        "incorrect value for acq_sv_profile[1].cn0, expected 59, is %d",
        check_msg->acq_sv_profile[1].cn0);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].cp == 12,
        "incorrect value for acq_sv_profile[1].cp, expected 12, is %d",
        check_msg->acq_sv_profile[1].cp);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].int_time == 253,
        "incorrect value for acq_sv_profile[1].int_time, expected 253, is %d",
        check_msg->acq_sv_profile[1].int_time);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].job_type == 166,
        "incorrect value for acq_sv_profile[1].job_type, expected 166, is %d",
        check_msg->acq_sv_profile[1].job_type);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].sid.code == 1,
        "incorrect value for acq_sv_profile[1].sid.code, expected 1, is %d",
        check_msg->acq_sv_profile[1].sid.code);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].sid.sat == 23,
        "incorrect value for acq_sv_profile[1].sid.sat, expected 23, is %d",
        check_msg->acq_sv_profile[1].sid.sat);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].status == 210,
        "incorrect value for acq_sv_profile[1].status, expected 210, is %d",
        check_msg->acq_sv_profile[1].status);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].time_spent == 175,
        "incorrect value for acq_sv_profile[1].time_spent, expected 175, is %d",
        check_msg->acq_sv_profile[1].time_spent);
    ck_assert_msg(
        check_msg->acq_sv_profile[1].timestamp == 190,
        "incorrect value for acq_sv_profile[1].timestamp, expected 190, is %d",
        check_msg->acq_sv_profile[1].timestamp);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].bin_width == 8,
        "incorrect value for acq_sv_profile[2].bin_width, expected 8, is %d",
        check_msg->acq_sv_profile[2].bin_width);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].cf == 84,
        "incorrect value for acq_sv_profile[2].cf, expected 84, is %d",
        check_msg->acq_sv_profile[2].cf);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].cf_max == 191,
        "incorrect value for acq_sv_profile[2].cf_max, expected 191, is %d",
        check_msg->acq_sv_profile[2].cf_max);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].cf_min == 91,
        "incorrect value for acq_sv_profile[2].cf_min, expected 91, is %d",
        check_msg->acq_sv_profile[2].cf_min);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].cn0 == 21,
        "incorrect value for acq_sv_profile[2].cn0, expected 21, is %d",
        check_msg->acq_sv_profile[2].cn0);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].cp == 82,
        "incorrect value for acq_sv_profile[2].cp, expected 82, is %d",
        check_msg->acq_sv_profile[2].cp);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].int_time == 153,
        "incorrect value for acq_sv_profile[2].int_time, expected 153, is %d",
        check_msg->acq_sv_profile[2].int_time);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].job_type == 126,
        "incorrect value for acq_sv_profile[2].job_type, expected 126, is %d",
        check_msg->acq_sv_profile[2].job_type);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].sid.code == 0,
        "incorrect value for acq_sv_profile[2].sid.code, expected 0, is %d",
        check_msg->acq_sv_profile[2].sid.code);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].sid.sat == 24,
        "incorrect value for acq_sv_profile[2].sid.sat, expected 24, is %d",
        check_msg->acq_sv_profile[2].sid.sat);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].status == 88,
        "incorrect value for acq_sv_profile[2].status, expected 88, is %d",
        check_msg->acq_sv_profile[2].status);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].time_spent == 172,
        "incorrect value for acq_sv_profile[2].time_spent, expected 172, is %d",
        check_msg->acq_sv_profile[2].time_spent);
    ck_assert_msg(
        check_msg->acq_sv_profile[2].timestamp == 130,
        "incorrect value for acq_sv_profile[2].timestamp, expected 130, is %d",
        check_msg->acq_sv_profile[2].timestamp);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_acquisition_MsgAcqSvProfile_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_acquisition_MsgAcqSvProfile");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_acquisition_MsgAcqSvProfile");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_acquisition_MsgAcqSvProfile);
  suite_add_tcase(s, tc_acq);
  return s;
}