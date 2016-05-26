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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_piksi.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_piksi_24 )
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

    sbp_register_callback(&sbp_state, 0x17, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,23,0,195,4,26,109,97,105,110,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,148,9,0,0,195,212, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 2452, "incorrect value for stack_free, expected 2452, is %d", msg->stack_free);
    fail_unless(msg->cpu == 0, "incorrect value for cpu, expected 0, is %d", msg->cpu);
    fail_unless(strstr(msg->name, ((char []){(char)109,(char)97,(char)105,(char)110,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0})) != NULL, "incorrect value for msg->name, expected string '%s', is '%s'", ((char []){(char)109,(char)97,(char)105,(char)110,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0}), msg->name);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x17, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,23,0,195,4,26,105,100,108,101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,228,1,36,0,0,0,225,18, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 36, "incorrect value for stack_free, expected 36, is %d", msg->stack_free);
    fail_unless(msg->cpu == 484, "incorrect value for cpu, expected 484, is %d", msg->cpu);
    fail_unless(strstr(msg->name, ((char []){(char)105,(char)100,(char)108,(char)101,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0})) != NULL, "incorrect value for msg->name, expected string '%s', is '%s'", ((char []){(char)105,(char)100,(char)108,(char)101,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0}), msg->name);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x17, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,23,0,195,4,26,78,65,80,32,73,83,82,0,0,0,0,0,0,0,0,0,0,0,0,0,138,1,92,7,0,0,166,116, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 1884, "incorrect value for stack_free, expected 1884, is %d", msg->stack_free);
    fail_unless(msg->cpu == 394, "incorrect value for cpu, expected 394, is %d", msg->cpu);
    fail_unless(strstr(msg->name, ((char []){(char)78,(char)65,(char)80,(char)32,(char)73,(char)83,(char)82,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0})) != NULL, "incorrect value for msg->name, expected string '%s', is '%s'", ((char []){(char)78,(char)65,(char)80,(char)32,(char)73,(char)83,(char)82,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0}), msg->name);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x17, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,23,0,195,4,26,83,66,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,4,12,0,0,229,174, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 3076, "incorrect value for stack_free, expected 3076, is %d", msg->stack_free);
    fail_unless(msg->cpu == 1, "incorrect value for cpu, expected 1, is %d", msg->cpu);
    fail_unless(strstr(msg->name, ((char []){(char)83,(char)66,(char)80,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0})) != NULL, "incorrect value for msg->name, expected string '%s', is '%s'", ((char []){(char)83,(char)66,(char)80,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0}), msg->name);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x17, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,23,0,195,4,26,109,97,110,97,103,101,32,97,99,113,0,0,0,0,0,0,0,0,0,0,10,0,124,9,0,0,52,2, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 2428, "incorrect value for stack_free, expected 2428, is %d", msg->stack_free);
    fail_unless(msg->cpu == 10, "incorrect value for cpu, expected 10, is %d", msg->cpu);
    fail_unless(strstr(msg->name, ((char []){(char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)97,(char)99,(char)113,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0})) != NULL, "incorrect value for msg->name, expected string '%s', is '%s'", ((char []){(char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)97,(char)99,(char)113,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0}), msg->name);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x17, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,23,0,195,4,26,109,97,110,97,103,101,32,116,114,97,99,107,0,0,0,0,0,0,0,0,0,0,28,9,0,0,122,54, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 2332, "incorrect value for stack_free, expected 2332, is %d", msg->stack_free);
    fail_unless(msg->cpu == 0, "incorrect value for cpu, expected 0, is %d", msg->cpu);
    fail_unless(strstr(msg->name, ((char []){(char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)116,(char)114,(char)97,(char)99,(char)107,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0})) != NULL, "incorrect value for msg->name, expected string '%s', is '%s'", ((char []){(char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)116,(char)114,(char)97,(char)99,(char)107,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0}), msg->name);
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

    u8 test_data[] = {85,24,0,195,4,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,154,153,57,65,0,0,0,0,0,0,0,0,15,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,247,5, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x18, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
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
    fail_unless((msg->uart_b.tx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_b.tx_throughput, expected 0.0, is %f", msg->uart_b.tx_throughput);
    fail_unless(msg->uart_b.tx_buffer_level == 0, "incorrect value for uart_b.tx_buffer_level, expected 0, is %d", msg->uart_b.tx_buffer_level);
    fail_unless((msg->uart_a.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.rx_throughput, expected 0.0, is %f", msg->uart_a.rx_throughput);
    fail_unless(msg->uart_a.crc_error_count == 0, "incorrect value for uart_a.crc_error_count, expected 0, is %d", msg->uart_a.crc_error_count);
    fail_unless(msg->uart_a.io_error_count == 0, "incorrect value for uart_a.io_error_count, expected 0, is %d", msg->uart_a.io_error_count);
    fail_unless(msg->uart_a.rx_buffer_level == 0, "incorrect value for uart_a.rx_buffer_level, expected 0, is %d", msg->uart_a.rx_buffer_level);
    fail_unless((msg->uart_a.tx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.tx_throughput, expected 0.0, is %f", msg->uart_a.tx_throughput);
    fail_unless(msg->uart_a.tx_buffer_level == 0, "incorrect value for uart_a.tx_buffer_level, expected 0, is %d", msg->uart_a.tx_buffer_level);
    fail_unless((msg->uart_ftdi.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f", msg->uart_ftdi.rx_throughput);
    fail_unless(msg->uart_ftdi.crc_error_count == 0, "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d", msg->uart_ftdi.crc_error_count);
    fail_unless(msg->uart_ftdi.io_error_count == 0, "incorrect value for uart_ftdi.io_error_count, expected 0, is %d", msg->uart_ftdi.io_error_count);
    fail_unless(msg->uart_ftdi.rx_buffer_level == 0, "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d", msg->uart_ftdi.rx_buffer_level);
    fail_unless((msg->uart_ftdi.tx_throughput*100 - 11.6000003815*100) < 0.05, "incorrect value for uart_ftdi.tx_throughput, expected 11.6000003815, is %f", msg->uart_ftdi.tx_throughput);
    fail_unless(msg->uart_ftdi.tx_buffer_level == 15, "incorrect value for uart_ftdi.tx_buffer_level, expected 15, is %d", msg->uart_ftdi.tx_buffer_level);
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

    u8 test_data[] = {85,24,0,195,4,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,43,135,61,0,0,0,0,0,0,0,0,0,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,65,110, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x18, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
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
    fail_unless((msg->uart_b.tx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_b.tx_throughput, expected 0.0, is %f", msg->uart_b.tx_throughput);
    fail_unless(msg->uart_b.tx_buffer_level == 0, "incorrect value for uart_b.tx_buffer_level, expected 0, is %d", msg->uart_b.tx_buffer_level);
    fail_unless((msg->uart_a.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.rx_throughput, expected 0.0, is %f", msg->uart_a.rx_throughput);
    fail_unless(msg->uart_a.crc_error_count == 0, "incorrect value for uart_a.crc_error_count, expected 0, is %d", msg->uart_a.crc_error_count);
    fail_unless(msg->uart_a.io_error_count == 0, "incorrect value for uart_a.io_error_count, expected 0, is %d", msg->uart_a.io_error_count);
    fail_unless(msg->uart_a.rx_buffer_level == 0, "incorrect value for uart_a.rx_buffer_level, expected 0, is %d", msg->uart_a.rx_buffer_level);
    fail_unless((msg->uart_a.tx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.tx_throughput, expected 0.0, is %f", msg->uart_a.tx_throughput);
    fail_unless(msg->uart_a.tx_buffer_level == 0, "incorrect value for uart_a.tx_buffer_level, expected 0, is %d", msg->uart_a.tx_buffer_level);
    fail_unless((msg->uart_ftdi.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f", msg->uart_ftdi.rx_throughput);
    fail_unless(msg->uart_ftdi.crc_error_count == 0, "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d", msg->uart_ftdi.crc_error_count);
    fail_unless(msg->uart_ftdi.io_error_count == 0, "incorrect value for uart_ftdi.io_error_count, expected 0, is %d", msg->uart_ftdi.io_error_count);
    fail_unless(msg->uart_ftdi.rx_buffer_level == 0, "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d", msg->uart_ftdi.rx_buffer_level);
    fail_unless((msg->uart_ftdi.tx_throughput*100 - 0.0659999996424*100) < 0.05, "incorrect value for uart_ftdi.tx_throughput, expected 0.0659999996424, is %f", msg->uart_ftdi.tx_throughput);
    fail_unless(msg->uart_ftdi.tx_buffer_level == 0, "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is %d", msg->uart_ftdi.tx_buffer_level);
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

    u8 test_data[] = {85,24,0,195,4,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,86,14,62,0,0,0,0,0,0,0,0,10,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,198,36, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x18, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
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
    fail_unless((msg->uart_b.tx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_b.tx_throughput, expected 0.0, is %f", msg->uart_b.tx_throughput);
    fail_unless(msg->uart_b.tx_buffer_level == 0, "incorrect value for uart_b.tx_buffer_level, expected 0, is %d", msg->uart_b.tx_buffer_level);
    fail_unless((msg->uart_a.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.rx_throughput, expected 0.0, is %f", msg->uart_a.rx_throughput);
    fail_unless(msg->uart_a.crc_error_count == 0, "incorrect value for uart_a.crc_error_count, expected 0, is %d", msg->uart_a.crc_error_count);
    fail_unless(msg->uart_a.io_error_count == 0, "incorrect value for uart_a.io_error_count, expected 0, is %d", msg->uart_a.io_error_count);
    fail_unless(msg->uart_a.rx_buffer_level == 0, "incorrect value for uart_a.rx_buffer_level, expected 0, is %d", msg->uart_a.rx_buffer_level);
    fail_unless((msg->uart_a.tx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.tx_throughput, expected 0.0, is %f", msg->uart_a.tx_throughput);
    fail_unless(msg->uart_a.tx_buffer_level == 0, "incorrect value for uart_a.tx_buffer_level, expected 0, is %d", msg->uart_a.tx_buffer_level);
    fail_unless((msg->uart_ftdi.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f", msg->uart_ftdi.rx_throughput);
    fail_unless(msg->uart_ftdi.crc_error_count == 0, "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d", msg->uart_ftdi.crc_error_count);
    fail_unless(msg->uart_ftdi.io_error_count == 0, "incorrect value for uart_ftdi.io_error_count, expected 0, is %d", msg->uart_ftdi.io_error_count);
    fail_unless(msg->uart_ftdi.rx_buffer_level == 0, "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d", msg->uart_ftdi.rx_buffer_level);
    fail_unless((msg->uart_ftdi.tx_throughput*100 - 0.138999998569*100) < 0.05, "incorrect value for uart_ftdi.tx_throughput, expected 0.138999998569, is %f", msg->uart_ftdi.tx_throughput);
    fail_unless(msg->uart_ftdi.tx_buffer_level == 10, "incorrect value for uart_ftdi.tx_buffer_level, expected 10, is %d", msg->uart_ftdi.tx_buffer_level);
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

    u8 test_data[] = {85,24,0,195,4,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,43,135,61,0,0,0,0,0,0,0,0,0,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,65,110, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x18, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
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
    fail_unless((msg->uart_b.tx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_b.tx_throughput, expected 0.0, is %f", msg->uart_b.tx_throughput);
    fail_unless(msg->uart_b.tx_buffer_level == 0, "incorrect value for uart_b.tx_buffer_level, expected 0, is %d", msg->uart_b.tx_buffer_level);
    fail_unless((msg->uart_a.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.rx_throughput, expected 0.0, is %f", msg->uart_a.rx_throughput);
    fail_unless(msg->uart_a.crc_error_count == 0, "incorrect value for uart_a.crc_error_count, expected 0, is %d", msg->uart_a.crc_error_count);
    fail_unless(msg->uart_a.io_error_count == 0, "incorrect value for uart_a.io_error_count, expected 0, is %d", msg->uart_a.io_error_count);
    fail_unless(msg->uart_a.rx_buffer_level == 0, "incorrect value for uart_a.rx_buffer_level, expected 0, is %d", msg->uart_a.rx_buffer_level);
    fail_unless((msg->uart_a.tx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.tx_throughput, expected 0.0, is %f", msg->uart_a.tx_throughput);
    fail_unless(msg->uart_a.tx_buffer_level == 0, "incorrect value for uart_a.tx_buffer_level, expected 0, is %d", msg->uart_a.tx_buffer_level);
    fail_unless((msg->uart_ftdi.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f", msg->uart_ftdi.rx_throughput);
    fail_unless(msg->uart_ftdi.crc_error_count == 0, "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d", msg->uart_ftdi.crc_error_count);
    fail_unless(msg->uart_ftdi.io_error_count == 0, "incorrect value for uart_ftdi.io_error_count, expected 0, is %d", msg->uart_ftdi.io_error_count);
    fail_unless(msg->uart_ftdi.rx_buffer_level == 0, "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d", msg->uart_ftdi.rx_buffer_level);
    fail_unless((msg->uart_ftdi.tx_throughput*100 - 0.0659999996424*100) < 0.05, "incorrect value for uart_ftdi.tx_throughput, expected 0.0659999996424, is %f", msg->uart_ftdi.tx_throughput);
    fail_unless(msg->uart_ftdi.tx_buffer_level == 0, "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is %d", msg->uart_ftdi.tx_buffer_level);
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

    u8 test_data[] = {85,24,0,195,4,58,0,0,0,0,138,75,6,60,0,0,0,0,0,0,80,113,201,61,0,0,0,0,0,0,0,0,2,0,145,237,252,62,0,0,0,0,0,0,0,0,38,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,112,111, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x18, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
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
    fail_unless((msg->uart_b.tx_throughput*100 - 0.098360657692*100) < 0.05, "incorrect value for uart_b.tx_throughput, expected 0.098360657692, is %f", msg->uart_b.tx_throughput);
    fail_unless(msg->uart_b.tx_buffer_level == 2, "incorrect value for uart_b.tx_buffer_level, expected 2, is %d", msg->uart_b.tx_buffer_level);
    fail_unless((msg->uart_a.rx_throughput*100 - 0.00819672085345*100) < 0.05, "incorrect value for uart_a.rx_throughput, expected 0.00819672085345, is %f", msg->uart_a.rx_throughput);
    fail_unless(msg->uart_a.crc_error_count == 0, "incorrect value for uart_a.crc_error_count, expected 0, is %d", msg->uart_a.crc_error_count);
    fail_unless(msg->uart_a.io_error_count == 0, "incorrect value for uart_a.io_error_count, expected 0, is %d", msg->uart_a.io_error_count);
    fail_unless(msg->uart_a.rx_buffer_level == 0, "incorrect value for uart_a.rx_buffer_level, expected 0, is %d", msg->uart_a.rx_buffer_level);
    fail_unless((msg->uart_a.tx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.tx_throughput, expected 0.0, is %f", msg->uart_a.tx_throughput);
    fail_unless(msg->uart_a.tx_buffer_level == 0, "incorrect value for uart_a.tx_buffer_level, expected 0, is %d", msg->uart_a.tx_buffer_level);
    fail_unless((msg->uart_ftdi.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f", msg->uart_ftdi.rx_throughput);
    fail_unless(msg->uart_ftdi.crc_error_count == 0, "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d", msg->uart_ftdi.crc_error_count);
    fail_unless(msg->uart_ftdi.io_error_count == 0, "incorrect value for uart_ftdi.io_error_count, expected 0, is %d", msg->uart_ftdi.io_error_count);
    fail_unless(msg->uart_ftdi.rx_buffer_level == 0, "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d", msg->uart_ftdi.rx_buffer_level);
    fail_unless((msg->uart_ftdi.tx_throughput*100 - 0.493999987841*100) < 0.05, "incorrect value for uart_ftdi.tx_throughput, expected 0.493999987841, is %f", msg->uart_ftdi.tx_throughput);
    fail_unless(msg->uart_ftdi.tx_buffer_level == 38, "incorrect value for uart_ftdi.tx_buffer_level, expected 38, is %d", msg->uart_ftdi.tx_buffer_level);
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

    u8 test_data[] = {85,24,0,195,4,58,166,155,68,60,0,0,0,0,0,0,0,0,2,0,166,155,68,60,0,0,0,0,0,0,0,0,2,0,236,81,168,63,0,0,0,0,0,0,0,0,50,0,255,255,255,255,0,0,0,0,0,0,0,0,255,255,255,255,22,72, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x18, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
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
    fail_unless((msg->uart_b.tx_throughput*100 - 0.0120000001043*100) < 0.05, "incorrect value for uart_b.tx_throughput, expected 0.0120000001043, is %f", msg->uart_b.tx_throughput);
    fail_unless(msg->uart_b.tx_buffer_level == 2, "incorrect value for uart_b.tx_buffer_level, expected 2, is %d", msg->uart_b.tx_buffer_level);
    fail_unless((msg->uart_a.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_a.rx_throughput, expected 0.0, is %f", msg->uart_a.rx_throughput);
    fail_unless(msg->uart_a.crc_error_count == 0, "incorrect value for uart_a.crc_error_count, expected 0, is %d", msg->uart_a.crc_error_count);
    fail_unless(msg->uart_a.io_error_count == 0, "incorrect value for uart_a.io_error_count, expected 0, is %d", msg->uart_a.io_error_count);
    fail_unless(msg->uart_a.rx_buffer_level == 0, "incorrect value for uart_a.rx_buffer_level, expected 0, is %d", msg->uart_a.rx_buffer_level);
    fail_unless((msg->uart_a.tx_throughput*100 - 0.0120000001043*100) < 0.05, "incorrect value for uart_a.tx_throughput, expected 0.0120000001043, is %f", msg->uart_a.tx_throughput);
    fail_unless(msg->uart_a.tx_buffer_level == 2, "incorrect value for uart_a.tx_buffer_level, expected 2, is %d", msg->uart_a.tx_buffer_level);
    fail_unless((msg->uart_ftdi.rx_throughput*100 - 0.0*100) < 0.05, "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is %f", msg->uart_ftdi.rx_throughput);
    fail_unless(msg->uart_ftdi.crc_error_count == 0, "incorrect value for uart_ftdi.crc_error_count, expected 0, is %d", msg->uart_ftdi.crc_error_count);
    fail_unless(msg->uart_ftdi.io_error_count == 0, "incorrect value for uart_ftdi.io_error_count, expected 0, is %d", msg->uart_ftdi.io_error_count);
    fail_unless(msg->uart_ftdi.rx_buffer_level == 0, "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is %d", msg->uart_ftdi.rx_buffer_level);
    fail_unless((msg->uart_ftdi.tx_throughput*100 - 1.31500005722*100) < 0.05, "incorrect value for uart_ftdi.tx_throughput, expected 1.31500005722, is %f", msg->uart_ftdi.tx_throughput);
    fail_unless(msg->uart_ftdi.tx_buffer_level == 50, "incorrect value for uart_ftdi.tx_buffer_level, expected 50, is %d", msg->uart_ftdi.tx_buffer_level);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x19, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,25,0,195,4,4,0,0,0,0,18,176, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x19, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_iar_state_t* msg = ( msg_iar_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->num_hyps == 0, "incorrect value for num_hyps, expected 0, is %d", msg->num_hyps);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x19, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,25,0,195,4,4,1,0,0,0,166,198, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x19, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_iar_state_t* msg = ( msg_iar_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->num_hyps == 1, "incorrect value for num_hyps, expected 1, is %d", msg->num_hyps);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x19, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,25,0,195,4,4,217,2,0,0,6,133, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x19, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_iar_state_t* msg = ( msg_iar_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->num_hyps == 729, "incorrect value for num_hyps, expected 729, is %d", msg->num_hyps);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x19, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,25,0,195,4,4,216,2,0,0,178,243, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x19, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_iar_state_t* msg = ( msg_iar_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->num_hyps == 728, "incorrect value for num_hyps, expected 728, is %d", msg->num_hyps);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x19, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,25,0,195,4,4,215,2,0,0,92,39, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x19, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_iar_state_t* msg = ( msg_iar_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->num_hyps == 727, "incorrect value for num_hyps, expected 727, is %d", msg->num_hyps);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x19, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,25,0,195,4,4,211,2,0,0,173,237, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x19, 1219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_iar_state_t* msg = ( msg_iar_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->num_hyps == 723, "incorrect value for num_hyps, expected 723, is %d", msg->num_hyps);
  }
}
END_TEST

Suite* auto_check_sbp_piksi_24_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_piksi_24");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_piksi_24");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_24);
  suite_add_tcase(s, tc_acq);
  return s;
}