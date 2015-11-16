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

// This file was auto-generated from /Users/joshuagross/Desktop/Projects/libsbp/spec/tests/yaml/swiftnav/sbp/test_tracking.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <sbp.h>
#include <tracking.h>

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

START_TEST( test_auto_check_sbp_tracking_18 )
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

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,204,177,51,65,1,2,198,4,39,65,1,3,219,182,27,65,1,7,132,120,101,65,1,10,91,91,251,64,1,13,42,37,163,64,1,22,130,184,215,64,1,30,115,53,75,65,1,31,16,74,126,65,1,25,132,196,135,64,1,6,100,59,223,64,17,225, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    free(errStr);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,216,57,48,65,1,2,145,41,46,65,1,3,4,26,34,65,1,7,177,67,109,65,1,10,61,80,249,64,1,13,250,199,155,64,1,22,55,19,215,64,1,30,138,138,79,65,1,31,214,179,119,65,1,25,53,138,120,64,1,6,183,247,129,64,168,173, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    free(errStr);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,141,76,60,65,1,2,69,139,46,65,1,3,146,27,30,65,1,7,235,56,97,65,1,10,141,213,243,64,1,13,250,170,166,64,1,22,17,101,201,64,1,30,172,183,83,65,1,31,238,193,120,65,1,25,220,48,132,64,1,6,49,214,54,64,110,179, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    free(errStr);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,55,143,120,66,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,248,89, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    free(errStr);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,218,14,19,66,1,2,210,3,21,65,1,3,234,214,134,65,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,84,101, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    free(errStr);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,98,39,219,65,1,2,0,0,56,64,1,3,121,123,7,65,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,37,123, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    free(errStr);
  }
}
END_TEST

Suite* auto_check_sbp_tracking_18_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_tracking_18");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_tracking_18");
  tcase_add_test(tc_acq, test_auto_check_sbp_tracking_18);
  suite_add_tcase(s, tc_acq);
  return s;
}