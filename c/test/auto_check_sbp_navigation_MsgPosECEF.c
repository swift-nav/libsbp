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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEF.yaml by generate.py.
// Do not modify by hand!

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

START_TEST(test_auto_check_sbp_navigation_MsgPosECEF) {
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

    sbp_callback_register(&sbp_state, 0x209, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  9,   2,  211, 136, 32,  16, 248, 122, 19,  73, 29,  46, 132,
        182, 122, 68, 193, 219, 192, 29, 176, 121, 119, 80, 193, 83, 11,
        210, 90,  79, 75,  77,  65,  0,  0,   15,  2,   84, 6,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef.accuracy = 0;

    test_msg.pos_ecef.flags = 2;

    test_msg.pos_ecef.n_sats = 15;

    test_msg.pos_ecef.tow = 326826000;

    test_msg.pos_ecef.x = -2684269.0326572997;

    test_msg.pos_ecef.y = -4316646.751816;

    test_msg.pos_ecef.z = 3839646.7095350414;

    sbp_message_send(&sbp_state, SbpMsgPosEcef, 35027, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgPosEcef, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.pos_ecef.accuracy == 0,
        "incorrect value for last_msg.msg.pos_ecef.accuracy, expected 0, is %d",
        last_msg.msg.pos_ecef.accuracy);

    ck_assert_msg(
        last_msg.msg.pos_ecef.flags == 2,
        "incorrect value for last_msg.msg.pos_ecef.flags, expected 2, is %d",
        last_msg.msg.pos_ecef.flags);

    ck_assert_msg(
        last_msg.msg.pos_ecef.n_sats == 15,
        "incorrect value for last_msg.msg.pos_ecef.n_sats, expected 15, is %d",
        last_msg.msg.pos_ecef.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef.tow == 326826000,
                  "incorrect value for last_msg.msg.pos_ecef.tow, expected "
                  "326826000, is %d",
                  last_msg.msg.pos_ecef.tow);

    ck_assert_msg((last_msg.msg.pos_ecef.x * 100 - -2684269.03266 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.x, expected "
                  "-2684269.03266, is %s",
                  last_msg.msg.pos_ecef.x);

    ck_assert_msg((last_msg.msg.pos_ecef.y * 100 - -4316646.75182 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.y, expected "
                  "-4316646.75182, is %s",
                  last_msg.msg.pos_ecef.y);

    ck_assert_msg((last_msg.msg.pos_ecef.z * 100 - 3839646.70954 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.z, expected "
                  "3839646.70954, is %s",
                  last_msg.msg.pos_ecef.z);
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

    sbp_callback_register(&sbp_state, 0x209, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  9,   2,  211, 136, 32,  248, 251, 122, 19,  103, 106, 57,  136,
        182, 122, 68, 193, 176, 242, 200, 176, 121, 119, 80,  193, 244, 135,
        97,  59,  79, 75,  77,  65,  0,   0,   15,  2,   147, 216,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef.accuracy = 0;

    test_msg.pos_ecef.flags = 2;

    test_msg.pos_ecef.n_sats = 15;

    test_msg.pos_ecef.tow = 326827000;

    test_msg.pos_ecef.x = -2684269.064252186;

    test_msg.pos_ecef.y = -4316646.762264892;

    test_msg.pos_ecef.z = 3839646.463913912;

    sbp_message_send(&sbp_state, SbpMsgPosEcef, 35027, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgPosEcef, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.pos_ecef.accuracy == 0,
        "incorrect value for last_msg.msg.pos_ecef.accuracy, expected 0, is %d",
        last_msg.msg.pos_ecef.accuracy);

    ck_assert_msg(
        last_msg.msg.pos_ecef.flags == 2,
        "incorrect value for last_msg.msg.pos_ecef.flags, expected 2, is %d",
        last_msg.msg.pos_ecef.flags);

    ck_assert_msg(
        last_msg.msg.pos_ecef.n_sats == 15,
        "incorrect value for last_msg.msg.pos_ecef.n_sats, expected 15, is %d",
        last_msg.msg.pos_ecef.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef.tow == 326827000,
                  "incorrect value for last_msg.msg.pos_ecef.tow, expected "
                  "326827000, is %d",
                  last_msg.msg.pos_ecef.tow);

    ck_assert_msg((last_msg.msg.pos_ecef.x * 100 - -2684269.06425 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.x, expected "
                  "-2684269.06425, is %s",
                  last_msg.msg.pos_ecef.x);

    ck_assert_msg((last_msg.msg.pos_ecef.y * 100 - -4316646.76226 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.y, expected "
                  "-4316646.76226, is %s",
                  last_msg.msg.pos_ecef.y);

    ck_assert_msg((last_msg.msg.pos_ecef.z * 100 - 3839646.46391 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.z, expected "
                  "3839646.46391, is %s",
                  last_msg.msg.pos_ecef.z);
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

    sbp_callback_register(&sbp_state, 0x209, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  9,   2,  211, 136, 32,  224, 255, 122, 19,  101, 179, 242, 182,
        182, 122, 68, 193, 130, 196, 145, 199, 121, 119, 80,  193, 212, 10,
        253, 15,  79, 75,  77,  65,  0,   0,   15,  2,   40,  201,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef.accuracy = 0;

    test_msg.pos_ecef.flags = 2;

    test_msg.pos_ecef.n_sats = 15;

    test_msg.pos_ecef.tow = 326828000;

    test_msg.pos_ecef.x = -2684269.4292816394;

    test_msg.pos_ecef.y = -4316647.118271949;

    test_msg.pos_ecef.z = 3839646.124909738;

    sbp_message_send(&sbp_state, SbpMsgPosEcef, 35027, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgPosEcef, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.pos_ecef.accuracy == 0,
        "incorrect value for last_msg.msg.pos_ecef.accuracy, expected 0, is %d",
        last_msg.msg.pos_ecef.accuracy);

    ck_assert_msg(
        last_msg.msg.pos_ecef.flags == 2,
        "incorrect value for last_msg.msg.pos_ecef.flags, expected 2, is %d",
        last_msg.msg.pos_ecef.flags);

    ck_assert_msg(
        last_msg.msg.pos_ecef.n_sats == 15,
        "incorrect value for last_msg.msg.pos_ecef.n_sats, expected 15, is %d",
        last_msg.msg.pos_ecef.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef.tow == 326828000,
                  "incorrect value for last_msg.msg.pos_ecef.tow, expected "
                  "326828000, is %d",
                  last_msg.msg.pos_ecef.tow);

    ck_assert_msg((last_msg.msg.pos_ecef.x * 100 - -2684269.42928 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.x, expected "
                  "-2684269.42928, is %s",
                  last_msg.msg.pos_ecef.x);

    ck_assert_msg((last_msg.msg.pos_ecef.y * 100 - -4316647.11827 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.y, expected "
                  "-4316647.11827, is %s",
                  last_msg.msg.pos_ecef.y);

    ck_assert_msg((last_msg.msg.pos_ecef.z * 100 - 3839646.12491 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.z, expected "
                  "3839646.12491, is %s",
                  last_msg.msg.pos_ecef.z);
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

    sbp_callback_register(&sbp_state, 0x209, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  9,   2,  211, 136, 32, 200, 3,   123, 19,  146, 214, 132, 215,
        182, 122, 68, 193, 213, 68, 49,  215, 121, 119, 80,  193, 71,  34,
        110, 243, 78, 75,  77,  65, 0,   0,   15,  2,   187, 86,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef.accuracy = 0;

    test_msg.pos_ecef.flags = 2;

    test_msg.pos_ecef.n_sats = 15;

    test_msg.pos_ecef.tow = 326829000;

    test_msg.pos_ecef.x = -2684269.683741399;

    test_msg.pos_ecef.y = -4316647.3623821335;

    test_msg.pos_ecef.z = 3839645.90179852;

    sbp_message_send(&sbp_state, SbpMsgPosEcef, 35027, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 35027,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgPosEcef, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.pos_ecef.accuracy == 0,
        "incorrect value for last_msg.msg.pos_ecef.accuracy, expected 0, is %d",
        last_msg.msg.pos_ecef.accuracy);

    ck_assert_msg(
        last_msg.msg.pos_ecef.flags == 2,
        "incorrect value for last_msg.msg.pos_ecef.flags, expected 2, is %d",
        last_msg.msg.pos_ecef.flags);

    ck_assert_msg(
        last_msg.msg.pos_ecef.n_sats == 15,
        "incorrect value for last_msg.msg.pos_ecef.n_sats, expected 15, is %d",
        last_msg.msg.pos_ecef.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef.tow == 326829000,
                  "incorrect value for last_msg.msg.pos_ecef.tow, expected "
                  "326829000, is %d",
                  last_msg.msg.pos_ecef.tow);

    ck_assert_msg((last_msg.msg.pos_ecef.x * 100 - -2684269.68374 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.x, expected "
                  "-2684269.68374, is %s",
                  last_msg.msg.pos_ecef.x);

    ck_assert_msg((last_msg.msg.pos_ecef.y * 100 - -4316647.36238 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.y, expected "
                  "-4316647.36238, is %s",
                  last_msg.msg.pos_ecef.y);

    ck_assert_msg((last_msg.msg.pos_ecef.z * 100 - 3839645.9018 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_ecef.z, expected "
                  "3839645.9018, is %s",
                  last_msg.msg.pos_ecef.z);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgPosECEF_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgPosECEF");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgPosECEF");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgPosECEF);
  suite_add_tcase(s, tc_acq);
  return s;
}