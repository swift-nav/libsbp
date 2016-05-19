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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_acquisition.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <sbp.h>
#include <acquisition.h>

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

START_TEST( test_auto_check_sbp_acquisition_18 )
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

    sbp_register_callback(&sbp_state, 0x15, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,21,0,195,4,13,0,0,104,65,0,192,53,68,198,199,0,70,8,2,68, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x15, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_dep_a_t* msg = ( msg_acq_result_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 727.0*100) < 0.05, "incorrect value for cp, expected 727.0, is %f", msg->cp);
    fail_unless((msg->snr*100 - 14.5*100) < 0.05, "incorrect value for snr, expected 14.5, is %f", msg->snr);
    fail_unless((msg->cf*100 - 8241.94335938*100) < 0.05, "incorrect value for cf, expected 8241.94335938, is %f", msg->cf);
    fail_unless(msg->prn == 8, "incorrect value for prn, expected 8, is %d", msg->prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x15, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,21,0,195,4,13,205,204,116,65,0,192,179,67,33,81,59,68,9,219,27, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x15, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_dep_a_t* msg = ( msg_acq_result_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 359.5*100) < 0.05, "incorrect value for cp, expected 359.5, is %f", msg->cp);
    fail_unless((msg->snr*100 - 15.3000001907*100) < 0.05, "incorrect value for snr, expected 15.3000001907, is %f", msg->snr);
    fail_unless((msg->cf*100 - 749.26763916*100) < 0.05, "incorrect value for cf, expected 749.26763916, is %f", msg->cf);
    fail_unless(msg->prn == 9, "incorrect value for prn, expected 9, is %d", msg->prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x15, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,21,0,195,4,13,205,204,144,65,0,0,34,66,57,237,202,197,11,150,35, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x15, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_dep_a_t* msg = ( msg_acq_result_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 40.5*100) < 0.05, "incorrect value for cp, expected 40.5, is %f", msg->cp);
    fail_unless((msg->snr*100 - 18.1000003815*100) < 0.05, "incorrect value for snr, expected 18.1000003815, is %f", msg->snr);
    fail_unless((msg->cf*100 - -6493.65283203*100) < 0.05, "incorrect value for cf, expected -6493.65283203, is %f", msg->cf);
    fail_unless(msg->prn == 11, "incorrect value for prn, expected 11, is %d", msg->prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x15, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,21,0,195,4,13,205,204,116,65,0,32,9,68,129,193,121,196,12,146,118, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x15, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_dep_a_t* msg = ( msg_acq_result_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 548.5*100) < 0.05, "incorrect value for cp, expected 548.5, is %f", msg->cp);
    fail_unless((msg->snr*100 - 15.3000001907*100) < 0.05, "incorrect value for snr, expected 15.3000001907, is %f", msg->snr);
    fail_unless((msg->cf*100 - -999.023498535*100) < 0.05, "incorrect value for cf, expected -999.023498535, is %f", msg->cf);
    fail_unless(msg->prn == 12, "incorrect value for prn, expected 12, is %d", msg->prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x15, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,21,0,195,4,13,205,204,116,65,0,32,67,68,228,74,148,69,14,23,75, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x15, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_dep_a_t* msg = ( msg_acq_result_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 780.5*100) < 0.05, "incorrect value for cp, expected 780.5, is %f", msg->cp);
    fail_unless((msg->snr*100 - 15.3000001907*100) < 0.05, "incorrect value for snr, expected 15.3000001907, is %f", msg->snr);
    fail_unless((msg->cf*100 - 4745.36132812*100) < 0.05, "incorrect value for cf, expected 4745.36132812, is %f", msg->cf);
    fail_unless(msg->prn == 14, "incorrect value for prn, expected 14, is %d", msg->prn);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x15, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,21,0,195,4,13,228,56,35,67,0,32,18,68,129,193,249,195,0,204,207, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x15, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_dep_a_t* msg = ( msg_acq_result_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 584.5*100) < 0.05, "incorrect value for cp, expected 584.5, is %f", msg->cp);
    fail_unless((msg->snr*100 - 163.222229004*100) < 0.05, "incorrect value for snr, expected 163.222229004, is %f", msg->snr);
    fail_unless((msg->cf*100 - -499.511749268*100) < 0.05, "incorrect value for cf, expected -499.511749268, is %f", msg->cf);
    fail_unless(msg->prn == 0, "incorrect value for prn, expected 0, is %d", msg->prn);
  }
}
END_TEST

Suite* auto_check_sbp_acquisition_18_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_acquisition_18");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_acquisition_18");
  tcase_add_test(tc_acq, test_auto_check_sbp_acquisition_18);
  suite_add_tcase(s, tc_acq);
  return s;
}