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

START_TEST( test_auto_check_sbp_navigation_14 )
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

    sbp_register_callback(&sbp_state, 0x20a, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,10,2,211,136,34,40,244,122,19,201,106,155,186,42,160,66,64,168,109,26,225,0,120,94,192,130,102,237,230,43,54,60,64,0,0,0,0,14,2,175,162, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x20a, 35027, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 35027,
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
    fail_unless(msg->n_sats == 14, "incorrect value for n_sats, expected 14, is %d", msg->n_sats);
    fail_unless((msg->lon*100 - -121.875053669*100) < 0.05, "incorrect value for lon, expected -121.875053669, is %f", msg->lon);
    fail_unless(msg->tow == 326825000, "incorrect value for tow, expected 326825000, is %d", msg->tow);
    fail_unless((msg->height*100 - 28.2116073923*100) < 0.05, "incorrect value for height, expected 28.2116073923, is %f", msg->height);
    fail_unless(msg->flags == 2, "incorrect value for flags, expected 2, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless((msg->lat*100 - 37.2513039836*100) < 0.05, "incorrect value for lat, expected 37.2513039836, is %f", msg->lat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20a, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,10,2,211,136,34,16,248,122,19,52,177,251,178,42,160,66,64,237,22,97,224,0,120,94,192,107,188,109,90,247,189,59,64,0,0,0,0,15,2,38,177, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x20a, 35027, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 35027,
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
    fail_unless(msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", msg->n_sats);
    fail_unless((msg->lon*100 - -121.875053496*100) < 0.05, "incorrect value for lon, expected -121.875053496, is %f", msg->lon);
    fail_unless(msg->tow == 326826000, "incorrect value for tow, expected 326826000, is %d", msg->tow);
    fail_unless((msg->height*100 - 27.7420555609*100) < 0.05, "incorrect value for height, expected 27.7420555609, is %f", msg->height);
    fail_unless(msg->flags == 2, "incorrect value for flags, expected 2, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless((msg->lat*100 - 37.2513030747*100) < 0.05, "incorrect value for lat, expected 37.2513030747, is %f", msg->lat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20a, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,10,2,211,136,34,248,251,122,19,135,66,9,163,42,160,66,64,146,8,99,225,0,120,94,192,45,181,143,219,28,157,59,64,0,0,0,0,15,2,51,40, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x20a, 35027, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 35027,
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
    fail_unless(msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", msg->n_sats);
    fail_unless((msg->lon*100 - -121.875053736*100) < 0.05, "incorrect value for lon, expected -121.875053736, is %f", msg->lon);
    fail_unless(msg->tow == 326827000, "incorrect value for tow, expected 326827000, is %d", msg->tow);
    fail_unless((msg->height*100 - 27.613721583*100) < 0.05, "incorrect value for height, expected 27.613721583, is %f", msg->height);
    fail_unless(msg->flags == 2, "incorrect value for flags, expected 2, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless((msg->lat*100 - 37.2513011737*100) < 0.05, "incorrect value for lat, expected 37.2513011737, is %f", msg->lat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20a, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,10,2,211,136,34,224,255,122,19,18,44,253,119,42,160,66,64,48,109,39,231,0,120,94,192,185,76,48,17,119,205,59,64,0,0,0,0,15,2,12,194, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x20a, 35027, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 35027,
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
    fail_unless(msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", msg->n_sats);
    fail_unless((msg->lon*100 - -121.875055111*100) < 0.05, "incorrect value for lon, expected -121.875055111, is %f", msg->lon);
    fail_unless(msg->tow == 326828000, "incorrect value for tow, expected 326828000, is %d", msg->tow);
    fail_unless((msg->height*100 - 27.8025980704*100) < 0.05, "incorrect value for height, expected 27.8025980704, is %f", msg->height);
    fail_unless(msg->flags == 2, "incorrect value for flags, expected 2, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless((msg->lat*100 - 37.2512960421*100) < 0.05, "incorrect value for lat, expected 37.2512960421, is %f", msg->lat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x20a, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,10,2,211,136,34,200,3,123,19,225,237,238,90,42,160,66,64,59,143,70,235,0,120,94,192,101,106,249,224,131,240,59,64,0,0,0,0,15,2,34,103, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x20a, 35027, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 35027,
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
    fail_unless(msg->n_sats == 15, "incorrect value for n_sats, expected 15, is %d", msg->n_sats);
    fail_unless((msg->lon*100 - -121.875056094*100) < 0.05, "incorrect value for lon, expected -121.875056094, is %f", msg->lon);
    fail_unless(msg->tow == 326829000, "incorrect value for tow, expected 326829000, is %d", msg->tow);
    fail_unless((msg->height*100 - 27.9395123109*100) < 0.05, "incorrect value for height, expected 27.9395123109, is %f", msg->height);
    fail_unless(msg->flags == 2, "incorrect value for flags, expected 2, is %d", msg->flags);
    fail_unless(msg->h_accuracy == 0, "incorrect value for h_accuracy, expected 0, is %d", msg->h_accuracy);
    fail_unless((msg->lat*100 - 37.2512925784*100) < 0.05, "incorrect value for lat, expected 37.2512925784, is %f", msg->lat);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_14_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_navigation_14");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_navigation_14");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_14);
  suite_add_tcase(s, tc_acq);
  return s;
}