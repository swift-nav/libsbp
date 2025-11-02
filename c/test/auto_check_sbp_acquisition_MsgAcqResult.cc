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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResult.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/acquisition.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_acquisition_MsgAcqResult,
     test_auto_check_sbp_acquisition_MsgAcqResult) {
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResult, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  47,  0,  195, 4,   14, 0,  0, 104, 65,  102,
        102, 144, 66, 205, 196, 0,  70, 8, 0,   207, 189,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result.cf = 8241.2001953125;

    test_msg.acq_result.cn0 = 14.5;

    test_msg.acq_result.cp = 72.19999694824219;

    test_msg.acq_result.sid.code = 0;

    test_msg.acq_result.sid.sat = 8;

    sbp_message_send(&sbp_state, SbpMsgAcqResult, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResult, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result.cf * 100 - 8241.20019531 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result.cf, expected "
           "8241.20019531, is "
        << last_msg.msg.acq_result.cf;

    EXPECT_LE((last_msg.msg.acq_result.cn0 * 100 - 14.5 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result.cn0, expected 14.5, is "
        << last_msg.msg.acq_result.cn0;

    EXPECT_LE((last_msg.msg.acq_result.cp * 100 - 72.1999969482 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result.cp, expected "
           "72.1999969482, is "
        << last_msg.msg.acq_result.cp;

    EXPECT_EQ(last_msg.msg.acq_result.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result.sid.code, expected 0, "
           "is "
        << (int64_t)last_msg.msg.acq_result.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result.sid.sat, 8)
        << "incorrect value for last_msg.msg.acq_result.sid.sat, expected 8, "
           "is "
        << (int64_t)last_msg.msg.acq_result.sid.sat;
  }
}

}  // namespace
