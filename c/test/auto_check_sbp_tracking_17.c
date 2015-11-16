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

// This file was auto-generated from /Users/joshuagross/Desktop/Projects/libsbp/spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingState.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_tracking_17 )
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

    sbp_register_callback(&sbp_state, 0x13, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,19,0,246,215,99,1,202,0,0,0,197,253,28,66,1,203,0,0,0,231,99,16,66,1,208,0,0,0,212,129,22,66,1,212,0,0,0,58,21,28,66,1,217,0,0,0,178,33,40,66,1,218,0,0,0,235,189,21,66,1,220,0,0,0,29,177,25,66,1,222,0,0,0,43,169,27,66,1,225,0,0,0,137,125,42,66,0,0,0,0,0,0,0,128,191,0,0,0,0,0,0,0,128,191,222,97, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x13, 55286, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_t* msg = ( msg_tracking_state_t *)last_msg;
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

    sbp_register_callback(&sbp_state, 0x13, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,19,0,246,215,99,1,202,0,0,0,250,249,27,66,1,203,0,0,0,40,143,11,66,1,208,0,0,0,190,200,21,66,1,212,0,0,0,251,233,26,66,1,217,0,0,0,209,238,39,66,1,218,0,0,0,162,219,21,66,1,220,0,0,0,162,197,25,66,1,222,0,0,0,14,35,28,66,1,225,0,0,0,9,153,43,66,0,0,0,0,0,0,0,128,191,0,0,0,0,0,0,0,128,191,20,31, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x13, 55286, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_t* msg = ( msg_tracking_state_t *)last_msg;
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

    sbp_register_callback(&sbp_state, 0x13, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,19,0,246,215,99,1,202,0,0,0,123,209,27,66,1,203,0,0,0,214,64,15,66,1,208,0,0,0,56,55,22,66,1,212,0,0,0,91,142,27,66,1,217,0,0,0,253,154,41,66,1,218,0,0,0,128,142,22,66,1,220,0,0,0,17,174,23,66,1,222,0,0,0,155,2,29,66,1,225,0,0,0,162,100,42,66,0,0,0,0,0,0,0,128,191,0,0,0,0,0,0,0,128,191,233,71, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x13, 55286, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_t* msg = ( msg_tracking_state_t *)last_msg;
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

    sbp_register_callback(&sbp_state, 0x13, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,19,0,246,215,99,1,202,0,0,0,120,122,29,66,1,203,0,0,0,66,22,18,66,1,208,0,0,0,153,163,24,66,1,212,0,0,0,178,204,28,66,1,217,0,0,0,220,59,38,66,1,218,0,0,0,161,27,20,66,1,220,0,0,0,125,107,24,66,1,222,0,0,0,242,46,28,66,1,225,0,0,0,231,130,41,66,0,0,0,0,0,0,0,128,191,0,0,0,0,0,0,0,128,191,73,193, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x13, 55286, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_t* msg = ( msg_tracking_state_t *)last_msg;
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

    sbp_register_callback(&sbp_state, 0x13, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,19,0,246,215,99,1,202,0,0,0,103,208,30,66,1,203,0,0,0,117,24,18,66,1,208,0,0,0,200,173,20,66,1,212,0,0,0,137,68,27,66,1,217,0,0,0,243,51,40,66,1,218,0,0,0,225,58,23,66,1,220,0,0,0,132,221,22,66,1,222,0,0,0,157,29,26,66,1,225,0,0,0,133,21,41,66,0,0,0,0,0,0,0,128,191,0,0,0,0,0,0,0,128,191,126,47, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x13, 55286, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_tracking_state_t* msg = ( msg_tracking_state_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    free(errStr);
  }
}
END_TEST

Suite* auto_check_sbp_tracking_17_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_tracking_17");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_tracking_17");
  tcase_add_test(tc_acq, test_auto_check_sbp_tracking_17);
  suite_add_tcase(s, tc_acq);
  return s;
}