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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/test_tracking.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_tracking_26 )
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

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,204,177,51,65,1,2,198,4,39,65,1,3,219,182,27,65,1,7,132,120,101,65,1,10,91,91,251,64,1,13,42,37,163,64,1,22,130,184,215,64,1,30,115,53,75,65,1,31,16,74,126,65,1,25,132,196,135,64,1,6,100,59,223,64,17,225, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->states[0].state == 1, "incorrect value for states[0].state, expected 1, is %d", msg->states[0].state);
    fail_unless(msg->states[0].prn == 0, "incorrect value for states[0].prn, expected 0, is %d", msg->states[0].prn);
    fail_unless((msg->states[0].cn0*100 - 11.2309074402*100) < 0.05, "incorrect value for states[0].cn0, expected 11.2309074402, is %f", msg->states[0].cn0);
    fail_unless(msg->states[1].state == 1, "incorrect value for states[1].state, expected 1, is %d", msg->states[1].state);
    fail_unless(msg->states[1].prn == 2, "incorrect value for states[1].prn, expected 2, is %d", msg->states[1].prn);
    fail_unless((msg->states[1].cn0*100 - 10.43866539*100) < 0.05, "incorrect value for states[1].cn0, expected 10.43866539, is %f", msg->states[1].cn0);
    fail_unless(msg->states[2].state == 1, "incorrect value for states[2].state, expected 1, is %d", msg->states[2].state);
    fail_unless(msg->states[2].prn == 3, "incorrect value for states[2].prn, expected 3, is %d", msg->states[2].prn);
    fail_unless((msg->states[2].cn0*100 - 9.73214244843*100) < 0.05, "incorrect value for states[2].cn0, expected 9.73214244843, is %f", msg->states[2].cn0);
    fail_unless(msg->states[3].state == 1, "incorrect value for states[3].state, expected 1, is %d", msg->states[3].state);
    fail_unless(msg->states[3].prn == 7, "incorrect value for states[3].prn, expected 7, is %d", msg->states[3].prn);
    fail_unless((msg->states[3].cn0*100 - 14.34192276*100) < 0.05, "incorrect value for states[3].cn0, expected 14.34192276, is %f", msg->states[3].cn0);
    fail_unless(msg->states[4].state == 1, "incorrect value for states[4].state, expected 1, is %d", msg->states[4].state);
    fail_unless(msg->states[4].prn == 10, "incorrect value for states[4].prn, expected 10, is %d", msg->states[4].prn);
    fail_unless((msg->states[4].cn0*100 - 7.85490179062*100) < 0.05, "incorrect value for states[4].cn0, expected 7.85490179062, is %f", msg->states[4].cn0);
    fail_unless(msg->states[5].state == 1, "incorrect value for states[5].state, expected 1, is %d", msg->states[5].state);
    fail_unless(msg->states[5].prn == 13, "incorrect value for states[5].prn, expected 13, is %d", msg->states[5].prn);
    fail_unless((msg->states[5].cn0*100 - 5.09828662872*100) < 0.05, "incorrect value for states[5].cn0, expected 5.09828662872, is %f", msg->states[5].cn0);
    fail_unless(msg->states[6].state == 1, "incorrect value for states[6].state, expected 1, is %d", msg->states[6].state);
    fail_unless(msg->states[6].prn == 22, "incorrect value for states[6].prn, expected 22, is %d", msg->states[6].prn);
    fail_unless((msg->states[6].cn0*100 - 6.74127292633*100) < 0.05, "incorrect value for states[6].cn0, expected 6.74127292633, is %f", msg->states[6].cn0);
    fail_unless(msg->states[7].state == 1, "incorrect value for states[7].state, expected 1, is %d", msg->states[7].state);
    fail_unless(msg->states[7].prn == 30, "incorrect value for states[7].prn, expected 30, is %d", msg->states[7].prn);
    fail_unless((msg->states[7].cn0*100 - 12.7005491257*100) < 0.05, "incorrect value for states[7].cn0, expected 12.7005491257, is %f", msg->states[7].cn0);
    fail_unless(msg->states[8].state == 1, "incorrect value for states[8].state, expected 1, is %d", msg->states[8].state);
    fail_unless(msg->states[8].prn == 31, "incorrect value for states[8].prn, expected 31, is %d", msg->states[8].prn);
    fail_unless((msg->states[8].cn0*100 - 15.893081665*100) < 0.05, "incorrect value for states[8].cn0, expected 15.893081665, is %f", msg->states[8].cn0);
    fail_unless(msg->states[9].state == 1, "incorrect value for states[9].state, expected 1, is %d", msg->states[9].state);
    fail_unless(msg->states[9].prn == 25, "incorrect value for states[9].prn, expected 25, is %d", msg->states[9].prn);
    fail_unless((msg->states[9].cn0*100 - 4.24273872375*100) < 0.05, "incorrect value for states[9].cn0, expected 4.24273872375, is %f", msg->states[9].cn0);
    fail_unless(msg->states[10].state == 1, "incorrect value for states[10].state, expected 1, is %d", msg->states[10].state);
    fail_unless(msg->states[10].prn == 6, "incorrect value for states[10].prn, expected 6, is %d", msg->states[10].prn);
    fail_unless((msg->states[10].cn0*100 - 6.97599983215*100) < 0.05, "incorrect value for states[10].cn0, expected 6.97599983215, is %f", msg->states[10].cn0);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,216,57,48,65,1,2,145,41,46,65,1,3,4,26,34,65,1,7,177,67,109,65,1,10,61,80,249,64,1,13,250,199,155,64,1,22,55,19,215,64,1,30,138,138,79,65,1,31,214,179,119,65,1,25,53,138,120,64,1,6,183,247,129,64,168,173, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->states[0].state == 1, "incorrect value for states[0].state, expected 1, is %d", msg->states[0].state);
    fail_unless(msg->states[0].prn == 0, "incorrect value for states[0].prn, expected 0, is %d", msg->states[0].prn);
    fail_unless((msg->states[0].cn0*100 - 11.0141220093*100) < 0.05, "incorrect value for states[0].cn0, expected 11.0141220093, is %f", msg->states[0].cn0);
    fail_unless(msg->states[1].state == 1, "incorrect value for states[1].state, expected 1, is %d", msg->states[1].state);
    fail_unless(msg->states[1].prn == 2, "incorrect value for states[1].prn, expected 2, is %d", msg->states[1].prn);
    fail_unless((msg->states[1].cn0*100 - 10.8851480484*100) < 0.05, "incorrect value for states[1].cn0, expected 10.8851480484, is %f", msg->states[1].cn0);
    fail_unless(msg->states[2].state == 1, "incorrect value for states[2].state, expected 1, is %d", msg->states[2].state);
    fail_unless(msg->states[2].prn == 3, "incorrect value for states[2].prn, expected 3, is %d", msg->states[2].prn);
    fail_unless((msg->states[2].cn0*100 - 10.1313514709*100) < 0.05, "incorrect value for states[2].cn0, expected 10.1313514709, is %f", msg->states[2].cn0);
    fail_unless(msg->states[3].state == 1, "incorrect value for states[3].state, expected 1, is %d", msg->states[3].state);
    fail_unless(msg->states[3].prn == 7, "incorrect value for states[3].prn, expected 7, is %d", msg->states[3].prn);
    fail_unless((msg->states[3].cn0*100 - 14.8290262222*100) < 0.05, "incorrect value for states[3].cn0, expected 14.8290262222, is %f", msg->states[3].cn0);
    fail_unless(msg->states[4].state == 1, "incorrect value for states[4].state, expected 1, is %d", msg->states[4].state);
    fail_unless(msg->states[4].prn == 10, "incorrect value for states[4].prn, expected 10, is %d", msg->states[4].prn);
    fail_unless((msg->states[4].cn0*100 - 7.79104471207*100) < 0.05, "incorrect value for states[4].cn0, expected 7.79104471207, is %f", msg->states[4].cn0);
    fail_unless(msg->states[5].state == 1, "incorrect value for states[5].state, expected 1, is %d", msg->states[5].state);
    fail_unless(msg->states[5].prn == 13, "incorrect value for states[5].prn, expected 13, is %d", msg->states[5].prn);
    fail_unless((msg->states[5].cn0*100 - 4.86816120148*100) < 0.05, "incorrect value for states[5].cn0, expected 4.86816120148, is %f", msg->states[5].cn0);
    fail_unless(msg->states[6].state == 1, "incorrect value for states[6].state, expected 1, is %d", msg->states[6].state);
    fail_unless(msg->states[6].prn == 22, "incorrect value for states[6].prn, expected 22, is %d", msg->states[6].prn);
    fail_unless((msg->states[6].cn0*100 - 6.72109556198*100) < 0.05, "incorrect value for states[6].cn0, expected 6.72109556198, is %f", msg->states[6].cn0);
    fail_unless(msg->states[7].state == 1, "incorrect value for states[7].state, expected 1, is %d", msg->states[7].state);
    fail_unless(msg->states[7].prn == 30, "incorrect value for states[7].prn, expected 30, is %d", msg->states[7].prn);
    fail_unless((msg->states[7].cn0*100 - 12.9713230133*100) < 0.05, "incorrect value for states[7].cn0, expected 12.9713230133, is %f", msg->states[7].cn0);
    fail_unless(msg->states[8].state == 1, "incorrect value for states[8].state, expected 1, is %d", msg->states[8].state);
    fail_unless(msg->states[8].prn == 31, "incorrect value for states[8].prn, expected 31, is %d", msg->states[8].prn);
    fail_unless((msg->states[8].cn0*100 - 15.4814052582*100) < 0.05, "incorrect value for states[8].cn0, expected 15.4814052582, is %f", msg->states[8].cn0);
    fail_unless(msg->states[9].state == 1, "incorrect value for states[9].state, expected 1, is %d", msg->states[9].state);
    fail_unless(msg->states[9].prn == 25, "incorrect value for states[9].prn, expected 25, is %d", msg->states[9].prn);
    fail_unless((msg->states[9].cn0*100 - 3.88343548775*100) < 0.05, "incorrect value for states[9].cn0, expected 3.88343548775, is %f", msg->states[9].cn0);
    fail_unless(msg->states[10].state == 1, "incorrect value for states[10].state, expected 1, is %d", msg->states[10].state);
    fail_unless(msg->states[10].prn == 6, "incorrect value for states[10].prn, expected 6, is %d", msg->states[10].prn);
    fail_unless((msg->states[10].cn0*100 - 4.06148862839*100) < 0.05, "incorrect value for states[10].cn0, expected 4.06148862839, is %f", msg->states[10].cn0);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,141,76,60,65,1,2,69,139,46,65,1,3,146,27,30,65,1,7,235,56,97,65,1,10,141,213,243,64,1,13,250,170,166,64,1,22,17,101,201,64,1,30,172,183,83,65,1,31,238,193,120,65,1,25,220,48,132,64,1,6,49,214,54,64,110,179, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->states[0].state == 1, "incorrect value for states[0].state, expected 1, is %d", msg->states[0].state);
    fail_unless(msg->states[0].prn == 0, "incorrect value for states[0].prn, expected 0, is %d", msg->states[0].prn);
    fail_unless((msg->states[0].cn0*100 - 11.7686891556*100) < 0.05, "incorrect value for states[0].cn0, expected 11.7686891556, is %f", msg->states[0].cn0);
    fail_unless(msg->states[1].state == 1, "incorrect value for states[1].state, expected 1, is %d", msg->states[1].state);
    fail_unless(msg->states[1].prn == 2, "incorrect value for states[1].prn, expected 2, is %d", msg->states[1].prn);
    fail_unless((msg->states[1].cn0*100 - 10.9090013504*100) < 0.05, "incorrect value for states[1].cn0, expected 10.9090013504, is %f", msg->states[1].cn0);
    fail_unless(msg->states[2].state == 1, "incorrect value for states[2].state, expected 1, is %d", msg->states[2].state);
    fail_unless(msg->states[2].prn == 3, "incorrect value for states[2].prn, expected 3, is %d", msg->states[2].prn);
    fail_unless((msg->states[2].cn0*100 - 9.88173103333*100) < 0.05, "incorrect value for states[2].cn0, expected 9.88173103333, is %f", msg->states[2].cn0);
    fail_unless(msg->states[3].state == 1, "incorrect value for states[3].state, expected 1, is %d", msg->states[3].state);
    fail_unless(msg->states[3].prn == 7, "incorrect value for states[3].prn, expected 7, is %d", msg->states[3].prn);
    fail_unless((msg->states[3].cn0*100 - 14.0763959885*100) < 0.05, "incorrect value for states[3].cn0, expected 14.0763959885, is %f", msg->states[3].cn0);
    fail_unless(msg->states[4].state == 1, "incorrect value for states[4].state, expected 1, is %d", msg->states[4].state);
    fail_unless(msg->states[4].prn == 10, "incorrect value for states[4].prn, expected 10, is %d", msg->states[4].prn);
    fail_unless((msg->states[4].cn0*100 - 7.6198182106*100) < 0.05, "incorrect value for states[4].cn0, expected 7.6198182106, is %f", msg->states[4].cn0);
    fail_unless(msg->states[5].state == 1, "incorrect value for states[5].state, expected 1, is %d", msg->states[5].state);
    fail_unless(msg->states[5].prn == 13, "incorrect value for states[5].prn, expected 13, is %d", msg->states[5].prn);
    fail_unless((msg->states[5].cn0*100 - 5.20837116241*100) < 0.05, "incorrect value for states[5].cn0, expected 5.20837116241, is %f", msg->states[5].cn0);
    fail_unless(msg->states[6].state == 1, "incorrect value for states[6].state, expected 1, is %d", msg->states[6].state);
    fail_unless(msg->states[6].prn == 22, "incorrect value for states[6].prn, expected 22, is %d", msg->states[6].prn);
    fail_unless((msg->states[6].cn0*100 - 6.29358720779*100) < 0.05, "incorrect value for states[6].cn0, expected 6.29358720779, is %f", msg->states[6].cn0);
    fail_unless(msg->states[7].state == 1, "incorrect value for states[7].state, expected 1, is %d", msg->states[7].state);
    fail_unless(msg->states[7].prn == 30, "incorrect value for states[7].prn, expected 30, is %d", msg->states[7].prn);
    fail_unless((msg->states[7].cn0*100 - 13.2323417664*100) < 0.05, "incorrect value for states[7].cn0, expected 13.2323417664, is %f", msg->states[7].cn0);
    fail_unless(msg->states[8].state == 1, "incorrect value for states[8].state, expected 1, is %d", msg->states[8].state);
    fail_unless(msg->states[8].prn == 31, "incorrect value for states[8].prn, expected 31, is %d", msg->states[8].prn);
    fail_unless((msg->states[8].cn0*100 - 15.5473461151*100) < 0.05, "incorrect value for states[8].cn0, expected 15.5473461151, is %f", msg->states[8].cn0);
    fail_unless(msg->states[9].state == 1, "incorrect value for states[9].state, expected 1, is %d", msg->states[9].state);
    fail_unless(msg->states[9].prn == 25, "incorrect value for states[9].prn, expected 25, is %d", msg->states[9].prn);
    fail_unless((msg->states[9].cn0*100 - 4.13096427917*100) < 0.05, "incorrect value for states[9].cn0, expected 4.13096427917, is %f", msg->states[9].cn0);
    fail_unless(msg->states[10].state == 1, "incorrect value for states[10].state, expected 1, is %d", msg->states[10].state);
    fail_unless(msg->states[10].prn == 6, "incorrect value for states[10].prn, expected 6, is %d", msg->states[10].prn);
    fail_unless((msg->states[10].cn0*100 - 2.85682320595*100) < 0.05, "incorrect value for states[10].cn0, expected 2.85682320595, is %f", msg->states[10].cn0);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,55,143,120,66,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,248,89, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->states[0].state == 1, "incorrect value for states[0].state, expected 1, is %d", msg->states[0].state);
    fail_unless(msg->states[0].prn == 0, "incorrect value for states[0].prn, expected 0, is %d", msg->states[0].prn);
    fail_unless((msg->states[0].cn0*100 - 62.1398582458*100) < 0.05, "incorrect value for states[0].cn0, expected 62.1398582458, is %f", msg->states[0].cn0);
    fail_unless(msg->states[1].state == 0, "incorrect value for states[1].state, expected 0, is %d", msg->states[1].state);
    fail_unless(msg->states[1].prn == 0, "incorrect value for states[1].prn, expected 0, is %d", msg->states[1].prn);
    fail_unless((msg->states[1].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[1].cn0, expected -1.0, is %f", msg->states[1].cn0);
    fail_unless(msg->states[2].state == 0, "incorrect value for states[2].state, expected 0, is %d", msg->states[2].state);
    fail_unless(msg->states[2].prn == 0, "incorrect value for states[2].prn, expected 0, is %d", msg->states[2].prn);
    fail_unless((msg->states[2].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[2].cn0, expected -1.0, is %f", msg->states[2].cn0);
    fail_unless(msg->states[3].state == 0, "incorrect value for states[3].state, expected 0, is %d", msg->states[3].state);
    fail_unless(msg->states[3].prn == 0, "incorrect value for states[3].prn, expected 0, is %d", msg->states[3].prn);
    fail_unless((msg->states[3].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[3].cn0, expected -1.0, is %f", msg->states[3].cn0);
    fail_unless(msg->states[4].state == 0, "incorrect value for states[4].state, expected 0, is %d", msg->states[4].state);
    fail_unless(msg->states[4].prn == 0, "incorrect value for states[4].prn, expected 0, is %d", msg->states[4].prn);
    fail_unless((msg->states[4].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[4].cn0, expected -1.0, is %f", msg->states[4].cn0);
    fail_unless(msg->states[5].state == 0, "incorrect value for states[5].state, expected 0, is %d", msg->states[5].state);
    fail_unless(msg->states[5].prn == 0, "incorrect value for states[5].prn, expected 0, is %d", msg->states[5].prn);
    fail_unless((msg->states[5].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[5].cn0, expected -1.0, is %f", msg->states[5].cn0);
    fail_unless(msg->states[6].state == 0, "incorrect value for states[6].state, expected 0, is %d", msg->states[6].state);
    fail_unless(msg->states[6].prn == 0, "incorrect value for states[6].prn, expected 0, is %d", msg->states[6].prn);
    fail_unless((msg->states[6].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[6].cn0, expected -1.0, is %f", msg->states[6].cn0);
    fail_unless(msg->states[7].state == 0, "incorrect value for states[7].state, expected 0, is %d", msg->states[7].state);
    fail_unless(msg->states[7].prn == 0, "incorrect value for states[7].prn, expected 0, is %d", msg->states[7].prn);
    fail_unless((msg->states[7].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[7].cn0, expected -1.0, is %f", msg->states[7].cn0);
    fail_unless(msg->states[8].state == 0, "incorrect value for states[8].state, expected 0, is %d", msg->states[8].state);
    fail_unless(msg->states[8].prn == 0, "incorrect value for states[8].prn, expected 0, is %d", msg->states[8].prn);
    fail_unless((msg->states[8].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[8].cn0, expected -1.0, is %f", msg->states[8].cn0);
    fail_unless(msg->states[9].state == 0, "incorrect value for states[9].state, expected 0, is %d", msg->states[9].state);
    fail_unless(msg->states[9].prn == 0, "incorrect value for states[9].prn, expected 0, is %d", msg->states[9].prn);
    fail_unless((msg->states[9].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[9].cn0, expected -1.0, is %f", msg->states[9].cn0);
    fail_unless(msg->states[10].state == 0, "incorrect value for states[10].state, expected 0, is %d", msg->states[10].state);
    fail_unless(msg->states[10].prn == 0, "incorrect value for states[10].prn, expected 0, is %d", msg->states[10].prn);
    fail_unless((msg->states[10].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[10].cn0, expected -1.0, is %f", msg->states[10].cn0);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,218,14,19,66,1,2,210,3,21,65,1,3,234,214,134,65,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,84,101, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->states[0].state == 1, "incorrect value for states[0].state, expected 1, is %d", msg->states[0].state);
    fail_unless(msg->states[0].prn == 0, "incorrect value for states[0].prn, expected 0, is %d", msg->states[0].prn);
    fail_unless((msg->states[0].cn0*100 - 36.764503479*100) < 0.05, "incorrect value for states[0].cn0, expected 36.764503479, is %f", msg->states[0].cn0);
    fail_unless(msg->states[1].state == 1, "incorrect value for states[1].state, expected 1, is %d", msg->states[1].state);
    fail_unless(msg->states[1].prn == 2, "incorrect value for states[1].prn, expected 2, is %d", msg->states[1].prn);
    fail_unless((msg->states[1].cn0*100 - 9.31343269348*100) < 0.05, "incorrect value for states[1].cn0, expected 9.31343269348, is %f", msg->states[1].cn0);
    fail_unless(msg->states[2].state == 1, "incorrect value for states[2].state, expected 1, is %d", msg->states[2].state);
    fail_unless(msg->states[2].prn == 3, "incorrect value for states[2].prn, expected 3, is %d", msg->states[2].prn);
    fail_unless((msg->states[2].cn0*100 - 16.8549385071*100) < 0.05, "incorrect value for states[2].cn0, expected 16.8549385071, is %f", msg->states[2].cn0);
    fail_unless(msg->states[3].state == 0, "incorrect value for states[3].state, expected 0, is %d", msg->states[3].state);
    fail_unless(msg->states[3].prn == 0, "incorrect value for states[3].prn, expected 0, is %d", msg->states[3].prn);
    fail_unless((msg->states[3].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[3].cn0, expected -1.0, is %f", msg->states[3].cn0);
    fail_unless(msg->states[4].state == 0, "incorrect value for states[4].state, expected 0, is %d", msg->states[4].state);
    fail_unless(msg->states[4].prn == 0, "incorrect value for states[4].prn, expected 0, is %d", msg->states[4].prn);
    fail_unless((msg->states[4].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[4].cn0, expected -1.0, is %f", msg->states[4].cn0);
    fail_unless(msg->states[5].state == 0, "incorrect value for states[5].state, expected 0, is %d", msg->states[5].state);
    fail_unless(msg->states[5].prn == 0, "incorrect value for states[5].prn, expected 0, is %d", msg->states[5].prn);
    fail_unless((msg->states[5].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[5].cn0, expected -1.0, is %f", msg->states[5].cn0);
    fail_unless(msg->states[6].state == 0, "incorrect value for states[6].state, expected 0, is %d", msg->states[6].state);
    fail_unless(msg->states[6].prn == 0, "incorrect value for states[6].prn, expected 0, is %d", msg->states[6].prn);
    fail_unless((msg->states[6].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[6].cn0, expected -1.0, is %f", msg->states[6].cn0);
    fail_unless(msg->states[7].state == 0, "incorrect value for states[7].state, expected 0, is %d", msg->states[7].state);
    fail_unless(msg->states[7].prn == 0, "incorrect value for states[7].prn, expected 0, is %d", msg->states[7].prn);
    fail_unless((msg->states[7].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[7].cn0, expected -1.0, is %f", msg->states[7].cn0);
    fail_unless(msg->states[8].state == 0, "incorrect value for states[8].state, expected 0, is %d", msg->states[8].state);
    fail_unless(msg->states[8].prn == 0, "incorrect value for states[8].prn, expected 0, is %d", msg->states[8].prn);
    fail_unless((msg->states[8].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[8].cn0, expected -1.0, is %f", msg->states[8].cn0);
    fail_unless(msg->states[9].state == 0, "incorrect value for states[9].state, expected 0, is %d", msg->states[9].state);
    fail_unless(msg->states[9].prn == 0, "incorrect value for states[9].prn, expected 0, is %d", msg->states[9].prn);
    fail_unless((msg->states[9].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[9].cn0, expected -1.0, is %f", msg->states[9].cn0);
    fail_unless(msg->states[10].state == 0, "incorrect value for states[10].state, expected 0, is %d", msg->states[10].state);
    fail_unless(msg->states[10].prn == 0, "incorrect value for states[10].prn, expected 0, is %d", msg->states[10].prn);
    fail_unless((msg->states[10].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[10].cn0, expected -1.0, is %f", msg->states[10].cn0);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x16, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,22,0,195,4,66,1,0,98,39,219,65,1,2,0,0,56,64,1,3,121,123,7,65,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,37,123, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x16, 1219, sizeof(test_data), test_data, &dummy_write);

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
    msg_tracking_state_dep_a_t* msg = ( msg_tracking_state_dep_a_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->states[0].state == 1, "incorrect value for states[0].state, expected 1, is %d", msg->states[0].state);
    fail_unless(msg->states[0].prn == 0, "incorrect value for states[0].prn, expected 0, is %d", msg->states[0].prn);
    fail_unless((msg->states[0].cn0*100 - 27.3942298889*100) < 0.05, "incorrect value for states[0].cn0, expected 27.3942298889, is %f", msg->states[0].cn0);
    fail_unless(msg->states[1].state == 1, "incorrect value for states[1].state, expected 1, is %d", msg->states[1].state);
    fail_unless(msg->states[1].prn == 2, "incorrect value for states[1].prn, expected 2, is %d", msg->states[1].prn);
    fail_unless((msg->states[1].cn0*100 - 2.875*100) < 0.05, "incorrect value for states[1].cn0, expected 2.875, is %f", msg->states[1].cn0);
    fail_unless(msg->states[2].state == 1, "incorrect value for states[2].state, expected 1, is %d", msg->states[2].state);
    fail_unless(msg->states[2].prn == 3, "incorrect value for states[2].prn, expected 3, is %d", msg->states[2].prn);
    fail_unless((msg->states[2].cn0*100 - 8.46764469147*100) < 0.05, "incorrect value for states[2].cn0, expected 8.46764469147, is %f", msg->states[2].cn0);
    fail_unless(msg->states[3].state == 0, "incorrect value for states[3].state, expected 0, is %d", msg->states[3].state);
    fail_unless(msg->states[3].prn == 0, "incorrect value for states[3].prn, expected 0, is %d", msg->states[3].prn);
    fail_unless((msg->states[3].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[3].cn0, expected -1.0, is %f", msg->states[3].cn0);
    fail_unless(msg->states[4].state == 0, "incorrect value for states[4].state, expected 0, is %d", msg->states[4].state);
    fail_unless(msg->states[4].prn == 0, "incorrect value for states[4].prn, expected 0, is %d", msg->states[4].prn);
    fail_unless((msg->states[4].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[4].cn0, expected -1.0, is %f", msg->states[4].cn0);
    fail_unless(msg->states[5].state == 0, "incorrect value for states[5].state, expected 0, is %d", msg->states[5].state);
    fail_unless(msg->states[5].prn == 0, "incorrect value for states[5].prn, expected 0, is %d", msg->states[5].prn);
    fail_unless((msg->states[5].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[5].cn0, expected -1.0, is %f", msg->states[5].cn0);
    fail_unless(msg->states[6].state == 0, "incorrect value for states[6].state, expected 0, is %d", msg->states[6].state);
    fail_unless(msg->states[6].prn == 0, "incorrect value for states[6].prn, expected 0, is %d", msg->states[6].prn);
    fail_unless((msg->states[6].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[6].cn0, expected -1.0, is %f", msg->states[6].cn0);
    fail_unless(msg->states[7].state == 0, "incorrect value for states[7].state, expected 0, is %d", msg->states[7].state);
    fail_unless(msg->states[7].prn == 0, "incorrect value for states[7].prn, expected 0, is %d", msg->states[7].prn);
    fail_unless((msg->states[7].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[7].cn0, expected -1.0, is %f", msg->states[7].cn0);
    fail_unless(msg->states[8].state == 0, "incorrect value for states[8].state, expected 0, is %d", msg->states[8].state);
    fail_unless(msg->states[8].prn == 0, "incorrect value for states[8].prn, expected 0, is %d", msg->states[8].prn);
    fail_unless((msg->states[8].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[8].cn0, expected -1.0, is %f", msg->states[8].cn0);
    fail_unless(msg->states[9].state == 0, "incorrect value for states[9].state, expected 0, is %d", msg->states[9].state);
    fail_unless(msg->states[9].prn == 0, "incorrect value for states[9].prn, expected 0, is %d", msg->states[9].prn);
    fail_unless((msg->states[9].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[9].cn0, expected -1.0, is %f", msg->states[9].cn0);
    fail_unless(msg->states[10].state == 0, "incorrect value for states[10].state, expected 0, is %d", msg->states[10].state);
    fail_unless(msg->states[10].prn == 0, "incorrect value for states[10].prn, expected 0, is %d", msg->states[10].prn);
    fail_unless((msg->states[10].cn0*100 - -1.0*100) < 0.05, "incorrect value for states[10].cn0, expected -1.0, is %f", msg->states[10].cn0);
  }
}
END_TEST

Suite* auto_check_sbp_tracking_26_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_tracking_26");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_tracking_26");
  tcase_add_test(tc_acq, test_auto_check_sbp_tracking_26);
  suite_add_tcase(s, tc_acq);
  return s;
}