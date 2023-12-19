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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhAcc.yaml by
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
#include <libsbp/legacy/api.h>
#include <libsbp/legacy/compat.h>
#include <libsbp/legacy/navigation.h>

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

START_TEST(test_legacy_auto_check_sbp_navigation_MsgPosLlhAcc) {
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

    sbp_payload_callback_register(&sbp_state, 0x218, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x218, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  24,  2,   2,   28,  67,  39,  120, 110, 18,  51,  51,  51,
        51,  51,  139, 189, 64,  154, 153, 153, 153, 25,  151, 192, 64,
        51,  51,  51,  51,  51,  161, 176, 64,  51,  51,  51,  51,  51,
        101, 179, 64,  51,  163, 22,  69,  154, 25,  173, 69,  102, 134,
        243, 68,  154, 201, 196, 69,  205, 224, 0,   70,  51,  35,  72,
        69,  51,  99,  31,  69,  95,  27,  72,  220, 177,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_llh_acc_t *test_msg = (msg_pos_llh_acc_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->at_accuracy = 6297.2001953125;
    test_msg->confidence_and_geoid = 95;
    test_msg->ct_accuracy = 1948.199951171875;
    test_msg->flags = 72;
    test_msg->h_accuracy = 2410.199951171875;
    test_msg->h_ellipse.orientation = 2550.199951171875;
    test_msg->h_ellipse.semi_major = 8248.2001953125;
    test_msg->h_ellipse.semi_minor = 3202.199951171875;
    test_msg->height = 4257.2;
    test_msg->lat = 7563.2;
    test_msg->lon = 8494.2;
    test_msg->n_sats = 27;
    test_msg->orthometric_height = 4965.2;
    test_msg->tow = 309229607;
    test_msg->v_accuracy = 5539.2001953125;
    sbp_payload_send(&sbp_state, 0x218, 7170, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 7170,
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
    ck_assert_msg(last_frame.sender_id == 7170,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x218,
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
    msg_pos_llh_acc_t *check_msg = (msg_pos_llh_acc_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        (check_msg->at_accuracy * 100 - 6297.20019531 * 100) < 0.05,
        "incorrect value for at_accuracy, expected 6297.20019531, is %f",
        check_msg->at_accuracy);
    ck_assert_msg(
        check_msg->confidence_and_geoid == 95,
        "incorrect value for confidence_and_geoid, expected 95, is %d",
        check_msg->confidence_and_geoid);
    ck_assert_msg(
        (check_msg->ct_accuracy * 100 - 1948.19995117 * 100) < 0.05,
        "incorrect value for ct_accuracy, expected 1948.19995117, is %f",
        check_msg->ct_accuracy);
    ck_assert_msg(check_msg->flags == 72,
                  "incorrect value for flags, expected 72, is %d",
                  check_msg->flags);
    ck_assert_msg(
        (check_msg->h_accuracy * 100 - 2410.19995117 * 100) < 0.05,
        "incorrect value for h_accuracy, expected 2410.19995117, is %f",
        check_msg->h_accuracy);
    ck_assert_msg(
        (check_msg->h_ellipse.orientation * 100 - 2550.19995117 * 100) < 0.05,
        "incorrect value for h_ellipse.orientation, expected 2550.19995117, is "
        "%f",
        check_msg->h_ellipse.orientation);
    ck_assert_msg(
        (check_msg->h_ellipse.semi_major * 100 - 8248.20019531 * 100) < 0.05,
        "incorrect value for h_ellipse.semi_major, expected 8248.20019531, is "
        "%f",
        check_msg->h_ellipse.semi_major);
    ck_assert_msg(
        (check_msg->h_ellipse.semi_minor * 100 - 3202.19995117 * 100) < 0.05,
        "incorrect value for h_ellipse.semi_minor, expected 3202.19995117, is "
        "%f",
        check_msg->h_ellipse.semi_minor);
    ck_assert_msg((check_msg->height * 100 - 4257.2 * 100) < 0.05,
                  "incorrect value for height, expected 4257.2, is %f",
                  check_msg->height);
    ck_assert_msg((check_msg->lat * 100 - 7563.2 * 100) < 0.05,
                  "incorrect value for lat, expected 7563.2, is %f",
                  check_msg->lat);
    ck_assert_msg((check_msg->lon * 100 - 8494.2 * 100) < 0.05,
                  "incorrect value for lon, expected 8494.2, is %f",
                  check_msg->lon);
    ck_assert_msg(check_msg->n_sats == 27,
                  "incorrect value for n_sats, expected 27, is %d",
                  check_msg->n_sats);
    ck_assert_msg(
        (check_msg->orthometric_height * 100 - 4965.2 * 100) < 0.05,
        "incorrect value for orthometric_height, expected 4965.2, is %f",
        check_msg->orthometric_height);
    ck_assert_msg(check_msg->tow == 309229607,
                  "incorrect value for tow, expected 309229607, is %d",
                  check_msg->tow);
    ck_assert_msg(
        (check_msg->v_accuracy * 100 - 5539.20019531 * 100) < 0.05,
        "incorrect value for v_accuracy, expected 5539.20019531, is %f",
        check_msg->v_accuracy);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_navigation_MsgPosLlhAcc_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_navigation_MsgPosLlhAcc");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_navigation_MsgPosLlhAcc");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_navigation_MsgPosLlhAcc);
  suite_add_tcase(s, tc_acq);
  return s;
}