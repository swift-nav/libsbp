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

// This file was auto-generated from /Users/joshuagross/Desktop/Projects/libsbp/spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <sbp.h>
#include <observation.h>

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

START_TEST( test_auto_check_sbp_observation_13 )
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

    sbp_register_callback(&sbp_state, 0x43, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,67,0,246,215,103,120,46,39,0,251,6,32,180,175,187,133,223,53,7,7,27,157,0,0,202,0,0,0,58,140,85,147,88,28,190,7,175,144,0,0,203,0,0,0,220,140,248,138,208,172,77,7,135,151,0,0,208,0,0,0,173,194,72,135,115,18,28,7,242,156,0,0,212,0,0,0,164,144,105,124,18,196,137,6,120,168,0,0,217,0,0,0,30,232,228,139,210,7,90,7,87,150,0,0,218,0,0,0,169,85, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x43, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_obs_t* msg = ( msg_obs_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header->n_obs, expected 32");
    fail_unless(msg->header.t.wn == 1787, "incorrect value for header.t.wn, expected 1787");
    fail_unless(msg->header.t.tow == 2567800, "incorrect value for header.t.tow, expected 2567800");
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

    sbp_register_callback(&sbp_state, 0x43, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,67,0,246,215,55,120,46,39,0,251,6,33,68,199,101,136,133,247,42,7,219,154,0,0,220,0,0,0,219,14,123,133,96,215,3,7,235,156,0,0,222,0,0,0,87,166,81,122,5,173,109,6,174,170,0,0,225,0,0,0,11,233, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x43, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_obs_t* msg = ( msg_obs_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 33, "incorrect value for header->n_obs, expected 33");
    fail_unless(msg->header.t.wn == 1787, "incorrect value for header.t.wn, expected 1787");
    fail_unless(msg->header.t.tow == 2567800, "incorrect value for header.t.tow, expected 2567800");
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

    sbp_register_callback(&sbp_state, 0x43, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,67,0,246,215,103,64,47,39,0,251,6,32,100,132,187,133,236,51,7,7,94,156,0,0,202,0,0,0,97,184,85,147,178,30,190,7,40,140,0,0,203,0,0,0,135,111,248,138,90,171,77,7,2,150,0,0,208,0,0,0,180,238,72,135,190,20,28,7,241,155,0,0,212,0,0,0,15,153,105,124,92,196,137,6,153,168,0,0,217,0,0,0,49,185,228,139,144,5,90,7,41,150,0,0,218,0,0,0,241,98, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x43, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_obs_t* msg = ( msg_obs_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header->n_obs, expected 32");
    fail_unless(msg->header.t.wn == 1787, "incorrect value for header.t.wn, expected 1787");
    fail_unless(msg->header.t.tow == 2568000, "incorrect value for header.t.tow, expected 2568000");
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

    sbp_register_callback(&sbp_state, 0x43, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,67,0,246,215,55,64,47,39,0,251,6,33,234,148,101,136,15,245,42,7,20,154,0,0,220,0,0,0,208,247,122,133,16,214,3,7,38,156,0,0,222,0,0,0,15,150,81,122,22,172,109,6,7,172,0,0,225,0,0,0,201,13, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x43, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_obs_t* msg = ( msg_obs_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 33, "incorrect value for header->n_obs, expected 33");
    fail_unless(msg->header.t.wn == 1787, "incorrect value for header.t.wn, expected 1787");
    fail_unless(msg->header.t.tow == 2568000, "incorrect value for header.t.tow, expected 2568000");
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

    sbp_register_callback(&sbp_state, 0x43, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,67,0,246,215,103,8,48,39,0,251,6,32,254,96,187,133,249,49,7,7,165,156,0,0,202,0,0,0,113,229,85,147,11,33,190,7,106,143,0,0,203,0,0,0,182,85,248,138,227,169,77,7,159,150,0,0,208,0,0,0,17,24,73,135,10,23,28,7,7,156,0,0,212,0,0,0,108,155,105,124,166,196,137,6,186,170,0,0,217,0,0,0,214,142,228,139,77,3,90,7,236,151,0,0,218,0,0,0,59,118, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x43, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_obs_t* msg = ( msg_obs_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header->n_obs, expected 32");
    fail_unless(msg->header.t.wn == 1787, "incorrect value for header.t.wn, expected 1787");
    fail_unless(msg->header.t.tow == 2568200, "incorrect value for header.t.tow, expected 2568200");
    free(errStr);
  }
}
END_TEST

Suite* auto_check_sbp_observation_13_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_observation_13");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_observation_13");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_13);
  suite_add_tcase(s, tc_acq);
  return s;
}