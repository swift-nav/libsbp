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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClock.yaml by generate.py.
// Do not modify by hand!

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

START_TEST(test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClock) {
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

    sbp_payload_callback_register(&sbp_state, 0x5dd, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x5dd, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  221, 5,   53,  229, 50,  83,  208, 102, 207, 164, 29,
        203, 212, 236, 255, 152, 233, 207, 55,  94,  54,  58,  128,
        68,  27,  117, 176, 110, 251, 61,  244, 122, 50,  95,  52,
        144, 232, 24,  10,  37,  127, 163, 66,  177, 105, 156, 245,
        10,  249, 107, 218, 17,  186, 56,  72,  14,  22,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ssr_orbit_clock_t *test_msg = (msg_ssr_orbit_clock_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->along = -1334502588;
    test_msg->c0 = -174298703;
    test_msg->c1 = -630458102;
    test_msg->c2 = 1211677201;
    test_msg->cross = -197264530;
    test_msg->dot_along = 169404560;
    test_msg->dot_cross = 1118011173;
    test_msg->dot_radial = 878654074;
    test_msg->iod = 936372632;
    test_msg->iod_ssr = 255;
    test_msg->radial = -2143668642;
    test_msg->sid.code = 212;
    test_msg->sid.sat = 203;
    test_msg->time.tow = 3479621715;
    test_msg->time.wn = 7588;
    test_msg->update_interval = 236;
    sbp_payload_send(&sbp_state, 0x5dd, 58677, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 58677,
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
    ck_assert_msg(last_frame.sender_id == 58677,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x5dd,
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
    msg_ssr_orbit_clock_t *check_msg =
        (msg_ssr_orbit_clock_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->along == -1334502588,
                  "incorrect value for along, expected -1334502588, is %d",
                  check_msg->along);
    ck_assert_msg(check_msg->c0 == -174298703,
                  "incorrect value for c0, expected -174298703, is %d",
                  check_msg->c0);
    ck_assert_msg(check_msg->c1 == -630458102,
                  "incorrect value for c1, expected -630458102, is %d",
                  check_msg->c1);
    ck_assert_msg(check_msg->c2 == 1211677201,
                  "incorrect value for c2, expected 1211677201, is %d",
                  check_msg->c2);
    ck_assert_msg(check_msg->cross == -197264530,
                  "incorrect value for cross, expected -197264530, is %d",
                  check_msg->cross);
    ck_assert_msg(check_msg->dot_along == 169404560,
                  "incorrect value for dot_along, expected 169404560, is %d",
                  check_msg->dot_along);
    ck_assert_msg(check_msg->dot_cross == 1118011173,
                  "incorrect value for dot_cross, expected 1118011173, is %d",
                  check_msg->dot_cross);
    ck_assert_msg(check_msg->dot_radial == 878654074,
                  "incorrect value for dot_radial, expected 878654074, is %d",
                  check_msg->dot_radial);
    ck_assert_msg(check_msg->iod == 936372632,
                  "incorrect value for iod, expected 936372632, is %d",
                  check_msg->iod);
    ck_assert_msg(check_msg->iod_ssr == 255,
                  "incorrect value for iod_ssr, expected 255, is %d",
                  check_msg->iod_ssr);
    ck_assert_msg(check_msg->radial == -2143668642,
                  "incorrect value for radial, expected -2143668642, is %d",
                  check_msg->radial);
    ck_assert_msg(check_msg->sid.code == 212,
                  "incorrect value for sid.code, expected 212, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.sat == 203,
                  "incorrect value for sid.sat, expected 203, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->time.tow == 3479621715,
                  "incorrect value for time.tow, expected 3479621715, is %d",
                  check_msg->time.tow);
    ck_assert_msg(check_msg->time.wn == 7588,
                  "incorrect value for time.wn, expected 7588, is %d",
                  check_msg->time.wn);
    ck_assert_msg(check_msg->update_interval == 236,
                  "incorrect value for update_interval, expected 236, is %d",
                  check_msg->update_interval);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_ssr_MsgSsrOrbitClock_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_ssr_MsgSsrOrbitClock");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_ssr_MsgSsrOrbitClock");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_ssr_MsgSsrOrbitClock);
  suite_add_tcase(s, tc_acq);
  return s;
}