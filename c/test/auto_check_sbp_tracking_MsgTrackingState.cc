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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingState.yaml by
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

TEST(auto_check_sbp_tracking_MsgTrackingState,
     test_auto_check_sbp_tracking_MsgTrackingState) {
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingState, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  65,  0,   55,  129, 252, 117, 184, 3,   102, 38,  106, 140, 141,
        25,  4,   90,  195, 246, 108, 75,  82,  137, 127, 45,  163, 32,  46,
        187, 93,  153, 60,  201, 147, 23,  29,  5,   208, 181, 30,  219, 69,
        254, 136, 3,   121, 33,  98,  144, 215, 133, 182, 14,  56,  169, 77,
        218, 62,  242, 84,  171, 249, 152, 137, 131, 130, 193, 21,  42,  68,
        253, 227, 216, 227, 24,  26,  210, 179, 19,  15,  227, 255, 122, 75,
        187, 200, 217, 48,  218, 122, 187, 238, 142, 149, 238, 55,  251, 212,
        128, 160, 194, 104, 113, 255, 141, 62,  43,  69,  245, 39,  100, 230,
        108, 56,  247, 68,  149, 143, 137, 101, 233, 70,  49,  165, 38,  110,
        218, 230, 80,  213, 196, 179, 139, 128, 15,  178, 196, 171, 8,   212,
        97,  194, 83,  233, 79,  99,  55,  90,  31,  180, 5,   25,  105, 186,
        22,  224, 80,  111, 8,   48,  106, 166, 4,   48,  156, 49,  86,  19,
        142, 146, 91,  124, 115, 64,  28,  230, 115, 178, 190, 131, 16,  242,
        105, 59,  182, 113, 192, 180, 48,  179, 166, 31,  172, 211, 77,  228,
        140, 49,  128, 77,  240, 194, 134, 194, 41,  58,  18,  53,  129, 55,
        91,  72,  134, 92,  33,  224, 157, 56,  186, 54,  224, 174, 82,  84,
        148, 190, 236, 54,  62,  67,  52,  215, 57,  254, 16,  133, 36,  174,
        219, 172, 145, 17,  192, 179, 111, 97,  207, 56,  208, 134, 180, 17,
        43,  226, 255, 182, 140, 113, 141, 111,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state.n_states = 63;

    test_msg.tracking_state.states[0].cn0 = 102;

    test_msg.tracking_state.states[0].fcn = 3;

    test_msg.tracking_state.states[0].sid.code = 184;

    test_msg.tracking_state.states[0].sid.sat = 117;

    test_msg.tracking_state.states[1].cn0 = 141;

    test_msg.tracking_state.states[1].fcn = 140;

    test_msg.tracking_state.states[1].sid.code = 106;

    test_msg.tracking_state.states[1].sid.sat = 38;

    test_msg.tracking_state.states[2].cn0 = 195;

    test_msg.tracking_state.states[2].fcn = 90;

    test_msg.tracking_state.states[2].sid.code = 4;

    test_msg.tracking_state.states[2].sid.sat = 25;

    test_msg.tracking_state.states[3].cn0 = 82;

    test_msg.tracking_state.states[3].fcn = 75;

    test_msg.tracking_state.states[3].sid.code = 108;

    test_msg.tracking_state.states[3].sid.sat = 246;

    test_msg.tracking_state.states[4].cn0 = 163;

    test_msg.tracking_state.states[4].fcn = 45;

    test_msg.tracking_state.states[4].sid.code = 127;

    test_msg.tracking_state.states[4].sid.sat = 137;

    test_msg.tracking_state.states[5].cn0 = 93;

    test_msg.tracking_state.states[5].fcn = 187;

    test_msg.tracking_state.states[5].sid.code = 46;

    test_msg.tracking_state.states[5].sid.sat = 32;

    test_msg.tracking_state.states[6].cn0 = 147;

    test_msg.tracking_state.states[6].fcn = 201;

    test_msg.tracking_state.states[6].sid.code = 60;

    test_msg.tracking_state.states[6].sid.sat = 153;

    test_msg.tracking_state.states[7].cn0 = 208;

    test_msg.tracking_state.states[7].fcn = 5;

    test_msg.tracking_state.states[7].sid.code = 29;

    test_msg.tracking_state.states[7].sid.sat = 23;

    test_msg.tracking_state.states[8].cn0 = 69;

    test_msg.tracking_state.states[8].fcn = 219;

    test_msg.tracking_state.states[8].sid.code = 30;

    test_msg.tracking_state.states[8].sid.sat = 181;

    test_msg.tracking_state.states[9].cn0 = 121;

    test_msg.tracking_state.states[9].fcn = 3;

    test_msg.tracking_state.states[9].sid.code = 136;

    test_msg.tracking_state.states[9].sid.sat = 254;

    test_msg.tracking_state.states[10].cn0 = 215;

    test_msg.tracking_state.states[10].fcn = 144;

    test_msg.tracking_state.states[10].sid.code = 98;

    test_msg.tracking_state.states[10].sid.sat = 33;

    test_msg.tracking_state.states[11].cn0 = 56;

    test_msg.tracking_state.states[11].fcn = 14;

    test_msg.tracking_state.states[11].sid.code = 182;

    test_msg.tracking_state.states[11].sid.sat = 133;

    test_msg.tracking_state.states[12].cn0 = 62;

    test_msg.tracking_state.states[12].fcn = 218;

    test_msg.tracking_state.states[12].sid.code = 77;

    test_msg.tracking_state.states[12].sid.sat = 169;

    test_msg.tracking_state.states[13].cn0 = 249;

    test_msg.tracking_state.states[13].fcn = 171;

    test_msg.tracking_state.states[13].sid.code = 84;

    test_msg.tracking_state.states[13].sid.sat = 242;

    test_msg.tracking_state.states[14].cn0 = 130;

    test_msg.tracking_state.states[14].fcn = 131;

    test_msg.tracking_state.states[14].sid.code = 137;

    test_msg.tracking_state.states[14].sid.sat = 152;

    test_msg.tracking_state.states[15].cn0 = 68;

    test_msg.tracking_state.states[15].fcn = 42;

    test_msg.tracking_state.states[15].sid.code = 21;

    test_msg.tracking_state.states[15].sid.sat = 193;

    test_msg.tracking_state.states[16].cn0 = 227;

    test_msg.tracking_state.states[16].fcn = 216;

    test_msg.tracking_state.states[16].sid.code = 227;

    test_msg.tracking_state.states[16].sid.sat = 253;

    test_msg.tracking_state.states[17].cn0 = 179;

    test_msg.tracking_state.states[17].fcn = 210;

    test_msg.tracking_state.states[17].sid.code = 26;

    test_msg.tracking_state.states[17].sid.sat = 24;

    test_msg.tracking_state.states[18].cn0 = 255;

    test_msg.tracking_state.states[18].fcn = 227;

    test_msg.tracking_state.states[18].sid.code = 15;

    test_msg.tracking_state.states[18].sid.sat = 19;

    test_msg.tracking_state.states[19].cn0 = 200;

    test_msg.tracking_state.states[19].fcn = 187;

    test_msg.tracking_state.states[19].sid.code = 75;

    test_msg.tracking_state.states[19].sid.sat = 122;

    test_msg.tracking_state.states[20].cn0 = 122;

    test_msg.tracking_state.states[20].fcn = 218;

    test_msg.tracking_state.states[20].sid.code = 48;

    test_msg.tracking_state.states[20].sid.sat = 217;

    test_msg.tracking_state.states[21].cn0 = 149;

    test_msg.tracking_state.states[21].fcn = 142;

    test_msg.tracking_state.states[21].sid.code = 238;

    test_msg.tracking_state.states[21].sid.sat = 187;

    test_msg.tracking_state.states[22].cn0 = 212;

    test_msg.tracking_state.states[22].fcn = 251;

    test_msg.tracking_state.states[22].sid.code = 55;

    test_msg.tracking_state.states[22].sid.sat = 238;

    test_msg.tracking_state.states[23].cn0 = 104;

    test_msg.tracking_state.states[23].fcn = 194;

    test_msg.tracking_state.states[23].sid.code = 160;

    test_msg.tracking_state.states[23].sid.sat = 128;

    test_msg.tracking_state.states[24].cn0 = 62;

    test_msg.tracking_state.states[24].fcn = 141;

    test_msg.tracking_state.states[24].sid.code = 255;

    test_msg.tracking_state.states[24].sid.sat = 113;

    test_msg.tracking_state.states[25].cn0 = 39;

    test_msg.tracking_state.states[25].fcn = 245;

    test_msg.tracking_state.states[25].sid.code = 69;

    test_msg.tracking_state.states[25].sid.sat = 43;

    test_msg.tracking_state.states[26].cn0 = 56;

    test_msg.tracking_state.states[26].fcn = 108;

    test_msg.tracking_state.states[26].sid.code = 230;

    test_msg.tracking_state.states[26].sid.sat = 100;

    test_msg.tracking_state.states[27].cn0 = 143;

    test_msg.tracking_state.states[27].fcn = 149;

    test_msg.tracking_state.states[27].sid.code = 68;

    test_msg.tracking_state.states[27].sid.sat = 247;

    test_msg.tracking_state.states[28].cn0 = 70;

    test_msg.tracking_state.states[28].fcn = 233;

    test_msg.tracking_state.states[28].sid.code = 101;

    test_msg.tracking_state.states[28].sid.sat = 137;

    test_msg.tracking_state.states[29].cn0 = 110;

    test_msg.tracking_state.states[29].fcn = 38;

    test_msg.tracking_state.states[29].sid.code = 165;

    test_msg.tracking_state.states[29].sid.sat = 49;

    test_msg.tracking_state.states[30].cn0 = 213;

    test_msg.tracking_state.states[30].fcn = 80;

    test_msg.tracking_state.states[30].sid.code = 230;

    test_msg.tracking_state.states[30].sid.sat = 218;

    test_msg.tracking_state.states[31].cn0 = 128;

    test_msg.tracking_state.states[31].fcn = 139;

    test_msg.tracking_state.states[31].sid.code = 179;

    test_msg.tracking_state.states[31].sid.sat = 196;

    test_msg.tracking_state.states[32].cn0 = 171;

    test_msg.tracking_state.states[32].fcn = 196;

    test_msg.tracking_state.states[32].sid.code = 178;

    test_msg.tracking_state.states[32].sid.sat = 15;

    test_msg.tracking_state.states[33].cn0 = 194;

    test_msg.tracking_state.states[33].fcn = 97;

    test_msg.tracking_state.states[33].sid.code = 212;

    test_msg.tracking_state.states[33].sid.sat = 8;

    test_msg.tracking_state.states[34].cn0 = 99;

    test_msg.tracking_state.states[34].fcn = 79;

    test_msg.tracking_state.states[34].sid.code = 233;

    test_msg.tracking_state.states[34].sid.sat = 83;

    test_msg.tracking_state.states[35].cn0 = 180;

    test_msg.tracking_state.states[35].fcn = 31;

    test_msg.tracking_state.states[35].sid.code = 90;

    test_msg.tracking_state.states[35].sid.sat = 55;

    test_msg.tracking_state.states[36].cn0 = 186;

    test_msg.tracking_state.states[36].fcn = 105;

    test_msg.tracking_state.states[36].sid.code = 25;

    test_msg.tracking_state.states[36].sid.sat = 5;

    test_msg.tracking_state.states[37].cn0 = 111;

    test_msg.tracking_state.states[37].fcn = 80;

    test_msg.tracking_state.states[37].sid.code = 224;

    test_msg.tracking_state.states[37].sid.sat = 22;

    test_msg.tracking_state.states[38].cn0 = 166;

    test_msg.tracking_state.states[38].fcn = 106;

    test_msg.tracking_state.states[38].sid.code = 48;

    test_msg.tracking_state.states[38].sid.sat = 8;

    test_msg.tracking_state.states[39].cn0 = 49;

    test_msg.tracking_state.states[39].fcn = 156;

    test_msg.tracking_state.states[39].sid.code = 48;

    test_msg.tracking_state.states[39].sid.sat = 4;

    test_msg.tracking_state.states[40].cn0 = 146;

    test_msg.tracking_state.states[40].fcn = 142;

    test_msg.tracking_state.states[40].sid.code = 19;

    test_msg.tracking_state.states[40].sid.sat = 86;

    test_msg.tracking_state.states[41].cn0 = 64;

    test_msg.tracking_state.states[41].fcn = 115;

    test_msg.tracking_state.states[41].sid.code = 124;

    test_msg.tracking_state.states[41].sid.sat = 91;

    test_msg.tracking_state.states[42].cn0 = 178;

    test_msg.tracking_state.states[42].fcn = 115;

    test_msg.tracking_state.states[42].sid.code = 230;

    test_msg.tracking_state.states[42].sid.sat = 28;

    test_msg.tracking_state.states[43].cn0 = 242;

    test_msg.tracking_state.states[43].fcn = 16;

    test_msg.tracking_state.states[43].sid.code = 131;

    test_msg.tracking_state.states[43].sid.sat = 190;

    test_msg.tracking_state.states[44].cn0 = 113;

    test_msg.tracking_state.states[44].fcn = 182;

    test_msg.tracking_state.states[44].sid.code = 59;

    test_msg.tracking_state.states[44].sid.sat = 105;

    test_msg.tracking_state.states[45].cn0 = 179;

    test_msg.tracking_state.states[45].fcn = 48;

    test_msg.tracking_state.states[45].sid.code = 180;

    test_msg.tracking_state.states[45].sid.sat = 192;

    test_msg.tracking_state.states[46].cn0 = 211;

    test_msg.tracking_state.states[46].fcn = 172;

    test_msg.tracking_state.states[46].sid.code = 31;

    test_msg.tracking_state.states[46].sid.sat = 166;

    test_msg.tracking_state.states[47].cn0 = 49;

    test_msg.tracking_state.states[47].fcn = 140;

    test_msg.tracking_state.states[47].sid.code = 228;

    test_msg.tracking_state.states[47].sid.sat = 77;

    test_msg.tracking_state.states[48].cn0 = 194;

    test_msg.tracking_state.states[48].fcn = 240;

    test_msg.tracking_state.states[48].sid.code = 77;

    test_msg.tracking_state.states[48].sid.sat = 128;

    test_msg.tracking_state.states[49].cn0 = 58;

    test_msg.tracking_state.states[49].fcn = 41;

    test_msg.tracking_state.states[49].sid.code = 194;

    test_msg.tracking_state.states[49].sid.sat = 134;

    test_msg.tracking_state.states[50].cn0 = 55;

    test_msg.tracking_state.states[50].fcn = 129;

    test_msg.tracking_state.states[50].sid.code = 53;

    test_msg.tracking_state.states[50].sid.sat = 18;

    test_msg.tracking_state.states[51].cn0 = 92;

    test_msg.tracking_state.states[51].fcn = 134;

    test_msg.tracking_state.states[51].sid.code = 72;

    test_msg.tracking_state.states[51].sid.sat = 91;

    test_msg.tracking_state.states[52].cn0 = 56;

    test_msg.tracking_state.states[52].fcn = 157;

    test_msg.tracking_state.states[52].sid.code = 224;

    test_msg.tracking_state.states[52].sid.sat = 33;

    test_msg.tracking_state.states[53].cn0 = 174;

    test_msg.tracking_state.states[53].fcn = 224;

    test_msg.tracking_state.states[53].sid.code = 54;

    test_msg.tracking_state.states[53].sid.sat = 186;

    test_msg.tracking_state.states[54].cn0 = 190;

    test_msg.tracking_state.states[54].fcn = 148;

    test_msg.tracking_state.states[54].sid.code = 84;

    test_msg.tracking_state.states[54].sid.sat = 82;

    test_msg.tracking_state.states[55].cn0 = 67;

    test_msg.tracking_state.states[55].fcn = 62;

    test_msg.tracking_state.states[55].sid.code = 54;

    test_msg.tracking_state.states[55].sid.sat = 236;

    test_msg.tracking_state.states[56].cn0 = 254;

    test_msg.tracking_state.states[56].fcn = 57;

    test_msg.tracking_state.states[56].sid.code = 215;

    test_msg.tracking_state.states[56].sid.sat = 52;

    test_msg.tracking_state.states[57].cn0 = 174;

    test_msg.tracking_state.states[57].fcn = 36;

    test_msg.tracking_state.states[57].sid.code = 133;

    test_msg.tracking_state.states[57].sid.sat = 16;

    test_msg.tracking_state.states[58].cn0 = 17;

    test_msg.tracking_state.states[58].fcn = 145;

    test_msg.tracking_state.states[58].sid.code = 172;

    test_msg.tracking_state.states[58].sid.sat = 219;

    test_msg.tracking_state.states[59].cn0 = 97;

    test_msg.tracking_state.states[59].fcn = 111;

    test_msg.tracking_state.states[59].sid.code = 179;

    test_msg.tracking_state.states[59].sid.sat = 192;

    test_msg.tracking_state.states[60].cn0 = 134;

    test_msg.tracking_state.states[60].fcn = 208;

    test_msg.tracking_state.states[60].sid.code = 56;

    test_msg.tracking_state.states[60].sid.sat = 207;

    test_msg.tracking_state.states[61].cn0 = 226;

    test_msg.tracking_state.states[61].fcn = 43;

    test_msg.tracking_state.states[61].sid.code = 17;

    test_msg.tracking_state.states[61].sid.sat = 180;

    test_msg.tracking_state.states[62].cn0 = 113;

    test_msg.tracking_state.states[62].fcn = 140;

    test_msg.tracking_state.states[62].sid.code = 182;

    test_msg.tracking_state.states[62].sid.sat = 255;

    sbp_message_send(&sbp_state, SbpMsgTrackingState, 33079, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 33079)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingState, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state.n_states, 63)
        << "incorrect value for last_msg.msg.tracking_state.n_states, expected "
           "63, is "
        << (int64_t)last_msg.msg.tracking_state.n_states;

    EXPECT_EQ(last_msg.msg.tracking_state.states[0].cn0, 102)
        << "incorrect value for last_msg.msg.tracking_state.states[0].cn0, "
           "expected 102, is "
        << (int64_t)last_msg.msg.tracking_state.states[0].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[0].fcn, 3)
        << "incorrect value for last_msg.msg.tracking_state.states[0].fcn, "
           "expected 3, is "
        << (int64_t)last_msg.msg.tracking_state.states[0].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[0].sid.code, 184)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[0].sid.code, expected 184, is "
        << (int64_t)last_msg.msg.tracking_state.states[0].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[0].sid.sat, 117)
        << "incorrect value for last_msg.msg.tracking_state.states[0].sid.sat, "
           "expected 117, is "
        << (int64_t)last_msg.msg.tracking_state.states[0].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[1].cn0, 141)
        << "incorrect value for last_msg.msg.tracking_state.states[1].cn0, "
           "expected 141, is "
        << (int64_t)last_msg.msg.tracking_state.states[1].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[1].fcn, 140)
        << "incorrect value for last_msg.msg.tracking_state.states[1].fcn, "
           "expected 140, is "
        << (int64_t)last_msg.msg.tracking_state.states[1].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[1].sid.code, 106)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[1].sid.code, expected 106, is "
        << (int64_t)last_msg.msg.tracking_state.states[1].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[1].sid.sat, 38)
        << "incorrect value for last_msg.msg.tracking_state.states[1].sid.sat, "
           "expected 38, is "
        << (int64_t)last_msg.msg.tracking_state.states[1].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[2].cn0, 195)
        << "incorrect value for last_msg.msg.tracking_state.states[2].cn0, "
           "expected 195, is "
        << (int64_t)last_msg.msg.tracking_state.states[2].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[2].fcn, 90)
        << "incorrect value for last_msg.msg.tracking_state.states[2].fcn, "
           "expected 90, is "
        << (int64_t)last_msg.msg.tracking_state.states[2].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[2].sid.code, 4)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[2].sid.code, expected 4, is "
        << (int64_t)last_msg.msg.tracking_state.states[2].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[2].sid.sat, 25)
        << "incorrect value for last_msg.msg.tracking_state.states[2].sid.sat, "
           "expected 25, is "
        << (int64_t)last_msg.msg.tracking_state.states[2].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[3].cn0, 82)
        << "incorrect value for last_msg.msg.tracking_state.states[3].cn0, "
           "expected 82, is "
        << (int64_t)last_msg.msg.tracking_state.states[3].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[3].fcn, 75)
        << "incorrect value for last_msg.msg.tracking_state.states[3].fcn, "
           "expected 75, is "
        << (int64_t)last_msg.msg.tracking_state.states[3].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[3].sid.code, 108)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[3].sid.code, expected 108, is "
        << (int64_t)last_msg.msg.tracking_state.states[3].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[3].sid.sat, 246)
        << "incorrect value for last_msg.msg.tracking_state.states[3].sid.sat, "
           "expected 246, is "
        << (int64_t)last_msg.msg.tracking_state.states[3].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[4].cn0, 163)
        << "incorrect value for last_msg.msg.tracking_state.states[4].cn0, "
           "expected 163, is "
        << (int64_t)last_msg.msg.tracking_state.states[4].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[4].fcn, 45)
        << "incorrect value for last_msg.msg.tracking_state.states[4].fcn, "
           "expected 45, is "
        << (int64_t)last_msg.msg.tracking_state.states[4].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[4].sid.code, 127)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[4].sid.code, expected 127, is "
        << (int64_t)last_msg.msg.tracking_state.states[4].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[4].sid.sat, 137)
        << "incorrect value for last_msg.msg.tracking_state.states[4].sid.sat, "
           "expected 137, is "
        << (int64_t)last_msg.msg.tracking_state.states[4].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[5].cn0, 93)
        << "incorrect value for last_msg.msg.tracking_state.states[5].cn0, "
           "expected 93, is "
        << (int64_t)last_msg.msg.tracking_state.states[5].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[5].fcn, 187)
        << "incorrect value for last_msg.msg.tracking_state.states[5].fcn, "
           "expected 187, is "
        << (int64_t)last_msg.msg.tracking_state.states[5].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[5].sid.code, 46)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[5].sid.code, expected 46, is "
        << (int64_t)last_msg.msg.tracking_state.states[5].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[5].sid.sat, 32)
        << "incorrect value for last_msg.msg.tracking_state.states[5].sid.sat, "
           "expected 32, is "
        << (int64_t)last_msg.msg.tracking_state.states[5].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[6].cn0, 147)
        << "incorrect value for last_msg.msg.tracking_state.states[6].cn0, "
           "expected 147, is "
        << (int64_t)last_msg.msg.tracking_state.states[6].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[6].fcn, 201)
        << "incorrect value for last_msg.msg.tracking_state.states[6].fcn, "
           "expected 201, is "
        << (int64_t)last_msg.msg.tracking_state.states[6].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[6].sid.code, 60)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[6].sid.code, expected 60, is "
        << (int64_t)last_msg.msg.tracking_state.states[6].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[6].sid.sat, 153)
        << "incorrect value for last_msg.msg.tracking_state.states[6].sid.sat, "
           "expected 153, is "
        << (int64_t)last_msg.msg.tracking_state.states[6].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[7].cn0, 208)
        << "incorrect value for last_msg.msg.tracking_state.states[7].cn0, "
           "expected 208, is "
        << (int64_t)last_msg.msg.tracking_state.states[7].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[7].fcn, 5)
        << "incorrect value for last_msg.msg.tracking_state.states[7].fcn, "
           "expected 5, is "
        << (int64_t)last_msg.msg.tracking_state.states[7].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[7].sid.code, 29)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[7].sid.code, expected 29, is "
        << (int64_t)last_msg.msg.tracking_state.states[7].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[7].sid.sat, 23)
        << "incorrect value for last_msg.msg.tracking_state.states[7].sid.sat, "
           "expected 23, is "
        << (int64_t)last_msg.msg.tracking_state.states[7].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[8].cn0, 69)
        << "incorrect value for last_msg.msg.tracking_state.states[8].cn0, "
           "expected 69, is "
        << (int64_t)last_msg.msg.tracking_state.states[8].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[8].fcn, 219)
        << "incorrect value for last_msg.msg.tracking_state.states[8].fcn, "
           "expected 219, is "
        << (int64_t)last_msg.msg.tracking_state.states[8].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[8].sid.code, 30)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[8].sid.code, expected 30, is "
        << (int64_t)last_msg.msg.tracking_state.states[8].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[8].sid.sat, 181)
        << "incorrect value for last_msg.msg.tracking_state.states[8].sid.sat, "
           "expected 181, is "
        << (int64_t)last_msg.msg.tracking_state.states[8].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[9].cn0, 121)
        << "incorrect value for last_msg.msg.tracking_state.states[9].cn0, "
           "expected 121, is "
        << (int64_t)last_msg.msg.tracking_state.states[9].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[9].fcn, 3)
        << "incorrect value for last_msg.msg.tracking_state.states[9].fcn, "
           "expected 3, is "
        << (int64_t)last_msg.msg.tracking_state.states[9].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[9].sid.code, 136)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[9].sid.code, expected 136, is "
        << (int64_t)last_msg.msg.tracking_state.states[9].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[9].sid.sat, 254)
        << "incorrect value for last_msg.msg.tracking_state.states[9].sid.sat, "
           "expected 254, is "
        << (int64_t)last_msg.msg.tracking_state.states[9].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[10].cn0, 215)
        << "incorrect value for last_msg.msg.tracking_state.states[10].cn0, "
           "expected 215, is "
        << (int64_t)last_msg.msg.tracking_state.states[10].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[10].fcn, 144)
        << "incorrect value for last_msg.msg.tracking_state.states[10].fcn, "
           "expected 144, is "
        << (int64_t)last_msg.msg.tracking_state.states[10].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[10].sid.code, 98)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[10].sid.code, expected 98, is "
        << (int64_t)last_msg.msg.tracking_state.states[10].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[10].sid.sat, 33)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[10].sid.sat, expected 33, is "
        << (int64_t)last_msg.msg.tracking_state.states[10].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[11].cn0, 56)
        << "incorrect value for last_msg.msg.tracking_state.states[11].cn0, "
           "expected 56, is "
        << (int64_t)last_msg.msg.tracking_state.states[11].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[11].fcn, 14)
        << "incorrect value for last_msg.msg.tracking_state.states[11].fcn, "
           "expected 14, is "
        << (int64_t)last_msg.msg.tracking_state.states[11].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[11].sid.code, 182)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[11].sid.code, expected 182, is "
        << (int64_t)last_msg.msg.tracking_state.states[11].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[11].sid.sat, 133)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[11].sid.sat, expected 133, is "
        << (int64_t)last_msg.msg.tracking_state.states[11].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[12].cn0, 62)
        << "incorrect value for last_msg.msg.tracking_state.states[12].cn0, "
           "expected 62, is "
        << (int64_t)last_msg.msg.tracking_state.states[12].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[12].fcn, 218)
        << "incorrect value for last_msg.msg.tracking_state.states[12].fcn, "
           "expected 218, is "
        << (int64_t)last_msg.msg.tracking_state.states[12].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[12].sid.code, 77)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[12].sid.code, expected 77, is "
        << (int64_t)last_msg.msg.tracking_state.states[12].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[12].sid.sat, 169)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[12].sid.sat, expected 169, is "
        << (int64_t)last_msg.msg.tracking_state.states[12].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[13].cn0, 249)
        << "incorrect value for last_msg.msg.tracking_state.states[13].cn0, "
           "expected 249, is "
        << (int64_t)last_msg.msg.tracking_state.states[13].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[13].fcn, 171)
        << "incorrect value for last_msg.msg.tracking_state.states[13].fcn, "
           "expected 171, is "
        << (int64_t)last_msg.msg.tracking_state.states[13].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[13].sid.code, 84)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[13].sid.code, expected 84, is "
        << (int64_t)last_msg.msg.tracking_state.states[13].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[13].sid.sat, 242)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[13].sid.sat, expected 242, is "
        << (int64_t)last_msg.msg.tracking_state.states[13].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[14].cn0, 130)
        << "incorrect value for last_msg.msg.tracking_state.states[14].cn0, "
           "expected 130, is "
        << (int64_t)last_msg.msg.tracking_state.states[14].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[14].fcn, 131)
        << "incorrect value for last_msg.msg.tracking_state.states[14].fcn, "
           "expected 131, is "
        << (int64_t)last_msg.msg.tracking_state.states[14].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[14].sid.code, 137)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[14].sid.code, expected 137, is "
        << (int64_t)last_msg.msg.tracking_state.states[14].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[14].sid.sat, 152)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[14].sid.sat, expected 152, is "
        << (int64_t)last_msg.msg.tracking_state.states[14].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[15].cn0, 68)
        << "incorrect value for last_msg.msg.tracking_state.states[15].cn0, "
           "expected 68, is "
        << (int64_t)last_msg.msg.tracking_state.states[15].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[15].fcn, 42)
        << "incorrect value for last_msg.msg.tracking_state.states[15].fcn, "
           "expected 42, is "
        << (int64_t)last_msg.msg.tracking_state.states[15].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[15].sid.code, 21)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[15].sid.code, expected 21, is "
        << (int64_t)last_msg.msg.tracking_state.states[15].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[15].sid.sat, 193)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[15].sid.sat, expected 193, is "
        << (int64_t)last_msg.msg.tracking_state.states[15].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[16].cn0, 227)
        << "incorrect value for last_msg.msg.tracking_state.states[16].cn0, "
           "expected 227, is "
        << (int64_t)last_msg.msg.tracking_state.states[16].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[16].fcn, 216)
        << "incorrect value for last_msg.msg.tracking_state.states[16].fcn, "
           "expected 216, is "
        << (int64_t)last_msg.msg.tracking_state.states[16].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[16].sid.code, 227)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[16].sid.code, expected 227, is "
        << (int64_t)last_msg.msg.tracking_state.states[16].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[16].sid.sat, 253)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[16].sid.sat, expected 253, is "
        << (int64_t)last_msg.msg.tracking_state.states[16].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[17].cn0, 179)
        << "incorrect value for last_msg.msg.tracking_state.states[17].cn0, "
           "expected 179, is "
        << (int64_t)last_msg.msg.tracking_state.states[17].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[17].fcn, 210)
        << "incorrect value for last_msg.msg.tracking_state.states[17].fcn, "
           "expected 210, is "
        << (int64_t)last_msg.msg.tracking_state.states[17].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[17].sid.code, 26)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[17].sid.code, expected 26, is "
        << (int64_t)last_msg.msg.tracking_state.states[17].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[17].sid.sat, 24)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[17].sid.sat, expected 24, is "
        << (int64_t)last_msg.msg.tracking_state.states[17].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[18].cn0, 255)
        << "incorrect value for last_msg.msg.tracking_state.states[18].cn0, "
           "expected 255, is "
        << (int64_t)last_msg.msg.tracking_state.states[18].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[18].fcn, 227)
        << "incorrect value for last_msg.msg.tracking_state.states[18].fcn, "
           "expected 227, is "
        << (int64_t)last_msg.msg.tracking_state.states[18].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[18].sid.code, 15)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[18].sid.code, expected 15, is "
        << (int64_t)last_msg.msg.tracking_state.states[18].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[18].sid.sat, 19)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[18].sid.sat, expected 19, is "
        << (int64_t)last_msg.msg.tracking_state.states[18].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[19].cn0, 200)
        << "incorrect value for last_msg.msg.tracking_state.states[19].cn0, "
           "expected 200, is "
        << (int64_t)last_msg.msg.tracking_state.states[19].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[19].fcn, 187)
        << "incorrect value for last_msg.msg.tracking_state.states[19].fcn, "
           "expected 187, is "
        << (int64_t)last_msg.msg.tracking_state.states[19].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[19].sid.code, 75)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[19].sid.code, expected 75, is "
        << (int64_t)last_msg.msg.tracking_state.states[19].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[19].sid.sat, 122)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[19].sid.sat, expected 122, is "
        << (int64_t)last_msg.msg.tracking_state.states[19].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[20].cn0, 122)
        << "incorrect value for last_msg.msg.tracking_state.states[20].cn0, "
           "expected 122, is "
        << (int64_t)last_msg.msg.tracking_state.states[20].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[20].fcn, 218)
        << "incorrect value for last_msg.msg.tracking_state.states[20].fcn, "
           "expected 218, is "
        << (int64_t)last_msg.msg.tracking_state.states[20].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[20].sid.code, 48)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[20].sid.code, expected 48, is "
        << (int64_t)last_msg.msg.tracking_state.states[20].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[20].sid.sat, 217)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[20].sid.sat, expected 217, is "
        << (int64_t)last_msg.msg.tracking_state.states[20].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[21].cn0, 149)
        << "incorrect value for last_msg.msg.tracking_state.states[21].cn0, "
           "expected 149, is "
        << (int64_t)last_msg.msg.tracking_state.states[21].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[21].fcn, 142)
        << "incorrect value for last_msg.msg.tracking_state.states[21].fcn, "
           "expected 142, is "
        << (int64_t)last_msg.msg.tracking_state.states[21].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[21].sid.code, 238)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[21].sid.code, expected 238, is "
        << (int64_t)last_msg.msg.tracking_state.states[21].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[21].sid.sat, 187)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[21].sid.sat, expected 187, is "
        << (int64_t)last_msg.msg.tracking_state.states[21].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[22].cn0, 212)
        << "incorrect value for last_msg.msg.tracking_state.states[22].cn0, "
           "expected 212, is "
        << (int64_t)last_msg.msg.tracking_state.states[22].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[22].fcn, 251)
        << "incorrect value for last_msg.msg.tracking_state.states[22].fcn, "
           "expected 251, is "
        << (int64_t)last_msg.msg.tracking_state.states[22].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[22].sid.code, 55)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[22].sid.code, expected 55, is "
        << (int64_t)last_msg.msg.tracking_state.states[22].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[22].sid.sat, 238)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[22].sid.sat, expected 238, is "
        << (int64_t)last_msg.msg.tracking_state.states[22].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[23].cn0, 104)
        << "incorrect value for last_msg.msg.tracking_state.states[23].cn0, "
           "expected 104, is "
        << (int64_t)last_msg.msg.tracking_state.states[23].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[23].fcn, 194)
        << "incorrect value for last_msg.msg.tracking_state.states[23].fcn, "
           "expected 194, is "
        << (int64_t)last_msg.msg.tracking_state.states[23].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[23].sid.code, 160)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[23].sid.code, expected 160, is "
        << (int64_t)last_msg.msg.tracking_state.states[23].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[23].sid.sat, 128)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[23].sid.sat, expected 128, is "
        << (int64_t)last_msg.msg.tracking_state.states[23].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[24].cn0, 62)
        << "incorrect value for last_msg.msg.tracking_state.states[24].cn0, "
           "expected 62, is "
        << (int64_t)last_msg.msg.tracking_state.states[24].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[24].fcn, 141)
        << "incorrect value for last_msg.msg.tracking_state.states[24].fcn, "
           "expected 141, is "
        << (int64_t)last_msg.msg.tracking_state.states[24].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[24].sid.code, 255)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[24].sid.code, expected 255, is "
        << (int64_t)last_msg.msg.tracking_state.states[24].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[24].sid.sat, 113)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[24].sid.sat, expected 113, is "
        << (int64_t)last_msg.msg.tracking_state.states[24].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[25].cn0, 39)
        << "incorrect value for last_msg.msg.tracking_state.states[25].cn0, "
           "expected 39, is "
        << (int64_t)last_msg.msg.tracking_state.states[25].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[25].fcn, 245)
        << "incorrect value for last_msg.msg.tracking_state.states[25].fcn, "
           "expected 245, is "
        << (int64_t)last_msg.msg.tracking_state.states[25].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[25].sid.code, 69)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[25].sid.code, expected 69, is "
        << (int64_t)last_msg.msg.tracking_state.states[25].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[25].sid.sat, 43)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[25].sid.sat, expected 43, is "
        << (int64_t)last_msg.msg.tracking_state.states[25].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[26].cn0, 56)
        << "incorrect value for last_msg.msg.tracking_state.states[26].cn0, "
           "expected 56, is "
        << (int64_t)last_msg.msg.tracking_state.states[26].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[26].fcn, 108)
        << "incorrect value for last_msg.msg.tracking_state.states[26].fcn, "
           "expected 108, is "
        << (int64_t)last_msg.msg.tracking_state.states[26].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[26].sid.code, 230)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[26].sid.code, expected 230, is "
        << (int64_t)last_msg.msg.tracking_state.states[26].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[26].sid.sat, 100)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[26].sid.sat, expected 100, is "
        << (int64_t)last_msg.msg.tracking_state.states[26].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[27].cn0, 143)
        << "incorrect value for last_msg.msg.tracking_state.states[27].cn0, "
           "expected 143, is "
        << (int64_t)last_msg.msg.tracking_state.states[27].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[27].fcn, 149)
        << "incorrect value for last_msg.msg.tracking_state.states[27].fcn, "
           "expected 149, is "
        << (int64_t)last_msg.msg.tracking_state.states[27].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[27].sid.code, 68)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[27].sid.code, expected 68, is "
        << (int64_t)last_msg.msg.tracking_state.states[27].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[27].sid.sat, 247)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[27].sid.sat, expected 247, is "
        << (int64_t)last_msg.msg.tracking_state.states[27].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[28].cn0, 70)
        << "incorrect value for last_msg.msg.tracking_state.states[28].cn0, "
           "expected 70, is "
        << (int64_t)last_msg.msg.tracking_state.states[28].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[28].fcn, 233)
        << "incorrect value for last_msg.msg.tracking_state.states[28].fcn, "
           "expected 233, is "
        << (int64_t)last_msg.msg.tracking_state.states[28].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[28].sid.code, 101)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[28].sid.code, expected 101, is "
        << (int64_t)last_msg.msg.tracking_state.states[28].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[28].sid.sat, 137)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[28].sid.sat, expected 137, is "
        << (int64_t)last_msg.msg.tracking_state.states[28].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[29].cn0, 110)
        << "incorrect value for last_msg.msg.tracking_state.states[29].cn0, "
           "expected 110, is "
        << (int64_t)last_msg.msg.tracking_state.states[29].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[29].fcn, 38)
        << "incorrect value for last_msg.msg.tracking_state.states[29].fcn, "
           "expected 38, is "
        << (int64_t)last_msg.msg.tracking_state.states[29].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[29].sid.code, 165)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[29].sid.code, expected 165, is "
        << (int64_t)last_msg.msg.tracking_state.states[29].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[29].sid.sat, 49)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[29].sid.sat, expected 49, is "
        << (int64_t)last_msg.msg.tracking_state.states[29].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[30].cn0, 213)
        << "incorrect value for last_msg.msg.tracking_state.states[30].cn0, "
           "expected 213, is "
        << (int64_t)last_msg.msg.tracking_state.states[30].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[30].fcn, 80)
        << "incorrect value for last_msg.msg.tracking_state.states[30].fcn, "
           "expected 80, is "
        << (int64_t)last_msg.msg.tracking_state.states[30].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[30].sid.code, 230)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[30].sid.code, expected 230, is "
        << (int64_t)last_msg.msg.tracking_state.states[30].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[30].sid.sat, 218)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[30].sid.sat, expected 218, is "
        << (int64_t)last_msg.msg.tracking_state.states[30].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[31].cn0, 128)
        << "incorrect value for last_msg.msg.tracking_state.states[31].cn0, "
           "expected 128, is "
        << (int64_t)last_msg.msg.tracking_state.states[31].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[31].fcn, 139)
        << "incorrect value for last_msg.msg.tracking_state.states[31].fcn, "
           "expected 139, is "
        << (int64_t)last_msg.msg.tracking_state.states[31].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[31].sid.code, 179)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[31].sid.code, expected 179, is "
        << (int64_t)last_msg.msg.tracking_state.states[31].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[31].sid.sat, 196)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[31].sid.sat, expected 196, is "
        << (int64_t)last_msg.msg.tracking_state.states[31].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[32].cn0, 171)
        << "incorrect value for last_msg.msg.tracking_state.states[32].cn0, "
           "expected 171, is "
        << (int64_t)last_msg.msg.tracking_state.states[32].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[32].fcn, 196)
        << "incorrect value for last_msg.msg.tracking_state.states[32].fcn, "
           "expected 196, is "
        << (int64_t)last_msg.msg.tracking_state.states[32].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[32].sid.code, 178)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[32].sid.code, expected 178, is "
        << (int64_t)last_msg.msg.tracking_state.states[32].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[32].sid.sat, 15)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[32].sid.sat, expected 15, is "
        << (int64_t)last_msg.msg.tracking_state.states[32].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[33].cn0, 194)
        << "incorrect value for last_msg.msg.tracking_state.states[33].cn0, "
           "expected 194, is "
        << (int64_t)last_msg.msg.tracking_state.states[33].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[33].fcn, 97)
        << "incorrect value for last_msg.msg.tracking_state.states[33].fcn, "
           "expected 97, is "
        << (int64_t)last_msg.msg.tracking_state.states[33].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[33].sid.code, 212)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[33].sid.code, expected 212, is "
        << (int64_t)last_msg.msg.tracking_state.states[33].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[33].sid.sat, 8)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[33].sid.sat, expected 8, is "
        << (int64_t)last_msg.msg.tracking_state.states[33].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[34].cn0, 99)
        << "incorrect value for last_msg.msg.tracking_state.states[34].cn0, "
           "expected 99, is "
        << (int64_t)last_msg.msg.tracking_state.states[34].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[34].fcn, 79)
        << "incorrect value for last_msg.msg.tracking_state.states[34].fcn, "
           "expected 79, is "
        << (int64_t)last_msg.msg.tracking_state.states[34].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[34].sid.code, 233)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[34].sid.code, expected 233, is "
        << (int64_t)last_msg.msg.tracking_state.states[34].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[34].sid.sat, 83)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[34].sid.sat, expected 83, is "
        << (int64_t)last_msg.msg.tracking_state.states[34].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[35].cn0, 180)
        << "incorrect value for last_msg.msg.tracking_state.states[35].cn0, "
           "expected 180, is "
        << (int64_t)last_msg.msg.tracking_state.states[35].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[35].fcn, 31)
        << "incorrect value for last_msg.msg.tracking_state.states[35].fcn, "
           "expected 31, is "
        << (int64_t)last_msg.msg.tracking_state.states[35].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[35].sid.code, 90)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[35].sid.code, expected 90, is "
        << (int64_t)last_msg.msg.tracking_state.states[35].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[35].sid.sat, 55)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[35].sid.sat, expected 55, is "
        << (int64_t)last_msg.msg.tracking_state.states[35].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[36].cn0, 186)
        << "incorrect value for last_msg.msg.tracking_state.states[36].cn0, "
           "expected 186, is "
        << (int64_t)last_msg.msg.tracking_state.states[36].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[36].fcn, 105)
        << "incorrect value for last_msg.msg.tracking_state.states[36].fcn, "
           "expected 105, is "
        << (int64_t)last_msg.msg.tracking_state.states[36].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[36].sid.code, 25)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[36].sid.code, expected 25, is "
        << (int64_t)last_msg.msg.tracking_state.states[36].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[36].sid.sat, 5)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[36].sid.sat, expected 5, is "
        << (int64_t)last_msg.msg.tracking_state.states[36].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[37].cn0, 111)
        << "incorrect value for last_msg.msg.tracking_state.states[37].cn0, "
           "expected 111, is "
        << (int64_t)last_msg.msg.tracking_state.states[37].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[37].fcn, 80)
        << "incorrect value for last_msg.msg.tracking_state.states[37].fcn, "
           "expected 80, is "
        << (int64_t)last_msg.msg.tracking_state.states[37].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[37].sid.code, 224)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[37].sid.code, expected 224, is "
        << (int64_t)last_msg.msg.tracking_state.states[37].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[37].sid.sat, 22)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[37].sid.sat, expected 22, is "
        << (int64_t)last_msg.msg.tracking_state.states[37].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[38].cn0, 166)
        << "incorrect value for last_msg.msg.tracking_state.states[38].cn0, "
           "expected 166, is "
        << (int64_t)last_msg.msg.tracking_state.states[38].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[38].fcn, 106)
        << "incorrect value for last_msg.msg.tracking_state.states[38].fcn, "
           "expected 106, is "
        << (int64_t)last_msg.msg.tracking_state.states[38].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[38].sid.code, 48)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[38].sid.code, expected 48, is "
        << (int64_t)last_msg.msg.tracking_state.states[38].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[38].sid.sat, 8)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[38].sid.sat, expected 8, is "
        << (int64_t)last_msg.msg.tracking_state.states[38].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[39].cn0, 49)
        << "incorrect value for last_msg.msg.tracking_state.states[39].cn0, "
           "expected 49, is "
        << (int64_t)last_msg.msg.tracking_state.states[39].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[39].fcn, 156)
        << "incorrect value for last_msg.msg.tracking_state.states[39].fcn, "
           "expected 156, is "
        << (int64_t)last_msg.msg.tracking_state.states[39].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[39].sid.code, 48)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[39].sid.code, expected 48, is "
        << (int64_t)last_msg.msg.tracking_state.states[39].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[39].sid.sat, 4)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[39].sid.sat, expected 4, is "
        << (int64_t)last_msg.msg.tracking_state.states[39].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[40].cn0, 146)
        << "incorrect value for last_msg.msg.tracking_state.states[40].cn0, "
           "expected 146, is "
        << (int64_t)last_msg.msg.tracking_state.states[40].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[40].fcn, 142)
        << "incorrect value for last_msg.msg.tracking_state.states[40].fcn, "
           "expected 142, is "
        << (int64_t)last_msg.msg.tracking_state.states[40].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[40].sid.code, 19)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[40].sid.code, expected 19, is "
        << (int64_t)last_msg.msg.tracking_state.states[40].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[40].sid.sat, 86)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[40].sid.sat, expected 86, is "
        << (int64_t)last_msg.msg.tracking_state.states[40].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[41].cn0, 64)
        << "incorrect value for last_msg.msg.tracking_state.states[41].cn0, "
           "expected 64, is "
        << (int64_t)last_msg.msg.tracking_state.states[41].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[41].fcn, 115)
        << "incorrect value for last_msg.msg.tracking_state.states[41].fcn, "
           "expected 115, is "
        << (int64_t)last_msg.msg.tracking_state.states[41].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[41].sid.code, 124)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[41].sid.code, expected 124, is "
        << (int64_t)last_msg.msg.tracking_state.states[41].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[41].sid.sat, 91)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[41].sid.sat, expected 91, is "
        << (int64_t)last_msg.msg.tracking_state.states[41].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[42].cn0, 178)
        << "incorrect value for last_msg.msg.tracking_state.states[42].cn0, "
           "expected 178, is "
        << (int64_t)last_msg.msg.tracking_state.states[42].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[42].fcn, 115)
        << "incorrect value for last_msg.msg.tracking_state.states[42].fcn, "
           "expected 115, is "
        << (int64_t)last_msg.msg.tracking_state.states[42].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[42].sid.code, 230)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[42].sid.code, expected 230, is "
        << (int64_t)last_msg.msg.tracking_state.states[42].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[42].sid.sat, 28)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[42].sid.sat, expected 28, is "
        << (int64_t)last_msg.msg.tracking_state.states[42].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[43].cn0, 242)
        << "incorrect value for last_msg.msg.tracking_state.states[43].cn0, "
           "expected 242, is "
        << (int64_t)last_msg.msg.tracking_state.states[43].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[43].fcn, 16)
        << "incorrect value for last_msg.msg.tracking_state.states[43].fcn, "
           "expected 16, is "
        << (int64_t)last_msg.msg.tracking_state.states[43].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[43].sid.code, 131)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[43].sid.code, expected 131, is "
        << (int64_t)last_msg.msg.tracking_state.states[43].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[43].sid.sat, 190)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[43].sid.sat, expected 190, is "
        << (int64_t)last_msg.msg.tracking_state.states[43].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[44].cn0, 113)
        << "incorrect value for last_msg.msg.tracking_state.states[44].cn0, "
           "expected 113, is "
        << (int64_t)last_msg.msg.tracking_state.states[44].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[44].fcn, 182)
        << "incorrect value for last_msg.msg.tracking_state.states[44].fcn, "
           "expected 182, is "
        << (int64_t)last_msg.msg.tracking_state.states[44].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[44].sid.code, 59)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[44].sid.code, expected 59, is "
        << (int64_t)last_msg.msg.tracking_state.states[44].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[44].sid.sat, 105)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[44].sid.sat, expected 105, is "
        << (int64_t)last_msg.msg.tracking_state.states[44].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[45].cn0, 179)
        << "incorrect value for last_msg.msg.tracking_state.states[45].cn0, "
           "expected 179, is "
        << (int64_t)last_msg.msg.tracking_state.states[45].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[45].fcn, 48)
        << "incorrect value for last_msg.msg.tracking_state.states[45].fcn, "
           "expected 48, is "
        << (int64_t)last_msg.msg.tracking_state.states[45].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[45].sid.code, 180)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[45].sid.code, expected 180, is "
        << (int64_t)last_msg.msg.tracking_state.states[45].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[45].sid.sat, 192)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[45].sid.sat, expected 192, is "
        << (int64_t)last_msg.msg.tracking_state.states[45].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[46].cn0, 211)
        << "incorrect value for last_msg.msg.tracking_state.states[46].cn0, "
           "expected 211, is "
        << (int64_t)last_msg.msg.tracking_state.states[46].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[46].fcn, 172)
        << "incorrect value for last_msg.msg.tracking_state.states[46].fcn, "
           "expected 172, is "
        << (int64_t)last_msg.msg.tracking_state.states[46].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[46].sid.code, 31)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[46].sid.code, expected 31, is "
        << (int64_t)last_msg.msg.tracking_state.states[46].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[46].sid.sat, 166)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[46].sid.sat, expected 166, is "
        << (int64_t)last_msg.msg.tracking_state.states[46].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[47].cn0, 49)
        << "incorrect value for last_msg.msg.tracking_state.states[47].cn0, "
           "expected 49, is "
        << (int64_t)last_msg.msg.tracking_state.states[47].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[47].fcn, 140)
        << "incorrect value for last_msg.msg.tracking_state.states[47].fcn, "
           "expected 140, is "
        << (int64_t)last_msg.msg.tracking_state.states[47].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[47].sid.code, 228)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[47].sid.code, expected 228, is "
        << (int64_t)last_msg.msg.tracking_state.states[47].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[47].sid.sat, 77)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[47].sid.sat, expected 77, is "
        << (int64_t)last_msg.msg.tracking_state.states[47].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[48].cn0, 194)
        << "incorrect value for last_msg.msg.tracking_state.states[48].cn0, "
           "expected 194, is "
        << (int64_t)last_msg.msg.tracking_state.states[48].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[48].fcn, 240)
        << "incorrect value for last_msg.msg.tracking_state.states[48].fcn, "
           "expected 240, is "
        << (int64_t)last_msg.msg.tracking_state.states[48].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[48].sid.code, 77)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[48].sid.code, expected 77, is "
        << (int64_t)last_msg.msg.tracking_state.states[48].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[48].sid.sat, 128)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[48].sid.sat, expected 128, is "
        << (int64_t)last_msg.msg.tracking_state.states[48].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[49].cn0, 58)
        << "incorrect value for last_msg.msg.tracking_state.states[49].cn0, "
           "expected 58, is "
        << (int64_t)last_msg.msg.tracking_state.states[49].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[49].fcn, 41)
        << "incorrect value for last_msg.msg.tracking_state.states[49].fcn, "
           "expected 41, is "
        << (int64_t)last_msg.msg.tracking_state.states[49].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[49].sid.code, 194)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[49].sid.code, expected 194, is "
        << (int64_t)last_msg.msg.tracking_state.states[49].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[49].sid.sat, 134)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[49].sid.sat, expected 134, is "
        << (int64_t)last_msg.msg.tracking_state.states[49].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[50].cn0, 55)
        << "incorrect value for last_msg.msg.tracking_state.states[50].cn0, "
           "expected 55, is "
        << (int64_t)last_msg.msg.tracking_state.states[50].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[50].fcn, 129)
        << "incorrect value for last_msg.msg.tracking_state.states[50].fcn, "
           "expected 129, is "
        << (int64_t)last_msg.msg.tracking_state.states[50].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[50].sid.code, 53)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[50].sid.code, expected 53, is "
        << (int64_t)last_msg.msg.tracking_state.states[50].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[50].sid.sat, 18)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[50].sid.sat, expected 18, is "
        << (int64_t)last_msg.msg.tracking_state.states[50].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[51].cn0, 92)
        << "incorrect value for last_msg.msg.tracking_state.states[51].cn0, "
           "expected 92, is "
        << (int64_t)last_msg.msg.tracking_state.states[51].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[51].fcn, 134)
        << "incorrect value for last_msg.msg.tracking_state.states[51].fcn, "
           "expected 134, is "
        << (int64_t)last_msg.msg.tracking_state.states[51].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[51].sid.code, 72)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[51].sid.code, expected 72, is "
        << (int64_t)last_msg.msg.tracking_state.states[51].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[51].sid.sat, 91)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[51].sid.sat, expected 91, is "
        << (int64_t)last_msg.msg.tracking_state.states[51].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[52].cn0, 56)
        << "incorrect value for last_msg.msg.tracking_state.states[52].cn0, "
           "expected 56, is "
        << (int64_t)last_msg.msg.tracking_state.states[52].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[52].fcn, 157)
        << "incorrect value for last_msg.msg.tracking_state.states[52].fcn, "
           "expected 157, is "
        << (int64_t)last_msg.msg.tracking_state.states[52].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[52].sid.code, 224)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[52].sid.code, expected 224, is "
        << (int64_t)last_msg.msg.tracking_state.states[52].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[52].sid.sat, 33)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[52].sid.sat, expected 33, is "
        << (int64_t)last_msg.msg.tracking_state.states[52].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[53].cn0, 174)
        << "incorrect value for last_msg.msg.tracking_state.states[53].cn0, "
           "expected 174, is "
        << (int64_t)last_msg.msg.tracking_state.states[53].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[53].fcn, 224)
        << "incorrect value for last_msg.msg.tracking_state.states[53].fcn, "
           "expected 224, is "
        << (int64_t)last_msg.msg.tracking_state.states[53].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[53].sid.code, 54)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[53].sid.code, expected 54, is "
        << (int64_t)last_msg.msg.tracking_state.states[53].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[53].sid.sat, 186)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[53].sid.sat, expected 186, is "
        << (int64_t)last_msg.msg.tracking_state.states[53].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[54].cn0, 190)
        << "incorrect value for last_msg.msg.tracking_state.states[54].cn0, "
           "expected 190, is "
        << (int64_t)last_msg.msg.tracking_state.states[54].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[54].fcn, 148)
        << "incorrect value for last_msg.msg.tracking_state.states[54].fcn, "
           "expected 148, is "
        << (int64_t)last_msg.msg.tracking_state.states[54].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[54].sid.code, 84)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[54].sid.code, expected 84, is "
        << (int64_t)last_msg.msg.tracking_state.states[54].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[54].sid.sat, 82)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[54].sid.sat, expected 82, is "
        << (int64_t)last_msg.msg.tracking_state.states[54].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[55].cn0, 67)
        << "incorrect value for last_msg.msg.tracking_state.states[55].cn0, "
           "expected 67, is "
        << (int64_t)last_msg.msg.tracking_state.states[55].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[55].fcn, 62)
        << "incorrect value for last_msg.msg.tracking_state.states[55].fcn, "
           "expected 62, is "
        << (int64_t)last_msg.msg.tracking_state.states[55].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[55].sid.code, 54)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[55].sid.code, expected 54, is "
        << (int64_t)last_msg.msg.tracking_state.states[55].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[55].sid.sat, 236)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[55].sid.sat, expected 236, is "
        << (int64_t)last_msg.msg.tracking_state.states[55].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[56].cn0, 254)
        << "incorrect value for last_msg.msg.tracking_state.states[56].cn0, "
           "expected 254, is "
        << (int64_t)last_msg.msg.tracking_state.states[56].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[56].fcn, 57)
        << "incorrect value for last_msg.msg.tracking_state.states[56].fcn, "
           "expected 57, is "
        << (int64_t)last_msg.msg.tracking_state.states[56].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[56].sid.code, 215)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[56].sid.code, expected 215, is "
        << (int64_t)last_msg.msg.tracking_state.states[56].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[56].sid.sat, 52)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[56].sid.sat, expected 52, is "
        << (int64_t)last_msg.msg.tracking_state.states[56].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[57].cn0, 174)
        << "incorrect value for last_msg.msg.tracking_state.states[57].cn0, "
           "expected 174, is "
        << (int64_t)last_msg.msg.tracking_state.states[57].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[57].fcn, 36)
        << "incorrect value for last_msg.msg.tracking_state.states[57].fcn, "
           "expected 36, is "
        << (int64_t)last_msg.msg.tracking_state.states[57].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[57].sid.code, 133)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[57].sid.code, expected 133, is "
        << (int64_t)last_msg.msg.tracking_state.states[57].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[57].sid.sat, 16)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[57].sid.sat, expected 16, is "
        << (int64_t)last_msg.msg.tracking_state.states[57].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[58].cn0, 17)
        << "incorrect value for last_msg.msg.tracking_state.states[58].cn0, "
           "expected 17, is "
        << (int64_t)last_msg.msg.tracking_state.states[58].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[58].fcn, 145)
        << "incorrect value for last_msg.msg.tracking_state.states[58].fcn, "
           "expected 145, is "
        << (int64_t)last_msg.msg.tracking_state.states[58].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[58].sid.code, 172)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[58].sid.code, expected 172, is "
        << (int64_t)last_msg.msg.tracking_state.states[58].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[58].sid.sat, 219)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[58].sid.sat, expected 219, is "
        << (int64_t)last_msg.msg.tracking_state.states[58].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[59].cn0, 97)
        << "incorrect value for last_msg.msg.tracking_state.states[59].cn0, "
           "expected 97, is "
        << (int64_t)last_msg.msg.tracking_state.states[59].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[59].fcn, 111)
        << "incorrect value for last_msg.msg.tracking_state.states[59].fcn, "
           "expected 111, is "
        << (int64_t)last_msg.msg.tracking_state.states[59].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[59].sid.code, 179)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[59].sid.code, expected 179, is "
        << (int64_t)last_msg.msg.tracking_state.states[59].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[59].sid.sat, 192)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[59].sid.sat, expected 192, is "
        << (int64_t)last_msg.msg.tracking_state.states[59].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[60].cn0, 134)
        << "incorrect value for last_msg.msg.tracking_state.states[60].cn0, "
           "expected 134, is "
        << (int64_t)last_msg.msg.tracking_state.states[60].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[60].fcn, 208)
        << "incorrect value for last_msg.msg.tracking_state.states[60].fcn, "
           "expected 208, is "
        << (int64_t)last_msg.msg.tracking_state.states[60].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[60].sid.code, 56)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[60].sid.code, expected 56, is "
        << (int64_t)last_msg.msg.tracking_state.states[60].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[60].sid.sat, 207)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[60].sid.sat, expected 207, is "
        << (int64_t)last_msg.msg.tracking_state.states[60].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[61].cn0, 226)
        << "incorrect value for last_msg.msg.tracking_state.states[61].cn0, "
           "expected 226, is "
        << (int64_t)last_msg.msg.tracking_state.states[61].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[61].fcn, 43)
        << "incorrect value for last_msg.msg.tracking_state.states[61].fcn, "
           "expected 43, is "
        << (int64_t)last_msg.msg.tracking_state.states[61].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[61].sid.code, 17)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[61].sid.code, expected 17, is "
        << (int64_t)last_msg.msg.tracking_state.states[61].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[61].sid.sat, 180)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[61].sid.sat, expected 180, is "
        << (int64_t)last_msg.msg.tracking_state.states[61].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state.states[62].cn0, 113)
        << "incorrect value for last_msg.msg.tracking_state.states[62].cn0, "
           "expected 113, is "
        << (int64_t)last_msg.msg.tracking_state.states[62].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state.states[62].fcn, 140)
        << "incorrect value for last_msg.msg.tracking_state.states[62].fcn, "
           "expected 140, is "
        << (int64_t)last_msg.msg.tracking_state.states[62].fcn;

    EXPECT_EQ(last_msg.msg.tracking_state.states[62].sid.code, 182)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[62].sid.code, expected 182, is "
        << (int64_t)last_msg.msg.tracking_state.states[62].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state.states[62].sid.sat, 255)
        << "incorrect value for "
           "last_msg.msg.tracking_state.states[62].sid.sat, expected 255, is "
        << (int64_t)last_msg.msg.tracking_state.states[62].sid.sat;
  }
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
        85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   197, 253, 28,
        66,  1,   203, 0,   0,   0,   231, 99,  16, 66,  1,   208, 0,   0,
        0,   212, 129, 22,  66,  1,   212, 0,   0,  0,   58,  21,  28,  66,
        1,   217, 0,   0,   0,   178, 33,  40,  66, 1,   218, 0,   0,   0,
        235, 189, 21,  66,  1,   220, 0,   0,   0,  29,  177, 25,  66,  1,
        222, 0,   0,   0,   43,  169, 27,  66,  1,  225, 0,   0,   0,   137,
        125, 42,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
        0,   0,   0,   0,   0,   128, 191, 222, 97,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_b.n_states = 11;

    test_msg.tracking_state_dep_b.states[0].cn0 = 39.24782180786133;

    test_msg.tracking_state_dep_b.states[0].sid.code = 0;

    test_msg.tracking_state_dep_b.states[0].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[0].sid.sat = 202;

    test_msg.tracking_state_dep_b.states[0].state = 1;

    test_msg.tracking_state_dep_b.states[1].cn0 = 36.09756088256836;

    test_msg.tracking_state_dep_b.states[1].sid.code = 0;

    test_msg.tracking_state_dep_b.states[1].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[1].sid.sat = 203;

    test_msg.tracking_state_dep_b.states[1].state = 1;

    test_msg.tracking_state_dep_b.states[2].cn0 = 37.62678527832031;

    test_msg.tracking_state_dep_b.states[2].sid.code = 0;

    test_msg.tracking_state_dep_b.states[2].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[2].sid.sat = 208;

    test_msg.tracking_state_dep_b.states[2].state = 1;

    test_msg.tracking_state_dep_b.states[3].cn0 = 39.020729064941406;

    test_msg.tracking_state_dep_b.states[3].sid.code = 0;

    test_msg.tracking_state_dep_b.states[3].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[3].sid.sat = 212;

    test_msg.tracking_state_dep_b.states[3].state = 1;

    test_msg.tracking_state_dep_b.states[4].cn0 = 42.03290557861328;

    test_msg.tracking_state_dep_b.states[4].sid.code = 0;

    test_msg.tracking_state_dep_b.states[4].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[4].sid.sat = 217;

    test_msg.tracking_state_dep_b.states[4].state = 1;

    test_msg.tracking_state_dep_b.states[5].cn0 = 37.43546676635742;

    test_msg.tracking_state_dep_b.states[5].sid.code = 0;

    test_msg.tracking_state_dep_b.states[5].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[5].sid.sat = 218;

    test_msg.tracking_state_dep_b.states[5].state = 1;

    test_msg.tracking_state_dep_b.states[6].cn0 = 38.4229621887207;

    test_msg.tracking_state_dep_b.states[6].sid.code = 0;

    test_msg.tracking_state_dep_b.states[6].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[6].sid.sat = 220;

    test_msg.tracking_state_dep_b.states[6].state = 1;

    test_msg.tracking_state_dep_b.states[7].cn0 = 38.91520309448242;

    test_msg.tracking_state_dep_b.states[7].sid.code = 0;

    test_msg.tracking_state_dep_b.states[7].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[7].sid.sat = 222;

    test_msg.tracking_state_dep_b.states[7].state = 1;

    test_msg.tracking_state_dep_b.states[8].cn0 = 42.62259292602539;

    test_msg.tracking_state_dep_b.states[8].sid.code = 0;

    test_msg.tracking_state_dep_b.states[8].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[8].sid.sat = 225;

    test_msg.tracking_state_dep_b.states[8].state = 1;

    test_msg.tracking_state_dep_b.states[9].cn0 = -1.0;

    test_msg.tracking_state_dep_b.states[9].sid.code = 0;

    test_msg.tracking_state_dep_b.states[9].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[9].sid.sat = 0;

    test_msg.tracking_state_dep_b.states[9].state = 0;

    test_msg.tracking_state_dep_b.states[10].cn0 = -1.0;

    test_msg.tracking_state_dep_b.states[10].sid.code = 0;

    test_msg.tracking_state_dep_b.states[10].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[10].sid.sat = 0;

    test_msg.tracking_state_dep_b.states[10].state = 0;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepB, 55286, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgTrackingStateDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.n_states, 11)
        << "incorrect value for last_msg.msg.tracking_state_dep_b.n_states, "
           "expected 11, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.n_states;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[0].cn0 * 100 -
               39.2478218079 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].cn0, expected "
           "39.2478218079, is "
        << last_msg.msg.tracking_state_dep_b.states[0].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.sat, 202)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.sat, expected 202, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[1].cn0 * 100 -
               36.0975608826 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].cn0, expected "
           "36.0975608826, is "
        << last_msg.msg.tracking_state_dep_b.states[1].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.sat, 203)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.sat, expected 203, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[2].cn0 * 100 -
               37.6267852783 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].cn0, expected "
           "37.6267852783, is "
        << last_msg.msg.tracking_state_dep_b.states[2].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.sat, 208)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.sat, expected 208, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[3].cn0 * 100 -
               39.0207290649 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].cn0, expected "
           "39.0207290649, is "
        << last_msg.msg.tracking_state_dep_b.states[3].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.sat, 212)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.sat, expected 212, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[4].cn0 * 100 -
               42.0329055786 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].cn0, expected "
           "42.0329055786, is "
        << last_msg.msg.tracking_state_dep_b.states[4].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.sat, 217)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.sat, expected 217, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[5].cn0 * 100 -
               37.4354667664 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].cn0, expected "
           "37.4354667664, is "
        << last_msg.msg.tracking_state_dep_b.states[5].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.sat, 218)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.sat, expected 218, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[6].cn0 * 100 -
               38.4229621887 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].cn0, expected "
           "38.4229621887, is "
        << last_msg.msg.tracking_state_dep_b.states[6].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.sat, 220)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.sat, expected 220, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[7].cn0 * 100 -
               38.9152030945 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].cn0, expected "
           "38.9152030945, is "
        << last_msg.msg.tracking_state_dep_b.states[7].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.sat, 222)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.sat, expected 222, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[8].cn0 * 100 -
               42.622592926 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].cn0, expected "
           "42.622592926, is "
        << last_msg.msg.tracking_state_dep_b.states[8].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.sat, 225)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.sat, expected 225, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].state;

    EXPECT_LE(
        (last_msg.msg.tracking_state_dep_b.states[9].cn0 * 100 - -1.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].cn0, expected -1.0, is "
        << last_msg.msg.tracking_state_dep_b.states[9].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].state, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].state, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].state;

    EXPECT_LE(
        (last_msg.msg.tracking_state_dep_b.states[10].cn0 * 100 - -1.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].cn0, expected -1.0, "
           "is "
        << last_msg.msg.tracking_state_dep_b.states[10].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].state, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].state, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].state;
  }
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
        85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   250, 249, 27,
        66,  1,   203, 0,   0,   0,   40,  143, 11, 66,  1,   208, 0,   0,
        0,   190, 200, 21,  66,  1,   212, 0,   0,  0,   251, 233, 26,  66,
        1,   217, 0,   0,   0,   209, 238, 39,  66, 1,   218, 0,   0,   0,
        162, 219, 21,  66,  1,   220, 0,   0,   0,  162, 197, 25,  66,  1,
        222, 0,   0,   0,   14,  35,  28,  66,  1,  225, 0,   0,   0,   9,
        153, 43,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
        0,   0,   0,   0,   0,   128, 191, 20,  31,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_b.n_states = 11;

    test_msg.tracking_state_dep_b.states[0].cn0 = 38.994117736816406;

    test_msg.tracking_state_dep_b.states[0].sid.code = 0;

    test_msg.tracking_state_dep_b.states[0].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[0].sid.sat = 202;

    test_msg.tracking_state_dep_b.states[0].state = 1;

    test_msg.tracking_state_dep_b.states[1].cn0 = 34.889801025390625;

    test_msg.tracking_state_dep_b.states[1].sid.code = 0;

    test_msg.tracking_state_dep_b.states[1].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[1].sid.sat = 203;

    test_msg.tracking_state_dep_b.states[1].state = 1;

    test_msg.tracking_state_dep_b.states[2].cn0 = 37.44603729248047;

    test_msg.tracking_state_dep_b.states[2].sid.code = 0;

    test_msg.tracking_state_dep_b.states[2].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[2].sid.sat = 208;

    test_msg.tracking_state_dep_b.states[2].state = 1;

    test_msg.tracking_state_dep_b.states[3].cn0 = 38.72849655151367;

    test_msg.tracking_state_dep_b.states[3].sid.code = 0;

    test_msg.tracking_state_dep_b.states[3].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[3].sid.sat = 212;

    test_msg.tracking_state_dep_b.states[3].state = 1;

    test_msg.tracking_state_dep_b.states[4].cn0 = 41.983219146728516;

    test_msg.tracking_state_dep_b.states[4].sid.code = 0;

    test_msg.tracking_state_dep_b.states[4].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[4].sid.sat = 217;

    test_msg.tracking_state_dep_b.states[4].state = 1;

    test_msg.tracking_state_dep_b.states[5].cn0 = 37.46448516845703;

    test_msg.tracking_state_dep_b.states[5].sid.code = 0;

    test_msg.tracking_state_dep_b.states[5].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[5].sid.sat = 218;

    test_msg.tracking_state_dep_b.states[5].state = 1;

    test_msg.tracking_state_dep_b.states[6].cn0 = 38.44300079345703;

    test_msg.tracking_state_dep_b.states[6].sid.code = 0;

    test_msg.tracking_state_dep_b.states[6].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[6].sid.sat = 220;

    test_msg.tracking_state_dep_b.states[6].state = 1;

    test_msg.tracking_state_dep_b.states[7].cn0 = 39.03423309326172;

    test_msg.tracking_state_dep_b.states[7].sid.code = 0;

    test_msg.tracking_state_dep_b.states[7].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[7].sid.sat = 222;

    test_msg.tracking_state_dep_b.states[7].state = 1;

    test_msg.tracking_state_dep_b.states[8].cn0 = 42.89944839477539;

    test_msg.tracking_state_dep_b.states[8].sid.code = 0;

    test_msg.tracking_state_dep_b.states[8].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[8].sid.sat = 225;

    test_msg.tracking_state_dep_b.states[8].state = 1;

    test_msg.tracking_state_dep_b.states[9].cn0 = -1.0;

    test_msg.tracking_state_dep_b.states[9].sid.code = 0;

    test_msg.tracking_state_dep_b.states[9].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[9].sid.sat = 0;

    test_msg.tracking_state_dep_b.states[9].state = 0;

    test_msg.tracking_state_dep_b.states[10].cn0 = -1.0;

    test_msg.tracking_state_dep_b.states[10].sid.code = 0;

    test_msg.tracking_state_dep_b.states[10].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[10].sid.sat = 0;

    test_msg.tracking_state_dep_b.states[10].state = 0;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepB, 55286, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgTrackingStateDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.n_states, 11)
        << "incorrect value for last_msg.msg.tracking_state_dep_b.n_states, "
           "expected 11, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.n_states;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[0].cn0 * 100 -
               38.9941177368 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].cn0, expected "
           "38.9941177368, is "
        << last_msg.msg.tracking_state_dep_b.states[0].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.sat, 202)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.sat, expected 202, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[1].cn0 * 100 -
               34.8898010254 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].cn0, expected "
           "34.8898010254, is "
        << last_msg.msg.tracking_state_dep_b.states[1].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.sat, 203)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.sat, expected 203, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[2].cn0 * 100 -
               37.4460372925 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].cn0, expected "
           "37.4460372925, is "
        << last_msg.msg.tracking_state_dep_b.states[2].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.sat, 208)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.sat, expected 208, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[3].cn0 * 100 -
               38.7284965515 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].cn0, expected "
           "38.7284965515, is "
        << last_msg.msg.tracking_state_dep_b.states[3].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.sat, 212)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.sat, expected 212, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[4].cn0 * 100 -
               41.9832191467 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].cn0, expected "
           "41.9832191467, is "
        << last_msg.msg.tracking_state_dep_b.states[4].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.sat, 217)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.sat, expected 217, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[5].cn0 * 100 -
               37.4644851685 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].cn0, expected "
           "37.4644851685, is "
        << last_msg.msg.tracking_state_dep_b.states[5].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.sat, 218)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.sat, expected 218, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[6].cn0 * 100 -
               38.4430007935 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].cn0, expected "
           "38.4430007935, is "
        << last_msg.msg.tracking_state_dep_b.states[6].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.sat, 220)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.sat, expected 220, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[7].cn0 * 100 -
               39.0342330933 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].cn0, expected "
           "39.0342330933, is "
        << last_msg.msg.tracking_state_dep_b.states[7].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.sat, 222)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.sat, expected 222, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[8].cn0 * 100 -
               42.8994483948 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].cn0, expected "
           "42.8994483948, is "
        << last_msg.msg.tracking_state_dep_b.states[8].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.sat, 225)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.sat, expected 225, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].state;

    EXPECT_LE(
        (last_msg.msg.tracking_state_dep_b.states[9].cn0 * 100 - -1.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].cn0, expected -1.0, is "
        << last_msg.msg.tracking_state_dep_b.states[9].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].state, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].state, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].state;

    EXPECT_LE(
        (last_msg.msg.tracking_state_dep_b.states[10].cn0 * 100 - -1.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].cn0, expected -1.0, "
           "is "
        << last_msg.msg.tracking_state_dep_b.states[10].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].state, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].state, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].state;
  }
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
        85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   123, 209, 27,
        66,  1,   203, 0,   0,   0,   214, 64,  15, 66,  1,   208, 0,   0,
        0,   56,  55,  22,  66,  1,   212, 0,   0,  0,   91,  142, 27,  66,
        1,   217, 0,   0,   0,   253, 154, 41,  66, 1,   218, 0,   0,   0,
        128, 142, 22,  66,  1,   220, 0,   0,   0,  17,  174, 23,  66,  1,
        222, 0,   0,   0,   155, 2,   29,  66,  1,  225, 0,   0,   0,   162,
        100, 42,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
        0,   0,   0,   0,   0,   128, 191, 233, 71,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_b.n_states = 11;

    test_msg.tracking_state_dep_b.states[0].cn0 = 38.95457077026367;

    test_msg.tracking_state_dep_b.states[0].sid.code = 0;

    test_msg.tracking_state_dep_b.states[0].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[0].sid.sat = 202;

    test_msg.tracking_state_dep_b.states[0].state = 1;

    test_msg.tracking_state_dep_b.states[1].cn0 = 35.813316345214844;

    test_msg.tracking_state_dep_b.states[1].sid.code = 0;

    test_msg.tracking_state_dep_b.states[1].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[1].sid.sat = 203;

    test_msg.tracking_state_dep_b.states[1].state = 1;

    test_msg.tracking_state_dep_b.states[2].cn0 = 37.553924560546875;

    test_msg.tracking_state_dep_b.states[2].sid.code = 0;

    test_msg.tracking_state_dep_b.states[2].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[2].sid.sat = 208;

    test_msg.tracking_state_dep_b.states[2].state = 1;

    test_msg.tracking_state_dep_b.states[3].cn0 = 38.88901901245117;

    test_msg.tracking_state_dep_b.states[3].sid.code = 0;

    test_msg.tracking_state_dep_b.states[3].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[3].sid.sat = 212;

    test_msg.tracking_state_dep_b.states[3].state = 1;

    test_msg.tracking_state_dep_b.states[4].cn0 = 42.4013557434082;

    test_msg.tracking_state_dep_b.states[4].sid.code = 0;

    test_msg.tracking_state_dep_b.states[4].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[4].sid.sat = 217;

    test_msg.tracking_state_dep_b.states[4].state = 1;

    test_msg.tracking_state_dep_b.states[5].cn0 = 37.63916015625;

    test_msg.tracking_state_dep_b.states[5].sid.code = 0;

    test_msg.tracking_state_dep_b.states[5].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[5].sid.sat = 218;

    test_msg.tracking_state_dep_b.states[5].state = 1;

    test_msg.tracking_state_dep_b.states[6].cn0 = 37.919986724853516;

    test_msg.tracking_state_dep_b.states[6].sid.code = 0;

    test_msg.tracking_state_dep_b.states[6].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[6].sid.sat = 220;

    test_msg.tracking_state_dep_b.states[6].state = 1;

    test_msg.tracking_state_dep_b.states[7].cn0 = 39.25254440307617;

    test_msg.tracking_state_dep_b.states[7].sid.code = 0;

    test_msg.tracking_state_dep_b.states[7].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[7].sid.sat = 222;

    test_msg.tracking_state_dep_b.states[7].state = 1;

    test_msg.tracking_state_dep_b.states[8].cn0 = 42.59827423095703;

    test_msg.tracking_state_dep_b.states[8].sid.code = 0;

    test_msg.tracking_state_dep_b.states[8].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[8].sid.sat = 225;

    test_msg.tracking_state_dep_b.states[8].state = 1;

    test_msg.tracking_state_dep_b.states[9].cn0 = -1.0;

    test_msg.tracking_state_dep_b.states[9].sid.code = 0;

    test_msg.tracking_state_dep_b.states[9].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[9].sid.sat = 0;

    test_msg.tracking_state_dep_b.states[9].state = 0;

    test_msg.tracking_state_dep_b.states[10].cn0 = -1.0;

    test_msg.tracking_state_dep_b.states[10].sid.code = 0;

    test_msg.tracking_state_dep_b.states[10].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[10].sid.sat = 0;

    test_msg.tracking_state_dep_b.states[10].state = 0;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepB, 55286, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgTrackingStateDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.n_states, 11)
        << "incorrect value for last_msg.msg.tracking_state_dep_b.n_states, "
           "expected 11, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.n_states;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[0].cn0 * 100 -
               38.9545707703 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].cn0, expected "
           "38.9545707703, is "
        << last_msg.msg.tracking_state_dep_b.states[0].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.sat, 202)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.sat, expected 202, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[1].cn0 * 100 -
               35.8133163452 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].cn0, expected "
           "35.8133163452, is "
        << last_msg.msg.tracking_state_dep_b.states[1].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.sat, 203)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.sat, expected 203, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[2].cn0 * 100 -
               37.5539245605 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].cn0, expected "
           "37.5539245605, is "
        << last_msg.msg.tracking_state_dep_b.states[2].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.sat, 208)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.sat, expected 208, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[3].cn0 * 100 -
               38.8890190125 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].cn0, expected "
           "38.8890190125, is "
        << last_msg.msg.tracking_state_dep_b.states[3].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.sat, 212)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.sat, expected 212, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[4].cn0 * 100 -
               42.4013557434 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].cn0, expected "
           "42.4013557434, is "
        << last_msg.msg.tracking_state_dep_b.states[4].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.sat, 217)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.sat, expected 217, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[5].cn0 * 100 -
               37.6391601562 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].cn0, expected "
           "37.6391601562, is "
        << last_msg.msg.tracking_state_dep_b.states[5].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.sat, 218)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.sat, expected 218, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[6].cn0 * 100 -
               37.9199867249 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].cn0, expected "
           "37.9199867249, is "
        << last_msg.msg.tracking_state_dep_b.states[6].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.sat, 220)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.sat, expected 220, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[7].cn0 * 100 -
               39.2525444031 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].cn0, expected "
           "39.2525444031, is "
        << last_msg.msg.tracking_state_dep_b.states[7].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.sat, 222)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.sat, expected 222, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[8].cn0 * 100 -
               42.598274231 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].cn0, expected "
           "42.598274231, is "
        << last_msg.msg.tracking_state_dep_b.states[8].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.sat, 225)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.sat, expected 225, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].state;

    EXPECT_LE(
        (last_msg.msg.tracking_state_dep_b.states[9].cn0 * 100 - -1.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].cn0, expected -1.0, is "
        << last_msg.msg.tracking_state_dep_b.states[9].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].state, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].state, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].state;

    EXPECT_LE(
        (last_msg.msg.tracking_state_dep_b.states[10].cn0 * 100 - -1.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].cn0, expected -1.0, "
           "is "
        << last_msg.msg.tracking_state_dep_b.states[10].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].state, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].state, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].state;
  }
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
        85,  19,  0,   246, 215, 99,  1,   202, 0,   0,   0,   120, 122, 29,
        66,  1,   203, 0,   0,   0,   66,  22,  18,  66,  1,   208, 0,   0,
        0,   153, 163, 24,  66,  1,   212, 0,   0,   0,   178, 204, 28,  66,
        1,   217, 0,   0,   0,   220, 59,  38,  66,  1,   218, 0,   0,   0,
        161, 27,  20,  66,  1,   220, 0,   0,   0,   125, 107, 24,  66,  1,
        222, 0,   0,   0,   242, 46,  28,  66,  1,   225, 0,   0,   0,   231,
        130, 41,  66,  0,   0,   0,   0,   0,   0,   0,   128, 191, 0,   0,
        0,   0,   0,   0,   0,   128, 191, 73,  193,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_b.n_states = 11;

    test_msg.tracking_state_dep_b.states[0].cn0 = 39.369598388671875;

    test_msg.tracking_state_dep_b.states[0].sid.code = 0;

    test_msg.tracking_state_dep_b.states[0].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[0].sid.sat = 202;

    test_msg.tracking_state_dep_b.states[0].state = 1;

    test_msg.tracking_state_dep_b.states[1].cn0 = 36.52173614501953;

    test_msg.tracking_state_dep_b.states[1].sid.code = 0;

    test_msg.tracking_state_dep_b.states[1].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[1].sid.sat = 203;

    test_msg.tracking_state_dep_b.states[1].state = 1;

    test_msg.tracking_state_dep_b.states[2].cn0 = 38.15976333618164;

    test_msg.tracking_state_dep_b.states[2].sid.code = 0;

    test_msg.tracking_state_dep_b.states[2].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[2].sid.sat = 208;

    test_msg.tracking_state_dep_b.states[2].state = 1;

    test_msg.tracking_state_dep_b.states[3].cn0 = 39.19989776611328;

    test_msg.tracking_state_dep_b.states[3].sid.code = 0;

    test_msg.tracking_state_dep_b.states[3].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[3].sid.sat = 212;

    test_msg.tracking_state_dep_b.states[3].state = 1;

    test_msg.tracking_state_dep_b.states[4].cn0 = 41.55845642089844;

    test_msg.tracking_state_dep_b.states[4].sid.code = 0;

    test_msg.tracking_state_dep_b.states[4].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[4].sid.sat = 217;

    test_msg.tracking_state_dep_b.states[4].state = 1;

    test_msg.tracking_state_dep_b.states[5].cn0 = 37.026981353759766;

    test_msg.tracking_state_dep_b.states[5].sid.code = 0;

    test_msg.tracking_state_dep_b.states[5].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[5].sid.sat = 218;

    test_msg.tracking_state_dep_b.states[5].state = 1;

    test_msg.tracking_state_dep_b.states[6].cn0 = 38.1049690246582;

    test_msg.tracking_state_dep_b.states[6].sid.code = 0;

    test_msg.tracking_state_dep_b.states[6].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[6].sid.sat = 220;

    test_msg.tracking_state_dep_b.states[6].state = 1;

    test_msg.tracking_state_dep_b.states[7].cn0 = 39.04584503173828;

    test_msg.tracking_state_dep_b.states[7].sid.code = 0;

    test_msg.tracking_state_dep_b.states[7].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[7].sid.sat = 222;

    test_msg.tracking_state_dep_b.states[7].state = 1;

    test_msg.tracking_state_dep_b.states[8].cn0 = 42.37783432006836;

    test_msg.tracking_state_dep_b.states[8].sid.code = 0;

    test_msg.tracking_state_dep_b.states[8].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[8].sid.sat = 225;

    test_msg.tracking_state_dep_b.states[8].state = 1;

    test_msg.tracking_state_dep_b.states[9].cn0 = -1.0;

    test_msg.tracking_state_dep_b.states[9].sid.code = 0;

    test_msg.tracking_state_dep_b.states[9].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[9].sid.sat = 0;

    test_msg.tracking_state_dep_b.states[9].state = 0;

    test_msg.tracking_state_dep_b.states[10].cn0 = -1.0;

    test_msg.tracking_state_dep_b.states[10].sid.code = 0;

    test_msg.tracking_state_dep_b.states[10].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[10].sid.sat = 0;

    test_msg.tracking_state_dep_b.states[10].state = 0;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepB, 55286, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgTrackingStateDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.n_states, 11)
        << "incorrect value for last_msg.msg.tracking_state_dep_b.n_states, "
           "expected 11, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.n_states;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[0].cn0 * 100 -
               39.3695983887 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].cn0, expected "
           "39.3695983887, is "
        << last_msg.msg.tracking_state_dep_b.states[0].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.sat, 202)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.sat, expected 202, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[1].cn0 * 100 -
               36.521736145 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].cn0, expected "
           "36.521736145, is "
        << last_msg.msg.tracking_state_dep_b.states[1].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.sat, 203)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.sat, expected 203, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[2].cn0 * 100 -
               38.1597633362 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].cn0, expected "
           "38.1597633362, is "
        << last_msg.msg.tracking_state_dep_b.states[2].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.sat, 208)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.sat, expected 208, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[3].cn0 * 100 -
               39.1998977661 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].cn0, expected "
           "39.1998977661, is "
        << last_msg.msg.tracking_state_dep_b.states[3].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.sat, 212)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.sat, expected 212, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[4].cn0 * 100 -
               41.5584564209 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].cn0, expected "
           "41.5584564209, is "
        << last_msg.msg.tracking_state_dep_b.states[4].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.sat, 217)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.sat, expected 217, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[5].cn0 * 100 -
               37.0269813538 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].cn0, expected "
           "37.0269813538, is "
        << last_msg.msg.tracking_state_dep_b.states[5].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.sat, 218)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.sat, expected 218, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[6].cn0 * 100 -
               38.1049690247 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].cn0, expected "
           "38.1049690247, is "
        << last_msg.msg.tracking_state_dep_b.states[6].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.sat, 220)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.sat, expected 220, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[7].cn0 * 100 -
               39.0458450317 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].cn0, expected "
           "39.0458450317, is "
        << last_msg.msg.tracking_state_dep_b.states[7].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.sat, 222)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.sat, expected 222, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[8].cn0 * 100 -
               42.3778343201 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].cn0, expected "
           "42.3778343201, is "
        << last_msg.msg.tracking_state_dep_b.states[8].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.sat, 225)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.sat, expected 225, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].state;

    EXPECT_LE(
        (last_msg.msg.tracking_state_dep_b.states[9].cn0 * 100 - -1.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].cn0, expected -1.0, is "
        << last_msg.msg.tracking_state_dep_b.states[9].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].state, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].state, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].state;

    EXPECT_LE(
        (last_msg.msg.tracking_state_dep_b.states[10].cn0 * 100 - -1.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].cn0, expected -1.0, "
           "is "
        << last_msg.msg.tracking_state_dep_b.states[10].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].state, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].state, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].state;
  }
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
        85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   103, 208, 30,
        66,  1,   203, 0,   0,   0,   117, 24,  18, 66,  1,   208, 0,   0,
        0,   200, 173, 20,  66,  1,   212, 0,   0,  0,   137, 68,  27,  66,
        1,   217, 0,   0,   0,   243, 51,  40,  66, 1,   218, 0,   0,   0,
        225, 58,  23,  66,  1,   220, 0,   0,   0,  132, 221, 22,  66,  1,
        222, 0,   0,   0,   157, 29,  26,  66,  1,  225, 0,   0,   0,   133,
        21,  41,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
        0,   0,   0,   0,   0,   128, 191, 126, 47,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_dep_b.n_states = 11;

    test_msg.tracking_state_dep_b.states[0].cn0 = 39.70351791381836;

    test_msg.tracking_state_dep_b.states[0].sid.code = 0;

    test_msg.tracking_state_dep_b.states[0].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[0].sid.sat = 202;

    test_msg.tracking_state_dep_b.states[0].state = 1;

    test_msg.tracking_state_dep_b.states[1].cn0 = 36.52388381958008;

    test_msg.tracking_state_dep_b.states[1].sid.code = 0;

    test_msg.tracking_state_dep_b.states[1].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[1].sid.sat = 203;

    test_msg.tracking_state_dep_b.states[1].state = 1;

    test_msg.tracking_state_dep_b.states[2].cn0 = 37.169708251953125;

    test_msg.tracking_state_dep_b.states[2].sid.code = 0;

    test_msg.tracking_state_dep_b.states[2].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[2].sid.sat = 208;

    test_msg.tracking_state_dep_b.states[2].state = 1;

    test_msg.tracking_state_dep_b.states[3].cn0 = 38.81692886352539;

    test_msg.tracking_state_dep_b.states[3].sid.code = 0;

    test_msg.tracking_state_dep_b.states[3].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[3].sid.sat = 212;

    test_msg.tracking_state_dep_b.states[3].state = 1;

    test_msg.tracking_state_dep_b.states[4].cn0 = 42.05073165893555;

    test_msg.tracking_state_dep_b.states[4].sid.code = 0;

    test_msg.tracking_state_dep_b.states[4].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[4].sid.sat = 217;

    test_msg.tracking_state_dep_b.states[4].state = 1;

    test_msg.tracking_state_dep_b.states[5].cn0 = 37.807498931884766;

    test_msg.tracking_state_dep_b.states[5].sid.code = 0;

    test_msg.tracking_state_dep_b.states[5].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[5].sid.sat = 218;

    test_msg.tracking_state_dep_b.states[5].state = 1;

    test_msg.tracking_state_dep_b.states[6].cn0 = 37.71632385253906;

    test_msg.tracking_state_dep_b.states[6].sid.code = 0;

    test_msg.tracking_state_dep_b.states[6].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[6].sid.sat = 220;

    test_msg.tracking_state_dep_b.states[6].state = 1;

    test_msg.tracking_state_dep_b.states[7].cn0 = 38.5289192199707;

    test_msg.tracking_state_dep_b.states[7].sid.code = 0;

    test_msg.tracking_state_dep_b.states[7].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[7].sid.sat = 222;

    test_msg.tracking_state_dep_b.states[7].state = 1;

    test_msg.tracking_state_dep_b.states[8].cn0 = 42.27101516723633;

    test_msg.tracking_state_dep_b.states[8].sid.code = 0;

    test_msg.tracking_state_dep_b.states[8].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[8].sid.sat = 225;

    test_msg.tracking_state_dep_b.states[8].state = 1;

    test_msg.tracking_state_dep_b.states[9].cn0 = -1.0;

    test_msg.tracking_state_dep_b.states[9].sid.code = 0;

    test_msg.tracking_state_dep_b.states[9].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[9].sid.sat = 0;

    test_msg.tracking_state_dep_b.states[9].state = 0;

    test_msg.tracking_state_dep_b.states[10].cn0 = -1.0;

    test_msg.tracking_state_dep_b.states[10].sid.code = 0;

    test_msg.tracking_state_dep_b.states[10].sid.reserved = 0;

    test_msg.tracking_state_dep_b.states[10].sid.sat = 0;

    test_msg.tracking_state_dep_b.states[10].state = 0;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDepB, 55286, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgTrackingStateDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.n_states, 11)
        << "incorrect value for last_msg.msg.tracking_state_dep_b.n_states, "
           "expected 11, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.n_states;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[0].cn0 * 100 -
               39.7035179138 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].cn0, expected "
           "39.7035179138, is "
        << last_msg.msg.tracking_state_dep_b.states[0].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].sid.sat, 202)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].sid.sat, expected 202, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[0].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[0].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[0].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[1].cn0 * 100 -
               36.5238838196 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].cn0, expected "
           "36.5238838196, is "
        << last_msg.msg.tracking_state_dep_b.states[1].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].sid.sat, 203)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].sid.sat, expected 203, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[1].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[1].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[1].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[2].cn0 * 100 -
               37.169708252 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].cn0, expected "
           "37.169708252, is "
        << last_msg.msg.tracking_state_dep_b.states[2].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].sid.sat, 208)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].sid.sat, expected 208, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[2].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[2].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[2].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[3].cn0 * 100 -
               38.8169288635 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].cn0, expected "
           "38.8169288635, is "
        << last_msg.msg.tracking_state_dep_b.states[3].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].sid.sat, 212)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].sid.sat, expected 212, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[3].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[3].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[3].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[4].cn0 * 100 -
               42.0507316589 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].cn0, expected "
           "42.0507316589, is "
        << last_msg.msg.tracking_state_dep_b.states[4].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].sid.sat, 217)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].sid.sat, expected 217, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[4].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[4].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[4].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[5].cn0 * 100 -
               37.8074989319 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].cn0, expected "
           "37.8074989319, is "
        << last_msg.msg.tracking_state_dep_b.states[5].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].sid.sat, 218)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].sid.sat, expected 218, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[5].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[5].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[5].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[6].cn0 * 100 -
               37.7163238525 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].cn0, expected "
           "37.7163238525, is "
        << last_msg.msg.tracking_state_dep_b.states[6].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].sid.sat, 220)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].sid.sat, expected 220, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[6].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[6].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[6].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[7].cn0 * 100 -
               38.52891922 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].cn0, expected "
           "38.52891922, is "
        << last_msg.msg.tracking_state_dep_b.states[7].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].sid.sat, 222)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].sid.sat, expected 222, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[7].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[7].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[7].state;

    EXPECT_LE((last_msg.msg.tracking_state_dep_b.states[8].cn0 * 100 -
               42.2710151672 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].cn0, expected "
           "42.2710151672, is "
        << last_msg.msg.tracking_state_dep_b.states[8].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].sid.sat, 225)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].sid.sat, expected 225, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[8].state, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[8].state, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[8].state;

    EXPECT_LE(
        (last_msg.msg.tracking_state_dep_b.states[9].cn0 * 100 - -1.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].cn0, expected -1.0, is "
        << last_msg.msg.tracking_state_dep_b.states[9].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.reserved, expected "
           "0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].sid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].sid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[9].state, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[9].state, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[9].state;

    EXPECT_LE(
        (last_msg.msg.tracking_state_dep_b.states[10].cn0 * 100 - -1.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].cn0, expected -1.0, "
           "is "
        << last_msg.msg.tracking_state_dep_b.states[10].cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].sid.sat, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].sid.sat, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_dep_b.states[10].state, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_dep_b.states[10].state, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_dep_b.states[10].state;
  }
}

}  // namespace
