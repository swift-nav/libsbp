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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgItrf.yaml by generate.py. Do
// not modify by hand!

#include <check.h>
#include <libsbp/sbp.h>
#include <libsbp/v4/navigation.h>
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

START_TEST(test_auto_check_sbp_navigation_MsgItrf) {
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

    sbp_callback_register(&sbp_state, 580, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 68, 2,  66, 0, 124, 1,  2,  102, 111, 111, 0,  0,   0, 0,  0,  0,
        0,  0,  0,  0,  0, 0,   0,  0,  0,   0,   0,   0,  0,   0, 0,  0,  0,
        0,  0,  0,  0,  0, 3,   98, 97, 114, 0,   0,   0,  0,   0, 0,  0,  0,
        0,  0,  0,  0,  0, 0,   0,  0,  0,   0,   0,   0,  0,   0, 0,  0,  0,
        0,  0,  0,  4,  5, 0,   6,  0,  7,   0,   0,   0,  8,   0, 0,  0,  9,
        0,  0,  0,  10, 0, 0,   0,  11, 0,   0,   0,   12, 0,   0, 0,  13, 0,
        0,  0,  14, 0,  0, 0,   15, 0,  0,   0,   16,  0,  0,   0, 17, 0,  0,
        0,  18, 0,  0,  0, 19,  0,  0,  0,   20,  0,   66, 126,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.itrf.n_stub = 124;

    test_msg.itrf.stub[0] = 1;

    test_msg.itrf.stub[1] = 2;

    test_msg.itrf.stub[2] = 102;

    test_msg.itrf.stub[3] = 111;

    test_msg.itrf.stub[4] = 111;

    test_msg.itrf.stub[5] = 0;

    test_msg.itrf.stub[6] = 0;

    test_msg.itrf.stub[7] = 0;

    test_msg.itrf.stub[8] = 0;

    test_msg.itrf.stub[9] = 0;

    test_msg.itrf.stub[10] = 0;

    test_msg.itrf.stub[11] = 0;

    test_msg.itrf.stub[12] = 0;

    test_msg.itrf.stub[13] = 0;

    test_msg.itrf.stub[14] = 0;

    test_msg.itrf.stub[15] = 0;

    test_msg.itrf.stub[16] = 0;

    test_msg.itrf.stub[17] = 0;

    test_msg.itrf.stub[18] = 0;

    test_msg.itrf.stub[19] = 0;

    test_msg.itrf.stub[20] = 0;

    test_msg.itrf.stub[21] = 0;

    test_msg.itrf.stub[22] = 0;

    test_msg.itrf.stub[23] = 0;

    test_msg.itrf.stub[24] = 0;

    test_msg.itrf.stub[25] = 0;

    test_msg.itrf.stub[26] = 0;

    test_msg.itrf.stub[27] = 0;

    test_msg.itrf.stub[28] = 0;

    test_msg.itrf.stub[29] = 0;

    test_msg.itrf.stub[30] = 0;

    test_msg.itrf.stub[31] = 0;

    test_msg.itrf.stub[32] = 0;

    test_msg.itrf.stub[33] = 3;

    test_msg.itrf.stub[34] = 98;

    test_msg.itrf.stub[35] = 97;

    test_msg.itrf.stub[36] = 114;

    test_msg.itrf.stub[37] = 0;

    test_msg.itrf.stub[38] = 0;

    test_msg.itrf.stub[39] = 0;

    test_msg.itrf.stub[40] = 0;

    test_msg.itrf.stub[41] = 0;

    test_msg.itrf.stub[42] = 0;

    test_msg.itrf.stub[43] = 0;

    test_msg.itrf.stub[44] = 0;

    test_msg.itrf.stub[45] = 0;

    test_msg.itrf.stub[46] = 0;

    test_msg.itrf.stub[47] = 0;

    test_msg.itrf.stub[48] = 0;

    test_msg.itrf.stub[49] = 0;

    test_msg.itrf.stub[50] = 0;

    test_msg.itrf.stub[51] = 0;

    test_msg.itrf.stub[52] = 0;

    test_msg.itrf.stub[53] = 0;

    test_msg.itrf.stub[54] = 0;

    test_msg.itrf.stub[55] = 0;

    test_msg.itrf.stub[56] = 0;

    test_msg.itrf.stub[57] = 0;

    test_msg.itrf.stub[58] = 0;

    test_msg.itrf.stub[59] = 0;

    test_msg.itrf.stub[60] = 0;

    test_msg.itrf.stub[61] = 0;

    test_msg.itrf.stub[62] = 0;

    test_msg.itrf.stub[63] = 0;

    test_msg.itrf.stub[64] = 0;

    test_msg.itrf.stub[65] = 4;

    test_msg.itrf.stub[66] = 5;

    test_msg.itrf.stub[67] = 0;

    test_msg.itrf.stub[68] = 6;

    test_msg.itrf.stub[69] = 0;

    test_msg.itrf.stub[70] = 7;

    test_msg.itrf.stub[71] = 0;

    test_msg.itrf.stub[72] = 0;

    test_msg.itrf.stub[73] = 0;

    test_msg.itrf.stub[74] = 8;

    test_msg.itrf.stub[75] = 0;

    test_msg.itrf.stub[76] = 0;

    test_msg.itrf.stub[77] = 0;

    test_msg.itrf.stub[78] = 9;

    test_msg.itrf.stub[79] = 0;

    test_msg.itrf.stub[80] = 0;

    test_msg.itrf.stub[81] = 0;

    test_msg.itrf.stub[82] = 10;

    test_msg.itrf.stub[83] = 0;

    test_msg.itrf.stub[84] = 0;

    test_msg.itrf.stub[85] = 0;

    test_msg.itrf.stub[86] = 11;

    test_msg.itrf.stub[87] = 0;

    test_msg.itrf.stub[88] = 0;

    test_msg.itrf.stub[89] = 0;

    test_msg.itrf.stub[90] = 12;

    test_msg.itrf.stub[91] = 0;

    test_msg.itrf.stub[92] = 0;

    test_msg.itrf.stub[93] = 0;

    test_msg.itrf.stub[94] = 13;

    test_msg.itrf.stub[95] = 0;

    test_msg.itrf.stub[96] = 0;

    test_msg.itrf.stub[97] = 0;

    test_msg.itrf.stub[98] = 14;

    test_msg.itrf.stub[99] = 0;

    test_msg.itrf.stub[100] = 0;

    test_msg.itrf.stub[101] = 0;

    test_msg.itrf.stub[102] = 15;

    test_msg.itrf.stub[103] = 0;

    test_msg.itrf.stub[104] = 0;

    test_msg.itrf.stub[105] = 0;

    test_msg.itrf.stub[106] = 16;

    test_msg.itrf.stub[107] = 0;

    test_msg.itrf.stub[108] = 0;

    test_msg.itrf.stub[109] = 0;

    test_msg.itrf.stub[110] = 17;

    test_msg.itrf.stub[111] = 0;

    test_msg.itrf.stub[112] = 0;

    test_msg.itrf.stub[113] = 0;

    test_msg.itrf.stub[114] = 18;

    test_msg.itrf.stub[115] = 0;

    test_msg.itrf.stub[116] = 0;

    test_msg.itrf.stub[117] = 0;

    test_msg.itrf.stub[118] = 19;

    test_msg.itrf.stub[119] = 0;

    test_msg.itrf.stub[120] = 0;

    test_msg.itrf.stub[121] = 0;

    test_msg.itrf.stub[122] = 20;

    test_msg.itrf.stub[123] = 0;

    sbp_message_send(&sbp_state, SbpMsgItrf, 66, &test_msg, &dummy_write);

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

    ck_assert_msg(sbp_message_cmp(SbpMsgItrf, &last_msg.msg, &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.itrf.n_stub == 124,
        "incorrect value for last_msg.msg.itrf.n_stub, expected 124, is %d",
        last_msg.msg.itrf.n_stub);

    ck_assert_msg(
        last_msg.msg.itrf.stub[0] == 1,
        "incorrect value for last_msg.msg.itrf.stub[0], expected 1, is %d",
        last_msg.msg.itrf.stub[0]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[1] == 2,
        "incorrect value for last_msg.msg.itrf.stub[1], expected 2, is %d",
        last_msg.msg.itrf.stub[1]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[2] == 102,
        "incorrect value for last_msg.msg.itrf.stub[2], expected 102, is %d",
        last_msg.msg.itrf.stub[2]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[3] == 111,
        "incorrect value for last_msg.msg.itrf.stub[3], expected 111, is %d",
        last_msg.msg.itrf.stub[3]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[4] == 111,
        "incorrect value for last_msg.msg.itrf.stub[4], expected 111, is %d",
        last_msg.msg.itrf.stub[4]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[5] == 0,
        "incorrect value for last_msg.msg.itrf.stub[5], expected 0, is %d",
        last_msg.msg.itrf.stub[5]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[6] == 0,
        "incorrect value for last_msg.msg.itrf.stub[6], expected 0, is %d",
        last_msg.msg.itrf.stub[6]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[7] == 0,
        "incorrect value for last_msg.msg.itrf.stub[7], expected 0, is %d",
        last_msg.msg.itrf.stub[7]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[8] == 0,
        "incorrect value for last_msg.msg.itrf.stub[8], expected 0, is %d",
        last_msg.msg.itrf.stub[8]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[9] == 0,
        "incorrect value for last_msg.msg.itrf.stub[9], expected 0, is %d",
        last_msg.msg.itrf.stub[9]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[10] == 0,
        "incorrect value for last_msg.msg.itrf.stub[10], expected 0, is %d",
        last_msg.msg.itrf.stub[10]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[11] == 0,
        "incorrect value for last_msg.msg.itrf.stub[11], expected 0, is %d",
        last_msg.msg.itrf.stub[11]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[12] == 0,
        "incorrect value for last_msg.msg.itrf.stub[12], expected 0, is %d",
        last_msg.msg.itrf.stub[12]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[13] == 0,
        "incorrect value for last_msg.msg.itrf.stub[13], expected 0, is %d",
        last_msg.msg.itrf.stub[13]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[14] == 0,
        "incorrect value for last_msg.msg.itrf.stub[14], expected 0, is %d",
        last_msg.msg.itrf.stub[14]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[15] == 0,
        "incorrect value for last_msg.msg.itrf.stub[15], expected 0, is %d",
        last_msg.msg.itrf.stub[15]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[16] == 0,
        "incorrect value for last_msg.msg.itrf.stub[16], expected 0, is %d",
        last_msg.msg.itrf.stub[16]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[17] == 0,
        "incorrect value for last_msg.msg.itrf.stub[17], expected 0, is %d",
        last_msg.msg.itrf.stub[17]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[18] == 0,
        "incorrect value for last_msg.msg.itrf.stub[18], expected 0, is %d",
        last_msg.msg.itrf.stub[18]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[19] == 0,
        "incorrect value for last_msg.msg.itrf.stub[19], expected 0, is %d",
        last_msg.msg.itrf.stub[19]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[20] == 0,
        "incorrect value for last_msg.msg.itrf.stub[20], expected 0, is %d",
        last_msg.msg.itrf.stub[20]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[21] == 0,
        "incorrect value for last_msg.msg.itrf.stub[21], expected 0, is %d",
        last_msg.msg.itrf.stub[21]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[22] == 0,
        "incorrect value for last_msg.msg.itrf.stub[22], expected 0, is %d",
        last_msg.msg.itrf.stub[22]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[23] == 0,
        "incorrect value for last_msg.msg.itrf.stub[23], expected 0, is %d",
        last_msg.msg.itrf.stub[23]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[24] == 0,
        "incorrect value for last_msg.msg.itrf.stub[24], expected 0, is %d",
        last_msg.msg.itrf.stub[24]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[25] == 0,
        "incorrect value for last_msg.msg.itrf.stub[25], expected 0, is %d",
        last_msg.msg.itrf.stub[25]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[26] == 0,
        "incorrect value for last_msg.msg.itrf.stub[26], expected 0, is %d",
        last_msg.msg.itrf.stub[26]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[27] == 0,
        "incorrect value for last_msg.msg.itrf.stub[27], expected 0, is %d",
        last_msg.msg.itrf.stub[27]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[28] == 0,
        "incorrect value for last_msg.msg.itrf.stub[28], expected 0, is %d",
        last_msg.msg.itrf.stub[28]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[29] == 0,
        "incorrect value for last_msg.msg.itrf.stub[29], expected 0, is %d",
        last_msg.msg.itrf.stub[29]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[30] == 0,
        "incorrect value for last_msg.msg.itrf.stub[30], expected 0, is %d",
        last_msg.msg.itrf.stub[30]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[31] == 0,
        "incorrect value for last_msg.msg.itrf.stub[31], expected 0, is %d",
        last_msg.msg.itrf.stub[31]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[32] == 0,
        "incorrect value for last_msg.msg.itrf.stub[32], expected 0, is %d",
        last_msg.msg.itrf.stub[32]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[33] == 3,
        "incorrect value for last_msg.msg.itrf.stub[33], expected 3, is %d",
        last_msg.msg.itrf.stub[33]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[34] == 98,
        "incorrect value for last_msg.msg.itrf.stub[34], expected 98, is %d",
        last_msg.msg.itrf.stub[34]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[35] == 97,
        "incorrect value for last_msg.msg.itrf.stub[35], expected 97, is %d",
        last_msg.msg.itrf.stub[35]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[36] == 114,
        "incorrect value for last_msg.msg.itrf.stub[36], expected 114, is %d",
        last_msg.msg.itrf.stub[36]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[37] == 0,
        "incorrect value for last_msg.msg.itrf.stub[37], expected 0, is %d",
        last_msg.msg.itrf.stub[37]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[38] == 0,
        "incorrect value for last_msg.msg.itrf.stub[38], expected 0, is %d",
        last_msg.msg.itrf.stub[38]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[39] == 0,
        "incorrect value for last_msg.msg.itrf.stub[39], expected 0, is %d",
        last_msg.msg.itrf.stub[39]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[40] == 0,
        "incorrect value for last_msg.msg.itrf.stub[40], expected 0, is %d",
        last_msg.msg.itrf.stub[40]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[41] == 0,
        "incorrect value for last_msg.msg.itrf.stub[41], expected 0, is %d",
        last_msg.msg.itrf.stub[41]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[42] == 0,
        "incorrect value for last_msg.msg.itrf.stub[42], expected 0, is %d",
        last_msg.msg.itrf.stub[42]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[43] == 0,
        "incorrect value for last_msg.msg.itrf.stub[43], expected 0, is %d",
        last_msg.msg.itrf.stub[43]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[44] == 0,
        "incorrect value for last_msg.msg.itrf.stub[44], expected 0, is %d",
        last_msg.msg.itrf.stub[44]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[45] == 0,
        "incorrect value for last_msg.msg.itrf.stub[45], expected 0, is %d",
        last_msg.msg.itrf.stub[45]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[46] == 0,
        "incorrect value for last_msg.msg.itrf.stub[46], expected 0, is %d",
        last_msg.msg.itrf.stub[46]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[47] == 0,
        "incorrect value for last_msg.msg.itrf.stub[47], expected 0, is %d",
        last_msg.msg.itrf.stub[47]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[48] == 0,
        "incorrect value for last_msg.msg.itrf.stub[48], expected 0, is %d",
        last_msg.msg.itrf.stub[48]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[49] == 0,
        "incorrect value for last_msg.msg.itrf.stub[49], expected 0, is %d",
        last_msg.msg.itrf.stub[49]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[50] == 0,
        "incorrect value for last_msg.msg.itrf.stub[50], expected 0, is %d",
        last_msg.msg.itrf.stub[50]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[51] == 0,
        "incorrect value for last_msg.msg.itrf.stub[51], expected 0, is %d",
        last_msg.msg.itrf.stub[51]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[52] == 0,
        "incorrect value for last_msg.msg.itrf.stub[52], expected 0, is %d",
        last_msg.msg.itrf.stub[52]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[53] == 0,
        "incorrect value for last_msg.msg.itrf.stub[53], expected 0, is %d",
        last_msg.msg.itrf.stub[53]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[54] == 0,
        "incorrect value for last_msg.msg.itrf.stub[54], expected 0, is %d",
        last_msg.msg.itrf.stub[54]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[55] == 0,
        "incorrect value for last_msg.msg.itrf.stub[55], expected 0, is %d",
        last_msg.msg.itrf.stub[55]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[56] == 0,
        "incorrect value for last_msg.msg.itrf.stub[56], expected 0, is %d",
        last_msg.msg.itrf.stub[56]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[57] == 0,
        "incorrect value for last_msg.msg.itrf.stub[57], expected 0, is %d",
        last_msg.msg.itrf.stub[57]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[58] == 0,
        "incorrect value for last_msg.msg.itrf.stub[58], expected 0, is %d",
        last_msg.msg.itrf.stub[58]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[59] == 0,
        "incorrect value for last_msg.msg.itrf.stub[59], expected 0, is %d",
        last_msg.msg.itrf.stub[59]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[60] == 0,
        "incorrect value for last_msg.msg.itrf.stub[60], expected 0, is %d",
        last_msg.msg.itrf.stub[60]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[61] == 0,
        "incorrect value for last_msg.msg.itrf.stub[61], expected 0, is %d",
        last_msg.msg.itrf.stub[61]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[62] == 0,
        "incorrect value for last_msg.msg.itrf.stub[62], expected 0, is %d",
        last_msg.msg.itrf.stub[62]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[63] == 0,
        "incorrect value for last_msg.msg.itrf.stub[63], expected 0, is %d",
        last_msg.msg.itrf.stub[63]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[64] == 0,
        "incorrect value for last_msg.msg.itrf.stub[64], expected 0, is %d",
        last_msg.msg.itrf.stub[64]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[65] == 4,
        "incorrect value for last_msg.msg.itrf.stub[65], expected 4, is %d",
        last_msg.msg.itrf.stub[65]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[66] == 5,
        "incorrect value for last_msg.msg.itrf.stub[66], expected 5, is %d",
        last_msg.msg.itrf.stub[66]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[67] == 0,
        "incorrect value for last_msg.msg.itrf.stub[67], expected 0, is %d",
        last_msg.msg.itrf.stub[67]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[68] == 6,
        "incorrect value for last_msg.msg.itrf.stub[68], expected 6, is %d",
        last_msg.msg.itrf.stub[68]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[69] == 0,
        "incorrect value for last_msg.msg.itrf.stub[69], expected 0, is %d",
        last_msg.msg.itrf.stub[69]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[70] == 7,
        "incorrect value for last_msg.msg.itrf.stub[70], expected 7, is %d",
        last_msg.msg.itrf.stub[70]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[71] == 0,
        "incorrect value for last_msg.msg.itrf.stub[71], expected 0, is %d",
        last_msg.msg.itrf.stub[71]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[72] == 0,
        "incorrect value for last_msg.msg.itrf.stub[72], expected 0, is %d",
        last_msg.msg.itrf.stub[72]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[73] == 0,
        "incorrect value for last_msg.msg.itrf.stub[73], expected 0, is %d",
        last_msg.msg.itrf.stub[73]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[74] == 8,
        "incorrect value for last_msg.msg.itrf.stub[74], expected 8, is %d",
        last_msg.msg.itrf.stub[74]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[75] == 0,
        "incorrect value for last_msg.msg.itrf.stub[75], expected 0, is %d",
        last_msg.msg.itrf.stub[75]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[76] == 0,
        "incorrect value for last_msg.msg.itrf.stub[76], expected 0, is %d",
        last_msg.msg.itrf.stub[76]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[77] == 0,
        "incorrect value for last_msg.msg.itrf.stub[77], expected 0, is %d",
        last_msg.msg.itrf.stub[77]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[78] == 9,
        "incorrect value for last_msg.msg.itrf.stub[78], expected 9, is %d",
        last_msg.msg.itrf.stub[78]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[79] == 0,
        "incorrect value for last_msg.msg.itrf.stub[79], expected 0, is %d",
        last_msg.msg.itrf.stub[79]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[80] == 0,
        "incorrect value for last_msg.msg.itrf.stub[80], expected 0, is %d",
        last_msg.msg.itrf.stub[80]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[81] == 0,
        "incorrect value for last_msg.msg.itrf.stub[81], expected 0, is %d",
        last_msg.msg.itrf.stub[81]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[82] == 10,
        "incorrect value for last_msg.msg.itrf.stub[82], expected 10, is %d",
        last_msg.msg.itrf.stub[82]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[83] == 0,
        "incorrect value for last_msg.msg.itrf.stub[83], expected 0, is %d",
        last_msg.msg.itrf.stub[83]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[84] == 0,
        "incorrect value for last_msg.msg.itrf.stub[84], expected 0, is %d",
        last_msg.msg.itrf.stub[84]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[85] == 0,
        "incorrect value for last_msg.msg.itrf.stub[85], expected 0, is %d",
        last_msg.msg.itrf.stub[85]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[86] == 11,
        "incorrect value for last_msg.msg.itrf.stub[86], expected 11, is %d",
        last_msg.msg.itrf.stub[86]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[87] == 0,
        "incorrect value for last_msg.msg.itrf.stub[87], expected 0, is %d",
        last_msg.msg.itrf.stub[87]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[88] == 0,
        "incorrect value for last_msg.msg.itrf.stub[88], expected 0, is %d",
        last_msg.msg.itrf.stub[88]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[89] == 0,
        "incorrect value for last_msg.msg.itrf.stub[89], expected 0, is %d",
        last_msg.msg.itrf.stub[89]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[90] == 12,
        "incorrect value for last_msg.msg.itrf.stub[90], expected 12, is %d",
        last_msg.msg.itrf.stub[90]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[91] == 0,
        "incorrect value for last_msg.msg.itrf.stub[91], expected 0, is %d",
        last_msg.msg.itrf.stub[91]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[92] == 0,
        "incorrect value for last_msg.msg.itrf.stub[92], expected 0, is %d",
        last_msg.msg.itrf.stub[92]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[93] == 0,
        "incorrect value for last_msg.msg.itrf.stub[93], expected 0, is %d",
        last_msg.msg.itrf.stub[93]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[94] == 13,
        "incorrect value for last_msg.msg.itrf.stub[94], expected 13, is %d",
        last_msg.msg.itrf.stub[94]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[95] == 0,
        "incorrect value for last_msg.msg.itrf.stub[95], expected 0, is %d",
        last_msg.msg.itrf.stub[95]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[96] == 0,
        "incorrect value for last_msg.msg.itrf.stub[96], expected 0, is %d",
        last_msg.msg.itrf.stub[96]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[97] == 0,
        "incorrect value for last_msg.msg.itrf.stub[97], expected 0, is %d",
        last_msg.msg.itrf.stub[97]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[98] == 14,
        "incorrect value for last_msg.msg.itrf.stub[98], expected 14, is %d",
        last_msg.msg.itrf.stub[98]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[99] == 0,
        "incorrect value for last_msg.msg.itrf.stub[99], expected 0, is %d",
        last_msg.msg.itrf.stub[99]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[100] == 0,
        "incorrect value for last_msg.msg.itrf.stub[100], expected 0, is %d",
        last_msg.msg.itrf.stub[100]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[101] == 0,
        "incorrect value for last_msg.msg.itrf.stub[101], expected 0, is %d",
        last_msg.msg.itrf.stub[101]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[102] == 15,
        "incorrect value for last_msg.msg.itrf.stub[102], expected 15, is %d",
        last_msg.msg.itrf.stub[102]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[103] == 0,
        "incorrect value for last_msg.msg.itrf.stub[103], expected 0, is %d",
        last_msg.msg.itrf.stub[103]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[104] == 0,
        "incorrect value for last_msg.msg.itrf.stub[104], expected 0, is %d",
        last_msg.msg.itrf.stub[104]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[105] == 0,
        "incorrect value for last_msg.msg.itrf.stub[105], expected 0, is %d",
        last_msg.msg.itrf.stub[105]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[106] == 16,
        "incorrect value for last_msg.msg.itrf.stub[106], expected 16, is %d",
        last_msg.msg.itrf.stub[106]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[107] == 0,
        "incorrect value for last_msg.msg.itrf.stub[107], expected 0, is %d",
        last_msg.msg.itrf.stub[107]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[108] == 0,
        "incorrect value for last_msg.msg.itrf.stub[108], expected 0, is %d",
        last_msg.msg.itrf.stub[108]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[109] == 0,
        "incorrect value for last_msg.msg.itrf.stub[109], expected 0, is %d",
        last_msg.msg.itrf.stub[109]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[110] == 17,
        "incorrect value for last_msg.msg.itrf.stub[110], expected 17, is %d",
        last_msg.msg.itrf.stub[110]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[111] == 0,
        "incorrect value for last_msg.msg.itrf.stub[111], expected 0, is %d",
        last_msg.msg.itrf.stub[111]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[112] == 0,
        "incorrect value for last_msg.msg.itrf.stub[112], expected 0, is %d",
        last_msg.msg.itrf.stub[112]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[113] == 0,
        "incorrect value for last_msg.msg.itrf.stub[113], expected 0, is %d",
        last_msg.msg.itrf.stub[113]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[114] == 18,
        "incorrect value for last_msg.msg.itrf.stub[114], expected 18, is %d",
        last_msg.msg.itrf.stub[114]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[115] == 0,
        "incorrect value for last_msg.msg.itrf.stub[115], expected 0, is %d",
        last_msg.msg.itrf.stub[115]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[116] == 0,
        "incorrect value for last_msg.msg.itrf.stub[116], expected 0, is %d",
        last_msg.msg.itrf.stub[116]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[117] == 0,
        "incorrect value for last_msg.msg.itrf.stub[117], expected 0, is %d",
        last_msg.msg.itrf.stub[117]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[118] == 19,
        "incorrect value for last_msg.msg.itrf.stub[118], expected 19, is %d",
        last_msg.msg.itrf.stub[118]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[119] == 0,
        "incorrect value for last_msg.msg.itrf.stub[119], expected 0, is %d",
        last_msg.msg.itrf.stub[119]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[120] == 0,
        "incorrect value for last_msg.msg.itrf.stub[120], expected 0, is %d",
        last_msg.msg.itrf.stub[120]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[121] == 0,
        "incorrect value for last_msg.msg.itrf.stub[121], expected 0, is %d",
        last_msg.msg.itrf.stub[121]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[122] == 20,
        "incorrect value for last_msg.msg.itrf.stub[122], expected 20, is %d",
        last_msg.msg.itrf.stub[122]);
    ck_assert_msg(
        last_msg.msg.itrf.stub[123] == 0,
        "incorrect value for last_msg.msg.itrf.stub[123], expected 0, is %d",
        last_msg.msg.itrf.stub[123]);
  }
}
END_TEST

Suite *auto_check_sbp_navigation_MsgItrf_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_navigation_MsgItrf");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_navigation_MsgItrf");
  tcase_add_test(tc_acq, test_auto_check_sbp_navigation_MsgItrf);
  suite_add_tcase(s, tc_acq);
  return s;
}