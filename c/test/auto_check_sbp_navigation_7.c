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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLH.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_navigation_7 )
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

    sbp_register_callback(&sbp_state, 0x201, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,1,2,246,215,34,20,46,39,0,250,29,226,186,235,182,66,64,19,203,51,196,24,139,94,192,31,157,160,232,122,115,81,64,0,0,0,0,9,0,236,139, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x201, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_pos_llh_t* msg = ( msg_pos_llh_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", msg->v_accuracy);
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless((msg->lon*100 - -122.173386622*100) < 0.05, "incorrect value for lon, expected -122.173386622, is %f", msg->lon);
    fail_unless(msg->tow == 2567700, "incorrect value for tow, expected 2567700, is %d", msg->tow);
    fail_unless((msg->height*100 - 69.8043767518*100) < 0.05, "incorrect value for height, expected 69.8043767518, is %f", msg->height);
    fail_unless(msg->flags == 0, "incorrect value for flags, expected 0, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless((msg->lat*100 - 37.4290689091*100) < 0.05, "incorrect value for lat, expected 37.4290689091, is %f", msg->lat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x201, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,1,2,246,215,34,20,46,39,0,161,51,75,148,235,182,66,64,36,41,246,30,25,139,94,192,254,218,49,127,10,108,81,64,0,0,0,0,9,1,25,117, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x201, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_pos_llh_t* msg = ( msg_pos_llh_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", msg->v_accuracy);
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless((msg->lon*100 - -122.173408261*100) < 0.05, "incorrect value for lon, expected -122.173408261, is %f", msg->lon);
    fail_unless(msg->tow == 2567700, "incorrect value for tow, expected 2567700, is %d", msg->tow);
    fail_unless((msg->height*100 - 69.6881406772*100) < 0.05, "incorrect value for height, expected 69.6881406772, is %f", msg->height);
    fail_unless(msg->flags == 1, "incorrect value for flags, expected 1, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless((msg->lat*100 - 37.4290643089*100) < 0.05, "incorrect value for lat, expected 37.4290643089, is %f", msg->lat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x201, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,1,2,246,215,34,120,46,39,0,56,214,210,65,235,182,66,64,13,46,132,80,25,139,94,192,22,143,46,234,191,95,81,64,0,0,0,0,9,0,174,105, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x201, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_pos_llh_t* msg = ( msg_pos_llh_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", msg->v_accuracy);
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless((msg->lon*100 - -122.173420075*100) < 0.05, "incorrect value for lon, expected -122.173420075, is %f", msg->lon);
    fail_unless(msg->tow == 2567800, "incorrect value for tow, expected 2567800, is %d", msg->tow);
    fail_unless((msg->height*100 - 69.4960885482*100) < 0.05, "incorrect value for height, expected 69.4960885482, is %f", msg->height);
    fail_unless(msg->flags == 0, "incorrect value for flags, expected 0, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless((msg->lat*100 - 37.4290544776*100) < 0.05, "incorrect value for lat, expected 37.4290544776, is %f", msg->lat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x201, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,1,2,246,215,34,120,46,39,0,251,117,115,140,235,182,66,64,152,134,167,12,25,139,94,192,160,22,137,253,4,108,81,64,0,0,0,0,9,1,122,127, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x201, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_pos_llh_t* msg = ( msg_pos_llh_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", msg->v_accuracy);
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless((msg->lon*100 - -122.173403896*100) < 0.05, "incorrect value for lon, expected -122.173403896, is %f", msg->lon);
    fail_unless(msg->tow == 2567800, "incorrect value for tow, expected 2567800, is %d", msg->tow);
    fail_unless((msg->height*100 - 69.6878045882*100) < 0.05, "incorrect value for height, expected 69.6878045882, is %f", msg->height);
    fail_unless(msg->flags == 1, "incorrect value for flags, expected 1, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless((msg->lat*100 - 37.4290633739*100) < 0.05, "incorrect value for lat, expected 37.4290633739, is %f", msg->lat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x201, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,1,2,246,215,34,220,46,39,0,51,124,88,251,235,182,66,64,153,5,250,16,25,139,94,192,146,60,187,219,152,161,81,64,0,0,0,0,9,0,194,158, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x201, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_pos_llh_t* msg = ( msg_pos_llh_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->v_accuracy == 0, "incorrect value for v_accuracy, expected 0, is %d", msg->v_accuracy);
    fail_unless(msg->n_sats == 9, "incorrect value for n_sats, expected 9, is %d", msg->n_sats);
    fail_unless((msg->lon*100 - -122.173404926*100) < 0.05, "incorrect value for lon, expected -122.173404926, is %f", msg->lon);
    fail_unless(msg->tow == 2567900, "incorrect value for tow, expected 2567900, is %d", msg->tow);
    fail_unless((msg->height*100 - 70.5249547318*100) < 0.05, "incorrect value for height, expected 70.5249547318, is %f", msg->height);
    fail_unless(msg->flags == 0, "incorrect value for flags, expected 0, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless((msg->lat*100 - 37.4290765936*100) < 0.05, "incorrect value for lat, expected 37.4290765936, is %f", msg->lat);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_7_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_navigation_7");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_7");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_7);
  suite_add_tcase(s, tc_acq);
  return s;
}