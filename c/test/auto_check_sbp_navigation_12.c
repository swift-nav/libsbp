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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEF.yaml by generate.py.
// Do not modify by hand!

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

START_TEST(test_auto_check_sbp_navigation_12) {
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

    sbp_register_callback(&sbp_state, 0x209, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x209, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x209, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  9,   2,  211, 136, 32,  16, 248, 122, 19,  73, 29,  46, 132,
        182, 122, 68, 193, 219, 192, 29, 176, 121, 119, 80, 193, 83, 11,
        210, 90,  79, 75,  77,  65,  0,  0,   15,  2,   84, 6,
    };
    u8 test_encoded_payload_data[] = {
        16,  248, 122, 19, 73,  29,  46,  132, 182, 122, 68,
        193, 219, 192, 29, 176, 121, 119, 80,  193, 83,  11,
        210, 90,  79,  75, 77,  65,  0,   0,   15,  2,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_pos_ecef_t *test_msg = (sbp_msg_pos_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 2;
    test_msg->n_sats = 15;
    test_msg->tow = 326826000;
    test_msg->x = -2684269.0326572997;
    test_msg->y = -4316646.751816;
    test_msg->z = 3839646.7095350414;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x209, 35027, &test_msg_storage, &dummy_write);

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
    sbp_msg_pos_ecef_t *check_msg = (sbp_msg_pos_ecef_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326826000,
                  "incorrect value for tow, expected 326826000, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2684269.03266 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.03266, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4316646.75182 * 100) < 0.05,
                  "incorrect value for y, expected -4316646.75182, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3839646.70954 * 100) < 0.05,
                  "incorrect value for z, expected 3839646.70954, is %f",
                  check_msg->z);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x209, 35027,
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
    ck_assert_msg(check_msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326826000,
                  "incorrect value for tow, expected 326826000, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2684269.03266 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.03266, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4316646.75182 * 100) < 0.05,
                  "incorrect value for y, expected -4316646.75182, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3839646.70954 * 100) < 0.05,
                  "incorrect value for z, expected 3839646.70954, is %f",
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

    sbp_register_callback(&sbp_state, 0x209, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x209, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x209, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  9,   2,  211, 136, 32,  248, 251, 122, 19,  103, 106, 57,  136,
        182, 122, 68, 193, 176, 242, 200, 176, 121, 119, 80,  193, 244, 135,
        97,  59,  79, 75,  77,  65,  0,   0,   15,  2,   147, 216,
    };
    u8 test_encoded_payload_data[] = {
        248, 251, 122, 19,  103, 106, 57,  136, 182, 122, 68,
        193, 176, 242, 200, 176, 121, 119, 80,  193, 244, 135,
        97,  59,  79,  75,  77,  65,  0,   0,   15,  2,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_pos_ecef_t *test_msg = (sbp_msg_pos_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 2;
    test_msg->n_sats = 15;
    test_msg->tow = 326827000;
    test_msg->x = -2684269.064252186;
    test_msg->y = -4316646.762264892;
    test_msg->z = 3839646.463913912;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x209, 35027, &test_msg_storage, &dummy_write);

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
    sbp_msg_pos_ecef_t *check_msg = (sbp_msg_pos_ecef_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326827000,
                  "incorrect value for tow, expected 326827000, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2684269.06425 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.06425, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4316646.76226 * 100) < 0.05,
                  "incorrect value for y, expected -4316646.76226, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3839646.46391 * 100) < 0.05,
                  "incorrect value for z, expected 3839646.46391, is %f",
                  check_msg->z);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x209, 35027,
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
    ck_assert_msg(check_msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326827000,
                  "incorrect value for tow, expected 326827000, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2684269.06425 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.06425, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4316646.76226 * 100) < 0.05,
                  "incorrect value for y, expected -4316646.76226, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3839646.46391 * 100) < 0.05,
                  "incorrect value for z, expected 3839646.46391, is %f",
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

    sbp_register_callback(&sbp_state, 0x209, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x209, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x209, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  9,   2,  211, 136, 32,  224, 255, 122, 19,  101, 179, 242, 182,
        182, 122, 68, 193, 130, 196, 145, 199, 121, 119, 80,  193, 212, 10,
        253, 15,  79, 75,  77,  65,  0,   0,   15,  2,   40,  201,
    };
    u8 test_encoded_payload_data[] = {
        224, 255, 122, 19,  101, 179, 242, 182, 182, 122, 68,
        193, 130, 196, 145, 199, 121, 119, 80,  193, 212, 10,
        253, 15,  79,  75,  77,  65,  0,   0,   15,  2,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_pos_ecef_t *test_msg = (sbp_msg_pos_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 2;
    test_msg->n_sats = 15;
    test_msg->tow = 326828000;
    test_msg->x = -2684269.4292816394;
    test_msg->y = -4316647.118271949;
    test_msg->z = 3839646.124909738;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x209, 35027, &test_msg_storage, &dummy_write);

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
    sbp_msg_pos_ecef_t *check_msg = (sbp_msg_pos_ecef_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326828000,
                  "incorrect value for tow, expected 326828000, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2684269.42928 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.42928, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4316647.11827 * 100) < 0.05,
                  "incorrect value for y, expected -4316647.11827, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3839646.12491 * 100) < 0.05,
                  "incorrect value for z, expected 3839646.12491, is %f",
                  check_msg->z);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x209, 35027,
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
    ck_assert_msg(check_msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326828000,
                  "incorrect value for tow, expected 326828000, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2684269.42928 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.42928, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4316647.11827 * 100) < 0.05,
                  "incorrect value for y, expected -4316647.11827, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3839646.12491 * 100) < 0.05,
                  "incorrect value for z, expected 3839646.12491, is %f",
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

    sbp_register_callback(&sbp_state, 0x209, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x209, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x209, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  9,   2,  211, 136, 32, 200, 3,   123, 19,  146, 214, 132, 215,
        182, 122, 68, 193, 213, 68, 49,  215, 121, 119, 80,  193, 71,  34,
        110, 243, 78, 75,  77,  65, 0,   0,   15,  2,   187, 86,
    };
    u8 test_encoded_payload_data[] = {
        200, 3,   123, 19, 146, 214, 132, 215, 182, 122, 68,
        193, 213, 68,  49, 215, 121, 119, 80,  193, 71,  34,
        110, 243, 78,  75, 77,  65,  0,   0,   15,  2,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_pos_ecef_t *test_msg = (sbp_msg_pos_ecef_t *)&test_msg_storage;
    test_msg->accuracy = 0;
    test_msg->flags = 2;
    test_msg->n_sats = 15;
    test_msg->tow = 326829000;
    test_msg->x = -2684269.683741399;
    test_msg->y = -4316647.3623821335;
    test_msg->z = 3839645.90179852;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x209, 35027, &test_msg_storage, &dummy_write);

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
    sbp_msg_pos_ecef_t *check_msg = (sbp_msg_pos_ecef_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326829000,
                  "incorrect value for tow, expected 326829000, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2684269.68374 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.68374, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4316647.36238 * 100) < 0.05,
                  "incorrect value for y, expected -4316647.36238, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3839645.9018 * 100) < 0.05,
                  "incorrect value for z, expected 3839645.9018, is %f",
                  check_msg->z);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x209, 35027,
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
    ck_assert_msg(check_msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 15,
                  "incorrect value for n_sats, expected 15, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 326829000,
                  "incorrect value for tow, expected 326829000, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2684269.68374 * 100) < 0.05,
                  "incorrect value for x, expected -2684269.68374, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4316647.36238 * 100) < 0.05,
                  "incorrect value for y, expected -4316647.36238, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3839645.9018 * 100) < 0.05,
                  "incorrect value for z, expected 3839645.9018, is %f",
                  check_msg->z);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_12_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_navigation_12");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_12");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_12);
  suite_add_tcase(s, tc_acq);
  return s;
}