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
#include <libsbp/legacy/piksi.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void* context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void* context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void* last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8* buff, u32 n, void* context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8* buff, u32 n, void* context) {
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

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void* context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void* context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_piksi_MsgUartState) {
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

    sbp_payload_callback_register(&sbp_state, 0x18, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x18, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 24, 0, 246, 215, 58,  26,  191, 93,  63,  0,   0,  0,  0,
        0,  0,  0, 0,   24,  0,   123, 50,  62,  64,  0,   0,  0,  0,
        0,  0,  0, 0,   40,  0,   54,  7,   162, 64,  177, 57, 16, 61,
        0,  0,  0, 0,   81,  1,   255, 255, 255, 255, 0,   0,  0,  0,
        0,  0,  0, 0,   255, 255, 255, 255, 71,  124,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_uart_state_depa_t* test_msg = (msg_uart_state_depa_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
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
    sbp_payload_send(&sbp_state, 0x18, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x18,
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
    msg_uart_state_depa_t* check_msg =
        (msg_uart_state_depa_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
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

    sbp_payload_callback_register(&sbp_state, 0x18, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x18, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 24, 0, 246, 215, 58,  237, 232, 95,  63,  0,  0,  0,   0,
        0,  0,  0, 0,   24,  0,   198, 186, 63,  64,  0,  0,  0,   0,
        0,  0,  0, 0,   40,  0,   214, 72,  217, 64,  29, 72, 180, 62,
        0,  0,  0, 0,   85,  1,   255, 255, 255, 255, 0,  0,  0,   0,
        0,  0,  0, 0,   255, 255, 255, 255, 153, 248,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_uart_state_depa_t* test_msg = (msg_uart_state_depa_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
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
    sbp_payload_send(&sbp_state, 0x18, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 55286,
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
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x18,
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
    msg_uart_state_depa_t* check_msg =
        (msg_uart_state_depa_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
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

Suite* legacy_auto_check_sbp_piksi_MsgUartState_suite(void) {
  Suite* s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_piksi_MsgUartState");
  TCase* tc_acq =
      tcase_create("Automated_Suite_legacy_auto_check_sbp_piksi_MsgUartState");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_piksi_MsgUartState);
  suite_add_tcase(s, tc_acq);
  return s;
}