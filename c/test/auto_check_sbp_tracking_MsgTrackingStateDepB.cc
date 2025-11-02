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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDepB.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/tracking.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_tracking_MsgTrackingStateDepB,
     test_auto_check_sbp_tracking_MsgTrackingStateDepB) {
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingStateDepB,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  19,  0,   242, 241, 252, 115, 183, 227, 63,  68,  154, 1,   183,
        69,  255, 175, 121, 43,  222, 51,  67,  35,  69,  78,  240, 5,   53,
        20,  51,  211, 54,  69,  153, 130, 237, 66,  155, 51,  227, 71,  69,
        53,  242, 136, 161, 190, 205, 188, 6,   70,  153, 125, 255, 142, 149,
        154, 217, 184, 69,  248, 102, 95,  31,  76,  154, 33,  169, 69,  131,
        115, 141, 27,  12,  154, 225, 200, 69,  208, 44,  147, 39,  23,  51,
        3,   66,  69,  237, 159, 251, 49,  203, 51,  99,  102, 69,  70,  214,
        87,  128, 206, 154, 121, 186, 69,  14,  206, 111, 218, 19,  154, 121,
        169, 69,  216, 98,  209, 54,  2,   154, 25,  219, 67,  200, 133, 99,
        7,   34,  102, 198, 232, 68,  155, 43,  85,  135, 46,  154, 177, 170,
        69,  155, 3,   83,  171, 201, 154, 241, 232, 69,  121, 43,  197, 16,
        19,  154, 241, 222, 69,  128, 245, 53,  63,  176, 51,  115, 66,  69,
        36,  20,  61,  153, 51,  154, 73,  134, 69,  46,  82,  116, 140, 22,
        51,  147, 37,  69,  177, 67,  146, 96,  143, 205, 76,  107, 68,  220,
        51,  160, 201, 251, 102, 102, 192, 68,  168, 194, 2,   161, 220, 102,
        102, 180, 68,  69,  8,   9,   125, 178, 102, 70,  134, 68,  185, 20,
        135, 186, 171, 51,  163, 4,   69,  18,  124, 155, 85,  170, 205, 208,
        13,  70,  57,  244, 206, 255, 186, 154, 105, 149, 69,  165, 199, 93,
        181, 175, 51,  67,  64,  69,  6,   28,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_b.n_states = 28;

    test_msg.tracking_state_dep_b.states[0].cn0 = 5856.2001953125;

    test_msg.tracking_state_dep_b.states[0].sid.code = 63;

    test_msg.tracking_state_dep_b.states[0].sid.reserved = 68;

    test_msg.tracking_state_dep_b.states[0].sid.sat = 58295;

    test_msg.tracking_state_dep_b.states[0].state = 115;

    test_msg.tracking_state_dep_b.states[1].cn0 = 2612.199951171875;

    test_msg.tracking_state_dep_b.states[1].sid.code = 43;

    test_msg.tracking_state_dep_b.states[1].sid.reserved = 222;

    test_msg.tracking_state_dep_b.states[1].sid.sat = 31151;

    test_msg.tracking_state_dep_b.states[1].state = 255;

    test_msg.tracking_state_dep_b.states[2].cn0 = 2925.199951171875;

    test_msg.tracking_state_dep_b.states[2].sid.code = 53;

    test_msg.tracking_state_dep_b.states[2].sid.reserved = 20;

    test_msg.tracking_state_dep_b.states[2].sid.sat = 1520;

    test_msg.tracking_state_dep_b.states[2].state = 78;

    test_msg.tracking_state_dep_b.states[3].cn0 = 3198.199951171875;

    test_msg.tracking_state_dep_b.states[3].sid.code = 66;

    test_msg.tracking_state_dep_b.states[3].sid.reserved = 155;

    test_msg.tracking_state_dep_b.states[3].sid.sat = 60802;

    test_msg.tracking_state_dep_b.states[3].state = 153;

    test_msg.tracking_state_dep_b.states[4].cn0 = 8623.2001953125;

    test_msg.tracking_state_dep_b.states[4].sid.code = 161;

    test_msg.tracking_state_dep_b.states[4].sid.reserved = 190;

    test_msg.tracking_state_dep_b.states[4].sid.sat = 35058;

    test_msg.tracking_state_dep_b.states[4].state = 53;

    test_msg.tracking_state_dep_b.states[5].cn0 = 5915.2001953125;

    test_msg.tracking_state_dep_b.states[5].sid.code = 142;

    test_msg.tracking_state_dep_b.states[5].sid.reserved = 149;

    test_msg.tracking_state_dep_b.states[5].sid.sat = 65405;

    test_msg.tracking_state_dep_b.states[5].state = 153;

    test_msg.tracking_state_dep_b.states[6].cn0 = 5412.2001953125;

    test_msg.tracking_state_dep_b.states[6].sid.code = 31;

    test_msg.tracking_state_dep_b.states[6].sid.reserved = 76;

    test_msg.tracking_state_dep_b.states[6].sid.sat = 24422;

    test_msg.tracking_state_dep_b.states[6].state = 248;

    test_msg.tracking_state_dep_b.states[7].cn0 = 6428.2001953125;

    test_msg.tracking_state_dep_b.states[7].sid.code = 27;

    test_msg.tracking_state_dep_b.states[7].sid.reserved = 12;

    test_msg.tracking_state_dep_b.states[7].sid.sat = 36211;

    test_msg.tracking_state_dep_b.states[7].state = 131;

    test_msg.tracking_state_dep_b.states[8].cn0 = 3104.199951171875;

    test_msg.tracking_state_dep_b.states[8].sid.code = 39;

    test_msg.tracking_state_dep_b.states[8].sid.reserved = 23;

    test_msg.tracking_state_dep_b.states[8].sid.sat = 37676;

    test_msg.tracking_state_dep_b.states[8].state = 208;

    test_msg.tracking_state_dep_b.states[9].cn0 = 3686.199951171875;

    test_msg.tracking_state_dep_b.states[9].sid.code = 49;

    test_msg.tracking_state_dep_b.states[9].sid.reserved = 203;

    test_msg.tracking_state_dep_b.states[9].sid.sat = 64415;

    test_msg.tracking_state_dep_b.states[9].state = 237;

    test_msg.tracking_state_dep_b.states[10].cn0 = 5967.2001953125;

    test_msg.tracking_state_dep_b.states[10].sid.code = 128;

    test_msg.tracking_state_dep_b.states[10].sid.reserved = 206;

    test_msg.tracking_state_dep_b.states[10].sid.sat = 22486;

    test_msg.tracking_state_dep_b.states[10].state = 70;

    test_msg.tracking_state_dep_b.states[11].cn0 = 5423.2001953125;

    test_msg.tracking_state_dep_b.states[11].sid.code = 218;

    test_msg.tracking_state_dep_b.states[11].sid.reserved = 19;

    test_msg.tracking_state_dep_b.states[11].sid.sat = 28622;

    test_msg.tracking_state_dep_b.states[11].state = 14;

    test_msg.tracking_state_dep_b.states[12].cn0 = 438.20001220703125;

    test_msg.tracking_state_dep_b.states[12].sid.code = 54;

    test_msg.tracking_state_dep_b.states[12].sid.reserved = 2;

    test_msg.tracking_state_dep_b.states[12].sid.sat = 53602;

    test_msg.tracking_state_dep_b.states[12].state = 216;

    test_msg.tracking_state_dep_b.states[13].cn0 = 1862.199951171875;

    test_msg.tracking_state_dep_b.states[13].sid.code = 7;

    test_msg.tracking_state_dep_b.states[13].sid.reserved = 34;

    test_msg.tracking_state_dep_b.states[13].sid.sat = 25477;

    test_msg.tracking_state_dep_b.states[13].state = 200;

    test_msg.tracking_state_dep_b.states[14].cn0 = 5462.2001953125;

    test_msg.tracking_state_dep_b.states[14].sid.code = 135;

    test_msg.tracking_state_dep_b.states[14].sid.reserved = 46;

    test_msg.tracking_state_dep_b.states[14].sid.sat = 21803;

    test_msg.tracking_state_dep_b.states[14].state = 155;

    test_msg.tracking_state_dep_b.states[15].cn0 = 7454.2001953125;

    test_msg.tracking_state_dep_b.states[15].sid.code = 171;

    test_msg.tracking_state_dep_b.states[15].sid.reserved = 201;

    test_msg.tracking_state_dep_b.states[15].sid.sat = 21251;

    test_msg.tracking_state_dep_b.states[15].state = 155;

    test_msg.tracking_state_dep_b.states[16].cn0 = 7134.2001953125;

    test_msg.tracking_state_dep_b.states[16].sid.code = 16;

    test_msg.tracking_state_dep_b.states[16].sid.reserved = 19;

    test_msg.tracking_state_dep_b.states[16].sid.sat = 50475;

    test_msg.tracking_state_dep_b.states[16].state = 121;

    test_msg.tracking_state_dep_b.states[17].cn0 = 3111.199951171875;

    test_msg.tracking_state_dep_b.states[17].sid.code = 63;

    test_msg.tracking_state_dep_b.states[17].sid.reserved = 176;

    test_msg.tracking_state_dep_b.states[17].sid.sat = 13813;

    test_msg.tracking_state_dep_b.states[17].state = 128;

    test_msg.tracking_state_dep_b.states[18].cn0 = 4297.2001953125;

    test_msg.tracking_state_dep_b.states[18].sid.code = 153;

    test_msg.tracking_state_dep_b.states[18].sid.reserved = 51;

    test_msg.tracking_state_dep_b.states[18].sid.sat = 15636;

    test_msg.tracking_state_dep_b.states[18].state = 36;

    test_msg.tracking_state_dep_b.states[19].cn0 = 2649.199951171875;

    test_msg.tracking_state_dep_b.states[19].sid.code = 140;

    test_msg.tracking_state_dep_b.states[19].sid.reserved = 22;

    test_msg.tracking_state_dep_b.states[19].sid.sat = 29778;

    test_msg.tracking_state_dep_b.states[19].state = 46;

    test_msg.tracking_state_dep_b.states[20].cn0 = 941.2000122070312;

    test_msg.tracking_state_dep_b.states[20].sid.code = 96;

    test_msg.tracking_state_dep_b.states[20].sid.reserved = 143;

    test_msg.tracking_state_dep_b.states[20].sid.sat = 37443;

    test_msg.tracking_state_dep_b.states[20].state = 177;

    test_msg.tracking_state_dep_b.states[21].cn0 = 1539.199951171875;

    test_msg.tracking_state_dep_b.states[21].sid.code = 201;

    test_msg.tracking_state_dep_b.states[21].sid.reserved = 251;

    test_msg.tracking_state_dep_b.states[21].sid.sat = 41011;

    test_msg.tracking_state_dep_b.states[21].state = 220;

    test_msg.tracking_state_dep_b.states[22].cn0 = 1443.199951171875;

    test_msg.tracking_state_dep_b.states[22].sid.code = 161;

    test_msg.tracking_state_dep_b.states[22].sid.reserved = 220;

    test_msg.tracking_state_dep_b.states[22].sid.sat = 706;

    test_msg.tracking_state_dep_b.states[22].state = 168;

    test_msg.tracking_state_dep_b.states[23].cn0 = 1074.199951171875;

    test_msg.tracking_state_dep_b.states[23].sid.code = 125;

    test_msg.tracking_state_dep_b.states[23].sid.reserved = 178;

    test_msg.tracking_state_dep_b.states[23].sid.sat = 2312;

    test_msg.tracking_state_dep_b.states[23].state = 69;

    test_msg.tracking_state_dep_b.states[24].cn0 = 2122.199951171875;

    test_msg.tracking_state_dep_b.states[24].sid.code = 186;

    test_msg.tracking_state_dep_b.states[24].sid.reserved = 171;

    test_msg.tracking_state_dep_b.states[24].sid.sat = 34580;

    test_msg.tracking_state_dep_b.states[24].state = 185;

    test_msg.tracking_state_dep_b.states[25].cn0 = 9076.2001953125;

    test_msg.tracking_state_dep_b.states[25].sid.code = 85;

    test_msg.tracking_state_dep_b.states[25].sid.reserved = 170;

    test_msg.tracking_state_dep_b.states[25].sid.sat = 39804;

    test_msg.tracking_state_dep_b.states[25].state = 18;

    test_msg.tracking_state_dep_b.states[26].cn0 = 4781.2001953125;

    test_msg.tracking_state_dep_b.states[26].sid.code = 255;

    test_msg.tracking_state_dep_b.states[26].sid.reserved = 186;

    test_msg.tracking_state_dep_b.states[26].sid.sat = 52980;

    test_msg.tracking_state_dep_b.states[26].state = 57;

    test_msg.tracking_state_dep_b.states[27].cn0 = 3076.199951171875;

    test_msg.tracking_state_dep_b.states[27].sid.code = 181;

    test_msg.tracking_state_dep_b.states[27].sid.reserved = 175;

    test_msg.tracking_state_dep_b.states[27].sid.sat = 24007;

    test_msg.tracking_state_dep_b.states[27].state = 165;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepB, 61938, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 61938)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgTrackingStateDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.n_states, 28)
        << "incorrect value for last_msg.msg.tracking_state_dep_b.n_states, "
           "expected 28, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.n_states;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[0].cn0 * 100 -
               5856.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].cn0, expected "
           "5856.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[0].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.code, 63)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.code, expected 63, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, 68)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, expected "
           "68, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.sat, 58295)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.sat, expected "
           "58295, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].state, 115)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].state, expected 115, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[1].cn0 * 100 -
               2612.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].cn0, expected "
           "2612.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[1].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.code, 43)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.code, expected 43, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, 222)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, expected "
           "222, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.sat, 31151)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.sat, expected "
           "31151, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].state, 255)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].state, expected 255, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[2].cn0 * 100 -
               2925.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].cn0, expected "
           "2925.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[2].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.code, 53)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.code, expected 53, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, 20)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, expected "
           "20, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.sat, 1520)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.sat, expected "
           "1520, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].state, 78)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].state, expected 78, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[3].cn0 * 100 -
               3198.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].cn0, expected "
           "3198.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[3].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.code, 66)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.code, expected 66, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, 155)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, expected "
           "155, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.sat, 60802)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.sat, expected "
           "60802, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].state, 153)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].state, expected 153, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[4].cn0 * 100 -
               8623.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].cn0, expected "
           "8623.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[4].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.code, 161)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.code, expected "
           "161, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, 190)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, expected "
           "190, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.sat, 35058)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.sat, expected "
           "35058, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].state, 53)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].state, expected 53, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[5].cn0 * 100 -
               5915.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].cn0, expected "
           "5915.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[5].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.code, 142)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.code, expected "
           "142, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, 149)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, expected "
           "149, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.sat, 65405)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.sat, expected "
           "65405, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].state, 153)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].state, expected 153, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[6].cn0 * 100 -
               5412.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].cn0, expected "
           "5412.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[6].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.code, 31)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.code, expected 31, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, 76)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, expected "
           "76, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.sat, 24422)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.sat, expected "
           "24422, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].state, 248)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].state, expected 248, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[7].cn0 * 100 -
               6428.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].cn0, expected "
           "6428.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[7].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.code, 27)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.code, expected 27, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, 12)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, expected "
           "12, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.sat, 36211)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.sat, expected "
           "36211, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].state, 131)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].state, expected 131, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[8].cn0 * 100 -
               3104.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].cn0, expected "
           "3104.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[8].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.code, 39)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.code, expected 39, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, 23)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, expected "
           "23, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.sat, 37676)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.sat, expected "
           "37676, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].state, 208)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].state, expected 208, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[9].cn0 * 100 -
               3686.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].cn0, expected "
           "3686.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[9].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.code, 49)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.code, expected 49, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, 203)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, expected "
           "203, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.sat, 64415)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.sat, expected "
           "64415, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].state, 237)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].state, expected 237, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[10].cn0 * 100 -
               5967.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].cn0, expected "
           "5967.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[10].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.code, 128)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.code, expected "
           "128, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, 206)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, "
           "expected 206, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.sat, 22486)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.sat, expected "
           "22486, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].state, 70)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].state, expected 70, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[11].cn0 * 100 -
               5423.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[11].cn0, expected "
           "5423.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[11].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[11].sid.code, 218)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[11].sid.code, expected "
           "218, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[11].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[11].sid.reserved, 19)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[11].sid.reserved, "
           "expected 19, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[11].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[11].sid.sat, 28622)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[11].sid.sat, expected "
           "28622, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[11].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[11].state, 14)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[11].state, expected 14, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[11].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[12].cn0 * 100 -
               438.200012207 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[12].cn0, expected "
           "438.200012207, is "
        << last_msg.msg.tracking_state_dep_b.states[12].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[12].sid.code, 54)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[12].sid.code, expected "
           "54, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[12].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[12].sid.reserved, 2)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[12].sid.reserved, "
           "expected 2, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[12].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[12].sid.sat, 53602)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[12].sid.sat, expected "
           "53602, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[12].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[12].state, 216)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[12].state, expected 216, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[12].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[13].cn0 * 100 -
               1862.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[13].cn0, expected "
           "1862.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[13].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[13].sid.code, 7)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[13].sid.code, expected 7, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[13].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[13].sid.reserved, 34)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[13].sid.reserved, "
           "expected 34, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[13].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[13].sid.sat, 25477)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[13].sid.sat, expected "
           "25477, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[13].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[13].state, 200)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[13].state, expected 200, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[13].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[14].cn0 * 100 -
               5462.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[14].cn0, expected "
           "5462.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[14].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[14].sid.code, 135)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[14].sid.code, expected "
           "135, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[14].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[14].sid.reserved, 46)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[14].sid.reserved, "
           "expected 46, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[14].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[14].sid.sat, 21803)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[14].sid.sat, expected "
           "21803, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[14].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[14].state, 155)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[14].state, expected 155, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[14].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[15].cn0 * 100 -
               7454.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[15].cn0, expected "
           "7454.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[15].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[15].sid.code, 171)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[15].sid.code, expected "
           "171, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[15].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[15].sid.reserved, 201)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[15].sid.reserved, "
           "expected 201, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[15].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[15].sid.sat, 21251)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[15].sid.sat, expected "
           "21251, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[15].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[15].state, 155)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[15].state, expected 155, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[15].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[16].cn0 * 100 -
               7134.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[16].cn0, expected "
           "7134.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[16].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[16].sid.code, 16)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[16].sid.code, expected "
           "16, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[16].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[16].sid.reserved, 19)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[16].sid.reserved, "
           "expected 19, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[16].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[16].sid.sat, 50475)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[16].sid.sat, expected "
           "50475, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[16].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[16].state, 121)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[16].state, expected 121, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[16].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[17].cn0 * 100 -
               3111.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[17].cn0, expected "
           "3111.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[17].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[17].sid.code, 63)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[17].sid.code, expected "
           "63, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[17].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[17].sid.reserved, 176)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[17].sid.reserved, "
           "expected 176, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[17].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[17].sid.sat, 13813)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[17].sid.sat, expected "
           "13813, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[17].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[17].state, 128)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[17].state, expected 128, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[17].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[18].cn0 * 100 -
               4297.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[18].cn0, expected "
           "4297.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[18].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[18].sid.code, 153)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[18].sid.code, expected "
           "153, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[18].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[18].sid.reserved, 51)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[18].sid.reserved, "
           "expected 51, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[18].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[18].sid.sat, 15636)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[18].sid.sat, expected "
           "15636, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[18].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[18].state, 36)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[18].state, expected 36, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[18].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[19].cn0 * 100 -
               2649.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[19].cn0, expected "
           "2649.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[19].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[19].sid.code, 140)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[19].sid.code, expected "
           "140, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[19].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[19].sid.reserved, 22)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[19].sid.reserved, "
           "expected 22, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[19].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[19].sid.sat, 29778)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[19].sid.sat, expected "
           "29778, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[19].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[19].state, 46)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[19].state, expected 46, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[19].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[20].cn0 * 100 -
               941.200012207 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[20].cn0, expected "
           "941.200012207, is "
        << last_msg.msg.tracking_state_dep_b.states[20].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[20].sid.code, 96)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[20].sid.code, expected "
           "96, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[20].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[20].sid.reserved, 143)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[20].sid.reserved, "
           "expected 143, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[20].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[20].sid.sat, 37443)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[20].sid.sat, expected "
           "37443, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[20].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[20].state, 177)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[20].state, expected 177, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[20].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[21].cn0 * 100 -
               1539.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[21].cn0, expected "
           "1539.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[21].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[21].sid.code, 201)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[21].sid.code, expected "
           "201, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[21].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[21].sid.reserved, 251)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[21].sid.reserved, "
           "expected 251, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[21].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[21].sid.sat, 41011)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[21].sid.sat, expected "
           "41011, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[21].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[21].state, 220)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[21].state, expected 220, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[21].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[22].cn0 * 100 -
               1443.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[22].cn0, expected "
           "1443.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[22].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[22].sid.code, 161)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[22].sid.code, expected "
           "161, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[22].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[22].sid.reserved, 220)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[22].sid.reserved, "
           "expected 220, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[22].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[22].sid.sat, 706)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[22].sid.sat, expected "
           "706, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[22].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[22].state, 168)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[22].state, expected 168, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[22].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[23].cn0 * 100 -
               1074.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[23].cn0, expected "
           "1074.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[23].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[23].sid.code, 125)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[23].sid.code, expected "
           "125, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[23].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[23].sid.reserved, 178)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[23].sid.reserved, "
           "expected 178, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[23].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[23].sid.sat, 2312)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[23].sid.sat, expected "
           "2312, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[23].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[23].state, 69)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[23].state, expected 69, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[23].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[24].cn0 * 100 -
               2122.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[24].cn0, expected "
           "2122.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[24].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[24].sid.code, 186)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[24].sid.code, expected "
           "186, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[24].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[24].sid.reserved, 171)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[24].sid.reserved, "
           "expected 171, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[24].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[24].sid.sat, 34580)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[24].sid.sat, expected "
           "34580, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[24].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[24].state, 185)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[24].state, expected 185, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[24].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[25].cn0 * 100 -
               9076.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[25].cn0, expected "
           "9076.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[25].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[25].sid.code, 85)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[25].sid.code, expected "
           "85, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[25].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[25].sid.reserved, 170)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[25].sid.reserved, "
           "expected 170, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[25].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[25].sid.sat, 39804)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[25].sid.sat, expected "
           "39804, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[25].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[25].state, 18)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[25].state, expected 18, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[25].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[26].cn0 * 100 -
               4781.20019531 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[26].cn0, expected "
           "4781.20019531, is "
        << last_msg.msg.tracking_state_dep_b.states[26].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[26].sid.code, 255)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[26].sid.code, expected "
           "255, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[26].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[26].sid.reserved, 186)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[26].sid.reserved, "
           "expected 186, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[26].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[26].sid.sat, 52980)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[26].sid.sat, expected "
           "52980, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[26].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[26].state, 57)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[26].state, expected 57, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[26].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[27].cn0 * 100 -
               3076.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[27].cn0, expected "
           "3076.19995117, is "
        << last_msg.msg.tracking_state_dep_b.states[27].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[27].sid.code, 181)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[27].sid.code, expected "
           "181, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[27].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[27].sid.reserved, 175)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[27].sid.reserved, "
           "expected 175, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[27].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[27].sid.sat, 24007)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[27].sid.sat, expected "
           "24007, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[27].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[27].state, 165)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[27].state, expected 165, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[27].state;
  }
}

}  // namespace
