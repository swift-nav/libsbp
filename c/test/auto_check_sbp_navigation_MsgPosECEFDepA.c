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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFDepA.yaml by
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

START_TEST(test_auto_check_sbp_navigation_MsgPosECEFDepA) {
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,   2,   246, 215, 32, 20,  46,  39,  0,  195, 122, 175, 75,
        33, 154, 68,  193, 164, 14, 230, 176, 231, 95, 80,  193, 78,  220,
        22, 253, 254, 105, 77,  65, 0,   0,   9,   0,  13,  86,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 0;

    test_msg.pos_ecef_dep_a.n_sats = 9;

    test_msg.pos_ecef_dep_a.tow = 2567700;

    test_msg.pos_ecef_dep_a.x = -2700354.5912927105;

    test_msg.pos_ecef_dep_a.y = -4292510.764041577;

    test_msg.pos_ecef_dep_a.z = 3855357.977260149;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 2567700,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 2567700, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2700354.59129 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2700354.59129, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4292510.76404 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4292510.76404, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3855357.97726 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3855357.97726, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,   2,   246, 215, 32,  20,  46,  39,  0,  212, 196, 12, 42,
        34, 154, 68,  193, 9,   113, 112, 123, 231, 95, 80,  193, 54, 97,
        38, 192, 254, 105, 77,  65,  0,   0,   9,   1,  75,  143,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 1;

    test_msg.pos_ecef_dep_a.n_sats = 9;

    test_msg.pos_ecef_dep_a.tow = 2567700;

    test_msg.pos_ecef_dep_a.x = -2700356.3285146747;

    test_msg.pos_ecef_dep_a.y = -4292509.928737887;

    test_msg.pos_ecef_dep_a.z = 3855357.5011712564;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 1,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 1, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 2567700,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 2567700, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2700356.32851 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2700356.32851, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4292509.92874 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4292509.92874, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3855357.50117 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3855357.50117, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,   2,   246, 215, 32, 120, 46,  39,  0,  112, 97,  39, 190,
        34, 154, 68,  193, 230, 43, 119, 115, 231, 95, 80,  193, 50, 199,
        76, 66,  254, 105, 77,  65, 0,   0,   9,   0,  204, 113,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 0;

    test_msg.pos_ecef_dep_a.n_sats = 9;

    test_msg.pos_ecef_dep_a.tow = 2567800;

    test_msg.pos_ecef_dep_a.x = -2700357.485576801;

    test_msg.pos_ecef_dep_a.y = -4292509.80414865;

    test_msg.pos_ecef_dep_a.z = 3855356.517968082;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 2567800,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 2567800, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2700357.48558 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2700357.48558, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4292509.80415 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4292509.80415, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3855356.51797 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3855356.51797, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  0,   2,   246, 215, 32,  120, 46,  39,  0,  194, 82,  121, 4,
        34,  154, 68,  193, 223, 186, 1,   140, 231, 95, 80,  193, 176, 152,
        147, 181, 254, 105, 77,  65,  0,   0,   9,   1,  97,  71,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 1;

    test_msg.pos_ecef_dep_a.n_sats = 9;

    test_msg.pos_ecef_dep_a.tow = 2567800;

    test_msg.pos_ecef_dep_a.x = -2700356.0349524925;

    test_msg.pos_ecef_dep_a.y = -4292510.187605589;

    test_msg.pos_ecef_dep_a.z = 3855357.4185667858;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 1,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 1, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 2567800,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 2567800, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2700356.03495 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2700356.03495, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4292510.18761 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4292510.18761, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3855357.41857 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3855357.41857, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  0,   2,   246, 215, 32,  220, 46,  39,  0,  216, 41,  227, 254,
        33,  154, 68,  193, 9,   151, 154, 124, 231, 95, 80,  193, 1,   183,
        214, 139, 255, 105, 77,  65,  0,   0,   9,   0,  7,   98,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 0;

    test_msg.pos_ecef_dep_a.n_sats = 9;

    test_msg.pos_ecef_dep_a.tow = 2567900;

    test_msg.pos_ecef_dep_a.x = -2700355.9913074784;

    test_msg.pos_ecef_dep_a.y = -4292509.946935424;

    test_msg.pos_ecef_dep_a.z = 3855359.0924900775;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 2567900,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 2567900, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2700355.99131 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2700355.99131, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4292509.94694 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4292509.94694, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3855359.09249 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3855359.09249, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,   32,  212, 157, 67, 24, 153, 222, 105, 1,
        252, 161, 68, 193, 254, 247, 52,  112, 74, 67, 80,  193, 164, 207,
        47,  146, 44, 163, 77,  65,  0,   0,   8,  0,  145, 4,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 0;

    test_msg.pos_ecef_dep_a.n_sats = 8;

    test_msg.pos_ecef_dep_a.tow = 407084500;

    test_msg.pos_ecef_dep_a.x = -2704376.0110433814;

    test_msg.pos_ecef_dep_a.y = -4263209.753232954;

    test_msg.pos_ecef_dep_a.z = 3884633.142084079;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 407084500,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 407084500, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2704376.01104 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2704376.01104, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4263209.75323 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4263209.75323, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3884633.14208 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3884633.14208, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,  32,  56, 158, 67, 24, 215, 184, 223, 246,
        251, 161, 68, 193, 36, 126, 17, 39,  74, 67, 80,  193, 19,  179,
        70,  80,  44, 163, 77, 65,  0,  0,   8,  0,  245, 66,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 0;

    test_msg.pos_ecef_dep_a.n_sats = 8;

    test_msg.pos_ecef_dep_a.tow = 407084600;

    test_msg.pos_ecef_dep_a.x = -2704375.9287024545;

    test_msg.pos_ecef_dep_a.y = -4263208.610442672;

    test_msg.pos_ecef_dep_a.z = 3884632.627157578;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 407084600,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 407084600, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2704375.9287 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2704375.9287, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4263208.61044 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4263208.61044, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3884632.62716 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3884632.62716, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,   32,  156, 158, 67, 24, 73, 74,  214, 148,
        251, 161, 68, 193, 213, 151, 184, 215, 73, 67, 80, 193, 110, 99,
        38,  164, 43, 163, 77,  65,  0,   0,   8,  0,  5,  223,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 0;

    test_msg.pos_ecef_dep_a.n_sats = 8;

    test_msg.pos_ecef_dep_a.tow = 407084700;

    test_msg.pos_ecef_dep_a.x = -2704375.162789617;

    test_msg.pos_ecef_dep_a.y = -4263207.370641668;

    test_msg.pos_ecef_dep_a.z = 3884631.282421521;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 407084700,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 407084700, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2704375.16279 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2704375.16279, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4263207.37064 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4263207.37064, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3884631.28242 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3884631.28242, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,   32,  0,   159, 67, 24, 177, 111, 112, 45,
        252, 161, 68, 193, 213, 168, 198, 253, 73, 67, 80,  193, 245, 12,
        228, 12,  44, 163, 77,  65,  0,   0,   8,  0,  143, 212,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 0;

    test_msg.pos_ecef_dep_a.n_sats = 8;

    test_msg.pos_ecef_dep_a.tow = 407084800;

    test_msg.pos_ecef_dep_a.x = -2704376.3549937834;

    test_msg.pos_ecef_dep_a.y = -4263207.965250214;

    test_msg.pos_ecef_dep_a.z = 3884632.1007095524;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 407084800,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 407084800, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2704376.35499 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2704376.35499, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4263207.96525 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4263207.96525, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3884632.10071 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3884632.10071, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,   32,  100, 159, 67, 24, 67, 231, 72,  165,
        251, 161, 68, 193, 150, 210, 36,  212, 73, 67, 80, 193, 234, 33,
        25,  189, 43, 163, 77,  65,  0,   0,   8,  0,  70, 221,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 0;

    test_msg.pos_ecef_dep_a.n_sats = 8;

    test_msg.pos_ecef_dep_a.tow = 407084900;

    test_msg.pos_ecef_dep_a.x = -2704375.291287334;

    test_msg.pos_ecef_dep_a.y = -4263207.314747473;

    test_msg.pos_ecef_dep_a.z = 3884631.4773294823;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 407084900,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 407084900, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2704375.29129 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2704375.29129, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4263207.31475 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4263207.31475, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3884631.47733 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3884631.47733, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
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

    sbp_callback_register(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,   32,  46,  162, 68, 24, 224, 72,  131, 215,
        251, 161, 68, 193, 180, 123, 222, 94,  74, 67, 80,  193, 191, 3,
        131, 193, 45, 163, 77,  65,  0,   0,   5,  0,  17,  221,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_dep_a.accuracy = 0;

    test_msg.pos_ecef_dep_a.flags = 0;

    test_msg.pos_ecef_dep_a.n_sats = 5;

    test_msg.pos_ecef_dep_a.tow = 407151150;

    test_msg.pos_ecef_dep_a.x = -2704375.68369399;

    test_msg.pos_ecef_dep_a.y = -4263209.482329298;

    test_msg.pos_ecef_dep_a.z = 3884635.5118107493;

    sbp_message_send(&sbp_state, SbpMsgPosEcefDepA, 1219, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 1219,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgPosEcefDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.accuracy == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.accuracy);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_ecef_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.n_sats == 5,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.n_sats, "
                  "expected 5, is %d",
                  last_msg.msg.pos_ecef_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_ecef_dep_a.tow == 407151150,
                  "incorrect value for last_msg.msg.pos_ecef_dep_a.tow, "
                  "expected 407151150, is %d",
                  last_msg.msg.pos_ecef_dep_a.tow);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.x * 100 - -2704375.68369 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.x, expected "
        "-2704375.68369, is %s",
        last_msg.msg.pos_ecef_dep_a.x);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.y * 100 - -4263209.48233 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.y, expected "
        "-4263209.48233, is %s",
        last_msg.msg.pos_ecef_dep_a.y);

    ck_assert_msg(
        (last_msg.msg.pos_ecef_dep_a.z * 100 - 3884635.51181 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_ecef_dep_a.z, expected "
        "3884635.51181, is %s",
        last_msg.msg.pos_ecef_dep_a.z);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgPosECEFDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgPosECEFDepA");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgPosECEFDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgPosECEFDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}