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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingThreadInfo.yaml by
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

TEST(auto_check_sbp_profiling_MsgProfilingThreadInfo,
     test_auto_check_sbp_profiling_MsgProfilingThreadInfo) {
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

    sbp_callback_register(&sbp_state, SbpMsgProfilingThreadInfo,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  2,   207, 0,   16,  39,  119, 91,  10,  0,   0,   0,
        0,   0,   110, 5,   155, 0,   0,   0,   0,   0,   1,   0,
        0,   128, 0,   208, 53,  4,   0,   70,  117, 115, 105, 111,
        110, 32,  101, 110, 103, 105, 110, 101, 0,   242, 170,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.profiling_thread_info.age = 10159470;

    size_t written;
    EXPECT_TRUE(sbp_msg_profiling_thread_info_name_set(
        &test_msg.profiling_thread_info, "Fusion engine", false, &written))
        << "Can't assign text";
    EXPECT_EQ(written, strlen("Fusion engine"))
        << "Wrote different to expected";
    EXPECT_EQ(sbp_msg_profiling_thread_info_name_encoded_len(
                  &test_msg.profiling_thread_info),
              14)
        << "String not encoded properly";

    test_msg.profiling_thread_info.stack_size = 8388608;

    test_msg.profiling_thread_info.stack_usage = 275920;

    test_msg.profiling_thread_info.state = 1;

    test_msg.profiling_thread_info.total_cpu_time = 678775;

    sbp_message_send(&sbp_state, SbpMsgProfilingThreadInfo, 4096, &test_msg,
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
        sbp_message_cmp(SbpMsgProfilingThreadInfo, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.profiling_thread_info.age, 10159470)
        << "incorrect value for last_msg.msg.profiling_thread_info.age, "
           "expected 10159470, is "
        << (int64_t)last_msg.msg.profiling_thread_info.age;

    EXPECT_EQ(sbp_msg_profiling_thread_info_name_encoded_len(
                  &last_msg.msg.profiling_thread_info),
              14)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_profiling_thread_info_name_get(
                         &last_msg.msg.profiling_thread_info),
                     "Fusion engine"),
              0)
        << "String not decoded properly";

    EXPECT_EQ(last_msg.msg.profiling_thread_info.stack_size, 8388608)
        << "incorrect value for last_msg.msg.profiling_thread_info.stack_size, "
           "expected 8388608, is "
        << (int64_t)last_msg.msg.profiling_thread_info.stack_size;

    EXPECT_EQ(last_msg.msg.profiling_thread_info.stack_usage, 275920)
        << "incorrect value for "
           "last_msg.msg.profiling_thread_info.stack_usage, expected 275920, "
           "is "
        << (int64_t)last_msg.msg.profiling_thread_info.stack_usage;

    EXPECT_EQ(last_msg.msg.profiling_thread_info.state, 1)
        << "incorrect value for last_msg.msg.profiling_thread_info.state, "
           "expected 1, is "
        << (int64_t)last_msg.msg.profiling_thread_info.state;

    EXPECT_EQ(last_msg.msg.profiling_thread_info.total_cpu_time, 678775)
        << "incorrect value for "
           "last_msg.msg.profiling_thread_info.total_cpu_time, expected "
           "678775, is "
        << (int64_t)last_msg.msg.profiling_thread_info.total_cpu_time;
  }
}

}  // namespace
