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

START_TEST( test_auto_check_sbp_tracking_41 )
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

    u8 test_data[] = {85,17,0,59,103,55,163,151,112,215,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,5,0,0,169,177,208,54,15,0,0,0,85,61,0,0,39,0,1,0,0,0,0,0,0,0,40,0,108,1,0,11,0,0,9,166,214, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x11, 26427, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 26427,
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
    fail_unless(msg->track_flags == 11, "incorrect value for track_flags, expected 11, is %d", msg->track_flags);
    fail_unless(msg->doppler == 15701, "incorrect value for doppler, expected 15701, is %d", msg->doppler);
    fail_unless(msg->clock_offset == 0, "incorrect value for clock_offset, expected 0, is %d", msg->clock_offset);
    fail_unless(msg->pset_flags == 0, "incorrect value for pset_flags, expected 0, is %d", msg->pset_flags);
    fail_unless(msg->lock == 14032, "incorrect value for lock, expected 14032, is %d", msg->lock);
    fail_unless(msg->nav_flags == 0, "incorrect value for nav_flags, expected 0, is %d", msg->nav_flags);
    fail_unless(msg->P_std == 0, "incorrect value for P_std, expected 0, is %d", msg->P_std);
    fail_unless(msg->L.i == 1319, "incorrect value for L.i, expected 1319, is %d", msg->L.i);
    fail_unless(msg->L.f == 169, "incorrect value for L.f, expected 169, is %d", msg->L.f);
    fail_unless(msg->clock_drift == 0, "incorrect value for clock_drift, expected 0, is %d", msg->clock_drift);
    fail_unless(msg->tot.wn == 0, "incorrect value for tot.wn, expected 0, is %d", msg->tot.wn);
    fail_unless(msg->tot.tow == 0, "incorrect value for tot.tow, expected 0, is %d", msg->tot.tow);
    fail_unless(msg->sync_flags == 1, "incorrect value for sync_flags, expected 1, is %d", msg->sync_flags);
    fail_unless(msg->acceleration == 108, "incorrect value for acceleration, expected 108, is %d", msg->acceleration);
    fail_unless(msg->uptime == 1, "incorrect value for uptime, expected 1, is %d", msg->uptime);
    fail_unless(msg->recv_time == 7909447587, "incorrect value for recv_time, expected 7909447587, is %d", msg->recv_time);
    fail_unless(msg->cn0 == 177, "incorrect value for cn0, expected 177, is %d", msg->cn0);
    fail_unless(msg->doppler_std == 39, "incorrect value for doppler_std, expected 39, is %d", msg->doppler_std);
    fail_unless(msg->tow_flags == 0, "incorrect value for tow_flags, expected 0, is %d", msg->tow_flags);
    fail_unless(msg->misc_flags == 9, "incorrect value for misc_flags, expected 9, is %d", msg->misc_flags);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 15, "incorrect value for sid.sat, expected 15, is %d", msg->sid.sat);
    fail_unless(msg->corr_spacing == 40, "incorrect value for corr_spacing, expected 40, is %d", msg->corr_spacing);
    fail_unless(msg->P == 0, "incorrect value for P, expected 0, is %d", msg->P);
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

    u8 test_data[] = {85,17,0,59,103,55,97,251,61,245,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,7,0,0,14,175,208,54,15,0,0,0,51,61,0,0,30,0,1,0,0,0,0,0,0,0,40,0,224,1,0,11,0,0,9,136,179, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x11, 26427, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 26427,
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
    fail_unless(msg->track_flags == 11, "incorrect value for track_flags, expected 11, is %d", msg->track_flags);
    fail_unless(msg->doppler == 15667, "incorrect value for doppler, expected 15667, is %d", msg->doppler);
    fail_unless(msg->clock_offset == 0, "incorrect value for clock_offset, expected 0, is %d", msg->clock_offset);
    fail_unless(msg->pset_flags == 0, "incorrect value for pset_flags, expected 0, is %d", msg->pset_flags);
    fail_unless(msg->lock == 14032, "incorrect value for lock, expected 14032, is %d", msg->lock);
    fail_unless(msg->nav_flags == 0, "incorrect value for nav_flags, expected 0, is %d", msg->nav_flags);
    fail_unless(msg->P_std == 0, "incorrect value for P_std, expected 0, is %d", msg->P_std);
    fail_unless(msg->L.i == 1810, "incorrect value for L.i, expected 1810, is %d", msg->L.i);
    fail_unless(msg->L.f == 14, "incorrect value for L.f, expected 14, is %d", msg->L.f);
    fail_unless(msg->clock_drift == 0, "incorrect value for clock_drift, expected 0, is %d", msg->clock_drift);
    fail_unless(msg->tot.wn == 0, "incorrect value for tot.wn, expected 0, is %d", msg->tot.wn);
    fail_unless(msg->tot.tow == 0, "incorrect value for tot.tow, expected 0, is %d", msg->tot.tow);
    fail_unless(msg->sync_flags == 1, "incorrect value for sync_flags, expected 1, is %d", msg->sync_flags);
    fail_unless(msg->acceleration == -32, "incorrect value for acceleration, expected -32, is %d", msg->acceleration);
    fail_unless(msg->uptime == 1, "incorrect value for uptime, expected 1, is %d", msg->uptime);
    fail_unless(msg->recv_time == 8409447265, "incorrect value for recv_time, expected 8409447265, is %d", msg->recv_time);
    fail_unless(msg->cn0 == 175, "incorrect value for cn0, expected 175, is %d", msg->cn0);
    fail_unless(msg->doppler_std == 30, "incorrect value for doppler_std, expected 30, is %d", msg->doppler_std);
    fail_unless(msg->tow_flags == 0, "incorrect value for tow_flags, expected 0, is %d", msg->tow_flags);
    fail_unless(msg->misc_flags == 9, "incorrect value for misc_flags, expected 9, is %d", msg->misc_flags);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 15, "incorrect value for sid.sat, expected 15, is %d", msg->sid.sat);
    fail_unless(msg->corr_spacing == 40, "incorrect value for corr_spacing, expected 40, is %d", msg->corr_spacing);
    fail_unless(msg->P == 0, "incorrect value for P, expected 0, is %d", msg->P);
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

    u8 test_data[] = {85,17,0,59,103,55,139,218,236,18,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,250,8,0,0,8,179,208,54,15,0,0,0,67,61,0,0,22,0,2,0,0,0,0,0,0,0,40,0,27,1,0,11,0,2,9,217,159, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x11, 26427, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 26427,
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
    fail_unless(msg->track_flags == 11, "incorrect value for track_flags, expected 11, is %d", msg->track_flags);
    fail_unless(msg->doppler == 15683, "incorrect value for doppler, expected 15683, is %d", msg->doppler);
    fail_unless(msg->clock_offset == 0, "incorrect value for clock_offset, expected 0, is %d", msg->clock_offset);
    fail_unless(msg->pset_flags == 2, "incorrect value for pset_flags, expected 2, is %d", msg->pset_flags);
    fail_unless(msg->lock == 14032, "incorrect value for lock, expected 14032, is %d", msg->lock);
    fail_unless(msg->nav_flags == 0, "incorrect value for nav_flags, expected 0, is %d", msg->nav_flags);
    fail_unless(msg->P_std == 0, "incorrect value for P_std, expected 0, is %d", msg->P_std);
    fail_unless(msg->L.i == 2298, "incorrect value for L.i, expected 2298, is %d", msg->L.i);
    fail_unless(msg->L.f == 8, "incorrect value for L.f, expected 8, is %d", msg->L.f);
    fail_unless(msg->clock_drift == 0, "incorrect value for clock_drift, expected 0, is %d", msg->clock_drift);
    fail_unless(msg->tot.wn == 0, "incorrect value for tot.wn, expected 0, is %d", msg->tot.wn);
    fail_unless(msg->tot.tow == 0, "incorrect value for tot.tow, expected 0, is %d", msg->tot.tow);
    fail_unless(msg->sync_flags == 1, "incorrect value for sync_flags, expected 1, is %d", msg->sync_flags);
    fail_unless(msg->acceleration == 27, "incorrect value for acceleration, expected 27, is %d", msg->acceleration);
    fail_unless(msg->uptime == 2, "incorrect value for uptime, expected 2, is %d", msg->uptime);
    fail_unless(msg->recv_time == 8907446923, "incorrect value for recv_time, expected 8907446923, is %d", msg->recv_time);
    fail_unless(msg->cn0 == 179, "incorrect value for cn0, expected 179, is %d", msg->cn0);
    fail_unless(msg->doppler_std == 22, "incorrect value for doppler_std, expected 22, is %d", msg->doppler_std);
    fail_unless(msg->tow_flags == 0, "incorrect value for tow_flags, expected 0, is %d", msg->tow_flags);
    fail_unless(msg->misc_flags == 9, "incorrect value for misc_flags, expected 9, is %d", msg->misc_flags);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 15, "incorrect value for sid.sat, expected 15, is %d", msg->sid.sat);
    fail_unless(msg->corr_spacing == 40, "incorrect value for corr_spacing, expected 40, is %d", msg->corr_spacing);
    fail_unless(msg->P == 0, "incorrect value for P, expected 0, is %d", msg->P);
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

    u8 test_data[] = {85,17,0,59,103,55,255,251,170,48,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,226,10,0,0,125,181,208,54,15,0,0,0,29,61,0,0,10,0,2,0,0,0,0,0,0,0,40,0,220,1,0,11,0,3,9,66,95, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x11, 26427, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 26427,
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
    fail_unless(msg->track_flags == 11, "incorrect value for track_flags, expected 11, is %d", msg->track_flags);
    fail_unless(msg->doppler == 15645, "incorrect value for doppler, expected 15645, is %d", msg->doppler);
    fail_unless(msg->clock_offset == 0, "incorrect value for clock_offset, expected 0, is %d", msg->clock_offset);
    fail_unless(msg->pset_flags == 3, "incorrect value for pset_flags, expected 3, is %d", msg->pset_flags);
    fail_unless(msg->lock == 14032, "incorrect value for lock, expected 14032, is %d", msg->lock);
    fail_unless(msg->nav_flags == 0, "incorrect value for nav_flags, expected 0, is %d", msg->nav_flags);
    fail_unless(msg->P_std == 0, "incorrect value for P_std, expected 0, is %d", msg->P_std);
    fail_unless(msg->L.i == 2786, "incorrect value for L.i, expected 2786, is %d", msg->L.i);
    fail_unless(msg->L.f == 125, "incorrect value for L.f, expected 125, is %d", msg->L.f);
    fail_unless(msg->clock_drift == 0, "incorrect value for clock_drift, expected 0, is %d", msg->clock_drift);
    fail_unless(msg->tot.wn == 0, "incorrect value for tot.wn, expected 0, is %d", msg->tot.wn);
    fail_unless(msg->tot.tow == 0, "incorrect value for tot.tow, expected 0, is %d", msg->tot.tow);
    fail_unless(msg->sync_flags == 1, "incorrect value for sync_flags, expected 1, is %d", msg->sync_flags);
    fail_unless(msg->acceleration == -36, "incorrect value for acceleration, expected -36, is %d", msg->acceleration);
    fail_unless(msg->uptime == 2, "incorrect value for uptime, expected 2, is %d", msg->uptime);
    fail_unless(msg->recv_time == 9406446591, "incorrect value for recv_time, expected 9406446591, is %d", msg->recv_time);
    fail_unless(msg->cn0 == 181, "incorrect value for cn0, expected 181, is %d", msg->cn0);
    fail_unless(msg->doppler_std == 10, "incorrect value for doppler_std, expected 10, is %d", msg->doppler_std);
    fail_unless(msg->tow_flags == 0, "incorrect value for tow_flags, expected 0, is %d", msg->tow_flags);
    fail_unless(msg->misc_flags == 9, "incorrect value for misc_flags, expected 9, is %d", msg->misc_flags);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 15, "incorrect value for sid.sat, expected 15, is %d", msg->sid.sat);
    fail_unless(msg->corr_spacing == 40, "incorrect value for corr_spacing, expected 40, is %d", msg->corr_spacing);
    fail_unless(msg->P == 0, "incorrect value for P, expected 0, is %d", msg->P);
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

    u8 test_data[] = {85,17,0,59,103,55,189,95,120,78,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,203,12,0,0,64,184,208,54,15,0,0,0,24,61,0,0,4,0,3,0,0,0,0,0,0,0,40,0,2,1,0,11,0,3,9,194,206, };

    dummy_reset();
    sbp_send_message(&sbp_state, 0x11, 26427, sizeof(test_data), test_data, &dummy_write);

    while (dummy_rd < dummy_wr) {
      fail_unless(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
          "sbp_process threw an error!");
    }

    fail_unless(n_callbacks_logged == 1,
        "one callback should have been logged");
    fail_unless(last_sender_id == 26427,
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
    fail_unless(msg->track_flags == 11, "incorrect value for track_flags, expected 11, is %d", msg->track_flags);
    fail_unless(msg->doppler == 15640, "incorrect value for doppler, expected 15640, is %d", msg->doppler);
    fail_unless(msg->clock_offset == 0, "incorrect value for clock_offset, expected 0, is %d", msg->clock_offset);
    fail_unless(msg->pset_flags == 3, "incorrect value for pset_flags, expected 3, is %d", msg->pset_flags);
    fail_unless(msg->lock == 14032, "incorrect value for lock, expected 14032, is %d", msg->lock);
    fail_unless(msg->nav_flags == 0, "incorrect value for nav_flags, expected 0, is %d", msg->nav_flags);
    fail_unless(msg->P_std == 0, "incorrect value for P_std, expected 0, is %d", msg->P_std);
    fail_unless(msg->L.i == 3275, "incorrect value for L.i, expected 3275, is %d", msg->L.i);
    fail_unless(msg->L.f == 64, "incorrect value for L.f, expected 64, is %d", msg->L.f);
    fail_unless(msg->clock_drift == 0, "incorrect value for clock_drift, expected 0, is %d", msg->clock_drift);
    fail_unless(msg->tot.wn == 0, "incorrect value for tot.wn, expected 0, is %d", msg->tot.wn);
    fail_unless(msg->tot.tow == 0, "incorrect value for tot.tow, expected 0, is %d", msg->tot.tow);
    fail_unless(msg->sync_flags == 1, "incorrect value for sync_flags, expected 1, is %d", msg->sync_flags);
    fail_unless(msg->acceleration == 2, "incorrect value for acceleration, expected 2, is %d", msg->acceleration);
    fail_unless(msg->uptime == 3, "incorrect value for uptime, expected 3, is %d", msg->uptime);
    fail_unless(msg->recv_time == 9906446269, "incorrect value for recv_time, expected 9906446269, is %d", msg->recv_time);
    fail_unless(msg->cn0 == 184, "incorrect value for cn0, expected 184, is %d", msg->cn0);
    fail_unless(msg->doppler_std == 4, "incorrect value for doppler_std, expected 4, is %d", msg->doppler_std);
    fail_unless(msg->tow_flags == 0, "incorrect value for tow_flags, expected 0, is %d", msg->tow_flags);
    fail_unless(msg->misc_flags == 9, "incorrect value for misc_flags, expected 9, is %d", msg->misc_flags);
    fail_unless(msg->sid.code == 0, "incorrect value for sid.code, expected 0, is %d", msg->sid.code);
    fail_unless(msg->sid.reserved == 0, "incorrect value for sid.reserved, expected 0, is %d", msg->sid.reserved);
    fail_unless(msg->sid.sat == 15, "incorrect value for sid.sat, expected 15, is %d", msg->sid.sat);
    fail_unless(msg->corr_spacing == 40, "incorrect value for corr_spacing, expected 40, is %d", msg->corr_spacing);
    fail_unless(msg->P == 0, "incorrect value for P, expected 0, is %d", msg->P);
  }
}
END_TEST

Suite* auto_check_sbp_tracking_41_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_tracking_41");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_tracking_41");
  tcase_add_test(tc_acq, test_auto_check_sbp_tracking_41);
  suite_add_tcase(s, tc_acq);
  return s;
}