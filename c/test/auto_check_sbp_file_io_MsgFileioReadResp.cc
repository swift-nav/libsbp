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
// spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadResp.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/file_io.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_file_io_MsgFileioReadResp,
     test_auto_check_sbp_file_io_MsgFileioReadResp) {
  sbp_msg_callbacks_node_t n;

  // State of the SBP message parser.
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

    sbp_callback_register(&sbp_state, SbpMsgFileioReadResp, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  163, 0,   195, 4,   255, 67,  183, 115, 15,  73,  231, 227, 179,
        18,  76,  68,  229, 216, 21,  98,  183, 69,  190, 5,   252, 176, 55,
        32,  78,  8,   52,  127, 50,  71,  106, 61,  79,  191, 106, 46,  79,
        118, 248, 118, 207, 206, 210, 91,  73,  251, 81,  131, 205, 193, 146,
        206, 185, 140, 249, 163, 231, 65,  67,  94,  250, 109, 152, 95,  123,
        77,  224, 124, 238, 205, 65,  103, 35,  104, 209, 5,   191, 47,  249,
        176, 166, 213, 46,  192, 86,  32,  103, 146, 252, 4,   16,  54,  161,
        60,  6,   13,  191, 116, 182, 42,  191, 213, 20,  217, 8,   142, 187,
        238, 120, 184, 250, 31,  151, 37,  51,  177, 130, 190, 155, 71,  68,
        56,  238, 92,  130, 37,  137, 146, 246, 114, 116, 138, 165, 217, 79,
        10,  189, 128, 189, 2,   240, 92,  28,  126, 105, 236, 228, 194, 0,
        51,  61,  74,  41,  10,  239, 133, 106, 190, 30,  27,  3,   240, 205,
        253, 113, 25,  28,  187, 81,  101, 216, 121, 41,  179, 120, 152, 18,
        116, 53,  212, 100, 2,   114, 198, 200, 10,  147, 25,  33,  115, 208,
        113, 60,  179, 183, 0,   41,  217, 206, 255, 211, 225, 142, 191, 133,
        81,  15,  248, 193, 66,  191, 244, 221, 248, 199, 241, 112, 51,  1,
        180, 180, 125, 97,  145, 25,  72,  210, 215, 208, 15,  126, 56,  38,
        65,  4,   64,  19,  74,  223, 111, 109, 52,  43,  167, 186, 202, 111,
        11,  91,  21,  236, 234, 196, 36,  171, 147, 10,  240,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.fileio_read_resp.contents[0] = 73;

    test_msg.fileio_read_resp.contents[1] = 231;

    test_msg.fileio_read_resp.contents[2] = 227;

    test_msg.fileio_read_resp.contents[3] = 179;

    test_msg.fileio_read_resp.contents[4] = 18;

    test_msg.fileio_read_resp.contents[5] = 76;

    test_msg.fileio_read_resp.contents[6] = 68;

    test_msg.fileio_read_resp.contents[7] = 229;

    test_msg.fileio_read_resp.contents[8] = 216;

    test_msg.fileio_read_resp.contents[9] = 21;

    test_msg.fileio_read_resp.contents[10] = 98;

    test_msg.fileio_read_resp.contents[11] = 183;

    test_msg.fileio_read_resp.contents[12] = 69;

    test_msg.fileio_read_resp.contents[13] = 190;

    test_msg.fileio_read_resp.contents[14] = 5;

    test_msg.fileio_read_resp.contents[15] = 252;

    test_msg.fileio_read_resp.contents[16] = 176;

    test_msg.fileio_read_resp.contents[17] = 55;

    test_msg.fileio_read_resp.contents[18] = 32;

    test_msg.fileio_read_resp.contents[19] = 78;

    test_msg.fileio_read_resp.contents[20] = 8;

    test_msg.fileio_read_resp.contents[21] = 52;

    test_msg.fileio_read_resp.contents[22] = 127;

    test_msg.fileio_read_resp.contents[23] = 50;

    test_msg.fileio_read_resp.contents[24] = 71;

    test_msg.fileio_read_resp.contents[25] = 106;

    test_msg.fileio_read_resp.contents[26] = 61;

    test_msg.fileio_read_resp.contents[27] = 79;

    test_msg.fileio_read_resp.contents[28] = 191;

    test_msg.fileio_read_resp.contents[29] = 106;

    test_msg.fileio_read_resp.contents[30] = 46;

    test_msg.fileio_read_resp.contents[31] = 79;

    test_msg.fileio_read_resp.contents[32] = 118;

    test_msg.fileio_read_resp.contents[33] = 248;

    test_msg.fileio_read_resp.contents[34] = 118;

    test_msg.fileio_read_resp.contents[35] = 207;

    test_msg.fileio_read_resp.contents[36] = 206;

    test_msg.fileio_read_resp.contents[37] = 210;

    test_msg.fileio_read_resp.contents[38] = 91;

    test_msg.fileio_read_resp.contents[39] = 73;

    test_msg.fileio_read_resp.contents[40] = 251;

    test_msg.fileio_read_resp.contents[41] = 81;

    test_msg.fileio_read_resp.contents[42] = 131;

    test_msg.fileio_read_resp.contents[43] = 205;

    test_msg.fileio_read_resp.contents[44] = 193;

    test_msg.fileio_read_resp.contents[45] = 146;

    test_msg.fileio_read_resp.contents[46] = 206;

    test_msg.fileio_read_resp.contents[47] = 185;

    test_msg.fileio_read_resp.contents[48] = 140;

    test_msg.fileio_read_resp.contents[49] = 249;

    test_msg.fileio_read_resp.contents[50] = 163;

    test_msg.fileio_read_resp.contents[51] = 231;

    test_msg.fileio_read_resp.contents[52] = 65;

    test_msg.fileio_read_resp.contents[53] = 67;

    test_msg.fileio_read_resp.contents[54] = 94;

    test_msg.fileio_read_resp.contents[55] = 250;

    test_msg.fileio_read_resp.contents[56] = 109;

    test_msg.fileio_read_resp.contents[57] = 152;

    test_msg.fileio_read_resp.contents[58] = 95;

    test_msg.fileio_read_resp.contents[59] = 123;

    test_msg.fileio_read_resp.contents[60] = 77;

    test_msg.fileio_read_resp.contents[61] = 224;

    test_msg.fileio_read_resp.contents[62] = 124;

    test_msg.fileio_read_resp.contents[63] = 238;

    test_msg.fileio_read_resp.contents[64] = 205;

    test_msg.fileio_read_resp.contents[65] = 65;

    test_msg.fileio_read_resp.contents[66] = 103;

    test_msg.fileio_read_resp.contents[67] = 35;

    test_msg.fileio_read_resp.contents[68] = 104;

    test_msg.fileio_read_resp.contents[69] = 209;

    test_msg.fileio_read_resp.contents[70] = 5;

    test_msg.fileio_read_resp.contents[71] = 191;

    test_msg.fileio_read_resp.contents[72] = 47;

    test_msg.fileio_read_resp.contents[73] = 249;

    test_msg.fileio_read_resp.contents[74] = 176;

    test_msg.fileio_read_resp.contents[75] = 166;

    test_msg.fileio_read_resp.contents[76] = 213;

    test_msg.fileio_read_resp.contents[77] = 46;

    test_msg.fileio_read_resp.contents[78] = 192;

    test_msg.fileio_read_resp.contents[79] = 86;

    test_msg.fileio_read_resp.contents[80] = 32;

    test_msg.fileio_read_resp.contents[81] = 103;

    test_msg.fileio_read_resp.contents[82] = 146;

    test_msg.fileio_read_resp.contents[83] = 252;

    test_msg.fileio_read_resp.contents[84] = 4;

    test_msg.fileio_read_resp.contents[85] = 16;

    test_msg.fileio_read_resp.contents[86] = 54;

    test_msg.fileio_read_resp.contents[87] = 161;

    test_msg.fileio_read_resp.contents[88] = 60;

    test_msg.fileio_read_resp.contents[89] = 6;

    test_msg.fileio_read_resp.contents[90] = 13;

    test_msg.fileio_read_resp.contents[91] = 191;

    test_msg.fileio_read_resp.contents[92] = 116;

    test_msg.fileio_read_resp.contents[93] = 182;

    test_msg.fileio_read_resp.contents[94] = 42;

    test_msg.fileio_read_resp.contents[95] = 191;

    test_msg.fileio_read_resp.contents[96] = 213;

    test_msg.fileio_read_resp.contents[97] = 20;

    test_msg.fileio_read_resp.contents[98] = 217;

    test_msg.fileio_read_resp.contents[99] = 8;

    test_msg.fileio_read_resp.contents[100] = 142;

    test_msg.fileio_read_resp.contents[101] = 187;

    test_msg.fileio_read_resp.contents[102] = 238;

    test_msg.fileio_read_resp.contents[103] = 120;

    test_msg.fileio_read_resp.contents[104] = 184;

    test_msg.fileio_read_resp.contents[105] = 250;

    test_msg.fileio_read_resp.contents[106] = 31;

    test_msg.fileio_read_resp.contents[107] = 151;

    test_msg.fileio_read_resp.contents[108] = 37;

    test_msg.fileio_read_resp.contents[109] = 51;

    test_msg.fileio_read_resp.contents[110] = 177;

    test_msg.fileio_read_resp.contents[111] = 130;

    test_msg.fileio_read_resp.contents[112] = 190;

    test_msg.fileio_read_resp.contents[113] = 155;

    test_msg.fileio_read_resp.contents[114] = 71;

    test_msg.fileio_read_resp.contents[115] = 68;

    test_msg.fileio_read_resp.contents[116] = 56;

    test_msg.fileio_read_resp.contents[117] = 238;

    test_msg.fileio_read_resp.contents[118] = 92;

    test_msg.fileio_read_resp.contents[119] = 130;

    test_msg.fileio_read_resp.contents[120] = 37;

    test_msg.fileio_read_resp.contents[121] = 137;

    test_msg.fileio_read_resp.contents[122] = 146;

    test_msg.fileio_read_resp.contents[123] = 246;

    test_msg.fileio_read_resp.contents[124] = 114;

    test_msg.fileio_read_resp.contents[125] = 116;

    test_msg.fileio_read_resp.contents[126] = 138;

    test_msg.fileio_read_resp.contents[127] = 165;

    test_msg.fileio_read_resp.contents[128] = 217;

    test_msg.fileio_read_resp.contents[129] = 79;

    test_msg.fileio_read_resp.contents[130] = 10;

    test_msg.fileio_read_resp.contents[131] = 189;

    test_msg.fileio_read_resp.contents[132] = 128;

    test_msg.fileio_read_resp.contents[133] = 189;

    test_msg.fileio_read_resp.contents[134] = 2;

    test_msg.fileio_read_resp.contents[135] = 240;

    test_msg.fileio_read_resp.contents[136] = 92;

    test_msg.fileio_read_resp.contents[137] = 28;

    test_msg.fileio_read_resp.contents[138] = 126;

    test_msg.fileio_read_resp.contents[139] = 105;

    test_msg.fileio_read_resp.contents[140] = 236;

    test_msg.fileio_read_resp.contents[141] = 228;

    test_msg.fileio_read_resp.contents[142] = 194;

    test_msg.fileio_read_resp.contents[143] = 0;

    test_msg.fileio_read_resp.contents[144] = 51;

    test_msg.fileio_read_resp.contents[145] = 61;

    test_msg.fileio_read_resp.contents[146] = 74;

    test_msg.fileio_read_resp.contents[147] = 41;

    test_msg.fileio_read_resp.contents[148] = 10;

    test_msg.fileio_read_resp.contents[149] = 239;

    test_msg.fileio_read_resp.contents[150] = 133;

    test_msg.fileio_read_resp.contents[151] = 106;

    test_msg.fileio_read_resp.contents[152] = 190;

    test_msg.fileio_read_resp.contents[153] = 30;

    test_msg.fileio_read_resp.contents[154] = 27;

    test_msg.fileio_read_resp.contents[155] = 3;

    test_msg.fileio_read_resp.contents[156] = 240;

    test_msg.fileio_read_resp.contents[157] = 205;

    test_msg.fileio_read_resp.contents[158] = 253;

    test_msg.fileio_read_resp.contents[159] = 113;

    test_msg.fileio_read_resp.contents[160] = 25;

    test_msg.fileio_read_resp.contents[161] = 28;

    test_msg.fileio_read_resp.contents[162] = 187;

    test_msg.fileio_read_resp.contents[163] = 81;

    test_msg.fileio_read_resp.contents[164] = 101;

    test_msg.fileio_read_resp.contents[165] = 216;

    test_msg.fileio_read_resp.contents[166] = 121;

    test_msg.fileio_read_resp.contents[167] = 41;

    test_msg.fileio_read_resp.contents[168] = 179;

    test_msg.fileio_read_resp.contents[169] = 120;

    test_msg.fileio_read_resp.contents[170] = 152;

    test_msg.fileio_read_resp.contents[171] = 18;

    test_msg.fileio_read_resp.contents[172] = 116;

    test_msg.fileio_read_resp.contents[173] = 53;

    test_msg.fileio_read_resp.contents[174] = 212;

    test_msg.fileio_read_resp.contents[175] = 100;

    test_msg.fileio_read_resp.contents[176] = 2;

    test_msg.fileio_read_resp.contents[177] = 114;

    test_msg.fileio_read_resp.contents[178] = 198;

    test_msg.fileio_read_resp.contents[179] = 200;

    test_msg.fileio_read_resp.contents[180] = 10;

    test_msg.fileio_read_resp.contents[181] = 147;

    test_msg.fileio_read_resp.contents[182] = 25;

    test_msg.fileio_read_resp.contents[183] = 33;

    test_msg.fileio_read_resp.contents[184] = 115;

    test_msg.fileio_read_resp.contents[185] = 208;

    test_msg.fileio_read_resp.contents[186] = 113;

    test_msg.fileio_read_resp.contents[187] = 60;

    test_msg.fileio_read_resp.contents[188] = 179;

    test_msg.fileio_read_resp.contents[189] = 183;

    test_msg.fileio_read_resp.contents[190] = 0;

    test_msg.fileio_read_resp.contents[191] = 41;

    test_msg.fileio_read_resp.contents[192] = 217;

    test_msg.fileio_read_resp.contents[193] = 206;

    test_msg.fileio_read_resp.contents[194] = 255;

    test_msg.fileio_read_resp.contents[195] = 211;

    test_msg.fileio_read_resp.contents[196] = 225;

    test_msg.fileio_read_resp.contents[197] = 142;

    test_msg.fileio_read_resp.contents[198] = 191;

    test_msg.fileio_read_resp.contents[199] = 133;

    test_msg.fileio_read_resp.contents[200] = 81;

    test_msg.fileio_read_resp.contents[201] = 15;

    test_msg.fileio_read_resp.contents[202] = 248;

    test_msg.fileio_read_resp.contents[203] = 193;

    test_msg.fileio_read_resp.contents[204] = 66;

    test_msg.fileio_read_resp.contents[205] = 191;

    test_msg.fileio_read_resp.contents[206] = 244;

    test_msg.fileio_read_resp.contents[207] = 221;

    test_msg.fileio_read_resp.contents[208] = 248;

    test_msg.fileio_read_resp.contents[209] = 199;

    test_msg.fileio_read_resp.contents[210] = 241;

    test_msg.fileio_read_resp.contents[211] = 112;

    test_msg.fileio_read_resp.contents[212] = 51;

    test_msg.fileio_read_resp.contents[213] = 1;

    test_msg.fileio_read_resp.contents[214] = 180;

    test_msg.fileio_read_resp.contents[215] = 180;

    test_msg.fileio_read_resp.contents[216] = 125;

    test_msg.fileio_read_resp.contents[217] = 97;

    test_msg.fileio_read_resp.contents[218] = 145;

    test_msg.fileio_read_resp.contents[219] = 25;

    test_msg.fileio_read_resp.contents[220] = 72;

    test_msg.fileio_read_resp.contents[221] = 210;

    test_msg.fileio_read_resp.contents[222] = 215;

    test_msg.fileio_read_resp.contents[223] = 208;

    test_msg.fileio_read_resp.contents[224] = 15;

    test_msg.fileio_read_resp.contents[225] = 126;

    test_msg.fileio_read_resp.contents[226] = 56;

    test_msg.fileio_read_resp.contents[227] = 38;

    test_msg.fileio_read_resp.contents[228] = 65;

    test_msg.fileio_read_resp.contents[229] = 4;

    test_msg.fileio_read_resp.contents[230] = 64;

    test_msg.fileio_read_resp.contents[231] = 19;

    test_msg.fileio_read_resp.contents[232] = 74;

    test_msg.fileio_read_resp.contents[233] = 223;

    test_msg.fileio_read_resp.contents[234] = 111;

    test_msg.fileio_read_resp.contents[235] = 109;

    test_msg.fileio_read_resp.contents[236] = 52;

    test_msg.fileio_read_resp.contents[237] = 43;

    test_msg.fileio_read_resp.contents[238] = 167;

    test_msg.fileio_read_resp.contents[239] = 186;

    test_msg.fileio_read_resp.contents[240] = 202;

    test_msg.fileio_read_resp.contents[241] = 111;

    test_msg.fileio_read_resp.contents[242] = 11;

    test_msg.fileio_read_resp.contents[243] = 91;

    test_msg.fileio_read_resp.contents[244] = 21;

    test_msg.fileio_read_resp.contents[245] = 236;

    test_msg.fileio_read_resp.contents[246] = 234;

    test_msg.fileio_read_resp.contents[247] = 196;

    test_msg.fileio_read_resp.contents[248] = 36;

    test_msg.fileio_read_resp.contents[249] = 171;

    test_msg.fileio_read_resp.contents[250] = 147;

    test_msg.fileio_read_resp.n_contents = 251;

    test_msg.fileio_read_resp.sequence = 259241795;

    sbp_message_send(&sbp_state, SbpMsgFileioReadResp, 1219, &test_msg,
                     &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgFileioReadResp, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[0], 73)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[0], "
           "expected 73, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[0];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[1], 231)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[1], "
           "expected 231, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[1];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[2], 227)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[2], "
           "expected 227, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[2];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[3], 179)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[3], "
           "expected 179, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[3];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[4], 18)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[4], "
           "expected 18, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[4];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[5], 76)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[5], "
           "expected 76, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[5];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[6], 68)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[6], "
           "expected 68, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[6];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[7], 229)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[7], "
           "expected 229, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[7];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[8], 216)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[8], "
           "expected 216, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[8];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[9], 21)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[9], "
           "expected 21, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[9];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[10], 98)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[10], "
           "expected 98, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[10];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[11], 183)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[11], "
           "expected 183, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[11];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[12], 69)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[12], "
           "expected 69, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[12];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[13], 190)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[13], "
           "expected 190, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[13];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[14], 5)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[14], "
           "expected 5, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[14];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[15], 252)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[15], "
           "expected 252, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[15];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[16], 176)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[16], "
           "expected 176, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[16];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[17], 55)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[17], "
           "expected 55, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[17];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[18], 32)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[18], "
           "expected 32, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[18];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[19], 78)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[19], "
           "expected 78, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[19];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[20], 8)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[20], "
           "expected 8, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[20];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[21], 52)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[21], "
           "expected 52, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[21];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[22], 127)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[22], "
           "expected 127, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[22];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[23], 50)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[23], "
           "expected 50, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[23];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[24], 71)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[24], "
           "expected 71, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[24];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[25], 106)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[25], "
           "expected 106, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[25];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[26], 61)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[26], "
           "expected 61, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[26];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[27], 79)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[27], "
           "expected 79, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[27];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[28], 191)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[28], "
           "expected 191, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[28];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[29], 106)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[29], "
           "expected 106, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[29];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[30], 46)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[30], "
           "expected 46, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[30];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[31], 79)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[31], "
           "expected 79, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[31];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[32], 118)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[32], "
           "expected 118, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[32];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[33], 248)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[33], "
           "expected 248, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[33];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[34], 118)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[34], "
           "expected 118, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[34];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[35], 207)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[35], "
           "expected 207, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[35];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[36], 206)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[36], "
           "expected 206, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[36];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[37], 210)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[37], "
           "expected 210, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[37];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[38], 91)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[38], "
           "expected 91, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[38];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[39], 73)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[39], "
           "expected 73, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[39];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[40], 251)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[40], "
           "expected 251, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[40];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[41], 81)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[41], "
           "expected 81, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[41];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[42], 131)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[42], "
           "expected 131, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[42];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[43], 205)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[43], "
           "expected 205, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[43];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[44], 193)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[44], "
           "expected 193, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[44];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[45], 146)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[45], "
           "expected 146, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[45];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[46], 206)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[46], "
           "expected 206, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[46];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[47], 185)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[47], "
           "expected 185, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[47];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[48], 140)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[48], "
           "expected 140, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[48];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[49], 249)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[49], "
           "expected 249, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[49];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[50], 163)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[50], "
           "expected 163, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[50];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[51], 231)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[51], "
           "expected 231, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[51];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[52], 65)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[52], "
           "expected 65, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[52];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[53], 67)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[53], "
           "expected 67, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[53];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[54], 94)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[54], "
           "expected 94, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[54];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[55], 250)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[55], "
           "expected 250, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[55];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[56], 109)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[56], "
           "expected 109, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[56];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[57], 152)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[57], "
           "expected 152, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[57];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[58], 95)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[58], "
           "expected 95, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[58];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[59], 123)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[59], "
           "expected 123, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[59];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[60], 77)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[60], "
           "expected 77, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[60];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[61], 224)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[61], "
           "expected 224, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[61];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[62], 124)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[62], "
           "expected 124, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[62];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[63], 238)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[63], "
           "expected 238, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[63];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[64], 205)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[64], "
           "expected 205, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[64];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[65], 65)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[65], "
           "expected 65, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[65];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[66], 103)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[66], "
           "expected 103, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[66];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[67], 35)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[67], "
           "expected 35, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[67];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[68], 104)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[68], "
           "expected 104, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[68];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[69], 209)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[69], "
           "expected 209, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[69];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[70], 5)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[70], "
           "expected 5, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[70];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[71], 191)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[71], "
           "expected 191, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[71];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[72], 47)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[72], "
           "expected 47, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[72];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[73], 249)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[73], "
           "expected 249, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[73];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[74], 176)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[74], "
           "expected 176, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[74];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[75], 166)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[75], "
           "expected 166, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[75];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[76], 213)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[76], "
           "expected 213, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[76];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[77], 46)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[77], "
           "expected 46, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[77];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[78], 192)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[78], "
           "expected 192, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[78];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[79], 86)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[79], "
           "expected 86, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[79];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[80], 32)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[80], "
           "expected 32, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[80];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[81], 103)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[81], "
           "expected 103, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[81];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[82], 146)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[82], "
           "expected 146, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[82];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[83], 252)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[83], "
           "expected 252, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[83];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[84], 4)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[84], "
           "expected 4, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[84];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[85], 16)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[85], "
           "expected 16, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[85];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[86], 54)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[86], "
           "expected 54, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[86];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[87], 161)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[87], "
           "expected 161, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[87];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[88], 60)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[88], "
           "expected 60, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[88];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[89], 6)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[89], "
           "expected 6, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[89];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[90], 13)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[90], "
           "expected 13, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[90];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[91], 191)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[91], "
           "expected 191, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[91];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[92], 116)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[92], "
           "expected 116, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[92];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[93], 182)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[93], "
           "expected 182, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[93];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[94], 42)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[94], "
           "expected 42, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[94];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[95], 191)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[95], "
           "expected 191, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[95];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[96], 213)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[96], "
           "expected 213, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[96];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[97], 20)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[97], "
           "expected 20, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[97];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[98], 217)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[98], "
           "expected 217, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[98];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[99], 8)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[99], "
           "expected 8, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[99];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[100], 142)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[100], "
           "expected 142, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[100];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[101], 187)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[101], "
           "expected 187, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[101];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[102], 238)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[102], "
           "expected 238, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[102];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[103], 120)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[103], "
           "expected 120, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[103];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[104], 184)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[104], "
           "expected 184, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[104];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[105], 250)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[105], "
           "expected 250, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[105];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[106], 31)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[106], "
           "expected 31, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[106];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[107], 151)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[107], "
           "expected 151, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[107];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[108], 37)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[108], "
           "expected 37, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[108];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[109], 51)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[109], "
           "expected 51, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[109];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[110], 177)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[110], "
           "expected 177, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[110];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[111], 130)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[111], "
           "expected 130, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[111];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[112], 190)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[112], "
           "expected 190, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[112];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[113], 155)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[113], "
           "expected 155, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[113];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[114], 71)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[114], "
           "expected 71, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[114];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[115], 68)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[115], "
           "expected 68, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[115];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[116], 56)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[116], "
           "expected 56, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[116];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[117], 238)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[117], "
           "expected 238, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[117];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[118], 92)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[118], "
           "expected 92, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[118];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[119], 130)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[119], "
           "expected 130, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[119];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[120], 37)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[120], "
           "expected 37, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[120];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[121], 137)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[121], "
           "expected 137, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[121];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[122], 146)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[122], "
           "expected 146, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[122];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[123], 246)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[123], "
           "expected 246, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[123];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[124], 114)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[124], "
           "expected 114, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[124];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[125], 116)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[125], "
           "expected 116, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[125];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[126], 138)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[126], "
           "expected 138, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[126];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[127], 165)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[127], "
           "expected 165, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[127];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[128], 217)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[128], "
           "expected 217, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[128];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[129], 79)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[129], "
           "expected 79, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[129];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[130], 10)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[130], "
           "expected 10, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[130];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[131], 189)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[131], "
           "expected 189, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[131];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[132], 128)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[132], "
           "expected 128, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[132];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[133], 189)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[133], "
           "expected 189, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[133];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[134], 2)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[134], "
           "expected 2, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[134];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[135], 240)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[135], "
           "expected 240, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[135];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[136], 92)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[136], "
           "expected 92, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[136];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[137], 28)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[137], "
           "expected 28, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[137];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[138], 126)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[138], "
           "expected 126, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[138];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[139], 105)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[139], "
           "expected 105, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[139];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[140], 236)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[140], "
           "expected 236, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[140];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[141], 228)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[141], "
           "expected 228, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[141];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[142], 194)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[142], "
           "expected 194, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[142];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[143], 0)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[143], "
           "expected 0, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[143];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[144], 51)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[144], "
           "expected 51, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[144];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[145], 61)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[145], "
           "expected 61, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[145];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[146], 74)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[146], "
           "expected 74, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[146];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[147], 41)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[147], "
           "expected 41, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[147];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[148], 10)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[148], "
           "expected 10, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[148];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[149], 239)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[149], "
           "expected 239, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[149];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[150], 133)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[150], "
           "expected 133, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[150];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[151], 106)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[151], "
           "expected 106, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[151];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[152], 190)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[152], "
           "expected 190, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[152];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[153], 30)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[153], "
           "expected 30, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[153];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[154], 27)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[154], "
           "expected 27, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[154];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[155], 3)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[155], "
           "expected 3, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[155];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[156], 240)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[156], "
           "expected 240, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[156];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[157], 205)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[157], "
           "expected 205, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[157];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[158], 253)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[158], "
           "expected 253, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[158];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[159], 113)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[159], "
           "expected 113, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[159];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[160], 25)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[160], "
           "expected 25, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[160];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[161], 28)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[161], "
           "expected 28, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[161];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[162], 187)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[162], "
           "expected 187, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[162];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[163], 81)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[163], "
           "expected 81, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[163];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[164], 101)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[164], "
           "expected 101, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[164];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[165], 216)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[165], "
           "expected 216, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[165];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[166], 121)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[166], "
           "expected 121, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[166];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[167], 41)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[167], "
           "expected 41, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[167];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[168], 179)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[168], "
           "expected 179, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[168];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[169], 120)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[169], "
           "expected 120, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[169];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[170], 152)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[170], "
           "expected 152, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[170];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[171], 18)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[171], "
           "expected 18, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[171];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[172], 116)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[172], "
           "expected 116, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[172];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[173], 53)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[173], "
           "expected 53, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[173];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[174], 212)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[174], "
           "expected 212, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[174];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[175], 100)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[175], "
           "expected 100, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[175];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[176], 2)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[176], "
           "expected 2, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[176];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[177], 114)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[177], "
           "expected 114, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[177];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[178], 198)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[178], "
           "expected 198, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[178];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[179], 200)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[179], "
           "expected 200, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[179];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[180], 10)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[180], "
           "expected 10, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[180];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[181], 147)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[181], "
           "expected 147, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[181];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[182], 25)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[182], "
           "expected 25, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[182];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[183], 33)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[183], "
           "expected 33, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[183];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[184], 115)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[184], "
           "expected 115, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[184];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[185], 208)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[185], "
           "expected 208, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[185];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[186], 113)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[186], "
           "expected 113, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[186];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[187], 60)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[187], "
           "expected 60, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[187];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[188], 179)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[188], "
           "expected 179, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[188];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[189], 183)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[189], "
           "expected 183, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[189];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[190], 0)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[190], "
           "expected 0, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[190];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[191], 41)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[191], "
           "expected 41, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[191];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[192], 217)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[192], "
           "expected 217, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[192];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[193], 206)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[193], "
           "expected 206, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[193];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[194], 255)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[194], "
           "expected 255, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[194];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[195], 211)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[195], "
           "expected 211, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[195];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[196], 225)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[196], "
           "expected 225, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[196];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[197], 142)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[197], "
           "expected 142, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[197];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[198], 191)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[198], "
           "expected 191, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[198];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[199], 133)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[199], "
           "expected 133, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[199];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[200], 81)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[200], "
           "expected 81, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[200];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[201], 15)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[201], "
           "expected 15, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[201];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[202], 248)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[202], "
           "expected 248, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[202];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[203], 193)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[203], "
           "expected 193, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[203];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[204], 66)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[204], "
           "expected 66, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[204];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[205], 191)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[205], "
           "expected 191, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[205];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[206], 244)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[206], "
           "expected 244, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[206];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[207], 221)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[207], "
           "expected 221, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[207];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[208], 248)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[208], "
           "expected 248, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[208];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[209], 199)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[209], "
           "expected 199, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[209];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[210], 241)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[210], "
           "expected 241, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[210];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[211], 112)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[211], "
           "expected 112, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[211];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[212], 51)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[212], "
           "expected 51, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[212];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[213], 1)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[213], "
           "expected 1, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[213];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[214], 180)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[214], "
           "expected 180, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[214];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[215], 180)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[215], "
           "expected 180, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[215];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[216], 125)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[216], "
           "expected 125, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[216];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[217], 97)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[217], "
           "expected 97, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[217];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[218], 145)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[218], "
           "expected 145, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[218];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[219], 25)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[219], "
           "expected 25, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[219];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[220], 72)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[220], "
           "expected 72, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[220];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[221], 210)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[221], "
           "expected 210, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[221];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[222], 215)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[222], "
           "expected 215, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[222];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[223], 208)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[223], "
           "expected 208, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[223];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[224], 15)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[224], "
           "expected 15, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[224];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[225], 126)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[225], "
           "expected 126, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[225];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[226], 56)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[226], "
           "expected 56, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[226];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[227], 38)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[227], "
           "expected 38, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[227];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[228], 65)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[228], "
           "expected 65, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[228];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[229], 4)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[229], "
           "expected 4, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[229];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[230], 64)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[230], "
           "expected 64, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[230];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[231], 19)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[231], "
           "expected 19, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[231];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[232], 74)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[232], "
           "expected 74, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[232];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[233], 223)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[233], "
           "expected 223, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[233];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[234], 111)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[234], "
           "expected 111, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[234];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[235], 109)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[235], "
           "expected 109, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[235];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[236], 52)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[236], "
           "expected 52, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[236];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[237], 43)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[237], "
           "expected 43, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[237];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[238], 167)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[238], "
           "expected 167, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[238];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[239], 186)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[239], "
           "expected 186, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[239];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[240], 202)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[240], "
           "expected 202, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[240];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[241], 111)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[241], "
           "expected 111, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[241];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[242], 11)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[242], "
           "expected 11, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[242];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[243], 91)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[243], "
           "expected 91, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[243];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[244], 21)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[244], "
           "expected 21, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[244];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[245], 236)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[245], "
           "expected 236, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[245];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[246], 234)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[246], "
           "expected 234, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[246];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[247], 196)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[247], "
           "expected 196, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[247];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[248], 36)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[248], "
           "expected 36, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[248];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[249], 171)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[249], "
           "expected 171, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[249];
    EXPECT_EQ(last_msg.msg.fileio_read_resp.contents[250], 147)
        << "incorrect value for last_msg.msg.fileio_read_resp.contents[250], "
           "expected 147, is "
        << (int64_t)last_msg.msg.fileio_read_resp.contents[250];

    EXPECT_EQ(last_msg.msg.fileio_read_resp.n_contents, 251)
        << "incorrect value for last_msg.msg.fileio_read_resp.n_contents, "
           "expected 251, is "
        << (int64_t)last_msg.msg.fileio_read_resp.n_contents;

    EXPECT_EQ(last_msg.msg.fileio_read_resp.sequence, 259241795)
        << "incorrect value for last_msg.msg.fileio_read_resp.sequence, "
           "expected 259241795, is "
        << (int64_t)last_msg.msg.fileio_read_resp.sequence;
  }
}

}  // namespace
