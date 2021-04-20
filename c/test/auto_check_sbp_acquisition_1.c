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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepB.yaml by
// generate.py. Do not modify by hand!

#include <acquisition.h>
#include <check.h>
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

START_TEST(test_auto_check_sbp_acquisition_1) {
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

    sbp_register_callback(&sbp_state, 0x14, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x14, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x14, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  20, 0,   246, 215, 16, 137, 167, 18, 66, 0,  0,
        161, 67, 240, 24,  156, 69, 9,   0,   0,  0,  80, 195,
    };
    u8 test_encoded_payload_data[] = {
        137, 167, 18, 66, 0, 0, 161, 67, 240, 24, 156, 69, 9, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_acq_result_dep_b_t *test_msg =
        (sbp_msg_acq_result_dep_b_t *)&test_msg_storage;
    test_msg->cf = 4995.1171875;
    test_msg->cp = 322.0;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 9;
    test_msg->snr = 36.66360855102539;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x14, 55286, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    sbp_msg_acq_result_dep_b_t *check_msg =
        (sbp_msg_acq_result_dep_b_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - 4995.1171875 * 100) < 0.05,
                  "incorrect value for cf, expected 4995.1171875, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cp * 100 - 322.0 * 100) < 0.05,
                  "incorrect value for cp, expected 322.0, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 9,
                  "incorrect value for sid.sat, expected 9, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->snr * 100 - 36.663608551 * 100) < 0.05,
                  "incorrect value for snr, expected 36.663608551, is %f",
                  check_msg->snr);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x14, 55286,
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
    ck_assert_msg(last_payload.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    ck_assert_msg((check_msg->cf * 100 - 4995.1171875 * 100) < 0.05,
                  "incorrect value for cf, expected 4995.1171875, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cp * 100 - 322.0 * 100) < 0.05,
                  "incorrect value for cp, expected 322.0, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 9,
                  "incorrect value for sid.sat, expected 9, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->snr * 100 - 36.663608551 * 100) < 0.05,
                  "incorrect value for snr, expected 36.663608551, is %f",
                  check_msg->snr);
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

    sbp_register_callback(&sbp_state, 0x14, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x14, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x14, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 20, 0,   246, 215, 16,  206, 172, 16, 66, 0,   192,
        82, 68, 198, 199, 0,   198, 3,   0,   0,  0,  149, 143,
    };
    u8 test_encoded_payload_data[] = {
        206, 172, 16, 66, 0, 192, 82, 68, 198, 199, 0, 198, 3, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_acq_result_dep_b_t *test_msg =
        (sbp_msg_acq_result_dep_b_t *)&test_msg_storage;
    test_msg->cf = -8241.943359375;
    test_msg->cp = 843.0;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 3;
    test_msg->snr = 36.16875457763672;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x14, 55286, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    sbp_msg_acq_result_dep_b_t *check_msg =
        (sbp_msg_acq_result_dep_b_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - -8241.94335938 * 100) < 0.05,
                  "incorrect value for cf, expected -8241.94335938, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cp * 100 - 843.0 * 100) < 0.05,
                  "incorrect value for cp, expected 843.0, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 3,
                  "incorrect value for sid.sat, expected 3, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->snr * 100 - 36.1687545776 * 100) < 0.05,
                  "incorrect value for snr, expected 36.1687545776, is %f",
                  check_msg->snr);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x14, 55286,
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
    ck_assert_msg(last_payload.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    ck_assert_msg((check_msg->cf * 100 - -8241.94335938 * 100) < 0.05,
                  "incorrect value for cf, expected -8241.94335938, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cp * 100 - 843.0 * 100) < 0.05,
                  "incorrect value for cp, expected 843.0, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 3,
                  "incorrect value for sid.sat, expected 3, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->snr * 100 - 36.1687545776 * 100) < 0.05,
                  "incorrect value for snr, expected 36.1687545776, is %f",
                  check_msg->snr);
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

    sbp_register_callback(&sbp_state, 0x14, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x14, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x14, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 20, 0,   246, 215, 16, 228, 27, 15, 66, 0,   128,
        70, 68, 228, 74,  148, 69, 18,  0,  0,  0,  179, 155,
    };
    u8 test_encoded_payload_data[] = {
        228, 27, 15, 66, 0, 128, 70, 68, 228, 74, 148, 69, 18, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_acq_result_dep_b_t *test_msg =
        (sbp_msg_acq_result_dep_b_t *)&test_msg_storage;
    test_msg->cf = 4745.361328125;
    test_msg->cp = 794.0;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 18;
    test_msg->snr = 35.77723693847656;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x14, 55286, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    sbp_msg_acq_result_dep_b_t *check_msg =
        (sbp_msg_acq_result_dep_b_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - 4745.36132812 * 100) < 0.05,
                  "incorrect value for cf, expected 4745.36132812, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cp * 100 - 794.0 * 100) < 0.05,
                  "incorrect value for cp, expected 794.0, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 18,
                  "incorrect value for sid.sat, expected 18, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->snr * 100 - 35.7772369385 * 100) < 0.05,
                  "incorrect value for snr, expected 35.7772369385, is %f",
                  check_msg->snr);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x14, 55286,
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
    ck_assert_msg(last_payload.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    ck_assert_msg((check_msg->cf * 100 - 4745.36132812 * 100) < 0.05,
                  "incorrect value for cf, expected 4745.36132812, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cp * 100 - 794.0 * 100) < 0.05,
                  "incorrect value for cp, expected 794.0, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 18,
                  "incorrect value for sid.sat, expected 18, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->snr * 100 - 35.7772369385 * 100) < 0.05,
                  "incorrect value for snr, expected 35.7772369385, is %f",
                  check_msg->snr);
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

    sbp_register_callback(&sbp_state, 0x14, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x14, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x14, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  20, 0,   246, 215, 16, 46, 199, 14, 66, 0,  64,
        129, 67, 240, 24,  28,  69, 17, 0,   0,  0,  18, 181,
    };
    u8 test_encoded_payload_data[] = {
        46, 199, 14, 66, 0, 64, 129, 67, 240, 24, 28, 69, 17, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_acq_result_dep_b_t *test_msg =
        (sbp_msg_acq_result_dep_b_t *)&test_msg_storage;
    test_msg->cf = 2497.55859375;
    test_msg->cp = 258.5;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 17;
    test_msg->snr = 35.69451141357422;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x14, 55286, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    sbp_msg_acq_result_dep_b_t *check_msg =
        (sbp_msg_acq_result_dep_b_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - 2497.55859375 * 100) < 0.05,
                  "incorrect value for cf, expected 2497.55859375, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cp * 100 - 258.5 * 100) < 0.05,
                  "incorrect value for cp, expected 258.5, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 17,
                  "incorrect value for sid.sat, expected 17, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->snr * 100 - 35.6945114136 * 100) < 0.05,
                  "incorrect value for snr, expected 35.6945114136, is %f",
                  check_msg->snr);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x14, 55286,
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
    ck_assert_msg(last_payload.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    ck_assert_msg((check_msg->cf * 100 - 2497.55859375 * 100) < 0.05,
                  "incorrect value for cf, expected 2497.55859375, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cp * 100 - 258.5 * 100) < 0.05,
                  "incorrect value for cp, expected 258.5, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 17,
                  "incorrect value for sid.sat, expected 17, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->snr * 100 - 35.6945114136 * 100) < 0.05,
                  "incorrect value for snr, expected 35.6945114136, is %f",
                  check_msg->snr);
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

    sbp_register_callback(&sbp_state, 0x14, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x14, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x14, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 20, 0,   246, 215, 16,  194, 24, 14, 66, 0,  128,
        2,  68, 129, 193, 249, 195, 5,   0,  0,  0,  35, 203,
    };
    u8 test_encoded_payload_data[] = {
        194, 24, 14, 66, 0, 128, 2, 68, 129, 193, 249, 195, 5, 0, 0, 0,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_acq_result_dep_b_t *test_msg =
        (sbp_msg_acq_result_dep_b_t *)&test_msg_storage;
    test_msg->cf = -499.5117492675781;
    test_msg->cp = 522.0;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 5;
    test_msg->snr = 35.52417755126953;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x14, 55286, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    sbp_msg_acq_result_dep_b_t *check_msg =
        (sbp_msg_acq_result_dep_b_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg((check_msg->cf * 100 - -499.511749268 * 100) < 0.05,
                  "incorrect value for cf, expected -499.511749268, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cp * 100 - 522.0 * 100) < 0.05,
                  "incorrect value for cp, expected 522.0, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 5,
                  "incorrect value for sid.sat, expected 5, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->snr * 100 - 35.5241775513 * 100) < 0.05,
                  "incorrect value for snr, expected 35.5241775513, is %f",
                  check_msg->snr);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x14, 55286,
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
    ck_assert_msg(last_payload.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
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
    ck_assert_msg((check_msg->cf * 100 - -499.511749268 * 100) < 0.05,
                  "incorrect value for cf, expected -499.511749268, is %f",
                  check_msg->cf);
    ck_assert_msg((check_msg->cp * 100 - 522.0 * 100) < 0.05,
                  "incorrect value for cp, expected 522.0, is %f",
                  check_msg->cp);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 5,
                  "incorrect value for sid.sat, expected 5, is %d",
                  check_msg->sid.sat);
    ck_assert_msg((check_msg->snr * 100 - 35.5241775513 * 100) < 0.05,
                  "incorrect value for snr, expected 35.5241775513, is %f",
                  check_msg->snr);
  }
}
END_TEST

Suite *auto_check_sbp_acquisition_1_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_acquisition_1");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_acquisition_1");
  tcase_add_test(tc_acq, test_auto_check_sbp_acquisition_1);
  suite_add_tcase(s, tc_acq);
  return s;
}