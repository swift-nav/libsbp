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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_logging.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <sbp.h>
#include <logging.h>

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

START_TEST( test_auto_check_sbp_logging_21 )
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

    sbp_register_callback(&sbp_state, 0x10, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,16,0,34,34,43,73,78,70,79,58,32,97,99,113,58,32,80,82,78,32,49,53,32,102,111,117,110,100,32,64,32,45,50,52,57,55,32,72,122,44,32,50,48,32,83,78,82,10,116,103, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x10, 8738, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 8738,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_print_dep_t* msg = ( msg_print_dep_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(strstr(msg->text, ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)49,(char)53,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)45,(char)50,(char)52,(char)57,(char)55,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10,0})) != NULL, "incorrect value for msg->text, expected string '%s', is '%s'", ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)49,(char)53,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)45,(char)50,(char)52,(char)57,(char)55,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10,0}), msg->text);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x10, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,16,0,34,34,42,73,78,70,79,58,32,97,99,113,58,32,80,82,78,32,51,49,32,102,111,117,110,100,32,64,32,52,50,52,53,32,72,122,44,32,50,49,32,83,78,82,10,140,43, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x10, 8738, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 8738,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_print_dep_t* msg = ( msg_print_dep_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(strstr(msg->text, ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)51,(char)49,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)52,(char)50,(char)52,(char)53,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)49,(char)32,(char)83,(char)78,(char)82,(char)10,0})) != NULL, "incorrect value for msg->text, expected string '%s', is '%s'", ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)51,(char)49,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)52,(char)50,(char)52,(char)53,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)49,(char)32,(char)83,(char)78,(char)82,(char)10,0}), msg->text);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x10, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,16,0,34,34,35,73,78,70,79,58,32,68,105,115,97,98,108,105,110,103,32,99,104,97,110,110,101,108,32,48,32,40,80,82,78,32,49,49,41,10,23,143, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x10, 8738, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 8738,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_print_dep_t* msg = ( msg_print_dep_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(strstr(msg->text, ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)68,(char)105,(char)115,(char)97,(char)98,(char)108,(char)105,(char)110,(char)103,(char)32,(char)99,(char)104,(char)97,(char)110,(char)110,(char)101,(char)108,(char)32,(char)48,(char)32,(char)40,(char)80,(char)82,(char)78,(char)32,(char)49,(char)49,(char)41,(char)10,0})) != NULL, "incorrect value for msg->text, expected string '%s', is '%s'", ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)68,(char)105,(char)115,(char)97,(char)98,(char)108,(char)105,(char)110,(char)103,(char)32,(char)99,(char)104,(char)97,(char)110,(char)110,(char)101,(char)108,(char)32,(char)48,(char)32,(char)40,(char)80,(char)82,(char)78,(char)32,(char)49,(char)49,(char)41,(char)10,0}), msg->text);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x10, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,16,0,34,34,41,73,78,70,79,58,32,97,99,113,58,32,80,82,78,32,50,32,102,111,117,110,100,32,64,32,51,57,57,54,32,72,122,44,32,50,48,32,83,78,82,10,239,48, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x10, 8738, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 8738,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_print_dep_t* msg = ( msg_print_dep_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(strstr(msg->text, ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)50,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)51,(char)57,(char)57,(char)54,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10,0})) != NULL, "incorrect value for msg->text, expected string '%s', is '%s'", ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)50,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)51,(char)57,(char)57,(char)54,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10,0}), msg->text);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x10, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,16,0,34,34,42,73,78,70,79,58,32,97,99,113,58,32,80,82,78,32,52,32,102,111,117,110,100,32,64,32,45,55,52,57,50,32,72,122,44,32,50,48,32,83,78,82,10,47,248, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x10, 8738, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 8738,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_print_dep_t* msg = ( msg_print_dep_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(strstr(msg->text, ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)52,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)45,(char)55,(char)52,(char)57,(char)50,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10,0})) != NULL, "incorrect value for msg->text, expected string '%s', is '%s'", ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)52,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)45,(char)55,(char)52,(char)57,(char)50,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10,0}), msg->text);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x10, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,16,0,34,34,35,73,78,70,79,58,32,68,105,115,97,98,108,105,110,103,32,99,104,97,110,110,101,108,32,49,32,40,80,82,78,32,49,53,41,10,158,139, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x10, 8738, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 8738,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_print_dep_t* msg = ( msg_print_dep_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(strstr(msg->text, ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)68,(char)105,(char)115,(char)97,(char)98,(char)108,(char)105,(char)110,(char)103,(char)32,(char)99,(char)104,(char)97,(char)110,(char)110,(char)101,(char)108,(char)32,(char)49,(char)32,(char)40,(char)80,(char)82,(char)78,(char)32,(char)49,(char)53,(char)41,(char)10,0})) != NULL, "incorrect value for msg->text, expected string '%s', is '%s'", ((char []){(char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)68,(char)105,(char)115,(char)97,(char)98,(char)108,(char)105,(char)110,(char)103,(char)32,(char)99,(char)104,(char)97,(char)110,(char)110,(char)101,(char)108,(char)32,(char)49,(char)32,(char)40,(char)80,(char)82,(char)78,(char)32,(char)49,(char)53,(char)41,(char)10,0}), msg->text);
  }
}
END_TEST

Suite* auto_check_sbp_logging_21_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_logging_21");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_logging_21");
  tcase_add_test(tc_acq, test_auto_check_sbp_logging_21);
  suite_add_tcase(s, tc_acq);
  return s;
}