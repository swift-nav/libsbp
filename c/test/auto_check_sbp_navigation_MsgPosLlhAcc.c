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
#include <libsbp/sbp.h>
#include <libsbp/v4/navigation.h>
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

START_TEST(test_auto_check_sbp_navigation_MsgPosLlhAcc) {
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

    sbp_callback_register(&sbp_state, 0x218, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  24,  2,   2,   28,  67,  39,  120, 110, 18,  51,  51,  51,
        51,  51,  139, 189, 64,  154, 153, 153, 153, 25,  151, 192, 64,
        51,  51,  51,  51,  51,  161, 176, 64,  51,  51,  51,  51,  51,
        101, 179, 64,  51,  163, 22,  69,  154, 25,  173, 69,  102, 134,
        243, 68,  154, 201, 196, 69,  205, 224, 0,   70,  51,  35,  72,
        69,  51,  99,  31,  69,  95,  27,  72,  220, 177,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_acc.at_accuracy = 6297.2001953125;

    test_msg.pos_llh_acc.confidence_and_geoid = 95;

    test_msg.pos_llh_acc.ct_accuracy = 1948.199951171875;

    test_msg.pos_llh_acc.flags = 72;

    test_msg.pos_llh_acc.h_accuracy = 2410.199951171875;

    test_msg.pos_llh_acc.h_ellipse.orientation = 2550.199951171875;

    test_msg.pos_llh_acc.h_ellipse.semi_major = 8248.2001953125;

    test_msg.pos_llh_acc.h_ellipse.semi_minor = 3202.199951171875;

    test_msg.pos_llh_acc.height = 4257.2;

    test_msg.pos_llh_acc.lat = 7563.2;

    test_msg.pos_llh_acc.lon = 8494.2;

    test_msg.pos_llh_acc.n_sats = 27;

    test_msg.pos_llh_acc.orthometric_height = 4965.2;

    test_msg.pos_llh_acc.tow = 309229607;

    test_msg.pos_llh_acc.v_accuracy = 5539.2001953125;

    sbp_message_send(&sbp_state, SbpMsgPosLlhAcc, 7170, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 7170,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosLlhAcc, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg((last_msg.msg.pos_llh_acc.at_accuracy * 100 -
                   6297.20019531 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh_acc.at_accuracy, "
                  "expected 6297.20019531, is %s",
                  last_msg.msg.pos_llh_acc.at_accuracy);

    ck_assert_msg(
        last_msg.msg.pos_llh_acc.confidence_and_geoid == 95,
        "incorrect value for last_msg.msg.pos_llh_acc.confidence_and_geoid, "
        "expected 95, is %d",
        last_msg.msg.pos_llh_acc.confidence_and_geoid);

    ck_assert_msg((last_msg.msg.pos_llh_acc.ct_accuracy * 100 -
                   1948.19995117 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh_acc.ct_accuracy, "
                  "expected 1948.19995117, is %s",
                  last_msg.msg.pos_llh_acc.ct_accuracy);

    ck_assert_msg(last_msg.msg.pos_llh_acc.flags == 72,
                  "incorrect value for last_msg.msg.pos_llh_acc.flags, "
                  "expected 72, is %d",
                  last_msg.msg.pos_llh_acc.flags);

    ck_assert_msg((last_msg.msg.pos_llh_acc.h_accuracy * 100 -
                   2410.19995117 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh_acc.h_accuracy, "
                  "expected 2410.19995117, is %s",
                  last_msg.msg.pos_llh_acc.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_acc.h_ellipse.orientation * 100 -
         2550.19995117 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_acc.h_ellipse.orientation, "
        "expected 2550.19995117, is %s",
        last_msg.msg.pos_llh_acc.h_ellipse.orientation);

    ck_assert_msg(
        (last_msg.msg.pos_llh_acc.h_ellipse.semi_major * 100 -
         8248.20019531 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_acc.h_ellipse.semi_major, "
        "expected 8248.20019531, is %s",
        last_msg.msg.pos_llh_acc.h_ellipse.semi_major);

    ck_assert_msg(
        (last_msg.msg.pos_llh_acc.h_ellipse.semi_minor * 100 -
         3202.19995117 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_acc.h_ellipse.semi_minor, "
        "expected 3202.19995117, is %s",
        last_msg.msg.pos_llh_acc.h_ellipse.semi_minor);

    ck_assert_msg((last_msg.msg.pos_llh_acc.height * 100 - 4257.2 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh_acc.height, "
                  "expected 4257.2, is %s",
                  last_msg.msg.pos_llh_acc.height);

    ck_assert_msg((last_msg.msg.pos_llh_acc.lat * 100 - 7563.2 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh_acc.lat, expected "
                  "7563.2, is %s",
                  last_msg.msg.pos_llh_acc.lat);

    ck_assert_msg((last_msg.msg.pos_llh_acc.lon * 100 - 8494.2 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh_acc.lon, expected "
                  "8494.2, is %s",
                  last_msg.msg.pos_llh_acc.lon);

    ck_assert_msg(last_msg.msg.pos_llh_acc.n_sats == 27,
                  "incorrect value for last_msg.msg.pos_llh_acc.n_sats, "
                  "expected 27, is %d",
                  last_msg.msg.pos_llh_acc.n_sats);

    ck_assert_msg(
        (last_msg.msg.pos_llh_acc.orthometric_height * 100 - 4965.2 * 100) <
            0.05,
        "incorrect value for last_msg.msg.pos_llh_acc.orthometric_height, "
        "expected 4965.2, is %s",
        last_msg.msg.pos_llh_acc.orthometric_height);

    ck_assert_msg(last_msg.msg.pos_llh_acc.tow == 309229607,
                  "incorrect value for last_msg.msg.pos_llh_acc.tow, expected "
                  "309229607, is %d",
                  last_msg.msg.pos_llh_acc.tow);

    ck_assert_msg((last_msg.msg.pos_llh_acc.v_accuracy * 100 -
                   5539.20019531 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh_acc.v_accuracy, "
                  "expected 5539.20019531, is %s",
                  last_msg.msg.pos_llh_acc.v_accuracy);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgPosLlhAcc_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgPosLlhAcc");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgPosLlhAcc");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgPosLlhAcc);
  suite_add_tcase(s, tc_acq);
  return s;
}