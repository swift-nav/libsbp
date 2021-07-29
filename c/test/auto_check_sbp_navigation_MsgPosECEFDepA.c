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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFDepA.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <navigation.h>
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

START_TEST(test_auto_check_sbp_navigation_MsgPosECEFDepA) {
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 0,   2,   246, 215, 32, 20,  46,  39,  0,  195, 122, 175, 75,
        33, 154, 68,  193, 164, 14, 230, 176, 231, 95, 80,  193, 78,  220,
        22, 253, 254, 105, 77,  65, 0,   0,   9,   0,  13,  86,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 9;
    test_msg->tow = 2567700;
    test_msg->x = -2700354.5912927105;
    test_msg->y = -4292510.764041577;
    test_msg->z = 3855357.977260149;
    sbp_send_message(&sbp_state, 0x200, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 9,
                  "incorrect value for n_sats, expected 9, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2567700,
                  "incorrect value for tow, expected 2567700, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2700354.59129 * 100) < 0.05,
                  "incorrect value for x, expected -2700354.59129, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4292510.76404 * 100) < 0.05,
                  "incorrect value for y, expected -4292510.76404, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3855357.97726 * 100) < 0.05,
                  "incorrect value for z, expected 3855357.97726, is %f",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 0,   2,   246, 215, 32,  20,  46,  39,  0,  212, 196, 12, 42,
        34, 154, 68,  193, 9,   113, 112, 123, 231, 95, 80,  193, 54, 97,
        38, 192, 254, 105, 77,  65,  0,   0,   9,   1,  75,  143,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 1;
    test_msg->n_sats = 9;
    test_msg->tow = 2567700;
    test_msg->x = -2700356.3285146747;
    test_msg->y = -4292509.928737887;
    test_msg->z = 3855357.5011712564;
    sbp_send_message(&sbp_state, 0x200, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 1,
                  "incorrect value for flags, expected 1, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 9,
                  "incorrect value for n_sats, expected 9, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2567700,
                  "incorrect value for tow, expected 2567700, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2700356.32851 * 100) < 0.05,
                  "incorrect value for x, expected -2700356.32851, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4292509.92874 * 100) < 0.05,
                  "incorrect value for y, expected -4292509.92874, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3855357.50117 * 100) < 0.05,
                  "incorrect value for z, expected 3855357.50117, is %f",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 0,   2,   246, 215, 32, 120, 46,  39,  0,  112, 97,  39, 190,
        34, 154, 68,  193, 230, 43, 119, 115, 231, 95, 80,  193, 50, 199,
        76, 66,  254, 105, 77,  65, 0,   0,   9,   0,  204, 113,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 9;
    test_msg->tow = 2567800;
    test_msg->x = -2700357.485576801;
    test_msg->y = -4292509.80414865;
    test_msg->z = 3855356.517968082;
    sbp_send_message(&sbp_state, 0x200, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 9,
                  "incorrect value for n_sats, expected 9, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2567800,
                  "incorrect value for tow, expected 2567800, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2700357.48558 * 100) < 0.05,
                  "incorrect value for x, expected -2700357.48558, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4292509.80415 * 100) < 0.05,
                  "incorrect value for y, expected -4292509.80415, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3855356.51797 * 100) < 0.05,
                  "incorrect value for z, expected 3855356.51797, is %f",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  0,   2,   246, 215, 32,  120, 46,  39,  0,  194, 82,  121, 4,
        34,  154, 68,  193, 223, 186, 1,   140, 231, 95, 80,  193, 176, 152,
        147, 181, 254, 105, 77,  65,  0,   0,   9,   1,  97,  71,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 1;
    test_msg->n_sats = 9;
    test_msg->tow = 2567800;
    test_msg->x = -2700356.0349524925;
    test_msg->y = -4292510.187605589;
    test_msg->z = 3855357.4185667858;
    sbp_send_message(&sbp_state, 0x200, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 1,
                  "incorrect value for flags, expected 1, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 9,
                  "incorrect value for n_sats, expected 9, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2567800,
                  "incorrect value for tow, expected 2567800, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2700356.03495 * 100) < 0.05,
                  "incorrect value for x, expected -2700356.03495, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4292510.18761 * 100) < 0.05,
                  "incorrect value for y, expected -4292510.18761, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3855357.41857 * 100) < 0.05,
                  "incorrect value for z, expected 3855357.41857, is %f",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  0,   2,   246, 215, 32,  220, 46,  39,  0,  216, 41,  227, 254,
        33,  154, 68,  193, 9,   151, 154, 124, 231, 95, 80,  193, 1,   183,
        214, 139, 255, 105, 77,  65,  0,   0,   9,   0,  7,   98,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 9;
    test_msg->tow = 2567900;
    test_msg->x = -2700355.9913074784;
    test_msg->y = -4292509.946935424;
    test_msg->z = 3855359.0924900775;
    sbp_send_message(&sbp_state, 0x200, 55286, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 9,
                  "incorrect value for n_sats, expected 9, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 2567900,
                  "incorrect value for tow, expected 2567900, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2700355.99131 * 100) < 0.05,
                  "incorrect value for x, expected -2700355.99131, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4292509.94694 * 100) < 0.05,
                  "incorrect value for y, expected -4292509.94694, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3855359.09249 * 100) < 0.05,
                  "incorrect value for z, expected 3855359.09249, is %f",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,   32,  212, 157, 67, 24, 153, 222, 105, 1,
        252, 161, 68, 193, 254, 247, 52,  112, 74, 67, 80,  193, 164, 207,
        47,  146, 44, 163, 77,  65,  0,   0,   8,  0,  145, 4,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 8;
    test_msg->tow = 407084500;
    test_msg->x = -2704376.0110433814;
    test_msg->y = -4263209.753232954;
    test_msg->z = 3884633.142084079;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8,
                  "incorrect value for n_sats, expected 8, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084500,
                  "incorrect value for tow, expected 407084500, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2704376.01104 * 100) < 0.05,
                  "incorrect value for x, expected -2704376.01104, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4263209.75323 * 100) < 0.05,
                  "incorrect value for y, expected -4263209.75323, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3884633.14208 * 100) < 0.05,
                  "incorrect value for z, expected 3884633.14208, is %f",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,  32,  56, 158, 67, 24, 215, 184, 223, 246,
        251, 161, 68, 193, 36, 126, 17, 39,  74, 67, 80,  193, 19,  179,
        70,  80,  44, 163, 77, 65,  0,  0,   8,  0,  245, 66,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 8;
    test_msg->tow = 407084600;
    test_msg->x = -2704375.9287024545;
    test_msg->y = -4263208.610442672;
    test_msg->z = 3884632.627157578;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8,
                  "incorrect value for n_sats, expected 8, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084600,
                  "incorrect value for tow, expected 407084600, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2704375.9287 * 100) < 0.05,
                  "incorrect value for x, expected -2704375.9287, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4263208.61044 * 100) < 0.05,
                  "incorrect value for y, expected -4263208.61044, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3884632.62716 * 100) < 0.05,
                  "incorrect value for z, expected 3884632.62716, is %f",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,   32,  156, 158, 67, 24, 73, 74,  214, 148,
        251, 161, 68, 193, 213, 151, 184, 215, 73, 67, 80, 193, 110, 99,
        38,  164, 43, 163, 77,  65,  0,   0,   8,  0,  5,  223,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 8;
    test_msg->tow = 407084700;
    test_msg->x = -2704375.162789617;
    test_msg->y = -4263207.370641668;
    test_msg->z = 3884631.282421521;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8,
                  "incorrect value for n_sats, expected 8, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084700,
                  "incorrect value for tow, expected 407084700, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2704375.16279 * 100) < 0.05,
                  "incorrect value for x, expected -2704375.16279, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4263207.37064 * 100) < 0.05,
                  "incorrect value for y, expected -4263207.37064, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3884631.28242 * 100) < 0.05,
                  "incorrect value for z, expected 3884631.28242, is %f",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,   32,  0,   159, 67, 24, 177, 111, 112, 45,
        252, 161, 68, 193, 213, 168, 198, 253, 73, 67, 80,  193, 245, 12,
        228, 12,  44, 163, 77,  65,  0,   0,   8,  0,  143, 212,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 8;
    test_msg->tow = 407084800;
    test_msg->x = -2704376.3549937834;
    test_msg->y = -4263207.965250214;
    test_msg->z = 3884632.1007095524;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8,
                  "incorrect value for n_sats, expected 8, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084800,
                  "incorrect value for tow, expected 407084800, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2704376.35499 * 100) < 0.05,
                  "incorrect value for x, expected -2704376.35499, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4263207.96525 * 100) < 0.05,
                  "incorrect value for y, expected -4263207.96525, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3884632.10071 * 100) < 0.05,
                  "incorrect value for z, expected 3884632.10071, is %f",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,   32,  100, 159, 67, 24, 67, 231, 72,  165,
        251, 161, 68, 193, 150, 210, 36,  212, 73, 67, 80, 193, 234, 33,
        25,  189, 43, 163, 77,  65,  0,   0,   8,  0,  70, 221,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 8;
    test_msg->tow = 407084900;
    test_msg->x = -2704375.291287334;
    test_msg->y = -4263207.314747473;
    test_msg->z = 3884631.4773294823;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 8,
                  "incorrect value for n_sats, expected 8, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407084900,
                  "incorrect value for tow, expected 407084900, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2704375.29129 * 100) < 0.05,
                  "incorrect value for x, expected -2704375.29129, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4263207.31475 * 100) < 0.05,
                  "incorrect value for y, expected -4263207.31475, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3884631.47733 * 100) < 0.05,
                  "incorrect value for z, expected 3884631.47733, is %f",
                  check_msg->z);
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

    sbp_register_callback(&sbp_state, 0x200, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0x200, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  0,   2,  195, 4,   32,  46,  162, 68, 24, 224, 72,  131, 215,
        251, 161, 68, 193, 180, 123, 222, 94,  74, 67, 80,  193, 191, 3,
        131, 193, 45, 163, 77,  65,  0,   0,   5,  0,  17,  221,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_pos_ecef_dep_a_t* test_msg = (msg_pos_ecef_dep_a_t*)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->accuracy = 0;
    test_msg->flags = 0;
    test_msg->n_sats = 5;
    test_msg->tow = 407151150;
    test_msg->x = -2704375.68369399;
    test_msg->y = -4263209.482329298;
    test_msg->z = 3884635.5118107493;
    sbp_send_message(&sbp_state, 0x200, 1219, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 1219,
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
    ck_assert_msg(last_frame.sender_id == 1219,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x200,
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
    msg_pos_ecef_dep_a_t* check_msg =
        (msg_pos_ecef_dep_a_t*)((void*)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->accuracy == 0,
                  "incorrect value for accuracy, expected 0, is %d",
                  check_msg->accuracy);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_sats == 5,
                  "incorrect value for n_sats, expected 5, is %d",
                  check_msg->n_sats);
    ck_assert_msg(check_msg->tow == 407151150,
                  "incorrect value for tow, expected 407151150, is %d",
                  check_msg->tow);
    ck_assert_msg((check_msg->x * 100 - -2704375.68369 * 100) < 0.05,
                  "incorrect value for x, expected -2704375.68369, is %f",
                  check_msg->x);
    ck_assert_msg((check_msg->y * 100 - -4263209.48233 * 100) < 0.05,
                  "incorrect value for y, expected -4263209.48233, is %f",
                  check_msg->y);
    ck_assert_msg((check_msg->z * 100 - 3884635.51181 * 100) < 0.05,
                  "incorrect value for z, expected 3884635.51181, is %f",
                  check_msg->z);
  }
}
END_TEST

Suite* auto_check_sbp_navigation_MsgPosECEFDepA_suite(void) {
  Suite* s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgPosECEFDepA");
  TCase* tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgPosECEFDepA");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgPosECEFDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}