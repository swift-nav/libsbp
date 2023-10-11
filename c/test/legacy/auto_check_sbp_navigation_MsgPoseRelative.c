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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPoseRelative.yaml by
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

static size_t dummy_wr = 0;
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

START_TEST(test_legacy_auto_check_sbp_navigation_MsgPoseRelative) {
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

    sbp_payload_callback_register(&sbp_state, 0x245, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x245, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  69,  2,  66,  0,  90,  86,  4,   0,   0,   0,   86,  4,   0,
        0,   172, 8,  0,   0,  76,  4,   0,   0,   38,  2,   0,   0,   100,
        0,   0,   0,  100, 3,  200, 204, 252, 168, 157, 255, 115, 53,  186,
        144, 190, 48, 34,  37, 0,   0,   128, 63,  0,   0,   0,   0,   0,
        0,   0,   0,  0,   0,  128, 63,  0,   0,   0,   0,   0,   0,   128,
        63,  0,   0,  0,   64, 0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   64, 0,   0,  0,   0,   0,   0,   0,   64,  5,   171, 187,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pose_relative_t *test_msg = (msg_pose_relative_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->cov_c_x_x = 2.0;
    test_msg->cov_c_x_y = 0.0;
    test_msg->cov_c_x_z = 0.0;
    test_msg->cov_c_y_y = 2.0;
    test_msg->cov_c_y_z = 0.0;
    test_msg->cov_c_z_z = 2.0;
    test_msg->cov_r_x_x = 1.0;
    test_msg->cov_r_x_y = 0.0;
    test_msg->cov_r_x_z = 0.0;
    test_msg->cov_r_y_y = 1.0;
    test_msg->cov_r_y_z = 0.0;
    test_msg->cov_r_z_z = 1.0;
    test_msg->flags = 5;
    test_msg->sensor_id = 0;
    test_msg->timestamp_1 = 1110;
    test_msg->timestamp_2 = 2220;
    test_msg->tow = 1110;
    if (sizeof(test_msg->trans) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->trans[0]);
    }
    test_msg->trans[0] = 1100;
    if (sizeof(test_msg->trans) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->trans[0]);
    }
    test_msg->trans[1] = 550;
    if (sizeof(test_msg->trans) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->trans[0]);
    }
    test_msg->trans[2] = 100;
    test_msg->w = -859307164;
    test_msg->x = -6444804;
    test_msg->y = -1866844813;
    test_msg->z = 622997694;
    sbp_payload_send(&sbp_state, 0x245, 66, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 66,
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
    ck_assert_msg(last_frame.sender_id == 66,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x245,
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
    msg_pose_relative_t *check_msg =
        (msg_pose_relative_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg((check_msg->cov_c_x_x * 100 - 2.0 * 100) < 0.05,
                  "incorrect value for cov_c_x_x, expected 2.0, is %f",
                  check_msg->cov_c_x_x);
    ck_assert_msg((check_msg->cov_c_x_y * 100 - 0.0 * 100) < 0.05,
                  "incorrect value for cov_c_x_y, expected 0.0, is %f",
                  check_msg->cov_c_x_y);
    ck_assert_msg((check_msg->cov_c_x_z * 100 - 0.0 * 100) < 0.05,
                  "incorrect value for cov_c_x_z, expected 0.0, is %f",
                  check_msg->cov_c_x_z);
    ck_assert_msg((check_msg->cov_c_y_y * 100 - 2.0 * 100) < 0.05,
                  "incorrect value for cov_c_y_y, expected 2.0, is %f",
                  check_msg->cov_c_y_y);
    ck_assert_msg((check_msg->cov_c_y_z * 100 - 0.0 * 100) < 0.05,
                  "incorrect value for cov_c_y_z, expected 0.0, is %f",
                  check_msg->cov_c_y_z);
    ck_assert_msg((check_msg->cov_c_z_z * 100 - 2.0 * 100) < 0.05,
                  "incorrect value for cov_c_z_z, expected 2.0, is %f",
                  check_msg->cov_c_z_z);
    ck_assert_msg((check_msg->cov_r_x_x * 100 - 1.0 * 100) < 0.05,
                  "incorrect value for cov_r_x_x, expected 1.0, is %f",
                  check_msg->cov_r_x_x);
    ck_assert_msg((check_msg->cov_r_x_y * 100 - 0.0 * 100) < 0.05,
                  "incorrect value for cov_r_x_y, expected 0.0, is %f",
                  check_msg->cov_r_x_y);
    ck_assert_msg((check_msg->cov_r_x_z * 100 - 0.0 * 100) < 0.05,
                  "incorrect value for cov_r_x_z, expected 0.0, is %f",
                  check_msg->cov_r_x_z);
    ck_assert_msg((check_msg->cov_r_y_y * 100 - 1.0 * 100) < 0.05,
                  "incorrect value for cov_r_y_y, expected 1.0, is %f",
                  check_msg->cov_r_y_y);
    ck_assert_msg((check_msg->cov_r_y_z * 100 - 0.0 * 100) < 0.05,
                  "incorrect value for cov_r_y_z, expected 0.0, is %f",
                  check_msg->cov_r_y_z);
    ck_assert_msg((check_msg->cov_r_z_z * 100 - 1.0 * 100) < 0.05,
                  "incorrect value for cov_r_z_z, expected 1.0, is %f",
                  check_msg->cov_r_z_z);
    ck_assert_msg(check_msg->flags == 5,
                  "incorrect value for flags, expected 5, is %" PRId64,
                  (int64_t)check_msg->flags);
    ck_assert_msg(check_msg->sensor_id == 0,
                  "incorrect value for sensor_id, expected 0, is %" PRId64,
                  (int64_t)check_msg->sensor_id);
    ck_assert_msg(check_msg->timestamp_1 == 1110,
                  "incorrect value for timestamp_1, expected 1110, is %" PRId64,
                  (int64_t)check_msg->timestamp_1);
    ck_assert_msg(check_msg->timestamp_2 == 2220,
                  "incorrect value for timestamp_2, expected 2220, is %" PRId64,
                  (int64_t)check_msg->timestamp_2);
    ck_assert_msg(check_msg->tow == 1110,
                  "incorrect value for tow, expected 1110, is %" PRId64,
                  (int64_t)check_msg->tow);
    ck_assert_msg(check_msg->trans[0] == 1100,
                  "incorrect value for trans[0], expected 1100, is %" PRId64,
                  (int64_t)check_msg->trans[0]);
    ck_assert_msg(check_msg->trans[1] == 550,
                  "incorrect value for trans[1], expected 550, is %" PRId64,
                  (int64_t)check_msg->trans[1]);
    ck_assert_msg(check_msg->trans[2] == 100,
                  "incorrect value for trans[2], expected 100, is %" PRId64,
                  (int64_t)check_msg->trans[2]);
    ck_assert_msg(check_msg->w == -859307164,
                  "incorrect value for w, expected -859307164, is %" PRId64,
                  (int64_t)check_msg->w);
    ck_assert_msg(check_msg->x == -6444804,
                  "incorrect value for x, expected -6444804, is %" PRId64,
                  (int64_t)check_msg->x);
    ck_assert_msg(check_msg->y == -1866844813,
                  "incorrect value for y, expected -1866844813, is %" PRId64,
                  (int64_t)check_msg->y);
    ck_assert_msg(check_msg->z == 622997694,
                  "incorrect value for z, expected 622997694, is %" PRId64,
                  (int64_t)check_msg->z);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_navigation_MsgPoseRelative_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_navigation_MsgPoseRelative");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_navigation_MsgPoseRelative");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_navigation_MsgPoseRelative);
  suite_add_tcase(s, tc_acq);
  return s;
}