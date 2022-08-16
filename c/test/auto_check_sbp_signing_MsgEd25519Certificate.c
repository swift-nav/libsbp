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

START_TEST(test_auto_check_sbp_signing_MsgEd25519Certificate) {
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

    sbp_callback_register(&sbp_state, 0xC02, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

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

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ed25519_certificate.certificate_bytes[0] = 0;

    test_msg.ed25519_certificate.certificate_bytes[1] = 3;

    test_msg.ed25519_certificate.certificate_bytes[2] = 6;

    test_msg.ed25519_certificate.certificate_bytes[3] = 9;

    test_msg.ed25519_certificate.certificate_bytes[4] = 12;

    test_msg.ed25519_certificate.certificate_bytes[5] = 15;

    test_msg.ed25519_certificate.certificate_bytes[6] = 18;

    test_msg.ed25519_certificate.certificate_bytes[7] = 21;

    test_msg.ed25519_certificate.certificate_bytes[8] = 24;

    test_msg.ed25519_certificate.certificate_bytes[9] = 27;

    test_msg.ed25519_certificate.certificate_bytes[10] = 30;

    test_msg.ed25519_certificate.certificate_bytes[11] = 33;

    test_msg.ed25519_certificate.certificate_bytes[12] = 36;

    test_msg.ed25519_certificate.certificate_bytes[13] = 39;

    test_msg.ed25519_certificate.certificate_bytes[14] = 42;

    test_msg.ed25519_certificate.certificate_bytes[15] = 45;

    test_msg.ed25519_certificate.certificate_bytes[16] = 48;

    test_msg.ed25519_certificate.certificate_bytes[17] = 51;

    test_msg.ed25519_certificate.certificate_bytes[18] = 54;

    test_msg.ed25519_certificate.certificate_bytes[19] = 57;

    test_msg.ed25519_certificate.certificate_bytes[20] = 60;

    test_msg.ed25519_certificate.certificate_bytes[21] = 63;

    test_msg.ed25519_certificate.certificate_bytes[22] = 66;

    test_msg.ed25519_certificate.certificate_bytes[23] = 69;

    test_msg.ed25519_certificate.certificate_bytes[24] = 72;

    test_msg.ed25519_certificate.certificate_bytes[25] = 75;

    test_msg.ed25519_certificate.certificate_bytes[26] = 78;

    test_msg.ed25519_certificate.certificate_bytes[27] = 81;

    test_msg.ed25519_certificate.certificate_bytes[28] = 84;

    test_msg.ed25519_certificate.certificate_bytes[29] = 87;

    test_msg.ed25519_certificate.certificate_bytes[30] = 90;

    test_msg.ed25519_certificate.certificate_bytes[31] = 93;

    test_msg.ed25519_certificate.certificate_bytes[32] = 96;

    test_msg.ed25519_certificate.certificate_bytes[33] = 99;

    test_msg.ed25519_certificate.certificate_bytes[34] = 102;

    test_msg.ed25519_certificate.certificate_bytes[35] = 105;

    test_msg.ed25519_certificate.certificate_bytes[36] = 108;

    test_msg.ed25519_certificate.certificate_bytes[37] = 111;

    test_msg.ed25519_certificate.certificate_bytes[38] = 114;

    test_msg.ed25519_certificate.certificate_bytes[39] = 117;

    test_msg.ed25519_certificate.certificate_bytes[40] = 120;

    test_msg.ed25519_certificate.certificate_bytes[41] = 123;

    test_msg.ed25519_certificate.certificate_bytes[42] = 126;

    test_msg.ed25519_certificate.certificate_bytes[43] = 129;

    test_msg.ed25519_certificate.certificate_bytes[44] = 132;

    test_msg.ed25519_certificate.certificate_bytes[45] = 135;

    test_msg.ed25519_certificate.certificate_bytes[46] = 138;

    test_msg.ed25519_certificate.certificate_bytes[47] = 141;

    test_msg.ed25519_certificate.certificate_bytes[48] = 144;

    test_msg.ed25519_certificate.certificate_bytes[49] = 147;

    test_msg.ed25519_certificate.certificate_bytes[50] = 150;

    test_msg.ed25519_certificate.certificate_bytes[51] = 153;

    test_msg.ed25519_certificate.certificate_bytes[52] = 156;

    test_msg.ed25519_certificate.certificate_bytes[53] = 159;

    test_msg.ed25519_certificate.certificate_bytes[54] = 162;

    test_msg.ed25519_certificate.certificate_bytes[55] = 165;

    test_msg.ed25519_certificate.certificate_bytes[56] = 168;

    test_msg.ed25519_certificate.certificate_bytes[57] = 171;

    test_msg.ed25519_certificate.certificate_bytes[58] = 174;

    test_msg.ed25519_certificate.certificate_bytes[59] = 177;

    test_msg.ed25519_certificate.certificate_bytes[60] = 180;

    test_msg.ed25519_certificate.certificate_bytes[61] = 183;

    test_msg.ed25519_certificate.certificate_bytes[62] = 186;

    test_msg.ed25519_certificate.certificate_bytes[63] = 189;

    test_msg.ed25519_certificate.certificate_bytes[64] = 192;

    test_msg.ed25519_certificate.certificate_bytes[65] = 195;

    test_msg.ed25519_certificate.certificate_bytes[66] = 198;

    test_msg.ed25519_certificate.certificate_bytes[67] = 201;

    test_msg.ed25519_certificate.certificate_bytes[68] = 204;

    test_msg.ed25519_certificate.certificate_bytes[69] = 207;

    test_msg.ed25519_certificate.certificate_bytes[70] = 210;

    test_msg.ed25519_certificate.certificate_bytes[71] = 213;

    test_msg.ed25519_certificate.certificate_bytes[72] = 216;

    test_msg.ed25519_certificate.certificate_bytes[73] = 219;

    test_msg.ed25519_certificate.certificate_bytes[74] = 222;

    test_msg.ed25519_certificate.certificate_bytes[75] = 225;

    test_msg.ed25519_certificate.certificate_bytes[76] = 228;

    test_msg.ed25519_certificate.certificate_bytes[77] = 231;

    test_msg.ed25519_certificate.certificate_bytes[78] = 234;

    test_msg.ed25519_certificate.certificate_bytes[79] = 237;

    test_msg.ed25519_certificate.certificate_bytes[80] = 240;

    test_msg.ed25519_certificate.certificate_bytes[81] = 243;

    test_msg.ed25519_certificate.certificate_bytes[82] = 246;

    test_msg.ed25519_certificate.certificate_bytes[83] = 249;

    test_msg.ed25519_certificate.certificate_bytes[84] = 252;

    test_msg.ed25519_certificate.fingerprint[0] = 100;

    test_msg.ed25519_certificate.fingerprint[1] = 101;

    test_msg.ed25519_certificate.fingerprint[2] = 102;

    test_msg.ed25519_certificate.fingerprint[3] = 103;

    test_msg.ed25519_certificate.fingerprint[4] = 104;

    test_msg.ed25519_certificate.fingerprint[5] = 105;

    test_msg.ed25519_certificate.fingerprint[6] = 106;

    test_msg.ed25519_certificate.fingerprint[7] = 107;

    test_msg.ed25519_certificate.fingerprint[8] = 108;

    test_msg.ed25519_certificate.fingerprint[9] = 109;

    test_msg.ed25519_certificate.fingerprint[10] = 110;

    test_msg.ed25519_certificate.fingerprint[11] = 111;

    test_msg.ed25519_certificate.fingerprint[12] = 112;

    test_msg.ed25519_certificate.fingerprint[13] = 113;

    test_msg.ed25519_certificate.fingerprint[14] = 114;

    test_msg.ed25519_certificate.fingerprint[15] = 115;

    test_msg.ed25519_certificate.fingerprint[16] = 116;

    test_msg.ed25519_certificate.fingerprint[17] = 117;

    test_msg.ed25519_certificate.fingerprint[18] = 118;

    test_msg.ed25519_certificate.fingerprint[19] = 119;

    test_msg.ed25519_certificate.n_certificate_bytes = 85;

    test_msg.ed25519_certificate.n_msg = 16;

    sbp_message_send(&sbp_state, SbpMsgEd25519Certificate, 66, &test_msg,
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

    ck_assert_msg(sbp_message_cmp(SbpMsgEd25519Certificate, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[0] == 0,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[0], "
                  "expected 0, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[0]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[1] == 3,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[1], "
                  "expected 3, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[1]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[2] == 6,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[2], "
                  "expected 6, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[2]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[3] == 9,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[3], "
                  "expected 9, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[3]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[4] == 12,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[4], "
                  "expected 12, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[4]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[5] == 15,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[5], "
                  "expected 15, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[5]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[6] == 18,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[6], "
                  "expected 18, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[6]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[7] == 21,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[7], "
                  "expected 21, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[7]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[8] == 24,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[8], "
                  "expected 24, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[8]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[9] == 27,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[9], "
                  "expected 27, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[9]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[10] == 30,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[10], "
                  "expected 30, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[10]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[11] == 33,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[11], "
                  "expected 33, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[11]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[12] == 36,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[12], "
                  "expected 36, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[12]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[13] == 39,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[13], "
                  "expected 39, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[13]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[14] == 42,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[14], "
                  "expected 42, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[14]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[15] == 45,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[15], "
                  "expected 45, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[15]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[16] == 48,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[16], "
                  "expected 48, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[16]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[17] == 51,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[17], "
                  "expected 51, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[17]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[18] == 54,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[18], "
                  "expected 54, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[18]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[19] == 57,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[19], "
                  "expected 57, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[19]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[20] == 60,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[20], "
                  "expected 60, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[20]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[21] == 63,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[21], "
                  "expected 63, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[21]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[22] == 66,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[22], "
                  "expected 66, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[22]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[23] == 69,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[23], "
                  "expected 69, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[23]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[24] == 72,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[24], "
                  "expected 72, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[24]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[25] == 75,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[25], "
                  "expected 75, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[25]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[26] == 78,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[26], "
                  "expected 78, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[26]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[27] == 81,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[27], "
                  "expected 81, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[27]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[28] == 84,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[28], "
                  "expected 84, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[28]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[29] == 87,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[29], "
                  "expected 87, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[29]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[30] == 90,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[30], "
                  "expected 90, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[30]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[31] == 93,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[31], "
                  "expected 93, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[31]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[32] == 96,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[32], "
                  "expected 96, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[32]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[33] == 99,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[33], "
                  "expected 99, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[33]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[34] == 102,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[34], "
                  "expected 102, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[34]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[35] == 105,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[35], "
                  "expected 105, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[35]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[36] == 108,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[36], "
                  "expected 108, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[36]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[37] == 111,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[37], "
                  "expected 111, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[37]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[38] == 114,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[38], "
                  "expected 114, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[38]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[39] == 117,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[39], "
                  "expected 117, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[39]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[40] == 120,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[40], "
                  "expected 120, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[40]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[41] == 123,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[41], "
                  "expected 123, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[41]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[42] == 126,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[42], "
                  "expected 126, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[42]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[43] == 129,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[43], "
                  "expected 129, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[43]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[44] == 132,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[44], "
                  "expected 132, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[44]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[45] == 135,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[45], "
                  "expected 135, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[45]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[46] == 138,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[46], "
                  "expected 138, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[46]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[47] == 141,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[47], "
                  "expected 141, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[47]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[48] == 144,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[48], "
                  "expected 144, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[48]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[49] == 147,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[49], "
                  "expected 147, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[49]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[50] == 150,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[50], "
                  "expected 150, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[50]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[51] == 153,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[51], "
                  "expected 153, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[51]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[52] == 156,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[52], "
                  "expected 156, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[52]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[53] == 159,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[53], "
                  "expected 159, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[53]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[54] == 162,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[54], "
                  "expected 162, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[54]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[55] == 165,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[55], "
                  "expected 165, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[55]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[56] == 168,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[56], "
                  "expected 168, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[56]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[57] == 171,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[57], "
                  "expected 171, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[57]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[58] == 174,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[58], "
                  "expected 174, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[58]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[59] == 177,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[59], "
                  "expected 177, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[59]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[60] == 180,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[60], "
                  "expected 180, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[60]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[61] == 183,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[61], "
                  "expected 183, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[61]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[62] == 186,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[62], "
                  "expected 186, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[62]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[63] == 189,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[63], "
                  "expected 189, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[63]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[64] == 192,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[64], "
                  "expected 192, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[64]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[65] == 195,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[65], "
                  "expected 195, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[65]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[66] == 198,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[66], "
                  "expected 198, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[66]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[67] == 201,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[67], "
                  "expected 201, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[67]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[68] == 204,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[68], "
                  "expected 204, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[68]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[69] == 207,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[69], "
                  "expected 207, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[69]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[70] == 210,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[70], "
                  "expected 210, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[70]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[71] == 213,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[71], "
                  "expected 213, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[71]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[72] == 216,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[72], "
                  "expected 216, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[72]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[73] == 219,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[73], "
                  "expected 219, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[73]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[74] == 222,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[74], "
                  "expected 222, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[74]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[75] == 225,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[75], "
                  "expected 225, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[75]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[76] == 228,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[76], "
                  "expected 228, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[76]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[77] == 231,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[77], "
                  "expected 231, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[77]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[78] == 234,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[78], "
                  "expected 234, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[78]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[79] == 237,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[79], "
                  "expected 237, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[79]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[80] == 240,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[80], "
                  "expected 240, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[80]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[81] == 243,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[81], "
                  "expected 243, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[81]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[82] == 246,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[82], "
                  "expected 246, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[82]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[83] == 249,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[83], "
                  "expected 249, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[83]);
    ck_assert_msg(last_msg.msg.ed25519_certificate.certificate_bytes[84] == 252,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.certificate_bytes[84], "
                  "expected 252, is %d",
                  last_msg.msg.ed25519_certificate.certificate_bytes[84]);

    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[0] == 100,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[0], "
        "expected 100, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[0]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[1] == 101,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[1], "
        "expected 101, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[1]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[2] == 102,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[2], "
        "expected 102, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[2]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[3] == 103,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[3], "
        "expected 103, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[3]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[4] == 104,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[4], "
        "expected 104, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[4]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[5] == 105,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[5], "
        "expected 105, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[5]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[6] == 106,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[6], "
        "expected 106, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[6]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[7] == 107,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[7], "
        "expected 107, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[7]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[8] == 108,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[8], "
        "expected 108, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[8]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[9] == 109,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[9], "
        "expected 109, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[9]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[10] == 110,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[10], "
        "expected 110, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[10]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[11] == 111,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[11], "
        "expected 111, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[11]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[12] == 112,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[12], "
        "expected 112, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[12]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[13] == 113,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[13], "
        "expected 113, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[13]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[14] == 114,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[14], "
        "expected 114, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[14]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[15] == 115,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[15], "
        "expected 115, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[15]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[16] == 116,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[16], "
        "expected 116, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[16]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[17] == 117,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[17], "
        "expected 117, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[17]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[18] == 118,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[18], "
        "expected 118, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[18]);
    ck_assert_msg(
        last_msg.msg.ed25519_certificate.fingerprint[19] == 119,
        "incorrect value for last_msg.msg.ed25519_certificate.fingerprint[19], "
        "expected 119, is %d",
        last_msg.msg.ed25519_certificate.fingerprint[19]);

    ck_assert_msg(last_msg.msg.ed25519_certificate.n_certificate_bytes == 85,
                  "incorrect value for "
                  "last_msg.msg.ed25519_certificate.n_certificate_bytes, "
                  "expected 85, is %d",
                  last_msg.msg.ed25519_certificate.n_certificate_bytes);

    ck_assert_msg(last_msg.msg.ed25519_certificate.n_msg == 16,
                  "incorrect value for last_msg.msg.ed25519_certificate.n_msg, "
                  "expected 16, is %d",
                  last_msg.msg.ed25519_certificate.n_msg);
  }
}
END_TEST

Suite *auto_check_sbp_signing_MsgEd25519Certificate_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_signing_MsgEd25519Certificate");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_signing_MsgEd25519Certificate");
  tcase_add_test(tc_acq, test_auto_check_sbp_signing_MsgEd25519Certificate);
  suite_add_tcase(s, tc_acq);
  return s;
}