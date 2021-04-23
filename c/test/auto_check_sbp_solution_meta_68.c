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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/solution_meta/test_MsgSolnMeta.yaml by generate.py. Do not modify by hand!

#include <check.h>
#include <stdio.h> // for debugging
#include <stdlib.h> // for malloc
#include <libsbp/sbp.h>
#include <libsbp/solution_meta.h>

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u8 len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  void *context;
} last_msg;

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  u16 msg_type;
  u8 msg_len;
  u8 msg[SBP_MAX_PAYLOAD_LEN];
  u16 frame_len;
  u8 frame[SBP_MAX_FRAME_LEN];
  void *context;
} last_frame;

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

static s32 dummy_write(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(dummy_buff + dummy_wr, buff, real_n);
 dummy_wr += real_n;
 return real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void* context)
{
 last_io_context = context;
 u32 real_n = n;//(dummy_n > n) ? n : dummy_n;
 memcpy(buff, dummy_buff + dummy_rd, real_n);
 dummy_rd += real_n;
 return real_n;
}

static void logging_reset()
{
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void* context)
{
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[], u16 frame_len, u8 frame[], void *context)
{
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST( test_auto_check_sbp_solution_meta_68 )
{
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
    // We re-initialize before every test so that callbacks for the same message types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_register_callback(&sbp_state, 0xff0e, &msg_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_register_frame_callback(&sbp_state, 0xff0e, &frame_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {85,14,255,21,3,56,36,227,233,29,131,0,70,0,110,0,18,0,44,1,0,64,9,0,10,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,184, };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_soln_meta_t* test_msg = ( msg_soln_meta_t* )test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->age_corrections = 18;
    test_msg->age_gnss = 1073742124;
    test_msg->hdop = 70;
    test_msg->pdop = 131;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[0].flags = 0;
    test_msg->sol_in[0].sensor_type = 9;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[1].flags = 2;
    test_msg->sol_in[1].sensor_type = 10;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[2].flags = 0;
    test_msg->sol_in[2].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[3].flags = 0;
    test_msg->sol_in[3].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[4].flags = 0;
    test_msg->sol_in[4].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[5].flags = 0;
    test_msg->sol_in[5].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[6].flags = 0;
    test_msg->sol_in[6].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[7].flags = 0;
    test_msg->sol_in[7].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[8].flags = 0;
    test_msg->sol_in[8].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[9].flags = 0;
    test_msg->sol_in[9].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[10].flags = 0;
    test_msg->sol_in[10].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[11].flags = 0;
    test_msg->sol_in[11].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[12].flags = 0;
    test_msg->sol_in[12].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[13].flags = 0;
    test_msg->sol_in[13].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[14].flags = 0;
    test_msg->sol_in[14].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[15].flags = 0;
    test_msg->sol_in[15].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[16].flags = 0;
    test_msg->sol_in[16].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[17].flags = 0;
    test_msg->sol_in[17].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[18].flags = 0;
    test_msg->sol_in[18].sensor_type = 0;
    if (sizeof(test_msg->sol_in) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->sol_in[0]);
    }
    
    test_msg->sol_in[19].flags = 0;
    test_msg->sol_in[19].sensor_type = 0;
    test_msg->tow = 501867300;
    test_msg->vdop = 110;
    sbp_send_message(&sbp_state, 0xff0e, 789, test_msg_len, test_msg_storage, &dummy_write);

    ck_assert_msg(test_msg_len == sizeof(encoded_frame) - 8,
        "Test message has not been generated correctly, or the encoded frame from the spec is badly defined. Check your test spec");

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
    ck_assert_msg(last_msg.sender_id == 789,
        "msg_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_msg.len == sizeof(encoded_frame) - 8,
        "msg_callback: len decoded incorrectly");
    ck_assert_msg(memcmp(last_msg.msg, encoded_frame + 6, sizeof(encoded_frame) - 8)
          == 0,
        "msg_callback: test data decoded incorrectly");
    ck_assert_msg(last_msg.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    ck_assert_msg(last_frame.n_callbacks_logged == 1,
        "frame_callback: one callback should have been logged");
    ck_assert_msg(last_frame.sender_id == 789,
        "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xff0e,
        "frame_callback: msg_type decoded incorrectly");
    ck_assert_msg(last_frame.msg_len == sizeof(encoded_frame) - 8,
        "frame_callback: msg_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.msg, encoded_frame + 6, sizeof(encoded_frame) - 8) == 0,
        "frame_callback: test data decoded incorrectly");
    ck_assert_msg(last_frame.frame_len == sizeof(encoded_frame),
        "frame_callback: frame_len decoded incorrectly");
    ck_assert_msg(memcmp(last_frame.frame, encoded_frame, sizeof(encoded_frame)) == 0,
        "frame_callback: frame decoded incorrectly");
    ck_assert_msg(last_frame.context == &DUMMY_MEMORY_FOR_CALLBACKS,
        "frame_callback: context pointer incorrectly passed");

    // Cast to expected message type - the +6 byte offset is where the payload starts
    msg_soln_meta_t* check_msg = ( msg_soln_meta_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->age_corrections == 18, "incorrect value for age_corrections, expected 18, is %d", check_msg->age_corrections);
    ck_assert_msg(check_msg->age_gnss == 1073742124, "incorrect value for age_gnss, expected 1073742124, is %d", check_msg->age_gnss);
    ck_assert_msg(check_msg->hdop == 70, "incorrect value for hdop, expected 70, is %d", check_msg->hdop);
    ck_assert_msg(check_msg->pdop == 131, "incorrect value for pdop, expected 131, is %d", check_msg->pdop);
    ck_assert_msg(check_msg->sol_in[0].flags == 0, "incorrect value for sol_in[0].flags, expected 0, is %d", check_msg->sol_in[0].flags);
    ck_assert_msg(check_msg->sol_in[0].sensor_type == 9, "incorrect value for sol_in[0].sensor_type, expected 9, is %d", check_msg->sol_in[0].sensor_type);
    ck_assert_msg(check_msg->sol_in[1].flags == 2, "incorrect value for sol_in[1].flags, expected 2, is %d", check_msg->sol_in[1].flags);
    ck_assert_msg(check_msg->sol_in[1].sensor_type == 10, "incorrect value for sol_in[1].sensor_type, expected 10, is %d", check_msg->sol_in[1].sensor_type);
    ck_assert_msg(check_msg->sol_in[2].flags == 0, "incorrect value for sol_in[2].flags, expected 0, is %d", check_msg->sol_in[2].flags);
    ck_assert_msg(check_msg->sol_in[2].sensor_type == 0, "incorrect value for sol_in[2].sensor_type, expected 0, is %d", check_msg->sol_in[2].sensor_type);
    ck_assert_msg(check_msg->sol_in[3].flags == 0, "incorrect value for sol_in[3].flags, expected 0, is %d", check_msg->sol_in[3].flags);
    ck_assert_msg(check_msg->sol_in[3].sensor_type == 0, "incorrect value for sol_in[3].sensor_type, expected 0, is %d", check_msg->sol_in[3].sensor_type);
    ck_assert_msg(check_msg->sol_in[4].flags == 0, "incorrect value for sol_in[4].flags, expected 0, is %d", check_msg->sol_in[4].flags);
    ck_assert_msg(check_msg->sol_in[4].sensor_type == 0, "incorrect value for sol_in[4].sensor_type, expected 0, is %d", check_msg->sol_in[4].sensor_type);
    ck_assert_msg(check_msg->sol_in[5].flags == 0, "incorrect value for sol_in[5].flags, expected 0, is %d", check_msg->sol_in[5].flags);
    ck_assert_msg(check_msg->sol_in[5].sensor_type == 0, "incorrect value for sol_in[5].sensor_type, expected 0, is %d", check_msg->sol_in[5].sensor_type);
    ck_assert_msg(check_msg->sol_in[6].flags == 0, "incorrect value for sol_in[6].flags, expected 0, is %d", check_msg->sol_in[6].flags);
    ck_assert_msg(check_msg->sol_in[6].sensor_type == 0, "incorrect value for sol_in[6].sensor_type, expected 0, is %d", check_msg->sol_in[6].sensor_type);
    ck_assert_msg(check_msg->sol_in[7].flags == 0, "incorrect value for sol_in[7].flags, expected 0, is %d", check_msg->sol_in[7].flags);
    ck_assert_msg(check_msg->sol_in[7].sensor_type == 0, "incorrect value for sol_in[7].sensor_type, expected 0, is %d", check_msg->sol_in[7].sensor_type);
    ck_assert_msg(check_msg->sol_in[8].flags == 0, "incorrect value for sol_in[8].flags, expected 0, is %d", check_msg->sol_in[8].flags);
    ck_assert_msg(check_msg->sol_in[8].sensor_type == 0, "incorrect value for sol_in[8].sensor_type, expected 0, is %d", check_msg->sol_in[8].sensor_type);
    ck_assert_msg(check_msg->sol_in[9].flags == 0, "incorrect value for sol_in[9].flags, expected 0, is %d", check_msg->sol_in[9].flags);
    ck_assert_msg(check_msg->sol_in[9].sensor_type == 0, "incorrect value for sol_in[9].sensor_type, expected 0, is %d", check_msg->sol_in[9].sensor_type);
    ck_assert_msg(check_msg->sol_in[10].flags == 0, "incorrect value for sol_in[10].flags, expected 0, is %d", check_msg->sol_in[10].flags);
    ck_assert_msg(check_msg->sol_in[10].sensor_type == 0, "incorrect value for sol_in[10].sensor_type, expected 0, is %d", check_msg->sol_in[10].sensor_type);
    ck_assert_msg(check_msg->sol_in[11].flags == 0, "incorrect value for sol_in[11].flags, expected 0, is %d", check_msg->sol_in[11].flags);
    ck_assert_msg(check_msg->sol_in[11].sensor_type == 0, "incorrect value for sol_in[11].sensor_type, expected 0, is %d", check_msg->sol_in[11].sensor_type);
    ck_assert_msg(check_msg->sol_in[12].flags == 0, "incorrect value for sol_in[12].flags, expected 0, is %d", check_msg->sol_in[12].flags);
    ck_assert_msg(check_msg->sol_in[12].sensor_type == 0, "incorrect value for sol_in[12].sensor_type, expected 0, is %d", check_msg->sol_in[12].sensor_type);
    ck_assert_msg(check_msg->sol_in[13].flags == 0, "incorrect value for sol_in[13].flags, expected 0, is %d", check_msg->sol_in[13].flags);
    ck_assert_msg(check_msg->sol_in[13].sensor_type == 0, "incorrect value for sol_in[13].sensor_type, expected 0, is %d", check_msg->sol_in[13].sensor_type);
    ck_assert_msg(check_msg->sol_in[14].flags == 0, "incorrect value for sol_in[14].flags, expected 0, is %d", check_msg->sol_in[14].flags);
    ck_assert_msg(check_msg->sol_in[14].sensor_type == 0, "incorrect value for sol_in[14].sensor_type, expected 0, is %d", check_msg->sol_in[14].sensor_type);
    ck_assert_msg(check_msg->sol_in[15].flags == 0, "incorrect value for sol_in[15].flags, expected 0, is %d", check_msg->sol_in[15].flags);
    ck_assert_msg(check_msg->sol_in[15].sensor_type == 0, "incorrect value for sol_in[15].sensor_type, expected 0, is %d", check_msg->sol_in[15].sensor_type);
    ck_assert_msg(check_msg->sol_in[16].flags == 0, "incorrect value for sol_in[16].flags, expected 0, is %d", check_msg->sol_in[16].flags);
    ck_assert_msg(check_msg->sol_in[16].sensor_type == 0, "incorrect value for sol_in[16].sensor_type, expected 0, is %d", check_msg->sol_in[16].sensor_type);
    ck_assert_msg(check_msg->sol_in[17].flags == 0, "incorrect value for sol_in[17].flags, expected 0, is %d", check_msg->sol_in[17].flags);
    ck_assert_msg(check_msg->sol_in[17].sensor_type == 0, "incorrect value for sol_in[17].sensor_type, expected 0, is %d", check_msg->sol_in[17].sensor_type);
    ck_assert_msg(check_msg->sol_in[18].flags == 0, "incorrect value for sol_in[18].flags, expected 0, is %d", check_msg->sol_in[18].flags);
    ck_assert_msg(check_msg->sol_in[18].sensor_type == 0, "incorrect value for sol_in[18].sensor_type, expected 0, is %d", check_msg->sol_in[18].sensor_type);
    ck_assert_msg(check_msg->sol_in[19].flags == 0, "incorrect value for sol_in[19].flags, expected 0, is %d", check_msg->sol_in[19].flags);
    ck_assert_msg(check_msg->sol_in[19].sensor_type == 0, "incorrect value for sol_in[19].sensor_type, expected 0, is %d", check_msg->sol_in[19].sensor_type);
    ck_assert_msg(check_msg->tow == 501867300, "incorrect value for tow, expected 501867300, is %d", check_msg->tow);
    ck_assert_msg(check_msg->vdop == 110, "incorrect value for vdop, expected 110, is %d", check_msg->vdop);
  }
}
END_TEST

Suite* auto_check_sbp_solution_meta_68_suite(void)
{
  Suite *s = suite_create("SBP generated test suite: auto_check_sbp_solution_meta_68");
  TCase *tc_acq = tcase_create("Automated_Suite_auto_check_sbp_solution_meta_68");
  tcase_add_test(tc_acq, test_auto_check_sbp_solution_meta_68);
  suite_add_tcase(s, tc_acq);
  return s;
}