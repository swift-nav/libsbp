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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSocketUsage.yaml by
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

TEST(auto_check_sbp_linux_MsgLinuxSocketUsage,
     test_auto_check_sbp_linux_MsgLinuxSocketUsage) {
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

    sbp_callback_register(&sbp_state, SbpMsgLinuxSocketUsage, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  5,   127, 114, 138, 72,  13,  196, 69,  173, 67,  222, 186, 181,
        246, 154, 251, 17,  224, 179, 26,  169, 177, 90,  149, 213, 214, 6,
        126, 64,  120, 185, 84,  131, 200, 111, 32,  141, 217, 209, 52,  14,
        190, 147, 159, 246, 141, 122, 212, 119, 131, 30,  120, 47,  25,  109,
        154, 65,  132, 164, 39,  30,  30,  175, 8,   44,  28,  111, 236, 240,
        176, 74,  159, 129, 154, 153, 162, 229, 130, 154,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.linux_socket_usage.avg_queue_depth = 2907030541;

    test_msg.linux_socket_usage.max_queue_depth = 3048922691;

    test_msg.linux_socket_usage.socket_state_counts[0] = 39670;

    test_msg.linux_socket_usage.socket_state_counts[1] = 4603;

    test_msg.linux_socket_usage.socket_state_counts[2] = 46048;

    test_msg.linux_socket_usage.socket_state_counts[3] = 43290;

    test_msg.linux_socket_usage.socket_state_counts[4] = 23217;

    test_msg.linux_socket_usage.socket_state_counts[5] = 54677;

    test_msg.linux_socket_usage.socket_state_counts[6] = 1750;

    test_msg.linux_socket_usage.socket_state_counts[7] = 16510;

    test_msg.linux_socket_usage.socket_state_counts[8] = 47480;

    test_msg.linux_socket_usage.socket_state_counts[9] = 33620;

    test_msg.linux_socket_usage.socket_state_counts[10] = 28616;

    test_msg.linux_socket_usage.socket_state_counts[11] = 36128;

    test_msg.linux_socket_usage.socket_state_counts[12] = 53721;

    test_msg.linux_socket_usage.socket_state_counts[13] = 3636;

    test_msg.linux_socket_usage.socket_state_counts[14] = 37822;

    test_msg.linux_socket_usage.socket_state_counts[15] = 63135;

    test_msg.linux_socket_usage.socket_type_counts[0] = 31373;

    test_msg.linux_socket_usage.socket_type_counts[1] = 30676;

    test_msg.linux_socket_usage.socket_type_counts[2] = 7811;

    test_msg.linux_socket_usage.socket_type_counts[3] = 12152;

    test_msg.linux_socket_usage.socket_type_counts[4] = 27929;

    test_msg.linux_socket_usage.socket_type_counts[5] = 16794;

    test_msg.linux_socket_usage.socket_type_counts[6] = 42116;

    test_msg.linux_socket_usage.socket_type_counts[7] = 7719;

    test_msg.linux_socket_usage.socket_type_counts[8] = 44830;

    test_msg.linux_socket_usage.socket_type_counts[9] = 11272;

    test_msg.linux_socket_usage.socket_type_counts[10] = 28444;

    test_msg.linux_socket_usage.socket_type_counts[11] = 61676;

    test_msg.linux_socket_usage.socket_type_counts[12] = 19120;

    test_msg.linux_socket_usage.socket_type_counts[13] = 33183;

    test_msg.linux_socket_usage.socket_type_counts[14] = 39322;

    test_msg.linux_socket_usage.socket_type_counts[15] = 58786;

    sbp_message_send(&sbp_state, SbpMsgLinuxSocketUsage, 35442, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 35442)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgLinuxSocketUsage, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.linux_socket_usage.avg_queue_depth, 2907030541)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.avg_queue_depth, expected "
           "2907030541, is "
        << (int64_t)last_msg.msg.linux_socket_usage.avg_queue_depth;

    EXPECT_EQ(last_msg.msg.linux_socket_usage.max_queue_depth, 3048922691)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.max_queue_depth, expected "
           "3048922691, is "
        << (int64_t)last_msg.msg.linux_socket_usage.max_queue_depth;

    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[0], 39670)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[0], expected "
           "39670, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[0];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[1], 4603)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[1], expected "
           "4603, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[1];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[2], 46048)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[2], expected "
           "46048, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[2];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[3], 43290)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[3], expected "
           "43290, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[3];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[4], 23217)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[4], expected "
           "23217, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[4];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[5], 54677)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[5], expected "
           "54677, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[5];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[6], 1750)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[6], expected "
           "1750, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[6];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[7], 16510)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[7], expected "
           "16510, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[7];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[8], 47480)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[8], expected "
           "47480, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[8];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[9], 33620)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[9], expected "
           "33620, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[9];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[10], 28616)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[10], expected "
           "28616, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[10];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[11], 36128)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[11], expected "
           "36128, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[11];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[12], 53721)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[12], expected "
           "53721, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[12];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[13], 3636)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[13], expected "
           "3636, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[13];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[14], 37822)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[14], expected "
           "37822, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[14];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_state_counts[15], 63135)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_state_counts[15], expected "
           "63135, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_state_counts[15];

    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[0], 31373)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[0], expected "
           "31373, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[0];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[1], 30676)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[1], expected "
           "30676, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[1];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[2], 7811)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[2], expected "
           "7811, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[2];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[3], 12152)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[3], expected "
           "12152, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[3];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[4], 27929)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[4], expected "
           "27929, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[4];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[5], 16794)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[5], expected "
           "16794, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[5];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[6], 42116)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[6], expected "
           "42116, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[6];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[7], 7719)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[7], expected "
           "7719, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[7];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[8], 44830)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[8], expected "
           "44830, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[8];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[9], 11272)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[9], expected "
           "11272, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[9];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[10], 28444)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[10], expected "
           "28444, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[10];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[11], 61676)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[11], expected "
           "61676, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[11];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[12], 19120)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[12], expected "
           "19120, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[12];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[13], 33183)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[13], expected "
           "33183, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[13];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[14], 39322)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[14], expected "
           "39322, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[14];
    EXPECT_EQ(last_msg.msg.linux_socket_usage.socket_type_counts[15], 58786)
        << "incorrect value for "
           "last_msg.msg.linux_socket_usage.socket_type_counts[15], expected "
           "58786, is "
        << (int64_t)last_msg.msg.linux_socket_usage.socket_type_counts[15];
  }
}

}  // namespace
