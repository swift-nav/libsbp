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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDepA.yaml
// by generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/tracking.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

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

START_TEST(test_legacy_auto_check_sbp_tracking_MsgTrackingStateDetailedDepA) {
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

    sbp_payload_callback_register(&sbp_state, 0x21, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x21, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 33,  0,   155, 110, 57,  46,  31,  180, 38,  219, 0,   0,
        0,  133, 100, 71,  94,  192, 2,   160, 207, 212, 255, 135, 139,
        62, 62,  179, 83,  227, 245, 134, 160, 204, 78,  95,  255, 38,
        59, 161, 15,  255, 86,  189, 248, 31,  191, 136, 194, 124, 23,
        15, 91,  249, 117, 142, 90,  219, 67,  25,  83,  62,  122, 100,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_tracking_state_detailed_dep_a_t *test_msg =
        (msg_tracking_state_detailed_dep_a_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->L.f = 204;
    test_msg->L.i = -1601767965;
    test_msg->P = 1044286343;
    test_msg->P_std = 21427;
    test_msg->acceleration = -114;
    test_msg->clock_drift = 23311;
    test_msg->clock_offset = 6012;
    test_msg->cn0 = 78;
    test_msg->corr_spacing = 30201;
    test_msg->doppler = 1459556257;
    test_msg->doppler_std = 63677;
    test_msg->lock = 65375;
    test_msg->misc_flags = 62;
    test_msg->nav_flags = 25;
    test_msg->pset_flags = 83;
    test_msg->recv_time = 941247176494;
    test_msg->sid.code = 59;
    test_msg->sid.sat = 38;
    test_msg->sync_flags = 90;
    test_msg->tot.ns_residual = -811597120;
    test_msg->tot.tow = 1581737093;
    test_msg->tot.wn = 65492;
    test_msg->tow_flags = 219;
    test_msg->track_flags = 67;
    test_msg->uptime = 3263741727;
    sbp_payload_send(&sbp_state, 0x21, 28315, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 28315,
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
    ck_assert_msg(last_frame.sender_id == 28315,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x21,
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
    msg_tracking_state_detailed_dep_a_t *check_msg =
        (msg_tracking_state_detailed_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->L.f == 204,
                  "incorrect value for L.f, expected 204, is %d",
                  check_msg->L.f);
    ck_assert_msg(check_msg->L.i == -1601767965,
                  "incorrect value for L.i, expected -1601767965, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 1044286343,
                  "incorrect value for P, expected 1044286343, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 21427,
                  "incorrect value for P_std, expected 21427, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == -114,
                  "incorrect value for acceleration, expected -114, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 23311,
                  "incorrect value for clock_drift, expected 23311, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 6012,
                  "incorrect value for clock_offset, expected 6012, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 78,
                  "incorrect value for cn0, expected 78, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 30201,
                  "incorrect value for corr_spacing, expected 30201, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 1459556257,
                  "incorrect value for doppler, expected 1459556257, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 63677,
                  "incorrect value for doppler_std, expected 63677, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 65375,
                  "incorrect value for lock, expected 65375, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 62,
                  "incorrect value for misc_flags, expected 62, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 25,
                  "incorrect value for nav_flags, expected 25, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 83,
                  "incorrect value for pset_flags, expected 83, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 941247176494,
                  "incorrect value for recv_time, expected 941247176494, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 59,
                  "incorrect value for sid.code, expected 59, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.sat == 38,
                  "incorrect value for sid.sat, expected 38, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 90,
                  "incorrect value for sync_flags, expected 90, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(
        check_msg->tot.ns_residual == -811597120,
        "incorrect value for tot.ns_residual, expected -811597120, is %d",
        check_msg->tot.ns_residual);
    ck_assert_msg(check_msg->tot.tow == 1581737093,
                  "incorrect value for tot.tow, expected 1581737093, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 65492,
                  "incorrect value for tot.wn, expected 65492, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 219,
                  "incorrect value for tow_flags, expected 219, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 67,
                  "incorrect value for track_flags, expected 67, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 3263741727,
                  "incorrect value for uptime, expected 3263741727, is %d",
                  check_msg->uptime);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_tracking_MsgTrackingStateDetailedDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_tracking_MsgTrackingStateDetailedDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_tracking_"
      "MsgTrackingStateDetailedDepA");
  tcase_add_test(
      tc_acq, test_legacy_auto_check_sbp_tracking_MsgTrackingStateDetailedDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}