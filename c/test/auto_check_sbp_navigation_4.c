/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEF.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <navigation.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 payload[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_payload;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 payload_len;
  u8 payload[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  sbp_msg_t msg;
  void *context;
} last_unpacked;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return real_n;
}

static void logging_reset() {
  memset(&last_payload, 0, sizeof(last_payload));
  memset(&last_frame, 0, sizeof(last_frame));
  memset(&last_unpacked, 0, sizeof(last_unpacked));
}

static void payload_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_payload.n_callbacks_logged++;
  last_payload.sender_id = sender_id;
  last_payload.len = len;
  last_payload.context = context;
  memcpy(last_payload.payload, msg, len);

  /*printy_callback(sender_id, len, msg);*/
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 payload_len,
                           u8 payload[], u16 frame_len, u8 frame[],
                           void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.payload_len = payload_len;
  memcpy(last_frame.payload, payload, payload_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

static void unpacked_callback(u16 sender_id, u16 msg_type, const sbp_msg_t *msg,
                              void *context) {
  last_unpacked.n_callbacks_logged++;
  last_unpacked.sender_id = sender_id;
  last_unpacked.msg_type = msg_type;
  memcpy(&last_unpacked.msg, msg, sizeof(*msg));
  last_unpacked.context = context;
}

START_TEST(test_auto_check_sbp_navigation_4) {
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;
  static sbp_msg_callbacks_node_t n3;

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

    sbp_register_callback(&sbp_state, 0x20b, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20b, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x20b, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  11, 2,  211, 136, 20,  40, 244, 122, 19, 150, 98, 238, 255,
        190, 64, 20, 0,   246, 163, 9,  0,   0,   0,  14,  0,  219, 191,
    };
    u8 test_encoded_payload_data[] = {
        40, 244, 122, 19,  150, 98, 238, 255, 190, 64,
        20, 0,   246, 163, 9,   0,  0,   0,   14,  0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_baseline_ecef_t *test_msg =
        (sbp_msg_baseline_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 14;
    test_msg->tow = 326825000;
    test_msg->x = -1154410;
    test_msg->y = 1327294;
    test_msg->z = 631798;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x20b, 35027, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_baseline_ecef_t *check_msg =
        (sbp_msg_baseline_ecef_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 14,
                  "incorrect value for n_sats, expected 14, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326825000,
                  "incorrect value for tow, expected 326825000, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->x == -1154410,
                  "incorrect value for x, expected -1154410, is %d",
                  check_msg->x);
    ck_assert_msg(check_msg->y == 1327294,
                  "incorrect value for y, expected 1327294, is %d",
                  check_msg->y);
    ck_assert_msg(check_msg->z == 631798,
                  "incorrect value for z, expected 631798, is %d",
                  check_msg->z);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x20b, 35027,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 14,
                  "incorrect value for n_sats, expected 14, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326825000,
                  "incorrect value for tow, expected 326825000, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->x == -1154410,
                  "incorrect value for x, expected -1154410, is %d",
                  check_msg->x);
    ck_assert_msg(check_msg->y == 1327294,
                  "incorrect value for y, expected 1327294, is %d",
                  check_msg->y);
    ck_assert_msg(check_msg->z == 631798,
                  "incorrect value for z, expected 631798, is %d",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x20b, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20b, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x20b, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  11, 2,  211, 136, 20,  16, 248, 122, 19, 72, 99, 238, 255,
        191, 65, 20, 0,   138, 162, 9,  0,   0,   0,  15, 0,  240, 78,
    };
    u8 test_encoded_payload_data[] = {
        16, 248, 122, 19,  72, 99, 238, 255, 191, 65,
        20, 0,   138, 162, 9,  0,  0,   0,   15,  0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_baseline_ecef_t *test_msg =
        (sbp_msg_baseline_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326826000;
    test_msg->x = -1154232;
    test_msg->y = 1327551;
    test_msg->z = 631434;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x20b, 35027, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_baseline_ecef_t *check_msg =
        (sbp_msg_baseline_ecef_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326826000,
                  "incorrect value for tow, expected 326826000, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->x == -1154232,
                  "incorrect value for x, expected -1154232, is %d",
                  check_msg->x);
    ck_assert_msg(check_msg->y == 1327551,
                  "incorrect value for y, expected 1327551, is %d",
                  check_msg->y);
    ck_assert_msg(check_msg->z == 631434,
                  "incorrect value for z, expected 631434, is %d",
                  check_msg->z);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x20b, 35027,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326826000,
                  "incorrect value for tow, expected 326826000, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->x == -1154232,
                  "incorrect value for x, expected -1154232, is %d",
                  check_msg->x);
    ck_assert_msg(check_msg->y == 1327551,
                  "incorrect value for y, expected 1327551, is %d",
                  check_msg->y);
    ck_assert_msg(check_msg->z == 631434,
                  "incorrect value for z, expected 631434, is %d",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x20b, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20b, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x20b, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  11, 2,  211, 136, 20,  248, 251, 122, 19, 41, 99, 238, 255,
        181, 65, 20, 0,   148, 161, 9,   0,   0,   0,  15, 0,  4,   132,
    };
    u8 test_encoded_payload_data[] = {
        248, 251, 122, 19,  41, 99, 238, 255, 181, 65,
        20,  0,   148, 161, 9,  0,  0,   0,   15,  0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_baseline_ecef_t *test_msg =
        (sbp_msg_baseline_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326827000;
    test_msg->x = -1154263;
    test_msg->y = 1327541;
    test_msg->z = 631188;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x20b, 35027, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_baseline_ecef_t *check_msg =
        (sbp_msg_baseline_ecef_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326827000,
                  "incorrect value for tow, expected 326827000, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->x == -1154263,
                  "incorrect value for x, expected -1154263, is %d",
                  check_msg->x);
    ck_assert_msg(check_msg->y == 1327541,
                  "incorrect value for y, expected 1327541, is %d",
                  check_msg->y);
    ck_assert_msg(check_msg->z == 631188,
                  "incorrect value for z, expected 631188, is %d",
                  check_msg->z);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x20b, 35027,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326827000,
                  "incorrect value for tow, expected 326827000, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->x == -1154263,
                  "incorrect value for x, expected -1154263, is %d",
                  check_msg->x);
    ck_assert_msg(check_msg->y == 1327541,
                  "incorrect value for y, expected 1327541, is %d",
                  check_msg->y);
    ck_assert_msg(check_msg->z == 631188,
                  "incorrect value for z, expected 631188, is %d",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x20b, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20b, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x20b, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 11, 2,  211, 136, 20,  224, 255, 122, 19, 188, 97, 238, 255,
        81, 64, 20, 0,   65,  160, 9,   0,   0,   0,  15,  0,  67,  94,
    };
    u8 test_encoded_payload_data[] = {
        224, 255, 122, 19,  188, 97, 238, 255, 81, 64,
        20,  0,   65,  160, 9,   0,  0,   0,   15, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_baseline_ecef_t *test_msg =
        (sbp_msg_baseline_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326828000;
    test_msg->x = -1154628;
    test_msg->y = 1327185;
    test_msg->z = 630849;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x20b, 35027, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_baseline_ecef_t *check_msg =
        (sbp_msg_baseline_ecef_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326828000,
                  "incorrect value for tow, expected 326828000, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->x == -1154628,
                  "incorrect value for x, expected -1154628, is %d",
                  check_msg->x);
    ck_assert_msg(check_msg->y == 1327185,
                  "incorrect value for y, expected 1327185, is %d",
                  check_msg->y);
    ck_assert_msg(check_msg->z == 630849,
                  "incorrect value for z, expected 630849, is %d",
                  check_msg->z);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x20b, 35027,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326828000,
                  "incorrect value for tow, expected 326828000, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->x == -1154628,
                  "incorrect value for x, expected -1154628, is %d",
                  check_msg->x);
    ck_assert_msg(check_msg->y == 1327185,
                  "incorrect value for y, expected 1327185, is %d",
                  check_msg->y);
    ck_assert_msg(check_msg->z == 630849,
                  "incorrect value for z, expected 630849, is %d",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x20b, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x20b, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x20b, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 11, 2,  211, 136, 20,  200, 3, 123, 19, 189, 96, 238, 255,
        93, 63, 20, 0,   98,  159, 9,   0, 0,   0,  15,  0,  106, 94,
    };
    u8 test_encoded_payload_data[] = {
        200, 3, 123, 19,  189, 96, 238, 255, 93, 63,
        20,  0, 98,  159, 9,   0,  0,   0,   15, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_baseline_ecef_t *test_msg =
        (sbp_msg_baseline_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 15;
    test_msg->tow = 326829000;
    test_msg->x = -1154883;
    test_msg->y = 1326941;
    test_msg->z = 630626;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x20b, 35027, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_baseline_ecef_t *check_msg =
        (sbp_msg_baseline_ecef_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326829000,
                  "incorrect value for tow, expected 326829000, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->x == -1154883,
                  "incorrect value for x, expected -1154883, is %d",
                  check_msg->x);
    ck_assert_msg(check_msg->y == 1326941,
                  "incorrect value for y, expected 1326941, is %d",
                  check_msg->y);
    ck_assert_msg(check_msg->z == 630626,
                  "incorrect value for z, expected 630626, is %d",
                  check_msg->z);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x20b, 35027,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 35027,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326829000,
                  "incorrect value for tow, expected 326829000, is %d",
                  check_msg->tow);
    ck_assert_msg(check_msg->x == -1154883,
                  "incorrect value for x, expected -1154883, is %d",
                  check_msg->x);
    ck_assert_msg(check_msg->y == 1326941,
                  "incorrect value for y, expected 1326941, is %d",
                  check_msg->y);
    ck_assert_msg(check_msg->z == 630626,
                  "incorrect value for z, expected 630626, is %d",
                  check_msg->z);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_4_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_navigation_4");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_4");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_4);
  suite_add_tcase(s, tc_acq);
  return s;
}