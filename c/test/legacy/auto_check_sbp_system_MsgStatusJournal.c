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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusJournal.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/system.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void* context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void* context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void* last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8* buff, u32 n, void* context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8* buff, u32 n, void* context) {
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

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void* context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void* context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_system_MsgStatusJournal) {
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

    sbp_payload_callback_register(&sbp_state, 0xFFFD, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0xFFFD, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 253, 255, 211, 136, 33, 1, 0, 1,  4,   100, 0,   0,   0,
        16, 146, 16,  0,   0,   6,  0, 1, 13, 186, 19,  0,   0,   6,
        0,  1,   14,  184, 34,  0,  0, 6, 0,  1,   15,  113, 119,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_status_journal_t* test_msg = (msg_status_journal_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->journal) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->journal[0]);
    }
    test_msg->journal[0].report.component = 6;
    test_msg->journal[0].report.generic = 1;
    test_msg->journal[0].report.specific = 13;
    test_msg->journal[0].uptime = 4242;
    if (sizeof(test_msg->journal) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->journal[0]);
    }
    test_msg->journal[1].report.component = 6;
    test_msg->journal[1].report.generic = 1;
    test_msg->journal[1].report.specific = 14;
    test_msg->journal[1].uptime = 5050;
    if (sizeof(test_msg->journal) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->journal[0]);
    }
    test_msg->journal[2].report.component = 6;
    test_msg->journal[2].report.generic = 1;
    test_msg->journal[2].report.specific = 15;
    test_msg->journal[2].uptime = 8888;
    test_msg->reporting_system = 1;
    test_msg->sbp_version = 1025;
    test_msg->sequence_descriptor = 16;
    test_msg->total_status_reports = 100;
    sbp_payload_send(&sbp_state, 0xFFFD, 35027, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 35027,
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
    ck_assert_msg(last_frame.sender_id == 35027,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xFFFD,
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
    msg_status_journal_t* check_msg =
        (msg_status_journal_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        check_msg->journal[0].report.component == 6,
        "incorrect value for journal[0].report.component, expected 6, is %d",
        check_msg->journal[0].report.component);
    ck_assert_msg(
        check_msg->journal[0].report.generic == 1,
        "incorrect value for journal[0].report.generic, expected 1, is %d",
        check_msg->journal[0].report.generic);
    ck_assert_msg(
        check_msg->journal[0].report.specific == 13,
        "incorrect value for journal[0].report.specific, expected 13, is %d",
        check_msg->journal[0].report.specific);
    ck_assert_msg(check_msg->journal[0].uptime == 4242,
                  "incorrect value for journal[0].uptime, expected 4242, is %d",
                  check_msg->journal[0].uptime);
    ck_assert_msg(
        check_msg->journal[1].report.component == 6,
        "incorrect value for journal[1].report.component, expected 6, is %d",
        check_msg->journal[1].report.component);
    ck_assert_msg(
        check_msg->journal[1].report.generic == 1,
        "incorrect value for journal[1].report.generic, expected 1, is %d",
        check_msg->journal[1].report.generic);
    ck_assert_msg(
        check_msg->journal[1].report.specific == 14,
        "incorrect value for journal[1].report.specific, expected 14, is %d",
        check_msg->journal[1].report.specific);
    ck_assert_msg(check_msg->journal[1].uptime == 5050,
                  "incorrect value for journal[1].uptime, expected 5050, is %d",
                  check_msg->journal[1].uptime);
    ck_assert_msg(
        check_msg->journal[2].report.component == 6,
        "incorrect value for journal[2].report.component, expected 6, is %d",
        check_msg->journal[2].report.component);
    ck_assert_msg(
        check_msg->journal[2].report.generic == 1,
        "incorrect value for journal[2].report.generic, expected 1, is %d",
        check_msg->journal[2].report.generic);
    ck_assert_msg(
        check_msg->journal[2].report.specific == 15,
        "incorrect value for journal[2].report.specific, expected 15, is %d",
        check_msg->journal[2].report.specific);
    ck_assert_msg(check_msg->journal[2].uptime == 8888,
                  "incorrect value for journal[2].uptime, expected 8888, is %d",
                  check_msg->journal[2].uptime);
    ck_assert_msg(check_msg->reporting_system == 1,
                  "incorrect value for reporting_system, expected 1, is %d",
                  check_msg->reporting_system);
    ck_assert_msg(check_msg->sbp_version == 1025,
                  "incorrect value for sbp_version, expected 1025, is %d",
                  check_msg->sbp_version);
    ck_assert_msg(check_msg->sequence_descriptor == 16,
                  "incorrect value for sequence_descriptor, expected 16, is %d",
                  check_msg->sequence_descriptor);
    ck_assert_msg(
        check_msg->total_status_reports == 100,
        "incorrect value for total_status_reports, expected 100, is %d",
        check_msg->total_status_reports);
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

    sbp_payload_callback_register(&sbp_state, 0xFFFD, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0xFFFD, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 253, 255, 211, 136, 17, 1, 0, 1, 4,  100, 0,   0,
        0,  16,  146, 16,  0,   0,  6, 0, 1, 13, 144, 121,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_status_journal_t* test_msg = (msg_status_journal_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->journal) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->journal[0]);
    }
    test_msg->journal[0].report.component = 6;
    test_msg->journal[0].report.generic = 1;
    test_msg->journal[0].report.specific = 13;
    test_msg->journal[0].uptime = 4242;
    test_msg->reporting_system = 1;
    test_msg->sbp_version = 1025;
    test_msg->sequence_descriptor = 16;
    test_msg->total_status_reports = 100;
    sbp_payload_send(&sbp_state, 0xFFFD, 35027, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 35027,
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
    ck_assert_msg(last_frame.sender_id == 35027,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xFFFD,
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
    msg_status_journal_t* check_msg =
        (msg_status_journal_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        check_msg->journal[0].report.component == 6,
        "incorrect value for journal[0].report.component, expected 6, is %d",
        check_msg->journal[0].report.component);
    ck_assert_msg(
        check_msg->journal[0].report.generic == 1,
        "incorrect value for journal[0].report.generic, expected 1, is %d",
        check_msg->journal[0].report.generic);
    ck_assert_msg(
        check_msg->journal[0].report.specific == 13,
        "incorrect value for journal[0].report.specific, expected 13, is %d",
        check_msg->journal[0].report.specific);
    ck_assert_msg(check_msg->journal[0].uptime == 4242,
                  "incorrect value for journal[0].uptime, expected 4242, is %d",
                  check_msg->journal[0].uptime);
    ck_assert_msg(check_msg->reporting_system == 1,
                  "incorrect value for reporting_system, expected 1, is %d",
                  check_msg->reporting_system);
    ck_assert_msg(check_msg->sbp_version == 1025,
                  "incorrect value for sbp_version, expected 1025, is %d",
                  check_msg->sbp_version);
    ck_assert_msg(check_msg->sequence_descriptor == 16,
                  "incorrect value for sequence_descriptor, expected 16, is %d",
                  check_msg->sequence_descriptor);
    ck_assert_msg(
        check_msg->total_status_reports == 100,
        "incorrect value for total_status_reports, expected 100, is %d",
        check_msg->total_status_reports);
  }
}
END_TEST

Suite* legacy_auto_check_sbp_system_MsgStatusJournal_suite(void) {
  Suite* s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_system_MsgStatusJournal");
  TCase* tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_system_MsgStatusJournal");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_system_MsgStatusJournal);
  suite_add_tcase(s, tc_acq);
  return s;
}