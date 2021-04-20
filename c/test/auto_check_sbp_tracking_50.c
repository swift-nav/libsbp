/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDep.yaml
// by generate.py. Do not modify by hand!

#include <check.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include <tracking.h>

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 payload[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_payload;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 payload_len;
  u8 payload[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  sbp_msg_t msg;
  void *context;
} last_unpacked;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return real_n;
}

static void logging_reset() {
  memset(&last_payload, 0, sizeof(last_payload));
  memset(&last_frame, 0, sizeof(last_frame));
  memset(&last_unpacked, 0, sizeof(last_unpacked));
}

static void payload_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_payload.n_callbacks_logged++;
  last_payload.sender_id = sender_id;
  last_payload.len = len;
  last_payload.context = context;
  memcpy(last_payload.payload, msg, len);

  /*printy_callback(sender_id, len, msg);*/
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 payload_len,
                           u8 payload[], u16 frame_len, u8 frame[],
                           void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.payload_len = payload_len;
  memcpy(last_frame.payload, payload, payload_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

static void unpacked_callback(u16 sender_id, u16 msg_type, const sbp_msg_t *msg,
                              void *context) {
  last_unpacked.n_callbacks_logged++;
  last_unpacked.sender_id = sender_id;
  last_unpacked.msg_type = msg_type;
  memcpy(&last_unpacked.msg, msg, sizeof(*msg));
  last_unpacked.context = context;
}

START_TEST(test_auto_check_sbp_tracking_50) {
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;
  static sbp_msg_callbacks_node_t n3;

  // State of the SBP message parser.
  // Must be statically allocated.
  sbp_state_t sbp_state;

  //
  // Run tests:
  //
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x11, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x11, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x11, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  17, 0,  59, 103, 55, 163, 151, 112, 215, 1,  0, 0, 0,   0,   0,
        0,   0,  0,  0,  0,   0,  0,   0,   0,   0,   39, 5, 0, 0,   169, 177,
        208, 54, 15, 0,  0,   0,  85,  61,  0,   0,   39, 0, 1, 0,   0,   0,
        0,   0,  0,  0,  40,  0,  108, 1,   0,   11,  0,  0, 9, 166, 214,
    };
    u8 test_encoded_payload_data[] = {
        163, 151, 112, 215, 1,  0,  0,   0, 0,  0,  0,   0,   0,   0,
        0,   0,   0,   0,   0,  0,  39,  5, 0,  0,  169, 177, 208, 54,
        15,  0,   0,   0,   85, 61, 0,   0, 39, 0,  1,   0,   0,   0,
        0,   0,   0,   0,   40, 0,  108, 1, 0,  11, 0,   0,   9,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_tracking_state_detailed_dep_t *test_msg =
        (sbp_msg_tracking_state_detailed_dep_t *)&test_msg_storage;
    test_msg->L.f = 169;
    test_msg->L.i = 1319;
    test_msg->P = 0;
    test_msg->P_std = 0;
    test_msg->acceleration = 108;
    test_msg->clock_drift = 0;
    test_msg->clock_offset = 0;
    test_msg->cn0 = 177;
    test_msg->corr_spacing = 40;
    test_msg->doppler = 15701;
    test_msg->doppler_std = 39;
    test_msg->lock = 14032;
    test_msg->misc_flags = 9;
    test_msg->nav_flags = 0;
    test_msg->pset_flags = 0;
    test_msg->recv_time = 7909447587;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 15;
    test_msg->sync_flags = 1;
    test_msg->tot.tow = 0;
    test_msg->tot.wn = 0;
    test_msg->tow_flags = 0;
    test_msg->track_flags = 11;
    test_msg->uptime = 1;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x11, 26427, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_tracking_state_detailed_dep_t *check_msg =
        (sbp_msg_tracking_state_detailed_dep_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->L.f == 169,
                  "incorrect value for L.f, expected 169, is %d",
                  check_msg->L.f);
    ck_assert_msg(check_msg->L.i == 1319,
                  "incorrect value for L.i, expected 1319, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 0, "incorrect value for P, expected 0, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 0,
                  "incorrect value for P_std, expected 0, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == 108,
                  "incorrect value for acceleration, expected 108, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 0,
                  "incorrect value for clock_drift, expected 0, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 0,
                  "incorrect value for clock_offset, expected 0, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 177,
                  "incorrect value for cn0, expected 177, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 40,
                  "incorrect value for corr_spacing, expected 40, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 15701,
                  "incorrect value for doppler, expected 15701, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 39,
                  "incorrect value for doppler_std, expected 39, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 14032,
                  "incorrect value for lock, expected 14032, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 9,
                  "incorrect value for misc_flags, expected 9, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 0,
                  "incorrect value for nav_flags, expected 0, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 0,
                  "incorrect value for pset_flags, expected 0, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 7909447587,
                  "incorrect value for recv_time, expected 7909447587, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 15,
                  "incorrect value for sid.sat, expected 15, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 1,
                  "incorrect value for sync_flags, expected 1, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(check_msg->tot.tow == 0,
                  "incorrect value for tot.tow, expected 0, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 0,
                  "incorrect value for tot.wn, expected 0, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 0,
                  "incorrect value for tow_flags, expected 0, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 11,
                  "incorrect value for track_flags, expected 11, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 1,
                  "incorrect value for uptime, expected 1, is %d",
                  check_msg->uptime);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x11, 26427,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->L.f == 169,
                  "incorrect value for L.f, expected 169, is %d",
                  check_msg->L.f);
    ck_assert_msg(check_msg->L.i == 1319,
                  "incorrect value for L.i, expected 1319, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 0, "incorrect value for P, expected 0, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 0,
                  "incorrect value for P_std, expected 0, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == 108,
                  "incorrect value for acceleration, expected 108, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 0,
                  "incorrect value for clock_drift, expected 0, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 0,
                  "incorrect value for clock_offset, expected 0, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 177,
                  "incorrect value for cn0, expected 177, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 40,
                  "incorrect value for corr_spacing, expected 40, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 15701,
                  "incorrect value for doppler, expected 15701, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 39,
                  "incorrect value for doppler_std, expected 39, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 14032,
                  "incorrect value for lock, expected 14032, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 9,
                  "incorrect value for misc_flags, expected 9, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 0,
                  "incorrect value for nav_flags, expected 0, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 0,
                  "incorrect value for pset_flags, expected 0, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 7909447587,
                  "incorrect value for recv_time, expected 7909447587, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 15,
                  "incorrect value for sid.sat, expected 15, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 1,
                  "incorrect value for sync_flags, expected 1, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(check_msg->tot.tow == 0,
                  "incorrect value for tot.tow, expected 0, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 0,
                  "incorrect value for tot.wn, expected 0, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 0,
                  "incorrect value for tow_flags, expected 0, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 11,
                  "incorrect value for track_flags, expected 11, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 1,
                  "incorrect value for uptime, expected 1, is %d",
                  check_msg->uptime);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x11, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x11, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x11, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  17, 0,  59, 103, 55, 97,  251, 61, 245, 1,  0, 0, 0,   0,   0,
        0,   0,  0,  0,  0,   0,  0,   0,   0,  0,   18, 7, 0, 0,   14,  175,
        208, 54, 15, 0,  0,   0,  51,  61,  0,  0,   30, 0, 1, 0,   0,   0,
        0,   0,  0,  0,  40,  0,  224, 1,   0,  11,  0,  0, 9, 136, 179,
    };
    u8 test_encoded_payload_data[] = {
        97, 251, 61, 245, 1,  0,  0,   0, 0,  0,  0,  0,   0,   0,
        0,  0,   0,  0,   0,  0,  18,  7, 0,  0,  14, 175, 208, 54,
        15, 0,   0,  0,   51, 61, 0,   0, 30, 0,  1,  0,   0,   0,
        0,  0,   0,  0,   40, 0,  224, 1, 0,  11, 0,  0,   9,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_tracking_state_detailed_dep_t *test_msg =
        (sbp_msg_tracking_state_detailed_dep_t *)&test_msg_storage;
    test_msg->L.f = 14;
    test_msg->L.i = 1810;
    test_msg->P = 0;
    test_msg->P_std = 0;
    test_msg->acceleration = -32;
    test_msg->clock_drift = 0;
    test_msg->clock_offset = 0;
    test_msg->cn0 = 175;
    test_msg->corr_spacing = 40;
    test_msg->doppler = 15667;
    test_msg->doppler_std = 30;
    test_msg->lock = 14032;
    test_msg->misc_flags = 9;
    test_msg->nav_flags = 0;
    test_msg->pset_flags = 0;
    test_msg->recv_time = 8409447265;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 15;
    test_msg->sync_flags = 1;
    test_msg->tot.tow = 0;
    test_msg->tot.wn = 0;
    test_msg->tow_flags = 0;
    test_msg->track_flags = 11;
    test_msg->uptime = 1;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x11, 26427, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_tracking_state_detailed_dep_t *check_msg =
        (sbp_msg_tracking_state_detailed_dep_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->L.f == 14,
                  "incorrect value for L.f, expected 14, is %d",
                  check_msg->L.f);
    ck_assert_msg(check_msg->L.i == 1810,
                  "incorrect value for L.i, expected 1810, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 0, "incorrect value for P, expected 0, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 0,
                  "incorrect value for P_std, expected 0, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == -32,
                  "incorrect value for acceleration, expected -32, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 0,
                  "incorrect value for clock_drift, expected 0, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 0,
                  "incorrect value for clock_offset, expected 0, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 175,
                  "incorrect value for cn0, expected 175, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 40,
                  "incorrect value for corr_spacing, expected 40, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 15667,
                  "incorrect value for doppler, expected 15667, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 30,
                  "incorrect value for doppler_std, expected 30, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 14032,
                  "incorrect value for lock, expected 14032, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 9,
                  "incorrect value for misc_flags, expected 9, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 0,
                  "incorrect value for nav_flags, expected 0, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 0,
                  "incorrect value for pset_flags, expected 0, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 8409447265,
                  "incorrect value for recv_time, expected 8409447265, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 15,
                  "incorrect value for sid.sat, expected 15, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 1,
                  "incorrect value for sync_flags, expected 1, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(check_msg->tot.tow == 0,
                  "incorrect value for tot.tow, expected 0, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 0,
                  "incorrect value for tot.wn, expected 0, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 0,
                  "incorrect value for tow_flags, expected 0, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 11,
                  "incorrect value for track_flags, expected 11, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 1,
                  "incorrect value for uptime, expected 1, is %d",
                  check_msg->uptime);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x11, 26427,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->L.f == 14,
                  "incorrect value for L.f, expected 14, is %d",
                  check_msg->L.f);
    ck_assert_msg(check_msg->L.i == 1810,
                  "incorrect value for L.i, expected 1810, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 0, "incorrect value for P, expected 0, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 0,
                  "incorrect value for P_std, expected 0, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == -32,
                  "incorrect value for acceleration, expected -32, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 0,
                  "incorrect value for clock_drift, expected 0, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 0,
                  "incorrect value for clock_offset, expected 0, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 175,
                  "incorrect value for cn0, expected 175, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 40,
                  "incorrect value for corr_spacing, expected 40, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 15667,
                  "incorrect value for doppler, expected 15667, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 30,
                  "incorrect value for doppler_std, expected 30, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 14032,
                  "incorrect value for lock, expected 14032, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 9,
                  "incorrect value for misc_flags, expected 9, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 0,
                  "incorrect value for nav_flags, expected 0, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 0,
                  "incorrect value for pset_flags, expected 0, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 8409447265,
                  "incorrect value for recv_time, expected 8409447265, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 15,
                  "incorrect value for sid.sat, expected 15, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 1,
                  "incorrect value for sync_flags, expected 1, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(check_msg->tot.tow == 0,
                  "incorrect value for tot.tow, expected 0, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 0,
                  "incorrect value for tot.wn, expected 0, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 0,
                  "incorrect value for tow_flags, expected 0, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 11,
                  "incorrect value for track_flags, expected 11, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 1,
                  "incorrect value for uptime, expected 1, is %d",
                  check_msg->uptime);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x11, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x11, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x11, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  17, 0,  59, 103, 55, 139, 218, 236, 18, 2,   0, 0, 0,   0,   0,
        0,   0,  0,  0,  0,   0,  0,   0,   0,   0,  250, 8, 0, 0,   8,   179,
        208, 54, 15, 0,  0,   0,  67,  61,  0,   0,  22,  0, 2, 0,   0,   0,
        0,   0,  0,  0,  40,  0,  27,  1,   0,   11, 0,   2, 9, 217, 159,
    };
    u8 test_encoded_payload_data[] = {
        139, 218, 236, 18, 2,  0,  0,   0, 0,  0,  0, 0,   0,   0,
        0,   0,   0,   0,  0,  0,  250, 8, 0,  0,  8, 179, 208, 54,
        15,  0,   0,   0,  67, 61, 0,   0, 22, 0,  2, 0,   0,   0,
        0,   0,   0,   0,  40, 0,  27,  1, 0,  11, 0, 2,   9,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_tracking_state_detailed_dep_t *test_msg =
        (sbp_msg_tracking_state_detailed_dep_t *)&test_msg_storage;
    test_msg->L.f = 8;
    test_msg->L.i = 2298;
    test_msg->P = 0;
    test_msg->P_std = 0;
    test_msg->acceleration = 27;
    test_msg->clock_drift = 0;
    test_msg->clock_offset = 0;
    test_msg->cn0 = 179;
    test_msg->corr_spacing = 40;
    test_msg->doppler = 15683;
    test_msg->doppler_std = 22;
    test_msg->lock = 14032;
    test_msg->misc_flags = 9;
    test_msg->nav_flags = 0;
    test_msg->pset_flags = 2;
    test_msg->recv_time = 8907446923;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 15;
    test_msg->sync_flags = 1;
    test_msg->tot.tow = 0;
    test_msg->tot.wn = 0;
    test_msg->tow_flags = 0;
    test_msg->track_flags = 11;
    test_msg->uptime = 2;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x11, 26427, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_tracking_state_detailed_dep_t *check_msg =
        (sbp_msg_tracking_state_detailed_dep_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->L.f == 8,
                  "incorrect value for L.f, expected 8, is %d", check_msg->L.f);
    ck_assert_msg(check_msg->L.i == 2298,
                  "incorrect value for L.i, expected 2298, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 0, "incorrect value for P, expected 0, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 0,
                  "incorrect value for P_std, expected 0, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == 27,
                  "incorrect value for acceleration, expected 27, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 0,
                  "incorrect value for clock_drift, expected 0, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 0,
                  "incorrect value for clock_offset, expected 0, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 179,
                  "incorrect value for cn0, expected 179, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 40,
                  "incorrect value for corr_spacing, expected 40, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 15683,
                  "incorrect value for doppler, expected 15683, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 22,
                  "incorrect value for doppler_std, expected 22, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 14032,
                  "incorrect value for lock, expected 14032, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 9,
                  "incorrect value for misc_flags, expected 9, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 0,
                  "incorrect value for nav_flags, expected 0, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 2,
                  "incorrect value for pset_flags, expected 2, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 8907446923,
                  "incorrect value for recv_time, expected 8907446923, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 15,
                  "incorrect value for sid.sat, expected 15, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 1,
                  "incorrect value for sync_flags, expected 1, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(check_msg->tot.tow == 0,
                  "incorrect value for tot.tow, expected 0, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 0,
                  "incorrect value for tot.wn, expected 0, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 0,
                  "incorrect value for tow_flags, expected 0, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 11,
                  "incorrect value for track_flags, expected 11, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 2,
                  "incorrect value for uptime, expected 2, is %d",
                  check_msg->uptime);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x11, 26427,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->L.f == 8,
                  "incorrect value for L.f, expected 8, is %d", check_msg->L.f);
    ck_assert_msg(check_msg->L.i == 2298,
                  "incorrect value for L.i, expected 2298, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 0, "incorrect value for P, expected 0, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 0,
                  "incorrect value for P_std, expected 0, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == 27,
                  "incorrect value for acceleration, expected 27, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 0,
                  "incorrect value for clock_drift, expected 0, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 0,
                  "incorrect value for clock_offset, expected 0, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 179,
                  "incorrect value for cn0, expected 179, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 40,
                  "incorrect value for corr_spacing, expected 40, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 15683,
                  "incorrect value for doppler, expected 15683, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 22,
                  "incorrect value for doppler_std, expected 22, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 14032,
                  "incorrect value for lock, expected 14032, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 9,
                  "incorrect value for misc_flags, expected 9, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 0,
                  "incorrect value for nav_flags, expected 0, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 2,
                  "incorrect value for pset_flags, expected 2, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 8907446923,
                  "incorrect value for recv_time, expected 8907446923, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 15,
                  "incorrect value for sid.sat, expected 15, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 1,
                  "incorrect value for sync_flags, expected 1, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(check_msg->tot.tow == 0,
                  "incorrect value for tot.tow, expected 0, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 0,
                  "incorrect value for tot.wn, expected 0, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 0,
                  "incorrect value for tow_flags, expected 0, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 11,
                  "incorrect value for track_flags, expected 11, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 2,
                  "incorrect value for uptime, expected 2, is %d",
                  check_msg->uptime);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x11, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x11, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x11, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  17, 0,  59, 103, 55, 255, 251, 170, 48, 2,   0,  0, 0,  0,   0,
        0,   0,  0,  0,  0,   0,  0,   0,   0,   0,  226, 10, 0, 0,  125, 181,
        208, 54, 15, 0,  0,   0,  29,  61,  0,   0,  10,  0,  2, 0,  0,   0,
        0,   0,  0,  0,  40,  0,  220, 1,   0,   11, 0,   3,  9, 66, 95,
    };
    u8 test_encoded_payload_data[] = {
        255, 251, 170, 48, 2,  0,  0,   0,  0,  0,  0,   0,   0,   0,
        0,   0,   0,   0,  0,  0,  226, 10, 0,  0,  125, 181, 208, 54,
        15,  0,   0,   0,  29, 61, 0,   0,  10, 0,  2,   0,   0,   0,
        0,   0,   0,   0,  40, 0,  220, 1,  0,  11, 0,   3,   9,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_tracking_state_detailed_dep_t *test_msg =
        (sbp_msg_tracking_state_detailed_dep_t *)&test_msg_storage;
    test_msg->L.f = 125;
    test_msg->L.i = 2786;
    test_msg->P = 0;
    test_msg->P_std = 0;
    test_msg->acceleration = -36;
    test_msg->clock_drift = 0;
    test_msg->clock_offset = 0;
    test_msg->cn0 = 181;
    test_msg->corr_spacing = 40;
    test_msg->doppler = 15645;
    test_msg->doppler_std = 10;
    test_msg->lock = 14032;
    test_msg->misc_flags = 9;
    test_msg->nav_flags = 0;
    test_msg->pset_flags = 3;
    test_msg->recv_time = 9406446591;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 15;
    test_msg->sync_flags = 1;
    test_msg->tot.tow = 0;
    test_msg->tot.wn = 0;
    test_msg->tow_flags = 0;
    test_msg->track_flags = 11;
    test_msg->uptime = 2;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x11, 26427, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_tracking_state_detailed_dep_t *check_msg =
        (sbp_msg_tracking_state_detailed_dep_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->L.f == 125,
                  "incorrect value for L.f, expected 125, is %d",
                  check_msg->L.f);
    ck_assert_msg(check_msg->L.i == 2786,
                  "incorrect value for L.i, expected 2786, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 0, "incorrect value for P, expected 0, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 0,
                  "incorrect value for P_std, expected 0, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == -36,
                  "incorrect value for acceleration, expected -36, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 0,
                  "incorrect value for clock_drift, expected 0, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 0,
                  "incorrect value for clock_offset, expected 0, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 181,
                  "incorrect value for cn0, expected 181, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 40,
                  "incorrect value for corr_spacing, expected 40, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 15645,
                  "incorrect value for doppler, expected 15645, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 10,
                  "incorrect value for doppler_std, expected 10, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 14032,
                  "incorrect value for lock, expected 14032, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 9,
                  "incorrect value for misc_flags, expected 9, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 0,
                  "incorrect value for nav_flags, expected 0, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 3,
                  "incorrect value for pset_flags, expected 3, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 9406446591,
                  "incorrect value for recv_time, expected 9406446591, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 15,
                  "incorrect value for sid.sat, expected 15, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 1,
                  "incorrect value for sync_flags, expected 1, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(check_msg->tot.tow == 0,
                  "incorrect value for tot.tow, expected 0, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 0,
                  "incorrect value for tot.wn, expected 0, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 0,
                  "incorrect value for tow_flags, expected 0, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 11,
                  "incorrect value for track_flags, expected 11, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 2,
                  "incorrect value for uptime, expected 2, is %d",
                  check_msg->uptime);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x11, 26427,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->L.f == 125,
                  "incorrect value for L.f, expected 125, is %d",
                  check_msg->L.f);
    ck_assert_msg(check_msg->L.i == 2786,
                  "incorrect value for L.i, expected 2786, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 0, "incorrect value for P, expected 0, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 0,
                  "incorrect value for P_std, expected 0, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == -36,
                  "incorrect value for acceleration, expected -36, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 0,
                  "incorrect value for clock_drift, expected 0, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 0,
                  "incorrect value for clock_offset, expected 0, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 181,
                  "incorrect value for cn0, expected 181, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 40,
                  "incorrect value for corr_spacing, expected 40, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 15645,
                  "incorrect value for doppler, expected 15645, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 10,
                  "incorrect value for doppler_std, expected 10, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 14032,
                  "incorrect value for lock, expected 14032, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 9,
                  "incorrect value for misc_flags, expected 9, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 0,
                  "incorrect value for nav_flags, expected 0, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 3,
                  "incorrect value for pset_flags, expected 3, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 9406446591,
                  "incorrect value for recv_time, expected 9406446591, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 15,
                  "incorrect value for sid.sat, expected 15, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 1,
                  "incorrect value for sync_flags, expected 1, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(check_msg->tot.tow == 0,
                  "incorrect value for tot.tow, expected 0, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 0,
                  "incorrect value for tot.wn, expected 0, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 0,
                  "incorrect value for tow_flags, expected 0, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 11,
                  "incorrect value for track_flags, expected 11, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 2,
                  "incorrect value for uptime, expected 2, is %d",
                  check_msg->uptime);
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0x11, &payload_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x11, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);
    sbp_register_unpacked_callback(&sbp_state, 0x11, &unpacked_callback,
                                   &DUMMY_MEMORY_FOR_CALLBACKS, &n3);

    u8 test_encoded_frame_data[] = {
        85,  17, 0,  59, 103, 55, 189, 95, 120, 78, 2,   0,  0, 0,   0,   0,
        0,   0,  0,  0,  0,   0,  0,   0,  0,   0,  203, 12, 0, 0,   64,  184,
        208, 54, 15, 0,  0,   0,  24,  61, 0,   0,  4,   0,  3, 0,   0,   0,
        0,   0,  0,  0,  40,  0,  2,   1,  0,   11, 0,   3,  9, 194, 206,
    };
    u8 test_encoded_payload_data[] = {
        189, 95,  120, 78, 2, 0,  0,   0,   0,  0,  0, 0, 0, 0,  0,  0, 0, 0, 0,
        0,   203, 12,  0,  0, 64, 184, 208, 54, 15, 0, 0, 0, 24, 61, 0, 0, 4, 0,
        3,   0,   0,   0,  0, 0,  0,   0,   40, 0,  2, 1, 0, 11, 0,  3, 9,
    };

    sbp_msg_t test_msg_storage;
    memset(&test_msg_storage, 0, sizeof(test_msg_storage));
    sbp_msg_tracking_state_detailed_dep_t *test_msg =
        (sbp_msg_tracking_state_detailed_dep_t *)&test_msg_storage;
    test_msg->L.f = 64;
    test_msg->L.i = 3275;
    test_msg->P = 0;
    test_msg->P_std = 0;
    test_msg->acceleration = 2;
    test_msg->clock_drift = 0;
    test_msg->clock_offset = 0;
    test_msg->cn0 = 184;
    test_msg->corr_spacing = 40;
    test_msg->doppler = 15640;
    test_msg->doppler_std = 4;
    test_msg->lock = 14032;
    test_msg->misc_flags = 9;
    test_msg->nav_flags = 0;
    test_msg->pset_flags = 3;
    test_msg->recv_time = 9906446269;
    test_msg->sid.code = 0;
    test_msg->sid.reserved = 0;
    test_msg->sid.sat = 15;
    test_msg->sync_flags = 1;
    test_msg->tot.tow = 0;
    test_msg->tot.wn = 0;
    test_msg->tow_flags = 0;
    test_msg->track_flags = 11;
    test_msg->uptime = 3;

    dummy_reset();
    logging_reset();

    // Test sending an unpacked message
    sbp_send_message(&sbp_state, 0x11, 26427, &test_msg_storage, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    sbp_msg_tracking_state_detailed_dep_t *check_msg =
        (sbp_msg_tracking_state_detailed_dep_t *)&last_unpacked.msg;
    // Run tests against fields
    ck_assert_msg(check_msg->L.f == 64,
                  "incorrect value for L.f, expected 64, is %d",
                  check_msg->L.f);
    ck_assert_msg(check_msg->L.i == 3275,
                  "incorrect value for L.i, expected 3275, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 0, "incorrect value for P, expected 0, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 0,
                  "incorrect value for P_std, expected 0, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == 2,
                  "incorrect value for acceleration, expected 2, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 0,
                  "incorrect value for clock_drift, expected 0, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 0,
                  "incorrect value for clock_offset, expected 0, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 184,
                  "incorrect value for cn0, expected 184, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 40,
                  "incorrect value for corr_spacing, expected 40, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 15640,
                  "incorrect value for doppler, expected 15640, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 4,
                  "incorrect value for doppler_std, expected 4, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 14032,
                  "incorrect value for lock, expected 14032, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 9,
                  "incorrect value for misc_flags, expected 9, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 0,
                  "incorrect value for nav_flags, expected 0, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 3,
                  "incorrect value for pset_flags, expected 3, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 9906446269,
                  "incorrect value for recv_time, expected 9906446269, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 15,
                  "incorrect value for sid.sat, expected 15, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 1,
                  "incorrect value for sync_flags, expected 1, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(check_msg->tot.tow == 0,
                  "incorrect value for tot.tow, expected 0, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 0,
                  "incorrect value for tot.wn, expected 0, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 0,
                  "incorrect value for tow_flags, expected 0, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 11,
                  "incorrect value for track_flags, expected 11, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 3,
                  "incorrect value for uptime, expected 3, is %d",
                  check_msg->uptime);

    // Test again by sending an already encoded payload

    dummy_reset();
    logging_reset();

    sbp_send_packed_message(&sbp_state, 0x11, 26427,
                            sizeof(test_encoded_payload_data),
                            test_encoded_payload_data, &dummy_write);

    ck_assert_msg(memcmp(dummy_buff, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "message not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_payload.n_callbacks_logged == 1,
                  "one payload callback should have been logged");
    ck_assert_msg(last_payload.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_payload.len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_payload.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_payload.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "one frame callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 26427,
                  "sender_id decoded incorrectly");
    ck_assert_msg(last_frame.payload_len == sizeof(test_encoded_payload_data),
                  "len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.payload, test_encoded_payload_data,
                         sizeof(test_encoded_payload_data)) == 0,
                  "test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(test_encoded_frame_data),
                  "frame len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, test_encoded_frame_data,
                         sizeof(test_encoded_frame_data)) == 0,
                  "frame data decoded incorrectly");
    // Run tests against fields
    ck_assert_msg(check_msg->L.f == 64,
                  "incorrect value for L.f, expected 64, is %d",
                  check_msg->L.f);
    ck_assert_msg(check_msg->L.i == 3275,
                  "incorrect value for L.i, expected 3275, is %d",
                  check_msg->L.i);
    ck_assert_msg(check_msg->P == 0, "incorrect value for P, expected 0, is %d",
                  check_msg->P);
    ck_assert_msg(check_msg->P_std == 0,
                  "incorrect value for P_std, expected 0, is %d",
                  check_msg->P_std);
    ck_assert_msg(check_msg->acceleration == 2,
                  "incorrect value for acceleration, expected 2, is %d",
                  check_msg->acceleration);
    ck_assert_msg(check_msg->clock_drift == 0,
                  "incorrect value for clock_drift, expected 0, is %d",
                  check_msg->clock_drift);
    ck_assert_msg(check_msg->clock_offset == 0,
                  "incorrect value for clock_offset, expected 0, is %d",
                  check_msg->clock_offset);
    ck_assert_msg(check_msg->cn0 == 184,
                  "incorrect value for cn0, expected 184, is %d",
                  check_msg->cn0);
    ck_assert_msg(check_msg->corr_spacing == 40,
                  "incorrect value for corr_spacing, expected 40, is %d",
                  check_msg->corr_spacing);
    ck_assert_msg(check_msg->doppler == 15640,
                  "incorrect value for doppler, expected 15640, is %d",
                  check_msg->doppler);
    ck_assert_msg(check_msg->doppler_std == 4,
                  "incorrect value for doppler_std, expected 4, is %d",
                  check_msg->doppler_std);
    ck_assert_msg(check_msg->lock == 14032,
                  "incorrect value for lock, expected 14032, is %d",
                  check_msg->lock);
    ck_assert_msg(check_msg->misc_flags == 9,
                  "incorrect value for misc_flags, expected 9, is %d",
                  check_msg->misc_flags);
    ck_assert_msg(check_msg->nav_flags == 0,
                  "incorrect value for nav_flags, expected 0, is %d",
                  check_msg->nav_flags);
    ck_assert_msg(check_msg->pset_flags == 3,
                  "incorrect value for pset_flags, expected 3, is %d",
                  check_msg->pset_flags);
    ck_assert_msg(check_msg->recv_time == 9906446269,
                  "incorrect value for recv_time, expected 9906446269, is %d",
                  check_msg->recv_time);
    ck_assert_msg(check_msg->sid.code == 0,
                  "incorrect value for sid.code, expected 0, is %d",
                  check_msg->sid.code);
    ck_assert_msg(check_msg->sid.reserved == 0,
                  "incorrect value for sid.reserved, expected 0, is %d",
                  check_msg->sid.reserved);
    ck_assert_msg(check_msg->sid.sat == 15,
                  "incorrect value for sid.sat, expected 15, is %d",
                  check_msg->sid.sat);
    ck_assert_msg(check_msg->sync_flags == 1,
                  "incorrect value for sync_flags, expected 1, is %d",
                  check_msg->sync_flags);
    ck_assert_msg(check_msg->tot.tow == 0,
                  "incorrect value for tot.tow, expected 0, is %d",
                  check_msg->tot.tow);
    ck_assert_msg(check_msg->tot.wn == 0,
                  "incorrect value for tot.wn, expected 0, is %d",
                  check_msg->tot.wn);
    ck_assert_msg(check_msg->tow_flags == 0,
                  "incorrect value for tow_flags, expected 0, is %d",
                  check_msg->tow_flags);
    ck_assert_msg(check_msg->track_flags == 11,
                  "incorrect value for track_flags, expected 11, is %d",
                  check_msg->track_flags);
    ck_assert_msg(check_msg->uptime == 3,
                  "incorrect value for uptime, expected 3, is %d",
                  check_msg->uptime);
  }
}
END_TEST

Suite *auto_check_sbp_tracking_50_suite(void) {
  Suite *s =
      suite_create("SBP generated test suite: auto_check_sbp_tracking_50");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_tracking_50");
  tcase_add_test(tc_acq, test_auto_check_sbp_tracking_50);
  suite_add_tcase(s, tc_acq);
  return s;
}