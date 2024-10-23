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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgCertificateChainDep.yaml by
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

START_TEST(test_auto_check_sbp_signing_MsgCertificateChainDep) {
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

    sbp_callback_register(&sbp_state, 0xC05, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

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

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.certificate_chain_dep.corrections_certificate[0] = 20;

    test_msg.certificate_chain_dep.corrections_certificate[1] = 21;

    test_msg.certificate_chain_dep.corrections_certificate[2] = 22;

    test_msg.certificate_chain_dep.corrections_certificate[3] = 23;

    test_msg.certificate_chain_dep.corrections_certificate[4] = 24;

    test_msg.certificate_chain_dep.corrections_certificate[5] = 25;

    test_msg.certificate_chain_dep.corrections_certificate[6] = 26;

    test_msg.certificate_chain_dep.corrections_certificate[7] = 27;

    test_msg.certificate_chain_dep.corrections_certificate[8] = 28;

    test_msg.certificate_chain_dep.corrections_certificate[9] = 29;

    test_msg.certificate_chain_dep.corrections_certificate[10] = 10;

    test_msg.certificate_chain_dep.corrections_certificate[11] = 11;

    test_msg.certificate_chain_dep.corrections_certificate[12] = 12;

    test_msg.certificate_chain_dep.corrections_certificate[13] = 13;

    test_msg.certificate_chain_dep.corrections_certificate[14] = 14;

    test_msg.certificate_chain_dep.corrections_certificate[15] = 15;

    test_msg.certificate_chain_dep.corrections_certificate[16] = 16;

    test_msg.certificate_chain_dep.corrections_certificate[17] = 17;

    test_msg.certificate_chain_dep.corrections_certificate[18] = 18;

    test_msg.certificate_chain_dep.corrections_certificate[19] = 19;

    test_msg.certificate_chain_dep.expiration.day = 30;

    test_msg.certificate_chain_dep.expiration.hours = 12;

    test_msg.certificate_chain_dep.expiration.minutes = 34;

    test_msg.certificate_chain_dep.expiration.month = 3;

    test_msg.certificate_chain_dep.expiration.ns = 123456789;

    test_msg.certificate_chain_dep.expiration.seconds = 59;

    test_msg.certificate_chain_dep.expiration.year = 2024;

    test_msg.certificate_chain_dep.intermediate_certificate[0] = 10;

    test_msg.certificate_chain_dep.intermediate_certificate[1] = 11;

    test_msg.certificate_chain_dep.intermediate_certificate[2] = 12;

    test_msg.certificate_chain_dep.intermediate_certificate[3] = 13;

    test_msg.certificate_chain_dep.intermediate_certificate[4] = 14;

    test_msg.certificate_chain_dep.intermediate_certificate[5] = 15;

    test_msg.certificate_chain_dep.intermediate_certificate[6] = 16;

    test_msg.certificate_chain_dep.intermediate_certificate[7] = 17;

    test_msg.certificate_chain_dep.intermediate_certificate[8] = 18;

    test_msg.certificate_chain_dep.intermediate_certificate[9] = 19;

    test_msg.certificate_chain_dep.intermediate_certificate[10] = 0;

    test_msg.certificate_chain_dep.intermediate_certificate[11] = 1;

    test_msg.certificate_chain_dep.intermediate_certificate[12] = 2;

    test_msg.certificate_chain_dep.intermediate_certificate[13] = 3;

    test_msg.certificate_chain_dep.intermediate_certificate[14] = 4;

    test_msg.certificate_chain_dep.intermediate_certificate[15] = 5;

    test_msg.certificate_chain_dep.intermediate_certificate[16] = 6;

    test_msg.certificate_chain_dep.intermediate_certificate[17] = 7;

    test_msg.certificate_chain_dep.intermediate_certificate[18] = 8;

    test_msg.certificate_chain_dep.intermediate_certificate[19] = 9;

    test_msg.certificate_chain_dep.root_certificate[0] = 0;

    test_msg.certificate_chain_dep.root_certificate[1] = 1;

    test_msg.certificate_chain_dep.root_certificate[2] = 2;

    test_msg.certificate_chain_dep.root_certificate[3] = 3;

    test_msg.certificate_chain_dep.root_certificate[4] = 4;

    test_msg.certificate_chain_dep.root_certificate[5] = 5;

    test_msg.certificate_chain_dep.root_certificate[6] = 6;

    test_msg.certificate_chain_dep.root_certificate[7] = 7;

    test_msg.certificate_chain_dep.root_certificate[8] = 8;

    test_msg.certificate_chain_dep.root_certificate[9] = 9;

    test_msg.certificate_chain_dep.root_certificate[10] = 10;

    test_msg.certificate_chain_dep.root_certificate[11] = 11;

    test_msg.certificate_chain_dep.root_certificate[12] = 12;

    test_msg.certificate_chain_dep.root_certificate[13] = 13;

    test_msg.certificate_chain_dep.root_certificate[14] = 14;

    test_msg.certificate_chain_dep.root_certificate[15] = 15;

    test_msg.certificate_chain_dep.root_certificate[16] = 16;

    test_msg.certificate_chain_dep.root_certificate[17] = 17;

    test_msg.certificate_chain_dep.root_certificate[18] = 18;

    test_msg.certificate_chain_dep.root_certificate[19] = 19;

    test_msg.certificate_chain_dep.signature[0] = 0;

    test_msg.certificate_chain_dep.signature[1] = 1;

    test_msg.certificate_chain_dep.signature[2] = 2;

    test_msg.certificate_chain_dep.signature[3] = 3;

    test_msg.certificate_chain_dep.signature[4] = 4;

    test_msg.certificate_chain_dep.signature[5] = 5;

    test_msg.certificate_chain_dep.signature[6] = 6;

    test_msg.certificate_chain_dep.signature[7] = 7;

    test_msg.certificate_chain_dep.signature[8] = 0;

    test_msg.certificate_chain_dep.signature[9] = 1;

    test_msg.certificate_chain_dep.signature[10] = 2;

    test_msg.certificate_chain_dep.signature[11] = 3;

    test_msg.certificate_chain_dep.signature[12] = 4;

    test_msg.certificate_chain_dep.signature[13] = 5;

    test_msg.certificate_chain_dep.signature[14] = 6;

    test_msg.certificate_chain_dep.signature[15] = 7;

    test_msg.certificate_chain_dep.signature[16] = 0;

    test_msg.certificate_chain_dep.signature[17] = 1;

    test_msg.certificate_chain_dep.signature[18] = 2;

    test_msg.certificate_chain_dep.signature[19] = 3;

    test_msg.certificate_chain_dep.signature[20] = 4;

    test_msg.certificate_chain_dep.signature[21] = 5;

    test_msg.certificate_chain_dep.signature[22] = 6;

    test_msg.certificate_chain_dep.signature[23] = 7;

    test_msg.certificate_chain_dep.signature[24] = 0;

    test_msg.certificate_chain_dep.signature[25] = 1;

    test_msg.certificate_chain_dep.signature[26] = 2;

    test_msg.certificate_chain_dep.signature[27] = 3;

    test_msg.certificate_chain_dep.signature[28] = 4;

    test_msg.certificate_chain_dep.signature[29] = 5;

    test_msg.certificate_chain_dep.signature[30] = 6;

    test_msg.certificate_chain_dep.signature[31] = 7;

    test_msg.certificate_chain_dep.signature[32] = 0;

    test_msg.certificate_chain_dep.signature[33] = 1;

    test_msg.certificate_chain_dep.signature[34] = 2;

    test_msg.certificate_chain_dep.signature[35] = 3;

    test_msg.certificate_chain_dep.signature[36] = 4;

    test_msg.certificate_chain_dep.signature[37] = 5;

    test_msg.certificate_chain_dep.signature[38] = 6;

    test_msg.certificate_chain_dep.signature[39] = 7;

    test_msg.certificate_chain_dep.signature[40] = 0;

    test_msg.certificate_chain_dep.signature[41] = 1;

    test_msg.certificate_chain_dep.signature[42] = 2;

    test_msg.certificate_chain_dep.signature[43] = 3;

    test_msg.certificate_chain_dep.signature[44] = 4;

    test_msg.certificate_chain_dep.signature[45] = 5;

    test_msg.certificate_chain_dep.signature[46] = 6;

    test_msg.certificate_chain_dep.signature[47] = 7;

    test_msg.certificate_chain_dep.signature[48] = 0;

    test_msg.certificate_chain_dep.signature[49] = 1;

    test_msg.certificate_chain_dep.signature[50] = 2;

    test_msg.certificate_chain_dep.signature[51] = 3;

    test_msg.certificate_chain_dep.signature[52] = 4;

    test_msg.certificate_chain_dep.signature[53] = 5;

    test_msg.certificate_chain_dep.signature[54] = 6;

    test_msg.certificate_chain_dep.signature[55] = 7;

    test_msg.certificate_chain_dep.signature[56] = 0;

    test_msg.certificate_chain_dep.signature[57] = 1;

    test_msg.certificate_chain_dep.signature[58] = 2;

    test_msg.certificate_chain_dep.signature[59] = 3;

    test_msg.certificate_chain_dep.signature[60] = 4;

    test_msg.certificate_chain_dep.signature[61] = 5;

    test_msg.certificate_chain_dep.signature[62] = 6;

    test_msg.certificate_chain_dep.signature[63] = 7;

    sbp_message_send(&sbp_state, SbpMsgCertificateChainDep, 66, &test_msg,
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

    ck_assert_msg(sbp_message_cmp(SbpMsgCertificateChainDep, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[0] == 20,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[0], "
        "expected 20, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.corrections_certificate[0]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[1] == 21,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[1], "
        "expected 21, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.corrections_certificate[1]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[2] == 22,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[2], "
        "expected 22, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.corrections_certificate[2]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[3] == 23,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[3], "
        "expected 23, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.corrections_certificate[3]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[4] == 24,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[4], "
        "expected 24, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.corrections_certificate[4]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[5] == 25,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[5], "
        "expected 25, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.corrections_certificate[5]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[6] == 26,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[6], "
        "expected 26, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.corrections_certificate[6]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[7] == 27,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[7], "
        "expected 27, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.corrections_certificate[7]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[8] == 28,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[8], "
        "expected 28, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.corrections_certificate[8]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[9] == 29,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[9], "
        "expected 29, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.corrections_certificate[9]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[10] == 10,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[10], "
        "expected 10, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.corrections_certificate[10]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[11] == 11,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[11], "
        "expected 11, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.corrections_certificate[11]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[12] == 12,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[12], "
        "expected 12, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.corrections_certificate[12]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[13] == 13,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[13], "
        "expected 13, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.corrections_certificate[13]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[14] == 14,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[14], "
        "expected 14, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.corrections_certificate[14]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[15] == 15,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[15], "
        "expected 15, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.corrections_certificate[15]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[16] == 16,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[16], "
        "expected 16, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.corrections_certificate[16]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[17] == 17,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[17], "
        "expected 17, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.corrections_certificate[17]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[18] == 18,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[18], "
        "expected 18, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.corrections_certificate[18]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.corrections_certificate[19] == 19,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.corrections_certificate[19], "
        "expected 19, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.corrections_certificate[19]);

    ck_assert_msg(last_msg.msg.certificate_chain_dep.expiration.day == 30,
                  "incorrect value for "
                  "last_msg.msg.certificate_chain_dep.expiration.day, expected "
                  "30, is %" PRId64,
                  (int64_t)last_msg.msg.certificate_chain_dep.expiration.day);

    ck_assert_msg(last_msg.msg.certificate_chain_dep.expiration.hours == 12,
                  "incorrect value for "
                  "last_msg.msg.certificate_chain_dep.expiration.hours, "
                  "expected 12, is %" PRId64,
                  (int64_t)last_msg.msg.certificate_chain_dep.expiration.hours);

    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.expiration.minutes == 34,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.expiration.minutes, expected 34, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.expiration.minutes);

    ck_assert_msg(last_msg.msg.certificate_chain_dep.expiration.month == 3,
                  "incorrect value for "
                  "last_msg.msg.certificate_chain_dep.expiration.month, "
                  "expected 3, is %" PRId64,
                  (int64_t)last_msg.msg.certificate_chain_dep.expiration.month);

    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.expiration.ns == 123456789,
        "incorrect value for last_msg.msg.certificate_chain_dep.expiration.ns, "
        "expected 123456789, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.expiration.ns);

    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.expiration.seconds == 59,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.expiration.seconds, expected 59, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.expiration.seconds);

    ck_assert_msg(last_msg.msg.certificate_chain_dep.expiration.year == 2024,
                  "incorrect value for "
                  "last_msg.msg.certificate_chain_dep.expiration.year, "
                  "expected 2024, is %" PRId64,
                  (int64_t)last_msg.msg.certificate_chain_dep.expiration.year);

    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[0] == 10,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[0], "
        "expected 10, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[0]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[1] == 11,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[1], "
        "expected 11, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[1]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[2] == 12,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[2], "
        "expected 12, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[2]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[3] == 13,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[3], "
        "expected 13, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[3]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[4] == 14,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[4], "
        "expected 14, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[4]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[5] == 15,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[5], "
        "expected 15, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[5]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[6] == 16,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[6], "
        "expected 16, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[6]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[7] == 17,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[7], "
        "expected 17, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[7]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[8] == 18,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[8], "
        "expected 18, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[8]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[9] == 19,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[9], "
        "expected 19, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[9]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[10] == 0,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[10], "
        "expected 0, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[10]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[11] == 1,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[11], "
        "expected 1, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[11]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[12] == 2,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[12], "
        "expected 2, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[12]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[13] == 3,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[13], "
        "expected 3, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[13]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[14] == 4,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[14], "
        "expected 4, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[14]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[15] == 5,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[15], "
        "expected 5, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[15]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[16] == 6,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[16], "
        "expected 6, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[16]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[17] == 7,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[17], "
        "expected 7, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[17]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[18] == 8,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[18], "
        "expected 8, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[18]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.intermediate_certificate[19] == 9,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.intermediate_certificate[19], "
        "expected 9, is %" PRId64,
        (int64_t)
            last_msg.msg.certificate_chain_dep.intermediate_certificate[19]);

    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[0] == 0,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[0], expected 0, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[0]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[1] == 1,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[1], expected 1, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[1]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[2] == 2,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[2], expected 2, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[2]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[3] == 3,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[3], expected 3, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[3]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[4] == 4,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[4], expected 4, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[4]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[5] == 5,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[5], expected 5, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[5]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[6] == 6,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[6], expected 6, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[6]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[7] == 7,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[7], expected 7, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[7]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[8] == 8,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[8], expected 8, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[8]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[9] == 9,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[9], expected 9, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[9]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[10] == 10,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[10], expected 10, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[10]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[11] == 11,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[11], expected 11, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[11]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[12] == 12,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[12], expected 12, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[12]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[13] == 13,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[13], expected 13, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[13]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[14] == 14,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[14], expected 14, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[14]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[15] == 15,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[15], expected 15, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[15]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[16] == 16,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[16], expected 16, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[16]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[17] == 17,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[17], expected 17, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[17]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[18] == 18,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[18], expected 18, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[18]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.root_certificate[19] == 19,
        "incorrect value for "
        "last_msg.msg.certificate_chain_dep.root_certificate[19], expected 19, "
        "is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[19]);

    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[0] == 0,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[0], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[0]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[1] == 1,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[1], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[1]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[2] == 2,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[2], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[2]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[3] == 3,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[3], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[3]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[4] == 4,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[4], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[4]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[5] == 5,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[5], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[5]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[6] == 6,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[6], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[6]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[7] == 7,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[7], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[7]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[8] == 0,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[8], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[8]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[9] == 1,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[9], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[9]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[10] == 2,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[10], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[10]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[11] == 3,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[11], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[11]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[12] == 4,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[12], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[12]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[13] == 5,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[13], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[13]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[14] == 6,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[14], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[14]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[15] == 7,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[15], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[15]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[16] == 0,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[16], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[16]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[17] == 1,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[17], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[17]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[18] == 2,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[18], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[18]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[19] == 3,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[19], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[19]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[20] == 4,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[20], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[20]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[21] == 5,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[21], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[21]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[22] == 6,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[22], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[22]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[23] == 7,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[23], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[23]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[24] == 0,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[24], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[24]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[25] == 1,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[25], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[25]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[26] == 2,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[26], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[26]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[27] == 3,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[27], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[27]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[28] == 4,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[28], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[28]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[29] == 5,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[29], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[29]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[30] == 6,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[30], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[30]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[31] == 7,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[31], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[31]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[32] == 0,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[32], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[32]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[33] == 1,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[33], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[33]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[34] == 2,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[34], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[34]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[35] == 3,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[35], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[35]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[36] == 4,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[36], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[36]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[37] == 5,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[37], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[37]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[38] == 6,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[38], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[38]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[39] == 7,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[39], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[39]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[40] == 0,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[40], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[40]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[41] == 1,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[41], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[41]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[42] == 2,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[42], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[42]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[43] == 3,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[43], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[43]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[44] == 4,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[44], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[44]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[45] == 5,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[45], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[45]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[46] == 6,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[46], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[46]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[47] == 7,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[47], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[47]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[48] == 0,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[48], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[48]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[49] == 1,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[49], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[49]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[50] == 2,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[50], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[50]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[51] == 3,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[51], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[51]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[52] == 4,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[52], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[52]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[53] == 5,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[53], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[53]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[54] == 6,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[54], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[54]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[55] == 7,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[55], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[55]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[56] == 0,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[56], "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[56]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[57] == 1,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[57], "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[57]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[58] == 2,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[58], "
        "expected 2, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[58]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[59] == 3,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[59], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[59]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[60] == 4,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[60], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[60]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[61] == 5,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[61], "
        "expected 5, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[61]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[62] == 6,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[62], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[62]);
    ck_assert_msg(
        last_msg.msg.certificate_chain_dep.signature[63] == 7,
        "incorrect value for last_msg.msg.certificate_chain_dep.signature[63], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.certificate_chain_dep.signature[63]);
  }
}
END_TEST

Suite *auto_check_sbp_signing_MsgCertificateChainDep_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_signing_MsgCertificateChainDep");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_signing_MsgCertificateChainDep");
  tcase_add_test(tc_acq, test_auto_check_sbp_signing_MsgCertificateChainDep);
  suite_add_tcase(s, tc_acq);
  return s;
}
