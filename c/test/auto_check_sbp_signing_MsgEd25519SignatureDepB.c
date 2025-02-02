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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519SignatureDepB.yaml by
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

START_TEST(test_auto_check_sbp_signing_MsgEd25519SignatureDepB) {
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

    sbp_callback_register(&sbp_state, 0xC03, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  3,   12,  66,  0,   186, 1,   0,   0,   1,   2,   3,   4,   5,
        6,   7,   8,   9,   10,  11,  12,  13,  14,  15,  16,  17,  18,  19,
        20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,
        34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,
        48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,
        62,  63,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
        112, 113, 114, 115, 116, 117, 118, 119, 136, 19,  0,   0,   114, 20,
        0,   0,   92,  21,  0,   0,   70,  22,  0,   0,   48,  23,  0,   0,
        26,  24,  0,   0,   4,   25,  0,   0,   238, 25,  0,   0,   216, 26,
        0,   0,   194, 27,  0,   0,   172, 28,  0,   0,   150, 29,  0,   0,
        128, 30,  0,   0,   106, 31,  0,   0,   84,  32,  0,   0,   62,  33,
        0,   0,   40,  34,  0,   0,   18,  35,  0,   0,   252, 35,  0,   0,
        230, 36,  0,   0,   208, 37,  0,   0,   186, 38,  0,   0,   164, 39,
        0,   0,   142, 40,  0,   0,   120, 41,  0,   0,   238, 145,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ed25519_signature_dep_b.fingerprint[0] = 100;

    test_msg.ed25519_signature_dep_b.fingerprint[1] = 101;

    test_msg.ed25519_signature_dep_b.fingerprint[2] = 102;

    test_msg.ed25519_signature_dep_b.fingerprint[3] = 103;

    test_msg.ed25519_signature_dep_b.fingerprint[4] = 104;

    test_msg.ed25519_signature_dep_b.fingerprint[5] = 105;

    test_msg.ed25519_signature_dep_b.fingerprint[6] = 106;

    test_msg.ed25519_signature_dep_b.fingerprint[7] = 107;

    test_msg.ed25519_signature_dep_b.fingerprint[8] = 108;

    test_msg.ed25519_signature_dep_b.fingerprint[9] = 109;

    test_msg.ed25519_signature_dep_b.fingerprint[10] = 110;

    test_msg.ed25519_signature_dep_b.fingerprint[11] = 111;

    test_msg.ed25519_signature_dep_b.fingerprint[12] = 112;

    test_msg.ed25519_signature_dep_b.fingerprint[13] = 113;

    test_msg.ed25519_signature_dep_b.fingerprint[14] = 114;

    test_msg.ed25519_signature_dep_b.fingerprint[15] = 115;

    test_msg.ed25519_signature_dep_b.fingerprint[16] = 116;

    test_msg.ed25519_signature_dep_b.fingerprint[17] = 117;

    test_msg.ed25519_signature_dep_b.fingerprint[18] = 118;

    test_msg.ed25519_signature_dep_b.fingerprint[19] = 119;

    test_msg.ed25519_signature_dep_b.n_signed_messages = 25;

    test_msg.ed25519_signature_dep_b.on_demand_counter = 0;

    test_msg.ed25519_signature_dep_b.signature[0] = 0;

    test_msg.ed25519_signature_dep_b.signature[1] = 1;

    test_msg.ed25519_signature_dep_b.signature[2] = 2;

    test_msg.ed25519_signature_dep_b.signature[3] = 3;

    test_msg.ed25519_signature_dep_b.signature[4] = 4;

    test_msg.ed25519_signature_dep_b.signature[5] = 5;

    test_msg.ed25519_signature_dep_b.signature[6] = 6;

    test_msg.ed25519_signature_dep_b.signature[7] = 7;

    test_msg.ed25519_signature_dep_b.signature[8] = 8;

    test_msg.ed25519_signature_dep_b.signature[9] = 9;

    test_msg.ed25519_signature_dep_b.signature[10] = 10;

    test_msg.ed25519_signature_dep_b.signature[11] = 11;

    test_msg.ed25519_signature_dep_b.signature[12] = 12;

    test_msg.ed25519_signature_dep_b.signature[13] = 13;

    test_msg.ed25519_signature_dep_b.signature[14] = 14;

    test_msg.ed25519_signature_dep_b.signature[15] = 15;

    test_msg.ed25519_signature_dep_b.signature[16] = 16;

    test_msg.ed25519_signature_dep_b.signature[17] = 17;

    test_msg.ed25519_signature_dep_b.signature[18] = 18;

    test_msg.ed25519_signature_dep_b.signature[19] = 19;

    test_msg.ed25519_signature_dep_b.signature[20] = 20;

    test_msg.ed25519_signature_dep_b.signature[21] = 21;

    test_msg.ed25519_signature_dep_b.signature[22] = 22;

    test_msg.ed25519_signature_dep_b.signature[23] = 23;

    test_msg.ed25519_signature_dep_b.signature[24] = 24;

    test_msg.ed25519_signature_dep_b.signature[25] = 25;

    test_msg.ed25519_signature_dep_b.signature[26] = 26;

    test_msg.ed25519_signature_dep_b.signature[27] = 27;

    test_msg.ed25519_signature_dep_b.signature[28] = 28;

    test_msg.ed25519_signature_dep_b.signature[29] = 29;

    test_msg.ed25519_signature_dep_b.signature[30] = 30;

    test_msg.ed25519_signature_dep_b.signature[31] = 31;

    test_msg.ed25519_signature_dep_b.signature[32] = 32;

    test_msg.ed25519_signature_dep_b.signature[33] = 33;

    test_msg.ed25519_signature_dep_b.signature[34] = 34;

    test_msg.ed25519_signature_dep_b.signature[35] = 35;

    test_msg.ed25519_signature_dep_b.signature[36] = 36;

    test_msg.ed25519_signature_dep_b.signature[37] = 37;

    test_msg.ed25519_signature_dep_b.signature[38] = 38;

    test_msg.ed25519_signature_dep_b.signature[39] = 39;

    test_msg.ed25519_signature_dep_b.signature[40] = 40;

    test_msg.ed25519_signature_dep_b.signature[41] = 41;

    test_msg.ed25519_signature_dep_b.signature[42] = 42;

    test_msg.ed25519_signature_dep_b.signature[43] = 43;

    test_msg.ed25519_signature_dep_b.signature[44] = 44;

    test_msg.ed25519_signature_dep_b.signature[45] = 45;

    test_msg.ed25519_signature_dep_b.signature[46] = 46;

    test_msg.ed25519_signature_dep_b.signature[47] = 47;

    test_msg.ed25519_signature_dep_b.signature[48] = 48;

    test_msg.ed25519_signature_dep_b.signature[49] = 49;

    test_msg.ed25519_signature_dep_b.signature[50] = 50;

    test_msg.ed25519_signature_dep_b.signature[51] = 51;

    test_msg.ed25519_signature_dep_b.signature[52] = 52;

    test_msg.ed25519_signature_dep_b.signature[53] = 53;

    test_msg.ed25519_signature_dep_b.signature[54] = 54;

    test_msg.ed25519_signature_dep_b.signature[55] = 55;

    test_msg.ed25519_signature_dep_b.signature[56] = 56;

    test_msg.ed25519_signature_dep_b.signature[57] = 57;

    test_msg.ed25519_signature_dep_b.signature[58] = 58;

    test_msg.ed25519_signature_dep_b.signature[59] = 59;

    test_msg.ed25519_signature_dep_b.signature[60] = 60;

    test_msg.ed25519_signature_dep_b.signature[61] = 61;

    test_msg.ed25519_signature_dep_b.signature[62] = 62;

    test_msg.ed25519_signature_dep_b.signature[63] = 63;

    test_msg.ed25519_signature_dep_b.signed_messages[0] = 5000;

    test_msg.ed25519_signature_dep_b.signed_messages[1] = 5234;

    test_msg.ed25519_signature_dep_b.signed_messages[2] = 5468;

    test_msg.ed25519_signature_dep_b.signed_messages[3] = 5702;

    test_msg.ed25519_signature_dep_b.signed_messages[4] = 5936;

    test_msg.ed25519_signature_dep_b.signed_messages[5] = 6170;

    test_msg.ed25519_signature_dep_b.signed_messages[6] = 6404;

    test_msg.ed25519_signature_dep_b.signed_messages[7] = 6638;

    test_msg.ed25519_signature_dep_b.signed_messages[8] = 6872;

    test_msg.ed25519_signature_dep_b.signed_messages[9] = 7106;

    test_msg.ed25519_signature_dep_b.signed_messages[10] = 7340;

    test_msg.ed25519_signature_dep_b.signed_messages[11] = 7574;

    test_msg.ed25519_signature_dep_b.signed_messages[12] = 7808;

    test_msg.ed25519_signature_dep_b.signed_messages[13] = 8042;

    test_msg.ed25519_signature_dep_b.signed_messages[14] = 8276;

    test_msg.ed25519_signature_dep_b.signed_messages[15] = 8510;

    test_msg.ed25519_signature_dep_b.signed_messages[16] = 8744;

    test_msg.ed25519_signature_dep_b.signed_messages[17] = 8978;

    test_msg.ed25519_signature_dep_b.signed_messages[18] = 9212;

    test_msg.ed25519_signature_dep_b.signed_messages[19] = 9446;

    test_msg.ed25519_signature_dep_b.signed_messages[20] = 9680;

    test_msg.ed25519_signature_dep_b.signed_messages[21] = 9914;

    test_msg.ed25519_signature_dep_b.signed_messages[22] = 10148;

    test_msg.ed25519_signature_dep_b.signed_messages[23] = 10382;

    test_msg.ed25519_signature_dep_b.signed_messages[24] = 10616;

    test_msg.ed25519_signature_dep_b.stream_counter = 1;

    sbp_message_send(&sbp_state, SbpMsgEd25519SignatureDepB, 66, &test_msg,
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

    ck_assert_msg(sbp_message_cmp(SbpMsgEd25519SignatureDepB, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.fingerprint[0] == 100,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.fingerprint[0], "
                  "expected 100, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[0]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.fingerprint[1] == 101,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.fingerprint[1], "
                  "expected 101, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[1]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.fingerprint[2] == 102,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.fingerprint[2], "
                  "expected 102, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[2]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.fingerprint[3] == 103,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.fingerprint[3], "
                  "expected 103, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[3]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.fingerprint[4] == 104,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.fingerprint[4], "
                  "expected 104, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[4]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.fingerprint[5] == 105,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.fingerprint[5], "
                  "expected 105, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[5]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.fingerprint[6] == 106,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.fingerprint[6], "
                  "expected 106, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[6]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.fingerprint[7] == 107,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.fingerprint[7], "
                  "expected 107, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[7]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.fingerprint[8] == 108,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.fingerprint[8], "
                  "expected 108, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[8]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.fingerprint[9] == 109,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.fingerprint[9], "
                  "expected 109, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[9]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.fingerprint[10] == 110,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.fingerprint[10], expected 110, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[10]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.fingerprint[11] == 111,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.fingerprint[11], expected 111, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[11]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.fingerprint[12] == 112,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.fingerprint[12], expected 112, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[12]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.fingerprint[13] == 113,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.fingerprint[13], expected 113, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[13]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.fingerprint[14] == 114,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.fingerprint[14], expected 114, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[14]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.fingerprint[15] == 115,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.fingerprint[15], expected 115, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[15]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.fingerprint[16] == 116,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.fingerprint[16], expected 116, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[16]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.fingerprint[17] == 117,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.fingerprint[17], expected 117, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[17]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.fingerprint[18] == 118,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.fingerprint[18], expected 118, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[18]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.fingerprint[19] == 119,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.fingerprint[19], expected 119, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.fingerprint[19]);

    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.n_signed_messages == 25,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.n_signed_messages, expected 25, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.n_signed_messages);

    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.on_demand_counter == 0,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.on_demand_counter, expected 0, "
        "is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.on_demand_counter);

    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[0] == 0,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[0], expected "
                  "0, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[0]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[1] == 1,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[1], expected "
                  "1, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[1]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[2] == 2,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[2], expected "
                  "2, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[2]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[3] == 3,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[3], expected "
                  "3, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[3]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[4] == 4,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[4], expected "
                  "4, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[4]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[5] == 5,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[5], expected "
                  "5, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[5]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[6] == 6,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[6], expected "
                  "6, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[6]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[7] == 7,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[7], expected "
                  "7, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[7]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[8] == 8,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[8], expected "
                  "8, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[8]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[9] == 9,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[9], expected "
                  "9, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[9]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[10] == 10,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[10], "
                  "expected 10, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[10]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[11] == 11,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[11], "
                  "expected 11, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[11]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[12] == 12,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[12], "
                  "expected 12, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[12]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[13] == 13,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[13], "
                  "expected 13, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[13]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[14] == 14,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[14], "
                  "expected 14, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[14]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[15] == 15,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[15], "
                  "expected 15, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[15]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[16] == 16,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[16], "
                  "expected 16, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[16]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[17] == 17,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[17], "
                  "expected 17, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[17]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[18] == 18,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[18], "
                  "expected 18, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[18]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[19] == 19,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[19], "
                  "expected 19, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[19]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[20] == 20,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[20], "
                  "expected 20, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[20]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[21] == 21,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[21], "
                  "expected 21, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[21]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[22] == 22,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[22], "
                  "expected 22, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[22]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[23] == 23,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[23], "
                  "expected 23, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[23]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[24] == 24,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[24], "
                  "expected 24, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[24]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[25] == 25,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[25], "
                  "expected 25, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[25]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[26] == 26,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[26], "
                  "expected 26, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[26]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[27] == 27,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[27], "
                  "expected 27, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[27]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[28] == 28,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[28], "
                  "expected 28, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[28]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[29] == 29,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[29], "
                  "expected 29, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[29]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[30] == 30,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[30], "
                  "expected 30, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[30]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[31] == 31,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[31], "
                  "expected 31, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[31]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[32] == 32,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[32], "
                  "expected 32, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[32]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[33] == 33,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[33], "
                  "expected 33, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[33]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[34] == 34,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[34], "
                  "expected 34, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[34]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[35] == 35,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[35], "
                  "expected 35, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[35]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[36] == 36,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[36], "
                  "expected 36, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[36]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[37] == 37,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[37], "
                  "expected 37, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[37]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[38] == 38,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[38], "
                  "expected 38, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[38]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[39] == 39,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[39], "
                  "expected 39, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[39]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[40] == 40,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[40], "
                  "expected 40, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[40]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[41] == 41,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[41], "
                  "expected 41, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[41]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[42] == 42,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[42], "
                  "expected 42, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[42]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[43] == 43,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[43], "
                  "expected 43, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[43]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[44] == 44,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[44], "
                  "expected 44, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[44]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[45] == 45,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[45], "
                  "expected 45, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[45]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[46] == 46,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[46], "
                  "expected 46, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[46]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[47] == 47,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[47], "
                  "expected 47, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[47]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[48] == 48,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[48], "
                  "expected 48, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[48]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[49] == 49,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[49], "
                  "expected 49, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[49]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[50] == 50,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[50], "
                  "expected 50, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[50]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[51] == 51,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[51], "
                  "expected 51, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[51]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[52] == 52,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[52], "
                  "expected 52, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[52]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[53] == 53,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[53], "
                  "expected 53, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[53]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[54] == 54,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[54], "
                  "expected 54, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[54]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[55] == 55,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[55], "
                  "expected 55, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[55]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[56] == 56,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[56], "
                  "expected 56, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[56]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[57] == 57,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[57], "
                  "expected 57, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[57]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[58] == 58,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[58], "
                  "expected 58, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[58]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[59] == 59,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[59], "
                  "expected 59, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[59]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[60] == 60,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[60], "
                  "expected 60, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[60]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[61] == 61,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[61], "
                  "expected 61, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[61]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[62] == 62,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[62], "
                  "expected 62, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[62]);
    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.signature[63] == 63,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.signature[63], "
                  "expected 63, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.signature[63]);

    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[0] == 5000,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[0], expected "
        "5000, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[0]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[1] == 5234,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[1], expected "
        "5234, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[1]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[2] == 5468,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[2], expected "
        "5468, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[2]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[3] == 5702,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[3], expected "
        "5702, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[3]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[4] == 5936,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[4], expected "
        "5936, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[4]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[5] == 6170,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[5], expected "
        "6170, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[5]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[6] == 6404,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[6], expected "
        "6404, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[6]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[7] == 6638,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[7], expected "
        "6638, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[7]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[8] == 6872,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[8], expected "
        "6872, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[8]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[9] == 7106,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[9], expected "
        "7106, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[9]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[10] == 7340,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[10], expected "
        "7340, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[10]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[11] == 7574,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[11], expected "
        "7574, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[11]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[12] == 7808,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[12], expected "
        "7808, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[12]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[13] == 8042,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[13], expected "
        "8042, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[13]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[14] == 8276,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[14], expected "
        "8276, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[14]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[15] == 8510,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[15], expected "
        "8510, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[15]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[16] == 8744,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[16], expected "
        "8744, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[16]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[17] == 8978,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[17], expected "
        "8978, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[17]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[18] == 9212,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[18], expected "
        "9212, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[18]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[19] == 9446,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[19], expected "
        "9446, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[19]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[20] == 9680,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[20], expected "
        "9680, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[20]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[21] == 9914,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[21], expected "
        "9914, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[21]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[22] == 10148,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[22], expected "
        "10148, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[22]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[23] == 10382,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[23], expected "
        "10382, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[23]);
    ck_assert_msg(
        last_msg.msg.ed25519_signature_dep_b.signed_messages[24] == 10616,
        "incorrect value for "
        "last_msg.msg.ed25519_signature_dep_b.signed_messages[24], expected "
        "10616, is %" PRId64,
        (int64_t)last_msg.msg.ed25519_signature_dep_b.signed_messages[24]);

    ck_assert_msg(last_msg.msg.ed25519_signature_dep_b.stream_counter == 1,
                  "incorrect value for "
                  "last_msg.msg.ed25519_signature_dep_b.stream_counter, "
                  "expected 1, is %" PRId64,
                  (int64_t)last_msg.msg.ed25519_signature_dep_b.stream_counter);
  }
}
END_TEST

Suite *auto_check_sbp_signing_MsgEd25519SignatureDepB_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_signing_MsgEd25519SignatureDepB");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_signing_MsgEd25519SignatureDepB");
  tcase_add_test(tc_acq, test_auto_check_sbp_signing_MsgEd25519SignatureDepB);
  suite_add_tcase(s, tc_acq);
  return s;
}
