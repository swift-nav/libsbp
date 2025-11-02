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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgGroupMeta.yaml by generate.py. Do
// not modify by hand!

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

TEST(auto_check_sbp_system_MsgGroupMeta,
     test_auto_check_sbp_system_MsgGroupMeta) {
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

    sbp_callback_register(&sbp_state, SbpMsgGroupMeta, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 10, 255, 238, 238, 9, 1, 2, 3, 10, 255, 10, 2, 2, 255, 2, 14,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.group_meta.flags = 2;

    test_msg.group_meta.group_id = 1;

    test_msg.group_meta.group_msgs[0] = 65290;

    test_msg.group_meta.group_msgs[1] = 522;

    test_msg.group_meta.group_msgs[2] = 65282;

    test_msg.group_meta.n_group_msgs = 3;

    sbp_message_send(&sbp_state, SbpMsgGroupMeta, 61166, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 61166)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgGroupMeta, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.group_meta.flags, 2)
        << "incorrect value for last_msg.msg.group_meta.flags, expected 2, is "
        << (int64_t)last_msg.msg.group_meta.flags;

    EXPECT_EQ(last_msg.msg.group_meta.group_id, 1)
        << "incorrect value for last_msg.msg.group_meta.group_id, expected 1, "
           "is "
        << (int64_t)last_msg.msg.group_meta.group_id;

    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[0], 65290)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[0], "
           "expected 65290, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[0];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[1], 522)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[1], "
           "expected 522, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[1];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[2], 65282)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[2], "
           "expected 65282, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[2];

    EXPECT_EQ(last_msg.msg.group_meta.n_group_msgs, 3)
        << "incorrect value for last_msg.msg.group_meta.n_group_msgs, expected "
           "3, is "
        << (int64_t)last_msg.msg.group_meta.n_group_msgs;
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

    sbp_callback_register(&sbp_state, SbpMsgGroupMeta, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 10, 255, 21, 3, 31, 1,   1, 14,  2,  1,   3,  1,
        10, 2,  17,  2,  9, 2,  20,  2, 14,  2,  18,  2,  13,
        2,  21, 2,   33, 2, 3,  255, 6, 255, 14, 255, 82, 154,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.group_meta.flags = 1;

    test_msg.group_meta.group_id = 1;

    test_msg.group_meta.group_msgs[0] = 258;

    test_msg.group_meta.group_msgs[1] = 259;

    test_msg.group_meta.group_msgs[2] = 522;

    test_msg.group_meta.group_msgs[3] = 529;

    test_msg.group_meta.group_msgs[4] = 521;

    test_msg.group_meta.group_msgs[5] = 532;

    test_msg.group_meta.group_msgs[6] = 526;

    test_msg.group_meta.group_msgs[7] = 530;

    test_msg.group_meta.group_msgs[8] = 525;

    test_msg.group_meta.group_msgs[9] = 533;

    test_msg.group_meta.group_msgs[10] = 545;

    test_msg.group_meta.group_msgs[11] = 65283;

    test_msg.group_meta.group_msgs[12] = 65286;

    test_msg.group_meta.group_msgs[13] = 65294;

    test_msg.group_meta.n_group_msgs = 14;

    sbp_message_send(&sbp_state, SbpMsgGroupMeta, 789, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 789)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgGroupMeta, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.group_meta.flags, 1)
        << "incorrect value for last_msg.msg.group_meta.flags, expected 1, is "
        << (int64_t)last_msg.msg.group_meta.flags;

    EXPECT_EQ(last_msg.msg.group_meta.group_id, 1)
        << "incorrect value for last_msg.msg.group_meta.group_id, expected 1, "
           "is "
        << (int64_t)last_msg.msg.group_meta.group_id;

    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[0], 258)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[0], "
           "expected 258, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[0];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[1], 259)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[1], "
           "expected 259, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[1];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[2], 522)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[2], "
           "expected 522, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[2];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[3], 529)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[3], "
           "expected 529, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[3];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[4], 521)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[4], "
           "expected 521, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[4];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[5], 532)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[5], "
           "expected 532, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[5];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[6], 526)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[6], "
           "expected 526, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[6];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[7], 530)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[7], "
           "expected 530, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[7];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[8], 525)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[8], "
           "expected 525, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[8];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[9], 533)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[9], "
           "expected 533, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[9];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[10], 545)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[10], "
           "expected 545, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[10];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[11], 65283)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[11], "
           "expected 65283, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[11];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[12], 65286)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[12], "
           "expected 65286, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[12];
    EXPECT_EQ(last_msg.msg.group_meta.group_msgs[13], 65294)
        << "incorrect value for last_msg.msg.group_meta.group_msgs[13], "
           "expected 65294, is "
        << (int64_t)last_msg.msg.group_meta.group_msgs[13];

    EXPECT_EQ(last_msg.msg.group_meta.n_group_msgs, 14)
        << "incorrect value for last_msg.msg.group_meta.n_group_msgs, expected "
           "14, is "
        << (int64_t)last_msg.msg.group_meta.n_group_msgs;
  }
}

}  // namespace
