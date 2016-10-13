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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResult.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_acquisition_1 )
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

    sbp_register_callback(&sbp_state, 0x1f, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,31,0,40,12,16,72,9,34,66,155,152,228,67,28,34,221,68,10,0,0,0,9,189, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x1f, 3112, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 3112,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_acq_result_t* msg = ( msg_acq_result_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 457.192230225*100) < 0.05, "incorrect value for cp, expected 457.192230225, is %f", msg->cp);
    fail_unless((msg->cf*100 - 1769.06591797*100) < 0.05, "incorrect value for cf, expected 1769.06591797, is %f", msg->cf);
    fail_unless((msg->cn0*100 - 40.5090637207*100) < 0.05, "incorrect value for cn0, expected 40.5090637207, is %f", msg->cn0);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 10, "incorrect value for sid.sat, expected 10, is %d", msg->sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x1f, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,31,0,40,12,16,132,250,45,66,207,93,88,68,68,185,252,195,6,0,0,0,136,185, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x1f, 3112, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 3112,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_acq_result_t* msg = ( msg_acq_result_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 865.465759277*100) < 0.05, "incorrect value for cp, expected 865.465759277, is %f", msg->cp);
    fail_unless((msg->cf*100 - -505.447387695*100) < 0.05, "incorrect value for cf, expected -505.447387695, is %f", msg->cf);
    fail_unless((msg->cn0*100 - 43.494644165*100) < 0.05, "incorrect value for cn0, expected 43.494644165, is %f", msg->cn0);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 6, "incorrect value for sid.sat, expected 6, is %d", msg->sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x1f, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,31,0,40,12,16,163,223,24,66,64,91,102,67,202,243,157,196,13,0,0,0,150,161, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x1f, 3112, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 3112,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_acq_result_t* msg = ( msg_acq_result_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 230.356445312*100) < 0.05, "incorrect value for cp, expected 230.356445312, is %f", msg->cp);
    fail_unless((msg->cf*100 - -1263.6184082*100) < 0.05, "incorrect value for cf, expected -1263.6184082, is %f", msg->cf);
    fail_unless((msg->cn0*100 - 38.2183952332*100) < 0.05, "incorrect value for cn0, expected 38.2183952332, is %f", msg->cn0);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 13, "incorrect value for sid.sat, expected 13, is %d", msg->sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x1f, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,31,0,40,12,16,129,65,21,66,224,214,124,67,243,138,61,69,1,0,0,0,109,209, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x1f, 3112, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 3112,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_acq_result_t* msg = ( msg_acq_result_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 252.839355469*100) < 0.05, "incorrect value for cp, expected 252.839355469, is %f", msg->cp);
    fail_unless((msg->cf*100 - 3032.68432617*100) < 0.05, "incorrect value for cf, expected 3032.68432617, is %f", msg->cf);
    fail_unless((msg->cn0*100 - 37.3139686584*100) < 0.05, "incorrect value for cn0, expected 37.3139686584, is %f", msg->cn0);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 1, "incorrect value for sid.sat, expected 1, is %d", msg->sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x1f, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,31,0,40,12,16,126,35,62,66,226,37,102,68,202,243,29,69,27,0,0,0,91,67, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x1f, 3112, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 3112,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_acq_result_t* msg = ( msg_acq_result_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 920.591918945*100) < 0.05, "incorrect value for cp, expected 920.591918945, is %f", msg->cp);
    fail_unless((msg->cf*100 - 2527.23681641*100) < 0.05, "incorrect value for cf, expected 2527.23681641, is %f", msg->cf);
    fail_unless((msg->cn0*100 - 47.5346603394*100) < 0.05, "incorrect value for cn0, expected 47.5346603394, is %f", msg->cn0);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 27, "incorrect value for sid.sat, expected 27, is %d", msg->sid.sat);
  }
}
END_TEST

Suite* auto_check_sbp_acquisition_1_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_acquisition_1");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_acquisition_1");
  tcase_add_test(tc_acq, test_auto_check_sbp_acquisition_1);
  suite_add_tcase(s, tc_acq);
  return s;
}