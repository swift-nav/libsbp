/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <sbp.h>
#include <piksi.h>

static u32 n_callbacks_logged;
static u16 last_sender_id;
static u8 last_len;
static u8 last_msg[256];
static void* last_context;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void* last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset()
{
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static u32 dummy_write(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(dummy_buff + dummy_wr, buff, real_n);
 dummy_wr += real_n;
 return real_n;
}

static u32 dummy_read(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(buff, dummy_buff + dummy_rd, real_n);
 dummy_rd += real_n;
 return real_n;
}

static void logging_reset()
{
  n_callbacks_logged = 0;
  last_context = 0;
  memset(last_msg, 0, sizeof(last_msg));
}

static void logging_callback(u16 sender_id, u8 len, u8 msg[], void* context)
{
  n_callbacks_logged++;
  last_sender_id = sender_id;
  last_len = len;
  last_context = context;
  memcpy(last_msg, msg, len);

  /*printy_callback(sender_id, len, msg);*/
}

START_TEST( test_auto_check_sbp_piksi_14 )
{
  static sbp_msg_callbacks_node_t n;
  //static sbp_msg_callbacks_node_t n2;

  // State of the SBP message parser.
  // Must be statically allocated.
  sbp_state_t sbp_state;

  //
  // Run tests:
  //
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x18, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,24,0,246,215,58,26,191,93,63,0,0,0,0,0,0,0,0,24,0,123,50,62,64,0,0,0,0,0,0,0,0,40,0,54,7,162,64,177,57,16,61,0,0,0,0,81,1,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,71,124, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x18, 55286, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 55286,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_uart_state_depa_t* msg = ( msg_uart_state_depa_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->latency.current == -1, "incorrect value for latency.current, expected -1, is %d", msg->latency.current);
    fail_unless(msg->latency.lmax == 0, "incorrect value for latency.lmax, expected 0, is %d", msg->latency.lmax);
    fail_unless(msg->latency.avg == -1, "incorrect value for latency.avg, expected -1, is %d", msg->latency.avg);
    fail_unless(msg->latency.lmin == 0, "incorrect value for latency.lmin, expected 0, is %d", msg->latency.lmin);
    fail_unless((msg->uart_b.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_b.rx_throughput, expected 0.0, is %f", msg->uart_b.rx_throughput);
    fail_unless(msg->uart_b.crc_error_count == 0, "incorrect value for uart_b.crc_error_count, expected 0, is %d", msg->uart_b.crc_error_count);
    fail_unless(msg->uart_b.io_error_count == 0, "incorrect value for uart_b.io_error_count, expected 0, is %d", msg->uart_b.io_error_count);
    fail_unless(msg->uart_b.rx_buffer_level == 0, "incorrect value for uart_b.rx_buffer_level, expected 0, is %d", msg->uart_b.rx_buffer_level);
    fail_unless((msg->uart_b.tx_throughput*100 - 2.9718310833*100) < 0.05, "incorrect value for uart_b.tx_throughput, expected 2.9718310833, is %f", msg->uart_b.tx_throughput);
    fail_unless(msg->uart_b.tx_buffer_level == 40, "incorrect value for uart_b.tx_buffer_level, expected 40, is %d", msg->uart_b.tx_buffer_level);
    fail_unless((msg->uart_a.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.rx_throughput, expected 0.0, is %f", msg->uart_a.rx_throughput);
    fail_unless(msg->uart_a.crc_error_count == 0, "incorrect value for uart_a.crc_error_count, expected 0, is %d", msg->uart_a.crc_error_count);
    fail_unless(msg->uart_a.io_error_count == 0, "incorrect value for uart_a.io_error_count, expected 0, is %d", msg->uart_a.io_error_count);
    fail_unless(msg->uart_a.rx_buffer_level == 0, "incorrect value for uart_a.rx_buffer_level, expected 0, is %d", msg->uart_a.rx_buffer_level);
    fail_unless((msg->uart_a.tx_throughput*100 - 0.866197228432*100) < 0.05, "incorrect value for uart_a.tx_throughput, expected 0.866197228432, is %f", msg->uart_a.tx_throughput);
    fail_unless(msg->uart_a.tx_buffer_level == 24, "incorrect value for uart_a.tx_buffer_level, expected 24, is %d", msg->uart_a.tx_buffer_level);
    fail_unless((msg->uart_ftdi.rx_throughput*100 - 0.0352112688124*100) < 0.05, "incorrect value for uart_ftdi.rx_throughput, expected 0.0352112688124, is %f", msg->uart_ftdi.rx_throughput);
    fail_unless(msg->uart_ftdi.crc_error_count == 0, "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d", msg->uart_ftdi.crc_error_count);
    fail_unless(msg->uart_ftdi.io_error_count == 0, "incorrect value for uart_ftdi.io_error_count, expected 0, is %d", msg->uart_ftdi.io_error_count);
    fail_unless(msg->uart_ftdi.rx_buffer_level == 1, "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is %d", msg->uart_ftdi.rx_buffer_level);
    fail_unless((msg->uart_ftdi.tx_throughput*100 - 5.06338024139*100) < 0.05, "incorrect value for uart_ftdi.tx_throughput, expected 5.06338024139, is %f", msg->uart_ftdi.tx_throughput);
    fail_unless(msg->uart_ftdi.tx_buffer_level == 81, "incorrect value for uart_ftdi.tx_buffer_level, expected 81, is %d", msg->uart_ftdi.tx_buffer_level);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x18, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,24,0,246,215,58,237,232,95,63,0,0,0,0,0,0,0,0,24,0,198,186,63,64,0,0,0,0,0,0,0,0,40,0,214,72,217,64,29,72,180,62,0,0,0,0,85,1,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,153,248, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x18, 55286, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 55286,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_uart_state_depa_t* msg = ( msg_uart_state_depa_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->latency.current == -1, "incorrect value for latency.current, expected -1, is %d", msg->latency.current);
    fail_unless(msg->latency.lmax == 0, "incorrect value for latency.lmax, expected 0, is %d", msg->latency.lmax);
    fail_unless(msg->latency.avg == -1, "incorrect value for latency.avg, expected -1, is %d", msg->latency.avg);
    fail_unless(msg->latency.lmin == 0, "incorrect value for latency.lmin, expected 0, is %d", msg->latency.lmin);
    fail_unless((msg->uart_b.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_b.rx_throughput, expected 0.0, is %f", msg->uart_b.rx_throughput);
    fail_unless(msg->uart_b.crc_error_count == 0, "incorrect value for uart_b.crc_error_count, expected 0, is %d", msg->uart_b.crc_error_count);
    fail_unless(msg->uart_b.io_error_count == 0, "incorrect value for uart_b.io_error_count, expected 0, is %d", msg->uart_b.io_error_count);
    fail_unless(msg->uart_b.rx_buffer_level == 0, "incorrect value for uart_b.rx_buffer_level, expected 0, is %d", msg->uart_b.rx_buffer_level);
    fail_unless((msg->uart_b.tx_throughput*100 - 2.99577474594*100) < 0.05, "incorrect value for uart_b.tx_throughput, expected 2.99577474594, is %f", msg->uart_b.tx_throughput);
    fail_unless(msg->uart_b.tx_buffer_level == 40, "incorrect value for uart_b.tx_buffer_level, expected 40, is %d", msg->uart_b.tx_buffer_level);
    fail_unless((msg->uart_a.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.rx_throughput, expected 0.0, is %f", msg->uart_a.rx_throughput);
    fail_unless(msg->uart_a.crc_error_count == 0, "incorrect value for uart_a.crc_error_count, expected 0, is %d", msg->uart_a.crc_error_count);
    fail_unless(msg->uart_a.io_error_count == 0, "incorrect value for uart_a.io_error_count, expected 0, is %d", msg->uart_a.io_error_count);
    fail_unless(msg->uart_a.rx_buffer_level == 0, "incorrect value for uart_a.rx_buffer_level, expected 0, is %d", msg->uart_a.rx_buffer_level);
    fail_unless((msg->uart_a.tx_throughput*100 - 0.874647915363*100) < 0.05, "incorrect value for uart_a.tx_throughput, expected 0.874647915363, is %f", msg->uart_a.tx_throughput);
    fail_unless(msg->uart_a.tx_buffer_level == 24, "incorrect value for uart_a.tx_buffer_level, expected 24, is %d", msg->uart_a.tx_buffer_level);
    fail_unless((msg->uart_ftdi.rx_throughput*100 - 0.352112680674*100) < 0.05, "incorrect value for uart_ftdi.rx_throughput, expected 0.352112680674, is %f", msg->uart_ftdi.rx_throughput);
    fail_unless(msg->uart_ftdi.crc_error_count == 0, "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d", msg->uart_ftdi.crc_error_count);
    fail_unless(msg->uart_ftdi.io_error_count == 0, "incorrect value for uart_ftdi.io_error_count, expected 0, is %d", msg->uart_ftdi.io_error_count);
    fail_unless(msg->uart_ftdi.rx_buffer_level == 1, "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is %d", msg->uart_ftdi.rx_buffer_level);
    fail_unless((msg->uart_ftdi.tx_throughput*100 - 6.79014110565*100) < 0.05, "incorrect value for uart_ftdi.tx_throughput, expected 6.79014110565, is %f", msg->uart_ftdi.tx_throughput);
    fail_unless(msg->uart_ftdi.tx_buffer_level == 85, "incorrect value for uart_ftdi.tx_buffer_level, expected 85, is %d", msg->uart_ftdi.tx_buffer_level);
  }
}
END_TEST

Suite* auto_check_sbp_piksi_14_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_piksi_14");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_piksi_14");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_14);
  suite_add_tcase(s, tc_acq);
  return s;
}