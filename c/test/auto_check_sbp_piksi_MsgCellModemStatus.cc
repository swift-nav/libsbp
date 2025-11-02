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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCellModemStatus.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/piksi.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_piksi_MsgCellModemStatus,
     test_auto_check_sbp_piksi_MsgCellModemStatus) {
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

    sbp_callback_register(&sbp_state, SbpMsgCellModemStatus, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  190, 0,   19,  27,  255, 103, 205, 48,  6,   70,  123, 242, 46,
        52,  64,  176, 154, 98,  43,  132, 196, 89,  253, 161, 250, 174, 204,
        110, 47,  38,  187, 63,  102, 177, 162, 49,  80,  194, 37,  107, 60,
        225, 52,  101, 178, 142, 246, 21,  17,  93,  75,  169, 86,  16,  209,
        80,  243, 30,  206, 220, 206, 115, 47,  154, 91,  227, 88,  11,  1,
        85,  146, 100, 190, 232, 207, 61,  61,  201, 220, 31,  78,  34,  57,
        82,  59,  104, 65,  221, 0,   43,  210, 9,   32,  122, 29,  237, 11,
        151, 223, 18,  81,  204, 172, 234, 127, 3,   82,  133, 169, 12,  176,
        193, 0,   24,  121, 85,  55,  214, 198, 75,  234, 179, 214, 85,  94,
        115, 21,  73,  121, 75,  46,  158, 63,  100, 122, 213, 20,  85,  212,
        131, 50,  224, 218, 215, 215, 149, 2,   19,  129, 39,  164, 5,   175,
        6,   62,  51,  78,  66,  248, 116, 88,  90,  128, 226, 177, 0,   47,
        140, 33,  126, 221, 110, 144, 97,  74,  250, 181, 199, 27,  176, 65,
        185, 110, 92,  34,  44,  131, 96,  178, 40,  176, 4,   90,  36,  7,
        180, 244, 244, 23,  108, 171, 204, 196, 61,  51,  179, 242, 156, 81,
        83,  16,  15,  134, 40,  245, 253, 150, 94,  150, 144, 197, 113, 5,
        141, 232, 33,  101, 231, 38,  75,  178, 243, 119, 1,   248, 218, 86,
        7,   88,  197, 148, 240, 227, 2,   65,  173, 122, 143, 251, 156, 217,
        67,  239, 219, 31,  224, 176, 129, 81,  80,  40,  230,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.cell_modem_status.n_reserved = 250;

    test_msg.cell_modem_status.reserved[0] = 123;

    test_msg.cell_modem_status.reserved[1] = 242;

    test_msg.cell_modem_status.reserved[2] = 46;

    test_msg.cell_modem_status.reserved[3] = 52;

    test_msg.cell_modem_status.reserved[4] = 64;

    test_msg.cell_modem_status.reserved[5] = 176;

    test_msg.cell_modem_status.reserved[6] = 154;

    test_msg.cell_modem_status.reserved[7] = 98;

    test_msg.cell_modem_status.reserved[8] = 43;

    test_msg.cell_modem_status.reserved[9] = 132;

    test_msg.cell_modem_status.reserved[10] = 196;

    test_msg.cell_modem_status.reserved[11] = 89;

    test_msg.cell_modem_status.reserved[12] = 253;

    test_msg.cell_modem_status.reserved[13] = 161;

    test_msg.cell_modem_status.reserved[14] = 250;

    test_msg.cell_modem_status.reserved[15] = 174;

    test_msg.cell_modem_status.reserved[16] = 204;

    test_msg.cell_modem_status.reserved[17] = 110;

    test_msg.cell_modem_status.reserved[18] = 47;

    test_msg.cell_modem_status.reserved[19] = 38;

    test_msg.cell_modem_status.reserved[20] = 187;

    test_msg.cell_modem_status.reserved[21] = 63;

    test_msg.cell_modem_status.reserved[22] = 102;

    test_msg.cell_modem_status.reserved[23] = 177;

    test_msg.cell_modem_status.reserved[24] = 162;

    test_msg.cell_modem_status.reserved[25] = 49;

    test_msg.cell_modem_status.reserved[26] = 80;

    test_msg.cell_modem_status.reserved[27] = 194;

    test_msg.cell_modem_status.reserved[28] = 37;

    test_msg.cell_modem_status.reserved[29] = 107;

    test_msg.cell_modem_status.reserved[30] = 60;

    test_msg.cell_modem_status.reserved[31] = 225;

    test_msg.cell_modem_status.reserved[32] = 52;

    test_msg.cell_modem_status.reserved[33] = 101;

    test_msg.cell_modem_status.reserved[34] = 178;

    test_msg.cell_modem_status.reserved[35] = 142;

    test_msg.cell_modem_status.reserved[36] = 246;

    test_msg.cell_modem_status.reserved[37] = 21;

    test_msg.cell_modem_status.reserved[38] = 17;

    test_msg.cell_modem_status.reserved[39] = 93;

    test_msg.cell_modem_status.reserved[40] = 75;

    test_msg.cell_modem_status.reserved[41] = 169;

    test_msg.cell_modem_status.reserved[42] = 86;

    test_msg.cell_modem_status.reserved[43] = 16;

    test_msg.cell_modem_status.reserved[44] = 209;

    test_msg.cell_modem_status.reserved[45] = 80;

    test_msg.cell_modem_status.reserved[46] = 243;

    test_msg.cell_modem_status.reserved[47] = 30;

    test_msg.cell_modem_status.reserved[48] = 206;

    test_msg.cell_modem_status.reserved[49] = 220;

    test_msg.cell_modem_status.reserved[50] = 206;

    test_msg.cell_modem_status.reserved[51] = 115;

    test_msg.cell_modem_status.reserved[52] = 47;

    test_msg.cell_modem_status.reserved[53] = 154;

    test_msg.cell_modem_status.reserved[54] = 91;

    test_msg.cell_modem_status.reserved[55] = 227;

    test_msg.cell_modem_status.reserved[56] = 88;

    test_msg.cell_modem_status.reserved[57] = 11;

    test_msg.cell_modem_status.reserved[58] = 1;

    test_msg.cell_modem_status.reserved[59] = 85;

    test_msg.cell_modem_status.reserved[60] = 146;

    test_msg.cell_modem_status.reserved[61] = 100;

    test_msg.cell_modem_status.reserved[62] = 190;

    test_msg.cell_modem_status.reserved[63] = 232;

    test_msg.cell_modem_status.reserved[64] = 207;

    test_msg.cell_modem_status.reserved[65] = 61;

    test_msg.cell_modem_status.reserved[66] = 61;

    test_msg.cell_modem_status.reserved[67] = 201;

    test_msg.cell_modem_status.reserved[68] = 220;

    test_msg.cell_modem_status.reserved[69] = 31;

    test_msg.cell_modem_status.reserved[70] = 78;

    test_msg.cell_modem_status.reserved[71] = 34;

    test_msg.cell_modem_status.reserved[72] = 57;

    test_msg.cell_modem_status.reserved[73] = 82;

    test_msg.cell_modem_status.reserved[74] = 59;

    test_msg.cell_modem_status.reserved[75] = 104;

    test_msg.cell_modem_status.reserved[76] = 65;

    test_msg.cell_modem_status.reserved[77] = 221;

    test_msg.cell_modem_status.reserved[78] = 0;

    test_msg.cell_modem_status.reserved[79] = 43;

    test_msg.cell_modem_status.reserved[80] = 210;

    test_msg.cell_modem_status.reserved[81] = 9;

    test_msg.cell_modem_status.reserved[82] = 32;

    test_msg.cell_modem_status.reserved[83] = 122;

    test_msg.cell_modem_status.reserved[84] = 29;

    test_msg.cell_modem_status.reserved[85] = 237;

    test_msg.cell_modem_status.reserved[86] = 11;

    test_msg.cell_modem_status.reserved[87] = 151;

    test_msg.cell_modem_status.reserved[88] = 223;

    test_msg.cell_modem_status.reserved[89] = 18;

    test_msg.cell_modem_status.reserved[90] = 81;

    test_msg.cell_modem_status.reserved[91] = 204;

    test_msg.cell_modem_status.reserved[92] = 172;

    test_msg.cell_modem_status.reserved[93] = 234;

    test_msg.cell_modem_status.reserved[94] = 127;

    test_msg.cell_modem_status.reserved[95] = 3;

    test_msg.cell_modem_status.reserved[96] = 82;

    test_msg.cell_modem_status.reserved[97] = 133;

    test_msg.cell_modem_status.reserved[98] = 169;

    test_msg.cell_modem_status.reserved[99] = 12;

    test_msg.cell_modem_status.reserved[100] = 176;

    test_msg.cell_modem_status.reserved[101] = 193;

    test_msg.cell_modem_status.reserved[102] = 0;

    test_msg.cell_modem_status.reserved[103] = 24;

    test_msg.cell_modem_status.reserved[104] = 121;

    test_msg.cell_modem_status.reserved[105] = 85;

    test_msg.cell_modem_status.reserved[106] = 55;

    test_msg.cell_modem_status.reserved[107] = 214;

    test_msg.cell_modem_status.reserved[108] = 198;

    test_msg.cell_modem_status.reserved[109] = 75;

    test_msg.cell_modem_status.reserved[110] = 234;

    test_msg.cell_modem_status.reserved[111] = 179;

    test_msg.cell_modem_status.reserved[112] = 214;

    test_msg.cell_modem_status.reserved[113] = 85;

    test_msg.cell_modem_status.reserved[114] = 94;

    test_msg.cell_modem_status.reserved[115] = 115;

    test_msg.cell_modem_status.reserved[116] = 21;

    test_msg.cell_modem_status.reserved[117] = 73;

    test_msg.cell_modem_status.reserved[118] = 121;

    test_msg.cell_modem_status.reserved[119] = 75;

    test_msg.cell_modem_status.reserved[120] = 46;

    test_msg.cell_modem_status.reserved[121] = 158;

    test_msg.cell_modem_status.reserved[122] = 63;

    test_msg.cell_modem_status.reserved[123] = 100;

    test_msg.cell_modem_status.reserved[124] = 122;

    test_msg.cell_modem_status.reserved[125] = 213;

    test_msg.cell_modem_status.reserved[126] = 20;

    test_msg.cell_modem_status.reserved[127] = 85;

    test_msg.cell_modem_status.reserved[128] = 212;

    test_msg.cell_modem_status.reserved[129] = 131;

    test_msg.cell_modem_status.reserved[130] = 50;

    test_msg.cell_modem_status.reserved[131] = 224;

    test_msg.cell_modem_status.reserved[132] = 218;

    test_msg.cell_modem_status.reserved[133] = 215;

    test_msg.cell_modem_status.reserved[134] = 215;

    test_msg.cell_modem_status.reserved[135] = 149;

    test_msg.cell_modem_status.reserved[136] = 2;

    test_msg.cell_modem_status.reserved[137] = 19;

    test_msg.cell_modem_status.reserved[138] = 129;

    test_msg.cell_modem_status.reserved[139] = 39;

    test_msg.cell_modem_status.reserved[140] = 164;

    test_msg.cell_modem_status.reserved[141] = 5;

    test_msg.cell_modem_status.reserved[142] = 175;

    test_msg.cell_modem_status.reserved[143] = 6;

    test_msg.cell_modem_status.reserved[144] = 62;

    test_msg.cell_modem_status.reserved[145] = 51;

    test_msg.cell_modem_status.reserved[146] = 78;

    test_msg.cell_modem_status.reserved[147] = 66;

    test_msg.cell_modem_status.reserved[148] = 248;

    test_msg.cell_modem_status.reserved[149] = 116;

    test_msg.cell_modem_status.reserved[150] = 88;

    test_msg.cell_modem_status.reserved[151] = 90;

    test_msg.cell_modem_status.reserved[152] = 128;

    test_msg.cell_modem_status.reserved[153] = 226;

    test_msg.cell_modem_status.reserved[154] = 177;

    test_msg.cell_modem_status.reserved[155] = 0;

    test_msg.cell_modem_status.reserved[156] = 47;

    test_msg.cell_modem_status.reserved[157] = 140;

    test_msg.cell_modem_status.reserved[158] = 33;

    test_msg.cell_modem_status.reserved[159] = 126;

    test_msg.cell_modem_status.reserved[160] = 221;

    test_msg.cell_modem_status.reserved[161] = 110;

    test_msg.cell_modem_status.reserved[162] = 144;

    test_msg.cell_modem_status.reserved[163] = 97;

    test_msg.cell_modem_status.reserved[164] = 74;

    test_msg.cell_modem_status.reserved[165] = 250;

    test_msg.cell_modem_status.reserved[166] = 181;

    test_msg.cell_modem_status.reserved[167] = 199;

    test_msg.cell_modem_status.reserved[168] = 27;

    test_msg.cell_modem_status.reserved[169] = 176;

    test_msg.cell_modem_status.reserved[170] = 65;

    test_msg.cell_modem_status.reserved[171] = 185;

    test_msg.cell_modem_status.reserved[172] = 110;

    test_msg.cell_modem_status.reserved[173] = 92;

    test_msg.cell_modem_status.reserved[174] = 34;

    test_msg.cell_modem_status.reserved[175] = 44;

    test_msg.cell_modem_status.reserved[176] = 131;

    test_msg.cell_modem_status.reserved[177] = 96;

    test_msg.cell_modem_status.reserved[178] = 178;

    test_msg.cell_modem_status.reserved[179] = 40;

    test_msg.cell_modem_status.reserved[180] = 176;

    test_msg.cell_modem_status.reserved[181] = 4;

    test_msg.cell_modem_status.reserved[182] = 90;

    test_msg.cell_modem_status.reserved[183] = 36;

    test_msg.cell_modem_status.reserved[184] = 7;

    test_msg.cell_modem_status.reserved[185] = 180;

    test_msg.cell_modem_status.reserved[186] = 244;

    test_msg.cell_modem_status.reserved[187] = 244;

    test_msg.cell_modem_status.reserved[188] = 23;

    test_msg.cell_modem_status.reserved[189] = 108;

    test_msg.cell_modem_status.reserved[190] = 171;

    test_msg.cell_modem_status.reserved[191] = 204;

    test_msg.cell_modem_status.reserved[192] = 196;

    test_msg.cell_modem_status.reserved[193] = 61;

    test_msg.cell_modem_status.reserved[194] = 51;

    test_msg.cell_modem_status.reserved[195] = 179;

    test_msg.cell_modem_status.reserved[196] = 242;

    test_msg.cell_modem_status.reserved[197] = 156;

    test_msg.cell_modem_status.reserved[198] = 81;

    test_msg.cell_modem_status.reserved[199] = 83;

    test_msg.cell_modem_status.reserved[200] = 16;

    test_msg.cell_modem_status.reserved[201] = 15;

    test_msg.cell_modem_status.reserved[202] = 134;

    test_msg.cell_modem_status.reserved[203] = 40;

    test_msg.cell_modem_status.reserved[204] = 245;

    test_msg.cell_modem_status.reserved[205] = 253;

    test_msg.cell_modem_status.reserved[206] = 150;

    test_msg.cell_modem_status.reserved[207] = 94;

    test_msg.cell_modem_status.reserved[208] = 150;

    test_msg.cell_modem_status.reserved[209] = 144;

    test_msg.cell_modem_status.reserved[210] = 197;

    test_msg.cell_modem_status.reserved[211] = 113;

    test_msg.cell_modem_status.reserved[212] = 5;

    test_msg.cell_modem_status.reserved[213] = 141;

    test_msg.cell_modem_status.reserved[214] = 232;

    test_msg.cell_modem_status.reserved[215] = 33;

    test_msg.cell_modem_status.reserved[216] = 101;

    test_msg.cell_modem_status.reserved[217] = 231;

    test_msg.cell_modem_status.reserved[218] = 38;

    test_msg.cell_modem_status.reserved[219] = 75;

    test_msg.cell_modem_status.reserved[220] = 178;

    test_msg.cell_modem_status.reserved[221] = 243;

    test_msg.cell_modem_status.reserved[222] = 119;

    test_msg.cell_modem_status.reserved[223] = 1;

    test_msg.cell_modem_status.reserved[224] = 248;

    test_msg.cell_modem_status.reserved[225] = 218;

    test_msg.cell_modem_status.reserved[226] = 86;

    test_msg.cell_modem_status.reserved[227] = 7;

    test_msg.cell_modem_status.reserved[228] = 88;

    test_msg.cell_modem_status.reserved[229] = 197;

    test_msg.cell_modem_status.reserved[230] = 148;

    test_msg.cell_modem_status.reserved[231] = 240;

    test_msg.cell_modem_status.reserved[232] = 227;

    test_msg.cell_modem_status.reserved[233] = 2;

    test_msg.cell_modem_status.reserved[234] = 65;

    test_msg.cell_modem_status.reserved[235] = 173;

    test_msg.cell_modem_status.reserved[236] = 122;

    test_msg.cell_modem_status.reserved[237] = 143;

    test_msg.cell_modem_status.reserved[238] = 251;

    test_msg.cell_modem_status.reserved[239] = 156;

    test_msg.cell_modem_status.reserved[240] = 217;

    test_msg.cell_modem_status.reserved[241] = 67;

    test_msg.cell_modem_status.reserved[242] = 239;

    test_msg.cell_modem_status.reserved[243] = 219;

    test_msg.cell_modem_status.reserved[244] = 31;

    test_msg.cell_modem_status.reserved[245] = 224;

    test_msg.cell_modem_status.reserved[246] = 176;

    test_msg.cell_modem_status.reserved[247] = 129;

    test_msg.cell_modem_status.reserved[248] = 81;

    test_msg.cell_modem_status.reserved[249] = 80;

    test_msg.cell_modem_status.signal_error_rate = 8588.2001953125;

    test_msg.cell_modem_status.signal_strength = 103;

    sbp_message_send(&sbp_state, SbpMsgCellModemStatus, 6931, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 6931)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgCellModemStatus, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.cell_modem_status.n_reserved, 250)
        << "incorrect value for last_msg.msg.cell_modem_status.n_reserved, "
           "expected 250, is "
        << (int64_t)last_msg.msg.cell_modem_status.n_reserved;

    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[0], 123)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[0], "
           "expected 123, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[0];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[1], 242)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[1], "
           "expected 242, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[1];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[2], 46)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[2], "
           "expected 46, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[2];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[3], 52)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[3], "
           "expected 52, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[3];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[4], 64)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[4], "
           "expected 64, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[4];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[5], 176)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[5], "
           "expected 176, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[5];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[6], 154)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[6], "
           "expected 154, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[6];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[7], 98)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[7], "
           "expected 98, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[7];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[8], 43)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[8], "
           "expected 43, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[8];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[9], 132)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[9], "
           "expected 132, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[9];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[10], 196)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[10], "
           "expected 196, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[10];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[11], 89)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[11], "
           "expected 89, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[11];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[12], 253)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[12], "
           "expected 253, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[12];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[13], 161)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[13], "
           "expected 161, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[13];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[14], 250)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[14], "
           "expected 250, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[14];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[15], 174)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[15], "
           "expected 174, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[15];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[16], 204)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[16], "
           "expected 204, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[16];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[17], 110)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[17], "
           "expected 110, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[17];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[18], 47)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[18], "
           "expected 47, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[18];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[19], 38)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[19], "
           "expected 38, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[19];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[20], 187)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[20], "
           "expected 187, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[20];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[21], 63)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[21], "
           "expected 63, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[21];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[22], 102)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[22], "
           "expected 102, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[22];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[23], 177)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[23], "
           "expected 177, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[23];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[24], 162)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[24], "
           "expected 162, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[24];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[25], 49)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[25], "
           "expected 49, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[25];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[26], 80)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[26], "
           "expected 80, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[26];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[27], 194)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[27], "
           "expected 194, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[27];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[28], 37)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[28], "
           "expected 37, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[28];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[29], 107)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[29], "
           "expected 107, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[29];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[30], 60)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[30], "
           "expected 60, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[30];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[31], 225)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[31], "
           "expected 225, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[31];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[32], 52)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[32], "
           "expected 52, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[32];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[33], 101)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[33], "
           "expected 101, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[33];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[34], 178)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[34], "
           "expected 178, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[34];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[35], 142)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[35], "
           "expected 142, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[35];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[36], 246)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[36], "
           "expected 246, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[36];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[37], 21)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[37], "
           "expected 21, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[37];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[38], 17)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[38], "
           "expected 17, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[38];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[39], 93)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[39], "
           "expected 93, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[39];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[40], 75)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[40], "
           "expected 75, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[40];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[41], 169)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[41], "
           "expected 169, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[41];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[42], 86)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[42], "
           "expected 86, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[42];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[43], 16)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[43], "
           "expected 16, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[43];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[44], 209)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[44], "
           "expected 209, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[44];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[45], 80)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[45], "
           "expected 80, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[45];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[46], 243)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[46], "
           "expected 243, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[46];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[47], 30)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[47], "
           "expected 30, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[47];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[48], 206)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[48], "
           "expected 206, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[48];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[49], 220)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[49], "
           "expected 220, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[49];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[50], 206)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[50], "
           "expected 206, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[50];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[51], 115)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[51], "
           "expected 115, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[51];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[52], 47)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[52], "
           "expected 47, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[52];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[53], 154)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[53], "
           "expected 154, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[53];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[54], 91)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[54], "
           "expected 91, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[54];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[55], 227)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[55], "
           "expected 227, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[55];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[56], 88)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[56], "
           "expected 88, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[56];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[57], 11)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[57], "
           "expected 11, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[57];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[58], 1)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[58], "
           "expected 1, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[58];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[59], 85)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[59], "
           "expected 85, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[59];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[60], 146)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[60], "
           "expected 146, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[60];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[61], 100)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[61], "
           "expected 100, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[61];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[62], 190)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[62], "
           "expected 190, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[62];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[63], 232)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[63], "
           "expected 232, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[63];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[64], 207)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[64], "
           "expected 207, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[64];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[65], 61)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[65], "
           "expected 61, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[65];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[66], 61)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[66], "
           "expected 61, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[66];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[67], 201)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[67], "
           "expected 201, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[67];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[68], 220)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[68], "
           "expected 220, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[68];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[69], 31)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[69], "
           "expected 31, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[69];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[70], 78)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[70], "
           "expected 78, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[70];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[71], 34)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[71], "
           "expected 34, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[71];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[72], 57)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[72], "
           "expected 57, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[72];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[73], 82)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[73], "
           "expected 82, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[73];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[74], 59)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[74], "
           "expected 59, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[74];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[75], 104)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[75], "
           "expected 104, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[75];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[76], 65)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[76], "
           "expected 65, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[76];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[77], 221)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[77], "
           "expected 221, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[77];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[78], 0)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[78], "
           "expected 0, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[78];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[79], 43)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[79], "
           "expected 43, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[79];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[80], 210)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[80], "
           "expected 210, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[80];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[81], 9)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[81], "
           "expected 9, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[81];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[82], 32)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[82], "
           "expected 32, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[82];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[83], 122)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[83], "
           "expected 122, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[83];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[84], 29)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[84], "
           "expected 29, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[84];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[85], 237)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[85], "
           "expected 237, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[85];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[86], 11)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[86], "
           "expected 11, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[86];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[87], 151)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[87], "
           "expected 151, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[87];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[88], 223)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[88], "
           "expected 223, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[88];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[89], 18)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[89], "
           "expected 18, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[89];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[90], 81)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[90], "
           "expected 81, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[90];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[91], 204)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[91], "
           "expected 204, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[91];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[92], 172)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[92], "
           "expected 172, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[92];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[93], 234)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[93], "
           "expected 234, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[93];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[94], 127)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[94], "
           "expected 127, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[94];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[95], 3)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[95], "
           "expected 3, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[95];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[96], 82)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[96], "
           "expected 82, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[96];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[97], 133)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[97], "
           "expected 133, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[97];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[98], 169)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[98], "
           "expected 169, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[98];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[99], 12)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[99], "
           "expected 12, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[99];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[100], 176)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[100], "
           "expected 176, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[100];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[101], 193)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[101], "
           "expected 193, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[101];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[102], 0)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[102], "
           "expected 0, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[102];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[103], 24)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[103], "
           "expected 24, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[103];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[104], 121)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[104], "
           "expected 121, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[104];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[105], 85)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[105], "
           "expected 85, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[105];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[106], 55)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[106], "
           "expected 55, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[106];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[107], 214)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[107], "
           "expected 214, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[107];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[108], 198)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[108], "
           "expected 198, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[108];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[109], 75)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[109], "
           "expected 75, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[109];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[110], 234)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[110], "
           "expected 234, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[110];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[111], 179)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[111], "
           "expected 179, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[111];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[112], 214)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[112], "
           "expected 214, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[112];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[113], 85)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[113], "
           "expected 85, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[113];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[114], 94)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[114], "
           "expected 94, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[114];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[115], 115)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[115], "
           "expected 115, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[115];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[116], 21)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[116], "
           "expected 21, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[116];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[117], 73)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[117], "
           "expected 73, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[117];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[118], 121)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[118], "
           "expected 121, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[118];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[119], 75)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[119], "
           "expected 75, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[119];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[120], 46)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[120], "
           "expected 46, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[120];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[121], 158)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[121], "
           "expected 158, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[121];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[122], 63)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[122], "
           "expected 63, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[122];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[123], 100)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[123], "
           "expected 100, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[123];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[124], 122)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[124], "
           "expected 122, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[124];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[125], 213)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[125], "
           "expected 213, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[125];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[126], 20)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[126], "
           "expected 20, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[126];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[127], 85)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[127], "
           "expected 85, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[127];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[128], 212)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[128], "
           "expected 212, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[128];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[129], 131)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[129], "
           "expected 131, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[129];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[130], 50)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[130], "
           "expected 50, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[130];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[131], 224)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[131], "
           "expected 224, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[131];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[132], 218)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[132], "
           "expected 218, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[132];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[133], 215)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[133], "
           "expected 215, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[133];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[134], 215)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[134], "
           "expected 215, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[134];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[135], 149)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[135], "
           "expected 149, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[135];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[136], 2)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[136], "
           "expected 2, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[136];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[137], 19)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[137], "
           "expected 19, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[137];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[138], 129)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[138], "
           "expected 129, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[138];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[139], 39)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[139], "
           "expected 39, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[139];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[140], 164)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[140], "
           "expected 164, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[140];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[141], 5)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[141], "
           "expected 5, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[141];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[142], 175)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[142], "
           "expected 175, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[142];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[143], 6)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[143], "
           "expected 6, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[143];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[144], 62)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[144], "
           "expected 62, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[144];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[145], 51)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[145], "
           "expected 51, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[145];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[146], 78)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[146], "
           "expected 78, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[146];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[147], 66)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[147], "
           "expected 66, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[147];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[148], 248)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[148], "
           "expected 248, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[148];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[149], 116)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[149], "
           "expected 116, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[149];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[150], 88)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[150], "
           "expected 88, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[150];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[151], 90)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[151], "
           "expected 90, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[151];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[152], 128)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[152], "
           "expected 128, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[152];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[153], 226)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[153], "
           "expected 226, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[153];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[154], 177)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[154], "
           "expected 177, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[154];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[155], 0)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[155], "
           "expected 0, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[155];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[156], 47)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[156], "
           "expected 47, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[156];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[157], 140)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[157], "
           "expected 140, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[157];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[158], 33)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[158], "
           "expected 33, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[158];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[159], 126)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[159], "
           "expected 126, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[159];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[160], 221)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[160], "
           "expected 221, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[160];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[161], 110)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[161], "
           "expected 110, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[161];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[162], 144)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[162], "
           "expected 144, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[162];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[163], 97)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[163], "
           "expected 97, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[163];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[164], 74)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[164], "
           "expected 74, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[164];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[165], 250)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[165], "
           "expected 250, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[165];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[166], 181)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[166], "
           "expected 181, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[166];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[167], 199)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[167], "
           "expected 199, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[167];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[168], 27)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[168], "
           "expected 27, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[168];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[169], 176)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[169], "
           "expected 176, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[169];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[170], 65)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[170], "
           "expected 65, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[170];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[171], 185)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[171], "
           "expected 185, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[171];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[172], 110)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[172], "
           "expected 110, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[172];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[173], 92)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[173], "
           "expected 92, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[173];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[174], 34)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[174], "
           "expected 34, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[174];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[175], 44)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[175], "
           "expected 44, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[175];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[176], 131)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[176], "
           "expected 131, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[176];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[177], 96)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[177], "
           "expected 96, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[177];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[178], 178)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[178], "
           "expected 178, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[178];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[179], 40)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[179], "
           "expected 40, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[179];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[180], 176)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[180], "
           "expected 176, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[180];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[181], 4)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[181], "
           "expected 4, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[181];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[182], 90)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[182], "
           "expected 90, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[182];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[183], 36)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[183], "
           "expected 36, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[183];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[184], 7)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[184], "
           "expected 7, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[184];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[185], 180)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[185], "
           "expected 180, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[185];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[186], 244)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[186], "
           "expected 244, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[186];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[187], 244)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[187], "
           "expected 244, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[187];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[188], 23)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[188], "
           "expected 23, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[188];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[189], 108)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[189], "
           "expected 108, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[189];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[190], 171)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[190], "
           "expected 171, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[190];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[191], 204)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[191], "
           "expected 204, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[191];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[192], 196)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[192], "
           "expected 196, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[192];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[193], 61)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[193], "
           "expected 61, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[193];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[194], 51)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[194], "
           "expected 51, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[194];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[195], 179)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[195], "
           "expected 179, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[195];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[196], 242)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[196], "
           "expected 242, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[196];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[197], 156)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[197], "
           "expected 156, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[197];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[198], 81)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[198], "
           "expected 81, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[198];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[199], 83)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[199], "
           "expected 83, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[199];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[200], 16)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[200], "
           "expected 16, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[200];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[201], 15)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[201], "
           "expected 15, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[201];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[202], 134)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[202], "
           "expected 134, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[202];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[203], 40)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[203], "
           "expected 40, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[203];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[204], 245)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[204], "
           "expected 245, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[204];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[205], 253)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[205], "
           "expected 253, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[205];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[206], 150)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[206], "
           "expected 150, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[206];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[207], 94)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[207], "
           "expected 94, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[207];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[208], 150)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[208], "
           "expected 150, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[208];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[209], 144)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[209], "
           "expected 144, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[209];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[210], 197)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[210], "
           "expected 197, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[210];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[211], 113)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[211], "
           "expected 113, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[211];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[212], 5)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[212], "
           "expected 5, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[212];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[213], 141)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[213], "
           "expected 141, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[213];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[214], 232)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[214], "
           "expected 232, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[214];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[215], 33)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[215], "
           "expected 33, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[215];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[216], 101)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[216], "
           "expected 101, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[216];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[217], 231)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[217], "
           "expected 231, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[217];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[218], 38)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[218], "
           "expected 38, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[218];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[219], 75)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[219], "
           "expected 75, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[219];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[220], 178)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[220], "
           "expected 178, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[220];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[221], 243)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[221], "
           "expected 243, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[221];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[222], 119)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[222], "
           "expected 119, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[222];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[223], 1)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[223], "
           "expected 1, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[223];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[224], 248)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[224], "
           "expected 248, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[224];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[225], 218)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[225], "
           "expected 218, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[225];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[226], 86)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[226], "
           "expected 86, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[226];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[227], 7)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[227], "
           "expected 7, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[227];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[228], 88)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[228], "
           "expected 88, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[228];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[229], 197)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[229], "
           "expected 197, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[229];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[230], 148)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[230], "
           "expected 148, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[230];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[231], 240)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[231], "
           "expected 240, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[231];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[232], 227)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[232], "
           "expected 227, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[232];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[233], 2)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[233], "
           "expected 2, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[233];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[234], 65)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[234], "
           "expected 65, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[234];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[235], 173)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[235], "
           "expected 173, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[235];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[236], 122)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[236], "
           "expected 122, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[236];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[237], 143)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[237], "
           "expected 143, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[237];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[238], 251)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[238], "
           "expected 251, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[238];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[239], 156)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[239], "
           "expected 156, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[239];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[240], 217)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[240], "
           "expected 217, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[240];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[241], 67)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[241], "
           "expected 67, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[241];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[242], 239)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[242], "
           "expected 239, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[242];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[243], 219)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[243], "
           "expected 219, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[243];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[244], 31)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[244], "
           "expected 31, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[244];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[245], 224)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[245], "
           "expected 224, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[245];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[246], 176)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[246], "
           "expected 176, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[246];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[247], 129)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[247], "
           "expected 129, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[247];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[248], 81)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[248], "
           "expected 81, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[248];
    EXPECT_EQ(last_msg.msg.cell_modem_status.reserved[249], 80)
        << "incorrect value for last_msg.msg.cell_modem_status.reserved[249], "
           "expected 80, is "
        << (int64_t)last_msg.msg.cell_modem_status.reserved[249];

    EXPECT_LE((last_msg.msg.cell_modem_status.signal_error_rate * 100 -
               8588.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.cell_modem_status.signal_error_rate, expected "
           "8588.20019531, is "
        << last_msg.msg.cell_modem_status.signal_error_rate;

    EXPECT_EQ(last_msg.msg.cell_modem_status.signal_strength, 103)
        << "incorrect value for "
           "last_msg.msg.cell_modem_status.signal_strength, expected 103, is "
        << (int64_t)last_msg.msg.cell_modem_status.signal_strength;
  }
}

}  // namespace
