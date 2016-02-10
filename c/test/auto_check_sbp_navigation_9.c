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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNED.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <sbp.h>
#include <navigation.h>

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

START_TEST( test_auto_check_sbp_navigation_9 )
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

    sbp_register_callback(&sbp_state, 0x205, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,5,2,246,215,22,20,46,39,0,198,251,255,255,156,15,0,0,0,0,0,0,0,0,0,0,9,0,161,92, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x205, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_vel_ned_t* msg = ( msg_vel_ned_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", msg->v_accuracy);
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless(msg->d == 0, "incorrect value for d, expected 0, is %d", msg->d);
    fail_unless(msg->tow == 2567700, "incorrect value for tow, expected 2567700, is %d", msg->tow);
    fail_unless(msg->n == -1082, "incorrect value for n, expected -1082, is %d", msg->n);
    fail_unless(msg->flags == 0, "incorrect value for flags, expected 0, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless(msg->e == 3996, "incorrect value for e, expected 3996, is %d", msg->e);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x205, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,5,2,246,215,22,120,46,39,0,14,252,255,255,207,14,0,0,0,0,0,0,0,0,0,0,9,0,125,160, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x205, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_vel_ned_t* msg = ( msg_vel_ned_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", msg->v_accuracy);
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless(msg->d == 0, "incorrect value for d, expected 0, is %d", msg->d);
    fail_unless(msg->tow == 2567800, "incorrect value for tow, expected 2567800, is %d", msg->tow);
    fail_unless(msg->n == -1010, "incorrect value for n, expected -1010, is %d", msg->n);
    fail_unless(msg->flags == 0, "incorrect value for flags, expected 0, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless(msg->e == 3791, "incorrect value for e, expected 3791, is %d", msg->e);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x205, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,5,2,246,215,22,220,46,39,0,48,252,255,255,140,14,0,0,0,0,0,0,0,0,0,0,9,0,179,135, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x205, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_vel_ned_t* msg = ( msg_vel_ned_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", msg->v_accuracy);
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless(msg->d == 0, "incorrect value for d, expected 0, is %d", msg->d);
    fail_unless(msg->tow == 2567900, "incorrect value for tow, expected 2567900, is %d", msg->tow);
    fail_unless(msg->n == -976, "incorrect value for n, expected -976, is %d", msg->n);
    fail_unless(msg->flags == 0, "incorrect value for flags, expected 0, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless(msg->e == 3724, "incorrect value for e, expected 3724, is %d", msg->e);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x205, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,5,2,246,215,22,64,47,39,0,32,252,255,255,8,15,0,0,0,0,0,0,0,0,0,0,9,0,51,177, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x205, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_vel_ned_t* msg = ( msg_vel_ned_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", msg->v_accuracy);
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless(msg->d == 0, "incorrect value for d, expected 0, is %d", msg->d);
    fail_unless(msg->tow == 2568000, "incorrect value for tow, expected 2568000, is %d", msg->tow);
    fail_unless(msg->n == -992, "incorrect value for n, expected -992, is %d", msg->n);
    fail_unless(msg->flags == 0, "incorrect value for flags, expected 0, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless(msg->e == 3848, "incorrect value for e, expected 3848, is %d", msg->e);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x205, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,5,2,246,215,22,164,47,39,0,80,252,255,255,140,14,0,0,0,0,0,0,0,0,0,0,9,0,23,0, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x205, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_vel_ned_t* msg = ( msg_vel_ned_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", msg->v_accuracy);
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless(msg->d == 0, "incorrect value for d, expected 0, is %d", msg->d);
    fail_unless(msg->tow == 2568100, "incorrect value for tow, expected 2568100, is %d", msg->tow);
    fail_unless(msg->n == -944, "incorrect value for n, expected -944, is %d", msg->n);
    fail_unless(msg->flags == 0, "incorrect value for flags, expected 0, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless(msg->e == 3724, "incorrect value for e, expected 3724, is %d", msg->e);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_9_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_navigation_9");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_9");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_9);
  suite_add_tcase(s, tc_acq);
  return s;
}