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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkStateResp.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/piksi.h>
#include <libsbp/sbp.h>
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

START_TEST(test_auto_check_sbp_piksi_MsgNetworkStateResp) {
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

    sbp_callback_register(&sbp_state, 0xbb, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  187, 0,  40,  15,  50,  143, 241, 84,  180, 152, 194,
        137, 32,  44, 114, 147, 68,  222, 92,  192, 78,  235, 63,
        208, 114, 53, 183, 24,  244, 231, 26,  105, 25,  136, 3,
        105, 102, 48, 0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,  0,   195, 229, 80,  147, 118, 193,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.network_state_resp.flags = 2471552451;

    {
      const char assign_string[] = {(char)105, (char)102, (char)48, (char)0,
                                    (char)0,   (char)0,   (char)0,  (char)0,
                                    (char)0,   (char)0,   (char)0,  (char)0,
                                    (char)0,   (char)0,   (char)0,  (char)0};
      memcpy(test_msg.network_state_resp.interface_name, assign_string,
             sizeof(assign_string));
    }

    test_msg.network_state_resp.ipv4_address[0] = 143;

    test_msg.network_state_resp.ipv4_address[1] = 241;

    test_msg.network_state_resp.ipv4_address[2] = 84;

    test_msg.network_state_resp.ipv4_address[3] = 180;

    test_msg.network_state_resp.ipv4_mask_size = 152;

    test_msg.network_state_resp.ipv6_address[0] = 194;

    test_msg.network_state_resp.ipv6_address[1] = 137;

    test_msg.network_state_resp.ipv6_address[2] = 32;

    test_msg.network_state_resp.ipv6_address[3] = 44;

    test_msg.network_state_resp.ipv6_address[4] = 114;

    test_msg.network_state_resp.ipv6_address[5] = 147;

    test_msg.network_state_resp.ipv6_address[6] = 68;

    test_msg.network_state_resp.ipv6_address[7] = 222;

    test_msg.network_state_resp.ipv6_address[8] = 92;

    test_msg.network_state_resp.ipv6_address[9] = 192;

    test_msg.network_state_resp.ipv6_address[10] = 78;

    test_msg.network_state_resp.ipv6_address[11] = 235;

    test_msg.network_state_resp.ipv6_address[12] = 63;

    test_msg.network_state_resp.ipv6_address[13] = 208;

    test_msg.network_state_resp.ipv6_address[14] = 114;

    test_msg.network_state_resp.ipv6_address[15] = 53;

    test_msg.network_state_resp.ipv6_mask_size = 183;

    test_msg.network_state_resp.rx_bytes = 451408920;

    test_msg.network_state_resp.tx_bytes = 59251049;

    sbp_message_send(&sbp_state, SbpMsgNetworkStateResp, 3880, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 3880,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgNetworkStateResp, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.network_state_resp.flags == 2471552451,
                  "incorrect value for last_msg.msg.network_state_resp.flags, "
                  "expected 2471552451, is %d",
                  last_msg.msg.network_state_resp.flags);

    {
      const char check_string[] = {(char)105, (char)102, (char)48, (char)0,
                                   (char)0,   (char)0,   (char)0,  (char)0,
                                   (char)0,   (char)0,   (char)0,  (char)0,
                                   (char)0,   (char)0,   (char)0,  (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.network_state_resp.interface_name, check_string,
                 sizeof(check_string)) == 0,
          "incorrect value for last_msg.msg.network_state_resp.interface_name, "
          "expected string '%s', is '%s'",
          check_string, last_msg.msg.network_state_resp.interface_name);
    }

    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv4_address[0] == 143,
        "incorrect value for last_msg.msg.network_state_resp.ipv4_address[0], "
        "expected 143, is %d",
        last_msg.msg.network_state_resp.ipv4_address[0]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv4_address[1] == 241,
        "incorrect value for last_msg.msg.network_state_resp.ipv4_address[1], "
        "expected 241, is %d",
        last_msg.msg.network_state_resp.ipv4_address[1]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv4_address[2] == 84,
        "incorrect value for last_msg.msg.network_state_resp.ipv4_address[2], "
        "expected 84, is %d",
        last_msg.msg.network_state_resp.ipv4_address[2]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv4_address[3] == 180,
        "incorrect value for last_msg.msg.network_state_resp.ipv4_address[3], "
        "expected 180, is %d",
        last_msg.msg.network_state_resp.ipv4_address[3]);

    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv4_mask_size == 152,
        "incorrect value for last_msg.msg.network_state_resp.ipv4_mask_size, "
        "expected 152, is %d",
        last_msg.msg.network_state_resp.ipv4_mask_size);

    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[0] == 194,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[0], "
        "expected 194, is %d",
        last_msg.msg.network_state_resp.ipv6_address[0]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[1] == 137,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[1], "
        "expected 137, is %d",
        last_msg.msg.network_state_resp.ipv6_address[1]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[2] == 32,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[2], "
        "expected 32, is %d",
        last_msg.msg.network_state_resp.ipv6_address[2]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[3] == 44,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[3], "
        "expected 44, is %d",
        last_msg.msg.network_state_resp.ipv6_address[3]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[4] == 114,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[4], "
        "expected 114, is %d",
        last_msg.msg.network_state_resp.ipv6_address[4]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[5] == 147,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[5], "
        "expected 147, is %d",
        last_msg.msg.network_state_resp.ipv6_address[5]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[6] == 68,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[6], "
        "expected 68, is %d",
        last_msg.msg.network_state_resp.ipv6_address[6]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[7] == 222,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[7], "
        "expected 222, is %d",
        last_msg.msg.network_state_resp.ipv6_address[7]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[8] == 92,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[8], "
        "expected 92, is %d",
        last_msg.msg.network_state_resp.ipv6_address[8]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[9] == 192,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[9], "
        "expected 192, is %d",
        last_msg.msg.network_state_resp.ipv6_address[9]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[10] == 78,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[10], "
        "expected 78, is %d",
        last_msg.msg.network_state_resp.ipv6_address[10]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[11] == 235,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[11], "
        "expected 235, is %d",
        last_msg.msg.network_state_resp.ipv6_address[11]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[12] == 63,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[12], "
        "expected 63, is %d",
        last_msg.msg.network_state_resp.ipv6_address[12]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[13] == 208,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[13], "
        "expected 208, is %d",
        last_msg.msg.network_state_resp.ipv6_address[13]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[14] == 114,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[14], "
        "expected 114, is %d",
        last_msg.msg.network_state_resp.ipv6_address[14]);
    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_address[15] == 53,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_address[15], "
        "expected 53, is %d",
        last_msg.msg.network_state_resp.ipv6_address[15]);

    ck_assert_msg(
        last_msg.msg.network_state_resp.ipv6_mask_size == 183,
        "incorrect value for last_msg.msg.network_state_resp.ipv6_mask_size, "
        "expected 183, is %d",
        last_msg.msg.network_state_resp.ipv6_mask_size);

    ck_assert_msg(
        last_msg.msg.network_state_resp.rx_bytes == 451408920,
        "incorrect value for last_msg.msg.network_state_resp.rx_bytes, "
        "expected 451408920, is %d",
        last_msg.msg.network_state_resp.rx_bytes);

    ck_assert_msg(
        last_msg.msg.network_state_resp.tx_bytes == 59251049,
        "incorrect value for last_msg.msg.network_state_resp.tx_bytes, "
        "expected 59251049, is %d",
        last_msg.msg.network_state_resp.tx_bytes);
  }
}
END_TEST

Suite *auto_check_sbp_piksi_MsgNetworkStateResp_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_piksi_MsgNetworkStateResp");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_piksi_MsgNetworkStateResp");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_MsgNetworkStateResp);
  suite_add_tcase(s, tc_acq);
  return s;
}