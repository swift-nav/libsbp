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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApc.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/api.h>
#include <libsbp/legacy/compat.h>
#include <libsbp/legacy/ssr.h>

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

START_TEST(test_legacy_auto_check_sbp_ssr_MsgSsrSatelliteApc) {
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

    sbp_payload_callback_register(&sbp_state, 0x605, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x605, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 5,  6,  0,  0,  41,  127, 58,  9,   0,   174, 8,   1,
        2,  3,  2,  0,  4,  61,  0,   1,   0,   255, 255, 217, 2,
        11, 10, 8,  5,  1,  252, 248, 246, 246, 246, 249, 252, 0,
        6,  12, 22, 30, 41, 41,  41,  41,  144, 161,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ssr_satellite_apc_t *test_msg =
        (msg_ssr_satellite_apc_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->apc) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0]);
    }
    if (sizeof(test_msg->apc[0].pco) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pco[0]);
    }
    test_msg->apc[0].pco[0] = 1;
    if (sizeof(test_msg->apc[0].pco) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pco[0]);
    }
    test_msg->apc[0].pco[1] = -1;
    if (sizeof(test_msg->apc[0].pco) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pco[0]);
    }
    test_msg->apc[0].pco[2] = 729;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[0] = 11;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[1] = 10;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[2] = 8;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[3] = 5;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[4] = 1;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[5] = -4;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[6] = -8;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[7] = -10;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[8] = -10;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[9] = -10;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[10] = -7;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[11] = -4;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[12] = 0;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[13] = 6;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[14] = 12;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[15] = 22;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[16] = 30;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[17] = 41;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[18] = 41;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[19] = 41;
    if (sizeof(test_msg->apc[0].pcv) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->apc[0].pcv[0]);
    }
    test_msg->apc[0].pcv[20] = 41;
    test_msg->apc[0].sat_info = 4;
    test_msg->apc[0].sid.code = 0;
    test_msg->apc[0].sid.sat = 2;
    test_msg->apc[0].svn = 61;
    test_msg->iod_ssr = 3;
    test_msg->sol_id = 2;
    test_msg->time.tow = 604799;
    test_msg->time.wn = 2222;
    test_msg->update_interval = 1;
    sbp_payload_send(&sbp_state, 0x605, 0, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 0,
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
    ck_assert_msg(last_frame.sender_id == 0,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x605,
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
    msg_ssr_satellite_apc_t *check_msg =
        (msg_ssr_satellite_apc_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->apc[0].pco[0] == 1,
                  "incorrect value for apc[0].pco[0], expected 1, is %d",
                  check_msg->apc[0].pco[0]);
    ck_assert_msg(check_msg->apc[0].pco[1] == -1,
                  "incorrect value for apc[0].pco[1], expected -1, is %d",
                  check_msg->apc[0].pco[1]);
    ck_assert_msg(check_msg->apc[0].pco[2] == 729,
                  "incorrect value for apc[0].pco[2], expected 729, is %d",
                  check_msg->apc[0].pco[2]);
    ck_assert_msg(check_msg->apc[0].pcv[0] == 11,
                  "incorrect value for apc[0].pcv[0], expected 11, is %d",
                  check_msg->apc[0].pcv[0]);
    ck_assert_msg(check_msg->apc[0].pcv[1] == 10,
                  "incorrect value for apc[0].pcv[1], expected 10, is %d",
                  check_msg->apc[0].pcv[1]);
    ck_assert_msg(check_msg->apc[0].pcv[2] == 8,
                  "incorrect value for apc[0].pcv[2], expected 8, is %d",
                  check_msg->apc[0].pcv[2]);
    ck_assert_msg(check_msg->apc[0].pcv[3] == 5,
                  "incorrect value for apc[0].pcv[3], expected 5, is %d",
                  check_msg->apc[0].pcv[3]);
    ck_assert_msg(check_msg->apc[0].pcv[4] == 1,
                  "incorrect value for apc[0].pcv[4], expected 1, is %d",
                  check_msg->apc[0].pcv[4]);
    ck_assert_msg(check_msg->apc[0].pcv[5] == -4,
                  "incorrect value for apc[0].pcv[5], expected -4, is %d",
                  check_msg->apc[0].pcv[5]);
    ck_assert_msg(check_msg->apc[0].pcv[6] == -8,
                  "incorrect value for apc[0].pcv[6], expected -8, is %d",
                  check_msg->apc[0].pcv[6]);
    ck_assert_msg(check_msg->apc[0].pcv[7] == -10,
                  "incorrect value for apc[0].pcv[7], expected -10, is %d",
                  check_msg->apc[0].pcv[7]);
    ck_assert_msg(check_msg->apc[0].pcv[8] == -10,
                  "incorrect value for apc[0].pcv[8], expected -10, is %d",
                  check_msg->apc[0].pcv[8]);
    ck_assert_msg(check_msg->apc[0].pcv[9] == -10,
                  "incorrect value for apc[0].pcv[9], expected -10, is %d",
                  check_msg->apc[0].pcv[9]);
    ck_assert_msg(check_msg->apc[0].pcv[10] == -7,
                  "incorrect value for apc[0].pcv[10], expected -7, is %d",
                  check_msg->apc[0].pcv[10]);
    ck_assert_msg(check_msg->apc[0].pcv[11] == -4,
                  "incorrect value for apc[0].pcv[11], expected -4, is %d",
                  check_msg->apc[0].pcv[11]);
    ck_assert_msg(check_msg->apc[0].pcv[12] == 0,
                  "incorrect value for apc[0].pcv[12], expected 0, is %d",
                  check_msg->apc[0].pcv[12]);
    ck_assert_msg(check_msg->apc[0].pcv[13] == 6,
                  "incorrect value for apc[0].pcv[13], expected 6, is %d",
                  check_msg->apc[0].pcv[13]);
    ck_assert_msg(check_msg->apc[0].pcv[14] == 12,
                  "incorrect value for apc[0].pcv[14], expected 12, is %d",
                  check_msg->apc[0].pcv[14]);
    ck_assert_msg(check_msg->apc[0].pcv[15] == 22,
                  "incorrect value for apc[0].pcv[15], expected 22, is %d",
                  check_msg->apc[0].pcv[15]);
    ck_assert_msg(check_msg->apc[0].pcv[16] == 30,
                  "incorrect value for apc[0].pcv[16], expected 30, is %d",
                  check_msg->apc[0].pcv[16]);
    ck_assert_msg(check_msg->apc[0].pcv[17] == 41,
                  "incorrect value for apc[0].pcv[17], expected 41, is %d",
                  check_msg->apc[0].pcv[17]);
    ck_assert_msg(check_msg->apc[0].pcv[18] == 41,
                  "incorrect value for apc[0].pcv[18], expected 41, is %d",
                  check_msg->apc[0].pcv[18]);
    ck_assert_msg(check_msg->apc[0].pcv[19] == 41,
                  "incorrect value for apc[0].pcv[19], expected 41, is %d",
                  check_msg->apc[0].pcv[19]);
    ck_assert_msg(check_msg->apc[0].pcv[20] == 41,
                  "incorrect value for apc[0].pcv[20], expected 41, is %d",
                  check_msg->apc[0].pcv[20]);
    ck_assert_msg(check_msg->apc[0].sat_info == 4,
                  "incorrect value for apc[0].sat_info, expected 4, is %d",
                  check_msg->apc[0].sat_info);
    ck_assert_msg(check_msg->apc[0].sid.code == 0,
                  "incorrect value for apc[0].sid.code, expected 0, is %d",
                  check_msg->apc[0].sid.code);
    ck_assert_msg(check_msg->apc[0].sid.sat == 2,
                  "incorrect value for apc[0].sid.sat, expected 2, is %d",
                  check_msg->apc[0].sid.sat);
    ck_assert_msg(check_msg->apc[0].svn == 61,
                  "incorrect value for apc[0].svn, expected 61, is %d",
                  check_msg->apc[0].svn);
    ck_assert_msg(check_msg->iod_ssr == 3,
                  "incorrect value for iod_ssr, expected 3, is %d",
                  check_msg->iod_ssr);
    ck_assert_msg(check_msg->sol_id == 2,
                  "incorrect value for sol_id, expected 2, is %d",
                  check_msg->sol_id);
    ck_assert_msg(check_msg->time.tow == 604799,
                  "incorrect value for time.tow, expected 604799, is %d",
                  check_msg->time.tow);
    ck_assert_msg(check_msg->time.wn == 2222,
                  "incorrect value for time.wn, expected 2222, is %d",
                  check_msg->time.wn);
    ck_assert_msg(check_msg->update_interval == 1,
                  "incorrect value for update_interval, expected 1, is %d",
                  check_msg->update_interval);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_ssr_MsgSsrSatelliteApc_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_ssr_MsgSsrSatelliteApc");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_ssr_MsgSsrSatelliteApc");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_ssr_MsgSsrSatelliteApc);
  suite_add_tcase(s, tc_acq);
  return s;
}