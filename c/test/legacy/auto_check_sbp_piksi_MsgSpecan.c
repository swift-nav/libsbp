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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgSpecan.yaml by generate.py. Do not
// modify by hand!

#include <check.h>
#include <sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/api.h>
#include <libsbp/legacy/compat.h>
#include <libsbp/legacy/piksi.h>

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

START_TEST(test_legacy_auto_check_sbp_piksi_MsgSpecan) {
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

    sbp_payload_callback_register(&sbp_state, 0x51, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x51, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  81,  0,   28,  212, 255, 74,  137, 71,  245, 34,  73,  12,  221,
        215, 167, 211, 19,  154, 201, 241, 69,  205, 136, 0,   70,  51,  67,
        108, 69,  102, 38,  166, 68,  100, 179, 185, 17,  175, 49,  193, 228,
        228, 47,  33,  24,  141, 177, 18,  99,  246, 121, 61,  40,  91,  145,
        223, 167, 174, 9,   116, 11,  247, 84,  49,  153, 205, 2,   230, 194,
        218, 241, 101, 107, 45,  137, 93,  114, 230, 43,  224, 23,  74,  209,
        199, 211, 130, 89,  220, 163, 68,  20,  253, 7,   206, 50,  129, 116,
        194, 23,  31,  226, 217, 157, 205, 221, 5,   224, 92,  82,  109, 223,
        195, 233, 165, 1,   82,  141, 157, 177, 169, 244, 131, 96,  109, 111,
        253, 149, 28,  225, 225, 72,  158, 158, 210, 196, 206, 70,  63,  225,
        184, 150, 174, 240, 45,  146, 59,  82,  194, 4,   179, 148, 66,  254,
        115, 77,  30,  46,  4,   204, 37,  200, 121, 18,  17,  171, 102, 163,
        175, 50,  66,  101, 69,  13,  223, 172, 160, 233, 220, 101, 237, 156,
        62,  117, 47,  143, 94,  135, 22,  155, 113, 110, 15,  243, 141, 227,
        46,  143, 227, 209, 249, 2,   153, 168, 131, 249, 160, 88,  38,  117,
        129, 57,  40,  109, 209, 177, 38,  47,  12,  15,  16,  9,   175, 69,
        70,  182, 239, 117, 135, 6,   71,  99,  230, 115, 2,   71,  165, 228,
        123, 210, 168, 90,  124, 20,  7,   220, 144, 168, 69,  22,  72,  162,
        69,  111, 91,  251, 72,  220, 28,  119, 150, 95,  2,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_specan_t *test_msg = (msg_specan_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    test_msg->amplitude_ref = 3780.199951171875;
    test_msg->amplitude_unit = 1329.199951171875;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[0] = 100;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[1] = 179;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[2] = 185;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[3] = 17;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[4] = 175;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[5] = 49;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[6] = 193;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[7] = 228;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[8] = 228;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[9] = 47;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[10] = 33;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[11] = 24;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[12] = 141;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[13] = 177;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[14] = 18;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[15] = 99;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[16] = 246;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[17] = 121;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[18] = 61;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[19] = 40;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[20] = 91;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[21] = 145;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[22] = 223;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[23] = 167;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[24] = 174;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[25] = 9;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[26] = 116;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[27] = 11;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[28] = 247;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[29] = 84;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[30] = 49;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[31] = 153;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[32] = 205;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[33] = 2;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[34] = 230;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[35] = 194;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[36] = 218;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[37] = 241;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[38] = 101;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[39] = 107;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[40] = 45;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[41] = 137;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[42] = 93;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[43] = 114;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[44] = 230;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[45] = 43;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[46] = 224;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[47] = 23;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[48] = 74;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[49] = 209;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[50] = 199;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[51] = 211;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[52] = 130;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[53] = 89;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[54] = 220;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[55] = 163;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[56] = 68;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[57] = 20;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[58] = 253;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[59] = 7;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[60] = 206;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[61] = 50;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[62] = 129;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[63] = 116;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[64] = 194;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[65] = 23;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[66] = 31;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[67] = 226;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[68] = 217;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[69] = 157;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[70] = 205;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[71] = 221;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[72] = 5;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[73] = 224;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[74] = 92;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[75] = 82;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[76] = 109;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[77] = 223;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[78] = 195;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[79] = 233;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[80] = 165;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[81] = 1;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[82] = 82;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[83] = 141;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[84] = 157;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[85] = 177;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[86] = 169;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[87] = 244;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[88] = 131;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[89] = 96;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[90] = 109;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[91] = 111;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[92] = 253;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[93] = 149;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[94] = 28;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[95] = 225;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[96] = 225;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[97] = 72;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[98] = 158;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[99] = 158;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[100] = 210;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[101] = 196;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[102] = 206;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[103] = 70;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[104] = 63;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[105] = 225;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[106] = 184;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[107] = 150;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[108] = 174;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[109] = 240;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[110] = 45;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[111] = 146;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[112] = 59;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[113] = 82;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[114] = 194;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[115] = 4;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[116] = 179;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[117] = 148;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[118] = 66;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[119] = 254;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[120] = 115;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[121] = 77;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[122] = 30;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[123] = 46;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[124] = 4;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[125] = 204;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[126] = 37;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[127] = 200;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[128] = 121;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[129] = 18;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[130] = 17;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[131] = 171;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[132] = 102;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[133] = 163;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[134] = 175;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[135] = 50;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[136] = 66;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[137] = 101;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[138] = 69;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[139] = 13;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[140] = 223;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[141] = 172;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[142] = 160;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[143] = 233;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[144] = 220;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[145] = 101;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[146] = 237;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[147] = 156;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[148] = 62;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[149] = 117;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[150] = 47;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[151] = 143;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[152] = 94;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[153] = 135;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[154] = 22;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[155] = 155;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[156] = 113;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[157] = 110;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[158] = 15;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[159] = 243;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[160] = 141;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[161] = 227;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[162] = 46;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[163] = 143;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[164] = 227;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[165] = 209;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[166] = 249;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[167] = 2;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[168] = 153;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[169] = 168;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[170] = 131;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[171] = 249;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[172] = 160;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[173] = 88;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[174] = 38;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[175] = 117;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[176] = 129;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[177] = 57;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[178] = 40;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[179] = 109;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[180] = 209;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[181] = 177;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[182] = 38;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[183] = 47;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[184] = 12;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[185] = 15;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[186] = 16;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[187] = 9;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[188] = 175;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[189] = 69;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[190] = 70;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[191] = 182;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[192] = 239;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[193] = 117;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[194] = 135;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[195] = 6;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[196] = 71;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[197] = 99;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[198] = 230;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[199] = 115;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[200] = 2;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[201] = 71;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[202] = 165;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[203] = 228;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[204] = 123;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[205] = 210;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[206] = 168;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[207] = 90;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[208] = 124;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[209] = 20;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[210] = 7;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[211] = 220;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[212] = 144;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[213] = 168;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[214] = 69;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[215] = 22;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[216] = 72;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[217] = 162;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[218] = 69;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[219] = 111;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[220] = 91;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[221] = 251;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[222] = 72;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[223] = 220;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[224] = 28;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[225] = 119;
    if (sizeof(test_msg->amplitude_value) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->amplitude_value[0]);
    }
    test_msg->amplitude_value[226] = 150;
    test_msg->channel_tag = 35146;
    test_msg->freq_ref = 7737.2001953125;
    test_msg->freq_step = 8226.2001953125;
    test_msg->t.ns_residual = -1479025396;
    test_msg->t.tow = 1227027783;
    test_msg->t.wn = 5075;
    sbp_payload_send(&sbp_state, 0x51, 54300, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 54300,
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
    ck_assert_msg(last_frame.sender_id == 54300,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x51,
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
    msg_specan_t *check_msg = (msg_specan_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        (check_msg->amplitude_ref * 100 - 3780.19995117 * 100) < 0.05,
        "incorrect value for amplitude_ref, expected 3780.19995117, is %f",
        check_msg->amplitude_ref);
    ck_assert_msg(
        (check_msg->amplitude_unit * 100 - 1329.19995117 * 100) < 0.05,
        "incorrect value for amplitude_unit, expected 1329.19995117, is %f",
        check_msg->amplitude_unit);
    ck_assert_msg(check_msg->amplitude_value[0] == 100,
                  "incorrect value for amplitude_value[0], expected 100, is %d",
                  check_msg->amplitude_value[0]);
    ck_assert_msg(check_msg->amplitude_value[1] == 179,
                  "incorrect value for amplitude_value[1], expected 179, is %d",
                  check_msg->amplitude_value[1]);
    ck_assert_msg(check_msg->amplitude_value[2] == 185,
                  "incorrect value for amplitude_value[2], expected 185, is %d",
                  check_msg->amplitude_value[2]);
    ck_assert_msg(check_msg->amplitude_value[3] == 17,
                  "incorrect value for amplitude_value[3], expected 17, is %d",
                  check_msg->amplitude_value[3]);
    ck_assert_msg(check_msg->amplitude_value[4] == 175,
                  "incorrect value for amplitude_value[4], expected 175, is %d",
                  check_msg->amplitude_value[4]);
    ck_assert_msg(check_msg->amplitude_value[5] == 49,
                  "incorrect value for amplitude_value[5], expected 49, is %d",
                  check_msg->amplitude_value[5]);
    ck_assert_msg(check_msg->amplitude_value[6] == 193,
                  "incorrect value for amplitude_value[6], expected 193, is %d",
                  check_msg->amplitude_value[6]);
    ck_assert_msg(check_msg->amplitude_value[7] == 228,
                  "incorrect value for amplitude_value[7], expected 228, is %d",
                  check_msg->amplitude_value[7]);
    ck_assert_msg(check_msg->amplitude_value[8] == 228,
                  "incorrect value for amplitude_value[8], expected 228, is %d",
                  check_msg->amplitude_value[8]);
    ck_assert_msg(check_msg->amplitude_value[9] == 47,
                  "incorrect value for amplitude_value[9], expected 47, is %d",
                  check_msg->amplitude_value[9]);
    ck_assert_msg(check_msg->amplitude_value[10] == 33,
                  "incorrect value for amplitude_value[10], expected 33, is %d",
                  check_msg->amplitude_value[10]);
    ck_assert_msg(check_msg->amplitude_value[11] == 24,
                  "incorrect value for amplitude_value[11], expected 24, is %d",
                  check_msg->amplitude_value[11]);
    ck_assert_msg(
        check_msg->amplitude_value[12] == 141,
        "incorrect value for amplitude_value[12], expected 141, is %d",
        check_msg->amplitude_value[12]);
    ck_assert_msg(
        check_msg->amplitude_value[13] == 177,
        "incorrect value for amplitude_value[13], expected 177, is %d",
        check_msg->amplitude_value[13]);
    ck_assert_msg(check_msg->amplitude_value[14] == 18,
                  "incorrect value for amplitude_value[14], expected 18, is %d",
                  check_msg->amplitude_value[14]);
    ck_assert_msg(check_msg->amplitude_value[15] == 99,
                  "incorrect value for amplitude_value[15], expected 99, is %d",
                  check_msg->amplitude_value[15]);
    ck_assert_msg(
        check_msg->amplitude_value[16] == 246,
        "incorrect value for amplitude_value[16], expected 246, is %d",
        check_msg->amplitude_value[16]);
    ck_assert_msg(
        check_msg->amplitude_value[17] == 121,
        "incorrect value for amplitude_value[17], expected 121, is %d",
        check_msg->amplitude_value[17]);
    ck_assert_msg(check_msg->amplitude_value[18] == 61,
                  "incorrect value for amplitude_value[18], expected 61, is %d",
                  check_msg->amplitude_value[18]);
    ck_assert_msg(check_msg->amplitude_value[19] == 40,
                  "incorrect value for amplitude_value[19], expected 40, is %d",
                  check_msg->amplitude_value[19]);
    ck_assert_msg(check_msg->amplitude_value[20] == 91,
                  "incorrect value for amplitude_value[20], expected 91, is %d",
                  check_msg->amplitude_value[20]);
    ck_assert_msg(
        check_msg->amplitude_value[21] == 145,
        "incorrect value for amplitude_value[21], expected 145, is %d",
        check_msg->amplitude_value[21]);
    ck_assert_msg(
        check_msg->amplitude_value[22] == 223,
        "incorrect value for amplitude_value[22], expected 223, is %d",
        check_msg->amplitude_value[22]);
    ck_assert_msg(
        check_msg->amplitude_value[23] == 167,
        "incorrect value for amplitude_value[23], expected 167, is %d",
        check_msg->amplitude_value[23]);
    ck_assert_msg(
        check_msg->amplitude_value[24] == 174,
        "incorrect value for amplitude_value[24], expected 174, is %d",
        check_msg->amplitude_value[24]);
    ck_assert_msg(check_msg->amplitude_value[25] == 9,
                  "incorrect value for amplitude_value[25], expected 9, is %d",
                  check_msg->amplitude_value[25]);
    ck_assert_msg(
        check_msg->amplitude_value[26] == 116,
        "incorrect value for amplitude_value[26], expected 116, is %d",
        check_msg->amplitude_value[26]);
    ck_assert_msg(check_msg->amplitude_value[27] == 11,
                  "incorrect value for amplitude_value[27], expected 11, is %d",
                  check_msg->amplitude_value[27]);
    ck_assert_msg(
        check_msg->amplitude_value[28] == 247,
        "incorrect value for amplitude_value[28], expected 247, is %d",
        check_msg->amplitude_value[28]);
    ck_assert_msg(check_msg->amplitude_value[29] == 84,
                  "incorrect value for amplitude_value[29], expected 84, is %d",
                  check_msg->amplitude_value[29]);
    ck_assert_msg(check_msg->amplitude_value[30] == 49,
                  "incorrect value for amplitude_value[30], expected 49, is %d",
                  check_msg->amplitude_value[30]);
    ck_assert_msg(
        check_msg->amplitude_value[31] == 153,
        "incorrect value for amplitude_value[31], expected 153, is %d",
        check_msg->amplitude_value[31]);
    ck_assert_msg(
        check_msg->amplitude_value[32] == 205,
        "incorrect value for amplitude_value[32], expected 205, is %d",
        check_msg->amplitude_value[32]);
    ck_assert_msg(check_msg->amplitude_value[33] == 2,
                  "incorrect value for amplitude_value[33], expected 2, is %d",
                  check_msg->amplitude_value[33]);
    ck_assert_msg(
        check_msg->amplitude_value[34] == 230,
        "incorrect value for amplitude_value[34], expected 230, is %d",
        check_msg->amplitude_value[34]);
    ck_assert_msg(
        check_msg->amplitude_value[35] == 194,
        "incorrect value for amplitude_value[35], expected 194, is %d",
        check_msg->amplitude_value[35]);
    ck_assert_msg(
        check_msg->amplitude_value[36] == 218,
        "incorrect value for amplitude_value[36], expected 218, is %d",
        check_msg->amplitude_value[36]);
    ck_assert_msg(
        check_msg->amplitude_value[37] == 241,
        "incorrect value for amplitude_value[37], expected 241, is %d",
        check_msg->amplitude_value[37]);
    ck_assert_msg(
        check_msg->amplitude_value[38] == 101,
        "incorrect value for amplitude_value[38], expected 101, is %d",
        check_msg->amplitude_value[38]);
    ck_assert_msg(
        check_msg->amplitude_value[39] == 107,
        "incorrect value for amplitude_value[39], expected 107, is %d",
        check_msg->amplitude_value[39]);
    ck_assert_msg(check_msg->amplitude_value[40] == 45,
                  "incorrect value for amplitude_value[40], expected 45, is %d",
                  check_msg->amplitude_value[40]);
    ck_assert_msg(
        check_msg->amplitude_value[41] == 137,
        "incorrect value for amplitude_value[41], expected 137, is %d",
        check_msg->amplitude_value[41]);
    ck_assert_msg(check_msg->amplitude_value[42] == 93,
                  "incorrect value for amplitude_value[42], expected 93, is %d",
                  check_msg->amplitude_value[42]);
    ck_assert_msg(
        check_msg->amplitude_value[43] == 114,
        "incorrect value for amplitude_value[43], expected 114, is %d",
        check_msg->amplitude_value[43]);
    ck_assert_msg(
        check_msg->amplitude_value[44] == 230,
        "incorrect value for amplitude_value[44], expected 230, is %d",
        check_msg->amplitude_value[44]);
    ck_assert_msg(check_msg->amplitude_value[45] == 43,
                  "incorrect value for amplitude_value[45], expected 43, is %d",
                  check_msg->amplitude_value[45]);
    ck_assert_msg(
        check_msg->amplitude_value[46] == 224,
        "incorrect value for amplitude_value[46], expected 224, is %d",
        check_msg->amplitude_value[46]);
    ck_assert_msg(check_msg->amplitude_value[47] == 23,
                  "incorrect value for amplitude_value[47], expected 23, is %d",
                  check_msg->amplitude_value[47]);
    ck_assert_msg(check_msg->amplitude_value[48] == 74,
                  "incorrect value for amplitude_value[48], expected 74, is %d",
                  check_msg->amplitude_value[48]);
    ck_assert_msg(
        check_msg->amplitude_value[49] == 209,
        "incorrect value for amplitude_value[49], expected 209, is %d",
        check_msg->amplitude_value[49]);
    ck_assert_msg(
        check_msg->amplitude_value[50] == 199,
        "incorrect value for amplitude_value[50], expected 199, is %d",
        check_msg->amplitude_value[50]);
    ck_assert_msg(
        check_msg->amplitude_value[51] == 211,
        "incorrect value for amplitude_value[51], expected 211, is %d",
        check_msg->amplitude_value[51]);
    ck_assert_msg(
        check_msg->amplitude_value[52] == 130,
        "incorrect value for amplitude_value[52], expected 130, is %d",
        check_msg->amplitude_value[52]);
    ck_assert_msg(check_msg->amplitude_value[53] == 89,
                  "incorrect value for amplitude_value[53], expected 89, is %d",
                  check_msg->amplitude_value[53]);
    ck_assert_msg(
        check_msg->amplitude_value[54] == 220,
        "incorrect value for amplitude_value[54], expected 220, is %d",
        check_msg->amplitude_value[54]);
    ck_assert_msg(
        check_msg->amplitude_value[55] == 163,
        "incorrect value for amplitude_value[55], expected 163, is %d",
        check_msg->amplitude_value[55]);
    ck_assert_msg(check_msg->amplitude_value[56] == 68,
                  "incorrect value for amplitude_value[56], expected 68, is %d",
                  check_msg->amplitude_value[56]);
    ck_assert_msg(check_msg->amplitude_value[57] == 20,
                  "incorrect value for amplitude_value[57], expected 20, is %d",
                  check_msg->amplitude_value[57]);
    ck_assert_msg(
        check_msg->amplitude_value[58] == 253,
        "incorrect value for amplitude_value[58], expected 253, is %d",
        check_msg->amplitude_value[58]);
    ck_assert_msg(check_msg->amplitude_value[59] == 7,
                  "incorrect value for amplitude_value[59], expected 7, is %d",
                  check_msg->amplitude_value[59]);
    ck_assert_msg(
        check_msg->amplitude_value[60] == 206,
        "incorrect value for amplitude_value[60], expected 206, is %d",
        check_msg->amplitude_value[60]);
    ck_assert_msg(check_msg->amplitude_value[61] == 50,
                  "incorrect value for amplitude_value[61], expected 50, is %d",
                  check_msg->amplitude_value[61]);
    ck_assert_msg(
        check_msg->amplitude_value[62] == 129,
        "incorrect value for amplitude_value[62], expected 129, is %d",
        check_msg->amplitude_value[62]);
    ck_assert_msg(
        check_msg->amplitude_value[63] == 116,
        "incorrect value for amplitude_value[63], expected 116, is %d",
        check_msg->amplitude_value[63]);
    ck_assert_msg(
        check_msg->amplitude_value[64] == 194,
        "incorrect value for amplitude_value[64], expected 194, is %d",
        check_msg->amplitude_value[64]);
    ck_assert_msg(check_msg->amplitude_value[65] == 23,
                  "incorrect value for amplitude_value[65], expected 23, is %d",
                  check_msg->amplitude_value[65]);
    ck_assert_msg(check_msg->amplitude_value[66] == 31,
                  "incorrect value for amplitude_value[66], expected 31, is %d",
                  check_msg->amplitude_value[66]);
    ck_assert_msg(
        check_msg->amplitude_value[67] == 226,
        "incorrect value for amplitude_value[67], expected 226, is %d",
        check_msg->amplitude_value[67]);
    ck_assert_msg(
        check_msg->amplitude_value[68] == 217,
        "incorrect value for amplitude_value[68], expected 217, is %d",
        check_msg->amplitude_value[68]);
    ck_assert_msg(
        check_msg->amplitude_value[69] == 157,
        "incorrect value for amplitude_value[69], expected 157, is %d",
        check_msg->amplitude_value[69]);
    ck_assert_msg(
        check_msg->amplitude_value[70] == 205,
        "incorrect value for amplitude_value[70], expected 205, is %d",
        check_msg->amplitude_value[70]);
    ck_assert_msg(
        check_msg->amplitude_value[71] == 221,
        "incorrect value for amplitude_value[71], expected 221, is %d",
        check_msg->amplitude_value[71]);
    ck_assert_msg(check_msg->amplitude_value[72] == 5,
                  "incorrect value for amplitude_value[72], expected 5, is %d",
                  check_msg->amplitude_value[72]);
    ck_assert_msg(
        check_msg->amplitude_value[73] == 224,
        "incorrect value for amplitude_value[73], expected 224, is %d",
        check_msg->amplitude_value[73]);
    ck_assert_msg(check_msg->amplitude_value[74] == 92,
                  "incorrect value for amplitude_value[74], expected 92, is %d",
                  check_msg->amplitude_value[74]);
    ck_assert_msg(check_msg->amplitude_value[75] == 82,
                  "incorrect value for amplitude_value[75], expected 82, is %d",
                  check_msg->amplitude_value[75]);
    ck_assert_msg(
        check_msg->amplitude_value[76] == 109,
        "incorrect value for amplitude_value[76], expected 109, is %d",
        check_msg->amplitude_value[76]);
    ck_assert_msg(
        check_msg->amplitude_value[77] == 223,
        "incorrect value for amplitude_value[77], expected 223, is %d",
        check_msg->amplitude_value[77]);
    ck_assert_msg(
        check_msg->amplitude_value[78] == 195,
        "incorrect value for amplitude_value[78], expected 195, is %d",
        check_msg->amplitude_value[78]);
    ck_assert_msg(
        check_msg->amplitude_value[79] == 233,
        "incorrect value for amplitude_value[79], expected 233, is %d",
        check_msg->amplitude_value[79]);
    ck_assert_msg(
        check_msg->amplitude_value[80] == 165,
        "incorrect value for amplitude_value[80], expected 165, is %d",
        check_msg->amplitude_value[80]);
    ck_assert_msg(check_msg->amplitude_value[81] == 1,
                  "incorrect value for amplitude_value[81], expected 1, is %d",
                  check_msg->amplitude_value[81]);
    ck_assert_msg(check_msg->amplitude_value[82] == 82,
                  "incorrect value for amplitude_value[82], expected 82, is %d",
                  check_msg->amplitude_value[82]);
    ck_assert_msg(
        check_msg->amplitude_value[83] == 141,
        "incorrect value for amplitude_value[83], expected 141, is %d",
        check_msg->amplitude_value[83]);
    ck_assert_msg(
        check_msg->amplitude_value[84] == 157,
        "incorrect value for amplitude_value[84], expected 157, is %d",
        check_msg->amplitude_value[84]);
    ck_assert_msg(
        check_msg->amplitude_value[85] == 177,
        "incorrect value for amplitude_value[85], expected 177, is %d",
        check_msg->amplitude_value[85]);
    ck_assert_msg(
        check_msg->amplitude_value[86] == 169,
        "incorrect value for amplitude_value[86], expected 169, is %d",
        check_msg->amplitude_value[86]);
    ck_assert_msg(
        check_msg->amplitude_value[87] == 244,
        "incorrect value for amplitude_value[87], expected 244, is %d",
        check_msg->amplitude_value[87]);
    ck_assert_msg(
        check_msg->amplitude_value[88] == 131,
        "incorrect value for amplitude_value[88], expected 131, is %d",
        check_msg->amplitude_value[88]);
    ck_assert_msg(check_msg->amplitude_value[89] == 96,
                  "incorrect value for amplitude_value[89], expected 96, is %d",
                  check_msg->amplitude_value[89]);
    ck_assert_msg(
        check_msg->amplitude_value[90] == 109,
        "incorrect value for amplitude_value[90], expected 109, is %d",
        check_msg->amplitude_value[90]);
    ck_assert_msg(
        check_msg->amplitude_value[91] == 111,
        "incorrect value for amplitude_value[91], expected 111, is %d",
        check_msg->amplitude_value[91]);
    ck_assert_msg(
        check_msg->amplitude_value[92] == 253,
        "incorrect value for amplitude_value[92], expected 253, is %d",
        check_msg->amplitude_value[92]);
    ck_assert_msg(
        check_msg->amplitude_value[93] == 149,
        "incorrect value for amplitude_value[93], expected 149, is %d",
        check_msg->amplitude_value[93]);
    ck_assert_msg(check_msg->amplitude_value[94] == 28,
                  "incorrect value for amplitude_value[94], expected 28, is %d",
                  check_msg->amplitude_value[94]);
    ck_assert_msg(
        check_msg->amplitude_value[95] == 225,
        "incorrect value for amplitude_value[95], expected 225, is %d",
        check_msg->amplitude_value[95]);
    ck_assert_msg(
        check_msg->amplitude_value[96] == 225,
        "incorrect value for amplitude_value[96], expected 225, is %d",
        check_msg->amplitude_value[96]);
    ck_assert_msg(check_msg->amplitude_value[97] == 72,
                  "incorrect value for amplitude_value[97], expected 72, is %d",
                  check_msg->amplitude_value[97]);
    ck_assert_msg(
        check_msg->amplitude_value[98] == 158,
        "incorrect value for amplitude_value[98], expected 158, is %d",
        check_msg->amplitude_value[98]);
    ck_assert_msg(
        check_msg->amplitude_value[99] == 158,
        "incorrect value for amplitude_value[99], expected 158, is %d",
        check_msg->amplitude_value[99]);
    ck_assert_msg(
        check_msg->amplitude_value[100] == 210,
        "incorrect value for amplitude_value[100], expected 210, is %d",
        check_msg->amplitude_value[100]);
    ck_assert_msg(
        check_msg->amplitude_value[101] == 196,
        "incorrect value for amplitude_value[101], expected 196, is %d",
        check_msg->amplitude_value[101]);
    ck_assert_msg(
        check_msg->amplitude_value[102] == 206,
        "incorrect value for amplitude_value[102], expected 206, is %d",
        check_msg->amplitude_value[102]);
    ck_assert_msg(
        check_msg->amplitude_value[103] == 70,
        "incorrect value for amplitude_value[103], expected 70, is %d",
        check_msg->amplitude_value[103]);
    ck_assert_msg(
        check_msg->amplitude_value[104] == 63,
        "incorrect value for amplitude_value[104], expected 63, is %d",
        check_msg->amplitude_value[104]);
    ck_assert_msg(
        check_msg->amplitude_value[105] == 225,
        "incorrect value for amplitude_value[105], expected 225, is %d",
        check_msg->amplitude_value[105]);
    ck_assert_msg(
        check_msg->amplitude_value[106] == 184,
        "incorrect value for amplitude_value[106], expected 184, is %d",
        check_msg->amplitude_value[106]);
    ck_assert_msg(
        check_msg->amplitude_value[107] == 150,
        "incorrect value for amplitude_value[107], expected 150, is %d",
        check_msg->amplitude_value[107]);
    ck_assert_msg(
        check_msg->amplitude_value[108] == 174,
        "incorrect value for amplitude_value[108], expected 174, is %d",
        check_msg->amplitude_value[108]);
    ck_assert_msg(
        check_msg->amplitude_value[109] == 240,
        "incorrect value for amplitude_value[109], expected 240, is %d",
        check_msg->amplitude_value[109]);
    ck_assert_msg(
        check_msg->amplitude_value[110] == 45,
        "incorrect value for amplitude_value[110], expected 45, is %d",
        check_msg->amplitude_value[110]);
    ck_assert_msg(
        check_msg->amplitude_value[111] == 146,
        "incorrect value for amplitude_value[111], expected 146, is %d",
        check_msg->amplitude_value[111]);
    ck_assert_msg(
        check_msg->amplitude_value[112] == 59,
        "incorrect value for amplitude_value[112], expected 59, is %d",
        check_msg->amplitude_value[112]);
    ck_assert_msg(
        check_msg->amplitude_value[113] == 82,
        "incorrect value for amplitude_value[113], expected 82, is %d",
        check_msg->amplitude_value[113]);
    ck_assert_msg(
        check_msg->amplitude_value[114] == 194,
        "incorrect value for amplitude_value[114], expected 194, is %d",
        check_msg->amplitude_value[114]);
    ck_assert_msg(check_msg->amplitude_value[115] == 4,
                  "incorrect value for amplitude_value[115], expected 4, is %d",
                  check_msg->amplitude_value[115]);
    ck_assert_msg(
        check_msg->amplitude_value[116] == 179,
        "incorrect value for amplitude_value[116], expected 179, is %d",
        check_msg->amplitude_value[116]);
    ck_assert_msg(
        check_msg->amplitude_value[117] == 148,
        "incorrect value for amplitude_value[117], expected 148, is %d",
        check_msg->amplitude_value[117]);
    ck_assert_msg(
        check_msg->amplitude_value[118] == 66,
        "incorrect value for amplitude_value[118], expected 66, is %d",
        check_msg->amplitude_value[118]);
    ck_assert_msg(
        check_msg->amplitude_value[119] == 254,
        "incorrect value for amplitude_value[119], expected 254, is %d",
        check_msg->amplitude_value[119]);
    ck_assert_msg(
        check_msg->amplitude_value[120] == 115,
        "incorrect value for amplitude_value[120], expected 115, is %d",
        check_msg->amplitude_value[120]);
    ck_assert_msg(
        check_msg->amplitude_value[121] == 77,
        "incorrect value for amplitude_value[121], expected 77, is %d",
        check_msg->amplitude_value[121]);
    ck_assert_msg(
        check_msg->amplitude_value[122] == 30,
        "incorrect value for amplitude_value[122], expected 30, is %d",
        check_msg->amplitude_value[122]);
    ck_assert_msg(
        check_msg->amplitude_value[123] == 46,
        "incorrect value for amplitude_value[123], expected 46, is %d",
        check_msg->amplitude_value[123]);
    ck_assert_msg(check_msg->amplitude_value[124] == 4,
                  "incorrect value for amplitude_value[124], expected 4, is %d",
                  check_msg->amplitude_value[124]);
    ck_assert_msg(
        check_msg->amplitude_value[125] == 204,
        "incorrect value for amplitude_value[125], expected 204, is %d",
        check_msg->amplitude_value[125]);
    ck_assert_msg(
        check_msg->amplitude_value[126] == 37,
        "incorrect value for amplitude_value[126], expected 37, is %d",
        check_msg->amplitude_value[126]);
    ck_assert_msg(
        check_msg->amplitude_value[127] == 200,
        "incorrect value for amplitude_value[127], expected 200, is %d",
        check_msg->amplitude_value[127]);
    ck_assert_msg(
        check_msg->amplitude_value[128] == 121,
        "incorrect value for amplitude_value[128], expected 121, is %d",
        check_msg->amplitude_value[128]);
    ck_assert_msg(
        check_msg->amplitude_value[129] == 18,
        "incorrect value for amplitude_value[129], expected 18, is %d",
        check_msg->amplitude_value[129]);
    ck_assert_msg(
        check_msg->amplitude_value[130] == 17,
        "incorrect value for amplitude_value[130], expected 17, is %d",
        check_msg->amplitude_value[130]);
    ck_assert_msg(
        check_msg->amplitude_value[131] == 171,
        "incorrect value for amplitude_value[131], expected 171, is %d",
        check_msg->amplitude_value[131]);
    ck_assert_msg(
        check_msg->amplitude_value[132] == 102,
        "incorrect value for amplitude_value[132], expected 102, is %d",
        check_msg->amplitude_value[132]);
    ck_assert_msg(
        check_msg->amplitude_value[133] == 163,
        "incorrect value for amplitude_value[133], expected 163, is %d",
        check_msg->amplitude_value[133]);
    ck_assert_msg(
        check_msg->amplitude_value[134] == 175,
        "incorrect value for amplitude_value[134], expected 175, is %d",
        check_msg->amplitude_value[134]);
    ck_assert_msg(
        check_msg->amplitude_value[135] == 50,
        "incorrect value for amplitude_value[135], expected 50, is %d",
        check_msg->amplitude_value[135]);
    ck_assert_msg(
        check_msg->amplitude_value[136] == 66,
        "incorrect value for amplitude_value[136], expected 66, is %d",
        check_msg->amplitude_value[136]);
    ck_assert_msg(
        check_msg->amplitude_value[137] == 101,
        "incorrect value for amplitude_value[137], expected 101, is %d",
        check_msg->amplitude_value[137]);
    ck_assert_msg(
        check_msg->amplitude_value[138] == 69,
        "incorrect value for amplitude_value[138], expected 69, is %d",
        check_msg->amplitude_value[138]);
    ck_assert_msg(
        check_msg->amplitude_value[139] == 13,
        "incorrect value for amplitude_value[139], expected 13, is %d",
        check_msg->amplitude_value[139]);
    ck_assert_msg(
        check_msg->amplitude_value[140] == 223,
        "incorrect value for amplitude_value[140], expected 223, is %d",
        check_msg->amplitude_value[140]);
    ck_assert_msg(
        check_msg->amplitude_value[141] == 172,
        "incorrect value for amplitude_value[141], expected 172, is %d",
        check_msg->amplitude_value[141]);
    ck_assert_msg(
        check_msg->amplitude_value[142] == 160,
        "incorrect value for amplitude_value[142], expected 160, is %d",
        check_msg->amplitude_value[142]);
    ck_assert_msg(
        check_msg->amplitude_value[143] == 233,
        "incorrect value for amplitude_value[143], expected 233, is %d",
        check_msg->amplitude_value[143]);
    ck_assert_msg(
        check_msg->amplitude_value[144] == 220,
        "incorrect value for amplitude_value[144], expected 220, is %d",
        check_msg->amplitude_value[144]);
    ck_assert_msg(
        check_msg->amplitude_value[145] == 101,
        "incorrect value for amplitude_value[145], expected 101, is %d",
        check_msg->amplitude_value[145]);
    ck_assert_msg(
        check_msg->amplitude_value[146] == 237,
        "incorrect value for amplitude_value[146], expected 237, is %d",
        check_msg->amplitude_value[146]);
    ck_assert_msg(
        check_msg->amplitude_value[147] == 156,
        "incorrect value for amplitude_value[147], expected 156, is %d",
        check_msg->amplitude_value[147]);
    ck_assert_msg(
        check_msg->amplitude_value[148] == 62,
        "incorrect value for amplitude_value[148], expected 62, is %d",
        check_msg->amplitude_value[148]);
    ck_assert_msg(
        check_msg->amplitude_value[149] == 117,
        "incorrect value for amplitude_value[149], expected 117, is %d",
        check_msg->amplitude_value[149]);
    ck_assert_msg(
        check_msg->amplitude_value[150] == 47,
        "incorrect value for amplitude_value[150], expected 47, is %d",
        check_msg->amplitude_value[150]);
    ck_assert_msg(
        check_msg->amplitude_value[151] == 143,
        "incorrect value for amplitude_value[151], expected 143, is %d",
        check_msg->amplitude_value[151]);
    ck_assert_msg(
        check_msg->amplitude_value[152] == 94,
        "incorrect value for amplitude_value[152], expected 94, is %d",
        check_msg->amplitude_value[152]);
    ck_assert_msg(
        check_msg->amplitude_value[153] == 135,
        "incorrect value for amplitude_value[153], expected 135, is %d",
        check_msg->amplitude_value[153]);
    ck_assert_msg(
        check_msg->amplitude_value[154] == 22,
        "incorrect value for amplitude_value[154], expected 22, is %d",
        check_msg->amplitude_value[154]);
    ck_assert_msg(
        check_msg->amplitude_value[155] == 155,
        "incorrect value for amplitude_value[155], expected 155, is %d",
        check_msg->amplitude_value[155]);
    ck_assert_msg(
        check_msg->amplitude_value[156] == 113,
        "incorrect value for amplitude_value[156], expected 113, is %d",
        check_msg->amplitude_value[156]);
    ck_assert_msg(
        check_msg->amplitude_value[157] == 110,
        "incorrect value for amplitude_value[157], expected 110, is %d",
        check_msg->amplitude_value[157]);
    ck_assert_msg(
        check_msg->amplitude_value[158] == 15,
        "incorrect value for amplitude_value[158], expected 15, is %d",
        check_msg->amplitude_value[158]);
    ck_assert_msg(
        check_msg->amplitude_value[159] == 243,
        "incorrect value for amplitude_value[159], expected 243, is %d",
        check_msg->amplitude_value[159]);
    ck_assert_msg(
        check_msg->amplitude_value[160] == 141,
        "incorrect value for amplitude_value[160], expected 141, is %d",
        check_msg->amplitude_value[160]);
    ck_assert_msg(
        check_msg->amplitude_value[161] == 227,
        "incorrect value for amplitude_value[161], expected 227, is %d",
        check_msg->amplitude_value[161]);
    ck_assert_msg(
        check_msg->amplitude_value[162] == 46,
        "incorrect value for amplitude_value[162], expected 46, is %d",
        check_msg->amplitude_value[162]);
    ck_assert_msg(
        check_msg->amplitude_value[163] == 143,
        "incorrect value for amplitude_value[163], expected 143, is %d",
        check_msg->amplitude_value[163]);
    ck_assert_msg(
        check_msg->amplitude_value[164] == 227,
        "incorrect value for amplitude_value[164], expected 227, is %d",
        check_msg->amplitude_value[164]);
    ck_assert_msg(
        check_msg->amplitude_value[165] == 209,
        "incorrect value for amplitude_value[165], expected 209, is %d",
        check_msg->amplitude_value[165]);
    ck_assert_msg(
        check_msg->amplitude_value[166] == 249,
        "incorrect value for amplitude_value[166], expected 249, is %d",
        check_msg->amplitude_value[166]);
    ck_assert_msg(check_msg->amplitude_value[167] == 2,
                  "incorrect value for amplitude_value[167], expected 2, is %d",
                  check_msg->amplitude_value[167]);
    ck_assert_msg(
        check_msg->amplitude_value[168] == 153,
        "incorrect value for amplitude_value[168], expected 153, is %d",
        check_msg->amplitude_value[168]);
    ck_assert_msg(
        check_msg->amplitude_value[169] == 168,
        "incorrect value for amplitude_value[169], expected 168, is %d",
        check_msg->amplitude_value[169]);
    ck_assert_msg(
        check_msg->amplitude_value[170] == 131,
        "incorrect value for amplitude_value[170], expected 131, is %d",
        check_msg->amplitude_value[170]);
    ck_assert_msg(
        check_msg->amplitude_value[171] == 249,
        "incorrect value for amplitude_value[171], expected 249, is %d",
        check_msg->amplitude_value[171]);
    ck_assert_msg(
        check_msg->amplitude_value[172] == 160,
        "incorrect value for amplitude_value[172], expected 160, is %d",
        check_msg->amplitude_value[172]);
    ck_assert_msg(
        check_msg->amplitude_value[173] == 88,
        "incorrect value for amplitude_value[173], expected 88, is %d",
        check_msg->amplitude_value[173]);
    ck_assert_msg(
        check_msg->amplitude_value[174] == 38,
        "incorrect value for amplitude_value[174], expected 38, is %d",
        check_msg->amplitude_value[174]);
    ck_assert_msg(
        check_msg->amplitude_value[175] == 117,
        "incorrect value for amplitude_value[175], expected 117, is %d",
        check_msg->amplitude_value[175]);
    ck_assert_msg(
        check_msg->amplitude_value[176] == 129,
        "incorrect value for amplitude_value[176], expected 129, is %d",
        check_msg->amplitude_value[176]);
    ck_assert_msg(
        check_msg->amplitude_value[177] == 57,
        "incorrect value for amplitude_value[177], expected 57, is %d",
        check_msg->amplitude_value[177]);
    ck_assert_msg(
        check_msg->amplitude_value[178] == 40,
        "incorrect value for amplitude_value[178], expected 40, is %d",
        check_msg->amplitude_value[178]);
    ck_assert_msg(
        check_msg->amplitude_value[179] == 109,
        "incorrect value for amplitude_value[179], expected 109, is %d",
        check_msg->amplitude_value[179]);
    ck_assert_msg(
        check_msg->amplitude_value[180] == 209,
        "incorrect value for amplitude_value[180], expected 209, is %d",
        check_msg->amplitude_value[180]);
    ck_assert_msg(
        check_msg->amplitude_value[181] == 177,
        "incorrect value for amplitude_value[181], expected 177, is %d",
        check_msg->amplitude_value[181]);
    ck_assert_msg(
        check_msg->amplitude_value[182] == 38,
        "incorrect value for amplitude_value[182], expected 38, is %d",
        check_msg->amplitude_value[182]);
    ck_assert_msg(
        check_msg->amplitude_value[183] == 47,
        "incorrect value for amplitude_value[183], expected 47, is %d",
        check_msg->amplitude_value[183]);
    ck_assert_msg(
        check_msg->amplitude_value[184] == 12,
        "incorrect value for amplitude_value[184], expected 12, is %d",
        check_msg->amplitude_value[184]);
    ck_assert_msg(
        check_msg->amplitude_value[185] == 15,
        "incorrect value for amplitude_value[185], expected 15, is %d",
        check_msg->amplitude_value[185]);
    ck_assert_msg(
        check_msg->amplitude_value[186] == 16,
        "incorrect value for amplitude_value[186], expected 16, is %d",
        check_msg->amplitude_value[186]);
    ck_assert_msg(check_msg->amplitude_value[187] == 9,
                  "incorrect value for amplitude_value[187], expected 9, is %d",
                  check_msg->amplitude_value[187]);
    ck_assert_msg(
        check_msg->amplitude_value[188] == 175,
        "incorrect value for amplitude_value[188], expected 175, is %d",
        check_msg->amplitude_value[188]);
    ck_assert_msg(
        check_msg->amplitude_value[189] == 69,
        "incorrect value for amplitude_value[189], expected 69, is %d",
        check_msg->amplitude_value[189]);
    ck_assert_msg(
        check_msg->amplitude_value[190] == 70,
        "incorrect value for amplitude_value[190], expected 70, is %d",
        check_msg->amplitude_value[190]);
    ck_assert_msg(
        check_msg->amplitude_value[191] == 182,
        "incorrect value for amplitude_value[191], expected 182, is %d",
        check_msg->amplitude_value[191]);
    ck_assert_msg(
        check_msg->amplitude_value[192] == 239,
        "incorrect value for amplitude_value[192], expected 239, is %d",
        check_msg->amplitude_value[192]);
    ck_assert_msg(
        check_msg->amplitude_value[193] == 117,
        "incorrect value for amplitude_value[193], expected 117, is %d",
        check_msg->amplitude_value[193]);
    ck_assert_msg(
        check_msg->amplitude_value[194] == 135,
        "incorrect value for amplitude_value[194], expected 135, is %d",
        check_msg->amplitude_value[194]);
    ck_assert_msg(check_msg->amplitude_value[195] == 6,
                  "incorrect value for amplitude_value[195], expected 6, is %d",
                  check_msg->amplitude_value[195]);
    ck_assert_msg(
        check_msg->amplitude_value[196] == 71,
        "incorrect value for amplitude_value[196], expected 71, is %d",
        check_msg->amplitude_value[196]);
    ck_assert_msg(
        check_msg->amplitude_value[197] == 99,
        "incorrect value for amplitude_value[197], expected 99, is %d",
        check_msg->amplitude_value[197]);
    ck_assert_msg(
        check_msg->amplitude_value[198] == 230,
        "incorrect value for amplitude_value[198], expected 230, is %d",
        check_msg->amplitude_value[198]);
    ck_assert_msg(
        check_msg->amplitude_value[199] == 115,
        "incorrect value for amplitude_value[199], expected 115, is %d",
        check_msg->amplitude_value[199]);
    ck_assert_msg(check_msg->amplitude_value[200] == 2,
                  "incorrect value for amplitude_value[200], expected 2, is %d",
                  check_msg->amplitude_value[200]);
    ck_assert_msg(
        check_msg->amplitude_value[201] == 71,
        "incorrect value for amplitude_value[201], expected 71, is %d",
        check_msg->amplitude_value[201]);
    ck_assert_msg(
        check_msg->amplitude_value[202] == 165,
        "incorrect value for amplitude_value[202], expected 165, is %d",
        check_msg->amplitude_value[202]);
    ck_assert_msg(
        check_msg->amplitude_value[203] == 228,
        "incorrect value for amplitude_value[203], expected 228, is %d",
        check_msg->amplitude_value[203]);
    ck_assert_msg(
        check_msg->amplitude_value[204] == 123,
        "incorrect value for amplitude_value[204], expected 123, is %d",
        check_msg->amplitude_value[204]);
    ck_assert_msg(
        check_msg->amplitude_value[205] == 210,
        "incorrect value for amplitude_value[205], expected 210, is %d",
        check_msg->amplitude_value[205]);
    ck_assert_msg(
        check_msg->amplitude_value[206] == 168,
        "incorrect value for amplitude_value[206], expected 168, is %d",
        check_msg->amplitude_value[206]);
    ck_assert_msg(
        check_msg->amplitude_value[207] == 90,
        "incorrect value for amplitude_value[207], expected 90, is %d",
        check_msg->amplitude_value[207]);
    ck_assert_msg(
        check_msg->amplitude_value[208] == 124,
        "incorrect value for amplitude_value[208], expected 124, is %d",
        check_msg->amplitude_value[208]);
    ck_assert_msg(
        check_msg->amplitude_value[209] == 20,
        "incorrect value for amplitude_value[209], expected 20, is %d",
        check_msg->amplitude_value[209]);
    ck_assert_msg(check_msg->amplitude_value[210] == 7,
                  "incorrect value for amplitude_value[210], expected 7, is %d",
                  check_msg->amplitude_value[210]);
    ck_assert_msg(
        check_msg->amplitude_value[211] == 220,
        "incorrect value for amplitude_value[211], expected 220, is %d",
        check_msg->amplitude_value[211]);
    ck_assert_msg(
        check_msg->amplitude_value[212] == 144,
        "incorrect value for amplitude_value[212], expected 144, is %d",
        check_msg->amplitude_value[212]);
    ck_assert_msg(
        check_msg->amplitude_value[213] == 168,
        "incorrect value for amplitude_value[213], expected 168, is %d",
        check_msg->amplitude_value[213]);
    ck_assert_msg(
        check_msg->amplitude_value[214] == 69,
        "incorrect value for amplitude_value[214], expected 69, is %d",
        check_msg->amplitude_value[214]);
    ck_assert_msg(
        check_msg->amplitude_value[215] == 22,
        "incorrect value for amplitude_value[215], expected 22, is %d",
        check_msg->amplitude_value[215]);
    ck_assert_msg(
        check_msg->amplitude_value[216] == 72,
        "incorrect value for amplitude_value[216], expected 72, is %d",
        check_msg->amplitude_value[216]);
    ck_assert_msg(
        check_msg->amplitude_value[217] == 162,
        "incorrect value for amplitude_value[217], expected 162, is %d",
        check_msg->amplitude_value[217]);
    ck_assert_msg(
        check_msg->amplitude_value[218] == 69,
        "incorrect value for amplitude_value[218], expected 69, is %d",
        check_msg->amplitude_value[218]);
    ck_assert_msg(
        check_msg->amplitude_value[219] == 111,
        "incorrect value for amplitude_value[219], expected 111, is %d",
        check_msg->amplitude_value[219]);
    ck_assert_msg(
        check_msg->amplitude_value[220] == 91,
        "incorrect value for amplitude_value[220], expected 91, is %d",
        check_msg->amplitude_value[220]);
    ck_assert_msg(
        check_msg->amplitude_value[221] == 251,
        "incorrect value for amplitude_value[221], expected 251, is %d",
        check_msg->amplitude_value[221]);
    ck_assert_msg(
        check_msg->amplitude_value[222] == 72,
        "incorrect value for amplitude_value[222], expected 72, is %d",
        check_msg->amplitude_value[222]);
    ck_assert_msg(
        check_msg->amplitude_value[223] == 220,
        "incorrect value for amplitude_value[223], expected 220, is %d",
        check_msg->amplitude_value[223]);
    ck_assert_msg(
        check_msg->amplitude_value[224] == 28,
        "incorrect value for amplitude_value[224], expected 28, is %d",
        check_msg->amplitude_value[224]);
    ck_assert_msg(
        check_msg->amplitude_value[225] == 119,
        "incorrect value for amplitude_value[225], expected 119, is %d",
        check_msg->amplitude_value[225]);
    ck_assert_msg(
        check_msg->amplitude_value[226] == 150,
        "incorrect value for amplitude_value[226], expected 150, is %d",
        check_msg->amplitude_value[226]);
    ck_assert_msg(check_msg->channel_tag == 35146,
                  "incorrect value for channel_tag, expected 35146, is %d",
                  check_msg->channel_tag);
    ck_assert_msg((check_msg->freq_ref * 100 - 7737.20019531 * 100) < 0.05,
                  "incorrect value for freq_ref, expected 7737.20019531, is %f",
                  check_msg->freq_ref);
    ck_assert_msg(
        (check_msg->freq_step * 100 - 8226.20019531 * 100) < 0.05,
        "incorrect value for freq_step, expected 8226.20019531, is %f",
        check_msg->freq_step);
    ck_assert_msg(
        check_msg->t.ns_residual == -1479025396,
        "incorrect value for t.ns_residual, expected -1479025396, is %d",
        check_msg->t.ns_residual);
    ck_assert_msg(check_msg->t.tow == 1227027783,
                  "incorrect value for t.tow, expected 1227027783, is %d",
                  check_msg->t.tow);
    ck_assert_msg(check_msg->t.wn == 5075,
                  "incorrect value for t.wn, expected 5075, is %d",
                  check_msg->t.wn);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_piksi_MsgSpecan_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_piksi_MsgSpecan");
  TCase *tc_acq =
      tcase_create("Automated_Suite_legacy_auto_check_sbp_piksi_MsgSpecan");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_piksi_MsgSpecan);
  suite_add_tcase(s, tc_acq);
  return s;
}