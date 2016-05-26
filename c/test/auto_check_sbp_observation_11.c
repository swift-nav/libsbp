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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs_dep_b.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_observation_11 )
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

    sbp_register_callback(&sbp_state, 0x43, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,67,0,246,215,103,120,46,39,0,251,6,32,180,175,187,133,223,53,7,7,27,157,0,0,202,0,0,0,58,140,85,147,88,28,190,7,175,144,0,0,203,0,0,0,220,140,248,138,208,172,77,7,135,151,0,0,208,0,0,0,173,194,72,135,115,18,28,7,242,156,0,0,212,0,0,0,164,144,105,124,18,196,137,6,120,168,0,0,217,0,0,0,30,232,228,139,210,7,90,7,87,150,0,0,218,0,0,0,169,85, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x43, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_obs_dep_b_t* msg = ( msg_obs_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header.n_obs, expected 32, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1787, "incorrect value for header.t.wn, expected 1787, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 2567800, "incorrect value for header.t.tow, expected 2567800, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 0, "incorrect value for obs[0].lock, expected 0, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 2243669940, "incorrect value for obs[0].P, expected 2243669940, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 117913055, "incorrect value for obs[0].L.i, expected 117913055, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 27, "incorrect value for obs[0].L.f, expected 27, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 157, "incorrect value for obs[0].cn0, expected 157, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 202, "incorrect value for obs[0].sid.sat, expected 202, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 0, "incorrect value for obs[1].lock, expected 0, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 2471857210, "incorrect value for obs[1].P, expected 2471857210, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 129899608, "incorrect value for obs[1].L.i, expected 129899608, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 175, "incorrect value for obs[1].L.f, expected 175, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 144, "incorrect value for obs[1].cn0, expected 144, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 203, "incorrect value for obs[1].sid.sat, expected 203, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 0, "incorrect value for obs[2].lock, expected 0, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 2331544796, "incorrect value for obs[2].P, expected 2331544796, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == 122531024, "incorrect value for obs[2].L.i, expected 122531024, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 135, "incorrect value for obs[2].L.f, expected 135, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 151, "incorrect value for obs[2].cn0, expected 151, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 208, "incorrect value for obs[2].sid.sat, expected 208, is %d", msg->obs[2].sid.sat);
    fail_unless(msg->obs[3].lock == 0, "incorrect value for obs[3].lock, expected 0, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[3].P == 2269692589, "incorrect value for obs[3].P, expected 2269692589, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].L.i == 119280243, "incorrect value for obs[3].L.i, expected 119280243, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 242, "incorrect value for obs[3].L.f, expected 242, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 156, "incorrect value for obs[3].cn0, expected 156, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].sid.code == 0, "incorrect value for obs[3].sid.code, expected 0, is %d", msg->obs[3].sid.code);
    fail_unless(msg->obs[3].sid.reserved == 0, "incorrect value for obs[3].sid.reserved, expected 0, is %d", msg->obs[3].sid.reserved);
    fail_unless(msg->obs[3].sid.sat == 212, "incorrect value for obs[3].sid.sat, expected 212, is %d", msg->obs[3].sid.sat);
    fail_unless(msg->obs[4].lock == 0, "incorrect value for obs[4].lock, expected 0, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[4].P == 2087293092, "incorrect value for obs[4].P, expected 2087293092, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].L.i == 109691922, "incorrect value for obs[4].L.i, expected 109691922, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 120, "incorrect value for obs[4].L.f, expected 120, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 168, "incorrect value for obs[4].cn0, expected 168, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].sid.code == 0, "incorrect value for obs[4].sid.code, expected 0, is %d", msg->obs[4].sid.code);
    fail_unless(msg->obs[4].sid.reserved == 0, "incorrect value for obs[4].sid.reserved, expected 0, is %d", msg->obs[4].sid.reserved);
    fail_unless(msg->obs[4].sid.sat == 217, "incorrect value for obs[4].sid.sat, expected 217, is %d", msg->obs[4].sid.sat);
    fail_unless(msg->obs[5].lock == 0, "incorrect value for obs[5].lock, expected 0, is %d", msg->obs[5].lock);
    fail_unless(msg->obs[5].P == 2347034654, "incorrect value for obs[5].P, expected 2347034654, is %d", msg->obs[5].P);
    fail_unless(msg->obs[5].L.i == 123340754, "incorrect value for obs[5].L.i, expected 123340754, is %d", msg->obs[5].L.i);
    fail_unless(msg->obs[5].L.f == 87, "incorrect value for obs[5].L.f, expected 87, is %d", msg->obs[5].L.f);
    fail_unless(msg->obs[5].cn0 == 150, "incorrect value for obs[5].cn0, expected 150, is %d", msg->obs[5].cn0);
    fail_unless(msg->obs[5].sid.code == 0, "incorrect value for obs[5].sid.code, expected 0, is %d", msg->obs[5].sid.code);
    fail_unless(msg->obs[5].sid.reserved == 0, "incorrect value for obs[5].sid.reserved, expected 0, is %d", msg->obs[5].sid.reserved);
    fail_unless(msg->obs[5].sid.sat == 218, "incorrect value for obs[5].sid.sat, expected 218, is %d", msg->obs[5].sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x43, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,67,0,246,215,55,120,46,39,0,251,6,33,68,199,101,136,133,247,42,7,219,154,0,0,220,0,0,0,219,14,123,133,96,215,3,7,235,156,0,0,222,0,0,0,87,166,81,122,5,173,109,6,174,170,0,0,225,0,0,0,11,233, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x43, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_obs_dep_b_t* msg = ( msg_obs_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 33, "incorrect value for header.n_obs, expected 33, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1787, "incorrect value for header.t.wn, expected 1787, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 2567800, "incorrect value for header.t.tow, expected 2567800, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 0, "incorrect value for obs[0].lock, expected 0, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 2288371524, "incorrect value for obs[0].P, expected 2288371524, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 120256389, "incorrect value for obs[0].L.i, expected 120256389, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 219, "incorrect value for obs[0].L.f, expected 219, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 154, "incorrect value for obs[0].cn0, expected 154, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 220, "incorrect value for obs[0].sid.sat, expected 220, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 0, "incorrect value for obs[1].lock, expected 0, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 2239434459, "incorrect value for obs[1].P, expected 2239434459, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 117692256, "incorrect value for obs[1].L.i, expected 117692256, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 235, "incorrect value for obs[1].L.f, expected 235, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 156, "incorrect value for obs[1].cn0, expected 156, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 222, "incorrect value for obs[1].sid.sat, expected 222, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 0, "incorrect value for obs[2].lock, expected 0, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 2052171351, "incorrect value for obs[2].P, expected 2052171351, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == 107851013, "incorrect value for obs[2].L.i, expected 107851013, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 174, "incorrect value for obs[2].L.f, expected 174, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 170, "incorrect value for obs[2].cn0, expected 170, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 225, "incorrect value for obs[2].sid.sat, expected 225, is %d", msg->obs[2].sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x43, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,67,0,246,215,103,64,47,39,0,251,6,32,100,132,187,133,236,51,7,7,94,156,0,0,202,0,0,0,97,184,85,147,178,30,190,7,40,140,0,0,203,0,0,0,135,111,248,138,90,171,77,7,2,150,0,0,208,0,0,0,180,238,72,135,190,20,28,7,241,155,0,0,212,0,0,0,15,153,105,124,92,196,137,6,153,168,0,0,217,0,0,0,49,185,228,139,144,5,90,7,41,150,0,0,218,0,0,0,241,98, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x43, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_obs_dep_b_t* msg = ( msg_obs_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header.n_obs, expected 32, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1787, "incorrect value for header.t.wn, expected 1787, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 2568000, "incorrect value for header.t.tow, expected 2568000, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 0, "incorrect value for obs[0].lock, expected 0, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 2243658852, "incorrect value for obs[0].P, expected 2243658852, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 117912556, "incorrect value for obs[0].L.i, expected 117912556, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 94, "incorrect value for obs[0].L.f, expected 94, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 156, "incorrect value for obs[0].cn0, expected 156, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 202, "incorrect value for obs[0].sid.sat, expected 202, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 0, "incorrect value for obs[1].lock, expected 0, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 2471868513, "incorrect value for obs[1].P, expected 2471868513, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 129900210, "incorrect value for obs[1].L.i, expected 129900210, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 40, "incorrect value for obs[1].L.f, expected 40, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 140, "incorrect value for obs[1].cn0, expected 140, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 203, "incorrect value for obs[1].sid.sat, expected 203, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 0, "incorrect value for obs[2].lock, expected 0, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 2331537287, "incorrect value for obs[2].P, expected 2331537287, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == 122530650, "incorrect value for obs[2].L.i, expected 122530650, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 2, "incorrect value for obs[2].L.f, expected 2, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 150, "incorrect value for obs[2].cn0, expected 150, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 208, "incorrect value for obs[2].sid.sat, expected 208, is %d", msg->obs[2].sid.sat);
    fail_unless(msg->obs[3].lock == 0, "incorrect value for obs[3].lock, expected 0, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[3].P == 2269703860, "incorrect value for obs[3].P, expected 2269703860, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].L.i == 119280830, "incorrect value for obs[3].L.i, expected 119280830, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 241, "incorrect value for obs[3].L.f, expected 241, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 155, "incorrect value for obs[3].cn0, expected 155, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].sid.code == 0, "incorrect value for obs[3].sid.code, expected 0, is %d", msg->obs[3].sid.code);
    fail_unless(msg->obs[3].sid.reserved == 0, "incorrect value for obs[3].sid.reserved, expected 0, is %d", msg->obs[3].sid.reserved);
    fail_unless(msg->obs[3].sid.sat == 212, "incorrect value for obs[3].sid.sat, expected 212, is %d", msg->obs[3].sid.sat);
    fail_unless(msg->obs[4].lock == 0, "incorrect value for obs[4].lock, expected 0, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[4].P == 2087295247, "incorrect value for obs[4].P, expected 2087295247, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].L.i == 109691996, "incorrect value for obs[4].L.i, expected 109691996, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 153, "incorrect value for obs[4].L.f, expected 153, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 168, "incorrect value for obs[4].cn0, expected 168, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].sid.code == 0, "incorrect value for obs[4].sid.code, expected 0, is %d", msg->obs[4].sid.code);
    fail_unless(msg->obs[4].sid.reserved == 0, "incorrect value for obs[4].sid.reserved, expected 0, is %d", msg->obs[4].sid.reserved);
    fail_unless(msg->obs[4].sid.sat == 217, "incorrect value for obs[4].sid.sat, expected 217, is %d", msg->obs[4].sid.sat);
    fail_unless(msg->obs[5].lock == 0, "incorrect value for obs[5].lock, expected 0, is %d", msg->obs[5].lock);
    fail_unless(msg->obs[5].P == 2347022641, "incorrect value for obs[5].P, expected 2347022641, is %d", msg->obs[5].P);
    fail_unless(msg->obs[5].L.i == 123340176, "incorrect value for obs[5].L.i, expected 123340176, is %d", msg->obs[5].L.i);
    fail_unless(msg->obs[5].L.f == 41, "incorrect value for obs[5].L.f, expected 41, is %d", msg->obs[5].L.f);
    fail_unless(msg->obs[5].cn0 == 150, "incorrect value for obs[5].cn0, expected 150, is %d", msg->obs[5].cn0);
    fail_unless(msg->obs[5].sid.code == 0, "incorrect value for obs[5].sid.code, expected 0, is %d", msg->obs[5].sid.code);
    fail_unless(msg->obs[5].sid.reserved == 0, "incorrect value for obs[5].sid.reserved, expected 0, is %d", msg->obs[5].sid.reserved);
    fail_unless(msg->obs[5].sid.sat == 218, "incorrect value for obs[5].sid.sat, expected 218, is %d", msg->obs[5].sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x43, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,67,0,246,215,55,64,47,39,0,251,6,33,234,148,101,136,15,245,42,7,20,154,0,0,220,0,0,0,208,247,122,133,16,214,3,7,38,156,0,0,222,0,0,0,15,150,81,122,22,172,109,6,7,172,0,0,225,0,0,0,201,13, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x43, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_obs_dep_b_t* msg = ( msg_obs_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 33, "incorrect value for header.n_obs, expected 33, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1787, "incorrect value for header.t.wn, expected 1787, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 2568000, "incorrect value for header.t.tow, expected 2568000, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 0, "incorrect value for obs[0].lock, expected 0, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 2288358634, "incorrect value for obs[0].P, expected 2288358634, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 120255759, "incorrect value for obs[0].L.i, expected 120255759, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 20, "incorrect value for obs[0].L.f, expected 20, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 154, "incorrect value for obs[0].cn0, expected 154, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 220, "incorrect value for obs[0].sid.sat, expected 220, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 0, "incorrect value for obs[1].lock, expected 0, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 2239428560, "incorrect value for obs[1].P, expected 2239428560, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 117691920, "incorrect value for obs[1].L.i, expected 117691920, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 38, "incorrect value for obs[1].L.f, expected 38, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 156, "incorrect value for obs[1].cn0, expected 156, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 222, "incorrect value for obs[1].sid.sat, expected 222, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 0, "incorrect value for obs[2].lock, expected 0, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 2052167183, "incorrect value for obs[2].P, expected 2052167183, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == 107850774, "incorrect value for obs[2].L.i, expected 107850774, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 7, "incorrect value for obs[2].L.f, expected 7, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 172, "incorrect value for obs[2].cn0, expected 172, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 225, "incorrect value for obs[2].sid.sat, expected 225, is %d", msg->obs[2].sid.sat);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x43, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,67,0,246,215,103,8,48,39,0,251,6,32,254,96,187,133,249,49,7,7,165,156,0,0,202,0,0,0,113,229,85,147,11,33,190,7,106,143,0,0,203,0,0,0,182,85,248,138,227,169,77,7,159,150,0,0,208,0,0,0,17,24,73,135,10,23,28,7,7,156,0,0,212,0,0,0,108,155,105,124,166,196,137,6,186,170,0,0,217,0,0,0,214,142,228,139,77,3,90,7,236,151,0,0,218,0,0,0,59,118, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x43, 55286, sizeof(test_data), test_data, &dummy_write);

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
    msg_obs_dep_b_t* msg = ( msg_obs_dep_b_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->header.n_obs == 32, "incorrect value for header.n_obs, expected 32, is %d", msg->header.n_obs);
    fail_unless(msg->header.t.wn == 1787, "incorrect value for header.t.wn, expected 1787, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 2568200, "incorrect value for header.t.tow, expected 2568200, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 0, "incorrect value for obs[0].lock, expected 0, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 2243649790, "incorrect value for obs[0].P, expected 2243649790, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 117912057, "incorrect value for obs[0].L.i, expected 117912057, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 165, "incorrect value for obs[0].L.f, expected 165, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 156, "incorrect value for obs[0].cn0, expected 156, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 202, "incorrect value for obs[0].sid.sat, expected 202, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 0, "incorrect value for obs[1].lock, expected 0, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 2471880049, "incorrect value for obs[1].P, expected 2471880049, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 129900811, "incorrect value for obs[1].L.i, expected 129900811, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 106, "incorrect value for obs[1].L.f, expected 106, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 143, "incorrect value for obs[1].cn0, expected 143, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 203, "incorrect value for obs[1].sid.sat, expected 203, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 0, "incorrect value for obs[2].lock, expected 0, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 2331530678, "incorrect value for obs[2].P, expected 2331530678, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == 122530275, "incorrect value for obs[2].L.i, expected 122530275, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 159, "incorrect value for obs[2].L.f, expected 159, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 150, "incorrect value for obs[2].cn0, expected 150, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 208, "incorrect value for obs[2].sid.sat, expected 208, is %d", msg->obs[2].sid.sat);
    fail_unless(msg->obs[3].lock == 0, "incorrect value for obs[3].lock, expected 0, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[3].P == 2269714449, "incorrect value for obs[3].P, expected 2269714449, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].L.i == 119281418, "incorrect value for obs[3].L.i, expected 119281418, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 7, "incorrect value for obs[3].L.f, expected 7, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 156, "incorrect value for obs[3].cn0, expected 156, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].sid.code == 0, "incorrect value for obs[3].sid.code, expected 0, is %d", msg->obs[3].sid.code);
    fail_unless(msg->obs[3].sid.reserved == 0, "incorrect value for obs[3].sid.reserved, expected 0, is %d", msg->obs[3].sid.reserved);
    fail_unless(msg->obs[3].sid.sat == 212, "incorrect value for obs[3].sid.sat, expected 212, is %d", msg->obs[3].sid.sat);
    fail_unless(msg->obs[4].lock == 0, "incorrect value for obs[4].lock, expected 0, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[4].P == 2087295852, "incorrect value for obs[4].P, expected 2087295852, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].L.i == 109692070, "incorrect value for obs[4].L.i, expected 109692070, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 186, "incorrect value for obs[4].L.f, expected 186, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 170, "incorrect value for obs[4].cn0, expected 170, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].sid.code == 0, "incorrect value for obs[4].sid.code, expected 0, is %d", msg->obs[4].sid.code);
    fail_unless(msg->obs[4].sid.reserved == 0, "incorrect value for obs[4].sid.reserved, expected 0, is %d", msg->obs[4].sid.reserved);
    fail_unless(msg->obs[4].sid.sat == 217, "incorrect value for obs[4].sid.sat, expected 217, is %d", msg->obs[4].sid.sat);
    fail_unless(msg->obs[5].lock == 0, "incorrect value for obs[5].lock, expected 0, is %d", msg->obs[5].lock);
    fail_unless(msg->obs[5].P == 2347011798, "incorrect value for obs[5].P, expected 2347011798, is %d", msg->obs[5].P);
    fail_unless(msg->obs[5].L.i == 123339597, "incorrect value for obs[5].L.i, expected 123339597, is %d", msg->obs[5].L.i);
    fail_unless(msg->obs[5].L.f == 236, "incorrect value for obs[5].L.f, expected 236, is %d", msg->obs[5].L.f);
    fail_unless(msg->obs[5].cn0 == 151, "incorrect value for obs[5].cn0, expected 151, is %d", msg->obs[5].cn0);
    fail_unless(msg->obs[5].sid.code == 0, "incorrect value for obs[5].sid.code, expected 0, is %d", msg->obs[5].sid.code);
    fail_unless(msg->obs[5].sid.reserved == 0, "incorrect value for obs[5].sid.reserved, expected 0, is %d", msg->obs[5].sid.reserved);
    fail_unless(msg->obs[5].sid.sat == 218, "incorrect value for obs[5].sid.sat, expected 218, is %d", msg->obs[5].sid.sat);
  }
}
END_TEST

Suite* auto_check_sbp_observation_11_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_observation_11");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_observation_11");
  tcase_add_test(tc_acq, test_auto_check_sbp_observation_11);
  suite_add_tcase(s, tc_acq);
  return s;
}