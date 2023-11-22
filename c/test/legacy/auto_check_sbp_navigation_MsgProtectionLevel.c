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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevel.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/navigation.h>
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

START_TEST(test_legacy_auto_check_sbp_navigation_MsgProtectionLevel) {
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

    sbp_payload_callback_register(&sbp_state, 0x217, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x217, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  23,  2,   45,  3,   76, 110, 84,  4,   242, 46,  51,  53,  160,
        89,  84,  167, 41,  57,  21, 217, 244, 61,  161, 83,  104, 140, 137,
        90,  246, 51,  51,  51,  51, 51,  170, 180, 64,  154, 153, 153, 153,
        25,  88,  195, 64,  51,  51, 51,  51,  51,  195, 121, 64,  231, 251,
        38,  221, 208, 183, 167, 80, 223, 26,  97,  164, 45,  46,  186, 60,
        235, 227, 183, 160, 187, 93, 116, 224, 105, 40,  32,  33,  133, 188,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_protection_level_t *test_msg =
        (msg_protection_level_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->atpl = 10663;
    test_msg->ctpl = 5433;
    test_msg->flags = 555755625;
    test_msg->heading = -529244741;
    test_msg->height = 412.2;
    test_msg->hopl = 26707;
    test_msg->hpl = 41013;
    test_msg->hvpl = 62681;
    test_msg->lat = 5290.2;
    test_msg->lon = 9904.2;
    test_msg->pitch = -1598561301;
    test_msg->popl = 35212;
    test_msg->roll = 1018834477;
    test_msg->ropl = 63066;
    test_msg->tow = 4060370030;
    test_msg->v_x = -584647705;
    test_msg->v_y = 1353168848;
    test_msg->v_z = -1537140001;
    test_msg->vpl = 21593;
    test_msg->vvpl = 41277;
    test_msg->wn = 13102;
    sbp_payload_send(&sbp_state, 0x217, 813, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 813,
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
    ck_assert_msg(last_frame.sender_id == 813,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x217,
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
    msg_protection_level_t *check_msg =
        (msg_protection_level_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->atpl == 10663,
                  "incorrect value for atpl, expected 10663, is %d",
                  check_msg->atpl);
    ck_assert_msg(check_msg->ctpl == 5433,
                  "incorrect value for ctpl, expected 5433, is %d",
                  check_msg->ctpl);
    ck_assert_msg(check_msg->flags == 555755625,
                  "incorrect value for flags, expected 555755625, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->heading == -529244741,
                  "incorrect value for heading, expected -529244741, is %d",
                  check_msg->heading);
    ck_assert_msg((check_msg->height * 100 - 412.2 * 100) < 0.05,
                  "incorrect value for height, expected 412.2, is %f",
                  check_msg->height);
    ck_assert_msg(check_msg->hopl == 26707,
                  "incorrect value for hopl, expected 26707, is %d",
                  check_msg->hopl);
    ck_assert_msg(check_msg->hpl == 41013,
                  "incorrect value for hpl, expected 41013, is %d",
                  check_msg->hpl);
    ck_assert_msg(check_msg->hvpl == 62681,
                  "incorrect value for hvpl, expected 62681, is %d",
                  check_msg->hvpl);
    ck_assert_msg((check_msg->lat * 100 - 5290.2 * 100) < 0.05,
                  "incorrect value for lat, expected 5290.2, is %f",
                  check_msg->lat);
    ck_assert_msg((check_msg->lon * 100 - 9904.2 * 100) < 0.05,
                  "incorrect value for lon, expected 9904.2, is %f",
                  check_msg->lon);
    ck_assert_msg(check_msg->pitch == -1598561301,
                  "incorrect value for pitch, expected -1598561301, is %d",
                  check_msg->pitch);
    ck_assert_msg(check_msg->popl == 35212,
                  "incorrect value for popl, expected 35212, is %d",
                  check_msg->popl);
    ck_assert_msg(check_msg->roll == 1018834477,
                  "incorrect value for roll, expected 1018834477, is %d",
                  check_msg->roll);
    ck_assert_msg(check_msg->ropl == 63066,
                  "incorrect value for ropl, expected 63066, is %d",
                  check_msg->ropl);
    ck_assert_msg(check_msg->tow == 4060370030,
                  "incorrect value for tow, expected 4060370030, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->v_x == -584647705,
                  "incorrect value for v_x, expected -584647705, is %d",
                  check_msg->v_x);
    ck_assert_msg(check_msg->v_y == 1353168848,
                  "incorrect value for v_y, expected 1353168848, is %d",
                  check_msg->v_y);
    ck_assert_msg(check_msg->v_z == -1537140001,
                  "incorrect value for v_z, expected -1537140001, is %d",
                  check_msg->v_z);
    ck_assert_msg(check_msg->vpl == 21593,
                  "incorrect value for vpl, expected 21593, is %d",
                  check_msg->vpl);
    ck_assert_msg(check_msg->vvpl == 41277,
                  "incorrect value for vvpl, expected 41277, is %d",
                  check_msg->vvpl);
    ck_assert_msg(check_msg->wn == 13102,
                  "incorrect value for wn, expected 13102, is %d",
                  check_msg->wn);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_navigation_MsgProtectionLevel_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_navigation_MsgProtectionLevel");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_navigation_MsgProtectionLevel");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_navigation_MsgProtectionLevel);
  suite_add_tcase(s, tc_acq);
  return s;
}