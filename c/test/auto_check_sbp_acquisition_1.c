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

    sbp_register_callback(&sbp_state, 0x14, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,20,0,246,215,16,137,167,18,66,0,0,161,67,240,24,156,69,9,0,0,0,80,195, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x14, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_t* msg = ( msg_acq_result_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 322.0*100) < 0.05, "incorrect value for cp, expected 322.0, is %f", msg->cp);
    fail_unless((msg->snr*100 - 36.663608551*100) < 0.05, "incorrect value for snr, expected 36.663608551, is %f", msg->snr);
    fail_unless((msg->cf*100 - 4995.1171875*100) < 0.05, "incorrect value for cf, expected 4995.1171875, is %f", msg->cf);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 9, "incorrect value for sid.sat, expected 9, is %d", msg->sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x14, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,20,0,246,215,16,206,172,16,66,0,192,82,68,198,199,0,198,3,0,0,0,149,143, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x14, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_t* msg = ( msg_acq_result_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 843.0*100) < 0.05, "incorrect value for cp, expected 843.0, is %f", msg->cp);
    fail_unless((msg->snr*100 - 36.1687545776*100) < 0.05, "incorrect value for snr, expected 36.1687545776, is %f", msg->snr);
    fail_unless((msg->cf*100 - -8241.94335938*100) < 0.05, "incorrect value for cf, expected -8241.94335938, is %f", msg->cf);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 3, "incorrect value for sid.sat, expected 3, is %d", msg->sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x14, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,20,0,246,215,16,228,27,15,66,0,128,70,68,228,74,148,69,18,0,0,0,179,155, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x14, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_t* msg = ( msg_acq_result_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 794.0*100) < 0.05, "incorrect value for cp, expected 794.0, is %f", msg->cp);
    fail_unless((msg->snr*100 - 35.7772369385*100) < 0.05, "incorrect value for snr, expected 35.7772369385, is %f", msg->snr);
    fail_unless((msg->cf*100 - 4745.36132812*100) < 0.05, "incorrect value for cf, expected 4745.36132812, is %f", msg->cf);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 18, "incorrect value for sid.sat, expected 18, is %d", msg->sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x14, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,20,0,246,215,16,46,199,14,66,0,64,129,67,240,24,28,69,17,0,0,0,18,181, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x14, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_t* msg = ( msg_acq_result_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 258.5*100) < 0.05, "incorrect value for cp, expected 258.5, is %f", msg->cp);
    fail_unless((msg->snr*100 - 35.6945114136*100) < 0.05, "incorrect value for snr, expected 35.6945114136, is %f", msg->snr);
    fail_unless((msg->cf*100 - 2497.55859375*100) < 0.05, "incorrect value for cf, expected 2497.55859375, is %f", msg->cf);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 17, "incorrect value for sid.sat, expected 17, is %d", msg->sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x14, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,20,0,246,215,16,194,24,14,66,0,128,2,68,129,193,249,195,5,0,0,0,35,203, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x14, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_acq_result_t* msg = ( msg_acq_result_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cp*100 - 522.0*100) < 0.05, "incorrect value for cp, expected 522.0, is %f", msg->cp);
    fail_unless((msg->snr*100 - 35.5241775513*100) < 0.05, "incorrect value for snr, expected 35.5241775513, is %f", msg->snr);
    fail_unless((msg->cf*100 - -499.511749268*100) < 0.05, "incorrect value for cf, expected -499.511749268, is %f", msg->cf);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 5, "incorrect value for sid.sat, expected 5, is %d", msg->sid.sat);
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