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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkBandwidthUsage.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/piksi.h>
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

START_TEST(test_auto_check_sbp_piksi_MsgNetworkBandwidthUsage) {
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

    sbp_callback_register(&sbp_state, 0xBD, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  189, 0,   207, 121, 200, 94,  105, 178, 128, 0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   99,  97,  110, 48,  0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   94,  105, 178, 128, 0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        99,  97,  110, 49,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   94,  105, 178, 128, 0,   0,   0,   0,   165, 235, 94,  203,
        0,   0,   0,   0,   237, 14,  148, 240, 184, 220, 202, 218, 101, 116,
        104, 48,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        94,  105, 178, 128, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   108, 111, 0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   94,  105,
        178, 128, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   115, 105, 116, 48,  0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   27,  133,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.network_bandwidth_usage.interfaces[0].duration = 2159176030;

    {
      const char assign_string[] = {(char)99, (char)97, (char)110, (char)48,
                                    (char)0,  (char)0,  (char)0,   (char)0,
                                    (char)0,  (char)0,  (char)0,   (char)0,
                                    (char)0,  (char)0,  (char)0,   (char)0};
      memcpy(test_msg.network_bandwidth_usage.interfaces[0].interface_name,
             assign_string, sizeof(assign_string));
    }

    test_msg.network_bandwidth_usage.interfaces[0].rx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[0].total_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[0].tx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[1].duration = 2159176030;

    {
      const char assign_string[] = {(char)99, (char)97, (char)110, (char)49,
                                    (char)0,  (char)0,  (char)0,   (char)0,
                                    (char)0,  (char)0,  (char)0,   (char)0,
                                    (char)0,  (char)0,  (char)0,   (char)0};
      memcpy(test_msg.network_bandwidth_usage.interfaces[1].interface_name,
             assign_string, sizeof(assign_string));
    }

    test_msg.network_bandwidth_usage.interfaces[1].rx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[1].total_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[1].tx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[2].duration = 2159176030;

    {
      const char assign_string[] = {(char)101, (char)116, (char)104, (char)48,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.network_bandwidth_usage.interfaces[2].interface_name,
             assign_string, sizeof(assign_string));
    }

    test_msg.network_bandwidth_usage.interfaces[2].rx_bytes = 4036234989;

    test_msg.network_bandwidth_usage.interfaces[2].total_bytes = 3411995557;

    test_msg.network_bandwidth_usage.interfaces[2].tx_bytes = 3670727864;

    test_msg.network_bandwidth_usage.interfaces[3].duration = 2159176030;

    {
      const char assign_string[] = {(char)108, (char)111, (char)0, (char)0,
                                    (char)0,   (char)0,   (char)0, (char)0,
                                    (char)0,   (char)0,   (char)0, (char)0,
                                    (char)0,   (char)0,   (char)0, (char)0};
      memcpy(test_msg.network_bandwidth_usage.interfaces[3].interface_name,
             assign_string, sizeof(assign_string));
    }

    test_msg.network_bandwidth_usage.interfaces[3].rx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[3].total_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[3].tx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[4].duration = 2159176030;

    {
      const char assign_string[] = {(char)115, (char)105, (char)116, (char)48,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.network_bandwidth_usage.interfaces[4].interface_name,
             assign_string, sizeof(assign_string));
    }

    test_msg.network_bandwidth_usage.interfaces[4].rx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[4].total_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[4].tx_bytes = 0;

    test_msg.network_bandwidth_usage.n_interfaces = 5;

    sbp_message_send(&sbp_state, SbpMsgNetworkBandwidthUsage, 31183, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 31183,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgNetworkBandwidthUsage, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.network_bandwidth_usage.interfaces[0].duration ==
                      2159176030,
                  "incorrect value for "
                  "last_msg.msg.network_bandwidth_usage.interfaces[0].duration,"
                  " expected 2159176030, is %d",
                  last_msg.msg.network_bandwidth_usage.interfaces[0].duration);

    {
      const char check_string[] = {(char)99, (char)97, (char)110, (char)48,
                                   (char)0,  (char)0,  (char)0,   (char)0,
                                   (char)0,  (char)0,  (char)0,   (char)0,
                                   (char)0,  (char)0,  (char)0,   (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.network_bandwidth_usage.interfaces[0]
                      .interface_name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.network_bandwidth_usage.interfaces[0].interface_name, "
          "expected string '%s', is '%s'",
          check_string,
          last_msg.msg.network_bandwidth_usage.interfaces[0].interface_name);
    }

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[0].rx_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[0].rx_bytes, expected "
        "0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[0].rx_bytes);

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[0].total_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[0].total_bytes, "
        "expected 0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[0].total_bytes);

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[0].tx_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[0].tx_bytes, expected "
        "0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[0].tx_bytes);

    ck_assert_msg(last_msg.msg.network_bandwidth_usage.interfaces[1].duration ==
                      2159176030,
                  "incorrect value for "
                  "last_msg.msg.network_bandwidth_usage.interfaces[1].duration,"
                  " expected 2159176030, is %d",
                  last_msg.msg.network_bandwidth_usage.interfaces[1].duration);

    {
      const char check_string[] = {(char)99, (char)97, (char)110, (char)49,
                                   (char)0,  (char)0,  (char)0,   (char)0,
                                   (char)0,  (char)0,  (char)0,   (char)0,
                                   (char)0,  (char)0,  (char)0,   (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.network_bandwidth_usage.interfaces[1]
                      .interface_name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.network_bandwidth_usage.interfaces[1].interface_name, "
          "expected string '%s', is '%s'",
          check_string,
          last_msg.msg.network_bandwidth_usage.interfaces[1].interface_name);
    }

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[1].rx_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[1].rx_bytes, expected "
        "0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[1].rx_bytes);

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[1].total_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[1].total_bytes, "
        "expected 0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[1].total_bytes);

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[1].tx_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[1].tx_bytes, expected "
        "0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[1].tx_bytes);

    ck_assert_msg(last_msg.msg.network_bandwidth_usage.interfaces[2].duration ==
                      2159176030,
                  "incorrect value for "
                  "last_msg.msg.network_bandwidth_usage.interfaces[2].duration,"
                  " expected 2159176030, is %d",
                  last_msg.msg.network_bandwidth_usage.interfaces[2].duration);

    {
      const char check_string[] = {(char)101, (char)116, (char)104, (char)48,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.network_bandwidth_usage.interfaces[2]
                      .interface_name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.network_bandwidth_usage.interfaces[2].interface_name, "
          "expected string '%s', is '%s'",
          check_string,
          last_msg.msg.network_bandwidth_usage.interfaces[2].interface_name);
    }

    ck_assert_msg(last_msg.msg.network_bandwidth_usage.interfaces[2].rx_bytes ==
                      4036234989,
                  "incorrect value for "
                  "last_msg.msg.network_bandwidth_usage.interfaces[2].rx_bytes,"
                  " expected 4036234989, is %d",
                  last_msg.msg.network_bandwidth_usage.interfaces[2].rx_bytes);

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[2].total_bytes ==
            3411995557,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[2].total_bytes, "
        "expected 3411995557, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[2].total_bytes);

    ck_assert_msg(last_msg.msg.network_bandwidth_usage.interfaces[2].tx_bytes ==
                      3670727864,
                  "incorrect value for "
                  "last_msg.msg.network_bandwidth_usage.interfaces[2].tx_bytes,"
                  " expected 3670727864, is %d",
                  last_msg.msg.network_bandwidth_usage.interfaces[2].tx_bytes);

    ck_assert_msg(last_msg.msg.network_bandwidth_usage.interfaces[3].duration ==
                      2159176030,
                  "incorrect value for "
                  "last_msg.msg.network_bandwidth_usage.interfaces[3].duration,"
                  " expected 2159176030, is %d",
                  last_msg.msg.network_bandwidth_usage.interfaces[3].duration);

    {
      const char check_string[] = {(char)108, (char)111, (char)0, (char)0,
                                   (char)0,   (char)0,   (char)0, (char)0,
                                   (char)0,   (char)0,   (char)0, (char)0,
                                   (char)0,   (char)0,   (char)0, (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.network_bandwidth_usage.interfaces[3]
                      .interface_name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.network_bandwidth_usage.interfaces[3].interface_name, "
          "expected string '%s', is '%s'",
          check_string,
          last_msg.msg.network_bandwidth_usage.interfaces[3].interface_name);
    }

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[3].rx_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[3].rx_bytes, expected "
        "0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[3].rx_bytes);

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[3].total_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[3].total_bytes, "
        "expected 0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[3].total_bytes);

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[3].tx_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[3].tx_bytes, expected "
        "0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[3].tx_bytes);

    ck_assert_msg(last_msg.msg.network_bandwidth_usage.interfaces[4].duration ==
                      2159176030,
                  "incorrect value for "
                  "last_msg.msg.network_bandwidth_usage.interfaces[4].duration,"
                  " expected 2159176030, is %d",
                  last_msg.msg.network_bandwidth_usage.interfaces[4].duration);

    {
      const char check_string[] = {(char)115, (char)105, (char)116, (char)48,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.network_bandwidth_usage.interfaces[4]
                      .interface_name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.network_bandwidth_usage.interfaces[4].interface_name, "
          "expected string '%s', is '%s'",
          check_string,
          last_msg.msg.network_bandwidth_usage.interfaces[4].interface_name);
    }

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[4].rx_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[4].rx_bytes, expected "
        "0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[4].rx_bytes);

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[4].total_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[4].total_bytes, "
        "expected 0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[4].total_bytes);

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.interfaces[4].tx_bytes == 0,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.interfaces[4].tx_bytes, expected "
        "0, is %d",
        last_msg.msg.network_bandwidth_usage.interfaces[4].tx_bytes);

    ck_assert_msg(
        last_msg.msg.network_bandwidth_usage.n_interfaces == 5,
        "incorrect value for "
        "last_msg.msg.network_bandwidth_usage.n_interfaces, expected 5, is %d",
        last_msg.msg.network_bandwidth_usage.n_interfaces);
  }
}
END_TEST

Suite *auto_check_sbp_piksi_MsgNetworkBandwidthUsage_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_piksi_MsgNetworkBandwidthUsage");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_piksi_MsgNetworkBandwidthUsage");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_MsgNetworkBandwidthUsage);
  suite_add_tcase(s, tc_acq);
  return s;
}