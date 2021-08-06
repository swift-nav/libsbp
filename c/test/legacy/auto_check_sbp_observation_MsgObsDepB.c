/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepB.yaml by generate.py.
// Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/observation.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void* context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void* context;
} last_frame;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
static u8 dummy_buff[1024];
static void* last_io_context;

static int DUMMY_MEMORY_FOR_CALLBACKS = 0xdeadbeef;
static int DUMMY_MEMORY_FOR_IO = 0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8* buff, u32 n, void* context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return real_n;
}

static s32 dummy_read(u8* buff, u32 n, void* context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return real_n;
}

static void logging_reset() {
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void* context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void* context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_observation_MsgObsDepB) {
  static sbp_msg_callbacks_node_t n;
  static sbp_msg_callbacks_node_t n2;

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

    sbp_payload_callback_register(&sbp_state, 0x43, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x43, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  67,  0,   246, 215, 103, 120, 46,  39,  0,   251, 6,   32,  180,
        175, 187, 133, 223, 53,  7,   7,   27,  157, 0,   0,   202, 0,   0,
        0,   58,  140, 85,  147, 88,  28,  190, 7,   175, 144, 0,   0,   203,
        0,   0,   0,   220, 140, 248, 138, 208, 172, 77,  7,   135, 151, 0,
        0,   208, 0,   0,   0,   173, 194, 72,  135, 115, 18,  28,  7,   242,
        156, 0,   0,   212, 0,   0,   0,   164, 144, 105, 124, 18,  196, 137,
        6,   120, 168, 0,   0,   217, 0,   0,   0,   30,  232, 228, 139, 210,
        7,   90,  7,   87,  150, 0,   0,   218, 0,   0,   0,   169, 85,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_b_t* test_msg = (msg_obs_dep_b_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 32;
    test_msg->header.t.tow = 2567800;
    test_msg->header.t.wn = 1787;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[0].L.f = 27;
    test_msg->obs[0].L.i = 117913055;
    test_msg->obs[0].P = 2243669940;
    test_msg->obs[0].cn0 = 157;
    test_msg->obs[0].lock = 0;
    test_msg->obs[0].sid.code = 0;
    test_msg->obs[0].sid.reserved = 0;
    test_msg->obs[0].sid.sat = 202;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[1].L.f = 175;
    test_msg->obs[1].L.i = 129899608;
    test_msg->obs[1].P = 2471857210;
    test_msg->obs[1].cn0 = 144;
    test_msg->obs[1].lock = 0;
    test_msg->obs[1].sid.code = 0;
    test_msg->obs[1].sid.reserved = 0;
    test_msg->obs[1].sid.sat = 203;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[2].L.f = 135;
    test_msg->obs[2].L.i = 122531024;
    test_msg->obs[2].P = 2331544796;
    test_msg->obs[2].cn0 = 151;
    test_msg->obs[2].lock = 0;
    test_msg->obs[2].sid.code = 0;
    test_msg->obs[2].sid.reserved = 0;
    test_msg->obs[2].sid.sat = 208;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[3].L.f = 242;
    test_msg->obs[3].L.i = 119280243;
    test_msg->obs[3].P = 2269692589;
    test_msg->obs[3].cn0 = 156;
    test_msg->obs[3].lock = 0;
    test_msg->obs[3].sid.code = 0;
    test_msg->obs[3].sid.reserved = 0;
    test_msg->obs[3].sid.sat = 212;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[4].L.f = 120;
    test_msg->obs[4].L.i = 109691922;
    test_msg->obs[4].P = 2087293092;
    test_msg->obs[4].cn0 = 168;
    test_msg->obs[4].lock = 0;
    test_msg->obs[4].sid.code = 0;
    test_msg->obs[4].sid.reserved = 0;
    test_msg->obs[4].sid.sat = 217;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[5].L.f = 87;
    test_msg->obs[5].L.i = 123340754;
    test_msg->obs[5].P = 2347034654;
    test_msg->obs[5].cn0 = 150;
    test_msg->obs[5].lock = 0;
    test_msg->obs[5].sid.code = 0;
    test_msg->obs[5].sid.reserved = 0;
    test_msg->obs[5].sid.sat = 218;
    sbp_payload_send(&sbp_state, 0x43, 55286, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x43,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_obs_dep_b_t* check_msg = (msg_obs_dep_b_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 32,
                  "incorrect value for header.n_obs, expected 32, is %d",
                  check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 2567800,
                  "incorrect value for header.t.tow, expected 2567800, is %d",
                  check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1787,
                  "incorrect value for header.t.wn, expected 1787, is %d",
                  check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 27,
                  "incorrect value for obs[0].L.f, expected 27, is %d",
                  check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == 117913055,
                  "incorrect value for obs[0].L.i, expected 117913055, is %d",
                  check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 2243669940,
                  "incorrect value for obs[0].P, expected 2243669940, is %d",
                  check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 157,
                  "incorrect value for obs[0].cn0, expected 157, is %d",
                  check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 0,
                  "incorrect value for obs[0].lock, expected 0, is %d",
                  check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].sid.code == 0,
                  "incorrect value for obs[0].sid.code, expected 0, is %d",
                  check_msg->obs[0].sid.code);
    ck_assert_msg(check_msg->obs[0].sid.reserved == 0,
                  "incorrect value for obs[0].sid.reserved, expected 0, is %d",
                  check_msg->obs[0].sid.reserved);
    ck_assert_msg(check_msg->obs[0].sid.sat == 202,
                  "incorrect value for obs[0].sid.sat, expected 202, is %d",
                  check_msg->obs[0].sid.sat);
    ck_assert_msg(check_msg->obs[1].L.f == 175,
                  "incorrect value for obs[1].L.f, expected 175, is %d",
                  check_msg->obs[1].L.f);
    ck_assert_msg(check_msg->obs[1].L.i == 129899608,
                  "incorrect value for obs[1].L.i, expected 129899608, is %d",
                  check_msg->obs[1].L.i);
    ck_assert_msg(check_msg->obs[1].P == 2471857210,
                  "incorrect value for obs[1].P, expected 2471857210, is %d",
                  check_msg->obs[1].P);
    ck_assert_msg(check_msg->obs[1].cn0 == 144,
                  "incorrect value for obs[1].cn0, expected 144, is %d",
                  check_msg->obs[1].cn0);
    ck_assert_msg(check_msg->obs[1].lock == 0,
                  "incorrect value for obs[1].lock, expected 0, is %d",
                  check_msg->obs[1].lock);
    ck_assert_msg(check_msg->obs[1].sid.code == 0,
                  "incorrect value for obs[1].sid.code, expected 0, is %d",
                  check_msg->obs[1].sid.code);
    ck_assert_msg(check_msg->obs[1].sid.reserved == 0,
                  "incorrect value for obs[1].sid.reserved, expected 0, is %d",
                  check_msg->obs[1].sid.reserved);
    ck_assert_msg(check_msg->obs[1].sid.sat == 203,
                  "incorrect value for obs[1].sid.sat, expected 203, is %d",
                  check_msg->obs[1].sid.sat);
    ck_assert_msg(check_msg->obs[2].L.f == 135,
                  "incorrect value for obs[2].L.f, expected 135, is %d",
                  check_msg->obs[2].L.f);
    ck_assert_msg(check_msg->obs[2].L.i == 122531024,
                  "incorrect value for obs[2].L.i, expected 122531024, is %d",
                  check_msg->obs[2].L.i);
    ck_assert_msg(check_msg->obs[2].P == 2331544796,
                  "incorrect value for obs[2].P, expected 2331544796, is %d",
                  check_msg->obs[2].P);
    ck_assert_msg(check_msg->obs[2].cn0 == 151,
                  "incorrect value for obs[2].cn0, expected 151, is %d",
                  check_msg->obs[2].cn0);
    ck_assert_msg(check_msg->obs[2].lock == 0,
                  "incorrect value for obs[2].lock, expected 0, is %d",
                  check_msg->obs[2].lock);
    ck_assert_msg(check_msg->obs[2].sid.code == 0,
                  "incorrect value for obs[2].sid.code, expected 0, is %d",
                  check_msg->obs[2].sid.code);
    ck_assert_msg(check_msg->obs[2].sid.reserved == 0,
                  "incorrect value for obs[2].sid.reserved, expected 0, is %d",
                  check_msg->obs[2].sid.reserved);
    ck_assert_msg(check_msg->obs[2].sid.sat == 208,
                  "incorrect value for obs[2].sid.sat, expected 208, is %d",
                  check_msg->obs[2].sid.sat);
    ck_assert_msg(check_msg->obs[3].L.f == 242,
                  "incorrect value for obs[3].L.f, expected 242, is %d",
                  check_msg->obs[3].L.f);
    ck_assert_msg(check_msg->obs[3].L.i == 119280243,
                  "incorrect value for obs[3].L.i, expected 119280243, is %d",
                  check_msg->obs[3].L.i);
    ck_assert_msg(check_msg->obs[3].P == 2269692589,
                  "incorrect value for obs[3].P, expected 2269692589, is %d",
                  check_msg->obs[3].P);
    ck_assert_msg(check_msg->obs[3].cn0 == 156,
                  "incorrect value for obs[3].cn0, expected 156, is %d",
                  check_msg->obs[3].cn0);
    ck_assert_msg(check_msg->obs[3].lock == 0,
                  "incorrect value for obs[3].lock, expected 0, is %d",
                  check_msg->obs[3].lock);
    ck_assert_msg(check_msg->obs[3].sid.code == 0,
                  "incorrect value for obs[3].sid.code, expected 0, is %d",
                  check_msg->obs[3].sid.code);
    ck_assert_msg(check_msg->obs[3].sid.reserved == 0,
                  "incorrect value for obs[3].sid.reserved, expected 0, is %d",
                  check_msg->obs[3].sid.reserved);
    ck_assert_msg(check_msg->obs[3].sid.sat == 212,
                  "incorrect value for obs[3].sid.sat, expected 212, is %d",
                  check_msg->obs[3].sid.sat);
    ck_assert_msg(check_msg->obs[4].L.f == 120,
                  "incorrect value for obs[4].L.f, expected 120, is %d",
                  check_msg->obs[4].L.f);
    ck_assert_msg(check_msg->obs[4].L.i == 109691922,
                  "incorrect value for obs[4].L.i, expected 109691922, is %d",
                  check_msg->obs[4].L.i);
    ck_assert_msg(check_msg->obs[4].P == 2087293092,
                  "incorrect value for obs[4].P, expected 2087293092, is %d",
                  check_msg->obs[4].P);
    ck_assert_msg(check_msg->obs[4].cn0 == 168,
                  "incorrect value for obs[4].cn0, expected 168, is %d",
                  check_msg->obs[4].cn0);
    ck_assert_msg(check_msg->obs[4].lock == 0,
                  "incorrect value for obs[4].lock, expected 0, is %d",
                  check_msg->obs[4].lock);
    ck_assert_msg(check_msg->obs[4].sid.code == 0,
                  "incorrect value for obs[4].sid.code, expected 0, is %d",
                  check_msg->obs[4].sid.code);
    ck_assert_msg(check_msg->obs[4].sid.reserved == 0,
                  "incorrect value for obs[4].sid.reserved, expected 0, is %d",
                  check_msg->obs[4].sid.reserved);
    ck_assert_msg(check_msg->obs[4].sid.sat == 217,
                  "incorrect value for obs[4].sid.sat, expected 217, is %d",
                  check_msg->obs[4].sid.sat);
    ck_assert_msg(check_msg->obs[5].L.f == 87,
                  "incorrect value for obs[5].L.f, expected 87, is %d",
                  check_msg->obs[5].L.f);
    ck_assert_msg(check_msg->obs[5].L.i == 123340754,
                  "incorrect value for obs[5].L.i, expected 123340754, is %d",
                  check_msg->obs[5].L.i);
    ck_assert_msg(check_msg->obs[5].P == 2347034654,
                  "incorrect value for obs[5].P, expected 2347034654, is %d",
                  check_msg->obs[5].P);
    ck_assert_msg(check_msg->obs[5].cn0 == 150,
                  "incorrect value for obs[5].cn0, expected 150, is %d",
                  check_msg->obs[5].cn0);
    ck_assert_msg(check_msg->obs[5].lock == 0,
                  "incorrect value for obs[5].lock, expected 0, is %d",
                  check_msg->obs[5].lock);
    ck_assert_msg(check_msg->obs[5].sid.code == 0,
                  "incorrect value for obs[5].sid.code, expected 0, is %d",
                  check_msg->obs[5].sid.code);
    ck_assert_msg(check_msg->obs[5].sid.reserved == 0,
                  "incorrect value for obs[5].sid.reserved, expected 0, is %d",
                  check_msg->obs[5].sid.reserved);
    ck_assert_msg(check_msg->obs[5].sid.sat == 218,
                  "incorrect value for obs[5].sid.sat, expected 218, is %d",
                  check_msg->obs[5].sid.sat);
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

    sbp_payload_callback_register(&sbp_state, 0x43, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x43, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 67,  0,   246, 215, 55,  120, 46,  39,  0,   251, 6,   33,
        68, 199, 101, 136, 133, 247, 42,  7,   219, 154, 0,   0,   220,
        0,  0,   0,   219, 14,  123, 133, 96,  215, 3,   7,   235, 156,
        0,  0,   222, 0,   0,   0,   87,  166, 81,  122, 5,   173, 109,
        6,  174, 170, 0,   0,   225, 0,   0,   0,   11,  233,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_b_t* test_msg = (msg_obs_dep_b_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 33;
    test_msg->header.t.tow = 2567800;
    test_msg->header.t.wn = 1787;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[0].L.f = 219;
    test_msg->obs[0].L.i = 120256389;
    test_msg->obs[0].P = 2288371524;
    test_msg->obs[0].cn0 = 154;
    test_msg->obs[0].lock = 0;
    test_msg->obs[0].sid.code = 0;
    test_msg->obs[0].sid.reserved = 0;
    test_msg->obs[0].sid.sat = 220;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[1].L.f = 235;
    test_msg->obs[1].L.i = 117692256;
    test_msg->obs[1].P = 2239434459;
    test_msg->obs[1].cn0 = 156;
    test_msg->obs[1].lock = 0;
    test_msg->obs[1].sid.code = 0;
    test_msg->obs[1].sid.reserved = 0;
    test_msg->obs[1].sid.sat = 222;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[2].L.f = 174;
    test_msg->obs[2].L.i = 107851013;
    test_msg->obs[2].P = 2052171351;
    test_msg->obs[2].cn0 = 170;
    test_msg->obs[2].lock = 0;
    test_msg->obs[2].sid.code = 0;
    test_msg->obs[2].sid.reserved = 0;
    test_msg->obs[2].sid.sat = 225;
    sbp_payload_send(&sbp_state, 0x43, 55286, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x43,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_obs_dep_b_t* check_msg = (msg_obs_dep_b_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 33,
                  "incorrect value for header.n_obs, expected 33, is %d",
                  check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 2567800,
                  "incorrect value for header.t.tow, expected 2567800, is %d",
                  check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1787,
                  "incorrect value for header.t.wn, expected 1787, is %d",
                  check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 219,
                  "incorrect value for obs[0].L.f, expected 219, is %d",
                  check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == 120256389,
                  "incorrect value for obs[0].L.i, expected 120256389, is %d",
                  check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 2288371524,
                  "incorrect value for obs[0].P, expected 2288371524, is %d",
                  check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 154,
                  "incorrect value for obs[0].cn0, expected 154, is %d",
                  check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 0,
                  "incorrect value for obs[0].lock, expected 0, is %d",
                  check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].sid.code == 0,
                  "incorrect value for obs[0].sid.code, expected 0, is %d",
                  check_msg->obs[0].sid.code);
    ck_assert_msg(check_msg->obs[0].sid.reserved == 0,
                  "incorrect value for obs[0].sid.reserved, expected 0, is %d",
                  check_msg->obs[0].sid.reserved);
    ck_assert_msg(check_msg->obs[0].sid.sat == 220,
                  "incorrect value for obs[0].sid.sat, expected 220, is %d",
                  check_msg->obs[0].sid.sat);
    ck_assert_msg(check_msg->obs[1].L.f == 235,
                  "incorrect value for obs[1].L.f, expected 235, is %d",
                  check_msg->obs[1].L.f);
    ck_assert_msg(check_msg->obs[1].L.i == 117692256,
                  "incorrect value for obs[1].L.i, expected 117692256, is %d",
                  check_msg->obs[1].L.i);
    ck_assert_msg(check_msg->obs[1].P == 2239434459,
                  "incorrect value for obs[1].P, expected 2239434459, is %d",
                  check_msg->obs[1].P);
    ck_assert_msg(check_msg->obs[1].cn0 == 156,
                  "incorrect value for obs[1].cn0, expected 156, is %d",
                  check_msg->obs[1].cn0);
    ck_assert_msg(check_msg->obs[1].lock == 0,
                  "incorrect value for obs[1].lock, expected 0, is %d",
                  check_msg->obs[1].lock);
    ck_assert_msg(check_msg->obs[1].sid.code == 0,
                  "incorrect value for obs[1].sid.code, expected 0, is %d",
                  check_msg->obs[1].sid.code);
    ck_assert_msg(check_msg->obs[1].sid.reserved == 0,
                  "incorrect value for obs[1].sid.reserved, expected 0, is %d",
                  check_msg->obs[1].sid.reserved);
    ck_assert_msg(check_msg->obs[1].sid.sat == 222,
                  "incorrect value for obs[1].sid.sat, expected 222, is %d",
                  check_msg->obs[1].sid.sat);
    ck_assert_msg(check_msg->obs[2].L.f == 174,
                  "incorrect value for obs[2].L.f, expected 174, is %d",
                  check_msg->obs[2].L.f);
    ck_assert_msg(check_msg->obs[2].L.i == 107851013,
                  "incorrect value for obs[2].L.i, expected 107851013, is %d",
                  check_msg->obs[2].L.i);
    ck_assert_msg(check_msg->obs[2].P == 2052171351,
                  "incorrect value for obs[2].P, expected 2052171351, is %d",
                  check_msg->obs[2].P);
    ck_assert_msg(check_msg->obs[2].cn0 == 170,
                  "incorrect value for obs[2].cn0, expected 170, is %d",
                  check_msg->obs[2].cn0);
    ck_assert_msg(check_msg->obs[2].lock == 0,
                  "incorrect value for obs[2].lock, expected 0, is %d",
                  check_msg->obs[2].lock);
    ck_assert_msg(check_msg->obs[2].sid.code == 0,
                  "incorrect value for obs[2].sid.code, expected 0, is %d",
                  check_msg->obs[2].sid.code);
    ck_assert_msg(check_msg->obs[2].sid.reserved == 0,
                  "incorrect value for obs[2].sid.reserved, expected 0, is %d",
                  check_msg->obs[2].sid.reserved);
    ck_assert_msg(check_msg->obs[2].sid.sat == 225,
                  "incorrect value for obs[2].sid.sat, expected 225, is %d",
                  check_msg->obs[2].sid.sat);
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

    sbp_payload_callback_register(&sbp_state, 0x43, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x43, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  67,  0,   246, 215, 103, 64,  47,  39,  0,   251, 6,   32,  100,
        132, 187, 133, 236, 51,  7,   7,   94,  156, 0,   0,   202, 0,   0,
        0,   97,  184, 85,  147, 178, 30,  190, 7,   40,  140, 0,   0,   203,
        0,   0,   0,   135, 111, 248, 138, 90,  171, 77,  7,   2,   150, 0,
        0,   208, 0,   0,   0,   180, 238, 72,  135, 190, 20,  28,  7,   241,
        155, 0,   0,   212, 0,   0,   0,   15,  153, 105, 124, 92,  196, 137,
        6,   153, 168, 0,   0,   217, 0,   0,   0,   49,  185, 228, 139, 144,
        5,   90,  7,   41,  150, 0,   0,   218, 0,   0,   0,   241, 98,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_b_t* test_msg = (msg_obs_dep_b_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 32;
    test_msg->header.t.tow = 2568000;
    test_msg->header.t.wn = 1787;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[0].L.f = 94;
    test_msg->obs[0].L.i = 117912556;
    test_msg->obs[0].P = 2243658852;
    test_msg->obs[0].cn0 = 156;
    test_msg->obs[0].lock = 0;
    test_msg->obs[0].sid.code = 0;
    test_msg->obs[0].sid.reserved = 0;
    test_msg->obs[0].sid.sat = 202;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[1].L.f = 40;
    test_msg->obs[1].L.i = 129900210;
    test_msg->obs[1].P = 2471868513;
    test_msg->obs[1].cn0 = 140;
    test_msg->obs[1].lock = 0;
    test_msg->obs[1].sid.code = 0;
    test_msg->obs[1].sid.reserved = 0;
    test_msg->obs[1].sid.sat = 203;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[2].L.f = 2;
    test_msg->obs[2].L.i = 122530650;
    test_msg->obs[2].P = 2331537287;
    test_msg->obs[2].cn0 = 150;
    test_msg->obs[2].lock = 0;
    test_msg->obs[2].sid.code = 0;
    test_msg->obs[2].sid.reserved = 0;
    test_msg->obs[2].sid.sat = 208;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[3].L.f = 241;
    test_msg->obs[3].L.i = 119280830;
    test_msg->obs[3].P = 2269703860;
    test_msg->obs[3].cn0 = 155;
    test_msg->obs[3].lock = 0;
    test_msg->obs[3].sid.code = 0;
    test_msg->obs[3].sid.reserved = 0;
    test_msg->obs[3].sid.sat = 212;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[4].L.f = 153;
    test_msg->obs[4].L.i = 109691996;
    test_msg->obs[4].P = 2087295247;
    test_msg->obs[4].cn0 = 168;
    test_msg->obs[4].lock = 0;
    test_msg->obs[4].sid.code = 0;
    test_msg->obs[4].sid.reserved = 0;
    test_msg->obs[4].sid.sat = 217;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[5].L.f = 41;
    test_msg->obs[5].L.i = 123340176;
    test_msg->obs[5].P = 2347022641;
    test_msg->obs[5].cn0 = 150;
    test_msg->obs[5].lock = 0;
    test_msg->obs[5].sid.code = 0;
    test_msg->obs[5].sid.reserved = 0;
    test_msg->obs[5].sid.sat = 218;
    sbp_payload_send(&sbp_state, 0x43, 55286, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x43,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_obs_dep_b_t* check_msg = (msg_obs_dep_b_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 32,
                  "incorrect value for header.n_obs, expected 32, is %d",
                  check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 2568000,
                  "incorrect value for header.t.tow, expected 2568000, is %d",
                  check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1787,
                  "incorrect value for header.t.wn, expected 1787, is %d",
                  check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 94,
                  "incorrect value for obs[0].L.f, expected 94, is %d",
                  check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == 117912556,
                  "incorrect value for obs[0].L.i, expected 117912556, is %d",
                  check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 2243658852,
                  "incorrect value for obs[0].P, expected 2243658852, is %d",
                  check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 156,
                  "incorrect value for obs[0].cn0, expected 156, is %d",
                  check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 0,
                  "incorrect value for obs[0].lock, expected 0, is %d",
                  check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].sid.code == 0,
                  "incorrect value for obs[0].sid.code, expected 0, is %d",
                  check_msg->obs[0].sid.code);
    ck_assert_msg(check_msg->obs[0].sid.reserved == 0,
                  "incorrect value for obs[0].sid.reserved, expected 0, is %d",
                  check_msg->obs[0].sid.reserved);
    ck_assert_msg(check_msg->obs[0].sid.sat == 202,
                  "incorrect value for obs[0].sid.sat, expected 202, is %d",
                  check_msg->obs[0].sid.sat);
    ck_assert_msg(check_msg->obs[1].L.f == 40,
                  "incorrect value for obs[1].L.f, expected 40, is %d",
                  check_msg->obs[1].L.f);
    ck_assert_msg(check_msg->obs[1].L.i == 129900210,
                  "incorrect value for obs[1].L.i, expected 129900210, is %d",
                  check_msg->obs[1].L.i);
    ck_assert_msg(check_msg->obs[1].P == 2471868513,
                  "incorrect value for obs[1].P, expected 2471868513, is %d",
                  check_msg->obs[1].P);
    ck_assert_msg(check_msg->obs[1].cn0 == 140,
                  "incorrect value for obs[1].cn0, expected 140, is %d",
                  check_msg->obs[1].cn0);
    ck_assert_msg(check_msg->obs[1].lock == 0,
                  "incorrect value for obs[1].lock, expected 0, is %d",
                  check_msg->obs[1].lock);
    ck_assert_msg(check_msg->obs[1].sid.code == 0,
                  "incorrect value for obs[1].sid.code, expected 0, is %d",
                  check_msg->obs[1].sid.code);
    ck_assert_msg(check_msg->obs[1].sid.reserved == 0,
                  "incorrect value for obs[1].sid.reserved, expected 0, is %d",
                  check_msg->obs[1].sid.reserved);
    ck_assert_msg(check_msg->obs[1].sid.sat == 203,
                  "incorrect value for obs[1].sid.sat, expected 203, is %d",
                  check_msg->obs[1].sid.sat);
    ck_assert_msg(check_msg->obs[2].L.f == 2,
                  "incorrect value for obs[2].L.f, expected 2, is %d",
                  check_msg->obs[2].L.f);
    ck_assert_msg(check_msg->obs[2].L.i == 122530650,
                  "incorrect value for obs[2].L.i, expected 122530650, is %d",
                  check_msg->obs[2].L.i);
    ck_assert_msg(check_msg->obs[2].P == 2331537287,
                  "incorrect value for obs[2].P, expected 2331537287, is %d",
                  check_msg->obs[2].P);
    ck_assert_msg(check_msg->obs[2].cn0 == 150,
                  "incorrect value for obs[2].cn0, expected 150, is %d",
                  check_msg->obs[2].cn0);
    ck_assert_msg(check_msg->obs[2].lock == 0,
                  "incorrect value for obs[2].lock, expected 0, is %d",
                  check_msg->obs[2].lock);
    ck_assert_msg(check_msg->obs[2].sid.code == 0,
                  "incorrect value for obs[2].sid.code, expected 0, is %d",
                  check_msg->obs[2].sid.code);
    ck_assert_msg(check_msg->obs[2].sid.reserved == 0,
                  "incorrect value for obs[2].sid.reserved, expected 0, is %d",
                  check_msg->obs[2].sid.reserved);
    ck_assert_msg(check_msg->obs[2].sid.sat == 208,
                  "incorrect value for obs[2].sid.sat, expected 208, is %d",
                  check_msg->obs[2].sid.sat);
    ck_assert_msg(check_msg->obs[3].L.f == 241,
                  "incorrect value for obs[3].L.f, expected 241, is %d",
                  check_msg->obs[3].L.f);
    ck_assert_msg(check_msg->obs[3].L.i == 119280830,
                  "incorrect value for obs[3].L.i, expected 119280830, is %d",
                  check_msg->obs[3].L.i);
    ck_assert_msg(check_msg->obs[3].P == 2269703860,
                  "incorrect value for obs[3].P, expected 2269703860, is %d",
                  check_msg->obs[3].P);
    ck_assert_msg(check_msg->obs[3].cn0 == 155,
                  "incorrect value for obs[3].cn0, expected 155, is %d",
                  check_msg->obs[3].cn0);
    ck_assert_msg(check_msg->obs[3].lock == 0,
                  "incorrect value for obs[3].lock, expected 0, is %d",
                  check_msg->obs[3].lock);
    ck_assert_msg(check_msg->obs[3].sid.code == 0,
                  "incorrect value for obs[3].sid.code, expected 0, is %d",
                  check_msg->obs[3].sid.code);
    ck_assert_msg(check_msg->obs[3].sid.reserved == 0,
                  "incorrect value for obs[3].sid.reserved, expected 0, is %d",
                  check_msg->obs[3].sid.reserved);
    ck_assert_msg(check_msg->obs[3].sid.sat == 212,
                  "incorrect value for obs[3].sid.sat, expected 212, is %d",
                  check_msg->obs[3].sid.sat);
    ck_assert_msg(check_msg->obs[4].L.f == 153,
                  "incorrect value for obs[4].L.f, expected 153, is %d",
                  check_msg->obs[4].L.f);
    ck_assert_msg(check_msg->obs[4].L.i == 109691996,
                  "incorrect value for obs[4].L.i, expected 109691996, is %d",
                  check_msg->obs[4].L.i);
    ck_assert_msg(check_msg->obs[4].P == 2087295247,
                  "incorrect value for obs[4].P, expected 2087295247, is %d",
                  check_msg->obs[4].P);
    ck_assert_msg(check_msg->obs[4].cn0 == 168,
                  "incorrect value for obs[4].cn0, expected 168, is %d",
                  check_msg->obs[4].cn0);
    ck_assert_msg(check_msg->obs[4].lock == 0,
                  "incorrect value for obs[4].lock, expected 0, is %d",
                  check_msg->obs[4].lock);
    ck_assert_msg(check_msg->obs[4].sid.code == 0,
                  "incorrect value for obs[4].sid.code, expected 0, is %d",
                  check_msg->obs[4].sid.code);
    ck_assert_msg(check_msg->obs[4].sid.reserved == 0,
                  "incorrect value for obs[4].sid.reserved, expected 0, is %d",
                  check_msg->obs[4].sid.reserved);
    ck_assert_msg(check_msg->obs[4].sid.sat == 217,
                  "incorrect value for obs[4].sid.sat, expected 217, is %d",
                  check_msg->obs[4].sid.sat);
    ck_assert_msg(check_msg->obs[5].L.f == 41,
                  "incorrect value for obs[5].L.f, expected 41, is %d",
                  check_msg->obs[5].L.f);
    ck_assert_msg(check_msg->obs[5].L.i == 123340176,
                  "incorrect value for obs[5].L.i, expected 123340176, is %d",
                  check_msg->obs[5].L.i);
    ck_assert_msg(check_msg->obs[5].P == 2347022641,
                  "incorrect value for obs[5].P, expected 2347022641, is %d",
                  check_msg->obs[5].P);
    ck_assert_msg(check_msg->obs[5].cn0 == 150,
                  "incorrect value for obs[5].cn0, expected 150, is %d",
                  check_msg->obs[5].cn0);
    ck_assert_msg(check_msg->obs[5].lock == 0,
                  "incorrect value for obs[5].lock, expected 0, is %d",
                  check_msg->obs[5].lock);
    ck_assert_msg(check_msg->obs[5].sid.code == 0,
                  "incorrect value for obs[5].sid.code, expected 0, is %d",
                  check_msg->obs[5].sid.code);
    ck_assert_msg(check_msg->obs[5].sid.reserved == 0,
                  "incorrect value for obs[5].sid.reserved, expected 0, is %d",
                  check_msg->obs[5].sid.reserved);
    ck_assert_msg(check_msg->obs[5].sid.sat == 218,
                  "incorrect value for obs[5].sid.sat, expected 218, is %d",
                  check_msg->obs[5].sid.sat);
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

    sbp_payload_callback_register(&sbp_state, 0x43, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x43, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  67, 0,   246, 215, 55, 64,  47, 39, 0,   251, 6, 33, 234, 148, 101,
        136, 15, 245, 42,  7,   20, 154, 0,  0,  220, 0,   0, 0,  208, 247, 122,
        133, 16, 214, 3,   7,   38, 156, 0,  0,  222, 0,   0, 0,  15,  150, 81,
        122, 22, 172, 109, 6,   7,  172, 0,  0,  225, 0,   0, 0,  201, 13,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_b_t* test_msg = (msg_obs_dep_b_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 33;
    test_msg->header.t.tow = 2568000;
    test_msg->header.t.wn = 1787;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[0].L.f = 20;
    test_msg->obs[0].L.i = 120255759;
    test_msg->obs[0].P = 2288358634;
    test_msg->obs[0].cn0 = 154;
    test_msg->obs[0].lock = 0;
    test_msg->obs[0].sid.code = 0;
    test_msg->obs[0].sid.reserved = 0;
    test_msg->obs[0].sid.sat = 220;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[1].L.f = 38;
    test_msg->obs[1].L.i = 117691920;
    test_msg->obs[1].P = 2239428560;
    test_msg->obs[1].cn0 = 156;
    test_msg->obs[1].lock = 0;
    test_msg->obs[1].sid.code = 0;
    test_msg->obs[1].sid.reserved = 0;
    test_msg->obs[1].sid.sat = 222;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[2].L.f = 7;
    test_msg->obs[2].L.i = 107850774;
    test_msg->obs[2].P = 2052167183;
    test_msg->obs[2].cn0 = 172;
    test_msg->obs[2].lock = 0;
    test_msg->obs[2].sid.code = 0;
    test_msg->obs[2].sid.reserved = 0;
    test_msg->obs[2].sid.sat = 225;
    sbp_payload_send(&sbp_state, 0x43, 55286, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x43,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_obs_dep_b_t* check_msg = (msg_obs_dep_b_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 33,
                  "incorrect value for header.n_obs, expected 33, is %d",
                  check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 2568000,
                  "incorrect value for header.t.tow, expected 2568000, is %d",
                  check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1787,
                  "incorrect value for header.t.wn, expected 1787, is %d",
                  check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 20,
                  "incorrect value for obs[0].L.f, expected 20, is %d",
                  check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == 120255759,
                  "incorrect value for obs[0].L.i, expected 120255759, is %d",
                  check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 2288358634,
                  "incorrect value for obs[0].P, expected 2288358634, is %d",
                  check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 154,
                  "incorrect value for obs[0].cn0, expected 154, is %d",
                  check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 0,
                  "incorrect value for obs[0].lock, expected 0, is %d",
                  check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].sid.code == 0,
                  "incorrect value for obs[0].sid.code, expected 0, is %d",
                  check_msg->obs[0].sid.code);
    ck_assert_msg(check_msg->obs[0].sid.reserved == 0,
                  "incorrect value for obs[0].sid.reserved, expected 0, is %d",
                  check_msg->obs[0].sid.reserved);
    ck_assert_msg(check_msg->obs[0].sid.sat == 220,
                  "incorrect value for obs[0].sid.sat, expected 220, is %d",
                  check_msg->obs[0].sid.sat);
    ck_assert_msg(check_msg->obs[1].L.f == 38,
                  "incorrect value for obs[1].L.f, expected 38, is %d",
                  check_msg->obs[1].L.f);
    ck_assert_msg(check_msg->obs[1].L.i == 117691920,
                  "incorrect value for obs[1].L.i, expected 117691920, is %d",
                  check_msg->obs[1].L.i);
    ck_assert_msg(check_msg->obs[1].P == 2239428560,
                  "incorrect value for obs[1].P, expected 2239428560, is %d",
                  check_msg->obs[1].P);
    ck_assert_msg(check_msg->obs[1].cn0 == 156,
                  "incorrect value for obs[1].cn0, expected 156, is %d",
                  check_msg->obs[1].cn0);
    ck_assert_msg(check_msg->obs[1].lock == 0,
                  "incorrect value for obs[1].lock, expected 0, is %d",
                  check_msg->obs[1].lock);
    ck_assert_msg(check_msg->obs[1].sid.code == 0,
                  "incorrect value for obs[1].sid.code, expected 0, is %d",
                  check_msg->obs[1].sid.code);
    ck_assert_msg(check_msg->obs[1].sid.reserved == 0,
                  "incorrect value for obs[1].sid.reserved, expected 0, is %d",
                  check_msg->obs[1].sid.reserved);
    ck_assert_msg(check_msg->obs[1].sid.sat == 222,
                  "incorrect value for obs[1].sid.sat, expected 222, is %d",
                  check_msg->obs[1].sid.sat);
    ck_assert_msg(check_msg->obs[2].L.f == 7,
                  "incorrect value for obs[2].L.f, expected 7, is %d",
                  check_msg->obs[2].L.f);
    ck_assert_msg(check_msg->obs[2].L.i == 107850774,
                  "incorrect value for obs[2].L.i, expected 107850774, is %d",
                  check_msg->obs[2].L.i);
    ck_assert_msg(check_msg->obs[2].P == 2052167183,
                  "incorrect value for obs[2].P, expected 2052167183, is %d",
                  check_msg->obs[2].P);
    ck_assert_msg(check_msg->obs[2].cn0 == 172,
                  "incorrect value for obs[2].cn0, expected 172, is %d",
                  check_msg->obs[2].cn0);
    ck_assert_msg(check_msg->obs[2].lock == 0,
                  "incorrect value for obs[2].lock, expected 0, is %d",
                  check_msg->obs[2].lock);
    ck_assert_msg(check_msg->obs[2].sid.code == 0,
                  "incorrect value for obs[2].sid.code, expected 0, is %d",
                  check_msg->obs[2].sid.code);
    ck_assert_msg(check_msg->obs[2].sid.reserved == 0,
                  "incorrect value for obs[2].sid.reserved, expected 0, is %d",
                  check_msg->obs[2].sid.reserved);
    ck_assert_msg(check_msg->obs[2].sid.sat == 225,
                  "incorrect value for obs[2].sid.sat, expected 225, is %d",
                  check_msg->obs[2].sid.sat);
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

    sbp_payload_callback_register(&sbp_state, 0x43, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x43, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  67,  0,   246, 215, 103, 8,   48,  39,  0,   251, 6,   32,  254,
        96,  187, 133, 249, 49,  7,   7,   165, 156, 0,   0,   202, 0,   0,
        0,   113, 229, 85,  147, 11,  33,  190, 7,   106, 143, 0,   0,   203,
        0,   0,   0,   182, 85,  248, 138, 227, 169, 77,  7,   159, 150, 0,
        0,   208, 0,   0,   0,   17,  24,  73,  135, 10,  23,  28,  7,   7,
        156, 0,   0,   212, 0,   0,   0,   108, 155, 105, 124, 166, 196, 137,
        6,   186, 170, 0,   0,   217, 0,   0,   0,   214, 142, 228, 139, 77,
        3,   90,  7,   236, 151, 0,   0,   218, 0,   0,   0,   59,  118,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_obs_dep_b_t* test_msg = (msg_obs_dep_b_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->header.n_obs = 32;
    test_msg->header.t.tow = 2568200;
    test_msg->header.t.wn = 1787;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[0].L.f = 165;
    test_msg->obs[0].L.i = 117912057;
    test_msg->obs[0].P = 2243649790;
    test_msg->obs[0].cn0 = 156;
    test_msg->obs[0].lock = 0;
    test_msg->obs[0].sid.code = 0;
    test_msg->obs[0].sid.reserved = 0;
    test_msg->obs[0].sid.sat = 202;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[1].L.f = 106;
    test_msg->obs[1].L.i = 129900811;
    test_msg->obs[1].P = 2471880049;
    test_msg->obs[1].cn0 = 143;
    test_msg->obs[1].lock = 0;
    test_msg->obs[1].sid.code = 0;
    test_msg->obs[1].sid.reserved = 0;
    test_msg->obs[1].sid.sat = 203;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[2].L.f = 159;
    test_msg->obs[2].L.i = 122530275;
    test_msg->obs[2].P = 2331530678;
    test_msg->obs[2].cn0 = 150;
    test_msg->obs[2].lock = 0;
    test_msg->obs[2].sid.code = 0;
    test_msg->obs[2].sid.reserved = 0;
    test_msg->obs[2].sid.sat = 208;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[3].L.f = 7;
    test_msg->obs[3].L.i = 119281418;
    test_msg->obs[3].P = 2269714449;
    test_msg->obs[3].cn0 = 156;
    test_msg->obs[3].lock = 0;
    test_msg->obs[3].sid.code = 0;
    test_msg->obs[3].sid.reserved = 0;
    test_msg->obs[3].sid.sat = 212;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[4].L.f = 186;
    test_msg->obs[4].L.i = 109692070;
    test_msg->obs[4].P = 2087295852;
    test_msg->obs[4].cn0 = 170;
    test_msg->obs[4].lock = 0;
    test_msg->obs[4].sid.code = 0;
    test_msg->obs[4].sid.reserved = 0;
    test_msg->obs[4].sid.sat = 217;
    if (sizeof(test_msg->obs) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->obs[0]);
    }
    test_msg->obs[5].L.f = 236;
    test_msg->obs[5].L.i = 123339597;
    test_msg->obs[5].P = 2347011798;
    test_msg->obs[5].cn0 = 151;
    test_msg->obs[5].lock = 0;
    test_msg->obs[5].sid.code = 0;
    test_msg->obs[5].sid.reserved = 0;
    test_msg->obs[5].sid.sat = 218;
    sbp_payload_send(&sbp_state, 0x43, 55286, test_msg_len, test_msg_storage,
                     &dummy_write);

    ck_assert_msg(
        test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame "
        "from the spec is badly defined. Check your test spec");

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff");
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 55286,
                  "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
                  "msg_callback: len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
                  "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 55286,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x43,
                  "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
                  "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6,
                         sizeof(encoded_frame) - 8) == 0,
                  "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
                  "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(
        memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
                  "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload
    // starts
    msg_obs_dep_b_t* check_msg = (msg_obs_dep_b_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->header.n_obs == 32,
                  "incorrect value for header.n_obs, expected 32, is %d",
                  check_msg->header.n_obs);
    ck_assert_msg(check_msg->header.t.tow == 2568200,
                  "incorrect value for header.t.tow, expected 2568200, is %d",
                  check_msg->header.t.tow);
    ck_assert_msg(check_msg->header.t.wn == 1787,
                  "incorrect value for header.t.wn, expected 1787, is %d",
                  check_msg->header.t.wn);
    ck_assert_msg(check_msg->obs[0].L.f == 165,
                  "incorrect value for obs[0].L.f, expected 165, is %d",
                  check_msg->obs[0].L.f);
    ck_assert_msg(check_msg->obs[0].L.i == 117912057,
                  "incorrect value for obs[0].L.i, expected 117912057, is %d",
                  check_msg->obs[0].L.i);
    ck_assert_msg(check_msg->obs[0].P == 2243649790,
                  "incorrect value for obs[0].P, expected 2243649790, is %d",
                  check_msg->obs[0].P);
    ck_assert_msg(check_msg->obs[0].cn0 == 156,
                  "incorrect value for obs[0].cn0, expected 156, is %d",
                  check_msg->obs[0].cn0);
    ck_assert_msg(check_msg->obs[0].lock == 0,
                  "incorrect value for obs[0].lock, expected 0, is %d",
                  check_msg->obs[0].lock);
    ck_assert_msg(check_msg->obs[0].sid.code == 0,
                  "incorrect value for obs[0].sid.code, expected 0, is %d",
                  check_msg->obs[0].sid.code);
    ck_assert_msg(check_msg->obs[0].sid.reserved == 0,
                  "incorrect value for obs[0].sid.reserved, expected 0, is %d",
                  check_msg->obs[0].sid.reserved);
    ck_assert_msg(check_msg->obs[0].sid.sat == 202,
                  "incorrect value for obs[0].sid.sat, expected 202, is %d",
                  check_msg->obs[0].sid.sat);
    ck_assert_msg(check_msg->obs[1].L.f == 106,
                  "incorrect value for obs[1].L.f, expected 106, is %d",
                  check_msg->obs[1].L.f);
    ck_assert_msg(check_msg->obs[1].L.i == 129900811,
                  "incorrect value for obs[1].L.i, expected 129900811, is %d",
                  check_msg->obs[1].L.i);
    ck_assert_msg(check_msg->obs[1].P == 2471880049,
                  "incorrect value for obs[1].P, expected 2471880049, is %d",
                  check_msg->obs[1].P);
    ck_assert_msg(check_msg->obs[1].cn0 == 143,
                  "incorrect value for obs[1].cn0, expected 143, is %d",
                  check_msg->obs[1].cn0);
    ck_assert_msg(check_msg->obs[1].lock == 0,
                  "incorrect value for obs[1].lock, expected 0, is %d",
                  check_msg->obs[1].lock);
    ck_assert_msg(check_msg->obs[1].sid.code == 0,
                  "incorrect value for obs[1].sid.code, expected 0, is %d",
                  check_msg->obs[1].sid.code);
    ck_assert_msg(check_msg->obs[1].sid.reserved == 0,
                  "incorrect value for obs[1].sid.reserved, expected 0, is %d",
                  check_msg->obs[1].sid.reserved);
    ck_assert_msg(check_msg->obs[1].sid.sat == 203,
                  "incorrect value for obs[1].sid.sat, expected 203, is %d",
                  check_msg->obs[1].sid.sat);
    ck_assert_msg(check_msg->obs[2].L.f == 159,
                  "incorrect value for obs[2].L.f, expected 159, is %d",
                  check_msg->obs[2].L.f);
    ck_assert_msg(check_msg->obs[2].L.i == 122530275,
                  "incorrect value for obs[2].L.i, expected 122530275, is %d",
                  check_msg->obs[2].L.i);
    ck_assert_msg(check_msg->obs[2].P == 2331530678,
                  "incorrect value for obs[2].P, expected 2331530678, is %d",
                  check_msg->obs[2].P);
    ck_assert_msg(check_msg->obs[2].cn0 == 150,
                  "incorrect value for obs[2].cn0, expected 150, is %d",
                  check_msg->obs[2].cn0);
    ck_assert_msg(check_msg->obs[2].lock == 0,
                  "incorrect value for obs[2].lock, expected 0, is %d",
                  check_msg->obs[2].lock);
    ck_assert_msg(check_msg->obs[2].sid.code == 0,
                  "incorrect value for obs[2].sid.code, expected 0, is %d",
                  check_msg->obs[2].sid.code);
    ck_assert_msg(check_msg->obs[2].sid.reserved == 0,
                  "incorrect value for obs[2].sid.reserved, expected 0, is %d",
                  check_msg->obs[2].sid.reserved);
    ck_assert_msg(check_msg->obs[2].sid.sat == 208,
                  "incorrect value for obs[2].sid.sat, expected 208, is %d",
                  check_msg->obs[2].sid.sat);
    ck_assert_msg(check_msg->obs[3].L.f == 7,
                  "incorrect value for obs[3].L.f, expected 7, is %d",
                  check_msg->obs[3].L.f);
    ck_assert_msg(check_msg->obs[3].L.i == 119281418,
                  "incorrect value for obs[3].L.i, expected 119281418, is %d",
                  check_msg->obs[3].L.i);
    ck_assert_msg(check_msg->obs[3].P == 2269714449,
                  "incorrect value for obs[3].P, expected 2269714449, is %d",
                  check_msg->obs[3].P);
    ck_assert_msg(check_msg->obs[3].cn0 == 156,
                  "incorrect value for obs[3].cn0, expected 156, is %d",
                  check_msg->obs[3].cn0);
    ck_assert_msg(check_msg->obs[3].lock == 0,
                  "incorrect value for obs[3].lock, expected 0, is %d",
                  check_msg->obs[3].lock);
    ck_assert_msg(check_msg->obs[3].sid.code == 0,
                  "incorrect value for obs[3].sid.code, expected 0, is %d",
                  check_msg->obs[3].sid.code);
    ck_assert_msg(check_msg->obs[3].sid.reserved == 0,
                  "incorrect value for obs[3].sid.reserved, expected 0, is %d",
                  check_msg->obs[3].sid.reserved);
    ck_assert_msg(check_msg->obs[3].sid.sat == 212,
                  "incorrect value for obs[3].sid.sat, expected 212, is %d",
                  check_msg->obs[3].sid.sat);
    ck_assert_msg(check_msg->obs[4].L.f == 186,
                  "incorrect value for obs[4].L.f, expected 186, is %d",
                  check_msg->obs[4].L.f);
    ck_assert_msg(check_msg->obs[4].L.i == 109692070,
                  "incorrect value for obs[4].L.i, expected 109692070, is %d",
                  check_msg->obs[4].L.i);
    ck_assert_msg(check_msg->obs[4].P == 2087295852,
                  "incorrect value for obs[4].P, expected 2087295852, is %d",
                  check_msg->obs[4].P);
    ck_assert_msg(check_msg->obs[4].cn0 == 170,
                  "incorrect value for obs[4].cn0, expected 170, is %d",
                  check_msg->obs[4].cn0);
    ck_assert_msg(check_msg->obs[4].lock == 0,
                  "incorrect value for obs[4].lock, expected 0, is %d",
                  check_msg->obs[4].lock);
    ck_assert_msg(check_msg->obs[4].sid.code == 0,
                  "incorrect value for obs[4].sid.code, expected 0, is %d",
                  check_msg->obs[4].sid.code);
    ck_assert_msg(check_msg->obs[4].sid.reserved == 0,
                  "incorrect value for obs[4].sid.reserved, expected 0, is %d",
                  check_msg->obs[4].sid.reserved);
    ck_assert_msg(check_msg->obs[4].sid.sat == 217,
                  "incorrect value for obs[4].sid.sat, expected 217, is %d",
                  check_msg->obs[4].sid.sat);
    ck_assert_msg(check_msg->obs[5].L.f == 236,
                  "incorrect value for obs[5].L.f, expected 236, is %d",
                  check_msg->obs[5].L.f);
    ck_assert_msg(check_msg->obs[5].L.i == 123339597,
                  "incorrect value for obs[5].L.i, expected 123339597, is %d",
                  check_msg->obs[5].L.i);
    ck_assert_msg(check_msg->obs[5].P == 2347011798,
                  "incorrect value for obs[5].P, expected 2347011798, is %d",
                  check_msg->obs[5].P);
    ck_assert_msg(check_msg->obs[5].cn0 == 151,
                  "incorrect value for obs[5].cn0, expected 151, is %d",
                  check_msg->obs[5].cn0);
    ck_assert_msg(check_msg->obs[5].lock == 0,
                  "incorrect value for obs[5].lock, expected 0, is %d",
                  check_msg->obs[5].lock);
    ck_assert_msg(check_msg->obs[5].sid.code == 0,
                  "incorrect value for obs[5].sid.code, expected 0, is %d",
                  check_msg->obs[5].sid.code);
    ck_assert_msg(check_msg->obs[5].sid.reserved == 0,
                  "incorrect value for obs[5].sid.reserved, expected 0, is %d",
                  check_msg->obs[5].sid.reserved);
    ck_assert_msg(check_msg->obs[5].sid.sat == 218,
                  "incorrect value for obs[5].sid.sat, expected 218, is %d",
                  check_msg->obs[5].sid.sat);
  }
}
END_TEST

Suite* legacy_auto_check_sbp_observation_MsgObsDepB_suite(void) {
  Suite* s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_observation_MsgObsDepB");
  TCase* tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_observation_MsgObsDepB");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_observation_MsgObsDepB);
  suite_add_tcase(s, tc_acq);
  return s;
}