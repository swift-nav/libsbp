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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml by generate.py. Do
// not modify by hand!

#include <check.h>
#include <piksi.h>
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

START_TEST(test_auto_check_sbp_piksi_32) {
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

    sbp_register_callback(&sbp_state, 0x18, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x18, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x18, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 24, 0, 246, 215, 58,  26,  191, 93,  63,  0,   0,  0,  0,
        0,  0,  0, 0,   24,  0,   123, 50,  62,  64,  0,   0,  0,  0,
        0,  0,  0, 0,   40,  0,   54,  7,   162, 64,  177, 57, 16, 61,
        0,  0,  0, 0,   81,  1,   255, 255, 255, 255, 0,   0,  0,  0,
        0,  0,  0, 0,   255, 255, 255, 255, 71,  124,
    };
    u8 test_encoded_payload_data[] = {
        26,  191, 93,  63, 0,  0,  0, 0, 0, 0,   0,   0,   24,  0,   123,
        50,  62,  64,  0,  0,  0,  0, 0, 0, 0,   0,   40,  0,   54,  7,
        162, 64,  177, 57, 16, 61, 0, 0, 0, 0,   81,  1,   255, 255, 255,
        255, 0,   0,   0,  0,  0,  0, 0, 0, 255, 255, 255, 255,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_uart_state_depa_t *test_msg =
        (sbp_msg_uart_state_depa_t *)&test_msg_storage;
    test_msg->latency.avg = -1;
    test_msg->latency.current = -1;
    test_msg->latency.lmax = 0;
    test_msg->latency.lmin = 0;
    test_msg->uart_a.crc_error_count = 0;
    test_msg->uart_a.io_error_count = 0;
    test_msg->uart_a.rx_buffer_level = 0;
    test_msg->uart_a.rx_throughput = 0.0;
    test_msg->uart_a.tx_buffer_level = 24;
    test_msg->uart_a.tx_throughput = 0.8661972284317017;
    test_msg->uart_b.crc_error_count = 0;
    test_msg->uart_b.io_error_count = 0;
    test_msg->uart_b.rx_buffer_level = 0;
    test_msg->uart_b.rx_throughput = 0.0;
    test_msg->uart_b.tx_buffer_level = 40;
    test_msg->uart_b.tx_throughput = 2.9718310832977295;
    test_msg->uart_ftdi.crc_error_count = 0;
    test_msg->uart_ftdi.io_error_count = 0;
    test_msg->uart_ftdi.rx_buffer_level = 1;
    test_msg->uart_ftdi.rx_throughput = 0.035211268812417984;
    test_msg->uart_ftdi.tx_buffer_level = 81;
    test_msg->uart_ftdi.tx_throughput = 5.063380241394043;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x18, 55286, &test_msg_storage, &dummy_write);

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
    sbp_msg_uart_state_depa_t *check_msg =
        (sbp_msg_uart_state_depa_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 24,
        "incorrect value for uart_a.tx_buffer_level, expected 24, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.866197228432 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.866197228432, is "
        "%f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 40,
        "incorrect value for uart_b.tx_buffer_level, expected 40, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 2.9718310833 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 2.9718310833, is "
        "%f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 1,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.rx_throughput * 100 -
                   0.0352112688124 * 100) < 0.05,
                  "incorrect value for uart_ftdi.rx_throughput, expected "
                  "0.0352112688124, is %f",
                  check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 81,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 81, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.tx_throughput * 100 - 5.06338024139 * 100) < 0.05,
        "incorrect value for uart_ftdi.tx_throughput, expected 5.06338024139, "
        "is %f",
        check_msg->uart_ftdi.tx_throughput);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x18, 55286,
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
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 24,
        "incorrect value for uart_a.tx_buffer_level, expected 24, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.866197228432 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.866197228432, is "
        "%f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 40,
        "incorrect value for uart_b.tx_buffer_level, expected 40, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 2.9718310833 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 2.9718310833, is "
        "%f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 1,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.rx_throughput * 100 -
                   0.0352112688124 * 100) < 0.05,
                  "incorrect value for uart_ftdi.rx_throughput, expected "
                  "0.0352112688124, is %f",
                  check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 81,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 81, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.tx_throughput * 100 - 5.06338024139 * 100) < 0.05,
        "incorrect value for uart_ftdi.tx_throughput, expected 5.06338024139, "
        "is %f",
        check_msg->uart_ftdi.tx_throughput);
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

    sbp_register_callback(&sbp_state, 0x18, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x18, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x18, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85, 24, 0, 246, 215, 58,  237, 232, 95,  63,  0,  0,  0,   0,
        0,  0,  0, 0,   24,  0,   198, 186, 63,  64,  0,  0,  0,   0,
        0,  0,  0, 0,   40,  0,   214, 72,  217, 64,  29, 72, 180, 62,
        0,  0,  0, 0,   85,  1,   255, 255, 255, 255, 0,  0,  0,   0,
        0,  0,  0, 0,   255, 255, 255, 255, 153, 248,
    };
    u8 test_encoded_payload_data[] = {
        237, 232, 95, 63, 0,   0,  0, 0, 0, 0,   0,   0,   24,  0,   198,
        186, 63,  64, 0,  0,   0,  0, 0, 0, 0,   0,   40,  0,   214, 72,
        217, 64,  29, 72, 180, 62, 0, 0, 0, 0,   85,  1,   255, 255, 255,
        255, 0,   0,  0,  0,   0,  0, 0, 0, 255, 255, 255, 255,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_uart_state_depa_t *test_msg =
        (sbp_msg_uart_state_depa_t *)&test_msg_storage;
    test_msg->latency.avg = -1;
    test_msg->latency.current = -1;
    test_msg->latency.lmax = 0;
    test_msg->latency.lmin = 0;
    test_msg->uart_a.crc_error_count = 0;
    test_msg->uart_a.io_error_count = 0;
    test_msg->uart_a.rx_buffer_level = 0;
    test_msg->uart_a.rx_throughput = 0.0;
    test_msg->uart_a.tx_buffer_level = 24;
    test_msg->uart_a.tx_throughput = 0.8746479153633118;
    test_msg->uart_b.crc_error_count = 0;
    test_msg->uart_b.io_error_count = 0;
    test_msg->uart_b.rx_buffer_level = 0;
    test_msg->uart_b.rx_throughput = 0.0;
    test_msg->uart_b.tx_buffer_level = 40;
    test_msg->uart_b.tx_throughput = 2.995774745941162;
    test_msg->uart_ftdi.crc_error_count = 0;
    test_msg->uart_ftdi.io_error_count = 0;
    test_msg->uart_ftdi.rx_buffer_level = 1;
    test_msg->uart_ftdi.rx_throughput = 0.35211268067359924;
    test_msg->uart_ftdi.tx_buffer_level = 85;
    test_msg->uart_ftdi.tx_throughput = 6.7901411056518555;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x18, 55286, &test_msg_storage, &dummy_write);

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
    sbp_msg_uart_state_depa_t *check_msg =
        (sbp_msg_uart_state_depa_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 24,
        "incorrect value for uart_a.tx_buffer_level, expected 24, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.874647915363 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.874647915363, is "
        "%f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 40,
        "incorrect value for uart_b.tx_buffer_level, expected 40, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 2.99577474594 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 2.99577474594, is "
        "%f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 1,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.rx_throughput * 100 -
                   0.352112680674 * 100) < 0.05,
                  "incorrect value for uart_ftdi.rx_throughput, expected "
                  "0.352112680674, is %f",
                  check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 85,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 85, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.tx_throughput * 100 - 6.79014110565 * 100) < 0.05,
        "incorrect value for uart_ftdi.tx_throughput, expected 6.79014110565, "
        "is %f",
        check_msg->uart_ftdi.tx_throughput);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x18, 55286,
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
    ck_assert_msg(check_msg->latency.avg == -1,
                  "incorrect value for latency.avg, expected -1, is %d",
                  check_msg->latency.avg);
    ck_assert_msg(check_msg->latency.current == -1,
                  "incorrect value for latency.current, expected -1, is %d",
                  check_msg->latency.current);
    ck_assert_msg(check_msg->latency.lmax == 0,
                  "incorrect value for latency.lmax, expected 0, is %d",
                  check_msg->latency.lmax);
    ck_assert_msg(check_msg->latency.lmin == 0,
                  "incorrect value for latency.lmin, expected 0, is %d",
                  check_msg->latency.lmin);
    ck_assert_msg(
        check_msg->uart_a.crc_error_count == 0,
        "incorrect value for uart_a.crc_error_count, expected 0, is %d",
        check_msg->uart_a.crc_error_count);
    ck_assert_msg(
        check_msg->uart_a.io_error_count == 0,
        "incorrect value for uart_a.io_error_count, expected 0, is %d",
        check_msg->uart_a.io_error_count);
    ck_assert_msg(
        check_msg->uart_a.rx_buffer_level == 0,
        "incorrect value for uart_a.rx_buffer_level, expected 0, is %d",
        check_msg->uart_a.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_a.rx_throughput, expected 0.0, is %f",
        check_msg->uart_a.rx_throughput);
    ck_assert_msg(
        check_msg->uart_a.tx_buffer_level == 24,
        "incorrect value for uart_a.tx_buffer_level, expected 24, is %d",
        check_msg->uart_a.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_a.tx_throughput * 100 - 0.874647915363 * 100) < 0.05,
        "incorrect value for uart_a.tx_throughput, expected 0.874647915363, is "
        "%f",
        check_msg->uart_a.tx_throughput);
    ck_assert_msg(
        check_msg->uart_b.crc_error_count == 0,
        "incorrect value for uart_b.crc_error_count, expected 0, is %d",
        check_msg->uart_b.crc_error_count);
    ck_assert_msg(
        check_msg->uart_b.io_error_count == 0,
        "incorrect value for uart_b.io_error_count, expected 0, is %d",
        check_msg->uart_b.io_error_count);
    ck_assert_msg(
        check_msg->uart_b.rx_buffer_level == 0,
        "incorrect value for uart_b.rx_buffer_level, expected 0, is %d",
        check_msg->uart_b.rx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.rx_throughput * 100 - 0.0 * 100) < 0.05,
        "incorrect value for uart_b.rx_throughput, expected 0.0, is %f",
        check_msg->uart_b.rx_throughput);
    ck_assert_msg(
        check_msg->uart_b.tx_buffer_level == 40,
        "incorrect value for uart_b.tx_buffer_level, expected 40, is %d",
        check_msg->uart_b.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_b.tx_throughput * 100 - 2.99577474594 * 100) < 0.05,
        "incorrect value for uart_b.tx_throughput, expected 2.99577474594, is "
        "%f",
        check_msg->uart_b.tx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.crc_error_count == 0,
        "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d",
        check_msg->uart_ftdi.crc_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.io_error_count == 0,
        "incorrect value for uart_ftdi.io_error_count, expected 0, is %d",
        check_msg->uart_ftdi.io_error_count);
    ck_assert_msg(
        check_msg->uart_ftdi.rx_buffer_level == 1,
        "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is %d",
        check_msg->uart_ftdi.rx_buffer_level);
    ck_assert_msg((check_msg->uart_ftdi.rx_throughput * 100 -
                   0.352112680674 * 100) < 0.05,
                  "incorrect value for uart_ftdi.rx_throughput, expected "
                  "0.352112680674, is %f",
                  check_msg->uart_ftdi.rx_throughput);
    ck_assert_msg(
        check_msg->uart_ftdi.tx_buffer_level == 85,
        "incorrect value for uart_ftdi.tx_buffer_level, expected 85, is %d",
        check_msg->uart_ftdi.tx_buffer_level);
    ck_assert_msg(
        (check_msg->uart_ftdi.tx_throughput * 100 - 6.79014110565 * 100) < 0.05,
        "incorrect value for uart_ftdi.tx_throughput, expected 6.79014110565, "
        "is %f",
        check_msg->uart_ftdi.tx_throughput);
  }
}
END_TEST

Suite *auto_check_sbp_piksi_32_suite(void) {
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_piksi_32");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_piksi_32");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_32);
  suite_add_tcase(s, tc_acq);
  return s;
}