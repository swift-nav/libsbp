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

// This file was auto-generated from /Users/joshuagross/Desktop/Projects/libsbp/spec/tests/yaml/swiftnav/sbp/test_observation.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_observation_20 )
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

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,98,56,158,67,24,46,7,32,56,235,249,121,244,114,255,255,33,46,67,218,0,238,203,70,124,22,25,3,0,98,43,184,157,2,176,133,197,125,126,71,253,255,185,39,68,55,3,60,173,162,131,98,231,253,255,139,30,33,16,10,128,178,248,136,42,113,253,255,40,20,42,71,13,246,246,17,135,255,51,3,0,64,27,108,249,22,210,41,114,118,131,48,255,255,31,52,226,58,30,23,217, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header->n_obs, expected 32");
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838");
    fail_unless(msg->header.t.tow == 407084600, "incorrect value for header.t.tow, expected 407084600");
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

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,20,56,158,67,24,46,7,33,84,52,164,117,102,32,0,0,147,62,62,250,31,234,14, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 33, "incorrect value for header->n_obs, expected 33");
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838");
    fail_unless(msg->header.t.tow == 407084600, "incorrect value for header.t.tow, expected 407084600");
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

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,98,0,159,67,24,46,7,32,32,209,249,121,145,114,255,255,141,45,67,218,0,177,128,70,124,79,27,3,0,159,44,184,157,2,59,135,197,125,175,69,253,255,77,40,68,55,3,211,172,162,131,177,229,253,255,20,31,33,16,10,128,178,248,136,116,111,253,255,94,21,42,71,13,182,173,17,135,37,54,3,0,214,27,108,249,22,91,20,114,118,240,47,255,255,129,52,226,58,30,200,119, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header->n_obs, expected 32");
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838");
    fail_unless(msg->header.t.tow == 407084800, "incorrect value for header.t.tow, expected 407084800");
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

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,20,0,159,67,24,46,7,33,49,19,164,117,120,32,0,0,222,63,62,250,31,11,231, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 33, "incorrect value for header->n_obs, expected 33");
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838");
    fail_unless(msg->header.t.tow == 407084800, "incorrect value for header.t.tow, expected 407084800");
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

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,72,96,162,68,24,46,7,16,87,132,217,121,121,148,255,255,189,43,175,147,0,132,64,200,125,106,31,254,255,1,41,14,177,3,128,178,248,136,70,68,254,255,166,18,184,133,13,24,127,178,134,6,25,2,0,249,28,33,96,22,170,104,86,118,67,112,255,255,203,56,208,88,30,43,107, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 16, "incorrect value for header->n_obs, expected 16");
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838");
    fail_unless(msg->header.t.tow == 407151200, "incorrect value for header.t.tow, expected 407151200");
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

    sbp_register_callback(&sbp_state, 0x45, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,69,0,195,4,72,40,163,68,24,46,7,16,132,107,217,121,14,148,255,255,1,44,175,147,0,129,66,200,125,148,29,254,255,153,41,14,177,3,128,178,248,136,143,66,254,255,222,18,184,133,13,158,53,178,134,42,27,2,0,237,30,33,96,22,38,83,86,118,168,111,255,255,45,56,208,88,30,1,175, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x45, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_obs_dep_a_t* msg = ( msg_obs_dep_a_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 16, "incorrect value for header->n_obs, expected 16");
    fail_unless(msg->header.t.wn == 1838, "incorrect value for header.t.wn, expected 1838");
    fail_unless(msg->header.t.tow == 407151400, "incorrect value for header.t.tow, expected 407151400");
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

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,0,60,190,0,0,0,0,0,186,82,192,0,0,0,0,0,76,109,64,0,0,0,0,0,132,208,190,0,0,0,0,0,254,220,62,0,0,0,0,0,0,113,62,0,0,0,0,0,0,133,190,28,36,25,81,223,254,52,62,220,116,216,39,33,189,3,64,0,0,0,156,177,204,134,63,0,0,160,220,182,33,180,64,152,225,192,44,254,76,238,191,41,150,24,2,148,156,65,190,252,90,119,48,15,215,240,63,124,127,115,94,208,16,238,63,165,115,52,74,97,167,246,189,0,0,0,0,192,180,229,190,0,0,0,0,0,0,112,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,3,0,225,156, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    sprintf(errStr, "incorrect value for dn, expected 4.88841790794e-09, is %d %f", (int)msg->dn, (float)msg->dn);
    fail_unless(msg->dn == 4.88841790794e-09, errStr);
    sprintf(errStr, "incorrect value for toc_wn, expected 1838, is %d %f", (int)msg->toc_wn, (float)msg->toc_wn);
    fail_unless(msg->toc_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for c_is, expected -1.56462192535e-07, is %d %f", (int)msg->c_is, (float)msg->c_is);
    fail_unless(msg->c_is == -1.56462192535e-07, errStr);
    sprintf(errStr, "incorrect value for c_ic, expected 6.33299350739e-08, is %d %f", (int)msg->c_ic, (float)msg->c_ic);
    fail_unless(msg->c_ic == 6.33299350739e-08, errStr);
    sprintf(errStr, "incorrect value for c_rs, expected -74.90625, is %d %f", (int)msg->c_rs, (float)msg->c_rs);
    fail_unless(msg->c_rs == -74.90625, errStr);
    sprintf(errStr, "incorrect value for toe_wn, expected 1838, is %d %f", (int)msg->toe_wn, (float)msg->toe_wn);
    fail_unless(msg->toe_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for prn, expected 3, is %d %f", (int)msg->prn, (float)msg->prn);
    fail_unless(msg->prn == 3, errStr);
    sprintf(errStr, "incorrect value for inc_dot, expected -3.29656588663e-10, is %d %f", (int)msg->inc_dot, (float)msg->inc_dot);
    fail_unless(msg->inc_dot == -3.29656588663e-10, errStr);
    sprintf(errStr, "incorrect value for tgd, expected -6.51925802231e-09, is %d %f", (int)msg->tgd, (float)msg->tgd);
    fail_unless(msg->tgd == -6.51925802231e-09, errStr);
    sprintf(errStr, "incorrect value for c_rc, expected 234.375, is %d %f", (int)msg->c_rc, (float)msg->c_rc);
    fail_unless(msg->c_rc == 234.375, errStr);
    sprintf(errStr, "incorrect value for ecc, expected 0.0111326099141, is %d %f", (int)msg->ecc, (float)msg->ecc);
    fail_unless(msg->ecc == 0.0111326099141, errStr);
    sprintf(errStr, "incorrect value for sqrta, expected 5153.71430397, is %d %f", (int)msg->sqrta, (float)msg->sqrta);
    fail_unless(msg->sqrta == 5153.71430397, errStr);
    sprintf(errStr, "incorrect value for omegadot, expected -8.20105589261e-09, is %d %f", (int)msg->omegadot, (float)msg->omegadot);
    fail_unless(msg->omegadot == -8.20105589261e-09, errStr);
    sprintf(errStr, "incorrect value for inc, expected 0.939552483058, is %d %f", (int)msg->inc, (float)msg->inc);
    fail_unless(msg->inc == 0.939552483058, errStr);
    sprintf(errStr, "incorrect value for toe_tow, expected 410400.0, is %d %f", (int)msg->toe_tow, (float)msg->toe_tow);
    fail_unless(msg->toe_tow == 410400.0, errStr);
    sprintf(errStr, "incorrect value for c_uc, expected -3.93763184547e-06, is %d %f", (int)msg->c_uc, (float)msg->c_uc);
    fail_unless(msg->c_uc == -3.93763184547e-06, errStr);
    sprintf(errStr, "incorrect value for healthy, expected 1, is %d %f", (int)msg->healthy, (float)msg->healthy);
    fail_unless(msg->healthy == 1, errStr);
    sprintf(errStr, "incorrect value for iode, expected 0, is %d %f", (int)msg->iode, (float)msg->iode);
    fail_unless(msg->iode == 0, errStr);
    sprintf(errStr, "incorrect value for omega0, expected -0.946898543748, is %d %f", (int)msg->omega0, (float)msg->omega0);
    fail_unless(msg->omega0 == -0.946898543748, errStr);
    sprintf(errStr, "incorrect value for c_us, expected 6.9122761488e-06, is %d %f", (int)msg->c_us, (float)msg->c_us);
    fail_unless(msg->c_us == 6.9122761488e-06, errStr);
    sprintf(errStr, "incorrect value for valid, expected 1, is %d %f", (int)msg->valid, (float)msg->valid);
    fail_unless(msg->valid == 1, errStr);
    sprintf(errStr, "incorrect value for af2, expected 0.0, is %d %f", (int)msg->af2, (float)msg->af2);
    fail_unless(msg->af2 == 0.0, errStr);
    sprintf(errStr, "incorrect value for m0, expected 2.46734839563, is %d %f", (int)msg->m0, (float)msg->m0);
    fail_unless(msg->m0 == 2.46734839563, errStr);
    sprintf(errStr, "incorrect value for w, expected 1.05250472004, is %d %f", (int)msg->w, (float)msg->w);
    fail_unless(msg->w == 1.05250472004, errStr);
    sprintf(errStr, "incorrect value for af0, expected -1.0350253433e-05, is %d %f", (int)msg->af0, (float)msg->af0);
    fail_unless(msg->af0 == -1.0350253433e-05, errStr);
    sprintf(errStr, "incorrect value for af1, expected -9.09494701773e-13, is %d %f", (int)msg->af1, (float)msg->af1);
    fail_unless(msg->af1 == -9.09494701773e-13, errStr);
    sprintf(errStr, "incorrect value for toc_tow, expected 410400.0, is %d %f", (int)msg->toc_tow, (float)msg->toc_tow);
    fail_unless(msg->toc_tow == 410400.0, errStr);
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

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,0,68,190,0,0,0,0,0,72,66,64,0,0,0,0,128,188,115,64,0,0,0,0,0,80,193,62,0,0,0,0,0,164,204,62,0,0,0,0,0,0,130,62,0,0,0,0,0,0,128,62,72,181,127,6,208,225,52,62,158,174,129,91,27,105,249,191,0,0,0,96,204,57,128,63,0,0,160,35,146,33,180,64,247,169,1,36,133,206,243,63,79,11,109,92,156,208,65,190,103,78,3,253,223,147,255,191,164,214,90,250,218,240,238,63,94,239,187,37,36,10,242,61,0,0,0,0,176,91,19,63,0,0,0,0,0,0,137,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,13,0,180,21, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    sprintf(errStr, "incorrect value for dn, expected 4.86198823561e-09, is %d %f", (int)msg->dn, (float)msg->dn);
    fail_unless(msg->dn == 4.86198823561e-09, errStr);
    sprintf(errStr, "incorrect value for toc_wn, expected 1838, is %d %f", (int)msg->toc_wn, (float)msg->toc_wn);
    fail_unless(msg->toc_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for c_is, expected 1.19209289551e-07, is %d %f", (int)msg->c_is, (float)msg->c_is);
    fail_unless(msg->c_is == 1.19209289551e-07, errStr);
    sprintf(errStr, "incorrect value for c_ic, expected 1.34110450745e-07, is %d %f", (int)msg->c_ic, (float)msg->c_ic);
    fail_unless(msg->c_ic == 1.34110450745e-07, errStr);
    sprintf(errStr, "incorrect value for c_rs, expected 36.5625, is %d %f", (int)msg->c_rs, (float)msg->c_rs);
    fail_unless(msg->c_rs == 36.5625, errStr);
    sprintf(errStr, "incorrect value for toe_wn, expected 1838, is %d %f", (int)msg->toe_wn, (float)msg->toe_wn);
    fail_unless(msg->toe_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for prn, expected 13, is %d %f", (int)msg->prn, (float)msg->prn);
    fail_unless(msg->prn == 13, errStr);
    sprintf(errStr, "incorrect value for inc_dot, expected 2.62510934634e-10, is %d %f", (int)msg->inc_dot, (float)msg->inc_dot);
    fail_unless(msg->inc_dot == 2.62510934634e-10, errStr);
    sprintf(errStr, "incorrect value for tgd, expected -9.31322574615e-09, is %d %f", (int)msg->tgd, (float)msg->tgd);
    fail_unless(msg->tgd == -9.31322574615e-09, errStr);
    sprintf(errStr, "incorrect value for c_rc, expected 315.78125, is %d %f", (int)msg->c_rc, (float)msg->c_rc);
    fail_unless(msg->c_rc == 315.78125, errStr);
    sprintf(errStr, "incorrect value for ecc, expected 0.00792274158448, is %d %f", (int)msg->ecc, (float)msg->ecc);
    fail_unless(msg->ecc == 0.00792274158448, errStr);
    sprintf(errStr, "incorrect value for sqrta, expected 5153.57085609, is %d %f", (int)msg->sqrta, (float)msg->sqrta);
    fail_unless(msg->sqrta == 5153.57085609, errStr);
    sprintf(errStr, "incorrect value for omegadot, expected -8.29570269217e-09, is %d %f", (int)msg->omegadot, (float)msg->omegadot);
    fail_unless(msg->omegadot == -8.29570269217e-09, errStr);
    sprintf(errStr, "incorrect value for inc, expected 0.966901291823, is %d %f", (int)msg->inc, (float)msg->inc);
    fail_unless(msg->inc == 0.966901291823, errStr);
    sprintf(errStr, "incorrect value for toe_tow, expected 410400.0, is %d %f", (int)msg->toe_tow, (float)msg->toe_tow);
    fail_unless(msg->toe_tow == 410400.0, errStr);
    sprintf(errStr, "incorrect value for c_uc, expected 2.06381082535e-06, is %d %f", (int)msg->c_uc, (float)msg->c_uc);
    fail_unless(msg->c_uc == 2.06381082535e-06, errStr);
    sprintf(errStr, "incorrect value for healthy, expected 1, is %d %f", (int)msg->healthy, (float)msg->healthy);
    fail_unless(msg->healthy == 1, errStr);
    sprintf(errStr, "incorrect value for iode, expected 0, is %d %f", (int)msg->iode, (float)msg->iode);
    fail_unless(msg->iode == 0, errStr);
    sprintf(errStr, "incorrect value for omega0, expected 1.23791994157, is %d %f", (int)msg->omega0, (float)msg->omega0);
    fail_unless(msg->omega0 == 1.23791994157, errStr);
    sprintf(errStr, "incorrect value for c_us, expected 3.41422855854e-06, is %d %f", (int)msg->c_us, (float)msg->c_us);
    fail_unless(msg->c_us == 3.41422855854e-06, errStr);
    sprintf(errStr, "incorrect value for valid, expected 1, is %d %f", (int)msg->valid, (float)msg->valid);
    fail_unless(msg->valid == 1, errStr);
    sprintf(errStr, "incorrect value for af2, expected 0.0, is %d %f", (int)msg->af2, (float)msg->af2);
    fail_unless(msg->af2 == 0.0, errStr);
    sprintf(errStr, "incorrect value for m0, expected -1.58816085572, is %d %f", (int)msg->m0, (float)msg->m0);
    fail_unless(msg->m0 == -1.58816085572, errStr);
    sprintf(errStr, "incorrect value for w, expected -1.97360228379, is %d %f", (int)msg->w, (float)msg->w);
    fail_unless(msg->w == -1.97360228379, errStr);
    sprintf(errStr, "incorrect value for af0, expected 7.38454982638e-05, is %d %f", (int)msg->af0, (float)msg->af0);
    fail_unless(msg->af0 == 7.38454982638e-05, errStr);
    sprintf(errStr, "incorrect value for af1, expected -2.84217094304e-12, is %d %f", (int)msg->af1, (float)msg->af1);
    fail_unless(msg->af1 == -2.84217094304e-12, errStr);
    sprintf(errStr, "incorrect value for toc_tow, expected 410400.0, is %d %f", (int)msg->toc_tow, (float)msg->toc_tow);
    fail_unless(msg->toc_tow == 410400.0, errStr);
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

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,0,56,62,0,0,0,0,0,40,81,192,0,0,0,0,0,129,109,64,0,0,0,0,0,28,205,190,0,0,0,0,0,76,223,62,0,0,0,0,0,0,105,190,0,0,0,0,0,0,92,190,134,161,223,255,243,43,51,62,146,176,113,142,234,164,5,64,0,0,0,56,175,140,112,63,0,0,192,90,171,33,180,64,36,38,237,255,200,160,237,191,204,92,63,154,49,91,65,190,125,94,251,132,52,61,216,63,2,139,28,27,231,199,238,63,124,183,4,180,194,30,247,189,0,0,0,0,0,104,222,190,0,0,0,0,0,0,96,61,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,0,0,222,152, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    sprintf(errStr, "incorrect value for dn, expected 4.46375736198e-09, is %d %f", (int)msg->dn, (float)msg->dn);
    fail_unless(msg->dn == 4.46375736198e-09, errStr);
    sprintf(errStr, "incorrect value for toc_wn, expected 1838, is %d %f", (int)msg->toc_wn, (float)msg->toc_wn);
    fail_unless(msg->toc_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for c_is, expected -2.60770320892e-08, is %d %f", (int)msg->c_is, (float)msg->c_is);
    fail_unless(msg->c_is == -2.60770320892e-08, errStr);
    sprintf(errStr, "incorrect value for c_ic, expected -4.65661287308e-08, is %d %f", (int)msg->c_ic, (float)msg->c_ic);
    fail_unless(msg->c_ic == -4.65661287308e-08, errStr);
    sprintf(errStr, "incorrect value for c_rs, expected -68.625, is %d %f", (int)msg->c_rs, (float)msg->c_rs);
    fail_unless(msg->c_rs == -68.625, errStr);
    sprintf(errStr, "incorrect value for toe_wn, expected 1838, is %d %f", (int)msg->toe_wn, (float)msg->toe_wn);
    fail_unless(msg->toe_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for prn, expected 0, is %d %f", (int)msg->prn, (float)msg->prn);
    fail_unless(msg->prn == 0, errStr);
    sprintf(errStr, "incorrect value for inc_dot, expected -3.36442585613e-10, is %d %f", (int)msg->inc_dot, (float)msg->inc_dot);
    fail_unless(msg->inc_dot == -3.36442585613e-10, errStr);
    sprintf(errStr, "incorrect value for tgd, expected 5.58793544769e-09, is %d %f", (int)msg->tgd, (float)msg->tgd);
    fail_unless(msg->tgd == 5.58793544769e-09, errStr);
    sprintf(errStr, "incorrect value for c_rc, expected 236.03125, is %d %f", (int)msg->c_rc, (float)msg->c_rc);
    fail_unless(msg->c_rc == 236.03125, errStr);
    sprintf(errStr, "incorrect value for ecc, expected 0.00404041714501, is %d %f", (int)msg->ecc, (float)msg->ecc);
    fail_unless(msg->ecc == 0.00404041714501, errStr);
    sprintf(errStr, "incorrect value for sqrta, expected 5153.66935349, is %d %f", (int)msg->sqrta, (float)msg->sqrta);
    fail_unless(msg->sqrta == 5153.66935349, errStr);
    sprintf(errStr, "incorrect value for omegadot, expected -8.08212236712e-09, is %d %f", (int)msg->omegadot, (float)msg->omegadot);
    fail_unless(msg->omegadot == -8.08212236712e-09, errStr);
    sprintf(errStr, "incorrect value for inc, expected 0.96190219207, is %d %f", (int)msg->inc, (float)msg->inc);
    fail_unless(msg->inc == 0.96190219207, errStr);
    sprintf(errStr, "incorrect value for toe_tow, expected 410400.0, is %d %f", (int)msg->toe_tow, (float)msg->toe_tow);
    fail_unless(msg->toe_tow == 410400.0, errStr);
    sprintf(errStr, "incorrect value for c_uc, expected -3.47010791302e-06, is %d %f", (int)msg->c_uc, (float)msg->c_uc);
    fail_unless(msg->c_uc == -3.47010791302e-06, errStr);
    sprintf(errStr, "incorrect value for healthy, expected 1, is %d %f", (int)msg->healthy, (float)msg->healthy);
    fail_unless(msg->healthy == 1, errStr);
    sprintf(errStr, "incorrect value for iode, expected 0, is %d %f", (int)msg->iode, (float)msg->iode);
    fail_unless(msg->iode == 0, errStr);
    sprintf(errStr, "incorrect value for omega0, expected -0.925877094132, is %d %f", (int)msg->omega0, (float)msg->omega0);
    fail_unless(msg->omega0 == -0.925877094132, errStr);
    sprintf(errStr, "incorrect value for c_us, expected 7.46175646782e-06, is %d %f", (int)msg->c_us, (float)msg->c_us);
    fail_unless(msg->c_us == 7.46175646782e-06, errStr);
    sprintf(errStr, "incorrect value for valid, expected 1, is %d %f", (int)msg->valid, (float)msg->valid);
    fail_unless(msg->valid == 1, errStr);
    sprintf(errStr, "incorrect value for af2, expected 0.0, is %d %f", (int)msg->af2, (float)msg->af2);
    fail_unless(msg->af2 == 0.0, errStr);
    sprintf(errStr, "incorrect value for m0, expected 2.70552550587, is %d %f", (int)msg->m0, (float)msg->m0);
    fail_unless(msg->m0 == 2.70552550587, errStr);
    sprintf(errStr, "incorrect value for w, expected 0.378735666146, is %d %f", (int)msg->w, (float)msg->w);
    fail_unless(msg->w == 0.378735666146, errStr);
    sprintf(errStr, "incorrect value for af0, expected -7.24941492081e-06, is %d %f", (int)msg->af0, (float)msg->af0);
    fail_unless(msg->af0 == -7.24941492081e-06, errStr);
    sprintf(errStr, "incorrect value for af1, expected 4.54747350886e-13, is %d %f", (int)msg->af1, (float)msg->af1);
    fail_unless(msg->af1 == 4.54747350886e-13, errStr);
    sprintf(errStr, "incorrect value for toc_tow, expected 410400.0, is %d %f", (int)msg->toc_tow, (float)msg->toc_tow);
    fail_unless(msg->toc_tow == 410400.0, errStr);
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

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,0,68,190,0,0,0,0,0,72,66,64,0,0,0,0,128,188,115,64,0,0,0,0,0,80,193,62,0,0,0,0,0,164,204,62,0,0,0,0,0,0,130,62,0,0,0,0,0,0,128,62,72,181,127,6,208,225,52,62,158,174,129,91,27,105,249,191,0,0,0,96,204,57,128,63,0,0,160,35,146,33,180,64,247,169,1,36,133,206,243,63,79,11,109,92,156,208,65,190,103,78,3,253,223,147,255,191,164,214,90,250,218,240,238,63,94,239,187,37,36,10,242,61,0,0,0,0,176,91,19,63,0,0,0,0,0,0,137,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,13,0,180,21, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    sprintf(errStr, "incorrect value for dn, expected 4.86198823561e-09, is %d %f", (int)msg->dn, (float)msg->dn);
    fail_unless(msg->dn == 4.86198823561e-09, errStr);
    sprintf(errStr, "incorrect value for toc_wn, expected 1838, is %d %f", (int)msg->toc_wn, (float)msg->toc_wn);
    fail_unless(msg->toc_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for c_is, expected 1.19209289551e-07, is %d %f", (int)msg->c_is, (float)msg->c_is);
    fail_unless(msg->c_is == 1.19209289551e-07, errStr);
    sprintf(errStr, "incorrect value for c_ic, expected 1.34110450745e-07, is %d %f", (int)msg->c_ic, (float)msg->c_ic);
    fail_unless(msg->c_ic == 1.34110450745e-07, errStr);
    sprintf(errStr, "incorrect value for c_rs, expected 36.5625, is %d %f", (int)msg->c_rs, (float)msg->c_rs);
    fail_unless(msg->c_rs == 36.5625, errStr);
    sprintf(errStr, "incorrect value for toe_wn, expected 1838, is %d %f", (int)msg->toe_wn, (float)msg->toe_wn);
    fail_unless(msg->toe_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for prn, expected 13, is %d %f", (int)msg->prn, (float)msg->prn);
    fail_unless(msg->prn == 13, errStr);
    sprintf(errStr, "incorrect value for inc_dot, expected 2.62510934634e-10, is %d %f", (int)msg->inc_dot, (float)msg->inc_dot);
    fail_unless(msg->inc_dot == 2.62510934634e-10, errStr);
    sprintf(errStr, "incorrect value for tgd, expected -9.31322574615e-09, is %d %f", (int)msg->tgd, (float)msg->tgd);
    fail_unless(msg->tgd == -9.31322574615e-09, errStr);
    sprintf(errStr, "incorrect value for c_rc, expected 315.78125, is %d %f", (int)msg->c_rc, (float)msg->c_rc);
    fail_unless(msg->c_rc == 315.78125, errStr);
    sprintf(errStr, "incorrect value for ecc, expected 0.00792274158448, is %d %f", (int)msg->ecc, (float)msg->ecc);
    fail_unless(msg->ecc == 0.00792274158448, errStr);
    sprintf(errStr, "incorrect value for sqrta, expected 5153.57085609, is %d %f", (int)msg->sqrta, (float)msg->sqrta);
    fail_unless(msg->sqrta == 5153.57085609, errStr);
    sprintf(errStr, "incorrect value for omegadot, expected -8.29570269217e-09, is %d %f", (int)msg->omegadot, (float)msg->omegadot);
    fail_unless(msg->omegadot == -8.29570269217e-09, errStr);
    sprintf(errStr, "incorrect value for inc, expected 0.966901291823, is %d %f", (int)msg->inc, (float)msg->inc);
    fail_unless(msg->inc == 0.966901291823, errStr);
    sprintf(errStr, "incorrect value for toe_tow, expected 410400.0, is %d %f", (int)msg->toe_tow, (float)msg->toe_tow);
    fail_unless(msg->toe_tow == 410400.0, errStr);
    sprintf(errStr, "incorrect value for c_uc, expected 2.06381082535e-06, is %d %f", (int)msg->c_uc, (float)msg->c_uc);
    fail_unless(msg->c_uc == 2.06381082535e-06, errStr);
    sprintf(errStr, "incorrect value for healthy, expected 1, is %d %f", (int)msg->healthy, (float)msg->healthy);
    fail_unless(msg->healthy == 1, errStr);
    sprintf(errStr, "incorrect value for iode, expected 0, is %d %f", (int)msg->iode, (float)msg->iode);
    fail_unless(msg->iode == 0, errStr);
    sprintf(errStr, "incorrect value for omega0, expected 1.23791994157, is %d %f", (int)msg->omega0, (float)msg->omega0);
    fail_unless(msg->omega0 == 1.23791994157, errStr);
    sprintf(errStr, "incorrect value for c_us, expected 3.41422855854e-06, is %d %f", (int)msg->c_us, (float)msg->c_us);
    fail_unless(msg->c_us == 3.41422855854e-06, errStr);
    sprintf(errStr, "incorrect value for valid, expected 1, is %d %f", (int)msg->valid, (float)msg->valid);
    fail_unless(msg->valid == 1, errStr);
    sprintf(errStr, "incorrect value for af2, expected 0.0, is %d %f", (int)msg->af2, (float)msg->af2);
    fail_unless(msg->af2 == 0.0, errStr);
    sprintf(errStr, "incorrect value for m0, expected -1.58816085572, is %d %f", (int)msg->m0, (float)msg->m0);
    fail_unless(msg->m0 == -1.58816085572, errStr);
    sprintf(errStr, "incorrect value for w, expected -1.97360228379, is %d %f", (int)msg->w, (float)msg->w);
    fail_unless(msg->w == -1.97360228379, errStr);
    sprintf(errStr, "incorrect value for af0, expected 7.38454982638e-05, is %d %f", (int)msg->af0, (float)msg->af0);
    fail_unless(msg->af0 == 7.38454982638e-05, errStr);
    sprintf(errStr, "incorrect value for af1, expected -2.84217094304e-12, is %d %f", (int)msg->af1, (float)msg->af1);
    fail_unless(msg->af1 == -2.84217094304e-12, errStr);
    sprintf(errStr, "incorrect value for toc_tow, expected 410400.0, is %d %f", (int)msg->toc_tow, (float)msg->toc_tow);
    fail_unless(msg->toc_tow == 410400.0, errStr);
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

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,128,85,190,0,0,0,0,0,156,69,64,0,0,0,0,128,19,115,64,0,0,0,0,0,160,193,62,0,0,0,0,0,152,207,62,0,0,0,0,0,0,97,190,0,0,0,0,0,192,139,190,26,26,13,149,16,152,54,62,104,7,46,214,75,84,5,192,0,0,0,128,230,82,132,63,0,0,160,252,162,33,180,64,73,6,130,54,217,171,242,63,81,224,163,123,238,42,66,190,206,43,141,67,243,157,5,192,113,179,153,187,43,92,238,63,254,236,31,43,224,157,244,61,0,0,0,0,232,4,26,191,0,0,0,0,0,0,134,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,22,0,99,61, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    sprintf(errStr, "incorrect value for dn, expected 5.26057626697e-09, is %d %f", (int)msg->dn, (float)msg->dn);
    fail_unless(msg->dn == 5.26057626697e-09, errStr);
    sprintf(errStr, "incorrect value for toc_wn, expected 1838, is %d %f", (int)msg->toc_wn, (float)msg->toc_wn);
    fail_unless(msg->toc_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for c_is, expected -2.06753611565e-07, is %d %f", (int)msg->c_is, (float)msg->c_is);
    fail_unless(msg->c_is == -2.06753611565e-07, errStr);
    sprintf(errStr, "incorrect value for c_ic, expected -3.16649675369e-08, is %d %f", (int)msg->c_ic, (float)msg->c_ic);
    fail_unless(msg->c_ic == -3.16649675369e-08, errStr);
    sprintf(errStr, "incorrect value for c_rs, expected 43.21875, is %d %f", (int)msg->c_rs, (float)msg->c_rs);
    fail_unless(msg->c_rs == 43.21875, errStr);
    sprintf(errStr, "incorrect value for toe_wn, expected 1838, is %d %f", (int)msg->toe_wn, (float)msg->toe_wn);
    fail_unless(msg->toe_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for prn, expected 22, is %d %f", (int)msg->prn, (float)msg->prn);
    fail_unless(msg->prn == 22, errStr);
    sprintf(errStr, "incorrect value for inc_dot, expected 3.00012496725e-10, is %d %f", (int)msg->inc_dot, (float)msg->inc_dot);
    fail_unless(msg->inc_dot == 3.00012496725e-10, errStr);
    sprintf(errStr, "incorrect value for tgd, expected -2.00234353542e-08, is %d %f", (int)msg->tgd, (float)msg->tgd);
    fail_unless(msg->tgd == -2.00234353542e-08, errStr);
    sprintf(errStr, "incorrect value for c_rc, expected 305.21875, is %d %f", (int)msg->c_rc, (float)msg->c_rc);
    fail_unless(msg->c_rc == 305.21875, errStr);
    sprintf(errStr, "incorrect value for ecc, expected 0.00992374494672, is %d %f", (int)msg->ecc, (float)msg->ecc);
    fail_unless(msg->ecc == 0.00992374494672, errStr);
    sprintf(errStr, "incorrect value for sqrta, expected 5153.63666725, is %d %f", (int)msg->sqrta, (float)msg->sqrta);
    fail_unless(msg->sqrta == 5153.63666725, errStr);
    sprintf(errStr, "incorrect value for omegadot, expected -8.4599952499e-09, is %d %f", (int)msg->omegadot, (float)msg->omegadot);
    fail_unless(msg->omegadot == -8.4599952499e-09, errStr);
    sprintf(errStr, "incorrect value for inc, expected 0.948751322181, is %d %f", (int)msg->inc, (float)msg->inc);
    fail_unless(msg->inc == 0.948751322181, errStr);
    sprintf(errStr, "incorrect value for toe_tow, expected 410400.0, is %d %f", (int)msg->toe_tow, (float)msg->toe_tow);
    fail_unless(msg->toe_tow == 410400.0, errStr);
    sprintf(errStr, "incorrect value for c_uc, expected 2.10106372833e-06, is %d %f", (int)msg->c_uc, (float)msg->c_uc);
    fail_unless(msg->c_uc == 2.10106372833e-06, errStr);
    sprintf(errStr, "incorrect value for healthy, expected 1, is %d %f", (int)msg->healthy, (float)msg->healthy);
    fail_unless(msg->healthy == 1, errStr);
    sprintf(errStr, "incorrect value for iode, expected 0, is %d %f", (int)msg->iode, (float)msg->iode);
    fail_unless(msg->iode == 0, errStr);
    sprintf(errStr, "incorrect value for omega0, expected 1.16695519726, is %d %f", (int)msg->omega0, (float)msg->omega0);
    fail_unless(msg->omega0 == 1.16695519726, errStr);
    sprintf(errStr, "incorrect value for c_us, expected 3.76626849174e-06, is %d %f", (int)msg->c_us, (float)msg->c_us);
    fail_unless(msg->c_us == 3.76626849174e-06, errStr);
    sprintf(errStr, "incorrect value for valid, expected 1, is %d %f", (int)msg->valid, (float)msg->valid);
    fail_unless(msg->valid == 1, errStr);
    sprintf(errStr, "incorrect value for af2, expected 0.0, is %d %f", (int)msg->af2, (float)msg->af2);
    fail_unless(msg->af2 == 0.0, errStr);
    sprintf(errStr, "incorrect value for m0, expected -2.66616027191, is %d %f", (int)msg->m0, (float)msg->m0);
    fail_unless(msg->m0 == -2.66616027191, errStr);
    sprintf(errStr, "incorrect value for w, expected -2.70212414527, is %d %f", (int)msg->w, (float)msg->w);
    fail_unless(msg->w == -2.70212414527, errStr);
    sprintf(errStr, "incorrect value for af0, expected -9.92552377284e-05, is %d %f", (int)msg->af0, (float)msg->af0);
    fail_unless(msg->af0 == -9.92552377284e-05, errStr);
    sprintf(errStr, "incorrect value for af1, expected -2.50111042988e-12, is %d %f", (int)msg->af1, (float)msg->af1);
    fail_unless(msg->af1 == -2.50111042988e-12, errStr);
    sprintf(errStr, "incorrect value for toc_tow, expected 410400.0, is %d %f", (int)msg->toc_tow, (float)msg->toc_tow);
    fail_unless(msg->toc_tow == 410400.0, errStr);
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

    sbp_register_callback(&sbp_state, 0x46, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,70,0,195,4,176,0,0,0,0,0,0,77,190,0,0,0,0,0,122,83,192,0,0,0,0,0,233,110,64,0,0,0,0,0,60,207,190,0,0,0,0,0,28,222,62,0,0,0,0,0,128,120,62,0,0,0,0,0,0,108,62,10,230,183,140,214,230,50,62,54,86,196,164,252,10,255,63,0,0,0,36,247,191,128,63,0,0,160,5,193,33,180,64,186,138,81,129,88,239,1,64,94,210,120,170,106,25,65,190,103,213,32,155,227,194,224,191,156,47,104,93,101,55,239,63,196,83,100,254,51,54,4,190,0,0,0,0,50,242,52,63,0,0,0,0,0,0,114,189,0,0,0,0,0,0,0,0,0,0,0,0,128,12,25,65,46,7,0,0,0,0,128,12,25,65,46,7,1,1,30,0,170,33, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x46, 1219, sizeof(test_data), test_data, &dummy_write);

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

    // Cast to expected message type
    char *errStr = (char *)malloc(500);
    msg_ephemeris_dep_b_t* msg = ( msg_ephemeris_dep_b_t *)last_msg;
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    sprintf(errStr, "incorrect value for dn, expected 4.40089760076e-09, is %d %f", (int)msg->dn, (float)msg->dn);
    fail_unless(msg->dn == 4.40089760076e-09, errStr);
    sprintf(errStr, "incorrect value for toc_wn, expected 1838, is %d %f", (int)msg->toc_wn, (float)msg->toc_wn);
    fail_unless(msg->toc_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for c_is, expected 5.21540641785e-08, is %d %f", (int)msg->c_is, (float)msg->c_is);
    fail_unless(msg->c_is == 5.21540641785e-08, errStr);
    sprintf(errStr, "incorrect value for c_ic, expected 9.12696123123e-08, is %d %f", (int)msg->c_ic, (float)msg->c_ic);
    fail_unless(msg->c_ic == 9.12696123123e-08, errStr);
    sprintf(errStr, "incorrect value for c_rs, expected -77.90625, is %d %f", (int)msg->c_rs, (float)msg->c_rs);
    fail_unless(msg->c_rs == -77.90625, errStr);
    sprintf(errStr, "incorrect value for toe_wn, expected 1838, is %d %f", (int)msg->toe_wn, (float)msg->toe_wn);
    fail_unless(msg->toe_wn == 1838, errStr);
    sprintf(errStr, "incorrect value for prn, expected 30, is %d %f", (int)msg->prn, (float)msg->prn);
    fail_unless(msg->prn == 30, errStr);
    sprintf(errStr, "incorrect value for inc_dot, expected -5.88238788221e-10, is %d %f", (int)msg->inc_dot, (float)msg->inc_dot);
    fail_unless(msg->inc_dot == -5.88238788221e-10, errStr);
    sprintf(errStr, "incorrect value for tgd, expected -1.35041773319e-08, is %d %f", (int)msg->tgd, (float)msg->tgd);
    fail_unless(msg->tgd == -1.35041773319e-08, errStr);
    sprintf(errStr, "incorrect value for c_rc, expected 247.28125, is %d %f", (int)msg->c_rc, (float)msg->c_rc);
    fail_unless(msg->c_rc == 247.28125, errStr);
    sprintf(errStr, "incorrect value for ecc, expected 0.00817864493001, is %d %f", (int)msg->ecc, (float)msg->ecc);
    fail_unless(msg->ecc == 0.00817864493001, errStr);
    sprintf(errStr, "incorrect value for sqrta, expected 5153.75399208, is %d %f", (int)msg->sqrta, (float)msg->sqrta);
    fail_unless(msg->sqrta == 5153.75399208, errStr);
    sprintf(errStr, "incorrect value for omegadot, expected -7.96247452617e-09, is %d %f", (int)msg->omegadot, (float)msg->omegadot);
    fail_unless(msg->omegadot == -7.96247452617e-09, errStr);
    sprintf(errStr, "incorrect value for inc, expected 0.975512201725, is %d %f", (int)msg->inc, (float)msg->inc);
    fail_unless(msg->inc == 0.975512201725, errStr);
    sprintf(errStr, "incorrect value for toe_tow, expected 410400.0, is %d %f", (int)msg->toe_tow, (float)msg->toe_tow);
    fail_unless(msg->toe_tow == 410400.0, errStr);
    sprintf(errStr, "incorrect value for c_uc, expected -3.72342765331e-06, is %d %f", (int)msg->c_uc, (float)msg->c_uc);
    fail_unless(msg->c_uc == -3.72342765331e-06, errStr);
    sprintf(errStr, "incorrect value for healthy, expected 1, is %d %f", (int)msg->healthy, (float)msg->healthy);
    fail_unless(msg->healthy == 1, errStr);
    sprintf(errStr, "incorrect value for iode, expected 0, is %d %f", (int)msg->iode, (float)msg->iode);
    fail_unless(msg->iode == 0, errStr);
    sprintf(errStr, "incorrect value for omega0, expected 2.24186802893, is %d %f", (int)msg->omega0, (float)msg->omega0);
    fail_unless(msg->omega0 == 2.24186802893, errStr);
    sprintf(errStr, "incorrect value for c_us, expected 7.17863440514e-06, is %d %f", (int)msg->c_us, (float)msg->c_us);
    fail_unless(msg->c_us == 7.17863440514e-06, errStr);
    sprintf(errStr, "incorrect value for valid, expected 1, is %d %f", (int)msg->valid, (float)msg->valid);
    fail_unless(msg->valid == 1, errStr);
    sprintf(errStr, "incorrect value for af2, expected 0.0, is %d %f", (int)msg->af2, (float)msg->af2);
    fail_unless(msg->af2 == 0.0, errStr);
    sprintf(errStr, "incorrect value for m0, expected 1.94018234598, is %d %f", (int)msg->m0, (float)msg->m0);
    fail_unless(msg->m0 == 1.94018234598, errStr);
    sprintf(errStr, "incorrect value for w, expected -0.523790171609, is %d %f", (int)msg->w, (float)msg->w);
    fail_unless(msg->w == -0.523790171609, errStr);
    sprintf(errStr, "incorrect value for af0, expected 0.000319611746818, is %d %f", (int)msg->af0, (float)msg->af0);
    fail_unless(msg->af0 == 0.000319611746818, errStr);
    sprintf(errStr, "incorrect value for af1, expected -1.02318153949e-12, is %d %f", (int)msg->af1, (float)msg->af1);
    fail_unless(msg->af1 == -1.02318153949e-12, errStr);
    sprintf(errStr, "incorrect value for toc_tow, expected 410400.0, is %d %f", (int)msg->toc_tow, (float)msg->toc_tow);
    fail_unless(msg->toc_tow == 410400.0, errStr);
    free(errStr);
  }
}
END_TEST

Suite* auto_check_sbp_observation_20_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_observation_20");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_observation_20");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_20);
  suite_add_tcase(s, tc_acq);
  return s;
}