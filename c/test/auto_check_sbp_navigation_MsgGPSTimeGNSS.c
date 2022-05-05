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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeGNSS.yaml by
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

START_TEST(test_auto_check_sbp_navigation_MsgGPSTimeGNSS) {
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

    sbp_callback_register(&sbp_state, 0x104, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,  1,   211, 136, 11, 128, 7,   40, 244,
        122, 19, 244, 139, 2,   0,  0,   153, 88,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_gnss.flags = 0;

    test_msg.gps_time_gnss.ns_residual = 166900;

    test_msg.gps_time_gnss.tow = 326825000;

    test_msg.gps_time_gnss.wn = 1920;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeGnss, 35027, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgGpsTimeGnss, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_gnss.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_gnss.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_gnss.flags);

    ck_assert_msg(last_msg.msg.gps_time_gnss.ns_residual == 166900,
                  "incorrect value for last_msg.msg.gps_time_gnss.ns_residual, "
                  "expected 166900, is %d",
                  last_msg.msg.gps_time_gnss.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_gnss.tow == 326825000,
                  "incorrect value for last_msg.msg.gps_time_gnss.tow, "
                  "expected 326825000, is %d",
                  last_msg.msg.gps_time_gnss.tow);

    ck_assert_msg(last_msg.msg.gps_time_gnss.wn == 1920,
                  "incorrect value for last_msg.msg.gps_time_gnss.wn, expected "
                  "1920, is %d",
                  last_msg.msg.gps_time_gnss.wn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x104, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,  1,   211, 136, 11, 128, 7,   28,  246,
        122, 19, 126, 234, 3,   0,  0,   250, 195,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_gnss.flags = 0;

    test_msg.gps_time_gnss.ns_residual = 256638;

    test_msg.gps_time_gnss.tow = 326825500;

    test_msg.gps_time_gnss.wn = 1920;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeGnss, 35027, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgGpsTimeGnss, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_gnss.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_gnss.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_gnss.flags);

    ck_assert_msg(last_msg.msg.gps_time_gnss.ns_residual == 256638,
                  "incorrect value for last_msg.msg.gps_time_gnss.ns_residual, "
                  "expected 256638, is %d",
                  last_msg.msg.gps_time_gnss.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_gnss.tow == 326825500,
                  "incorrect value for last_msg.msg.gps_time_gnss.tow, "
                  "expected 326825500, is %d",
                  last_msg.msg.gps_time_gnss.tow);

    ck_assert_msg(last_msg.msg.gps_time_gnss.wn == 1920,
                  "incorrect value for last_msg.msg.gps_time_gnss.wn, expected "
                  "1920, is %d",
                  last_msg.msg.gps_time_gnss.wn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x104, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,  1,   211, 136, 11, 128, 7,   16,  248,
        122, 19, 129, 12,  4,   0,  0,   183, 148,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_gnss.flags = 0;

    test_msg.gps_time_gnss.ns_residual = 265345;

    test_msg.gps_time_gnss.tow = 326826000;

    test_msg.gps_time_gnss.wn = 1920;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeGnss, 35027, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgGpsTimeGnss, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_gnss.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_gnss.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_gnss.flags);

    ck_assert_msg(last_msg.msg.gps_time_gnss.ns_residual == 265345,
                  "incorrect value for last_msg.msg.gps_time_gnss.ns_residual, "
                  "expected 265345, is %d",
                  last_msg.msg.gps_time_gnss.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_gnss.tow == 326826000,
                  "incorrect value for last_msg.msg.gps_time_gnss.tow, "
                  "expected 326826000, is %d",
                  last_msg.msg.gps_time_gnss.tow);

    ck_assert_msg(last_msg.msg.gps_time_gnss.wn == 1920,
                  "incorrect value for last_msg.msg.gps_time_gnss.wn, expected "
                  "1920, is %d",
                  last_msg.msg.gps_time_gnss.wn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x104, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,  1,   211, 136, 11, 128, 7,   4,   250,
        122, 19, 137, 204, 4,   0,  0,   137, 101,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_gnss.flags = 0;

    test_msg.gps_time_gnss.ns_residual = 314505;

    test_msg.gps_time_gnss.tow = 326826500;

    test_msg.gps_time_gnss.wn = 1920;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeGnss, 35027, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgGpsTimeGnss, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_gnss.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_gnss.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_gnss.flags);

    ck_assert_msg(last_msg.msg.gps_time_gnss.ns_residual == 314505,
                  "incorrect value for last_msg.msg.gps_time_gnss.ns_residual, "
                  "expected 314505, is %d",
                  last_msg.msg.gps_time_gnss.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_gnss.tow == 326826500,
                  "incorrect value for last_msg.msg.gps_time_gnss.tow, "
                  "expected 326826500, is %d",
                  last_msg.msg.gps_time_gnss.tow);

    ck_assert_msg(last_msg.msg.gps_time_gnss.wn == 1920,
                  "incorrect value for last_msg.msg.gps_time_gnss.wn, expected "
                  "1920, is %d",
                  last_msg.msg.gps_time_gnss.wn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, 0x104, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,  1,   211, 136, 11, 128, 7,  248, 251,
        122, 19, 181, 137, 5,   0,  0,   15, 225,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_gnss.flags = 0;

    test_msg.gps_time_gnss.ns_residual = 362933;

    test_msg.gps_time_gnss.tow = 326827000;

    test_msg.gps_time_gnss.wn = 1920;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeGnss, 35027, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgGpsTimeGnss, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.gps_time_gnss.flags == 0,
                  "incorrect value for last_msg.msg.gps_time_gnss.flags, "
                  "expected 0, is %d",
                  last_msg.msg.gps_time_gnss.flags);

    ck_assert_msg(last_msg.msg.gps_time_gnss.ns_residual == 362933,
                  "incorrect value for last_msg.msg.gps_time_gnss.ns_residual, "
                  "expected 362933, is %d",
                  last_msg.msg.gps_time_gnss.ns_residual);

    ck_assert_msg(last_msg.msg.gps_time_gnss.tow == 326827000,
                  "incorrect value for last_msg.msg.gps_time_gnss.tow, "
                  "expected 326827000, is %d",
                  last_msg.msg.gps_time_gnss.tow);

    ck_assert_msg(last_msg.msg.gps_time_gnss.wn == 1920,
                  "incorrect value for last_msg.msg.gps_time_gnss.wn, expected "
                  "1920, is %d",
                  last_msg.msg.gps_time_gnss.wn);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgGPSTimeGNSS_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgGPSTimeGNSS");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgGPSTimeGNSS");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgGPSTimeGNSS);
  suite_add_tcase(s, tc_acq);
  return s;
}