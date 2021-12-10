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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepC.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/acquisition.h>
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

START_TEST(test_auto_check_sbp_acquisition_MsgAcqResultDepC) {
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

    sbp_callback_register(&sbp_state, 0x1f, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  31, 0,  40, 12,  16, 72, 9, 34, 66, 155, 152,
        228, 67, 28, 34, 221, 68, 10, 0, 0,  0,  9,   189,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_c.cf = 1769.06591796875;

    test_msg.acq_result_dep_c.cn0 = 40.509063720703125;

    test_msg.acq_result_dep_c.cp = 457.1922302246094;

    test_msg.acq_result_dep_c.sid.code = 0;

    test_msg.acq_result_dep_c.sid.reserved = 0;

    test_msg.acq_result_dep_c.sid.sat = 10;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepC, 3112, &test_msg,
                     &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 3112,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgAcqResultDepC, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cf * 100 - 1769.06591797 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cf, expected "
        "1769.06591797, is %s",
        last_msg.msg.acq_result_dep_c.cf);

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cn0 * 100 - 40.5090637207 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cn0, expected "
        "40.5090637207, is %s",
        last_msg.msg.acq_result_dep_c.cn0);

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cp * 100 - 457.192230225 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cp, expected "
        "457.192230225, is %s",
        last_msg.msg.acq_result_dep_c.cp);

    ck_assert_msg(last_msg.msg.acq_result_dep_c.sid.code == 0,
                  "incorrect value for last_msg.msg.acq_result_dep_c.sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.acq_result_dep_c.sid.code);

    ck_assert_msg(
        last_msg.msg.acq_result_dep_c.sid.reserved == 0,
        "incorrect value for last_msg.msg.acq_result_dep_c.sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.acq_result_dep_c.sid.reserved);

    ck_assert_msg(last_msg.msg.acq_result_dep_c.sid.sat == 10,
                  "incorrect value for last_msg.msg.acq_result_dep_c.sid.sat, "
                  "expected 10, is %d",
                  last_msg.msg.acq_result_dep_c.sid.sat);
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

    sbp_callback_register(&sbp_state, 0x1f, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 31, 0,  40,  12,  16,  132, 250, 45, 66, 207, 93,
        88, 68, 68, 185, 252, 195, 6,   0,   0,  0,  136, 185,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_c.cf = -505.4473876953125;

    test_msg.acq_result_dep_c.cn0 = 43.49464416503906;

    test_msg.acq_result_dep_c.cp = 865.4657592773438;

    test_msg.acq_result_dep_c.sid.code = 0;

    test_msg.acq_result_dep_c.sid.reserved = 0;

    test_msg.acq_result_dep_c.sid.sat = 6;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepC, 3112, &test_msg,
                     &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 3112,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgAcqResultDepC, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cf * 100 - -505.447387695 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cf, expected "
        "-505.447387695, is %s",
        last_msg.msg.acq_result_dep_c.cf);

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cn0 * 100 - 43.494644165 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cn0, expected "
        "43.494644165, is %s",
        last_msg.msg.acq_result_dep_c.cn0);

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cp * 100 - 865.465759277 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cp, expected "
        "865.465759277, is %s",
        last_msg.msg.acq_result_dep_c.cp);

    ck_assert_msg(last_msg.msg.acq_result_dep_c.sid.code == 0,
                  "incorrect value for last_msg.msg.acq_result_dep_c.sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.acq_result_dep_c.sid.code);

    ck_assert_msg(
        last_msg.msg.acq_result_dep_c.sid.reserved == 0,
        "incorrect value for last_msg.msg.acq_result_dep_c.sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.acq_result_dep_c.sid.reserved);

    ck_assert_msg(last_msg.msg.acq_result_dep_c.sid.sat == 6,
                  "incorrect value for last_msg.msg.acq_result_dep_c.sid.sat, "
                  "expected 6, is %d",
                  last_msg.msg.acq_result_dep_c.sid.sat);
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

    sbp_callback_register(&sbp_state, 0x1f, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  31, 0,   40,  12,  16,  163, 223, 24, 66, 64,  91,
        102, 67, 202, 243, 157, 196, 13,  0,   0,  0,  150, 161,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_c.cf = -1263.618408203125;

    test_msg.acq_result_dep_c.cn0 = 38.2183952331543;

    test_msg.acq_result_dep_c.cp = 230.3564453125;

    test_msg.acq_result_dep_c.sid.code = 0;

    test_msg.acq_result_dep_c.sid.reserved = 0;

    test_msg.acq_result_dep_c.sid.sat = 13;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepC, 3112, &test_msg,
                     &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 3112,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgAcqResultDepC, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cf * 100 - -1263.6184082 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cf, expected "
        "-1263.6184082, is %s",
        last_msg.msg.acq_result_dep_c.cf);

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cn0 * 100 - 38.2183952332 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cn0, expected "
        "38.2183952332, is %s",
        last_msg.msg.acq_result_dep_c.cn0);

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cp * 100 - 230.356445312 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cp, expected "
        "230.356445312, is %s",
        last_msg.msg.acq_result_dep_c.cp);

    ck_assert_msg(last_msg.msg.acq_result_dep_c.sid.code == 0,
                  "incorrect value for last_msg.msg.acq_result_dep_c.sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.acq_result_dep_c.sid.code);

    ck_assert_msg(
        last_msg.msg.acq_result_dep_c.sid.reserved == 0,
        "incorrect value for last_msg.msg.acq_result_dep_c.sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.acq_result_dep_c.sid.reserved);

    ck_assert_msg(last_msg.msg.acq_result_dep_c.sid.sat == 13,
                  "incorrect value for last_msg.msg.acq_result_dep_c.sid.sat, "
                  "expected 13, is %d",
                  last_msg.msg.acq_result_dep_c.sid.sat);
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

    sbp_callback_register(&sbp_state, 0x1f, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  31, 0,   40,  12, 16, 129, 65, 21, 66, 224, 214,
        124, 67, 243, 138, 61, 69, 1,   0,  0,  0,  109, 209,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_c.cf = 3032.684326171875;

    test_msg.acq_result_dep_c.cn0 = 37.313968658447266;

    test_msg.acq_result_dep_c.cp = 252.83935546875;

    test_msg.acq_result_dep_c.sid.code = 0;

    test_msg.acq_result_dep_c.sid.reserved = 0;

    test_msg.acq_result_dep_c.sid.sat = 1;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepC, 3112, &test_msg,
                     &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 3112,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgAcqResultDepC, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cf * 100 - 3032.68432617 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cf, expected "
        "3032.68432617, is %s",
        last_msg.msg.acq_result_dep_c.cf);

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cn0 * 100 - 37.3139686584 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cn0, expected "
        "37.3139686584, is %s",
        last_msg.msg.acq_result_dep_c.cn0);

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cp * 100 - 252.839355469 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cp, expected "
        "252.839355469, is %s",
        last_msg.msg.acq_result_dep_c.cp);

    ck_assert_msg(last_msg.msg.acq_result_dep_c.sid.code == 0,
                  "incorrect value for last_msg.msg.acq_result_dep_c.sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.acq_result_dep_c.sid.code);

    ck_assert_msg(
        last_msg.msg.acq_result_dep_c.sid.reserved == 0,
        "incorrect value for last_msg.msg.acq_result_dep_c.sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.acq_result_dep_c.sid.reserved);

    ck_assert_msg(last_msg.msg.acq_result_dep_c.sid.sat == 1,
                  "incorrect value for last_msg.msg.acq_result_dep_c.sid.sat, "
                  "expected 1, is %d",
                  last_msg.msg.acq_result_dep_c.sid.sat);
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

    sbp_callback_register(&sbp_state, 0x1f, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  31, 0,   40,  12, 16, 126, 35, 62, 66, 226, 37,
        102, 68, 202, 243, 29, 69, 27,  0,  0,  0,  91,  67,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_c.cf = 2527.23681640625;

    test_msg.acq_result_dep_c.cn0 = 47.53466033935547;

    test_msg.acq_result_dep_c.cp = 920.5919189453125;

    test_msg.acq_result_dep_c.sid.code = 0;

    test_msg.acq_result_dep_c.sid.reserved = 0;

    test_msg.acq_result_dep_c.sid.sat = 27;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepC, 3112, &test_msg,
                     &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 3112,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgAcqResultDepC, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cf * 100 - 2527.23681641 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cf, expected "
        "2527.23681641, is %s",
        last_msg.msg.acq_result_dep_c.cf);

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cn0 * 100 - 47.5346603394 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cn0, expected "
        "47.5346603394, is %s",
        last_msg.msg.acq_result_dep_c.cn0);

    ck_assert_msg(
        (last_msg.msg.acq_result_dep_c.cp * 100 - 920.591918945 * 100) < 0.05,
        "incorrect value for last_msg.msg.acq_result_dep_c.cp, expected "
        "920.591918945, is %s",
        last_msg.msg.acq_result_dep_c.cp);

    ck_assert_msg(last_msg.msg.acq_result_dep_c.sid.code == 0,
                  "incorrect value for last_msg.msg.acq_result_dep_c.sid.code, "
                  "expected 0, is %d",
                  last_msg.msg.acq_result_dep_c.sid.code);

    ck_assert_msg(
        last_msg.msg.acq_result_dep_c.sid.reserved == 0,
        "incorrect value for last_msg.msg.acq_result_dep_c.sid.reserved, "
        "expected 0, is %d",
        last_msg.msg.acq_result_dep_c.sid.reserved);

    ck_assert_msg(last_msg.msg.acq_result_dep_c.sid.sat == 27,
                  "incorrect value for last_msg.msg.acq_result_dep_c.sid.sat, "
                  "expected 27, is %d",
                  last_msg.msg.acq_result_dep_c.sid.sat);
  }
}
END_TEST

Suite *auto_check_sbp_acquisition_MsgAcqResultDepC_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_acquisition_MsgAcqResultDepC");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_acquisition_MsgAcqResultDepC");
  tcase_add_test(tc_acq, test_auto_check_sbp_acquisition_MsgAcqResultDepC);
  suite_add_tcase(s, tc_acq);
  return s;
}