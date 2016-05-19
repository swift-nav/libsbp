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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_observation_10 )
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

    sbp_register_callback(&sbp_state, 0x49, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,73,0,253,6,87,0,224,121,25,105,7,32,255,141,175,74,175,84,6,0,148,177,172,209,5,0,0,0,126,35,38,81,181,251,5,0,168,186,42,145,11,0,0,0,55,229,216,77,49,99,251,255,84,168,251,168,12,0,0,0,221,231,239,78,74,169,253,255,125,185,106,237,14,0,0,0,104,86,144,71,53,207,253,255,77,197,74,175,16,0,0,0,12,72, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x49, 1789, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1789,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_t* msg = ( msg_obs_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header.n_obs, expected 32, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1897, "incorrect value for header.t.wn, expected 1897, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 427417600, "incorrect value for header.t.tow, expected 427417600, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 53676, "incorrect value for obs[0].lock, expected 53676, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 1253019135, "incorrect value for obs[0].P, expected 1253019135, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 414895, "incorrect value for obs[0].L.i, expected 414895, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 148, "incorrect value for obs[0].L.f, expected 148, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 177, "incorrect value for obs[0].cn0, expected 177, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 5, "incorrect value for obs[0].sid.sat, expected 5, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 37162, "incorrect value for obs[1].lock, expected 37162, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 1361453950, "incorrect value for obs[1].P, expected 1361453950, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 392117, "incorrect value for obs[1].L.i, expected 392117, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 168, "incorrect value for obs[1].L.f, expected 168, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 186, "incorrect value for obs[1].cn0, expected 186, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 11, "incorrect value for obs[1].sid.sat, expected 11, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 43259, "incorrect value for obs[2].lock, expected 43259, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 1306060087, "incorrect value for obs[2].P, expected 1306060087, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == -302287, "incorrect value for obs[2].L.i, expected -302287, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 84, "incorrect value for obs[2].L.f, expected 84, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 168, "incorrect value for obs[2].cn0, expected 168, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 12, "incorrect value for obs[2].sid.sat, expected 12, is %d", msg->obs[2].sid.sat);
    fail_unless(msg->obs[3].lock == 60778, "incorrect value for obs[3].lock, expected 60778, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[3].P == 1324345309, "incorrect value for obs[3].P, expected 1324345309, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].L.i == -153270, "incorrect value for obs[3].L.i, expected -153270, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 125, "incorrect value for obs[3].L.f, expected 125, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 185, "incorrect value for obs[3].cn0, expected 185, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].sid.code == 0, "incorrect value for obs[3].sid.code, expected 0, is %d", msg->obs[3].sid.code);
    fail_unless(msg->obs[3].sid.reserved == 0, "incorrect value for obs[3].sid.reserved, expected 0, is %d", msg->obs[3].sid.reserved);
    fail_unless(msg->obs[3].sid.sat == 14, "incorrect value for obs[3].sid.sat, expected 14, is %d", msg->obs[3].sid.sat);
    fail_unless(msg->obs[4].lock == 44874, "incorrect value for obs[4].lock, expected 44874, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[4].P == 1200641640, "incorrect value for obs[4].P, expected 1200641640, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].L.i == -143563, "incorrect value for obs[4].L.i, expected -143563, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 77, "incorrect value for obs[4].L.f, expected 77, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 197, "incorrect value for obs[4].cn0, expected 197, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].sid.code == 0, "incorrect value for obs[4].sid.code, expected 0, is %d", msg->obs[4].sid.code);
    fail_unless(msg->obs[4].sid.reserved == 0, "incorrect value for obs[4].sid.reserved, expected 0, is %d", msg->obs[4].sid.reserved);
    fail_unless(msg->obs[4].sid.sat == 16, "incorrect value for obs[4].sid.sat, expected 16, is %d", msg->obs[4].sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x49, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,73,0,253,6,55,0,224,121,25,105,7,33,64,89,124,68,6,46,1,0,130,202,245,151,18,0,0,0,16,53,181,74,13,196,4,0,71,200,195,243,23,0,0,0,163,67,151,75,103,35,254,255,6,187,73,172,27,0,0,0,53,135, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x49, 1789, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1789,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_t* msg = ( msg_obs_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 33, "incorrect value for header.n_obs, expected 33, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1897, "incorrect value for header.t.wn, expected 1897, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 427417600, "incorrect value for header.t.tow, expected 427417600, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 38901, "incorrect value for obs[0].lock, expected 38901, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 1149000000, "incorrect value for obs[0].P, expected 1149000000, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 77318, "incorrect value for obs[0].L.i, expected 77318, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 130, "incorrect value for obs[0].L.f, expected 130, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 202, "incorrect value for obs[0].cn0, expected 202, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 18, "incorrect value for obs[0].sid.sat, expected 18, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 62403, "incorrect value for obs[1].lock, expected 62403, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 1253389584, "incorrect value for obs[1].P, expected 1253389584, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 312333, "incorrect value for obs[1].L.i, expected 312333, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 71, "incorrect value for obs[1].L.f, expected 71, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 200, "incorrect value for obs[1].cn0, expected 200, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 23, "incorrect value for obs[1].sid.sat, expected 23, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 44105, "incorrect value for obs[2].lock, expected 44105, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 1268204451, "incorrect value for obs[2].P, expected 1268204451, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == -122009, "incorrect value for obs[2].L.i, expected -122009, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 6, "incorrect value for obs[2].L.f, expected 6, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 187, "incorrect value for obs[2].cn0, expected 187, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 27, "incorrect value for obs[2].sid.sat, expected 27, is %d", msg->obs[2].sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x49, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,73,0,253,6,87,200,224,121,25,105,7,32,97,122,175,74,61,87,6,0,188,163,172,209,5,0,0,0,142,16,38,81,49,254,5,0,157,171,42,145,11,0,0,0,201,253,216,77,24,97,251,255,140,173,251,168,12,0,0,0,19,247,239,78,52,168,253,255,72,161,106,237,14,0,0,0,142,99,144,71,78,206,253,255,156,197,74,175,16,0,0,0,230,8, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x49, 1789, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1789,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_t* msg = ( msg_obs_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header.n_obs, expected 32, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1897, "incorrect value for header.t.wn, expected 1897, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 427417800, "incorrect value for header.t.tow, expected 427417800, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 53676, "incorrect value for obs[0].lock, expected 53676, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 1253014113, "incorrect value for obs[0].P, expected 1253014113, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 415549, "incorrect value for obs[0].L.i, expected 415549, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 188, "incorrect value for obs[0].L.f, expected 188, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 163, "incorrect value for obs[0].cn0, expected 163, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 5, "incorrect value for obs[0].sid.sat, expected 5, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 37162, "incorrect value for obs[1].lock, expected 37162, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 1361449102, "incorrect value for obs[1].P, expected 1361449102, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 392753, "incorrect value for obs[1].L.i, expected 392753, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 157, "incorrect value for obs[1].L.f, expected 157, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 171, "incorrect value for obs[1].cn0, expected 171, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 11, "incorrect value for obs[1].sid.sat, expected 11, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 43259, "incorrect value for obs[2].lock, expected 43259, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 1306066377, "incorrect value for obs[2].P, expected 1306066377, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == -302824, "incorrect value for obs[2].L.i, expected -302824, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 140, "incorrect value for obs[2].L.f, expected 140, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 173, "incorrect value for obs[2].cn0, expected 173, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 12, "incorrect value for obs[2].sid.sat, expected 12, is %d", msg->obs[2].sid.sat);
    fail_unless(msg->obs[3].lock == 60778, "incorrect value for obs[3].lock, expected 60778, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[3].P == 1324349203, "incorrect value for obs[3].P, expected 1324349203, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].L.i == -153548, "incorrect value for obs[3].L.i, expected -153548, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 72, "incorrect value for obs[3].L.f, expected 72, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 161, "incorrect value for obs[3].cn0, expected 161, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].sid.code == 0, "incorrect value for obs[3].sid.code, expected 0, is %d", msg->obs[3].sid.code);
    fail_unless(msg->obs[3].sid.reserved == 0, "incorrect value for obs[3].sid.reserved, expected 0, is %d", msg->obs[3].sid.reserved);
    fail_unless(msg->obs[3].sid.sat == 14, "incorrect value for obs[3].sid.sat, expected 14, is %d", msg->obs[3].sid.sat);
    fail_unless(msg->obs[4].lock == 44874, "incorrect value for obs[4].lock, expected 44874, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[4].P == 1200645006, "incorrect value for obs[4].P, expected 1200645006, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].L.i == -143794, "incorrect value for obs[4].L.i, expected -143794, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 156, "incorrect value for obs[4].L.f, expected 156, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 197, "incorrect value for obs[4].cn0, expected 197, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].sid.code == 0, "incorrect value for obs[4].sid.code, expected 0, is %d", msg->obs[4].sid.code);
    fail_unless(msg->obs[4].sid.reserved == 0, "incorrect value for obs[4].sid.reserved, expected 0, is %d", msg->obs[4].sid.reserved);
    fail_unless(msg->obs[4].sid.sat == 16, "incorrect value for obs[4].sid.sat, expected 16, is %d", msg->obs[4].sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x49, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,73,0,253,6,55,200,224,121,25,105,7,33,64,89,124,68,138,46,1,0,86,207,245,151,18,0,0,0,121,35,181,74,99,198,4,0,72,178,195,243,23,0,0,0,216,80,151,75,134,34,254,255,250,194,73,172,27,0,0,0,186,72, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x49, 1789, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1789,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_t* msg = ( msg_obs_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 33, "incorrect value for header.n_obs, expected 33, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1897, "incorrect value for header.t.wn, expected 1897, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 427417800, "incorrect value for header.t.tow, expected 427417800, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 38901, "incorrect value for obs[0].lock, expected 38901, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 1149000000, "incorrect value for obs[0].P, expected 1149000000, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 77450, "incorrect value for obs[0].L.i, expected 77450, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 86, "incorrect value for obs[0].L.f, expected 86, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 207, "incorrect value for obs[0].cn0, expected 207, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 18, "incorrect value for obs[0].sid.sat, expected 18, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 62403, "incorrect value for obs[1].lock, expected 62403, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 1253385081, "incorrect value for obs[1].P, expected 1253385081, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 312931, "incorrect value for obs[1].L.i, expected 312931, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 72, "incorrect value for obs[1].L.f, expected 72, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 178, "incorrect value for obs[1].cn0, expected 178, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 23, "incorrect value for obs[1].sid.sat, expected 23, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 44105, "incorrect value for obs[2].lock, expected 44105, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 1268207832, "incorrect value for obs[2].P, expected 1268207832, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == -122234, "incorrect value for obs[2].L.i, expected -122234, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 250, "incorrect value for obs[2].L.f, expected 250, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 194, "incorrect value for obs[2].cn0, expected 194, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 27, "incorrect value for obs[2].sid.sat, expected 27, is %d", msg->obs[2].sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x49, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,73,0,253,6,87,144,225,121,25,105,7,32,158,102,175,74,203,89,6,0,209,191,172,209,5,0,0,0,208,253,37,81,173,0,6,0,131,185,42,145,11,0,0,0,63,22,217,77,255,94,251,255,175,165,251,168,12,0,0,0,253,5,240,78,30,167,253,255,7,184,106,237,14,0,0,0,239,112,144,71,103,205,253,255,211,186,74,175,16,0,0,0,188,101, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x49, 1789, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 1789,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_obs_t* msg = ( msg_obs_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header.n_obs, expected 32, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1897, "incorrect value for header.t.wn, expected 1897, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 427418000, "incorrect value for header.t.tow, expected 427418000, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 53676, "incorrect value for obs[0].lock, expected 53676, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 1253009054, "incorrect value for obs[0].P, expected 1253009054, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 416203, "incorrect value for obs[0].L.i, expected 416203, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 209, "incorrect value for obs[0].L.f, expected 209, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 191, "incorrect value for obs[0].cn0, expected 191, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 5, "incorrect value for obs[0].sid.sat, expected 5, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 37162, "incorrect value for obs[1].lock, expected 37162, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 1361444304, "incorrect value for obs[1].P, expected 1361444304, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 393389, "incorrect value for obs[1].L.i, expected 393389, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 131, "incorrect value for obs[1].L.f, expected 131, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 185, "incorrect value for obs[1].cn0, expected 185, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 11, "incorrect value for obs[1].sid.sat, expected 11, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 43259, "incorrect value for obs[2].lock, expected 43259, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 1306072639, "incorrect value for obs[2].P, expected 1306072639, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == -303361, "incorrect value for obs[2].L.i, expected -303361, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 175, "incorrect value for obs[2].L.f, expected 175, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 165, "incorrect value for obs[2].cn0, expected 165, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 12, "incorrect value for obs[2].sid.sat, expected 12, is %d", msg->obs[2].sid.sat);
    fail_unless(msg->obs[3].lock == 60778, "incorrect value for obs[3].lock, expected 60778, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[3].P == 1324353021, "incorrect value for obs[3].P, expected 1324353021, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].L.i == -153826, "incorrect value for obs[3].L.i, expected -153826, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 7, "incorrect value for obs[3].L.f, expected 7, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 184, "incorrect value for obs[3].cn0, expected 184, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].sid.code == 0, "incorrect value for obs[3].sid.code, expected 0, is %d", msg->obs[3].sid.code);
    fail_unless(msg->obs[3].sid.reserved == 0, "incorrect value for obs[3].sid.reserved, expected 0, is %d", msg->obs[3].sid.reserved);
    fail_unless(msg->obs[3].sid.sat == 14, "incorrect value for obs[3].sid.sat, expected 14, is %d", msg->obs[3].sid.sat);
    fail_unless(msg->obs[4].lock == 44874, "incorrect value for obs[4].lock, expected 44874, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[4].P == 1200648431, "incorrect value for obs[4].P, expected 1200648431, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].L.i == -144025, "incorrect value for obs[4].L.i, expected -144025, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 211, "incorrect value for obs[4].L.f, expected 211, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 186, "incorrect value for obs[4].cn0, expected 186, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].sid.code == 0, "incorrect value for obs[4].sid.code, expected 0, is %d", msg->obs[4].sid.code);
    fail_unless(msg->obs[4].sid.reserved == 0, "incorrect value for obs[4].sid.reserved, expected 0, is %d", msg->obs[4].sid.reserved);
    fail_unless(msg->obs[4].sid.sat == 16, "incorrect value for obs[4].sid.sat, expected 16, is %d", msg->obs[4].sid.sat);
  }
}
END_TEST

Suite* auto_check_sbp_observation_10_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_observation_10");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_observation_10");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_10);
  suite_add_tcase(s, tc_acq);
  return s;
}