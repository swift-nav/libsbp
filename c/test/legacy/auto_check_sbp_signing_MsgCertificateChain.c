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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgCertificateChain.yaml by
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

START_TEST(test_legacy_auto_check_sbp_signing_MsgCertificateChain) {
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

    sbp_payload_callback_register(&sbp_state, 0xC05, &msg_callback,
                                  &DUMMY_MEMORY_FOR_CALLBACKS, &n);
    sbp_frame_callback_register(&sbp_state, 0xC05, &frame_callback,
                                &DUMMY_MEMORY_FOR_CALLBACKS, &n2);

    u8 encoded_frame[] = {
        85, 5,  12,  66, 0,  135, 0,  1,  2,  3,  4,   5,  6,  7,   8,   9,
        10, 11, 12,  13, 14, 15,  16, 17, 18, 19, 10,  11, 12, 13,  14,  15,
        16, 17, 18,  19, 0,  1,   2,  3,  4,  5,  6,   7,  8,  9,   20,  21,
        22, 23, 24,  25, 26, 27,  28, 29, 10, 11, 12,  13, 14, 15,  16,  17,
        18, 19, 232, 7,  3,  30,  12, 34, 59, 21, 205, 91, 7,  0,   1,   2,
        3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  0,   1,   2,
        3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  0,   1,   2,
        3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  0,   1,   2,
        3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  112, 100,
    };

    dummy_reset();

    u8 test_msg_storage[SBP_MAX_PAYLOAD_LEN];
    memset(test_msg_storage, 0, sizeof(test_msg_storage));
    u8 test_msg_len = 0;
    msg_certificate_chain_t *test_msg =
        (msg_certificate_chain_t *)test_msg_storage;
    test_msg_len = sizeof(*test_msg);
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[0] = 20;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[1] = 21;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[2] = 22;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[3] = 23;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[4] = 24;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[5] = 25;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[6] = 26;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[7] = 27;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[8] = 28;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[9] = 29;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[10] = 10;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[11] = 11;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[12] = 12;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[13] = 13;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[14] = 14;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[15] = 15;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[16] = 16;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[17] = 17;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[18] = 18;
    if (sizeof(test_msg->corrections_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->corrections_certificate[0]);
    }
    test_msg->corrections_certificate[19] = 19;
    test_msg->expiration.day = 30;
    test_msg->expiration.hours = 12;
    test_msg->expiration.minutes = 34;
    test_msg->expiration.month = 3;
    test_msg->expiration.ns = 123456789;
    test_msg->expiration.seconds = 59;
    test_msg->expiration.year = 2024;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[0] = 10;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[1] = 11;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[2] = 12;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[3] = 13;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[4] = 14;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[5] = 15;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[6] = 16;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[7] = 17;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[8] = 18;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[9] = 19;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[10] = 0;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[11] = 1;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[12] = 2;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[13] = 3;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[14] = 4;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[15] = 5;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[16] = 6;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[17] = 7;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[18] = 8;
    if (sizeof(test_msg->intermediate_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->intermediate_certificate[0]);
    }
    test_msg->intermediate_certificate[19] = 9;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[0] = 0;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[1] = 1;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[2] = 2;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[3] = 3;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[4] = 4;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[5] = 5;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[6] = 6;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[7] = 7;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[8] = 8;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[9] = 9;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[10] = 10;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[11] = 11;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[12] = 12;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[13] = 13;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[14] = 14;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[15] = 15;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[16] = 16;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[17] = 17;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[18] = 18;
    if (sizeof(test_msg->root_certificate) == 0) {
      // Cope with variable length arrays
      test_msg_len += sizeof(test_msg->root_certificate[0]);
    }
    test_msg->root_certificate[19] = 19;
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
    sbp_payload_send(&sbp_state, 0xC05, 66, test_msg_len, test_msg_storage,
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
    ck_assert_msg(last_frame.msg_type == 0xC05,
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
    msg_certificate_chain_t *check_msg =
        (msg_certificate_chain_t *)((void *)last_msg.msg);
    // Run tests against fields
    ck_assert_msg(check_msg != 0, "stub to prevent warnings if msg isn't used");
    ck_assert_msg(
        check_msg->corrections_certificate[0] == 20,
        "incorrect value for corrections_certificate[0], expected 20, is %d",
        check_msg->corrections_certificate[0]);
    ck_assert_msg(
        check_msg->corrections_certificate[1] == 21,
        "incorrect value for corrections_certificate[1], expected 21, is %d",
        check_msg->corrections_certificate[1]);
    ck_assert_msg(
        check_msg->corrections_certificate[2] == 22,
        "incorrect value for corrections_certificate[2], expected 22, is %d",
        check_msg->corrections_certificate[2]);
    ck_assert_msg(
        check_msg->corrections_certificate[3] == 23,
        "incorrect value for corrections_certificate[3], expected 23, is %d",
        check_msg->corrections_certificate[3]);
    ck_assert_msg(
        check_msg->corrections_certificate[4] == 24,
        "incorrect value for corrections_certificate[4], expected 24, is %d",
        check_msg->corrections_certificate[4]);
    ck_assert_msg(
        check_msg->corrections_certificate[5] == 25,
        "incorrect value for corrections_certificate[5], expected 25, is %d",
        check_msg->corrections_certificate[5]);
    ck_assert_msg(
        check_msg->corrections_certificate[6] == 26,
        "incorrect value for corrections_certificate[6], expected 26, is %d",
        check_msg->corrections_certificate[6]);
    ck_assert_msg(
        check_msg->corrections_certificate[7] == 27,
        "incorrect value for corrections_certificate[7], expected 27, is %d",
        check_msg->corrections_certificate[7]);
    ck_assert_msg(
        check_msg->corrections_certificate[8] == 28,
        "incorrect value for corrections_certificate[8], expected 28, is %d",
        check_msg->corrections_certificate[8]);
    ck_assert_msg(
        check_msg->corrections_certificate[9] == 29,
        "incorrect value for corrections_certificate[9], expected 29, is %d",
        check_msg->corrections_certificate[9]);
    ck_assert_msg(
        check_msg->corrections_certificate[10] == 10,
        "incorrect value for corrections_certificate[10], expected 10, is %d",
        check_msg->corrections_certificate[10]);
    ck_assert_msg(
        check_msg->corrections_certificate[11] == 11,
        "incorrect value for corrections_certificate[11], expected 11, is %d",
        check_msg->corrections_certificate[11]);
    ck_assert_msg(
        check_msg->corrections_certificate[12] == 12,
        "incorrect value for corrections_certificate[12], expected 12, is %d",
        check_msg->corrections_certificate[12]);
    ck_assert_msg(
        check_msg->corrections_certificate[13] == 13,
        "incorrect value for corrections_certificate[13], expected 13, is %d",
        check_msg->corrections_certificate[13]);
    ck_assert_msg(
        check_msg->corrections_certificate[14] == 14,
        "incorrect value for corrections_certificate[14], expected 14, is %d",
        check_msg->corrections_certificate[14]);
    ck_assert_msg(
        check_msg->corrections_certificate[15] == 15,
        "incorrect value for corrections_certificate[15], expected 15, is %d",
        check_msg->corrections_certificate[15]);
    ck_assert_msg(
        check_msg->corrections_certificate[16] == 16,
        "incorrect value for corrections_certificate[16], expected 16, is %d",
        check_msg->corrections_certificate[16]);
    ck_assert_msg(
        check_msg->corrections_certificate[17] == 17,
        "incorrect value for corrections_certificate[17], expected 17, is %d",
        check_msg->corrections_certificate[17]);
    ck_assert_msg(
        check_msg->corrections_certificate[18] == 18,
        "incorrect value for corrections_certificate[18], expected 18, is %d",
        check_msg->corrections_certificate[18]);
    ck_assert_msg(
        check_msg->corrections_certificate[19] == 19,
        "incorrect value for corrections_certificate[19], expected 19, is %d",
        check_msg->corrections_certificate[19]);
    ck_assert_msg(check_msg->expiration.day == 30,
                  "incorrect value for expiration.day, expected 30, is %d",
                  check_msg->expiration.day);
    ck_assert_msg(check_msg->expiration.hours == 12,
                  "incorrect value for expiration.hours, expected 12, is %d",
                  check_msg->expiration.hours);
    ck_assert_msg(check_msg->expiration.minutes == 34,
                  "incorrect value for expiration.minutes, expected 34, is %d",
                  check_msg->expiration.minutes);
    ck_assert_msg(check_msg->expiration.month == 3,
                  "incorrect value for expiration.month, expected 3, is %d",
                  check_msg->expiration.month);
    ck_assert_msg(
        check_msg->expiration.ns == 123456789,
        "incorrect value for expiration.ns, expected 123456789, is %d",
        check_msg->expiration.ns);
    ck_assert_msg(check_msg->expiration.seconds == 59,
                  "incorrect value for expiration.seconds, expected 59, is %d",
                  check_msg->expiration.seconds);
    ck_assert_msg(check_msg->expiration.year == 2024,
                  "incorrect value for expiration.year, expected 2024, is %d",
                  check_msg->expiration.year);
    ck_assert_msg(
        check_msg->intermediate_certificate[0] == 10,
        "incorrect value for intermediate_certificate[0], expected 10, is %d",
        check_msg->intermediate_certificate[0]);
    ck_assert_msg(
        check_msg->intermediate_certificate[1] == 11,
        "incorrect value for intermediate_certificate[1], expected 11, is %d",
        check_msg->intermediate_certificate[1]);
    ck_assert_msg(
        check_msg->intermediate_certificate[2] == 12,
        "incorrect value for intermediate_certificate[2], expected 12, is %d",
        check_msg->intermediate_certificate[2]);
    ck_assert_msg(
        check_msg->intermediate_certificate[3] == 13,
        "incorrect value for intermediate_certificate[3], expected 13, is %d",
        check_msg->intermediate_certificate[3]);
    ck_assert_msg(
        check_msg->intermediate_certificate[4] == 14,
        "incorrect value for intermediate_certificate[4], expected 14, is %d",
        check_msg->intermediate_certificate[4]);
    ck_assert_msg(
        check_msg->intermediate_certificate[5] == 15,
        "incorrect value for intermediate_certificate[5], expected 15, is %d",
        check_msg->intermediate_certificate[5]);
    ck_assert_msg(
        check_msg->intermediate_certificate[6] == 16,
        "incorrect value for intermediate_certificate[6], expected 16, is %d",
        check_msg->intermediate_certificate[6]);
    ck_assert_msg(
        check_msg->intermediate_certificate[7] == 17,
        "incorrect value for intermediate_certificate[7], expected 17, is %d",
        check_msg->intermediate_certificate[7]);
    ck_assert_msg(
        check_msg->intermediate_certificate[8] == 18,
        "incorrect value for intermediate_certificate[8], expected 18, is %d",
        check_msg->intermediate_certificate[8]);
    ck_assert_msg(
        check_msg->intermediate_certificate[9] == 19,
        "incorrect value for intermediate_certificate[9], expected 19, is %d",
        check_msg->intermediate_certificate[9]);
    ck_assert_msg(
        check_msg->intermediate_certificate[10] == 0,
        "incorrect value for intermediate_certificate[10], expected 0, is %d",
        check_msg->intermediate_certificate[10]);
    ck_assert_msg(
        check_msg->intermediate_certificate[11] == 1,
        "incorrect value for intermediate_certificate[11], expected 1, is %d",
        check_msg->intermediate_certificate[11]);
    ck_assert_msg(
        check_msg->intermediate_certificate[12] == 2,
        "incorrect value for intermediate_certificate[12], expected 2, is %d",
        check_msg->intermediate_certificate[12]);
    ck_assert_msg(
        check_msg->intermediate_certificate[13] == 3,
        "incorrect value for intermediate_certificate[13], expected 3, is %d",
        check_msg->intermediate_certificate[13]);
    ck_assert_msg(
        check_msg->intermediate_certificate[14] == 4,
        "incorrect value for intermediate_certificate[14], expected 4, is %d",
        check_msg->intermediate_certificate[14]);
    ck_assert_msg(
        check_msg->intermediate_certificate[15] == 5,
        "incorrect value for intermediate_certificate[15], expected 5, is %d",
        check_msg->intermediate_certificate[15]);
    ck_assert_msg(
        check_msg->intermediate_certificate[16] == 6,
        "incorrect value for intermediate_certificate[16], expected 6, is %d",
        check_msg->intermediate_certificate[16]);
    ck_assert_msg(
        check_msg->intermediate_certificate[17] == 7,
        "incorrect value for intermediate_certificate[17], expected 7, is %d",
        check_msg->intermediate_certificate[17]);
    ck_assert_msg(
        check_msg->intermediate_certificate[18] == 8,
        "incorrect value for intermediate_certificate[18], expected 8, is %d",
        check_msg->intermediate_certificate[18]);
    ck_assert_msg(
        check_msg->intermediate_certificate[19] == 9,
        "incorrect value for intermediate_certificate[19], expected 9, is %d",
        check_msg->intermediate_certificate[19]);
    ck_assert_msg(check_msg->root_certificate[0] == 0,
                  "incorrect value for root_certificate[0], expected 0, is %d",
                  check_msg->root_certificate[0]);
    ck_assert_msg(check_msg->root_certificate[1] == 1,
                  "incorrect value for root_certificate[1], expected 1, is %d",
                  check_msg->root_certificate[1]);
    ck_assert_msg(check_msg->root_certificate[2] == 2,
                  "incorrect value for root_certificate[2], expected 2, is %d",
                  check_msg->root_certificate[2]);
    ck_assert_msg(check_msg->root_certificate[3] == 3,
                  "incorrect value for root_certificate[3], expected 3, is %d",
                  check_msg->root_certificate[3]);
    ck_assert_msg(check_msg->root_certificate[4] == 4,
                  "incorrect value for root_certificate[4], expected 4, is %d",
                  check_msg->root_certificate[4]);
    ck_assert_msg(check_msg->root_certificate[5] == 5,
                  "incorrect value for root_certificate[5], expected 5, is %d",
                  check_msg->root_certificate[5]);
    ck_assert_msg(check_msg->root_certificate[6] == 6,
                  "incorrect value for root_certificate[6], expected 6, is %d",
                  check_msg->root_certificate[6]);
    ck_assert_msg(check_msg->root_certificate[7] == 7,
                  "incorrect value for root_certificate[7], expected 7, is %d",
                  check_msg->root_certificate[7]);
    ck_assert_msg(check_msg->root_certificate[8] == 8,
                  "incorrect value for root_certificate[8], expected 8, is %d",
                  check_msg->root_certificate[8]);
    ck_assert_msg(check_msg->root_certificate[9] == 9,
                  "incorrect value for root_certificate[9], expected 9, is %d",
                  check_msg->root_certificate[9]);
    ck_assert_msg(
        check_msg->root_certificate[10] == 10,
        "incorrect value for root_certificate[10], expected 10, is %d",
        check_msg->root_certificate[10]);
    ck_assert_msg(
        check_msg->root_certificate[11] == 11,
        "incorrect value for root_certificate[11], expected 11, is %d",
        check_msg->root_certificate[11]);
    ck_assert_msg(
        check_msg->root_certificate[12] == 12,
        "incorrect value for root_certificate[12], expected 12, is %d",
        check_msg->root_certificate[12]);
    ck_assert_msg(
        check_msg->root_certificate[13] == 13,
        "incorrect value for root_certificate[13], expected 13, is %d",
        check_msg->root_certificate[13]);
    ck_assert_msg(
        check_msg->root_certificate[14] == 14,
        "incorrect value for root_certificate[14], expected 14, is %d",
        check_msg->root_certificate[14]);
    ck_assert_msg(
        check_msg->root_certificate[15] == 15,
        "incorrect value for root_certificate[15], expected 15, is %d",
        check_msg->root_certificate[15]);
    ck_assert_msg(
        check_msg->root_certificate[16] == 16,
        "incorrect value for root_certificate[16], expected 16, is %d",
        check_msg->root_certificate[16]);
    ck_assert_msg(
        check_msg->root_certificate[17] == 17,
        "incorrect value for root_certificate[17], expected 17, is %d",
        check_msg->root_certificate[17]);
    ck_assert_msg(
        check_msg->root_certificate[18] == 18,
        "incorrect value for root_certificate[18], expected 18, is %d",
        check_msg->root_certificate[18]);
    ck_assert_msg(
        check_msg->root_certificate[19] == 19,
        "incorrect value for root_certificate[19], expected 19, is %d",
        check_msg->root_certificate[19]);
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
  }
}
END_TEST

Suite *legacy_auto_check_sbp_signing_MsgCertificateChain_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "legacy_auto_check_sbp_signing_MsgCertificateChain");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_legacy_auto_check_sbp_signing_MsgCertificateChain");
  tcase_add_test(tc_acq,
                 test_legacy_auto_check_sbp_signing_MsgCertificateChain);
  suite_add_tcase(s, tc_acq);
  return s;
}