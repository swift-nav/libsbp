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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingQueueInfo.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/profiling.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_profiling_MsgProfilingQueueInfo,
     test_auto_check_sbp_profiling_MsgProfilingQueueInfo) {
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

    sbp_callback_register(&sbp_state, SbpMsgProfilingQueueInfo,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,   207, 0,   16,  58,  0,   1,   136, 19,  0,  0,  0,   0,
        0,   0,   67,  111, 104, 101, 115, 105, 118, 101, 83, 98, 112, 77,
        115, 103, 0,   0,   0,   0,   0,   0,   0,   0,   0,  0,  0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0,  0,   0,
        100, 0,   10,  0,   50,  0,   0,   0,   138, 42,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.profiling_queue_info.n_queues = 1;

    test_msg.profiling_queue_info.queues[0].current_fill = 10;

    test_msg.profiling_queue_info.queues[0].drop_count = 0;

    {
      const char assign_string[] = {
          (char)67,  (char)111, (char)104, (char)101, (char)115, (char)105,
          (char)118, (char)101, (char)83,  (char)98,  (char)112, (char)77,
          (char)115, (char)103, (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.profiling_queue_info.queues[0].name, assign_string,
             sizeof(assign_string));
    }

    test_msg.profiling_queue_info.queues[0].peak_fill = 50;

    test_msg.profiling_queue_info.queues[0].size = 100;

    test_msg.profiling_queue_info.queues[0].timestamp = 5000;

    test_msg.profiling_queue_info.seq_len = 1;

    test_msg.profiling_queue_info.seq_no = 0;

    sbp_message_send(&sbp_state, SbpMsgProfilingQueueInfo, 4096, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 4096)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgProfilingQueueInfo, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.profiling_queue_info.n_queues, 1)
        << "incorrect value for last_msg.msg.profiling_queue_info.n_queues, "
           "expected 1, is "
        << (int64_t)last_msg.msg.profiling_queue_info.n_queues;

    EXPECT_EQ(last_msg.msg.profiling_queue_info.queues[0].current_fill, 10)
        << "incorrect value for "
           "last_msg.msg.profiling_queue_info.queues[0].current_fill, expected "
           "10, is "
        << (int64_t)last_msg.msg.profiling_queue_info.queues[0].current_fill;

    EXPECT_EQ(last_msg.msg.profiling_queue_info.queues[0].drop_count, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_queue_info.queues[0].drop_count, expected "
           "0, is "
        << (int64_t)last_msg.msg.profiling_queue_info.queues[0].drop_count;

    {
      const char check_string[] = {
          (char)67,  (char)111, (char)104, (char)101, (char)115, (char)105,
          (char)118, (char)101, (char)83,  (char)98,  (char)112, (char)77,
          (char)115, (char)103, (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.profiling_queue_info.queues[0].name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.profiling_queue_info.queues[0].name, expected "
             "string '"
          << check_string << "', is '"
          << last_msg.msg.profiling_queue_info.queues[0].name << "'";
    }

    EXPECT_EQ(last_msg.msg.profiling_queue_info.queues[0].peak_fill, 50)
        << "incorrect value for "
           "last_msg.msg.profiling_queue_info.queues[0].peak_fill, expected "
           "50, is "
        << (int64_t)last_msg.msg.profiling_queue_info.queues[0].peak_fill;

    EXPECT_EQ(last_msg.msg.profiling_queue_info.queues[0].size, 100)
        << "incorrect value for "
           "last_msg.msg.profiling_queue_info.queues[0].size, expected 100, is "
        << (int64_t)last_msg.msg.profiling_queue_info.queues[0].size;

    EXPECT_EQ(last_msg.msg.profiling_queue_info.queues[0].timestamp, 5000)
        << "incorrect value for "
           "last_msg.msg.profiling_queue_info.queues[0].timestamp, expected "
           "5000, is "
        << (int64_t)last_msg.msg.profiling_queue_info.queues[0].timestamp;

    EXPECT_EQ(last_msg.msg.profiling_queue_info.seq_len, 1)
        << "incorrect value for last_msg.msg.profiling_queue_info.seq_len, "
           "expected 1, is "
        << (int64_t)last_msg.msg.profiling_queue_info.seq_len;

    EXPECT_EQ(last_msg.msg.profiling_queue_info.seq_no, 0)
        << "incorrect value for last_msg.msg.profiling_queue_info.seq_no, "
           "expected 0, is "
        << (int64_t)last_msg.msg.profiling_queue_info.seq_no;
  }
}

}  // namespace
