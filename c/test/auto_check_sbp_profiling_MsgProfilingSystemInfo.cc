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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingSystemInfo.yaml by
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

TEST(auto_check_sbp_profiling_MsgProfilingSystemInfo,
     test_auto_check_sbp_profiling_MsgProfilingSystemInfo) {
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

    sbp_callback_register(&sbp_state, SbpMsgProfilingSystemInfo,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 1,   207, 0, 16, 21, 98, 40, 52, 0,   0,   0, 0,   0,  114,
        12, 157, 0,   0, 0,  0,  0,  27, 72, 195, 226, 0, 252, 65,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.profiling_system_info.age = 10292338;

    test_msg.profiling_system_info.heap_usage = 14861128;

    test_msg.profiling_system_info.n_threads = 27;

    test_msg.profiling_system_info.total_cpu_time = 3418210;

    sbp_message_send(&sbp_state, SbpMsgProfilingSystemInfo, 4096, &test_msg,
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
        sbp_message_cmp(SbpMsgProfilingSystemInfo, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.profiling_system_info.age, 10292338)
        << "incorrect value for last_msg.msg.profiling_system_info.age, "
           "expected 10292338, is "
        << (int64_t)last_msg.msg.profiling_system_info.age;

    EXPECT_EQ(last_msg.msg.profiling_system_info.heap_usage, 14861128)
        << "incorrect value for last_msg.msg.profiling_system_info.heap_usage, "
           "expected 14861128, is "
        << (int64_t)last_msg.msg.profiling_system_info.heap_usage;

    EXPECT_EQ(last_msg.msg.profiling_system_info.n_threads, 27)
        << "incorrect value for last_msg.msg.profiling_system_info.n_threads, "
           "expected 27, is "
        << (int64_t)last_msg.msg.profiling_system_info.n_threads;

    EXPECT_EQ(last_msg.msg.profiling_system_info.total_cpu_time, 3418210)
        << "incorrect value for "
           "last_msg.msg.profiling_system_info.total_cpu_time, expected "
           "3418210, is "
        << (int64_t)last_msg.msg.profiling_system_info.total_cpu_time;
  }
}

}  // namespace
