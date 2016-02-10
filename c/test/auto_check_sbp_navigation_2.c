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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEF.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_navigation_2 )
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

    sbp_register_callback(&sbp_state, 0x202, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,2,2,246,215,20,20,46,39,0,21,48,255,255,52,117,255,255,216,211,254,255,0,0,9,1,50,137, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x202, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_baseline_ecef_t* msg = ( msg_baseline_ecef_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless(msg->x == -53227, "incorrect value for x, expected -53227, is %d", msg->x);
    fail_unless(msg->y == -35532, "incorrect value for y, expected -35532, is %d", msg->y);
    fail_unless(msg->flags == 1, "incorrect value for flags, expected 1, is %d", msg->flags);
    fail_unless(msg->z == -76840, "incorrect value for z, expected -76840, is %d", msg->z);
    fail_unless(msg->tow == 2567700, "incorrect value for tow, expected 2567700, is %d", msg->tow);
    fail_unless(msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", msg->accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x202, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,2,2,246,215,20,120,46,39,0,58,49,255,255,49,116,255,255,134,211,254,255,0,0,9,1,227,155, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x202, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_baseline_ecef_t* msg = ( msg_baseline_ecef_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless(msg->x == -52934, "incorrect value for x, expected -52934, is %d", msg->x);
    fail_unless(msg->y == -35791, "incorrect value for y, expected -35791, is %d", msg->y);
    fail_unless(msg->flags == 1, "incorrect value for flags, expected 1, is %d", msg->flags);
    fail_unless(msg->z == -76922, "incorrect value for z, expected -76922, is %d", msg->z);
    fail_unless(msg->tow == 2567800, "incorrect value for tow, expected 2567800, is %d", msg->tow);
    fail_unless(msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", msg->accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x202, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,2,2,246,215,20,220,46,39,0,97,50,255,255,47,115,255,255,52,211,254,255,0,0,9,1,61,126, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x202, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_baseline_ecef_t* msg = ( msg_baseline_ecef_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless(msg->x == -52639, "incorrect value for x, expected -52639, is %d", msg->x);
    fail_unless(msg->y == -36049, "incorrect value for y, expected -36049, is %d", msg->y);
    fail_unless(msg->flags == 1, "incorrect value for flags, expected 1, is %d", msg->flags);
    fail_unless(msg->z == -77004, "incorrect value for z, expected -77004, is %d", msg->z);
    fail_unless(msg->tow == 2567900, "incorrect value for tow, expected 2567900, is %d", msg->tow);
    fail_unless(msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", msg->accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x202, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,2,2,246,215,20,64,47,39,0,136,51,255,255,45,114,255,255,228,210,254,255,0,0,9,1,200,79, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x202, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_baseline_ecef_t* msg = ( msg_baseline_ecef_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless(msg->x == -52344, "incorrect value for x, expected -52344, is %d", msg->x);
    fail_unless(msg->y == -36307, "incorrect value for y, expected -36307, is %d", msg->y);
    fail_unless(msg->flags == 1, "incorrect value for flags, expected 1, is %d", msg->flags);
    fail_unless(msg->z == -77084, "incorrect value for z, expected -77084, is %d", msg->z);
    fail_unless(msg->tow == 2568000, "incorrect value for tow, expected 2568000, is %d", msg->tow);
    fail_unless(msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", msg->accuracy);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x202, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,2,2,246,215,20,164,47,39,0,176,52,255,255,44,113,255,255,149,210,254,255,0,0,9,1,104,24, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x202, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_baseline_ecef_t* msg = ( msg_baseline_ecef_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless(msg->x == -52048, "incorrect value for x, expected -52048, is %d", msg->x);
    fail_unless(msg->y == -36564, "incorrect value for y, expected -36564, is %d", msg->y);
    fail_unless(msg->flags == 1, "incorrect value for flags, expected 1, is %d", msg->flags);
    fail_unless(msg->z == -77163, "incorrect value for z, expected -77163, is %d", msg->z);
    fail_unless(msg->tow == 2568100, "incorrect value for tow, expected 2568100, is %d", msg->tow);
    fail_unless(msg->accuracy == 0, "incorrect value for accuracy, expected 0, is %d", msg->accuracy);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_2_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_navigation_2");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_2");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_2);
  suite_add_tcase(s, tc_acq);
  return s;
}