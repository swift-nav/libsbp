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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgIarState.yaml by generate.py. Do
// not modify by hand!

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

TEST(auto_check_sbp_piksi_MsgIarState, test_auto_check_sbp_piksi_MsgIarState) {
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

    sbp_callback_register(&sbp_state, SbpMsgIarState, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 25, 0, 246, 215, 4, 1, 0, 0, 0, 216, 140,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.iar_state.num_hyps = 1;

    sbp_message_send(&sbp_state, SbpMsgIarState, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgIarState, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.iar_state.num_hyps, 1)
        << "incorrect value for last_msg.msg.iar_state.num_hyps, expected 1, "
           "is "
        << (int64_t)last_msg.msg.iar_state.num_hyps;
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

    sbp_callback_register(&sbp_state, SbpMsgIarState, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 25, 0, 195, 4, 4, 0, 0, 0, 0, 18, 176,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.iar_state.num_hyps = 0;

    sbp_message_send(&sbp_state, SbpMsgIarState, 1219, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgIarState, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.iar_state.num_hyps, 0)
        << "incorrect value for last_msg.msg.iar_state.num_hyps, expected 0, "
           "is "
        << (int64_t)last_msg.msg.iar_state.num_hyps;
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

    sbp_callback_register(&sbp_state, SbpMsgIarState, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 25, 0, 195, 4, 4, 1, 0, 0, 0, 166, 198,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.iar_state.num_hyps = 1;

    sbp_message_send(&sbp_state, SbpMsgIarState, 1219, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgIarState, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.iar_state.num_hyps, 1)
        << "incorrect value for last_msg.msg.iar_state.num_hyps, expected 1, "
           "is "
        << (int64_t)last_msg.msg.iar_state.num_hyps;
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

    sbp_callback_register(&sbp_state, SbpMsgIarState, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 25, 0, 195, 4, 4, 217, 2, 0, 0, 6, 133,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.iar_state.num_hyps = 729;

    sbp_message_send(&sbp_state, SbpMsgIarState, 1219, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgIarState, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.iar_state.num_hyps, 729)
        << "incorrect value for last_msg.msg.iar_state.num_hyps, expected 729, "
           "is "
        << (int64_t)last_msg.msg.iar_state.num_hyps;
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

    sbp_callback_register(&sbp_state, SbpMsgIarState, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 25, 0, 195, 4, 4, 216, 2, 0, 0, 178, 243,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.iar_state.num_hyps = 728;

    sbp_message_send(&sbp_state, SbpMsgIarState, 1219, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgIarState, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.iar_state.num_hyps, 728)
        << "incorrect value for last_msg.msg.iar_state.num_hyps, expected 728, "
           "is "
        << (int64_t)last_msg.msg.iar_state.num_hyps;
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

    sbp_callback_register(&sbp_state, SbpMsgIarState, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 25, 0, 195, 4, 4, 215, 2, 0, 0, 92, 39,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.iar_state.num_hyps = 727;

    sbp_message_send(&sbp_state, SbpMsgIarState, 1219, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgIarState, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.iar_state.num_hyps, 727)
        << "incorrect value for last_msg.msg.iar_state.num_hyps, expected 727, "
           "is "
        << (int64_t)last_msg.msg.iar_state.num_hyps;
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

    sbp_callback_register(&sbp_state, SbpMsgIarState, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 25, 0, 195, 4, 4, 211, 2, 0, 0, 173, 237,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.iar_state.num_hyps = 723;

    sbp_message_send(&sbp_state, SbpMsgIarState, 1219, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgIarState, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.iar_state.num_hyps, 723)
        << "incorrect value for last_msg.msg.iar_state.num_hyps, expected 723, "
           "is "
        << (int64_t)last_msg.msg.iar_state.num_hyps;
  }
}

}  // namespace
