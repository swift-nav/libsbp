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
// spec/tests/yaml/swiftnav/sbp/sbas/test_MsgSbasRaw.yaml by generate.py. Do not
// modify by hand!

#include <check.h>
#include <libsbp/legacy/sbas.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

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
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_sbas_MsgSbasRaw) {
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

    sbp_payload_callback_register(&sbp_state, 0x7777, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x7777, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  119, 119, 28,  200, 34,  131, 2,   201, 228, 233, 29,  4,   23,
        255, 0,   23,  255, 0,   23,  255, 127, 240, 2,   255, 192, 3,   127,
        247, 255, 127, 247, 255, 229, 229, 238, 170, 175, 255, 240, 167, 14,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_sbas_raw_t *test_msg = (msg_sbas_raw_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[0] = 23;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[1] = 255;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[2] = 0;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[3] = 23;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[4] = 255;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[5] = 0;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[6] = 23;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[7] = 255;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[8] = 127;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[9] = 240;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[10] = 2;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[11] = 255;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[12] = 192;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[13] = 3;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[14] = 127;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[15] = 247;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[16] = 255;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[17] = 127;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[18] = 247;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[19] = 255;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[20] = 229;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[21] = 229;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[22] = 238;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[23] = 170;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[24] = 175;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[25] = 255;
    if (sizeof(test_msg->data) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->data[0]);
    }
    test_msg->data[26] = 240;
    test_msg->message_type = 4;
    test_msg->sid.code = 2;
    test_msg->sid.sat = 131;
    test_msg->tow = 501867721;
    sbp_payload_send(&sbp_state, 0x7777, 51228, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 51228,
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
    ck_assert_msg(last_frame.sender_id == 51228,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x7777,
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
    msg_sbas_raw_t *check_msg = (msg_sbas_raw_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->data[0] == 23,
                  "incorrect value for data[0], expected 23, is %d",
                  check_msg->data[0]);
    ck_assert_msg(check_msg->data[1] == 255,
                  "incorrect value for data[1], expected 255, is %d",
                  check_msg->data[1]);
    ck_assert_msg(check_msg->data[2] == 0,
                  "incorrect value for data[2], expected 0, is %d",
                  check_msg->data[2]);
    ck_assert_msg(check_msg->data[3] == 23,
                  "incorrect value for data[3], expected 23, is %d",
                  check_msg->data[3]);
    ck_assert_msg(check_msg->data[4] == 255,
                  "incorrect value for data[4], expected 255, is %d",
                  check_msg->data[4]);
    ck_assert_msg(check_msg->data[5] == 0,
                  "incorrect value for data[5], expected 0, is %d",
                  check_msg->data[5]);
    ck_assert_msg(check_msg->data[6] == 23,
                  "incorrect value for data[6], expected 23, is %d",
                  check_msg->data[6]);
    ck_assert_msg(check_msg->data[7] == 255,
                  "incorrect value for data[7], expected 255, is %d",
                  check_msg->data[7]);
    ck_assert_msg(check_msg->data[8] == 127,
                  "incorrect value for data[8], expected 127, is %d",
                  check_msg->data[8]);
    ck_assert_msg(check_msg->data[9] == 240,
                  "incorrect value for data[9], expected 240, is %d",
                  check_msg->data[9]);
    ck_assert_msg(check_msg->data[10] == 2,
                  "incorrect value for data[10], expected 2, is %d",
                  check_msg->data[10]);
    ck_assert_msg(check_msg->data[11] == 255,
                  "incorrect value for data[11], expected 255, is %d",
                  check_msg->data[11]);
    ck_assert_msg(check_msg->data[12] == 192,
                  "incorrect value for data[12], expected 192, is %d",
                  check_msg->data[12]);
    ck_assert_msg(check_msg->data[13] == 3,
                  "incorrect value for data[13], expected 3, is %d",
                  check_msg->data[13]);
    ck_assert_msg(check_msg->data[14] == 127,
                  "incorrect value for data[14], expected 127, is %d",
                  check_msg->data[14]);
    ck_assert_msg(check_msg->data[15] == 247,
                  "incorrect value for data[15], expected 247, is %d",
                  check_msg->data[15]);
    ck_assert_msg(check_msg->data[16] == 255,
                  "incorrect value for data[16], expected 255, is %d",
                  check_msg->data[16]);
    ck_assert_msg(check_msg->data[17] == 127,
                  "incorrect value for data[17], expected 127, is %d",
                  check_msg->data[17]);
    ck_assert_msg(check_msg->data[18] == 247,
                  "incorrect value for data[18], expected 247, is %d",
                  check_msg->data[18]);
    ck_assert_msg(check_msg->data[19] == 255,
                  "incorrect value for data[19], expected 255, is %d",
                  check_msg->data[19]);
    ck_assert_msg(check_msg->data[20] == 229,
                  "incorrect value for data[20], expected 229, is %d",
                  check_msg->data[20]);
    ck_assert_msg(check_msg->data[21] == 229,
                  "incorrect value for data[21], expected 229, is %d",
                  check_msg->data[21]);
    ck_assert_msg(check_msg->data[22] == 238,
                  "incorrect value for data[22], expected 238, is %d",
                  check_msg->data[22]);
    ck_assert_msg(check_msg->data[23] == 170,
                  "incorrect value for data[23], expected 170, is %d",
                  check_msg->data[23]);
    ck_assert_msg(check_msg->data[24] == 175,
                  "incorrect value for data[24], expected 175, is %d",
                  check_msg->data[24]);
    ck_assert_msg(check_msg->data[25] == 255,
                  "incorrect value for data[25], expected 255, is %d",
                  check_msg->data[25]);
    ck_assert_msg(check_msg->data[26] == 240,
                  "incorrect value for data[26], expected 240, is %d",
                  check_msg->data[26]);
    ck_assert_msg(check_msg->message_type == 4,
                  "incorrect value for message_type, expected 4, is %d",
                  check_msg->message_type);
    ck_assert_msg(check_msg->sid.code == 2,
                  "incorrect value for sid.code, expected 2, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.sat == 131,
                  "incorrect value for sid.sat, expected 131, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->tow == 501867721,
                  "incorrect value for tow, expected 501867721, is %d",
                  check_msg->tow);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_sbas_MsgSbasRaw_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_sbas_MsgSbasRaw");
  TCase *tc_acq =
      tcase_create("Automated_Suite_legacy_auto_check_sbp_sbas_MsgSbasRaw");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_sbas_MsgSbasRaw);
  suite_add_tcase(s, tc_acq);
  return s;
}