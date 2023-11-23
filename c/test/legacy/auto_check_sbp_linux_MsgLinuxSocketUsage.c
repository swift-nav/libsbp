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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSocketUsage.yaml by
// generate.py. Do not modify by hand!

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
#include <libsbp/legacy/linux.h>

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

START_TEST(test_legacy_auto_check_sbp_linux_MsgLinuxSocketUsage) {
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

    sbp_payload_callback_register(&sbp_state, 0x7f05, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x7f05, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  5,   127, 114, 138, 72,  13,  196, 69,  173, 67,  222, 186, 181,
        246, 154, 251, 17,  224, 179, 26,  169, 177, 90,  149, 213, 214, 6,
        126, 64,  120, 185, 84,  131, 200, 111, 32,  141, 217, 209, 52,  14,
        190, 147, 159, 246, 141, 122, 212, 119, 131, 30,  120, 47,  25,  109,
        154, 65,  132, 164, 39,  30,  30,  175, 8,   44,  28,  111, 236, 240,
        176, 74,  159, 129, 154, 153, 162, 229, 130, 154,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_linux_socket_usage_t *test_msg =
        (msg_linux_socket_usage_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->avg_queue_depth = 2907030541;
    test_msg->max_queue_depth = 3048922691;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[0] = 39670;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[1] = 4603;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[2] = 46048;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[3] = 43290;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[4] = 23217;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[5] = 54677;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[6] = 1750;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[7] = 16510;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[8] = 47480;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[9] = 33620;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[10] = 28616;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[11] = 36128;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[12] = 53721;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[13] = 3636;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[14] = 37822;
    if (sizeof(test_msg->socket_state_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_state_counts[0]);
    }
    test_msg->socket_state_counts[15] = 63135;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[0] = 31373;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[1] = 30676;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[2] = 7811;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[3] = 12152;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[4] = 27929;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[5] = 16794;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[6] = 42116;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[7] = 7719;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[8] = 44830;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[9] = 11272;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[10] = 28444;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[11] = 61676;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[12] = 19120;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[13] = 33183;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[14] = 39322;
    if (sizeof(test_msg->socket_type_counts) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->socket_type_counts[0]);
    }
    test_msg->socket_type_counts[15] = 58786;
    sbp_payload_send(&sbp_state, 0x7f05, 35442, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 35442,
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
    ck_assert_msg(last_frame.sender_id == 35442,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x7f05,
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
    msg_linux_socket_usage_t *check_msg =
        (msg_linux_socket_usage_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        check_msg->avg_queue_depth == 2907030541,
        "incorrect value for avg_queue_depth, expected 2907030541, is %d",
        check_msg->avg_queue_depth);
    ck_assert_msg(
        check_msg->max_queue_depth == 3048922691,
        "incorrect value for max_queue_depth, expected 3048922691, is %d",
        check_msg->max_queue_depth);
    ck_assert_msg(
        check_msg->socket_state_counts[0] == 39670,
        "incorrect value for socket_state_counts[0], expected 39670, is %d",
        check_msg->socket_state_counts[0]);
    ck_assert_msg(
        check_msg->socket_state_counts[1] == 4603,
        "incorrect value for socket_state_counts[1], expected 4603, is %d",
        check_msg->socket_state_counts[1]);
    ck_assert_msg(
        check_msg->socket_state_counts[2] == 46048,
        "incorrect value for socket_state_counts[2], expected 46048, is %d",
        check_msg->socket_state_counts[2]);
    ck_assert_msg(
        check_msg->socket_state_counts[3] == 43290,
        "incorrect value for socket_state_counts[3], expected 43290, is %d",
        check_msg->socket_state_counts[3]);
    ck_assert_msg(
        check_msg->socket_state_counts[4] == 23217,
        "incorrect value for socket_state_counts[4], expected 23217, is %d",
        check_msg->socket_state_counts[4]);
    ck_assert_msg(
        check_msg->socket_state_counts[5] == 54677,
        "incorrect value for socket_state_counts[5], expected 54677, is %d",
        check_msg->socket_state_counts[5]);
    ck_assert_msg(
        check_msg->socket_state_counts[6] == 1750,
        "incorrect value for socket_state_counts[6], expected 1750, is %d",
        check_msg->socket_state_counts[6]);
    ck_assert_msg(
        check_msg->socket_state_counts[7] == 16510,
        "incorrect value for socket_state_counts[7], expected 16510, is %d",
        check_msg->socket_state_counts[7]);
    ck_assert_msg(
        check_msg->socket_state_counts[8] == 47480,
        "incorrect value for socket_state_counts[8], expected 47480, is %d",
        check_msg->socket_state_counts[8]);
    ck_assert_msg(
        check_msg->socket_state_counts[9] == 33620,
        "incorrect value for socket_state_counts[9], expected 33620, is %d",
        check_msg->socket_state_counts[9]);
    ck_assert_msg(
        check_msg->socket_state_counts[10] == 28616,
        "incorrect value for socket_state_counts[10], expected 28616, is %d",
        check_msg->socket_state_counts[10]);
    ck_assert_msg(
        check_msg->socket_state_counts[11] == 36128,
        "incorrect value for socket_state_counts[11], expected 36128, is %d",
        check_msg->socket_state_counts[11]);
    ck_assert_msg(
        check_msg->socket_state_counts[12] == 53721,
        "incorrect value for socket_state_counts[12], expected 53721, is %d",
        check_msg->socket_state_counts[12]);
    ck_assert_msg(
        check_msg->socket_state_counts[13] == 3636,
        "incorrect value for socket_state_counts[13], expected 3636, is %d",
        check_msg->socket_state_counts[13]);
    ck_assert_msg(
        check_msg->socket_state_counts[14] == 37822,
        "incorrect value for socket_state_counts[14], expected 37822, is %d",
        check_msg->socket_state_counts[14]);
    ck_assert_msg(
        check_msg->socket_state_counts[15] == 63135,
        "incorrect value for socket_state_counts[15], expected 63135, is %d",
        check_msg->socket_state_counts[15]);
    ck_assert_msg(
        check_msg->socket_type_counts[0] == 31373,
        "incorrect value for socket_type_counts[0], expected 31373, is %d",
        check_msg->socket_type_counts[0]);
    ck_assert_msg(
        check_msg->socket_type_counts[1] == 30676,
        "incorrect value for socket_type_counts[1], expected 30676, is %d",
        check_msg->socket_type_counts[1]);
    ck_assert_msg(
        check_msg->socket_type_counts[2] == 7811,
        "incorrect value for socket_type_counts[2], expected 7811, is %d",
        check_msg->socket_type_counts[2]);
    ck_assert_msg(
        check_msg->socket_type_counts[3] == 12152,
        "incorrect value for socket_type_counts[3], expected 12152, is %d",
        check_msg->socket_type_counts[3]);
    ck_assert_msg(
        check_msg->socket_type_counts[4] == 27929,
        "incorrect value for socket_type_counts[4], expected 27929, is %d",
        check_msg->socket_type_counts[4]);
    ck_assert_msg(
        check_msg->socket_type_counts[5] == 16794,
        "incorrect value for socket_type_counts[5], expected 16794, is %d",
        check_msg->socket_type_counts[5]);
    ck_assert_msg(
        check_msg->socket_type_counts[6] == 42116,
        "incorrect value for socket_type_counts[6], expected 42116, is %d",
        check_msg->socket_type_counts[6]);
    ck_assert_msg(
        check_msg->socket_type_counts[7] == 7719,
        "incorrect value for socket_type_counts[7], expected 7719, is %d",
        check_msg->socket_type_counts[7]);
    ck_assert_msg(
        check_msg->socket_type_counts[8] == 44830,
        "incorrect value for socket_type_counts[8], expected 44830, is %d",
        check_msg->socket_type_counts[8]);
    ck_assert_msg(
        check_msg->socket_type_counts[9] == 11272,
        "incorrect value for socket_type_counts[9], expected 11272, is %d",
        check_msg->socket_type_counts[9]);
    ck_assert_msg(
        check_msg->socket_type_counts[10] == 28444,
        "incorrect value for socket_type_counts[10], expected 28444, is %d",
        check_msg->socket_type_counts[10]);
    ck_assert_msg(
        check_msg->socket_type_counts[11] == 61676,
        "incorrect value for socket_type_counts[11], expected 61676, is %d",
        check_msg->socket_type_counts[11]);
    ck_assert_msg(
        check_msg->socket_type_counts[12] == 19120,
        "incorrect value for socket_type_counts[12], expected 19120, is %d",
        check_msg->socket_type_counts[12]);
    ck_assert_msg(
        check_msg->socket_type_counts[13] == 33183,
        "incorrect value for socket_type_counts[13], expected 33183, is %d",
        check_msg->socket_type_counts[13]);
    ck_assert_msg(
        check_msg->socket_type_counts[14] == 39322,
        "incorrect value for socket_type_counts[14], expected 39322, is %d",
        check_msg->socket_type_counts[14]);
    ck_assert_msg(
        check_msg->socket_type_counts[15] == 58786,
        "incorrect value for socket_type_counts[15], expected 58786, is %d",
        check_msg->socket_type_counts[15]);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_linux_MsgLinuxSocketUsage_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_linux_MsgLinuxSocketUsage");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_linux_MsgLinuxSocketUsage");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_linux_MsgLinuxSocketUsage);
  suite_add_tcase(s, tc_acq);
  return s;
}