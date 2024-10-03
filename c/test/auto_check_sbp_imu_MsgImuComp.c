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
// spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuComp.yaml by generate.py. Do not
// modify by hand!

#include <check.h>
#include <libsbp/imu.h>
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

START_TEST(test_auto_check_sbp_imu_MsgImuComp) {
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

    sbp_callback_register(&sbp_state, 0x905, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  5, 9,  52, 18,  34,  26,  1,   0,   192, 0,   0,   0,  0,
        206, 0, 96, 0,  0,   0,   223, 255, 255, 255, 44,  16,  0,  0,
        60,  0, 0,  0,  208, 254, 255, 255, 238, 255, 255, 255, 79, 86,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.imu_comp.acc_comp_x = 96;

    test_msg.imu_comp.acc_comp_y = -33;

    test_msg.imu_comp.acc_comp_z = 4140;

    test_msg.imu_comp.flags = 206;

    test_msg.imu_comp.gyr_comp_x = 60;

    test_msg.imu_comp.gyr_comp_y = -304;

    test_msg.imu_comp.gyr_comp_z = -18;

    test_msg.imu_comp.time = 3221225754;

    sbp_message_send(&sbp_state, SbpMsgImuComp, 4660, &test_msg, &dummy_write);

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
    ck_assert_msg(last_msg.sender_id == 4660,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgImuComp, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.imu_comp.acc_comp_x == 96,
                  "incorrect value for last_msg.msg.imu_comp.acc_comp_x, "
                  "expected 96, is %" PRId64,
                  (int64_t)last_msg.msg.imu_comp.acc_comp_x);

    ck_assert_msg(last_msg.msg.imu_comp.acc_comp_y == -33,
                  "incorrect value for last_msg.msg.imu_comp.acc_comp_y, "
                  "expected -33, is %" PRId64,
                  (int64_t)last_msg.msg.imu_comp.acc_comp_y);

    ck_assert_msg(last_msg.msg.imu_comp.acc_comp_z == 4140,
                  "incorrect value for last_msg.msg.imu_comp.acc_comp_z, "
                  "expected 4140, is %" PRId64,
                  (int64_t)last_msg.msg.imu_comp.acc_comp_z);

    ck_assert_msg(last_msg.msg.imu_comp.flags == 206,
                  "incorrect value for last_msg.msg.imu_comp.flags, expected "
                  "206, is %" PRId64,
                  (int64_t)last_msg.msg.imu_comp.flags);

    ck_assert_msg(last_msg.msg.imu_comp.gyr_comp_x == 60,
                  "incorrect value for last_msg.msg.imu_comp.gyr_comp_x, "
                  "expected 60, is %" PRId64,
                  (int64_t)last_msg.msg.imu_comp.gyr_comp_x);

    ck_assert_msg(last_msg.msg.imu_comp.gyr_comp_y == -304,
                  "incorrect value for last_msg.msg.imu_comp.gyr_comp_y, "
                  "expected -304, is %" PRId64,
                  (int64_t)last_msg.msg.imu_comp.gyr_comp_y);

    ck_assert_msg(last_msg.msg.imu_comp.gyr_comp_z == -18,
                  "incorrect value for last_msg.msg.imu_comp.gyr_comp_z, "
                  "expected -18, is %" PRId64,
                  (int64_t)last_msg.msg.imu_comp.gyr_comp_z);

    ck_assert_msg(last_msg.msg.imu_comp.time == 3221225754,
                  "incorrect value for last_msg.msg.imu_comp.time, expected "
                  "3221225754, is %" PRId64,
                  (int64_t)last_msg.msg.imu_comp.time);
  }
}
END_TEST

Suite *auto_check_sbp_imu_MsgImuComp_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_imu_MsgImuComp");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_imu_MsgImuComp");
  tcase_add_test(tc_acq, test_auto_check_sbp_imu_MsgImuComp);
  suite_add_tcase(s, tc_acq);
  return s;
}