/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/ndb/test_MsgNdbEvent.yaml by generate.py. Do not
// modify by hand!

#include <check.h>
#include <libsbp/ndb.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static size_t dummy_wr = 0;
static size_t dummy_rd = 0;
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
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
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

START_TEST(test_auto_check_sbp_ndb_MsgNdbEvent) {
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

    sbp_callback_register(&sbp_state, 0x400, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,   4,  164, 174, 18,  254, 188, 70, 185, 69,  0,  0,
        0,  249, 73, 205, 115, 238, 74,  98,  66, 182, 148, 16, 166,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ndb_event.data_source = 115;

    test_msg.ndb_event.event = 249;

    test_msg.ndb_event.object_sid.code = 74;

    test_msg.ndb_event.object_sid.sat = 238;

    test_msg.ndb_event.object_type = 73;

    test_msg.ndb_event.original_sender = 38070;

    test_msg.ndb_event.recv_time = 299461164286;

    test_msg.ndb_event.result = 205;

    test_msg.ndb_event.src_sid.code = 66;

    test_msg.ndb_event.src_sid.sat = 98;

    sbp_message_send(&sbp_state, SbpMsgNdbEvent, 44708, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 44708,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgNdbEvent, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.ndb_event.data_source == 115,
                  "incorrect value for last_msg.msg.ndb_event.data_source, "
                  "expected 115, is %" PRId64,
                  (int64_t)last_msg.msg.ndb_event.data_source);

    ck_assert_msg(last_msg.msg.ndb_event.event == 249,
                  "incorrect value for last_msg.msg.ndb_event.event, expected "
                  "249, is %" PRId64,
                  (int64_t)last_msg.msg.ndb_event.event);

    ck_assert_msg(last_msg.msg.ndb_event.object_sid.code == 74,
                  "incorrect value for last_msg.msg.ndb_event.object_sid.code, "
                  "expected 74, is %" PRId64,
                  (int64_t)last_msg.msg.ndb_event.object_sid.code);

    ck_assert_msg(last_msg.msg.ndb_event.object_sid.sat == 238,
                  "incorrect value for last_msg.msg.ndb_event.object_sid.sat, "
                  "expected 238, is %" PRId64,
                  (int64_t)last_msg.msg.ndb_event.object_sid.sat);

    ck_assert_msg(last_msg.msg.ndb_event.object_type == 73,
                  "incorrect value for last_msg.msg.ndb_event.object_type, "
                  "expected 73, is %" PRId64,
                  (int64_t)last_msg.msg.ndb_event.object_type);

    ck_assert_msg(last_msg.msg.ndb_event.original_sender == 38070,
                  "incorrect value for last_msg.msg.ndb_event.original_sender, "
                  "expected 38070, is %" PRId64,
                  (int64_t)last_msg.msg.ndb_event.original_sender);

    ck_assert_msg(last_msg.msg.ndb_event.recv_time == 299461164286,
                  "incorrect value for last_msg.msg.ndb_event.recv_time, "
                  "expected 299461164286, is %" PRId64,
                  (int64_t)last_msg.msg.ndb_event.recv_time);

    ck_assert_msg(last_msg.msg.ndb_event.result == 205,
                  "incorrect value for last_msg.msg.ndb_event.result, expected "
                  "205, is %" PRId64,
                  (int64_t)last_msg.msg.ndb_event.result);

    ck_assert_msg(last_msg.msg.ndb_event.src_sid.code == 66,
                  "incorrect value for last_msg.msg.ndb_event.src_sid.code, "
                  "expected 66, is %" PRId64,
                  (int64_t)last_msg.msg.ndb_event.src_sid.code);

    ck_assert_msg(last_msg.msg.ndb_event.src_sid.sat == 98,
                  "incorrect value for last_msg.msg.ndb_event.src_sid.sat, "
                  "expected 98, is %" PRId64,
                  (int64_t)last_msg.msg.ndb_event.src_sid.sat);
  }
}
END_TEST

Suite *auto_check_sbp_ndb_MsgNdbEvent_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_ndb_MsgNdbEvent");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_ndb_MsgNdbEvent");
  tcase_add_test(tc_acq, test_auto_check_sbp_ndb_MsgNdbEvent);
  suite_add_tcase(s, tc_acq);
  return s;
}
