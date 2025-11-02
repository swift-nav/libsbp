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
// spec/tests/yaml/swiftnav/sbp/sbas/test_MsgSbasRaw.yaml by generate.py. Do not
// modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbas.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_sbas_MsgSbasRaw, test_auto_check_sbp_sbas_MsgSbasRaw) {
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

    sbp_callback_register(&sbp_state, SbpMsgSbasRaw, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  119, 119, 28,  200, 34,  131, 2,   201, 228, 233, 29,  4,   23,
        255, 0,   23,  255, 0,   23,  255, 127, 240, 2,   255, 192, 3,   127,
        247, 255, 127, 247, 255, 229, 229, 238, 170, 175, 255, 240, 167, 14,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.sbas_raw.data[0] = 23;

    test_msg.sbas_raw.data[1] = 255;

    test_msg.sbas_raw.data[2] = 0;

    test_msg.sbas_raw.data[3] = 23;

    test_msg.sbas_raw.data[4] = 255;

    test_msg.sbas_raw.data[5] = 0;

    test_msg.sbas_raw.data[6] = 23;

    test_msg.sbas_raw.data[7] = 255;

    test_msg.sbas_raw.data[8] = 127;

    test_msg.sbas_raw.data[9] = 240;

    test_msg.sbas_raw.data[10] = 2;

    test_msg.sbas_raw.data[11] = 255;

    test_msg.sbas_raw.data[12] = 192;

    test_msg.sbas_raw.data[13] = 3;

    test_msg.sbas_raw.data[14] = 127;

    test_msg.sbas_raw.data[15] = 247;

    test_msg.sbas_raw.data[16] = 255;

    test_msg.sbas_raw.data[17] = 127;

    test_msg.sbas_raw.data[18] = 247;

    test_msg.sbas_raw.data[19] = 255;

    test_msg.sbas_raw.data[20] = 229;

    test_msg.sbas_raw.data[21] = 229;

    test_msg.sbas_raw.data[22] = 238;

    test_msg.sbas_raw.data[23] = 170;

    test_msg.sbas_raw.data[24] = 175;

    test_msg.sbas_raw.data[25] = 255;

    test_msg.sbas_raw.data[26] = 240;

    test_msg.sbas_raw.message_type = 4;

    test_msg.sbas_raw.sid.code = 2;

    test_msg.sbas_raw.sid.sat = 131;

    test_msg.sbas_raw.tow = 501867721;

    sbp_message_send(&sbp_state, SbpMsgSbasRaw, 51228, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 51228)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSbasRaw, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.sbas_raw.data[0], 23)
        << "incorrect value for last_msg.msg.sbas_raw.data[0], expected 23, is "
        << (int64_t)last_msg.msg.sbas_raw.data[0];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[1], 255)
        << "incorrect value for last_msg.msg.sbas_raw.data[1], expected 255, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[1];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[2], 0)
        << "incorrect value for last_msg.msg.sbas_raw.data[2], expected 0, is "
        << (int64_t)last_msg.msg.sbas_raw.data[2];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[3], 23)
        << "incorrect value for last_msg.msg.sbas_raw.data[3], expected 23, is "
        << (int64_t)last_msg.msg.sbas_raw.data[3];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[4], 255)
        << "incorrect value for last_msg.msg.sbas_raw.data[4], expected 255, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[4];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[5], 0)
        << "incorrect value for last_msg.msg.sbas_raw.data[5], expected 0, is "
        << (int64_t)last_msg.msg.sbas_raw.data[5];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[6], 23)
        << "incorrect value for last_msg.msg.sbas_raw.data[6], expected 23, is "
        << (int64_t)last_msg.msg.sbas_raw.data[6];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[7], 255)
        << "incorrect value for last_msg.msg.sbas_raw.data[7], expected 255, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[7];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[8], 127)
        << "incorrect value for last_msg.msg.sbas_raw.data[8], expected 127, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[8];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[9], 240)
        << "incorrect value for last_msg.msg.sbas_raw.data[9], expected 240, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[9];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[10], 2)
        << "incorrect value for last_msg.msg.sbas_raw.data[10], expected 2, is "
        << (int64_t)last_msg.msg.sbas_raw.data[10];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[11], 255)
        << "incorrect value for last_msg.msg.sbas_raw.data[11], expected 255, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[11];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[12], 192)
        << "incorrect value for last_msg.msg.sbas_raw.data[12], expected 192, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[12];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[13], 3)
        << "incorrect value for last_msg.msg.sbas_raw.data[13], expected 3, is "
        << (int64_t)last_msg.msg.sbas_raw.data[13];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[14], 127)
        << "incorrect value for last_msg.msg.sbas_raw.data[14], expected 127, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[14];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[15], 247)
        << "incorrect value for last_msg.msg.sbas_raw.data[15], expected 247, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[15];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[16], 255)
        << "incorrect value for last_msg.msg.sbas_raw.data[16], expected 255, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[16];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[17], 127)
        << "incorrect value for last_msg.msg.sbas_raw.data[17], expected 127, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[17];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[18], 247)
        << "incorrect value for last_msg.msg.sbas_raw.data[18], expected 247, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[18];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[19], 255)
        << "incorrect value for last_msg.msg.sbas_raw.data[19], expected 255, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[19];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[20], 229)
        << "incorrect value for last_msg.msg.sbas_raw.data[20], expected 229, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[20];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[21], 229)
        << "incorrect value for last_msg.msg.sbas_raw.data[21], expected 229, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[21];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[22], 238)
        << "incorrect value for last_msg.msg.sbas_raw.data[22], expected 238, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[22];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[23], 170)
        << "incorrect value for last_msg.msg.sbas_raw.data[23], expected 170, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[23];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[24], 175)
        << "incorrect value for last_msg.msg.sbas_raw.data[24], expected 175, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[24];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[25], 255)
        << "incorrect value for last_msg.msg.sbas_raw.data[25], expected 255, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[25];
    EXPECT_EQ(last_msg.msg.sbas_raw.data[26], 240)
        << "incorrect value for last_msg.msg.sbas_raw.data[26], expected 240, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.data[26];

    EXPECT_EQ(last_msg.msg.sbas_raw.message_type, 4)
        << "incorrect value for last_msg.msg.sbas_raw.message_type, expected "
           "4, is "
        << (int64_t)last_msg.msg.sbas_raw.message_type;

    EXPECT_EQ(last_msg.msg.sbas_raw.sid.code, 2)
        << "incorrect value for last_msg.msg.sbas_raw.sid.code, expected 2, is "
        << (int64_t)last_msg.msg.sbas_raw.sid.code;

    EXPECT_EQ(last_msg.msg.sbas_raw.sid.sat, 131)
        << "incorrect value for last_msg.msg.sbas_raw.sid.sat, expected 131, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.sid.sat;

    EXPECT_EQ(last_msg.msg.sbas_raw.tow, 501867721)
        << "incorrect value for last_msg.msg.sbas_raw.tow, expected 501867721, "
           "is "
        << (int64_t)last_msg.msg.sbas_raw.tow;
  }
}

}  // namespace
