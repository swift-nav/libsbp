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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgThreadState.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_piksi_23 )
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

    u8 test_data[] = {85,23,0,246,215,26,109,97,105,110,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,156,9,0,0,73,138, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 2460, "incorrect value for stack_free, expected 2460, is %d", msg->stack_free);
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

    u8 test_data[] = {85,23,0,246,215,26,105,100,108,101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,83,2,36,0,0,0,151,20, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 36, "incorrect value for stack_free, expected 36, is %d", msg->stack_free);
    fail_unless(msg->cpu == 595, "incorrect value for cpu, expected 595, is %d", msg->cpu);
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

    u8 test_data[] = {85,23,0,246,215,26,78,65,80,32,73,83,82,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,116,4,0,0,226,60, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 1140, "incorrect value for stack_free, expected 1140, is %d", msg->stack_free);
    fail_unless(msg->cpu == 14, "incorrect value for cpu, expected 14, is %d", msg->cpu);
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

    u8 test_data[] = {85,23,0,246,215,26,83,66,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,196,19,0,0,90,169, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 5060, "incorrect value for stack_free, expected 5060, is %d", msg->stack_free);
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

    u8 test_data[] = {85,23,0,246,215,26,109,97,110,97,103,101,32,97,99,113,0,0,0,0,0,0,0,0,0,0,7,0,20,9,0,0,47,75, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x17, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_thread_state_t* msg = ( msg_thread_state_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->stack_free == 2324, "incorrect value for stack_free, expected 2324, is %d", msg->stack_free);
    fail_unless(msg->cpu == 7, "incorrect value for cpu, expected 7, is %d", msg->cpu);
    fail_unless(strstr(msg->name, ((char []){(char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)97,(char)99,(char)113,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0})) != NULL, "incorrect value for msg->name, expected string '%s', is '%s'", ((char []){(char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)97,(char)99,(char)113,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,0}), msg->name);
  }
}
END_TEST

Suite* auto_check_sbp_piksi_23_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_piksi_23");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_piksi_23");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_23);
  suite_add_tcase(s, tc_acq);
  return s;
}