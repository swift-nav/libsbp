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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml by generate.py. Do
// not modify by hand!

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

START_TEST(test_auto_check_sbp_piksi_MsgUartState) {
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

    sbp_callback_register(&sbp_state, 0x1d, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  29,  0,   200, 224, 74,  154, 169, 242, 69,  102, 166, 231, 68,
        89,  98,  79,  184, 138, 244, 154, 73,  201, 69,  154, 65,  211, 69,
        201, 16,  103, 249, 143, 161, 154, 17,  186, 69,  51,  211, 7,   69,
        215, 149, 253, 25,  218, 24,  29,  195, 16,  19,  159, 142, 71,  17,
        10,  113, 137, 219, 135, 18,  182, 21,  38,  190, 59,  196, 169, 155,
        107, 111, 253, 168, 244, 158, 112, 19,  251, 131, 100, 225,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.uart_state.latency.avg = 319865629;

    test_msg.uart_state.latency.current = 364253831;

    test_msg.uart_state.latency.lmax = -611749622;

    test_msg.uart_state.latency.lmin = 289902239;

    test_msg.uart_state.obs_period.avg = -1002717658;

    test_msg.uart_state.obs_period.current = -2080697488;

    test_msg.uart_state.obs_period.pmax = -1628133123;

    test_msg.uart_state.obs_period.pmin = 1869323177;

    test_msg.uart_state.uart_a.crc_error_count = 25177;

    test_msg.uart_state.uart_a.io_error_count = 47183;

    test_msg.uart_state.uart_a.rx_buffer_level = 244;

    test_msg.uart_state.uart_a.rx_throughput = 1853.199951171875;

    test_msg.uart_state.uart_a.tx_buffer_level = 138;

    test_msg.uart_state.uart_a.tx_throughput = 7765.2001953125;

    test_msg.uart_state.uart_b.crc_error_count = 4297;

    test_msg.uart_state.uart_b.io_error_count = 63847;

    test_msg.uart_state.uart_b.rx_buffer_level = 161;

    test_msg.uart_state.uart_b.rx_throughput = 6760.2001953125;

    test_msg.uart_state.uart_b.tx_buffer_level = 143;

    test_msg.uart_state.uart_b.tx_throughput = 6441.2001953125;

    test_msg.uart_state.uart_ftdi.crc_error_count = 38359;

    test_msg.uart_state.uart_ftdi.io_error_count = 6653;

    test_msg.uart_state.uart_ftdi.rx_buffer_level = 24;

    test_msg.uart_state.uart_ftdi.rx_throughput = 2173.199951171875;

    test_msg.uart_state.uart_ftdi.tx_buffer_level = 218;

    test_msg.uart_state.uart_ftdi.tx_throughput = 5954.2001953125;

    sbp_message_send(&sbp_state, SbpMsgUartState, 57544, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 57544,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgUartState, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.uart_state.latency.avg == 319865629,
                  "incorrect value for last_msg.msg.uart_state.latency.avg, "
                  "expected 319865629, is %d",
                  last_msg.msg.uart_state.latency.avg);

    ck_assert_msg(
        last_msg.msg.uart_state.latency.current == 364253831,
        "incorrect value for last_msg.msg.uart_state.latency.current, expected "
        "364253831, is %d",
        last_msg.msg.uart_state.latency.current);

    ck_assert_msg(last_msg.msg.uart_state.latency.lmax == -611749622,
                  "incorrect value for last_msg.msg.uart_state.latency.lmax, "
                  "expected -611749622, is %d",
                  last_msg.msg.uart_state.latency.lmax);

    ck_assert_msg(last_msg.msg.uart_state.latency.lmin == 289902239,
                  "incorrect value for last_msg.msg.uart_state.latency.lmin, "
                  "expected 289902239, is %d",
                  last_msg.msg.uart_state.latency.lmin);

    ck_assert_msg(last_msg.msg.uart_state.obs_period.avg == -1002717658,
                  "incorrect value for last_msg.msg.uart_state.obs_period.avg, "
                  "expected -1002717658, is %d",
                  last_msg.msg.uart_state.obs_period.avg);

    ck_assert_msg(
        last_msg.msg.uart_state.obs_period.current == -2080697488,
        "incorrect value for last_msg.msg.uart_state.obs_period.current, "
        "expected -2080697488, is %d",
        last_msg.msg.uart_state.obs_period.current);

    ck_assert_msg(
        last_msg.msg.uart_state.obs_period.pmax == -1628133123,
        "incorrect value for last_msg.msg.uart_state.obs_period.pmax, expected "
        "-1628133123, is %d",
        last_msg.msg.uart_state.obs_period.pmax);

    ck_assert_msg(
        last_msg.msg.uart_state.obs_period.pmin == 1869323177,
        "incorrect value for last_msg.msg.uart_state.obs_period.pmin, expected "
        "1869323177, is %d",
        last_msg.msg.uart_state.obs_period.pmin);

    ck_assert_msg(
        last_msg.msg.uart_state.uart_a.crc_error_count == 25177,
        "incorrect value for last_msg.msg.uart_state.uart_a.crc_error_count, "
        "expected 25177, is %d",
        last_msg.msg.uart_state.uart_a.crc_error_count);

    ck_assert_msg(
        last_msg.msg.uart_state.uart_a.io_error_count == 47183,
        "incorrect value for last_msg.msg.uart_state.uart_a.io_error_count, "
        "expected 47183, is %d",
        last_msg.msg.uart_state.uart_a.io_error_count);

    ck_assert_msg(
        last_msg.msg.uart_state.uart_a.rx_buffer_level == 244,
        "incorrect value for last_msg.msg.uart_state.uart_a.rx_buffer_level, "
        "expected 244, is %d",
        last_msg.msg.uart_state.uart_a.rx_buffer_level);

    ck_assert_msg(
        (last_msg.msg.uart_state.uart_a.rx_throughput * 100 -
         1853.19995117 * 100) < 0.05,
        "incorrect value for last_msg.msg.uart_state.uart_a.rx_throughput, "
        "expected 1853.19995117, is %s",
        last_msg.msg.uart_state.uart_a.rx_throughput);

    ck_assert_msg(
        last_msg.msg.uart_state.uart_a.tx_buffer_level == 138,
        "incorrect value for last_msg.msg.uart_state.uart_a.tx_buffer_level, "
        "expected 138, is %d",
        last_msg.msg.uart_state.uart_a.tx_buffer_level);

    ck_assert_msg(
        (last_msg.msg.uart_state.uart_a.tx_throughput * 100 -
         7765.20019531 * 100) < 0.05,
        "incorrect value for last_msg.msg.uart_state.uart_a.tx_throughput, "
        "expected 7765.20019531, is %s",
        last_msg.msg.uart_state.uart_a.tx_throughput);

    ck_assert_msg(
        last_msg.msg.uart_state.uart_b.crc_error_count == 4297,
        "incorrect value for last_msg.msg.uart_state.uart_b.crc_error_count, "
        "expected 4297, is %d",
        last_msg.msg.uart_state.uart_b.crc_error_count);

    ck_assert_msg(
        last_msg.msg.uart_state.uart_b.io_error_count == 63847,
        "incorrect value for last_msg.msg.uart_state.uart_b.io_error_count, "
        "expected 63847, is %d",
        last_msg.msg.uart_state.uart_b.io_error_count);

    ck_assert_msg(
        last_msg.msg.uart_state.uart_b.rx_buffer_level == 161,
        "incorrect value for last_msg.msg.uart_state.uart_b.rx_buffer_level, "
        "expected 161, is %d",
        last_msg.msg.uart_state.uart_b.rx_buffer_level);

    ck_assert_msg(
        (last_msg.msg.uart_state.uart_b.rx_throughput * 100 -
         6760.20019531 * 100) < 0.05,
        "incorrect value for last_msg.msg.uart_state.uart_b.rx_throughput, "
        "expected 6760.20019531, is %s",
        last_msg.msg.uart_state.uart_b.rx_throughput);

    ck_assert_msg(
        last_msg.msg.uart_state.uart_b.tx_buffer_level == 143,
        "incorrect value for last_msg.msg.uart_state.uart_b.tx_buffer_level, "
        "expected 143, is %d",
        last_msg.msg.uart_state.uart_b.tx_buffer_level);

    ck_assert_msg(
        (last_msg.msg.uart_state.uart_b.tx_throughput * 100 -
         6441.20019531 * 100) < 0.05,
        "incorrect value for last_msg.msg.uart_state.uart_b.tx_throughput, "
        "expected 6441.20019531, is %s",
        last_msg.msg.uart_state.uart_b.tx_throughput);

    ck_assert_msg(last_msg.msg.uart_state.uart_ftdi.crc_error_count == 38359,
                  "incorrect value for "
                  "last_msg.msg.uart_state.uart_ftdi.crc_error_count, expected "
                  "38359, is %d",
                  last_msg.msg.uart_state.uart_ftdi.crc_error_count);

    ck_assert_msg(
        last_msg.msg.uart_state.uart_ftdi.io_error_count == 6653,
        "incorrect value for last_msg.msg.uart_state.uart_ftdi.io_error_count, "
        "expected 6653, is %d",
        last_msg.msg.uart_state.uart_ftdi.io_error_count);

    ck_assert_msg(
        last_msg.msg.uart_state.uart_ftdi.rx_buffer_level == 24,
        "incorrect value for "
        "last_msg.msg.uart_state.uart_ftdi.rx_buffer_level, expected 24, is %d",
        last_msg.msg.uart_state.uart_ftdi.rx_buffer_level);

    ck_assert_msg(
        (last_msg.msg.uart_state.uart_ftdi.rx_throughput * 100 -
         2173.19995117 * 100) < 0.05,
        "incorrect value for last_msg.msg.uart_state.uart_ftdi.rx_throughput, "
        "expected 2173.19995117, is %s",
        last_msg.msg.uart_state.uart_ftdi.rx_throughput);

    ck_assert_msg(last_msg.msg.uart_state.uart_ftdi.tx_buffer_level == 218,
                  "incorrect value for "
                  "last_msg.msg.uart_state.uart_ftdi.tx_buffer_level, expected "
                  "218, is %d",
                  last_msg.msg.uart_state.uart_ftdi.tx_buffer_level);

    ck_assert_msg(
        (last_msg.msg.uart_state.uart_ftdi.tx_throughput * 100 -
         5954.20019531 * 100) < 0.05,
        "incorrect value for last_msg.msg.uart_state.uart_ftdi.tx_throughput, "
        "expected 5954.20019531, is %s",
        last_msg.msg.uart_state.uart_ftdi.tx_throughput);
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

    sbp_callback_register(&sbp_state, 0x18, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 24, 0, 246, 215, 58,  26,  191, 93,  63,  0,   0,  0,  0,
        0,  0,  0, 0,   24,  0,   123, 50,  62,  64,  0,   0,  0,  0,
        0,  0,  0, 0,   40,  0,   54,  7,   162, 64,  177, 57, 16, 61,
        0,  0,  0, 0,   81,  1,   255, 255, 255, 255, 0,   0,  0,  0,
        0,  0,  0, 0,   255, 255, 255, 255, 71,  124,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.uart_state_depa.latency.avg = -1;

    test_msg.uart_state_depa.latency.current = -1;

    test_msg.uart_state_depa.latency.lmax = 0;

    test_msg.uart_state_depa.latency.lmin = 0;

    test_msg.uart_state_depa.uart_a.crc_error_count = 0;

    test_msg.uart_state_depa.uart_a.io_error_count = 0;

    test_msg.uart_state_depa.uart_a.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_a.tx_buffer_level = 24;

    test_msg.uart_state_depa.uart_a.tx_throughput = 0.8661972284317017;

    test_msg.uart_state_depa.uart_b.crc_error_count = 0;

    test_msg.uart_state_depa.uart_b.io_error_count = 0;

    test_msg.uart_state_depa.uart_b.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.tx_buffer_level = 40;

    test_msg.uart_state_depa.uart_b.tx_throughput = 2.9718310832977295;

    test_msg.uart_state_depa.uart_ftdi.crc_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.io_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_buffer_level = 1;

    test_msg.uart_state_depa.uart_ftdi.rx_throughput = 0.035211268812417984;

    test_msg.uart_state_depa.uart_ftdi.tx_buffer_level = 81;

    test_msg.uart_state_depa.uart_ftdi.tx_throughput = 5.063380241394043;

    sbp_message_send(&sbp_state, SbpMsgUartStateDepa, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgUartStateDepa, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.uart_state_depa.latency.avg == -1,
        "incorrect value for last_msg.msg.uart_state_depa.latency.avg, "
        "expected -1, is %d",
        last_msg.msg.uart_state_depa.latency.avg);

    ck_assert_msg(
        last_msg.msg.uart_state_depa.latency.current == -1,
        "incorrect value for last_msg.msg.uart_state_depa.latency.current, "
        "expected -1, is %d",
        last_msg.msg.uart_state_depa.latency.current);

    ck_assert_msg(
        last_msg.msg.uart_state_depa.latency.lmax == 0,
        "incorrect value for last_msg.msg.uart_state_depa.latency.lmax, "
        "expected 0, is %d",
        last_msg.msg.uart_state_depa.latency.lmax);

    ck_assert_msg(
        last_msg.msg.uart_state_depa.latency.lmin == 0,
        "incorrect value for last_msg.msg.uart_state_depa.latency.lmin, "
        "expected 0, is %d",
        last_msg.msg.uart_state_depa.latency.lmin);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_a.crc_error_count == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_a.crc_error_count, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_a.crc_error_count);

    ck_assert_msg(
        last_msg.msg.uart_state_depa.uart_a.io_error_count == 0,
        "incorrect value for "
        "last_msg.msg.uart_state_depa.uart_a.io_error_count, expected 0, is %d",
        last_msg.msg.uart_state_depa.uart_a.io_error_count);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_a.rx_buffer_level == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_a.rx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_a.rx_throughput * 100 -
                   0.0 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_a.rx_throughput, expected "
                  "0.0, is %s",
                  last_msg.msg.uart_state_depa.uart_a.rx_throughput);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_a.tx_buffer_level == 24,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, "
                  "expected 24, is %d",
                  last_msg.msg.uart_state_depa.uart_a.tx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_a.tx_throughput * 100 -
                   0.866197228432 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_a.tx_throughput, expected "
                  "0.866197228432, is %s",
                  last_msg.msg.uart_state_depa.uart_a.tx_throughput);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_b.crc_error_count == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_b.crc_error_count, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_b.crc_error_count);

    ck_assert_msg(
        last_msg.msg.uart_state_depa.uart_b.io_error_count == 0,
        "incorrect value for "
        "last_msg.msg.uart_state_depa.uart_b.io_error_count, expected 0, is %d",
        last_msg.msg.uart_state_depa.uart_b.io_error_count);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_b.rx_buffer_level == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_b.rx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_b.rx_throughput * 100 -
                   0.0 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_b.rx_throughput, expected "
                  "0.0, is %s",
                  last_msg.msg.uart_state_depa.uart_b.rx_throughput);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_b.tx_buffer_level == 40,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, "
                  "expected 40, is %d",
                  last_msg.msg.uart_state_depa.uart_b.tx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_b.tx_throughput * 100 -
                   2.9718310833 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_b.tx_throughput, expected "
                  "2.9718310833, is %s",
                  last_msg.msg.uart_state_depa.uart_b.tx_throughput);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_ftdi.io_error_count == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_ftdi.io_error_count);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level == 1,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, "
                  "expected 1, is %d",
                  last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput * 100 -
                   0.0352112688124 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput, "
                  "expected 0.0352112688124, is %s",
                  last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level == 81,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, "
                  "expected 81, is %d",
                  last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput * 100 -
                   5.06338024139 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput, "
                  "expected 5.06338024139, is %s",
                  last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput);
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

    sbp_callback_register(&sbp_state, 0x18, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 24, 0, 246, 215, 58,  237, 232, 95,  63,  0,  0,  0,   0,
        0,  0,  0, 0,   24,  0,   198, 186, 63,  64,  0,  0,  0,   0,
        0,  0,  0, 0,   40,  0,   214, 72,  217, 64,  29, 72, 180, 62,
        0,  0,  0, 0,   85,  1,   255, 255, 255, 255, 0,  0,  0,   0,
        0,  0,  0, 0,   255, 255, 255, 255, 153, 248,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.uart_state_depa.latency.avg = -1;

    test_msg.uart_state_depa.latency.current = -1;

    test_msg.uart_state_depa.latency.lmax = 0;

    test_msg.uart_state_depa.latency.lmin = 0;

    test_msg.uart_state_depa.uart_a.crc_error_count = 0;

    test_msg.uart_state_depa.uart_a.io_error_count = 0;

    test_msg.uart_state_depa.uart_a.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_a.tx_buffer_level = 24;

    test_msg.uart_state_depa.uart_a.tx_throughput = 0.8746479153633118;

    test_msg.uart_state_depa.uart_b.crc_error_count = 0;

    test_msg.uart_state_depa.uart_b.io_error_count = 0;

    test_msg.uart_state_depa.uart_b.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.tx_buffer_level = 40;

    test_msg.uart_state_depa.uart_b.tx_throughput = 2.995774745941162;

    test_msg.uart_state_depa.uart_ftdi.crc_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.io_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_buffer_level = 1;

    test_msg.uart_state_depa.uart_ftdi.rx_throughput = 0.35211268067359924;

    test_msg.uart_state_depa.uart_ftdi.tx_buffer_level = 85;

    test_msg.uart_state_depa.uart_ftdi.tx_throughput = 6.7901411056518555;

    sbp_message_send(&sbp_state, SbpMsgUartStateDepa, 55286, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgUartStateDepa, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.uart_state_depa.latency.avg == -1,
        "incorrect value for last_msg.msg.uart_state_depa.latency.avg, "
        "expected -1, is %d",
        last_msg.msg.uart_state_depa.latency.avg);

    ck_assert_msg(
        last_msg.msg.uart_state_depa.latency.current == -1,
        "incorrect value for last_msg.msg.uart_state_depa.latency.current, "
        "expected -1, is %d",
        last_msg.msg.uart_state_depa.latency.current);

    ck_assert_msg(
        last_msg.msg.uart_state_depa.latency.lmax == 0,
        "incorrect value for last_msg.msg.uart_state_depa.latency.lmax, "
        "expected 0, is %d",
        last_msg.msg.uart_state_depa.latency.lmax);

    ck_assert_msg(
        last_msg.msg.uart_state_depa.latency.lmin == 0,
        "incorrect value for last_msg.msg.uart_state_depa.latency.lmin, "
        "expected 0, is %d",
        last_msg.msg.uart_state_depa.latency.lmin);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_a.crc_error_count == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_a.crc_error_count, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_a.crc_error_count);

    ck_assert_msg(
        last_msg.msg.uart_state_depa.uart_a.io_error_count == 0,
        "incorrect value for "
        "last_msg.msg.uart_state_depa.uart_a.io_error_count, expected 0, is %d",
        last_msg.msg.uart_state_depa.uart_a.io_error_count);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_a.rx_buffer_level == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_a.rx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_a.rx_throughput * 100 -
                   0.0 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_a.rx_throughput, expected "
                  "0.0, is %s",
                  last_msg.msg.uart_state_depa.uart_a.rx_throughput);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_a.tx_buffer_level == 24,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, "
                  "expected 24, is %d",
                  last_msg.msg.uart_state_depa.uart_a.tx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_a.tx_throughput * 100 -
                   0.874647915363 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_a.tx_throughput, expected "
                  "0.874647915363, is %s",
                  last_msg.msg.uart_state_depa.uart_a.tx_throughput);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_b.crc_error_count == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_b.crc_error_count, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_b.crc_error_count);

    ck_assert_msg(
        last_msg.msg.uart_state_depa.uart_b.io_error_count == 0,
        "incorrect value for "
        "last_msg.msg.uart_state_depa.uart_b.io_error_count, expected 0, is %d",
        last_msg.msg.uart_state_depa.uart_b.io_error_count);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_b.rx_buffer_level == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_b.rx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_b.rx_throughput * 100 -
                   0.0 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_b.rx_throughput, expected "
                  "0.0, is %s",
                  last_msg.msg.uart_state_depa.uart_b.rx_throughput);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_b.tx_buffer_level == 40,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, "
                  "expected 40, is %d",
                  last_msg.msg.uart_state_depa.uart_b.tx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_b.tx_throughput * 100 -
                   2.99577474594 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_b.tx_throughput, expected "
                  "2.99577474594, is %s",
                  last_msg.msg.uart_state_depa.uart_b.tx_throughput);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_ftdi.io_error_count == 0,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, "
                  "expected 0, is %d",
                  last_msg.msg.uart_state_depa.uart_ftdi.io_error_count);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level == 1,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, "
                  "expected 1, is %d",
                  last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput * 100 -
                   0.352112680674 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput, "
                  "expected 0.352112680674, is %s",
                  last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput);

    ck_assert_msg(last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level == 85,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, "
                  "expected 85, is %d",
                  last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level);

    ck_assert_msg((last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput * 100 -
                   6.79014110565 * 100) < 0.05,
                  "incorrect value for "
                  "last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput, "
                  "expected 6.79014110565, is %s",
                  last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput);
  }
}
END_TEST

Suite *auto_check_sbp_piksi_MsgUartState_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_piksi_MsgUartState");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_piksi_MsgUartState");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_MsgUartState);
  suite_add_tcase(s, tc_acq);
  return s;
}