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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLH.yaml by generate.py.
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

START_TEST(test_auto_check_sbp_navigation_MsgPosLLH) {
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

    sbp_callback_register(&sbp_state, 0x20a, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  10,  2,  211, 136, 34,  40, 244, 122, 19,  201, 106, 155, 186,
        42,  160, 66, 64,  168, 109, 26, 225, 0,   120, 94,  192, 130, 102,
        237, 230, 43, 54,  60,  64,  0,  0,   0,   0,   14,  2,   175, 162,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh.flags = 2;

    test_msg.pos_llh.h_accuracy = 0;

    test_msg.pos_llh.height = 28.21160739227208;

    test_msg.pos_llh.lat = 37.25130398358085;

    test_msg.pos_llh.lon = -121.87505366879361;

    test_msg.pos_llh.n_sats = 14;

    test_msg.pos_llh.tow = 326825000;

    test_msg.pos_llh.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlh, 35027, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgPosLlh, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.pos_llh.flags == 2,
        "incorrect value for last_msg.msg.pos_llh.flags, expected 2, is %d",
        last_msg.msg.pos_llh.flags);

    ck_assert_msg(last_msg.msg.pos_llh.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh.height * 100 - 28.2116073923 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh.height, expected "
        "28.2116073923, is %s",
        last_msg.msg.pos_llh.height);

    ck_assert_msg((last_msg.msg.pos_llh.lat * 100 - 37.2513039836 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh.lat, expected "
                  "37.2513039836, is %s",
                  last_msg.msg.pos_llh.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh.lon * 100 - -121.875053669 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh.lon, expected "
        "-121.875053669, is %s",
        last_msg.msg.pos_llh.lon);

    ck_assert_msg(
        last_msg.msg.pos_llh.n_sats == 14,
        "incorrect value for last_msg.msg.pos_llh.n_sats, expected 14, is %d",
        last_msg.msg.pos_llh.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh.tow == 326825000,
                  "incorrect value for last_msg.msg.pos_llh.tow, expected "
                  "326825000, is %d",
                  last_msg.msg.pos_llh.tow);

    ck_assert_msg(last_msg.msg.pos_llh.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x20a, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  10,  2,   211, 136, 34, 16, 248, 122, 19,  52, 177, 251, 178,
        42,  160, 66,  64,  237, 22, 97, 224, 0,   120, 94, 192, 107, 188,
        109, 90,  247, 189, 59,  64, 0,  0,   0,   0,   15, 2,   38,  177,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh.flags = 2;

    test_msg.pos_llh.h_accuracy = 0;

    test_msg.pos_llh.height = 27.742055560866373;

    test_msg.pos_llh.lat = 37.251303074738104;

    test_msg.pos_llh.lon = -121.87505349618341;

    test_msg.pos_llh.n_sats = 15;

    test_msg.pos_llh.tow = 326826000;

    test_msg.pos_llh.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlh, 35027, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgPosLlh, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.pos_llh.flags == 2,
        "incorrect value for last_msg.msg.pos_llh.flags, expected 2, is %d",
        last_msg.msg.pos_llh.flags);

    ck_assert_msg(last_msg.msg.pos_llh.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh.height * 100 - 27.7420555609 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh.height, expected "
        "27.7420555609, is %s",
        last_msg.msg.pos_llh.height);

    ck_assert_msg((last_msg.msg.pos_llh.lat * 100 - 37.2513030747 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh.lat, expected "
                  "37.2513030747, is %s",
                  last_msg.msg.pos_llh.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh.lon * 100 - -121.875053496 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh.lon, expected "
        "-121.875053496, is %s",
        last_msg.msg.pos_llh.lon);

    ck_assert_msg(
        last_msg.msg.pos_llh.n_sats == 15,
        "incorrect value for last_msg.msg.pos_llh.n_sats, expected 15, is %d",
        last_msg.msg.pos_llh.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh.tow == 326826000,
                  "incorrect value for last_msg.msg.pos_llh.tow, expected "
                  "326826000, is %d",
                  last_msg.msg.pos_llh.tow);

    ck_assert_msg(last_msg.msg.pos_llh.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x20a, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  10,  2,  211, 136, 34, 248, 251, 122, 19,  135, 66,  9,  163,
        42,  160, 66, 64,  146, 8,  99,  225, 0,   120, 94,  192, 45, 181,
        143, 219, 28, 157, 59,  64, 0,   0,   0,   0,   15,  2,   51, 40,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh.flags = 2;

    test_msg.pos_llh.h_accuracy = 0;

    test_msg.pos_llh.height = 27.613721582970516;

    test_msg.pos_llh.lat = 37.25130117370741;

    test_msg.pos_llh.lon = -121.87505373641241;

    test_msg.pos_llh.n_sats = 15;

    test_msg.pos_llh.tow = 326827000;

    test_msg.pos_llh.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlh, 35027, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgPosLlh, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.pos_llh.flags == 2,
        "incorrect value for last_msg.msg.pos_llh.flags, expected 2, is %d",
        last_msg.msg.pos_llh.flags);

    ck_assert_msg(last_msg.msg.pos_llh.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh.height * 100 - 27.613721583 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh.height, expected "
        "27.613721583, is %s",
        last_msg.msg.pos_llh.height);

    ck_assert_msg((last_msg.msg.pos_llh.lat * 100 - 37.2513011737 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh.lat, expected "
                  "37.2513011737, is %s",
                  last_msg.msg.pos_llh.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh.lon * 100 - -121.875053736 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh.lon, expected "
        "-121.875053736, is %s",
        last_msg.msg.pos_llh.lon);

    ck_assert_msg(
        last_msg.msg.pos_llh.n_sats == 15,
        "incorrect value for last_msg.msg.pos_llh.n_sats, expected 15, is %d",
        last_msg.msg.pos_llh.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh.tow == 326827000,
                  "incorrect value for last_msg.msg.pos_llh.tow, expected "
                  "326827000, is %d",
                  last_msg.msg.pos_llh.tow);

    ck_assert_msg(last_msg.msg.pos_llh.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x20a, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 10,  2,   211, 136, 34,  224, 255, 122, 19,  18, 44,  253, 119,
        42, 160, 66,  64,  48,  109, 39,  231, 0,   120, 94, 192, 185, 76,
        48, 17,  119, 205, 59,  64,  0,   0,   0,   0,   15, 2,   12,  194,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh.flags = 2;

    test_msg.pos_llh.h_accuracy = 0;

    test_msg.pos_llh.height = 27.80259807042305;

    test_msg.pos_llh.lat = 37.251296042079176;

    test_msg.pos_llh.lon = -121.87505511141057;

    test_msg.pos_llh.n_sats = 15;

    test_msg.pos_llh.tow = 326828000;

    test_msg.pos_llh.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlh, 35027, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgPosLlh, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.pos_llh.flags == 2,
        "incorrect value for last_msg.msg.pos_llh.flags, expected 2, is %d",
        last_msg.msg.pos_llh.flags);

    ck_assert_msg(last_msg.msg.pos_llh.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh.height * 100 - 27.8025980704 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh.height, expected "
        "27.8025980704, is %s",
        last_msg.msg.pos_llh.height);

    ck_assert_msg((last_msg.msg.pos_llh.lat * 100 - 37.2512960421 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh.lat, expected "
                  "37.2512960421, is %s",
                  last_msg.msg.pos_llh.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh.lon * 100 - -121.875055111 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh.lon, expected "
        "-121.875055111, is %s",
        last_msg.msg.pos_llh.lon);

    ck_assert_msg(
        last_msg.msg.pos_llh.n_sats == 15,
        "incorrect value for last_msg.msg.pos_llh.n_sats, expected 15, is %d",
        last_msg.msg.pos_llh.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh.tow == 326828000,
                  "incorrect value for last_msg.msg.pos_llh.tow, expected "
                  "326828000, is %d",
                  last_msg.msg.pos_llh.tow);

    ck_assert_msg(last_msg.msg.pos_llh.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh.v_accuracy);
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

    sbp_callback_register(&sbp_state, 0x20a, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  10,  2,   211, 136, 34,  200, 3,   123, 19,  225, 237, 238, 90,
        42,  160, 66,  64,  59,  143, 70,  235, 0,   120, 94,  192, 101, 106,
        249, 224, 131, 240, 59,  64,  0,   0,   0,   0,   15,  2,   34,  103,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh.flags = 2;

    test_msg.pos_llh.h_accuracy = 0;

    test_msg.pos_llh.height = 27.939512310879213;

    test_msg.pos_llh.lat = 37.251292578377395;

    test_msg.pos_llh.lon = -121.87505609407974;

    test_msg.pos_llh.n_sats = 15;

    test_msg.pos_llh.tow = 326829000;

    test_msg.pos_llh.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlh, 35027, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgPosLlh, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.pos_llh.flags == 2,
        "incorrect value for last_msg.msg.pos_llh.flags, expected 2, is %d",
        last_msg.msg.pos_llh.flags);

    ck_assert_msg(last_msg.msg.pos_llh.h_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh.h_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh.h_accuracy);

    ck_assert_msg(
        (last_msg.msg.pos_llh.height * 100 - 27.9395123109 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh.height, expected "
        "27.9395123109, is %s",
        last_msg.msg.pos_llh.height);

    ck_assert_msg((last_msg.msg.pos_llh.lat * 100 - 37.2512925784 * 100) < 0.05,
                  "incorrect value for last_msg.msg.pos_llh.lat, expected "
                  "37.2512925784, is %s",
                  last_msg.msg.pos_llh.lat);

    ck_assert_msg(
        (last_msg.msg.pos_llh.lon * 100 - -121.875056094 * 100) < 0.05,
        "incorrect value for last_msg.msg.pos_llh.lon, expected "
        "-121.875056094, is %s",
        last_msg.msg.pos_llh.lon);

    ck_assert_msg(
        last_msg.msg.pos_llh.n_sats == 15,
        "incorrect value for last_msg.msg.pos_llh.n_sats, expected 15, is %d",
        last_msg.msg.pos_llh.n_sats);

    ck_assert_msg(last_msg.msg.pos_llh.tow == 326829000,
                  "incorrect value for last_msg.msg.pos_llh.tow, expected "
                  "326829000, is %d",
                  last_msg.msg.pos_llh.tow);

    ck_assert_msg(last_msg.msg.pos_llh.v_accuracy == 0,
                  "incorrect value for last_msg.msg.pos_llh.v_accuracy, "
                  "expected 0, is %d",
                  last_msg.msg.pos_llh.v_accuracy);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgPosLLH_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgPosLLH");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgPosLLH");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgPosLLH);
  suite_add_tcase(s, tc_acq);
  return s;
}