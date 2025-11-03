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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodeBiases.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/ssr.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_ssr_MsgSsrCodeBiases,
     test_auto_check_sbp_ssr_MsgSsrCodeBiases) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrCodeBiases, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  225, 5,   39,  87,  253, 208, 90,  19,  23,  9,   66,  133, 241,
        254, 132, 51,  4,   131, 240, 120, 83,  148, 209, 213, 62,  228, 232,
        71,  66,  188, 210, 128, 54,  131, 152, 129, 111, 139, 242, 177, 145,
        44,  9,   245, 207, 241, 202, 150, 141, 50,  159, 220, 139, 37,  187,
        98,  191, 23,  128, 136, 167, 200, 6,   211, 90,  23,  244, 138, 215,
        209, 139, 13,  101, 32,  7,   18,  29,  70,  250, 109, 73,  202, 79,
        144, 9,   146, 69,  241, 52,  22,  99,  98,  204, 3,   171, 230, 180,
        75,  62,  145, 86,  130, 31,  30,  155, 37,  18,  55,  210, 39,  127,
        242, 66,  13,  237, 152, 170, 212, 15,  246, 59,  94,  180, 195, 157,
        69,  100, 119, 16,  68,  179, 175, 144, 113, 81,  82,  30,  151, 21,
        109, 41,  225, 8,   77,  164, 157, 0,   73,  30,  6,   78,  81,  143,
        116, 240, 151, 55,  185, 169, 254, 51,  39,  74,  175, 247, 34,  97,
        74,  97,  176, 48,  236, 173, 12,  174, 101, 130, 30,  169, 193, 190,
        204, 196, 123, 107, 25,  225, 74,  9,   10,  55,  3,   131, 246, 99,
        133, 34,  227, 203, 68,  18,  97,  223, 89,  192, 246, 50,  69,  91,
        10,  151, 74,  118, 110, 36,  168, 247, 160, 77,  179, 141, 178, 99,
        191, 120, 77,  192, 91,  224, 1,   226, 50,  87,  146, 148, 238, 100,
        179, 125, 227, 215, 104, 184, 31,  57,  90,  79,  21,  156, 245, 81,
        60,  93,  170, 60,  200, 167, 13,  125, 132,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_code_biases.biases[0].code = 51;

    test_msg.ssr_code_biases.biases[0].value = -31996;

    test_msg.ssr_code_biases.biases[1].code = 240;

    test_msg.ssr_code_biases.biases[1].value = 21368;

    test_msg.ssr_code_biases.biases[2].code = 148;

    test_msg.ssr_code_biases.biases[2].value = -10799;

    test_msg.ssr_code_biases.biases[3].code = 62;

    test_msg.ssr_code_biases.biases[3].value = -5916;

    test_msg.ssr_code_biases.biases[4].code = 71;

    test_msg.ssr_code_biases.biases[4].value = -17342;

    test_msg.ssr_code_biases.biases[5].code = 210;

    test_msg.ssr_code_biases.biases[5].value = 13952;

    test_msg.ssr_code_biases.biases[6].code = 131;

    test_msg.ssr_code_biases.biases[6].value = -32360;

    test_msg.ssr_code_biases.biases[7].code = 111;

    test_msg.ssr_code_biases.biases[7].value = -3445;

    test_msg.ssr_code_biases.biases[8].code = 177;

    test_msg.ssr_code_biases.biases[8].value = 11409;

    test_msg.ssr_code_biases.biases[9].code = 9;

    test_msg.ssr_code_biases.biases[9].value = -12299;

    test_msg.ssr_code_biases.biases[10].code = 241;

    test_msg.ssr_code_biases.biases[10].value = -26934;

    test_msg.ssr_code_biases.biases[11].code = 141;

    test_msg.ssr_code_biases.biases[11].value = -24782;

    test_msg.ssr_code_biases.biases[12].code = 220;

    test_msg.ssr_code_biases.biases[12].value = 9611;

    test_msg.ssr_code_biases.biases[13].code = 187;

    test_msg.ssr_code_biases.biases[13].value = -16542;

    test_msg.ssr_code_biases.biases[14].code = 23;

    test_msg.ssr_code_biases.biases[14].value = -30592;

    test_msg.ssr_code_biases.biases[15].code = 167;

    test_msg.ssr_code_biases.biases[15].value = 1736;

    test_msg.ssr_code_biases.biases[16].code = 211;

    test_msg.ssr_code_biases.biases[16].value = 5978;

    test_msg.ssr_code_biases.biases[17].code = 244;

    test_msg.ssr_code_biases.biases[17].value = -10358;

    test_msg.ssr_code_biases.biases[18].code = 209;

    test_msg.ssr_code_biases.biases[18].value = 3467;

    test_msg.ssr_code_biases.biases[19].code = 101;

    test_msg.ssr_code_biases.biases[19].value = 1824;

    test_msg.ssr_code_biases.biases[20].code = 18;

    test_msg.ssr_code_biases.biases[20].value = 17949;

    test_msg.ssr_code_biases.biases[21].code = 250;

    test_msg.ssr_code_biases.biases[21].value = 18797;

    test_msg.ssr_code_biases.biases[22].code = 202;

    test_msg.ssr_code_biases.biases[22].value = -28593;

    test_msg.ssr_code_biases.biases[23].code = 9;

    test_msg.ssr_code_biases.biases[23].value = 17810;

    test_msg.ssr_code_biases.biases[24].code = 241;

    test_msg.ssr_code_biases.biases[24].value = 5684;

    test_msg.ssr_code_biases.biases[25].code = 99;

    test_msg.ssr_code_biases.biases[25].value = -13214;

    test_msg.ssr_code_biases.biases[26].code = 3;

    test_msg.ssr_code_biases.biases[26].value = -6485;

    test_msg.ssr_code_biases.biases[27].code = 180;

    test_msg.ssr_code_biases.biases[27].value = 15947;

    test_msg.ssr_code_biases.biases[28].code = 145;

    test_msg.ssr_code_biases.biases[28].value = -32170;

    test_msg.ssr_code_biases.biases[29].code = 31;

    test_msg.ssr_code_biases.biases[29].value = -25826;

    test_msg.ssr_code_biases.biases[30].code = 37;

    test_msg.ssr_code_biases.biases[30].value = 14098;

    test_msg.ssr_code_biases.biases[31].code = 210;

    test_msg.ssr_code_biases.biases[31].value = 32551;

    test_msg.ssr_code_biases.biases[32].code = 242;

    test_msg.ssr_code_biases.biases[32].value = 3394;

    test_msg.ssr_code_biases.biases[33].code = 237;

    test_msg.ssr_code_biases.biases[33].value = -21864;

    test_msg.ssr_code_biases.biases[34].code = 212;

    test_msg.ssr_code_biases.biases[34].value = -2545;

    test_msg.ssr_code_biases.biases[35].code = 59;

    test_msg.ssr_code_biases.biases[35].value = -19362;

    test_msg.ssr_code_biases.biases[36].code = 195;

    test_msg.ssr_code_biases.biases[36].value = 17821;

    test_msg.ssr_code_biases.biases[37].code = 100;

    test_msg.ssr_code_biases.biases[37].value = 4215;

    test_msg.ssr_code_biases.biases[38].code = 68;

    test_msg.ssr_code_biases.biases[38].value = -20557;

    test_msg.ssr_code_biases.biases[39].code = 144;

    test_msg.ssr_code_biases.biases[39].value = 20849;

    test_msg.ssr_code_biases.biases[40].code = 82;

    test_msg.ssr_code_biases.biases[40].value = -26850;

    test_msg.ssr_code_biases.biases[41].code = 21;

    test_msg.ssr_code_biases.biases[41].value = 10605;

    test_msg.ssr_code_biases.biases[42].code = 225;

    test_msg.ssr_code_biases.biases[42].value = 19720;

    test_msg.ssr_code_biases.biases[43].code = 164;

    test_msg.ssr_code_biases.biases[43].value = 157;

    test_msg.ssr_code_biases.biases[44].code = 73;

    test_msg.ssr_code_biases.biases[44].value = 1566;

    test_msg.ssr_code_biases.biases[45].code = 78;

    test_msg.ssr_code_biases.biases[45].value = -28847;

    test_msg.ssr_code_biases.biases[46].code = 116;

    test_msg.ssr_code_biases.biases[46].value = -26640;

    test_msg.ssr_code_biases.biases[47].code = 55;

    test_msg.ssr_code_biases.biases[47].value = -22087;

    test_msg.ssr_code_biases.biases[48].code = 254;

    test_msg.ssr_code_biases.biases[48].value = 10035;

    test_msg.ssr_code_biases.biases[49].code = 74;

    test_msg.ssr_code_biases.biases[49].value = -2129;

    test_msg.ssr_code_biases.biases[50].code = 34;

    test_msg.ssr_code_biases.biases[50].value = 19041;

    test_msg.ssr_code_biases.biases[51].code = 97;

    test_msg.ssr_code_biases.biases[51].value = 12464;

    test_msg.ssr_code_biases.biases[52].code = 236;

    test_msg.ssr_code_biases.biases[52].value = 3245;

    test_msg.ssr_code_biases.biases[53].code = 174;

    test_msg.ssr_code_biases.biases[53].value = -32155;

    test_msg.ssr_code_biases.biases[54].code = 30;

    test_msg.ssr_code_biases.biases[54].value = -15959;

    test_msg.ssr_code_biases.biases[55].code = 190;

    test_msg.ssr_code_biases.biases[55].value = -15156;

    test_msg.ssr_code_biases.biases[56].code = 123;

    test_msg.ssr_code_biases.biases[56].value = 6507;

    test_msg.ssr_code_biases.biases[57].code = 225;

    test_msg.ssr_code_biases.biases[57].value = 2378;

    test_msg.ssr_code_biases.biases[58].code = 10;

    test_msg.ssr_code_biases.biases[58].value = 823;

    test_msg.ssr_code_biases.biases[59].code = 131;

    test_msg.ssr_code_biases.biases[59].value = 25590;

    test_msg.ssr_code_biases.biases[60].code = 133;

    test_msg.ssr_code_biases.biases[60].value = -7390;

    test_msg.ssr_code_biases.biases[61].code = 203;

    test_msg.ssr_code_biases.biases[61].value = 4676;

    test_msg.ssr_code_biases.biases[62].code = 97;

    test_msg.ssr_code_biases.biases[62].value = 23007;

    test_msg.ssr_code_biases.biases[63].code = 192;

    test_msg.ssr_code_biases.biases[63].value = 13046;

    test_msg.ssr_code_biases.biases[64].code = 69;

    test_msg.ssr_code_biases.biases[64].value = 2651;

    test_msg.ssr_code_biases.biases[65].code = 151;

    test_msg.ssr_code_biases.biases[65].value = 30282;

    test_msg.ssr_code_biases.biases[66].code = 110;

    test_msg.ssr_code_biases.biases[66].value = -22492;

    test_msg.ssr_code_biases.biases[67].code = 247;

    test_msg.ssr_code_biases.biases[67].value = 19872;

    test_msg.ssr_code_biases.biases[68].code = 179;

    test_msg.ssr_code_biases.biases[68].value = -19827;

    test_msg.ssr_code_biases.biases[69].code = 99;

    test_msg.ssr_code_biases.biases[69].value = 30911;

    test_msg.ssr_code_biases.biases[70].code = 77;

    test_msg.ssr_code_biases.biases[70].value = 23488;

    test_msg.ssr_code_biases.biases[71].code = 224;

    test_msg.ssr_code_biases.biases[71].value = -7679;

    test_msg.ssr_code_biases.biases[72].code = 50;

    test_msg.ssr_code_biases.biases[72].value = -28073;

    test_msg.ssr_code_biases.biases[73].code = 148;

    test_msg.ssr_code_biases.biases[73].value = 25838;

    test_msg.ssr_code_biases.biases[74].code = 179;

    test_msg.ssr_code_biases.biases[74].value = -7299;

    test_msg.ssr_code_biases.biases[75].code = 215;

    test_msg.ssr_code_biases.biases[75].value = -18328;

    test_msg.ssr_code_biases.biases[76].code = 31;

    test_msg.ssr_code_biases.biases[76].value = 23097;

    test_msg.ssr_code_biases.biases[77].code = 79;

    test_msg.ssr_code_biases.biases[77].value = -25579;

    test_msg.ssr_code_biases.biases[78].code = 245;

    test_msg.ssr_code_biases.biases[78].value = 15441;

    test_msg.ssr_code_biases.biases[79].code = 93;

    test_msg.ssr_code_biases.biases[79].value = 15530;

    test_msg.ssr_code_biases.biases[80].code = 200;

    test_msg.ssr_code_biases.biases[80].value = 3495;

    test_msg.ssr_code_biases.iod_ssr = 132;

    test_msg.ssr_code_biases.n_biases = 81;

    test_msg.ssr_code_biases.sid.code = 241;

    test_msg.ssr_code_biases.sid.sat = 133;

    test_msg.ssr_code_biases.time.tow = 387144400;

    test_msg.ssr_code_biases.time.wn = 16905;

    test_msg.ssr_code_biases.update_interval = 254;

    sbp_message_send(&sbp_state, SbpMsgSsrCodeBiases, 22311, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 22311)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrCodeBiases, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[0].code, 51)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[0].code, "
           "expected 51, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[0].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[0].value, -31996)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[0].value, "
           "expected -31996, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[0].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[1].code, 240)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[1].code, "
           "expected 240, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[1].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[1].value, 21368)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[1].value, "
           "expected 21368, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[1].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[2].code, 148)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[2].code, "
           "expected 148, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[2].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[2].value, -10799)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[2].value, "
           "expected -10799, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[2].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[3].code, 62)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[3].code, "
           "expected 62, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[3].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[3].value, -5916)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[3].value, "
           "expected -5916, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[3].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[4].code, 71)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[4].code, "
           "expected 71, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[4].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[4].value, -17342)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[4].value, "
           "expected -17342, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[4].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[5].code, 210)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[5].code, "
           "expected 210, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[5].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[5].value, 13952)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[5].value, "
           "expected 13952, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[5].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[6].code, 131)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[6].code, "
           "expected 131, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[6].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[6].value, -32360)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[6].value, "
           "expected -32360, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[6].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[7].code, 111)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[7].code, "
           "expected 111, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[7].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[7].value, -3445)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[7].value, "
           "expected -3445, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[7].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[8].code, 177)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[8].code, "
           "expected 177, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[8].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[8].value, 11409)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[8].value, "
           "expected 11409, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[8].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[9].code, 9)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[9].code, "
           "expected 9, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[9].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[9].value, -12299)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[9].value, "
           "expected -12299, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[9].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[10].code, 241)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[10].code, "
           "expected 241, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[10].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[10].value, -26934)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[10].value, "
           "expected -26934, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[10].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[11].code, 141)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[11].code, "
           "expected 141, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[11].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[11].value, -24782)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[11].value, "
           "expected -24782, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[11].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[12].code, 220)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[12].code, "
           "expected 220, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[12].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[12].value, 9611)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[12].value, "
           "expected 9611, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[12].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[13].code, 187)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[13].code, "
           "expected 187, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[13].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[13].value, -16542)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[13].value, "
           "expected -16542, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[13].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[14].code, 23)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[14].code, "
           "expected 23, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[14].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[14].value, -30592)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[14].value, "
           "expected -30592, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[14].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[15].code, 167)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[15].code, "
           "expected 167, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[15].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[15].value, 1736)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[15].value, "
           "expected 1736, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[15].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[16].code, 211)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[16].code, "
           "expected 211, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[16].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[16].value, 5978)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[16].value, "
           "expected 5978, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[16].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[17].code, 244)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[17].code, "
           "expected 244, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[17].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[17].value, -10358)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[17].value, "
           "expected -10358, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[17].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[18].code, 209)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[18].code, "
           "expected 209, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[18].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[18].value, 3467)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[18].value, "
           "expected 3467, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[18].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[19].code, 101)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[19].code, "
           "expected 101, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[19].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[19].value, 1824)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[19].value, "
           "expected 1824, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[19].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[20].code, 18)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[20].code, "
           "expected 18, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[20].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[20].value, 17949)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[20].value, "
           "expected 17949, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[20].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[21].code, 250)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[21].code, "
           "expected 250, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[21].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[21].value, 18797)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[21].value, "
           "expected 18797, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[21].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[22].code, 202)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[22].code, "
           "expected 202, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[22].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[22].value, -28593)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[22].value, "
           "expected -28593, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[22].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[23].code, 9)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[23].code, "
           "expected 9, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[23].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[23].value, 17810)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[23].value, "
           "expected 17810, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[23].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[24].code, 241)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[24].code, "
           "expected 241, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[24].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[24].value, 5684)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[24].value, "
           "expected 5684, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[24].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[25].code, 99)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[25].code, "
           "expected 99, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[25].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[25].value, -13214)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[25].value, "
           "expected -13214, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[25].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[26].code, 3)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[26].code, "
           "expected 3, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[26].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[26].value, -6485)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[26].value, "
           "expected -6485, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[26].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[27].code, 180)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[27].code, "
           "expected 180, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[27].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[27].value, 15947)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[27].value, "
           "expected 15947, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[27].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[28].code, 145)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[28].code, "
           "expected 145, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[28].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[28].value, -32170)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[28].value, "
           "expected -32170, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[28].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[29].code, 31)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[29].code, "
           "expected 31, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[29].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[29].value, -25826)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[29].value, "
           "expected -25826, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[29].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[30].code, 37)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[30].code, "
           "expected 37, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[30].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[30].value, 14098)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[30].value, "
           "expected 14098, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[30].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[31].code, 210)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[31].code, "
           "expected 210, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[31].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[31].value, 32551)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[31].value, "
           "expected 32551, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[31].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[32].code, 242)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[32].code, "
           "expected 242, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[32].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[32].value, 3394)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[32].value, "
           "expected 3394, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[32].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[33].code, 237)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[33].code, "
           "expected 237, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[33].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[33].value, -21864)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[33].value, "
           "expected -21864, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[33].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[34].code, 212)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[34].code, "
           "expected 212, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[34].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[34].value, -2545)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[34].value, "
           "expected -2545, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[34].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[35].code, 59)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[35].code, "
           "expected 59, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[35].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[35].value, -19362)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[35].value, "
           "expected -19362, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[35].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[36].code, 195)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[36].code, "
           "expected 195, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[36].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[36].value, 17821)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[36].value, "
           "expected 17821, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[36].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[37].code, 100)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[37].code, "
           "expected 100, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[37].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[37].value, 4215)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[37].value, "
           "expected 4215, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[37].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[38].code, 68)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[38].code, "
           "expected 68, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[38].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[38].value, -20557)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[38].value, "
           "expected -20557, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[38].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[39].code, 144)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[39].code, "
           "expected 144, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[39].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[39].value, 20849)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[39].value, "
           "expected 20849, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[39].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[40].code, 82)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[40].code, "
           "expected 82, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[40].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[40].value, -26850)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[40].value, "
           "expected -26850, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[40].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[41].code, 21)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[41].code, "
           "expected 21, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[41].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[41].value, 10605)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[41].value, "
           "expected 10605, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[41].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[42].code, 225)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[42].code, "
           "expected 225, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[42].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[42].value, 19720)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[42].value, "
           "expected 19720, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[42].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[43].code, 164)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[43].code, "
           "expected 164, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[43].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[43].value, 157)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[43].value, "
           "expected 157, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[43].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[44].code, 73)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[44].code, "
           "expected 73, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[44].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[44].value, 1566)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[44].value, "
           "expected 1566, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[44].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[45].code, 78)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[45].code, "
           "expected 78, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[45].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[45].value, -28847)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[45].value, "
           "expected -28847, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[45].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[46].code, 116)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[46].code, "
           "expected 116, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[46].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[46].value, -26640)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[46].value, "
           "expected -26640, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[46].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[47].code, 55)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[47].code, "
           "expected 55, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[47].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[47].value, -22087)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[47].value, "
           "expected -22087, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[47].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[48].code, 254)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[48].code, "
           "expected 254, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[48].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[48].value, 10035)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[48].value, "
           "expected 10035, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[48].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[49].code, 74)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[49].code, "
           "expected 74, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[49].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[49].value, -2129)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[49].value, "
           "expected -2129, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[49].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[50].code, 34)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[50].code, "
           "expected 34, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[50].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[50].value, 19041)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[50].value, "
           "expected 19041, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[50].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[51].code, 97)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[51].code, "
           "expected 97, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[51].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[51].value, 12464)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[51].value, "
           "expected 12464, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[51].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[52].code, 236)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[52].code, "
           "expected 236, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[52].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[52].value, 3245)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[52].value, "
           "expected 3245, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[52].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[53].code, 174)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[53].code, "
           "expected 174, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[53].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[53].value, -32155)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[53].value, "
           "expected -32155, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[53].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[54].code, 30)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[54].code, "
           "expected 30, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[54].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[54].value, -15959)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[54].value, "
           "expected -15959, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[54].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[55].code, 190)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[55].code, "
           "expected 190, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[55].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[55].value, -15156)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[55].value, "
           "expected -15156, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[55].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[56].code, 123)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[56].code, "
           "expected 123, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[56].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[56].value, 6507)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[56].value, "
           "expected 6507, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[56].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[57].code, 225)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[57].code, "
           "expected 225, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[57].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[57].value, 2378)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[57].value, "
           "expected 2378, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[57].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[58].code, 10)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[58].code, "
           "expected 10, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[58].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[58].value, 823)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[58].value, "
           "expected 823, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[58].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[59].code, 131)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[59].code, "
           "expected 131, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[59].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[59].value, 25590)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[59].value, "
           "expected 25590, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[59].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[60].code, 133)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[60].code, "
           "expected 133, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[60].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[60].value, -7390)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[60].value, "
           "expected -7390, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[60].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[61].code, 203)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[61].code, "
           "expected 203, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[61].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[61].value, 4676)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[61].value, "
           "expected 4676, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[61].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[62].code, 97)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[62].code, "
           "expected 97, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[62].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[62].value, 23007)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[62].value, "
           "expected 23007, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[62].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[63].code, 192)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[63].code, "
           "expected 192, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[63].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[63].value, 13046)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[63].value, "
           "expected 13046, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[63].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[64].code, 69)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[64].code, "
           "expected 69, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[64].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[64].value, 2651)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[64].value, "
           "expected 2651, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[64].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[65].code, 151)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[65].code, "
           "expected 151, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[65].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[65].value, 30282)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[65].value, "
           "expected 30282, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[65].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[66].code, 110)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[66].code, "
           "expected 110, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[66].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[66].value, -22492)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[66].value, "
           "expected -22492, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[66].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[67].code, 247)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[67].code, "
           "expected 247, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[67].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[67].value, 19872)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[67].value, "
           "expected 19872, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[67].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[68].code, 179)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[68].code, "
           "expected 179, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[68].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[68].value, -19827)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[68].value, "
           "expected -19827, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[68].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[69].code, 99)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[69].code, "
           "expected 99, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[69].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[69].value, 30911)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[69].value, "
           "expected 30911, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[69].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[70].code, 77)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[70].code, "
           "expected 77, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[70].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[70].value, 23488)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[70].value, "
           "expected 23488, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[70].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[71].code, 224)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[71].code, "
           "expected 224, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[71].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[71].value, -7679)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[71].value, "
           "expected -7679, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[71].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[72].code, 50)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[72].code, "
           "expected 50, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[72].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[72].value, -28073)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[72].value, "
           "expected -28073, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[72].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[73].code, 148)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[73].code, "
           "expected 148, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[73].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[73].value, 25838)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[73].value, "
           "expected 25838, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[73].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[74].code, 179)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[74].code, "
           "expected 179, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[74].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[74].value, -7299)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[74].value, "
           "expected -7299, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[74].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[75].code, 215)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[75].code, "
           "expected 215, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[75].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[75].value, -18328)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[75].value, "
           "expected -18328, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[75].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[76].code, 31)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[76].code, "
           "expected 31, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[76].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[76].value, 23097)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[76].value, "
           "expected 23097, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[76].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[77].code, 79)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[77].code, "
           "expected 79, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[77].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[77].value, -25579)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[77].value, "
           "expected -25579, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[77].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[78].code, 245)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[78].code, "
           "expected 245, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[78].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[78].value, 15441)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[78].value, "
           "expected 15441, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[78].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[79].code, 93)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[79].code, "
           "expected 93, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[79].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[79].value, 15530)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[79].value, "
           "expected 15530, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[79].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[80].code, 200)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[80].code, "
           "expected 200, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[80].code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.biases[80].value, 3495)
        << "incorrect value for last_msg.msg.ssr_code_biases.biases[80].value, "
           "expected 3495, is "
        << (int64_t)last_msg.msg.ssr_code_biases.biases[80].value;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.iod_ssr, 132)
        << "incorrect value for last_msg.msg.ssr_code_biases.iod_ssr, expected "
           "132, is "
        << (int64_t)last_msg.msg.ssr_code_biases.iod_ssr;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.n_biases, 81)
        << "incorrect value for last_msg.msg.ssr_code_biases.n_biases, "
           "expected 81, is "
        << (int64_t)last_msg.msg.ssr_code_biases.n_biases;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.sid.code, 241)
        << "incorrect value for last_msg.msg.ssr_code_biases.sid.code, "
           "expected 241, is "
        << (int64_t)last_msg.msg.ssr_code_biases.sid.code;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.sid.sat, 133)
        << "incorrect value for last_msg.msg.ssr_code_biases.sid.sat, expected "
           "133, is "
        << (int64_t)last_msg.msg.ssr_code_biases.sid.sat;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.time.tow, 387144400)
        << "incorrect value for last_msg.msg.ssr_code_biases.time.tow, "
           "expected 387144400, is "
        << (int64_t)last_msg.msg.ssr_code_biases.time.tow;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.time.wn, 16905)
        << "incorrect value for last_msg.msg.ssr_code_biases.time.wn, expected "
           "16905, is "
        << (int64_t)last_msg.msg.ssr_code_biases.time.wn;

    EXPECT_EQ(last_msg.msg.ssr_code_biases.update_interval, 254)
        << "incorrect value for last_msg.msg.ssr_code_biases.update_interval, "
           "expected 254, is "
        << (int64_t)last_msg.msg.ssr_code_biases.update_interval;
  }
}

}  // namespace
