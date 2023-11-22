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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockDepA.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/ssr.h>
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

START_TEST(test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClockDepA) {
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

    sbp_payload_callback_register(&sbp_state, 0x5dc, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x5dc, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  220, 5,   33,  166, 47,  225, 114, 31,  189, 43,  30,  1,   30,
        194, 211, 193, 175, 161, 143, 254, 56,  63,  232, 7,   216, 69,  1,
        110, 165, 124, 196, 189, 27,  116, 88,  4,   61,  3,   151, 18,  171,
        147, 46,  198, 85,  243, 245, 225, 235, 123, 181, 210, 157, 252,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ssr_orbit_clock_dep_a_t *test_msg =
        (msg_ssr_orbit_clock_dep_a_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->along = 132661048;
    test_msg->c0 = -970026069;
    test_msg->c1 = -503975083;
    test_msg->c2 = -759858197;
    test_msg->cross = 1845577176;
    test_msg->dot_along = 72905755;
    test_msg->dot_cross = 311886653;
    test_msg->dot_radial = -1111196507;
    test_msg->iod = 193;
    test_msg->iod_ssr = 211;
    test_msg->radial = -24141393;
    test_msg->sid.code = 30;
    test_msg->sid.sat = 1;
    test_msg->time.tow = 3172954849;
    test_msg->time.wn = 7723;
    test_msg->update_interval = 194;
    sbp_payload_send(&sbp_state, 0x5dc, 42529, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 42529,
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
    ck_assert_msg(last_frame.sender_id == 42529,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x5dc,
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
    msg_ssr_orbit_clock_dep_a_t *check_msg =
        (msg_ssr_orbit_clock_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->along == 132661048,
                  "incorrect value for along, expected 132661048, is %d",
                  check_msg->along);
    ck_assert_msg(check_msg->c0 == -970026069,
                  "incorrect value for c0, expected -970026069, is %d",
                  check_msg->c0);
    ck_assert_msg(check_msg->c1 == -503975083,
                  "incorrect value for c1, expected -503975083, is %d",
                  check_msg->c1);
    ck_assert_msg(check_msg->c2 == -759858197,
                  "incorrect value for c2, expected -759858197, is %d",
                  check_msg->c2);
    ck_assert_msg(check_msg->cross == 1845577176,
                  "incorrect value for cross, expected 1845577176, is %d",
                  check_msg->cross);
    ck_assert_msg(check_msg->dot_along == 72905755,
                  "incorrect value for dot_along, expected 72905755, is %d",
                  check_msg->dot_along);
    ck_assert_msg(check_msg->dot_cross == 311886653,
                  "incorrect value for dot_cross, expected 311886653, is %d",
                  check_msg->dot_cross);
    ck_assert_msg(check_msg->dot_radial == -1111196507,
                  "incorrect value for dot_radial, expected -1111196507, is %d",
                  check_msg->dot_radial);
    ck_assert_msg(check_msg->iod == 193,
                  "incorrect value for iod, expected 193, is %d",
                  check_msg->iod);
    ck_assert_msg(check_msg->iod_ssr == 211,
                  "incorrect value for iod_ssr, expected 211, is %d",
                  check_msg->iod_ssr);
    ck_assert_msg(check_msg->radial == -24141393,
                  "incorrect value for radial, expected -24141393, is %d",
                  check_msg->radial);
    ck_assert_msg(check_msg->sid.code == 30,
                  "incorrect value for sid.code, expected 30, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.sat == 1,
                  "incorrect value for sid.sat, expected 1, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->time.tow == 3172954849,
                  "incorrect value for time.tow, expected 3172954849, is %d",
                  check_msg->time.tow);
    ck_assert_msg(check_msg->time.wn == 7723,
                  "incorrect value for time.wn, expected 7723, is %d",
                  check_msg->time.wn);
    ck_assert_msg(check_msg->update_interval == 194,
                  "incorrect value for update_interval, expected 194, is %d",
                  check_msg->update_interval);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_ssr_MsgSsrOrbitClockDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_ssr_MsgSsrOrbitClockDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_ssr_MsgSsrOrbitClockDepA");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClockDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}