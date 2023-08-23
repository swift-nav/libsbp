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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaCertificate.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/api.h>
#include <libsbp/legacy/signing.h>
#include <libsbp/sbp.h>
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

START_TEST(test_legacy_auto_check_sbp_signing_MsgEcdsaCertificate) {
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

    sbp_payload_callback_register(&sbp_state, 0xC04, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0xC04, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  4,   12,  66,  0,   253, 48,  10,  11,  12,  13,  2,   180, 160,
        116, 77,  243, 28,  173, 36,  86,  33,  8,   31,  120, 73,  64,  169,
        148, 224, 57,  95,  17,  40,  213, 92,  195, 146, 235, 228, 177, 101,
        82,  182, 25,  172, 170, 250, 236, 7,   119, 4,   201, 10,  14,  208,
        47,  126, 49,  210, 174, 75,  221, 203, 24,  66,  52,  35,  26,  30,
        140, 111, 246, 39,  226, 205, 198, 178, 196, 5,   81,  9,   44,  164,
        163, 214, 138, 123, 76,  74,  237, 121, 13,  137, 186, 97,  193, 189,
        200, 124, 69,  115, 230, 159, 185, 158, 51,  12,  225, 65,  192, 105,
        56,  41,  85,  133, 19,  217, 166, 48,  139, 131, 96,  216, 98,  147,
        132, 234, 167, 248, 247, 32,  239, 194, 188, 254, 114, 117, 83,  25,
        251, 191, 104, 240, 118, 68,  42,  93,  18,  16,  37,  232, 99,  179,
        23,  90,  94,  136, 6,   125, 91,  255, 15,  71,  43,  46,  25,  252,
        229, 80,  143, 58,  241, 11,  62,  181, 155, 53,  153, 149, 152, 227,
        150, 87,  112, 165, 2,   128, 231, 25,  157, 244, 204, 108, 253, 127,
        122, 145, 113, 162, 197, 171, 199, 54,  184, 222, 206, 67,  144, 78,
        187, 207, 60,  211, 141, 135, 106, 220, 79,  183, 245, 21,  161, 168,
        34,  129, 50,  176, 1,   218, 20,  130, 59,  249, 109, 219, 0,   100,
        103, 55,  29,  242, 110, 154, 190, 233, 142, 45,  61,  215, 202, 238,
        88,  209, 70,  63,  151, 27,  102, 219, 30,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ecdsa_certificate_t *test_msg =
        (msg_ecdsa_certificate_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[0] = 180;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[1] = 160;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[2] = 116;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[3] = 77;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[4] = 243;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[5] = 28;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[6] = 173;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[7] = 36;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[8] = 86;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[9] = 33;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[10] = 8;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[11] = 31;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[12] = 120;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[13] = 73;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[14] = 64;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[15] = 169;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[16] = 148;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[17] = 224;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[18] = 57;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[19] = 95;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[20] = 17;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[21] = 40;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[22] = 213;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[23] = 92;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[24] = 195;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[25] = 146;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[26] = 235;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[27] = 228;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[28] = 177;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[29] = 101;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[30] = 82;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[31] = 182;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[32] = 25;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[33] = 172;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[34] = 170;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[35] = 250;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[36] = 236;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[37] = 7;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[38] = 119;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[39] = 4;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[40] = 201;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[41] = 10;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[42] = 14;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[43] = 208;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[44] = 47;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[45] = 126;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[46] = 49;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[47] = 210;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[48] = 174;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[49] = 75;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[50] = 221;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[51] = 203;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[52] = 24;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[53] = 66;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[54] = 52;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[55] = 35;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[56] = 26;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[57] = 30;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[58] = 140;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[59] = 111;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[60] = 246;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[61] = 39;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[62] = 226;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[63] = 205;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[64] = 198;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[65] = 178;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[66] = 196;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[67] = 5;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[68] = 81;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[69] = 9;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[70] = 44;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[71] = 164;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[72] = 163;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[73] = 214;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[74] = 138;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[75] = 123;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[76] = 76;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[77] = 74;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[78] = 237;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[79] = 121;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[80] = 13;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[81] = 137;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[82] = 186;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[83] = 97;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[84] = 193;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[85] = 189;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[86] = 200;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[87] = 124;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[88] = 69;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[89] = 115;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[90] = 230;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[91] = 159;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[92] = 185;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[93] = 158;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[94] = 51;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[95] = 12;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[96] = 225;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[97] = 65;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[98] = 192;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[99] = 105;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[100] = 56;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[101] = 41;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[102] = 85;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[103] = 133;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[104] = 19;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[105] = 217;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[106] = 166;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[107] = 48;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[108] = 139;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[109] = 131;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[110] = 96;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[111] = 216;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[112] = 98;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[113] = 147;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[114] = 132;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[115] = 234;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[116] = 167;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[117] = 248;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[118] = 247;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[119] = 32;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[120] = 239;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[121] = 194;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[122] = 188;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[123] = 254;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[124] = 114;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[125] = 117;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[126] = 83;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[127] = 25;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[128] = 251;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[129] = 191;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[130] = 104;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[131] = 240;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[132] = 118;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[133] = 68;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[134] = 42;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[135] = 93;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[136] = 18;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[137] = 16;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[138] = 37;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[139] = 232;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[140] = 99;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[141] = 179;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[142] = 23;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[143] = 90;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[144] = 94;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[145] = 136;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[146] = 6;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[147] = 125;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[148] = 91;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[149] = 255;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[150] = 15;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[151] = 71;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[152] = 43;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[153] = 46;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[154] = 25;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[155] = 252;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[156] = 229;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[157] = 80;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[158] = 143;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[159] = 58;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[160] = 241;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[161] = 11;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[162] = 62;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[163] = 181;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[164] = 155;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[165] = 53;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[166] = 153;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[167] = 149;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[168] = 152;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[169] = 227;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[170] = 150;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[171] = 87;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[172] = 112;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[173] = 165;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[174] = 2;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[175] = 128;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[176] = 231;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[177] = 25;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[178] = 157;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[179] = 244;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[180] = 204;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[181] = 108;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[182] = 253;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[183] = 127;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[184] = 122;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[185] = 145;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[186] = 113;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[187] = 162;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[188] = 197;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[189] = 171;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[190] = 199;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[191] = 54;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[192] = 184;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[193] = 222;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[194] = 206;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[195] = 67;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[196] = 144;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[197] = 78;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[198] = 187;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[199] = 207;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[200] = 60;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[201] = 211;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[202] = 141;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[203] = 135;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[204] = 106;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[205] = 220;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[206] = 79;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[207] = 183;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[208] = 245;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[209] = 21;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[210] = 161;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[211] = 168;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[212] = 34;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[213] = 129;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[214] = 50;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[215] = 176;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[216] = 1;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[217] = 218;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[218] = 20;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[219] = 130;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[220] = 59;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[221] = 249;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[222] = 109;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[223] = 219;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[224] = 0;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[225] = 100;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[226] = 103;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[227] = 55;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[228] = 29;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[229] = 242;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[230] = 110;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[231] = 154;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[232] = 190;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[233] = 233;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[234] = 142;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[235] = 45;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[236] = 61;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[237] = 215;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[238] = 202;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[239] = 238;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[240] = 88;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[241] = 209;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[242] = 70;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[243] = 63;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[244] = 151;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[245] = 27;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[246] = 102;
    if (sizeof(test_msg->certificate_id) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_id[0]);
    }
    test_msg->certificate_id[0] = 10;
    if (sizeof(test_msg->certificate_id) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_id[0]);
    }
    test_msg->certificate_id[1] = 11;
    if (sizeof(test_msg->certificate_id) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_id[0]);
    }
    test_msg->certificate_id[2] = 12;
    if (sizeof(test_msg->certificate_id) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_id[0]);
    }
    test_msg->certificate_id[3] = 13;
    test_msg->flags = 2;
    test_msg->n_msg = 48;
    sbp_payload_send(&sbp_state, 0xC04, 66, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 66,
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
    ck_assert_msg(last_frame.sender_id == 66,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xC04,
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
    msg_ecdsa_certificate_t *check_msg =
        (msg_ecdsa_certificate_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        check_msg->certificate_bytes[0] == 180,
        "incorrect value for certificate_bytes[0], expected 180, is %d",
        check_msg->certificate_bytes[0]);
    ck_assert_msg(
        check_msg->certificate_bytes[1] == 160,
        "incorrect value for certificate_bytes[1], expected 160, is %d",
        check_msg->certificate_bytes[1]);
    ck_assert_msg(
        check_msg->certificate_bytes[2] == 116,
        "incorrect value for certificate_bytes[2], expected 116, is %d",
        check_msg->certificate_bytes[2]);
    ck_assert_msg(
        check_msg->certificate_bytes[3] == 77,
        "incorrect value for certificate_bytes[3], expected 77, is %d",
        check_msg->certificate_bytes[3]);
    ck_assert_msg(
        check_msg->certificate_bytes[4] == 243,
        "incorrect value for certificate_bytes[4], expected 243, is %d",
        check_msg->certificate_bytes[4]);
    ck_assert_msg(
        check_msg->certificate_bytes[5] == 28,
        "incorrect value for certificate_bytes[5], expected 28, is %d",
        check_msg->certificate_bytes[5]);
    ck_assert_msg(
        check_msg->certificate_bytes[6] == 173,
        "incorrect value for certificate_bytes[6], expected 173, is %d",
        check_msg->certificate_bytes[6]);
    ck_assert_msg(
        check_msg->certificate_bytes[7] == 36,
        "incorrect value for certificate_bytes[7], expected 36, is %d",
        check_msg->certificate_bytes[7]);
    ck_assert_msg(
        check_msg->certificate_bytes[8] == 86,
        "incorrect value for certificate_bytes[8], expected 86, is %d",
        check_msg->certificate_bytes[8]);
    ck_assert_msg(
        check_msg->certificate_bytes[9] == 33,
        "incorrect value for certificate_bytes[9], expected 33, is %d",
        check_msg->certificate_bytes[9]);
    ck_assert_msg(
        check_msg->certificate_bytes[10] == 8,
        "incorrect value for certificate_bytes[10], expected 8, is %d",
        check_msg->certificate_bytes[10]);
    ck_assert_msg(
        check_msg->certificate_bytes[11] == 31,
        "incorrect value for certificate_bytes[11], expected 31, is %d",
        check_msg->certificate_bytes[11]);
    ck_assert_msg(
        check_msg->certificate_bytes[12] == 120,
        "incorrect value for certificate_bytes[12], expected 120, is %d",
        check_msg->certificate_bytes[12]);
    ck_assert_msg(
        check_msg->certificate_bytes[13] == 73,
        "incorrect value for certificate_bytes[13], expected 73, is %d",
        check_msg->certificate_bytes[13]);
    ck_assert_msg(
        check_msg->certificate_bytes[14] == 64,
        "incorrect value for certificate_bytes[14], expected 64, is %d",
        check_msg->certificate_bytes[14]);
    ck_assert_msg(
        check_msg->certificate_bytes[15] == 169,
        "incorrect value for certificate_bytes[15], expected 169, is %d",
        check_msg->certificate_bytes[15]);
    ck_assert_msg(
        check_msg->certificate_bytes[16] == 148,
        "incorrect value for certificate_bytes[16], expected 148, is %d",
        check_msg->certificate_bytes[16]);
    ck_assert_msg(
        check_msg->certificate_bytes[17] == 224,
        "incorrect value for certificate_bytes[17], expected 224, is %d",
        check_msg->certificate_bytes[17]);
    ck_assert_msg(
        check_msg->certificate_bytes[18] == 57,
        "incorrect value for certificate_bytes[18], expected 57, is %d",
        check_msg->certificate_bytes[18]);
    ck_assert_msg(
        check_msg->certificate_bytes[19] == 95,
        "incorrect value for certificate_bytes[19], expected 95, is %d",
        check_msg->certificate_bytes[19]);
    ck_assert_msg(
        check_msg->certificate_bytes[20] == 17,
        "incorrect value for certificate_bytes[20], expected 17, is %d",
        check_msg->certificate_bytes[20]);
    ck_assert_msg(
        check_msg->certificate_bytes[21] == 40,
        "incorrect value for certificate_bytes[21], expected 40, is %d",
        check_msg->certificate_bytes[21]);
    ck_assert_msg(
        check_msg->certificate_bytes[22] == 213,
        "incorrect value for certificate_bytes[22], expected 213, is %d",
        check_msg->certificate_bytes[22]);
    ck_assert_msg(
        check_msg->certificate_bytes[23] == 92,
        "incorrect value for certificate_bytes[23], expected 92, is %d",
        check_msg->certificate_bytes[23]);
    ck_assert_msg(
        check_msg->certificate_bytes[24] == 195,
        "incorrect value for certificate_bytes[24], expected 195, is %d",
        check_msg->certificate_bytes[24]);
    ck_assert_msg(
        check_msg->certificate_bytes[25] == 146,
        "incorrect value for certificate_bytes[25], expected 146, is %d",
        check_msg->certificate_bytes[25]);
    ck_assert_msg(
        check_msg->certificate_bytes[26] == 235,
        "incorrect value for certificate_bytes[26], expected 235, is %d",
        check_msg->certificate_bytes[26]);
    ck_assert_msg(
        check_msg->certificate_bytes[27] == 228,
        "incorrect value for certificate_bytes[27], expected 228, is %d",
        check_msg->certificate_bytes[27]);
    ck_assert_msg(
        check_msg->certificate_bytes[28] == 177,
        "incorrect value for certificate_bytes[28], expected 177, is %d",
        check_msg->certificate_bytes[28]);
    ck_assert_msg(
        check_msg->certificate_bytes[29] == 101,
        "incorrect value for certificate_bytes[29], expected 101, is %d",
        check_msg->certificate_bytes[29]);
    ck_assert_msg(
        check_msg->certificate_bytes[30] == 82,
        "incorrect value for certificate_bytes[30], expected 82, is %d",
        check_msg->certificate_bytes[30]);
    ck_assert_msg(
        check_msg->certificate_bytes[31] == 182,
        "incorrect value for certificate_bytes[31], expected 182, is %d",
        check_msg->certificate_bytes[31]);
    ck_assert_msg(
        check_msg->certificate_bytes[32] == 25,
        "incorrect value for certificate_bytes[32], expected 25, is %d",
        check_msg->certificate_bytes[32]);
    ck_assert_msg(
        check_msg->certificate_bytes[33] == 172,
        "incorrect value for certificate_bytes[33], expected 172, is %d",
        check_msg->certificate_bytes[33]);
    ck_assert_msg(
        check_msg->certificate_bytes[34] == 170,
        "incorrect value for certificate_bytes[34], expected 170, is %d",
        check_msg->certificate_bytes[34]);
    ck_assert_msg(
        check_msg->certificate_bytes[35] == 250,
        "incorrect value for certificate_bytes[35], expected 250, is %d",
        check_msg->certificate_bytes[35]);
    ck_assert_msg(
        check_msg->certificate_bytes[36] == 236,
        "incorrect value for certificate_bytes[36], expected 236, is %d",
        check_msg->certificate_bytes[36]);
    ck_assert_msg(
        check_msg->certificate_bytes[37] == 7,
        "incorrect value for certificate_bytes[37], expected 7, is %d",
        check_msg->certificate_bytes[37]);
    ck_assert_msg(
        check_msg->certificate_bytes[38] == 119,
        "incorrect value for certificate_bytes[38], expected 119, is %d",
        check_msg->certificate_bytes[38]);
    ck_assert_msg(
        check_msg->certificate_bytes[39] == 4,
        "incorrect value for certificate_bytes[39], expected 4, is %d",
        check_msg->certificate_bytes[39]);
    ck_assert_msg(
        check_msg->certificate_bytes[40] == 201,
        "incorrect value for certificate_bytes[40], expected 201, is %d",
        check_msg->certificate_bytes[40]);
    ck_assert_msg(
        check_msg->certificate_bytes[41] == 10,
        "incorrect value for certificate_bytes[41], expected 10, is %d",
        check_msg->certificate_bytes[41]);
    ck_assert_msg(
        check_msg->certificate_bytes[42] == 14,
        "incorrect value for certificate_bytes[42], expected 14, is %d",
        check_msg->certificate_bytes[42]);
    ck_assert_msg(
        check_msg->certificate_bytes[43] == 208,
        "incorrect value for certificate_bytes[43], expected 208, is %d",
        check_msg->certificate_bytes[43]);
    ck_assert_msg(
        check_msg->certificate_bytes[44] == 47,
        "incorrect value for certificate_bytes[44], expected 47, is %d",
        check_msg->certificate_bytes[44]);
    ck_assert_msg(
        check_msg->certificate_bytes[45] == 126,
        "incorrect value for certificate_bytes[45], expected 126, is %d",
        check_msg->certificate_bytes[45]);
    ck_assert_msg(
        check_msg->certificate_bytes[46] == 49,
        "incorrect value for certificate_bytes[46], expected 49, is %d",
        check_msg->certificate_bytes[46]);
    ck_assert_msg(
        check_msg->certificate_bytes[47] == 210,
        "incorrect value for certificate_bytes[47], expected 210, is %d",
        check_msg->certificate_bytes[47]);
    ck_assert_msg(
        check_msg->certificate_bytes[48] == 174,
        "incorrect value for certificate_bytes[48], expected 174, is %d",
        check_msg->certificate_bytes[48]);
    ck_assert_msg(
        check_msg->certificate_bytes[49] == 75,
        "incorrect value for certificate_bytes[49], expected 75, is %d",
        check_msg->certificate_bytes[49]);
    ck_assert_msg(
        check_msg->certificate_bytes[50] == 221,
        "incorrect value for certificate_bytes[50], expected 221, is %d",
        check_msg->certificate_bytes[50]);
    ck_assert_msg(
        check_msg->certificate_bytes[51] == 203,
        "incorrect value for certificate_bytes[51], expected 203, is %d",
        check_msg->certificate_bytes[51]);
    ck_assert_msg(
        check_msg->certificate_bytes[52] == 24,
        "incorrect value for certificate_bytes[52], expected 24, is %d",
        check_msg->certificate_bytes[52]);
    ck_assert_msg(
        check_msg->certificate_bytes[53] == 66,
        "incorrect value for certificate_bytes[53], expected 66, is %d",
        check_msg->certificate_bytes[53]);
    ck_assert_msg(
        check_msg->certificate_bytes[54] == 52,
        "incorrect value for certificate_bytes[54], expected 52, is %d",
        check_msg->certificate_bytes[54]);
    ck_assert_msg(
        check_msg->certificate_bytes[55] == 35,
        "incorrect value for certificate_bytes[55], expected 35, is %d",
        check_msg->certificate_bytes[55]);
    ck_assert_msg(
        check_msg->certificate_bytes[56] == 26,
        "incorrect value for certificate_bytes[56], expected 26, is %d",
        check_msg->certificate_bytes[56]);
    ck_assert_msg(
        check_msg->certificate_bytes[57] == 30,
        "incorrect value for certificate_bytes[57], expected 30, is %d",
        check_msg->certificate_bytes[57]);
    ck_assert_msg(
        check_msg->certificate_bytes[58] == 140,
        "incorrect value for certificate_bytes[58], expected 140, is %d",
        check_msg->certificate_bytes[58]);
    ck_assert_msg(
        check_msg->certificate_bytes[59] == 111,
        "incorrect value for certificate_bytes[59], expected 111, is %d",
        check_msg->certificate_bytes[59]);
    ck_assert_msg(
        check_msg->certificate_bytes[60] == 246,
        "incorrect value for certificate_bytes[60], expected 246, is %d",
        check_msg->certificate_bytes[60]);
    ck_assert_msg(
        check_msg->certificate_bytes[61] == 39,
        "incorrect value for certificate_bytes[61], expected 39, is %d",
        check_msg->certificate_bytes[61]);
    ck_assert_msg(
        check_msg->certificate_bytes[62] == 226,
        "incorrect value for certificate_bytes[62], expected 226, is %d",
        check_msg->certificate_bytes[62]);
    ck_assert_msg(
        check_msg->certificate_bytes[63] == 205,
        "incorrect value for certificate_bytes[63], expected 205, is %d",
        check_msg->certificate_bytes[63]);
    ck_assert_msg(
        check_msg->certificate_bytes[64] == 198,
        "incorrect value for certificate_bytes[64], expected 198, is %d",
        check_msg->certificate_bytes[64]);
    ck_assert_msg(
        check_msg->certificate_bytes[65] == 178,
        "incorrect value for certificate_bytes[65], expected 178, is %d",
        check_msg->certificate_bytes[65]);
    ck_assert_msg(
        check_msg->certificate_bytes[66] == 196,
        "incorrect value for certificate_bytes[66], expected 196, is %d",
        check_msg->certificate_bytes[66]);
    ck_assert_msg(
        check_msg->certificate_bytes[67] == 5,
        "incorrect value for certificate_bytes[67], expected 5, is %d",
        check_msg->certificate_bytes[67]);
    ck_assert_msg(
        check_msg->certificate_bytes[68] == 81,
        "incorrect value for certificate_bytes[68], expected 81, is %d",
        check_msg->certificate_bytes[68]);
    ck_assert_msg(
        check_msg->certificate_bytes[69] == 9,
        "incorrect value for certificate_bytes[69], expected 9, is %d",
        check_msg->certificate_bytes[69]);
    ck_assert_msg(
        check_msg->certificate_bytes[70] == 44,
        "incorrect value for certificate_bytes[70], expected 44, is %d",
        check_msg->certificate_bytes[70]);
    ck_assert_msg(
        check_msg->certificate_bytes[71] == 164,
        "incorrect value for certificate_bytes[71], expected 164, is %d",
        check_msg->certificate_bytes[71]);
    ck_assert_msg(
        check_msg->certificate_bytes[72] == 163,
        "incorrect value for certificate_bytes[72], expected 163, is %d",
        check_msg->certificate_bytes[72]);
    ck_assert_msg(
        check_msg->certificate_bytes[73] == 214,
        "incorrect value for certificate_bytes[73], expected 214, is %d",
        check_msg->certificate_bytes[73]);
    ck_assert_msg(
        check_msg->certificate_bytes[74] == 138,
        "incorrect value for certificate_bytes[74], expected 138, is %d",
        check_msg->certificate_bytes[74]);
    ck_assert_msg(
        check_msg->certificate_bytes[75] == 123,
        "incorrect value for certificate_bytes[75], expected 123, is %d",
        check_msg->certificate_bytes[75]);
    ck_assert_msg(
        check_msg->certificate_bytes[76] == 76,
        "incorrect value for certificate_bytes[76], expected 76, is %d",
        check_msg->certificate_bytes[76]);
    ck_assert_msg(
        check_msg->certificate_bytes[77] == 74,
        "incorrect value for certificate_bytes[77], expected 74, is %d",
        check_msg->certificate_bytes[77]);
    ck_assert_msg(
        check_msg->certificate_bytes[78] == 237,
        "incorrect value for certificate_bytes[78], expected 237, is %d",
        check_msg->certificate_bytes[78]);
    ck_assert_msg(
        check_msg->certificate_bytes[79] == 121,
        "incorrect value for certificate_bytes[79], expected 121, is %d",
        check_msg->certificate_bytes[79]);
    ck_assert_msg(
        check_msg->certificate_bytes[80] == 13,
        "incorrect value for certificate_bytes[80], expected 13, is %d",
        check_msg->certificate_bytes[80]);
    ck_assert_msg(
        check_msg->certificate_bytes[81] == 137,
        "incorrect value for certificate_bytes[81], expected 137, is %d",
        check_msg->certificate_bytes[81]);
    ck_assert_msg(
        check_msg->certificate_bytes[82] == 186,
        "incorrect value for certificate_bytes[82], expected 186, is %d",
        check_msg->certificate_bytes[82]);
    ck_assert_msg(
        check_msg->certificate_bytes[83] == 97,
        "incorrect value for certificate_bytes[83], expected 97, is %d",
        check_msg->certificate_bytes[83]);
    ck_assert_msg(
        check_msg->certificate_bytes[84] == 193,
        "incorrect value for certificate_bytes[84], expected 193, is %d",
        check_msg->certificate_bytes[84]);
    ck_assert_msg(
        check_msg->certificate_bytes[85] == 189,
        "incorrect value for certificate_bytes[85], expected 189, is %d",
        check_msg->certificate_bytes[85]);
    ck_assert_msg(
        check_msg->certificate_bytes[86] == 200,
        "incorrect value for certificate_bytes[86], expected 200, is %d",
        check_msg->certificate_bytes[86]);
    ck_assert_msg(
        check_msg->certificate_bytes[87] == 124,
        "incorrect value for certificate_bytes[87], expected 124, is %d",
        check_msg->certificate_bytes[87]);
    ck_assert_msg(
        check_msg->certificate_bytes[88] == 69,
        "incorrect value for certificate_bytes[88], expected 69, is %d",
        check_msg->certificate_bytes[88]);
    ck_assert_msg(
        check_msg->certificate_bytes[89] == 115,
        "incorrect value for certificate_bytes[89], expected 115, is %d",
        check_msg->certificate_bytes[89]);
    ck_assert_msg(
        check_msg->certificate_bytes[90] == 230,
        "incorrect value for certificate_bytes[90], expected 230, is %d",
        check_msg->certificate_bytes[90]);
    ck_assert_msg(
        check_msg->certificate_bytes[91] == 159,
        "incorrect value for certificate_bytes[91], expected 159, is %d",
        check_msg->certificate_bytes[91]);
    ck_assert_msg(
        check_msg->certificate_bytes[92] == 185,
        "incorrect value for certificate_bytes[92], expected 185, is %d",
        check_msg->certificate_bytes[92]);
    ck_assert_msg(
        check_msg->certificate_bytes[93] == 158,
        "incorrect value for certificate_bytes[93], expected 158, is %d",
        check_msg->certificate_bytes[93]);
    ck_assert_msg(
        check_msg->certificate_bytes[94] == 51,
        "incorrect value for certificate_bytes[94], expected 51, is %d",
        check_msg->certificate_bytes[94]);
    ck_assert_msg(
        check_msg->certificate_bytes[95] == 12,
        "incorrect value for certificate_bytes[95], expected 12, is %d",
        check_msg->certificate_bytes[95]);
    ck_assert_msg(
        check_msg->certificate_bytes[96] == 225,
        "incorrect value for certificate_bytes[96], expected 225, is %d",
        check_msg->certificate_bytes[96]);
    ck_assert_msg(
        check_msg->certificate_bytes[97] == 65,
        "incorrect value for certificate_bytes[97], expected 65, is %d",
        check_msg->certificate_bytes[97]);
    ck_assert_msg(
        check_msg->certificate_bytes[98] == 192,
        "incorrect value for certificate_bytes[98], expected 192, is %d",
        check_msg->certificate_bytes[98]);
    ck_assert_msg(
        check_msg->certificate_bytes[99] == 105,
        "incorrect value for certificate_bytes[99], expected 105, is %d",
        check_msg->certificate_bytes[99]);
    ck_assert_msg(
        check_msg->certificate_bytes[100] == 56,
        "incorrect value for certificate_bytes[100], expected 56, is %d",
        check_msg->certificate_bytes[100]);
    ck_assert_msg(
        check_msg->certificate_bytes[101] == 41,
        "incorrect value for certificate_bytes[101], expected 41, is %d",
        check_msg->certificate_bytes[101]);
    ck_assert_msg(
        check_msg->certificate_bytes[102] == 85,
        "incorrect value for certificate_bytes[102], expected 85, is %d",
        check_msg->certificate_bytes[102]);
    ck_assert_msg(
        check_msg->certificate_bytes[103] == 133,
        "incorrect value for certificate_bytes[103], expected 133, is %d",
        check_msg->certificate_bytes[103]);
    ck_assert_msg(
        check_msg->certificate_bytes[104] == 19,
        "incorrect value for certificate_bytes[104], expected 19, is %d",
        check_msg->certificate_bytes[104]);
    ck_assert_msg(
        check_msg->certificate_bytes[105] == 217,
        "incorrect value for certificate_bytes[105], expected 217, is %d",
        check_msg->certificate_bytes[105]);
    ck_assert_msg(
        check_msg->certificate_bytes[106] == 166,
        "incorrect value for certificate_bytes[106], expected 166, is %d",
        check_msg->certificate_bytes[106]);
    ck_assert_msg(
        check_msg->certificate_bytes[107] == 48,
        "incorrect value for certificate_bytes[107], expected 48, is %d",
        check_msg->certificate_bytes[107]);
    ck_assert_msg(
        check_msg->certificate_bytes[108] == 139,
        "incorrect value for certificate_bytes[108], expected 139, is %d",
        check_msg->certificate_bytes[108]);
    ck_assert_msg(
        check_msg->certificate_bytes[109] == 131,
        "incorrect value for certificate_bytes[109], expected 131, is %d",
        check_msg->certificate_bytes[109]);
    ck_assert_msg(
        check_msg->certificate_bytes[110] == 96,
        "incorrect value for certificate_bytes[110], expected 96, is %d",
        check_msg->certificate_bytes[110]);
    ck_assert_msg(
        check_msg->certificate_bytes[111] == 216,
        "incorrect value for certificate_bytes[111], expected 216, is %d",
        check_msg->certificate_bytes[111]);
    ck_assert_msg(
        check_msg->certificate_bytes[112] == 98,
        "incorrect value for certificate_bytes[112], expected 98, is %d",
        check_msg->certificate_bytes[112]);
    ck_assert_msg(
        check_msg->certificate_bytes[113] == 147,
        "incorrect value for certificate_bytes[113], expected 147, is %d",
        check_msg->certificate_bytes[113]);
    ck_assert_msg(
        check_msg->certificate_bytes[114] == 132,
        "incorrect value for certificate_bytes[114], expected 132, is %d",
        check_msg->certificate_bytes[114]);
    ck_assert_msg(
        check_msg->certificate_bytes[115] == 234,
        "incorrect value for certificate_bytes[115], expected 234, is %d",
        check_msg->certificate_bytes[115]);
    ck_assert_msg(
        check_msg->certificate_bytes[116] == 167,
        "incorrect value for certificate_bytes[116], expected 167, is %d",
        check_msg->certificate_bytes[116]);
    ck_assert_msg(
        check_msg->certificate_bytes[117] == 248,
        "incorrect value for certificate_bytes[117], expected 248, is %d",
        check_msg->certificate_bytes[117]);
    ck_assert_msg(
        check_msg->certificate_bytes[118] == 247,
        "incorrect value for certificate_bytes[118], expected 247, is %d",
        check_msg->certificate_bytes[118]);
    ck_assert_msg(
        check_msg->certificate_bytes[119] == 32,
        "incorrect value for certificate_bytes[119], expected 32, is %d",
        check_msg->certificate_bytes[119]);
    ck_assert_msg(
        check_msg->certificate_bytes[120] == 239,
        "incorrect value for certificate_bytes[120], expected 239, is %d",
        check_msg->certificate_bytes[120]);
    ck_assert_msg(
        check_msg->certificate_bytes[121] == 194,
        "incorrect value for certificate_bytes[121], expected 194, is %d",
        check_msg->certificate_bytes[121]);
    ck_assert_msg(
        check_msg->certificate_bytes[122] == 188,
        "incorrect value for certificate_bytes[122], expected 188, is %d",
        check_msg->certificate_bytes[122]);
    ck_assert_msg(
        check_msg->certificate_bytes[123] == 254,
        "incorrect value for certificate_bytes[123], expected 254, is %d",
        check_msg->certificate_bytes[123]);
    ck_assert_msg(
        check_msg->certificate_bytes[124] == 114,
        "incorrect value for certificate_bytes[124], expected 114, is %d",
        check_msg->certificate_bytes[124]);
    ck_assert_msg(
        check_msg->certificate_bytes[125] == 117,
        "incorrect value for certificate_bytes[125], expected 117, is %d",
        check_msg->certificate_bytes[125]);
    ck_assert_msg(
        check_msg->certificate_bytes[126] == 83,
        "incorrect value for certificate_bytes[126], expected 83, is %d",
        check_msg->certificate_bytes[126]);
    ck_assert_msg(
        check_msg->certificate_bytes[127] == 25,
        "incorrect value for certificate_bytes[127], expected 25, is %d",
        check_msg->certificate_bytes[127]);
    ck_assert_msg(
        check_msg->certificate_bytes[128] == 251,
        "incorrect value for certificate_bytes[128], expected 251, is %d",
        check_msg->certificate_bytes[128]);
    ck_assert_msg(
        check_msg->certificate_bytes[129] == 191,
        "incorrect value for certificate_bytes[129], expected 191, is %d",
        check_msg->certificate_bytes[129]);
    ck_assert_msg(
        check_msg->certificate_bytes[130] == 104,
        "incorrect value for certificate_bytes[130], expected 104, is %d",
        check_msg->certificate_bytes[130]);
    ck_assert_msg(
        check_msg->certificate_bytes[131] == 240,
        "incorrect value for certificate_bytes[131], expected 240, is %d",
        check_msg->certificate_bytes[131]);
    ck_assert_msg(
        check_msg->certificate_bytes[132] == 118,
        "incorrect value for certificate_bytes[132], expected 118, is %d",
        check_msg->certificate_bytes[132]);
    ck_assert_msg(
        check_msg->certificate_bytes[133] == 68,
        "incorrect value for certificate_bytes[133], expected 68, is %d",
        check_msg->certificate_bytes[133]);
    ck_assert_msg(
        check_msg->certificate_bytes[134] == 42,
        "incorrect value for certificate_bytes[134], expected 42, is %d",
        check_msg->certificate_bytes[134]);
    ck_assert_msg(
        check_msg->certificate_bytes[135] == 93,
        "incorrect value for certificate_bytes[135], expected 93, is %d",
        check_msg->certificate_bytes[135]);
    ck_assert_msg(
        check_msg->certificate_bytes[136] == 18,
        "incorrect value for certificate_bytes[136], expected 18, is %d",
        check_msg->certificate_bytes[136]);
    ck_assert_msg(
        check_msg->certificate_bytes[137] == 16,
        "incorrect value for certificate_bytes[137], expected 16, is %d",
        check_msg->certificate_bytes[137]);
    ck_assert_msg(
        check_msg->certificate_bytes[138] == 37,
        "incorrect value for certificate_bytes[138], expected 37, is %d",
        check_msg->certificate_bytes[138]);
    ck_assert_msg(
        check_msg->certificate_bytes[139] == 232,
        "incorrect value for certificate_bytes[139], expected 232, is %d",
        check_msg->certificate_bytes[139]);
    ck_assert_msg(
        check_msg->certificate_bytes[140] == 99,
        "incorrect value for certificate_bytes[140], expected 99, is %d",
        check_msg->certificate_bytes[140]);
    ck_assert_msg(
        check_msg->certificate_bytes[141] == 179,
        "incorrect value for certificate_bytes[141], expected 179, is %d",
        check_msg->certificate_bytes[141]);
    ck_assert_msg(
        check_msg->certificate_bytes[142] == 23,
        "incorrect value for certificate_bytes[142], expected 23, is %d",
        check_msg->certificate_bytes[142]);
    ck_assert_msg(
        check_msg->certificate_bytes[143] == 90,
        "incorrect value for certificate_bytes[143], expected 90, is %d",
        check_msg->certificate_bytes[143]);
    ck_assert_msg(
        check_msg->certificate_bytes[144] == 94,
        "incorrect value for certificate_bytes[144], expected 94, is %d",
        check_msg->certificate_bytes[144]);
    ck_assert_msg(
        check_msg->certificate_bytes[145] == 136,
        "incorrect value for certificate_bytes[145], expected 136, is %d",
        check_msg->certificate_bytes[145]);
    ck_assert_msg(
        check_msg->certificate_bytes[146] == 6,
        "incorrect value for certificate_bytes[146], expected 6, is %d",
        check_msg->certificate_bytes[146]);
    ck_assert_msg(
        check_msg->certificate_bytes[147] == 125,
        "incorrect value for certificate_bytes[147], expected 125, is %d",
        check_msg->certificate_bytes[147]);
    ck_assert_msg(
        check_msg->certificate_bytes[148] == 91,
        "incorrect value for certificate_bytes[148], expected 91, is %d",
        check_msg->certificate_bytes[148]);
    ck_assert_msg(
        check_msg->certificate_bytes[149] == 255,
        "incorrect value for certificate_bytes[149], expected 255, is %d",
        check_msg->certificate_bytes[149]);
    ck_assert_msg(
        check_msg->certificate_bytes[150] == 15,
        "incorrect value for certificate_bytes[150], expected 15, is %d",
        check_msg->certificate_bytes[150]);
    ck_assert_msg(
        check_msg->certificate_bytes[151] == 71,
        "incorrect value for certificate_bytes[151], expected 71, is %d",
        check_msg->certificate_bytes[151]);
    ck_assert_msg(
        check_msg->certificate_bytes[152] == 43,
        "incorrect value for certificate_bytes[152], expected 43, is %d",
        check_msg->certificate_bytes[152]);
    ck_assert_msg(
        check_msg->certificate_bytes[153] == 46,
        "incorrect value for certificate_bytes[153], expected 46, is %d",
        check_msg->certificate_bytes[153]);
    ck_assert_msg(
        check_msg->certificate_bytes[154] == 25,
        "incorrect value for certificate_bytes[154], expected 25, is %d",
        check_msg->certificate_bytes[154]);
    ck_assert_msg(
        check_msg->certificate_bytes[155] == 252,
        "incorrect value for certificate_bytes[155], expected 252, is %d",
        check_msg->certificate_bytes[155]);
    ck_assert_msg(
        check_msg->certificate_bytes[156] == 229,
        "incorrect value for certificate_bytes[156], expected 229, is %d",
        check_msg->certificate_bytes[156]);
    ck_assert_msg(
        check_msg->certificate_bytes[157] == 80,
        "incorrect value for certificate_bytes[157], expected 80, is %d",
        check_msg->certificate_bytes[157]);
    ck_assert_msg(
        check_msg->certificate_bytes[158] == 143,
        "incorrect value for certificate_bytes[158], expected 143, is %d",
        check_msg->certificate_bytes[158]);
    ck_assert_msg(
        check_msg->certificate_bytes[159] == 58,
        "incorrect value for certificate_bytes[159], expected 58, is %d",
        check_msg->certificate_bytes[159]);
    ck_assert_msg(
        check_msg->certificate_bytes[160] == 241,
        "incorrect value for certificate_bytes[160], expected 241, is %d",
        check_msg->certificate_bytes[160]);
    ck_assert_msg(
        check_msg->certificate_bytes[161] == 11,
        "incorrect value for certificate_bytes[161], expected 11, is %d",
        check_msg->certificate_bytes[161]);
    ck_assert_msg(
        check_msg->certificate_bytes[162] == 62,
        "incorrect value for certificate_bytes[162], expected 62, is %d",
        check_msg->certificate_bytes[162]);
    ck_assert_msg(
        check_msg->certificate_bytes[163] == 181,
        "incorrect value for certificate_bytes[163], expected 181, is %d",
        check_msg->certificate_bytes[163]);
    ck_assert_msg(
        check_msg->certificate_bytes[164] == 155,
        "incorrect value for certificate_bytes[164], expected 155, is %d",
        check_msg->certificate_bytes[164]);
    ck_assert_msg(
        check_msg->certificate_bytes[165] == 53,
        "incorrect value for certificate_bytes[165], expected 53, is %d",
        check_msg->certificate_bytes[165]);
    ck_assert_msg(
        check_msg->certificate_bytes[166] == 153,
        "incorrect value for certificate_bytes[166], expected 153, is %d",
        check_msg->certificate_bytes[166]);
    ck_assert_msg(
        check_msg->certificate_bytes[167] == 149,
        "incorrect value for certificate_bytes[167], expected 149, is %d",
        check_msg->certificate_bytes[167]);
    ck_assert_msg(
        check_msg->certificate_bytes[168] == 152,
        "incorrect value for certificate_bytes[168], expected 152, is %d",
        check_msg->certificate_bytes[168]);
    ck_assert_msg(
        check_msg->certificate_bytes[169] == 227,
        "incorrect value for certificate_bytes[169], expected 227, is %d",
        check_msg->certificate_bytes[169]);
    ck_assert_msg(
        check_msg->certificate_bytes[170] == 150,
        "incorrect value for certificate_bytes[170], expected 150, is %d",
        check_msg->certificate_bytes[170]);
    ck_assert_msg(
        check_msg->certificate_bytes[171] == 87,
        "incorrect value for certificate_bytes[171], expected 87, is %d",
        check_msg->certificate_bytes[171]);
    ck_assert_msg(
        check_msg->certificate_bytes[172] == 112,
        "incorrect value for certificate_bytes[172], expected 112, is %d",
        check_msg->certificate_bytes[172]);
    ck_assert_msg(
        check_msg->certificate_bytes[173] == 165,
        "incorrect value for certificate_bytes[173], expected 165, is %d",
        check_msg->certificate_bytes[173]);
    ck_assert_msg(
        check_msg->certificate_bytes[174] == 2,
        "incorrect value for certificate_bytes[174], expected 2, is %d",
        check_msg->certificate_bytes[174]);
    ck_assert_msg(
        check_msg->certificate_bytes[175] == 128,
        "incorrect value for certificate_bytes[175], expected 128, is %d",
        check_msg->certificate_bytes[175]);
    ck_assert_msg(
        check_msg->certificate_bytes[176] == 231,
        "incorrect value for certificate_bytes[176], expected 231, is %d",
        check_msg->certificate_bytes[176]);
    ck_assert_msg(
        check_msg->certificate_bytes[177] == 25,
        "incorrect value for certificate_bytes[177], expected 25, is %d",
        check_msg->certificate_bytes[177]);
    ck_assert_msg(
        check_msg->certificate_bytes[178] == 157,
        "incorrect value for certificate_bytes[178], expected 157, is %d",
        check_msg->certificate_bytes[178]);
    ck_assert_msg(
        check_msg->certificate_bytes[179] == 244,
        "incorrect value for certificate_bytes[179], expected 244, is %d",
        check_msg->certificate_bytes[179]);
    ck_assert_msg(
        check_msg->certificate_bytes[180] == 204,
        "incorrect value for certificate_bytes[180], expected 204, is %d",
        check_msg->certificate_bytes[180]);
    ck_assert_msg(
        check_msg->certificate_bytes[181] == 108,
        "incorrect value for certificate_bytes[181], expected 108, is %d",
        check_msg->certificate_bytes[181]);
    ck_assert_msg(
        check_msg->certificate_bytes[182] == 253,
        "incorrect value for certificate_bytes[182], expected 253, is %d",
        check_msg->certificate_bytes[182]);
    ck_assert_msg(
        check_msg->certificate_bytes[183] == 127,
        "incorrect value for certificate_bytes[183], expected 127, is %d",
        check_msg->certificate_bytes[183]);
    ck_assert_msg(
        check_msg->certificate_bytes[184] == 122,
        "incorrect value for certificate_bytes[184], expected 122, is %d",
        check_msg->certificate_bytes[184]);
    ck_assert_msg(
        check_msg->certificate_bytes[185] == 145,
        "incorrect value for certificate_bytes[185], expected 145, is %d",
        check_msg->certificate_bytes[185]);
    ck_assert_msg(
        check_msg->certificate_bytes[186] == 113,
        "incorrect value for certificate_bytes[186], expected 113, is %d",
        check_msg->certificate_bytes[186]);
    ck_assert_msg(
        check_msg->certificate_bytes[187] == 162,
        "incorrect value for certificate_bytes[187], expected 162, is %d",
        check_msg->certificate_bytes[187]);
    ck_assert_msg(
        check_msg->certificate_bytes[188] == 197,
        "incorrect value for certificate_bytes[188], expected 197, is %d",
        check_msg->certificate_bytes[188]);
    ck_assert_msg(
        check_msg->certificate_bytes[189] == 171,
        "incorrect value for certificate_bytes[189], expected 171, is %d",
        check_msg->certificate_bytes[189]);
    ck_assert_msg(
        check_msg->certificate_bytes[190] == 199,
        "incorrect value for certificate_bytes[190], expected 199, is %d",
        check_msg->certificate_bytes[190]);
    ck_assert_msg(
        check_msg->certificate_bytes[191] == 54,
        "incorrect value for certificate_bytes[191], expected 54, is %d",
        check_msg->certificate_bytes[191]);
    ck_assert_msg(
        check_msg->certificate_bytes[192] == 184,
        "incorrect value for certificate_bytes[192], expected 184, is %d",
        check_msg->certificate_bytes[192]);
    ck_assert_msg(
        check_msg->certificate_bytes[193] == 222,
        "incorrect value for certificate_bytes[193], expected 222, is %d",
        check_msg->certificate_bytes[193]);
    ck_assert_msg(
        check_msg->certificate_bytes[194] == 206,
        "incorrect value for certificate_bytes[194], expected 206, is %d",
        check_msg->certificate_bytes[194]);
    ck_assert_msg(
        check_msg->certificate_bytes[195] == 67,
        "incorrect value for certificate_bytes[195], expected 67, is %d",
        check_msg->certificate_bytes[195]);
    ck_assert_msg(
        check_msg->certificate_bytes[196] == 144,
        "incorrect value for certificate_bytes[196], expected 144, is %d",
        check_msg->certificate_bytes[196]);
    ck_assert_msg(
        check_msg->certificate_bytes[197] == 78,
        "incorrect value for certificate_bytes[197], expected 78, is %d",
        check_msg->certificate_bytes[197]);
    ck_assert_msg(
        check_msg->certificate_bytes[198] == 187,
        "incorrect value for certificate_bytes[198], expected 187, is %d",
        check_msg->certificate_bytes[198]);
    ck_assert_msg(
        check_msg->certificate_bytes[199] == 207,
        "incorrect value for certificate_bytes[199], expected 207, is %d",
        check_msg->certificate_bytes[199]);
    ck_assert_msg(
        check_msg->certificate_bytes[200] == 60,
        "incorrect value for certificate_bytes[200], expected 60, is %d",
        check_msg->certificate_bytes[200]);
    ck_assert_msg(
        check_msg->certificate_bytes[201] == 211,
        "incorrect value for certificate_bytes[201], expected 211, is %d",
        check_msg->certificate_bytes[201]);
    ck_assert_msg(
        check_msg->certificate_bytes[202] == 141,
        "incorrect value for certificate_bytes[202], expected 141, is %d",
        check_msg->certificate_bytes[202]);
    ck_assert_msg(
        check_msg->certificate_bytes[203] == 135,
        "incorrect value for certificate_bytes[203], expected 135, is %d",
        check_msg->certificate_bytes[203]);
    ck_assert_msg(
        check_msg->certificate_bytes[204] == 106,
        "incorrect value for certificate_bytes[204], expected 106, is %d",
        check_msg->certificate_bytes[204]);
    ck_assert_msg(
        check_msg->certificate_bytes[205] == 220,
        "incorrect value for certificate_bytes[205], expected 220, is %d",
        check_msg->certificate_bytes[205]);
    ck_assert_msg(
        check_msg->certificate_bytes[206] == 79,
        "incorrect value for certificate_bytes[206], expected 79, is %d",
        check_msg->certificate_bytes[206]);
    ck_assert_msg(
        check_msg->certificate_bytes[207] == 183,
        "incorrect value for certificate_bytes[207], expected 183, is %d",
        check_msg->certificate_bytes[207]);
    ck_assert_msg(
        check_msg->certificate_bytes[208] == 245,
        "incorrect value for certificate_bytes[208], expected 245, is %d",
        check_msg->certificate_bytes[208]);
    ck_assert_msg(
        check_msg->certificate_bytes[209] == 21,
        "incorrect value for certificate_bytes[209], expected 21, is %d",
        check_msg->certificate_bytes[209]);
    ck_assert_msg(
        check_msg->certificate_bytes[210] == 161,
        "incorrect value for certificate_bytes[210], expected 161, is %d",
        check_msg->certificate_bytes[210]);
    ck_assert_msg(
        check_msg->certificate_bytes[211] == 168,
        "incorrect value for certificate_bytes[211], expected 168, is %d",
        check_msg->certificate_bytes[211]);
    ck_assert_msg(
        check_msg->certificate_bytes[212] == 34,
        "incorrect value for certificate_bytes[212], expected 34, is %d",
        check_msg->certificate_bytes[212]);
    ck_assert_msg(
        check_msg->certificate_bytes[213] == 129,
        "incorrect value for certificate_bytes[213], expected 129, is %d",
        check_msg->certificate_bytes[213]);
    ck_assert_msg(
        check_msg->certificate_bytes[214] == 50,
        "incorrect value for certificate_bytes[214], expected 50, is %d",
        check_msg->certificate_bytes[214]);
    ck_assert_msg(
        check_msg->certificate_bytes[215] == 176,
        "incorrect value for certificate_bytes[215], expected 176, is %d",
        check_msg->certificate_bytes[215]);
    ck_assert_msg(
        check_msg->certificate_bytes[216] == 1,
        "incorrect value for certificate_bytes[216], expected 1, is %d",
        check_msg->certificate_bytes[216]);
    ck_assert_msg(
        check_msg->certificate_bytes[217] == 218,
        "incorrect value for certificate_bytes[217], expected 218, is %d",
        check_msg->certificate_bytes[217]);
    ck_assert_msg(
        check_msg->certificate_bytes[218] == 20,
        "incorrect value for certificate_bytes[218], expected 20, is %d",
        check_msg->certificate_bytes[218]);
    ck_assert_msg(
        check_msg->certificate_bytes[219] == 130,
        "incorrect value for certificate_bytes[219], expected 130, is %d",
        check_msg->certificate_bytes[219]);
    ck_assert_msg(
        check_msg->certificate_bytes[220] == 59,
        "incorrect value for certificate_bytes[220], expected 59, is %d",
        check_msg->certificate_bytes[220]);
    ck_assert_msg(
        check_msg->certificate_bytes[221] == 249,
        "incorrect value for certificate_bytes[221], expected 249, is %d",
        check_msg->certificate_bytes[221]);
    ck_assert_msg(
        check_msg->certificate_bytes[222] == 109,
        "incorrect value for certificate_bytes[222], expected 109, is %d",
        check_msg->certificate_bytes[222]);
    ck_assert_msg(
        check_msg->certificate_bytes[223] == 219,
        "incorrect value for certificate_bytes[223], expected 219, is %d",
        check_msg->certificate_bytes[223]);
    ck_assert_msg(
        check_msg->certificate_bytes[224] == 0,
        "incorrect value for certificate_bytes[224], expected 0, is %d",
        check_msg->certificate_bytes[224]);
    ck_assert_msg(
        check_msg->certificate_bytes[225] == 100,
        "incorrect value for certificate_bytes[225], expected 100, is %d",
        check_msg->certificate_bytes[225]);
    ck_assert_msg(
        check_msg->certificate_bytes[226] == 103,
        "incorrect value for certificate_bytes[226], expected 103, is %d",
        check_msg->certificate_bytes[226]);
    ck_assert_msg(
        check_msg->certificate_bytes[227] == 55,
        "incorrect value for certificate_bytes[227], expected 55, is %d",
        check_msg->certificate_bytes[227]);
    ck_assert_msg(
        check_msg->certificate_bytes[228] == 29,
        "incorrect value for certificate_bytes[228], expected 29, is %d",
        check_msg->certificate_bytes[228]);
    ck_assert_msg(
        check_msg->certificate_bytes[229] == 242,
        "incorrect value for certificate_bytes[229], expected 242, is %d",
        check_msg->certificate_bytes[229]);
    ck_assert_msg(
        check_msg->certificate_bytes[230] == 110,
        "incorrect value for certificate_bytes[230], expected 110, is %d",
        check_msg->certificate_bytes[230]);
    ck_assert_msg(
        check_msg->certificate_bytes[231] == 154,
        "incorrect value for certificate_bytes[231], expected 154, is %d",
        check_msg->certificate_bytes[231]);
    ck_assert_msg(
        check_msg->certificate_bytes[232] == 190,
        "incorrect value for certificate_bytes[232], expected 190, is %d",
        check_msg->certificate_bytes[232]);
    ck_assert_msg(
        check_msg->certificate_bytes[233] == 233,
        "incorrect value for certificate_bytes[233], expected 233, is %d",
        check_msg->certificate_bytes[233]);
    ck_assert_msg(
        check_msg->certificate_bytes[234] == 142,
        "incorrect value for certificate_bytes[234], expected 142, is %d",
        check_msg->certificate_bytes[234]);
    ck_assert_msg(
        check_msg->certificate_bytes[235] == 45,
        "incorrect value for certificate_bytes[235], expected 45, is %d",
        check_msg->certificate_bytes[235]);
    ck_assert_msg(
        check_msg->certificate_bytes[236] == 61,
        "incorrect value for certificate_bytes[236], expected 61, is %d",
        check_msg->certificate_bytes[236]);
    ck_assert_msg(
        check_msg->certificate_bytes[237] == 215,
        "incorrect value for certificate_bytes[237], expected 215, is %d",
        check_msg->certificate_bytes[237]);
    ck_assert_msg(
        check_msg->certificate_bytes[238] == 202,
        "incorrect value for certificate_bytes[238], expected 202, is %d",
        check_msg->certificate_bytes[238]);
    ck_assert_msg(
        check_msg->certificate_bytes[239] == 238,
        "incorrect value for certificate_bytes[239], expected 238, is %d",
        check_msg->certificate_bytes[239]);
    ck_assert_msg(
        check_msg->certificate_bytes[240] == 88,
        "incorrect value for certificate_bytes[240], expected 88, is %d",
        check_msg->certificate_bytes[240]);
    ck_assert_msg(
        check_msg->certificate_bytes[241] == 209,
        "incorrect value for certificate_bytes[241], expected 209, is %d",
        check_msg->certificate_bytes[241]);
    ck_assert_msg(
        check_msg->certificate_bytes[242] == 70,
        "incorrect value for certificate_bytes[242], expected 70, is %d",
        check_msg->certificate_bytes[242]);
    ck_assert_msg(
        check_msg->certificate_bytes[243] == 63,
        "incorrect value for certificate_bytes[243], expected 63, is %d",
        check_msg->certificate_bytes[243]);
    ck_assert_msg(
        check_msg->certificate_bytes[244] == 151,
        "incorrect value for certificate_bytes[244], expected 151, is %d",
        check_msg->certificate_bytes[244]);
    ck_assert_msg(
        check_msg->certificate_bytes[245] == 27,
        "incorrect value for certificate_bytes[245], expected 27, is %d",
        check_msg->certificate_bytes[245]);
    ck_assert_msg(
        check_msg->certificate_bytes[246] == 102,
        "incorrect value for certificate_bytes[246], expected 102, is %d",
        check_msg->certificate_bytes[246]);
    ck_assert_msg(check_msg->certificate_id[0] == 10,
                  "incorrect value for certificate_id[0], expected 10, is %d",
                  check_msg->certificate_id[0]);
    ck_assert_msg(check_msg->certificate_id[1] == 11,
                  "incorrect value for certificate_id[1], expected 11, is %d",
                  check_msg->certificate_id[1]);
    ck_assert_msg(check_msg->certificate_id[2] == 12,
                  "incorrect value for certificate_id[2], expected 12, is %d",
                  check_msg->certificate_id[2]);
    ck_assert_msg(check_msg->certificate_id[3] == 13,
                  "incorrect value for certificate_id[3], expected 13, is %d",
                  check_msg->certificate_id[3]);
    ck_assert_msg(check_msg->flags == 2,
                  "incorrect value for flags, expected 2, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->n_msg == 48,
                  "incorrect value for n_msg, expected 48, is %d",
                  check_msg->n_msg);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_signing_MsgEcdsaCertificate_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_signing_MsgEcdsaCertificate");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_signing_MsgEcdsaCertificate");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_signing_MsgEcdsaCertificate);
  suite_add_tcase(s, tc_acq);
  return s;
}