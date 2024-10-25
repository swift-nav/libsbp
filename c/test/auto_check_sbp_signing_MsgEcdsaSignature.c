/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignature.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/signing.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static size_t dummy_wr = 0;
static size_t dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static void *DUMMY_MEMORY_FOR_CALLBACKS = (void *)0xdeadbeef;
static void *DUMMY_MEMORY_FOR_IO = (void *)0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return (s32)real_n;
}

static void logging_reset() { memset(&last_msg, 0, sizeof(last_msg)); }

static void msg_callback(u16 sender_id, sbp_msg_type_t msg_type,
                         const sbp_msg_t *msg, void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.msg_type = msg_type;
  last_msg.msg = *msg;
  last_msg.context = context;
}

START_TEST(test_auto_check_sbp_signing_MsgEcdsaSignature) {
  static sbp_msg_callbacks_node_t n;

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

    sbp_callback_register(&sbp_state, 0xC08, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 8,  12, 66, 0,  83, 0,  1,  2,  1,   2,   3,  4,  72, 0,  1,
        2,  3,  4,  5,  6,  7,  8,  9,  10, 11,  12,  13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23, 24, 25, 26, 27,  28,  29, 30, 31, 32, 33,
        34, 35, 36, 37, 38, 39, 40, 41, 42, 43,  44,  45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59,  60,  61, 62, 63, 64, 65,
        66, 67, 68, 69, 70, 71, 10, 21, 23, 232, 131,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ecdsa_signature.certificate_id[0] = 1;

    test_msg.ecdsa_signature.certificate_id[1] = 2;

    test_msg.ecdsa_signature.certificate_id[2] = 3;

    test_msg.ecdsa_signature.certificate_id[3] = 4;

    test_msg.ecdsa_signature.flags = 0;

    test_msg.ecdsa_signature.n_signed_messages = 3;

    test_msg.ecdsa_signature.on_demand_counter = 2;

    test_msg.ecdsa_signature.signature.data[0] = 0;

    test_msg.ecdsa_signature.signature.data[1] = 1;

    test_msg.ecdsa_signature.signature.data[2] = 2;

    test_msg.ecdsa_signature.signature.data[3] = 3;

    test_msg.ecdsa_signature.signature.data[4] = 4;

    test_msg.ecdsa_signature.signature.data[5] = 5;

    test_msg.ecdsa_signature.signature.data[6] = 6;

    test_msg.ecdsa_signature.signature.data[7] = 7;

    test_msg.ecdsa_signature.signature.data[8] = 8;

    test_msg.ecdsa_signature.signature.data[9] = 9;

    test_msg.ecdsa_signature.signature.data[10] = 10;

    test_msg.ecdsa_signature.signature.data[11] = 11;

    test_msg.ecdsa_signature.signature.data[12] = 12;

    test_msg.ecdsa_signature.signature.data[13] = 13;

    test_msg.ecdsa_signature.signature.data[14] = 14;

    test_msg.ecdsa_signature.signature.data[15] = 15;

    test_msg.ecdsa_signature.signature.data[16] = 16;

    test_msg.ecdsa_signature.signature.data[17] = 17;

    test_msg.ecdsa_signature.signature.data[18] = 18;

    test_msg.ecdsa_signature.signature.data[19] = 19;

    test_msg.ecdsa_signature.signature.data[20] = 20;

    test_msg.ecdsa_signature.signature.data[21] = 21;

    test_msg.ecdsa_signature.signature.data[22] = 22;

    test_msg.ecdsa_signature.signature.data[23] = 23;

    test_msg.ecdsa_signature.signature.data[24] = 24;

    test_msg.ecdsa_signature.signature.data[25] = 25;

    test_msg.ecdsa_signature.signature.data[26] = 26;

    test_msg.ecdsa_signature.signature.data[27] = 27;

    test_msg.ecdsa_signature.signature.data[28] = 28;

    test_msg.ecdsa_signature.signature.data[29] = 29;

    test_msg.ecdsa_signature.signature.data[30] = 30;

    test_msg.ecdsa_signature.signature.data[31] = 31;

    test_msg.ecdsa_signature.signature.data[32] = 32;

    test_msg.ecdsa_signature.signature.data[33] = 33;

    test_msg.ecdsa_signature.signature.data[34] = 34;

    test_msg.ecdsa_signature.signature.data[35] = 35;

    test_msg.ecdsa_signature.signature.data[36] = 36;

    test_msg.ecdsa_signature.signature.data[37] = 37;

    test_msg.ecdsa_signature.signature.data[38] = 38;

    test_msg.ecdsa_signature.signature.data[39] = 39;

    test_msg.ecdsa_signature.signature.data[40] = 40;

    test_msg.ecdsa_signature.signature.data[41] = 41;

    test_msg.ecdsa_signature.signature.data[42] = 42;

    test_msg.ecdsa_signature.signature.data[43] = 43;

    test_msg.ecdsa_signature.signature.data[44] = 44;

    test_msg.ecdsa_signature.signature.data[45] = 45;

    test_msg.ecdsa_signature.signature.data[46] = 46;

    test_msg.ecdsa_signature.signature.data[47] = 47;

    test_msg.ecdsa_signature.signature.data[48] = 48;

    test_msg.ecdsa_signature.signature.data[49] = 49;

    test_msg.ecdsa_signature.signature.data[50] = 50;

    test_msg.ecdsa_signature.signature.data[51] = 51;

    test_msg.ecdsa_signature.signature.data[52] = 52;

    test_msg.ecdsa_signature.signature.data[53] = 53;

    test_msg.ecdsa_signature.signature.data[54] = 54;

    test_msg.ecdsa_signature.signature.data[55] = 55;

    test_msg.ecdsa_signature.signature.data[56] = 56;

    test_msg.ecdsa_signature.signature.data[57] = 57;

    test_msg.ecdsa_signature.signature.data[58] = 58;

    test_msg.ecdsa_signature.signature.data[59] = 59;

    test_msg.ecdsa_signature.signature.data[60] = 60;

    test_msg.ecdsa_signature.signature.data[61] = 61;

    test_msg.ecdsa_signature.signature.data[62] = 62;

    test_msg.ecdsa_signature.signature.data[63] = 63;

    test_msg.ecdsa_signature.signature.data[64] = 64;

    test_msg.ecdsa_signature.signature.data[65] = 65;

    test_msg.ecdsa_signature.signature.data[66] = 66;

    test_msg.ecdsa_signature.signature.data[67] = 67;

    test_msg.ecdsa_signature.signature.data[68] = 68;

    test_msg.ecdsa_signature.signature.data[69] = 69;

    test_msg.ecdsa_signature.signature.data[70] = 70;

    test_msg.ecdsa_signature.signature.data[71] = 71;

    test_msg.ecdsa_signature.signature.len = 72;

    test_msg.ecdsa_signature.signed_messages[0] = 10;

    test_msg.ecdsa_signature.signed_messages[1] = 21;

    test_msg.ecdsa_signature.signed_messages[2] = 23;

    test_msg.ecdsa_signature.stream_counter = 1;

    sbp_message_send(&sbp_state, SbpMsgEcdsaSignature, 66, &test_msg,
                     &dummy_write);

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff (expected: %zu, "
                  "actual: %zu)",
                  sizeof(encoded_frame), dummy_wr);
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

    ck_assert_msg(
        sbp_message_cmp(SbpMsgEcdsaSignature, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.ecdsa_signature.certificate_id[0] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature.certificate_id[0], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.certificate_id[0]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.certificate_id[1] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature.certificate_id[1], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.certificate_id[1]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.certificate_id[2] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature.certificate_id[2], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.certificate_id[2]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.certificate_id[3] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature.certificate_id[3], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.certificate_id[3]);

    ck_assert_msg(last_msg.msg.ecdsa_signature.flags == 0,
                  "incorrect value for last_msg.msg.ecdsa_signature.flags, "
                  "expected 0, is %" PRId64,
                  (int64_t)last_msg.msg.ecdsa_signature.flags);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature.n_signed_messages == 3,
        "incorrect value for last_msg.msg.ecdsa_signature.n_signed_messages, "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.n_signed_messages);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature.on_demand_counter == 2,
        "incorrect value for last_msg.msg.ecdsa_signature.on_demand_counter, "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.on_demand_counter);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[0] == 0,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[0], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[0]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[1] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[1], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[1]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[2] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[2], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[2]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[3] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[3], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[3]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[4] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[4], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[4]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[5] == 5,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[5], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[5]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[6] == 6,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[6], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[6]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[7] == 7,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[7], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[7]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[8] == 8,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[8], "
        "expected 8, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[8]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[9] == 9,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[9], "
        "expected 9, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[9]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[10] == 10,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[10], "
        "expected 10, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[10]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[11] == 11,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[11], "
        "expected 11, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[11]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[12] == 12,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[12], "
        "expected 12, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[12]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[13] == 13,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[13], "
        "expected 13, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[13]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[14] == 14,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[14], "
        "expected 14, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[14]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[15] == 15,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[15], "
        "expected 15, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[15]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[16] == 16,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[16], "
        "expected 16, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[16]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[17] == 17,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[17], "
        "expected 17, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[17]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[18] == 18,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[18], "
        "expected 18, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[18]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[19] == 19,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[19], "
        "expected 19, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[19]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[20] == 20,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[20], "
        "expected 20, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[20]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[21] == 21,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[21], "
        "expected 21, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[21]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[22] == 22,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[22], "
        "expected 22, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[22]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[23] == 23,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[23], "
        "expected 23, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[23]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[24] == 24,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[24], "
        "expected 24, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[24]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[25] == 25,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[25], "
        "expected 25, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[25]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[26] == 26,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[26], "
        "expected 26, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[26]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[27] == 27,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[27], "
        "expected 27, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[27]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[28] == 28,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[28], "
        "expected 28, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[28]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[29] == 29,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[29], "
        "expected 29, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[29]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[30] == 30,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[30], "
        "expected 30, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[30]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[31] == 31,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[31], "
        "expected 31, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[31]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[32] == 32,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[32], "
        "expected 32, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[32]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[33] == 33,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[33], "
        "expected 33, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[33]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[34] == 34,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[34], "
        "expected 34, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[34]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[35] == 35,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[35], "
        "expected 35, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[35]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[36] == 36,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[36], "
        "expected 36, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[36]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[37] == 37,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[37], "
        "expected 37, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[37]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[38] == 38,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[38], "
        "expected 38, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[38]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[39] == 39,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[39], "
        "expected 39, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[39]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[40] == 40,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[40], "
        "expected 40, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[40]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[41] == 41,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[41], "
        "expected 41, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[41]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[42] == 42,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[42], "
        "expected 42, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[42]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[43] == 43,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[43], "
        "expected 43, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[43]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[44] == 44,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[44], "
        "expected 44, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[44]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[45] == 45,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[45], "
        "expected 45, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[45]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[46] == 46,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[46], "
        "expected 46, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[46]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[47] == 47,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[47], "
        "expected 47, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[47]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[48] == 48,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[48], "
        "expected 48, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[48]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[49] == 49,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[49], "
        "expected 49, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[49]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[50] == 50,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[50], "
        "expected 50, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[50]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[51] == 51,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[51], "
        "expected 51, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[51]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[52] == 52,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[52], "
        "expected 52, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[52]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[53] == 53,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[53], "
        "expected 53, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[53]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[54] == 54,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[54], "
        "expected 54, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[54]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[55] == 55,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[55], "
        "expected 55, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[55]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[56] == 56,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[56], "
        "expected 56, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[56]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[57] == 57,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[57], "
        "expected 57, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[57]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[58] == 58,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[58], "
        "expected 58, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[58]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[59] == 59,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[59], "
        "expected 59, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[59]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[60] == 60,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[60], "
        "expected 60, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[60]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[61] == 61,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[61], "
        "expected 61, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[61]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[62] == 62,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[62], "
        "expected 62, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[62]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[63] == 63,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[63], "
        "expected 63, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[63]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[64] == 64,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[64], "
        "expected 64, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[64]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[65] == 65,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[65], "
        "expected 65, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[65]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[66] == 66,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[66], "
        "expected 66, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[66]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[67] == 67,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[67], "
        "expected 67, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[67]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[68] == 68,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[68], "
        "expected 68, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[68]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[69] == 69,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[69], "
        "expected 69, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[69]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[70] == 70,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[70], "
        "expected 70, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[70]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.data[71] == 71,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.data[71], "
        "expected 71, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.data[71]);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signature.len == 72,
        "incorrect value for last_msg.msg.ecdsa_signature.signature.len, "
        "expected 72, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signature.len);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signed_messages[0] == 10,
        "incorrect value for last_msg.msg.ecdsa_signature.signed_messages[0], "
        "expected 10, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signed_messages[0]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signed_messages[1] == 21,
        "incorrect value for last_msg.msg.ecdsa_signature.signed_messages[1], "
        "expected 21, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signed_messages[1]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature.signed_messages[2] == 23,
        "incorrect value for last_msg.msg.ecdsa_signature.signed_messages[2], "
        "expected 23, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.signed_messages[2]);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature.stream_counter == 1,
        "incorrect value for last_msg.msg.ecdsa_signature.stream_counter, "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.ecdsa_signature.stream_counter);
  }
}
END_TEST

Suite *auto_check_sbp_signing_MsgEcdsaSignature_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_signing_MsgEcdsaSignature");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_signing_MsgEcdsaSignature");
  tcase_add_test(tc_acq, test_auto_check_sbp_signing_MsgEcdsaSignature);
  suite_add_tcase(s, tc_acq);
  return s;
}
