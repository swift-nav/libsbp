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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSysState.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/linux.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_linux_MsgLinuxSysState,
     test_auto_check_sbp_linux_MsgLinuxSysState) {
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

    sbp_callback_register(&sbp_state, SbpMsgLinuxSysState, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  10,  127, 85,  167, 15, 20,  207, 125, 215, 196, 71,
        161, 229, 250, 186, 108, 30, 106, 5,   9,   229, 242,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.linux_sys_state.flags = 9;

    test_msg.linux_sys_state.mem_total = 53012;

    test_msg.linux_sys_state.pcpu = 125;

    test_msg.linux_sys_state.pid_count = 47866;

    test_msg.linux_sys_state.pmem = 215;

    test_msg.linux_sys_state.procs_starting = 18372;

    test_msg.linux_sys_state.procs_stopping = 58785;

    test_msg.linux_sys_state.time = 90840684;

    sbp_message_send(&sbp_state, SbpMsgLinuxSysState, 42837, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 42837)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgLinuxSysState, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.linux_sys_state.flags, 9)
        << "incorrect value for last_msg.msg.linux_sys_state.flags, expected "
           "9, is "
        << (int64_t)last_msg.msg.linux_sys_state.flags;

    EXPECT_EQ(last_msg.msg.linux_sys_state.mem_total, 53012)
        << "incorrect value for last_msg.msg.linux_sys_state.mem_total, "
           "expected 53012, is "
        << (int64_t)last_msg.msg.linux_sys_state.mem_total;

    EXPECT_EQ(last_msg.msg.linux_sys_state.pcpu, 125)
        << "incorrect value for last_msg.msg.linux_sys_state.pcpu, expected "
           "125, is "
        << (int64_t)last_msg.msg.linux_sys_state.pcpu;

    EXPECT_EQ(last_msg.msg.linux_sys_state.pid_count, 47866)
        << "incorrect value for last_msg.msg.linux_sys_state.pid_count, "
           "expected 47866, is "
        << (int64_t)last_msg.msg.linux_sys_state.pid_count;

    EXPECT_EQ(last_msg.msg.linux_sys_state.pmem, 215)
        << "incorrect value for last_msg.msg.linux_sys_state.pmem, expected "
           "215, is "
        << (int64_t)last_msg.msg.linux_sys_state.pmem;

    EXPECT_EQ(last_msg.msg.linux_sys_state.procs_starting, 18372)
        << "incorrect value for last_msg.msg.linux_sys_state.procs_starting, "
           "expected 18372, is "
        << (int64_t)last_msg.msg.linux_sys_state.procs_starting;

    EXPECT_EQ(last_msg.msg.linux_sys_state.procs_stopping, 58785)
        << "incorrect value for last_msg.msg.linux_sys_state.procs_stopping, "
           "expected 58785, is "
        << (int64_t)last_msg.msg.linux_sys_state.procs_stopping;

    EXPECT_EQ(last_msg.msg.linux_sys_state.time, 90840684)
        << "incorrect value for last_msg.msg.linux_sys_state.time, expected "
           "90840684, is "
        << (int64_t)last_msg.msg.linux_sys_state.time;
  }
}

}  // namespace
