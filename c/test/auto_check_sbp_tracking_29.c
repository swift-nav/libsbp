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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailed.yaml by generate.py. Do not modify by hand!

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

START_TEST( test_auto_check_sbp_tracking_29 )
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

    sbp_register_callback(&sbp_state, 0x11, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,17,0,67,192,55,175,230,139,53,1,0,0,0,0,92,38,5,84,7,64,89,124,68,100,0,116,86,205,248,238,0,57,48,255,255,0,0,251,0,0,0,2,0,16,14,0,0,100,0,10,0,208,7,1,170,171,172,173,174,175,187,182, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x11, 49219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 49219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_tracking_state_detailed_t* msg = ( msg_tracking_state_detailed_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->track_flags == 172, "incorrect value for track_flags, expected 172, is %d", msg->track_flags);
    fail_unless(msg->doppler == 251, "incorrect value for doppler, expected 251, is %d", msg->doppler);
    fail_unless(msg->clock_offset == 100, "incorrect value for clock_offset, expected 100, is %d", msg->clock_offset);
    fail_unless(msg->pset_flags == 174, "incorrect value for pset_flags, expected 174, is %d", msg->pset_flags);
    fail_unless(msg->lock == 12345, "incorrect value for lock, expected 12345, is %d", msg->lock);
    fail_unless(msg->nav_flags == 173, "incorrect value for nav_flags, expected 173, is %d", msg->nav_flags);
    fail_unless(msg->P_std == 100, "incorrect value for P_std, expected 100, is %d", msg->P_std);
    fail_unless(msg->L.i == -120760716, "incorrect value for L.i, expected -120760716, is %d", msg->L.i);
    fail_unless(msg->L.f == 238, "incorrect value for L.f, expected 238, is %d", msg->L.f);
    fail_unless(msg->clock_drift == 10, "incorrect value for clock_drift, expected 10, is %d", msg->clock_drift);
    fail_unless(msg->tot.wn == 1876, "incorrect value for tot.wn, expected 1876, is %d", msg->tot.wn);
    fail_unless(msg->tot.tow == 86400000, "incorrect value for tot.tow, expected 86400000, is %d", msg->tot.tow);
    fail_unless(msg->sync_flags == 170, "incorrect value for sync_flags, expected 170, is %d", msg->sync_flags);
    fail_unless(msg->acceleration == 1, "incorrect value for acceleration, expected 1, is %d", msg->acceleration);
    fail_unless(msg->uptime == 3600, "incorrect value for uptime, expected 3600, is %d", msg->uptime);
    fail_unless(msg->recv_time == 5193328303, "incorrect value for recv_time, expected 5193328303, is %d", msg->recv_time);
    fail_unless(msg->cn0 == 0, "incorrect value for cn0, expected 0, is %d", msg->cn0);
    fail_unless(msg->doppler_std == 2, "incorrect value for doppler_std, expected 2, is %d", msg->doppler_std);
    fail_unless(msg->tow_flags == 171, "incorrect value for tow_flags, expected 171, is %d", msg->tow_flags);
    fail_unless(msg->misc_flags == 175, "incorrect value for misc_flags, expected 175, is %d", msg->misc_flags);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 65535, "incorrect value for sid.sat, expected 65535, is %d", msg->sid.sat);
    fail_unless(msg->corr_spacing == 2000, "incorrect value for corr_spacing, expected 2000, is %d", msg->corr_spacing);
    fail_unless(msg->P == 1149000000, "incorrect value for P, expected 1149000000, is %d", msg->P);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x11, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,17,0,67,192,55,217,239,139,53,1,0,0,0,0,92,38,5,84,7,64,89,124,68,100,0,116,86,205,248,238,0,57,48,255,255,0,0,251,0,0,0,2,0,16,14,0,0,100,0,10,0,208,7,1,170,171,172,173,174,175,129,30, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x11, 49219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 49219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_tracking_state_detailed_t* msg = ( msg_tracking_state_detailed_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->track_flags == 172, "incorrect value for track_flags, expected 172, is %d", msg->track_flags);
    fail_unless(msg->doppler == 251, "incorrect value for doppler, expected 251, is %d", msg->doppler);
    fail_unless(msg->clock_offset == 100, "incorrect value for clock_offset, expected 100, is %d", msg->clock_offset);
    fail_unless(msg->pset_flags == 174, "incorrect value for pset_flags, expected 174, is %d", msg->pset_flags);
    fail_unless(msg->lock == 12345, "incorrect value for lock, expected 12345, is %d", msg->lock);
    fail_unless(msg->nav_flags == 173, "incorrect value for nav_flags, expected 173, is %d", msg->nav_flags);
    fail_unless(msg->P_std == 100, "incorrect value for P_std, expected 100, is %d", msg->P_std);
    fail_unless(msg->L.i == -120760716, "incorrect value for L.i, expected -120760716, is %d", msg->L.i);
    fail_unless(msg->L.f == 238, "incorrect value for L.f, expected 238, is %d", msg->L.f);
    fail_unless(msg->clock_drift == 10, "incorrect value for clock_drift, expected 10, is %d", msg->clock_drift);
    fail_unless(msg->tot.wn == 1876, "incorrect value for tot.wn, expected 1876, is %d", msg->tot.wn);
    fail_unless(msg->tot.tow == 86400000, "incorrect value for tot.tow, expected 86400000, is %d", msg->tot.tow);
    fail_unless(msg->sync_flags == 170, "incorrect value for sync_flags, expected 170, is %d", msg->sync_flags);
    fail_unless(msg->acceleration == 1, "incorrect value for acceleration, expected 1, is %d", msg->acceleration);
    fail_unless(msg->uptime == 3600, "incorrect value for uptime, expected 3600, is %d", msg->uptime);
    fail_unless(msg->recv_time == 5193330649, "incorrect value for recv_time, expected 5193330649, is %d", msg->recv_time);
    fail_unless(msg->cn0 == 0, "incorrect value for cn0, expected 0, is %d", msg->cn0);
    fail_unless(msg->doppler_std == 2, "incorrect value for doppler_std, expected 2, is %d", msg->doppler_std);
    fail_unless(msg->tow_flags == 171, "incorrect value for tow_flags, expected 171, is %d", msg->tow_flags);
    fail_unless(msg->misc_flags == 175, "incorrect value for misc_flags, expected 175, is %d", msg->misc_flags);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 65535, "incorrect value for sid.sat, expected 65535, is %d", msg->sid.sat);
    fail_unless(msg->corr_spacing == 2000, "incorrect value for corr_spacing, expected 2000, is %d", msg->corr_spacing);
    fail_unless(msg->P == 1149000000, "incorrect value for P, expected 1149000000, is %d", msg->P);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x11, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,17,0,67,192,55,56,247,139,53,1,0,0,0,0,92,38,5,84,7,64,89,124,68,100,0,116,86,205,248,238,0,57,48,255,255,0,0,251,0,0,0,2,0,16,14,0,0,100,0,10,0,208,7,1,170,171,172,173,174,175,239,93, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x11, 49219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 49219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_tracking_state_detailed_t* msg = ( msg_tracking_state_detailed_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->track_flags == 172, "incorrect value for track_flags, expected 172, is %d", msg->track_flags);
    fail_unless(msg->doppler == 251, "incorrect value for doppler, expected 251, is %d", msg->doppler);
    fail_unless(msg->clock_offset == 100, "incorrect value for clock_offset, expected 100, is %d", msg->clock_offset);
    fail_unless(msg->pset_flags == 174, "incorrect value for pset_flags, expected 174, is %d", msg->pset_flags);
    fail_unless(msg->lock == 12345, "incorrect value for lock, expected 12345, is %d", msg->lock);
    fail_unless(msg->nav_flags == 173, "incorrect value for nav_flags, expected 173, is %d", msg->nav_flags);
    fail_unless(msg->P_std == 100, "incorrect value for P_std, expected 100, is %d", msg->P_std);
    fail_unless(msg->L.i == -120760716, "incorrect value for L.i, expected -120760716, is %d", msg->L.i);
    fail_unless(msg->L.f == 238, "incorrect value for L.f, expected 238, is %d", msg->L.f);
    fail_unless(msg->clock_drift == 10, "incorrect value for clock_drift, expected 10, is %d", msg->clock_drift);
    fail_unless(msg->tot.wn == 1876, "incorrect value for tot.wn, expected 1876, is %d", msg->tot.wn);
    fail_unless(msg->tot.tow == 86400000, "incorrect value for tot.tow, expected 86400000, is %d", msg->tot.tow);
    fail_unless(msg->sync_flags == 170, "incorrect value for sync_flags, expected 170, is %d", msg->sync_flags);
    fail_unless(msg->acceleration == 1, "incorrect value for acceleration, expected 1, is %d", msg->acceleration);
    fail_unless(msg->uptime == 3600, "incorrect value for uptime, expected 3600, is %d", msg->uptime);
    fail_unless(msg->recv_time == 5193332536, "incorrect value for recv_time, expected 5193332536, is %d", msg->recv_time);
    fail_unless(msg->cn0 == 0, "incorrect value for cn0, expected 0, is %d", msg->cn0);
    fail_unless(msg->doppler_std == 2, "incorrect value for doppler_std, expected 2, is %d", msg->doppler_std);
    fail_unless(msg->tow_flags == 171, "incorrect value for tow_flags, expected 171, is %d", msg->tow_flags);
    fail_unless(msg->misc_flags == 175, "incorrect value for misc_flags, expected 175, is %d", msg->misc_flags);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 65535, "incorrect value for sid.sat, expected 65535, is %d", msg->sid.sat);
    fail_unless(msg->corr_spacing == 2000, "incorrect value for corr_spacing, expected 2000, is %d", msg->corr_spacing);
    fail_unless(msg->P == 1149000000, "incorrect value for P, expected 1149000000, is %d", msg->P);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x11, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,17,0,67,192,55,120,254,139,53,1,0,0,0,0,92,38,5,84,7,64,89,124,68,100,0,116,86,205,248,238,0,57,48,255,255,0,0,251,0,0,0,2,0,16,14,0,0,100,0,10,0,208,7,1,170,171,172,173,174,175,93,190, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x11, 49219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 49219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_tracking_state_detailed_t* msg = ( msg_tracking_state_detailed_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->track_flags == 172, "incorrect value for track_flags, expected 172, is %d", msg->track_flags);
    fail_unless(msg->doppler == 251, "incorrect value for doppler, expected 251, is %d", msg->doppler);
    fail_unless(msg->clock_offset == 100, "incorrect value for clock_offset, expected 100, is %d", msg->clock_offset);
    fail_unless(msg->pset_flags == 174, "incorrect value for pset_flags, expected 174, is %d", msg->pset_flags);
    fail_unless(msg->lock == 12345, "incorrect value for lock, expected 12345, is %d", msg->lock);
    fail_unless(msg->nav_flags == 173, "incorrect value for nav_flags, expected 173, is %d", msg->nav_flags);
    fail_unless(msg->P_std == 100, "incorrect value for P_std, expected 100, is %d", msg->P_std);
    fail_unless(msg->L.i == -120760716, "incorrect value for L.i, expected -120760716, is %d", msg->L.i);
    fail_unless(msg->L.f == 238, "incorrect value for L.f, expected 238, is %d", msg->L.f);
    fail_unless(msg->clock_drift == 10, "incorrect value for clock_drift, expected 10, is %d", msg->clock_drift);
    fail_unless(msg->tot.wn == 1876, "incorrect value for tot.wn, expected 1876, is %d", msg->tot.wn);
    fail_unless(msg->tot.tow == 86400000, "incorrect value for tot.tow, expected 86400000, is %d", msg->tot.tow);
    fail_unless(msg->sync_flags == 170, "incorrect value for sync_flags, expected 170, is %d", msg->sync_flags);
    fail_unless(msg->acceleration == 1, "incorrect value for acceleration, expected 1, is %d", msg->acceleration);
    fail_unless(msg->uptime == 3600, "incorrect value for uptime, expected 3600, is %d", msg->uptime);
    fail_unless(msg->recv_time == 5193334392, "incorrect value for recv_time, expected 5193334392, is %d", msg->recv_time);
    fail_unless(msg->cn0 == 0, "incorrect value for cn0, expected 0, is %d", msg->cn0);
    fail_unless(msg->doppler_std == 2, "incorrect value for doppler_std, expected 2, is %d", msg->doppler_std);
    fail_unless(msg->tow_flags == 171, "incorrect value for tow_flags, expected 171, is %d", msg->tow_flags);
    fail_unless(msg->misc_flags == 175, "incorrect value for misc_flags, expected 175, is %d", msg->misc_flags);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 65535, "incorrect value for sid.sat, expected 65535, is %d", msg->sid.sat);
    fail_unless(msg->corr_spacing == 2000, "incorrect value for corr_spacing, expected 2000, is %d", msg->corr_spacing);
    fail_unless(msg->P == 1149000000, "incorrect value for P, expected 1149000000, is %d", msg->P);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x11, &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 test_data[] = {85,17,0,67,192,55,206,5,140,53,1,0,0,0,0,92,38,5,84,7,64,89,124,68,100,0,116,86,205,248,238,0,57,48,255,255,0,0,251,0,0,0,2,0,16,14,0,0,100,0,10,0,208,7,1,170,171,172,173,174,175,161,251, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x11, 49219, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 49219,
        "sender_id decoded incorrectly");
    fail_unless(last_len == sizeof(test_data),
        "len decoded incorrectly");
    fail_unless(memcmp(last_msg, test_data, sizeof(test_data))
          == 0,
        "test data decoded incorrectly");
    fail_unless(last_context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_tracking_state_detailed_t* msg = ( msg_tracking_state_detailed_t *)((void *)last_msg + 6);
    // Run tests against fields
    fail_unless(msg != 0, "stub to prevent warnings if msg isn't used");
    fail_unless(msg->track_flags == 172, "incorrect value for track_flags, expected 172, is %d", msg->track_flags);
    fail_unless(msg->doppler == 251, "incorrect value for doppler, expected 251, is %d", msg->doppler);
    fail_unless(msg->clock_offset == 100, "incorrect value for clock_offset, expected 100, is %d", msg->clock_offset);
    fail_unless(msg->pset_flags == 174, "incorrect value for pset_flags, expected 174, is %d", msg->pset_flags);
    fail_unless(msg->lock == 12345, "incorrect value for lock, expected 12345, is %d", msg->lock);
    fail_unless(msg->nav_flags == 173, "incorrect value for nav_flags, expected 173, is %d", msg->nav_flags);
    fail_unless(msg->P_std == 100, "incorrect value for P_std, expected 100, is %d", msg->P_std);
    fail_unless(msg->L.i == -120760716, "incorrect value for L.i, expected -120760716, is %d", msg->L.i);
    fail_unless(msg->L.f == 238, "incorrect value for L.f, expected 238, is %d", msg->L.f);
    fail_unless(msg->clock_drift == 10, "incorrect value for clock_drift, expected 10, is %d", msg->clock_drift);
    fail_unless(msg->tot.wn == 1876, "incorrect value for tot.wn, expected 1876, is %d", msg->tot.wn);
    fail_unless(msg->tot.tow == 86400000, "incorrect value for tot.tow, expected 86400000, is %d", msg->tot.tow);
    fail_unless(msg->sync_flags == 170, "incorrect value for sync_flags, expected 170, is %d", msg->sync_flags);
    fail_unless(msg->acceleration == 1, "incorrect value for acceleration, expected 1, is %d", msg->acceleration);
    fail_unless(msg->uptime == 3600, "incorrect value for uptime, expected 3600, is %d", msg->uptime);
    fail_unless(msg->recv_time == 5193336270, "incorrect value for recv_time, expected 5193336270, is %d", msg->recv_time);
    fail_unless(msg->cn0 == 0, "incorrect value for cn0, expected 0, is %d", msg->cn0);
    fail_unless(msg->doppler_std == 2, "incorrect value for doppler_std, expected 2, is %d", msg->doppler_std);
    fail_unless(msg->tow_flags == 171, "incorrect value for tow_flags, expected 171, is %d", msg->tow_flags);
    fail_unless(msg->misc_flags == 175, "incorrect value for misc_flags, expected 175, is %d", msg->misc_flags);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 65535, "incorrect value for sid.sat, expected 65535, is %d", msg->sid.sat);
    fail_unless(msg->corr_spacing == 2000, "incorrect value for corr_spacing, expected 2000, is %d", msg->corr_spacing);
    fail_unless(msg->P == 1149000000, "incorrect value for P, expected 1149000000, is %d", msg->P);
  }
}
END_TEST

Suite* auto_check_sbp_tracking_29_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_tracking_29");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_tracking_29");
  tcase_add_test(tc_acq, test_auto_check_sbp_tracking_29);
  suite_add_tcase(s, tc_acq);
  return s;
}