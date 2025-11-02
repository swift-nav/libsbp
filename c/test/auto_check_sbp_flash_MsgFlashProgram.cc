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
// spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashProgram.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/flash.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_flash_MsgFlashProgram,
     test_auto_check_sbp_flash_MsgFlashProgram) {
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

    sbp_callback_register(&sbp_state, SbpMsgFlashProgram, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  230, 0,   195, 4,   255, 212, 87,  52,  244, 250, 176, 222, 235,
        106, 144, 29,  141, 255, 3,   16,  192, 237, 172, 254, 213, 4,   220,
        98,  34,  222, 230, 214, 6,   217, 172, 122, 46,  13,  38,  240, 236,
        60,  121, 47,  252, 163, 141, 222, 29,  168, 214, 118, 55,  201, 233,
        21,  214, 57,  245, 246, 19,  3,   121, 49,  231, 37,  186, 58,  238,
        98,  39,  70,  232, 133, 25,  10,  134, 129, 69,  228, 134, 9,   88,
        183, 133, 171, 255, 166, 100, 152, 231, 92,  9,   196, 106, 246, 29,
        145, 156, 151, 32,  67,  188, 63,  233, 142, 174, 139, 154, 127, 35,
        60,  56,  187, 121, 103, 135, 152, 182, 88,  160, 255, 227, 240, 54,
        100, 91,  31,  141, 102, 130, 254, 54,  227, 229, 62,  53,  225, 143,
        88,  139, 126, 235, 235, 35,  54,  134, 163, 92,  57,  87,  130, 178,
        22,  158, 18,  237, 209, 187, 226, 1,   46,  64,  226, 235, 213, 186,
        159, 221, 186, 25,  115, 84,  131, 167, 201, 104, 1,   200, 13,  50,
        71,  73,  193, 201, 250, 172, 193, 13,  20,  238, 130, 243, 68,  4,
        72,  46,  194, 113, 255, 238, 15,  230, 64,  178, 127, 217, 92,  160,
        201, 118, 163, 144, 58,  28,  174, 65,  73,  45,  123, 118, 83,  107,
        239, 168, 32,  212, 191, 81,  93,  186, 223, 32,  19,  58,  137, 72,
        217, 151, 251, 83,  20,  113, 37,  151, 34,  37,  71,  95,  105, 235,
        144, 164, 83,  197, 254, 183, 223, 91,  19,  45,  227,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.flash_program.addr_len = 250;

    test_msg.flash_program.addr_start[0] = 87;

    test_msg.flash_program.addr_start[1] = 52;

    test_msg.flash_program.addr_start[2] = 244;

    test_msg.flash_program.data[0] = 176;

    test_msg.flash_program.data[1] = 222;

    test_msg.flash_program.data[2] = 235;

    test_msg.flash_program.data[3] = 106;

    test_msg.flash_program.data[4] = 144;

    test_msg.flash_program.data[5] = 29;

    test_msg.flash_program.data[6] = 141;

    test_msg.flash_program.data[7] = 255;

    test_msg.flash_program.data[8] = 3;

    test_msg.flash_program.data[9] = 16;

    test_msg.flash_program.data[10] = 192;

    test_msg.flash_program.data[11] = 237;

    test_msg.flash_program.data[12] = 172;

    test_msg.flash_program.data[13] = 254;

    test_msg.flash_program.data[14] = 213;

    test_msg.flash_program.data[15] = 4;

    test_msg.flash_program.data[16] = 220;

    test_msg.flash_program.data[17] = 98;

    test_msg.flash_program.data[18] = 34;

    test_msg.flash_program.data[19] = 222;

    test_msg.flash_program.data[20] = 230;

    test_msg.flash_program.data[21] = 214;

    test_msg.flash_program.data[22] = 6;

    test_msg.flash_program.data[23] = 217;

    test_msg.flash_program.data[24] = 172;

    test_msg.flash_program.data[25] = 122;

    test_msg.flash_program.data[26] = 46;

    test_msg.flash_program.data[27] = 13;

    test_msg.flash_program.data[28] = 38;

    test_msg.flash_program.data[29] = 240;

    test_msg.flash_program.data[30] = 236;

    test_msg.flash_program.data[31] = 60;

    test_msg.flash_program.data[32] = 121;

    test_msg.flash_program.data[33] = 47;

    test_msg.flash_program.data[34] = 252;

    test_msg.flash_program.data[35] = 163;

    test_msg.flash_program.data[36] = 141;

    test_msg.flash_program.data[37] = 222;

    test_msg.flash_program.data[38] = 29;

    test_msg.flash_program.data[39] = 168;

    test_msg.flash_program.data[40] = 214;

    test_msg.flash_program.data[41] = 118;

    test_msg.flash_program.data[42] = 55;

    test_msg.flash_program.data[43] = 201;

    test_msg.flash_program.data[44] = 233;

    test_msg.flash_program.data[45] = 21;

    test_msg.flash_program.data[46] = 214;

    test_msg.flash_program.data[47] = 57;

    test_msg.flash_program.data[48] = 245;

    test_msg.flash_program.data[49] = 246;

    test_msg.flash_program.data[50] = 19;

    test_msg.flash_program.data[51] = 3;

    test_msg.flash_program.data[52] = 121;

    test_msg.flash_program.data[53] = 49;

    test_msg.flash_program.data[54] = 231;

    test_msg.flash_program.data[55] = 37;

    test_msg.flash_program.data[56] = 186;

    test_msg.flash_program.data[57] = 58;

    test_msg.flash_program.data[58] = 238;

    test_msg.flash_program.data[59] = 98;

    test_msg.flash_program.data[60] = 39;

    test_msg.flash_program.data[61] = 70;

    test_msg.flash_program.data[62] = 232;

    test_msg.flash_program.data[63] = 133;

    test_msg.flash_program.data[64] = 25;

    test_msg.flash_program.data[65] = 10;

    test_msg.flash_program.data[66] = 134;

    test_msg.flash_program.data[67] = 129;

    test_msg.flash_program.data[68] = 69;

    test_msg.flash_program.data[69] = 228;

    test_msg.flash_program.data[70] = 134;

    test_msg.flash_program.data[71] = 9;

    test_msg.flash_program.data[72] = 88;

    test_msg.flash_program.data[73] = 183;

    test_msg.flash_program.data[74] = 133;

    test_msg.flash_program.data[75] = 171;

    test_msg.flash_program.data[76] = 255;

    test_msg.flash_program.data[77] = 166;

    test_msg.flash_program.data[78] = 100;

    test_msg.flash_program.data[79] = 152;

    test_msg.flash_program.data[80] = 231;

    test_msg.flash_program.data[81] = 92;

    test_msg.flash_program.data[82] = 9;

    test_msg.flash_program.data[83] = 196;

    test_msg.flash_program.data[84] = 106;

    test_msg.flash_program.data[85] = 246;

    test_msg.flash_program.data[86] = 29;

    test_msg.flash_program.data[87] = 145;

    test_msg.flash_program.data[88] = 156;

    test_msg.flash_program.data[89] = 151;

    test_msg.flash_program.data[90] = 32;

    test_msg.flash_program.data[91] = 67;

    test_msg.flash_program.data[92] = 188;

    test_msg.flash_program.data[93] = 63;

    test_msg.flash_program.data[94] = 233;

    test_msg.flash_program.data[95] = 142;

    test_msg.flash_program.data[96] = 174;

    test_msg.flash_program.data[97] = 139;

    test_msg.flash_program.data[98] = 154;

    test_msg.flash_program.data[99] = 127;

    test_msg.flash_program.data[100] = 35;

    test_msg.flash_program.data[101] = 60;

    test_msg.flash_program.data[102] = 56;

    test_msg.flash_program.data[103] = 187;

    test_msg.flash_program.data[104] = 121;

    test_msg.flash_program.data[105] = 103;

    test_msg.flash_program.data[106] = 135;

    test_msg.flash_program.data[107] = 152;

    test_msg.flash_program.data[108] = 182;

    test_msg.flash_program.data[109] = 88;

    test_msg.flash_program.data[110] = 160;

    test_msg.flash_program.data[111] = 255;

    test_msg.flash_program.data[112] = 227;

    test_msg.flash_program.data[113] = 240;

    test_msg.flash_program.data[114] = 54;

    test_msg.flash_program.data[115] = 100;

    test_msg.flash_program.data[116] = 91;

    test_msg.flash_program.data[117] = 31;

    test_msg.flash_program.data[118] = 141;

    test_msg.flash_program.data[119] = 102;

    test_msg.flash_program.data[120] = 130;

    test_msg.flash_program.data[121] = 254;

    test_msg.flash_program.data[122] = 54;

    test_msg.flash_program.data[123] = 227;

    test_msg.flash_program.data[124] = 229;

    test_msg.flash_program.data[125] = 62;

    test_msg.flash_program.data[126] = 53;

    test_msg.flash_program.data[127] = 225;

    test_msg.flash_program.data[128] = 143;

    test_msg.flash_program.data[129] = 88;

    test_msg.flash_program.data[130] = 139;

    test_msg.flash_program.data[131] = 126;

    test_msg.flash_program.data[132] = 235;

    test_msg.flash_program.data[133] = 235;

    test_msg.flash_program.data[134] = 35;

    test_msg.flash_program.data[135] = 54;

    test_msg.flash_program.data[136] = 134;

    test_msg.flash_program.data[137] = 163;

    test_msg.flash_program.data[138] = 92;

    test_msg.flash_program.data[139] = 57;

    test_msg.flash_program.data[140] = 87;

    test_msg.flash_program.data[141] = 130;

    test_msg.flash_program.data[142] = 178;

    test_msg.flash_program.data[143] = 22;

    test_msg.flash_program.data[144] = 158;

    test_msg.flash_program.data[145] = 18;

    test_msg.flash_program.data[146] = 237;

    test_msg.flash_program.data[147] = 209;

    test_msg.flash_program.data[148] = 187;

    test_msg.flash_program.data[149] = 226;

    test_msg.flash_program.data[150] = 1;

    test_msg.flash_program.data[151] = 46;

    test_msg.flash_program.data[152] = 64;

    test_msg.flash_program.data[153] = 226;

    test_msg.flash_program.data[154] = 235;

    test_msg.flash_program.data[155] = 213;

    test_msg.flash_program.data[156] = 186;

    test_msg.flash_program.data[157] = 159;

    test_msg.flash_program.data[158] = 221;

    test_msg.flash_program.data[159] = 186;

    test_msg.flash_program.data[160] = 25;

    test_msg.flash_program.data[161] = 115;

    test_msg.flash_program.data[162] = 84;

    test_msg.flash_program.data[163] = 131;

    test_msg.flash_program.data[164] = 167;

    test_msg.flash_program.data[165] = 201;

    test_msg.flash_program.data[166] = 104;

    test_msg.flash_program.data[167] = 1;

    test_msg.flash_program.data[168] = 200;

    test_msg.flash_program.data[169] = 13;

    test_msg.flash_program.data[170] = 50;

    test_msg.flash_program.data[171] = 71;

    test_msg.flash_program.data[172] = 73;

    test_msg.flash_program.data[173] = 193;

    test_msg.flash_program.data[174] = 201;

    test_msg.flash_program.data[175] = 250;

    test_msg.flash_program.data[176] = 172;

    test_msg.flash_program.data[177] = 193;

    test_msg.flash_program.data[178] = 13;

    test_msg.flash_program.data[179] = 20;

    test_msg.flash_program.data[180] = 238;

    test_msg.flash_program.data[181] = 130;

    test_msg.flash_program.data[182] = 243;

    test_msg.flash_program.data[183] = 68;

    test_msg.flash_program.data[184] = 4;

    test_msg.flash_program.data[185] = 72;

    test_msg.flash_program.data[186] = 46;

    test_msg.flash_program.data[187] = 194;

    test_msg.flash_program.data[188] = 113;

    test_msg.flash_program.data[189] = 255;

    test_msg.flash_program.data[190] = 238;

    test_msg.flash_program.data[191] = 15;

    test_msg.flash_program.data[192] = 230;

    test_msg.flash_program.data[193] = 64;

    test_msg.flash_program.data[194] = 178;

    test_msg.flash_program.data[195] = 127;

    test_msg.flash_program.data[196] = 217;

    test_msg.flash_program.data[197] = 92;

    test_msg.flash_program.data[198] = 160;

    test_msg.flash_program.data[199] = 201;

    test_msg.flash_program.data[200] = 118;

    test_msg.flash_program.data[201] = 163;

    test_msg.flash_program.data[202] = 144;

    test_msg.flash_program.data[203] = 58;

    test_msg.flash_program.data[204] = 28;

    test_msg.flash_program.data[205] = 174;

    test_msg.flash_program.data[206] = 65;

    test_msg.flash_program.data[207] = 73;

    test_msg.flash_program.data[208] = 45;

    test_msg.flash_program.data[209] = 123;

    test_msg.flash_program.data[210] = 118;

    test_msg.flash_program.data[211] = 83;

    test_msg.flash_program.data[212] = 107;

    test_msg.flash_program.data[213] = 239;

    test_msg.flash_program.data[214] = 168;

    test_msg.flash_program.data[215] = 32;

    test_msg.flash_program.data[216] = 212;

    test_msg.flash_program.data[217] = 191;

    test_msg.flash_program.data[218] = 81;

    test_msg.flash_program.data[219] = 93;

    test_msg.flash_program.data[220] = 186;

    test_msg.flash_program.data[221] = 223;

    test_msg.flash_program.data[222] = 32;

    test_msg.flash_program.data[223] = 19;

    test_msg.flash_program.data[224] = 58;

    test_msg.flash_program.data[225] = 137;

    test_msg.flash_program.data[226] = 72;

    test_msg.flash_program.data[227] = 217;

    test_msg.flash_program.data[228] = 151;

    test_msg.flash_program.data[229] = 251;

    test_msg.flash_program.data[230] = 83;

    test_msg.flash_program.data[231] = 20;

    test_msg.flash_program.data[232] = 113;

    test_msg.flash_program.data[233] = 37;

    test_msg.flash_program.data[234] = 151;

    test_msg.flash_program.data[235] = 34;

    test_msg.flash_program.data[236] = 37;

    test_msg.flash_program.data[237] = 71;

    test_msg.flash_program.data[238] = 95;

    test_msg.flash_program.data[239] = 105;

    test_msg.flash_program.data[240] = 235;

    test_msg.flash_program.data[241] = 144;

    test_msg.flash_program.data[242] = 164;

    test_msg.flash_program.data[243] = 83;

    test_msg.flash_program.data[244] = 197;

    test_msg.flash_program.data[245] = 254;

    test_msg.flash_program.data[246] = 183;

    test_msg.flash_program.data[247] = 223;

    test_msg.flash_program.data[248] = 91;

    test_msg.flash_program.data[249] = 19;

    test_msg.flash_program.target = 212;

    sbp_message_send(&sbp_state, SbpMsgFlashProgram, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgFlashProgram, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.flash_program.addr_len, 250)
        << "incorrect value for last_msg.msg.flash_program.addr_len, expected "
           "250, is "
        << (int64_t)last_msg.msg.flash_program.addr_len;

    EXPECT_EQ(last_msg.msg.flash_program.addr_start[0], 87)
        << "incorrect value for last_msg.msg.flash_program.addr_start[0], "
           "expected 87, is "
        << (int64_t)last_msg.msg.flash_program.addr_start[0];
    EXPECT_EQ(last_msg.msg.flash_program.addr_start[1], 52)
        << "incorrect value for last_msg.msg.flash_program.addr_start[1], "
           "expected 52, is "
        << (int64_t)last_msg.msg.flash_program.addr_start[1];
    EXPECT_EQ(last_msg.msg.flash_program.addr_start[2], 244)
        << "incorrect value for last_msg.msg.flash_program.addr_start[2], "
           "expected 244, is "
        << (int64_t)last_msg.msg.flash_program.addr_start[2];

    EXPECT_EQ(last_msg.msg.flash_program.data[0], 176)
        << "incorrect value for last_msg.msg.flash_program.data[0], expected "
           "176, is "
        << (int64_t)last_msg.msg.flash_program.data[0];
    EXPECT_EQ(last_msg.msg.flash_program.data[1], 222)
        << "incorrect value for last_msg.msg.flash_program.data[1], expected "
           "222, is "
        << (int64_t)last_msg.msg.flash_program.data[1];
    EXPECT_EQ(last_msg.msg.flash_program.data[2], 235)
        << "incorrect value for last_msg.msg.flash_program.data[2], expected "
           "235, is "
        << (int64_t)last_msg.msg.flash_program.data[2];
    EXPECT_EQ(last_msg.msg.flash_program.data[3], 106)
        << "incorrect value for last_msg.msg.flash_program.data[3], expected "
           "106, is "
        << (int64_t)last_msg.msg.flash_program.data[3];
    EXPECT_EQ(last_msg.msg.flash_program.data[4], 144)
        << "incorrect value for last_msg.msg.flash_program.data[4], expected "
           "144, is "
        << (int64_t)last_msg.msg.flash_program.data[4];
    EXPECT_EQ(last_msg.msg.flash_program.data[5], 29)
        << "incorrect value for last_msg.msg.flash_program.data[5], expected "
           "29, is "
        << (int64_t)last_msg.msg.flash_program.data[5];
    EXPECT_EQ(last_msg.msg.flash_program.data[6], 141)
        << "incorrect value for last_msg.msg.flash_program.data[6], expected "
           "141, is "
        << (int64_t)last_msg.msg.flash_program.data[6];
    EXPECT_EQ(last_msg.msg.flash_program.data[7], 255)
        << "incorrect value for last_msg.msg.flash_program.data[7], expected "
           "255, is "
        << (int64_t)last_msg.msg.flash_program.data[7];
    EXPECT_EQ(last_msg.msg.flash_program.data[8], 3)
        << "incorrect value for last_msg.msg.flash_program.data[8], expected "
           "3, is "
        << (int64_t)last_msg.msg.flash_program.data[8];
    EXPECT_EQ(last_msg.msg.flash_program.data[9], 16)
        << "incorrect value for last_msg.msg.flash_program.data[9], expected "
           "16, is "
        << (int64_t)last_msg.msg.flash_program.data[9];
    EXPECT_EQ(last_msg.msg.flash_program.data[10], 192)
        << "incorrect value for last_msg.msg.flash_program.data[10], expected "
           "192, is "
        << (int64_t)last_msg.msg.flash_program.data[10];
    EXPECT_EQ(last_msg.msg.flash_program.data[11], 237)
        << "incorrect value for last_msg.msg.flash_program.data[11], expected "
           "237, is "
        << (int64_t)last_msg.msg.flash_program.data[11];
    EXPECT_EQ(last_msg.msg.flash_program.data[12], 172)
        << "incorrect value for last_msg.msg.flash_program.data[12], expected "
           "172, is "
        << (int64_t)last_msg.msg.flash_program.data[12];
    EXPECT_EQ(last_msg.msg.flash_program.data[13], 254)
        << "incorrect value for last_msg.msg.flash_program.data[13], expected "
           "254, is "
        << (int64_t)last_msg.msg.flash_program.data[13];
    EXPECT_EQ(last_msg.msg.flash_program.data[14], 213)
        << "incorrect value for last_msg.msg.flash_program.data[14], expected "
           "213, is "
        << (int64_t)last_msg.msg.flash_program.data[14];
    EXPECT_EQ(last_msg.msg.flash_program.data[15], 4)
        << "incorrect value for last_msg.msg.flash_program.data[15], expected "
           "4, is "
        << (int64_t)last_msg.msg.flash_program.data[15];
    EXPECT_EQ(last_msg.msg.flash_program.data[16], 220)
        << "incorrect value for last_msg.msg.flash_program.data[16], expected "
           "220, is "
        << (int64_t)last_msg.msg.flash_program.data[16];
    EXPECT_EQ(last_msg.msg.flash_program.data[17], 98)
        << "incorrect value for last_msg.msg.flash_program.data[17], expected "
           "98, is "
        << (int64_t)last_msg.msg.flash_program.data[17];
    EXPECT_EQ(last_msg.msg.flash_program.data[18], 34)
        << "incorrect value for last_msg.msg.flash_program.data[18], expected "
           "34, is "
        << (int64_t)last_msg.msg.flash_program.data[18];
    EXPECT_EQ(last_msg.msg.flash_program.data[19], 222)
        << "incorrect value for last_msg.msg.flash_program.data[19], expected "
           "222, is "
        << (int64_t)last_msg.msg.flash_program.data[19];
    EXPECT_EQ(last_msg.msg.flash_program.data[20], 230)
        << "incorrect value for last_msg.msg.flash_program.data[20], expected "
           "230, is "
        << (int64_t)last_msg.msg.flash_program.data[20];
    EXPECT_EQ(last_msg.msg.flash_program.data[21], 214)
        << "incorrect value for last_msg.msg.flash_program.data[21], expected "
           "214, is "
        << (int64_t)last_msg.msg.flash_program.data[21];
    EXPECT_EQ(last_msg.msg.flash_program.data[22], 6)
        << "incorrect value for last_msg.msg.flash_program.data[22], expected "
           "6, is "
        << (int64_t)last_msg.msg.flash_program.data[22];
    EXPECT_EQ(last_msg.msg.flash_program.data[23], 217)
        << "incorrect value for last_msg.msg.flash_program.data[23], expected "
           "217, is "
        << (int64_t)last_msg.msg.flash_program.data[23];
    EXPECT_EQ(last_msg.msg.flash_program.data[24], 172)
        << "incorrect value for last_msg.msg.flash_program.data[24], expected "
           "172, is "
        << (int64_t)last_msg.msg.flash_program.data[24];
    EXPECT_EQ(last_msg.msg.flash_program.data[25], 122)
        << "incorrect value for last_msg.msg.flash_program.data[25], expected "
           "122, is "
        << (int64_t)last_msg.msg.flash_program.data[25];
    EXPECT_EQ(last_msg.msg.flash_program.data[26], 46)
        << "incorrect value for last_msg.msg.flash_program.data[26], expected "
           "46, is "
        << (int64_t)last_msg.msg.flash_program.data[26];
    EXPECT_EQ(last_msg.msg.flash_program.data[27], 13)
        << "incorrect value for last_msg.msg.flash_program.data[27], expected "
           "13, is "
        << (int64_t)last_msg.msg.flash_program.data[27];
    EXPECT_EQ(last_msg.msg.flash_program.data[28], 38)
        << "incorrect value for last_msg.msg.flash_program.data[28], expected "
           "38, is "
        << (int64_t)last_msg.msg.flash_program.data[28];
    EXPECT_EQ(last_msg.msg.flash_program.data[29], 240)
        << "incorrect value for last_msg.msg.flash_program.data[29], expected "
           "240, is "
        << (int64_t)last_msg.msg.flash_program.data[29];
    EXPECT_EQ(last_msg.msg.flash_program.data[30], 236)
        << "incorrect value for last_msg.msg.flash_program.data[30], expected "
           "236, is "
        << (int64_t)last_msg.msg.flash_program.data[30];
    EXPECT_EQ(last_msg.msg.flash_program.data[31], 60)
        << "incorrect value for last_msg.msg.flash_program.data[31], expected "
           "60, is "
        << (int64_t)last_msg.msg.flash_program.data[31];
    EXPECT_EQ(last_msg.msg.flash_program.data[32], 121)
        << "incorrect value for last_msg.msg.flash_program.data[32], expected "
           "121, is "
        << (int64_t)last_msg.msg.flash_program.data[32];
    EXPECT_EQ(last_msg.msg.flash_program.data[33], 47)
        << "incorrect value for last_msg.msg.flash_program.data[33], expected "
           "47, is "
        << (int64_t)last_msg.msg.flash_program.data[33];
    EXPECT_EQ(last_msg.msg.flash_program.data[34], 252)
        << "incorrect value for last_msg.msg.flash_program.data[34], expected "
           "252, is "
        << (int64_t)last_msg.msg.flash_program.data[34];
    EXPECT_EQ(last_msg.msg.flash_program.data[35], 163)
        << "incorrect value for last_msg.msg.flash_program.data[35], expected "
           "163, is "
        << (int64_t)last_msg.msg.flash_program.data[35];
    EXPECT_EQ(last_msg.msg.flash_program.data[36], 141)
        << "incorrect value for last_msg.msg.flash_program.data[36], expected "
           "141, is "
        << (int64_t)last_msg.msg.flash_program.data[36];
    EXPECT_EQ(last_msg.msg.flash_program.data[37], 222)
        << "incorrect value for last_msg.msg.flash_program.data[37], expected "
           "222, is "
        << (int64_t)last_msg.msg.flash_program.data[37];
    EXPECT_EQ(last_msg.msg.flash_program.data[38], 29)
        << "incorrect value for last_msg.msg.flash_program.data[38], expected "
           "29, is "
        << (int64_t)last_msg.msg.flash_program.data[38];
    EXPECT_EQ(last_msg.msg.flash_program.data[39], 168)
        << "incorrect value for last_msg.msg.flash_program.data[39], expected "
           "168, is "
        << (int64_t)last_msg.msg.flash_program.data[39];
    EXPECT_EQ(last_msg.msg.flash_program.data[40], 214)
        << "incorrect value for last_msg.msg.flash_program.data[40], expected "
           "214, is "
        << (int64_t)last_msg.msg.flash_program.data[40];
    EXPECT_EQ(last_msg.msg.flash_program.data[41], 118)
        << "incorrect value for last_msg.msg.flash_program.data[41], expected "
           "118, is "
        << (int64_t)last_msg.msg.flash_program.data[41];
    EXPECT_EQ(last_msg.msg.flash_program.data[42], 55)
        << "incorrect value for last_msg.msg.flash_program.data[42], expected "
           "55, is "
        << (int64_t)last_msg.msg.flash_program.data[42];
    EXPECT_EQ(last_msg.msg.flash_program.data[43], 201)
        << "incorrect value for last_msg.msg.flash_program.data[43], expected "
           "201, is "
        << (int64_t)last_msg.msg.flash_program.data[43];
    EXPECT_EQ(last_msg.msg.flash_program.data[44], 233)
        << "incorrect value for last_msg.msg.flash_program.data[44], expected "
           "233, is "
        << (int64_t)last_msg.msg.flash_program.data[44];
    EXPECT_EQ(last_msg.msg.flash_program.data[45], 21)
        << "incorrect value for last_msg.msg.flash_program.data[45], expected "
           "21, is "
        << (int64_t)last_msg.msg.flash_program.data[45];
    EXPECT_EQ(last_msg.msg.flash_program.data[46], 214)
        << "incorrect value for last_msg.msg.flash_program.data[46], expected "
           "214, is "
        << (int64_t)last_msg.msg.flash_program.data[46];
    EXPECT_EQ(last_msg.msg.flash_program.data[47], 57)
        << "incorrect value for last_msg.msg.flash_program.data[47], expected "
           "57, is "
        << (int64_t)last_msg.msg.flash_program.data[47];
    EXPECT_EQ(last_msg.msg.flash_program.data[48], 245)
        << "incorrect value for last_msg.msg.flash_program.data[48], expected "
           "245, is "
        << (int64_t)last_msg.msg.flash_program.data[48];
    EXPECT_EQ(last_msg.msg.flash_program.data[49], 246)
        << "incorrect value for last_msg.msg.flash_program.data[49], expected "
           "246, is "
        << (int64_t)last_msg.msg.flash_program.data[49];
    EXPECT_EQ(last_msg.msg.flash_program.data[50], 19)
        << "incorrect value for last_msg.msg.flash_program.data[50], expected "
           "19, is "
        << (int64_t)last_msg.msg.flash_program.data[50];
    EXPECT_EQ(last_msg.msg.flash_program.data[51], 3)
        << "incorrect value for last_msg.msg.flash_program.data[51], expected "
           "3, is "
        << (int64_t)last_msg.msg.flash_program.data[51];
    EXPECT_EQ(last_msg.msg.flash_program.data[52], 121)
        << "incorrect value for last_msg.msg.flash_program.data[52], expected "
           "121, is "
        << (int64_t)last_msg.msg.flash_program.data[52];
    EXPECT_EQ(last_msg.msg.flash_program.data[53], 49)
        << "incorrect value for last_msg.msg.flash_program.data[53], expected "
           "49, is "
        << (int64_t)last_msg.msg.flash_program.data[53];
    EXPECT_EQ(last_msg.msg.flash_program.data[54], 231)
        << "incorrect value for last_msg.msg.flash_program.data[54], expected "
           "231, is "
        << (int64_t)last_msg.msg.flash_program.data[54];
    EXPECT_EQ(last_msg.msg.flash_program.data[55], 37)
        << "incorrect value for last_msg.msg.flash_program.data[55], expected "
           "37, is "
        << (int64_t)last_msg.msg.flash_program.data[55];
    EXPECT_EQ(last_msg.msg.flash_program.data[56], 186)
        << "incorrect value for last_msg.msg.flash_program.data[56], expected "
           "186, is "
        << (int64_t)last_msg.msg.flash_program.data[56];
    EXPECT_EQ(last_msg.msg.flash_program.data[57], 58)
        << "incorrect value for last_msg.msg.flash_program.data[57], expected "
           "58, is "
        << (int64_t)last_msg.msg.flash_program.data[57];
    EXPECT_EQ(last_msg.msg.flash_program.data[58], 238)
        << "incorrect value for last_msg.msg.flash_program.data[58], expected "
           "238, is "
        << (int64_t)last_msg.msg.flash_program.data[58];
    EXPECT_EQ(last_msg.msg.flash_program.data[59], 98)
        << "incorrect value for last_msg.msg.flash_program.data[59], expected "
           "98, is "
        << (int64_t)last_msg.msg.flash_program.data[59];
    EXPECT_EQ(last_msg.msg.flash_program.data[60], 39)
        << "incorrect value for last_msg.msg.flash_program.data[60], expected "
           "39, is "
        << (int64_t)last_msg.msg.flash_program.data[60];
    EXPECT_EQ(last_msg.msg.flash_program.data[61], 70)
        << "incorrect value for last_msg.msg.flash_program.data[61], expected "
           "70, is "
        << (int64_t)last_msg.msg.flash_program.data[61];
    EXPECT_EQ(last_msg.msg.flash_program.data[62], 232)
        << "incorrect value for last_msg.msg.flash_program.data[62], expected "
           "232, is "
        << (int64_t)last_msg.msg.flash_program.data[62];
    EXPECT_EQ(last_msg.msg.flash_program.data[63], 133)
        << "incorrect value for last_msg.msg.flash_program.data[63], expected "
           "133, is "
        << (int64_t)last_msg.msg.flash_program.data[63];
    EXPECT_EQ(last_msg.msg.flash_program.data[64], 25)
        << "incorrect value for last_msg.msg.flash_program.data[64], expected "
           "25, is "
        << (int64_t)last_msg.msg.flash_program.data[64];
    EXPECT_EQ(last_msg.msg.flash_program.data[65], 10)
        << "incorrect value for last_msg.msg.flash_program.data[65], expected "
           "10, is "
        << (int64_t)last_msg.msg.flash_program.data[65];
    EXPECT_EQ(last_msg.msg.flash_program.data[66], 134)
        << "incorrect value for last_msg.msg.flash_program.data[66], expected "
           "134, is "
        << (int64_t)last_msg.msg.flash_program.data[66];
    EXPECT_EQ(last_msg.msg.flash_program.data[67], 129)
        << "incorrect value for last_msg.msg.flash_program.data[67], expected "
           "129, is "
        << (int64_t)last_msg.msg.flash_program.data[67];
    EXPECT_EQ(last_msg.msg.flash_program.data[68], 69)
        << "incorrect value for last_msg.msg.flash_program.data[68], expected "
           "69, is "
        << (int64_t)last_msg.msg.flash_program.data[68];
    EXPECT_EQ(last_msg.msg.flash_program.data[69], 228)
        << "incorrect value for last_msg.msg.flash_program.data[69], expected "
           "228, is "
        << (int64_t)last_msg.msg.flash_program.data[69];
    EXPECT_EQ(last_msg.msg.flash_program.data[70], 134)
        << "incorrect value for last_msg.msg.flash_program.data[70], expected "
           "134, is "
        << (int64_t)last_msg.msg.flash_program.data[70];
    EXPECT_EQ(last_msg.msg.flash_program.data[71], 9)
        << "incorrect value for last_msg.msg.flash_program.data[71], expected "
           "9, is "
        << (int64_t)last_msg.msg.flash_program.data[71];
    EXPECT_EQ(last_msg.msg.flash_program.data[72], 88)
        << "incorrect value for last_msg.msg.flash_program.data[72], expected "
           "88, is "
        << (int64_t)last_msg.msg.flash_program.data[72];
    EXPECT_EQ(last_msg.msg.flash_program.data[73], 183)
        << "incorrect value for last_msg.msg.flash_program.data[73], expected "
           "183, is "
        << (int64_t)last_msg.msg.flash_program.data[73];
    EXPECT_EQ(last_msg.msg.flash_program.data[74], 133)
        << "incorrect value for last_msg.msg.flash_program.data[74], expected "
           "133, is "
        << (int64_t)last_msg.msg.flash_program.data[74];
    EXPECT_EQ(last_msg.msg.flash_program.data[75], 171)
        << "incorrect value for last_msg.msg.flash_program.data[75], expected "
           "171, is "
        << (int64_t)last_msg.msg.flash_program.data[75];
    EXPECT_EQ(last_msg.msg.flash_program.data[76], 255)
        << "incorrect value for last_msg.msg.flash_program.data[76], expected "
           "255, is "
        << (int64_t)last_msg.msg.flash_program.data[76];
    EXPECT_EQ(last_msg.msg.flash_program.data[77], 166)
        << "incorrect value for last_msg.msg.flash_program.data[77], expected "
           "166, is "
        << (int64_t)last_msg.msg.flash_program.data[77];
    EXPECT_EQ(last_msg.msg.flash_program.data[78], 100)
        << "incorrect value for last_msg.msg.flash_program.data[78], expected "
           "100, is "
        << (int64_t)last_msg.msg.flash_program.data[78];
    EXPECT_EQ(last_msg.msg.flash_program.data[79], 152)
        << "incorrect value for last_msg.msg.flash_program.data[79], expected "
           "152, is "
        << (int64_t)last_msg.msg.flash_program.data[79];
    EXPECT_EQ(last_msg.msg.flash_program.data[80], 231)
        << "incorrect value for last_msg.msg.flash_program.data[80], expected "
           "231, is "
        << (int64_t)last_msg.msg.flash_program.data[80];
    EXPECT_EQ(last_msg.msg.flash_program.data[81], 92)
        << "incorrect value for last_msg.msg.flash_program.data[81], expected "
           "92, is "
        << (int64_t)last_msg.msg.flash_program.data[81];
    EXPECT_EQ(last_msg.msg.flash_program.data[82], 9)
        << "incorrect value for last_msg.msg.flash_program.data[82], expected "
           "9, is "
        << (int64_t)last_msg.msg.flash_program.data[82];
    EXPECT_EQ(last_msg.msg.flash_program.data[83], 196)
        << "incorrect value for last_msg.msg.flash_program.data[83], expected "
           "196, is "
        << (int64_t)last_msg.msg.flash_program.data[83];
    EXPECT_EQ(last_msg.msg.flash_program.data[84], 106)
        << "incorrect value for last_msg.msg.flash_program.data[84], expected "
           "106, is "
        << (int64_t)last_msg.msg.flash_program.data[84];
    EXPECT_EQ(last_msg.msg.flash_program.data[85], 246)
        << "incorrect value for last_msg.msg.flash_program.data[85], expected "
           "246, is "
        << (int64_t)last_msg.msg.flash_program.data[85];
    EXPECT_EQ(last_msg.msg.flash_program.data[86], 29)
        << "incorrect value for last_msg.msg.flash_program.data[86], expected "
           "29, is "
        << (int64_t)last_msg.msg.flash_program.data[86];
    EXPECT_EQ(last_msg.msg.flash_program.data[87], 145)
        << "incorrect value for last_msg.msg.flash_program.data[87], expected "
           "145, is "
        << (int64_t)last_msg.msg.flash_program.data[87];
    EXPECT_EQ(last_msg.msg.flash_program.data[88], 156)
        << "incorrect value for last_msg.msg.flash_program.data[88], expected "
           "156, is "
        << (int64_t)last_msg.msg.flash_program.data[88];
    EXPECT_EQ(last_msg.msg.flash_program.data[89], 151)
        << "incorrect value for last_msg.msg.flash_program.data[89], expected "
           "151, is "
        << (int64_t)last_msg.msg.flash_program.data[89];
    EXPECT_EQ(last_msg.msg.flash_program.data[90], 32)
        << "incorrect value for last_msg.msg.flash_program.data[90], expected "
           "32, is "
        << (int64_t)last_msg.msg.flash_program.data[90];
    EXPECT_EQ(last_msg.msg.flash_program.data[91], 67)
        << "incorrect value for last_msg.msg.flash_program.data[91], expected "
           "67, is "
        << (int64_t)last_msg.msg.flash_program.data[91];
    EXPECT_EQ(last_msg.msg.flash_program.data[92], 188)
        << "incorrect value for last_msg.msg.flash_program.data[92], expected "
           "188, is "
        << (int64_t)last_msg.msg.flash_program.data[92];
    EXPECT_EQ(last_msg.msg.flash_program.data[93], 63)
        << "incorrect value for last_msg.msg.flash_program.data[93], expected "
           "63, is "
        << (int64_t)last_msg.msg.flash_program.data[93];
    EXPECT_EQ(last_msg.msg.flash_program.data[94], 233)
        << "incorrect value for last_msg.msg.flash_program.data[94], expected "
           "233, is "
        << (int64_t)last_msg.msg.flash_program.data[94];
    EXPECT_EQ(last_msg.msg.flash_program.data[95], 142)
        << "incorrect value for last_msg.msg.flash_program.data[95], expected "
           "142, is "
        << (int64_t)last_msg.msg.flash_program.data[95];
    EXPECT_EQ(last_msg.msg.flash_program.data[96], 174)
        << "incorrect value for last_msg.msg.flash_program.data[96], expected "
           "174, is "
        << (int64_t)last_msg.msg.flash_program.data[96];
    EXPECT_EQ(last_msg.msg.flash_program.data[97], 139)
        << "incorrect value for last_msg.msg.flash_program.data[97], expected "
           "139, is "
        << (int64_t)last_msg.msg.flash_program.data[97];
    EXPECT_EQ(last_msg.msg.flash_program.data[98], 154)
        << "incorrect value for last_msg.msg.flash_program.data[98], expected "
           "154, is "
        << (int64_t)last_msg.msg.flash_program.data[98];
    EXPECT_EQ(last_msg.msg.flash_program.data[99], 127)
        << "incorrect value for last_msg.msg.flash_program.data[99], expected "
           "127, is "
        << (int64_t)last_msg.msg.flash_program.data[99];
    EXPECT_EQ(last_msg.msg.flash_program.data[100], 35)
        << "incorrect value for last_msg.msg.flash_program.data[100], expected "
           "35, is "
        << (int64_t)last_msg.msg.flash_program.data[100];
    EXPECT_EQ(last_msg.msg.flash_program.data[101], 60)
        << "incorrect value for last_msg.msg.flash_program.data[101], expected "
           "60, is "
        << (int64_t)last_msg.msg.flash_program.data[101];
    EXPECT_EQ(last_msg.msg.flash_program.data[102], 56)
        << "incorrect value for last_msg.msg.flash_program.data[102], expected "
           "56, is "
        << (int64_t)last_msg.msg.flash_program.data[102];
    EXPECT_EQ(last_msg.msg.flash_program.data[103], 187)
        << "incorrect value for last_msg.msg.flash_program.data[103], expected "
           "187, is "
        << (int64_t)last_msg.msg.flash_program.data[103];
    EXPECT_EQ(last_msg.msg.flash_program.data[104], 121)
        << "incorrect value for last_msg.msg.flash_program.data[104], expected "
           "121, is "
        << (int64_t)last_msg.msg.flash_program.data[104];
    EXPECT_EQ(last_msg.msg.flash_program.data[105], 103)
        << "incorrect value for last_msg.msg.flash_program.data[105], expected "
           "103, is "
        << (int64_t)last_msg.msg.flash_program.data[105];
    EXPECT_EQ(last_msg.msg.flash_program.data[106], 135)
        << "incorrect value for last_msg.msg.flash_program.data[106], expected "
           "135, is "
        << (int64_t)last_msg.msg.flash_program.data[106];
    EXPECT_EQ(last_msg.msg.flash_program.data[107], 152)
        << "incorrect value for last_msg.msg.flash_program.data[107], expected "
           "152, is "
        << (int64_t)last_msg.msg.flash_program.data[107];
    EXPECT_EQ(last_msg.msg.flash_program.data[108], 182)
        << "incorrect value for last_msg.msg.flash_program.data[108], expected "
           "182, is "
        << (int64_t)last_msg.msg.flash_program.data[108];
    EXPECT_EQ(last_msg.msg.flash_program.data[109], 88)
        << "incorrect value for last_msg.msg.flash_program.data[109], expected "
           "88, is "
        << (int64_t)last_msg.msg.flash_program.data[109];
    EXPECT_EQ(last_msg.msg.flash_program.data[110], 160)
        << "incorrect value for last_msg.msg.flash_program.data[110], expected "
           "160, is "
        << (int64_t)last_msg.msg.flash_program.data[110];
    EXPECT_EQ(last_msg.msg.flash_program.data[111], 255)
        << "incorrect value for last_msg.msg.flash_program.data[111], expected "
           "255, is "
        << (int64_t)last_msg.msg.flash_program.data[111];
    EXPECT_EQ(last_msg.msg.flash_program.data[112], 227)
        << "incorrect value for last_msg.msg.flash_program.data[112], expected "
           "227, is "
        << (int64_t)last_msg.msg.flash_program.data[112];
    EXPECT_EQ(last_msg.msg.flash_program.data[113], 240)
        << "incorrect value for last_msg.msg.flash_program.data[113], expected "
           "240, is "
        << (int64_t)last_msg.msg.flash_program.data[113];
    EXPECT_EQ(last_msg.msg.flash_program.data[114], 54)
        << "incorrect value for last_msg.msg.flash_program.data[114], expected "
           "54, is "
        << (int64_t)last_msg.msg.flash_program.data[114];
    EXPECT_EQ(last_msg.msg.flash_program.data[115], 100)
        << "incorrect value for last_msg.msg.flash_program.data[115], expected "
           "100, is "
        << (int64_t)last_msg.msg.flash_program.data[115];
    EXPECT_EQ(last_msg.msg.flash_program.data[116], 91)
        << "incorrect value for last_msg.msg.flash_program.data[116], expected "
           "91, is "
        << (int64_t)last_msg.msg.flash_program.data[116];
    EXPECT_EQ(last_msg.msg.flash_program.data[117], 31)
        << "incorrect value for last_msg.msg.flash_program.data[117], expected "
           "31, is "
        << (int64_t)last_msg.msg.flash_program.data[117];
    EXPECT_EQ(last_msg.msg.flash_program.data[118], 141)
        << "incorrect value for last_msg.msg.flash_program.data[118], expected "
           "141, is "
        << (int64_t)last_msg.msg.flash_program.data[118];
    EXPECT_EQ(last_msg.msg.flash_program.data[119], 102)
        << "incorrect value for last_msg.msg.flash_program.data[119], expected "
           "102, is "
        << (int64_t)last_msg.msg.flash_program.data[119];
    EXPECT_EQ(last_msg.msg.flash_program.data[120], 130)
        << "incorrect value for last_msg.msg.flash_program.data[120], expected "
           "130, is "
        << (int64_t)last_msg.msg.flash_program.data[120];
    EXPECT_EQ(last_msg.msg.flash_program.data[121], 254)
        << "incorrect value for last_msg.msg.flash_program.data[121], expected "
           "254, is "
        << (int64_t)last_msg.msg.flash_program.data[121];
    EXPECT_EQ(last_msg.msg.flash_program.data[122], 54)
        << "incorrect value for last_msg.msg.flash_program.data[122], expected "
           "54, is "
        << (int64_t)last_msg.msg.flash_program.data[122];
    EXPECT_EQ(last_msg.msg.flash_program.data[123], 227)
        << "incorrect value for last_msg.msg.flash_program.data[123], expected "
           "227, is "
        << (int64_t)last_msg.msg.flash_program.data[123];
    EXPECT_EQ(last_msg.msg.flash_program.data[124], 229)
        << "incorrect value for last_msg.msg.flash_program.data[124], expected "
           "229, is "
        << (int64_t)last_msg.msg.flash_program.data[124];
    EXPECT_EQ(last_msg.msg.flash_program.data[125], 62)
        << "incorrect value for last_msg.msg.flash_program.data[125], expected "
           "62, is "
        << (int64_t)last_msg.msg.flash_program.data[125];
    EXPECT_EQ(last_msg.msg.flash_program.data[126], 53)
        << "incorrect value for last_msg.msg.flash_program.data[126], expected "
           "53, is "
        << (int64_t)last_msg.msg.flash_program.data[126];
    EXPECT_EQ(last_msg.msg.flash_program.data[127], 225)
        << "incorrect value for last_msg.msg.flash_program.data[127], expected "
           "225, is "
        << (int64_t)last_msg.msg.flash_program.data[127];
    EXPECT_EQ(last_msg.msg.flash_program.data[128], 143)
        << "incorrect value for last_msg.msg.flash_program.data[128], expected "
           "143, is "
        << (int64_t)last_msg.msg.flash_program.data[128];
    EXPECT_EQ(last_msg.msg.flash_program.data[129], 88)
        << "incorrect value for last_msg.msg.flash_program.data[129], expected "
           "88, is "
        << (int64_t)last_msg.msg.flash_program.data[129];
    EXPECT_EQ(last_msg.msg.flash_program.data[130], 139)
        << "incorrect value for last_msg.msg.flash_program.data[130], expected "
           "139, is "
        << (int64_t)last_msg.msg.flash_program.data[130];
    EXPECT_EQ(last_msg.msg.flash_program.data[131], 126)
        << "incorrect value for last_msg.msg.flash_program.data[131], expected "
           "126, is "
        << (int64_t)last_msg.msg.flash_program.data[131];
    EXPECT_EQ(last_msg.msg.flash_program.data[132], 235)
        << "incorrect value for last_msg.msg.flash_program.data[132], expected "
           "235, is "
        << (int64_t)last_msg.msg.flash_program.data[132];
    EXPECT_EQ(last_msg.msg.flash_program.data[133], 235)
        << "incorrect value for last_msg.msg.flash_program.data[133], expected "
           "235, is "
        << (int64_t)last_msg.msg.flash_program.data[133];
    EXPECT_EQ(last_msg.msg.flash_program.data[134], 35)
        << "incorrect value for last_msg.msg.flash_program.data[134], expected "
           "35, is "
        << (int64_t)last_msg.msg.flash_program.data[134];
    EXPECT_EQ(last_msg.msg.flash_program.data[135], 54)
        << "incorrect value for last_msg.msg.flash_program.data[135], expected "
           "54, is "
        << (int64_t)last_msg.msg.flash_program.data[135];
    EXPECT_EQ(last_msg.msg.flash_program.data[136], 134)
        << "incorrect value for last_msg.msg.flash_program.data[136], expected "
           "134, is "
        << (int64_t)last_msg.msg.flash_program.data[136];
    EXPECT_EQ(last_msg.msg.flash_program.data[137], 163)
        << "incorrect value for last_msg.msg.flash_program.data[137], expected "
           "163, is "
        << (int64_t)last_msg.msg.flash_program.data[137];
    EXPECT_EQ(last_msg.msg.flash_program.data[138], 92)
        << "incorrect value for last_msg.msg.flash_program.data[138], expected "
           "92, is "
        << (int64_t)last_msg.msg.flash_program.data[138];
    EXPECT_EQ(last_msg.msg.flash_program.data[139], 57)
        << "incorrect value for last_msg.msg.flash_program.data[139], expected "
           "57, is "
        << (int64_t)last_msg.msg.flash_program.data[139];
    EXPECT_EQ(last_msg.msg.flash_program.data[140], 87)
        << "incorrect value for last_msg.msg.flash_program.data[140], expected "
           "87, is "
        << (int64_t)last_msg.msg.flash_program.data[140];
    EXPECT_EQ(last_msg.msg.flash_program.data[141], 130)
        << "incorrect value for last_msg.msg.flash_program.data[141], expected "
           "130, is "
        << (int64_t)last_msg.msg.flash_program.data[141];
    EXPECT_EQ(last_msg.msg.flash_program.data[142], 178)
        << "incorrect value for last_msg.msg.flash_program.data[142], expected "
           "178, is "
        << (int64_t)last_msg.msg.flash_program.data[142];
    EXPECT_EQ(last_msg.msg.flash_program.data[143], 22)
        << "incorrect value for last_msg.msg.flash_program.data[143], expected "
           "22, is "
        << (int64_t)last_msg.msg.flash_program.data[143];
    EXPECT_EQ(last_msg.msg.flash_program.data[144], 158)
        << "incorrect value for last_msg.msg.flash_program.data[144], expected "
           "158, is "
        << (int64_t)last_msg.msg.flash_program.data[144];
    EXPECT_EQ(last_msg.msg.flash_program.data[145], 18)
        << "incorrect value for last_msg.msg.flash_program.data[145], expected "
           "18, is "
        << (int64_t)last_msg.msg.flash_program.data[145];
    EXPECT_EQ(last_msg.msg.flash_program.data[146], 237)
        << "incorrect value for last_msg.msg.flash_program.data[146], expected "
           "237, is "
        << (int64_t)last_msg.msg.flash_program.data[146];
    EXPECT_EQ(last_msg.msg.flash_program.data[147], 209)
        << "incorrect value for last_msg.msg.flash_program.data[147], expected "
           "209, is "
        << (int64_t)last_msg.msg.flash_program.data[147];
    EXPECT_EQ(last_msg.msg.flash_program.data[148], 187)
        << "incorrect value for last_msg.msg.flash_program.data[148], expected "
           "187, is "
        << (int64_t)last_msg.msg.flash_program.data[148];
    EXPECT_EQ(last_msg.msg.flash_program.data[149], 226)
        << "incorrect value for last_msg.msg.flash_program.data[149], expected "
           "226, is "
        << (int64_t)last_msg.msg.flash_program.data[149];
    EXPECT_EQ(last_msg.msg.flash_program.data[150], 1)
        << "incorrect value for last_msg.msg.flash_program.data[150], expected "
           "1, is "
        << (int64_t)last_msg.msg.flash_program.data[150];
    EXPECT_EQ(last_msg.msg.flash_program.data[151], 46)
        << "incorrect value for last_msg.msg.flash_program.data[151], expected "
           "46, is "
        << (int64_t)last_msg.msg.flash_program.data[151];
    EXPECT_EQ(last_msg.msg.flash_program.data[152], 64)
        << "incorrect value for last_msg.msg.flash_program.data[152], expected "
           "64, is "
        << (int64_t)last_msg.msg.flash_program.data[152];
    EXPECT_EQ(last_msg.msg.flash_program.data[153], 226)
        << "incorrect value for last_msg.msg.flash_program.data[153], expected "
           "226, is "
        << (int64_t)last_msg.msg.flash_program.data[153];
    EXPECT_EQ(last_msg.msg.flash_program.data[154], 235)
        << "incorrect value for last_msg.msg.flash_program.data[154], expected "
           "235, is "
        << (int64_t)last_msg.msg.flash_program.data[154];
    EXPECT_EQ(last_msg.msg.flash_program.data[155], 213)
        << "incorrect value for last_msg.msg.flash_program.data[155], expected "
           "213, is "
        << (int64_t)last_msg.msg.flash_program.data[155];
    EXPECT_EQ(last_msg.msg.flash_program.data[156], 186)
        << "incorrect value for last_msg.msg.flash_program.data[156], expected "
           "186, is "
        << (int64_t)last_msg.msg.flash_program.data[156];
    EXPECT_EQ(last_msg.msg.flash_program.data[157], 159)
        << "incorrect value for last_msg.msg.flash_program.data[157], expected "
           "159, is "
        << (int64_t)last_msg.msg.flash_program.data[157];
    EXPECT_EQ(last_msg.msg.flash_program.data[158], 221)
        << "incorrect value for last_msg.msg.flash_program.data[158], expected "
           "221, is "
        << (int64_t)last_msg.msg.flash_program.data[158];
    EXPECT_EQ(last_msg.msg.flash_program.data[159], 186)
        << "incorrect value for last_msg.msg.flash_program.data[159], expected "
           "186, is "
        << (int64_t)last_msg.msg.flash_program.data[159];
    EXPECT_EQ(last_msg.msg.flash_program.data[160], 25)
        << "incorrect value for last_msg.msg.flash_program.data[160], expected "
           "25, is "
        << (int64_t)last_msg.msg.flash_program.data[160];
    EXPECT_EQ(last_msg.msg.flash_program.data[161], 115)
        << "incorrect value for last_msg.msg.flash_program.data[161], expected "
           "115, is "
        << (int64_t)last_msg.msg.flash_program.data[161];
    EXPECT_EQ(last_msg.msg.flash_program.data[162], 84)
        << "incorrect value for last_msg.msg.flash_program.data[162], expected "
           "84, is "
        << (int64_t)last_msg.msg.flash_program.data[162];
    EXPECT_EQ(last_msg.msg.flash_program.data[163], 131)
        << "incorrect value for last_msg.msg.flash_program.data[163], expected "
           "131, is "
        << (int64_t)last_msg.msg.flash_program.data[163];
    EXPECT_EQ(last_msg.msg.flash_program.data[164], 167)
        << "incorrect value for last_msg.msg.flash_program.data[164], expected "
           "167, is "
        << (int64_t)last_msg.msg.flash_program.data[164];
    EXPECT_EQ(last_msg.msg.flash_program.data[165], 201)
        << "incorrect value for last_msg.msg.flash_program.data[165], expected "
           "201, is "
        << (int64_t)last_msg.msg.flash_program.data[165];
    EXPECT_EQ(last_msg.msg.flash_program.data[166], 104)
        << "incorrect value for last_msg.msg.flash_program.data[166], expected "
           "104, is "
        << (int64_t)last_msg.msg.flash_program.data[166];
    EXPECT_EQ(last_msg.msg.flash_program.data[167], 1)
        << "incorrect value for last_msg.msg.flash_program.data[167], expected "
           "1, is "
        << (int64_t)last_msg.msg.flash_program.data[167];
    EXPECT_EQ(last_msg.msg.flash_program.data[168], 200)
        << "incorrect value for last_msg.msg.flash_program.data[168], expected "
           "200, is "
        << (int64_t)last_msg.msg.flash_program.data[168];
    EXPECT_EQ(last_msg.msg.flash_program.data[169], 13)
        << "incorrect value for last_msg.msg.flash_program.data[169], expected "
           "13, is "
        << (int64_t)last_msg.msg.flash_program.data[169];
    EXPECT_EQ(last_msg.msg.flash_program.data[170], 50)
        << "incorrect value for last_msg.msg.flash_program.data[170], expected "
           "50, is "
        << (int64_t)last_msg.msg.flash_program.data[170];
    EXPECT_EQ(last_msg.msg.flash_program.data[171], 71)
        << "incorrect value for last_msg.msg.flash_program.data[171], expected "
           "71, is "
        << (int64_t)last_msg.msg.flash_program.data[171];
    EXPECT_EQ(last_msg.msg.flash_program.data[172], 73)
        << "incorrect value for last_msg.msg.flash_program.data[172], expected "
           "73, is "
        << (int64_t)last_msg.msg.flash_program.data[172];
    EXPECT_EQ(last_msg.msg.flash_program.data[173], 193)
        << "incorrect value for last_msg.msg.flash_program.data[173], expected "
           "193, is "
        << (int64_t)last_msg.msg.flash_program.data[173];
    EXPECT_EQ(last_msg.msg.flash_program.data[174], 201)
        << "incorrect value for last_msg.msg.flash_program.data[174], expected "
           "201, is "
        << (int64_t)last_msg.msg.flash_program.data[174];
    EXPECT_EQ(last_msg.msg.flash_program.data[175], 250)
        << "incorrect value for last_msg.msg.flash_program.data[175], expected "
           "250, is "
        << (int64_t)last_msg.msg.flash_program.data[175];
    EXPECT_EQ(last_msg.msg.flash_program.data[176], 172)
        << "incorrect value for last_msg.msg.flash_program.data[176], expected "
           "172, is "
        << (int64_t)last_msg.msg.flash_program.data[176];
    EXPECT_EQ(last_msg.msg.flash_program.data[177], 193)
        << "incorrect value for last_msg.msg.flash_program.data[177], expected "
           "193, is "
        << (int64_t)last_msg.msg.flash_program.data[177];
    EXPECT_EQ(last_msg.msg.flash_program.data[178], 13)
        << "incorrect value for last_msg.msg.flash_program.data[178], expected "
           "13, is "
        << (int64_t)last_msg.msg.flash_program.data[178];
    EXPECT_EQ(last_msg.msg.flash_program.data[179], 20)
        << "incorrect value for last_msg.msg.flash_program.data[179], expected "
           "20, is "
        << (int64_t)last_msg.msg.flash_program.data[179];
    EXPECT_EQ(last_msg.msg.flash_program.data[180], 238)
        << "incorrect value for last_msg.msg.flash_program.data[180], expected "
           "238, is "
        << (int64_t)last_msg.msg.flash_program.data[180];
    EXPECT_EQ(last_msg.msg.flash_program.data[181], 130)
        << "incorrect value for last_msg.msg.flash_program.data[181], expected "
           "130, is "
        << (int64_t)last_msg.msg.flash_program.data[181];
    EXPECT_EQ(last_msg.msg.flash_program.data[182], 243)
        << "incorrect value for last_msg.msg.flash_program.data[182], expected "
           "243, is "
        << (int64_t)last_msg.msg.flash_program.data[182];
    EXPECT_EQ(last_msg.msg.flash_program.data[183], 68)
        << "incorrect value for last_msg.msg.flash_program.data[183], expected "
           "68, is "
        << (int64_t)last_msg.msg.flash_program.data[183];
    EXPECT_EQ(last_msg.msg.flash_program.data[184], 4)
        << "incorrect value for last_msg.msg.flash_program.data[184], expected "
           "4, is "
        << (int64_t)last_msg.msg.flash_program.data[184];
    EXPECT_EQ(last_msg.msg.flash_program.data[185], 72)
        << "incorrect value for last_msg.msg.flash_program.data[185], expected "
           "72, is "
        << (int64_t)last_msg.msg.flash_program.data[185];
    EXPECT_EQ(last_msg.msg.flash_program.data[186], 46)
        << "incorrect value for last_msg.msg.flash_program.data[186], expected "
           "46, is "
        << (int64_t)last_msg.msg.flash_program.data[186];
    EXPECT_EQ(last_msg.msg.flash_program.data[187], 194)
        << "incorrect value for last_msg.msg.flash_program.data[187], expected "
           "194, is "
        << (int64_t)last_msg.msg.flash_program.data[187];
    EXPECT_EQ(last_msg.msg.flash_program.data[188], 113)
        << "incorrect value for last_msg.msg.flash_program.data[188], expected "
           "113, is "
        << (int64_t)last_msg.msg.flash_program.data[188];
    EXPECT_EQ(last_msg.msg.flash_program.data[189], 255)
        << "incorrect value for last_msg.msg.flash_program.data[189], expected "
           "255, is "
        << (int64_t)last_msg.msg.flash_program.data[189];
    EXPECT_EQ(last_msg.msg.flash_program.data[190], 238)
        << "incorrect value for last_msg.msg.flash_program.data[190], expected "
           "238, is "
        << (int64_t)last_msg.msg.flash_program.data[190];
    EXPECT_EQ(last_msg.msg.flash_program.data[191], 15)
        << "incorrect value for last_msg.msg.flash_program.data[191], expected "
           "15, is "
        << (int64_t)last_msg.msg.flash_program.data[191];
    EXPECT_EQ(last_msg.msg.flash_program.data[192], 230)
        << "incorrect value for last_msg.msg.flash_program.data[192], expected "
           "230, is "
        << (int64_t)last_msg.msg.flash_program.data[192];
    EXPECT_EQ(last_msg.msg.flash_program.data[193], 64)
        << "incorrect value for last_msg.msg.flash_program.data[193], expected "
           "64, is "
        << (int64_t)last_msg.msg.flash_program.data[193];
    EXPECT_EQ(last_msg.msg.flash_program.data[194], 178)
        << "incorrect value for last_msg.msg.flash_program.data[194], expected "
           "178, is "
        << (int64_t)last_msg.msg.flash_program.data[194];
    EXPECT_EQ(last_msg.msg.flash_program.data[195], 127)
        << "incorrect value for last_msg.msg.flash_program.data[195], expected "
           "127, is "
        << (int64_t)last_msg.msg.flash_program.data[195];
    EXPECT_EQ(last_msg.msg.flash_program.data[196], 217)
        << "incorrect value for last_msg.msg.flash_program.data[196], expected "
           "217, is "
        << (int64_t)last_msg.msg.flash_program.data[196];
    EXPECT_EQ(last_msg.msg.flash_program.data[197], 92)
        << "incorrect value for last_msg.msg.flash_program.data[197], expected "
           "92, is "
        << (int64_t)last_msg.msg.flash_program.data[197];
    EXPECT_EQ(last_msg.msg.flash_program.data[198], 160)
        << "incorrect value for last_msg.msg.flash_program.data[198], expected "
           "160, is "
        << (int64_t)last_msg.msg.flash_program.data[198];
    EXPECT_EQ(last_msg.msg.flash_program.data[199], 201)
        << "incorrect value for last_msg.msg.flash_program.data[199], expected "
           "201, is "
        << (int64_t)last_msg.msg.flash_program.data[199];
    EXPECT_EQ(last_msg.msg.flash_program.data[200], 118)
        << "incorrect value for last_msg.msg.flash_program.data[200], expected "
           "118, is "
        << (int64_t)last_msg.msg.flash_program.data[200];
    EXPECT_EQ(last_msg.msg.flash_program.data[201], 163)
        << "incorrect value for last_msg.msg.flash_program.data[201], expected "
           "163, is "
        << (int64_t)last_msg.msg.flash_program.data[201];
    EXPECT_EQ(last_msg.msg.flash_program.data[202], 144)
        << "incorrect value for last_msg.msg.flash_program.data[202], expected "
           "144, is "
        << (int64_t)last_msg.msg.flash_program.data[202];
    EXPECT_EQ(last_msg.msg.flash_program.data[203], 58)
        << "incorrect value for last_msg.msg.flash_program.data[203], expected "
           "58, is "
        << (int64_t)last_msg.msg.flash_program.data[203];
    EXPECT_EQ(last_msg.msg.flash_program.data[204], 28)
        << "incorrect value for last_msg.msg.flash_program.data[204], expected "
           "28, is "
        << (int64_t)last_msg.msg.flash_program.data[204];
    EXPECT_EQ(last_msg.msg.flash_program.data[205], 174)
        << "incorrect value for last_msg.msg.flash_program.data[205], expected "
           "174, is "
        << (int64_t)last_msg.msg.flash_program.data[205];
    EXPECT_EQ(last_msg.msg.flash_program.data[206], 65)
        << "incorrect value for last_msg.msg.flash_program.data[206], expected "
           "65, is "
        << (int64_t)last_msg.msg.flash_program.data[206];
    EXPECT_EQ(last_msg.msg.flash_program.data[207], 73)
        << "incorrect value for last_msg.msg.flash_program.data[207], expected "
           "73, is "
        << (int64_t)last_msg.msg.flash_program.data[207];
    EXPECT_EQ(last_msg.msg.flash_program.data[208], 45)
        << "incorrect value for last_msg.msg.flash_program.data[208], expected "
           "45, is "
        << (int64_t)last_msg.msg.flash_program.data[208];
    EXPECT_EQ(last_msg.msg.flash_program.data[209], 123)
        << "incorrect value for last_msg.msg.flash_program.data[209], expected "
           "123, is "
        << (int64_t)last_msg.msg.flash_program.data[209];
    EXPECT_EQ(last_msg.msg.flash_program.data[210], 118)
        << "incorrect value for last_msg.msg.flash_program.data[210], expected "
           "118, is "
        << (int64_t)last_msg.msg.flash_program.data[210];
    EXPECT_EQ(last_msg.msg.flash_program.data[211], 83)
        << "incorrect value for last_msg.msg.flash_program.data[211], expected "
           "83, is "
        << (int64_t)last_msg.msg.flash_program.data[211];
    EXPECT_EQ(last_msg.msg.flash_program.data[212], 107)
        << "incorrect value for last_msg.msg.flash_program.data[212], expected "
           "107, is "
        << (int64_t)last_msg.msg.flash_program.data[212];
    EXPECT_EQ(last_msg.msg.flash_program.data[213], 239)
        << "incorrect value for last_msg.msg.flash_program.data[213], expected "
           "239, is "
        << (int64_t)last_msg.msg.flash_program.data[213];
    EXPECT_EQ(last_msg.msg.flash_program.data[214], 168)
        << "incorrect value for last_msg.msg.flash_program.data[214], expected "
           "168, is "
        << (int64_t)last_msg.msg.flash_program.data[214];
    EXPECT_EQ(last_msg.msg.flash_program.data[215], 32)
        << "incorrect value for last_msg.msg.flash_program.data[215], expected "
           "32, is "
        << (int64_t)last_msg.msg.flash_program.data[215];
    EXPECT_EQ(last_msg.msg.flash_program.data[216], 212)
        << "incorrect value for last_msg.msg.flash_program.data[216], expected "
           "212, is "
        << (int64_t)last_msg.msg.flash_program.data[216];
    EXPECT_EQ(last_msg.msg.flash_program.data[217], 191)
        << "incorrect value for last_msg.msg.flash_program.data[217], expected "
           "191, is "
        << (int64_t)last_msg.msg.flash_program.data[217];
    EXPECT_EQ(last_msg.msg.flash_program.data[218], 81)
        << "incorrect value for last_msg.msg.flash_program.data[218], expected "
           "81, is "
        << (int64_t)last_msg.msg.flash_program.data[218];
    EXPECT_EQ(last_msg.msg.flash_program.data[219], 93)
        << "incorrect value for last_msg.msg.flash_program.data[219], expected "
           "93, is "
        << (int64_t)last_msg.msg.flash_program.data[219];
    EXPECT_EQ(last_msg.msg.flash_program.data[220], 186)
        << "incorrect value for last_msg.msg.flash_program.data[220], expected "
           "186, is "
        << (int64_t)last_msg.msg.flash_program.data[220];
    EXPECT_EQ(last_msg.msg.flash_program.data[221], 223)
        << "incorrect value for last_msg.msg.flash_program.data[221], expected "
           "223, is "
        << (int64_t)last_msg.msg.flash_program.data[221];
    EXPECT_EQ(last_msg.msg.flash_program.data[222], 32)
        << "incorrect value for last_msg.msg.flash_program.data[222], expected "
           "32, is "
        << (int64_t)last_msg.msg.flash_program.data[222];
    EXPECT_EQ(last_msg.msg.flash_program.data[223], 19)
        << "incorrect value for last_msg.msg.flash_program.data[223], expected "
           "19, is "
        << (int64_t)last_msg.msg.flash_program.data[223];
    EXPECT_EQ(last_msg.msg.flash_program.data[224], 58)
        << "incorrect value for last_msg.msg.flash_program.data[224], expected "
           "58, is "
        << (int64_t)last_msg.msg.flash_program.data[224];
    EXPECT_EQ(last_msg.msg.flash_program.data[225], 137)
        << "incorrect value for last_msg.msg.flash_program.data[225], expected "
           "137, is "
        << (int64_t)last_msg.msg.flash_program.data[225];
    EXPECT_EQ(last_msg.msg.flash_program.data[226], 72)
        << "incorrect value for last_msg.msg.flash_program.data[226], expected "
           "72, is "
        << (int64_t)last_msg.msg.flash_program.data[226];
    EXPECT_EQ(last_msg.msg.flash_program.data[227], 217)
        << "incorrect value for last_msg.msg.flash_program.data[227], expected "
           "217, is "
        << (int64_t)last_msg.msg.flash_program.data[227];
    EXPECT_EQ(last_msg.msg.flash_program.data[228], 151)
        << "incorrect value for last_msg.msg.flash_program.data[228], expected "
           "151, is "
        << (int64_t)last_msg.msg.flash_program.data[228];
    EXPECT_EQ(last_msg.msg.flash_program.data[229], 251)
        << "incorrect value for last_msg.msg.flash_program.data[229], expected "
           "251, is "
        << (int64_t)last_msg.msg.flash_program.data[229];
    EXPECT_EQ(last_msg.msg.flash_program.data[230], 83)
        << "incorrect value for last_msg.msg.flash_program.data[230], expected "
           "83, is "
        << (int64_t)last_msg.msg.flash_program.data[230];
    EXPECT_EQ(last_msg.msg.flash_program.data[231], 20)
        << "incorrect value for last_msg.msg.flash_program.data[231], expected "
           "20, is "
        << (int64_t)last_msg.msg.flash_program.data[231];
    EXPECT_EQ(last_msg.msg.flash_program.data[232], 113)
        << "incorrect value for last_msg.msg.flash_program.data[232], expected "
           "113, is "
        << (int64_t)last_msg.msg.flash_program.data[232];
    EXPECT_EQ(last_msg.msg.flash_program.data[233], 37)
        << "incorrect value for last_msg.msg.flash_program.data[233], expected "
           "37, is "
        << (int64_t)last_msg.msg.flash_program.data[233];
    EXPECT_EQ(last_msg.msg.flash_program.data[234], 151)
        << "incorrect value for last_msg.msg.flash_program.data[234], expected "
           "151, is "
        << (int64_t)last_msg.msg.flash_program.data[234];
    EXPECT_EQ(last_msg.msg.flash_program.data[235], 34)
        << "incorrect value for last_msg.msg.flash_program.data[235], expected "
           "34, is "
        << (int64_t)last_msg.msg.flash_program.data[235];
    EXPECT_EQ(last_msg.msg.flash_program.data[236], 37)
        << "incorrect value for last_msg.msg.flash_program.data[236], expected "
           "37, is "
        << (int64_t)last_msg.msg.flash_program.data[236];
    EXPECT_EQ(last_msg.msg.flash_program.data[237], 71)
        << "incorrect value for last_msg.msg.flash_program.data[237], expected "
           "71, is "
        << (int64_t)last_msg.msg.flash_program.data[237];
    EXPECT_EQ(last_msg.msg.flash_program.data[238], 95)
        << "incorrect value for last_msg.msg.flash_program.data[238], expected "
           "95, is "
        << (int64_t)last_msg.msg.flash_program.data[238];
    EXPECT_EQ(last_msg.msg.flash_program.data[239], 105)
        << "incorrect value for last_msg.msg.flash_program.data[239], expected "
           "105, is "
        << (int64_t)last_msg.msg.flash_program.data[239];
    EXPECT_EQ(last_msg.msg.flash_program.data[240], 235)
        << "incorrect value for last_msg.msg.flash_program.data[240], expected "
           "235, is "
        << (int64_t)last_msg.msg.flash_program.data[240];
    EXPECT_EQ(last_msg.msg.flash_program.data[241], 144)
        << "incorrect value for last_msg.msg.flash_program.data[241], expected "
           "144, is "
        << (int64_t)last_msg.msg.flash_program.data[241];
    EXPECT_EQ(last_msg.msg.flash_program.data[242], 164)
        << "incorrect value for last_msg.msg.flash_program.data[242], expected "
           "164, is "
        << (int64_t)last_msg.msg.flash_program.data[242];
    EXPECT_EQ(last_msg.msg.flash_program.data[243], 83)
        << "incorrect value for last_msg.msg.flash_program.data[243], expected "
           "83, is "
        << (int64_t)last_msg.msg.flash_program.data[243];
    EXPECT_EQ(last_msg.msg.flash_program.data[244], 197)
        << "incorrect value for last_msg.msg.flash_program.data[244], expected "
           "197, is "
        << (int64_t)last_msg.msg.flash_program.data[244];
    EXPECT_EQ(last_msg.msg.flash_program.data[245], 254)
        << "incorrect value for last_msg.msg.flash_program.data[245], expected "
           "254, is "
        << (int64_t)last_msg.msg.flash_program.data[245];
    EXPECT_EQ(last_msg.msg.flash_program.data[246], 183)
        << "incorrect value for last_msg.msg.flash_program.data[246], expected "
           "183, is "
        << (int64_t)last_msg.msg.flash_program.data[246];
    EXPECT_EQ(last_msg.msg.flash_program.data[247], 223)
        << "incorrect value for last_msg.msg.flash_program.data[247], expected "
           "223, is "
        << (int64_t)last_msg.msg.flash_program.data[247];
    EXPECT_EQ(last_msg.msg.flash_program.data[248], 91)
        << "incorrect value for last_msg.msg.flash_program.data[248], expected "
           "91, is "
        << (int64_t)last_msg.msg.flash_program.data[248];
    EXPECT_EQ(last_msg.msg.flash_program.data[249], 19)
        << "incorrect value for last_msg.msg.flash_program.data[249], expected "
           "19, is "
        << (int64_t)last_msg.msg.flash_program.data[249];

    EXPECT_EQ(last_msg.msg.flash_program.target, 212)
        << "incorrect value for last_msg.msg.flash_program.target, expected "
           "212, is "
        << (int64_t)last_msg.msg.flash_program.target;
  }
}

}  // namespace
