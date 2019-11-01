/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCov.yaml by generate.py. Do not modify by hand!

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

static s32 dummy_write(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(dummy_buff + dummy_wr, buff, real_n);
 dummy_wr += real_n;
 return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void* context)
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

START_TEST( test_auto_check_sbp_navigation_13 )
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

    sbp_register_callback(&sbp_state, 0x214, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,20,2,66,0,54,7,0,0,0,0,0,0,0,0,0,24,64,0,0,0,0,0,0,240,63,0,0,0,0,0,0,16,64,0,0,0,65,0,0,224,64,0,0,0,64,0,0,192,64,0,0,0,65,0,0,160,64,4,5,249,167, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x214, 66, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 66,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_pos_ecef_cov_t* msg = ( msg_pos_ecef_cov_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless((msg->cov_x_x*100 - 8.0*100) < 0.05, "incorrect value for cov_x_x, expected 8.0, is %f", msg->cov_x_x);
    fail_unless((msg->cov_x_y*100 - 7.0*100) < 0.05, "incorrect value for cov_x_y, expected 7.0, is %f", msg->cov_x_y);
    fail_unless((msg->cov_x_z*100 - 2.0*100) < 0.05, "incorrect value for cov_x_z, expected 2.0, is %f", msg->cov_x_z);
    fail_unless((msg->cov_y_y*100 - 6.0*100) < 0.05, "incorrect value for cov_y_y, expected 6.0, is %f", msg->cov_y_y);
    fail_unless((msg->cov_y_z*100 - 8.0*100) < 0.05, "incorrect value for cov_y_z, expected 8.0, is %f", msg->cov_y_z);
    fail_unless((msg->cov_z_z*100 - 5.0*100) < 0.05, "incorrect value for cov_z_z, expected 5.0, is %f", msg->cov_z_z);
    fail_unless(msg->flags == 5, "incorrect value for flags, expected 5, is %d", msg->flags);
    fail_unless(msg->n_sats == 4, "incorrect value for n_sats, expected 4, is %d", msg->n_sats);
    fail_unless(msg->tow == 7, "incorrect value for tow, expected 7, is %d", msg->tow);
    fail_unless((msg->x*100 - 6.0*100) < 0.05, "incorrect value for x, expected 6.0, is %f", msg->x);
    fail_unless((msg->y*100 - 1.0*100) < 0.05, "incorrect value for y, expected 1.0, is %f", msg->y);
    fail_unless((msg->z*100 - 4.0*100) < 0.05, "incorrect value for z, expected 4.0, is %f", msg->z);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_13_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_navigation_13");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_13");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_13);
  suite_add_tcase(s, tc_acq);
  return s;
}