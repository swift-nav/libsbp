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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519Certificate.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/legacy/signing.h>
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

START_TEST(test_legacy_auto_check_sbp_signing_MsgEd25519Certificate) {
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

    sbp_payload_callback_register(&sbp_state, 0xC02, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0xC02, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  2,   12,  66,  0,   106, 16,  100, 101, 102, 103, 104, 105,
        106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
        119, 0,   3,   6,   9,   12,  15,  18,  21,  24,  27,  30,  33,
        36,  39,  42,  45,  48,  51,  54,  57,  60,  63,  66,  69,  72,
        75,  78,  81,  84,  87,  90,  93,  96,  99,  102, 105, 108, 111,
        114, 117, 120, 123, 126, 129, 132, 135, 138, 141, 144, 147, 150,
        153, 156, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186, 189,
        192, 195, 198, 201, 204, 207, 210, 213, 216, 219, 222, 225, 228,
        231, 234, 237, 240, 243, 246, 249, 252, 218, 148,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ed25519_certificate_t *test_msg =
        (msg_ed25519_certificate_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[0] = 0;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[1] = 3;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[2] = 6;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[3] = 9;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[4] = 12;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[5] = 15;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[6] = 18;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[7] = 21;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[8] = 24;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[9] = 27;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[10] = 30;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[11] = 33;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[12] = 36;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[13] = 39;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[14] = 42;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[15] = 45;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[16] = 48;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[17] = 51;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[18] = 54;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[19] = 57;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[20] = 60;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[21] = 63;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[22] = 66;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[23] = 69;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[24] = 72;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[25] = 75;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[26] = 78;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[27] = 81;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[28] = 84;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[29] = 87;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[30] = 90;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[31] = 93;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[32] = 96;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[33] = 99;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[34] = 102;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[35] = 105;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[36] = 108;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[37] = 111;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[38] = 114;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[39] = 117;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[40] = 120;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[41] = 123;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[42] = 126;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[43] = 129;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[44] = 132;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[45] = 135;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[46] = 138;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[47] = 141;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[48] = 144;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[49] = 147;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[50] = 150;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[51] = 153;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[52] = 156;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[53] = 159;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[54] = 162;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[55] = 165;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[56] = 168;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[57] = 171;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[58] = 174;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[59] = 177;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[60] = 180;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[61] = 183;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[62] = 186;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[63] = 189;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[64] = 192;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[65] = 195;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[66] = 198;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[67] = 201;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[68] = 204;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[69] = 207;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[70] = 210;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[71] = 213;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[72] = 216;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[73] = 219;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[74] = 222;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[75] = 225;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[76] = 228;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[77] = 231;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[78] = 234;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[79] = 237;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[80] = 240;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[81] = 243;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[82] = 246;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[83] = 249;
    if (sizeof(test_msg->certificate_bytes) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_bytes[0]);
    }
    test_msg->certificate_bytes[84] = 252;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[0] = 100;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[1] = 101;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[2] = 102;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[3] = 103;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[4] = 104;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[5] = 105;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[6] = 106;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[7] = 107;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[8] = 108;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[9] = 109;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[10] = 110;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[11] = 111;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[12] = 112;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[13] = 113;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[14] = 114;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[15] = 115;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[16] = 116;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[17] = 117;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[18] = 118;
    if (sizeof(test_msg->fingerprint) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->fingerprint[0]);
    }
    test_msg->fingerprint[19] = 119;
    test_msg->n_msg = 16;
    sbp_payload_send(&sbp_state, 0xC02, 66, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_frame.msg_type == 0xC02,
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
    msg_ed25519_certificate_t *check_msg =
        (msg_ed25519_certificate_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->certificate_bytes[0] == 0,
                  "incorrect value for certificate_bytes[0], expected 0, is %d",
                  check_msg->certificate_bytes[0]);
    ck_assert_msg(check_msg->certificate_bytes[1] == 3,
                  "incorrect value for certificate_bytes[1], expected 3, is %d",
                  check_msg->certificate_bytes[1]);
    ck_assert_msg(check_msg->certificate_bytes[2] == 6,
                  "incorrect value for certificate_bytes[2], expected 6, is %d",
                  check_msg->certificate_bytes[2]);
    ck_assert_msg(check_msg->certificate_bytes[3] == 9,
                  "incorrect value for certificate_bytes[3], expected 9, is %d",
                  check_msg->certificate_bytes[3]);
    ck_assert_msg(
        check_msg->certificate_bytes[4] == 12,
        "incorrect value for certificate_bytes[4], expected 12, is %d",
        check_msg->certificate_bytes[4]);
    ck_assert_msg(
        check_msg->certificate_bytes[5] == 15,
        "incorrect value for certificate_bytes[5], expected 15, is %d",
        check_msg->certificate_bytes[5]);
    ck_assert_msg(
        check_msg->certificate_bytes[6] == 18,
        "incorrect value for certificate_bytes[6], expected 18, is %d",
        check_msg->certificate_bytes[6]);
    ck_assert_msg(
        check_msg->certificate_bytes[7] == 21,
        "incorrect value for certificate_bytes[7], expected 21, is %d",
        check_msg->certificate_bytes[7]);
    ck_assert_msg(
        check_msg->certificate_bytes[8] == 24,
        "incorrect value for certificate_bytes[8], expected 24, is %d",
        check_msg->certificate_bytes[8]);
    ck_assert_msg(
        check_msg->certificate_bytes[9] == 27,
        "incorrect value for certificate_bytes[9], expected 27, is %d",
        check_msg->certificate_bytes[9]);
    ck_assert_msg(
        check_msg->certificate_bytes[10] == 30,
        "incorrect value for certificate_bytes[10], expected 30, is %d",
        check_msg->certificate_bytes[10]);
    ck_assert_msg(
        check_msg->certificate_bytes[11] == 33,
        "incorrect value for certificate_bytes[11], expected 33, is %d",
        check_msg->certificate_bytes[11]);
    ck_assert_msg(
        check_msg->certificate_bytes[12] == 36,
        "incorrect value for certificate_bytes[12], expected 36, is %d",
        check_msg->certificate_bytes[12]);
    ck_assert_msg(
        check_msg->certificate_bytes[13] == 39,
        "incorrect value for certificate_bytes[13], expected 39, is %d",
        check_msg->certificate_bytes[13]);
    ck_assert_msg(
        check_msg->certificate_bytes[14] == 42,
        "incorrect value for certificate_bytes[14], expected 42, is %d",
        check_msg->certificate_bytes[14]);
    ck_assert_msg(
        check_msg->certificate_bytes[15] == 45,
        "incorrect value for certificate_bytes[15], expected 45, is %d",
        check_msg->certificate_bytes[15]);
    ck_assert_msg(
        check_msg->certificate_bytes[16] == 48,
        "incorrect value for certificate_bytes[16], expected 48, is %d",
        check_msg->certificate_bytes[16]);
    ck_assert_msg(
        check_msg->certificate_bytes[17] == 51,
        "incorrect value for certificate_bytes[17], expected 51, is %d",
        check_msg->certificate_bytes[17]);
    ck_assert_msg(
        check_msg->certificate_bytes[18] == 54,
        "incorrect value for certificate_bytes[18], expected 54, is %d",
        check_msg->certificate_bytes[18]);
    ck_assert_msg(
        check_msg->certificate_bytes[19] == 57,
        "incorrect value for certificate_bytes[19], expected 57, is %d",
        check_msg->certificate_bytes[19]);
    ck_assert_msg(
        check_msg->certificate_bytes[20] == 60,
        "incorrect value for certificate_bytes[20], expected 60, is %d",
        check_msg->certificate_bytes[20]);
    ck_assert_msg(
        check_msg->certificate_bytes[21] == 63,
        "incorrect value for certificate_bytes[21], expected 63, is %d",
        check_msg->certificate_bytes[21]);
    ck_assert_msg(
        check_msg->certificate_bytes[22] == 66,
        "incorrect value for certificate_bytes[22], expected 66, is %d",
        check_msg->certificate_bytes[22]);
    ck_assert_msg(
        check_msg->certificate_bytes[23] == 69,
        "incorrect value for certificate_bytes[23], expected 69, is %d",
        check_msg->certificate_bytes[23]);
    ck_assert_msg(
        check_msg->certificate_bytes[24] == 72,
        "incorrect value for certificate_bytes[24], expected 72, is %d",
        check_msg->certificate_bytes[24]);
    ck_assert_msg(
        check_msg->certificate_bytes[25] == 75,
        "incorrect value for certificate_bytes[25], expected 75, is %d",
        check_msg->certificate_bytes[25]);
    ck_assert_msg(
        check_msg->certificate_bytes[26] == 78,
        "incorrect value for certificate_bytes[26], expected 78, is %d",
        check_msg->certificate_bytes[26]);
    ck_assert_msg(
        check_msg->certificate_bytes[27] == 81,
        "incorrect value for certificate_bytes[27], expected 81, is %d",
        check_msg->certificate_bytes[27]);
    ck_assert_msg(
        check_msg->certificate_bytes[28] == 84,
        "incorrect value for certificate_bytes[28], expected 84, is %d",
        check_msg->certificate_bytes[28]);
    ck_assert_msg(
        check_msg->certificate_bytes[29] == 87,
        "incorrect value for certificate_bytes[29], expected 87, is %d",
        check_msg->certificate_bytes[29]);
    ck_assert_msg(
        check_msg->certificate_bytes[30] == 90,
        "incorrect value for certificate_bytes[30], expected 90, is %d",
        check_msg->certificate_bytes[30]);
    ck_assert_msg(
        check_msg->certificate_bytes[31] == 93,
        "incorrect value for certificate_bytes[31], expected 93, is %d",
        check_msg->certificate_bytes[31]);
    ck_assert_msg(
        check_msg->certificate_bytes[32] == 96,
        "incorrect value for certificate_bytes[32], expected 96, is %d",
        check_msg->certificate_bytes[32]);
    ck_assert_msg(
        check_msg->certificate_bytes[33] == 99,
        "incorrect value for certificate_bytes[33], expected 99, is %d",
        check_msg->certificate_bytes[33]);
    ck_assert_msg(
        check_msg->certificate_bytes[34] == 102,
        "incorrect value for certificate_bytes[34], expected 102, is %d",
        check_msg->certificate_bytes[34]);
    ck_assert_msg(
        check_msg->certificate_bytes[35] == 105,
        "incorrect value for certificate_bytes[35], expected 105, is %d",
        check_msg->certificate_bytes[35]);
    ck_assert_msg(
        check_msg->certificate_bytes[36] == 108,
        "incorrect value for certificate_bytes[36], expected 108, is %d",
        check_msg->certificate_bytes[36]);
    ck_assert_msg(
        check_msg->certificate_bytes[37] == 111,
        "incorrect value for certificate_bytes[37], expected 111, is %d",
        check_msg->certificate_bytes[37]);
    ck_assert_msg(
        check_msg->certificate_bytes[38] == 114,
        "incorrect value for certificate_bytes[38], expected 114, is %d",
        check_msg->certificate_bytes[38]);
    ck_assert_msg(
        check_msg->certificate_bytes[39] == 117,
        "incorrect value for certificate_bytes[39], expected 117, is %d",
        check_msg->certificate_bytes[39]);
    ck_assert_msg(
        check_msg->certificate_bytes[40] == 120,
        "incorrect value for certificate_bytes[40], expected 120, is %d",
        check_msg->certificate_bytes[40]);
    ck_assert_msg(
        check_msg->certificate_bytes[41] == 123,
        "incorrect value for certificate_bytes[41], expected 123, is %d",
        check_msg->certificate_bytes[41]);
    ck_assert_msg(
        check_msg->certificate_bytes[42] == 126,
        "incorrect value for certificate_bytes[42], expected 126, is %d",
        check_msg->certificate_bytes[42]);
    ck_assert_msg(
        check_msg->certificate_bytes[43] == 129,
        "incorrect value for certificate_bytes[43], expected 129, is %d",
        check_msg->certificate_bytes[43]);
    ck_assert_msg(
        check_msg->certificate_bytes[44] == 132,
        "incorrect value for certificate_bytes[44], expected 132, is %d",
        check_msg->certificate_bytes[44]);
    ck_assert_msg(
        check_msg->certificate_bytes[45] == 135,
        "incorrect value for certificate_bytes[45], expected 135, is %d",
        check_msg->certificate_bytes[45]);
    ck_assert_msg(
        check_msg->certificate_bytes[46] == 138,
        "incorrect value for certificate_bytes[46], expected 138, is %d",
        check_msg->certificate_bytes[46]);
    ck_assert_msg(
        check_msg->certificate_bytes[47] == 141,
        "incorrect value for certificate_bytes[47], expected 141, is %d",
        check_msg->certificate_bytes[47]);
    ck_assert_msg(
        check_msg->certificate_bytes[48] == 144,
        "incorrect value for certificate_bytes[48], expected 144, is %d",
        check_msg->certificate_bytes[48]);
    ck_assert_msg(
        check_msg->certificate_bytes[49] == 147,
        "incorrect value for certificate_bytes[49], expected 147, is %d",
        check_msg->certificate_bytes[49]);
    ck_assert_msg(
        check_msg->certificate_bytes[50] == 150,
        "incorrect value for certificate_bytes[50], expected 150, is %d",
        check_msg->certificate_bytes[50]);
    ck_assert_msg(
        check_msg->certificate_bytes[51] == 153,
        "incorrect value for certificate_bytes[51], expected 153, is %d",
        check_msg->certificate_bytes[51]);
    ck_assert_msg(
        check_msg->certificate_bytes[52] == 156,
        "incorrect value for certificate_bytes[52], expected 156, is %d",
        check_msg->certificate_bytes[52]);
    ck_assert_msg(
        check_msg->certificate_bytes[53] == 159,
        "incorrect value for certificate_bytes[53], expected 159, is %d",
        check_msg->certificate_bytes[53]);
    ck_assert_msg(
        check_msg->certificate_bytes[54] == 162,
        "incorrect value for certificate_bytes[54], expected 162, is %d",
        check_msg->certificate_bytes[54]);
    ck_assert_msg(
        check_msg->certificate_bytes[55] == 165,
        "incorrect value for certificate_bytes[55], expected 165, is %d",
        check_msg->certificate_bytes[55]);
    ck_assert_msg(
        check_msg->certificate_bytes[56] == 168,
        "incorrect value for certificate_bytes[56], expected 168, is %d",
        check_msg->certificate_bytes[56]);
    ck_assert_msg(
        check_msg->certificate_bytes[57] == 171,
        "incorrect value for certificate_bytes[57], expected 171, is %d",
        check_msg->certificate_bytes[57]);
    ck_assert_msg(
        check_msg->certificate_bytes[58] == 174,
        "incorrect value for certificate_bytes[58], expected 174, is %d",
        check_msg->certificate_bytes[58]);
    ck_assert_msg(
        check_msg->certificate_bytes[59] == 177,
        "incorrect value for certificate_bytes[59], expected 177, is %d",
        check_msg->certificate_bytes[59]);
    ck_assert_msg(
        check_msg->certificate_bytes[60] == 180,
        "incorrect value for certificate_bytes[60], expected 180, is %d",
        check_msg->certificate_bytes[60]);
    ck_assert_msg(
        check_msg->certificate_bytes[61] == 183,
        "incorrect value for certificate_bytes[61], expected 183, is %d",
        check_msg->certificate_bytes[61]);
    ck_assert_msg(
        check_msg->certificate_bytes[62] == 186,
        "incorrect value for certificate_bytes[62], expected 186, is %d",
        check_msg->certificate_bytes[62]);
    ck_assert_msg(
        check_msg->certificate_bytes[63] == 189,
        "incorrect value for certificate_bytes[63], expected 189, is %d",
        check_msg->certificate_bytes[63]);
    ck_assert_msg(
        check_msg->certificate_bytes[64] == 192,
        "incorrect value for certificate_bytes[64], expected 192, is %d",
        check_msg->certificate_bytes[64]);
    ck_assert_msg(
        check_msg->certificate_bytes[65] == 195,
        "incorrect value for certificate_bytes[65], expected 195, is %d",
        check_msg->certificate_bytes[65]);
    ck_assert_msg(
        check_msg->certificate_bytes[66] == 198,
        "incorrect value for certificate_bytes[66], expected 198, is %d",
        check_msg->certificate_bytes[66]);
    ck_assert_msg(
        check_msg->certificate_bytes[67] == 201,
        "incorrect value for certificate_bytes[67], expected 201, is %d",
        check_msg->certificate_bytes[67]);
    ck_assert_msg(
        check_msg->certificate_bytes[68] == 204,
        "incorrect value for certificate_bytes[68], expected 204, is %d",
        check_msg->certificate_bytes[68]);
    ck_assert_msg(
        check_msg->certificate_bytes[69] == 207,
        "incorrect value for certificate_bytes[69], expected 207, is %d",
        check_msg->certificate_bytes[69]);
    ck_assert_msg(
        check_msg->certificate_bytes[70] == 210,
        "incorrect value for certificate_bytes[70], expected 210, is %d",
        check_msg->certificate_bytes[70]);
    ck_assert_msg(
        check_msg->certificate_bytes[71] == 213,
        "incorrect value for certificate_bytes[71], expected 213, is %d",
        check_msg->certificate_bytes[71]);
    ck_assert_msg(
        check_msg->certificate_bytes[72] == 216,
        "incorrect value for certificate_bytes[72], expected 216, is %d",
        check_msg->certificate_bytes[72]);
    ck_assert_msg(
        check_msg->certificate_bytes[73] == 219,
        "incorrect value for certificate_bytes[73], expected 219, is %d",
        check_msg->certificate_bytes[73]);
    ck_assert_msg(
        check_msg->certificate_bytes[74] == 222,
        "incorrect value for certificate_bytes[74], expected 222, is %d",
        check_msg->certificate_bytes[74]);
    ck_assert_msg(
        check_msg->certificate_bytes[75] == 225,
        "incorrect value for certificate_bytes[75], expected 225, is %d",
        check_msg->certificate_bytes[75]);
    ck_assert_msg(
        check_msg->certificate_bytes[76] == 228,
        "incorrect value for certificate_bytes[76], expected 228, is %d",
        check_msg->certificate_bytes[76]);
    ck_assert_msg(
        check_msg->certificate_bytes[77] == 231,
        "incorrect value for certificate_bytes[77], expected 231, is %d",
        check_msg->certificate_bytes[77]);
    ck_assert_msg(
        check_msg->certificate_bytes[78] == 234,
        "incorrect value for certificate_bytes[78], expected 234, is %d",
        check_msg->certificate_bytes[78]);
    ck_assert_msg(
        check_msg->certificate_bytes[79] == 237,
        "incorrect value for certificate_bytes[79], expected 237, is %d",
        check_msg->certificate_bytes[79]);
    ck_assert_msg(
        check_msg->certificate_bytes[80] == 240,
        "incorrect value for certificate_bytes[80], expected 240, is %d",
        check_msg->certificate_bytes[80]);
    ck_assert_msg(
        check_msg->certificate_bytes[81] == 243,
        "incorrect value for certificate_bytes[81], expected 243, is %d",
        check_msg->certificate_bytes[81]);
    ck_assert_msg(
        check_msg->certificate_bytes[82] == 246,
        "incorrect value for certificate_bytes[82], expected 246, is %d",
        check_msg->certificate_bytes[82]);
    ck_assert_msg(
        check_msg->certificate_bytes[83] == 249,
        "incorrect value for certificate_bytes[83], expected 249, is %d",
        check_msg->certificate_bytes[83]);
    ck_assert_msg(
        check_msg->certificate_bytes[84] == 252,
        "incorrect value for certificate_bytes[84], expected 252, is %d",
        check_msg->certificate_bytes[84]);
    ck_assert_msg(check_msg->fingerprint[0] == 100,
                  "incorrect value for fingerprint[0], expected 100, is %d",
                  check_msg->fingerprint[0]);
    ck_assert_msg(check_msg->fingerprint[1] == 101,
                  "incorrect value for fingerprint[1], expected 101, is %d",
                  check_msg->fingerprint[1]);
    ck_assert_msg(check_msg->fingerprint[2] == 102,
                  "incorrect value for fingerprint[2], expected 102, is %d",
                  check_msg->fingerprint[2]);
    ck_assert_msg(check_msg->fingerprint[3] == 103,
                  "incorrect value for fingerprint[3], expected 103, is %d",
                  check_msg->fingerprint[3]);
    ck_assert_msg(check_msg->fingerprint[4] == 104,
                  "incorrect value for fingerprint[4], expected 104, is %d",
                  check_msg->fingerprint[4]);
    ck_assert_msg(check_msg->fingerprint[5] == 105,
                  "incorrect value for fingerprint[5], expected 105, is %d",
                  check_msg->fingerprint[5]);
    ck_assert_msg(check_msg->fingerprint[6] == 106,
                  "incorrect value for fingerprint[6], expected 106, is %d",
                  check_msg->fingerprint[6]);
    ck_assert_msg(check_msg->fingerprint[7] == 107,
                  "incorrect value for fingerprint[7], expected 107, is %d",
                  check_msg->fingerprint[7]);
    ck_assert_msg(check_msg->fingerprint[8] == 108,
                  "incorrect value for fingerprint[8], expected 108, is %d",
                  check_msg->fingerprint[8]);
    ck_assert_msg(check_msg->fingerprint[9] == 109,
                  "incorrect value for fingerprint[9], expected 109, is %d",
                  check_msg->fingerprint[9]);
    ck_assert_msg(check_msg->fingerprint[10] == 110,
                  "incorrect value for fingerprint[10], expected 110, is %d",
                  check_msg->fingerprint[10]);
    ck_assert_msg(check_msg->fingerprint[11] == 111,
                  "incorrect value for fingerprint[11], expected 111, is %d",
                  check_msg->fingerprint[11]);
    ck_assert_msg(check_msg->fingerprint[12] == 112,
                  "incorrect value for fingerprint[12], expected 112, is %d",
                  check_msg->fingerprint[12]);
    ck_assert_msg(check_msg->fingerprint[13] == 113,
                  "incorrect value for fingerprint[13], expected 113, is %d",
                  check_msg->fingerprint[13]);
    ck_assert_msg(check_msg->fingerprint[14] == 114,
                  "incorrect value for fingerprint[14], expected 114, is %d",
                  check_msg->fingerprint[14]);
    ck_assert_msg(check_msg->fingerprint[15] == 115,
                  "incorrect value for fingerprint[15], expected 115, is %d",
                  check_msg->fingerprint[15]);
    ck_assert_msg(check_msg->fingerprint[16] == 116,
                  "incorrect value for fingerprint[16], expected 116, is %d",
                  check_msg->fingerprint[16]);
    ck_assert_msg(check_msg->fingerprint[17] == 117,
                  "incorrect value for fingerprint[17], expected 117, is %d",
                  check_msg->fingerprint[17]);
    ck_assert_msg(check_msg->fingerprint[18] == 118,
                  "incorrect value for fingerprint[18], expected 118, is %d",
                  check_msg->fingerprint[18]);
    ck_assert_msg(check_msg->fingerprint[19] == 119,
                  "incorrect value for fingerprint[19], expected 119, is %d",
                  check_msg->fingerprint[19]);
    ck_assert_msg(check_msg->n_msg == 16,
                  "incorrect value for n_msg, expected 16, is %d",
                  check_msg->n_msg);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_signing_MsgEd25519Certificate_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_signing_MsgEd25519Certificate");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_signing_MsgEd25519Certificate");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_signing_MsgEd25519Certificate);
  suite_add_tcase(s, tc_acq);
  return s;
}