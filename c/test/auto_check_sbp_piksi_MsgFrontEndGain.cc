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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgFrontEndGain.yaml by generate.py.
// Do not modify by hand!

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

TEST(auto_check_sbp_piksi_MsgFrontEndGain,
     test_auto_check_sbp_piksi_MsgFrontEndGain) {
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

    sbp_callback_register(&sbp_state, SbpMsgFrontEndGain, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 191, 0,   175, 245, 16, 41,  133, 134, 10, 105, 20,
        38, 38,  246, 233, 216, 80, 187, 213, 85,  2,  235, 135,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.front_end_gain.if_gain[0] = -10;

    test_msg.front_end_gain.if_gain[1] = -23;

    test_msg.front_end_gain.if_gain[2] = -40;

    test_msg.front_end_gain.if_gain[3] = 80;

    test_msg.front_end_gain.if_gain[4] = -69;

    test_msg.front_end_gain.if_gain[5] = -43;

    test_msg.front_end_gain.if_gain[6] = 85;

    test_msg.front_end_gain.if_gain[7] = 2;

    test_msg.front_end_gain.rf_gain[0] = 41;

    test_msg.front_end_gain.rf_gain[1] = -123;

    test_msg.front_end_gain.rf_gain[2] = -122;

    test_msg.front_end_gain.rf_gain[3] = 10;

    test_msg.front_end_gain.rf_gain[4] = 105;

    test_msg.front_end_gain.rf_gain[5] = 20;

    test_msg.front_end_gain.rf_gain[6] = 38;

    test_msg.front_end_gain.rf_gain[7] = 38;

    sbp_message_send(&sbp_state, SbpMsgFrontEndGain, 62895, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 62895)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgFrontEndGain, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.front_end_gain.if_gain[0], -10)
        << "incorrect value for last_msg.msg.front_end_gain.if_gain[0], "
           "expected -10, is "
        << (int64_t)last_msg.msg.front_end_gain.if_gain[0];
    EXPECT_EQ(last_msg.msg.front_end_gain.if_gain[1], -23)
        << "incorrect value for last_msg.msg.front_end_gain.if_gain[1], "
           "expected -23, is "
        << (int64_t)last_msg.msg.front_end_gain.if_gain[1];
    EXPECT_EQ(last_msg.msg.front_end_gain.if_gain[2], -40)
        << "incorrect value for last_msg.msg.front_end_gain.if_gain[2], "
           "expected -40, is "
        << (int64_t)last_msg.msg.front_end_gain.if_gain[2];
    EXPECT_EQ(last_msg.msg.front_end_gain.if_gain[3], 80)
        << "incorrect value for last_msg.msg.front_end_gain.if_gain[3], "
           "expected 80, is "
        << (int64_t)last_msg.msg.front_end_gain.if_gain[3];
    EXPECT_EQ(last_msg.msg.front_end_gain.if_gain[4], -69)
        << "incorrect value for last_msg.msg.front_end_gain.if_gain[4], "
           "expected -69, is "
        << (int64_t)last_msg.msg.front_end_gain.if_gain[4];
    EXPECT_EQ(last_msg.msg.front_end_gain.if_gain[5], -43)
        << "incorrect value for last_msg.msg.front_end_gain.if_gain[5], "
           "expected -43, is "
        << (int64_t)last_msg.msg.front_end_gain.if_gain[5];
    EXPECT_EQ(last_msg.msg.front_end_gain.if_gain[6], 85)
        << "incorrect value for last_msg.msg.front_end_gain.if_gain[6], "
           "expected 85, is "
        << (int64_t)last_msg.msg.front_end_gain.if_gain[6];
    EXPECT_EQ(last_msg.msg.front_end_gain.if_gain[7], 2)
        << "incorrect value for last_msg.msg.front_end_gain.if_gain[7], "
           "expected 2, is "
        << (int64_t)last_msg.msg.front_end_gain.if_gain[7];

    EXPECT_EQ(last_msg.msg.front_end_gain.rf_gain[0], 41)
        << "incorrect value for last_msg.msg.front_end_gain.rf_gain[0], "
           "expected 41, is "
        << (int64_t)last_msg.msg.front_end_gain.rf_gain[0];
    EXPECT_EQ(last_msg.msg.front_end_gain.rf_gain[1], -123)
        << "incorrect value for last_msg.msg.front_end_gain.rf_gain[1], "
           "expected -123, is "
        << (int64_t)last_msg.msg.front_end_gain.rf_gain[1];
    EXPECT_EQ(last_msg.msg.front_end_gain.rf_gain[2], -122)
        << "incorrect value for last_msg.msg.front_end_gain.rf_gain[2], "
           "expected -122, is "
        << (int64_t)last_msg.msg.front_end_gain.rf_gain[2];
    EXPECT_EQ(last_msg.msg.front_end_gain.rf_gain[3], 10)
        << "incorrect value for last_msg.msg.front_end_gain.rf_gain[3], "
           "expected 10, is "
        << (int64_t)last_msg.msg.front_end_gain.rf_gain[3];
    EXPECT_EQ(last_msg.msg.front_end_gain.rf_gain[4], 105)
        << "incorrect value for last_msg.msg.front_end_gain.rf_gain[4], "
           "expected 105, is "
        << (int64_t)last_msg.msg.front_end_gain.rf_gain[4];
    EXPECT_EQ(last_msg.msg.front_end_gain.rf_gain[5], 20)
        << "incorrect value for last_msg.msg.front_end_gain.rf_gain[5], "
           "expected 20, is "
        << (int64_t)last_msg.msg.front_end_gain.rf_gain[5];
    EXPECT_EQ(last_msg.msg.front_end_gain.rf_gain[6], 38)
        << "incorrect value for last_msg.msg.front_end_gain.rf_gain[6], "
           "expected 38, is "
        << (int64_t)last_msg.msg.front_end_gain.rf_gain[6];
    EXPECT_EQ(last_msg.msg.front_end_gain.rf_gain[7], 38)
        << "incorrect value for last_msg.msg.front_end_gain.rf_gain[7], "
           "expected 38, is "
        << (int64_t)last_msg.msg.front_end_gain.rf_gain[7];
  }
}

}  // namespace
