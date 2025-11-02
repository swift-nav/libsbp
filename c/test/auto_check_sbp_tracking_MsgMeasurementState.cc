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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgMeasurementState.yaml by
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

TEST(auto_check_sbp_tracking_MsgMeasurementState,
     test_auto_check_sbp_tracking_MsgMeasurementState) {
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

    sbp_callback_register(&sbp_state, SbpMsgMeasurementState, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  97, 0,   207, 121, 237, 29,  0,  162, 0,   0,  0,   0,   0,  0,
        27,  0,  201, 20,  0,   168, 32,  0,  184, 15,  0,  187, 0,   0,  0,
        18,  0,  210, 16,  0,   167, 0,   0,  0,   23,  0,  213, 10,  0,  223,
        0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   131, 2,  202,
        27,  1,  192, 15,  1,   165, 29,  1,  146, 32,  1,  170, 18,  1,  201,
        0,   0,  0,   0,   0,   0,   0,   0,  0,   23,  1,  212, 10,  1,  205,
        0,   0,  0,   96,  3,   230, 0,   0,  0,   101, 3,  214, 103, 3,  212,
        104, 3,  209, 106, 3,   157, 102, 3,  230, 0,   0,  0,   0,   0,  0,
        101, 4,  189, 96,  4,   207, 106, 4,  164, 104, 4,  193, 0,   0,  0,
        102, 4,  208, 0,   0,   0,   27,  12, 212, 29,  12, 161, 32,  12, 216,
        30,  12, 216, 20,  12,  178, 0,   0,  0,   0,   0,  0,   0,   0,  0,
        0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   0,   0,  0,
        0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   0,   0,  0,
        36,  14, 203, 0,   0,   0,   5,   14, 158, 4,   14, 194, 11,  14, 192,
        9,   14, 207, 0,   0,   0,   0,   0,  0,   0,   0,  0,   9,   20, 218,
        5,   20, 176, 36,  20,  217, 11,  20, 200, 4,   20, 205, 0,   0,  0,
        0,   0,  0,   35,  54,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.measurement_state.n_states = 79;

    test_msg.measurement_state.states[0].cn0 = 162;

    test_msg.measurement_state.states[0].mesid.code = 0;

    test_msg.measurement_state.states[0].mesid.sat = 29;

    test_msg.measurement_state.states[1].cn0 = 0;

    test_msg.measurement_state.states[1].mesid.code = 0;

    test_msg.measurement_state.states[1].mesid.sat = 0;

    test_msg.measurement_state.states[2].cn0 = 0;

    test_msg.measurement_state.states[2].mesid.code = 0;

    test_msg.measurement_state.states[2].mesid.sat = 0;

    test_msg.measurement_state.states[3].cn0 = 201;

    test_msg.measurement_state.states[3].mesid.code = 0;

    test_msg.measurement_state.states[3].mesid.sat = 27;

    test_msg.measurement_state.states[4].cn0 = 168;

    test_msg.measurement_state.states[4].mesid.code = 0;

    test_msg.measurement_state.states[4].mesid.sat = 20;

    test_msg.measurement_state.states[5].cn0 = 184;

    test_msg.measurement_state.states[5].mesid.code = 0;

    test_msg.measurement_state.states[5].mesid.sat = 32;

    test_msg.measurement_state.states[6].cn0 = 187;

    test_msg.measurement_state.states[6].mesid.code = 0;

    test_msg.measurement_state.states[6].mesid.sat = 15;

    test_msg.measurement_state.states[7].cn0 = 0;

    test_msg.measurement_state.states[7].mesid.code = 0;

    test_msg.measurement_state.states[7].mesid.sat = 0;

    test_msg.measurement_state.states[8].cn0 = 210;

    test_msg.measurement_state.states[8].mesid.code = 0;

    test_msg.measurement_state.states[8].mesid.sat = 18;

    test_msg.measurement_state.states[9].cn0 = 167;

    test_msg.measurement_state.states[9].mesid.code = 0;

    test_msg.measurement_state.states[9].mesid.sat = 16;

    test_msg.measurement_state.states[10].cn0 = 0;

    test_msg.measurement_state.states[10].mesid.code = 0;

    test_msg.measurement_state.states[10].mesid.sat = 0;

    test_msg.measurement_state.states[11].cn0 = 213;

    test_msg.measurement_state.states[11].mesid.code = 0;

    test_msg.measurement_state.states[11].mesid.sat = 23;

    test_msg.measurement_state.states[12].cn0 = 223;

    test_msg.measurement_state.states[12].mesid.code = 0;

    test_msg.measurement_state.states[12].mesid.sat = 10;

    test_msg.measurement_state.states[13].cn0 = 0;

    test_msg.measurement_state.states[13].mesid.code = 0;

    test_msg.measurement_state.states[13].mesid.sat = 0;

    test_msg.measurement_state.states[14].cn0 = 0;

    test_msg.measurement_state.states[14].mesid.code = 0;

    test_msg.measurement_state.states[14].mesid.sat = 0;

    test_msg.measurement_state.states[15].cn0 = 0;

    test_msg.measurement_state.states[15].mesid.code = 0;

    test_msg.measurement_state.states[15].mesid.sat = 0;

    test_msg.measurement_state.states[16].cn0 = 0;

    test_msg.measurement_state.states[16].mesid.code = 0;

    test_msg.measurement_state.states[16].mesid.sat = 0;

    test_msg.measurement_state.states[17].cn0 = 202;

    test_msg.measurement_state.states[17].mesid.code = 2;

    test_msg.measurement_state.states[17].mesid.sat = 131;

    test_msg.measurement_state.states[18].cn0 = 192;

    test_msg.measurement_state.states[18].mesid.code = 1;

    test_msg.measurement_state.states[18].mesid.sat = 27;

    test_msg.measurement_state.states[19].cn0 = 165;

    test_msg.measurement_state.states[19].mesid.code = 1;

    test_msg.measurement_state.states[19].mesid.sat = 15;

    test_msg.measurement_state.states[20].cn0 = 146;

    test_msg.measurement_state.states[20].mesid.code = 1;

    test_msg.measurement_state.states[20].mesid.sat = 29;

    test_msg.measurement_state.states[21].cn0 = 170;

    test_msg.measurement_state.states[21].mesid.code = 1;

    test_msg.measurement_state.states[21].mesid.sat = 32;

    test_msg.measurement_state.states[22].cn0 = 201;

    test_msg.measurement_state.states[22].mesid.code = 1;

    test_msg.measurement_state.states[22].mesid.sat = 18;

    test_msg.measurement_state.states[23].cn0 = 0;

    test_msg.measurement_state.states[23].mesid.code = 0;

    test_msg.measurement_state.states[23].mesid.sat = 0;

    test_msg.measurement_state.states[24].cn0 = 0;

    test_msg.measurement_state.states[24].mesid.code = 0;

    test_msg.measurement_state.states[24].mesid.sat = 0;

    test_msg.measurement_state.states[25].cn0 = 0;

    test_msg.measurement_state.states[25].mesid.code = 0;

    test_msg.measurement_state.states[25].mesid.sat = 0;

    test_msg.measurement_state.states[26].cn0 = 212;

    test_msg.measurement_state.states[26].mesid.code = 1;

    test_msg.measurement_state.states[26].mesid.sat = 23;

    test_msg.measurement_state.states[27].cn0 = 205;

    test_msg.measurement_state.states[27].mesid.code = 1;

    test_msg.measurement_state.states[27].mesid.sat = 10;

    test_msg.measurement_state.states[28].cn0 = 0;

    test_msg.measurement_state.states[28].mesid.code = 0;

    test_msg.measurement_state.states[28].mesid.sat = 0;

    test_msg.measurement_state.states[29].cn0 = 230;

    test_msg.measurement_state.states[29].mesid.code = 3;

    test_msg.measurement_state.states[29].mesid.sat = 96;

    test_msg.measurement_state.states[30].cn0 = 0;

    test_msg.measurement_state.states[30].mesid.code = 0;

    test_msg.measurement_state.states[30].mesid.sat = 0;

    test_msg.measurement_state.states[31].cn0 = 214;

    test_msg.measurement_state.states[31].mesid.code = 3;

    test_msg.measurement_state.states[31].mesid.sat = 101;

    test_msg.measurement_state.states[32].cn0 = 212;

    test_msg.measurement_state.states[32].mesid.code = 3;

    test_msg.measurement_state.states[32].mesid.sat = 103;

    test_msg.measurement_state.states[33].cn0 = 209;

    test_msg.measurement_state.states[33].mesid.code = 3;

    test_msg.measurement_state.states[33].mesid.sat = 104;

    test_msg.measurement_state.states[34].cn0 = 157;

    test_msg.measurement_state.states[34].mesid.code = 3;

    test_msg.measurement_state.states[34].mesid.sat = 106;

    test_msg.measurement_state.states[35].cn0 = 230;

    test_msg.measurement_state.states[35].mesid.code = 3;

    test_msg.measurement_state.states[35].mesid.sat = 102;

    test_msg.measurement_state.states[36].cn0 = 0;

    test_msg.measurement_state.states[36].mesid.code = 0;

    test_msg.measurement_state.states[36].mesid.sat = 0;

    test_msg.measurement_state.states[37].cn0 = 0;

    test_msg.measurement_state.states[37].mesid.code = 0;

    test_msg.measurement_state.states[37].mesid.sat = 0;

    test_msg.measurement_state.states[38].cn0 = 189;

    test_msg.measurement_state.states[38].mesid.code = 4;

    test_msg.measurement_state.states[38].mesid.sat = 101;

    test_msg.measurement_state.states[39].cn0 = 207;

    test_msg.measurement_state.states[39].mesid.code = 4;

    test_msg.measurement_state.states[39].mesid.sat = 96;

    test_msg.measurement_state.states[40].cn0 = 164;

    test_msg.measurement_state.states[40].mesid.code = 4;

    test_msg.measurement_state.states[40].mesid.sat = 106;

    test_msg.measurement_state.states[41].cn0 = 193;

    test_msg.measurement_state.states[41].mesid.code = 4;

    test_msg.measurement_state.states[41].mesid.sat = 104;

    test_msg.measurement_state.states[42].cn0 = 0;

    test_msg.measurement_state.states[42].mesid.code = 0;

    test_msg.measurement_state.states[42].mesid.sat = 0;

    test_msg.measurement_state.states[43].cn0 = 208;

    test_msg.measurement_state.states[43].mesid.code = 4;

    test_msg.measurement_state.states[43].mesid.sat = 102;

    test_msg.measurement_state.states[44].cn0 = 0;

    test_msg.measurement_state.states[44].mesid.code = 0;

    test_msg.measurement_state.states[44].mesid.sat = 0;

    test_msg.measurement_state.states[45].cn0 = 212;

    test_msg.measurement_state.states[45].mesid.code = 12;

    test_msg.measurement_state.states[45].mesid.sat = 27;

    test_msg.measurement_state.states[46].cn0 = 161;

    test_msg.measurement_state.states[46].mesid.code = 12;

    test_msg.measurement_state.states[46].mesid.sat = 29;

    test_msg.measurement_state.states[47].cn0 = 216;

    test_msg.measurement_state.states[47].mesid.code = 12;

    test_msg.measurement_state.states[47].mesid.sat = 32;

    test_msg.measurement_state.states[48].cn0 = 216;

    test_msg.measurement_state.states[48].mesid.code = 12;

    test_msg.measurement_state.states[48].mesid.sat = 30;

    test_msg.measurement_state.states[49].cn0 = 178;

    test_msg.measurement_state.states[49].mesid.code = 12;

    test_msg.measurement_state.states[49].mesid.sat = 20;

    test_msg.measurement_state.states[50].cn0 = 0;

    test_msg.measurement_state.states[50].mesid.code = 0;

    test_msg.measurement_state.states[50].mesid.sat = 0;

    test_msg.measurement_state.states[51].cn0 = 0;

    test_msg.measurement_state.states[51].mesid.code = 0;

    test_msg.measurement_state.states[51].mesid.sat = 0;

    test_msg.measurement_state.states[52].cn0 = 0;

    test_msg.measurement_state.states[52].mesid.code = 0;

    test_msg.measurement_state.states[52].mesid.sat = 0;

    test_msg.measurement_state.states[53].cn0 = 0;

    test_msg.measurement_state.states[53].mesid.code = 0;

    test_msg.measurement_state.states[53].mesid.sat = 0;

    test_msg.measurement_state.states[54].cn0 = 0;

    test_msg.measurement_state.states[54].mesid.code = 0;

    test_msg.measurement_state.states[54].mesid.sat = 0;

    test_msg.measurement_state.states[55].cn0 = 0;

    test_msg.measurement_state.states[55].mesid.code = 0;

    test_msg.measurement_state.states[55].mesid.sat = 0;

    test_msg.measurement_state.states[56].cn0 = 0;

    test_msg.measurement_state.states[56].mesid.code = 0;

    test_msg.measurement_state.states[56].mesid.sat = 0;

    test_msg.measurement_state.states[57].cn0 = 0;

    test_msg.measurement_state.states[57].mesid.code = 0;

    test_msg.measurement_state.states[57].mesid.sat = 0;

    test_msg.measurement_state.states[58].cn0 = 0;

    test_msg.measurement_state.states[58].mesid.code = 0;

    test_msg.measurement_state.states[58].mesid.sat = 0;

    test_msg.measurement_state.states[59].cn0 = 0;

    test_msg.measurement_state.states[59].mesid.code = 0;

    test_msg.measurement_state.states[59].mesid.sat = 0;

    test_msg.measurement_state.states[60].cn0 = 0;

    test_msg.measurement_state.states[60].mesid.code = 0;

    test_msg.measurement_state.states[60].mesid.sat = 0;

    test_msg.measurement_state.states[61].cn0 = 0;

    test_msg.measurement_state.states[61].mesid.code = 0;

    test_msg.measurement_state.states[61].mesid.sat = 0;

    test_msg.measurement_state.states[62].cn0 = 0;

    test_msg.measurement_state.states[62].mesid.code = 0;

    test_msg.measurement_state.states[62].mesid.sat = 0;

    test_msg.measurement_state.states[63].cn0 = 203;

    test_msg.measurement_state.states[63].mesid.code = 14;

    test_msg.measurement_state.states[63].mesid.sat = 36;

    test_msg.measurement_state.states[64].cn0 = 0;

    test_msg.measurement_state.states[64].mesid.code = 0;

    test_msg.measurement_state.states[64].mesid.sat = 0;

    test_msg.measurement_state.states[65].cn0 = 158;

    test_msg.measurement_state.states[65].mesid.code = 14;

    test_msg.measurement_state.states[65].mesid.sat = 5;

    test_msg.measurement_state.states[66].cn0 = 194;

    test_msg.measurement_state.states[66].mesid.code = 14;

    test_msg.measurement_state.states[66].mesid.sat = 4;

    test_msg.measurement_state.states[67].cn0 = 192;

    test_msg.measurement_state.states[67].mesid.code = 14;

    test_msg.measurement_state.states[67].mesid.sat = 11;

    test_msg.measurement_state.states[68].cn0 = 207;

    test_msg.measurement_state.states[68].mesid.code = 14;

    test_msg.measurement_state.states[68].mesid.sat = 9;

    test_msg.measurement_state.states[69].cn0 = 0;

    test_msg.measurement_state.states[69].mesid.code = 0;

    test_msg.measurement_state.states[69].mesid.sat = 0;

    test_msg.measurement_state.states[70].cn0 = 0;

    test_msg.measurement_state.states[70].mesid.code = 0;

    test_msg.measurement_state.states[70].mesid.sat = 0;

    test_msg.measurement_state.states[71].cn0 = 0;

    test_msg.measurement_state.states[71].mesid.code = 0;

    test_msg.measurement_state.states[71].mesid.sat = 0;

    test_msg.measurement_state.states[72].cn0 = 218;

    test_msg.measurement_state.states[72].mesid.code = 20;

    test_msg.measurement_state.states[72].mesid.sat = 9;

    test_msg.measurement_state.states[73].cn0 = 176;

    test_msg.measurement_state.states[73].mesid.code = 20;

    test_msg.measurement_state.states[73].mesid.sat = 5;

    test_msg.measurement_state.states[74].cn0 = 217;

    test_msg.measurement_state.states[74].mesid.code = 20;

    test_msg.measurement_state.states[74].mesid.sat = 36;

    test_msg.measurement_state.states[75].cn0 = 200;

    test_msg.measurement_state.states[75].mesid.code = 20;

    test_msg.measurement_state.states[75].mesid.sat = 11;

    test_msg.measurement_state.states[76].cn0 = 205;

    test_msg.measurement_state.states[76].mesid.code = 20;

    test_msg.measurement_state.states[76].mesid.sat = 4;

    test_msg.measurement_state.states[77].cn0 = 0;

    test_msg.measurement_state.states[77].mesid.code = 0;

    test_msg.measurement_state.states[77].mesid.sat = 0;

    test_msg.measurement_state.states[78].cn0 = 0;

    test_msg.measurement_state.states[78].mesid.code = 0;

    test_msg.measurement_state.states[78].mesid.sat = 0;

    sbp_message_send(&sbp_state, SbpMsgMeasurementState, 31183, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 31183)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgMeasurementState, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.measurement_state.n_states, 79)
        << "incorrect value for last_msg.msg.measurement_state.n_states, "
           "expected 79, is "
        << (int64_t)last_msg.msg.measurement_state.n_states;

    EXPECT_EQ(last_msg.msg.measurement_state.states[0].cn0, 162)
        << "incorrect value for last_msg.msg.measurement_state.states[0].cn0, "
           "expected 162, is "
        << (int64_t)last_msg.msg.measurement_state.states[0].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[0].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[0].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[0].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[0].mesid.sat, 29)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[0].mesid.sat, expected 29, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[0].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[1].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[1].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[1].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[1].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[1].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[1].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[1].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[1].mesid.sat, expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[1].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[2].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[2].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[2].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[2].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[2].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[2].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[2].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[2].mesid.sat, expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[2].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[3].cn0, 201)
        << "incorrect value for last_msg.msg.measurement_state.states[3].cn0, "
           "expected 201, is "
        << (int64_t)last_msg.msg.measurement_state.states[3].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[3].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[3].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[3].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[3].mesid.sat, 27)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[3].mesid.sat, expected 27, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[3].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[4].cn0, 168)
        << "incorrect value for last_msg.msg.measurement_state.states[4].cn0, "
           "expected 168, is "
        << (int64_t)last_msg.msg.measurement_state.states[4].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[4].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[4].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[4].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[4].mesid.sat, 20)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[4].mesid.sat, expected 20, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[4].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[5].cn0, 184)
        << "incorrect value for last_msg.msg.measurement_state.states[5].cn0, "
           "expected 184, is "
        << (int64_t)last_msg.msg.measurement_state.states[5].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[5].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[5].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[5].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[5].mesid.sat, 32)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[5].mesid.sat, expected 32, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[5].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[6].cn0, 187)
        << "incorrect value for last_msg.msg.measurement_state.states[6].cn0, "
           "expected 187, is "
        << (int64_t)last_msg.msg.measurement_state.states[6].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[6].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[6].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[6].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[6].mesid.sat, 15)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[6].mesid.sat, expected 15, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[6].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[7].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[7].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[7].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[7].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[7].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[7].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[7].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[7].mesid.sat, expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[7].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[8].cn0, 210)
        << "incorrect value for last_msg.msg.measurement_state.states[8].cn0, "
           "expected 210, is "
        << (int64_t)last_msg.msg.measurement_state.states[8].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[8].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[8].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[8].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[8].mesid.sat, 18)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[8].mesid.sat, expected 18, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[8].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[9].cn0, 167)
        << "incorrect value for last_msg.msg.measurement_state.states[9].cn0, "
           "expected 167, is "
        << (int64_t)last_msg.msg.measurement_state.states[9].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[9].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[9].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[9].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[9].mesid.sat, 16)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[9].mesid.sat, expected 16, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[9].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[10].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[10].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[10].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[10].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[10].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[10].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[10].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[10].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[10].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[11].cn0, 213)
        << "incorrect value for last_msg.msg.measurement_state.states[11].cn0, "
           "expected 213, is "
        << (int64_t)last_msg.msg.measurement_state.states[11].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[11].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[11].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[11].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[11].mesid.sat, 23)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[11].mesid.sat, expected 23, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[11].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[12].cn0, 223)
        << "incorrect value for last_msg.msg.measurement_state.states[12].cn0, "
           "expected 223, is "
        << (int64_t)last_msg.msg.measurement_state.states[12].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[12].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[12].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[12].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[12].mesid.sat, 10)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[12].mesid.sat, expected 10, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[12].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[13].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[13].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[13].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[13].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[13].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[13].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[13].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[13].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[13].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[14].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[14].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[14].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[14].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[14].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[14].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[14].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[14].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[14].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[15].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[15].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[15].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[15].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[15].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[15].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[15].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[15].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[15].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[16].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[16].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[16].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[16].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[16].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[16].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[16].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[16].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[16].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[17].cn0, 202)
        << "incorrect value for last_msg.msg.measurement_state.states[17].cn0, "
           "expected 202, is "
        << (int64_t)last_msg.msg.measurement_state.states[17].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[17].mesid.code, 2)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[17].mesid.code, expected 2, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[17].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[17].mesid.sat, 131)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[17].mesid.sat, expected 131, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[17].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[18].cn0, 192)
        << "incorrect value for last_msg.msg.measurement_state.states[18].cn0, "
           "expected 192, is "
        << (int64_t)last_msg.msg.measurement_state.states[18].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[18].mesid.code, 1)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[18].mesid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[18].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[18].mesid.sat, 27)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[18].mesid.sat, expected 27, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[18].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[19].cn0, 165)
        << "incorrect value for last_msg.msg.measurement_state.states[19].cn0, "
           "expected 165, is "
        << (int64_t)last_msg.msg.measurement_state.states[19].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[19].mesid.code, 1)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[19].mesid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[19].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[19].mesid.sat, 15)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[19].mesid.sat, expected 15, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[19].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[20].cn0, 146)
        << "incorrect value for last_msg.msg.measurement_state.states[20].cn0, "
           "expected 146, is "
        << (int64_t)last_msg.msg.measurement_state.states[20].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[20].mesid.code, 1)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[20].mesid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[20].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[20].mesid.sat, 29)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[20].mesid.sat, expected 29, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[20].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[21].cn0, 170)
        << "incorrect value for last_msg.msg.measurement_state.states[21].cn0, "
           "expected 170, is "
        << (int64_t)last_msg.msg.measurement_state.states[21].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[21].mesid.code, 1)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[21].mesid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[21].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[21].mesid.sat, 32)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[21].mesid.sat, expected 32, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[21].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[22].cn0, 201)
        << "incorrect value for last_msg.msg.measurement_state.states[22].cn0, "
           "expected 201, is "
        << (int64_t)last_msg.msg.measurement_state.states[22].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[22].mesid.code, 1)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[22].mesid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[22].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[22].mesid.sat, 18)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[22].mesid.sat, expected 18, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[22].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[23].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[23].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[23].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[23].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[23].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[23].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[23].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[23].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[23].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[24].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[24].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[24].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[24].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[24].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[24].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[24].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[24].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[24].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[25].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[25].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[25].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[25].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[25].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[25].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[25].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[25].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[25].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[26].cn0, 212)
        << "incorrect value for last_msg.msg.measurement_state.states[26].cn0, "
           "expected 212, is "
        << (int64_t)last_msg.msg.measurement_state.states[26].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[26].mesid.code, 1)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[26].mesid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[26].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[26].mesid.sat, 23)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[26].mesid.sat, expected 23, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[26].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[27].cn0, 205)
        << "incorrect value for last_msg.msg.measurement_state.states[27].cn0, "
           "expected 205, is "
        << (int64_t)last_msg.msg.measurement_state.states[27].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[27].mesid.code, 1)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[27].mesid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[27].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[27].mesid.sat, 10)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[27].mesid.sat, expected 10, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[27].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[28].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[28].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[28].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[28].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[28].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[28].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[28].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[28].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[28].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[29].cn0, 230)
        << "incorrect value for last_msg.msg.measurement_state.states[29].cn0, "
           "expected 230, is "
        << (int64_t)last_msg.msg.measurement_state.states[29].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[29].mesid.code, 3)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[29].mesid.code, expected 3, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[29].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[29].mesid.sat, 96)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[29].mesid.sat, expected 96, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[29].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[30].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[30].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[30].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[30].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[30].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[30].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[30].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[30].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[30].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[31].cn0, 214)
        << "incorrect value for last_msg.msg.measurement_state.states[31].cn0, "
           "expected 214, is "
        << (int64_t)last_msg.msg.measurement_state.states[31].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[31].mesid.code, 3)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[31].mesid.code, expected 3, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[31].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[31].mesid.sat, 101)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[31].mesid.sat, expected 101, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[31].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[32].cn0, 212)
        << "incorrect value for last_msg.msg.measurement_state.states[32].cn0, "
           "expected 212, is "
        << (int64_t)last_msg.msg.measurement_state.states[32].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[32].mesid.code, 3)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[32].mesid.code, expected 3, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[32].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[32].mesid.sat, 103)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[32].mesid.sat, expected 103, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[32].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[33].cn0, 209)
        << "incorrect value for last_msg.msg.measurement_state.states[33].cn0, "
           "expected 209, is "
        << (int64_t)last_msg.msg.measurement_state.states[33].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[33].mesid.code, 3)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[33].mesid.code, expected 3, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[33].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[33].mesid.sat, 104)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[33].mesid.sat, expected 104, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[33].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[34].cn0, 157)
        << "incorrect value for last_msg.msg.measurement_state.states[34].cn0, "
           "expected 157, is "
        << (int64_t)last_msg.msg.measurement_state.states[34].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[34].mesid.code, 3)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[34].mesid.code, expected 3, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[34].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[34].mesid.sat, 106)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[34].mesid.sat, expected 106, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[34].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[35].cn0, 230)
        << "incorrect value for last_msg.msg.measurement_state.states[35].cn0, "
           "expected 230, is "
        << (int64_t)last_msg.msg.measurement_state.states[35].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[35].mesid.code, 3)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[35].mesid.code, expected 3, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[35].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[35].mesid.sat, 102)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[35].mesid.sat, expected 102, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[35].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[36].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[36].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[36].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[36].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[36].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[36].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[36].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[36].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[36].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[37].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[37].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[37].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[37].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[37].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[37].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[37].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[37].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[37].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[38].cn0, 189)
        << "incorrect value for last_msg.msg.measurement_state.states[38].cn0, "
           "expected 189, is "
        << (int64_t)last_msg.msg.measurement_state.states[38].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[38].mesid.code, 4)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[38].mesid.code, expected 4, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[38].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[38].mesid.sat, 101)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[38].mesid.sat, expected 101, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[38].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[39].cn0, 207)
        << "incorrect value for last_msg.msg.measurement_state.states[39].cn0, "
           "expected 207, is "
        << (int64_t)last_msg.msg.measurement_state.states[39].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[39].mesid.code, 4)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[39].mesid.code, expected 4, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[39].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[39].mesid.sat, 96)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[39].mesid.sat, expected 96, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[39].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[40].cn0, 164)
        << "incorrect value for last_msg.msg.measurement_state.states[40].cn0, "
           "expected 164, is "
        << (int64_t)last_msg.msg.measurement_state.states[40].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[40].mesid.code, 4)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[40].mesid.code, expected 4, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[40].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[40].mesid.sat, 106)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[40].mesid.sat, expected 106, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[40].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[41].cn0, 193)
        << "incorrect value for last_msg.msg.measurement_state.states[41].cn0, "
           "expected 193, is "
        << (int64_t)last_msg.msg.measurement_state.states[41].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[41].mesid.code, 4)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[41].mesid.code, expected 4, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[41].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[41].mesid.sat, 104)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[41].mesid.sat, expected 104, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[41].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[42].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[42].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[42].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[42].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[42].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[42].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[42].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[42].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[42].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[43].cn0, 208)
        << "incorrect value for last_msg.msg.measurement_state.states[43].cn0, "
           "expected 208, is "
        << (int64_t)last_msg.msg.measurement_state.states[43].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[43].mesid.code, 4)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[43].mesid.code, expected 4, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[43].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[43].mesid.sat, 102)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[43].mesid.sat, expected 102, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[43].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[44].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[44].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[44].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[44].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[44].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[44].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[44].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[44].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[44].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[45].cn0, 212)
        << "incorrect value for last_msg.msg.measurement_state.states[45].cn0, "
           "expected 212, is "
        << (int64_t)last_msg.msg.measurement_state.states[45].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[45].mesid.code, 12)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[45].mesid.code, expected 12, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[45].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[45].mesid.sat, 27)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[45].mesid.sat, expected 27, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[45].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[46].cn0, 161)
        << "incorrect value for last_msg.msg.measurement_state.states[46].cn0, "
           "expected 161, is "
        << (int64_t)last_msg.msg.measurement_state.states[46].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[46].mesid.code, 12)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[46].mesid.code, expected 12, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[46].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[46].mesid.sat, 29)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[46].mesid.sat, expected 29, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[46].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[47].cn0, 216)
        << "incorrect value for last_msg.msg.measurement_state.states[47].cn0, "
           "expected 216, is "
        << (int64_t)last_msg.msg.measurement_state.states[47].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[47].mesid.code, 12)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[47].mesid.code, expected 12, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[47].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[47].mesid.sat, 32)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[47].mesid.sat, expected 32, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[47].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[48].cn0, 216)
        << "incorrect value for last_msg.msg.measurement_state.states[48].cn0, "
           "expected 216, is "
        << (int64_t)last_msg.msg.measurement_state.states[48].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[48].mesid.code, 12)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[48].mesid.code, expected 12, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[48].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[48].mesid.sat, 30)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[48].mesid.sat, expected 30, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[48].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[49].cn0, 178)
        << "incorrect value for last_msg.msg.measurement_state.states[49].cn0, "
           "expected 178, is "
        << (int64_t)last_msg.msg.measurement_state.states[49].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[49].mesid.code, 12)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[49].mesid.code, expected 12, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[49].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[49].mesid.sat, 20)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[49].mesid.sat, expected 20, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[49].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[50].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[50].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[50].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[50].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[50].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[50].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[50].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[50].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[50].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[51].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[51].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[51].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[51].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[51].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[51].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[51].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[51].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[51].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[52].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[52].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[52].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[52].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[52].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[52].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[52].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[52].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[52].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[53].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[53].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[53].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[53].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[53].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[53].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[53].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[53].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[53].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[54].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[54].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[54].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[54].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[54].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[54].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[54].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[54].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[54].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[55].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[55].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[55].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[55].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[55].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[55].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[55].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[55].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[55].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[56].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[56].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[56].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[56].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[56].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[56].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[56].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[56].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[56].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[57].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[57].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[57].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[57].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[57].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[57].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[57].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[57].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[57].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[58].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[58].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[58].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[58].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[58].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[58].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[58].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[58].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[58].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[59].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[59].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[59].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[59].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[59].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[59].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[59].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[59].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[59].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[60].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[60].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[60].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[60].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[60].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[60].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[60].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[60].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[60].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[61].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[61].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[61].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[61].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[61].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[61].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[61].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[61].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[61].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[62].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[62].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[62].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[62].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[62].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[62].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[62].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[62].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[62].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[63].cn0, 203)
        << "incorrect value for last_msg.msg.measurement_state.states[63].cn0, "
           "expected 203, is "
        << (int64_t)last_msg.msg.measurement_state.states[63].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[63].mesid.code, 14)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[63].mesid.code, expected 14, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[63].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[63].mesid.sat, 36)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[63].mesid.sat, expected 36, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[63].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[64].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[64].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[64].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[64].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[64].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[64].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[64].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[64].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[64].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[65].cn0, 158)
        << "incorrect value for last_msg.msg.measurement_state.states[65].cn0, "
           "expected 158, is "
        << (int64_t)last_msg.msg.measurement_state.states[65].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[65].mesid.code, 14)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[65].mesid.code, expected 14, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[65].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[65].mesid.sat, 5)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[65].mesid.sat, expected 5, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[65].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[66].cn0, 194)
        << "incorrect value for last_msg.msg.measurement_state.states[66].cn0, "
           "expected 194, is "
        << (int64_t)last_msg.msg.measurement_state.states[66].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[66].mesid.code, 14)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[66].mesid.code, expected 14, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[66].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[66].mesid.sat, 4)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[66].mesid.sat, expected 4, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[66].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[67].cn0, 192)
        << "incorrect value for last_msg.msg.measurement_state.states[67].cn0, "
           "expected 192, is "
        << (int64_t)last_msg.msg.measurement_state.states[67].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[67].mesid.code, 14)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[67].mesid.code, expected 14, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[67].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[67].mesid.sat, 11)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[67].mesid.sat, expected 11, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[67].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[68].cn0, 207)
        << "incorrect value for last_msg.msg.measurement_state.states[68].cn0, "
           "expected 207, is "
        << (int64_t)last_msg.msg.measurement_state.states[68].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[68].mesid.code, 14)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[68].mesid.code, expected 14, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[68].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[68].mesid.sat, 9)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[68].mesid.sat, expected 9, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[68].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[69].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[69].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[69].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[69].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[69].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[69].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[69].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[69].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[69].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[70].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[70].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[70].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[70].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[70].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[70].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[70].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[70].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[70].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[71].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[71].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[71].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[71].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[71].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[71].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[71].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[71].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[71].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[72].cn0, 218)
        << "incorrect value for last_msg.msg.measurement_state.states[72].cn0, "
           "expected 218, is "
        << (int64_t)last_msg.msg.measurement_state.states[72].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[72].mesid.code, 20)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[72].mesid.code, expected 20, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[72].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[72].mesid.sat, 9)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[72].mesid.sat, expected 9, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[72].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[73].cn0, 176)
        << "incorrect value for last_msg.msg.measurement_state.states[73].cn0, "
           "expected 176, is "
        << (int64_t)last_msg.msg.measurement_state.states[73].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[73].mesid.code, 20)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[73].mesid.code, expected 20, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[73].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[73].mesid.sat, 5)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[73].mesid.sat, expected 5, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[73].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[74].cn0, 217)
        << "incorrect value for last_msg.msg.measurement_state.states[74].cn0, "
           "expected 217, is "
        << (int64_t)last_msg.msg.measurement_state.states[74].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[74].mesid.code, 20)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[74].mesid.code, expected 20, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[74].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[74].mesid.sat, 36)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[74].mesid.sat, expected 36, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[74].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[75].cn0, 200)
        << "incorrect value for last_msg.msg.measurement_state.states[75].cn0, "
           "expected 200, is "
        << (int64_t)last_msg.msg.measurement_state.states[75].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[75].mesid.code, 20)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[75].mesid.code, expected 20, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[75].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[75].mesid.sat, 11)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[75].mesid.sat, expected 11, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[75].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[76].cn0, 205)
        << "incorrect value for last_msg.msg.measurement_state.states[76].cn0, "
           "expected 205, is "
        << (int64_t)last_msg.msg.measurement_state.states[76].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[76].mesid.code, 20)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[76].mesid.code, expected 20, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[76].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[76].mesid.sat, 4)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[76].mesid.sat, expected 4, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[76].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[77].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[77].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[77].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[77].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[77].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[77].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[77].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[77].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[77].mesid.sat;

    EXPECT_EQ(last_msg.msg.measurement_state.states[78].cn0, 0)
        << "incorrect value for last_msg.msg.measurement_state.states[78].cn0, "
           "expected 0, is "
        << (int64_t)last_msg.msg.measurement_state.states[78].cn0;

    EXPECT_EQ(last_msg.msg.measurement_state.states[78].mesid.code, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[78].mesid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[78].mesid.code;

    EXPECT_EQ(last_msg.msg.measurement_state.states[78].mesid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.measurement_state.states[78].mesid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.measurement_state.states[78].mesid.sat;
  }
}

}  // namespace
