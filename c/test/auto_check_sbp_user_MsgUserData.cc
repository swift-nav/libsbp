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
// spec/tests/yaml/swiftnav/sbp/user/test_MsgUserData.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/user.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_user_MsgUserData, test_auto_check_sbp_user_MsgUserData) {
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

    sbp_callback_register(&sbp_state, SbpMsgUserData, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  0,   8,   126, 33,  255, 53,  5,   172, 138, 50,  49,  206, 234,
        149, 204, 113, 31,  108, 188, 179, 154, 156, 167, 145, 139, 42,  207,
        126, 242, 193, 9,   58,  75,  8,   135, 11,  92,  131, 245, 24,  90,
        255, 30,  58,  31,  109, 148, 56,  178, 140, 30,  159, 70,  17,  170,
        50,  148, 1,   99,  112, 88,  217, 36,  84,  34,  234, 82,  144, 144,
        97,  96,  75,  174, 58,  219, 180, 148, 247, 59,  2,   116, 214, 114,
        55,  134, 54,  119, 108, 128, 73,  181, 20,  233, 23,  23,  73,  119,
        136, 231, 189, 26,  174, 128, 93,  30,  76,  45,  109, 134, 81,  0,
        116, 158, 127, 40,  133, 208, 134, 127, 140, 232, 183, 184, 108, 6,
        228, 54,  238, 59,  220, 30,  228, 212, 50,  182, 97,  20,  41,  76,
        227, 88,  12,  95,  112, 209, 183, 127, 4,   165, 189, 44,  239, 232,
        132, 9,   114, 184, 249, 208, 246, 194, 250, 2,   97,  173, 157, 202,
        172, 180, 150, 213, 193, 177, 209, 156, 20,  174, 18,  73,  132, 215,
        115, 128, 175, 169, 116, 132, 100, 72,  45,  25,  14,  205, 213, 145,
        68,  137, 249, 54,  40,  174, 215, 148, 166, 190, 63,  118, 6,   165,
        212, 74,  68,  200, 38,  139, 212, 112, 45,  167, 236, 255, 106, 92,
        132, 59,  61,  233, 3,   246, 158, 83,  134, 246, 154, 17,  0,   6,
        56,  216, 19,  216, 70,  71,  161, 184, 5,   177, 45,  37,  98,  56,
        149, 0,   73,  221, 105, 239, 168, 205, 85,  81,  245,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.user_data.contents[0] = 53;

    test_msg.user_data.contents[1] = 5;

    test_msg.user_data.contents[2] = 172;

    test_msg.user_data.contents[3] = 138;

    test_msg.user_data.contents[4] = 50;

    test_msg.user_data.contents[5] = 49;

    test_msg.user_data.contents[6] = 206;

    test_msg.user_data.contents[7] = 234;

    test_msg.user_data.contents[8] = 149;

    test_msg.user_data.contents[9] = 204;

    test_msg.user_data.contents[10] = 113;

    test_msg.user_data.contents[11] = 31;

    test_msg.user_data.contents[12] = 108;

    test_msg.user_data.contents[13] = 188;

    test_msg.user_data.contents[14] = 179;

    test_msg.user_data.contents[15] = 154;

    test_msg.user_data.contents[16] = 156;

    test_msg.user_data.contents[17] = 167;

    test_msg.user_data.contents[18] = 145;

    test_msg.user_data.contents[19] = 139;

    test_msg.user_data.contents[20] = 42;

    test_msg.user_data.contents[21] = 207;

    test_msg.user_data.contents[22] = 126;

    test_msg.user_data.contents[23] = 242;

    test_msg.user_data.contents[24] = 193;

    test_msg.user_data.contents[25] = 9;

    test_msg.user_data.contents[26] = 58;

    test_msg.user_data.contents[27] = 75;

    test_msg.user_data.contents[28] = 8;

    test_msg.user_data.contents[29] = 135;

    test_msg.user_data.contents[30] = 11;

    test_msg.user_data.contents[31] = 92;

    test_msg.user_data.contents[32] = 131;

    test_msg.user_data.contents[33] = 245;

    test_msg.user_data.contents[34] = 24;

    test_msg.user_data.contents[35] = 90;

    test_msg.user_data.contents[36] = 255;

    test_msg.user_data.contents[37] = 30;

    test_msg.user_data.contents[38] = 58;

    test_msg.user_data.contents[39] = 31;

    test_msg.user_data.contents[40] = 109;

    test_msg.user_data.contents[41] = 148;

    test_msg.user_data.contents[42] = 56;

    test_msg.user_data.contents[43] = 178;

    test_msg.user_data.contents[44] = 140;

    test_msg.user_data.contents[45] = 30;

    test_msg.user_data.contents[46] = 159;

    test_msg.user_data.contents[47] = 70;

    test_msg.user_data.contents[48] = 17;

    test_msg.user_data.contents[49] = 170;

    test_msg.user_data.contents[50] = 50;

    test_msg.user_data.contents[51] = 148;

    test_msg.user_data.contents[52] = 1;

    test_msg.user_data.contents[53] = 99;

    test_msg.user_data.contents[54] = 112;

    test_msg.user_data.contents[55] = 88;

    test_msg.user_data.contents[56] = 217;

    test_msg.user_data.contents[57] = 36;

    test_msg.user_data.contents[58] = 84;

    test_msg.user_data.contents[59] = 34;

    test_msg.user_data.contents[60] = 234;

    test_msg.user_data.contents[61] = 82;

    test_msg.user_data.contents[62] = 144;

    test_msg.user_data.contents[63] = 144;

    test_msg.user_data.contents[64] = 97;

    test_msg.user_data.contents[65] = 96;

    test_msg.user_data.contents[66] = 75;

    test_msg.user_data.contents[67] = 174;

    test_msg.user_data.contents[68] = 58;

    test_msg.user_data.contents[69] = 219;

    test_msg.user_data.contents[70] = 180;

    test_msg.user_data.contents[71] = 148;

    test_msg.user_data.contents[72] = 247;

    test_msg.user_data.contents[73] = 59;

    test_msg.user_data.contents[74] = 2;

    test_msg.user_data.contents[75] = 116;

    test_msg.user_data.contents[76] = 214;

    test_msg.user_data.contents[77] = 114;

    test_msg.user_data.contents[78] = 55;

    test_msg.user_data.contents[79] = 134;

    test_msg.user_data.contents[80] = 54;

    test_msg.user_data.contents[81] = 119;

    test_msg.user_data.contents[82] = 108;

    test_msg.user_data.contents[83] = 128;

    test_msg.user_data.contents[84] = 73;

    test_msg.user_data.contents[85] = 181;

    test_msg.user_data.contents[86] = 20;

    test_msg.user_data.contents[87] = 233;

    test_msg.user_data.contents[88] = 23;

    test_msg.user_data.contents[89] = 23;

    test_msg.user_data.contents[90] = 73;

    test_msg.user_data.contents[91] = 119;

    test_msg.user_data.contents[92] = 136;

    test_msg.user_data.contents[93] = 231;

    test_msg.user_data.contents[94] = 189;

    test_msg.user_data.contents[95] = 26;

    test_msg.user_data.contents[96] = 174;

    test_msg.user_data.contents[97] = 128;

    test_msg.user_data.contents[98] = 93;

    test_msg.user_data.contents[99] = 30;

    test_msg.user_data.contents[100] = 76;

    test_msg.user_data.contents[101] = 45;

    test_msg.user_data.contents[102] = 109;

    test_msg.user_data.contents[103] = 134;

    test_msg.user_data.contents[104] = 81;

    test_msg.user_data.contents[105] = 0;

    test_msg.user_data.contents[106] = 116;

    test_msg.user_data.contents[107] = 158;

    test_msg.user_data.contents[108] = 127;

    test_msg.user_data.contents[109] = 40;

    test_msg.user_data.contents[110] = 133;

    test_msg.user_data.contents[111] = 208;

    test_msg.user_data.contents[112] = 134;

    test_msg.user_data.contents[113] = 127;

    test_msg.user_data.contents[114] = 140;

    test_msg.user_data.contents[115] = 232;

    test_msg.user_data.contents[116] = 183;

    test_msg.user_data.contents[117] = 184;

    test_msg.user_data.contents[118] = 108;

    test_msg.user_data.contents[119] = 6;

    test_msg.user_data.contents[120] = 228;

    test_msg.user_data.contents[121] = 54;

    test_msg.user_data.contents[122] = 238;

    test_msg.user_data.contents[123] = 59;

    test_msg.user_data.contents[124] = 220;

    test_msg.user_data.contents[125] = 30;

    test_msg.user_data.contents[126] = 228;

    test_msg.user_data.contents[127] = 212;

    test_msg.user_data.contents[128] = 50;

    test_msg.user_data.contents[129] = 182;

    test_msg.user_data.contents[130] = 97;

    test_msg.user_data.contents[131] = 20;

    test_msg.user_data.contents[132] = 41;

    test_msg.user_data.contents[133] = 76;

    test_msg.user_data.contents[134] = 227;

    test_msg.user_data.contents[135] = 88;

    test_msg.user_data.contents[136] = 12;

    test_msg.user_data.contents[137] = 95;

    test_msg.user_data.contents[138] = 112;

    test_msg.user_data.contents[139] = 209;

    test_msg.user_data.contents[140] = 183;

    test_msg.user_data.contents[141] = 127;

    test_msg.user_data.contents[142] = 4;

    test_msg.user_data.contents[143] = 165;

    test_msg.user_data.contents[144] = 189;

    test_msg.user_data.contents[145] = 44;

    test_msg.user_data.contents[146] = 239;

    test_msg.user_data.contents[147] = 232;

    test_msg.user_data.contents[148] = 132;

    test_msg.user_data.contents[149] = 9;

    test_msg.user_data.contents[150] = 114;

    test_msg.user_data.contents[151] = 184;

    test_msg.user_data.contents[152] = 249;

    test_msg.user_data.contents[153] = 208;

    test_msg.user_data.contents[154] = 246;

    test_msg.user_data.contents[155] = 194;

    test_msg.user_data.contents[156] = 250;

    test_msg.user_data.contents[157] = 2;

    test_msg.user_data.contents[158] = 97;

    test_msg.user_data.contents[159] = 173;

    test_msg.user_data.contents[160] = 157;

    test_msg.user_data.contents[161] = 202;

    test_msg.user_data.contents[162] = 172;

    test_msg.user_data.contents[163] = 180;

    test_msg.user_data.contents[164] = 150;

    test_msg.user_data.contents[165] = 213;

    test_msg.user_data.contents[166] = 193;

    test_msg.user_data.contents[167] = 177;

    test_msg.user_data.contents[168] = 209;

    test_msg.user_data.contents[169] = 156;

    test_msg.user_data.contents[170] = 20;

    test_msg.user_data.contents[171] = 174;

    test_msg.user_data.contents[172] = 18;

    test_msg.user_data.contents[173] = 73;

    test_msg.user_data.contents[174] = 132;

    test_msg.user_data.contents[175] = 215;

    test_msg.user_data.contents[176] = 115;

    test_msg.user_data.contents[177] = 128;

    test_msg.user_data.contents[178] = 175;

    test_msg.user_data.contents[179] = 169;

    test_msg.user_data.contents[180] = 116;

    test_msg.user_data.contents[181] = 132;

    test_msg.user_data.contents[182] = 100;

    test_msg.user_data.contents[183] = 72;

    test_msg.user_data.contents[184] = 45;

    test_msg.user_data.contents[185] = 25;

    test_msg.user_data.contents[186] = 14;

    test_msg.user_data.contents[187] = 205;

    test_msg.user_data.contents[188] = 213;

    test_msg.user_data.contents[189] = 145;

    test_msg.user_data.contents[190] = 68;

    test_msg.user_data.contents[191] = 137;

    test_msg.user_data.contents[192] = 249;

    test_msg.user_data.contents[193] = 54;

    test_msg.user_data.contents[194] = 40;

    test_msg.user_data.contents[195] = 174;

    test_msg.user_data.contents[196] = 215;

    test_msg.user_data.contents[197] = 148;

    test_msg.user_data.contents[198] = 166;

    test_msg.user_data.contents[199] = 190;

    test_msg.user_data.contents[200] = 63;

    test_msg.user_data.contents[201] = 118;

    test_msg.user_data.contents[202] = 6;

    test_msg.user_data.contents[203] = 165;

    test_msg.user_data.contents[204] = 212;

    test_msg.user_data.contents[205] = 74;

    test_msg.user_data.contents[206] = 68;

    test_msg.user_data.contents[207] = 200;

    test_msg.user_data.contents[208] = 38;

    test_msg.user_data.contents[209] = 139;

    test_msg.user_data.contents[210] = 212;

    test_msg.user_data.contents[211] = 112;

    test_msg.user_data.contents[212] = 45;

    test_msg.user_data.contents[213] = 167;

    test_msg.user_data.contents[214] = 236;

    test_msg.user_data.contents[215] = 255;

    test_msg.user_data.contents[216] = 106;

    test_msg.user_data.contents[217] = 92;

    test_msg.user_data.contents[218] = 132;

    test_msg.user_data.contents[219] = 59;

    test_msg.user_data.contents[220] = 61;

    test_msg.user_data.contents[221] = 233;

    test_msg.user_data.contents[222] = 3;

    test_msg.user_data.contents[223] = 246;

    test_msg.user_data.contents[224] = 158;

    test_msg.user_data.contents[225] = 83;

    test_msg.user_data.contents[226] = 134;

    test_msg.user_data.contents[227] = 246;

    test_msg.user_data.contents[228] = 154;

    test_msg.user_data.contents[229] = 17;

    test_msg.user_data.contents[230] = 0;

    test_msg.user_data.contents[231] = 6;

    test_msg.user_data.contents[232] = 56;

    test_msg.user_data.contents[233] = 216;

    test_msg.user_data.contents[234] = 19;

    test_msg.user_data.contents[235] = 216;

    test_msg.user_data.contents[236] = 70;

    test_msg.user_data.contents[237] = 71;

    test_msg.user_data.contents[238] = 161;

    test_msg.user_data.contents[239] = 184;

    test_msg.user_data.contents[240] = 5;

    test_msg.user_data.contents[241] = 177;

    test_msg.user_data.contents[242] = 45;

    test_msg.user_data.contents[243] = 37;

    test_msg.user_data.contents[244] = 98;

    test_msg.user_data.contents[245] = 56;

    test_msg.user_data.contents[246] = 149;

    test_msg.user_data.contents[247] = 0;

    test_msg.user_data.contents[248] = 73;

    test_msg.user_data.contents[249] = 221;

    test_msg.user_data.contents[250] = 105;

    test_msg.user_data.contents[251] = 239;

    test_msg.user_data.contents[252] = 168;

    test_msg.user_data.contents[253] = 205;

    test_msg.user_data.contents[254] = 85;

    test_msg.user_data.n_contents = 255;

    sbp_message_send(&sbp_state, SbpMsgUserData, 8574, &test_msg, &dummy_write);

    EXPECT_EQ(dummy_wr, sizeof(encoded_frame))
        << "not enough data was written to dummy_buff (expected: "
        << sizeof(encoded_frame) << ", actual: " << dummy_wr << ")";
    EXPECT_EQ(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)), 0)
        << "frame was not encoded properly";

    while (dummy_rd < dummy_wr) {
      EXPECT_GE(sbp_process(&sbp_state, &dummy_read), SBP_OK)
          << "sbp_process threw an error!";
    }

    EXPECT_EQ(last_msg.n_callbacks_logged, 1)
        << "msg_callback: one callback should have been logged";
    EXPECT_EQ(last_msg.sender_id, 8574)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgUserData, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.user_data.contents[0], 53)
        << "incorrect value for last_msg.msg.user_data.contents[0], expected "
           "53, is "
        << (int64_t)last_msg.msg.user_data.contents[0];
    EXPECT_EQ(last_msg.msg.user_data.contents[1], 5)
        << "incorrect value for last_msg.msg.user_data.contents[1], expected "
           "5, is "
        << (int64_t)last_msg.msg.user_data.contents[1];
    EXPECT_EQ(last_msg.msg.user_data.contents[2], 172)
        << "incorrect value for last_msg.msg.user_data.contents[2], expected "
           "172, is "
        << (int64_t)last_msg.msg.user_data.contents[2];
    EXPECT_EQ(last_msg.msg.user_data.contents[3], 138)
        << "incorrect value for last_msg.msg.user_data.contents[3], expected "
           "138, is "
        << (int64_t)last_msg.msg.user_data.contents[3];
    EXPECT_EQ(last_msg.msg.user_data.contents[4], 50)
        << "incorrect value for last_msg.msg.user_data.contents[4], expected "
           "50, is "
        << (int64_t)last_msg.msg.user_data.contents[4];
    EXPECT_EQ(last_msg.msg.user_data.contents[5], 49)
        << "incorrect value for last_msg.msg.user_data.contents[5], expected "
           "49, is "
        << (int64_t)last_msg.msg.user_data.contents[5];
    EXPECT_EQ(last_msg.msg.user_data.contents[6], 206)
        << "incorrect value for last_msg.msg.user_data.contents[6], expected "
           "206, is "
        << (int64_t)last_msg.msg.user_data.contents[6];
    EXPECT_EQ(last_msg.msg.user_data.contents[7], 234)
        << "incorrect value for last_msg.msg.user_data.contents[7], expected "
           "234, is "
        << (int64_t)last_msg.msg.user_data.contents[7];
    EXPECT_EQ(last_msg.msg.user_data.contents[8], 149)
        << "incorrect value for last_msg.msg.user_data.contents[8], expected "
           "149, is "
        << (int64_t)last_msg.msg.user_data.contents[8];
    EXPECT_EQ(last_msg.msg.user_data.contents[9], 204)
        << "incorrect value for last_msg.msg.user_data.contents[9], expected "
           "204, is "
        << (int64_t)last_msg.msg.user_data.contents[9];
    EXPECT_EQ(last_msg.msg.user_data.contents[10], 113)
        << "incorrect value for last_msg.msg.user_data.contents[10], expected "
           "113, is "
        << (int64_t)last_msg.msg.user_data.contents[10];
    EXPECT_EQ(last_msg.msg.user_data.contents[11], 31)
        << "incorrect value for last_msg.msg.user_data.contents[11], expected "
           "31, is "
        << (int64_t)last_msg.msg.user_data.contents[11];
    EXPECT_EQ(last_msg.msg.user_data.contents[12], 108)
        << "incorrect value for last_msg.msg.user_data.contents[12], expected "
           "108, is "
        << (int64_t)last_msg.msg.user_data.contents[12];
    EXPECT_EQ(last_msg.msg.user_data.contents[13], 188)
        << "incorrect value for last_msg.msg.user_data.contents[13], expected "
           "188, is "
        << (int64_t)last_msg.msg.user_data.contents[13];
    EXPECT_EQ(last_msg.msg.user_data.contents[14], 179)
        << "incorrect value for last_msg.msg.user_data.contents[14], expected "
           "179, is "
        << (int64_t)last_msg.msg.user_data.contents[14];
    EXPECT_EQ(last_msg.msg.user_data.contents[15], 154)
        << "incorrect value for last_msg.msg.user_data.contents[15], expected "
           "154, is "
        << (int64_t)last_msg.msg.user_data.contents[15];
    EXPECT_EQ(last_msg.msg.user_data.contents[16], 156)
        << "incorrect value for last_msg.msg.user_data.contents[16], expected "
           "156, is "
        << (int64_t)last_msg.msg.user_data.contents[16];
    EXPECT_EQ(last_msg.msg.user_data.contents[17], 167)
        << "incorrect value for last_msg.msg.user_data.contents[17], expected "
           "167, is "
        << (int64_t)last_msg.msg.user_data.contents[17];
    EXPECT_EQ(last_msg.msg.user_data.contents[18], 145)
        << "incorrect value for last_msg.msg.user_data.contents[18], expected "
           "145, is "
        << (int64_t)last_msg.msg.user_data.contents[18];
    EXPECT_EQ(last_msg.msg.user_data.contents[19], 139)
        << "incorrect value for last_msg.msg.user_data.contents[19], expected "
           "139, is "
        << (int64_t)last_msg.msg.user_data.contents[19];
    EXPECT_EQ(last_msg.msg.user_data.contents[20], 42)
        << "incorrect value for last_msg.msg.user_data.contents[20], expected "
           "42, is "
        << (int64_t)last_msg.msg.user_data.contents[20];
    EXPECT_EQ(last_msg.msg.user_data.contents[21], 207)
        << "incorrect value for last_msg.msg.user_data.contents[21], expected "
           "207, is "
        << (int64_t)last_msg.msg.user_data.contents[21];
    EXPECT_EQ(last_msg.msg.user_data.contents[22], 126)
        << "incorrect value for last_msg.msg.user_data.contents[22], expected "
           "126, is "
        << (int64_t)last_msg.msg.user_data.contents[22];
    EXPECT_EQ(last_msg.msg.user_data.contents[23], 242)
        << "incorrect value for last_msg.msg.user_data.contents[23], expected "
           "242, is "
        << (int64_t)last_msg.msg.user_data.contents[23];
    EXPECT_EQ(last_msg.msg.user_data.contents[24], 193)
        << "incorrect value for last_msg.msg.user_data.contents[24], expected "
           "193, is "
        << (int64_t)last_msg.msg.user_data.contents[24];
    EXPECT_EQ(last_msg.msg.user_data.contents[25], 9)
        << "incorrect value for last_msg.msg.user_data.contents[25], expected "
           "9, is "
        << (int64_t)last_msg.msg.user_data.contents[25];
    EXPECT_EQ(last_msg.msg.user_data.contents[26], 58)
        << "incorrect value for last_msg.msg.user_data.contents[26], expected "
           "58, is "
        << (int64_t)last_msg.msg.user_data.contents[26];
    EXPECT_EQ(last_msg.msg.user_data.contents[27], 75)
        << "incorrect value for last_msg.msg.user_data.contents[27], expected "
           "75, is "
        << (int64_t)last_msg.msg.user_data.contents[27];
    EXPECT_EQ(last_msg.msg.user_data.contents[28], 8)
        << "incorrect value for last_msg.msg.user_data.contents[28], expected "
           "8, is "
        << (int64_t)last_msg.msg.user_data.contents[28];
    EXPECT_EQ(last_msg.msg.user_data.contents[29], 135)
        << "incorrect value for last_msg.msg.user_data.contents[29], expected "
           "135, is "
        << (int64_t)last_msg.msg.user_data.contents[29];
    EXPECT_EQ(last_msg.msg.user_data.contents[30], 11)
        << "incorrect value for last_msg.msg.user_data.contents[30], expected "
           "11, is "
        << (int64_t)last_msg.msg.user_data.contents[30];
    EXPECT_EQ(last_msg.msg.user_data.contents[31], 92)
        << "incorrect value for last_msg.msg.user_data.contents[31], expected "
           "92, is "
        << (int64_t)last_msg.msg.user_data.contents[31];
    EXPECT_EQ(last_msg.msg.user_data.contents[32], 131)
        << "incorrect value for last_msg.msg.user_data.contents[32], expected "
           "131, is "
        << (int64_t)last_msg.msg.user_data.contents[32];
    EXPECT_EQ(last_msg.msg.user_data.contents[33], 245)
        << "incorrect value for last_msg.msg.user_data.contents[33], expected "
           "245, is "
        << (int64_t)last_msg.msg.user_data.contents[33];
    EXPECT_EQ(last_msg.msg.user_data.contents[34], 24)
        << "incorrect value for last_msg.msg.user_data.contents[34], expected "
           "24, is "
        << (int64_t)last_msg.msg.user_data.contents[34];
    EXPECT_EQ(last_msg.msg.user_data.contents[35], 90)
        << "incorrect value for last_msg.msg.user_data.contents[35], expected "
           "90, is "
        << (int64_t)last_msg.msg.user_data.contents[35];
    EXPECT_EQ(last_msg.msg.user_data.contents[36], 255)
        << "incorrect value for last_msg.msg.user_data.contents[36], expected "
           "255, is "
        << (int64_t)last_msg.msg.user_data.contents[36];
    EXPECT_EQ(last_msg.msg.user_data.contents[37], 30)
        << "incorrect value for last_msg.msg.user_data.contents[37], expected "
           "30, is "
        << (int64_t)last_msg.msg.user_data.contents[37];
    EXPECT_EQ(last_msg.msg.user_data.contents[38], 58)
        << "incorrect value for last_msg.msg.user_data.contents[38], expected "
           "58, is "
        << (int64_t)last_msg.msg.user_data.contents[38];
    EXPECT_EQ(last_msg.msg.user_data.contents[39], 31)
        << "incorrect value for last_msg.msg.user_data.contents[39], expected "
           "31, is "
        << (int64_t)last_msg.msg.user_data.contents[39];
    EXPECT_EQ(last_msg.msg.user_data.contents[40], 109)
        << "incorrect value for last_msg.msg.user_data.contents[40], expected "
           "109, is "
        << (int64_t)last_msg.msg.user_data.contents[40];
    EXPECT_EQ(last_msg.msg.user_data.contents[41], 148)
        << "incorrect value for last_msg.msg.user_data.contents[41], expected "
           "148, is "
        << (int64_t)last_msg.msg.user_data.contents[41];
    EXPECT_EQ(last_msg.msg.user_data.contents[42], 56)
        << "incorrect value for last_msg.msg.user_data.contents[42], expected "
           "56, is "
        << (int64_t)last_msg.msg.user_data.contents[42];
    EXPECT_EQ(last_msg.msg.user_data.contents[43], 178)
        << "incorrect value for last_msg.msg.user_data.contents[43], expected "
           "178, is "
        << (int64_t)last_msg.msg.user_data.contents[43];
    EXPECT_EQ(last_msg.msg.user_data.contents[44], 140)
        << "incorrect value for last_msg.msg.user_data.contents[44], expected "
           "140, is "
        << (int64_t)last_msg.msg.user_data.contents[44];
    EXPECT_EQ(last_msg.msg.user_data.contents[45], 30)
        << "incorrect value for last_msg.msg.user_data.contents[45], expected "
           "30, is "
        << (int64_t)last_msg.msg.user_data.contents[45];
    EXPECT_EQ(last_msg.msg.user_data.contents[46], 159)
        << "incorrect value for last_msg.msg.user_data.contents[46], expected "
           "159, is "
        << (int64_t)last_msg.msg.user_data.contents[46];
    EXPECT_EQ(last_msg.msg.user_data.contents[47], 70)
        << "incorrect value for last_msg.msg.user_data.contents[47], expected "
           "70, is "
        << (int64_t)last_msg.msg.user_data.contents[47];
    EXPECT_EQ(last_msg.msg.user_data.contents[48], 17)
        << "incorrect value for last_msg.msg.user_data.contents[48], expected "
           "17, is "
        << (int64_t)last_msg.msg.user_data.contents[48];
    EXPECT_EQ(last_msg.msg.user_data.contents[49], 170)
        << "incorrect value for last_msg.msg.user_data.contents[49], expected "
           "170, is "
        << (int64_t)last_msg.msg.user_data.contents[49];
    EXPECT_EQ(last_msg.msg.user_data.contents[50], 50)
        << "incorrect value for last_msg.msg.user_data.contents[50], expected "
           "50, is "
        << (int64_t)last_msg.msg.user_data.contents[50];
    EXPECT_EQ(last_msg.msg.user_data.contents[51], 148)
        << "incorrect value for last_msg.msg.user_data.contents[51], expected "
           "148, is "
        << (int64_t)last_msg.msg.user_data.contents[51];
    EXPECT_EQ(last_msg.msg.user_data.contents[52], 1)
        << "incorrect value for last_msg.msg.user_data.contents[52], expected "
           "1, is "
        << (int64_t)last_msg.msg.user_data.contents[52];
    EXPECT_EQ(last_msg.msg.user_data.contents[53], 99)
        << "incorrect value for last_msg.msg.user_data.contents[53], expected "
           "99, is "
        << (int64_t)last_msg.msg.user_data.contents[53];
    EXPECT_EQ(last_msg.msg.user_data.contents[54], 112)
        << "incorrect value for last_msg.msg.user_data.contents[54], expected "
           "112, is "
        << (int64_t)last_msg.msg.user_data.contents[54];
    EXPECT_EQ(last_msg.msg.user_data.contents[55], 88)
        << "incorrect value for last_msg.msg.user_data.contents[55], expected "
           "88, is "
        << (int64_t)last_msg.msg.user_data.contents[55];
    EXPECT_EQ(last_msg.msg.user_data.contents[56], 217)
        << "incorrect value for last_msg.msg.user_data.contents[56], expected "
           "217, is "
        << (int64_t)last_msg.msg.user_data.contents[56];
    EXPECT_EQ(last_msg.msg.user_data.contents[57], 36)
        << "incorrect value for last_msg.msg.user_data.contents[57], expected "
           "36, is "
        << (int64_t)last_msg.msg.user_data.contents[57];
    EXPECT_EQ(last_msg.msg.user_data.contents[58], 84)
        << "incorrect value for last_msg.msg.user_data.contents[58], expected "
           "84, is "
        << (int64_t)last_msg.msg.user_data.contents[58];
    EXPECT_EQ(last_msg.msg.user_data.contents[59], 34)
        << "incorrect value for last_msg.msg.user_data.contents[59], expected "
           "34, is "
        << (int64_t)last_msg.msg.user_data.contents[59];
    EXPECT_EQ(last_msg.msg.user_data.contents[60], 234)
        << "incorrect value for last_msg.msg.user_data.contents[60], expected "
           "234, is "
        << (int64_t)last_msg.msg.user_data.contents[60];
    EXPECT_EQ(last_msg.msg.user_data.contents[61], 82)
        << "incorrect value for last_msg.msg.user_data.contents[61], expected "
           "82, is "
        << (int64_t)last_msg.msg.user_data.contents[61];
    EXPECT_EQ(last_msg.msg.user_data.contents[62], 144)
        << "incorrect value for last_msg.msg.user_data.contents[62], expected "
           "144, is "
        << (int64_t)last_msg.msg.user_data.contents[62];
    EXPECT_EQ(last_msg.msg.user_data.contents[63], 144)
        << "incorrect value for last_msg.msg.user_data.contents[63], expected "
           "144, is "
        << (int64_t)last_msg.msg.user_data.contents[63];
    EXPECT_EQ(last_msg.msg.user_data.contents[64], 97)
        << "incorrect value for last_msg.msg.user_data.contents[64], expected "
           "97, is "
        << (int64_t)last_msg.msg.user_data.contents[64];
    EXPECT_EQ(last_msg.msg.user_data.contents[65], 96)
        << "incorrect value for last_msg.msg.user_data.contents[65], expected "
           "96, is "
        << (int64_t)last_msg.msg.user_data.contents[65];
    EXPECT_EQ(last_msg.msg.user_data.contents[66], 75)
        << "incorrect value for last_msg.msg.user_data.contents[66], expected "
           "75, is "
        << (int64_t)last_msg.msg.user_data.contents[66];
    EXPECT_EQ(last_msg.msg.user_data.contents[67], 174)
        << "incorrect value for last_msg.msg.user_data.contents[67], expected "
           "174, is "
        << (int64_t)last_msg.msg.user_data.contents[67];
    EXPECT_EQ(last_msg.msg.user_data.contents[68], 58)
        << "incorrect value for last_msg.msg.user_data.contents[68], expected "
           "58, is "
        << (int64_t)last_msg.msg.user_data.contents[68];
    EXPECT_EQ(last_msg.msg.user_data.contents[69], 219)
        << "incorrect value for last_msg.msg.user_data.contents[69], expected "
           "219, is "
        << (int64_t)last_msg.msg.user_data.contents[69];
    EXPECT_EQ(last_msg.msg.user_data.contents[70], 180)
        << "incorrect value for last_msg.msg.user_data.contents[70], expected "
           "180, is "
        << (int64_t)last_msg.msg.user_data.contents[70];
    EXPECT_EQ(last_msg.msg.user_data.contents[71], 148)
        << "incorrect value for last_msg.msg.user_data.contents[71], expected "
           "148, is "
        << (int64_t)last_msg.msg.user_data.contents[71];
    EXPECT_EQ(last_msg.msg.user_data.contents[72], 247)
        << "incorrect value for last_msg.msg.user_data.contents[72], expected "
           "247, is "
        << (int64_t)last_msg.msg.user_data.contents[72];
    EXPECT_EQ(last_msg.msg.user_data.contents[73], 59)
        << "incorrect value for last_msg.msg.user_data.contents[73], expected "
           "59, is "
        << (int64_t)last_msg.msg.user_data.contents[73];
    EXPECT_EQ(last_msg.msg.user_data.contents[74], 2)
        << "incorrect value for last_msg.msg.user_data.contents[74], expected "
           "2, is "
        << (int64_t)last_msg.msg.user_data.contents[74];
    EXPECT_EQ(last_msg.msg.user_data.contents[75], 116)
        << "incorrect value for last_msg.msg.user_data.contents[75], expected "
           "116, is "
        << (int64_t)last_msg.msg.user_data.contents[75];
    EXPECT_EQ(last_msg.msg.user_data.contents[76], 214)
        << "incorrect value for last_msg.msg.user_data.contents[76], expected "
           "214, is "
        << (int64_t)last_msg.msg.user_data.contents[76];
    EXPECT_EQ(last_msg.msg.user_data.contents[77], 114)
        << "incorrect value for last_msg.msg.user_data.contents[77], expected "
           "114, is "
        << (int64_t)last_msg.msg.user_data.contents[77];
    EXPECT_EQ(last_msg.msg.user_data.contents[78], 55)
        << "incorrect value for last_msg.msg.user_data.contents[78], expected "
           "55, is "
        << (int64_t)last_msg.msg.user_data.contents[78];
    EXPECT_EQ(last_msg.msg.user_data.contents[79], 134)
        << "incorrect value for last_msg.msg.user_data.contents[79], expected "
           "134, is "
        << (int64_t)last_msg.msg.user_data.contents[79];
    EXPECT_EQ(last_msg.msg.user_data.contents[80], 54)
        << "incorrect value for last_msg.msg.user_data.contents[80], expected "
           "54, is "
        << (int64_t)last_msg.msg.user_data.contents[80];
    EXPECT_EQ(last_msg.msg.user_data.contents[81], 119)
        << "incorrect value for last_msg.msg.user_data.contents[81], expected "
           "119, is "
        << (int64_t)last_msg.msg.user_data.contents[81];
    EXPECT_EQ(last_msg.msg.user_data.contents[82], 108)
        << "incorrect value for last_msg.msg.user_data.contents[82], expected "
           "108, is "
        << (int64_t)last_msg.msg.user_data.contents[82];
    EXPECT_EQ(last_msg.msg.user_data.contents[83], 128)
        << "incorrect value for last_msg.msg.user_data.contents[83], expected "
           "128, is "
        << (int64_t)last_msg.msg.user_data.contents[83];
    EXPECT_EQ(last_msg.msg.user_data.contents[84], 73)
        << "incorrect value for last_msg.msg.user_data.contents[84], expected "
           "73, is "
        << (int64_t)last_msg.msg.user_data.contents[84];
    EXPECT_EQ(last_msg.msg.user_data.contents[85], 181)
        << "incorrect value for last_msg.msg.user_data.contents[85], expected "
           "181, is "
        << (int64_t)last_msg.msg.user_data.contents[85];
    EXPECT_EQ(last_msg.msg.user_data.contents[86], 20)
        << "incorrect value for last_msg.msg.user_data.contents[86], expected "
           "20, is "
        << (int64_t)last_msg.msg.user_data.contents[86];
    EXPECT_EQ(last_msg.msg.user_data.contents[87], 233)
        << "incorrect value for last_msg.msg.user_data.contents[87], expected "
           "233, is "
        << (int64_t)last_msg.msg.user_data.contents[87];
    EXPECT_EQ(last_msg.msg.user_data.contents[88], 23)
        << "incorrect value for last_msg.msg.user_data.contents[88], expected "
           "23, is "
        << (int64_t)last_msg.msg.user_data.contents[88];
    EXPECT_EQ(last_msg.msg.user_data.contents[89], 23)
        << "incorrect value for last_msg.msg.user_data.contents[89], expected "
           "23, is "
        << (int64_t)last_msg.msg.user_data.contents[89];
    EXPECT_EQ(last_msg.msg.user_data.contents[90], 73)
        << "incorrect value for last_msg.msg.user_data.contents[90], expected "
           "73, is "
        << (int64_t)last_msg.msg.user_data.contents[90];
    EXPECT_EQ(last_msg.msg.user_data.contents[91], 119)
        << "incorrect value for last_msg.msg.user_data.contents[91], expected "
           "119, is "
        << (int64_t)last_msg.msg.user_data.contents[91];
    EXPECT_EQ(last_msg.msg.user_data.contents[92], 136)
        << "incorrect value for last_msg.msg.user_data.contents[92], expected "
           "136, is "
        << (int64_t)last_msg.msg.user_data.contents[92];
    EXPECT_EQ(last_msg.msg.user_data.contents[93], 231)
        << "incorrect value for last_msg.msg.user_data.contents[93], expected "
           "231, is "
        << (int64_t)last_msg.msg.user_data.contents[93];
    EXPECT_EQ(last_msg.msg.user_data.contents[94], 189)
        << "incorrect value for last_msg.msg.user_data.contents[94], expected "
           "189, is "
        << (int64_t)last_msg.msg.user_data.contents[94];
    EXPECT_EQ(last_msg.msg.user_data.contents[95], 26)
        << "incorrect value for last_msg.msg.user_data.contents[95], expected "
           "26, is "
        << (int64_t)last_msg.msg.user_data.contents[95];
    EXPECT_EQ(last_msg.msg.user_data.contents[96], 174)
        << "incorrect value for last_msg.msg.user_data.contents[96], expected "
           "174, is "
        << (int64_t)last_msg.msg.user_data.contents[96];
    EXPECT_EQ(last_msg.msg.user_data.contents[97], 128)
        << "incorrect value for last_msg.msg.user_data.contents[97], expected "
           "128, is "
        << (int64_t)last_msg.msg.user_data.contents[97];
    EXPECT_EQ(last_msg.msg.user_data.contents[98], 93)
        << "incorrect value for last_msg.msg.user_data.contents[98], expected "
           "93, is "
        << (int64_t)last_msg.msg.user_data.contents[98];
    EXPECT_EQ(last_msg.msg.user_data.contents[99], 30)
        << "incorrect value for last_msg.msg.user_data.contents[99], expected "
           "30, is "
        << (int64_t)last_msg.msg.user_data.contents[99];
    EXPECT_EQ(last_msg.msg.user_data.contents[100], 76)
        << "incorrect value for last_msg.msg.user_data.contents[100], expected "
           "76, is "
        << (int64_t)last_msg.msg.user_data.contents[100];
    EXPECT_EQ(last_msg.msg.user_data.contents[101], 45)
        << "incorrect value for last_msg.msg.user_data.contents[101], expected "
           "45, is "
        << (int64_t)last_msg.msg.user_data.contents[101];
    EXPECT_EQ(last_msg.msg.user_data.contents[102], 109)
        << "incorrect value for last_msg.msg.user_data.contents[102], expected "
           "109, is "
        << (int64_t)last_msg.msg.user_data.contents[102];
    EXPECT_EQ(last_msg.msg.user_data.contents[103], 134)
        << "incorrect value for last_msg.msg.user_data.contents[103], expected "
           "134, is "
        << (int64_t)last_msg.msg.user_data.contents[103];
    EXPECT_EQ(last_msg.msg.user_data.contents[104], 81)
        << "incorrect value for last_msg.msg.user_data.contents[104], expected "
           "81, is "
        << (int64_t)last_msg.msg.user_data.contents[104];
    EXPECT_EQ(last_msg.msg.user_data.contents[105], 0)
        << "incorrect value for last_msg.msg.user_data.contents[105], expected "
           "0, is "
        << (int64_t)last_msg.msg.user_data.contents[105];
    EXPECT_EQ(last_msg.msg.user_data.contents[106], 116)
        << "incorrect value for last_msg.msg.user_data.contents[106], expected "
           "116, is "
        << (int64_t)last_msg.msg.user_data.contents[106];
    EXPECT_EQ(last_msg.msg.user_data.contents[107], 158)
        << "incorrect value for last_msg.msg.user_data.contents[107], expected "
           "158, is "
        << (int64_t)last_msg.msg.user_data.contents[107];
    EXPECT_EQ(last_msg.msg.user_data.contents[108], 127)
        << "incorrect value for last_msg.msg.user_data.contents[108], expected "
           "127, is "
        << (int64_t)last_msg.msg.user_data.contents[108];
    EXPECT_EQ(last_msg.msg.user_data.contents[109], 40)
        << "incorrect value for last_msg.msg.user_data.contents[109], expected "
           "40, is "
        << (int64_t)last_msg.msg.user_data.contents[109];
    EXPECT_EQ(last_msg.msg.user_data.contents[110], 133)
        << "incorrect value for last_msg.msg.user_data.contents[110], expected "
           "133, is "
        << (int64_t)last_msg.msg.user_data.contents[110];
    EXPECT_EQ(last_msg.msg.user_data.contents[111], 208)
        << "incorrect value for last_msg.msg.user_data.contents[111], expected "
           "208, is "
        << (int64_t)last_msg.msg.user_data.contents[111];
    EXPECT_EQ(last_msg.msg.user_data.contents[112], 134)
        << "incorrect value for last_msg.msg.user_data.contents[112], expected "
           "134, is "
        << (int64_t)last_msg.msg.user_data.contents[112];
    EXPECT_EQ(last_msg.msg.user_data.contents[113], 127)
        << "incorrect value for last_msg.msg.user_data.contents[113], expected "
           "127, is "
        << (int64_t)last_msg.msg.user_data.contents[113];
    EXPECT_EQ(last_msg.msg.user_data.contents[114], 140)
        << "incorrect value for last_msg.msg.user_data.contents[114], expected "
           "140, is "
        << (int64_t)last_msg.msg.user_data.contents[114];
    EXPECT_EQ(last_msg.msg.user_data.contents[115], 232)
        << "incorrect value for last_msg.msg.user_data.contents[115], expected "
           "232, is "
        << (int64_t)last_msg.msg.user_data.contents[115];
    EXPECT_EQ(last_msg.msg.user_data.contents[116], 183)
        << "incorrect value for last_msg.msg.user_data.contents[116], expected "
           "183, is "
        << (int64_t)last_msg.msg.user_data.contents[116];
    EXPECT_EQ(last_msg.msg.user_data.contents[117], 184)
        << "incorrect value for last_msg.msg.user_data.contents[117], expected "
           "184, is "
        << (int64_t)last_msg.msg.user_data.contents[117];
    EXPECT_EQ(last_msg.msg.user_data.contents[118], 108)
        << "incorrect value for last_msg.msg.user_data.contents[118], expected "
           "108, is "
        << (int64_t)last_msg.msg.user_data.contents[118];
    EXPECT_EQ(last_msg.msg.user_data.contents[119], 6)
        << "incorrect value for last_msg.msg.user_data.contents[119], expected "
           "6, is "
        << (int64_t)last_msg.msg.user_data.contents[119];
    EXPECT_EQ(last_msg.msg.user_data.contents[120], 228)
        << "incorrect value for last_msg.msg.user_data.contents[120], expected "
           "228, is "
        << (int64_t)last_msg.msg.user_data.contents[120];
    EXPECT_EQ(last_msg.msg.user_data.contents[121], 54)
        << "incorrect value for last_msg.msg.user_data.contents[121], expected "
           "54, is "
        << (int64_t)last_msg.msg.user_data.contents[121];
    EXPECT_EQ(last_msg.msg.user_data.contents[122], 238)
        << "incorrect value for last_msg.msg.user_data.contents[122], expected "
           "238, is "
        << (int64_t)last_msg.msg.user_data.contents[122];
    EXPECT_EQ(last_msg.msg.user_data.contents[123], 59)
        << "incorrect value for last_msg.msg.user_data.contents[123], expected "
           "59, is "
        << (int64_t)last_msg.msg.user_data.contents[123];
    EXPECT_EQ(last_msg.msg.user_data.contents[124], 220)
        << "incorrect value for last_msg.msg.user_data.contents[124], expected "
           "220, is "
        << (int64_t)last_msg.msg.user_data.contents[124];
    EXPECT_EQ(last_msg.msg.user_data.contents[125], 30)
        << "incorrect value for last_msg.msg.user_data.contents[125], expected "
           "30, is "
        << (int64_t)last_msg.msg.user_data.contents[125];
    EXPECT_EQ(last_msg.msg.user_data.contents[126], 228)
        << "incorrect value for last_msg.msg.user_data.contents[126], expected "
           "228, is "
        << (int64_t)last_msg.msg.user_data.contents[126];
    EXPECT_EQ(last_msg.msg.user_data.contents[127], 212)
        << "incorrect value for last_msg.msg.user_data.contents[127], expected "
           "212, is "
        << (int64_t)last_msg.msg.user_data.contents[127];
    EXPECT_EQ(last_msg.msg.user_data.contents[128], 50)
        << "incorrect value for last_msg.msg.user_data.contents[128], expected "
           "50, is "
        << (int64_t)last_msg.msg.user_data.contents[128];
    EXPECT_EQ(last_msg.msg.user_data.contents[129], 182)
        << "incorrect value for last_msg.msg.user_data.contents[129], expected "
           "182, is "
        << (int64_t)last_msg.msg.user_data.contents[129];
    EXPECT_EQ(last_msg.msg.user_data.contents[130], 97)
        << "incorrect value for last_msg.msg.user_data.contents[130], expected "
           "97, is "
        << (int64_t)last_msg.msg.user_data.contents[130];
    EXPECT_EQ(last_msg.msg.user_data.contents[131], 20)
        << "incorrect value for last_msg.msg.user_data.contents[131], expected "
           "20, is "
        << (int64_t)last_msg.msg.user_data.contents[131];
    EXPECT_EQ(last_msg.msg.user_data.contents[132], 41)
        << "incorrect value for last_msg.msg.user_data.contents[132], expected "
           "41, is "
        << (int64_t)last_msg.msg.user_data.contents[132];
    EXPECT_EQ(last_msg.msg.user_data.contents[133], 76)
        << "incorrect value for last_msg.msg.user_data.contents[133], expected "
           "76, is "
        << (int64_t)last_msg.msg.user_data.contents[133];
    EXPECT_EQ(last_msg.msg.user_data.contents[134], 227)
        << "incorrect value for last_msg.msg.user_data.contents[134], expected "
           "227, is "
        << (int64_t)last_msg.msg.user_data.contents[134];
    EXPECT_EQ(last_msg.msg.user_data.contents[135], 88)
        << "incorrect value for last_msg.msg.user_data.contents[135], expected "
           "88, is "
        << (int64_t)last_msg.msg.user_data.contents[135];
    EXPECT_EQ(last_msg.msg.user_data.contents[136], 12)
        << "incorrect value for last_msg.msg.user_data.contents[136], expected "
           "12, is "
        << (int64_t)last_msg.msg.user_data.contents[136];
    EXPECT_EQ(last_msg.msg.user_data.contents[137], 95)
        << "incorrect value for last_msg.msg.user_data.contents[137], expected "
           "95, is "
        << (int64_t)last_msg.msg.user_data.contents[137];
    EXPECT_EQ(last_msg.msg.user_data.contents[138], 112)
        << "incorrect value for last_msg.msg.user_data.contents[138], expected "
           "112, is "
        << (int64_t)last_msg.msg.user_data.contents[138];
    EXPECT_EQ(last_msg.msg.user_data.contents[139], 209)
        << "incorrect value for last_msg.msg.user_data.contents[139], expected "
           "209, is "
        << (int64_t)last_msg.msg.user_data.contents[139];
    EXPECT_EQ(last_msg.msg.user_data.contents[140], 183)
        << "incorrect value for last_msg.msg.user_data.contents[140], expected "
           "183, is "
        << (int64_t)last_msg.msg.user_data.contents[140];
    EXPECT_EQ(last_msg.msg.user_data.contents[141], 127)
        << "incorrect value for last_msg.msg.user_data.contents[141], expected "
           "127, is "
        << (int64_t)last_msg.msg.user_data.contents[141];
    EXPECT_EQ(last_msg.msg.user_data.contents[142], 4)
        << "incorrect value for last_msg.msg.user_data.contents[142], expected "
           "4, is "
        << (int64_t)last_msg.msg.user_data.contents[142];
    EXPECT_EQ(last_msg.msg.user_data.contents[143], 165)
        << "incorrect value for last_msg.msg.user_data.contents[143], expected "
           "165, is "
        << (int64_t)last_msg.msg.user_data.contents[143];
    EXPECT_EQ(last_msg.msg.user_data.contents[144], 189)
        << "incorrect value for last_msg.msg.user_data.contents[144], expected "
           "189, is "
        << (int64_t)last_msg.msg.user_data.contents[144];
    EXPECT_EQ(last_msg.msg.user_data.contents[145], 44)
        << "incorrect value for last_msg.msg.user_data.contents[145], expected "
           "44, is "
        << (int64_t)last_msg.msg.user_data.contents[145];
    EXPECT_EQ(last_msg.msg.user_data.contents[146], 239)
        << "incorrect value for last_msg.msg.user_data.contents[146], expected "
           "239, is "
        << (int64_t)last_msg.msg.user_data.contents[146];
    EXPECT_EQ(last_msg.msg.user_data.contents[147], 232)
        << "incorrect value for last_msg.msg.user_data.contents[147], expected "
           "232, is "
        << (int64_t)last_msg.msg.user_data.contents[147];
    EXPECT_EQ(last_msg.msg.user_data.contents[148], 132)
        << "incorrect value for last_msg.msg.user_data.contents[148], expected "
           "132, is "
        << (int64_t)last_msg.msg.user_data.contents[148];
    EXPECT_EQ(last_msg.msg.user_data.contents[149], 9)
        << "incorrect value for last_msg.msg.user_data.contents[149], expected "
           "9, is "
        << (int64_t)last_msg.msg.user_data.contents[149];
    EXPECT_EQ(last_msg.msg.user_data.contents[150], 114)
        << "incorrect value for last_msg.msg.user_data.contents[150], expected "
           "114, is "
        << (int64_t)last_msg.msg.user_data.contents[150];
    EXPECT_EQ(last_msg.msg.user_data.contents[151], 184)
        << "incorrect value for last_msg.msg.user_data.contents[151], expected "
           "184, is "
        << (int64_t)last_msg.msg.user_data.contents[151];
    EXPECT_EQ(last_msg.msg.user_data.contents[152], 249)
        << "incorrect value for last_msg.msg.user_data.contents[152], expected "
           "249, is "
        << (int64_t)last_msg.msg.user_data.contents[152];
    EXPECT_EQ(last_msg.msg.user_data.contents[153], 208)
        << "incorrect value for last_msg.msg.user_data.contents[153], expected "
           "208, is "
        << (int64_t)last_msg.msg.user_data.contents[153];
    EXPECT_EQ(last_msg.msg.user_data.contents[154], 246)
        << "incorrect value for last_msg.msg.user_data.contents[154], expected "
           "246, is "
        << (int64_t)last_msg.msg.user_data.contents[154];
    EXPECT_EQ(last_msg.msg.user_data.contents[155], 194)
        << "incorrect value for last_msg.msg.user_data.contents[155], expected "
           "194, is "
        << (int64_t)last_msg.msg.user_data.contents[155];
    EXPECT_EQ(last_msg.msg.user_data.contents[156], 250)
        << "incorrect value for last_msg.msg.user_data.contents[156], expected "
           "250, is "
        << (int64_t)last_msg.msg.user_data.contents[156];
    EXPECT_EQ(last_msg.msg.user_data.contents[157], 2)
        << "incorrect value for last_msg.msg.user_data.contents[157], expected "
           "2, is "
        << (int64_t)last_msg.msg.user_data.contents[157];
    EXPECT_EQ(last_msg.msg.user_data.contents[158], 97)
        << "incorrect value for last_msg.msg.user_data.contents[158], expected "
           "97, is "
        << (int64_t)last_msg.msg.user_data.contents[158];
    EXPECT_EQ(last_msg.msg.user_data.contents[159], 173)
        << "incorrect value for last_msg.msg.user_data.contents[159], expected "
           "173, is "
        << (int64_t)last_msg.msg.user_data.contents[159];
    EXPECT_EQ(last_msg.msg.user_data.contents[160], 157)
        << "incorrect value for last_msg.msg.user_data.contents[160], expected "
           "157, is "
        << (int64_t)last_msg.msg.user_data.contents[160];
    EXPECT_EQ(last_msg.msg.user_data.contents[161], 202)
        << "incorrect value for last_msg.msg.user_data.contents[161], expected "
           "202, is "
        << (int64_t)last_msg.msg.user_data.contents[161];
    EXPECT_EQ(last_msg.msg.user_data.contents[162], 172)
        << "incorrect value for last_msg.msg.user_data.contents[162], expected "
           "172, is "
        << (int64_t)last_msg.msg.user_data.contents[162];
    EXPECT_EQ(last_msg.msg.user_data.contents[163], 180)
        << "incorrect value for last_msg.msg.user_data.contents[163], expected "
           "180, is "
        << (int64_t)last_msg.msg.user_data.contents[163];
    EXPECT_EQ(last_msg.msg.user_data.contents[164], 150)
        << "incorrect value for last_msg.msg.user_data.contents[164], expected "
           "150, is "
        << (int64_t)last_msg.msg.user_data.contents[164];
    EXPECT_EQ(last_msg.msg.user_data.contents[165], 213)
        << "incorrect value for last_msg.msg.user_data.contents[165], expected "
           "213, is "
        << (int64_t)last_msg.msg.user_data.contents[165];
    EXPECT_EQ(last_msg.msg.user_data.contents[166], 193)
        << "incorrect value for last_msg.msg.user_data.contents[166], expected "
           "193, is "
        << (int64_t)last_msg.msg.user_data.contents[166];
    EXPECT_EQ(last_msg.msg.user_data.contents[167], 177)
        << "incorrect value for last_msg.msg.user_data.contents[167], expected "
           "177, is "
        << (int64_t)last_msg.msg.user_data.contents[167];
    EXPECT_EQ(last_msg.msg.user_data.contents[168], 209)
        << "incorrect value for last_msg.msg.user_data.contents[168], expected "
           "209, is "
        << (int64_t)last_msg.msg.user_data.contents[168];
    EXPECT_EQ(last_msg.msg.user_data.contents[169], 156)
        << "incorrect value for last_msg.msg.user_data.contents[169], expected "
           "156, is "
        << (int64_t)last_msg.msg.user_data.contents[169];
    EXPECT_EQ(last_msg.msg.user_data.contents[170], 20)
        << "incorrect value for last_msg.msg.user_data.contents[170], expected "
           "20, is "
        << (int64_t)last_msg.msg.user_data.contents[170];
    EXPECT_EQ(last_msg.msg.user_data.contents[171], 174)
        << "incorrect value for last_msg.msg.user_data.contents[171], expected "
           "174, is "
        << (int64_t)last_msg.msg.user_data.contents[171];
    EXPECT_EQ(last_msg.msg.user_data.contents[172], 18)
        << "incorrect value for last_msg.msg.user_data.contents[172], expected "
           "18, is "
        << (int64_t)last_msg.msg.user_data.contents[172];
    EXPECT_EQ(last_msg.msg.user_data.contents[173], 73)
        << "incorrect value for last_msg.msg.user_data.contents[173], expected "
           "73, is "
        << (int64_t)last_msg.msg.user_data.contents[173];
    EXPECT_EQ(last_msg.msg.user_data.contents[174], 132)
        << "incorrect value for last_msg.msg.user_data.contents[174], expected "
           "132, is "
        << (int64_t)last_msg.msg.user_data.contents[174];
    EXPECT_EQ(last_msg.msg.user_data.contents[175], 215)
        << "incorrect value for last_msg.msg.user_data.contents[175], expected "
           "215, is "
        << (int64_t)last_msg.msg.user_data.contents[175];
    EXPECT_EQ(last_msg.msg.user_data.contents[176], 115)
        << "incorrect value for last_msg.msg.user_data.contents[176], expected "
           "115, is "
        << (int64_t)last_msg.msg.user_data.contents[176];
    EXPECT_EQ(last_msg.msg.user_data.contents[177], 128)
        << "incorrect value for last_msg.msg.user_data.contents[177], expected "
           "128, is "
        << (int64_t)last_msg.msg.user_data.contents[177];
    EXPECT_EQ(last_msg.msg.user_data.contents[178], 175)
        << "incorrect value for last_msg.msg.user_data.contents[178], expected "
           "175, is "
        << (int64_t)last_msg.msg.user_data.contents[178];
    EXPECT_EQ(last_msg.msg.user_data.contents[179], 169)
        << "incorrect value for last_msg.msg.user_data.contents[179], expected "
           "169, is "
        << (int64_t)last_msg.msg.user_data.contents[179];
    EXPECT_EQ(last_msg.msg.user_data.contents[180], 116)
        << "incorrect value for last_msg.msg.user_data.contents[180], expected "
           "116, is "
        << (int64_t)last_msg.msg.user_data.contents[180];
    EXPECT_EQ(last_msg.msg.user_data.contents[181], 132)
        << "incorrect value for last_msg.msg.user_data.contents[181], expected "
           "132, is "
        << (int64_t)last_msg.msg.user_data.contents[181];
    EXPECT_EQ(last_msg.msg.user_data.contents[182], 100)
        << "incorrect value for last_msg.msg.user_data.contents[182], expected "
           "100, is "
        << (int64_t)last_msg.msg.user_data.contents[182];
    EXPECT_EQ(last_msg.msg.user_data.contents[183], 72)
        << "incorrect value for last_msg.msg.user_data.contents[183], expected "
           "72, is "
        << (int64_t)last_msg.msg.user_data.contents[183];
    EXPECT_EQ(last_msg.msg.user_data.contents[184], 45)
        << "incorrect value for last_msg.msg.user_data.contents[184], expected "
           "45, is "
        << (int64_t)last_msg.msg.user_data.contents[184];
    EXPECT_EQ(last_msg.msg.user_data.contents[185], 25)
        << "incorrect value for last_msg.msg.user_data.contents[185], expected "
           "25, is "
        << (int64_t)last_msg.msg.user_data.contents[185];
    EXPECT_EQ(last_msg.msg.user_data.contents[186], 14)
        << "incorrect value for last_msg.msg.user_data.contents[186], expected "
           "14, is "
        << (int64_t)last_msg.msg.user_data.contents[186];
    EXPECT_EQ(last_msg.msg.user_data.contents[187], 205)
        << "incorrect value for last_msg.msg.user_data.contents[187], expected "
           "205, is "
        << (int64_t)last_msg.msg.user_data.contents[187];
    EXPECT_EQ(last_msg.msg.user_data.contents[188], 213)
        << "incorrect value for last_msg.msg.user_data.contents[188], expected "
           "213, is "
        << (int64_t)last_msg.msg.user_data.contents[188];
    EXPECT_EQ(last_msg.msg.user_data.contents[189], 145)
        << "incorrect value for last_msg.msg.user_data.contents[189], expected "
           "145, is "
        << (int64_t)last_msg.msg.user_data.contents[189];
    EXPECT_EQ(last_msg.msg.user_data.contents[190], 68)
        << "incorrect value for last_msg.msg.user_data.contents[190], expected "
           "68, is "
        << (int64_t)last_msg.msg.user_data.contents[190];
    EXPECT_EQ(last_msg.msg.user_data.contents[191], 137)
        << "incorrect value for last_msg.msg.user_data.contents[191], expected "
           "137, is "
        << (int64_t)last_msg.msg.user_data.contents[191];
    EXPECT_EQ(last_msg.msg.user_data.contents[192], 249)
        << "incorrect value for last_msg.msg.user_data.contents[192], expected "
           "249, is "
        << (int64_t)last_msg.msg.user_data.contents[192];
    EXPECT_EQ(last_msg.msg.user_data.contents[193], 54)
        << "incorrect value for last_msg.msg.user_data.contents[193], expected "
           "54, is "
        << (int64_t)last_msg.msg.user_data.contents[193];
    EXPECT_EQ(last_msg.msg.user_data.contents[194], 40)
        << "incorrect value for last_msg.msg.user_data.contents[194], expected "
           "40, is "
        << (int64_t)last_msg.msg.user_data.contents[194];
    EXPECT_EQ(last_msg.msg.user_data.contents[195], 174)
        << "incorrect value for last_msg.msg.user_data.contents[195], expected "
           "174, is "
        << (int64_t)last_msg.msg.user_data.contents[195];
    EXPECT_EQ(last_msg.msg.user_data.contents[196], 215)
        << "incorrect value for last_msg.msg.user_data.contents[196], expected "
           "215, is "
        << (int64_t)last_msg.msg.user_data.contents[196];
    EXPECT_EQ(last_msg.msg.user_data.contents[197], 148)
        << "incorrect value for last_msg.msg.user_data.contents[197], expected "
           "148, is "
        << (int64_t)last_msg.msg.user_data.contents[197];
    EXPECT_EQ(last_msg.msg.user_data.contents[198], 166)
        << "incorrect value for last_msg.msg.user_data.contents[198], expected "
           "166, is "
        << (int64_t)last_msg.msg.user_data.contents[198];
    EXPECT_EQ(last_msg.msg.user_data.contents[199], 190)
        << "incorrect value for last_msg.msg.user_data.contents[199], expected "
           "190, is "
        << (int64_t)last_msg.msg.user_data.contents[199];
    EXPECT_EQ(last_msg.msg.user_data.contents[200], 63)
        << "incorrect value for last_msg.msg.user_data.contents[200], expected "
           "63, is "
        << (int64_t)last_msg.msg.user_data.contents[200];
    EXPECT_EQ(last_msg.msg.user_data.contents[201], 118)
        << "incorrect value for last_msg.msg.user_data.contents[201], expected "
           "118, is "
        << (int64_t)last_msg.msg.user_data.contents[201];
    EXPECT_EQ(last_msg.msg.user_data.contents[202], 6)
        << "incorrect value for last_msg.msg.user_data.contents[202], expected "
           "6, is "
        << (int64_t)last_msg.msg.user_data.contents[202];
    EXPECT_EQ(last_msg.msg.user_data.contents[203], 165)
        << "incorrect value for last_msg.msg.user_data.contents[203], expected "
           "165, is "
        << (int64_t)last_msg.msg.user_data.contents[203];
    EXPECT_EQ(last_msg.msg.user_data.contents[204], 212)
        << "incorrect value for last_msg.msg.user_data.contents[204], expected "
           "212, is "
        << (int64_t)last_msg.msg.user_data.contents[204];
    EXPECT_EQ(last_msg.msg.user_data.contents[205], 74)
        << "incorrect value for last_msg.msg.user_data.contents[205], expected "
           "74, is "
        << (int64_t)last_msg.msg.user_data.contents[205];
    EXPECT_EQ(last_msg.msg.user_data.contents[206], 68)
        << "incorrect value for last_msg.msg.user_data.contents[206], expected "
           "68, is "
        << (int64_t)last_msg.msg.user_data.contents[206];
    EXPECT_EQ(last_msg.msg.user_data.contents[207], 200)
        << "incorrect value for last_msg.msg.user_data.contents[207], expected "
           "200, is "
        << (int64_t)last_msg.msg.user_data.contents[207];
    EXPECT_EQ(last_msg.msg.user_data.contents[208], 38)
        << "incorrect value for last_msg.msg.user_data.contents[208], expected "
           "38, is "
        << (int64_t)last_msg.msg.user_data.contents[208];
    EXPECT_EQ(last_msg.msg.user_data.contents[209], 139)
        << "incorrect value for last_msg.msg.user_data.contents[209], expected "
           "139, is "
        << (int64_t)last_msg.msg.user_data.contents[209];
    EXPECT_EQ(last_msg.msg.user_data.contents[210], 212)
        << "incorrect value for last_msg.msg.user_data.contents[210], expected "
           "212, is "
        << (int64_t)last_msg.msg.user_data.contents[210];
    EXPECT_EQ(last_msg.msg.user_data.contents[211], 112)
        << "incorrect value for last_msg.msg.user_data.contents[211], expected "
           "112, is "
        << (int64_t)last_msg.msg.user_data.contents[211];
    EXPECT_EQ(last_msg.msg.user_data.contents[212], 45)
        << "incorrect value for last_msg.msg.user_data.contents[212], expected "
           "45, is "
        << (int64_t)last_msg.msg.user_data.contents[212];
    EXPECT_EQ(last_msg.msg.user_data.contents[213], 167)
        << "incorrect value for last_msg.msg.user_data.contents[213], expected "
           "167, is "
        << (int64_t)last_msg.msg.user_data.contents[213];
    EXPECT_EQ(last_msg.msg.user_data.contents[214], 236)
        << "incorrect value for last_msg.msg.user_data.contents[214], expected "
           "236, is "
        << (int64_t)last_msg.msg.user_data.contents[214];
    EXPECT_EQ(last_msg.msg.user_data.contents[215], 255)
        << "incorrect value for last_msg.msg.user_data.contents[215], expected "
           "255, is "
        << (int64_t)last_msg.msg.user_data.contents[215];
    EXPECT_EQ(last_msg.msg.user_data.contents[216], 106)
        << "incorrect value for last_msg.msg.user_data.contents[216], expected "
           "106, is "
        << (int64_t)last_msg.msg.user_data.contents[216];
    EXPECT_EQ(last_msg.msg.user_data.contents[217], 92)
        << "incorrect value for last_msg.msg.user_data.contents[217], expected "
           "92, is "
        << (int64_t)last_msg.msg.user_data.contents[217];
    EXPECT_EQ(last_msg.msg.user_data.contents[218], 132)
        << "incorrect value for last_msg.msg.user_data.contents[218], expected "
           "132, is "
        << (int64_t)last_msg.msg.user_data.contents[218];
    EXPECT_EQ(last_msg.msg.user_data.contents[219], 59)
        << "incorrect value for last_msg.msg.user_data.contents[219], expected "
           "59, is "
        << (int64_t)last_msg.msg.user_data.contents[219];
    EXPECT_EQ(last_msg.msg.user_data.contents[220], 61)
        << "incorrect value for last_msg.msg.user_data.contents[220], expected "
           "61, is "
        << (int64_t)last_msg.msg.user_data.contents[220];
    EXPECT_EQ(last_msg.msg.user_data.contents[221], 233)
        << "incorrect value for last_msg.msg.user_data.contents[221], expected "
           "233, is "
        << (int64_t)last_msg.msg.user_data.contents[221];
    EXPECT_EQ(last_msg.msg.user_data.contents[222], 3)
        << "incorrect value for last_msg.msg.user_data.contents[222], expected "
           "3, is "
        << (int64_t)last_msg.msg.user_data.contents[222];
    EXPECT_EQ(last_msg.msg.user_data.contents[223], 246)
        << "incorrect value for last_msg.msg.user_data.contents[223], expected "
           "246, is "
        << (int64_t)last_msg.msg.user_data.contents[223];
    EXPECT_EQ(last_msg.msg.user_data.contents[224], 158)
        << "incorrect value for last_msg.msg.user_data.contents[224], expected "
           "158, is "
        << (int64_t)last_msg.msg.user_data.contents[224];
    EXPECT_EQ(last_msg.msg.user_data.contents[225], 83)
        << "incorrect value for last_msg.msg.user_data.contents[225], expected "
           "83, is "
        << (int64_t)last_msg.msg.user_data.contents[225];
    EXPECT_EQ(last_msg.msg.user_data.contents[226], 134)
        << "incorrect value for last_msg.msg.user_data.contents[226], expected "
           "134, is "
        << (int64_t)last_msg.msg.user_data.contents[226];
    EXPECT_EQ(last_msg.msg.user_data.contents[227], 246)
        << "incorrect value for last_msg.msg.user_data.contents[227], expected "
           "246, is "
        << (int64_t)last_msg.msg.user_data.contents[227];
    EXPECT_EQ(last_msg.msg.user_data.contents[228], 154)
        << "incorrect value for last_msg.msg.user_data.contents[228], expected "
           "154, is "
        << (int64_t)last_msg.msg.user_data.contents[228];
    EXPECT_EQ(last_msg.msg.user_data.contents[229], 17)
        << "incorrect value for last_msg.msg.user_data.contents[229], expected "
           "17, is "
        << (int64_t)last_msg.msg.user_data.contents[229];
    EXPECT_EQ(last_msg.msg.user_data.contents[230], 0)
        << "incorrect value for last_msg.msg.user_data.contents[230], expected "
           "0, is "
        << (int64_t)last_msg.msg.user_data.contents[230];
    EXPECT_EQ(last_msg.msg.user_data.contents[231], 6)
        << "incorrect value for last_msg.msg.user_data.contents[231], expected "
           "6, is "
        << (int64_t)last_msg.msg.user_data.contents[231];
    EXPECT_EQ(last_msg.msg.user_data.contents[232], 56)
        << "incorrect value for last_msg.msg.user_data.contents[232], expected "
           "56, is "
        << (int64_t)last_msg.msg.user_data.contents[232];
    EXPECT_EQ(last_msg.msg.user_data.contents[233], 216)
        << "incorrect value for last_msg.msg.user_data.contents[233], expected "
           "216, is "
        << (int64_t)last_msg.msg.user_data.contents[233];
    EXPECT_EQ(last_msg.msg.user_data.contents[234], 19)
        << "incorrect value for last_msg.msg.user_data.contents[234], expected "
           "19, is "
        << (int64_t)last_msg.msg.user_data.contents[234];
    EXPECT_EQ(last_msg.msg.user_data.contents[235], 216)
        << "incorrect value for last_msg.msg.user_data.contents[235], expected "
           "216, is "
        << (int64_t)last_msg.msg.user_data.contents[235];
    EXPECT_EQ(last_msg.msg.user_data.contents[236], 70)
        << "incorrect value for last_msg.msg.user_data.contents[236], expected "
           "70, is "
        << (int64_t)last_msg.msg.user_data.contents[236];
    EXPECT_EQ(last_msg.msg.user_data.contents[237], 71)
        << "incorrect value for last_msg.msg.user_data.contents[237], expected "
           "71, is "
        << (int64_t)last_msg.msg.user_data.contents[237];
    EXPECT_EQ(last_msg.msg.user_data.contents[238], 161)
        << "incorrect value for last_msg.msg.user_data.contents[238], expected "
           "161, is "
        << (int64_t)last_msg.msg.user_data.contents[238];
    EXPECT_EQ(last_msg.msg.user_data.contents[239], 184)
        << "incorrect value for last_msg.msg.user_data.contents[239], expected "
           "184, is "
        << (int64_t)last_msg.msg.user_data.contents[239];
    EXPECT_EQ(last_msg.msg.user_data.contents[240], 5)
        << "incorrect value for last_msg.msg.user_data.contents[240], expected "
           "5, is "
        << (int64_t)last_msg.msg.user_data.contents[240];
    EXPECT_EQ(last_msg.msg.user_data.contents[241], 177)
        << "incorrect value for last_msg.msg.user_data.contents[241], expected "
           "177, is "
        << (int64_t)last_msg.msg.user_data.contents[241];
    EXPECT_EQ(last_msg.msg.user_data.contents[242], 45)
        << "incorrect value for last_msg.msg.user_data.contents[242], expected "
           "45, is "
        << (int64_t)last_msg.msg.user_data.contents[242];
    EXPECT_EQ(last_msg.msg.user_data.contents[243], 37)
        << "incorrect value for last_msg.msg.user_data.contents[243], expected "
           "37, is "
        << (int64_t)last_msg.msg.user_data.contents[243];
    EXPECT_EQ(last_msg.msg.user_data.contents[244], 98)
        << "incorrect value for last_msg.msg.user_data.contents[244], expected "
           "98, is "
        << (int64_t)last_msg.msg.user_data.contents[244];
    EXPECT_EQ(last_msg.msg.user_data.contents[245], 56)
        << "incorrect value for last_msg.msg.user_data.contents[245], expected "
           "56, is "
        << (int64_t)last_msg.msg.user_data.contents[245];
    EXPECT_EQ(last_msg.msg.user_data.contents[246], 149)
        << "incorrect value for last_msg.msg.user_data.contents[246], expected "
           "149, is "
        << (int64_t)last_msg.msg.user_data.contents[246];
    EXPECT_EQ(last_msg.msg.user_data.contents[247], 0)
        << "incorrect value for last_msg.msg.user_data.contents[247], expected "
           "0, is "
        << (int64_t)last_msg.msg.user_data.contents[247];
    EXPECT_EQ(last_msg.msg.user_data.contents[248], 73)
        << "incorrect value for last_msg.msg.user_data.contents[248], expected "
           "73, is "
        << (int64_t)last_msg.msg.user_data.contents[248];
    EXPECT_EQ(last_msg.msg.user_data.contents[249], 221)
        << "incorrect value for last_msg.msg.user_data.contents[249], expected "
           "221, is "
        << (int64_t)last_msg.msg.user_data.contents[249];
    EXPECT_EQ(last_msg.msg.user_data.contents[250], 105)
        << "incorrect value for last_msg.msg.user_data.contents[250], expected "
           "105, is "
        << (int64_t)last_msg.msg.user_data.contents[250];
    EXPECT_EQ(last_msg.msg.user_data.contents[251], 239)
        << "incorrect value for last_msg.msg.user_data.contents[251], expected "
           "239, is "
        << (int64_t)last_msg.msg.user_data.contents[251];
    EXPECT_EQ(last_msg.msg.user_data.contents[252], 168)
        << "incorrect value for last_msg.msg.user_data.contents[252], expected "
           "168, is "
        << (int64_t)last_msg.msg.user_data.contents[252];
    EXPECT_EQ(last_msg.msg.user_data.contents[253], 205)
        << "incorrect value for last_msg.msg.user_data.contents[253], expected "
           "205, is "
        << (int64_t)last_msg.msg.user_data.contents[253];
    EXPECT_EQ(last_msg.msg.user_data.contents[254], 85)
        << "incorrect value for last_msg.msg.user_data.contents[254], expected "
           "85, is "
        << (int64_t)last_msg.msg.user_data.contents[254];

    EXPECT_EQ(last_msg.msg.user_data.n_contents, 255)
        << "incorrect value for last_msg.msg.user_data.n_contents, expected "
           "255, is "
        << (int64_t)last_msg.msg.user_data.n_contents;
  }
}

}  // namespace
