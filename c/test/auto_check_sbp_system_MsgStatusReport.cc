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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusReport.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/system.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_system_MsgStatusReport,
     test_auto_check_sbp_system_MsgStatusReport) {
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

    sbp_callback_register(&sbp_state, SbpMsgStatusReport, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  254, 255, 6,   84,  252, 82,  253, 177, 95,  3,   60,  143, 90,
        233, 21,  208, 98,  247, 203, 221, 198, 156, 207, 217, 238, 162, 136,
        154, 11,  114, 236, 134, 235, 12,  133, 9,   30,  175, 145, 26,  114,
        215, 20,  146, 249, 54,  54,  133, 193, 106, 186, 210, 183, 0,   129,
        5,   248, 225, 149, 135, 127, 2,   26,  88,  92,  10,  103, 73,  3,
        103, 68,  76,  184, 33,  206, 194, 163, 123, 30,  151, 176, 149, 172,
        184, 231, 118, 230, 200, 168, 100, 109, 10,  233, 4,   60,  247, 82,
        215, 166, 28,  138, 110, 45,  98,  218, 244, 179, 126, 107, 92,  124,
        94,  157, 42,  187, 124, 6,   97,  247, 160, 188, 110, 120, 254, 214,
        110, 51,  240, 164, 147, 18,  74,  178, 67,  4,   27,  73,  190, 64,
        179, 146, 125, 153, 192, 46,  202, 66,  248, 46,  40,  161, 173, 242,
        214, 3,   11,  1,   118, 70,  162, 61,  178, 27,  156, 40,  191, 113,
        230, 200, 72,  8,   215, 245, 78,  59,  222, 250, 115, 32,  33,  30,
        211, 170, 145, 92,  157, 75,  24,  169, 6,   55,  62,  8,   107, 82,
        140, 49,  179, 122, 90,  71,  28,  88,  103, 51,  177, 72,  93,  39,
        148, 11,  202, 42,  34,  92,  204, 102, 29,  98,  249, 91,  134, 95,
        23,  248, 192, 20,  83,  195, 95,  180, 54,  36,  186, 75,  64,  20,
        157, 133, 12,  149, 28,  14,  185, 129, 101, 239, 74,  248, 245, 30,
        228, 88,  142, 212, 53,  224, 158, 166,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.status_report.n_status = 60;

    test_msg.status_report.reporting_system = 64850;

    test_msg.status_report.sbp_version = 24497;

    test_msg.status_report.sequence = 1519336451;

    test_msg.status_report.status[0].component = 52215;

    test_msg.status_report.status[0].generic = 221;

    test_msg.status_report.status[0].specific = 198;

    test_msg.status_report.status[1].component = 53148;

    test_msg.status_report.status[1].generic = 217;

    test_msg.status_report.status[1].specific = 238;

    test_msg.status_report.status[2].component = 34978;

    test_msg.status_report.status[2].generic = 154;

    test_msg.status_report.status[2].specific = 11;

    test_msg.status_report.status[3].component = 60530;

    test_msg.status_report.status[3].generic = 134;

    test_msg.status_report.status[3].specific = 235;

    test_msg.status_report.status[4].component = 34060;

    test_msg.status_report.status[4].generic = 9;

    test_msg.status_report.status[4].specific = 30;

    test_msg.status_report.status[5].component = 37295;

    test_msg.status_report.status[5].generic = 26;

    test_msg.status_report.status[5].specific = 114;

    test_msg.status_report.status[6].component = 5335;

    test_msg.status_report.status[6].generic = 146;

    test_msg.status_report.status[6].specific = 249;

    test_msg.status_report.status[7].component = 13878;

    test_msg.status_report.status[7].generic = 133;

    test_msg.status_report.status[7].specific = 193;

    test_msg.status_report.status[8].component = 47722;

    test_msg.status_report.status[8].generic = 210;

    test_msg.status_report.status[8].specific = 183;

    test_msg.status_report.status[9].component = 33024;

    test_msg.status_report.status[9].generic = 5;

    test_msg.status_report.status[9].specific = 248;

    test_msg.status_report.status[10].component = 38369;

    test_msg.status_report.status[10].generic = 135;

    test_msg.status_report.status[10].specific = 127;

    test_msg.status_report.status[11].component = 6658;

    test_msg.status_report.status[11].generic = 88;

    test_msg.status_report.status[11].specific = 92;

    test_msg.status_report.status[12].component = 26378;

    test_msg.status_report.status[12].generic = 73;

    test_msg.status_report.status[12].specific = 3;

    test_msg.status_report.status[13].component = 17511;

    test_msg.status_report.status[13].generic = 76;

    test_msg.status_report.status[13].specific = 184;

    test_msg.status_report.status[14].component = 52769;

    test_msg.status_report.status[14].generic = 194;

    test_msg.status_report.status[14].specific = 163;

    test_msg.status_report.status[15].component = 7803;

    test_msg.status_report.status[15].generic = 151;

    test_msg.status_report.status[15].specific = 176;

    test_msg.status_report.status[16].component = 44181;

    test_msg.status_report.status[16].generic = 184;

    test_msg.status_report.status[16].specific = 231;

    test_msg.status_report.status[17].component = 58998;

    test_msg.status_report.status[17].generic = 200;

    test_msg.status_report.status[17].specific = 168;

    test_msg.status_report.status[18].component = 28004;

    test_msg.status_report.status[18].generic = 10;

    test_msg.status_report.status[18].specific = 233;

    test_msg.status_report.status[19].component = 15364;

    test_msg.status_report.status[19].generic = 247;

    test_msg.status_report.status[19].specific = 82;

    test_msg.status_report.status[20].component = 42711;

    test_msg.status_report.status[20].generic = 28;

    test_msg.status_report.status[20].specific = 138;

    test_msg.status_report.status[21].component = 11630;

    test_msg.status_report.status[21].generic = 98;

    test_msg.status_report.status[21].specific = 218;

    test_msg.status_report.status[22].component = 46068;

    test_msg.status_report.status[22].generic = 126;

    test_msg.status_report.status[22].specific = 107;

    test_msg.status_report.status[23].component = 31836;

    test_msg.status_report.status[23].generic = 94;

    test_msg.status_report.status[23].specific = 157;

    test_msg.status_report.status[24].component = 47914;

    test_msg.status_report.status[24].generic = 124;

    test_msg.status_report.status[24].specific = 6;

    test_msg.status_report.status[25].component = 63329;

    test_msg.status_report.status[25].generic = 160;

    test_msg.status_report.status[25].specific = 188;

    test_msg.status_report.status[26].component = 30830;

    test_msg.status_report.status[26].generic = 254;

    test_msg.status_report.status[26].specific = 214;

    test_msg.status_report.status[27].component = 13166;

    test_msg.status_report.status[27].generic = 240;

    test_msg.status_report.status[27].specific = 164;

    test_msg.status_report.status[28].component = 4755;

    test_msg.status_report.status[28].generic = 74;

    test_msg.status_report.status[28].specific = 178;

    test_msg.status_report.status[29].component = 1091;

    test_msg.status_report.status[29].generic = 27;

    test_msg.status_report.status[29].specific = 73;

    test_msg.status_report.status[30].component = 16574;

    test_msg.status_report.status[30].generic = 179;

    test_msg.status_report.status[30].specific = 146;

    test_msg.status_report.status[31].component = 39293;

    test_msg.status_report.status[31].generic = 192;

    test_msg.status_report.status[31].specific = 46;

    test_msg.status_report.status[32].component = 17098;

    test_msg.status_report.status[32].generic = 248;

    test_msg.status_report.status[32].specific = 46;

    test_msg.status_report.status[33].component = 41256;

    test_msg.status_report.status[33].generic = 173;

    test_msg.status_report.status[33].specific = 242;

    test_msg.status_report.status[34].component = 982;

    test_msg.status_report.status[34].generic = 11;

    test_msg.status_report.status[34].specific = 1;

    test_msg.status_report.status[35].component = 18038;

    test_msg.status_report.status[35].generic = 162;

    test_msg.status_report.status[35].specific = 61;

    test_msg.status_report.status[36].component = 7090;

    test_msg.status_report.status[36].generic = 156;

    test_msg.status_report.status[36].specific = 40;

    test_msg.status_report.status[37].component = 29119;

    test_msg.status_report.status[37].generic = 230;

    test_msg.status_report.status[37].specific = 200;

    test_msg.status_report.status[38].component = 2120;

    test_msg.status_report.status[38].generic = 215;

    test_msg.status_report.status[38].specific = 245;

    test_msg.status_report.status[39].component = 15182;

    test_msg.status_report.status[39].generic = 222;

    test_msg.status_report.status[39].specific = 250;

    test_msg.status_report.status[40].component = 8307;

    test_msg.status_report.status[40].generic = 33;

    test_msg.status_report.status[40].specific = 30;

    test_msg.status_report.status[41].component = 43731;

    test_msg.status_report.status[41].generic = 145;

    test_msg.status_report.status[41].specific = 92;

    test_msg.status_report.status[42].component = 19357;

    test_msg.status_report.status[42].generic = 24;

    test_msg.status_report.status[42].specific = 169;

    test_msg.status_report.status[43].component = 14086;

    test_msg.status_report.status[43].generic = 62;

    test_msg.status_report.status[43].specific = 8;

    test_msg.status_report.status[44].component = 21099;

    test_msg.status_report.status[44].generic = 140;

    test_msg.status_report.status[44].specific = 49;

    test_msg.status_report.status[45].component = 31411;

    test_msg.status_report.status[45].generic = 90;

    test_msg.status_report.status[45].specific = 71;

    test_msg.status_report.status[46].component = 22556;

    test_msg.status_report.status[46].generic = 103;

    test_msg.status_report.status[46].specific = 51;

    test_msg.status_report.status[47].component = 18609;

    test_msg.status_report.status[47].generic = 93;

    test_msg.status_report.status[47].specific = 39;

    test_msg.status_report.status[48].component = 2964;

    test_msg.status_report.status[48].generic = 202;

    test_msg.status_report.status[48].specific = 42;

    test_msg.status_report.status[49].component = 23586;

    test_msg.status_report.status[49].generic = 204;

    test_msg.status_report.status[49].specific = 102;

    test_msg.status_report.status[50].component = 25117;

    test_msg.status_report.status[50].generic = 249;

    test_msg.status_report.status[50].specific = 91;

    test_msg.status_report.status[51].component = 24454;

    test_msg.status_report.status[51].generic = 23;

    test_msg.status_report.status[51].specific = 248;

    test_msg.status_report.status[52].component = 5312;

    test_msg.status_report.status[52].generic = 83;

    test_msg.status_report.status[52].specific = 195;

    test_msg.status_report.status[53].component = 46175;

    test_msg.status_report.status[53].generic = 54;

    test_msg.status_report.status[53].specific = 36;

    test_msg.status_report.status[54].component = 19386;

    test_msg.status_report.status[54].generic = 64;

    test_msg.status_report.status[54].specific = 20;

    test_msg.status_report.status[55].component = 34205;

    test_msg.status_report.status[55].generic = 12;

    test_msg.status_report.status[55].specific = 149;

    test_msg.status_report.status[56].component = 3612;

    test_msg.status_report.status[56].generic = 185;

    test_msg.status_report.status[56].specific = 129;

    test_msg.status_report.status[57].component = 61285;

    test_msg.status_report.status[57].generic = 74;

    test_msg.status_report.status[57].specific = 248;

    test_msg.status_report.status[58].component = 7925;

    test_msg.status_report.status[58].generic = 228;

    test_msg.status_report.status[58].specific = 88;

    test_msg.status_report.status[59].component = 54414;

    test_msg.status_report.status[59].generic = 53;

    test_msg.status_report.status[59].specific = 224;

    test_msg.status_report.uptime = 1657804265;

    sbp_message_send(&sbp_state, SbpMsgStatusReport, 21510, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 21510)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgStatusReport, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.status_report.n_status, 60)
        << "incorrect value for last_msg.msg.status_report.n_status, expected "
           "60, is "
        << (int64_t)last_msg.msg.status_report.n_status;

    EXPECT_EQ(last_msg.msg.status_report.reporting_system, 64850)
        << "incorrect value for last_msg.msg.status_report.reporting_system, "
           "expected 64850, is "
        << (int64_t)last_msg.msg.status_report.reporting_system;

    EXPECT_EQ(last_msg.msg.status_report.sbp_version, 24497)
        << "incorrect value for last_msg.msg.status_report.sbp_version, "
           "expected 24497, is "
        << (int64_t)last_msg.msg.status_report.sbp_version;

    EXPECT_EQ(last_msg.msg.status_report.sequence, 1519336451)
        << "incorrect value for last_msg.msg.status_report.sequence, expected "
           "1519336451, is "
        << (int64_t)last_msg.msg.status_report.sequence;

    EXPECT_EQ(last_msg.msg.status_report.status[0].component, 52215)
        << "incorrect value for "
           "last_msg.msg.status_report.status[0].component, expected 52215, is "
        << (int64_t)last_msg.msg.status_report.status[0].component;

    EXPECT_EQ(last_msg.msg.status_report.status[0].generic, 221)
        << "incorrect value for last_msg.msg.status_report.status[0].generic, "
           "expected 221, is "
        << (int64_t)last_msg.msg.status_report.status[0].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[0].specific, 198)
        << "incorrect value for last_msg.msg.status_report.status[0].specific, "
           "expected 198, is "
        << (int64_t)last_msg.msg.status_report.status[0].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[1].component, 53148)
        << "incorrect value for "
           "last_msg.msg.status_report.status[1].component, expected 53148, is "
        << (int64_t)last_msg.msg.status_report.status[1].component;

    EXPECT_EQ(last_msg.msg.status_report.status[1].generic, 217)
        << "incorrect value for last_msg.msg.status_report.status[1].generic, "
           "expected 217, is "
        << (int64_t)last_msg.msg.status_report.status[1].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[1].specific, 238)
        << "incorrect value for last_msg.msg.status_report.status[1].specific, "
           "expected 238, is "
        << (int64_t)last_msg.msg.status_report.status[1].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[2].component, 34978)
        << "incorrect value for "
           "last_msg.msg.status_report.status[2].component, expected 34978, is "
        << (int64_t)last_msg.msg.status_report.status[2].component;

    EXPECT_EQ(last_msg.msg.status_report.status[2].generic, 154)
        << "incorrect value for last_msg.msg.status_report.status[2].generic, "
           "expected 154, is "
        << (int64_t)last_msg.msg.status_report.status[2].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[2].specific, 11)
        << "incorrect value for last_msg.msg.status_report.status[2].specific, "
           "expected 11, is "
        << (int64_t)last_msg.msg.status_report.status[2].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[3].component, 60530)
        << "incorrect value for "
           "last_msg.msg.status_report.status[3].component, expected 60530, is "
        << (int64_t)last_msg.msg.status_report.status[3].component;

    EXPECT_EQ(last_msg.msg.status_report.status[3].generic, 134)
        << "incorrect value for last_msg.msg.status_report.status[3].generic, "
           "expected 134, is "
        << (int64_t)last_msg.msg.status_report.status[3].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[3].specific, 235)
        << "incorrect value for last_msg.msg.status_report.status[3].specific, "
           "expected 235, is "
        << (int64_t)last_msg.msg.status_report.status[3].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[4].component, 34060)
        << "incorrect value for "
           "last_msg.msg.status_report.status[4].component, expected 34060, is "
        << (int64_t)last_msg.msg.status_report.status[4].component;

    EXPECT_EQ(last_msg.msg.status_report.status[4].generic, 9)
        << "incorrect value for last_msg.msg.status_report.status[4].generic, "
           "expected 9, is "
        << (int64_t)last_msg.msg.status_report.status[4].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[4].specific, 30)
        << "incorrect value for last_msg.msg.status_report.status[4].specific, "
           "expected 30, is "
        << (int64_t)last_msg.msg.status_report.status[4].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[5].component, 37295)
        << "incorrect value for "
           "last_msg.msg.status_report.status[5].component, expected 37295, is "
        << (int64_t)last_msg.msg.status_report.status[5].component;

    EXPECT_EQ(last_msg.msg.status_report.status[5].generic, 26)
        << "incorrect value for last_msg.msg.status_report.status[5].generic, "
           "expected 26, is "
        << (int64_t)last_msg.msg.status_report.status[5].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[5].specific, 114)
        << "incorrect value for last_msg.msg.status_report.status[5].specific, "
           "expected 114, is "
        << (int64_t)last_msg.msg.status_report.status[5].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[6].component, 5335)
        << "incorrect value for "
           "last_msg.msg.status_report.status[6].component, expected 5335, is "
        << (int64_t)last_msg.msg.status_report.status[6].component;

    EXPECT_EQ(last_msg.msg.status_report.status[6].generic, 146)
        << "incorrect value for last_msg.msg.status_report.status[6].generic, "
           "expected 146, is "
        << (int64_t)last_msg.msg.status_report.status[6].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[6].specific, 249)
        << "incorrect value for last_msg.msg.status_report.status[6].specific, "
           "expected 249, is "
        << (int64_t)last_msg.msg.status_report.status[6].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[7].component, 13878)
        << "incorrect value for "
           "last_msg.msg.status_report.status[7].component, expected 13878, is "
        << (int64_t)last_msg.msg.status_report.status[7].component;

    EXPECT_EQ(last_msg.msg.status_report.status[7].generic, 133)
        << "incorrect value for last_msg.msg.status_report.status[7].generic, "
           "expected 133, is "
        << (int64_t)last_msg.msg.status_report.status[7].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[7].specific, 193)
        << "incorrect value for last_msg.msg.status_report.status[7].specific, "
           "expected 193, is "
        << (int64_t)last_msg.msg.status_report.status[7].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[8].component, 47722)
        << "incorrect value for "
           "last_msg.msg.status_report.status[8].component, expected 47722, is "
        << (int64_t)last_msg.msg.status_report.status[8].component;

    EXPECT_EQ(last_msg.msg.status_report.status[8].generic, 210)
        << "incorrect value for last_msg.msg.status_report.status[8].generic, "
           "expected 210, is "
        << (int64_t)last_msg.msg.status_report.status[8].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[8].specific, 183)
        << "incorrect value for last_msg.msg.status_report.status[8].specific, "
           "expected 183, is "
        << (int64_t)last_msg.msg.status_report.status[8].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[9].component, 33024)
        << "incorrect value for "
           "last_msg.msg.status_report.status[9].component, expected 33024, is "
        << (int64_t)last_msg.msg.status_report.status[9].component;

    EXPECT_EQ(last_msg.msg.status_report.status[9].generic, 5)
        << "incorrect value for last_msg.msg.status_report.status[9].generic, "
           "expected 5, is "
        << (int64_t)last_msg.msg.status_report.status[9].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[9].specific, 248)
        << "incorrect value for last_msg.msg.status_report.status[9].specific, "
           "expected 248, is "
        << (int64_t)last_msg.msg.status_report.status[9].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[10].component, 38369)
        << "incorrect value for "
           "last_msg.msg.status_report.status[10].component, expected 38369, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[10].component;

    EXPECT_EQ(last_msg.msg.status_report.status[10].generic, 135)
        << "incorrect value for last_msg.msg.status_report.status[10].generic, "
           "expected 135, is "
        << (int64_t)last_msg.msg.status_report.status[10].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[10].specific, 127)
        << "incorrect value for "
           "last_msg.msg.status_report.status[10].specific, expected 127, is "
        << (int64_t)last_msg.msg.status_report.status[10].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[11].component, 6658)
        << "incorrect value for "
           "last_msg.msg.status_report.status[11].component, expected 6658, is "
        << (int64_t)last_msg.msg.status_report.status[11].component;

    EXPECT_EQ(last_msg.msg.status_report.status[11].generic, 88)
        << "incorrect value for last_msg.msg.status_report.status[11].generic, "
           "expected 88, is "
        << (int64_t)last_msg.msg.status_report.status[11].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[11].specific, 92)
        << "incorrect value for "
           "last_msg.msg.status_report.status[11].specific, expected 92, is "
        << (int64_t)last_msg.msg.status_report.status[11].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[12].component, 26378)
        << "incorrect value for "
           "last_msg.msg.status_report.status[12].component, expected 26378, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[12].component;

    EXPECT_EQ(last_msg.msg.status_report.status[12].generic, 73)
        << "incorrect value for last_msg.msg.status_report.status[12].generic, "
           "expected 73, is "
        << (int64_t)last_msg.msg.status_report.status[12].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[12].specific, 3)
        << "incorrect value for "
           "last_msg.msg.status_report.status[12].specific, expected 3, is "
        << (int64_t)last_msg.msg.status_report.status[12].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[13].component, 17511)
        << "incorrect value for "
           "last_msg.msg.status_report.status[13].component, expected 17511, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[13].component;

    EXPECT_EQ(last_msg.msg.status_report.status[13].generic, 76)
        << "incorrect value for last_msg.msg.status_report.status[13].generic, "
           "expected 76, is "
        << (int64_t)last_msg.msg.status_report.status[13].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[13].specific, 184)
        << "incorrect value for "
           "last_msg.msg.status_report.status[13].specific, expected 184, is "
        << (int64_t)last_msg.msg.status_report.status[13].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[14].component, 52769)
        << "incorrect value for "
           "last_msg.msg.status_report.status[14].component, expected 52769, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[14].component;

    EXPECT_EQ(last_msg.msg.status_report.status[14].generic, 194)
        << "incorrect value for last_msg.msg.status_report.status[14].generic, "
           "expected 194, is "
        << (int64_t)last_msg.msg.status_report.status[14].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[14].specific, 163)
        << "incorrect value for "
           "last_msg.msg.status_report.status[14].specific, expected 163, is "
        << (int64_t)last_msg.msg.status_report.status[14].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[15].component, 7803)
        << "incorrect value for "
           "last_msg.msg.status_report.status[15].component, expected 7803, is "
        << (int64_t)last_msg.msg.status_report.status[15].component;

    EXPECT_EQ(last_msg.msg.status_report.status[15].generic, 151)
        << "incorrect value for last_msg.msg.status_report.status[15].generic, "
           "expected 151, is "
        << (int64_t)last_msg.msg.status_report.status[15].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[15].specific, 176)
        << "incorrect value for "
           "last_msg.msg.status_report.status[15].specific, expected 176, is "
        << (int64_t)last_msg.msg.status_report.status[15].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[16].component, 44181)
        << "incorrect value for "
           "last_msg.msg.status_report.status[16].component, expected 44181, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[16].component;

    EXPECT_EQ(last_msg.msg.status_report.status[16].generic, 184)
        << "incorrect value for last_msg.msg.status_report.status[16].generic, "
           "expected 184, is "
        << (int64_t)last_msg.msg.status_report.status[16].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[16].specific, 231)
        << "incorrect value for "
           "last_msg.msg.status_report.status[16].specific, expected 231, is "
        << (int64_t)last_msg.msg.status_report.status[16].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[17].component, 58998)
        << "incorrect value for "
           "last_msg.msg.status_report.status[17].component, expected 58998, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[17].component;

    EXPECT_EQ(last_msg.msg.status_report.status[17].generic, 200)
        << "incorrect value for last_msg.msg.status_report.status[17].generic, "
           "expected 200, is "
        << (int64_t)last_msg.msg.status_report.status[17].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[17].specific, 168)
        << "incorrect value for "
           "last_msg.msg.status_report.status[17].specific, expected 168, is "
        << (int64_t)last_msg.msg.status_report.status[17].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[18].component, 28004)
        << "incorrect value for "
           "last_msg.msg.status_report.status[18].component, expected 28004, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[18].component;

    EXPECT_EQ(last_msg.msg.status_report.status[18].generic, 10)
        << "incorrect value for last_msg.msg.status_report.status[18].generic, "
           "expected 10, is "
        << (int64_t)last_msg.msg.status_report.status[18].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[18].specific, 233)
        << "incorrect value for "
           "last_msg.msg.status_report.status[18].specific, expected 233, is "
        << (int64_t)last_msg.msg.status_report.status[18].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[19].component, 15364)
        << "incorrect value for "
           "last_msg.msg.status_report.status[19].component, expected 15364, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[19].component;

    EXPECT_EQ(last_msg.msg.status_report.status[19].generic, 247)
        << "incorrect value for last_msg.msg.status_report.status[19].generic, "
           "expected 247, is "
        << (int64_t)last_msg.msg.status_report.status[19].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[19].specific, 82)
        << "incorrect value for "
           "last_msg.msg.status_report.status[19].specific, expected 82, is "
        << (int64_t)last_msg.msg.status_report.status[19].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[20].component, 42711)
        << "incorrect value for "
           "last_msg.msg.status_report.status[20].component, expected 42711, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[20].component;

    EXPECT_EQ(last_msg.msg.status_report.status[20].generic, 28)
        << "incorrect value for last_msg.msg.status_report.status[20].generic, "
           "expected 28, is "
        << (int64_t)last_msg.msg.status_report.status[20].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[20].specific, 138)
        << "incorrect value for "
           "last_msg.msg.status_report.status[20].specific, expected 138, is "
        << (int64_t)last_msg.msg.status_report.status[20].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[21].component, 11630)
        << "incorrect value for "
           "last_msg.msg.status_report.status[21].component, expected 11630, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[21].component;

    EXPECT_EQ(last_msg.msg.status_report.status[21].generic, 98)
        << "incorrect value for last_msg.msg.status_report.status[21].generic, "
           "expected 98, is "
        << (int64_t)last_msg.msg.status_report.status[21].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[21].specific, 218)
        << "incorrect value for "
           "last_msg.msg.status_report.status[21].specific, expected 218, is "
        << (int64_t)last_msg.msg.status_report.status[21].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[22].component, 46068)
        << "incorrect value for "
           "last_msg.msg.status_report.status[22].component, expected 46068, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[22].component;

    EXPECT_EQ(last_msg.msg.status_report.status[22].generic, 126)
        << "incorrect value for last_msg.msg.status_report.status[22].generic, "
           "expected 126, is "
        << (int64_t)last_msg.msg.status_report.status[22].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[22].specific, 107)
        << "incorrect value for "
           "last_msg.msg.status_report.status[22].specific, expected 107, is "
        << (int64_t)last_msg.msg.status_report.status[22].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[23].component, 31836)
        << "incorrect value for "
           "last_msg.msg.status_report.status[23].component, expected 31836, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[23].component;

    EXPECT_EQ(last_msg.msg.status_report.status[23].generic, 94)
        << "incorrect value for last_msg.msg.status_report.status[23].generic, "
           "expected 94, is "
        << (int64_t)last_msg.msg.status_report.status[23].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[23].specific, 157)
        << "incorrect value for "
           "last_msg.msg.status_report.status[23].specific, expected 157, is "
        << (int64_t)last_msg.msg.status_report.status[23].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[24].component, 47914)
        << "incorrect value for "
           "last_msg.msg.status_report.status[24].component, expected 47914, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[24].component;

    EXPECT_EQ(last_msg.msg.status_report.status[24].generic, 124)
        << "incorrect value for last_msg.msg.status_report.status[24].generic, "
           "expected 124, is "
        << (int64_t)last_msg.msg.status_report.status[24].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[24].specific, 6)
        << "incorrect value for "
           "last_msg.msg.status_report.status[24].specific, expected 6, is "
        << (int64_t)last_msg.msg.status_report.status[24].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[25].component, 63329)
        << "incorrect value for "
           "last_msg.msg.status_report.status[25].component, expected 63329, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[25].component;

    EXPECT_EQ(last_msg.msg.status_report.status[25].generic, 160)
        << "incorrect value for last_msg.msg.status_report.status[25].generic, "
           "expected 160, is "
        << (int64_t)last_msg.msg.status_report.status[25].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[25].specific, 188)
        << "incorrect value for "
           "last_msg.msg.status_report.status[25].specific, expected 188, is "
        << (int64_t)last_msg.msg.status_report.status[25].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[26].component, 30830)
        << "incorrect value for "
           "last_msg.msg.status_report.status[26].component, expected 30830, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[26].component;

    EXPECT_EQ(last_msg.msg.status_report.status[26].generic, 254)
        << "incorrect value for last_msg.msg.status_report.status[26].generic, "
           "expected 254, is "
        << (int64_t)last_msg.msg.status_report.status[26].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[26].specific, 214)
        << "incorrect value for "
           "last_msg.msg.status_report.status[26].specific, expected 214, is "
        << (int64_t)last_msg.msg.status_report.status[26].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[27].component, 13166)
        << "incorrect value for "
           "last_msg.msg.status_report.status[27].component, expected 13166, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[27].component;

    EXPECT_EQ(last_msg.msg.status_report.status[27].generic, 240)
        << "incorrect value for last_msg.msg.status_report.status[27].generic, "
           "expected 240, is "
        << (int64_t)last_msg.msg.status_report.status[27].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[27].specific, 164)
        << "incorrect value for "
           "last_msg.msg.status_report.status[27].specific, expected 164, is "
        << (int64_t)last_msg.msg.status_report.status[27].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[28].component, 4755)
        << "incorrect value for "
           "last_msg.msg.status_report.status[28].component, expected 4755, is "
        << (int64_t)last_msg.msg.status_report.status[28].component;

    EXPECT_EQ(last_msg.msg.status_report.status[28].generic, 74)
        << "incorrect value for last_msg.msg.status_report.status[28].generic, "
           "expected 74, is "
        << (int64_t)last_msg.msg.status_report.status[28].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[28].specific, 178)
        << "incorrect value for "
           "last_msg.msg.status_report.status[28].specific, expected 178, is "
        << (int64_t)last_msg.msg.status_report.status[28].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[29].component, 1091)
        << "incorrect value for "
           "last_msg.msg.status_report.status[29].component, expected 1091, is "
        << (int64_t)last_msg.msg.status_report.status[29].component;

    EXPECT_EQ(last_msg.msg.status_report.status[29].generic, 27)
        << "incorrect value for last_msg.msg.status_report.status[29].generic, "
           "expected 27, is "
        << (int64_t)last_msg.msg.status_report.status[29].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[29].specific, 73)
        << "incorrect value for "
           "last_msg.msg.status_report.status[29].specific, expected 73, is "
        << (int64_t)last_msg.msg.status_report.status[29].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[30].component, 16574)
        << "incorrect value for "
           "last_msg.msg.status_report.status[30].component, expected 16574, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[30].component;

    EXPECT_EQ(last_msg.msg.status_report.status[30].generic, 179)
        << "incorrect value for last_msg.msg.status_report.status[30].generic, "
           "expected 179, is "
        << (int64_t)last_msg.msg.status_report.status[30].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[30].specific, 146)
        << "incorrect value for "
           "last_msg.msg.status_report.status[30].specific, expected 146, is "
        << (int64_t)last_msg.msg.status_report.status[30].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[31].component, 39293)
        << "incorrect value for "
           "last_msg.msg.status_report.status[31].component, expected 39293, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[31].component;

    EXPECT_EQ(last_msg.msg.status_report.status[31].generic, 192)
        << "incorrect value for last_msg.msg.status_report.status[31].generic, "
           "expected 192, is "
        << (int64_t)last_msg.msg.status_report.status[31].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[31].specific, 46)
        << "incorrect value for "
           "last_msg.msg.status_report.status[31].specific, expected 46, is "
        << (int64_t)last_msg.msg.status_report.status[31].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[32].component, 17098)
        << "incorrect value for "
           "last_msg.msg.status_report.status[32].component, expected 17098, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[32].component;

    EXPECT_EQ(last_msg.msg.status_report.status[32].generic, 248)
        << "incorrect value for last_msg.msg.status_report.status[32].generic, "
           "expected 248, is "
        << (int64_t)last_msg.msg.status_report.status[32].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[32].specific, 46)
        << "incorrect value for "
           "last_msg.msg.status_report.status[32].specific, expected 46, is "
        << (int64_t)last_msg.msg.status_report.status[32].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[33].component, 41256)
        << "incorrect value for "
           "last_msg.msg.status_report.status[33].component, expected 41256, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[33].component;

    EXPECT_EQ(last_msg.msg.status_report.status[33].generic, 173)
        << "incorrect value for last_msg.msg.status_report.status[33].generic, "
           "expected 173, is "
        << (int64_t)last_msg.msg.status_report.status[33].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[33].specific, 242)
        << "incorrect value for "
           "last_msg.msg.status_report.status[33].specific, expected 242, is "
        << (int64_t)last_msg.msg.status_report.status[33].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[34].component, 982)
        << "incorrect value for "
           "last_msg.msg.status_report.status[34].component, expected 982, is "
        << (int64_t)last_msg.msg.status_report.status[34].component;

    EXPECT_EQ(last_msg.msg.status_report.status[34].generic, 11)
        << "incorrect value for last_msg.msg.status_report.status[34].generic, "
           "expected 11, is "
        << (int64_t)last_msg.msg.status_report.status[34].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[34].specific, 1)
        << "incorrect value for "
           "last_msg.msg.status_report.status[34].specific, expected 1, is "
        << (int64_t)last_msg.msg.status_report.status[34].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[35].component, 18038)
        << "incorrect value for "
           "last_msg.msg.status_report.status[35].component, expected 18038, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[35].component;

    EXPECT_EQ(last_msg.msg.status_report.status[35].generic, 162)
        << "incorrect value for last_msg.msg.status_report.status[35].generic, "
           "expected 162, is "
        << (int64_t)last_msg.msg.status_report.status[35].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[35].specific, 61)
        << "incorrect value for "
           "last_msg.msg.status_report.status[35].specific, expected 61, is "
        << (int64_t)last_msg.msg.status_report.status[35].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[36].component, 7090)
        << "incorrect value for "
           "last_msg.msg.status_report.status[36].component, expected 7090, is "
        << (int64_t)last_msg.msg.status_report.status[36].component;

    EXPECT_EQ(last_msg.msg.status_report.status[36].generic, 156)
        << "incorrect value for last_msg.msg.status_report.status[36].generic, "
           "expected 156, is "
        << (int64_t)last_msg.msg.status_report.status[36].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[36].specific, 40)
        << "incorrect value for "
           "last_msg.msg.status_report.status[36].specific, expected 40, is "
        << (int64_t)last_msg.msg.status_report.status[36].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[37].component, 29119)
        << "incorrect value for "
           "last_msg.msg.status_report.status[37].component, expected 29119, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[37].component;

    EXPECT_EQ(last_msg.msg.status_report.status[37].generic, 230)
        << "incorrect value for last_msg.msg.status_report.status[37].generic, "
           "expected 230, is "
        << (int64_t)last_msg.msg.status_report.status[37].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[37].specific, 200)
        << "incorrect value for "
           "last_msg.msg.status_report.status[37].specific, expected 200, is "
        << (int64_t)last_msg.msg.status_report.status[37].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[38].component, 2120)
        << "incorrect value for "
           "last_msg.msg.status_report.status[38].component, expected 2120, is "
        << (int64_t)last_msg.msg.status_report.status[38].component;

    EXPECT_EQ(last_msg.msg.status_report.status[38].generic, 215)
        << "incorrect value for last_msg.msg.status_report.status[38].generic, "
           "expected 215, is "
        << (int64_t)last_msg.msg.status_report.status[38].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[38].specific, 245)
        << "incorrect value for "
           "last_msg.msg.status_report.status[38].specific, expected 245, is "
        << (int64_t)last_msg.msg.status_report.status[38].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[39].component, 15182)
        << "incorrect value for "
           "last_msg.msg.status_report.status[39].component, expected 15182, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[39].component;

    EXPECT_EQ(last_msg.msg.status_report.status[39].generic, 222)
        << "incorrect value for last_msg.msg.status_report.status[39].generic, "
           "expected 222, is "
        << (int64_t)last_msg.msg.status_report.status[39].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[39].specific, 250)
        << "incorrect value for "
           "last_msg.msg.status_report.status[39].specific, expected 250, is "
        << (int64_t)last_msg.msg.status_report.status[39].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[40].component, 8307)
        << "incorrect value for "
           "last_msg.msg.status_report.status[40].component, expected 8307, is "
        << (int64_t)last_msg.msg.status_report.status[40].component;

    EXPECT_EQ(last_msg.msg.status_report.status[40].generic, 33)
        << "incorrect value for last_msg.msg.status_report.status[40].generic, "
           "expected 33, is "
        << (int64_t)last_msg.msg.status_report.status[40].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[40].specific, 30)
        << "incorrect value for "
           "last_msg.msg.status_report.status[40].specific, expected 30, is "
        << (int64_t)last_msg.msg.status_report.status[40].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[41].component, 43731)
        << "incorrect value for "
           "last_msg.msg.status_report.status[41].component, expected 43731, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[41].component;

    EXPECT_EQ(last_msg.msg.status_report.status[41].generic, 145)
        << "incorrect value for last_msg.msg.status_report.status[41].generic, "
           "expected 145, is "
        << (int64_t)last_msg.msg.status_report.status[41].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[41].specific, 92)
        << "incorrect value for "
           "last_msg.msg.status_report.status[41].specific, expected 92, is "
        << (int64_t)last_msg.msg.status_report.status[41].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[42].component, 19357)
        << "incorrect value for "
           "last_msg.msg.status_report.status[42].component, expected 19357, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[42].component;

    EXPECT_EQ(last_msg.msg.status_report.status[42].generic, 24)
        << "incorrect value for last_msg.msg.status_report.status[42].generic, "
           "expected 24, is "
        << (int64_t)last_msg.msg.status_report.status[42].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[42].specific, 169)
        << "incorrect value for "
           "last_msg.msg.status_report.status[42].specific, expected 169, is "
        << (int64_t)last_msg.msg.status_report.status[42].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[43].component, 14086)
        << "incorrect value for "
           "last_msg.msg.status_report.status[43].component, expected 14086, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[43].component;

    EXPECT_EQ(last_msg.msg.status_report.status[43].generic, 62)
        << "incorrect value for last_msg.msg.status_report.status[43].generic, "
           "expected 62, is "
        << (int64_t)last_msg.msg.status_report.status[43].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[43].specific, 8)
        << "incorrect value for "
           "last_msg.msg.status_report.status[43].specific, expected 8, is "
        << (int64_t)last_msg.msg.status_report.status[43].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[44].component, 21099)
        << "incorrect value for "
           "last_msg.msg.status_report.status[44].component, expected 21099, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[44].component;

    EXPECT_EQ(last_msg.msg.status_report.status[44].generic, 140)
        << "incorrect value for last_msg.msg.status_report.status[44].generic, "
           "expected 140, is "
        << (int64_t)last_msg.msg.status_report.status[44].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[44].specific, 49)
        << "incorrect value for "
           "last_msg.msg.status_report.status[44].specific, expected 49, is "
        << (int64_t)last_msg.msg.status_report.status[44].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[45].component, 31411)
        << "incorrect value for "
           "last_msg.msg.status_report.status[45].component, expected 31411, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[45].component;

    EXPECT_EQ(last_msg.msg.status_report.status[45].generic, 90)
        << "incorrect value for last_msg.msg.status_report.status[45].generic, "
           "expected 90, is "
        << (int64_t)last_msg.msg.status_report.status[45].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[45].specific, 71)
        << "incorrect value for "
           "last_msg.msg.status_report.status[45].specific, expected 71, is "
        << (int64_t)last_msg.msg.status_report.status[45].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[46].component, 22556)
        << "incorrect value for "
           "last_msg.msg.status_report.status[46].component, expected 22556, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[46].component;

    EXPECT_EQ(last_msg.msg.status_report.status[46].generic, 103)
        << "incorrect value for last_msg.msg.status_report.status[46].generic, "
           "expected 103, is "
        << (int64_t)last_msg.msg.status_report.status[46].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[46].specific, 51)
        << "incorrect value for "
           "last_msg.msg.status_report.status[46].specific, expected 51, is "
        << (int64_t)last_msg.msg.status_report.status[46].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[47].component, 18609)
        << "incorrect value for "
           "last_msg.msg.status_report.status[47].component, expected 18609, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[47].component;

    EXPECT_EQ(last_msg.msg.status_report.status[47].generic, 93)
        << "incorrect value for last_msg.msg.status_report.status[47].generic, "
           "expected 93, is "
        << (int64_t)last_msg.msg.status_report.status[47].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[47].specific, 39)
        << "incorrect value for "
           "last_msg.msg.status_report.status[47].specific, expected 39, is "
        << (int64_t)last_msg.msg.status_report.status[47].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[48].component, 2964)
        << "incorrect value for "
           "last_msg.msg.status_report.status[48].component, expected 2964, is "
        << (int64_t)last_msg.msg.status_report.status[48].component;

    EXPECT_EQ(last_msg.msg.status_report.status[48].generic, 202)
        << "incorrect value for last_msg.msg.status_report.status[48].generic, "
           "expected 202, is "
        << (int64_t)last_msg.msg.status_report.status[48].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[48].specific, 42)
        << "incorrect value for "
           "last_msg.msg.status_report.status[48].specific, expected 42, is "
        << (int64_t)last_msg.msg.status_report.status[48].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[49].component, 23586)
        << "incorrect value for "
           "last_msg.msg.status_report.status[49].component, expected 23586, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[49].component;

    EXPECT_EQ(last_msg.msg.status_report.status[49].generic, 204)
        << "incorrect value for last_msg.msg.status_report.status[49].generic, "
           "expected 204, is "
        << (int64_t)last_msg.msg.status_report.status[49].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[49].specific, 102)
        << "incorrect value for "
           "last_msg.msg.status_report.status[49].specific, expected 102, is "
        << (int64_t)last_msg.msg.status_report.status[49].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[50].component, 25117)
        << "incorrect value for "
           "last_msg.msg.status_report.status[50].component, expected 25117, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[50].component;

    EXPECT_EQ(last_msg.msg.status_report.status[50].generic, 249)
        << "incorrect value for last_msg.msg.status_report.status[50].generic, "
           "expected 249, is "
        << (int64_t)last_msg.msg.status_report.status[50].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[50].specific, 91)
        << "incorrect value for "
           "last_msg.msg.status_report.status[50].specific, expected 91, is "
        << (int64_t)last_msg.msg.status_report.status[50].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[51].component, 24454)
        << "incorrect value for "
           "last_msg.msg.status_report.status[51].component, expected 24454, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[51].component;

    EXPECT_EQ(last_msg.msg.status_report.status[51].generic, 23)
        << "incorrect value for last_msg.msg.status_report.status[51].generic, "
           "expected 23, is "
        << (int64_t)last_msg.msg.status_report.status[51].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[51].specific, 248)
        << "incorrect value for "
           "last_msg.msg.status_report.status[51].specific, expected 248, is "
        << (int64_t)last_msg.msg.status_report.status[51].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[52].component, 5312)
        << "incorrect value for "
           "last_msg.msg.status_report.status[52].component, expected 5312, is "
        << (int64_t)last_msg.msg.status_report.status[52].component;

    EXPECT_EQ(last_msg.msg.status_report.status[52].generic, 83)
        << "incorrect value for last_msg.msg.status_report.status[52].generic, "
           "expected 83, is "
        << (int64_t)last_msg.msg.status_report.status[52].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[52].specific, 195)
        << "incorrect value for "
           "last_msg.msg.status_report.status[52].specific, expected 195, is "
        << (int64_t)last_msg.msg.status_report.status[52].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[53].component, 46175)
        << "incorrect value for "
           "last_msg.msg.status_report.status[53].component, expected 46175, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[53].component;

    EXPECT_EQ(last_msg.msg.status_report.status[53].generic, 54)
        << "incorrect value for last_msg.msg.status_report.status[53].generic, "
           "expected 54, is "
        << (int64_t)last_msg.msg.status_report.status[53].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[53].specific, 36)
        << "incorrect value for "
           "last_msg.msg.status_report.status[53].specific, expected 36, is "
        << (int64_t)last_msg.msg.status_report.status[53].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[54].component, 19386)
        << "incorrect value for "
           "last_msg.msg.status_report.status[54].component, expected 19386, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[54].component;

    EXPECT_EQ(last_msg.msg.status_report.status[54].generic, 64)
        << "incorrect value for last_msg.msg.status_report.status[54].generic, "
           "expected 64, is "
        << (int64_t)last_msg.msg.status_report.status[54].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[54].specific, 20)
        << "incorrect value for "
           "last_msg.msg.status_report.status[54].specific, expected 20, is "
        << (int64_t)last_msg.msg.status_report.status[54].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[55].component, 34205)
        << "incorrect value for "
           "last_msg.msg.status_report.status[55].component, expected 34205, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[55].component;

    EXPECT_EQ(last_msg.msg.status_report.status[55].generic, 12)
        << "incorrect value for last_msg.msg.status_report.status[55].generic, "
           "expected 12, is "
        << (int64_t)last_msg.msg.status_report.status[55].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[55].specific, 149)
        << "incorrect value for "
           "last_msg.msg.status_report.status[55].specific, expected 149, is "
        << (int64_t)last_msg.msg.status_report.status[55].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[56].component, 3612)
        << "incorrect value for "
           "last_msg.msg.status_report.status[56].component, expected 3612, is "
        << (int64_t)last_msg.msg.status_report.status[56].component;

    EXPECT_EQ(last_msg.msg.status_report.status[56].generic, 185)
        << "incorrect value for last_msg.msg.status_report.status[56].generic, "
           "expected 185, is "
        << (int64_t)last_msg.msg.status_report.status[56].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[56].specific, 129)
        << "incorrect value for "
           "last_msg.msg.status_report.status[56].specific, expected 129, is "
        << (int64_t)last_msg.msg.status_report.status[56].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[57].component, 61285)
        << "incorrect value for "
           "last_msg.msg.status_report.status[57].component, expected 61285, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[57].component;

    EXPECT_EQ(last_msg.msg.status_report.status[57].generic, 74)
        << "incorrect value for last_msg.msg.status_report.status[57].generic, "
           "expected 74, is "
        << (int64_t)last_msg.msg.status_report.status[57].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[57].specific, 248)
        << "incorrect value for "
           "last_msg.msg.status_report.status[57].specific, expected 248, is "
        << (int64_t)last_msg.msg.status_report.status[57].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[58].component, 7925)
        << "incorrect value for "
           "last_msg.msg.status_report.status[58].component, expected 7925, is "
        << (int64_t)last_msg.msg.status_report.status[58].component;

    EXPECT_EQ(last_msg.msg.status_report.status[58].generic, 228)
        << "incorrect value for last_msg.msg.status_report.status[58].generic, "
           "expected 228, is "
        << (int64_t)last_msg.msg.status_report.status[58].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[58].specific, 88)
        << "incorrect value for "
           "last_msg.msg.status_report.status[58].specific, expected 88, is "
        << (int64_t)last_msg.msg.status_report.status[58].specific;

    EXPECT_EQ(last_msg.msg.status_report.status[59].component, 54414)
        << "incorrect value for "
           "last_msg.msg.status_report.status[59].component, expected 54414, "
           "is "
        << (int64_t)last_msg.msg.status_report.status[59].component;

    EXPECT_EQ(last_msg.msg.status_report.status[59].generic, 53)
        << "incorrect value for last_msg.msg.status_report.status[59].generic, "
           "expected 53, is "
        << (int64_t)last_msg.msg.status_report.status[59].generic;

    EXPECT_EQ(last_msg.msg.status_report.status[59].specific, 224)
        << "incorrect value for "
           "last_msg.msg.status_report.status[59].specific, expected 224, is "
        << (int64_t)last_msg.msg.status_report.status[59].specific;

    EXPECT_EQ(last_msg.msg.status_report.uptime, 1657804265)
        << "incorrect value for last_msg.msg.status_report.uptime, expected "
           "1657804265, is "
        << (int64_t)last_msg.msg.status_report.uptime;
  }
}

}  // namespace
