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
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagHighLevel.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/integrity.h>
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

START_TEST(test_auto_check_sbp_integrity_MsgSsrFlagHighLevel) {
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

    sbp_callback_register(&sbp_state, 3001, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 185, 11, 66, 0, 31, 180, 0, 0,  0, 3,  0,   104,
        1,  0,   0,  6,  0, 10, 20,  0, 30, 0, 40, 1,   2,
        3,  0,   0,  0,  0, 0,  0,   4, 5,  6, 7,  102, 67,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_flag_high_level.chain_id = 40;

    test_msg.ssr_flag_high_level.corr_time.tow = 360;

    test_msg.ssr_flag_high_level.corr_time.wn = 6;

    test_msg.ssr_flag_high_level.obs_time.tow = 180;

    test_msg.ssr_flag_high_level.obs_time.wn = 3;

    test_msg.ssr_flag_high_level.reserved[0] = 0;

    test_msg.ssr_flag_high_level.reserved[1] = 0;

    test_msg.ssr_flag_high_level.reserved[2] = 0;

    test_msg.ssr_flag_high_level.reserved[3] = 0;

    test_msg.ssr_flag_high_level.reserved[4] = 0;

    test_msg.ssr_flag_high_level.reserved[5] = 0;

    test_msg.ssr_flag_high_level.ssr_sol_id = 10;

    test_msg.ssr_flag_high_level.tile_id = 30;

    test_msg.ssr_flag_high_level.tile_set_id = 20;

    test_msg.ssr_flag_high_level.use_bds_sat = 3;

    test_msg.ssr_flag_high_level.use_gal_sat = 2;

    test_msg.ssr_flag_high_level.use_gps_sat = 1;

    test_msg.ssr_flag_high_level.use_iono_grid_point_sat_los = 7;

    test_msg.ssr_flag_high_level.use_iono_grid_points = 5;

    test_msg.ssr_flag_high_level.use_iono_tile_sat_los = 6;

    test_msg.ssr_flag_high_level.use_tropo_grid_points = 4;

    sbp_message_send(&sbp_state, SbpMsgSsrFlagHighLevel, 66, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 66,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgSsrFlagHighLevel, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.chain_id == 40,
        "incorrect value for last_msg.msg.ssr_flag_high_level.chain_id, "
        "expected 40, is %d",
        last_msg.msg.ssr_flag_high_level.chain_id);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.corr_time.tow == 360,
        "incorrect value for last_msg.msg.ssr_flag_high_level.corr_time.tow, "
        "expected 360, is %d",
        last_msg.msg.ssr_flag_high_level.corr_time.tow);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.corr_time.wn == 6,
        "incorrect value for last_msg.msg.ssr_flag_high_level.corr_time.wn, "
        "expected 6, is %d",
        last_msg.msg.ssr_flag_high_level.corr_time.wn);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.obs_time.tow == 180,
        "incorrect value for last_msg.msg.ssr_flag_high_level.obs_time.tow, "
        "expected 180, is %d",
        last_msg.msg.ssr_flag_high_level.obs_time.tow);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.obs_time.wn == 3,
        "incorrect value for last_msg.msg.ssr_flag_high_level.obs_time.wn, "
        "expected 3, is %d",
        last_msg.msg.ssr_flag_high_level.obs_time.wn);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.reserved[0] == 0,
        "incorrect value for last_msg.msg.ssr_flag_high_level.reserved[0], "
        "expected 0, is %d",
        last_msg.msg.ssr_flag_high_level.reserved[0]);
    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.reserved[1] == 0,
        "incorrect value for last_msg.msg.ssr_flag_high_level.reserved[1], "
        "expected 0, is %d",
        last_msg.msg.ssr_flag_high_level.reserved[1]);
    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.reserved[2] == 0,
        "incorrect value for last_msg.msg.ssr_flag_high_level.reserved[2], "
        "expected 0, is %d",
        last_msg.msg.ssr_flag_high_level.reserved[2]);
    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.reserved[3] == 0,
        "incorrect value for last_msg.msg.ssr_flag_high_level.reserved[3], "
        "expected 0, is %d",
        last_msg.msg.ssr_flag_high_level.reserved[3]);
    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.reserved[4] == 0,
        "incorrect value for last_msg.msg.ssr_flag_high_level.reserved[4], "
        "expected 0, is %d",
        last_msg.msg.ssr_flag_high_level.reserved[4]);
    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.reserved[5] == 0,
        "incorrect value for last_msg.msg.ssr_flag_high_level.reserved[5], "
        "expected 0, is %d",
        last_msg.msg.ssr_flag_high_level.reserved[5]);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.ssr_sol_id == 10,
        "incorrect value for last_msg.msg.ssr_flag_high_level.ssr_sol_id, "
        "expected 10, is %d",
        last_msg.msg.ssr_flag_high_level.ssr_sol_id);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.tile_id == 30,
        "incorrect value for last_msg.msg.ssr_flag_high_level.tile_id, "
        "expected 30, is %d",
        last_msg.msg.ssr_flag_high_level.tile_id);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.tile_set_id == 20,
        "incorrect value for last_msg.msg.ssr_flag_high_level.tile_set_id, "
        "expected 20, is %d",
        last_msg.msg.ssr_flag_high_level.tile_set_id);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.use_bds_sat == 3,
        "incorrect value for last_msg.msg.ssr_flag_high_level.use_bds_sat, "
        "expected 3, is %d",
        last_msg.msg.ssr_flag_high_level.use_bds_sat);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.use_gal_sat == 2,
        "incorrect value for last_msg.msg.ssr_flag_high_level.use_gal_sat, "
        "expected 2, is %d",
        last_msg.msg.ssr_flag_high_level.use_gal_sat);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.use_gps_sat == 1,
        "incorrect value for last_msg.msg.ssr_flag_high_level.use_gps_sat, "
        "expected 1, is %d",
        last_msg.msg.ssr_flag_high_level.use_gps_sat);

    ck_assert_msg(
        last_msg.msg.ssr_flag_high_level.use_iono_grid_point_sat_los == 7,
        "incorrect value for "
        "last_msg.msg.ssr_flag_high_level.use_iono_grid_point_sat_los, "
        "expected 7, is %d",
        last_msg.msg.ssr_flag_high_level.use_iono_grid_point_sat_los);

    ck_assert_msg(last_msg.msg.ssr_flag_high_level.use_iono_grid_points == 5,
                  "incorrect value for "
                  "last_msg.msg.ssr_flag_high_level.use_iono_grid_points, "
                  "expected 5, is %d",
                  last_msg.msg.ssr_flag_high_level.use_iono_grid_points);

    ck_assert_msg(last_msg.msg.ssr_flag_high_level.use_iono_tile_sat_los == 6,
                  "incorrect value for "
                  "last_msg.msg.ssr_flag_high_level.use_iono_tile_sat_los, "
                  "expected 6, is %d",
                  last_msg.msg.ssr_flag_high_level.use_iono_tile_sat_los);

    ck_assert_msg(last_msg.msg.ssr_flag_high_level.use_tropo_grid_points == 4,
                  "incorrect value for "
                  "last_msg.msg.ssr_flag_high_level.use_tropo_grid_points, "
                  "expected 4, is %d",
                  last_msg.msg.ssr_flag_high_level.use_tropo_grid_points);
  }
}
END_TEST

Suite *auto_check_sbp_integrity_MsgSsrFlagHighLevel_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_integrity_MsgSsrFlagHighLevel");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_integrity_MsgSsrFlagHighLevel");
  tcase_add_test(tc_acq, test_auto_check_sbp_integrity_MsgSsrFlagHighLevel);
  suite_add_tcase(s, tc_acq);
  return s;
}