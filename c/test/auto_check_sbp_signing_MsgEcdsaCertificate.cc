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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaCertificate.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/signing.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_signing_MsgEcdsaCertificate,
     test_auto_check_sbp_signing_MsgEcdsaCertificate) {
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

    sbp_callback_register(&sbp_state, SbpMsgEcdsaCertificate, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,   12,  66,  0,   253, 48,  10,  11,  12,  13,  2,   180, 160,
        116, 77,  243, 28,  173, 36,  86,  33,  8,   31,  120, 73,  64,  169,
        148, 224, 57,  95,  17,  40,  213, 92,  195, 146, 235, 228, 177, 101,
        82,  182, 25,  172, 170, 250, 236, 7,   119, 4,   201, 10,  14,  208,
        47,  126, 49,  210, 174, 75,  221, 203, 24,  66,  52,  35,  26,  30,
        140, 111, 246, 39,  226, 205, 198, 178, 196, 5,   81,  9,   44,  164,
        163, 214, 138, 123, 76,  74,  237, 121, 13,  137, 186, 97,  193, 189,
        200, 124, 69,  115, 230, 159, 185, 158, 51,  12,  225, 65,  192, 105,
        56,  41,  85,  133, 19,  217, 166, 48,  139, 131, 96,  216, 98,  147,
        132, 234, 167, 248, 247, 32,  239, 194, 188, 254, 114, 117, 83,  25,
        251, 191, 104, 240, 118, 68,  42,  93,  18,  16,  37,  232, 99,  179,
        23,  90,  94,  136, 6,   125, 91,  255, 15,  71,  43,  46,  25,  252,
        229, 80,  143, 58,  241, 11,  62,  181, 155, 53,  153, 149, 152, 227,
        150, 87,  112, 165, 2,   128, 231, 25,  157, 244, 204, 108, 253, 127,
        122, 145, 113, 162, 197, 171, 199, 54,  184, 222, 206, 67,  144, 78,
        187, 207, 60,  211, 141, 135, 106, 220, 79,  183, 245, 21,  161, 168,
        34,  129, 50,  176, 1,   218, 20,  130, 59,  249, 109, 219, 0,   100,
        103, 55,  29,  242, 110, 154, 190, 233, 142, 45,  61,  215, 202, 238,
        88,  209, 70,  63,  151, 27,  102, 219, 30,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ecdsa_certificate.certificate_bytes[0] = 180;

    test_msg.ecdsa_certificate.certificate_bytes[1] = 160;

    test_msg.ecdsa_certificate.certificate_bytes[2] = 116;

    test_msg.ecdsa_certificate.certificate_bytes[3] = 77;

    test_msg.ecdsa_certificate.certificate_bytes[4] = 243;

    test_msg.ecdsa_certificate.certificate_bytes[5] = 28;

    test_msg.ecdsa_certificate.certificate_bytes[6] = 173;

    test_msg.ecdsa_certificate.certificate_bytes[7] = 36;

    test_msg.ecdsa_certificate.certificate_bytes[8] = 86;

    test_msg.ecdsa_certificate.certificate_bytes[9] = 33;

    test_msg.ecdsa_certificate.certificate_bytes[10] = 8;

    test_msg.ecdsa_certificate.certificate_bytes[11] = 31;

    test_msg.ecdsa_certificate.certificate_bytes[12] = 120;

    test_msg.ecdsa_certificate.certificate_bytes[13] = 73;

    test_msg.ecdsa_certificate.certificate_bytes[14] = 64;

    test_msg.ecdsa_certificate.certificate_bytes[15] = 169;

    test_msg.ecdsa_certificate.certificate_bytes[16] = 148;

    test_msg.ecdsa_certificate.certificate_bytes[17] = 224;

    test_msg.ecdsa_certificate.certificate_bytes[18] = 57;

    test_msg.ecdsa_certificate.certificate_bytes[19] = 95;

    test_msg.ecdsa_certificate.certificate_bytes[20] = 17;

    test_msg.ecdsa_certificate.certificate_bytes[21] = 40;

    test_msg.ecdsa_certificate.certificate_bytes[22] = 213;

    test_msg.ecdsa_certificate.certificate_bytes[23] = 92;

    test_msg.ecdsa_certificate.certificate_bytes[24] = 195;

    test_msg.ecdsa_certificate.certificate_bytes[25] = 146;

    test_msg.ecdsa_certificate.certificate_bytes[26] = 235;

    test_msg.ecdsa_certificate.certificate_bytes[27] = 228;

    test_msg.ecdsa_certificate.certificate_bytes[28] = 177;

    test_msg.ecdsa_certificate.certificate_bytes[29] = 101;

    test_msg.ecdsa_certificate.certificate_bytes[30] = 82;

    test_msg.ecdsa_certificate.certificate_bytes[31] = 182;

    test_msg.ecdsa_certificate.certificate_bytes[32] = 25;

    test_msg.ecdsa_certificate.certificate_bytes[33] = 172;

    test_msg.ecdsa_certificate.certificate_bytes[34] = 170;

    test_msg.ecdsa_certificate.certificate_bytes[35] = 250;

    test_msg.ecdsa_certificate.certificate_bytes[36] = 236;

    test_msg.ecdsa_certificate.certificate_bytes[37] = 7;

    test_msg.ecdsa_certificate.certificate_bytes[38] = 119;

    test_msg.ecdsa_certificate.certificate_bytes[39] = 4;

    test_msg.ecdsa_certificate.certificate_bytes[40] = 201;

    test_msg.ecdsa_certificate.certificate_bytes[41] = 10;

    test_msg.ecdsa_certificate.certificate_bytes[42] = 14;

    test_msg.ecdsa_certificate.certificate_bytes[43] = 208;

    test_msg.ecdsa_certificate.certificate_bytes[44] = 47;

    test_msg.ecdsa_certificate.certificate_bytes[45] = 126;

    test_msg.ecdsa_certificate.certificate_bytes[46] = 49;

    test_msg.ecdsa_certificate.certificate_bytes[47] = 210;

    test_msg.ecdsa_certificate.certificate_bytes[48] = 174;

    test_msg.ecdsa_certificate.certificate_bytes[49] = 75;

    test_msg.ecdsa_certificate.certificate_bytes[50] = 221;

    test_msg.ecdsa_certificate.certificate_bytes[51] = 203;

    test_msg.ecdsa_certificate.certificate_bytes[52] = 24;

    test_msg.ecdsa_certificate.certificate_bytes[53] = 66;

    test_msg.ecdsa_certificate.certificate_bytes[54] = 52;

    test_msg.ecdsa_certificate.certificate_bytes[55] = 35;

    test_msg.ecdsa_certificate.certificate_bytes[56] = 26;

    test_msg.ecdsa_certificate.certificate_bytes[57] = 30;

    test_msg.ecdsa_certificate.certificate_bytes[58] = 140;

    test_msg.ecdsa_certificate.certificate_bytes[59] = 111;

    test_msg.ecdsa_certificate.certificate_bytes[60] = 246;

    test_msg.ecdsa_certificate.certificate_bytes[61] = 39;

    test_msg.ecdsa_certificate.certificate_bytes[62] = 226;

    test_msg.ecdsa_certificate.certificate_bytes[63] = 205;

    test_msg.ecdsa_certificate.certificate_bytes[64] = 198;

    test_msg.ecdsa_certificate.certificate_bytes[65] = 178;

    test_msg.ecdsa_certificate.certificate_bytes[66] = 196;

    test_msg.ecdsa_certificate.certificate_bytes[67] = 5;

    test_msg.ecdsa_certificate.certificate_bytes[68] = 81;

    test_msg.ecdsa_certificate.certificate_bytes[69] = 9;

    test_msg.ecdsa_certificate.certificate_bytes[70] = 44;

    test_msg.ecdsa_certificate.certificate_bytes[71] = 164;

    test_msg.ecdsa_certificate.certificate_bytes[72] = 163;

    test_msg.ecdsa_certificate.certificate_bytes[73] = 214;

    test_msg.ecdsa_certificate.certificate_bytes[74] = 138;

    test_msg.ecdsa_certificate.certificate_bytes[75] = 123;

    test_msg.ecdsa_certificate.certificate_bytes[76] = 76;

    test_msg.ecdsa_certificate.certificate_bytes[77] = 74;

    test_msg.ecdsa_certificate.certificate_bytes[78] = 237;

    test_msg.ecdsa_certificate.certificate_bytes[79] = 121;

    test_msg.ecdsa_certificate.certificate_bytes[80] = 13;

    test_msg.ecdsa_certificate.certificate_bytes[81] = 137;

    test_msg.ecdsa_certificate.certificate_bytes[82] = 186;

    test_msg.ecdsa_certificate.certificate_bytes[83] = 97;

    test_msg.ecdsa_certificate.certificate_bytes[84] = 193;

    test_msg.ecdsa_certificate.certificate_bytes[85] = 189;

    test_msg.ecdsa_certificate.certificate_bytes[86] = 200;

    test_msg.ecdsa_certificate.certificate_bytes[87] = 124;

    test_msg.ecdsa_certificate.certificate_bytes[88] = 69;

    test_msg.ecdsa_certificate.certificate_bytes[89] = 115;

    test_msg.ecdsa_certificate.certificate_bytes[90] = 230;

    test_msg.ecdsa_certificate.certificate_bytes[91] = 159;

    test_msg.ecdsa_certificate.certificate_bytes[92] = 185;

    test_msg.ecdsa_certificate.certificate_bytes[93] = 158;

    test_msg.ecdsa_certificate.certificate_bytes[94] = 51;

    test_msg.ecdsa_certificate.certificate_bytes[95] = 12;

    test_msg.ecdsa_certificate.certificate_bytes[96] = 225;

    test_msg.ecdsa_certificate.certificate_bytes[97] = 65;

    test_msg.ecdsa_certificate.certificate_bytes[98] = 192;

    test_msg.ecdsa_certificate.certificate_bytes[99] = 105;

    test_msg.ecdsa_certificate.certificate_bytes[100] = 56;

    test_msg.ecdsa_certificate.certificate_bytes[101] = 41;

    test_msg.ecdsa_certificate.certificate_bytes[102] = 85;

    test_msg.ecdsa_certificate.certificate_bytes[103] = 133;

    test_msg.ecdsa_certificate.certificate_bytes[104] = 19;

    test_msg.ecdsa_certificate.certificate_bytes[105] = 217;

    test_msg.ecdsa_certificate.certificate_bytes[106] = 166;

    test_msg.ecdsa_certificate.certificate_bytes[107] = 48;

    test_msg.ecdsa_certificate.certificate_bytes[108] = 139;

    test_msg.ecdsa_certificate.certificate_bytes[109] = 131;

    test_msg.ecdsa_certificate.certificate_bytes[110] = 96;

    test_msg.ecdsa_certificate.certificate_bytes[111] = 216;

    test_msg.ecdsa_certificate.certificate_bytes[112] = 98;

    test_msg.ecdsa_certificate.certificate_bytes[113] = 147;

    test_msg.ecdsa_certificate.certificate_bytes[114] = 132;

    test_msg.ecdsa_certificate.certificate_bytes[115] = 234;

    test_msg.ecdsa_certificate.certificate_bytes[116] = 167;

    test_msg.ecdsa_certificate.certificate_bytes[117] = 248;

    test_msg.ecdsa_certificate.certificate_bytes[118] = 247;

    test_msg.ecdsa_certificate.certificate_bytes[119] = 32;

    test_msg.ecdsa_certificate.certificate_bytes[120] = 239;

    test_msg.ecdsa_certificate.certificate_bytes[121] = 194;

    test_msg.ecdsa_certificate.certificate_bytes[122] = 188;

    test_msg.ecdsa_certificate.certificate_bytes[123] = 254;

    test_msg.ecdsa_certificate.certificate_bytes[124] = 114;

    test_msg.ecdsa_certificate.certificate_bytes[125] = 117;

    test_msg.ecdsa_certificate.certificate_bytes[126] = 83;

    test_msg.ecdsa_certificate.certificate_bytes[127] = 25;

    test_msg.ecdsa_certificate.certificate_bytes[128] = 251;

    test_msg.ecdsa_certificate.certificate_bytes[129] = 191;

    test_msg.ecdsa_certificate.certificate_bytes[130] = 104;

    test_msg.ecdsa_certificate.certificate_bytes[131] = 240;

    test_msg.ecdsa_certificate.certificate_bytes[132] = 118;

    test_msg.ecdsa_certificate.certificate_bytes[133] = 68;

    test_msg.ecdsa_certificate.certificate_bytes[134] = 42;

    test_msg.ecdsa_certificate.certificate_bytes[135] = 93;

    test_msg.ecdsa_certificate.certificate_bytes[136] = 18;

    test_msg.ecdsa_certificate.certificate_bytes[137] = 16;

    test_msg.ecdsa_certificate.certificate_bytes[138] = 37;

    test_msg.ecdsa_certificate.certificate_bytes[139] = 232;

    test_msg.ecdsa_certificate.certificate_bytes[140] = 99;

    test_msg.ecdsa_certificate.certificate_bytes[141] = 179;

    test_msg.ecdsa_certificate.certificate_bytes[142] = 23;

    test_msg.ecdsa_certificate.certificate_bytes[143] = 90;

    test_msg.ecdsa_certificate.certificate_bytes[144] = 94;

    test_msg.ecdsa_certificate.certificate_bytes[145] = 136;

    test_msg.ecdsa_certificate.certificate_bytes[146] = 6;

    test_msg.ecdsa_certificate.certificate_bytes[147] = 125;

    test_msg.ecdsa_certificate.certificate_bytes[148] = 91;

    test_msg.ecdsa_certificate.certificate_bytes[149] = 255;

    test_msg.ecdsa_certificate.certificate_bytes[150] = 15;

    test_msg.ecdsa_certificate.certificate_bytes[151] = 71;

    test_msg.ecdsa_certificate.certificate_bytes[152] = 43;

    test_msg.ecdsa_certificate.certificate_bytes[153] = 46;

    test_msg.ecdsa_certificate.certificate_bytes[154] = 25;

    test_msg.ecdsa_certificate.certificate_bytes[155] = 252;

    test_msg.ecdsa_certificate.certificate_bytes[156] = 229;

    test_msg.ecdsa_certificate.certificate_bytes[157] = 80;

    test_msg.ecdsa_certificate.certificate_bytes[158] = 143;

    test_msg.ecdsa_certificate.certificate_bytes[159] = 58;

    test_msg.ecdsa_certificate.certificate_bytes[160] = 241;

    test_msg.ecdsa_certificate.certificate_bytes[161] = 11;

    test_msg.ecdsa_certificate.certificate_bytes[162] = 62;

    test_msg.ecdsa_certificate.certificate_bytes[163] = 181;

    test_msg.ecdsa_certificate.certificate_bytes[164] = 155;

    test_msg.ecdsa_certificate.certificate_bytes[165] = 53;

    test_msg.ecdsa_certificate.certificate_bytes[166] = 153;

    test_msg.ecdsa_certificate.certificate_bytes[167] = 149;

    test_msg.ecdsa_certificate.certificate_bytes[168] = 152;

    test_msg.ecdsa_certificate.certificate_bytes[169] = 227;

    test_msg.ecdsa_certificate.certificate_bytes[170] = 150;

    test_msg.ecdsa_certificate.certificate_bytes[171] = 87;

    test_msg.ecdsa_certificate.certificate_bytes[172] = 112;

    test_msg.ecdsa_certificate.certificate_bytes[173] = 165;

    test_msg.ecdsa_certificate.certificate_bytes[174] = 2;

    test_msg.ecdsa_certificate.certificate_bytes[175] = 128;

    test_msg.ecdsa_certificate.certificate_bytes[176] = 231;

    test_msg.ecdsa_certificate.certificate_bytes[177] = 25;

    test_msg.ecdsa_certificate.certificate_bytes[178] = 157;

    test_msg.ecdsa_certificate.certificate_bytes[179] = 244;

    test_msg.ecdsa_certificate.certificate_bytes[180] = 204;

    test_msg.ecdsa_certificate.certificate_bytes[181] = 108;

    test_msg.ecdsa_certificate.certificate_bytes[182] = 253;

    test_msg.ecdsa_certificate.certificate_bytes[183] = 127;

    test_msg.ecdsa_certificate.certificate_bytes[184] = 122;

    test_msg.ecdsa_certificate.certificate_bytes[185] = 145;

    test_msg.ecdsa_certificate.certificate_bytes[186] = 113;

    test_msg.ecdsa_certificate.certificate_bytes[187] = 162;

    test_msg.ecdsa_certificate.certificate_bytes[188] = 197;

    test_msg.ecdsa_certificate.certificate_bytes[189] = 171;

    test_msg.ecdsa_certificate.certificate_bytes[190] = 199;

    test_msg.ecdsa_certificate.certificate_bytes[191] = 54;

    test_msg.ecdsa_certificate.certificate_bytes[192] = 184;

    test_msg.ecdsa_certificate.certificate_bytes[193] = 222;

    test_msg.ecdsa_certificate.certificate_bytes[194] = 206;

    test_msg.ecdsa_certificate.certificate_bytes[195] = 67;

    test_msg.ecdsa_certificate.certificate_bytes[196] = 144;

    test_msg.ecdsa_certificate.certificate_bytes[197] = 78;

    test_msg.ecdsa_certificate.certificate_bytes[198] = 187;

    test_msg.ecdsa_certificate.certificate_bytes[199] = 207;

    test_msg.ecdsa_certificate.certificate_bytes[200] = 60;

    test_msg.ecdsa_certificate.certificate_bytes[201] = 211;

    test_msg.ecdsa_certificate.certificate_bytes[202] = 141;

    test_msg.ecdsa_certificate.certificate_bytes[203] = 135;

    test_msg.ecdsa_certificate.certificate_bytes[204] = 106;

    test_msg.ecdsa_certificate.certificate_bytes[205] = 220;

    test_msg.ecdsa_certificate.certificate_bytes[206] = 79;

    test_msg.ecdsa_certificate.certificate_bytes[207] = 183;

    test_msg.ecdsa_certificate.certificate_bytes[208] = 245;

    test_msg.ecdsa_certificate.certificate_bytes[209] = 21;

    test_msg.ecdsa_certificate.certificate_bytes[210] = 161;

    test_msg.ecdsa_certificate.certificate_bytes[211] = 168;

    test_msg.ecdsa_certificate.certificate_bytes[212] = 34;

    test_msg.ecdsa_certificate.certificate_bytes[213] = 129;

    test_msg.ecdsa_certificate.certificate_bytes[214] = 50;

    test_msg.ecdsa_certificate.certificate_bytes[215] = 176;

    test_msg.ecdsa_certificate.certificate_bytes[216] = 1;

    test_msg.ecdsa_certificate.certificate_bytes[217] = 218;

    test_msg.ecdsa_certificate.certificate_bytes[218] = 20;

    test_msg.ecdsa_certificate.certificate_bytes[219] = 130;

    test_msg.ecdsa_certificate.certificate_bytes[220] = 59;

    test_msg.ecdsa_certificate.certificate_bytes[221] = 249;

    test_msg.ecdsa_certificate.certificate_bytes[222] = 109;

    test_msg.ecdsa_certificate.certificate_bytes[223] = 219;

    test_msg.ecdsa_certificate.certificate_bytes[224] = 0;

    test_msg.ecdsa_certificate.certificate_bytes[225] = 100;

    test_msg.ecdsa_certificate.certificate_bytes[226] = 103;

    test_msg.ecdsa_certificate.certificate_bytes[227] = 55;

    test_msg.ecdsa_certificate.certificate_bytes[228] = 29;

    test_msg.ecdsa_certificate.certificate_bytes[229] = 242;

    test_msg.ecdsa_certificate.certificate_bytes[230] = 110;

    test_msg.ecdsa_certificate.certificate_bytes[231] = 154;

    test_msg.ecdsa_certificate.certificate_bytes[232] = 190;

    test_msg.ecdsa_certificate.certificate_bytes[233] = 233;

    test_msg.ecdsa_certificate.certificate_bytes[234] = 142;

    test_msg.ecdsa_certificate.certificate_bytes[235] = 45;

    test_msg.ecdsa_certificate.certificate_bytes[236] = 61;

    test_msg.ecdsa_certificate.certificate_bytes[237] = 215;

    test_msg.ecdsa_certificate.certificate_bytes[238] = 202;

    test_msg.ecdsa_certificate.certificate_bytes[239] = 238;

    test_msg.ecdsa_certificate.certificate_bytes[240] = 88;

    test_msg.ecdsa_certificate.certificate_bytes[241] = 209;

    test_msg.ecdsa_certificate.certificate_bytes[242] = 70;

    test_msg.ecdsa_certificate.certificate_bytes[243] = 63;

    test_msg.ecdsa_certificate.certificate_bytes[244] = 151;

    test_msg.ecdsa_certificate.certificate_bytes[245] = 27;

    test_msg.ecdsa_certificate.certificate_bytes[246] = 102;

    test_msg.ecdsa_certificate.certificate_id[0] = 10;

    test_msg.ecdsa_certificate.certificate_id[1] = 11;

    test_msg.ecdsa_certificate.certificate_id[2] = 12;

    test_msg.ecdsa_certificate.certificate_id[3] = 13;

    test_msg.ecdsa_certificate.flags = 2;

    test_msg.ecdsa_certificate.n_certificate_bytes = 247;

    test_msg.ecdsa_certificate.n_msg = 48;

    sbp_message_send(&sbp_state, SbpMsgEcdsaCertificate, 66, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 66)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgEcdsaCertificate, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[0], 180)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[0], expected 180, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[0];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[1], 160)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[1], expected 160, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[1];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[2], 116)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[2], expected 116, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[2];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[3], 77)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[3], expected 77, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[3];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[4], 243)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[4], expected 243, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[4];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[5], 28)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[5], expected 28, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[5];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[6], 173)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[6], expected 173, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[6];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[7], 36)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[7], expected 36, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[7];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[8], 86)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[8], expected 86, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[8];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[9], 33)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[9], expected 33, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[9];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[10], 8)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[10], expected 8, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[10];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[11], 31)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[11], expected 31, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[11];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[12], 120)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[12], expected "
           "120, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[12];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[13], 73)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[13], expected 73, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[13];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[14], 64)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[14], expected 64, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[14];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[15], 169)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[15], expected "
           "169, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[15];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[16], 148)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[16], expected "
           "148, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[16];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[17], 224)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[17], expected "
           "224, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[17];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[18], 57)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[18], expected 57, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[18];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[19], 95)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[19], expected 95, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[19];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[20], 17)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[20], expected 17, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[20];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[21], 40)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[21], expected 40, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[21];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[22], 213)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[22], expected "
           "213, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[22];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[23], 92)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[23], expected 92, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[23];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[24], 195)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[24], expected "
           "195, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[24];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[25], 146)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[25], expected "
           "146, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[25];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[26], 235)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[26], expected "
           "235, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[26];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[27], 228)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[27], expected "
           "228, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[27];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[28], 177)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[28], expected "
           "177, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[28];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[29], 101)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[29], expected "
           "101, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[29];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[30], 82)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[30], expected 82, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[30];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[31], 182)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[31], expected "
           "182, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[31];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[32], 25)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[32], expected 25, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[32];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[33], 172)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[33], expected "
           "172, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[33];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[34], 170)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[34], expected "
           "170, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[34];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[35], 250)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[35], expected "
           "250, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[35];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[36], 236)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[36], expected "
           "236, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[36];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[37], 7)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[37], expected 7, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[37];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[38], 119)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[38], expected "
           "119, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[38];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[39], 4)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[39], expected 4, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[39];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[40], 201)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[40], expected "
           "201, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[40];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[41], 10)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[41], expected 10, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[41];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[42], 14)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[42], expected 14, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[42];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[43], 208)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[43], expected "
           "208, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[43];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[44], 47)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[44], expected 47, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[44];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[45], 126)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[45], expected "
           "126, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[45];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[46], 49)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[46], expected 49, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[46];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[47], 210)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[47], expected "
           "210, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[47];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[48], 174)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[48], expected "
           "174, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[48];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[49], 75)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[49], expected 75, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[49];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[50], 221)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[50], expected "
           "221, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[50];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[51], 203)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[51], expected "
           "203, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[51];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[52], 24)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[52], expected 24, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[52];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[53], 66)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[53], expected 66, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[53];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[54], 52)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[54], expected 52, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[54];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[55], 35)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[55], expected 35, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[55];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[56], 26)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[56], expected 26, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[56];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[57], 30)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[57], expected 30, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[57];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[58], 140)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[58], expected "
           "140, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[58];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[59], 111)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[59], expected "
           "111, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[59];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[60], 246)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[60], expected "
           "246, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[60];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[61], 39)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[61], expected 39, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[61];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[62], 226)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[62], expected "
           "226, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[62];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[63], 205)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[63], expected "
           "205, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[63];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[64], 198)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[64], expected "
           "198, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[64];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[65], 178)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[65], expected "
           "178, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[65];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[66], 196)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[66], expected "
           "196, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[66];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[67], 5)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[67], expected 5, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[67];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[68], 81)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[68], expected 81, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[68];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[69], 9)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[69], expected 9, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[69];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[70], 44)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[70], expected 44, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[70];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[71], 164)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[71], expected "
           "164, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[71];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[72], 163)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[72], expected "
           "163, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[72];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[73], 214)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[73], expected "
           "214, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[73];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[74], 138)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[74], expected "
           "138, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[74];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[75], 123)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[75], expected "
           "123, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[75];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[76], 76)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[76], expected 76, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[76];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[77], 74)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[77], expected 74, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[77];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[78], 237)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[78], expected "
           "237, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[78];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[79], 121)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[79], expected "
           "121, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[79];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[80], 13)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[80], expected 13, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[80];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[81], 137)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[81], expected "
           "137, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[81];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[82], 186)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[82], expected "
           "186, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[82];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[83], 97)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[83], expected 97, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[83];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[84], 193)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[84], expected "
           "193, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[84];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[85], 189)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[85], expected "
           "189, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[85];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[86], 200)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[86], expected "
           "200, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[86];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[87], 124)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[87], expected "
           "124, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[87];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[88], 69)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[88], expected 69, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[88];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[89], 115)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[89], expected "
           "115, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[89];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[90], 230)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[90], expected "
           "230, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[90];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[91], 159)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[91], expected "
           "159, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[91];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[92], 185)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[92], expected "
           "185, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[92];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[93], 158)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[93], expected "
           "158, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[93];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[94], 51)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[94], expected 51, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[94];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[95], 12)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[95], expected 12, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[95];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[96], 225)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[96], expected "
           "225, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[96];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[97], 65)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[97], expected 65, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[97];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[98], 192)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[98], expected "
           "192, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[98];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[99], 105)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[99], expected "
           "105, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[99];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[100], 56)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[100], expected "
           "56, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[100];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[101], 41)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[101], expected "
           "41, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[101];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[102], 85)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[102], expected "
           "85, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[102];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[103], 133)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[103], expected "
           "133, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[103];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[104], 19)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[104], expected "
           "19, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[104];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[105], 217)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[105], expected "
           "217, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[105];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[106], 166)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[106], expected "
           "166, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[106];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[107], 48)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[107], expected "
           "48, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[107];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[108], 139)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[108], expected "
           "139, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[108];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[109], 131)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[109], expected "
           "131, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[109];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[110], 96)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[110], expected "
           "96, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[110];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[111], 216)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[111], expected "
           "216, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[111];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[112], 98)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[112], expected "
           "98, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[112];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[113], 147)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[113], expected "
           "147, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[113];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[114], 132)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[114], expected "
           "132, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[114];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[115], 234)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[115], expected "
           "234, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[115];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[116], 167)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[116], expected "
           "167, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[116];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[117], 248)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[117], expected "
           "248, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[117];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[118], 247)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[118], expected "
           "247, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[118];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[119], 32)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[119], expected "
           "32, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[119];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[120], 239)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[120], expected "
           "239, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[120];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[121], 194)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[121], expected "
           "194, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[121];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[122], 188)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[122], expected "
           "188, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[122];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[123], 254)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[123], expected "
           "254, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[123];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[124], 114)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[124], expected "
           "114, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[124];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[125], 117)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[125], expected "
           "117, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[125];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[126], 83)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[126], expected "
           "83, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[126];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[127], 25)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[127], expected "
           "25, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[127];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[128], 251)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[128], expected "
           "251, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[128];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[129], 191)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[129], expected "
           "191, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[129];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[130], 104)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[130], expected "
           "104, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[130];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[131], 240)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[131], expected "
           "240, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[131];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[132], 118)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[132], expected "
           "118, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[132];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[133], 68)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[133], expected "
           "68, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[133];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[134], 42)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[134], expected "
           "42, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[134];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[135], 93)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[135], expected "
           "93, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[135];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[136], 18)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[136], expected "
           "18, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[136];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[137], 16)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[137], expected "
           "16, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[137];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[138], 37)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[138], expected "
           "37, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[138];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[139], 232)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[139], expected "
           "232, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[139];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[140], 99)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[140], expected "
           "99, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[140];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[141], 179)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[141], expected "
           "179, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[141];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[142], 23)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[142], expected "
           "23, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[142];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[143], 90)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[143], expected "
           "90, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[143];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[144], 94)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[144], expected "
           "94, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[144];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[145], 136)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[145], expected "
           "136, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[145];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[146], 6)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[146], expected 6, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[146];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[147], 125)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[147], expected "
           "125, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[147];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[148], 91)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[148], expected "
           "91, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[148];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[149], 255)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[149], expected "
           "255, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[149];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[150], 15)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[150], expected "
           "15, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[150];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[151], 71)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[151], expected "
           "71, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[151];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[152], 43)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[152], expected "
           "43, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[152];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[153], 46)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[153], expected "
           "46, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[153];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[154], 25)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[154], expected "
           "25, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[154];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[155], 252)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[155], expected "
           "252, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[155];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[156], 229)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[156], expected "
           "229, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[156];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[157], 80)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[157], expected "
           "80, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[157];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[158], 143)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[158], expected "
           "143, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[158];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[159], 58)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[159], expected "
           "58, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[159];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[160], 241)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[160], expected "
           "241, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[160];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[161], 11)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[161], expected "
           "11, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[161];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[162], 62)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[162], expected "
           "62, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[162];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[163], 181)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[163], expected "
           "181, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[163];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[164], 155)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[164], expected "
           "155, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[164];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[165], 53)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[165], expected "
           "53, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[165];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[166], 153)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[166], expected "
           "153, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[166];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[167], 149)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[167], expected "
           "149, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[167];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[168], 152)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[168], expected "
           "152, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[168];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[169], 227)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[169], expected "
           "227, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[169];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[170], 150)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[170], expected "
           "150, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[170];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[171], 87)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[171], expected "
           "87, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[171];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[172], 112)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[172], expected "
           "112, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[172];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[173], 165)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[173], expected "
           "165, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[173];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[174], 2)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[174], expected 2, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[174];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[175], 128)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[175], expected "
           "128, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[175];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[176], 231)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[176], expected "
           "231, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[176];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[177], 25)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[177], expected "
           "25, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[177];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[178], 157)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[178], expected "
           "157, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[178];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[179], 244)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[179], expected "
           "244, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[179];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[180], 204)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[180], expected "
           "204, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[180];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[181], 108)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[181], expected "
           "108, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[181];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[182], 253)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[182], expected "
           "253, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[182];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[183], 127)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[183], expected "
           "127, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[183];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[184], 122)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[184], expected "
           "122, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[184];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[185], 145)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[185], expected "
           "145, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[185];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[186], 113)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[186], expected "
           "113, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[186];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[187], 162)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[187], expected "
           "162, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[187];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[188], 197)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[188], expected "
           "197, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[188];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[189], 171)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[189], expected "
           "171, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[189];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[190], 199)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[190], expected "
           "199, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[190];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[191], 54)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[191], expected "
           "54, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[191];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[192], 184)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[192], expected "
           "184, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[192];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[193], 222)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[193], expected "
           "222, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[193];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[194], 206)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[194], expected "
           "206, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[194];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[195], 67)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[195], expected "
           "67, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[195];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[196], 144)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[196], expected "
           "144, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[196];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[197], 78)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[197], expected "
           "78, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[197];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[198], 187)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[198], expected "
           "187, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[198];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[199], 207)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[199], expected "
           "207, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[199];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[200], 60)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[200], expected "
           "60, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[200];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[201], 211)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[201], expected "
           "211, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[201];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[202], 141)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[202], expected "
           "141, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[202];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[203], 135)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[203], expected "
           "135, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[203];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[204], 106)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[204], expected "
           "106, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[204];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[205], 220)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[205], expected "
           "220, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[205];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[206], 79)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[206], expected "
           "79, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[206];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[207], 183)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[207], expected "
           "183, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[207];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[208], 245)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[208], expected "
           "245, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[208];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[209], 21)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[209], expected "
           "21, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[209];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[210], 161)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[210], expected "
           "161, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[210];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[211], 168)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[211], expected "
           "168, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[211];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[212], 34)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[212], expected "
           "34, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[212];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[213], 129)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[213], expected "
           "129, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[213];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[214], 50)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[214], expected "
           "50, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[214];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[215], 176)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[215], expected "
           "176, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[215];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[216], 1)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[216], expected 1, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[216];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[217], 218)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[217], expected "
           "218, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[217];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[218], 20)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[218], expected "
           "20, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[218];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[219], 130)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[219], expected "
           "130, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[219];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[220], 59)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[220], expected "
           "59, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[220];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[221], 249)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[221], expected "
           "249, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[221];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[222], 109)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[222], expected "
           "109, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[222];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[223], 219)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[223], expected "
           "219, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[223];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[224], 0)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[224], expected 0, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[224];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[225], 100)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[225], expected "
           "100, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[225];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[226], 103)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[226], expected "
           "103, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[226];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[227], 55)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[227], expected "
           "55, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[227];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[228], 29)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[228], expected "
           "29, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[228];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[229], 242)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[229], expected "
           "242, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[229];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[230], 110)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[230], expected "
           "110, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[230];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[231], 154)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[231], expected "
           "154, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[231];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[232], 190)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[232], expected "
           "190, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[232];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[233], 233)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[233], expected "
           "233, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[233];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[234], 142)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[234], expected "
           "142, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[234];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[235], 45)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[235], expected "
           "45, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[235];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[236], 61)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[236], expected "
           "61, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[236];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[237], 215)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[237], expected "
           "215, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[237];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[238], 202)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[238], expected "
           "202, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[238];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[239], 238)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[239], expected "
           "238, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[239];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[240], 88)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[240], expected "
           "88, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[240];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[241], 209)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[241], expected "
           "209, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[241];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[242], 70)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[242], expected "
           "70, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[242];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[243], 63)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[243], expected "
           "63, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[243];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[244], 151)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[244], expected "
           "151, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[244];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[245], 27)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[245], expected "
           "27, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[245];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_bytes[246], 102)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_bytes[246], expected "
           "102, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_bytes[246];

    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_id[0], 10)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_id[0], expected 10, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_id[0];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_id[1], 11)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_id[1], expected 11, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_id[1];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_id[2], 12)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_id[2], expected 12, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_id[2];
    EXPECT_EQ(last_msg.msg.ecdsa_certificate.certificate_id[3], 13)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.certificate_id[3], expected 13, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.certificate_id[3];

    EXPECT_EQ(last_msg.msg.ecdsa_certificate.flags, 2)
        << "incorrect value for last_msg.msg.ecdsa_certificate.flags, expected "
           "2, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.flags;

    EXPECT_EQ(last_msg.msg.ecdsa_certificate.n_certificate_bytes, 247)
        << "incorrect value for "
           "last_msg.msg.ecdsa_certificate.n_certificate_bytes, expected 247, "
           "is "
        << (int64_t)last_msg.msg.ecdsa_certificate.n_certificate_bytes;

    EXPECT_EQ(last_msg.msg.ecdsa_certificate.n_msg, 48)
        << "incorrect value for last_msg.msg.ecdsa_certificate.n_msg, expected "
           "48, is "
        << (int64_t)last_msg.msg.ecdsa_certificate.n_msg;
  }
}

}  // namespace
