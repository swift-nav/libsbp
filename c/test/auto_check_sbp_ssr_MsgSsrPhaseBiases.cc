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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrPhaseBiases.yaml by generate.py.
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

TEST(auto_check_sbp_ssr_MsgSsrPhaseBiases,
     test_auto_check_sbp_ssr_MsgSsrPhaseBiases) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrPhaseBiases, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  230, 5,   219, 206, 255, 209, 154, 144, 12,  213, 164, 169, 82,
        177, 230, 98,  209, 249, 22,  17,  29,  250, 245, 193, 219, 30,  212,
        177, 207, 187, 33,  146, 58,  204, 164, 65,  114, 49,  248, 52,  8,
        161, 44,  252, 166, 168, 232, 124, 134, 86,  173, 241, 174, 44,  142,
        155, 129, 143, 184, 161, 211, 15,  36,  189, 208, 194, 221, 152, 16,
        203, 87,  34,  188, 141, 104, 189, 102, 156, 252, 22,  251, 136, 49,
        188, 157, 222, 245, 49,  132, 16,  34,  142, 228, 85,  139, 221, 197,
        235, 98,  74,  107, 70,  36,  38,  239, 251, 112, 188, 124, 246, 141,
        164, 150, 104, 7,   213, 44,  21,  244, 192, 4,   143, 24,  42,  21,
        84,  136, 7,   42,  118, 45,  23,  174, 175, 129, 54,  169, 14,  213,
        2,   197, 98,  60,  13,  207, 105, 100, 129, 72,  136, 240, 140, 129,
        9,   114, 172, 151, 150, 17,  210, 127, 115, 151, 3,   242, 254, 215,
        14,  5,   34,  126, 2,   215, 65,  38,  176, 23,  210, 201, 97,  36,
        207, 92,  224, 26,  116, 155, 211, 165, 47,  102, 38,  67,  199, 55,
        117, 36,  169, 33,  1,   230, 201, 183, 21,  42,  62,  147, 173, 173,
        155, 98,  146, 231, 167, 138, 82,  167, 127, 229, 1,   2,   127, 237,
        207, 116, 90,  115, 159, 3,   42,  66,  145, 250, 201, 7,   251, 2,
        75,  230, 26,  213, 181, 56,  64,  97,  88,  255, 6,   147, 16,  89,
        203, 27,  68,  243, 230, 55,  242, 167, 169, 219, 240,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_phase_biases.biases[0].bias = -1311498533;

    test_msg.ssr_phase_biases.biases[0].code = 29;

    test_msg.ssr_phase_biases.biases[0].discontinuity_counter = 193;

    test_msg.ssr_phase_biases.biases[0].integer_indicator = 250;

    test_msg.ssr_phase_biases.biases[0].widelane_integer_indicator = 245;

    test_msg.ssr_phase_biases.biases[1].bias = 1101319226;

    test_msg.ssr_phase_biases.biases[1].code = 207;

    test_msg.ssr_phase_biases.biases[1].discontinuity_counter = 146;

    test_msg.ssr_phase_biases.biases[1].integer_indicator = 187;

    test_msg.ssr_phase_biases.biases[1].widelane_integer_indicator = 33;

    test_msg.ssr_phase_biases.biases[2].bias = -64184056;

    test_msg.ssr_phase_biases.biases[2].code = 114;

    test_msg.ssr_phase_biases.biases[2].discontinuity_counter = 52;

    test_msg.ssr_phase_biases.biases[2].integer_indicator = 49;

    test_msg.ssr_phase_biases.biases[2].widelane_integer_indicator = 248;

    test_msg.ssr_phase_biases.biases[3].bias = -240298362;

    test_msg.ssr_phase_biases.biases[3].code = 166;

    test_msg.ssr_phase_biases.biases[3].discontinuity_counter = 124;

    test_msg.ssr_phase_biases.biases[3].integer_indicator = 168;

    test_msg.ssr_phase_biases.biases[3].widelane_integer_indicator = 232;

    test_msg.ssr_phase_biases.biases[4].bias = -1581740159;

    test_msg.ssr_phase_biases.biases[4].code = 174;

    test_msg.ssr_phase_biases.biases[4].discontinuity_counter = 155;

    test_msg.ssr_phase_biases.biases[4].integer_indicator = 44;

    test_msg.ssr_phase_biases.biases[4].widelane_integer_indicator = 142;

    test_msg.ssr_phase_biases.biases[5].bias = -1730297136;

    test_msg.ssr_phase_biases.biases[5].code = 211;

    test_msg.ssr_phase_biases.biases[5].discontinuity_counter = 189;

    test_msg.ssr_phase_biases.biases[5].integer_indicator = 15;

    test_msg.ssr_phase_biases.biases[5].widelane_integer_indicator = 36;

    test_msg.ssr_phase_biases.biases[6].bias = -1117221444;

    test_msg.ssr_phase_biases.biases[6].code = 16;

    test_msg.ssr_phase_biases.biases[6].discontinuity_counter = 34;

    test_msg.ssr_phase_biases.biases[6].integer_indicator = 203;

    test_msg.ssr_phase_biases.biases[6].widelane_integer_indicator = 87;

    test_msg.ssr_phase_biases.biases[7].bias = -1137604357;

    test_msg.ssr_phase_biases.biases[7].code = 102;

    test_msg.ssr_phase_biases.biases[7].discontinuity_counter = 22;

    test_msg.ssr_phase_biases.biases[7].integer_indicator = 156;

    test_msg.ssr_phase_biases.biases[7].widelane_integer_indicator = 252;

    test_msg.ssr_phase_biases.biases[8].bias = -1910370172;

    test_msg.ssr_phase_biases.biases[8].code = 157;

    test_msg.ssr_phase_biases.biases[8].discontinuity_counter = 49;

    test_msg.ssr_phase_biases.biases[8].integer_indicator = 222;

    test_msg.ssr_phase_biases.biases[8].widelane_integer_indicator = 245;

    test_msg.ssr_phase_biases.biases[9].bias = 1247996869;

    test_msg.ssr_phase_biases.biases[9].code = 228;

    test_msg.ssr_phase_biases.biases[9].discontinuity_counter = 221;

    test_msg.ssr_phase_biases.biases[9].integer_indicator = 85;

    test_msg.ssr_phase_biases.biases[9].widelane_integer_indicator = 139;

    test_msg.ssr_phase_biases.biases[10].bias = -1133446161;

    test_msg.ssr_phase_biases.biases[10].code = 107;

    test_msg.ssr_phase_biases.biases[10].discontinuity_counter = 38;

    test_msg.ssr_phase_biases.biases[10].integer_indicator = 70;

    test_msg.ssr_phase_biases.biases[10].widelane_integer_indicator = 36;

    test_msg.ssr_phase_biases.biases[11].bias = -720934762;

    test_msg.ssr_phase_biases.biases[11].code = 124;

    test_msg.ssr_phase_biases.biases[11].discontinuity_counter = 164;

    test_msg.ssr_phase_biases.biases[11].integer_indicator = 246;

    test_msg.ssr_phase_biases.biases[11].widelane_integer_indicator = 141;

    test_msg.ssr_phase_biases.biases[12].bias = 706252548;

    test_msg.ssr_phase_biases.biases[12].code = 44;

    test_msg.ssr_phase_biases.biases[12].discontinuity_counter = 192;

    test_msg.ssr_phase_biases.biases[12].integer_indicator = 21;

    test_msg.ssr_phase_biases.biases[12].widelane_integer_indicator = 244;

    test_msg.ssr_phase_biases.biases[13].bias = 388855338;

    test_msg.ssr_phase_biases.biases[13].code = 21;

    test_msg.ssr_phase_biases.biases[13].discontinuity_counter = 7;

    test_msg.ssr_phase_biases.biases[13].integer_indicator = 84;

    test_msg.ssr_phase_biases.biases[13].widelane_integer_indicator = 136;

    test_msg.ssr_phase_biases.biases[14].bias = 47517353;

    test_msg.ssr_phase_biases.biases[14].code = 174;

    test_msg.ssr_phase_biases.biases[14].discontinuity_counter = 54;

    test_msg.ssr_phase_biases.biases[14].integer_indicator = 175;

    test_msg.ssr_phase_biases.biases[14].widelane_integer_indicator = 129;

    test_msg.ssr_phase_biases.biases[15].bias = -2124125745;

    test_msg.ssr_phase_biases.biases[15].code = 197;

    test_msg.ssr_phase_biases.biases[15].discontinuity_counter = 13;

    test_msg.ssr_phase_biases.biases[15].integer_indicator = 98;

    test_msg.ssr_phase_biases.biases[15].widelane_integer_indicator = 60;

    test_msg.ssr_phase_biases.biases[16].bias = -1401812607;

    test_msg.ssr_phase_biases.biases[16].code = 72;

    test_msg.ssr_phase_biases.biases[16].discontinuity_counter = 140;

    test_msg.ssr_phase_biases.biases[16].integer_indicator = 136;

    test_msg.ssr_phase_biases.biases[16].widelane_integer_indicator = 240;

    test_msg.ssr_phase_biases.biases[17].bias = 60257151;

    test_msg.ssr_phase_biases.biases[17].code = 151;

    test_msg.ssr_phase_biases.biases[17].discontinuity_counter = 210;

    test_msg.ssr_phase_biases.biases[17].integer_indicator = 150;

    test_msg.ssr_phase_biases.biases[17].widelane_integer_indicator = 17;

    test_msg.ssr_phase_biases.biases[18].bias = 41820677;

    test_msg.ssr_phase_biases.biases[18].code = 242;

    test_msg.ssr_phase_biases.biases[18].discontinuity_counter = 14;

    test_msg.ssr_phase_biases.biases[18].integer_indicator = 254;

    test_msg.ssr_phase_biases.biases[18].widelane_integer_indicator = 215;

    test_msg.ssr_phase_biases.biases[19].bias = 1640616471;

    test_msg.ssr_phase_biases.biases[19].code = 215;

    test_msg.ssr_phase_biases.biases[19].discontinuity_counter = 176;

    test_msg.ssr_phase_biases.biases[19].integer_indicator = 65;

    test_msg.ssr_phase_biases.biases[19].widelane_integer_indicator = 38;

    test_msg.ssr_phase_biases.biases[20].bias = -744786918;

    test_msg.ssr_phase_biases.biases[20].code = 36;

    test_msg.ssr_phase_biases.biases[20].discontinuity_counter = 224;

    test_msg.ssr_phase_biases.biases[20].integer_indicator = 207;

    test_msg.ssr_phase_biases.biases[20].widelane_integer_indicator = 92;

    test_msg.ssr_phase_biases.biases[21].bias = 1966589763;

    test_msg.ssr_phase_biases.biases[21].code = 165;

    test_msg.ssr_phase_biases.biases[21].discontinuity_counter = 38;

    test_msg.ssr_phase_biases.biases[21].integer_indicator = 47;

    test_msg.ssr_phase_biases.biases[21].widelane_integer_indicator = 102;

    test_msg.ssr_phase_biases.biases[22].bias = 364366310;

    test_msg.ssr_phase_biases.biases[22].code = 36;

    test_msg.ssr_phase_biases.biases[22].discontinuity_counter = 1;

    test_msg.ssr_phase_biases.biases[22].integer_indicator = 169;

    test_msg.ssr_phase_biases.biases[22].widelane_integer_indicator = 33;

    test_msg.ssr_phase_biases.biases[23].bias = -1839031379;

    test_msg.ssr_phase_biases.biases[23].code = 42;

    test_msg.ssr_phase_biases.biases[23].discontinuity_counter = 173;

    test_msg.ssr_phase_biases.biases[23].integer_indicator = 62;

    test_msg.ssr_phase_biases.biases[23].widelane_integer_indicator = 147;

    test_msg.ssr_phase_biases.biases[24].bias = 31817639;

    test_msg.ssr_phase_biases.biases[24].code = 231;

    test_msg.ssr_phase_biases.biases[24].discontinuity_counter = 82;

    test_msg.ssr_phase_biases.biases[24].integer_indicator = 167;

    test_msg.ssr_phase_biases.biases[24].widelane_integer_indicator = 138;

    test_msg.ssr_phase_biases.biases[25].bias = -1619830156;

    test_msg.ssr_phase_biases.biases[25].code = 2;

    test_msg.ssr_phase_biases.biases[25].discontinuity_counter = 207;

    test_msg.ssr_phase_biases.biases[25].integer_indicator = 127;

    test_msg.ssr_phase_biases.biases[25].widelane_integer_indicator = 237;

    test_msg.ssr_phase_biases.biases[26].bias = -83375622;

    test_msg.ssr_phase_biases.biases[26].code = 3;

    test_msg.ssr_phase_biases.biases[26].discontinuity_counter = 145;

    test_msg.ssr_phase_biases.biases[26].integer_indicator = 42;

    test_msg.ssr_phase_biases.biases[26].widelane_integer_indicator = 66;

    test_msg.ssr_phase_biases.biases[27].bias = 1077458389;

    test_msg.ssr_phase_biases.biases[27].code = 2;

    test_msg.ssr_phase_biases.biases[27].discontinuity_counter = 26;

    test_msg.ssr_phase_biases.biases[27].integer_indicator = 75;

    test_msg.ssr_phase_biases.biases[27].widelane_integer_indicator = 230;

    test_msg.ssr_phase_biases.biases[28].bias = -883355501;

    test_msg.ssr_phase_biases.biases[28].code = 97;

    test_msg.ssr_phase_biases.biases[28].discontinuity_counter = 6;

    test_msg.ssr_phase_biases.biases[28].integer_indicator = 88;

    test_msg.ssr_phase_biases.biases[28].widelane_integer_indicator = 255;

    test_msg.ssr_phase_biases.biases[29].bias = -1448611273;

    test_msg.ssr_phase_biases.biases[29].code = 27;

    test_msg.ssr_phase_biases.biases[29].discontinuity_counter = 230;

    test_msg.ssr_phase_biases.biases[29].integer_indicator = 68;

    test_msg.ssr_phase_biases.biases[29].widelane_integer_indicator = 243;

    test_msg.ssr_phase_biases.dispersive_bias = 98;

    test_msg.ssr_phase_biases.iod_ssr = 230;

    test_msg.ssr_phase_biases.mw_consistency = 209;

    test_msg.ssr_phase_biases.n_biases = 30;

    test_msg.ssr_phase_biases.sid.code = 82;

    test_msg.ssr_phase_biases.sid.sat = 169;

    test_msg.ssr_phase_biases.time.tow = 210803409;

    test_msg.ssr_phase_biases.time.wn = 42197;

    test_msg.ssr_phase_biases.update_interval = 177;

    test_msg.ssr_phase_biases.yaw = 5881;

    test_msg.ssr_phase_biases.yaw_rate = 17;

    sbp_message_send(&sbp_state, SbpMsgSsrPhaseBiases, 52955, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 52955)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrPhaseBiases, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[0].bias, -1311498533)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[0].bias, "
           "expected -1311498533, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[0].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[0].code, 29)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[0].code, "
           "expected 29, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[0].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[0].discontinuity_counter,
              193)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[0].discontinuity_counter, "
           "expected 193, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[0]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[0].integer_indicator, 250)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[0].integer_indicator, "
           "expected 250, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[0].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[0].widelane_integer_indicator, 245)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[0].widelane_integer_indicator,"
           " expected 245, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[0]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[1].bias, 1101319226)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[1].bias, "
           "expected 1101319226, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[1].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[1].code, 207)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[1].code, "
           "expected 207, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[1].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[1].discontinuity_counter,
              146)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[1].discontinuity_counter, "
           "expected 146, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[1]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[1].integer_indicator, 187)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[1].integer_indicator, "
           "expected 187, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[1].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[1].widelane_integer_indicator, 33)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[1].widelane_integer_indicator,"
           " expected 33, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[1]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[2].bias, -64184056)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[2].bias, "
           "expected -64184056, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[2].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[2].code, 114)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[2].code, "
           "expected 114, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[2].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[2].discontinuity_counter, 52)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[2].discontinuity_counter, "
           "expected 52, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[2]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[2].integer_indicator, 49)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[2].integer_indicator, "
           "expected 49, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[2].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[2].widelane_integer_indicator, 248)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[2].widelane_integer_indicator,"
           " expected 248, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[2]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[3].bias, -240298362)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[3].bias, "
           "expected -240298362, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[3].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[3].code, 166)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[3].code, "
           "expected 166, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[3].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[3].discontinuity_counter,
              124)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[3].discontinuity_counter, "
           "expected 124, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[3]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[3].integer_indicator, 168)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[3].integer_indicator, "
           "expected 168, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[3].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[3].widelane_integer_indicator, 232)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[3].widelane_integer_indicator,"
           " expected 232, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[3]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[4].bias, -1581740159)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[4].bias, "
           "expected -1581740159, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[4].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[4].code, 174)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[4].code, "
           "expected 174, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[4].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[4].discontinuity_counter,
              155)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[4].discontinuity_counter, "
           "expected 155, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[4]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[4].integer_indicator, 44)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[4].integer_indicator, "
           "expected 44, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[4].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[4].widelane_integer_indicator, 142)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[4].widelane_integer_indicator,"
           " expected 142, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[4]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[5].bias, -1730297136)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[5].bias, "
           "expected -1730297136, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[5].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[5].code, 211)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[5].code, "
           "expected 211, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[5].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[5].discontinuity_counter,
              189)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[5].discontinuity_counter, "
           "expected 189, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[5]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[5].integer_indicator, 15)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[5].integer_indicator, "
           "expected 15, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[5].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[5].widelane_integer_indicator, 36)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[5].widelane_integer_indicator,"
           " expected 36, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[5]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[6].bias, -1117221444)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[6].bias, "
           "expected -1117221444, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[6].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[6].code, 16)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[6].code, "
           "expected 16, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[6].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[6].discontinuity_counter, 34)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[6].discontinuity_counter, "
           "expected 34, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[6]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[6].integer_indicator, 203)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[6].integer_indicator, "
           "expected 203, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[6].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[6].widelane_integer_indicator, 87)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[6].widelane_integer_indicator,"
           " expected 87, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[6]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[7].bias, -1137604357)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[7].bias, "
           "expected -1137604357, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[7].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[7].code, 102)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[7].code, "
           "expected 102, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[7].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[7].discontinuity_counter, 22)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[7].discontinuity_counter, "
           "expected 22, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[7]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[7].integer_indicator, 156)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[7].integer_indicator, "
           "expected 156, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[7].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[7].widelane_integer_indicator, 252)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[7].widelane_integer_indicator,"
           " expected 252, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[7]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[8].bias, -1910370172)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[8].bias, "
           "expected -1910370172, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[8].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[8].code, 157)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[8].code, "
           "expected 157, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[8].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[8].discontinuity_counter, 49)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[8].discontinuity_counter, "
           "expected 49, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[8]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[8].integer_indicator, 222)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[8].integer_indicator, "
           "expected 222, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[8].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[8].widelane_integer_indicator, 245)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[8].widelane_integer_indicator,"
           " expected 245, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[8]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[9].bias, 1247996869)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[9].bias, "
           "expected 1247996869, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[9].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[9].code, 228)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[9].code, "
           "expected 228, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[9].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[9].discontinuity_counter,
              221)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[9].discontinuity_counter, "
           "expected 221, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[9]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[9].integer_indicator, 85)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[9].integer_indicator, "
           "expected 85, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[9].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[9].widelane_integer_indicator, 139)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[9].widelane_integer_indicator,"
           " expected 139, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[9]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[10].bias, -1133446161)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[10].bias, "
           "expected -1133446161, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[10].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[10].code, 107)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[10].code, "
           "expected 107, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[10].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[10].discontinuity_counter,
              38)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[10].discontinuity_counter, "
           "expected 38, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[10]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[10].integer_indicator, 70)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[10].integer_indicator, "
           "expected 70, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[10].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[10].widelane_integer_indicator, 36)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[10].widelane_integer_"
           "indicator, expected 36, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[10]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[11].bias, -720934762)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[11].bias, "
           "expected -720934762, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[11].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[11].code, 124)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[11].code, "
           "expected 124, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[11].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[11].discontinuity_counter,
              164)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[11].discontinuity_counter, "
           "expected 164, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[11]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[11].integer_indicator, 246)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[11].integer_indicator, "
           "expected 246, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[11].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[11].widelane_integer_indicator,
        141)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[11].widelane_integer_"
           "indicator, expected 141, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[11]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[12].bias, 706252548)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[12].bias, "
           "expected 706252548, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[12].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[12].code, 44)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[12].code, "
           "expected 44, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[12].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[12].discontinuity_counter,
              192)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[12].discontinuity_counter, "
           "expected 192, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[12]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[12].integer_indicator, 21)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[12].integer_indicator, "
           "expected 21, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[12].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[12].widelane_integer_indicator,
        244)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[12].widelane_integer_"
           "indicator, expected 244, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[12]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[13].bias, 388855338)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[13].bias, "
           "expected 388855338, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[13].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[13].code, 21)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[13].code, "
           "expected 21, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[13].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[13].discontinuity_counter, 7)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[13].discontinuity_counter, "
           "expected 7, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[13]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[13].integer_indicator, 84)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[13].integer_indicator, "
           "expected 84, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[13].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[13].widelane_integer_indicator,
        136)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[13].widelane_integer_"
           "indicator, expected 136, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[13]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[14].bias, 47517353)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[14].bias, "
           "expected 47517353, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[14].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[14].code, 174)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[14].code, "
           "expected 174, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[14].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[14].discontinuity_counter,
              54)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[14].discontinuity_counter, "
           "expected 54, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[14]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[14].integer_indicator, 175)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[14].integer_indicator, "
           "expected 175, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[14].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[14].widelane_integer_indicator,
        129)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[14].widelane_integer_"
           "indicator, expected 129, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[14]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[15].bias, -2124125745)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[15].bias, "
           "expected -2124125745, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[15].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[15].code, 197)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[15].code, "
           "expected 197, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[15].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[15].discontinuity_counter,
              13)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[15].discontinuity_counter, "
           "expected 13, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[15]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[15].integer_indicator, 98)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[15].integer_indicator, "
           "expected 98, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[15].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[15].widelane_integer_indicator, 60)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[15].widelane_integer_"
           "indicator, expected 60, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[15]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[16].bias, -1401812607)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[16].bias, "
           "expected -1401812607, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[16].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[16].code, 72)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[16].code, "
           "expected 72, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[16].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[16].discontinuity_counter,
              140)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[16].discontinuity_counter, "
           "expected 140, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[16]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[16].integer_indicator, 136)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[16].integer_indicator, "
           "expected 136, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[16].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[16].widelane_integer_indicator,
        240)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[16].widelane_integer_"
           "indicator, expected 240, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[16]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[17].bias, 60257151)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[17].bias, "
           "expected 60257151, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[17].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[17].code, 151)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[17].code, "
           "expected 151, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[17].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[17].discontinuity_counter,
              210)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[17].discontinuity_counter, "
           "expected 210, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[17]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[17].integer_indicator, 150)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[17].integer_indicator, "
           "expected 150, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[17].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[17].widelane_integer_indicator, 17)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[17].widelane_integer_"
           "indicator, expected 17, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[17]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[18].bias, 41820677)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[18].bias, "
           "expected 41820677, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[18].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[18].code, 242)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[18].code, "
           "expected 242, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[18].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[18].discontinuity_counter,
              14)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[18].discontinuity_counter, "
           "expected 14, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[18]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[18].integer_indicator, 254)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[18].integer_indicator, "
           "expected 254, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[18].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[18].widelane_integer_indicator,
        215)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[18].widelane_integer_"
           "indicator, expected 215, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[18]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[19].bias, 1640616471)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[19].bias, "
           "expected 1640616471, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[19].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[19].code, 215)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[19].code, "
           "expected 215, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[19].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[19].discontinuity_counter,
              176)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[19].discontinuity_counter, "
           "expected 176, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[19]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[19].integer_indicator, 65)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[19].integer_indicator, "
           "expected 65, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[19].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[19].widelane_integer_indicator, 38)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[19].widelane_integer_"
           "indicator, expected 38, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[19]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[20].bias, -744786918)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[20].bias, "
           "expected -744786918, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[20].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[20].code, 36)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[20].code, "
           "expected 36, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[20].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[20].discontinuity_counter,
              224)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[20].discontinuity_counter, "
           "expected 224, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[20]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[20].integer_indicator, 207)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[20].integer_indicator, "
           "expected 207, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[20].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[20].widelane_integer_indicator, 92)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[20].widelane_integer_"
           "indicator, expected 92, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[20]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[21].bias, 1966589763)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[21].bias, "
           "expected 1966589763, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[21].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[21].code, 165)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[21].code, "
           "expected 165, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[21].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[21].discontinuity_counter,
              38)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[21].discontinuity_counter, "
           "expected 38, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[21]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[21].integer_indicator, 47)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[21].integer_indicator, "
           "expected 47, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[21].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[21].widelane_integer_indicator,
        102)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[21].widelane_integer_"
           "indicator, expected 102, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[21]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[22].bias, 364366310)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[22].bias, "
           "expected 364366310, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[22].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[22].code, 36)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[22].code, "
           "expected 36, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[22].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[22].discontinuity_counter, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[22].discontinuity_counter, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[22]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[22].integer_indicator, 169)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[22].integer_indicator, "
           "expected 169, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[22].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[22].widelane_integer_indicator, 33)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[22].widelane_integer_"
           "indicator, expected 33, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[22]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[23].bias, -1839031379)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[23].bias, "
           "expected -1839031379, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[23].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[23].code, 42)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[23].code, "
           "expected 42, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[23].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[23].discontinuity_counter,
              173)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[23].discontinuity_counter, "
           "expected 173, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[23]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[23].integer_indicator, 62)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[23].integer_indicator, "
           "expected 62, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[23].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[23].widelane_integer_indicator,
        147)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[23].widelane_integer_"
           "indicator, expected 147, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[23]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[24].bias, 31817639)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[24].bias, "
           "expected 31817639, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[24].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[24].code, 231)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[24].code, "
           "expected 231, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[24].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[24].discontinuity_counter,
              82)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[24].discontinuity_counter, "
           "expected 82, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[24]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[24].integer_indicator, 167)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[24].integer_indicator, "
           "expected 167, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[24].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[24].widelane_integer_indicator,
        138)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[24].widelane_integer_"
           "indicator, expected 138, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[24]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[25].bias, -1619830156)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[25].bias, "
           "expected -1619830156, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[25].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[25].code, 2)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[25].code, "
           "expected 2, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[25].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[25].discontinuity_counter,
              207)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[25].discontinuity_counter, "
           "expected 207, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[25]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[25].integer_indicator, 127)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[25].integer_indicator, "
           "expected 127, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[25].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[25].widelane_integer_indicator,
        237)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[25].widelane_integer_"
           "indicator, expected 237, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[25]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[26].bias, -83375622)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[26].bias, "
           "expected -83375622, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[26].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[26].code, 3)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[26].code, "
           "expected 3, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[26].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[26].discontinuity_counter,
              145)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[26].discontinuity_counter, "
           "expected 145, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[26]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[26].integer_indicator, 42)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[26].integer_indicator, "
           "expected 42, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[26].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[26].widelane_integer_indicator, 66)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[26].widelane_integer_"
           "indicator, expected 66, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[26]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[27].bias, 1077458389)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[27].bias, "
           "expected 1077458389, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[27].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[27].code, 2)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[27].code, "
           "expected 2, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[27].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[27].discontinuity_counter,
              26)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[27].discontinuity_counter, "
           "expected 26, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[27]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[27].integer_indicator, 75)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[27].integer_indicator, "
           "expected 75, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[27].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[27].widelane_integer_indicator,
        230)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[27].widelane_integer_"
           "indicator, expected 230, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[27]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[28].bias, -883355501)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[28].bias, "
           "expected -883355501, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[28].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[28].code, 97)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[28].code, "
           "expected 97, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[28].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[28].discontinuity_counter, 6)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[28].discontinuity_counter, "
           "expected 6, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[28]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[28].integer_indicator, 88)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[28].integer_indicator, "
           "expected 88, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[28].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[28].widelane_integer_indicator,
        255)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[28].widelane_integer_"
           "indicator, expected 255, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[28]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[29].bias, -1448611273)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[29].bias, "
           "expected -1448611273, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[29].bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[29].code, 27)
        << "incorrect value for last_msg.msg.ssr_phase_biases.biases[29].code, "
           "expected 27, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[29].code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[29].discontinuity_counter,
              230)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[29].discontinuity_counter, "
           "expected 230, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[29]
               .discontinuity_counter;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.biases[29].integer_indicator, 68)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[29].integer_indicator, "
           "expected 68, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[29].integer_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_phase_biases.biases[29].widelane_integer_indicator,
        243)
        << "incorrect value for "
           "last_msg.msg.ssr_phase_biases.biases[29].widelane_integer_"
           "indicator, expected 243, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.biases[29]
               .widelane_integer_indicator;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.dispersive_bias, 98)
        << "incorrect value for last_msg.msg.ssr_phase_biases.dispersive_bias, "
           "expected 98, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.dispersive_bias;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.iod_ssr, 230)
        << "incorrect value for last_msg.msg.ssr_phase_biases.iod_ssr, "
           "expected 230, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.iod_ssr;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.mw_consistency, 209)
        << "incorrect value for last_msg.msg.ssr_phase_biases.mw_consistency, "
           "expected 209, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.mw_consistency;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.n_biases, 30)
        << "incorrect value for last_msg.msg.ssr_phase_biases.n_biases, "
           "expected 30, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.n_biases;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.sid.code, 82)
        << "incorrect value for last_msg.msg.ssr_phase_biases.sid.code, "
           "expected 82, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.sid.code;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.sid.sat, 169)
        << "incorrect value for last_msg.msg.ssr_phase_biases.sid.sat, "
           "expected 169, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.sid.sat;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.time.tow, 210803409)
        << "incorrect value for last_msg.msg.ssr_phase_biases.time.tow, "
           "expected 210803409, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.time.tow;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.time.wn, 42197)
        << "incorrect value for last_msg.msg.ssr_phase_biases.time.wn, "
           "expected 42197, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.time.wn;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.update_interval, 177)
        << "incorrect value for last_msg.msg.ssr_phase_biases.update_interval, "
           "expected 177, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.update_interval;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.yaw, 5881)
        << "incorrect value for last_msg.msg.ssr_phase_biases.yaw, expected "
           "5881, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.yaw;

    EXPECT_EQ(last_msg.msg.ssr_phase_biases.yaw_rate, 17)
        << "incorrect value for last_msg.msg.ssr_phase_biases.yaw_rate, "
           "expected 17, is "
        << (int64_t)last_msg.msg.ssr_phase_biases.yaw_rate;
  }
}

}  // namespace
