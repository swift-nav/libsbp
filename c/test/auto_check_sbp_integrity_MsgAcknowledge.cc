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
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgAcknowledge.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/integrity.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_integrity_MsgAcknowledge,
     test_auto_check_sbp_integrity_MsgAcknowledge) {
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

    sbp_callback_register(&sbp_state, SbpMsgAcknowledge, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 210, 11, 42, 0, 11, 30, 64, 226, 1, 0, 0, 1, 0, 1, 0, 2, 86, 178,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acknowledge.area_id = 123456;

    test_msg.acknowledge.correction_mask_on_demand = 1;

    test_msg.acknowledge.correction_mask_stream = 1;

    test_msg.acknowledge.request_id = 30;

    test_msg.acknowledge.response_code = 0;

    test_msg.acknowledge.solution_id = 2;

    sbp_message_send(&sbp_state, SbpMsgAcknowledge, 42, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 42)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcknowledge, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.acknowledge.area_id, 123456)
        << "incorrect value for last_msg.msg.acknowledge.area_id, expected "
           "123456, is "
        << (int64_t)last_msg.msg.acknowledge.area_id;

    EXPECT_EQ(last_msg.msg.acknowledge.correction_mask_on_demand, 1)
        << "incorrect value for "
           "last_msg.msg.acknowledge.correction_mask_on_demand, expected 1, is "
        << (int64_t)last_msg.msg.acknowledge.correction_mask_on_demand;

    EXPECT_EQ(last_msg.msg.acknowledge.correction_mask_stream, 1)
        << "incorrect value for "
           "last_msg.msg.acknowledge.correction_mask_stream, expected 1, is "
        << (int64_t)last_msg.msg.acknowledge.correction_mask_stream;

    EXPECT_EQ(last_msg.msg.acknowledge.request_id, 30)
        << "incorrect value for last_msg.msg.acknowledge.request_id, expected "
           "30, is "
        << (int64_t)last_msg.msg.acknowledge.request_id;

    EXPECT_EQ(last_msg.msg.acknowledge.response_code, 0)
        << "incorrect value for last_msg.msg.acknowledge.response_code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acknowledge.response_code;

    EXPECT_EQ(last_msg.msg.acknowledge.solution_id, 2)
        << "incorrect value for last_msg.msg.acknowledge.solution_id, expected "
           "2, is "
        << (int64_t)last_msg.msg.acknowledge.solution_id;
  }
}

}  // namespace
