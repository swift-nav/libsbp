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
// spec/tests/yaml/swiftnav/sbp/user/test_MsgUserData.yaml by generate.py. Do
// not modify by hand!

#include <check.h>
#include <libsbp/legacy/user.h>
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

START_TEST(test_legacy_auto_check_sbp_user_MsgUserData) {
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

    sbp_payload_callback_register(&sbp_state, 0x800, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0x800, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  0,   8,   126, 33,  255, 53,  5,   172, 138, 50,  49,  206, 234,
        149, 204, 113, 31,  108, 188, 179, 154, 156, 167, 145, 139, 42,  207,
        126, 242, 193, 9,   58,  75,  8,   135, 11,  92,  131, 245, 24,  90,
        255, 30,  58,  31,  109, 148, 56,  178, 140, 30,  159, 70,  17,  170,
        50,  148, 1,   99,  112, 88,  217, 36,  84,  34,  234, 82,  144, 144,
        97,  96,  75,  174, 58,  219, 180, 148, 247, 59,  2,   116, 214, 114,
        55,  134, 54,  119, 108, 128, 73,  181, 20,  233, 23,  23,  73,  119,
        136, 231, 189, 26,  174, 128, 93,  30,  76,  45,  109, 134, 81,  0,
        116, 158, 127, 40,  133, 208, 134, 127, 140, 232, 183, 184, 108, 6,
        228, 54,  238, 59,  220, 30,  228, 212, 50,  182, 97,  20,  41,  76,
        227, 88,  12,  95,  112, 209, 183, 127, 4,   165, 189, 44,  239, 232,
        132, 9,   114, 184, 249, 208, 246, 194, 250, 2,   97,  173, 157, 202,
        172, 180, 150, 213, 193, 177, 209, 156, 20,  174, 18,  73,  132, 215,
        115, 128, 175, 169, 116, 132, 100, 72,  45,  25,  14,  205, 213, 145,
        68,  137, 249, 54,  40,  174, 215, 148, 166, 190, 63,  118, 6,   165,
        212, 74,  68,  200, 38,  139, 212, 112, 45,  167, 236, 255, 106, 92,
        132, 59,  61,  233, 3,   246, 158, 83,  134, 246, 154, 17,  0,   6,
        56,  216, 19,  216, 70,  71,  161, 184, 5,   177, 45,  37,  98,  56,
        149, 0,   73,  221, 105, 239, 168, 205, 85,  81,  245,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_user_data_t *test_msg = (msg_user_data_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[0] = 53;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[1] = 5;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[2] = 172;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[3] = 138;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[4] = 50;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[5] = 49;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[6] = 206;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[7] = 234;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[8] = 149;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[9] = 204;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[10] = 113;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[11] = 31;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[12] = 108;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[13] = 188;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[14] = 179;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[15] = 154;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[16] = 156;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[17] = 167;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[18] = 145;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[19] = 139;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[20] = 42;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[21] = 207;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[22] = 126;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[23] = 242;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[24] = 193;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[25] = 9;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[26] = 58;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[27] = 75;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[28] = 8;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[29] = 135;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[30] = 11;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[31] = 92;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[32] = 131;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[33] = 245;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[34] = 24;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[35] = 90;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[36] = 255;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[37] = 30;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[38] = 58;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[39] = 31;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[40] = 109;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[41] = 148;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[42] = 56;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[43] = 178;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[44] = 140;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[45] = 30;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[46] = 159;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[47] = 70;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[48] = 17;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[49] = 170;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[50] = 50;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[51] = 148;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[52] = 1;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[53] = 99;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[54] = 112;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[55] = 88;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[56] = 217;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[57] = 36;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[58] = 84;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[59] = 34;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[60] = 234;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[61] = 82;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[62] = 144;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[63] = 144;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[64] = 97;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[65] = 96;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[66] = 75;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[67] = 174;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[68] = 58;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[69] = 219;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[70] = 180;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[71] = 148;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[72] = 247;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[73] = 59;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[74] = 2;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[75] = 116;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[76] = 214;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[77] = 114;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[78] = 55;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[79] = 134;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[80] = 54;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[81] = 119;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[82] = 108;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[83] = 128;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[84] = 73;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[85] = 181;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[86] = 20;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[87] = 233;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[88] = 23;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[89] = 23;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[90] = 73;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[91] = 119;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[92] = 136;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[93] = 231;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[94] = 189;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[95] = 26;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[96] = 174;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[97] = 128;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[98] = 93;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[99] = 30;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[100] = 76;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[101] = 45;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[102] = 109;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[103] = 134;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[104] = 81;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[105] = 0;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[106] = 116;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[107] = 158;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[108] = 127;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[109] = 40;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[110] = 133;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[111] = 208;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[112] = 134;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[113] = 127;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[114] = 140;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[115] = 232;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[116] = 183;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[117] = 184;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[118] = 108;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[119] = 6;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[120] = 228;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[121] = 54;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[122] = 238;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[123] = 59;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[124] = 220;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[125] = 30;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[126] = 228;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[127] = 212;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[128] = 50;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[129] = 182;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[130] = 97;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[131] = 20;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[132] = 41;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[133] = 76;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[134] = 227;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[135] = 88;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[136] = 12;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[137] = 95;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[138] = 112;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[139] = 209;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[140] = 183;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[141] = 127;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[142] = 4;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[143] = 165;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[144] = 189;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[145] = 44;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[146] = 239;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[147] = 232;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[148] = 132;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[149] = 9;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[150] = 114;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[151] = 184;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[152] = 249;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[153] = 208;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[154] = 246;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[155] = 194;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[156] = 250;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[157] = 2;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[158] = 97;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[159] = 173;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[160] = 157;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[161] = 202;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[162] = 172;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[163] = 180;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[164] = 150;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[165] = 213;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[166] = 193;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[167] = 177;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[168] = 209;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[169] = 156;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[170] = 20;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[171] = 174;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[172] = 18;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[173] = 73;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[174] = 132;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[175] = 215;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[176] = 115;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[177] = 128;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[178] = 175;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[179] = 169;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[180] = 116;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[181] = 132;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[182] = 100;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[183] = 72;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[184] = 45;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[185] = 25;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[186] = 14;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[187] = 205;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[188] = 213;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[189] = 145;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[190] = 68;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[191] = 137;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[192] = 249;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[193] = 54;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[194] = 40;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[195] = 174;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[196] = 215;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[197] = 148;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[198] = 166;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[199] = 190;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[200] = 63;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[201] = 118;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[202] = 6;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[203] = 165;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[204] = 212;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[205] = 74;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[206] = 68;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[207] = 200;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[208] = 38;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[209] = 139;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[210] = 212;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[211] = 112;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[212] = 45;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[213] = 167;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[214] = 236;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[215] = 255;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[216] = 106;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[217] = 92;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[218] = 132;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[219] = 59;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[220] = 61;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[221] = 233;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[222] = 3;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[223] = 246;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[224] = 158;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[225] = 83;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[226] = 134;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[227] = 246;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[228] = 154;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[229] = 17;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[230] = 0;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[231] = 6;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[232] = 56;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[233] = 216;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[234] = 19;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[235] = 216;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[236] = 70;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[237] = 71;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[238] = 161;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[239] = 184;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[240] = 5;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[241] = 177;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[242] = 45;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[243] = 37;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[244] = 98;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[245] = 56;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[246] = 149;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[247] = 0;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[248] = 73;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[249] = 221;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[250] = 105;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[251] = 239;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[252] = 168;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[253] = 205;
    if (sizeof(test_msg->contents) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->contents[0]);
    }
    test_msg->contents[254] = 85;
    sbp_payload_send(&sbp_state, 0x800, 8574, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 8574,
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
    ck_assert_msg(last_frame.sender_id == 8574,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0x800,
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
    msg_user_data_t *check_msg = (msg_user_data_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->contents[0] == 53,
                  "incorrect value for contents[0], expected 53, is %d",
                  check_msg->contents[0]);
    ck_assert_msg(check_msg->contents[1] == 5,
                  "incorrect value for contents[1], expected 5, is %d",
                  check_msg->contents[1]);
    ck_assert_msg(check_msg->contents[2] == 172,
                  "incorrect value for contents[2], expected 172, is %d",
                  check_msg->contents[2]);
    ck_assert_msg(check_msg->contents[3] == 138,
                  "incorrect value for contents[3], expected 138, is %d",
                  check_msg->contents[3]);
    ck_assert_msg(check_msg->contents[4] == 50,
                  "incorrect value for contents[4], expected 50, is %d",
                  check_msg->contents[4]);
    ck_assert_msg(check_msg->contents[5] == 49,
                  "incorrect value for contents[5], expected 49, is %d",
                  check_msg->contents[5]);
    ck_assert_msg(check_msg->contents[6] == 206,
                  "incorrect value for contents[6], expected 206, is %d",
                  check_msg->contents[6]);
    ck_assert_msg(check_msg->contents[7] == 234,
                  "incorrect value for contents[7], expected 234, is %d",
                  check_msg->contents[7]);
    ck_assert_msg(check_msg->contents[8] == 149,
                  "incorrect value for contents[8], expected 149, is %d",
                  check_msg->contents[8]);
    ck_assert_msg(check_msg->contents[9] == 204,
                  "incorrect value for contents[9], expected 204, is %d",
                  check_msg->contents[9]);
    ck_assert_msg(check_msg->contents[10] == 113,
                  "incorrect value for contents[10], expected 113, is %d",
                  check_msg->contents[10]);
    ck_assert_msg(check_msg->contents[11] == 31,
                  "incorrect value for contents[11], expected 31, is %d",
                  check_msg->contents[11]);
    ck_assert_msg(check_msg->contents[12] == 108,
                  "incorrect value for contents[12], expected 108, is %d",
                  check_msg->contents[12]);
    ck_assert_msg(check_msg->contents[13] == 188,
                  "incorrect value for contents[13], expected 188, is %d",
                  check_msg->contents[13]);
    ck_assert_msg(check_msg->contents[14] == 179,
                  "incorrect value for contents[14], expected 179, is %d",
                  check_msg->contents[14]);
    ck_assert_msg(check_msg->contents[15] == 154,
                  "incorrect value for contents[15], expected 154, is %d",
                  check_msg->contents[15]);
    ck_assert_msg(check_msg->contents[16] == 156,
                  "incorrect value for contents[16], expected 156, is %d",
                  check_msg->contents[16]);
    ck_assert_msg(check_msg->contents[17] == 167,
                  "incorrect value for contents[17], expected 167, is %d",
                  check_msg->contents[17]);
    ck_assert_msg(check_msg->contents[18] == 145,
                  "incorrect value for contents[18], expected 145, is %d",
                  check_msg->contents[18]);
    ck_assert_msg(check_msg->contents[19] == 139,
                  "incorrect value for contents[19], expected 139, is %d",
                  check_msg->contents[19]);
    ck_assert_msg(check_msg->contents[20] == 42,
                  "incorrect value for contents[20], expected 42, is %d",
                  check_msg->contents[20]);
    ck_assert_msg(check_msg->contents[21] == 207,
                  "incorrect value for contents[21], expected 207, is %d",
                  check_msg->contents[21]);
    ck_assert_msg(check_msg->contents[22] == 126,
                  "incorrect value for contents[22], expected 126, is %d",
                  check_msg->contents[22]);
    ck_assert_msg(check_msg->contents[23] == 242,
                  "incorrect value for contents[23], expected 242, is %d",
                  check_msg->contents[23]);
    ck_assert_msg(check_msg->contents[24] == 193,
                  "incorrect value for contents[24], expected 193, is %d",
                  check_msg->contents[24]);
    ck_assert_msg(check_msg->contents[25] == 9,
                  "incorrect value for contents[25], expected 9, is %d",
                  check_msg->contents[25]);
    ck_assert_msg(check_msg->contents[26] == 58,
                  "incorrect value for contents[26], expected 58, is %d",
                  check_msg->contents[26]);
    ck_assert_msg(check_msg->contents[27] == 75,
                  "incorrect value for contents[27], expected 75, is %d",
                  check_msg->contents[27]);
    ck_assert_msg(check_msg->contents[28] == 8,
                  "incorrect value for contents[28], expected 8, is %d",
                  check_msg->contents[28]);
    ck_assert_msg(check_msg->contents[29] == 135,
                  "incorrect value for contents[29], expected 135, is %d",
                  check_msg->contents[29]);
    ck_assert_msg(check_msg->contents[30] == 11,
                  "incorrect value for contents[30], expected 11, is %d",
                  check_msg->contents[30]);
    ck_assert_msg(check_msg->contents[31] == 92,
                  "incorrect value for contents[31], expected 92, is %d",
                  check_msg->contents[31]);
    ck_assert_msg(check_msg->contents[32] == 131,
                  "incorrect value for contents[32], expected 131, is %d",
                  check_msg->contents[32]);
    ck_assert_msg(check_msg->contents[33] == 245,
                  "incorrect value for contents[33], expected 245, is %d",
                  check_msg->contents[33]);
    ck_assert_msg(check_msg->contents[34] == 24,
                  "incorrect value for contents[34], expected 24, is %d",
                  check_msg->contents[34]);
    ck_assert_msg(check_msg->contents[35] == 90,
                  "incorrect value for contents[35], expected 90, is %d",
                  check_msg->contents[35]);
    ck_assert_msg(check_msg->contents[36] == 255,
                  "incorrect value for contents[36], expected 255, is %d",
                  check_msg->contents[36]);
    ck_assert_msg(check_msg->contents[37] == 30,
                  "incorrect value for contents[37], expected 30, is %d",
                  check_msg->contents[37]);
    ck_assert_msg(check_msg->contents[38] == 58,
                  "incorrect value for contents[38], expected 58, is %d",
                  check_msg->contents[38]);
    ck_assert_msg(check_msg->contents[39] == 31,
                  "incorrect value for contents[39], expected 31, is %d",
                  check_msg->contents[39]);
    ck_assert_msg(check_msg->contents[40] == 109,
                  "incorrect value for contents[40], expected 109, is %d",
                  check_msg->contents[40]);
    ck_assert_msg(check_msg->contents[41] == 148,
                  "incorrect value for contents[41], expected 148, is %d",
                  check_msg->contents[41]);
    ck_assert_msg(check_msg->contents[42] == 56,
                  "incorrect value for contents[42], expected 56, is %d",
                  check_msg->contents[42]);
    ck_assert_msg(check_msg->contents[43] == 178,
                  "incorrect value for contents[43], expected 178, is %d",
                  check_msg->contents[43]);
    ck_assert_msg(check_msg->contents[44] == 140,
                  "incorrect value for contents[44], expected 140, is %d",
                  check_msg->contents[44]);
    ck_assert_msg(check_msg->contents[45] == 30,
                  "incorrect value for contents[45], expected 30, is %d",
                  check_msg->contents[45]);
    ck_assert_msg(check_msg->contents[46] == 159,
                  "incorrect value for contents[46], expected 159, is %d",
                  check_msg->contents[46]);
    ck_assert_msg(check_msg->contents[47] == 70,
                  "incorrect value for contents[47], expected 70, is %d",
                  check_msg->contents[47]);
    ck_assert_msg(check_msg->contents[48] == 17,
                  "incorrect value for contents[48], expected 17, is %d",
                  check_msg->contents[48]);
    ck_assert_msg(check_msg->contents[49] == 170,
                  "incorrect value for contents[49], expected 170, is %d",
                  check_msg->contents[49]);
    ck_assert_msg(check_msg->contents[50] == 50,
                  "incorrect value for contents[50], expected 50, is %d",
                  check_msg->contents[50]);
    ck_assert_msg(check_msg->contents[51] == 148,
                  "incorrect value for contents[51], expected 148, is %d",
                  check_msg->contents[51]);
    ck_assert_msg(check_msg->contents[52] == 1,
                  "incorrect value for contents[52], expected 1, is %d",
                  check_msg->contents[52]);
    ck_assert_msg(check_msg->contents[53] == 99,
                  "incorrect value for contents[53], expected 99, is %d",
                  check_msg->contents[53]);
    ck_assert_msg(check_msg->contents[54] == 112,
                  "incorrect value for contents[54], expected 112, is %d",
                  check_msg->contents[54]);
    ck_assert_msg(check_msg->contents[55] == 88,
                  "incorrect value for contents[55], expected 88, is %d",
                  check_msg->contents[55]);
    ck_assert_msg(check_msg->contents[56] == 217,
                  "incorrect value for contents[56], expected 217, is %d",
                  check_msg->contents[56]);
    ck_assert_msg(check_msg->contents[57] == 36,
                  "incorrect value for contents[57], expected 36, is %d",
                  check_msg->contents[57]);
    ck_assert_msg(check_msg->contents[58] == 84,
                  "incorrect value for contents[58], expected 84, is %d",
                  check_msg->contents[58]);
    ck_assert_msg(check_msg->contents[59] == 34,
                  "incorrect value for contents[59], expected 34, is %d",
                  check_msg->contents[59]);
    ck_assert_msg(check_msg->contents[60] == 234,
                  "incorrect value for contents[60], expected 234, is %d",
                  check_msg->contents[60]);
    ck_assert_msg(check_msg->contents[61] == 82,
                  "incorrect value for contents[61], expected 82, is %d",
                  check_msg->contents[61]);
    ck_assert_msg(check_msg->contents[62] == 144,
                  "incorrect value for contents[62], expected 144, is %d",
                  check_msg->contents[62]);
    ck_assert_msg(check_msg->contents[63] == 144,
                  "incorrect value for contents[63], expected 144, is %d",
                  check_msg->contents[63]);
    ck_assert_msg(check_msg->contents[64] == 97,
                  "incorrect value for contents[64], expected 97, is %d",
                  check_msg->contents[64]);
    ck_assert_msg(check_msg->contents[65] == 96,
                  "incorrect value for contents[65], expected 96, is %d",
                  check_msg->contents[65]);
    ck_assert_msg(check_msg->contents[66] == 75,
                  "incorrect value for contents[66], expected 75, is %d",
                  check_msg->contents[66]);
    ck_assert_msg(check_msg->contents[67] == 174,
                  "incorrect value for contents[67], expected 174, is %d",
                  check_msg->contents[67]);
    ck_assert_msg(check_msg->contents[68] == 58,
                  "incorrect value for contents[68], expected 58, is %d",
                  check_msg->contents[68]);
    ck_assert_msg(check_msg->contents[69] == 219,
                  "incorrect value for contents[69], expected 219, is %d",
                  check_msg->contents[69]);
    ck_assert_msg(check_msg->contents[70] == 180,
                  "incorrect value for contents[70], expected 180, is %d",
                  check_msg->contents[70]);
    ck_assert_msg(check_msg->contents[71] == 148,
                  "incorrect value for contents[71], expected 148, is %d",
                  check_msg->contents[71]);
    ck_assert_msg(check_msg->contents[72] == 247,
                  "incorrect value for contents[72], expected 247, is %d",
                  check_msg->contents[72]);
    ck_assert_msg(check_msg->contents[73] == 59,
                  "incorrect value for contents[73], expected 59, is %d",
                  check_msg->contents[73]);
    ck_assert_msg(check_msg->contents[74] == 2,
                  "incorrect value for contents[74], expected 2, is %d",
                  check_msg->contents[74]);
    ck_assert_msg(check_msg->contents[75] == 116,
                  "incorrect value for contents[75], expected 116, is %d",
                  check_msg->contents[75]);
    ck_assert_msg(check_msg->contents[76] == 214,
                  "incorrect value for contents[76], expected 214, is %d",
                  check_msg->contents[76]);
    ck_assert_msg(check_msg->contents[77] == 114,
                  "incorrect value for contents[77], expected 114, is %d",
                  check_msg->contents[77]);
    ck_assert_msg(check_msg->contents[78] == 55,
                  "incorrect value for contents[78], expected 55, is %d",
                  check_msg->contents[78]);
    ck_assert_msg(check_msg->contents[79] == 134,
                  "incorrect value for contents[79], expected 134, is %d",
                  check_msg->contents[79]);
    ck_assert_msg(check_msg->contents[80] == 54,
                  "incorrect value for contents[80], expected 54, is %d",
                  check_msg->contents[80]);
    ck_assert_msg(check_msg->contents[81] == 119,
                  "incorrect value for contents[81], expected 119, is %d",
                  check_msg->contents[81]);
    ck_assert_msg(check_msg->contents[82] == 108,
                  "incorrect value for contents[82], expected 108, is %d",
                  check_msg->contents[82]);
    ck_assert_msg(check_msg->contents[83] == 128,
                  "incorrect value for contents[83], expected 128, is %d",
                  check_msg->contents[83]);
    ck_assert_msg(check_msg->contents[84] == 73,
                  "incorrect value for contents[84], expected 73, is %d",
                  check_msg->contents[84]);
    ck_assert_msg(check_msg->contents[85] == 181,
                  "incorrect value for contents[85], expected 181, is %d",
                  check_msg->contents[85]);
    ck_assert_msg(check_msg->contents[86] == 20,
                  "incorrect value for contents[86], expected 20, is %d",
                  check_msg->contents[86]);
    ck_assert_msg(check_msg->contents[87] == 233,
                  "incorrect value for contents[87], expected 233, is %d",
                  check_msg->contents[87]);
    ck_assert_msg(check_msg->contents[88] == 23,
                  "incorrect value for contents[88], expected 23, is %d",
                  check_msg->contents[88]);
    ck_assert_msg(check_msg->contents[89] == 23,
                  "incorrect value for contents[89], expected 23, is %d",
                  check_msg->contents[89]);
    ck_assert_msg(check_msg->contents[90] == 73,
                  "incorrect value for contents[90], expected 73, is %d",
                  check_msg->contents[90]);
    ck_assert_msg(check_msg->contents[91] == 119,
                  "incorrect value for contents[91], expected 119, is %d",
                  check_msg->contents[91]);
    ck_assert_msg(check_msg->contents[92] == 136,
                  "incorrect value for contents[92], expected 136, is %d",
                  check_msg->contents[92]);
    ck_assert_msg(check_msg->contents[93] == 231,
                  "incorrect value for contents[93], expected 231, is %d",
                  check_msg->contents[93]);
    ck_assert_msg(check_msg->contents[94] == 189,
                  "incorrect value for contents[94], expected 189, is %d",
                  check_msg->contents[94]);
    ck_assert_msg(check_msg->contents[95] == 26,
                  "incorrect value for contents[95], expected 26, is %d",
                  check_msg->contents[95]);
    ck_assert_msg(check_msg->contents[96] == 174,
                  "incorrect value for contents[96], expected 174, is %d",
                  check_msg->contents[96]);
    ck_assert_msg(check_msg->contents[97] == 128,
                  "incorrect value for contents[97], expected 128, is %d",
                  check_msg->contents[97]);
    ck_assert_msg(check_msg->contents[98] == 93,
                  "incorrect value for contents[98], expected 93, is %d",
                  check_msg->contents[98]);
    ck_assert_msg(check_msg->contents[99] == 30,
                  "incorrect value for contents[99], expected 30, is %d",
                  check_msg->contents[99]);
    ck_assert_msg(check_msg->contents[100] == 76,
                  "incorrect value for contents[100], expected 76, is %d",
                  check_msg->contents[100]);
    ck_assert_msg(check_msg->contents[101] == 45,
                  "incorrect value for contents[101], expected 45, is %d",
                  check_msg->contents[101]);
    ck_assert_msg(check_msg->contents[102] == 109,
                  "incorrect value for contents[102], expected 109, is %d",
                  check_msg->contents[102]);
    ck_assert_msg(check_msg->contents[103] == 134,
                  "incorrect value for contents[103], expected 134, is %d",
                  check_msg->contents[103]);
    ck_assert_msg(check_msg->contents[104] == 81,
                  "incorrect value for contents[104], expected 81, is %d",
                  check_msg->contents[104]);
    ck_assert_msg(check_msg->contents[105] == 0,
                  "incorrect value for contents[105], expected 0, is %d",
                  check_msg->contents[105]);
    ck_assert_msg(check_msg->contents[106] == 116,
                  "incorrect value for contents[106], expected 116, is %d",
                  check_msg->contents[106]);
    ck_assert_msg(check_msg->contents[107] == 158,
                  "incorrect value for contents[107], expected 158, is %d",
                  check_msg->contents[107]);
    ck_assert_msg(check_msg->contents[108] == 127,
                  "incorrect value for contents[108], expected 127, is %d",
                  check_msg->contents[108]);
    ck_assert_msg(check_msg->contents[109] == 40,
                  "incorrect value for contents[109], expected 40, is %d",
                  check_msg->contents[109]);
    ck_assert_msg(check_msg->contents[110] == 133,
                  "incorrect value for contents[110], expected 133, is %d",
                  check_msg->contents[110]);
    ck_assert_msg(check_msg->contents[111] == 208,
                  "incorrect value for contents[111], expected 208, is %d",
                  check_msg->contents[111]);
    ck_assert_msg(check_msg->contents[112] == 134,
                  "incorrect value for contents[112], expected 134, is %d",
                  check_msg->contents[112]);
    ck_assert_msg(check_msg->contents[113] == 127,
                  "incorrect value for contents[113], expected 127, is %d",
                  check_msg->contents[113]);
    ck_assert_msg(check_msg->contents[114] == 140,
                  "incorrect value for contents[114], expected 140, is %d",
                  check_msg->contents[114]);
    ck_assert_msg(check_msg->contents[115] == 232,
                  "incorrect value for contents[115], expected 232, is %d",
                  check_msg->contents[115]);
    ck_assert_msg(check_msg->contents[116] == 183,
                  "incorrect value for contents[116], expected 183, is %d",
                  check_msg->contents[116]);
    ck_assert_msg(check_msg->contents[117] == 184,
                  "incorrect value for contents[117], expected 184, is %d",
                  check_msg->contents[117]);
    ck_assert_msg(check_msg->contents[118] == 108,
                  "incorrect value for contents[118], expected 108, is %d",
                  check_msg->contents[118]);
    ck_assert_msg(check_msg->contents[119] == 6,
                  "incorrect value for contents[119], expected 6, is %d",
                  check_msg->contents[119]);
    ck_assert_msg(check_msg->contents[120] == 228,
                  "incorrect value for contents[120], expected 228, is %d",
                  check_msg->contents[120]);
    ck_assert_msg(check_msg->contents[121] == 54,
                  "incorrect value for contents[121], expected 54, is %d",
                  check_msg->contents[121]);
    ck_assert_msg(check_msg->contents[122] == 238,
                  "incorrect value for contents[122], expected 238, is %d",
                  check_msg->contents[122]);
    ck_assert_msg(check_msg->contents[123] == 59,
                  "incorrect value for contents[123], expected 59, is %d",
                  check_msg->contents[123]);
    ck_assert_msg(check_msg->contents[124] == 220,
                  "incorrect value for contents[124], expected 220, is %d",
                  check_msg->contents[124]);
    ck_assert_msg(check_msg->contents[125] == 30,
                  "incorrect value for contents[125], expected 30, is %d",
                  check_msg->contents[125]);
    ck_assert_msg(check_msg->contents[126] == 228,
                  "incorrect value for contents[126], expected 228, is %d",
                  check_msg->contents[126]);
    ck_assert_msg(check_msg->contents[127] == 212,
                  "incorrect value for contents[127], expected 212, is %d",
                  check_msg->contents[127]);
    ck_assert_msg(check_msg->contents[128] == 50,
                  "incorrect value for contents[128], expected 50, is %d",
                  check_msg->contents[128]);
    ck_assert_msg(check_msg->contents[129] == 182,
                  "incorrect value for contents[129], expected 182, is %d",
                  check_msg->contents[129]);
    ck_assert_msg(check_msg->contents[130] == 97,
                  "incorrect value for contents[130], expected 97, is %d",
                  check_msg->contents[130]);
    ck_assert_msg(check_msg->contents[131] == 20,
                  "incorrect value for contents[131], expected 20, is %d",
                  check_msg->contents[131]);
    ck_assert_msg(check_msg->contents[132] == 41,
                  "incorrect value for contents[132], expected 41, is %d",
                  check_msg->contents[132]);
    ck_assert_msg(check_msg->contents[133] == 76,
                  "incorrect value for contents[133], expected 76, is %d",
                  check_msg->contents[133]);
    ck_assert_msg(check_msg->contents[134] == 227,
                  "incorrect value for contents[134], expected 227, is %d",
                  check_msg->contents[134]);
    ck_assert_msg(check_msg->contents[135] == 88,
                  "incorrect value for contents[135], expected 88, is %d",
                  check_msg->contents[135]);
    ck_assert_msg(check_msg->contents[136] == 12,
                  "incorrect value for contents[136], expected 12, is %d",
                  check_msg->contents[136]);
    ck_assert_msg(check_msg->contents[137] == 95,
                  "incorrect value for contents[137], expected 95, is %d",
                  check_msg->contents[137]);
    ck_assert_msg(check_msg->contents[138] == 112,
                  "incorrect value for contents[138], expected 112, is %d",
                  check_msg->contents[138]);
    ck_assert_msg(check_msg->contents[139] == 209,
                  "incorrect value for contents[139], expected 209, is %d",
                  check_msg->contents[139]);
    ck_assert_msg(check_msg->contents[140] == 183,
                  "incorrect value for contents[140], expected 183, is %d",
                  check_msg->contents[140]);
    ck_assert_msg(check_msg->contents[141] == 127,
                  "incorrect value for contents[141], expected 127, is %d",
                  check_msg->contents[141]);
    ck_assert_msg(check_msg->contents[142] == 4,
                  "incorrect value for contents[142], expected 4, is %d",
                  check_msg->contents[142]);
    ck_assert_msg(check_msg->contents[143] == 165,
                  "incorrect value for contents[143], expected 165, is %d",
                  check_msg->contents[143]);
    ck_assert_msg(check_msg->contents[144] == 189,
                  "incorrect value for contents[144], expected 189, is %d",
                  check_msg->contents[144]);
    ck_assert_msg(check_msg->contents[145] == 44,
                  "incorrect value for contents[145], expected 44, is %d",
                  check_msg->contents[145]);
    ck_assert_msg(check_msg->contents[146] == 239,
                  "incorrect value for contents[146], expected 239, is %d",
                  check_msg->contents[146]);
    ck_assert_msg(check_msg->contents[147] == 232,
                  "incorrect value for contents[147], expected 232, is %d",
                  check_msg->contents[147]);
    ck_assert_msg(check_msg->contents[148] == 132,
                  "incorrect value for contents[148], expected 132, is %d",
                  check_msg->contents[148]);
    ck_assert_msg(check_msg->contents[149] == 9,
                  "incorrect value for contents[149], expected 9, is %d",
                  check_msg->contents[149]);
    ck_assert_msg(check_msg->contents[150] == 114,
                  "incorrect value for contents[150], expected 114, is %d",
                  check_msg->contents[150]);
    ck_assert_msg(check_msg->contents[151] == 184,
                  "incorrect value for contents[151], expected 184, is %d",
                  check_msg->contents[151]);
    ck_assert_msg(check_msg->contents[152] == 249,
                  "incorrect value for contents[152], expected 249, is %d",
                  check_msg->contents[152]);
    ck_assert_msg(check_msg->contents[153] == 208,
                  "incorrect value for contents[153], expected 208, is %d",
                  check_msg->contents[153]);
    ck_assert_msg(check_msg->contents[154] == 246,
                  "incorrect value for contents[154], expected 246, is %d",
                  check_msg->contents[154]);
    ck_assert_msg(check_msg->contents[155] == 194,
                  "incorrect value for contents[155], expected 194, is %d",
                  check_msg->contents[155]);
    ck_assert_msg(check_msg->contents[156] == 250,
                  "incorrect value for contents[156], expected 250, is %d",
                  check_msg->contents[156]);
    ck_assert_msg(check_msg->contents[157] == 2,
                  "incorrect value for contents[157], expected 2, is %d",
                  check_msg->contents[157]);
    ck_assert_msg(check_msg->contents[158] == 97,
                  "incorrect value for contents[158], expected 97, is %d",
                  check_msg->contents[158]);
    ck_assert_msg(check_msg->contents[159] == 173,
                  "incorrect value for contents[159], expected 173, is %d",
                  check_msg->contents[159]);
    ck_assert_msg(check_msg->contents[160] == 157,
                  "incorrect value for contents[160], expected 157, is %d",
                  check_msg->contents[160]);
    ck_assert_msg(check_msg->contents[161] == 202,
                  "incorrect value for contents[161], expected 202, is %d",
                  check_msg->contents[161]);
    ck_assert_msg(check_msg->contents[162] == 172,
                  "incorrect value for contents[162], expected 172, is %d",
                  check_msg->contents[162]);
    ck_assert_msg(check_msg->contents[163] == 180,
                  "incorrect value for contents[163], expected 180, is %d",
                  check_msg->contents[163]);
    ck_assert_msg(check_msg->contents[164] == 150,
                  "incorrect value for contents[164], expected 150, is %d",
                  check_msg->contents[164]);
    ck_assert_msg(check_msg->contents[165] == 213,
                  "incorrect value for contents[165], expected 213, is %d",
                  check_msg->contents[165]);
    ck_assert_msg(check_msg->contents[166] == 193,
                  "incorrect value for contents[166], expected 193, is %d",
                  check_msg->contents[166]);
    ck_assert_msg(check_msg->contents[167] == 177,
                  "incorrect value for contents[167], expected 177, is %d",
                  check_msg->contents[167]);
    ck_assert_msg(check_msg->contents[168] == 209,
                  "incorrect value for contents[168], expected 209, is %d",
                  check_msg->contents[168]);
    ck_assert_msg(check_msg->contents[169] == 156,
                  "incorrect value for contents[169], expected 156, is %d",
                  check_msg->contents[169]);
    ck_assert_msg(check_msg->contents[170] == 20,
                  "incorrect value for contents[170], expected 20, is %d",
                  check_msg->contents[170]);
    ck_assert_msg(check_msg->contents[171] == 174,
                  "incorrect value for contents[171], expected 174, is %d",
                  check_msg->contents[171]);
    ck_assert_msg(check_msg->contents[172] == 18,
                  "incorrect value for contents[172], expected 18, is %d",
                  check_msg->contents[172]);
    ck_assert_msg(check_msg->contents[173] == 73,
                  "incorrect value for contents[173], expected 73, is %d",
                  check_msg->contents[173]);
    ck_assert_msg(check_msg->contents[174] == 132,
                  "incorrect value for contents[174], expected 132, is %d",
                  check_msg->contents[174]);
    ck_assert_msg(check_msg->contents[175] == 215,
                  "incorrect value for contents[175], expected 215, is %d",
                  check_msg->contents[175]);
    ck_assert_msg(check_msg->contents[176] == 115,
                  "incorrect value for contents[176], expected 115, is %d",
                  check_msg->contents[176]);
    ck_assert_msg(check_msg->contents[177] == 128,
                  "incorrect value for contents[177], expected 128, is %d",
                  check_msg->contents[177]);
    ck_assert_msg(check_msg->contents[178] == 175,
                  "incorrect value for contents[178], expected 175, is %d",
                  check_msg->contents[178]);
    ck_assert_msg(check_msg->contents[179] == 169,
                  "incorrect value for contents[179], expected 169, is %d",
                  check_msg->contents[179]);
    ck_assert_msg(check_msg->contents[180] == 116,
                  "incorrect value for contents[180], expected 116, is %d",
                  check_msg->contents[180]);
    ck_assert_msg(check_msg->contents[181] == 132,
                  "incorrect value for contents[181], expected 132, is %d",
                  check_msg->contents[181]);
    ck_assert_msg(check_msg->contents[182] == 100,
                  "incorrect value for contents[182], expected 100, is %d",
                  check_msg->contents[182]);
    ck_assert_msg(check_msg->contents[183] == 72,
                  "incorrect value for contents[183], expected 72, is %d",
                  check_msg->contents[183]);
    ck_assert_msg(check_msg->contents[184] == 45,
                  "incorrect value for contents[184], expected 45, is %d",
                  check_msg->contents[184]);
    ck_assert_msg(check_msg->contents[185] == 25,
                  "incorrect value for contents[185], expected 25, is %d",
                  check_msg->contents[185]);
    ck_assert_msg(check_msg->contents[186] == 14,
                  "incorrect value for contents[186], expected 14, is %d",
                  check_msg->contents[186]);
    ck_assert_msg(check_msg->contents[187] == 205,
                  "incorrect value for contents[187], expected 205, is %d",
                  check_msg->contents[187]);
    ck_assert_msg(check_msg->contents[188] == 213,
                  "incorrect value for contents[188], expected 213, is %d",
                  check_msg->contents[188]);
    ck_assert_msg(check_msg->contents[189] == 145,
                  "incorrect value for contents[189], expected 145, is %d",
                  check_msg->contents[189]);
    ck_assert_msg(check_msg->contents[190] == 68,
                  "incorrect value for contents[190], expected 68, is %d",
                  check_msg->contents[190]);
    ck_assert_msg(check_msg->contents[191] == 137,
                  "incorrect value for contents[191], expected 137, is %d",
                  check_msg->contents[191]);
    ck_assert_msg(check_msg->contents[192] == 249,
                  "incorrect value for contents[192], expected 249, is %d",
                  check_msg->contents[192]);
    ck_assert_msg(check_msg->contents[193] == 54,
                  "incorrect value for contents[193], expected 54, is %d",
                  check_msg->contents[193]);
    ck_assert_msg(check_msg->contents[194] == 40,
                  "incorrect value for contents[194], expected 40, is %d",
                  check_msg->contents[194]);
    ck_assert_msg(check_msg->contents[195] == 174,
                  "incorrect value for contents[195], expected 174, is %d",
                  check_msg->contents[195]);
    ck_assert_msg(check_msg->contents[196] == 215,
                  "incorrect value for contents[196], expected 215, is %d",
                  check_msg->contents[196]);
    ck_assert_msg(check_msg->contents[197] == 148,
                  "incorrect value for contents[197], expected 148, is %d",
                  check_msg->contents[197]);
    ck_assert_msg(check_msg->contents[198] == 166,
                  "incorrect value for contents[198], expected 166, is %d",
                  check_msg->contents[198]);
    ck_assert_msg(check_msg->contents[199] == 190,
                  "incorrect value for contents[199], expected 190, is %d",
                  check_msg->contents[199]);
    ck_assert_msg(check_msg->contents[200] == 63,
                  "incorrect value for contents[200], expected 63, is %d",
                  check_msg->contents[200]);
    ck_assert_msg(check_msg->contents[201] == 118,
                  "incorrect value for contents[201], expected 118, is %d",
                  check_msg->contents[201]);
    ck_assert_msg(check_msg->contents[202] == 6,
                  "incorrect value for contents[202], expected 6, is %d",
                  check_msg->contents[202]);
    ck_assert_msg(check_msg->contents[203] == 165,
                  "incorrect value for contents[203], expected 165, is %d",
                  check_msg->contents[203]);
    ck_assert_msg(check_msg->contents[204] == 212,
                  "incorrect value for contents[204], expected 212, is %d",
                  check_msg->contents[204]);
    ck_assert_msg(check_msg->contents[205] == 74,
                  "incorrect value for contents[205], expected 74, is %d",
                  check_msg->contents[205]);
    ck_assert_msg(check_msg->contents[206] == 68,
                  "incorrect value for contents[206], expected 68, is %d",
                  check_msg->contents[206]);
    ck_assert_msg(check_msg->contents[207] == 200,
                  "incorrect value for contents[207], expected 200, is %d",
                  check_msg->contents[207]);
    ck_assert_msg(check_msg->contents[208] == 38,
                  "incorrect value for contents[208], expected 38, is %d",
                  check_msg->contents[208]);
    ck_assert_msg(check_msg->contents[209] == 139,
                  "incorrect value for contents[209], expected 139, is %d",
                  check_msg->contents[209]);
    ck_assert_msg(check_msg->contents[210] == 212,
                  "incorrect value for contents[210], expected 212, is %d",
                  check_msg->contents[210]);
    ck_assert_msg(check_msg->contents[211] == 112,
                  "incorrect value for contents[211], expected 112, is %d",
                  check_msg->contents[211]);
    ck_assert_msg(check_msg->contents[212] == 45,
                  "incorrect value for contents[212], expected 45, is %d",
                  check_msg->contents[212]);
    ck_assert_msg(check_msg->contents[213] == 167,
                  "incorrect value for contents[213], expected 167, is %d",
                  check_msg->contents[213]);
    ck_assert_msg(check_msg->contents[214] == 236,
                  "incorrect value for contents[214], expected 236, is %d",
                  check_msg->contents[214]);
    ck_assert_msg(check_msg->contents[215] == 255,
                  "incorrect value for contents[215], expected 255, is %d",
                  check_msg->contents[215]);
    ck_assert_msg(check_msg->contents[216] == 106,
                  "incorrect value for contents[216], expected 106, is %d",
                  check_msg->contents[216]);
    ck_assert_msg(check_msg->contents[217] == 92,
                  "incorrect value for contents[217], expected 92, is %d",
                  check_msg->contents[217]);
    ck_assert_msg(check_msg->contents[218] == 132,
                  "incorrect value for contents[218], expected 132, is %d",
                  check_msg->contents[218]);
    ck_assert_msg(check_msg->contents[219] == 59,
                  "incorrect value for contents[219], expected 59, is %d",
                  check_msg->contents[219]);
    ck_assert_msg(check_msg->contents[220] == 61,
                  "incorrect value for contents[220], expected 61, is %d",
                  check_msg->contents[220]);
    ck_assert_msg(check_msg->contents[221] == 233,
                  "incorrect value for contents[221], expected 233, is %d",
                  check_msg->contents[221]);
    ck_assert_msg(check_msg->contents[222] == 3,
                  "incorrect value for contents[222], expected 3, is %d",
                  check_msg->contents[222]);
    ck_assert_msg(check_msg->contents[223] == 246,
                  "incorrect value for contents[223], expected 246, is %d",
                  check_msg->contents[223]);
    ck_assert_msg(check_msg->contents[224] == 158,
                  "incorrect value for contents[224], expected 158, is %d",
                  check_msg->contents[224]);
    ck_assert_msg(check_msg->contents[225] == 83,
                  "incorrect value for contents[225], expected 83, is %d",
                  check_msg->contents[225]);
    ck_assert_msg(check_msg->contents[226] == 134,
                  "incorrect value for contents[226], expected 134, is %d",
                  check_msg->contents[226]);
    ck_assert_msg(check_msg->contents[227] == 246,
                  "incorrect value for contents[227], expected 246, is %d",
                  check_msg->contents[227]);
    ck_assert_msg(check_msg->contents[228] == 154,
                  "incorrect value for contents[228], expected 154, is %d",
                  check_msg->contents[228]);
    ck_assert_msg(check_msg->contents[229] == 17,
                  "incorrect value for contents[229], expected 17, is %d",
                  check_msg->contents[229]);
    ck_assert_msg(check_msg->contents[230] == 0,
                  "incorrect value for contents[230], expected 0, is %d",
                  check_msg->contents[230]);
    ck_assert_msg(check_msg->contents[231] == 6,
                  "incorrect value for contents[231], expected 6, is %d",
                  check_msg->contents[231]);
    ck_assert_msg(check_msg->contents[232] == 56,
                  "incorrect value for contents[232], expected 56, is %d",
                  check_msg->contents[232]);
    ck_assert_msg(check_msg->contents[233] == 216,
                  "incorrect value for contents[233], expected 216, is %d",
                  check_msg->contents[233]);
    ck_assert_msg(check_msg->contents[234] == 19,
                  "incorrect value for contents[234], expected 19, is %d",
                  check_msg->contents[234]);
    ck_assert_msg(check_msg->contents[235] == 216,
                  "incorrect value for contents[235], expected 216, is %d",
                  check_msg->contents[235]);
    ck_assert_msg(check_msg->contents[236] == 70,
                  "incorrect value for contents[236], expected 70, is %d",
                  check_msg->contents[236]);
    ck_assert_msg(check_msg->contents[237] == 71,
                  "incorrect value for contents[237], expected 71, is %d",
                  check_msg->contents[237]);
    ck_assert_msg(check_msg->contents[238] == 161,
                  "incorrect value for contents[238], expected 161, is %d",
                  check_msg->contents[238]);
    ck_assert_msg(check_msg->contents[239] == 184,
                  "incorrect value for contents[239], expected 184, is %d",
                  check_msg->contents[239]);
    ck_assert_msg(check_msg->contents[240] == 5,
                  "incorrect value for contents[240], expected 5, is %d",
                  check_msg->contents[240]);
    ck_assert_msg(check_msg->contents[241] == 177,
                  "incorrect value for contents[241], expected 177, is %d",
                  check_msg->contents[241]);
    ck_assert_msg(check_msg->contents[242] == 45,
                  "incorrect value for contents[242], expected 45, is %d",
                  check_msg->contents[242]);
    ck_assert_msg(check_msg->contents[243] == 37,
                  "incorrect value for contents[243], expected 37, is %d",
                  check_msg->contents[243]);
    ck_assert_msg(check_msg->contents[244] == 98,
                  "incorrect value for contents[244], expected 98, is %d",
                  check_msg->contents[244]);
    ck_assert_msg(check_msg->contents[245] == 56,
                  "incorrect value for contents[245], expected 56, is %d",
                  check_msg->contents[245]);
    ck_assert_msg(check_msg->contents[246] == 149,
                  "incorrect value for contents[246], expected 149, is %d",
                  check_msg->contents[246]);
    ck_assert_msg(check_msg->contents[247] == 0,
                  "incorrect value for contents[247], expected 0, is %d",
                  check_msg->contents[247]);
    ck_assert_msg(check_msg->contents[248] == 73,
                  "incorrect value for contents[248], expected 73, is %d",
                  check_msg->contents[248]);
    ck_assert_msg(check_msg->contents[249] == 221,
                  "incorrect value for contents[249], expected 221, is %d",
                  check_msg->contents[249]);
    ck_assert_msg(check_msg->contents[250] == 105,
                  "incorrect value for contents[250], expected 105, is %d",
                  check_msg->contents[250]);
    ck_assert_msg(check_msg->contents[251] == 239,
                  "incorrect value for contents[251], expected 239, is %d",
                  check_msg->contents[251]);
    ck_assert_msg(check_msg->contents[252] == 168,
                  "incorrect value for contents[252], expected 168, is %d",
                  check_msg->contents[252]);
    ck_assert_msg(check_msg->contents[253] == 205,
                  "incorrect value for contents[253], expected 205, is %d",
                  check_msg->contents[253]);
    ck_assert_msg(check_msg->contents[254] == 85,
                  "incorrect value for contents[254], expected 85, is %d",
                  check_msg->contents[254]);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_user_MsgUserData_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: legacy_auto_check_sbp_user_MsgUserData");
  TCase *tc_acq =
      tcase_create("Automated_Suite_legacy_auto_check_sbp_user_MsgUserData");
  tcase_add_test(tc_acq, test_legacy_auto_check_sbp_user_MsgUserData);
  suite_add_tcase(s, tc_acq);
  return s;
}