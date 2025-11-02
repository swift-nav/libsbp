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
// spec/tests/yaml/swiftnav/sbp/logging/test_MsgFwd.yaml by generate.py. Do not
// modify by hand!

#include <gtest/gtest.h>
#include <libsbp/logging.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_logging_MsgFwd, test_auto_check_sbp_logging_MsgFwd) {
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

    sbp_callback_register(&sbp_state, SbpMsgFwd, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  2,  4,  66, 0,  18, 0,  0,  86, 81, 68,  47,  81,
        103, 65, 69, 65, 65, 65, 65, 65, 69, 97, 103, 125, 95,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.fwd.fwd_payload[0] = 86;

    test_msg.fwd.fwd_payload[1] = 81;

    test_msg.fwd.fwd_payload[2] = 68;

    test_msg.fwd.fwd_payload[3] = 47;

    test_msg.fwd.fwd_payload[4] = 81;

    test_msg.fwd.fwd_payload[5] = 103;

    test_msg.fwd.fwd_payload[6] = 65;

    test_msg.fwd.fwd_payload[7] = 69;

    test_msg.fwd.fwd_payload[8] = 65;

    test_msg.fwd.fwd_payload[9] = 65;

    test_msg.fwd.fwd_payload[10] = 65;

    test_msg.fwd.fwd_payload[11] = 65;

    test_msg.fwd.fwd_payload[12] = 65;

    test_msg.fwd.fwd_payload[13] = 69;

    test_msg.fwd.fwd_payload[14] = 97;

    test_msg.fwd.fwd_payload[15] = 103;

    test_msg.fwd.n_fwd_payload = 16;

    test_msg.fwd.protocol = 0;

    test_msg.fwd.source = 0;

    sbp_message_send(&sbp_state, SbpMsgFwd, 66, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgFwd, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[0], 86)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[0], expected 86, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[0];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[1], 81)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[1], expected 81, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[1];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[2], 68)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[2], expected 68, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[2];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[3], 47)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[3], expected 47, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[3];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[4], 81)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[4], expected 81, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[4];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[5], 103)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[5], expected 103, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[5];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[6], 65)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[6], expected 65, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[6];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[7], 69)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[7], expected 69, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[7];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[8], 65)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[8], expected 65, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[8];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[9], 65)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[9], expected 65, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[9];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[10], 65)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[10], expected 65, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[10];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[11], 65)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[11], expected 65, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[11];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[12], 65)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[12], expected 65, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[12];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[13], 69)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[13], expected 69, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[13];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[14], 97)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[14], expected 97, "
           "is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[14];
    EXPECT_EQ(last_msg.msg.fwd.fwd_payload[15], 103)
        << "incorrect value for last_msg.msg.fwd.fwd_payload[15], expected "
           "103, is "
        << (int64_t)last_msg.msg.fwd.fwd_payload[15];

    EXPECT_EQ(last_msg.msg.fwd.n_fwd_payload, 16)
        << "incorrect value for last_msg.msg.fwd.n_fwd_payload, expected 16, "
           "is "
        << (int64_t)last_msg.msg.fwd.n_fwd_payload;

    EXPECT_EQ(last_msg.msg.fwd.protocol, 0)
        << "incorrect value for last_msg.msg.fwd.protocol, expected 0, is "
        << (int64_t)last_msg.msg.fwd.protocol;

    EXPECT_EQ(last_msg.msg.fwd.source, 0)
        << "incorrect value for last_msg.msg.fwd.source, expected 0, is "
        << (int64_t)last_msg.msg.fwd.source;
  }
}

}  // namespace
