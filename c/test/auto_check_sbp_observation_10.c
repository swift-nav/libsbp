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

    u8 test_data[] = {85,73,0,70,152,87,8,95,183,24,106,7,32,126,250,73,80,113,94,247,255,231,163,229,229,4,0,0,0,60,220,96,70,81,147,250,255,196,208,20,28,6,0,0,0,248,61,62,77,28,60,242,255,110,171,180,178,7,0,0,0,237,84,190,77,172,37,13,0,41,170,233,164,10,0,0,0,36,85,9,75,240,188,21,0,19,182,196,209,12,0,0,0,190,175, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x49, 38982, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 38982,
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
    fail_unless(msg->header.t.wn == 1898, "incorrect value for header.t.wn, expected 1898, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 414670600, "incorrect value for header.t.tow, expected 414670600, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 58853, "incorrect value for obs[0].lock, expected 58853, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 1347025534, "incorrect value for obs[0].P, expected 1347025534, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == -565647, "incorrect value for obs[0].L.i, expected -565647, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 231, "incorrect value for obs[0].L.f, expected 231, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 163, "incorrect value for obs[0].cn0, expected 163, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 4, "incorrect value for obs[0].sid.sat, expected 4, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 7188, "incorrect value for obs[1].lock, expected 7188, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 1180752956, "incorrect value for obs[1].P, expected 1180752956, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == -355503, "incorrect value for obs[1].L.i, expected -355503, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 196, "incorrect value for obs[1].L.f, expected 196, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 208, "incorrect value for obs[1].cn0, expected 208, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 6, "incorrect value for obs[1].sid.sat, expected 6, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 45748, "incorrect value for obs[2].lock, expected 45748, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 1295924728, "incorrect value for obs[2].P, expected 1295924728, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == -902116, "incorrect value for obs[2].L.i, expected -902116, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 110, "incorrect value for obs[2].L.f, expected 110, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 171, "incorrect value for obs[2].cn0, expected 171, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 7, "incorrect value for obs[2].sid.sat, expected 7, is %d", msg->obs[2].sid.sat);
    fail_unless(msg->obs[3].lock == 42217, "incorrect value for obs[3].lock, expected 42217, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[3].P == 1304319213, "incorrect value for obs[3].P, expected 1304319213, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].L.i == 861612, "incorrect value for obs[3].L.i, expected 861612, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 41, "incorrect value for obs[3].L.f, expected 41, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 170, "incorrect value for obs[3].cn0, expected 170, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].sid.code == 0, "incorrect value for obs[3].sid.code, expected 0, is %d", msg->obs[3].sid.code);
    fail_unless(msg->obs[3].sid.reserved == 0, "incorrect value for obs[3].sid.reserved, expected 0, is %d", msg->obs[3].sid.reserved);
    fail_unless(msg->obs[3].sid.sat == 10, "incorrect value for obs[3].sid.sat, expected 10, is %d", msg->obs[3].sid.sat);
    fail_unless(msg->obs[4].lock == 53700, "incorrect value for obs[4].lock, expected 53700, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[4].P == 1258902820, "incorrect value for obs[4].P, expected 1258902820, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].L.i == 1424624, "incorrect value for obs[4].L.i, expected 1424624, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 19, "incorrect value for obs[4].L.f, expected 19, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 182, "incorrect value for obs[4].cn0, expected 182, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].sid.code == 0, "incorrect value for obs[4].sid.code, expected 0, is %d", msg->obs[4].sid.code);
    fail_unless(msg->obs[4].sid.reserved == 0, "incorrect value for obs[4].sid.reserved, expected 0, is %d", msg->obs[4].sid.reserved);
    fail_unless(msg->obs[4].sid.sat == 12, "incorrect value for obs[4].sid.sat, expected 12, is %d", msg->obs[4].sid.sat);
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

    u8 test_data[] = {85,73,0,70,152,55,8,95,183,24,106,7,33,68,166,75,77,186,230,24,0,101,186,162,102,16,0,0,0,87,255,155,69,74,158,5,0,26,190,206,30,27,0,0,0,64,89,124,68,26,22,3,0,114,217,225,73,29,0,0,0,37,179, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x49, 38982, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 38982,
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
    fail_unless(msg->header.t.wn == 1898, "incorrect value for header.t.wn, expected 1898, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 414670600, "incorrect value for header.t.tow, expected 414670600, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 26274, "incorrect value for obs[0].lock, expected 26274, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 1296803396, "incorrect value for obs[0].P, expected 1296803396, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 1631930, "incorrect value for obs[0].L.i, expected 1631930, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 101, "incorrect value for obs[0].L.f, expected 101, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 186, "incorrect value for obs[0].cn0, expected 186, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 16, "incorrect value for obs[0].sid.sat, expected 16, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 7886, "incorrect value for obs[1].lock, expected 7886, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 1167851351, "incorrect value for obs[1].P, expected 1167851351, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 368202, "incorrect value for obs[1].L.i, expected 368202, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 26, "incorrect value for obs[1].L.f, expected 26, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 190, "incorrect value for obs[1].cn0, expected 190, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 27, "incorrect value for obs[1].sid.sat, expected 27, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 18913, "incorrect value for obs[2].lock, expected 18913, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 1149000000, "incorrect value for obs[2].P, expected 1149000000, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == 202266, "incorrect value for obs[2].L.i, expected 202266, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 114, "incorrect value for obs[2].L.f, expected 114, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 217, "incorrect value for obs[2].cn0, expected 217, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 29, "incorrect value for obs[2].sid.sat, expected 29, is %d", msg->obs[2].sid.sat);
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

    u8 test_data[] = {85,73,0,0,0,87,8,95,183,24,106,7,32,217,251,73,80,9,72,248,255,30,168,113,81,4,0,0,0,211,220,96,70,198,107,251,255,115,195,53,144,6,0,0,0,77,61,62,77,40,161,243,255,130,176,93,142,7,0,0,0,1,86,190,77,88,77,12,0,116,199,229,213,10,0,0,0,93,85,9,75,64,139,20,0,120,177,196,194,12,0,0,0,141,161, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x49, 0, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 0,
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
    fail_unless(msg->header.t.wn == 1898, "incorrect value for header.t.wn, expected 1898, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 414670600, "incorrect value for header.t.tow, expected 414670600, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 20849, "incorrect value for obs[0].lock, expected 20849, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 1347025881, "incorrect value for obs[0].P, expected 1347025881, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == -505847, "incorrect value for obs[0].L.i, expected -505847, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 30, "incorrect value for obs[0].L.f, expected 30, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 168, "incorrect value for obs[0].cn0, expected 168, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 4, "incorrect value for obs[0].sid.sat, expected 4, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 36917, "incorrect value for obs[1].lock, expected 36917, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 1180753107, "incorrect value for obs[1].P, expected 1180753107, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == -300090, "incorrect value for obs[1].L.i, expected -300090, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 115, "incorrect value for obs[1].L.f, expected 115, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 195, "incorrect value for obs[1].cn0, expected 195, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 6, "incorrect value for obs[1].sid.sat, expected 6, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 36445, "incorrect value for obs[2].lock, expected 36445, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 1295924557, "incorrect value for obs[2].P, expected 1295924557, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == -810712, "incorrect value for obs[2].L.i, expected -810712, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 130, "incorrect value for obs[2].L.f, expected 130, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 176, "incorrect value for obs[2].cn0, expected 176, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 7, "incorrect value for obs[2].sid.sat, expected 7, is %d", msg->obs[2].sid.sat);
    fail_unless(msg->obs[3].lock == 54757, "incorrect value for obs[3].lock, expected 54757, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[3].P == 1304319489, "incorrect value for obs[3].P, expected 1304319489, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].L.i == 806232, "incorrect value for obs[3].L.i, expected 806232, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 116, "incorrect value for obs[3].L.f, expected 116, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 199, "incorrect value for obs[3].cn0, expected 199, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].sid.code == 0, "incorrect value for obs[3].sid.code, expected 0, is %d", msg->obs[3].sid.code);
    fail_unless(msg->obs[3].sid.reserved == 0, "incorrect value for obs[3].sid.reserved, expected 0, is %d", msg->obs[3].sid.reserved);
    fail_unless(msg->obs[3].sid.sat == 10, "incorrect value for obs[3].sid.sat, expected 10, is %d", msg->obs[3].sid.sat);
    fail_unless(msg->obs[4].lock == 49860, "incorrect value for obs[4].lock, expected 49860, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[4].P == 1258902877, "incorrect value for obs[4].P, expected 1258902877, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].L.i == 1346368, "incorrect value for obs[4].L.i, expected 1346368, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 120, "incorrect value for obs[4].L.f, expected 120, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 177, "incorrect value for obs[4].cn0, expected 177, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].sid.code == 0, "incorrect value for obs[4].sid.code, expected 0, is %d", msg->obs[4].sid.code);
    fail_unless(msg->obs[4].sid.reserved == 0, "incorrect value for obs[4].sid.reserved, expected 0, is %d", msg->obs[4].sid.reserved);
    fail_unless(msg->obs[4].sid.sat == 12, "incorrect value for obs[4].sid.sat, expected 12, is %d", msg->obs[4].sid.sat);
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

    u8 test_data[] = {85,73,0,0,0,55,8,95,183,24,106,7,33,70,167,75,77,140,136,23,0,90,187,158,129,16,0,0,0,232,255,155,69,45,175,5,0,17,208,175,56,27,0,0,0,64,89,124,68,45,96,3,0,75,185,73,206,29,0,0,0,220,158, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x49, 0, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 0,
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
    fail_unless(msg->header.t.wn == 1898, "incorrect value for header.t.wn, expected 1898, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 414670600, "incorrect value for header.t.tow, expected 414670600, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 33182, "incorrect value for obs[0].lock, expected 33182, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 1296803654, "incorrect value for obs[0].P, expected 1296803654, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == 1542284, "incorrect value for obs[0].L.i, expected 1542284, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 90, "incorrect value for obs[0].L.f, expected 90, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 187, "incorrect value for obs[0].cn0, expected 187, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 16, "incorrect value for obs[0].sid.sat, expected 16, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 14511, "incorrect value for obs[1].lock, expected 14511, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 1167851496, "incorrect value for obs[1].P, expected 1167851496, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == 372525, "incorrect value for obs[1].L.i, expected 372525, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 17, "incorrect value for obs[1].L.f, expected 17, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 208, "incorrect value for obs[1].cn0, expected 208, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 27, "incorrect value for obs[1].sid.sat, expected 27, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 52809, "incorrect value for obs[2].lock, expected 52809, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 1149000000, "incorrect value for obs[2].P, expected 1149000000, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == 221229, "incorrect value for obs[2].L.i, expected 221229, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 75, "incorrect value for obs[2].L.f, expected 75, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 185, "incorrect value for obs[2].cn0, expected 185, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 29, "incorrect value for obs[2].sid.sat, expected 29, is %d", msg->obs[2].sid.sat);
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

    u8 test_data[] = {85,73,0,70,152,87,208,95,183,24,106,7,32,44,8,74,80,86,93,247,255,57,158,229,229,4,0,0,0,224,229,96,70,156,146,250,255,221,200,20,28,6,0,0,0,60,82,62,77,93,58,242,255,39,164,180,178,7,0,0,0,222,73,190,77,46,39,13,0,202,181,233,164,10,0,0,0,149,64,9,75,114,191,21,0,249,182,196,209,12,0,0,0,112,8, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x49, 38982, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 38982,
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
    fail_unless(msg->header.t.wn == 1898, "incorrect value for header.t.wn, expected 1898, is %d", msg->header.t.wn);
    fail_unless(msg->header.t.tow == 414670800, "incorrect value for header.t.tow, expected 414670800, is %d", msg->header.t.tow);
    fail_unless(msg->obs[0].lock == 58853, "incorrect value for obs[0].lock, expected 58853, is %d", msg->obs[0].lock);
    fail_unless(msg->obs[0].P == 1347029036, "incorrect value for obs[0].P, expected 1347029036, is %d", msg->obs[0].P);
    fail_unless(msg->obs[0].L.i == -565930, "incorrect value for obs[0].L.i, expected -565930, is %d", msg->obs[0].L.i);
    fail_unless(msg->obs[0].L.f == 57, "incorrect value for obs[0].L.f, expected 57, is %d", msg->obs[0].L.f);
    fail_unless(msg->obs[0].cn0 == 158, "incorrect value for obs[0].cn0, expected 158, is %d", msg->obs[0].cn0);
    fail_unless(msg->obs[0].sid.code == 0, "incorrect value for obs[0].sid.code, expected 0, is %d", msg->obs[0].sid.code);
    fail_unless(msg->obs[0].sid.reserved == 0, "incorrect value for obs[0].sid.reserved, expected 0, is %d", msg->obs[0].sid.reserved);
    fail_unless(msg->obs[0].sid.sat == 4, "incorrect value for obs[0].sid.sat, expected 4, is %d", msg->obs[0].sid.sat);
    fail_unless(msg->obs[1].lock == 7188, "incorrect value for obs[1].lock, expected 7188, is %d", msg->obs[1].lock);
    fail_unless(msg->obs[1].P == 1180755424, "incorrect value for obs[1].P, expected 1180755424, is %d", msg->obs[1].P);
    fail_unless(msg->obs[1].L.i == -355684, "incorrect value for obs[1].L.i, expected -355684, is %d", msg->obs[1].L.i);
    fail_unless(msg->obs[1].L.f == 221, "incorrect value for obs[1].L.f, expected 221, is %d", msg->obs[1].L.f);
    fail_unless(msg->obs[1].cn0 == 200, "incorrect value for obs[1].cn0, expected 200, is %d", msg->obs[1].cn0);
    fail_unless(msg->obs[1].sid.code == 0, "incorrect value for obs[1].sid.code, expected 0, is %d", msg->obs[1].sid.code);
    fail_unless(msg->obs[1].sid.reserved == 0, "incorrect value for obs[1].sid.reserved, expected 0, is %d", msg->obs[1].sid.reserved);
    fail_unless(msg->obs[1].sid.sat == 6, "incorrect value for obs[1].sid.sat, expected 6, is %d", msg->obs[1].sid.sat);
    fail_unless(msg->obs[2].lock == 45748, "incorrect value for obs[2].lock, expected 45748, is %d", msg->obs[2].lock);
    fail_unless(msg->obs[2].P == 1295929916, "incorrect value for obs[2].P, expected 1295929916, is %d", msg->obs[2].P);
    fail_unless(msg->obs[2].L.i == -902563, "incorrect value for obs[2].L.i, expected -902563, is %d", msg->obs[2].L.i);
    fail_unless(msg->obs[2].L.f == 39, "incorrect value for obs[2].L.f, expected 39, is %d", msg->obs[2].L.f);
    fail_unless(msg->obs[2].cn0 == 164, "incorrect value for obs[2].cn0, expected 164, is %d", msg->obs[2].cn0);
    fail_unless(msg->obs[2].sid.code == 0, "incorrect value for obs[2].sid.code, expected 0, is %d", msg->obs[2].sid.code);
    fail_unless(msg->obs[2].sid.reserved == 0, "incorrect value for obs[2].sid.reserved, expected 0, is %d", msg->obs[2].sid.reserved);
    fail_unless(msg->obs[2].sid.sat == 7, "incorrect value for obs[2].sid.sat, expected 7, is %d", msg->obs[2].sid.sat);
    fail_unless(msg->obs[3].lock == 42217, "incorrect value for obs[3].lock, expected 42217, is %d", msg->obs[3].lock);
    fail_unless(msg->obs[3].P == 1304316382, "incorrect value for obs[3].P, expected 1304316382, is %d", msg->obs[3].P);
    fail_unless(msg->obs[3].L.i == 861998, "incorrect value for obs[3].L.i, expected 861998, is %d", msg->obs[3].L.i);
    fail_unless(msg->obs[3].L.f == 202, "incorrect value for obs[3].L.f, expected 202, is %d", msg->obs[3].L.f);
    fail_unless(msg->obs[3].cn0 == 181, "incorrect value for obs[3].cn0, expected 181, is %d", msg->obs[3].cn0);
    fail_unless(msg->obs[3].sid.code == 0, "incorrect value for obs[3].sid.code, expected 0, is %d", msg->obs[3].sid.code);
    fail_unless(msg->obs[3].sid.reserved == 0, "incorrect value for obs[3].sid.reserved, expected 0, is %d", msg->obs[3].sid.reserved);
    fail_unless(msg->obs[3].sid.sat == 10, "incorrect value for obs[3].sid.sat, expected 10, is %d", msg->obs[3].sid.sat);
    fail_unless(msg->obs[4].lock == 53700, "incorrect value for obs[4].lock, expected 53700, is %d", msg->obs[4].lock);
    fail_unless(msg->obs[4].P == 1258897557, "incorrect value for obs[4].P, expected 1258897557, is %d", msg->obs[4].P);
    fail_unless(msg->obs[4].L.i == 1425266, "incorrect value for obs[4].L.i, expected 1425266, is %d", msg->obs[4].L.i);
    fail_unless(msg->obs[4].L.f == 249, "incorrect value for obs[4].L.f, expected 249, is %d", msg->obs[4].L.f);
    fail_unless(msg->obs[4].cn0 == 182, "incorrect value for obs[4].cn0, expected 182, is %d", msg->obs[4].cn0);
    fail_unless(msg->obs[4].sid.code == 0, "incorrect value for obs[4].sid.code, expected 0, is %d", msg->obs[4].sid.code);
    fail_unless(msg->obs[4].sid.reserved == 0, "incorrect value for obs[4].sid.reserved, expected 0, is %d", msg->obs[4].sid.reserved);
    fail_unless(msg->obs[4].sid.sat == 12, "incorrect value for obs[4].sid.sat, expected 12, is %d", msg->obs[4].sid.sat);
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