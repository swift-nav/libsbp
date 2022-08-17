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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519Signature.yaml by
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

START_TEST(test_legacy_auto_check_sbp_signing_MsgEd25519Signature) {
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

    sbp_payload_callback_register(&sbp_state, 0xC01, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0xC01, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  1,   12,  148, 38,  184, 0,   1,   2,   3,   4,   5,   6,   7,
        8,   9,   10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,
        22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,
        36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,
        50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,
        100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
        114, 115, 116, 117, 118, 119, 136, 19,  0,   0,   114, 20,  0,   0,
        92,  21,  0,   0,   70,  22,  0,   0,   48,  23,  0,   0,   26,  24,
        0,   0,   4,   25,  0,   0,   238, 25,  0,   0,   216, 26,  0,   0,
        194, 27,  0,   0,   172, 28,  0,   0,   150, 29,  0,   0,   128, 30,
        0,   0,   106, 31,  0,   0,   84,  32,  0,   0,   62,  33,  0,   0,
        40,  34,  0,   0,   18,  35,  0,   0,   252, 35,  0,   0,   230, 36,
        0,   0,   208, 37,  0,   0,   186, 38,  0,   0,   164, 39,  0,   0,
        142, 40,  0,   0,   120, 41,  0,   0,   188, 56,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ed25519_signature_t *test_msg =
        (msg_ed25519_signature_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
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
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[0] = 0;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[1] = 1;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[2] = 2;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[3] = 3;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[4] = 4;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[5] = 5;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[6] = 6;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[7] = 7;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[8] = 8;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[9] = 9;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[10] = 10;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[11] = 11;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[12] = 12;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[13] = 13;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[14] = 14;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[15] = 15;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[16] = 16;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[17] = 17;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[18] = 18;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[19] = 19;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[20] = 20;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[21] = 21;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[22] = 22;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[23] = 23;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[24] = 24;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[25] = 25;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[26] = 26;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[27] = 27;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[28] = 28;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[29] = 29;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[30] = 30;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[31] = 31;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[32] = 32;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[33] = 33;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[34] = 34;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[35] = 35;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[36] = 36;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[37] = 37;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[38] = 38;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[39] = 39;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[40] = 40;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[41] = 41;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[42] = 42;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[43] = 43;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[44] = 44;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[45] = 45;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[46] = 46;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[47] = 47;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[48] = 48;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[49] = 49;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[50] = 50;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[51] = 51;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[52] = 52;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[53] = 53;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[54] = 54;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[55] = 55;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[56] = 56;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[57] = 57;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[58] = 58;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[59] = 59;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[60] = 60;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[61] = 61;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[62] = 62;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[63] = 63;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[0] = 5000;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[1] = 5234;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[2] = 5468;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[3] = 5702;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[4] = 5936;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[5] = 6170;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[6] = 6404;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[7] = 6638;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[8] = 6872;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[9] = 7106;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[10] = 7340;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[11] = 7574;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[12] = 7808;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[13] = 8042;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[14] = 8276;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[15] = 8510;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[16] = 8744;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[17] = 8978;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[18] = 9212;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[19] = 9446;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[20] = 9680;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[21] = 9914;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[22] = 10148;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[23] = 10382;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[24] = 10616;
    sbp_payload_send(&sbp_state, 0xC01, 9876, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_msg.sender_id == 9876,
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
    ck_assert_msg(last_frame.sender_id == 9876,
                  "frame_callback: sender_id decoded incorrectly");
    ck_assert_msg(last_frame.msg_type == 0xC01,
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
    msg_ed25519_signature_t *check_msg =
        (msg_ed25519_signature_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
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
    ck_assert_msg(check_msg->signature[0] == 0,
                  "incorrect value for signature[0], expected 0, is %d",
                  check_msg->signature[0]);
    ck_assert_msg(check_msg->signature[1] == 1,
                  "incorrect value for signature[1], expected 1, is %d",
                  check_msg->signature[1]);
    ck_assert_msg(check_msg->signature[2] == 2,
                  "incorrect value for signature[2], expected 2, is %d",
                  check_msg->signature[2]);
    ck_assert_msg(check_msg->signature[3] == 3,
                  "incorrect value for signature[3], expected 3, is %d",
                  check_msg->signature[3]);
    ck_assert_msg(check_msg->signature[4] == 4,
                  "incorrect value for signature[4], expected 4, is %d",
                  check_msg->signature[4]);
    ck_assert_msg(check_msg->signature[5] == 5,
                  "incorrect value for signature[5], expected 5, is %d",
                  check_msg->signature[5]);
    ck_assert_msg(check_msg->signature[6] == 6,
                  "incorrect value for signature[6], expected 6, is %d",
                  check_msg->signature[6]);
    ck_assert_msg(check_msg->signature[7] == 7,
                  "incorrect value for signature[7], expected 7, is %d",
                  check_msg->signature[7]);
    ck_assert_msg(check_msg->signature[8] == 8,
                  "incorrect value for signature[8], expected 8, is %d",
                  check_msg->signature[8]);
    ck_assert_msg(check_msg->signature[9] == 9,
                  "incorrect value for signature[9], expected 9, is %d",
                  check_msg->signature[9]);
    ck_assert_msg(check_msg->signature[10] == 10,
                  "incorrect value for signature[10], expected 10, is %d",
                  check_msg->signature[10]);
    ck_assert_msg(check_msg->signature[11] == 11,
                  "incorrect value for signature[11], expected 11, is %d",
                  check_msg->signature[11]);
    ck_assert_msg(check_msg->signature[12] == 12,
                  "incorrect value for signature[12], expected 12, is %d",
                  check_msg->signature[12]);
    ck_assert_msg(check_msg->signature[13] == 13,
                  "incorrect value for signature[13], expected 13, is %d",
                  check_msg->signature[13]);
    ck_assert_msg(check_msg->signature[14] == 14,
                  "incorrect value for signature[14], expected 14, is %d",
                  check_msg->signature[14]);
    ck_assert_msg(check_msg->signature[15] == 15,
                  "incorrect value for signature[15], expected 15, is %d",
                  check_msg->signature[15]);
    ck_assert_msg(check_msg->signature[16] == 16,
                  "incorrect value for signature[16], expected 16, is %d",
                  check_msg->signature[16]);
    ck_assert_msg(check_msg->signature[17] == 17,
                  "incorrect value for signature[17], expected 17, is %d",
                  check_msg->signature[17]);
    ck_assert_msg(check_msg->signature[18] == 18,
                  "incorrect value for signature[18], expected 18, is %d",
                  check_msg->signature[18]);
    ck_assert_msg(check_msg->signature[19] == 19,
                  "incorrect value for signature[19], expected 19, is %d",
                  check_msg->signature[19]);
    ck_assert_msg(check_msg->signature[20] == 20,
                  "incorrect value for signature[20], expected 20, is %d",
                  check_msg->signature[20]);
    ck_assert_msg(check_msg->signature[21] == 21,
                  "incorrect value for signature[21], expected 21, is %d",
                  check_msg->signature[21]);
    ck_assert_msg(check_msg->signature[22] == 22,
                  "incorrect value for signature[22], expected 22, is %d",
                  check_msg->signature[22]);
    ck_assert_msg(check_msg->signature[23] == 23,
                  "incorrect value for signature[23], expected 23, is %d",
                  check_msg->signature[23]);
    ck_assert_msg(check_msg->signature[24] == 24,
                  "incorrect value for signature[24], expected 24, is %d",
                  check_msg->signature[24]);
    ck_assert_msg(check_msg->signature[25] == 25,
                  "incorrect value for signature[25], expected 25, is %d",
                  check_msg->signature[25]);
    ck_assert_msg(check_msg->signature[26] == 26,
                  "incorrect value for signature[26], expected 26, is %d",
                  check_msg->signature[26]);
    ck_assert_msg(check_msg->signature[27] == 27,
                  "incorrect value for signature[27], expected 27, is %d",
                  check_msg->signature[27]);
    ck_assert_msg(check_msg->signature[28] == 28,
                  "incorrect value for signature[28], expected 28, is %d",
                  check_msg->signature[28]);
    ck_assert_msg(check_msg->signature[29] == 29,
                  "incorrect value for signature[29], expected 29, is %d",
                  check_msg->signature[29]);
    ck_assert_msg(check_msg->signature[30] == 30,
                  "incorrect value for signature[30], expected 30, is %d",
                  check_msg->signature[30]);
    ck_assert_msg(check_msg->signature[31] == 31,
                  "incorrect value for signature[31], expected 31, is %d",
                  check_msg->signature[31]);
    ck_assert_msg(check_msg->signature[32] == 32,
                  "incorrect value for signature[32], expected 32, is %d",
                  check_msg->signature[32]);
    ck_assert_msg(check_msg->signature[33] == 33,
                  "incorrect value for signature[33], expected 33, is %d",
                  check_msg->signature[33]);
    ck_assert_msg(check_msg->signature[34] == 34,
                  "incorrect value for signature[34], expected 34, is %d",
                  check_msg->signature[34]);
    ck_assert_msg(check_msg->signature[35] == 35,
                  "incorrect value for signature[35], expected 35, is %d",
                  check_msg->signature[35]);
    ck_assert_msg(check_msg->signature[36] == 36,
                  "incorrect value for signature[36], expected 36, is %d",
                  check_msg->signature[36]);
    ck_assert_msg(check_msg->signature[37] == 37,
                  "incorrect value for signature[37], expected 37, is %d",
                  check_msg->signature[37]);
    ck_assert_msg(check_msg->signature[38] == 38,
                  "incorrect value for signature[38], expected 38, is %d",
                  check_msg->signature[38]);
    ck_assert_msg(check_msg->signature[39] == 39,
                  "incorrect value for signature[39], expected 39, is %d",
                  check_msg->signature[39]);
    ck_assert_msg(check_msg->signature[40] == 40,
                  "incorrect value for signature[40], expected 40, is %d",
                  check_msg->signature[40]);
    ck_assert_msg(check_msg->signature[41] == 41,
                  "incorrect value for signature[41], expected 41, is %d",
                  check_msg->signature[41]);
    ck_assert_msg(check_msg->signature[42] == 42,
                  "incorrect value for signature[42], expected 42, is %d",
                  check_msg->signature[42]);
    ck_assert_msg(check_msg->signature[43] == 43,
                  "incorrect value for signature[43], expected 43, is %d",
                  check_msg->signature[43]);
    ck_assert_msg(check_msg->signature[44] == 44,
                  "incorrect value for signature[44], expected 44, is %d",
                  check_msg->signature[44]);
    ck_assert_msg(check_msg->signature[45] == 45,
                  "incorrect value for signature[45], expected 45, is %d",
                  check_msg->signature[45]);
    ck_assert_msg(check_msg->signature[46] == 46,
                  "incorrect value for signature[46], expected 46, is %d",
                  check_msg->signature[46]);
    ck_assert_msg(check_msg->signature[47] == 47,
                  "incorrect value for signature[47], expected 47, is %d",
                  check_msg->signature[47]);
    ck_assert_msg(check_msg->signature[48] == 48,
                  "incorrect value for signature[48], expected 48, is %d",
                  check_msg->signature[48]);
    ck_assert_msg(check_msg->signature[49] == 49,
                  "incorrect value for signature[49], expected 49, is %d",
                  check_msg->signature[49]);
    ck_assert_msg(check_msg->signature[50] == 50,
                  "incorrect value for signature[50], expected 50, is %d",
                  check_msg->signature[50]);
    ck_assert_msg(check_msg->signature[51] == 51,
                  "incorrect value for signature[51], expected 51, is %d",
                  check_msg->signature[51]);
    ck_assert_msg(check_msg->signature[52] == 52,
                  "incorrect value for signature[52], expected 52, is %d",
                  check_msg->signature[52]);
    ck_assert_msg(check_msg->signature[53] == 53,
                  "incorrect value for signature[53], expected 53, is %d",
                  check_msg->signature[53]);
    ck_assert_msg(check_msg->signature[54] == 54,
                  "incorrect value for signature[54], expected 54, is %d",
                  check_msg->signature[54]);
    ck_assert_msg(check_msg->signature[55] == 55,
                  "incorrect value for signature[55], expected 55, is %d",
                  check_msg->signature[55]);
    ck_assert_msg(check_msg->signature[56] == 56,
                  "incorrect value for signature[56], expected 56, is %d",
                  check_msg->signature[56]);
    ck_assert_msg(check_msg->signature[57] == 57,
                  "incorrect value for signature[57], expected 57, is %d",
                  check_msg->signature[57]);
    ck_assert_msg(check_msg->signature[58] == 58,
                  "incorrect value for signature[58], expected 58, is %d",
                  check_msg->signature[58]);
    ck_assert_msg(check_msg->signature[59] == 59,
                  "incorrect value for signature[59], expected 59, is %d",
                  check_msg->signature[59]);
    ck_assert_msg(check_msg->signature[60] == 60,
                  "incorrect value for signature[60], expected 60, is %d",
                  check_msg->signature[60]);
    ck_assert_msg(check_msg->signature[61] == 61,
                  "incorrect value for signature[61], expected 61, is %d",
                  check_msg->signature[61]);
    ck_assert_msg(check_msg->signature[62] == 62,
                  "incorrect value for signature[62], expected 62, is %d",
                  check_msg->signature[62]);
    ck_assert_msg(check_msg->signature[63] == 63,
                  "incorrect value for signature[63], expected 63, is %d",
                  check_msg->signature[63]);
    ck_assert_msg(
        check_msg->signed_messages[0] == 5000,
        "incorrect value for signed_messages[0], expected 5000, is %d",
        check_msg->signed_messages[0]);
    ck_assert_msg(
        check_msg->signed_messages[1] == 5234,
        "incorrect value for signed_messages[1], expected 5234, is %d",
        check_msg->signed_messages[1]);
    ck_assert_msg(
        check_msg->signed_messages[2] == 5468,
        "incorrect value for signed_messages[2], expected 5468, is %d",
        check_msg->signed_messages[2]);
    ck_assert_msg(
        check_msg->signed_messages[3] == 5702,
        "incorrect value for signed_messages[3], expected 5702, is %d",
        check_msg->signed_messages[3]);
    ck_assert_msg(
        check_msg->signed_messages[4] == 5936,
        "incorrect value for signed_messages[4], expected 5936, is %d",
        check_msg->signed_messages[4]);
    ck_assert_msg(
        check_msg->signed_messages[5] == 6170,
        "incorrect value for signed_messages[5], expected 6170, is %d",
        check_msg->signed_messages[5]);
    ck_assert_msg(
        check_msg->signed_messages[6] == 6404,
        "incorrect value for signed_messages[6], expected 6404, is %d",
        check_msg->signed_messages[6]);
    ck_assert_msg(
        check_msg->signed_messages[7] == 6638,
        "incorrect value for signed_messages[7], expected 6638, is %d",
        check_msg->signed_messages[7]);
    ck_assert_msg(
        check_msg->signed_messages[8] == 6872,
        "incorrect value for signed_messages[8], expected 6872, is %d",
        check_msg->signed_messages[8]);
    ck_assert_msg(
        check_msg->signed_messages[9] == 7106,
        "incorrect value for signed_messages[9], expected 7106, is %d",
        check_msg->signed_messages[9]);
    ck_assert_msg(
        check_msg->signed_messages[10] == 7340,
        "incorrect value for signed_messages[10], expected 7340, is %d",
        check_msg->signed_messages[10]);
    ck_assert_msg(
        check_msg->signed_messages[11] == 7574,
        "incorrect value for signed_messages[11], expected 7574, is %d",
        check_msg->signed_messages[11]);
    ck_assert_msg(
        check_msg->signed_messages[12] == 7808,
        "incorrect value for signed_messages[12], expected 7808, is %d",
        check_msg->signed_messages[12]);
    ck_assert_msg(
        check_msg->signed_messages[13] == 8042,
        "incorrect value for signed_messages[13], expected 8042, is %d",
        check_msg->signed_messages[13]);
    ck_assert_msg(
        check_msg->signed_messages[14] == 8276,
        "incorrect value for signed_messages[14], expected 8276, is %d",
        check_msg->signed_messages[14]);
    ck_assert_msg(
        check_msg->signed_messages[15] == 8510,
        "incorrect value for signed_messages[15], expected 8510, is %d",
        check_msg->signed_messages[15]);
    ck_assert_msg(
        check_msg->signed_messages[16] == 8744,
        "incorrect value for signed_messages[16], expected 8744, is %d",
        check_msg->signed_messages[16]);
    ck_assert_msg(
        check_msg->signed_messages[17] == 8978,
        "incorrect value for signed_messages[17], expected 8978, is %d",
        check_msg->signed_messages[17]);
    ck_assert_msg(
        check_msg->signed_messages[18] == 9212,
        "incorrect value for signed_messages[18], expected 9212, is %d",
        check_msg->signed_messages[18]);
    ck_assert_msg(
        check_msg->signed_messages[19] == 9446,
        "incorrect value for signed_messages[19], expected 9446, is %d",
        check_msg->signed_messages[19]);
    ck_assert_msg(
        check_msg->signed_messages[20] == 9680,
        "incorrect value for signed_messages[20], expected 9680, is %d",
        check_msg->signed_messages[20]);
    ck_assert_msg(
        check_msg->signed_messages[21] == 9914,
        "incorrect value for signed_messages[21], expected 9914, is %d",
        check_msg->signed_messages[21]);
    ck_assert_msg(
        check_msg->signed_messages[22] == 10148,
        "incorrect value for signed_messages[22], expected 10148, is %d",
        check_msg->signed_messages[22]);
    ck_assert_msg(
        check_msg->signed_messages[23] == 10382,
        "incorrect value for signed_messages[23], expected 10382, is %d",
        check_msg->signed_messages[23]);
    ck_assert_msg(
        check_msg->signed_messages[24] == 10616,
        "incorrect value for signed_messages[24], expected 10616, is %d",
        check_msg->signed_messages[24]);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_signing_MsgEd25519Signature_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_signing_MsgEd25519Signature");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_signing_MsgEd25519Signature");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_signing_MsgEd25519Signature);
  suite_add_tcase(s, tc_acq);
  return s;
}