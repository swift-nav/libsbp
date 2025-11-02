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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessSocketQueues.yaml by
// generate.py. Do not modify by hand!

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

TEST(auto_check_sbp_linux_MsgLinuxProcessSocketQueues,
     test_auto_check_sbp_linux_MsgLinuxProcessSocketQueues) {
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

    sbp_callback_register(&sbp_state, SbpMsgLinuxProcessSocketQueues,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,   127, 187, 232, 121, 181, 135, 75,  249, 211, 35,  252,
        80,  109, 15,  223, 97,  100, 100, 114, 101, 115, 115, 32,  111,
        102, 32,  108, 97,  114, 103, 101, 115, 116, 0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   47,  112, 97,  116, 104, 47,  116, 111, 47,  112,
        114, 111, 99,  101, 115, 115, 45,  110, 97,  109, 101, 32,  97,
        114, 103, 48,  32,  97,  114, 103, 49,  32,  97,  114, 103, 50,
        32,  97,  114, 103, 51,  32,  97,  114, 103, 52,  2,   247,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    {
      const char assign_string[] = {
          (char)97,  (char)100, (char)100, (char)114, (char)101, (char)115,
          (char)115, (char)32,  (char)111, (char)102, (char)32,  (char)108,
          (char)97,  (char)114, (char)103, (char)101, (char)115, (char)116,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.linux_process_socket_queues.address_of_largest,
             assign_string, sizeof(assign_string));
    }

    size_t written;
    EXPECT_TRUE(sbp_msg_linux_process_socket_queues_cmdline_set(
        &test_msg.linux_process_socket_queues,
        "/path/to/process-name arg0 arg1 arg2 arg3 arg4", false, &written))
        << "Can't assign text";
    EXPECT_EQ(written, strlen("/path/to/process-name arg0 arg1 arg2 arg3 arg4"))
        << "Wrote different to expected";
    EXPECT_EQ(sbp_msg_linux_process_socket_queues_cmdline_encoded_len(
                  &test_msg.linux_process_socket_queues),
              46)
        << "String not encoded properly";

    test_msg.linux_process_socket_queues.index = 181;

    test_msg.linux_process_socket_queues.pid = 19335;

    test_msg.linux_process_socket_queues.recv_queued = 54265;

    test_msg.linux_process_socket_queues.send_queued = 64547;

    test_msg.linux_process_socket_queues.socket_states = 57103;

    test_msg.linux_process_socket_queues.socket_types = 27984;

    sbp_message_send(&sbp_state, SbpMsgLinuxProcessSocketQueues, 59579,
                     &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 59579)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgLinuxProcessSocketQueues, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    {
      const char check_string[] = {
          (char)97,  (char)100, (char)100, (char)114, (char)101, (char)115,
          (char)115, (char)32,  (char)111, (char)102, (char)32,  (char)108,
          (char)97,  (char)114, (char)103, (char)101, (char)115, (char)116,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0};
      EXPECT_EQ(
          memcmp(&last_msg.msg.linux_process_socket_queues.address_of_largest,
                 check_string, sizeof(check_string)),
          0)
          << "incorrect value for "
             "last_msg.msg.linux_process_socket_queues.address_of_largest, "
             "expected string '"
          << check_string << "', is '"
          << last_msg.msg.linux_process_socket_queues.address_of_largest << "'";
    }

    EXPECT_EQ(sbp_msg_linux_process_socket_queues_cmdline_encoded_len(
                  &last_msg.msg.linux_process_socket_queues),
              46)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_linux_process_socket_queues_cmdline_get(
                         &last_msg.msg.linux_process_socket_queues),
                     "/path/to/process-name arg0 arg1 arg2 arg3 arg4"),
              0)
        << "String not decoded properly";

    EXPECT_EQ(last_msg.msg.linux_process_socket_queues.index, 181)
        << "incorrect value for "
           "last_msg.msg.linux_process_socket_queues.index, expected 181, is "
        << (int64_t)last_msg.msg.linux_process_socket_queues.index;

    EXPECT_EQ(last_msg.msg.linux_process_socket_queues.pid, 19335)
        << "incorrect value for last_msg.msg.linux_process_socket_queues.pid, "
           "expected 19335, is "
        << (int64_t)last_msg.msg.linux_process_socket_queues.pid;

    EXPECT_EQ(last_msg.msg.linux_process_socket_queues.recv_queued, 54265)
        << "incorrect value for "
           "last_msg.msg.linux_process_socket_queues.recv_queued, expected "
           "54265, is "
        << (int64_t)last_msg.msg.linux_process_socket_queues.recv_queued;

    EXPECT_EQ(last_msg.msg.linux_process_socket_queues.send_queued, 64547)
        << "incorrect value for "
           "last_msg.msg.linux_process_socket_queues.send_queued, expected "
           "64547, is "
        << (int64_t)last_msg.msg.linux_process_socket_queues.send_queued;

    EXPECT_EQ(last_msg.msg.linux_process_socket_queues.socket_states, 57103)
        << "incorrect value for "
           "last_msg.msg.linux_process_socket_queues.socket_states, expected "
           "57103, is "
        << (int64_t)last_msg.msg.linux_process_socket_queues.socket_states;

    EXPECT_EQ(last_msg.msg.linux_process_socket_queues.socket_types, 27984)
        << "incorrect value for "
           "last_msg.msg.linux_process_socket_queues.socket_types, expected "
           "27984, is "
        << (int64_t)last_msg.msg.linux_process_socket_queues.socket_types;
  }
}

}  // namespace
