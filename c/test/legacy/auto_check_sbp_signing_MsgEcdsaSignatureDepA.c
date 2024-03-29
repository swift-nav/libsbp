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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepA.yaml by
// generate.py. Do not modify by hand!

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
#include <libsbp/legacy/signing.h>

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

START_TEST(test_legacy_auto_check_sbp_signing_MsgEcdsaSignatureDepA) {
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

    sbp_payload_callback_register(&sbp_state, 0xC06, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0xC06, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85,  6,   12,  66,  0,   255, 0,   1,   2,   1,   2,   3,   4,   0,
        1,   2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,   5,   6,
        7,   0,   1,   2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,
        5,   6,   7,   0,   1,   2,   3,   4,   5,   6,   7,   0,   1,   2,
        3,   4,   5,   6,   7,   0,   1,   2,   3,   4,   5,   6,   7,   0,
        1,   2,   3,   4,   5,   6,   7,   10,  21,  23,  63,  140, 37,  130,
        106, 28,  40,  165, 179, 73,  178, 60,  126, 114, 78,  113, 27,  95,
        3,   62,  104, 145, 96,  19,  92,  123, 14,  90,  153, 183, 9,   72,
        81,  118, 112, 124, 16,  182, 76,  146, 115, 58,  144, 17,  105, 66,
        31,  135, 54,  100, 84,  181, 103, 11,  88,  133, 155, 167, 173, 143,
        86,  158, 20,  168, 132, 141, 102, 50,  48,  71,  147, 53,  87,  1,
        108, 138, 36,  134, 139, 163, 82,  43,  52,  150, 12,  30,  110, 156,
        107, 120, 91,  122, 69,  164, 170, 116, 25,  94,  5,   22,  24,  162,
        175, 38,  157, 98,  44,  160, 47,  97,  142, 8,   74,  13,  177, 15,
        128, 26,  131, 154, 65,  169, 55,  136, 125, 171, 161, 29,  129, 151,
        68,  166, 51,  70,  45,  56,  79,  149, 99,  42,  101, 152, 39,  89,
        180, 64,  49,  6,   80,  172, 32,  109, 2,   119, 93,  176, 0,   33,
        57,  34,  18,  85,  121, 137, 83,  111, 59,  7,   77,  4,   117, 159,
        148, 35,  61,  41,  67,  46,  127, 75,  174, 97,  172,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_ecdsa_signature_dep_a_t *test_msg =
        (msg_ecdsa_signature_dep_a_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->certificate_id) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_id[0]);
    }
    test_msg->certificate_id[0] = 1;
    if (sizeof(test_msg->certificate_id) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_id[0]);
    }
    test_msg->certificate_id[1] = 2;
    if (sizeof(test_msg->certificate_id) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_id[0]);
    }
    test_msg->certificate_id[2] = 3;
    if (sizeof(test_msg->certificate_id) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->certificate_id[0]);
    }
    test_msg->certificate_id[3] = 4;
    test_msg->flags = 0;
    test_msg->on_demand_counter = 2;
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
    test_msg->signature[8] = 0;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[9] = 1;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[10] = 2;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[11] = 3;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[12] = 4;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[13] = 5;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[14] = 6;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[15] = 7;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[16] = 0;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[17] = 1;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[18] = 2;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[19] = 3;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[20] = 4;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[21] = 5;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[22] = 6;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[23] = 7;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[24] = 0;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[25] = 1;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[26] = 2;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[27] = 3;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[28] = 4;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[29] = 5;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[30] = 6;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[31] = 7;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[32] = 0;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[33] = 1;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[34] = 2;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[35] = 3;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[36] = 4;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[37] = 5;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[38] = 6;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[39] = 7;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[40] = 0;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[41] = 1;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[42] = 2;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[43] = 3;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[44] = 4;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[45] = 5;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[46] = 6;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[47] = 7;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[48] = 0;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[49] = 1;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[50] = 2;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[51] = 3;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[52] = 4;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[53] = 5;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[54] = 6;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[55] = 7;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[56] = 0;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[57] = 1;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[58] = 2;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[59] = 3;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[60] = 4;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[61] = 5;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[62] = 6;
    if (sizeof(test_msg->signature) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signature[0]);
    }
    test_msg->signature[63] = 7;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[0] = 10;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[1] = 21;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[2] = 23;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[3] = 63;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[4] = 140;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[5] = 37;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[6] = 130;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[7] = 106;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[8] = 28;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[9] = 40;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[10] = 165;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[11] = 179;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[12] = 73;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[13] = 178;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[14] = 60;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[15] = 126;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[16] = 114;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[17] = 78;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[18] = 113;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[19] = 27;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[20] = 95;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[21] = 3;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[22] = 62;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[23] = 104;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[24] = 145;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[25] = 96;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[26] = 19;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[27] = 92;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[28] = 123;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[29] = 14;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[30] = 90;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[31] = 153;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[32] = 183;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[33] = 9;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[34] = 72;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[35] = 81;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[36] = 118;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[37] = 112;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[38] = 124;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[39] = 16;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[40] = 182;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[41] = 76;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[42] = 146;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[43] = 115;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[44] = 58;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[45] = 144;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[46] = 17;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[47] = 105;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[48] = 66;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[49] = 31;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[50] = 135;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[51] = 54;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[52] = 100;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[53] = 84;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[54] = 181;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[55] = 103;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[56] = 11;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[57] = 88;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[58] = 133;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[59] = 155;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[60] = 167;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[61] = 173;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[62] = 143;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[63] = 86;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[64] = 158;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[65] = 20;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[66] = 168;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[67] = 132;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[68] = 141;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[69] = 102;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[70] = 50;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[71] = 48;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[72] = 71;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[73] = 147;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[74] = 53;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[75] = 87;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[76] = 1;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[77] = 108;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[78] = 138;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[79] = 36;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[80] = 134;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[81] = 139;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[82] = 163;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[83] = 82;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[84] = 43;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[85] = 52;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[86] = 150;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[87] = 12;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[88] = 30;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[89] = 110;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[90] = 156;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[91] = 107;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[92] = 120;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[93] = 91;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[94] = 122;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[95] = 69;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[96] = 164;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[97] = 170;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[98] = 116;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[99] = 25;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[100] = 94;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[101] = 5;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[102] = 22;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[103] = 24;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[104] = 162;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[105] = 175;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[106] = 38;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[107] = 157;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[108] = 98;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[109] = 44;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[110] = 160;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[111] = 47;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[112] = 97;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[113] = 142;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[114] = 8;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[115] = 74;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[116] = 13;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[117] = 177;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[118] = 15;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[119] = 128;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[120] = 26;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[121] = 131;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[122] = 154;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[123] = 65;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[124] = 169;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[125] = 55;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[126] = 136;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[127] = 125;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[128] = 171;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[129] = 161;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[130] = 29;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[131] = 129;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[132] = 151;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[133] = 68;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[134] = 166;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[135] = 51;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[136] = 70;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[137] = 45;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[138] = 56;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[139] = 79;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[140] = 149;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[141] = 99;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[142] = 42;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[143] = 101;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[144] = 152;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[145] = 39;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[146] = 89;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[147] = 180;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[148] = 64;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[149] = 49;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[150] = 6;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[151] = 80;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[152] = 172;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[153] = 32;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[154] = 109;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[155] = 2;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[156] = 119;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[157] = 93;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[158] = 176;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[159] = 0;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[160] = 33;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[161] = 57;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[162] = 34;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[163] = 18;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[164] = 85;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[165] = 121;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[166] = 137;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[167] = 83;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[168] = 111;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[169] = 59;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[170] = 7;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[171] = 77;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[172] = 4;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[173] = 117;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[174] = 159;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[175] = 148;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[176] = 35;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[177] = 61;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[178] = 41;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[179] = 67;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[180] = 46;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[181] = 127;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[182] = 75;
    if (sizeof(test_msg->signed_messages) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->signed_messages[0]);
    }
    test_msg->signed_messages[183] = 174;
    test_msg->stream_counter = 1;
    sbp_payload_send(&sbp_state, 0xC06, 66, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_frame.msg_type == 0xC06,
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
    msg_ecdsa_signature_dep_a_t *check_msg =
        (msg_ecdsa_signature_dep_a_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(check_msg->certificate_id[0] == 1,
                  "incorrect value for certificate_id[0], expected 1, is %d",
                  check_msg->certificate_id[0]);
    ck_assert_msg(check_msg->certificate_id[1] == 2,
                  "incorrect value for certificate_id[1], expected 2, is %d",
                  check_msg->certificate_id[1]);
    ck_assert_msg(check_msg->certificate_id[2] == 3,
                  "incorrect value for certificate_id[2], expected 3, is %d",
                  check_msg->certificate_id[2]);
    ck_assert_msg(check_msg->certificate_id[3] == 4,
                  "incorrect value for certificate_id[3], expected 4, is %d",
                  check_msg->certificate_id[3]);
    ck_assert_msg(check_msg->flags == 0,
                  "incorrect value for flags, expected 0, is %d",
                  check_msg->flags);
    ck_assert_msg(check_msg->on_demand_counter == 2,
                  "incorrect value for on_demand_counter, expected 2, is %d",
                  check_msg->on_demand_counter);
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
    ck_assert_msg(check_msg->signature[8] == 0,
                  "incorrect value for signature[8], expected 0, is %d",
                  check_msg->signature[8]);
    ck_assert_msg(check_msg->signature[9] == 1,
                  "incorrect value for signature[9], expected 1, is %d",
                  check_msg->signature[9]);
    ck_assert_msg(check_msg->signature[10] == 2,
                  "incorrect value for signature[10], expected 2, is %d",
                  check_msg->signature[10]);
    ck_assert_msg(check_msg->signature[11] == 3,
                  "incorrect value for signature[11], expected 3, is %d",
                  check_msg->signature[11]);
    ck_assert_msg(check_msg->signature[12] == 4,
                  "incorrect value for signature[12], expected 4, is %d",
                  check_msg->signature[12]);
    ck_assert_msg(check_msg->signature[13] == 5,
                  "incorrect value for signature[13], expected 5, is %d",
                  check_msg->signature[13]);
    ck_assert_msg(check_msg->signature[14] == 6,
                  "incorrect value for signature[14], expected 6, is %d",
                  check_msg->signature[14]);
    ck_assert_msg(check_msg->signature[15] == 7,
                  "incorrect value for signature[15], expected 7, is %d",
                  check_msg->signature[15]);
    ck_assert_msg(check_msg->signature[16] == 0,
                  "incorrect value for signature[16], expected 0, is %d",
                  check_msg->signature[16]);
    ck_assert_msg(check_msg->signature[17] == 1,
                  "incorrect value for signature[17], expected 1, is %d",
                  check_msg->signature[17]);
    ck_assert_msg(check_msg->signature[18] == 2,
                  "incorrect value for signature[18], expected 2, is %d",
                  check_msg->signature[18]);
    ck_assert_msg(check_msg->signature[19] == 3,
                  "incorrect value for signature[19], expected 3, is %d",
                  check_msg->signature[19]);
    ck_assert_msg(check_msg->signature[20] == 4,
                  "incorrect value for signature[20], expected 4, is %d",
                  check_msg->signature[20]);
    ck_assert_msg(check_msg->signature[21] == 5,
                  "incorrect value for signature[21], expected 5, is %d",
                  check_msg->signature[21]);
    ck_assert_msg(check_msg->signature[22] == 6,
                  "incorrect value for signature[22], expected 6, is %d",
                  check_msg->signature[22]);
    ck_assert_msg(check_msg->signature[23] == 7,
                  "incorrect value for signature[23], expected 7, is %d",
                  check_msg->signature[23]);
    ck_assert_msg(check_msg->signature[24] == 0,
                  "incorrect value for signature[24], expected 0, is %d",
                  check_msg->signature[24]);
    ck_assert_msg(check_msg->signature[25] == 1,
                  "incorrect value for signature[25], expected 1, is %d",
                  check_msg->signature[25]);
    ck_assert_msg(check_msg->signature[26] == 2,
                  "incorrect value for signature[26], expected 2, is %d",
                  check_msg->signature[26]);
    ck_assert_msg(check_msg->signature[27] == 3,
                  "incorrect value for signature[27], expected 3, is %d",
                  check_msg->signature[27]);
    ck_assert_msg(check_msg->signature[28] == 4,
                  "incorrect value for signature[28], expected 4, is %d",
                  check_msg->signature[28]);
    ck_assert_msg(check_msg->signature[29] == 5,
                  "incorrect value for signature[29], expected 5, is %d",
                  check_msg->signature[29]);
    ck_assert_msg(check_msg->signature[30] == 6,
                  "incorrect value for signature[30], expected 6, is %d",
                  check_msg->signature[30]);
    ck_assert_msg(check_msg->signature[31] == 7,
                  "incorrect value for signature[31], expected 7, is %d",
                  check_msg->signature[31]);
    ck_assert_msg(check_msg->signature[32] == 0,
                  "incorrect value for signature[32], expected 0, is %d",
                  check_msg->signature[32]);
    ck_assert_msg(check_msg->signature[33] == 1,
                  "incorrect value for signature[33], expected 1, is %d",
                  check_msg->signature[33]);
    ck_assert_msg(check_msg->signature[34] == 2,
                  "incorrect value for signature[34], expected 2, is %d",
                  check_msg->signature[34]);
    ck_assert_msg(check_msg->signature[35] == 3,
                  "incorrect value for signature[35], expected 3, is %d",
                  check_msg->signature[35]);
    ck_assert_msg(check_msg->signature[36] == 4,
                  "incorrect value for signature[36], expected 4, is %d",
                  check_msg->signature[36]);
    ck_assert_msg(check_msg->signature[37] == 5,
                  "incorrect value for signature[37], expected 5, is %d",
                  check_msg->signature[37]);
    ck_assert_msg(check_msg->signature[38] == 6,
                  "incorrect value for signature[38], expected 6, is %d",
                  check_msg->signature[38]);
    ck_assert_msg(check_msg->signature[39] == 7,
                  "incorrect value for signature[39], expected 7, is %d",
                  check_msg->signature[39]);
    ck_assert_msg(check_msg->signature[40] == 0,
                  "incorrect value for signature[40], expected 0, is %d",
                  check_msg->signature[40]);
    ck_assert_msg(check_msg->signature[41] == 1,
                  "incorrect value for signature[41], expected 1, is %d",
                  check_msg->signature[41]);
    ck_assert_msg(check_msg->signature[42] == 2,
                  "incorrect value for signature[42], expected 2, is %d",
                  check_msg->signature[42]);
    ck_assert_msg(check_msg->signature[43] == 3,
                  "incorrect value for signature[43], expected 3, is %d",
                  check_msg->signature[43]);
    ck_assert_msg(check_msg->signature[44] == 4,
                  "incorrect value for signature[44], expected 4, is %d",
                  check_msg->signature[44]);
    ck_assert_msg(check_msg->signature[45] == 5,
                  "incorrect value for signature[45], expected 5, is %d",
                  check_msg->signature[45]);
    ck_assert_msg(check_msg->signature[46] == 6,
                  "incorrect value for signature[46], expected 6, is %d",
                  check_msg->signature[46]);
    ck_assert_msg(check_msg->signature[47] == 7,
                  "incorrect value for signature[47], expected 7, is %d",
                  check_msg->signature[47]);
    ck_assert_msg(check_msg->signature[48] == 0,
                  "incorrect value for signature[48], expected 0, is %d",
                  check_msg->signature[48]);
    ck_assert_msg(check_msg->signature[49] == 1,
                  "incorrect value for signature[49], expected 1, is %d",
                  check_msg->signature[49]);
    ck_assert_msg(check_msg->signature[50] == 2,
                  "incorrect value for signature[50], expected 2, is %d",
                  check_msg->signature[50]);
    ck_assert_msg(check_msg->signature[51] == 3,
                  "incorrect value for signature[51], expected 3, is %d",
                  check_msg->signature[51]);
    ck_assert_msg(check_msg->signature[52] == 4,
                  "incorrect value for signature[52], expected 4, is %d",
                  check_msg->signature[52]);
    ck_assert_msg(check_msg->signature[53] == 5,
                  "incorrect value for signature[53], expected 5, is %d",
                  check_msg->signature[53]);
    ck_assert_msg(check_msg->signature[54] == 6,
                  "incorrect value for signature[54], expected 6, is %d",
                  check_msg->signature[54]);
    ck_assert_msg(check_msg->signature[55] == 7,
                  "incorrect value for signature[55], expected 7, is %d",
                  check_msg->signature[55]);
    ck_assert_msg(check_msg->signature[56] == 0,
                  "incorrect value for signature[56], expected 0, is %d",
                  check_msg->signature[56]);
    ck_assert_msg(check_msg->signature[57] == 1,
                  "incorrect value for signature[57], expected 1, is %d",
                  check_msg->signature[57]);
    ck_assert_msg(check_msg->signature[58] == 2,
                  "incorrect value for signature[58], expected 2, is %d",
                  check_msg->signature[58]);
    ck_assert_msg(check_msg->signature[59] == 3,
                  "incorrect value for signature[59], expected 3, is %d",
                  check_msg->signature[59]);
    ck_assert_msg(check_msg->signature[60] == 4,
                  "incorrect value for signature[60], expected 4, is %d",
                  check_msg->signature[60]);
    ck_assert_msg(check_msg->signature[61] == 5,
                  "incorrect value for signature[61], expected 5, is %d",
                  check_msg->signature[61]);
    ck_assert_msg(check_msg->signature[62] == 6,
                  "incorrect value for signature[62], expected 6, is %d",
                  check_msg->signature[62]);
    ck_assert_msg(check_msg->signature[63] == 7,
                  "incorrect value for signature[63], expected 7, is %d",
                  check_msg->signature[63]);
    ck_assert_msg(check_msg->signed_messages[0] == 10,
                  "incorrect value for signed_messages[0], expected 10, is %d",
                  check_msg->signed_messages[0]);
    ck_assert_msg(check_msg->signed_messages[1] == 21,
                  "incorrect value for signed_messages[1], expected 21, is %d",
                  check_msg->signed_messages[1]);
    ck_assert_msg(check_msg->signed_messages[2] == 23,
                  "incorrect value for signed_messages[2], expected 23, is %d",
                  check_msg->signed_messages[2]);
    ck_assert_msg(check_msg->signed_messages[3] == 63,
                  "incorrect value for signed_messages[3], expected 63, is %d",
                  check_msg->signed_messages[3]);
    ck_assert_msg(check_msg->signed_messages[4] == 140,
                  "incorrect value for signed_messages[4], expected 140, is %d",
                  check_msg->signed_messages[4]);
    ck_assert_msg(check_msg->signed_messages[5] == 37,
                  "incorrect value for signed_messages[5], expected 37, is %d",
                  check_msg->signed_messages[5]);
    ck_assert_msg(check_msg->signed_messages[6] == 130,
                  "incorrect value for signed_messages[6], expected 130, is %d",
                  check_msg->signed_messages[6]);
    ck_assert_msg(check_msg->signed_messages[7] == 106,
                  "incorrect value for signed_messages[7], expected 106, is %d",
                  check_msg->signed_messages[7]);
    ck_assert_msg(check_msg->signed_messages[8] == 28,
                  "incorrect value for signed_messages[8], expected 28, is %d",
                  check_msg->signed_messages[8]);
    ck_assert_msg(check_msg->signed_messages[9] == 40,
                  "incorrect value for signed_messages[9], expected 40, is %d",
                  check_msg->signed_messages[9]);
    ck_assert_msg(
        check_msg->signed_messages[10] == 165,
        "incorrect value for signed_messages[10], expected 165, is %d",
        check_msg->signed_messages[10]);
    ck_assert_msg(
        check_msg->signed_messages[11] == 179,
        "incorrect value for signed_messages[11], expected 179, is %d",
        check_msg->signed_messages[11]);
    ck_assert_msg(check_msg->signed_messages[12] == 73,
                  "incorrect value for signed_messages[12], expected 73, is %d",
                  check_msg->signed_messages[12]);
    ck_assert_msg(
        check_msg->signed_messages[13] == 178,
        "incorrect value for signed_messages[13], expected 178, is %d",
        check_msg->signed_messages[13]);
    ck_assert_msg(check_msg->signed_messages[14] == 60,
                  "incorrect value for signed_messages[14], expected 60, is %d",
                  check_msg->signed_messages[14]);
    ck_assert_msg(
        check_msg->signed_messages[15] == 126,
        "incorrect value for signed_messages[15], expected 126, is %d",
        check_msg->signed_messages[15]);
    ck_assert_msg(
        check_msg->signed_messages[16] == 114,
        "incorrect value for signed_messages[16], expected 114, is %d",
        check_msg->signed_messages[16]);
    ck_assert_msg(check_msg->signed_messages[17] == 78,
                  "incorrect value for signed_messages[17], expected 78, is %d",
                  check_msg->signed_messages[17]);
    ck_assert_msg(
        check_msg->signed_messages[18] == 113,
        "incorrect value for signed_messages[18], expected 113, is %d",
        check_msg->signed_messages[18]);
    ck_assert_msg(check_msg->signed_messages[19] == 27,
                  "incorrect value for signed_messages[19], expected 27, is %d",
                  check_msg->signed_messages[19]);
    ck_assert_msg(check_msg->signed_messages[20] == 95,
                  "incorrect value for signed_messages[20], expected 95, is %d",
                  check_msg->signed_messages[20]);
    ck_assert_msg(check_msg->signed_messages[21] == 3,
                  "incorrect value for signed_messages[21], expected 3, is %d",
                  check_msg->signed_messages[21]);
    ck_assert_msg(check_msg->signed_messages[22] == 62,
                  "incorrect value for signed_messages[22], expected 62, is %d",
                  check_msg->signed_messages[22]);
    ck_assert_msg(
        check_msg->signed_messages[23] == 104,
        "incorrect value for signed_messages[23], expected 104, is %d",
        check_msg->signed_messages[23]);
    ck_assert_msg(
        check_msg->signed_messages[24] == 145,
        "incorrect value for signed_messages[24], expected 145, is %d",
        check_msg->signed_messages[24]);
    ck_assert_msg(check_msg->signed_messages[25] == 96,
                  "incorrect value for signed_messages[25], expected 96, is %d",
                  check_msg->signed_messages[25]);
    ck_assert_msg(check_msg->signed_messages[26] == 19,
                  "incorrect value for signed_messages[26], expected 19, is %d",
                  check_msg->signed_messages[26]);
    ck_assert_msg(check_msg->signed_messages[27] == 92,
                  "incorrect value for signed_messages[27], expected 92, is %d",
                  check_msg->signed_messages[27]);
    ck_assert_msg(
        check_msg->signed_messages[28] == 123,
        "incorrect value for signed_messages[28], expected 123, is %d",
        check_msg->signed_messages[28]);
    ck_assert_msg(check_msg->signed_messages[29] == 14,
                  "incorrect value for signed_messages[29], expected 14, is %d",
                  check_msg->signed_messages[29]);
    ck_assert_msg(check_msg->signed_messages[30] == 90,
                  "incorrect value for signed_messages[30], expected 90, is %d",
                  check_msg->signed_messages[30]);
    ck_assert_msg(
        check_msg->signed_messages[31] == 153,
        "incorrect value for signed_messages[31], expected 153, is %d",
        check_msg->signed_messages[31]);
    ck_assert_msg(
        check_msg->signed_messages[32] == 183,
        "incorrect value for signed_messages[32], expected 183, is %d",
        check_msg->signed_messages[32]);
    ck_assert_msg(check_msg->signed_messages[33] == 9,
                  "incorrect value for signed_messages[33], expected 9, is %d",
                  check_msg->signed_messages[33]);
    ck_assert_msg(check_msg->signed_messages[34] == 72,
                  "incorrect value for signed_messages[34], expected 72, is %d",
                  check_msg->signed_messages[34]);
    ck_assert_msg(check_msg->signed_messages[35] == 81,
                  "incorrect value for signed_messages[35], expected 81, is %d",
                  check_msg->signed_messages[35]);
    ck_assert_msg(
        check_msg->signed_messages[36] == 118,
        "incorrect value for signed_messages[36], expected 118, is %d",
        check_msg->signed_messages[36]);
    ck_assert_msg(
        check_msg->signed_messages[37] == 112,
        "incorrect value for signed_messages[37], expected 112, is %d",
        check_msg->signed_messages[37]);
    ck_assert_msg(
        check_msg->signed_messages[38] == 124,
        "incorrect value for signed_messages[38], expected 124, is %d",
        check_msg->signed_messages[38]);
    ck_assert_msg(check_msg->signed_messages[39] == 16,
                  "incorrect value for signed_messages[39], expected 16, is %d",
                  check_msg->signed_messages[39]);
    ck_assert_msg(
        check_msg->signed_messages[40] == 182,
        "incorrect value for signed_messages[40], expected 182, is %d",
        check_msg->signed_messages[40]);
    ck_assert_msg(check_msg->signed_messages[41] == 76,
                  "incorrect value for signed_messages[41], expected 76, is %d",
                  check_msg->signed_messages[41]);
    ck_assert_msg(
        check_msg->signed_messages[42] == 146,
        "incorrect value for signed_messages[42], expected 146, is %d",
        check_msg->signed_messages[42]);
    ck_assert_msg(
        check_msg->signed_messages[43] == 115,
        "incorrect value for signed_messages[43], expected 115, is %d",
        check_msg->signed_messages[43]);
    ck_assert_msg(check_msg->signed_messages[44] == 58,
                  "incorrect value for signed_messages[44], expected 58, is %d",
                  check_msg->signed_messages[44]);
    ck_assert_msg(
        check_msg->signed_messages[45] == 144,
        "incorrect value for signed_messages[45], expected 144, is %d",
        check_msg->signed_messages[45]);
    ck_assert_msg(check_msg->signed_messages[46] == 17,
                  "incorrect value for signed_messages[46], expected 17, is %d",
                  check_msg->signed_messages[46]);
    ck_assert_msg(
        check_msg->signed_messages[47] == 105,
        "incorrect value for signed_messages[47], expected 105, is %d",
        check_msg->signed_messages[47]);
    ck_assert_msg(check_msg->signed_messages[48] == 66,
                  "incorrect value for signed_messages[48], expected 66, is %d",
                  check_msg->signed_messages[48]);
    ck_assert_msg(check_msg->signed_messages[49] == 31,
                  "incorrect value for signed_messages[49], expected 31, is %d",
                  check_msg->signed_messages[49]);
    ck_assert_msg(
        check_msg->signed_messages[50] == 135,
        "incorrect value for signed_messages[50], expected 135, is %d",
        check_msg->signed_messages[50]);
    ck_assert_msg(check_msg->signed_messages[51] == 54,
                  "incorrect value for signed_messages[51], expected 54, is %d",
                  check_msg->signed_messages[51]);
    ck_assert_msg(
        check_msg->signed_messages[52] == 100,
        "incorrect value for signed_messages[52], expected 100, is %d",
        check_msg->signed_messages[52]);
    ck_assert_msg(check_msg->signed_messages[53] == 84,
                  "incorrect value for signed_messages[53], expected 84, is %d",
                  check_msg->signed_messages[53]);
    ck_assert_msg(
        check_msg->signed_messages[54] == 181,
        "incorrect value for signed_messages[54], expected 181, is %d",
        check_msg->signed_messages[54]);
    ck_assert_msg(
        check_msg->signed_messages[55] == 103,
        "incorrect value for signed_messages[55], expected 103, is %d",
        check_msg->signed_messages[55]);
    ck_assert_msg(check_msg->signed_messages[56] == 11,
                  "incorrect value for signed_messages[56], expected 11, is %d",
                  check_msg->signed_messages[56]);
    ck_assert_msg(check_msg->signed_messages[57] == 88,
                  "incorrect value for signed_messages[57], expected 88, is %d",
                  check_msg->signed_messages[57]);
    ck_assert_msg(
        check_msg->signed_messages[58] == 133,
        "incorrect value for signed_messages[58], expected 133, is %d",
        check_msg->signed_messages[58]);
    ck_assert_msg(
        check_msg->signed_messages[59] == 155,
        "incorrect value for signed_messages[59], expected 155, is %d",
        check_msg->signed_messages[59]);
    ck_assert_msg(
        check_msg->signed_messages[60] == 167,
        "incorrect value for signed_messages[60], expected 167, is %d",
        check_msg->signed_messages[60]);
    ck_assert_msg(
        check_msg->signed_messages[61] == 173,
        "incorrect value for signed_messages[61], expected 173, is %d",
        check_msg->signed_messages[61]);
    ck_assert_msg(
        check_msg->signed_messages[62] == 143,
        "incorrect value for signed_messages[62], expected 143, is %d",
        check_msg->signed_messages[62]);
    ck_assert_msg(check_msg->signed_messages[63] == 86,
                  "incorrect value for signed_messages[63], expected 86, is %d",
                  check_msg->signed_messages[63]);
    ck_assert_msg(
        check_msg->signed_messages[64] == 158,
        "incorrect value for signed_messages[64], expected 158, is %d",
        check_msg->signed_messages[64]);
    ck_assert_msg(check_msg->signed_messages[65] == 20,
                  "incorrect value for signed_messages[65], expected 20, is %d",
                  check_msg->signed_messages[65]);
    ck_assert_msg(
        check_msg->signed_messages[66] == 168,
        "incorrect value for signed_messages[66], expected 168, is %d",
        check_msg->signed_messages[66]);
    ck_assert_msg(
        check_msg->signed_messages[67] == 132,
        "incorrect value for signed_messages[67], expected 132, is %d",
        check_msg->signed_messages[67]);
    ck_assert_msg(
        check_msg->signed_messages[68] == 141,
        "incorrect value for signed_messages[68], expected 141, is %d",
        check_msg->signed_messages[68]);
    ck_assert_msg(
        check_msg->signed_messages[69] == 102,
        "incorrect value for signed_messages[69], expected 102, is %d",
        check_msg->signed_messages[69]);
    ck_assert_msg(check_msg->signed_messages[70] == 50,
                  "incorrect value for signed_messages[70], expected 50, is %d",
                  check_msg->signed_messages[70]);
    ck_assert_msg(check_msg->signed_messages[71] == 48,
                  "incorrect value for signed_messages[71], expected 48, is %d",
                  check_msg->signed_messages[71]);
    ck_assert_msg(check_msg->signed_messages[72] == 71,
                  "incorrect value for signed_messages[72], expected 71, is %d",
                  check_msg->signed_messages[72]);
    ck_assert_msg(
        check_msg->signed_messages[73] == 147,
        "incorrect value for signed_messages[73], expected 147, is %d",
        check_msg->signed_messages[73]);
    ck_assert_msg(check_msg->signed_messages[74] == 53,
                  "incorrect value for signed_messages[74], expected 53, is %d",
                  check_msg->signed_messages[74]);
    ck_assert_msg(check_msg->signed_messages[75] == 87,
                  "incorrect value for signed_messages[75], expected 87, is %d",
                  check_msg->signed_messages[75]);
    ck_assert_msg(check_msg->signed_messages[76] == 1,
                  "incorrect value for signed_messages[76], expected 1, is %d",
                  check_msg->signed_messages[76]);
    ck_assert_msg(
        check_msg->signed_messages[77] == 108,
        "incorrect value for signed_messages[77], expected 108, is %d",
        check_msg->signed_messages[77]);
    ck_assert_msg(
        check_msg->signed_messages[78] == 138,
        "incorrect value for signed_messages[78], expected 138, is %d",
        check_msg->signed_messages[78]);
    ck_assert_msg(check_msg->signed_messages[79] == 36,
                  "incorrect value for signed_messages[79], expected 36, is %d",
                  check_msg->signed_messages[79]);
    ck_assert_msg(
        check_msg->signed_messages[80] == 134,
        "incorrect value for signed_messages[80], expected 134, is %d",
        check_msg->signed_messages[80]);
    ck_assert_msg(
        check_msg->signed_messages[81] == 139,
        "incorrect value for signed_messages[81], expected 139, is %d",
        check_msg->signed_messages[81]);
    ck_assert_msg(
        check_msg->signed_messages[82] == 163,
        "incorrect value for signed_messages[82], expected 163, is %d",
        check_msg->signed_messages[82]);
    ck_assert_msg(check_msg->signed_messages[83] == 82,
                  "incorrect value for signed_messages[83], expected 82, is %d",
                  check_msg->signed_messages[83]);
    ck_assert_msg(check_msg->signed_messages[84] == 43,
                  "incorrect value for signed_messages[84], expected 43, is %d",
                  check_msg->signed_messages[84]);
    ck_assert_msg(check_msg->signed_messages[85] == 52,
                  "incorrect value for signed_messages[85], expected 52, is %d",
                  check_msg->signed_messages[85]);
    ck_assert_msg(
        check_msg->signed_messages[86] == 150,
        "incorrect value for signed_messages[86], expected 150, is %d",
        check_msg->signed_messages[86]);
    ck_assert_msg(check_msg->signed_messages[87] == 12,
                  "incorrect value for signed_messages[87], expected 12, is %d",
                  check_msg->signed_messages[87]);
    ck_assert_msg(check_msg->signed_messages[88] == 30,
                  "incorrect value for signed_messages[88], expected 30, is %d",
                  check_msg->signed_messages[88]);
    ck_assert_msg(
        check_msg->signed_messages[89] == 110,
        "incorrect value for signed_messages[89], expected 110, is %d",
        check_msg->signed_messages[89]);
    ck_assert_msg(
        check_msg->signed_messages[90] == 156,
        "incorrect value for signed_messages[90], expected 156, is %d",
        check_msg->signed_messages[90]);
    ck_assert_msg(
        check_msg->signed_messages[91] == 107,
        "incorrect value for signed_messages[91], expected 107, is %d",
        check_msg->signed_messages[91]);
    ck_assert_msg(
        check_msg->signed_messages[92] == 120,
        "incorrect value for signed_messages[92], expected 120, is %d",
        check_msg->signed_messages[92]);
    ck_assert_msg(check_msg->signed_messages[93] == 91,
                  "incorrect value for signed_messages[93], expected 91, is %d",
                  check_msg->signed_messages[93]);
    ck_assert_msg(
        check_msg->signed_messages[94] == 122,
        "incorrect value for signed_messages[94], expected 122, is %d",
        check_msg->signed_messages[94]);
    ck_assert_msg(check_msg->signed_messages[95] == 69,
                  "incorrect value for signed_messages[95], expected 69, is %d",
                  check_msg->signed_messages[95]);
    ck_assert_msg(
        check_msg->signed_messages[96] == 164,
        "incorrect value for signed_messages[96], expected 164, is %d",
        check_msg->signed_messages[96]);
    ck_assert_msg(
        check_msg->signed_messages[97] == 170,
        "incorrect value for signed_messages[97], expected 170, is %d",
        check_msg->signed_messages[97]);
    ck_assert_msg(
        check_msg->signed_messages[98] == 116,
        "incorrect value for signed_messages[98], expected 116, is %d",
        check_msg->signed_messages[98]);
    ck_assert_msg(check_msg->signed_messages[99] == 25,
                  "incorrect value for signed_messages[99], expected 25, is %d",
                  check_msg->signed_messages[99]);
    ck_assert_msg(
        check_msg->signed_messages[100] == 94,
        "incorrect value for signed_messages[100], expected 94, is %d",
        check_msg->signed_messages[100]);
    ck_assert_msg(check_msg->signed_messages[101] == 5,
                  "incorrect value for signed_messages[101], expected 5, is %d",
                  check_msg->signed_messages[101]);
    ck_assert_msg(
        check_msg->signed_messages[102] == 22,
        "incorrect value for signed_messages[102], expected 22, is %d",
        check_msg->signed_messages[102]);
    ck_assert_msg(
        check_msg->signed_messages[103] == 24,
        "incorrect value for signed_messages[103], expected 24, is %d",
        check_msg->signed_messages[103]);
    ck_assert_msg(
        check_msg->signed_messages[104] == 162,
        "incorrect value for signed_messages[104], expected 162, is %d",
        check_msg->signed_messages[104]);
    ck_assert_msg(
        check_msg->signed_messages[105] == 175,
        "incorrect value for signed_messages[105], expected 175, is %d",
        check_msg->signed_messages[105]);
    ck_assert_msg(
        check_msg->signed_messages[106] == 38,
        "incorrect value for signed_messages[106], expected 38, is %d",
        check_msg->signed_messages[106]);
    ck_assert_msg(
        check_msg->signed_messages[107] == 157,
        "incorrect value for signed_messages[107], expected 157, is %d",
        check_msg->signed_messages[107]);
    ck_assert_msg(
        check_msg->signed_messages[108] == 98,
        "incorrect value for signed_messages[108], expected 98, is %d",
        check_msg->signed_messages[108]);
    ck_assert_msg(
        check_msg->signed_messages[109] == 44,
        "incorrect value for signed_messages[109], expected 44, is %d",
        check_msg->signed_messages[109]);
    ck_assert_msg(
        check_msg->signed_messages[110] == 160,
        "incorrect value for signed_messages[110], expected 160, is %d",
        check_msg->signed_messages[110]);
    ck_assert_msg(
        check_msg->signed_messages[111] == 47,
        "incorrect value for signed_messages[111], expected 47, is %d",
        check_msg->signed_messages[111]);
    ck_assert_msg(
        check_msg->signed_messages[112] == 97,
        "incorrect value for signed_messages[112], expected 97, is %d",
        check_msg->signed_messages[112]);
    ck_assert_msg(
        check_msg->signed_messages[113] == 142,
        "incorrect value for signed_messages[113], expected 142, is %d",
        check_msg->signed_messages[113]);
    ck_assert_msg(check_msg->signed_messages[114] == 8,
                  "incorrect value for signed_messages[114], expected 8, is %d",
                  check_msg->signed_messages[114]);
    ck_assert_msg(
        check_msg->signed_messages[115] == 74,
        "incorrect value for signed_messages[115], expected 74, is %d",
        check_msg->signed_messages[115]);
    ck_assert_msg(
        check_msg->signed_messages[116] == 13,
        "incorrect value for signed_messages[116], expected 13, is %d",
        check_msg->signed_messages[116]);
    ck_assert_msg(
        check_msg->signed_messages[117] == 177,
        "incorrect value for signed_messages[117], expected 177, is %d",
        check_msg->signed_messages[117]);
    ck_assert_msg(
        check_msg->signed_messages[118] == 15,
        "incorrect value for signed_messages[118], expected 15, is %d",
        check_msg->signed_messages[118]);
    ck_assert_msg(
        check_msg->signed_messages[119] == 128,
        "incorrect value for signed_messages[119], expected 128, is %d",
        check_msg->signed_messages[119]);
    ck_assert_msg(
        check_msg->signed_messages[120] == 26,
        "incorrect value for signed_messages[120], expected 26, is %d",
        check_msg->signed_messages[120]);
    ck_assert_msg(
        check_msg->signed_messages[121] == 131,
        "incorrect value for signed_messages[121], expected 131, is %d",
        check_msg->signed_messages[121]);
    ck_assert_msg(
        check_msg->signed_messages[122] == 154,
        "incorrect value for signed_messages[122], expected 154, is %d",
        check_msg->signed_messages[122]);
    ck_assert_msg(
        check_msg->signed_messages[123] == 65,
        "incorrect value for signed_messages[123], expected 65, is %d",
        check_msg->signed_messages[123]);
    ck_assert_msg(
        check_msg->signed_messages[124] == 169,
        "incorrect value for signed_messages[124], expected 169, is %d",
        check_msg->signed_messages[124]);
    ck_assert_msg(
        check_msg->signed_messages[125] == 55,
        "incorrect value for signed_messages[125], expected 55, is %d",
        check_msg->signed_messages[125]);
    ck_assert_msg(
        check_msg->signed_messages[126] == 136,
        "incorrect value for signed_messages[126], expected 136, is %d",
        check_msg->signed_messages[126]);
    ck_assert_msg(
        check_msg->signed_messages[127] == 125,
        "incorrect value for signed_messages[127], expected 125, is %d",
        check_msg->signed_messages[127]);
    ck_assert_msg(
        check_msg->signed_messages[128] == 171,
        "incorrect value for signed_messages[128], expected 171, is %d",
        check_msg->signed_messages[128]);
    ck_assert_msg(
        check_msg->signed_messages[129] == 161,
        "incorrect value for signed_messages[129], expected 161, is %d",
        check_msg->signed_messages[129]);
    ck_assert_msg(
        check_msg->signed_messages[130] == 29,
        "incorrect value for signed_messages[130], expected 29, is %d",
        check_msg->signed_messages[130]);
    ck_assert_msg(
        check_msg->signed_messages[131] == 129,
        "incorrect value for signed_messages[131], expected 129, is %d",
        check_msg->signed_messages[131]);
    ck_assert_msg(
        check_msg->signed_messages[132] == 151,
        "incorrect value for signed_messages[132], expected 151, is %d",
        check_msg->signed_messages[132]);
    ck_assert_msg(
        check_msg->signed_messages[133] == 68,
        "incorrect value for signed_messages[133], expected 68, is %d",
        check_msg->signed_messages[133]);
    ck_assert_msg(
        check_msg->signed_messages[134] == 166,
        "incorrect value for signed_messages[134], expected 166, is %d",
        check_msg->signed_messages[134]);
    ck_assert_msg(
        check_msg->signed_messages[135] == 51,
        "incorrect value for signed_messages[135], expected 51, is %d",
        check_msg->signed_messages[135]);
    ck_assert_msg(
        check_msg->signed_messages[136] == 70,
        "incorrect value for signed_messages[136], expected 70, is %d",
        check_msg->signed_messages[136]);
    ck_assert_msg(
        check_msg->signed_messages[137] == 45,
        "incorrect value for signed_messages[137], expected 45, is %d",
        check_msg->signed_messages[137]);
    ck_assert_msg(
        check_msg->signed_messages[138] == 56,
        "incorrect value for signed_messages[138], expected 56, is %d",
        check_msg->signed_messages[138]);
    ck_assert_msg(
        check_msg->signed_messages[139] == 79,
        "incorrect value for signed_messages[139], expected 79, is %d",
        check_msg->signed_messages[139]);
    ck_assert_msg(
        check_msg->signed_messages[140] == 149,
        "incorrect value for signed_messages[140], expected 149, is %d",
        check_msg->signed_messages[140]);
    ck_assert_msg(
        check_msg->signed_messages[141] == 99,
        "incorrect value for signed_messages[141], expected 99, is %d",
        check_msg->signed_messages[141]);
    ck_assert_msg(
        check_msg->signed_messages[142] == 42,
        "incorrect value for signed_messages[142], expected 42, is %d",
        check_msg->signed_messages[142]);
    ck_assert_msg(
        check_msg->signed_messages[143] == 101,
        "incorrect value for signed_messages[143], expected 101, is %d",
        check_msg->signed_messages[143]);
    ck_assert_msg(
        check_msg->signed_messages[144] == 152,
        "incorrect value for signed_messages[144], expected 152, is %d",
        check_msg->signed_messages[144]);
    ck_assert_msg(
        check_msg->signed_messages[145] == 39,
        "incorrect value for signed_messages[145], expected 39, is %d",
        check_msg->signed_messages[145]);
    ck_assert_msg(
        check_msg->signed_messages[146] == 89,
        "incorrect value for signed_messages[146], expected 89, is %d",
        check_msg->signed_messages[146]);
    ck_assert_msg(
        check_msg->signed_messages[147] == 180,
        "incorrect value for signed_messages[147], expected 180, is %d",
        check_msg->signed_messages[147]);
    ck_assert_msg(
        check_msg->signed_messages[148] == 64,
        "incorrect value for signed_messages[148], expected 64, is %d",
        check_msg->signed_messages[148]);
    ck_assert_msg(
        check_msg->signed_messages[149] == 49,
        "incorrect value for signed_messages[149], expected 49, is %d",
        check_msg->signed_messages[149]);
    ck_assert_msg(check_msg->signed_messages[150] == 6,
                  "incorrect value for signed_messages[150], expected 6, is %d",
                  check_msg->signed_messages[150]);
    ck_assert_msg(
        check_msg->signed_messages[151] == 80,
        "incorrect value for signed_messages[151], expected 80, is %d",
        check_msg->signed_messages[151]);
    ck_assert_msg(
        check_msg->signed_messages[152] == 172,
        "incorrect value for signed_messages[152], expected 172, is %d",
        check_msg->signed_messages[152]);
    ck_assert_msg(
        check_msg->signed_messages[153] == 32,
        "incorrect value for signed_messages[153], expected 32, is %d",
        check_msg->signed_messages[153]);
    ck_assert_msg(
        check_msg->signed_messages[154] == 109,
        "incorrect value for signed_messages[154], expected 109, is %d",
        check_msg->signed_messages[154]);
    ck_assert_msg(check_msg->signed_messages[155] == 2,
                  "incorrect value for signed_messages[155], expected 2, is %d",
                  check_msg->signed_messages[155]);
    ck_assert_msg(
        check_msg->signed_messages[156] == 119,
        "incorrect value for signed_messages[156], expected 119, is %d",
        check_msg->signed_messages[156]);
    ck_assert_msg(
        check_msg->signed_messages[157] == 93,
        "incorrect value for signed_messages[157], expected 93, is %d",
        check_msg->signed_messages[157]);
    ck_assert_msg(
        check_msg->signed_messages[158] == 176,
        "incorrect value for signed_messages[158], expected 176, is %d",
        check_msg->signed_messages[158]);
    ck_assert_msg(check_msg->signed_messages[159] == 0,
                  "incorrect value for signed_messages[159], expected 0, is %d",
                  check_msg->signed_messages[159]);
    ck_assert_msg(
        check_msg->signed_messages[160] == 33,
        "incorrect value for signed_messages[160], expected 33, is %d",
        check_msg->signed_messages[160]);
    ck_assert_msg(
        check_msg->signed_messages[161] == 57,
        "incorrect value for signed_messages[161], expected 57, is %d",
        check_msg->signed_messages[161]);
    ck_assert_msg(
        check_msg->signed_messages[162] == 34,
        "incorrect value for signed_messages[162], expected 34, is %d",
        check_msg->signed_messages[162]);
    ck_assert_msg(
        check_msg->signed_messages[163] == 18,
        "incorrect value for signed_messages[163], expected 18, is %d",
        check_msg->signed_messages[163]);
    ck_assert_msg(
        check_msg->signed_messages[164] == 85,
        "incorrect value for signed_messages[164], expected 85, is %d",
        check_msg->signed_messages[164]);
    ck_assert_msg(
        check_msg->signed_messages[165] == 121,
        "incorrect value for signed_messages[165], expected 121, is %d",
        check_msg->signed_messages[165]);
    ck_assert_msg(
        check_msg->signed_messages[166] == 137,
        "incorrect value for signed_messages[166], expected 137, is %d",
        check_msg->signed_messages[166]);
    ck_assert_msg(
        check_msg->signed_messages[167] == 83,
        "incorrect value for signed_messages[167], expected 83, is %d",
        check_msg->signed_messages[167]);
    ck_assert_msg(
        check_msg->signed_messages[168] == 111,
        "incorrect value for signed_messages[168], expected 111, is %d",
        check_msg->signed_messages[168]);
    ck_assert_msg(
        check_msg->signed_messages[169] == 59,
        "incorrect value for signed_messages[169], expected 59, is %d",
        check_msg->signed_messages[169]);
    ck_assert_msg(check_msg->signed_messages[170] == 7,
                  "incorrect value for signed_messages[170], expected 7, is %d",
                  check_msg->signed_messages[170]);
    ck_assert_msg(
        check_msg->signed_messages[171] == 77,
        "incorrect value for signed_messages[171], expected 77, is %d",
        check_msg->signed_messages[171]);
    ck_assert_msg(check_msg->signed_messages[172] == 4,
                  "incorrect value for signed_messages[172], expected 4, is %d",
                  check_msg->signed_messages[172]);
    ck_assert_msg(
        check_msg->signed_messages[173] == 117,
        "incorrect value for signed_messages[173], expected 117, is %d",
        check_msg->signed_messages[173]);
    ck_assert_msg(
        check_msg->signed_messages[174] == 159,
        "incorrect value for signed_messages[174], expected 159, is %d",
        check_msg->signed_messages[174]);
    ck_assert_msg(
        check_msg->signed_messages[175] == 148,
        "incorrect value for signed_messages[175], expected 148, is %d",
        check_msg->signed_messages[175]);
    ck_assert_msg(
        check_msg->signed_messages[176] == 35,
        "incorrect value for signed_messages[176], expected 35, is %d",
        check_msg->signed_messages[176]);
    ck_assert_msg(
        check_msg->signed_messages[177] == 61,
        "incorrect value for signed_messages[177], expected 61, is %d",
        check_msg->signed_messages[177]);
    ck_assert_msg(
        check_msg->signed_messages[178] == 41,
        "incorrect value for signed_messages[178], expected 41, is %d",
        check_msg->signed_messages[178]);
    ck_assert_msg(
        check_msg->signed_messages[179] == 67,
        "incorrect value for signed_messages[179], expected 67, is %d",
        check_msg->signed_messages[179]);
    ck_assert_msg(
        check_msg->signed_messages[180] == 46,
        "incorrect value for signed_messages[180], expected 46, is %d",
        check_msg->signed_messages[180]);
    ck_assert_msg(
        check_msg->signed_messages[181] == 127,
        "incorrect value for signed_messages[181], expected 127, is %d",
        check_msg->signed_messages[181]);
    ck_assert_msg(
        check_msg->signed_messages[182] == 75,
        "incorrect value for signed_messages[182], expected 75, is %d",
        check_msg->signed_messages[182]);
    ck_assert_msg(
        check_msg->signed_messages[183] == 174,
        "incorrect value for signed_messages[183], expected 174, is %d",
        check_msg->signed_messages[183]);
    ck_assert_msg(check_msg->stream_counter == 1,
                  "incorrect value for stream_counter, expected 1, is %d",
                  check_msg->stream_counter);
  }
}
END_TEST

Suite *legacy_auto_check_sbp_signing_MsgEcdsaSignatureDepA_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_signing_MsgEcdsaSignatureDepA");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_signing_MsgEcdsaSignatureDepA");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_signing_MsgEcdsaSignatureDepA);
  suite_add_tcase(s, tc_acq);
  return s;
}