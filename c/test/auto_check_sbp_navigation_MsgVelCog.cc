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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelCog.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/navigation.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_navigation_MsgVelCog,
     test_auto_check_sbp_navigation_MsgVelCog) {
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

    sbp_callback_register(&sbp_state, SbpMsgVelCog, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  28,  2, 211, 136, 30,  48, 246, 122, 19,  232, 3,   0,
        0,   208, 7, 0,   0,   184, 11, 0,   0,   160, 15,  0,   0,
        136, 19,  0, 0,   112, 23,  0,  0,   62,  0,   212, 193,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_cog.cog = 1000;

    test_msg.vel_cog.cog_accuracy = 4000;

    test_msg.vel_cog.flags = 62;

    test_msg.vel_cog.sog = 2000;

    test_msg.vel_cog.sog_accuracy = 5000;

    test_msg.vel_cog.tow = 326825520;

    test_msg.vel_cog.v_up = 3000;

    test_msg.vel_cog.v_up_accuracy = 6000;

    sbp_message_send(&sbp_state, SbpMsgVelCog, 35027, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 35027)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelCog, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_cog.cog, 1000)
        << "incorrect value for last_msg.msg.vel_cog.cog, expected 1000, is "
        << (int64_t)last_msg.msg.vel_cog.cog;

    EXPECT_EQ(last_msg.msg.vel_cog.cog_accuracy, 4000)
        << "incorrect value for last_msg.msg.vel_cog.cog_accuracy, expected "
           "4000, is "
        << (int64_t)last_msg.msg.vel_cog.cog_accuracy;

    EXPECT_EQ(last_msg.msg.vel_cog.flags, 62)
        << "incorrect value for last_msg.msg.vel_cog.flags, expected 62, is "
        << (int64_t)last_msg.msg.vel_cog.flags;

    EXPECT_EQ(last_msg.msg.vel_cog.sog, 2000)
        << "incorrect value for last_msg.msg.vel_cog.sog, expected 2000, is "
        << (int64_t)last_msg.msg.vel_cog.sog;

    EXPECT_EQ(last_msg.msg.vel_cog.sog_accuracy, 5000)
        << "incorrect value for last_msg.msg.vel_cog.sog_accuracy, expected "
           "5000, is "
        << (int64_t)last_msg.msg.vel_cog.sog_accuracy;

    EXPECT_EQ(last_msg.msg.vel_cog.tow, 326825520)
        << "incorrect value for last_msg.msg.vel_cog.tow, expected 326825520, "
           "is "
        << (int64_t)last_msg.msg.vel_cog.tow;

    EXPECT_EQ(last_msg.msg.vel_cog.v_up, 3000)
        << "incorrect value for last_msg.msg.vel_cog.v_up, expected 3000, is "
        << (int64_t)last_msg.msg.vel_cog.v_up;

    EXPECT_EQ(last_msg.msg.vel_cog.v_up_accuracy, 6000)
        << "incorrect value for last_msg.msg.vel_cog.v_up_accuracy, expected "
           "6000, is "
        << (int64_t)last_msg.msg.vel_cog.v_up_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgVelCog, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  28,  2, 211, 136, 30, 48,  246, 122, 19, 123, 0,   0,
        0,   200, 1, 0,   0,   24, 252, 255, 255, 0,  149, 186, 10,
        100, 0,   0, 0,   100, 0,  0,   0,   0,   0,  90,  114,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_cog.cog = 123;

    test_msg.vel_cog.cog_accuracy = 180000000;

    test_msg.vel_cog.flags = 0;

    test_msg.vel_cog.sog = 456;

    test_msg.vel_cog.sog_accuracy = 100;

    test_msg.vel_cog.tow = 326825520;

    test_msg.vel_cog.v_up = -1000;

    test_msg.vel_cog.v_up_accuracy = 100;

    sbp_message_send(&sbp_state, SbpMsgVelCog, 35027, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 35027)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelCog, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_cog.cog, 123)
        << "incorrect value for last_msg.msg.vel_cog.cog, expected 123, is "
        << (int64_t)last_msg.msg.vel_cog.cog;

    EXPECT_EQ(last_msg.msg.vel_cog.cog_accuracy, 180000000)
        << "incorrect value for last_msg.msg.vel_cog.cog_accuracy, expected "
           "180000000, is "
        << (int64_t)last_msg.msg.vel_cog.cog_accuracy;

    EXPECT_EQ(last_msg.msg.vel_cog.flags, 0)
        << "incorrect value for last_msg.msg.vel_cog.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_cog.flags;

    EXPECT_EQ(last_msg.msg.vel_cog.sog, 456)
        << "incorrect value for last_msg.msg.vel_cog.sog, expected 456, is "
        << (int64_t)last_msg.msg.vel_cog.sog;

    EXPECT_EQ(last_msg.msg.vel_cog.sog_accuracy, 100)
        << "incorrect value for last_msg.msg.vel_cog.sog_accuracy, expected "
           "100, is "
        << (int64_t)last_msg.msg.vel_cog.sog_accuracy;

    EXPECT_EQ(last_msg.msg.vel_cog.tow, 326825520)
        << "incorrect value for last_msg.msg.vel_cog.tow, expected 326825520, "
           "is "
        << (int64_t)last_msg.msg.vel_cog.tow;

    EXPECT_EQ(last_msg.msg.vel_cog.v_up, -1000)
        << "incorrect value for last_msg.msg.vel_cog.v_up, expected -1000, is "
        << (int64_t)last_msg.msg.vel_cog.v_up;

    EXPECT_EQ(last_msg.msg.vel_cog.v_up_accuracy, 100)
        << "incorrect value for last_msg.msg.vel_cog.v_up_accuracy, expected "
           "100, is "
        << (int64_t)last_msg.msg.vel_cog.v_up_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgVelCog, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 28, 2, 211, 136, 30, 48, 246, 122, 19, 0, 0, 0, 0, 0, 0, 0, 0,  0,
        0,  0,  0, 0,   0,   0,  0,  0,   0,   0,  0, 0, 0, 0, 0, 0, 0, 42, 210,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_cog.cog = 0;

    test_msg.vel_cog.cog_accuracy = 0;

    test_msg.vel_cog.flags = 0;

    test_msg.vel_cog.sog = 0;

    test_msg.vel_cog.sog_accuracy = 0;

    test_msg.vel_cog.tow = 326825520;

    test_msg.vel_cog.v_up = 0;

    test_msg.vel_cog.v_up_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelCog, 35027, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 35027)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelCog, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_cog.cog, 0)
        << "incorrect value for last_msg.msg.vel_cog.cog, expected 0, is "
        << (int64_t)last_msg.msg.vel_cog.cog;

    EXPECT_EQ(last_msg.msg.vel_cog.cog_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_cog.cog_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_cog.cog_accuracy;

    EXPECT_EQ(last_msg.msg.vel_cog.flags, 0)
        << "incorrect value for last_msg.msg.vel_cog.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_cog.flags;

    EXPECT_EQ(last_msg.msg.vel_cog.sog, 0)
        << "incorrect value for last_msg.msg.vel_cog.sog, expected 0, is "
        << (int64_t)last_msg.msg.vel_cog.sog;

    EXPECT_EQ(last_msg.msg.vel_cog.sog_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_cog.sog_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_cog.sog_accuracy;

    EXPECT_EQ(last_msg.msg.vel_cog.tow, 326825520)
        << "incorrect value for last_msg.msg.vel_cog.tow, expected 326825520, "
           "is "
        << (int64_t)last_msg.msg.vel_cog.tow;

    EXPECT_EQ(last_msg.msg.vel_cog.v_up, 0)
        << "incorrect value for last_msg.msg.vel_cog.v_up, expected 0, is "
        << (int64_t)last_msg.msg.vel_cog.v_up;

    EXPECT_EQ(last_msg.msg.vel_cog.v_up_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_cog.v_up_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_cog.v_up_accuracy;
  }
}

}  // namespace
