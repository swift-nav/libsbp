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
// spec/tests/yaml/swiftnav/sbp/flash/test_MsgStmUniqueIdResp.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/flash.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_flash_MsgStmUniqueIdResp,
     test_auto_check_sbp_flash_MsgStmUniqueIdResp) {
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

    sbp_callback_register(&sbp_state, SbpMsgStmUniqueIdResp, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 229, 0,   195, 4,  12,  196, 16,  15,  163,
        85, 221, 119, 102, 32, 194, 56,  144, 221, 196,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.stm_unique_id_resp.stm_id[0] = 196;

    test_msg.stm_unique_id_resp.stm_id[1] = 16;

    test_msg.stm_unique_id_resp.stm_id[2] = 15;

    test_msg.stm_unique_id_resp.stm_id[3] = 163;

    test_msg.stm_unique_id_resp.stm_id[4] = 85;

    test_msg.stm_unique_id_resp.stm_id[5] = 221;

    test_msg.stm_unique_id_resp.stm_id[6] = 119;

    test_msg.stm_unique_id_resp.stm_id[7] = 102;

    test_msg.stm_unique_id_resp.stm_id[8] = 32;

    test_msg.stm_unique_id_resp.stm_id[9] = 194;

    test_msg.stm_unique_id_resp.stm_id[10] = 56;

    test_msg.stm_unique_id_resp.stm_id[11] = 144;

    sbp_message_send(&sbp_state, SbpMsgStmUniqueIdResp, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgStmUniqueIdResp, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[0], 196)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[0], "
           "expected 196, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[0];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[1], 16)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[1], "
           "expected 16, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[1];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[2], 15)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[2], "
           "expected 15, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[2];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[3], 163)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[3], "
           "expected 163, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[3];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[4], 85)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[4], "
           "expected 85, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[4];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[5], 221)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[5], "
           "expected 221, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[5];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[6], 119)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[6], "
           "expected 119, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[6];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[7], 102)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[7], "
           "expected 102, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[7];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[8], 32)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[8], "
           "expected 32, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[8];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[9], 194)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[9], "
           "expected 194, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[9];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[10], 56)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[10], "
           "expected 56, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[10];
    EXPECT_EQ(last_msg.msg.stm_unique_id_resp.stm_id[11], 144)
        << "incorrect value for last_msg.msg.stm_unique_id_resp.stm_id[11], "
           "expected 144, is "
        << (int64_t)last_msg.msg.stm_unique_id_resp.stm_id[11];
  }
}

}  // namespace
