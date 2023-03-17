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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepB.yaml by
// generate.py. Do not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/signing.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static u32 dummy_wr = 0;
static u32 dummy_rd = 0;
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
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  u32 real_n = n;  //(dummy_n > n) ? n : dummy_n;
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

START_TEST(test_auto_check_sbp_signing_MsgEcdsaSignatureDepB) {
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

    sbp_callback_register(&sbp_state, 0xC07, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 7,  12, 66, 0,  83, 0,  1,  2,  1,   2,   3,  4,  72, 0,  1,
        2,  3,  4,  5,  6,  7,  8,  9,  10, 11,  12,  13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23, 24, 25, 26, 27,  28,  29, 30, 31, 32, 33,
        34, 35, 36, 37, 38, 39, 40, 41, 42, 43,  44,  45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59,  60,  61, 62, 63, 64, 65,
        66, 67, 68, 69, 70, 71, 10, 21, 23, 254, 159,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ecdsa_signature_dep_b.certificate_id[0] = 1;

    test_msg.ecdsa_signature_dep_b.certificate_id[1] = 2;

    test_msg.ecdsa_signature_dep_b.certificate_id[2] = 3;

    test_msg.ecdsa_signature_dep_b.certificate_id[3] = 4;

    test_msg.ecdsa_signature_dep_b.flags = 0;

    test_msg.ecdsa_signature_dep_b.n_signature_bytes = 72;

    test_msg.ecdsa_signature_dep_b.n_signed_messages = 3;

    test_msg.ecdsa_signature_dep_b.on_demand_counter = 2;

    test_msg.ecdsa_signature_dep_b.signature[0] = 0;

    test_msg.ecdsa_signature_dep_b.signature[1] = 1;

    test_msg.ecdsa_signature_dep_b.signature[2] = 2;

    test_msg.ecdsa_signature_dep_b.signature[3] = 3;

    test_msg.ecdsa_signature_dep_b.signature[4] = 4;

    test_msg.ecdsa_signature_dep_b.signature[5] = 5;

    test_msg.ecdsa_signature_dep_b.signature[6] = 6;

    test_msg.ecdsa_signature_dep_b.signature[7] = 7;

    test_msg.ecdsa_signature_dep_b.signature[8] = 8;

    test_msg.ecdsa_signature_dep_b.signature[9] = 9;

    test_msg.ecdsa_signature_dep_b.signature[10] = 10;

    test_msg.ecdsa_signature_dep_b.signature[11] = 11;

    test_msg.ecdsa_signature_dep_b.signature[12] = 12;

    test_msg.ecdsa_signature_dep_b.signature[13] = 13;

    test_msg.ecdsa_signature_dep_b.signature[14] = 14;

    test_msg.ecdsa_signature_dep_b.signature[15] = 15;

    test_msg.ecdsa_signature_dep_b.signature[16] = 16;

    test_msg.ecdsa_signature_dep_b.signature[17] = 17;

    test_msg.ecdsa_signature_dep_b.signature[18] = 18;

    test_msg.ecdsa_signature_dep_b.signature[19] = 19;

    test_msg.ecdsa_signature_dep_b.signature[20] = 20;

    test_msg.ecdsa_signature_dep_b.signature[21] = 21;

    test_msg.ecdsa_signature_dep_b.signature[22] = 22;

    test_msg.ecdsa_signature_dep_b.signature[23] = 23;

    test_msg.ecdsa_signature_dep_b.signature[24] = 24;

    test_msg.ecdsa_signature_dep_b.signature[25] = 25;

    test_msg.ecdsa_signature_dep_b.signature[26] = 26;

    test_msg.ecdsa_signature_dep_b.signature[27] = 27;

    test_msg.ecdsa_signature_dep_b.signature[28] = 28;

    test_msg.ecdsa_signature_dep_b.signature[29] = 29;

    test_msg.ecdsa_signature_dep_b.signature[30] = 30;

    test_msg.ecdsa_signature_dep_b.signature[31] = 31;

    test_msg.ecdsa_signature_dep_b.signature[32] = 32;

    test_msg.ecdsa_signature_dep_b.signature[33] = 33;

    test_msg.ecdsa_signature_dep_b.signature[34] = 34;

    test_msg.ecdsa_signature_dep_b.signature[35] = 35;

    test_msg.ecdsa_signature_dep_b.signature[36] = 36;

    test_msg.ecdsa_signature_dep_b.signature[37] = 37;

    test_msg.ecdsa_signature_dep_b.signature[38] = 38;

    test_msg.ecdsa_signature_dep_b.signature[39] = 39;

    test_msg.ecdsa_signature_dep_b.signature[40] = 40;

    test_msg.ecdsa_signature_dep_b.signature[41] = 41;

    test_msg.ecdsa_signature_dep_b.signature[42] = 42;

    test_msg.ecdsa_signature_dep_b.signature[43] = 43;

    test_msg.ecdsa_signature_dep_b.signature[44] = 44;

    test_msg.ecdsa_signature_dep_b.signature[45] = 45;

    test_msg.ecdsa_signature_dep_b.signature[46] = 46;

    test_msg.ecdsa_signature_dep_b.signature[47] = 47;

    test_msg.ecdsa_signature_dep_b.signature[48] = 48;

    test_msg.ecdsa_signature_dep_b.signature[49] = 49;

    test_msg.ecdsa_signature_dep_b.signature[50] = 50;

    test_msg.ecdsa_signature_dep_b.signature[51] = 51;

    test_msg.ecdsa_signature_dep_b.signature[52] = 52;

    test_msg.ecdsa_signature_dep_b.signature[53] = 53;

    test_msg.ecdsa_signature_dep_b.signature[54] = 54;

    test_msg.ecdsa_signature_dep_b.signature[55] = 55;

    test_msg.ecdsa_signature_dep_b.signature[56] = 56;

    test_msg.ecdsa_signature_dep_b.signature[57] = 57;

    test_msg.ecdsa_signature_dep_b.signature[58] = 58;

    test_msg.ecdsa_signature_dep_b.signature[59] = 59;

    test_msg.ecdsa_signature_dep_b.signature[60] = 60;

    test_msg.ecdsa_signature_dep_b.signature[61] = 61;

    test_msg.ecdsa_signature_dep_b.signature[62] = 62;

    test_msg.ecdsa_signature_dep_b.signature[63] = 63;

    test_msg.ecdsa_signature_dep_b.signature[64] = 64;

    test_msg.ecdsa_signature_dep_b.signature[65] = 65;

    test_msg.ecdsa_signature_dep_b.signature[66] = 66;

    test_msg.ecdsa_signature_dep_b.signature[67] = 67;

    test_msg.ecdsa_signature_dep_b.signature[68] = 68;

    test_msg.ecdsa_signature_dep_b.signature[69] = 69;

    test_msg.ecdsa_signature_dep_b.signature[70] = 70;

    test_msg.ecdsa_signature_dep_b.signature[71] = 71;

    test_msg.ecdsa_signature_dep_b.signed_messages[0] = 10;

    test_msg.ecdsa_signature_dep_b.signed_messages[1] = 21;

    test_msg.ecdsa_signature_dep_b.signed_messages[2] = 23;

    test_msg.ecdsa_signature_dep_b.stream_counter = 1;

    sbp_message_send(&sbp_state, SbpMsgEcdsaSignatureDepB, 66, &test_msg,
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

    ck_assert_msg(sbp_message_cmp(SbpMsgEcdsaSignatureDepB, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.certificate_id[0] == 1,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.certificate_id[0], "
                  "expected 1, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.certificate_id[0]);
    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.certificate_id[1] == 2,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.certificate_id[1], "
                  "expected 2, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.certificate_id[1]);
    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.certificate_id[2] == 3,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.certificate_id[2], "
                  "expected 3, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.certificate_id[2]);
    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.certificate_id[3] == 4,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.certificate_id[3], "
                  "expected 4, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.certificate_id[3]);

    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.flags == 0,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.flags, expected 0, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.flags);

    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.n_signature_bytes == 72,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.n_signature_bytes, "
                  "expected 72, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.n_signature_bytes);

    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.n_signed_messages == 3,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.n_signed_messages, "
                  "expected 3, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.n_signed_messages);

    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.on_demand_counter == 2,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.on_demand_counter, "
                  "expected 2, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.on_demand_counter);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[0] == 0,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[0], "
        "expected 0, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[0]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[1] == 1,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[1], "
        "expected 1, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[1]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[2] == 2,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[2], "
        "expected 2, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[2]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[3] == 3,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[3], "
        "expected 3, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[3]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[4] == 4,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[4], "
        "expected 4, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[4]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[5] == 5,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[5], "
        "expected 5, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[5]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[6] == 6,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[6], "
        "expected 6, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[6]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[7] == 7,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[7], "
        "expected 7, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[7]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[8] == 8,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[8], "
        "expected 8, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[8]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[9] == 9,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[9], "
        "expected 9, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[9]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[10] == 10,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[10], "
        "expected 10, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[10]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[11] == 11,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[11], "
        "expected 11, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[11]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[12] == 12,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[12], "
        "expected 12, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[12]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[13] == 13,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[13], "
        "expected 13, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[13]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[14] == 14,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[14], "
        "expected 14, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[14]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[15] == 15,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[15], "
        "expected 15, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[15]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[16] == 16,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[16], "
        "expected 16, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[16]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[17] == 17,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[17], "
        "expected 17, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[17]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[18] == 18,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[18], "
        "expected 18, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[18]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[19] == 19,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[19], "
        "expected 19, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[19]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[20] == 20,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[20], "
        "expected 20, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[20]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[21] == 21,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[21], "
        "expected 21, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[21]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[22] == 22,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[22], "
        "expected 22, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[22]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[23] == 23,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[23], "
        "expected 23, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[23]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[24] == 24,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[24], "
        "expected 24, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[24]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[25] == 25,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[25], "
        "expected 25, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[25]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[26] == 26,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[26], "
        "expected 26, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[26]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[27] == 27,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[27], "
        "expected 27, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[27]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[28] == 28,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[28], "
        "expected 28, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[28]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[29] == 29,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[29], "
        "expected 29, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[29]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[30] == 30,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[30], "
        "expected 30, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[30]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[31] == 31,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[31], "
        "expected 31, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[31]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[32] == 32,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[32], "
        "expected 32, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[32]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[33] == 33,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[33], "
        "expected 33, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[33]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[34] == 34,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[34], "
        "expected 34, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[34]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[35] == 35,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[35], "
        "expected 35, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[35]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[36] == 36,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[36], "
        "expected 36, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[36]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[37] == 37,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[37], "
        "expected 37, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[37]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[38] == 38,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[38], "
        "expected 38, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[38]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[39] == 39,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[39], "
        "expected 39, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[39]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[40] == 40,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[40], "
        "expected 40, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[40]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[41] == 41,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[41], "
        "expected 41, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[41]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[42] == 42,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[42], "
        "expected 42, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[42]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[43] == 43,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[43], "
        "expected 43, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[43]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[44] == 44,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[44], "
        "expected 44, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[44]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[45] == 45,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[45], "
        "expected 45, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[45]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[46] == 46,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[46], "
        "expected 46, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[46]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[47] == 47,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[47], "
        "expected 47, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[47]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[48] == 48,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[48], "
        "expected 48, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[48]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[49] == 49,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[49], "
        "expected 49, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[49]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[50] == 50,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[50], "
        "expected 50, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[50]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[51] == 51,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[51], "
        "expected 51, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[51]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[52] == 52,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[52], "
        "expected 52, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[52]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[53] == 53,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[53], "
        "expected 53, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[53]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[54] == 54,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[54], "
        "expected 54, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[54]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[55] == 55,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[55], "
        "expected 55, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[55]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[56] == 56,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[56], "
        "expected 56, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[56]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[57] == 57,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[57], "
        "expected 57, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[57]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[58] == 58,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[58], "
        "expected 58, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[58]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[59] == 59,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[59], "
        "expected 59, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[59]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[60] == 60,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[60], "
        "expected 60, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[60]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[61] == 61,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[61], "
        "expected 61, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[61]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[62] == 62,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[62], "
        "expected 62, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[62]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[63] == 63,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[63], "
        "expected 63, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[63]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[64] == 64,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[64], "
        "expected 64, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[64]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[65] == 65,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[65], "
        "expected 65, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[65]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[66] == 66,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[66], "
        "expected 66, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[66]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[67] == 67,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[67], "
        "expected 67, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[67]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[68] == 68,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[68], "
        "expected 68, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[68]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[69] == 69,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[69], "
        "expected 69, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[69]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[70] == 70,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[70], "
        "expected 70, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[70]);
    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.signature[71] == 71,
        "incorrect value for last_msg.msg.ecdsa_signature_dep_b.signature[71], "
        "expected 71, is %d",
        last_msg.msg.ecdsa_signature_dep_b.signature[71]);

    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.signed_messages[0] == 10,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.signed_messages[0], "
                  "expected 10, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.signed_messages[0]);
    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.signed_messages[1] == 21,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.signed_messages[1], "
                  "expected 21, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.signed_messages[1]);
    ck_assert_msg(last_msg.msg.ecdsa_signature_dep_b.signed_messages[2] == 23,
                  "incorrect value for "
                  "last_msg.msg.ecdsa_signature_dep_b.signed_messages[2], "
                  "expected 23, is %d",
                  last_msg.msg.ecdsa_signature_dep_b.signed_messages[2]);

    ck_assert_msg(
        last_msg.msg.ecdsa_signature_dep_b.stream_counter == 1,
        "incorrect value for "
        "last_msg.msg.ecdsa_signature_dep_b.stream_counter, expected 1, is %d",
        last_msg.msg.ecdsa_signature_dep_b.stream_counter);
  }
}
END_TEST

Suite *auto_check_sbp_signing_MsgEcdsaSignatureDepB_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_signing_MsgEcdsaSignatureDepB");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_signing_MsgEcdsaSignatureDepB");
  tcase_add_test(tc_acq, test_auto_check_sbp_signing_MsgEcdsaSignatureDepB);
  suite_add_tcase(s, tc_acq);
  return s;
}