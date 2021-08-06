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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgMeasurementState.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/tracking.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

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
  memset(&last_msg, 0, sizeof(last_msg));
  memset(&last_frame, 0, sizeof(last_frame));
}

static void msg_callback(u16 sender_id, u8 len, u8 msg[], void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.len = len;
  last_msg.context = context;
  memcpy(last_msg.msg, msg, len);
}

static void frame_callback(u16 sender_id, u16 msg_type, u8 msg_len, u8 msg[],
                           u16 frame_len, u8 frame[], void *context) {
  last_frame.n_callbacks_logged++;
  last_frame.sender_id = sender_id;
  last_frame.msg_type = msg_type;
  last_frame.msg_len = msg_len;
  memcpy(last_frame.msg, msg, msg_len);
  last_frame.frame_len = frame_len;
  memcpy(last_frame.frame, frame, frame_len);
  last_frame.context = context;
}

START_TEST(test_legacy_auto_check_sbp_tracking_MsgMeasurementState) {
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

    sbp_payload_callback_register(&sbp_state, 0x61, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x61, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  97, 0,   207, 121, 237, 29,  0,  162, 0,   0,  0,   0,   0,  0,
        27,  0,  201, 20,  0,   168, 32,  0,  184, 15,  0,  187, 0,   0,  0,
        18,  0,  210, 16,  0,   167, 0,   0,  0,   23,  0,  213, 10,  0,  223,
        0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   131, 2,  202,
        27,  1,  192, 15,  1,   165, 29,  1,  146, 32,  1,  170, 18,  1,  201,
        0,   0,  0,   0,   0,   0,   0,   0,  0,   23,  1,  212, 10,  1,  205,
        0,   0,  0,   96,  3,   230, 0,   0,  0,   101, 3,  214, 103, 3,  212,
        104, 3,  209, 106, 3,   157, 102, 3,  230, 0,   0,  0,   0,   0,  0,
        101, 4,  189, 96,  4,   207, 106, 4,  164, 104, 4,  193, 0,   0,  0,
        102, 4,  208, 0,   0,   0,   27,  12, 212, 29,  12, 161, 32,  12, 216,
        30,  12, 216, 20,  12,  178, 0,   0,  0,   0,   0,  0,   0,   0,  0,
        0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   0,   0,  0,
        0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   0,   0,  0,
        36,  14, 203, 0,   0,   0,   5,   14, 158, 4,   14, 194, 11,  14, 192,
        9,   14, 207, 0,   0,   0,   0,   0,  0,   0,   0,  0,   9,   20, 218,
        5,   20, 176, 36,  20,  217, 11,  20, 200, 4,   20, 205, 0,   0,  0,
        0,   0,  0,   35,  54,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_measurement_state_t *test_msg =
        (msg_measurement_state_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[0].cn0 = 162;
    test_msg->states[0].mesid.code = 0;
    test_msg->states[0].mesid.sat = 29;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[1].cn0 = 0;
    test_msg->states[1].mesid.code = 0;
    test_msg->states[1].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[2].cn0 = 0;
    test_msg->states[2].mesid.code = 0;
    test_msg->states[2].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[3].cn0 = 201;
    test_msg->states[3].mesid.code = 0;
    test_msg->states[3].mesid.sat = 27;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[4].cn0 = 168;
    test_msg->states[4].mesid.code = 0;
    test_msg->states[4].mesid.sat = 20;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[5].cn0 = 184;
    test_msg->states[5].mesid.code = 0;
    test_msg->states[5].mesid.sat = 32;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[6].cn0 = 187;
    test_msg->states[6].mesid.code = 0;
    test_msg->states[6].mesid.sat = 15;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[7].cn0 = 0;
    test_msg->states[7].mesid.code = 0;
    test_msg->states[7].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[8].cn0 = 210;
    test_msg->states[8].mesid.code = 0;
    test_msg->states[8].mesid.sat = 18;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[9].cn0 = 167;
    test_msg->states[9].mesid.code = 0;
    test_msg->states[9].mesid.sat = 16;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[10].cn0 = 0;
    test_msg->states[10].mesid.code = 0;
    test_msg->states[10].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[11].cn0 = 213;
    test_msg->states[11].mesid.code = 0;
    test_msg->states[11].mesid.sat = 23;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[12].cn0 = 223;
    test_msg->states[12].mesid.code = 0;
    test_msg->states[12].mesid.sat = 10;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[13].cn0 = 0;
    test_msg->states[13].mesid.code = 0;
    test_msg->states[13].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[14].cn0 = 0;
    test_msg->states[14].mesid.code = 0;
    test_msg->states[14].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[15].cn0 = 0;
    test_msg->states[15].mesid.code = 0;
    test_msg->states[15].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[16].cn0 = 0;
    test_msg->states[16].mesid.code = 0;
    test_msg->states[16].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[17].cn0 = 202;
    test_msg->states[17].mesid.code = 2;
    test_msg->states[17].mesid.sat = 131;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[18].cn0 = 192;
    test_msg->states[18].mesid.code = 1;
    test_msg->states[18].mesid.sat = 27;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[19].cn0 = 165;
    test_msg->states[19].mesid.code = 1;
    test_msg->states[19].mesid.sat = 15;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[20].cn0 = 146;
    test_msg->states[20].mesid.code = 1;
    test_msg->states[20].mesid.sat = 29;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[21].cn0 = 170;
    test_msg->states[21].mesid.code = 1;
    test_msg->states[21].mesid.sat = 32;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[22].cn0 = 201;
    test_msg->states[22].mesid.code = 1;
    test_msg->states[22].mesid.sat = 18;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[23].cn0 = 0;
    test_msg->states[23].mesid.code = 0;
    test_msg->states[23].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[24].cn0 = 0;
    test_msg->states[24].mesid.code = 0;
    test_msg->states[24].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[25].cn0 = 0;
    test_msg->states[25].mesid.code = 0;
    test_msg->states[25].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[26].cn0 = 212;
    test_msg->states[26].mesid.code = 1;
    test_msg->states[26].mesid.sat = 23;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[27].cn0 = 205;
    test_msg->states[27].mesid.code = 1;
    test_msg->states[27].mesid.sat = 10;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[28].cn0 = 0;
    test_msg->states[28].mesid.code = 0;
    test_msg->states[28].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[29].cn0 = 230;
    test_msg->states[29].mesid.code = 3;
    test_msg->states[29].mesid.sat = 96;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[30].cn0 = 0;
    test_msg->states[30].mesid.code = 0;
    test_msg->states[30].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[31].cn0 = 214;
    test_msg->states[31].mesid.code = 3;
    test_msg->states[31].mesid.sat = 101;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[32].cn0 = 212;
    test_msg->states[32].mesid.code = 3;
    test_msg->states[32].mesid.sat = 103;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[33].cn0 = 209;
    test_msg->states[33].mesid.code = 3;
    test_msg->states[33].mesid.sat = 104;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[34].cn0 = 157;
    test_msg->states[34].mesid.code = 3;
    test_msg->states[34].mesid.sat = 106;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[35].cn0 = 230;
    test_msg->states[35].mesid.code = 3;
    test_msg->states[35].mesid.sat = 102;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[36].cn0 = 0;
    test_msg->states[36].mesid.code = 0;
    test_msg->states[36].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[37].cn0 = 0;
    test_msg->states[37].mesid.code = 0;
    test_msg->states[37].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[38].cn0 = 189;
    test_msg->states[38].mesid.code = 4;
    test_msg->states[38].mesid.sat = 101;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[39].cn0 = 207;
    test_msg->states[39].mesid.code = 4;
    test_msg->states[39].mesid.sat = 96;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[40].cn0 = 164;
    test_msg->states[40].mesid.code = 4;
    test_msg->states[40].mesid.sat = 106;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[41].cn0 = 193;
    test_msg->states[41].mesid.code = 4;
    test_msg->states[41].mesid.sat = 104;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[42].cn0 = 0;
    test_msg->states[42].mesid.code = 0;
    test_msg->states[42].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[43].cn0 = 208;
    test_msg->states[43].mesid.code = 4;
    test_msg->states[43].mesid.sat = 102;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[44].cn0 = 0;
    test_msg->states[44].mesid.code = 0;
    test_msg->states[44].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[45].cn0 = 212;
    test_msg->states[45].mesid.code = 12;
    test_msg->states[45].mesid.sat = 27;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[46].cn0 = 161;
    test_msg->states[46].mesid.code = 12;
    test_msg->states[46].mesid.sat = 29;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[47].cn0 = 216;
    test_msg->states[47].mesid.code = 12;
    test_msg->states[47].mesid.sat = 32;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[48].cn0 = 216;
    test_msg->states[48].mesid.code = 12;
    test_msg->states[48].mesid.sat = 30;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[49].cn0 = 178;
    test_msg->states[49].mesid.code = 12;
    test_msg->states[49].mesid.sat = 20;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[50].cn0 = 0;
    test_msg->states[50].mesid.code = 0;
    test_msg->states[50].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[51].cn0 = 0;
    test_msg->states[51].mesid.code = 0;
    test_msg->states[51].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[52].cn0 = 0;
    test_msg->states[52].mesid.code = 0;
    test_msg->states[52].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[53].cn0 = 0;
    test_msg->states[53].mesid.code = 0;
    test_msg->states[53].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[54].cn0 = 0;
    test_msg->states[54].mesid.code = 0;
    test_msg->states[54].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[55].cn0 = 0;
    test_msg->states[55].mesid.code = 0;
    test_msg->states[55].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[56].cn0 = 0;
    test_msg->states[56].mesid.code = 0;
    test_msg->states[56].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[57].cn0 = 0;
    test_msg->states[57].mesid.code = 0;
    test_msg->states[57].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[58].cn0 = 0;
    test_msg->states[58].mesid.code = 0;
    test_msg->states[58].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[59].cn0 = 0;
    test_msg->states[59].mesid.code = 0;
    test_msg->states[59].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[60].cn0 = 0;
    test_msg->states[60].mesid.code = 0;
    test_msg->states[60].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[61].cn0 = 0;
    test_msg->states[61].mesid.code = 0;
    test_msg->states[61].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[62].cn0 = 0;
    test_msg->states[62].mesid.code = 0;
    test_msg->states[62].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[63].cn0 = 203;
    test_msg->states[63].mesid.code = 14;
    test_msg->states[63].mesid.sat = 36;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[64].cn0 = 0;
    test_msg->states[64].mesid.code = 0;
    test_msg->states[64].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[65].cn0 = 158;
    test_msg->states[65].mesid.code = 14;
    test_msg->states[65].mesid.sat = 5;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[66].cn0 = 194;
    test_msg->states[66].mesid.code = 14;
    test_msg->states[66].mesid.sat = 4;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[67].cn0 = 192;
    test_msg->states[67].mesid.code = 14;
    test_msg->states[67].mesid.sat = 11;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[68].cn0 = 207;
    test_msg->states[68].mesid.code = 14;
    test_msg->states[68].mesid.sat = 9;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[69].cn0 = 0;
    test_msg->states[69].mesid.code = 0;
    test_msg->states[69].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[70].cn0 = 0;
    test_msg->states[70].mesid.code = 0;
    test_msg->states[70].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[71].cn0 = 0;
    test_msg->states[71].mesid.code = 0;
    test_msg->states[71].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[72].cn0 = 218;
    test_msg->states[72].mesid.code = 20;
    test_msg->states[72].mesid.sat = 9;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[73].cn0 = 176;
    test_msg->states[73].mesid.code = 20;
    test_msg->states[73].mesid.sat = 5;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[74].cn0 = 217;
    test_msg->states[74].mesid.code = 20;
    test_msg->states[74].mesid.sat = 36;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[75].cn0 = 200;
    test_msg->states[75].mesid.code = 20;
    test_msg->states[75].mesid.sat = 11;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[76].cn0 = 205;
    test_msg->states[76].mesid.code = 20;
    test_msg->states[76].mesid.sat = 4;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[77].cn0 = 0;
    test_msg->states[77].mesid.code = 0;
    test_msg->states[77].mesid.sat = 0;
    if (sizeof(test_msg->states) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->states[0]);
    }
    test_msg->states[78].cn0 = 0;
    test_msg->states[78].mesid.code = 0;
    test_msg->states[78].mesid.sat = 0;
    sbp_payload_send(&sbp_state, 0x61, 31183, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 31183,
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
    ck_assert_msg(last_frame.sender_id == 31183,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x61,
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
    msg_measurement_state_t *check_msg =
        (msg_measurement_state_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->states[0].cn0 == 162,
                  "incorrect value for states[0].cn0, expected 162, is %d",
                  check_msg->states[0].cn0);
    ck_assert_msg(check_msg->states[0].mesid.code == 0,
                  "incorrect value for states[0].mesid.code, expected 0, is %d",
                  check_msg->states[0].mesid.code);
    ck_assert_msg(check_msg->states[0].mesid.sat == 29,
                  "incorrect value for states[0].mesid.sat, expected 29, is %d",
                  check_msg->states[0].mesid.sat);
    ck_assert_msg(check_msg->states[1].cn0 == 0,
                  "incorrect value for states[1].cn0, expected 0, is %d",
                  check_msg->states[1].cn0);
    ck_assert_msg(check_msg->states[1].mesid.code == 0,
                  "incorrect value for states[1].mesid.code, expected 0, is %d",
                  check_msg->states[1].mesid.code);
    ck_assert_msg(check_msg->states[1].mesid.sat == 0,
                  "incorrect value for states[1].mesid.sat, expected 0, is %d",
                  check_msg->states[1].mesid.sat);
    ck_assert_msg(check_msg->states[2].cn0 == 0,
                  "incorrect value for states[2].cn0, expected 0, is %d",
                  check_msg->states[2].cn0);
    ck_assert_msg(check_msg->states[2].mesid.code == 0,
                  "incorrect value for states[2].mesid.code, expected 0, is %d",
                  check_msg->states[2].mesid.code);
    ck_assert_msg(check_msg->states[2].mesid.sat == 0,
                  "incorrect value for states[2].mesid.sat, expected 0, is %d",
                  check_msg->states[2].mesid.sat);
    ck_assert_msg(check_msg->states[3].cn0 == 201,
                  "incorrect value for states[3].cn0, expected 201, is %d",
                  check_msg->states[3].cn0);
    ck_assert_msg(check_msg->states[3].mesid.code == 0,
                  "incorrect value for states[3].mesid.code, expected 0, is %d",
                  check_msg->states[3].mesid.code);
    ck_assert_msg(check_msg->states[3].mesid.sat == 27,
                  "incorrect value for states[3].mesid.sat, expected 27, is %d",
                  check_msg->states[3].mesid.sat);
    ck_assert_msg(check_msg->states[4].cn0 == 168,
                  "incorrect value for states[4].cn0, expected 168, is %d",
                  check_msg->states[4].cn0);
    ck_assert_msg(check_msg->states[4].mesid.code == 0,
                  "incorrect value for states[4].mesid.code, expected 0, is %d",
                  check_msg->states[4].mesid.code);
    ck_assert_msg(check_msg->states[4].mesid.sat == 20,
                  "incorrect value for states[4].mesid.sat, expected 20, is %d",
                  check_msg->states[4].mesid.sat);
    ck_assert_msg(check_msg->states[5].cn0 == 184,
                  "incorrect value for states[5].cn0, expected 184, is %d",
                  check_msg->states[5].cn0);
    ck_assert_msg(check_msg->states[5].mesid.code == 0,
                  "incorrect value for states[5].mesid.code, expected 0, is %d",
                  check_msg->states[5].mesid.code);
    ck_assert_msg(check_msg->states[5].mesid.sat == 32,
                  "incorrect value for states[5].mesid.sat, expected 32, is %d",
                  check_msg->states[5].mesid.sat);
    ck_assert_msg(check_msg->states[6].cn0 == 187,
                  "incorrect value for states[6].cn0, expected 187, is %d",
                  check_msg->states[6].cn0);
    ck_assert_msg(check_msg->states[6].mesid.code == 0,
                  "incorrect value for states[6].mesid.code, expected 0, is %d",
                  check_msg->states[6].mesid.code);
    ck_assert_msg(check_msg->states[6].mesid.sat == 15,
                  "incorrect value for states[6].mesid.sat, expected 15, is %d",
                  check_msg->states[6].mesid.sat);
    ck_assert_msg(check_msg->states[7].cn0 == 0,
                  "incorrect value for states[7].cn0, expected 0, is %d",
                  check_msg->states[7].cn0);
    ck_assert_msg(check_msg->states[7].mesid.code == 0,
                  "incorrect value for states[7].mesid.code, expected 0, is %d",
                  check_msg->states[7].mesid.code);
    ck_assert_msg(check_msg->states[7].mesid.sat == 0,
                  "incorrect value for states[7].mesid.sat, expected 0, is %d",
                  check_msg->states[7].mesid.sat);
    ck_assert_msg(check_msg->states[8].cn0 == 210,
                  "incorrect value for states[8].cn0, expected 210, is %d",
                  check_msg->states[8].cn0);
    ck_assert_msg(check_msg->states[8].mesid.code == 0,
                  "incorrect value for states[8].mesid.code, expected 0, is %d",
                  check_msg->states[8].mesid.code);
    ck_assert_msg(check_msg->states[8].mesid.sat == 18,
                  "incorrect value for states[8].mesid.sat, expected 18, is %d",
                  check_msg->states[8].mesid.sat);
    ck_assert_msg(check_msg->states[9].cn0 == 167,
                  "incorrect value for states[9].cn0, expected 167, is %d",
                  check_msg->states[9].cn0);
    ck_assert_msg(check_msg->states[9].mesid.code == 0,
                  "incorrect value for states[9].mesid.code, expected 0, is %d",
                  check_msg->states[9].mesid.code);
    ck_assert_msg(check_msg->states[9].mesid.sat == 16,
                  "incorrect value for states[9].mesid.sat, expected 16, is %d",
                  check_msg->states[9].mesid.sat);
    ck_assert_msg(check_msg->states[10].cn0 == 0,
                  "incorrect value for states[10].cn0, expected 0, is %d",
                  check_msg->states[10].cn0);
    ck_assert_msg(
        check_msg->states[10].mesid.code == 0,
        "incorrect value for states[10].mesid.code, expected 0, is %d",
        check_msg->states[10].mesid.code);
    ck_assert_msg(check_msg->states[10].mesid.sat == 0,
                  "incorrect value for states[10].mesid.sat, expected 0, is %d",
                  check_msg->states[10].mesid.sat);
    ck_assert_msg(check_msg->states[11].cn0 == 213,
                  "incorrect value for states[11].cn0, expected 213, is %d",
                  check_msg->states[11].cn0);
    ck_assert_msg(
        check_msg->states[11].mesid.code == 0,
        "incorrect value for states[11].mesid.code, expected 0, is %d",
        check_msg->states[11].mesid.code);
    ck_assert_msg(
        check_msg->states[11].mesid.sat == 23,
        "incorrect value for states[11].mesid.sat, expected 23, is %d",
        check_msg->states[11].mesid.sat);
    ck_assert_msg(check_msg->states[12].cn0 == 223,
                  "incorrect value for states[12].cn0, expected 223, is %d",
                  check_msg->states[12].cn0);
    ck_assert_msg(
        check_msg->states[12].mesid.code == 0,
        "incorrect value for states[12].mesid.code, expected 0, is %d",
        check_msg->states[12].mesid.code);
    ck_assert_msg(
        check_msg->states[12].mesid.sat == 10,
        "incorrect value for states[12].mesid.sat, expected 10, is %d",
        check_msg->states[12].mesid.sat);
    ck_assert_msg(check_msg->states[13].cn0 == 0,
                  "incorrect value for states[13].cn0, expected 0, is %d",
                  check_msg->states[13].cn0);
    ck_assert_msg(
        check_msg->states[13].mesid.code == 0,
        "incorrect value for states[13].mesid.code, expected 0, is %d",
        check_msg->states[13].mesid.code);
    ck_assert_msg(check_msg->states[13].mesid.sat == 0,
                  "incorrect value for states[13].mesid.sat, expected 0, is %d",
                  check_msg->states[13].mesid.sat);
    ck_assert_msg(check_msg->states[14].cn0 == 0,
                  "incorrect value for states[14].cn0, expected 0, is %d",
                  check_msg->states[14].cn0);
    ck_assert_msg(
        check_msg->states[14].mesid.code == 0,
        "incorrect value for states[14].mesid.code, expected 0, is %d",
        check_msg->states[14].mesid.code);
    ck_assert_msg(check_msg->states[14].mesid.sat == 0,
                  "incorrect value for states[14].mesid.sat, expected 0, is %d",
                  check_msg->states[14].mesid.sat);
    ck_assert_msg(check_msg->states[15].cn0 == 0,
                  "incorrect value for states[15].cn0, expected 0, is %d",
                  check_msg->states[15].cn0);
    ck_assert_msg(
        check_msg->states[15].mesid.code == 0,
        "incorrect value for states[15].mesid.code, expected 0, is %d",
        check_msg->states[15].mesid.code);
    ck_assert_msg(check_msg->states[15].mesid.sat == 0,
                  "incorrect value for states[15].mesid.sat, expected 0, is %d",
                  check_msg->states[15].mesid.sat);
    ck_assert_msg(check_msg->states[16].cn0 == 0,
                  "incorrect value for states[16].cn0, expected 0, is %d",
                  check_msg->states[16].cn0);
    ck_assert_msg(
        check_msg->states[16].mesid.code == 0,
        "incorrect value for states[16].mesid.code, expected 0, is %d",
        check_msg->states[16].mesid.code);
    ck_assert_msg(check_msg->states[16].mesid.sat == 0,
                  "incorrect value for states[16].mesid.sat, expected 0, is %d",
                  check_msg->states[16].mesid.sat);
    ck_assert_msg(check_msg->states[17].cn0 == 202,
                  "incorrect value for states[17].cn0, expected 202, is %d",
                  check_msg->states[17].cn0);
    ck_assert_msg(
        check_msg->states[17].mesid.code == 2,
        "incorrect value for states[17].mesid.code, expected 2, is %d",
        check_msg->states[17].mesid.code);
    ck_assert_msg(
        check_msg->states[17].mesid.sat == 131,
        "incorrect value for states[17].mesid.sat, expected 131, is %d",
        check_msg->states[17].mesid.sat);
    ck_assert_msg(check_msg->states[18].cn0 == 192,
                  "incorrect value for states[18].cn0, expected 192, is %d",
                  check_msg->states[18].cn0);
    ck_assert_msg(
        check_msg->states[18].mesid.code == 1,
        "incorrect value for states[18].mesid.code, expected 1, is %d",
        check_msg->states[18].mesid.code);
    ck_assert_msg(
        check_msg->states[18].mesid.sat == 27,
        "incorrect value for states[18].mesid.sat, expected 27, is %d",
        check_msg->states[18].mesid.sat);
    ck_assert_msg(check_msg->states[19].cn0 == 165,
                  "incorrect value for states[19].cn0, expected 165, is %d",
                  check_msg->states[19].cn0);
    ck_assert_msg(
        check_msg->states[19].mesid.code == 1,
        "incorrect value for states[19].mesid.code, expected 1, is %d",
        check_msg->states[19].mesid.code);
    ck_assert_msg(
        check_msg->states[19].mesid.sat == 15,
        "incorrect value for states[19].mesid.sat, expected 15, is %d",
        check_msg->states[19].mesid.sat);
    ck_assert_msg(check_msg->states[20].cn0 == 146,
                  "incorrect value for states[20].cn0, expected 146, is %d",
                  check_msg->states[20].cn0);
    ck_assert_msg(
        check_msg->states[20].mesid.code == 1,
        "incorrect value for states[20].mesid.code, expected 1, is %d",
        check_msg->states[20].mesid.code);
    ck_assert_msg(
        check_msg->states[20].mesid.sat == 29,
        "incorrect value for states[20].mesid.sat, expected 29, is %d",
        check_msg->states[20].mesid.sat);
    ck_assert_msg(check_msg->states[21].cn0 == 170,
                  "incorrect value for states[21].cn0, expected 170, is %d",
                  check_msg->states[21].cn0);
    ck_assert_msg(
        check_msg->states[21].mesid.code == 1,
        "incorrect value for states[21].mesid.code, expected 1, is %d",
        check_msg->states[21].mesid.code);
    ck_assert_msg(
        check_msg->states[21].mesid.sat == 32,
        "incorrect value for states[21].mesid.sat, expected 32, is %d",
        check_msg->states[21].mesid.sat);
    ck_assert_msg(check_msg->states[22].cn0 == 201,
                  "incorrect value for states[22].cn0, expected 201, is %d",
                  check_msg->states[22].cn0);
    ck_assert_msg(
        check_msg->states[22].mesid.code == 1,
        "incorrect value for states[22].mesid.code, expected 1, is %d",
        check_msg->states[22].mesid.code);
    ck_assert_msg(
        check_msg->states[22].mesid.sat == 18,
        "incorrect value for states[22].mesid.sat, expected 18, is %d",
        check_msg->states[22].mesid.sat);
    ck_assert_msg(check_msg->states[23].cn0 == 0,
                  "incorrect value for states[23].cn0, expected 0, is %d",
                  check_msg->states[23].cn0);
    ck_assert_msg(
        check_msg->states[23].mesid.code == 0,
        "incorrect value for states[23].mesid.code, expected 0, is %d",
        check_msg->states[23].mesid.code);
    ck_assert_msg(check_msg->states[23].mesid.sat == 0,
                  "incorrect value for states[23].mesid.sat, expected 0, is %d",
                  check_msg->states[23].mesid.sat);
    ck_assert_msg(check_msg->states[24].cn0 == 0,
                  "incorrect value for states[24].cn0, expected 0, is %d",
                  check_msg->states[24].cn0);
    ck_assert_msg(
        check_msg->states[24].mesid.code == 0,
        "incorrect value for states[24].mesid.code, expected 0, is %d",
        check_msg->states[24].mesid.code);
    ck_assert_msg(check_msg->states[24].mesid.sat == 0,
                  "incorrect value for states[24].mesid.sat, expected 0, is %d",
                  check_msg->states[24].mesid.sat);
    ck_assert_msg(check_msg->states[25].cn0 == 0,
                  "incorrect value for states[25].cn0, expected 0, is %d",
                  check_msg->states[25].cn0);
    ck_assert_msg(
        check_msg->states[25].mesid.code == 0,
        "incorrect value for states[25].mesid.code, expected 0, is %d",
        check_msg->states[25].mesid.code);
    ck_assert_msg(check_msg->states[25].mesid.sat == 0,
                  "incorrect value for states[25].mesid.sat, expected 0, is %d",
                  check_msg->states[25].mesid.sat);
    ck_assert_msg(check_msg->states[26].cn0 == 212,
                  "incorrect value for states[26].cn0, expected 212, is %d",
                  check_msg->states[26].cn0);
    ck_assert_msg(
        check_msg->states[26].mesid.code == 1,
        "incorrect value for states[26].mesid.code, expected 1, is %d",
        check_msg->states[26].mesid.code);
    ck_assert_msg(
        check_msg->states[26].mesid.sat == 23,
        "incorrect value for states[26].mesid.sat, expected 23, is %d",
        check_msg->states[26].mesid.sat);
    ck_assert_msg(check_msg->states[27].cn0 == 205,
                  "incorrect value for states[27].cn0, expected 205, is %d",
                  check_msg->states[27].cn0);
    ck_assert_msg(
        check_msg->states[27].mesid.code == 1,
        "incorrect value for states[27].mesid.code, expected 1, is %d",
        check_msg->states[27].mesid.code);
    ck_assert_msg(
        check_msg->states[27].mesid.sat == 10,
        "incorrect value for states[27].mesid.sat, expected 10, is %d",
        check_msg->states[27].mesid.sat);
    ck_assert_msg(check_msg->states[28].cn0 == 0,
                  "incorrect value for states[28].cn0, expected 0, is %d",
                  check_msg->states[28].cn0);
    ck_assert_msg(
        check_msg->states[28].mesid.code == 0,
        "incorrect value for states[28].mesid.code, expected 0, is %d",
        check_msg->states[28].mesid.code);
    ck_assert_msg(check_msg->states[28].mesid.sat == 0,
                  "incorrect value for states[28].mesid.sat, expected 0, is %d",
                  check_msg->states[28].mesid.sat);
    ck_assert_msg(check_msg->states[29].cn0 == 230,
                  "incorrect value for states[29].cn0, expected 230, is %d",
                  check_msg->states[29].cn0);
    ck_assert_msg(
        check_msg->states[29].mesid.code == 3,
        "incorrect value for states[29].mesid.code, expected 3, is %d",
        check_msg->states[29].mesid.code);
    ck_assert_msg(
        check_msg->states[29].mesid.sat == 96,
        "incorrect value for states[29].mesid.sat, expected 96, is %d",
        check_msg->states[29].mesid.sat);
    ck_assert_msg(check_msg->states[30].cn0 == 0,
                  "incorrect value for states[30].cn0, expected 0, is %d",
                  check_msg->states[30].cn0);
    ck_assert_msg(
        check_msg->states[30].mesid.code == 0,
        "incorrect value for states[30].mesid.code, expected 0, is %d",
        check_msg->states[30].mesid.code);
    ck_assert_msg(check_msg->states[30].mesid.sat == 0,
                  "incorrect value for states[30].mesid.sat, expected 0, is %d",
                  check_msg->states[30].mesid.sat);
    ck_assert_msg(check_msg->states[31].cn0 == 214,
                  "incorrect value for states[31].cn0, expected 214, is %d",
                  check_msg->states[31].cn0);
    ck_assert_msg(
        check_msg->states[31].mesid.code == 3,
        "incorrect value for states[31].mesid.code, expected 3, is %d",
        check_msg->states[31].mesid.code);
    ck_assert_msg(
        check_msg->states[31].mesid.sat == 101,
        "incorrect value for states[31].mesid.sat, expected 101, is %d",
        check_msg->states[31].mesid.sat);
    ck_assert_msg(check_msg->states[32].cn0 == 212,
                  "incorrect value for states[32].cn0, expected 212, is %d",
                  check_msg->states[32].cn0);
    ck_assert_msg(
        check_msg->states[32].mesid.code == 3,
        "incorrect value for states[32].mesid.code, expected 3, is %d",
        check_msg->states[32].mesid.code);
    ck_assert_msg(
        check_msg->states[32].mesid.sat == 103,
        "incorrect value for states[32].mesid.sat, expected 103, is %d",
        check_msg->states[32].mesid.sat);
    ck_assert_msg(check_msg->states[33].cn0 == 209,
                  "incorrect value for states[33].cn0, expected 209, is %d",
                  check_msg->states[33].cn0);
    ck_assert_msg(
        check_msg->states[33].mesid.code == 3,
        "incorrect value for states[33].mesid.code, expected 3, is %d",
        check_msg->states[33].mesid.code);
    ck_assert_msg(
        check_msg->states[33].mesid.sat == 104,
        "incorrect value for states[33].mesid.sat, expected 104, is %d",
        check_msg->states[33].mesid.sat);
    ck_assert_msg(check_msg->states[34].cn0 == 157,
                  "incorrect value for states[34].cn0, expected 157, is %d",
                  check_msg->states[34].cn0);
    ck_assert_msg(
        check_msg->states[34].mesid.code == 3,
        "incorrect value for states[34].mesid.code, expected 3, is %d",
        check_msg->states[34].mesid.code);
    ck_assert_msg(
        check_msg->states[34].mesid.sat == 106,
        "incorrect value for states[34].mesid.sat, expected 106, is %d",
        check_msg->states[34].mesid.sat);
    ck_assert_msg(check_msg->states[35].cn0 == 230,
                  "incorrect value for states[35].cn0, expected 230, is %d",
                  check_msg->states[35].cn0);
    ck_assert_msg(
        check_msg->states[35].mesid.code == 3,
        "incorrect value for states[35].mesid.code, expected 3, is %d",
        check_msg->states[35].mesid.code);
    ck_assert_msg(
        check_msg->states[35].mesid.sat == 102,
        "incorrect value for states[35].mesid.sat, expected 102, is %d",
        check_msg->states[35].mesid.sat);
    ck_assert_msg(check_msg->states[36].cn0 == 0,
                  "incorrect value for states[36].cn0, expected 0, is %d",
                  check_msg->states[36].cn0);
    ck_assert_msg(
        check_msg->states[36].mesid.code == 0,
        "incorrect value for states[36].mesid.code, expected 0, is %d",
        check_msg->states[36].mesid.code);
    ck_assert_msg(check_msg->states[36].mesid.sat == 0,
                  "incorrect value for states[36].mesid.sat, expected 0, is %d",
                  check_msg->states[36].mesid.sat);
    ck_assert_msg(check_msg->states[37].cn0 == 0,
                  "incorrect value for states[37].cn0, expected 0, is %d",
                  check_msg->states[37].cn0);
    ck_assert_msg(
        check_msg->states[37].mesid.code == 0,
        "incorrect value for states[37].mesid.code, expected 0, is %d",
        check_msg->states[37].mesid.code);
    ck_assert_msg(check_msg->states[37].mesid.sat == 0,
                  "incorrect value for states[37].mesid.sat, expected 0, is %d",
                  check_msg->states[37].mesid.sat);
    ck_assert_msg(check_msg->states[38].cn0 == 189,
                  "incorrect value for states[38].cn0, expected 189, is %d",
                  check_msg->states[38].cn0);
    ck_assert_msg(
        check_msg->states[38].mesid.code == 4,
        "incorrect value for states[38].mesid.code, expected 4, is %d",
        check_msg->states[38].mesid.code);
    ck_assert_msg(
        check_msg->states[38].mesid.sat == 101,
        "incorrect value for states[38].mesid.sat, expected 101, is %d",
        check_msg->states[38].mesid.sat);
    ck_assert_msg(check_msg->states[39].cn0 == 207,
                  "incorrect value for states[39].cn0, expected 207, is %d",
                  check_msg->states[39].cn0);
    ck_assert_msg(
        check_msg->states[39].mesid.code == 4,
        "incorrect value for states[39].mesid.code, expected 4, is %d",
        check_msg->states[39].mesid.code);
    ck_assert_msg(
        check_msg->states[39].mesid.sat == 96,
        "incorrect value for states[39].mesid.sat, expected 96, is %d",
        check_msg->states[39].mesid.sat);
    ck_assert_msg(check_msg->states[40].cn0 == 164,
                  "incorrect value for states[40].cn0, expected 164, is %d",
                  check_msg->states[40].cn0);
    ck_assert_msg(
        check_msg->states[40].mesid.code == 4,
        "incorrect value for states[40].mesid.code, expected 4, is %d",
        check_msg->states[40].mesid.code);
    ck_assert_msg(
        check_msg->states[40].mesid.sat == 106,
        "incorrect value for states[40].mesid.sat, expected 106, is %d",
        check_msg->states[40].mesid.sat);
    ck_assert_msg(check_msg->states[41].cn0 == 193,
                  "incorrect value for states[41].cn0, expected 193, is %d",
                  check_msg->states[41].cn0);
    ck_assert_msg(
        check_msg->states[41].mesid.code == 4,
        "incorrect value for states[41].mesid.code, expected 4, is %d",
        check_msg->states[41].mesid.code);
    ck_assert_msg(
        check_msg->states[41].mesid.sat == 104,
        "incorrect value for states[41].mesid.sat, expected 104, is %d",
        check_msg->states[41].mesid.sat);
    ck_assert_msg(check_msg->states[42].cn0 == 0,
                  "incorrect value for states[42].cn0, expected 0, is %d",
                  check_msg->states[42].cn0);
    ck_assert_msg(
        check_msg->states[42].mesid.code == 0,
        "incorrect value for states[42].mesid.code, expected 0, is %d",
        check_msg->states[42].mesid.code);
    ck_assert_msg(check_msg->states[42].mesid.sat == 0,
                  "incorrect value for states[42].mesid.sat, expected 0, is %d",
                  check_msg->states[42].mesid.sat);
    ck_assert_msg(check_msg->states[43].cn0 == 208,
                  "incorrect value for states[43].cn0, expected 208, is %d",
                  check_msg->states[43].cn0);
    ck_assert_msg(
        check_msg->states[43].mesid.code == 4,
        "incorrect value for states[43].mesid.code, expected 4, is %d",
        check_msg->states[43].mesid.code);
    ck_assert_msg(
        check_msg->states[43].mesid.sat == 102,
        "incorrect value for states[43].mesid.sat, expected 102, is %d",
        check_msg->states[43].mesid.sat);
    ck_assert_msg(check_msg->states[44].cn0 == 0,
                  "incorrect value for states[44].cn0, expected 0, is %d",
                  check_msg->states[44].cn0);
    ck_assert_msg(
        check_msg->states[44].mesid.code == 0,
        "incorrect value for states[44].mesid.code, expected 0, is %d",
        check_msg->states[44].mesid.code);
    ck_assert_msg(check_msg->states[44].mesid.sat == 0,
                  "incorrect value for states[44].mesid.sat, expected 0, is %d",
                  check_msg->states[44].mesid.sat);
    ck_assert_msg(check_msg->states[45].cn0 == 212,
                  "incorrect value for states[45].cn0, expected 212, is %d",
                  check_msg->states[45].cn0);
    ck_assert_msg(
        check_msg->states[45].mesid.code == 12,
        "incorrect value for states[45].mesid.code, expected 12, is %d",
        check_msg->states[45].mesid.code);
    ck_assert_msg(
        check_msg->states[45].mesid.sat == 27,
        "incorrect value for states[45].mesid.sat, expected 27, is %d",
        check_msg->states[45].mesid.sat);
    ck_assert_msg(check_msg->states[46].cn0 == 161,
                  "incorrect value for states[46].cn0, expected 161, is %d",
                  check_msg->states[46].cn0);
    ck_assert_msg(
        check_msg->states[46].mesid.code == 12,
        "incorrect value for states[46].mesid.code, expected 12, is %d",
        check_msg->states[46].mesid.code);
    ck_assert_msg(
        check_msg->states[46].mesid.sat == 29,
        "incorrect value for states[46].mesid.sat, expected 29, is %d",
        check_msg->states[46].mesid.sat);
    ck_assert_msg(check_msg->states[47].cn0 == 216,
                  "incorrect value for states[47].cn0, expected 216, is %d",
                  check_msg->states[47].cn0);
    ck_assert_msg(
        check_msg->states[47].mesid.code == 12,
        "incorrect value for states[47].mesid.code, expected 12, is %d",
        check_msg->states[47].mesid.code);
    ck_assert_msg(
        check_msg->states[47].mesid.sat == 32,
        "incorrect value for states[47].mesid.sat, expected 32, is %d",
        check_msg->states[47].mesid.sat);
    ck_assert_msg(check_msg->states[48].cn0 == 216,
                  "incorrect value for states[48].cn0, expected 216, is %d",
                  check_msg->states[48].cn0);
    ck_assert_msg(
        check_msg->states[48].mesid.code == 12,
        "incorrect value for states[48].mesid.code, expected 12, is %d",
        check_msg->states[48].mesid.code);
    ck_assert_msg(
        check_msg->states[48].mesid.sat == 30,
        "incorrect value for states[48].mesid.sat, expected 30, is %d",
        check_msg->states[48].mesid.sat);
    ck_assert_msg(check_msg->states[49].cn0 == 178,
                  "incorrect value for states[49].cn0, expected 178, is %d",
                  check_msg->states[49].cn0);
    ck_assert_msg(
        check_msg->states[49].mesid.code == 12,
        "incorrect value for states[49].mesid.code, expected 12, is %d",
        check_msg->states[49].mesid.code);
    ck_assert_msg(
        check_msg->states[49].mesid.sat == 20,
        "incorrect value for states[49].mesid.sat, expected 20, is %d",
        check_msg->states[49].mesid.sat);
    ck_assert_msg(check_msg->states[50].cn0 == 0,
                  "incorrect value for states[50].cn0, expected 0, is %d",
                  check_msg->states[50].cn0);
    ck_assert_msg(
        check_msg->states[50].mesid.code == 0,
        "incorrect value for states[50].mesid.code, expected 0, is %d",
        check_msg->states[50].mesid.code);
    ck_assert_msg(check_msg->states[50].mesid.sat == 0,
                  "incorrect value for states[50].mesid.sat, expected 0, is %d",
                  check_msg->states[50].mesid.sat);
    ck_assert_msg(check_msg->states[51].cn0 == 0,
                  "incorrect value for states[51].cn0, expected 0, is %d",
                  check_msg->states[51].cn0);
    ck_assert_msg(
        check_msg->states[51].mesid.code == 0,
        "incorrect value for states[51].mesid.code, expected 0, is %d",
        check_msg->states[51].mesid.code);
    ck_assert_msg(check_msg->states[51].mesid.sat == 0,
                  "incorrect value for states[51].mesid.sat, expected 0, is %d",
                  check_msg->states[51].mesid.sat);
    ck_assert_msg(check_msg->states[52].cn0 == 0,
                  "incorrect value for states[52].cn0, expected 0, is %d",
                  check_msg->states[52].cn0);
    ck_assert_msg(
        check_msg->states[52].mesid.code == 0,
        "incorrect value for states[52].mesid.code, expected 0, is %d",
        check_msg->states[52].mesid.code);
    ck_assert_msg(check_msg->states[52].mesid.sat == 0,
                  "incorrect value for states[52].mesid.sat, expected 0, is %d",
                  check_msg->states[52].mesid.sat);
    ck_assert_msg(check_msg->states[53].cn0 == 0,
                  "incorrect value for states[53].cn0, expected 0, is %d",
                  check_msg->states[53].cn0);
    ck_assert_msg(
        check_msg->states[53].mesid.code == 0,
        "incorrect value for states[53].mesid.code, expected 0, is %d",
        check_msg->states[53].mesid.code);
    ck_assert_msg(check_msg->states[53].mesid.sat == 0,
                  "incorrect value for states[53].mesid.sat, expected 0, is %d",
                  check_msg->states[53].mesid.sat);
    ck_assert_msg(check_msg->states[54].cn0 == 0,
                  "incorrect value for states[54].cn0, expected 0, is %d",
                  check_msg->states[54].cn0);
    ck_assert_msg(
        check_msg->states[54].mesid.code == 0,
        "incorrect value for states[54].mesid.code, expected 0, is %d",
        check_msg->states[54].mesid.code);
    ck_assert_msg(check_msg->states[54].mesid.sat == 0,
                  "incorrect value for states[54].mesid.sat, expected 0, is %d",
                  check_msg->states[54].mesid.sat);
    ck_assert_msg(check_msg->states[55].cn0 == 0,
                  "incorrect value for states[55].cn0, expected 0, is %d",
                  check_msg->states[55].cn0);
    ck_assert_msg(
        check_msg->states[55].mesid.code == 0,
        "incorrect value for states[55].mesid.code, expected 0, is %d",
        check_msg->states[55].mesid.code);
    ck_assert_msg(check_msg->states[55].mesid.sat == 0,
                  "incorrect value for states[55].mesid.sat, expected 0, is %d",
                  check_msg->states[55].mesid.sat);
    ck_assert_msg(check_msg->states[56].cn0 == 0,
                  "incorrect value for states[56].cn0, expected 0, is %d",
                  check_msg->states[56].cn0);
    ck_assert_msg(
        check_msg->states[56].mesid.code == 0,
        "incorrect value for states[56].mesid.code, expected 0, is %d",
        check_msg->states[56].mesid.code);
    ck_assert_msg(check_msg->states[56].mesid.sat == 0,
                  "incorrect value for states[56].mesid.sat, expected 0, is %d",
                  check_msg->states[56].mesid.sat);
    ck_assert_msg(check_msg->states[57].cn0 == 0,
                  "incorrect value for states[57].cn0, expected 0, is %d",
                  check_msg->states[57].cn0);
    ck_assert_msg(
        check_msg->states[57].mesid.code == 0,
        "incorrect value for states[57].mesid.code, expected 0, is %d",
        check_msg->states[57].mesid.code);
    ck_assert_msg(check_msg->states[57].mesid.sat == 0,
                  "incorrect value for states[57].mesid.sat, expected 0, is %d",
                  check_msg->states[57].mesid.sat);
    ck_assert_msg(check_msg->states[58].cn0 == 0,
                  "incorrect value for states[58].cn0, expected 0, is %d",
                  check_msg->states[58].cn0);
    ck_assert_msg(
        check_msg->states[58].mesid.code == 0,
        "incorrect value for states[58].mesid.code, expected 0, is %d",
        check_msg->states[58].mesid.code);
    ck_assert_msg(check_msg->states[58].mesid.sat == 0,
                  "incorrect value for states[58].mesid.sat, expected 0, is %d",
                  check_msg->states[58].mesid.sat);
    ck_assert_msg(check_msg->states[59].cn0 == 0,
                  "incorrect value for states[59].cn0, expected 0, is %d",
                  check_msg->states[59].cn0);
    ck_assert_msg(
        check_msg->states[59].mesid.code == 0,
        "incorrect value for states[59].mesid.code, expected 0, is %d",
        check_msg->states[59].mesid.code);
    ck_assert_msg(check_msg->states[59].mesid.sat == 0,
                  "incorrect value for states[59].mesid.sat, expected 0, is %d",
                  check_msg->states[59].mesid.sat);
    ck_assert_msg(check_msg->states[60].cn0 == 0,
                  "incorrect value for states[60].cn0, expected 0, is %d",
                  check_msg->states[60].cn0);
    ck_assert_msg(
        check_msg->states[60].mesid.code == 0,
        "incorrect value for states[60].mesid.code, expected 0, is %d",
        check_msg->states[60].mesid.code);
    ck_assert_msg(check_msg->states[60].mesid.sat == 0,
                  "incorrect value for states[60].mesid.sat, expected 0, is %d",
                  check_msg->states[60].mesid.sat);
    ck_assert_msg(check_msg->states[61].cn0 == 0,
                  "incorrect value for states[61].cn0, expected 0, is %d",
                  check_msg->states[61].cn0);
    ck_assert_msg(
        check_msg->states[61].mesid.code == 0,
        "incorrect value for states[61].mesid.code, expected 0, is %d",
        check_msg->states[61].mesid.code);
    ck_assert_msg(check_msg->states[61].mesid.sat == 0,
                  "incorrect value for states[61].mesid.sat, expected 0, is %d",
                  check_msg->states[61].mesid.sat);
    ck_assert_msg(check_msg->states[62].cn0 == 0,
                  "incorrect value for states[62].cn0, expected 0, is %d",
                  check_msg->states[62].cn0);
    ck_assert_msg(
        check_msg->states[62].mesid.code == 0,
        "incorrect value for states[62].mesid.code, expected 0, is %d",
        check_msg->states[62].mesid.code);
    ck_assert_msg(check_msg->states[62].mesid.sat == 0,
                  "incorrect value for states[62].mesid.sat, expected 0, is %d",
                  check_msg->states[62].mesid.sat);
    ck_assert_msg(check_msg->states[63].cn0 == 203,
                  "incorrect value for states[63].cn0, expected 203, is %d",
                  check_msg->states[63].cn0);
    ck_assert_msg(
        check_msg->states[63].mesid.code == 14,
        "incorrect value for states[63].mesid.code, expected 14, is %d",
        check_msg->states[63].mesid.code);
    ck_assert_msg(
        check_msg->states[63].mesid.sat == 36,
        "incorrect value for states[63].mesid.sat, expected 36, is %d",
        check_msg->states[63].mesid.sat);
    ck_assert_msg(check_msg->states[64].cn0 == 0,
                  "incorrect value for states[64].cn0, expected 0, is %d",
                  check_msg->states[64].cn0);
    ck_assert_msg(
        check_msg->states[64].mesid.code == 0,
        "incorrect value for states[64].mesid.code, expected 0, is %d",
        check_msg->states[64].mesid.code);
    ck_assert_msg(check_msg->states[64].mesid.sat == 0,
                  "incorrect value for states[64].mesid.sat, expected 0, is %d",
                  check_msg->states[64].mesid.sat);
    ck_assert_msg(check_msg->states[65].cn0 == 158,
                  "incorrect value for states[65].cn0, expected 158, is %d",
                  check_msg->states[65].cn0);
    ck_assert_msg(
        check_msg->states[65].mesid.code == 14,
        "incorrect value for states[65].mesid.code, expected 14, is %d",
        check_msg->states[65].mesid.code);
    ck_assert_msg(check_msg->states[65].mesid.sat == 5,
                  "incorrect value for states[65].mesid.sat, expected 5, is %d",
                  check_msg->states[65].mesid.sat);
    ck_assert_msg(check_msg->states[66].cn0 == 194,
                  "incorrect value for states[66].cn0, expected 194, is %d",
                  check_msg->states[66].cn0);
    ck_assert_msg(
        check_msg->states[66].mesid.code == 14,
        "incorrect value for states[66].mesid.code, expected 14, is %d",
        check_msg->states[66].mesid.code);
    ck_assert_msg(check_msg->states[66].mesid.sat == 4,
                  "incorrect value for states[66].mesid.sat, expected 4, is %d",
                  check_msg->states[66].mesid.sat);
    ck_assert_msg(check_msg->states[67].cn0 == 192,
                  "incorrect value for states[67].cn0, expected 192, is %d",
                  check_msg->states[67].cn0);
    ck_assert_msg(
        check_msg->states[67].mesid.code == 14,
        "incorrect value for states[67].mesid.code, expected 14, is %d",
        check_msg->states[67].mesid.code);
    ck_assert_msg(
        check_msg->states[67].mesid.sat == 11,
        "incorrect value for states[67].mesid.sat, expected 11, is %d",
        check_msg->states[67].mesid.sat);
    ck_assert_msg(check_msg->states[68].cn0 == 207,
                  "incorrect value for states[68].cn0, expected 207, is %d",
                  check_msg->states[68].cn0);
    ck_assert_msg(
        check_msg->states[68].mesid.code == 14,
        "incorrect value for states[68].mesid.code, expected 14, is %d",
        check_msg->states[68].mesid.code);
    ck_assert_msg(check_msg->states[68].mesid.sat == 9,
                  "incorrect value for states[68].mesid.sat, expected 9, is %d",
                  check_msg->states[68].mesid.sat);
    ck_assert_msg(check_msg->states[69].cn0 == 0,
                  "incorrect value for states[69].cn0, expected 0, is %d",
                  check_msg->states[69].cn0);
    ck_assert_msg(
        check_msg->states[69].mesid.code == 0,
        "incorrect value for states[69].mesid.code, expected 0, is %d",
        check_msg->states[69].mesid.code);
    ck_assert_msg(check_msg->states[69].mesid.sat == 0,
                  "incorrect value for states[69].mesid.sat, expected 0, is %d",
                  check_msg->states[69].mesid.sat);
    ck_assert_msg(check_msg->states[70].cn0 == 0,
                  "incorrect value for states[70].cn0, expected 0, is %d",
                  check_msg->states[70].cn0);
    ck_assert_msg(
        check_msg->states[70].mesid.code == 0,
        "incorrect value for states[70].mesid.code, expected 0, is %d",
        check_msg->states[70].mesid.code);
    ck_assert_msg(check_msg->states[70].mesid.sat == 0,
                  "incorrect value for states[70].mesid.sat, expected 0, is %d",
                  check_msg->states[70].mesid.sat);
    ck_assert_msg(check_msg->states[71].cn0 == 0,
                  "incorrect value for states[71].cn0, expected 0, is %d",
                  check_msg->states[71].cn0);
    ck_assert_msg(
        check_msg->states[71].mesid.code == 0,
        "incorrect value for states[71].mesid.code, expected 0, is %d",
        check_msg->states[71].mesid.code);
    ck_assert_msg(check_msg->states[71].mesid.sat == 0,
                  "incorrect value for states[71].mesid.sat, expected 0, is %d",
                  check_msg->states[71].mesid.sat);
    ck_assert_msg(check_msg->states[72].cn0 == 218,
                  "incorrect value for states[72].cn0, expected 218, is %d",
                  check_msg->states[72].cn0);
    ck_assert_msg(
        check_msg->states[72].mesid.code == 20,
        "incorrect value for states[72].mesid.code, expected 20, is %d",
        check_msg->states[72].mesid.code);
    ck_assert_msg(check_msg->states[72].mesid.sat == 9,
                  "incorrect value for states[72].mesid.sat, expected 9, is %d",
                  check_msg->states[72].mesid.sat);
    ck_assert_msg(check_msg->states[73].cn0 == 176,
                  "incorrect value for states[73].cn0, expected 176, is %d",
                  check_msg->states[73].cn0);
    ck_assert_msg(
        check_msg->states[73].mesid.code == 20,
        "incorrect value for states[73].mesid.code, expected 20, is %d",
        check_msg->states[73].mesid.code);
    ck_assert_msg(check_msg->states[73].mesid.sat == 5,
                  "incorrect value for states[73].mesid.sat, expected 5, is %d",
                  check_msg->states[73].mesid.sat);
    ck_assert_msg(check_msg->states[74].cn0 == 217,
                  "incorrect value for states[74].cn0, expected 217, is %d",
                  check_msg->states[74].cn0);
    ck_assert_msg(
        check_msg->states[74].mesid.code == 20,
        "incorrect value for states[74].mesid.code, expected 20, is %d",
        check_msg->states[74].mesid.code);
    ck_assert_msg(
        check_msg->states[74].mesid.sat == 36,
        "incorrect value for states[74].mesid.sat, expected 36, is %d",
        check_msg->states[74].mesid.sat);
    ck_assert_msg(check_msg->states[75].cn0 == 200,
                  "incorrect value for states[75].cn0, expected 200, is %d",
                  check_msg->states[75].cn0);
    ck_assert_msg(
        check_msg->states[75].mesid.code == 20,
        "incorrect value for states[75].mesid.code, expected 20, is %d",
        check_msg->states[75].mesid.code);
    ck_assert_msg(
        check_msg->states[75].mesid.sat == 11,
        "incorrect value for states[75].mesid.sat, expected 11, is %d",
        check_msg->states[75].mesid.sat);
    ck_assert_msg(check_msg->states[76].cn0 == 205,
                  "incorrect value for states[76].cn0, expected 205, is %d",
                  check_msg->states[76].cn0);
    ck_assert_msg(
        check_msg->states[76].mesid.code == 20,
        "incorrect value for states[76].mesid.code, expected 20, is %d",
        check_msg->states[76].mesid.code);
    ck_assert_msg(check_msg->states[76].mesid.sat == 4,
                  "incorrect value for states[76].mesid.sat, expected 4, is %d",
                  check_msg->states[76].mesid.sat);
    ck_assert_msg(check_msg->states[77].cn0 == 0,
                  "incorrect value for states[77].cn0, expected 0, is %d",
                  check_msg->states[77].cn0);
    ck_assert_msg(
        check_msg->states[77].mesid.code == 0,
        "incorrect value for states[77].mesid.code, expected 0, is %d",
        check_msg->states[77].mesid.code);
    ck_assert_msg(check_msg->states[77].mesid.sat == 0,
                  "incorrect value for states[77].mesid.sat, expected 0, is %d",
                  check_msg->states[77].mesid.sat);
    ck_assert_msg(check_msg->states[78].cn0 == 0,
                  "incorrect value for states[78].cn0, expected 0, is %d",
                  check_msg->states[78].cn0);
    ck_assert_msg(
        check_msg->states[78].mesid.code == 0,
        "incorrect value for states[78].mesid.code, expected 0, is %d",
        check_msg->states[78].mesid.code);
    ck_assert_msg(check_msg->states[78].mesid.sat == 0,
                  "incorrect value for states[78].mesid.sat, expected 0, is %d",
                  check_msg->states[78].mesid.sat);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_tracking_MsgMeasurementState_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_tracking_MsgMeasurementState");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_tracking_MsgMeasurementState");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_tracking_MsgMeasurementState);
  suite_add_tcase(s, tc_acq);
  return s;
}