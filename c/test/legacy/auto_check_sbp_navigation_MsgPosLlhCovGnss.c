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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhCovGnss.yaml by
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

START_TEST(test_legacy_auto_check_sbp_navigation_MsgPosLlhCovGnss) {
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

    sbp_payload_callback_register(&sbp_state, 0x231, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x231, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  49,  2,   0,   16,  54,  24,  229, 233, 29,  73,  123, 28,
        207, 101, 234, 66,  64,  100, 168, 19,  20,  86,  146, 94,  192,
        214, 198, 35,  120, 209, 100, 49,  192, 12,  102, 245, 59,  6,
        181, 192, 185, 168, 79,  243, 58,  96,  60,  148, 59,  253, 58,
        93,  186, 159, 174, 6,   61,  18,  4,   10,  196,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_llh_cov_gnss_t *test_msg =
        (msg_pos_llh_cov_gnss_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->cov_d_d = 0.03288137540221214;
    test_msg->cov_e_d = -0.0008439270895905793;
    test_msg->cov_e_e = 0.004523798823356628;
    test_msg->cov_n_d = 0.0018563168123364449;
    test_msg->cov_n_e = -0.00036755966721102595;
    test_msg->cov_n_n = 0.007488971576094627;
    test_msg->flags = 4;
    test_msg->height = -17.39382124780135;
    test_msg->lat = 37.83123196497633;
    test_msg->lon = -122.28650381011681;
    test_msg->n_sats = 18;
    test_msg->tow = 501867800;
    sbp_payload_send(&sbp_state, 0x231, 4096, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 4096,
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
    ck_assert_msg(last_frame.sender_id == 4096,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x231,
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
    msg_pos_llh_cov_gnss_t *check_msg =
        (msg_pos_llh_cov_gnss_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        (check_msg->cov_d_d * 100 - 0.0328813754022 * 100) < 0.05,
        "incorrect value for cov_d_d, expected 0.0328813754022, is %f",
        check_msg->cov_d_d);
    ck_assert_msg(
        (check_msg->cov_e_d * 100 - -0.000843927089591 * 100) < 0.05,
        "incorrect value for cov_e_d, expected -0.000843927089591, is %f",
        check_msg->cov_e_d);
    ck_assert_msg(
        (check_msg->cov_e_e * 100 - 0.00452379882336 * 100) < 0.05,
        "incorrect value for cov_e_e, expected 0.00452379882336, is %f",
        check_msg->cov_e_e);
    ck_assert_msg(
        (check_msg->cov_n_d * 100 - 0.00185631681234 * 100) < 0.05,
        "incorrect value for cov_n_d, expected 0.00185631681234, is %f",
        check_msg->cov_n_d);
    ck_assert_msg(
        (check_msg->cov_n_e * 100 - -0.000367559667211 * 100) < 0.05,
        "incorrect value for cov_n_e, expected -0.000367559667211, is %f",
        check_msg->cov_n_e);
    ck_assert_msg(
        (check_msg->cov_n_n * 100 - 0.00748897157609 * 100) < 0.05,
        "incorrect value for cov_n_n, expected 0.00748897157609, is %f",
        check_msg->cov_n_n);
    ck_assert_msg(check_msg->flags == 4,
                  "incorrect value for flags, expected 4, is %d",
                  check_msg->flags);
    ck_assert_msg((check_msg->height * 100 - -17.3938212478 * 100) < 0.05,
                  "incorrect value for height, expected -17.3938212478, is %f",
                  check_msg->height);
    ck_assert_msg((check_msg->lat * 100 - 37.831231965 * 100) < 0.05,
                  "incorrect value for lat, expected 37.831231965, is %f",
                  check_msg->lat);
    ck_assert_msg((check_msg->lon * 100 - -122.28650381 * 100) < 0.05,
                  "incorrect value for lon, expected -122.28650381, is %f",
                  check_msg->lon);
    ck_assert_msg(check_msg->n_sats == 18,
                  "incorrect value for n_sats, expected 18, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 501867800,
                  "incorrect value for tow, expected 501867800, is %d",
                  check_msg->tow);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_navigation_MsgPosLlhCovGnss_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_navigation_MsgPosLlhCovGnss");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_navigation_MsgPosLlhCovGnss");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_navigation_MsgPosLlhCovGnss);
  suite_add_tcase(s, tc_acq);
  return s;
}