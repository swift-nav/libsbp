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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/observation.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_observation_MsgObs,
     test_auto_check_sbp_observation_MsgObs) {
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

    sbp_callback_register(&sbp_state, SbpMsgObs, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  74,  0,   129, 240, 249, 152, 202, 226, 25,  0,   0,   0,   0,
        106, 8,   32,  49,  227, 254, 62,  121, 242, 158, 6,   146, 0,   250,
        172, 182, 10,  15,  10,  0,   30,  228, 254, 62,  12,  189, 40,  5,
        59,  83,  251, 172, 178, 10,  15,  10,  1,   215, 205, 144, 72,  106,
        111, 160, 7,   243, 109, 243, 119, 158, 10,  15,  18,  0,   25,  207,
        144, 72,  223, 96,  241, 5,   12,  52,  246, 27,  125, 9,   11,  18,
        1,   34,  184, 223, 74,  150, 138, 222, 7,   53,  13,  11,  245, 114,
        9,   15,  22,  0,   113, 80,  6,   69,  162, 41,  65,  7,   70,  127,
        246, 246, 189, 9,   15,  23,  0,   247, 80,  6,   69,  213, 35,  167,
        5,   221, 152, 248, 231, 158, 9,   11,  23,  1,   8,   146, 166, 64,
        12,  122, 203, 6,   114, 51,  248, 67,  93,  3,   11,  27,  0,   221,
        172, 173, 75,  217, 47,  244, 7,   232, 225, 11,  237, 123, 5,   15,
        31,  0,   250, 174, 173, 75,  216, 163, 50,  6,   40,  70,  9,   62,
        120, 3,   11,  31,  1,   135, 16,  6,   66,  99,  218, 11,  7,   7,
        138, 242, 96,  176, 10,  15,  2,   3,   148, 130, 6,   58,  217, 88,
        54,  6,   203, 21,  252, 96,  170, 10,  15,  3,   3,   186, 108, 197,
        63,  127, 54,  211, 6,   80,  4,   241, 219, 200, 10,  15,  17,  3,
        167, 195, 8,   57,  19,  204, 22,  6,   105, 51,  254, 182, 152, 10,
        15,  18,  3,   237, 248,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs.header.n_obs = 32;

    test_msg.obs.header.t.ns_residual = 0;

    test_msg.obs.header.t.tow = 434293400;

    test_msg.obs.header.t.wn = 2154;

    test_msg.obs.n_obs = 14;

    test_msg.obs.obs[0].D.f = 172;

    test_msg.obs.obs[0].D.i = -1536;

    test_msg.obs.obs[0].L.f = 146;

    test_msg.obs.obs[0].L.i = 111080057;

    test_msg.obs.obs[0].P = 1056891697;

    test_msg.obs.obs[0].cn0 = 182;

    test_msg.obs.obs[0].flags = 15;

    test_msg.obs.obs[0].lock = 10;

    test_msg.obs.obs[0].sid.code = 0;

    test_msg.obs.obs[0].sid.sat = 10;

    test_msg.obs.obs[1].D.f = 172;

    test_msg.obs.obs[1].D.i = -1197;

    test_msg.obs.obs[1].L.f = 59;

    test_msg.obs.obs[1].L.i = 86555916;

    test_msg.obs.obs[1].P = 1056891934;

    test_msg.obs.obs[1].cn0 = 178;

    test_msg.obs.obs[1].flags = 15;

    test_msg.obs.obs[1].lock = 10;

    test_msg.obs.obs[1].sid.code = 1;

    test_msg.obs.obs[1].sid.sat = 10;

    test_msg.obs.obs[2].D.f = 119;

    test_msg.obs.obs[2].D.i = -3219;

    test_msg.obs.obs[2].L.f = 243;

    test_msg.obs.obs[2].L.i = 127954794;

    test_msg.obs.obs[2].P = 1217449431;

    test_msg.obs.obs[2].cn0 = 158;

    test_msg.obs.obs[2].flags = 15;

    test_msg.obs.obs[2].lock = 10;

    test_msg.obs.obs[2].sid.code = 0;

    test_msg.obs.obs[2].sid.sat = 18;

    test_msg.obs.obs[3].D.f = 27;

    test_msg.obs.obs[3].D.i = -2508;

    test_msg.obs.obs[3].L.f = 12;

    test_msg.obs.obs[3].L.i = 99705055;

    test_msg.obs.obs[3].P = 1217449753;

    test_msg.obs.obs[3].cn0 = 125;

    test_msg.obs.obs[3].flags = 11;

    test_msg.obs.obs[3].lock = 9;

    test_msg.obs.obs[3].sid.code = 1;

    test_msg.obs.obs[3].sid.sat = 18;

    test_msg.obs.obs[4].D.f = 245;

    test_msg.obs.obs[4].D.i = 2829;

    test_msg.obs.obs[4].L.f = 53;

    test_msg.obs.obs[4].L.i = 132024982;

    test_msg.obs.obs[4].P = 1256175650;

    test_msg.obs.obs[4].cn0 = 114;

    test_msg.obs.obs[4].flags = 15;

    test_msg.obs.obs[4].lock = 9;

    test_msg.obs.obs[4].sid.code = 0;

    test_msg.obs.obs[4].sid.sat = 22;

    test_msg.obs.obs[5].D.f = 246;

    test_msg.obs.obs[5].D.i = -2433;

    test_msg.obs.obs[5].L.f = 70;

    test_msg.obs.obs[5].L.i = 121711010;

    test_msg.obs.obs[5].P = 1158041713;

    test_msg.obs.obs[5].cn0 = 189;

    test_msg.obs.obs[5].flags = 15;

    test_msg.obs.obs[5].lock = 9;

    test_msg.obs.obs[5].sid.code = 0;

    test_msg.obs.obs[5].sid.sat = 23;

    test_msg.obs.obs[6].D.f = 231;

    test_msg.obs.obs[6].D.i = -1896;

    test_msg.obs.obs[6].L.f = 221;

    test_msg.obs.obs[6].L.i = 94839765;

    test_msg.obs.obs[6].P = 1158041847;

    test_msg.obs.obs[6].cn0 = 158;

    test_msg.obs.obs[6].flags = 11;

    test_msg.obs.obs[6].lock = 9;

    test_msg.obs.obs[6].sid.code = 1;

    test_msg.obs.obs[6].sid.sat = 23;

    test_msg.obs.obs[7].D.f = 67;

    test_msg.obs.obs[7].D.i = -1997;

    test_msg.obs.obs[7].L.f = 114;

    test_msg.obs.obs[7].L.i = 113998348;

    test_msg.obs.obs[7].P = 1084658184;

    test_msg.obs.obs[7].cn0 = 93;

    test_msg.obs.obs[7].flags = 11;

    test_msg.obs.obs[7].lock = 3;

    test_msg.obs.obs[7].sid.code = 0;

    test_msg.obs.obs[7].sid.sat = 27;

    test_msg.obs.obs[8].D.f = 237;

    test_msg.obs.obs[8].D.i = 3041;

    test_msg.obs.obs[8].L.f = 232;

    test_msg.obs.obs[8].L.i = 133443545;

    test_msg.obs.obs[8].P = 1269673181;

    test_msg.obs.obs[8].cn0 = 123;

    test_msg.obs.obs[8].flags = 15;

    test_msg.obs.obs[8].lock = 5;

    test_msg.obs.obs[8].sid.code = 0;

    test_msg.obs.obs[8].sid.sat = 31;

    test_msg.obs.obs[9].D.f = 62;

    test_msg.obs.obs[9].D.i = 2374;

    test_msg.obs.obs[9].L.f = 40;

    test_msg.obs.obs[9].L.i = 103982040;

    test_msg.obs.obs[9].P = 1269673722;

    test_msg.obs.obs[9].cn0 = 120;

    test_msg.obs.obs[9].flags = 11;

    test_msg.obs.obs[9].lock = 3;

    test_msg.obs.obs[9].sid.code = 1;

    test_msg.obs.obs[9].sid.sat = 31;

    test_msg.obs.obs[10].D.f = 96;

    test_msg.obs.obs[10].D.i = -3446;

    test_msg.obs.obs[10].L.f = 7;

    test_msg.obs.obs[10].L.i = 118217315;

    test_msg.obs.obs[10].P = 1107693703;

    test_msg.obs.obs[10].cn0 = 176;

    test_msg.obs.obs[10].flags = 15;

    test_msg.obs.obs[10].lock = 10;

    test_msg.obs.obs[10].sid.code = 3;

    test_msg.obs.obs[10].sid.sat = 2;

    test_msg.obs.obs[11].D.f = 96;

    test_msg.obs.obs[11].D.i = -1003;

    test_msg.obs.obs[11].L.f = 203;

    test_msg.obs.obs[11].L.i = 104224985;

    test_msg.obs.obs[11].P = 973505172;

    test_msg.obs.obs[11].cn0 = 170;

    test_msg.obs.obs[11].flags = 15;

    test_msg.obs.obs[11].lock = 10;

    test_msg.obs.obs[11].sid.code = 3;

    test_msg.obs.obs[11].sid.sat = 3;

    test_msg.obs.obs[12].D.f = 219;

    test_msg.obs.obs[12].D.i = -3836;

    test_msg.obs.obs[12].L.f = 80;

    test_msg.obs.obs[12].L.i = 114505343;

    test_msg.obs.obs[12].P = 1069903034;

    test_msg.obs.obs[12].cn0 = 200;

    test_msg.obs.obs[12].flags = 15;

    test_msg.obs.obs[12].lock = 10;

    test_msg.obs.obs[12].sid.code = 3;

    test_msg.obs.obs[12].sid.sat = 17;

    test_msg.obs.obs[13].D.f = 182;

    test_msg.obs.obs[13].D.i = -461;

    test_msg.obs.obs[13].L.f = 105;

    test_msg.obs.obs[13].L.i = 102157331;

    test_msg.obs.obs[13].P = 956875687;

    test_msg.obs.obs[13].cn0 = 152;

    test_msg.obs.obs[13].flags = 15;

    test_msg.obs.obs[13].lock = 10;

    test_msg.obs.obs[13].sid.code = 3;

    test_msg.obs.obs[13].sid.sat = 18;

    sbp_message_send(&sbp_state, SbpMsgObs, 61569, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 61569)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgObs, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.obs.header.n_obs, 32)
        << "incorrect value for last_msg.msg.obs.header.n_obs, expected 32, is "
        << (int64_t)last_msg.msg.obs.header.n_obs;

    EXPECT_EQ(last_msg.msg.obs.header.t.ns_residual, 0)
        << "incorrect value for last_msg.msg.obs.header.t.ns_residual, "
           "expected 0, is "
        << (int64_t)last_msg.msg.obs.header.t.ns_residual;

    EXPECT_EQ(last_msg.msg.obs.header.t.tow, 434293400)
        << "incorrect value for last_msg.msg.obs.header.t.tow, expected "
           "434293400, is "
        << (int64_t)last_msg.msg.obs.header.t.tow;

    EXPECT_EQ(last_msg.msg.obs.header.t.wn, 2154)
        << "incorrect value for last_msg.msg.obs.header.t.wn, expected 2154, "
           "is "
        << (int64_t)last_msg.msg.obs.header.t.wn;

    EXPECT_EQ(last_msg.msg.obs.n_obs, 14)
        << "incorrect value for last_msg.msg.obs.n_obs, expected 14, is "
        << (int64_t)last_msg.msg.obs.n_obs;

    EXPECT_EQ(last_msg.msg.obs.obs[0].D.f, 172)
        << "incorrect value for last_msg.msg.obs.obs[0].D.f, expected 172, is "
        << (int64_t)last_msg.msg.obs.obs[0].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[0].D.i, -1536)
        << "incorrect value for last_msg.msg.obs.obs[0].D.i, expected -1536, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[0].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[0].L.f, 146)
        << "incorrect value for last_msg.msg.obs.obs[0].L.f, expected 146, is "
        << (int64_t)last_msg.msg.obs.obs[0].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[0].L.i, 111080057)
        << "incorrect value for last_msg.msg.obs.obs[0].L.i, expected "
           "111080057, is "
        << (int64_t)last_msg.msg.obs.obs[0].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[0].P, 1056891697)
        << "incorrect value for last_msg.msg.obs.obs[0].P, expected "
           "1056891697, is "
        << (int64_t)last_msg.msg.obs.obs[0].P;

    EXPECT_EQ(last_msg.msg.obs.obs[0].cn0, 182)
        << "incorrect value for last_msg.msg.obs.obs[0].cn0, expected 182, is "
        << (int64_t)last_msg.msg.obs.obs[0].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[0].flags, 15)
        << "incorrect value for last_msg.msg.obs.obs[0].flags, expected 15, is "
        << (int64_t)last_msg.msg.obs.obs[0].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[0].lock, 10)
        << "incorrect value for last_msg.msg.obs.obs[0].lock, expected 10, is "
        << (int64_t)last_msg.msg.obs.obs[0].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[0].sid.code, 0)
        << "incorrect value for last_msg.msg.obs.obs[0].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[0].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[0].sid.sat, 10)
        << "incorrect value for last_msg.msg.obs.obs[0].sid.sat, expected 10, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[0].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[1].D.f, 172)
        << "incorrect value for last_msg.msg.obs.obs[1].D.f, expected 172, is "
        << (int64_t)last_msg.msg.obs.obs[1].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[1].D.i, -1197)
        << "incorrect value for last_msg.msg.obs.obs[1].D.i, expected -1197, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[1].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[1].L.f, 59)
        << "incorrect value for last_msg.msg.obs.obs[1].L.f, expected 59, is "
        << (int64_t)last_msg.msg.obs.obs[1].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[1].L.i, 86555916)
        << "incorrect value for last_msg.msg.obs.obs[1].L.i, expected "
           "86555916, is "
        << (int64_t)last_msg.msg.obs.obs[1].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[1].P, 1056891934)
        << "incorrect value for last_msg.msg.obs.obs[1].P, expected "
           "1056891934, is "
        << (int64_t)last_msg.msg.obs.obs[1].P;

    EXPECT_EQ(last_msg.msg.obs.obs[1].cn0, 178)
        << "incorrect value for last_msg.msg.obs.obs[1].cn0, expected 178, is "
        << (int64_t)last_msg.msg.obs.obs[1].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[1].flags, 15)
        << "incorrect value for last_msg.msg.obs.obs[1].flags, expected 15, is "
        << (int64_t)last_msg.msg.obs.obs[1].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[1].lock, 10)
        << "incorrect value for last_msg.msg.obs.obs[1].lock, expected 10, is "
        << (int64_t)last_msg.msg.obs.obs[1].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[1].sid.code, 1)
        << "incorrect value for last_msg.msg.obs.obs[1].sid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[1].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[1].sid.sat, 10)
        << "incorrect value for last_msg.msg.obs.obs[1].sid.sat, expected 10, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[1].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[2].D.f, 119)
        << "incorrect value for last_msg.msg.obs.obs[2].D.f, expected 119, is "
        << (int64_t)last_msg.msg.obs.obs[2].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[2].D.i, -3219)
        << "incorrect value for last_msg.msg.obs.obs[2].D.i, expected -3219, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[2].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[2].L.f, 243)
        << "incorrect value for last_msg.msg.obs.obs[2].L.f, expected 243, is "
        << (int64_t)last_msg.msg.obs.obs[2].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[2].L.i, 127954794)
        << "incorrect value for last_msg.msg.obs.obs[2].L.i, expected "
           "127954794, is "
        << (int64_t)last_msg.msg.obs.obs[2].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[2].P, 1217449431)
        << "incorrect value for last_msg.msg.obs.obs[2].P, expected "
           "1217449431, is "
        << (int64_t)last_msg.msg.obs.obs[2].P;

    EXPECT_EQ(last_msg.msg.obs.obs[2].cn0, 158)
        << "incorrect value for last_msg.msg.obs.obs[2].cn0, expected 158, is "
        << (int64_t)last_msg.msg.obs.obs[2].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[2].flags, 15)
        << "incorrect value for last_msg.msg.obs.obs[2].flags, expected 15, is "
        << (int64_t)last_msg.msg.obs.obs[2].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[2].lock, 10)
        << "incorrect value for last_msg.msg.obs.obs[2].lock, expected 10, is "
        << (int64_t)last_msg.msg.obs.obs[2].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[2].sid.code, 0)
        << "incorrect value for last_msg.msg.obs.obs[2].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[2].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[2].sid.sat, 18)
        << "incorrect value for last_msg.msg.obs.obs[2].sid.sat, expected 18, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[2].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[3].D.f, 27)
        << "incorrect value for last_msg.msg.obs.obs[3].D.f, expected 27, is "
        << (int64_t)last_msg.msg.obs.obs[3].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[3].D.i, -2508)
        << "incorrect value for last_msg.msg.obs.obs[3].D.i, expected -2508, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[3].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[3].L.f, 12)
        << "incorrect value for last_msg.msg.obs.obs[3].L.f, expected 12, is "
        << (int64_t)last_msg.msg.obs.obs[3].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[3].L.i, 99705055)
        << "incorrect value for last_msg.msg.obs.obs[3].L.i, expected "
           "99705055, is "
        << (int64_t)last_msg.msg.obs.obs[3].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[3].P, 1217449753)
        << "incorrect value for last_msg.msg.obs.obs[3].P, expected "
           "1217449753, is "
        << (int64_t)last_msg.msg.obs.obs[3].P;

    EXPECT_EQ(last_msg.msg.obs.obs[3].cn0, 125)
        << "incorrect value for last_msg.msg.obs.obs[3].cn0, expected 125, is "
        << (int64_t)last_msg.msg.obs.obs[3].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[3].flags, 11)
        << "incorrect value for last_msg.msg.obs.obs[3].flags, expected 11, is "
        << (int64_t)last_msg.msg.obs.obs[3].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[3].lock, 9)
        << "incorrect value for last_msg.msg.obs.obs[3].lock, expected 9, is "
        << (int64_t)last_msg.msg.obs.obs[3].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[3].sid.code, 1)
        << "incorrect value for last_msg.msg.obs.obs[3].sid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[3].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[3].sid.sat, 18)
        << "incorrect value for last_msg.msg.obs.obs[3].sid.sat, expected 18, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[3].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[4].D.f, 245)
        << "incorrect value for last_msg.msg.obs.obs[4].D.f, expected 245, is "
        << (int64_t)last_msg.msg.obs.obs[4].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[4].D.i, 2829)
        << "incorrect value for last_msg.msg.obs.obs[4].D.i, expected 2829, is "
        << (int64_t)last_msg.msg.obs.obs[4].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[4].L.f, 53)
        << "incorrect value for last_msg.msg.obs.obs[4].L.f, expected 53, is "
        << (int64_t)last_msg.msg.obs.obs[4].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[4].L.i, 132024982)
        << "incorrect value for last_msg.msg.obs.obs[4].L.i, expected "
           "132024982, is "
        << (int64_t)last_msg.msg.obs.obs[4].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[4].P, 1256175650)
        << "incorrect value for last_msg.msg.obs.obs[4].P, expected "
           "1256175650, is "
        << (int64_t)last_msg.msg.obs.obs[4].P;

    EXPECT_EQ(last_msg.msg.obs.obs[4].cn0, 114)
        << "incorrect value for last_msg.msg.obs.obs[4].cn0, expected 114, is "
        << (int64_t)last_msg.msg.obs.obs[4].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[4].flags, 15)
        << "incorrect value for last_msg.msg.obs.obs[4].flags, expected 15, is "
        << (int64_t)last_msg.msg.obs.obs[4].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[4].lock, 9)
        << "incorrect value for last_msg.msg.obs.obs[4].lock, expected 9, is "
        << (int64_t)last_msg.msg.obs.obs[4].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[4].sid.code, 0)
        << "incorrect value for last_msg.msg.obs.obs[4].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[4].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[4].sid.sat, 22)
        << "incorrect value for last_msg.msg.obs.obs[4].sid.sat, expected 22, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[4].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[5].D.f, 246)
        << "incorrect value for last_msg.msg.obs.obs[5].D.f, expected 246, is "
        << (int64_t)last_msg.msg.obs.obs[5].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[5].D.i, -2433)
        << "incorrect value for last_msg.msg.obs.obs[5].D.i, expected -2433, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[5].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[5].L.f, 70)
        << "incorrect value for last_msg.msg.obs.obs[5].L.f, expected 70, is "
        << (int64_t)last_msg.msg.obs.obs[5].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[5].L.i, 121711010)
        << "incorrect value for last_msg.msg.obs.obs[5].L.i, expected "
           "121711010, is "
        << (int64_t)last_msg.msg.obs.obs[5].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[5].P, 1158041713)
        << "incorrect value for last_msg.msg.obs.obs[5].P, expected "
           "1158041713, is "
        << (int64_t)last_msg.msg.obs.obs[5].P;

    EXPECT_EQ(last_msg.msg.obs.obs[5].cn0, 189)
        << "incorrect value for last_msg.msg.obs.obs[5].cn0, expected 189, is "
        << (int64_t)last_msg.msg.obs.obs[5].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[5].flags, 15)
        << "incorrect value for last_msg.msg.obs.obs[5].flags, expected 15, is "
        << (int64_t)last_msg.msg.obs.obs[5].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[5].lock, 9)
        << "incorrect value for last_msg.msg.obs.obs[5].lock, expected 9, is "
        << (int64_t)last_msg.msg.obs.obs[5].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[5].sid.code, 0)
        << "incorrect value for last_msg.msg.obs.obs[5].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[5].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[5].sid.sat, 23)
        << "incorrect value for last_msg.msg.obs.obs[5].sid.sat, expected 23, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[5].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[6].D.f, 231)
        << "incorrect value for last_msg.msg.obs.obs[6].D.f, expected 231, is "
        << (int64_t)last_msg.msg.obs.obs[6].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[6].D.i, -1896)
        << "incorrect value for last_msg.msg.obs.obs[6].D.i, expected -1896, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[6].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[6].L.f, 221)
        << "incorrect value for last_msg.msg.obs.obs[6].L.f, expected 221, is "
        << (int64_t)last_msg.msg.obs.obs[6].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[6].L.i, 94839765)
        << "incorrect value for last_msg.msg.obs.obs[6].L.i, expected "
           "94839765, is "
        << (int64_t)last_msg.msg.obs.obs[6].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[6].P, 1158041847)
        << "incorrect value for last_msg.msg.obs.obs[6].P, expected "
           "1158041847, is "
        << (int64_t)last_msg.msg.obs.obs[6].P;

    EXPECT_EQ(last_msg.msg.obs.obs[6].cn0, 158)
        << "incorrect value for last_msg.msg.obs.obs[6].cn0, expected 158, is "
        << (int64_t)last_msg.msg.obs.obs[6].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[6].flags, 11)
        << "incorrect value for last_msg.msg.obs.obs[6].flags, expected 11, is "
        << (int64_t)last_msg.msg.obs.obs[6].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[6].lock, 9)
        << "incorrect value for last_msg.msg.obs.obs[6].lock, expected 9, is "
        << (int64_t)last_msg.msg.obs.obs[6].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[6].sid.code, 1)
        << "incorrect value for last_msg.msg.obs.obs[6].sid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[6].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[6].sid.sat, 23)
        << "incorrect value for last_msg.msg.obs.obs[6].sid.sat, expected 23, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[6].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[7].D.f, 67)
        << "incorrect value for last_msg.msg.obs.obs[7].D.f, expected 67, is "
        << (int64_t)last_msg.msg.obs.obs[7].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[7].D.i, -1997)
        << "incorrect value for last_msg.msg.obs.obs[7].D.i, expected -1997, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[7].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[7].L.f, 114)
        << "incorrect value for last_msg.msg.obs.obs[7].L.f, expected 114, is "
        << (int64_t)last_msg.msg.obs.obs[7].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[7].L.i, 113998348)
        << "incorrect value for last_msg.msg.obs.obs[7].L.i, expected "
           "113998348, is "
        << (int64_t)last_msg.msg.obs.obs[7].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[7].P, 1084658184)
        << "incorrect value for last_msg.msg.obs.obs[7].P, expected "
           "1084658184, is "
        << (int64_t)last_msg.msg.obs.obs[7].P;

    EXPECT_EQ(last_msg.msg.obs.obs[7].cn0, 93)
        << "incorrect value for last_msg.msg.obs.obs[7].cn0, expected 93, is "
        << (int64_t)last_msg.msg.obs.obs[7].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[7].flags, 11)
        << "incorrect value for last_msg.msg.obs.obs[7].flags, expected 11, is "
        << (int64_t)last_msg.msg.obs.obs[7].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[7].lock, 3)
        << "incorrect value for last_msg.msg.obs.obs[7].lock, expected 3, is "
        << (int64_t)last_msg.msg.obs.obs[7].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[7].sid.code, 0)
        << "incorrect value for last_msg.msg.obs.obs[7].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[7].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[7].sid.sat, 27)
        << "incorrect value for last_msg.msg.obs.obs[7].sid.sat, expected 27, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[7].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[8].D.f, 237)
        << "incorrect value for last_msg.msg.obs.obs[8].D.f, expected 237, is "
        << (int64_t)last_msg.msg.obs.obs[8].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[8].D.i, 3041)
        << "incorrect value for last_msg.msg.obs.obs[8].D.i, expected 3041, is "
        << (int64_t)last_msg.msg.obs.obs[8].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[8].L.f, 232)
        << "incorrect value for last_msg.msg.obs.obs[8].L.f, expected 232, is "
        << (int64_t)last_msg.msg.obs.obs[8].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[8].L.i, 133443545)
        << "incorrect value for last_msg.msg.obs.obs[8].L.i, expected "
           "133443545, is "
        << (int64_t)last_msg.msg.obs.obs[8].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[8].P, 1269673181)
        << "incorrect value for last_msg.msg.obs.obs[8].P, expected "
           "1269673181, is "
        << (int64_t)last_msg.msg.obs.obs[8].P;

    EXPECT_EQ(last_msg.msg.obs.obs[8].cn0, 123)
        << "incorrect value for last_msg.msg.obs.obs[8].cn0, expected 123, is "
        << (int64_t)last_msg.msg.obs.obs[8].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[8].flags, 15)
        << "incorrect value for last_msg.msg.obs.obs[8].flags, expected 15, is "
        << (int64_t)last_msg.msg.obs.obs[8].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[8].lock, 5)
        << "incorrect value for last_msg.msg.obs.obs[8].lock, expected 5, is "
        << (int64_t)last_msg.msg.obs.obs[8].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[8].sid.code, 0)
        << "incorrect value for last_msg.msg.obs.obs[8].sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[8].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[8].sid.sat, 31)
        << "incorrect value for last_msg.msg.obs.obs[8].sid.sat, expected 31, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[8].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[9].D.f, 62)
        << "incorrect value for last_msg.msg.obs.obs[9].D.f, expected 62, is "
        << (int64_t)last_msg.msg.obs.obs[9].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[9].D.i, 2374)
        << "incorrect value for last_msg.msg.obs.obs[9].D.i, expected 2374, is "
        << (int64_t)last_msg.msg.obs.obs[9].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[9].L.f, 40)
        << "incorrect value for last_msg.msg.obs.obs[9].L.f, expected 40, is "
        << (int64_t)last_msg.msg.obs.obs[9].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[9].L.i, 103982040)
        << "incorrect value for last_msg.msg.obs.obs[9].L.i, expected "
           "103982040, is "
        << (int64_t)last_msg.msg.obs.obs[9].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[9].P, 1269673722)
        << "incorrect value for last_msg.msg.obs.obs[9].P, expected "
           "1269673722, is "
        << (int64_t)last_msg.msg.obs.obs[9].P;

    EXPECT_EQ(last_msg.msg.obs.obs[9].cn0, 120)
        << "incorrect value for last_msg.msg.obs.obs[9].cn0, expected 120, is "
        << (int64_t)last_msg.msg.obs.obs[9].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[9].flags, 11)
        << "incorrect value for last_msg.msg.obs.obs[9].flags, expected 11, is "
        << (int64_t)last_msg.msg.obs.obs[9].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[9].lock, 3)
        << "incorrect value for last_msg.msg.obs.obs[9].lock, expected 3, is "
        << (int64_t)last_msg.msg.obs.obs[9].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[9].sid.code, 1)
        << "incorrect value for last_msg.msg.obs.obs[9].sid.code, expected 1, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[9].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[9].sid.sat, 31)
        << "incorrect value for last_msg.msg.obs.obs[9].sid.sat, expected 31, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[9].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[10].D.f, 96)
        << "incorrect value for last_msg.msg.obs.obs[10].D.f, expected 96, is "
        << (int64_t)last_msg.msg.obs.obs[10].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[10].D.i, -3446)
        << "incorrect value for last_msg.msg.obs.obs[10].D.i, expected -3446, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[10].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[10].L.f, 7)
        << "incorrect value for last_msg.msg.obs.obs[10].L.f, expected 7, is "
        << (int64_t)last_msg.msg.obs.obs[10].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[10].L.i, 118217315)
        << "incorrect value for last_msg.msg.obs.obs[10].L.i, expected "
           "118217315, is "
        << (int64_t)last_msg.msg.obs.obs[10].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[10].P, 1107693703)
        << "incorrect value for last_msg.msg.obs.obs[10].P, expected "
           "1107693703, is "
        << (int64_t)last_msg.msg.obs.obs[10].P;

    EXPECT_EQ(last_msg.msg.obs.obs[10].cn0, 176)
        << "incorrect value for last_msg.msg.obs.obs[10].cn0, expected 176, is "
        << (int64_t)last_msg.msg.obs.obs[10].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[10].flags, 15)
        << "incorrect value for last_msg.msg.obs.obs[10].flags, expected 15, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[10].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[10].lock, 10)
        << "incorrect value for last_msg.msg.obs.obs[10].lock, expected 10, is "
        << (int64_t)last_msg.msg.obs.obs[10].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[10].sid.code, 3)
        << "incorrect value for last_msg.msg.obs.obs[10].sid.code, expected 3, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[10].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[10].sid.sat, 2)
        << "incorrect value for last_msg.msg.obs.obs[10].sid.sat, expected 2, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[10].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[11].D.f, 96)
        << "incorrect value for last_msg.msg.obs.obs[11].D.f, expected 96, is "
        << (int64_t)last_msg.msg.obs.obs[11].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[11].D.i, -1003)
        << "incorrect value for last_msg.msg.obs.obs[11].D.i, expected -1003, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[11].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[11].L.f, 203)
        << "incorrect value for last_msg.msg.obs.obs[11].L.f, expected 203, is "
        << (int64_t)last_msg.msg.obs.obs[11].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[11].L.i, 104224985)
        << "incorrect value for last_msg.msg.obs.obs[11].L.i, expected "
           "104224985, is "
        << (int64_t)last_msg.msg.obs.obs[11].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[11].P, 973505172)
        << "incorrect value for last_msg.msg.obs.obs[11].P, expected "
           "973505172, is "
        << (int64_t)last_msg.msg.obs.obs[11].P;

    EXPECT_EQ(last_msg.msg.obs.obs[11].cn0, 170)
        << "incorrect value for last_msg.msg.obs.obs[11].cn0, expected 170, is "
        << (int64_t)last_msg.msg.obs.obs[11].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[11].flags, 15)
        << "incorrect value for last_msg.msg.obs.obs[11].flags, expected 15, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[11].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[11].lock, 10)
        << "incorrect value for last_msg.msg.obs.obs[11].lock, expected 10, is "
        << (int64_t)last_msg.msg.obs.obs[11].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[11].sid.code, 3)
        << "incorrect value for last_msg.msg.obs.obs[11].sid.code, expected 3, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[11].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[11].sid.sat, 3)
        << "incorrect value for last_msg.msg.obs.obs[11].sid.sat, expected 3, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[11].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[12].D.f, 219)
        << "incorrect value for last_msg.msg.obs.obs[12].D.f, expected 219, is "
        << (int64_t)last_msg.msg.obs.obs[12].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[12].D.i, -3836)
        << "incorrect value for last_msg.msg.obs.obs[12].D.i, expected -3836, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[12].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[12].L.f, 80)
        << "incorrect value for last_msg.msg.obs.obs[12].L.f, expected 80, is "
        << (int64_t)last_msg.msg.obs.obs[12].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[12].L.i, 114505343)
        << "incorrect value for last_msg.msg.obs.obs[12].L.i, expected "
           "114505343, is "
        << (int64_t)last_msg.msg.obs.obs[12].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[12].P, 1069903034)
        << "incorrect value for last_msg.msg.obs.obs[12].P, expected "
           "1069903034, is "
        << (int64_t)last_msg.msg.obs.obs[12].P;

    EXPECT_EQ(last_msg.msg.obs.obs[12].cn0, 200)
        << "incorrect value for last_msg.msg.obs.obs[12].cn0, expected 200, is "
        << (int64_t)last_msg.msg.obs.obs[12].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[12].flags, 15)
        << "incorrect value for last_msg.msg.obs.obs[12].flags, expected 15, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[12].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[12].lock, 10)
        << "incorrect value for last_msg.msg.obs.obs[12].lock, expected 10, is "
        << (int64_t)last_msg.msg.obs.obs[12].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[12].sid.code, 3)
        << "incorrect value for last_msg.msg.obs.obs[12].sid.code, expected 3, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[12].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[12].sid.sat, 17)
        << "incorrect value for last_msg.msg.obs.obs[12].sid.sat, expected 17, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[12].sid.sat;

    EXPECT_EQ(last_msg.msg.obs.obs[13].D.f, 182)
        << "incorrect value for last_msg.msg.obs.obs[13].D.f, expected 182, is "
        << (int64_t)last_msg.msg.obs.obs[13].D.f;

    EXPECT_EQ(last_msg.msg.obs.obs[13].D.i, -461)
        << "incorrect value for last_msg.msg.obs.obs[13].D.i, expected -461, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[13].D.i;

    EXPECT_EQ(last_msg.msg.obs.obs[13].L.f, 105)
        << "incorrect value for last_msg.msg.obs.obs[13].L.f, expected 105, is "
        << (int64_t)last_msg.msg.obs.obs[13].L.f;

    EXPECT_EQ(last_msg.msg.obs.obs[13].L.i, 102157331)
        << "incorrect value for last_msg.msg.obs.obs[13].L.i, expected "
           "102157331, is "
        << (int64_t)last_msg.msg.obs.obs[13].L.i;

    EXPECT_EQ(last_msg.msg.obs.obs[13].P, 956875687)
        << "incorrect value for last_msg.msg.obs.obs[13].P, expected "
           "956875687, is "
        << (int64_t)last_msg.msg.obs.obs[13].P;

    EXPECT_EQ(last_msg.msg.obs.obs[13].cn0, 152)
        << "incorrect value for last_msg.msg.obs.obs[13].cn0, expected 152, is "
        << (int64_t)last_msg.msg.obs.obs[13].cn0;

    EXPECT_EQ(last_msg.msg.obs.obs[13].flags, 15)
        << "incorrect value for last_msg.msg.obs.obs[13].flags, expected 15, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[13].flags;

    EXPECT_EQ(last_msg.msg.obs.obs[13].lock, 10)
        << "incorrect value for last_msg.msg.obs.obs[13].lock, expected 10, is "
        << (int64_t)last_msg.msg.obs.obs[13].lock;

    EXPECT_EQ(last_msg.msg.obs.obs[13].sid.code, 3)
        << "incorrect value for last_msg.msg.obs.obs[13].sid.code, expected 3, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[13].sid.code;

    EXPECT_EQ(last_msg.msg.obs.obs[13].sid.sat, 18)
        << "incorrect value for last_msg.msg.obs.obs[13].sid.sat, expected 18, "
           "is "
        << (int64_t)last_msg.msg.obs.obs[13].sid.sat;
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

    sbp_callback_register(&sbp_state, SbpMsgObs, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 74, 0, 129, 240, 11, 152, 202, 226, 25,
        0,  0,  0, 0,   106, 8,  16,  201, 101,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.obs.header.n_obs = 16;

    test_msg.obs.header.t.ns_residual = 0;

    test_msg.obs.header.t.tow = 434293400;

    test_msg.obs.header.t.wn = 2154;

    sbp_message_send(&sbp_state, SbpMsgObs, 61569, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 61569)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgObs, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.obs.header.n_obs, 16)
        << "incorrect value for last_msg.msg.obs.header.n_obs, expected 16, is "
        << (int64_t)last_msg.msg.obs.header.n_obs;

    EXPECT_EQ(last_msg.msg.obs.header.t.ns_residual, 0)
        << "incorrect value for last_msg.msg.obs.header.t.ns_residual, "
           "expected 0, is "
        << (int64_t)last_msg.msg.obs.header.t.ns_residual;

    EXPECT_EQ(last_msg.msg.obs.header.t.tow, 434293400)
        << "incorrect value for last_msg.msg.obs.header.t.tow, expected "
           "434293400, is "
        << (int64_t)last_msg.msg.obs.header.t.tow;

    EXPECT_EQ(last_msg.msg.obs.header.t.wn, 2154)
        << "incorrect value for last_msg.msg.obs.header.t.wn, expected 2154, "
           "is "
        << (int64_t)last_msg.msg.obs.header.t.wn;
  }
}

}  // namespace
