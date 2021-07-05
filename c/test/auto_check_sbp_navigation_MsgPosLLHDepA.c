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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHDepA.yaml by
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

START_TEST(test_auto_check_sbp_navigation_MsgPosLLHDepA) {
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,   246, 215, 34,  20, 46,  39, 0,   250, 29,  226, 186,
        235, 182, 66,  64,  19,  203, 51, 196, 24, 139, 94,  192, 31,  157,
        160, 232, 122, 115, 81,  64,  0,  0,   0,  0,   9,   0,   236, 139,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 0;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 69.80437675175607;

    test_msg.pos_llh_dep_a.lat = 37.42906890908121;

    test_msg.pos_llh_dep_a.lon = -122.17338662202773;

    test_msg.pos_llh_dep_a.n_sats = 9;

    test_msg.pos_llh_dep_a.tow = 2567700;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 55286, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 69.8043767518 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "69.8043767518, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.4290689091 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.4290689091, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.173386622 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.173386622, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 2567700,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 2567700, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,  246, 215, 34, 20,  46, 39, 0,   161, 51,  75,  148,
        235, 182, 66, 64,  36,  41, 246, 30, 25, 139, 94,  192, 254, 218,
        49,  127, 10, 108, 81,  64, 0,   0,  0,  0,   9,   1,   25,  117,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 1;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 69.68814067715354;

    test_msg.pos_llh_dep_a.lat = 37.42906430885274;

    test_msg.pos_llh_dep_a.lon = -122.17340826071865;

    test_msg.pos_llh_dep_a.n_sats = 9;

    test_msg.pos_llh_dep_a.tow = 2567700;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 55286, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 1,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 1, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 69.6881406772 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "69.6881406772, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.4290643089 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.4290643089, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.173408261 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.173408261, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 2567700,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 2567700, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,   246, 215, 34, 120, 46, 39, 0,   56, 214, 210, 65,
        235, 182, 66,  64,  13,  46, 132, 80, 25, 139, 94, 192, 22,  143,
        46,  234, 191, 95,  81,  64, 0,   0,  0,  0,   9,  0,   174, 105,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 0;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 69.49608854815264;

    test_msg.pos_llh_dep_a.lat = 37.42905447764173;

    test_msg.pos_llh_dep_a.lon = -122.17342007549469;

    test_msg.pos_llh_dep_a.n_sats = 9;

    test_msg.pos_llh_dep_a.tow = 2567800;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 55286, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 69.4960885482 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "69.4960885482, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.4290544776 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.4290544776, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.173420075 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.173420075, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 2567800,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 2567800, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,  246, 215, 34,  120, 46, 39, 0,   251, 117, 115, 140,
        235, 182, 66, 64,  152, 134, 167, 12, 25, 139, 94,  192, 160, 22,
        137, 253, 4,  108, 81,  64,  0,   0,  0,  0,   9,   1,   122, 127,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 1;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 69.68780458819901;

    test_msg.pos_llh_dep_a.lat = 37.429063373925565;

    test_msg.pos_llh_dep_a.lon = -122.17340389594972;

    test_msg.pos_llh_dep_a.n_sats = 9;

    test_msg.pos_llh_dep_a.tow = 2567800;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 55286, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 1,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 1, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 69.6878045882 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "69.6878045882, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.4290633739 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.4290633739, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.173403896 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.173403896, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 2567800,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 2567800, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,   246, 215, 34, 220, 46, 39, 0,   51, 124, 88,  251,
        235, 182, 66,  64,  153, 5,  250, 16, 25, 139, 94, 192, 146, 60,
        187, 219, 152, 161, 81,  64, 0,   0,  0,  0,   9,  0,   194, 158,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 0;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 70.5249547317965;

    test_msg.pos_llh_dep_a.lat = 37.42907659359516;

    test_msg.pos_llh_dep_a.lon = -122.17340492645452;

    test_msg.pos_llh_dep_a.n_sats = 9;

    test_msg.pos_llh_dep_a.tow = 2567900;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 55286, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 70.5249547318 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "70.5249547318, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.4290765936 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.4290765936, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.173404926 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.173404926, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 9,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 9, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 2567900,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 2567900, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,   195, 4,   34,  212, 157, 67,  24,  8,  23,  228, 8,
        151, 225, 66,  64,  156, 174, 42,  194, 230, 152, 94, 192, 153, 23,
        72,  47,  196, 40,  16,  64,  0,   0,   0,   0,   8,  0,   237, 169,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 0;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 4.039810885214956;

    test_msg.pos_llh_dep_a.lat = 37.76242171418386;

    test_msg.pos_llh_dep_a.lon = -122.38908437889262;

    test_msg.pos_llh_dep_a.n_sats = 8;

    test_msg.pos_llh_dep_a.tow = 407084500;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 4.03981088521 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "4.03981088521, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.7624217142 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.7624217142, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.389084379 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.389084379, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 407084500,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 407084500, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,   195, 4,   34,  56,  158, 67,  24,  220, 109, 212, 24,
        151, 225, 66,  64,  159, 231, 254, 219, 230, 152, 94,  192, 128, 151,
        67,  19,  233, 105, 7,   64,  0,   0,   0,   0,   8,   0,   152, 11,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 0;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 2.926714087009657;

    test_msg.pos_llh_dep_a.lat = 37.76242361423985;

    test_msg.pos_llh_dep_a.lon = -122.38909053700489;

    test_msg.pos_llh_dep_a.n_sats = 8;

    test_msg.pos_llh_dep_a.tow = 407084600;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 2.92671408701 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "2.92671408701, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.7624236142 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.7624236142, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.389090537 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.389090537, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 407084600,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 407084600, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,  195, 4,   34,  156, 158, 67,  24,  13, 91,  237, 11,
        151, 225, 66, 64,  75,  113, 210, 220, 230, 152, 94, 192, 37,  6,
        145, 188, 89, 112, 238, 63,  0,   0,   0,   0,   8,  0,   221, 155,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 0;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 0.9512146647395566;

    test_msg.pos_llh_dep_a.lat = 37.762422076126406;

    test_msg.pos_llh_dep_a.lon = -122.3890907340148;

    test_msg.pos_llh_dep_a.n_sats = 8;

    test_msg.pos_llh_dep_a.tow = 407084700;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 0.95121466474 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "0.95121466474, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.7624220761 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.7624220761, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.389090734 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.389090734, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 407084700,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 407084700, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,  195, 4,  34,  0,   159, 67,  24,  51, 183, 5,   8,
        151, 225, 66, 64,  13, 226, 148, 253, 230, 152, 94, 192, 187, 27,
        11,  32,  69, 213, 2,  64,  0,   0,   0,   0,   8,  0,   82,  94,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 0;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 2.354135752047538;

    test_msg.pos_llh_dep_a.lat = 37.762421610632735;

    test_msg.pos_llh_dep_a.lon = -122.38909854449612;

    test_msg.pos_llh_dep_a.n_sats = 8;

    test_msg.pos_llh_dep_a.tow = 407084800;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 2.35413575205 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "2.35413575205, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.7624216106 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.7624216106, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.389098544 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.389098544, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 407084800,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 407084800, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,  195, 4,   34,  100, 159, 67,  24,  22, 77,  146, 22,
        151, 225, 66, 64,  64,  134, 105, 227, 230, 152, 94, 192, 37,  99,
        114, 72,  31, 103, 241, 63,  0,   0,   0,   0,   8,  0,   70,  60,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 0;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 1.0876763181642641;

    test_msg.pos_llh_dep_a.lat = 37.76242334502801;

    test_msg.pos_llh_dep_a.lon = -122.38909230523223;

    test_msg.pos_llh_dep_a.n_sats = 8;

    test_msg.pos_llh_dep_a.tow = 407084900;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 1.08767631816 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "1.08767631816, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.762423345 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.762423345, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.389092305 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.389092305, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 8,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 8, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 407084900,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 407084900, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x201, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  1,   2,   195, 4,   34,  46,  162, 68,  24,  124, 245, 46,  169,
        151, 225, 66,  64,  135, 149, 234, 187, 230, 152, 94,  192, 194, 201,
        115, 145, 166, 175, 20,  64,  0,   0,   0,   0,   5,   0,   212, 121,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_dep_a.flags = 0;

    test_msg.pos_llh_dep_a.h_accuracy = 0;

    test_msg.pos_llh_dep_a.height = 5.171533844654222;

    test_msg.pos_llh_dep_a.lat = 37.76244082253376;

    test_msg.pos_llh_dep_a.lon = -122.38908288868525;

    test_msg.pos_llh_dep_a.n_sats = 5;

    test_msg.pos_llh_dep_a.tow = 407151150;

    test_msg.pos_llh_dep_a.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlhDepA, 1219, &test_msg,
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
        sbp_message_cmp(SbpMsgPosLlhDepA, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.flags == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.flags, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.flags);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.height * 100 - 5.17153384465 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.height, expected "
        "5.17153384465, is %s",
        last_msg.msg.pos_llh_dep_a.height);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lat * 100 - 37.7624408225 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lat, expected "
        "37.7624408225, is %s",
        last_msg.msg.pos_llh_dep_a.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh_dep_a.lon * 100 - -122.389082889 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh_dep_a.lon, expected "
        "-122.389082889, is %s",
        last_msg.msg.pos_llh_dep_a.lon);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.n_sats == 5,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.n_sats, "
                  "expected 5, is %d",
                  last_msg.msg.pos_llh_dep_a.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.tow == 407151150,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.tow, "
                  "expected 407151150, is %d",
                  last_msg.msg.pos_llh_dep_a.tow);

    ck_assert_msg(last_msg.msg.pos_llh_dep_a.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh_dep_a.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh_dep_a.v_accuracy);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgPosLLHDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgPosLLHDepA");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgPosLLHDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgPosLLHDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}