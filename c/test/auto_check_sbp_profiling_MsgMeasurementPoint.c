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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgMeasurementPoint.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/profiling.h>
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

START_TEST(test_auto_check_sbp_profiling_MsgMeasurementPoint) {
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

    sbp_callback_register(&sbp_state, 0xCF00, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,   207, 0,   16,  48,  250, 7,   0,   0,   180, 0,  2,   0,
        0,  0,   40,  0,   0,   0,   130, 201, 148, 141, 97,  85, 0,   0,
        18, 130, 201, 148, 0,   0,   0,   0,   66,  64,  157, 15, 0,   0,
        0,  0,   18,  0,   114, 111, 117, 116, 101, 40,  41,  0,  212, 165,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    ck_assert_msg(sbp_msg_measurement_point_func_set(
                      &test_msg.measurement_point, "route()", false, &written),
                  "Can't assign text");
    ck_assert_msg(written == strlen("route()"), "Wrote different to expected");
    ck_assert_msg(sbp_msg_measurement_point_func_encoded_len(
                      &test_msg.measurement_point) == 8,
                  "String not encoded properly");

    test_msg.measurement_point.id = 2496234002;

    test_msg.measurement_point.line = 18;

    test_msg.measurement_point.max = 40;

    test_msg.measurement_point.min = 2;

    test_msg.measurement_point.num_executions = 180;

    test_msg.measurement_point.return_addr = 93877475527042;

    test_msg.measurement_point.slice_time = 261963842;

    test_msg.measurement_point.total_time = 2042;

    sbp_message_send(&sbp_state, SbpMsgMeasurementPoint, 4096, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 4096,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgMeasurementPoint, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(sbp_msg_measurement_point_func_encoded_len(
                      &last_msg.msg.measurement_point) == 8,
                  "Invalid encoded len");
    ck_assert_msg(strcmp(sbp_msg_measurement_point_func_get(
                             &last_msg.msg.measurement_point),
                         "route()") == 0,
                  "String not decoded properly");

    ck_assert_msg(last_msg.msg.measurement_point.id == 2496234002,
                  "incorrect value for last_msg.msg.measurement_point.id, "
                  "expected 2496234002, is %" PRId64,
                  (int64_t)last_msg.msg.measurement_point.id);

    ck_assert_msg(last_msg.msg.measurement_point.line == 18,
                  "incorrect value for last_msg.msg.measurement_point.line, "
                  "expected 18, is %" PRId64,
                  (int64_t)last_msg.msg.measurement_point.line);

    ck_assert_msg(last_msg.msg.measurement_point.max == 40,
                  "incorrect value for last_msg.msg.measurement_point.max, "
                  "expected 40, is %" PRId64,
                  (int64_t)last_msg.msg.measurement_point.max);

    ck_assert_msg(last_msg.msg.measurement_point.min == 2,
                  "incorrect value for last_msg.msg.measurement_point.min, "
                  "expected 2, is %" PRId64,
                  (int64_t)last_msg.msg.measurement_point.min);

    ck_assert_msg(
        last_msg.msg.measurement_point.num_executions == 180,
        "incorrect value for last_msg.msg.measurement_point.num_executions, "
        "expected 180, is %" PRId64,
        (int64_t)last_msg.msg.measurement_point.num_executions);

    ck_assert_msg(
        last_msg.msg.measurement_point.return_addr == 93877475527042,
        "incorrect value for last_msg.msg.measurement_point.return_addr, "
        "expected 93877475527042, is %" PRId64,
        (int64_t)last_msg.msg.measurement_point.return_addr);

    ck_assert_msg(
        last_msg.msg.measurement_point.slice_time == 261963842,
        "incorrect value for last_msg.msg.measurement_point.slice_time, "
        "expected 261963842, is %" PRId64,
        (int64_t)last_msg.msg.measurement_point.slice_time);

    ck_assert_msg(
        last_msg.msg.measurement_point.total_time == 2042,
        "incorrect value for last_msg.msg.measurement_point.total_time, "
        "expected 2042, is %" PRId64,
        (int64_t)last_msg.msg.measurement_point.total_time);
  }
}
END_TEST

Suite *auto_check_sbp_profiling_MsgMeasurementPoint_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_profiling_MsgMeasurementPoint");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_profiling_MsgMeasurementPoint");
  tcase_add_test(tc_acq, test_auto_check_sbp_profiling_MsgMeasurementPoint);
  suite_add_tcase(s, tc_acq);
  return s;
}
