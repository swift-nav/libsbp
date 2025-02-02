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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgSpecanDep.yaml by generate.py. Do
// not modify by hand!

#include <check.h>
#include <libsbp/piksi.h>
#include <libsbp/sbp.h>
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

START_TEST(test_auto_check_sbp_piksi_MsgSpecanDep) {
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

    sbp_callback_register(&sbp_state, 0x50, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  80,  0,   112, 217, 255, 246, 22,  221, 56,  37,  59,  45,  27,
        154, 97,  198, 69,  154, 1,   144, 69,  205, 20,  18,  70,  51,  211,
        89,  69,  240, 14,  179, 186, 227, 244, 173, 240, 182, 71,  166, 117,
        196, 13,  44,  27,  33,  28,  67,  254, 3,   249, 92,  44,  122, 169,
        77,  186, 68,  135, 63,  168, 162, 89,  36,  186, 99,  63,  105, 116,
        216, 44,  67,  212, 156, 75,  81,  53,  250, 225, 23,  205, 26,  34,
        119, 50,  101, 64,  7,   231, 124, 183, 203, 102, 234, 84,  83,  208,
        23,  68,  54,  179, 98,  96,  116, 244, 246, 94,  104, 94,  13,  56,
        210, 18,  191, 22,  133, 81,  153, 159, 161, 219, 59,  21,  164, 121,
        145, 203, 171, 132, 57,  180, 102, 101, 11,  229, 175, 145, 73,  72,
        124, 4,   184, 228, 61,  234, 218, 62,  226, 217, 193, 7,   109, 44,
        83,  201, 20,  101, 9,   140, 186, 162, 81,  91,  30,  231, 161, 81,
        216, 114, 60,  231, 163, 163, 49,  237, 244, 185, 240, 89,  143, 174,
        165, 211, 241, 13,  16,  61,  141, 101, 89,  37,  117, 189, 86,  118,
        176, 228, 12,  14,  119, 135, 129, 243, 50,  29,  207, 198, 117, 100,
        225, 6,   139, 110, 39,  210, 68,  199, 43,  132, 64,  17,  51,  173,
        181, 12,  140, 16,  247, 84,  183, 105, 39,  157, 77,  30,  205, 194,
        59,  64,  241, 183, 238, 105, 181, 170, 45,  8,   166, 164, 238, 83,
        148, 173, 108, 228, 67,  89,  189, 67,  26,  39,  216,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.specan_dep.amplitude_ref = 9349.2001953125;

    test_msg.specan_dep.amplitude_unit = 3485.199951171875;

    test_msg.specan_dep.amplitude_value[0] = 240;

    test_msg.specan_dep.amplitude_value[1] = 14;

    test_msg.specan_dep.amplitude_value[2] = 179;

    test_msg.specan_dep.amplitude_value[3] = 186;

    test_msg.specan_dep.amplitude_value[4] = 227;

    test_msg.specan_dep.amplitude_value[5] = 244;

    test_msg.specan_dep.amplitude_value[6] = 173;

    test_msg.specan_dep.amplitude_value[7] = 240;

    test_msg.specan_dep.amplitude_value[8] = 182;

    test_msg.specan_dep.amplitude_value[9] = 71;

    test_msg.specan_dep.amplitude_value[10] = 166;

    test_msg.specan_dep.amplitude_value[11] = 117;

    test_msg.specan_dep.amplitude_value[12] = 196;

    test_msg.specan_dep.amplitude_value[13] = 13;

    test_msg.specan_dep.amplitude_value[14] = 44;

    test_msg.specan_dep.amplitude_value[15] = 27;

    test_msg.specan_dep.amplitude_value[16] = 33;

    test_msg.specan_dep.amplitude_value[17] = 28;

    test_msg.specan_dep.amplitude_value[18] = 67;

    test_msg.specan_dep.amplitude_value[19] = 254;

    test_msg.specan_dep.amplitude_value[20] = 3;

    test_msg.specan_dep.amplitude_value[21] = 249;

    test_msg.specan_dep.amplitude_value[22] = 92;

    test_msg.specan_dep.amplitude_value[23] = 44;

    test_msg.specan_dep.amplitude_value[24] = 122;

    test_msg.specan_dep.amplitude_value[25] = 169;

    test_msg.specan_dep.amplitude_value[26] = 77;

    test_msg.specan_dep.amplitude_value[27] = 186;

    test_msg.specan_dep.amplitude_value[28] = 68;

    test_msg.specan_dep.amplitude_value[29] = 135;

    test_msg.specan_dep.amplitude_value[30] = 63;

    test_msg.specan_dep.amplitude_value[31] = 168;

    test_msg.specan_dep.amplitude_value[32] = 162;

    test_msg.specan_dep.amplitude_value[33] = 89;

    test_msg.specan_dep.amplitude_value[34] = 36;

    test_msg.specan_dep.amplitude_value[35] = 186;

    test_msg.specan_dep.amplitude_value[36] = 99;

    test_msg.specan_dep.amplitude_value[37] = 63;

    test_msg.specan_dep.amplitude_value[38] = 105;

    test_msg.specan_dep.amplitude_value[39] = 116;

    test_msg.specan_dep.amplitude_value[40] = 216;

    test_msg.specan_dep.amplitude_value[41] = 44;

    test_msg.specan_dep.amplitude_value[42] = 67;

    test_msg.specan_dep.amplitude_value[43] = 212;

    test_msg.specan_dep.amplitude_value[44] = 156;

    test_msg.specan_dep.amplitude_value[45] = 75;

    test_msg.specan_dep.amplitude_value[46] = 81;

    test_msg.specan_dep.amplitude_value[47] = 53;

    test_msg.specan_dep.amplitude_value[48] = 250;

    test_msg.specan_dep.amplitude_value[49] = 225;

    test_msg.specan_dep.amplitude_value[50] = 23;

    test_msg.specan_dep.amplitude_value[51] = 205;

    test_msg.specan_dep.amplitude_value[52] = 26;

    test_msg.specan_dep.amplitude_value[53] = 34;

    test_msg.specan_dep.amplitude_value[54] = 119;

    test_msg.specan_dep.amplitude_value[55] = 50;

    test_msg.specan_dep.amplitude_value[56] = 101;

    test_msg.specan_dep.amplitude_value[57] = 64;

    test_msg.specan_dep.amplitude_value[58] = 7;

    test_msg.specan_dep.amplitude_value[59] = 231;

    test_msg.specan_dep.amplitude_value[60] = 124;

    test_msg.specan_dep.amplitude_value[61] = 183;

    test_msg.specan_dep.amplitude_value[62] = 203;

    test_msg.specan_dep.amplitude_value[63] = 102;

    test_msg.specan_dep.amplitude_value[64] = 234;

    test_msg.specan_dep.amplitude_value[65] = 84;

    test_msg.specan_dep.amplitude_value[66] = 83;

    test_msg.specan_dep.amplitude_value[67] = 208;

    test_msg.specan_dep.amplitude_value[68] = 23;

    test_msg.specan_dep.amplitude_value[69] = 68;

    test_msg.specan_dep.amplitude_value[70] = 54;

    test_msg.specan_dep.amplitude_value[71] = 179;

    test_msg.specan_dep.amplitude_value[72] = 98;

    test_msg.specan_dep.amplitude_value[73] = 96;

    test_msg.specan_dep.amplitude_value[74] = 116;

    test_msg.specan_dep.amplitude_value[75] = 244;

    test_msg.specan_dep.amplitude_value[76] = 246;

    test_msg.specan_dep.amplitude_value[77] = 94;

    test_msg.specan_dep.amplitude_value[78] = 104;

    test_msg.specan_dep.amplitude_value[79] = 94;

    test_msg.specan_dep.amplitude_value[80] = 13;

    test_msg.specan_dep.amplitude_value[81] = 56;

    test_msg.specan_dep.amplitude_value[82] = 210;

    test_msg.specan_dep.amplitude_value[83] = 18;

    test_msg.specan_dep.amplitude_value[84] = 191;

    test_msg.specan_dep.amplitude_value[85] = 22;

    test_msg.specan_dep.amplitude_value[86] = 133;

    test_msg.specan_dep.amplitude_value[87] = 81;

    test_msg.specan_dep.amplitude_value[88] = 153;

    test_msg.specan_dep.amplitude_value[89] = 159;

    test_msg.specan_dep.amplitude_value[90] = 161;

    test_msg.specan_dep.amplitude_value[91] = 219;

    test_msg.specan_dep.amplitude_value[92] = 59;

    test_msg.specan_dep.amplitude_value[93] = 21;

    test_msg.specan_dep.amplitude_value[94] = 164;

    test_msg.specan_dep.amplitude_value[95] = 121;

    test_msg.specan_dep.amplitude_value[96] = 145;

    test_msg.specan_dep.amplitude_value[97] = 203;

    test_msg.specan_dep.amplitude_value[98] = 171;

    test_msg.specan_dep.amplitude_value[99] = 132;

    test_msg.specan_dep.amplitude_value[100] = 57;

    test_msg.specan_dep.amplitude_value[101] = 180;

    test_msg.specan_dep.amplitude_value[102] = 102;

    test_msg.specan_dep.amplitude_value[103] = 101;

    test_msg.specan_dep.amplitude_value[104] = 11;

    test_msg.specan_dep.amplitude_value[105] = 229;

    test_msg.specan_dep.amplitude_value[106] = 175;

    test_msg.specan_dep.amplitude_value[107] = 145;

    test_msg.specan_dep.amplitude_value[108] = 73;

    test_msg.specan_dep.amplitude_value[109] = 72;

    test_msg.specan_dep.amplitude_value[110] = 124;

    test_msg.specan_dep.amplitude_value[111] = 4;

    test_msg.specan_dep.amplitude_value[112] = 184;

    test_msg.specan_dep.amplitude_value[113] = 228;

    test_msg.specan_dep.amplitude_value[114] = 61;

    test_msg.specan_dep.amplitude_value[115] = 234;

    test_msg.specan_dep.amplitude_value[116] = 218;

    test_msg.specan_dep.amplitude_value[117] = 62;

    test_msg.specan_dep.amplitude_value[118] = 226;

    test_msg.specan_dep.amplitude_value[119] = 217;

    test_msg.specan_dep.amplitude_value[120] = 193;

    test_msg.specan_dep.amplitude_value[121] = 7;

    test_msg.specan_dep.amplitude_value[122] = 109;

    test_msg.specan_dep.amplitude_value[123] = 44;

    test_msg.specan_dep.amplitude_value[124] = 83;

    test_msg.specan_dep.amplitude_value[125] = 201;

    test_msg.specan_dep.amplitude_value[126] = 20;

    test_msg.specan_dep.amplitude_value[127] = 101;

    test_msg.specan_dep.amplitude_value[128] = 9;

    test_msg.specan_dep.amplitude_value[129] = 140;

    test_msg.specan_dep.amplitude_value[130] = 186;

    test_msg.specan_dep.amplitude_value[131] = 162;

    test_msg.specan_dep.amplitude_value[132] = 81;

    test_msg.specan_dep.amplitude_value[133] = 91;

    test_msg.specan_dep.amplitude_value[134] = 30;

    test_msg.specan_dep.amplitude_value[135] = 231;

    test_msg.specan_dep.amplitude_value[136] = 161;

    test_msg.specan_dep.amplitude_value[137] = 81;

    test_msg.specan_dep.amplitude_value[138] = 216;

    test_msg.specan_dep.amplitude_value[139] = 114;

    test_msg.specan_dep.amplitude_value[140] = 60;

    test_msg.specan_dep.amplitude_value[141] = 231;

    test_msg.specan_dep.amplitude_value[142] = 163;

    test_msg.specan_dep.amplitude_value[143] = 163;

    test_msg.specan_dep.amplitude_value[144] = 49;

    test_msg.specan_dep.amplitude_value[145] = 237;

    test_msg.specan_dep.amplitude_value[146] = 244;

    test_msg.specan_dep.amplitude_value[147] = 185;

    test_msg.specan_dep.amplitude_value[148] = 240;

    test_msg.specan_dep.amplitude_value[149] = 89;

    test_msg.specan_dep.amplitude_value[150] = 143;

    test_msg.specan_dep.amplitude_value[151] = 174;

    test_msg.specan_dep.amplitude_value[152] = 165;

    test_msg.specan_dep.amplitude_value[153] = 211;

    test_msg.specan_dep.amplitude_value[154] = 241;

    test_msg.specan_dep.amplitude_value[155] = 13;

    test_msg.specan_dep.amplitude_value[156] = 16;

    test_msg.specan_dep.amplitude_value[157] = 61;

    test_msg.specan_dep.amplitude_value[158] = 141;

    test_msg.specan_dep.amplitude_value[159] = 101;

    test_msg.specan_dep.amplitude_value[160] = 89;

    test_msg.specan_dep.amplitude_value[161] = 37;

    test_msg.specan_dep.amplitude_value[162] = 117;

    test_msg.specan_dep.amplitude_value[163] = 189;

    test_msg.specan_dep.amplitude_value[164] = 86;

    test_msg.specan_dep.amplitude_value[165] = 118;

    test_msg.specan_dep.amplitude_value[166] = 176;

    test_msg.specan_dep.amplitude_value[167] = 228;

    test_msg.specan_dep.amplitude_value[168] = 12;

    test_msg.specan_dep.amplitude_value[169] = 14;

    test_msg.specan_dep.amplitude_value[170] = 119;

    test_msg.specan_dep.amplitude_value[171] = 135;

    test_msg.specan_dep.amplitude_value[172] = 129;

    test_msg.specan_dep.amplitude_value[173] = 243;

    test_msg.specan_dep.amplitude_value[174] = 50;

    test_msg.specan_dep.amplitude_value[175] = 29;

    test_msg.specan_dep.amplitude_value[176] = 207;

    test_msg.specan_dep.amplitude_value[177] = 198;

    test_msg.specan_dep.amplitude_value[178] = 117;

    test_msg.specan_dep.amplitude_value[179] = 100;

    test_msg.specan_dep.amplitude_value[180] = 225;

    test_msg.specan_dep.amplitude_value[181] = 6;

    test_msg.specan_dep.amplitude_value[182] = 139;

    test_msg.specan_dep.amplitude_value[183] = 110;

    test_msg.specan_dep.amplitude_value[184] = 39;

    test_msg.specan_dep.amplitude_value[185] = 210;

    test_msg.specan_dep.amplitude_value[186] = 68;

    test_msg.specan_dep.amplitude_value[187] = 199;

    test_msg.specan_dep.amplitude_value[188] = 43;

    test_msg.specan_dep.amplitude_value[189] = 132;

    test_msg.specan_dep.amplitude_value[190] = 64;

    test_msg.specan_dep.amplitude_value[191] = 17;

    test_msg.specan_dep.amplitude_value[192] = 51;

    test_msg.specan_dep.amplitude_value[193] = 173;

    test_msg.specan_dep.amplitude_value[194] = 181;

    test_msg.specan_dep.amplitude_value[195] = 12;

    test_msg.specan_dep.amplitude_value[196] = 140;

    test_msg.specan_dep.amplitude_value[197] = 16;

    test_msg.specan_dep.amplitude_value[198] = 247;

    test_msg.specan_dep.amplitude_value[199] = 84;

    test_msg.specan_dep.amplitude_value[200] = 183;

    test_msg.specan_dep.amplitude_value[201] = 105;

    test_msg.specan_dep.amplitude_value[202] = 39;

    test_msg.specan_dep.amplitude_value[203] = 157;

    test_msg.specan_dep.amplitude_value[204] = 77;

    test_msg.specan_dep.amplitude_value[205] = 30;

    test_msg.specan_dep.amplitude_value[206] = 205;

    test_msg.specan_dep.amplitude_value[207] = 194;

    test_msg.specan_dep.amplitude_value[208] = 59;

    test_msg.specan_dep.amplitude_value[209] = 64;

    test_msg.specan_dep.amplitude_value[210] = 241;

    test_msg.specan_dep.amplitude_value[211] = 183;

    test_msg.specan_dep.amplitude_value[212] = 238;

    test_msg.specan_dep.amplitude_value[213] = 105;

    test_msg.specan_dep.amplitude_value[214] = 181;

    test_msg.specan_dep.amplitude_value[215] = 170;

    test_msg.specan_dep.amplitude_value[216] = 45;

    test_msg.specan_dep.amplitude_value[217] = 8;

    test_msg.specan_dep.amplitude_value[218] = 166;

    test_msg.specan_dep.amplitude_value[219] = 164;

    test_msg.specan_dep.amplitude_value[220] = 238;

    test_msg.specan_dep.amplitude_value[221] = 83;

    test_msg.specan_dep.amplitude_value[222] = 148;

    test_msg.specan_dep.amplitude_value[223] = 173;

    test_msg.specan_dep.amplitude_value[224] = 108;

    test_msg.specan_dep.amplitude_value[225] = 228;

    test_msg.specan_dep.amplitude_value[226] = 67;

    test_msg.specan_dep.amplitude_value[227] = 89;

    test_msg.specan_dep.amplitude_value[228] = 189;

    test_msg.specan_dep.amplitude_value[229] = 67;

    test_msg.specan_dep.amplitude_value[230] = 26;

    test_msg.specan_dep.channel_tag = 5878;

    test_msg.specan_dep.freq_ref = 6348.2001953125;

    test_msg.specan_dep.freq_step = 4608.2001953125;

    test_msg.specan_dep.n_amplitude_value = 231;

    test_msg.specan_dep.t.tow = 992295133;

    test_msg.specan_dep.t.wn = 6957;

    sbp_message_send(&sbp_state, SbpMsgSpecanDep, 55664, &test_msg,
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
    ck_assert_msg(last_msg.sender_id == 55664,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(
        sbp_message_cmp(SbpMsgSpecanDep, &last_msg.msg, &test_msg) == 0,
        "Sent and received messages did not compare equal");

    ck_assert_msg((last_msg.msg.specan_dep.amplitude_ref * 100 -
                   9349.20019531 * 100) < 0.05,
                  "incorrect value for last_msg.msg.specan_dep.amplitude_ref, "
                  "expected 9349.20019531, is %f",
                  last_msg.msg.specan_dep.amplitude_ref);

    ck_assert_msg((last_msg.msg.specan_dep.amplitude_unit * 100 -
                   3485.19995117 * 100) < 0.05,
                  "incorrect value for last_msg.msg.specan_dep.amplitude_unit, "
                  "expected 3485.19995117, is %f",
                  last_msg.msg.specan_dep.amplitude_unit);

    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[0] == 240,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[0], "
        "expected 240, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[0]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[1] == 14,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[1], "
        "expected 14, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[1]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[2] == 179,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[2], "
        "expected 179, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[2]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[3] == 186,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[3], "
        "expected 186, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[3]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[4] == 227,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[4], "
        "expected 227, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[4]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[5] == 244,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[5], "
        "expected 244, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[5]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[6] == 173,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[6], "
        "expected 173, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[6]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[7] == 240,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[7], "
        "expected 240, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[7]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[8] == 182,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[8], "
        "expected 182, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[8]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[9] == 71,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[9], "
        "expected 71, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[9]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[10] == 166,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[10], "
        "expected 166, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[10]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[11] == 117,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[11], "
        "expected 117, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[11]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[12] == 196,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[12], "
        "expected 196, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[12]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[13] == 13,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[13], "
        "expected 13, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[13]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[14] == 44,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[14], "
        "expected 44, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[14]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[15] == 27,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[15], "
        "expected 27, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[15]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[16] == 33,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[16], "
        "expected 33, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[16]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[17] == 28,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[17], "
        "expected 28, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[17]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[18] == 67,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[18], "
        "expected 67, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[18]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[19] == 254,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[19], "
        "expected 254, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[19]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[20] == 3,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[20], "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[20]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[21] == 249,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[21], "
        "expected 249, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[21]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[22] == 92,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[22], "
        "expected 92, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[22]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[23] == 44,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[23], "
        "expected 44, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[23]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[24] == 122,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[24], "
        "expected 122, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[24]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[25] == 169,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[25], "
        "expected 169, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[25]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[26] == 77,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[26], "
        "expected 77, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[26]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[27] == 186,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[27], "
        "expected 186, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[27]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[28] == 68,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[28], "
        "expected 68, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[28]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[29] == 135,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[29], "
        "expected 135, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[29]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[30] == 63,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[30], "
        "expected 63, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[30]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[31] == 168,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[31], "
        "expected 168, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[31]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[32] == 162,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[32], "
        "expected 162, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[32]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[33] == 89,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[33], "
        "expected 89, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[33]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[34] == 36,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[34], "
        "expected 36, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[34]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[35] == 186,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[35], "
        "expected 186, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[35]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[36] == 99,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[36], "
        "expected 99, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[36]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[37] == 63,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[37], "
        "expected 63, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[37]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[38] == 105,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[38], "
        "expected 105, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[38]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[39] == 116,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[39], "
        "expected 116, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[39]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[40] == 216,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[40], "
        "expected 216, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[40]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[41] == 44,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[41], "
        "expected 44, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[41]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[42] == 67,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[42], "
        "expected 67, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[42]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[43] == 212,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[43], "
        "expected 212, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[43]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[44] == 156,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[44], "
        "expected 156, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[44]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[45] == 75,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[45], "
        "expected 75, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[45]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[46] == 81,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[46], "
        "expected 81, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[46]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[47] == 53,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[47], "
        "expected 53, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[47]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[48] == 250,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[48], "
        "expected 250, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[48]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[49] == 225,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[49], "
        "expected 225, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[49]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[50] == 23,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[50], "
        "expected 23, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[50]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[51] == 205,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[51], "
        "expected 205, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[51]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[52] == 26,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[52], "
        "expected 26, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[52]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[53] == 34,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[53], "
        "expected 34, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[53]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[54] == 119,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[54], "
        "expected 119, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[54]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[55] == 50,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[55], "
        "expected 50, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[55]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[56] == 101,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[56], "
        "expected 101, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[56]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[57] == 64,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[57], "
        "expected 64, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[57]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[58] == 7,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[58], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[58]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[59] == 231,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[59], "
        "expected 231, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[59]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[60] == 124,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[60], "
        "expected 124, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[60]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[61] == 183,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[61], "
        "expected 183, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[61]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[62] == 203,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[62], "
        "expected 203, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[62]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[63] == 102,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[63], "
        "expected 102, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[63]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[64] == 234,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[64], "
        "expected 234, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[64]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[65] == 84,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[65], "
        "expected 84, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[65]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[66] == 83,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[66], "
        "expected 83, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[66]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[67] == 208,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[67], "
        "expected 208, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[67]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[68] == 23,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[68], "
        "expected 23, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[68]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[69] == 68,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[69], "
        "expected 68, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[69]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[70] == 54,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[70], "
        "expected 54, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[70]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[71] == 179,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[71], "
        "expected 179, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[71]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[72] == 98,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[72], "
        "expected 98, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[72]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[73] == 96,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[73], "
        "expected 96, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[73]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[74] == 116,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[74], "
        "expected 116, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[74]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[75] == 244,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[75], "
        "expected 244, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[75]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[76] == 246,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[76], "
        "expected 246, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[76]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[77] == 94,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[77], "
        "expected 94, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[77]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[78] == 104,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[78], "
        "expected 104, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[78]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[79] == 94,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[79], "
        "expected 94, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[79]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[80] == 13,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[80], "
        "expected 13, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[80]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[81] == 56,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[81], "
        "expected 56, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[81]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[82] == 210,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[82], "
        "expected 210, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[82]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[83] == 18,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[83], "
        "expected 18, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[83]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[84] == 191,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[84], "
        "expected 191, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[84]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[85] == 22,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[85], "
        "expected 22, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[85]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[86] == 133,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[86], "
        "expected 133, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[86]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[87] == 81,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[87], "
        "expected 81, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[87]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[88] == 153,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[88], "
        "expected 153, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[88]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[89] == 159,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[89], "
        "expected 159, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[89]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[90] == 161,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[90], "
        "expected 161, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[90]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[91] == 219,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[91], "
        "expected 219, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[91]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[92] == 59,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[92], "
        "expected 59, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[92]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[93] == 21,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[93], "
        "expected 21, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[93]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[94] == 164,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[94], "
        "expected 164, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[94]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[95] == 121,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[95], "
        "expected 121, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[95]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[96] == 145,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[96], "
        "expected 145, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[96]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[97] == 203,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[97], "
        "expected 203, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[97]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[98] == 171,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[98], "
        "expected 171, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[98]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[99] == 132,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[99], "
        "expected 132, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[99]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[100] == 57,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[100], "
        "expected 57, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[100]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[101] == 180,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[101], "
        "expected 180, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[101]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[102] == 102,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[102], "
        "expected 102, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[102]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[103] == 101,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[103], "
        "expected 101, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[103]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[104] == 11,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[104], "
        "expected 11, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[104]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[105] == 229,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[105], "
        "expected 229, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[105]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[106] == 175,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[106], "
        "expected 175, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[106]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[107] == 145,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[107], "
        "expected 145, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[107]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[108] == 73,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[108], "
        "expected 73, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[108]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[109] == 72,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[109], "
        "expected 72, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[109]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[110] == 124,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[110], "
        "expected 124, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[110]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[111] == 4,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[111], "
        "expected 4, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[111]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[112] == 184,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[112], "
        "expected 184, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[112]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[113] == 228,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[113], "
        "expected 228, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[113]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[114] == 61,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[114], "
        "expected 61, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[114]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[115] == 234,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[115], "
        "expected 234, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[115]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[116] == 218,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[116], "
        "expected 218, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[116]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[117] == 62,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[117], "
        "expected 62, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[117]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[118] == 226,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[118], "
        "expected 226, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[118]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[119] == 217,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[119], "
        "expected 217, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[119]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[120] == 193,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[120], "
        "expected 193, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[120]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[121] == 7,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[121], "
        "expected 7, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[121]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[122] == 109,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[122], "
        "expected 109, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[122]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[123] == 44,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[123], "
        "expected 44, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[123]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[124] == 83,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[124], "
        "expected 83, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[124]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[125] == 201,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[125], "
        "expected 201, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[125]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[126] == 20,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[126], "
        "expected 20, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[126]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[127] == 101,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[127], "
        "expected 101, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[127]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[128] == 9,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[128], "
        "expected 9, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[128]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[129] == 140,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[129], "
        "expected 140, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[129]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[130] == 186,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[130], "
        "expected 186, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[130]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[131] == 162,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[131], "
        "expected 162, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[131]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[132] == 81,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[132], "
        "expected 81, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[132]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[133] == 91,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[133], "
        "expected 91, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[133]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[134] == 30,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[134], "
        "expected 30, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[134]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[135] == 231,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[135], "
        "expected 231, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[135]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[136] == 161,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[136], "
        "expected 161, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[136]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[137] == 81,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[137], "
        "expected 81, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[137]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[138] == 216,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[138], "
        "expected 216, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[138]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[139] == 114,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[139], "
        "expected 114, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[139]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[140] == 60,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[140], "
        "expected 60, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[140]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[141] == 231,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[141], "
        "expected 231, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[141]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[142] == 163,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[142], "
        "expected 163, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[142]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[143] == 163,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[143], "
        "expected 163, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[143]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[144] == 49,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[144], "
        "expected 49, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[144]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[145] == 237,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[145], "
        "expected 237, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[145]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[146] == 244,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[146], "
        "expected 244, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[146]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[147] == 185,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[147], "
        "expected 185, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[147]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[148] == 240,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[148], "
        "expected 240, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[148]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[149] == 89,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[149], "
        "expected 89, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[149]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[150] == 143,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[150], "
        "expected 143, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[150]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[151] == 174,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[151], "
        "expected 174, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[151]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[152] == 165,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[152], "
        "expected 165, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[152]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[153] == 211,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[153], "
        "expected 211, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[153]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[154] == 241,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[154], "
        "expected 241, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[154]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[155] == 13,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[155], "
        "expected 13, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[155]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[156] == 16,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[156], "
        "expected 16, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[156]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[157] == 61,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[157], "
        "expected 61, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[157]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[158] == 141,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[158], "
        "expected 141, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[158]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[159] == 101,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[159], "
        "expected 101, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[159]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[160] == 89,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[160], "
        "expected 89, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[160]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[161] == 37,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[161], "
        "expected 37, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[161]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[162] == 117,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[162], "
        "expected 117, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[162]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[163] == 189,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[163], "
        "expected 189, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[163]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[164] == 86,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[164], "
        "expected 86, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[164]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[165] == 118,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[165], "
        "expected 118, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[165]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[166] == 176,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[166], "
        "expected 176, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[166]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[167] == 228,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[167], "
        "expected 228, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[167]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[168] == 12,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[168], "
        "expected 12, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[168]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[169] == 14,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[169], "
        "expected 14, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[169]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[170] == 119,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[170], "
        "expected 119, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[170]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[171] == 135,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[171], "
        "expected 135, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[171]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[172] == 129,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[172], "
        "expected 129, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[172]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[173] == 243,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[173], "
        "expected 243, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[173]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[174] == 50,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[174], "
        "expected 50, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[174]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[175] == 29,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[175], "
        "expected 29, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[175]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[176] == 207,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[176], "
        "expected 207, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[176]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[177] == 198,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[177], "
        "expected 198, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[177]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[178] == 117,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[178], "
        "expected 117, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[178]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[179] == 100,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[179], "
        "expected 100, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[179]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[180] == 225,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[180], "
        "expected 225, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[180]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[181] == 6,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[181], "
        "expected 6, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[181]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[182] == 139,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[182], "
        "expected 139, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[182]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[183] == 110,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[183], "
        "expected 110, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[183]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[184] == 39,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[184], "
        "expected 39, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[184]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[185] == 210,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[185], "
        "expected 210, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[185]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[186] == 68,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[186], "
        "expected 68, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[186]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[187] == 199,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[187], "
        "expected 199, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[187]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[188] == 43,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[188], "
        "expected 43, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[188]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[189] == 132,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[189], "
        "expected 132, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[189]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[190] == 64,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[190], "
        "expected 64, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[190]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[191] == 17,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[191], "
        "expected 17, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[191]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[192] == 51,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[192], "
        "expected 51, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[192]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[193] == 173,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[193], "
        "expected 173, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[193]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[194] == 181,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[194], "
        "expected 181, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[194]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[195] == 12,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[195], "
        "expected 12, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[195]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[196] == 140,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[196], "
        "expected 140, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[196]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[197] == 16,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[197], "
        "expected 16, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[197]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[198] == 247,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[198], "
        "expected 247, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[198]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[199] == 84,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[199], "
        "expected 84, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[199]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[200] == 183,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[200], "
        "expected 183, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[200]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[201] == 105,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[201], "
        "expected 105, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[201]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[202] == 39,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[202], "
        "expected 39, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[202]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[203] == 157,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[203], "
        "expected 157, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[203]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[204] == 77,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[204], "
        "expected 77, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[204]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[205] == 30,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[205], "
        "expected 30, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[205]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[206] == 205,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[206], "
        "expected 205, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[206]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[207] == 194,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[207], "
        "expected 194, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[207]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[208] == 59,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[208], "
        "expected 59, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[208]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[209] == 64,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[209], "
        "expected 64, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[209]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[210] == 241,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[210], "
        "expected 241, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[210]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[211] == 183,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[211], "
        "expected 183, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[211]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[212] == 238,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[212], "
        "expected 238, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[212]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[213] == 105,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[213], "
        "expected 105, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[213]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[214] == 181,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[214], "
        "expected 181, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[214]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[215] == 170,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[215], "
        "expected 170, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[215]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[216] == 45,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[216], "
        "expected 45, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[216]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[217] == 8,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[217], "
        "expected 8, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[217]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[218] == 166,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[218], "
        "expected 166, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[218]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[219] == 164,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[219], "
        "expected 164, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[219]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[220] == 238,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[220], "
        "expected 238, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[220]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[221] == 83,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[221], "
        "expected 83, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[221]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[222] == 148,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[222], "
        "expected 148, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[222]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[223] == 173,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[223], "
        "expected 173, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[223]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[224] == 108,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[224], "
        "expected 108, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[224]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[225] == 228,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[225], "
        "expected 228, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[225]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[226] == 67,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[226], "
        "expected 67, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[226]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[227] == 89,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[227], "
        "expected 89, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[227]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[228] == 189,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[228], "
        "expected 189, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[228]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[229] == 67,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[229], "
        "expected 67, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[229]);
    ck_assert_msg(
        last_msg.msg.specan_dep.amplitude_value[230] == 26,
        "incorrect value for last_msg.msg.specan_dep.amplitude_value[230], "
        "expected 26, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.amplitude_value[230]);

    ck_assert_msg(last_msg.msg.specan_dep.channel_tag == 5878,
                  "incorrect value for last_msg.msg.specan_dep.channel_tag, "
                  "expected 5878, is %" PRId64,
                  (int64_t)last_msg.msg.specan_dep.channel_tag);

    ck_assert_msg(
        (last_msg.msg.specan_dep.freq_ref * 100 - 6348.20019531 * 100) < 0.05,
        "incorrect value for last_msg.msg.specan_dep.freq_ref, expected "
        "6348.20019531, is %f",
        last_msg.msg.specan_dep.freq_ref);

    ck_assert_msg(
        (last_msg.msg.specan_dep.freq_step * 100 - 4608.20019531 * 100) < 0.05,
        "incorrect value for last_msg.msg.specan_dep.freq_step, expected "
        "4608.20019531, is %f",
        last_msg.msg.specan_dep.freq_step);

    ck_assert_msg(
        last_msg.msg.specan_dep.n_amplitude_value == 231,
        "incorrect value for last_msg.msg.specan_dep.n_amplitude_value, "
        "expected 231, is %" PRId64,
        (int64_t)last_msg.msg.specan_dep.n_amplitude_value);

    ck_assert_msg(last_msg.msg.specan_dep.t.tow == 992295133,
                  "incorrect value for last_msg.msg.specan_dep.t.tow, expected "
                  "992295133, is %" PRId64,
                  (int64_t)last_msg.msg.specan_dep.t.tow);

    ck_assert_msg(last_msg.msg.specan_dep.t.wn == 6957,
                  "incorrect value for last_msg.msg.specan_dep.t.wn, expected "
                  "6957, is %" PRId64,
                  (int64_t)last_msg.msg.specan_dep.t.wn);
  }
}
END_TEST

Suite *auto_check_sbp_piksi_MsgSpecanDep_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: auto_check_sbp_piksi_MsgSpecanDep");
  TCase *tc_acq =
      tcase_create("Automated_Suite_auto_check_sbp_piksi_MsgSpecanDep");
  tcase_add_test(tc_acq, test_auto_check_sbp_piksi_MsgSpecanDep);
  suite_add_tcase(s, tc_acq);
  return s;
}
