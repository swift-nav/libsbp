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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNED.yaml by generate.py.
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

TEST(auto_check_sbp_navigation_MsgVelNED,
     test_auto_check_sbp_navigation_MsgVelNED) {
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

    sbp_callback_register(&sbp_state, SbpMsgVelNed, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  14,  2,   211, 136, 22,  40,  244, 122, 19, 3, 0,  0, 0,  252,
        255, 255, 255, 243, 255, 255, 255, 0,   0,   0,  0, 14, 0, 86, 209,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned.d = -13;

    test_msg.vel_ned.e = -4;

    test_msg.vel_ned.flags = 0;

    test_msg.vel_ned.h_accuracy = 0;

    test_msg.vel_ned.n = 3;

    test_msg.vel_ned.n_sats = 14;

    test_msg.vel_ned.tow = 326825000;

    test_msg.vel_ned.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNed, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelNed, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ned.d, -13)
        << "incorrect value for last_msg.msg.vel_ned.d, expected -13, is "
        << (int64_t)last_msg.msg.vel_ned.d;

    EXPECT_EQ(last_msg.msg.vel_ned.e, -4)
        << "incorrect value for last_msg.msg.vel_ned.e, expected -4, is "
        << (int64_t)last_msg.msg.vel_ned.e;

    EXPECT_EQ(last_msg.msg.vel_ned.flags, 0)
        << "incorrect value for last_msg.msg.vel_ned.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ned.flags;

    EXPECT_EQ(last_msg.msg.vel_ned.h_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ned.h_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.h_accuracy;

    EXPECT_EQ(last_msg.msg.vel_ned.n, 3)
        << "incorrect value for last_msg.msg.vel_ned.n, expected 3, is "
        << (int64_t)last_msg.msg.vel_ned.n;

    EXPECT_EQ(last_msg.msg.vel_ned.n_sats, 14)
        << "incorrect value for last_msg.msg.vel_ned.n_sats, expected 14, is "
        << (int64_t)last_msg.msg.vel_ned.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ned.tow, 326825000)
        << "incorrect value for last_msg.msg.vel_ned.tow, expected 326825000, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.tow;

    EXPECT_EQ(last_msg.msg.vel_ned.v_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ned.v_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgVelNed, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  14,  2,   211, 136, 22,  28,  246, 122, 19,
        252, 255, 255, 255, 255, 255, 255, 255, 232, 255,
        255, 255, 0,   0,   0,   0,   15,  0,   16,  228,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned.d = -24;

    test_msg.vel_ned.e = -1;

    test_msg.vel_ned.flags = 0;

    test_msg.vel_ned.h_accuracy = 0;

    test_msg.vel_ned.n = -4;

    test_msg.vel_ned.n_sats = 15;

    test_msg.vel_ned.tow = 326825500;

    test_msg.vel_ned.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNed, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelNed, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ned.d, -24)
        << "incorrect value for last_msg.msg.vel_ned.d, expected -24, is "
        << (int64_t)last_msg.msg.vel_ned.d;

    EXPECT_EQ(last_msg.msg.vel_ned.e, -1)
        << "incorrect value for last_msg.msg.vel_ned.e, expected -1, is "
        << (int64_t)last_msg.msg.vel_ned.e;

    EXPECT_EQ(last_msg.msg.vel_ned.flags, 0)
        << "incorrect value for last_msg.msg.vel_ned.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ned.flags;

    EXPECT_EQ(last_msg.msg.vel_ned.h_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ned.h_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.h_accuracy;

    EXPECT_EQ(last_msg.msg.vel_ned.n, -4)
        << "incorrect value for last_msg.msg.vel_ned.n, expected -4, is "
        << (int64_t)last_msg.msg.vel_ned.n;

    EXPECT_EQ(last_msg.msg.vel_ned.n_sats, 15)
        << "incorrect value for last_msg.msg.vel_ned.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.vel_ned.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ned.tow, 326825500)
        << "incorrect value for last_msg.msg.vel_ned.tow, expected 326825500, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.tow;

    EXPECT_EQ(last_msg.msg.vel_ned.v_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ned.v_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgVelNed, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  14,  2,   211, 136, 22,  16,  248, 122, 19, 0, 0,  0, 0,  253,
        255, 255, 255, 244, 255, 255, 255, 0,   0,   0,  0, 15, 0, 11, 164,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned.d = -12;

    test_msg.vel_ned.e = -3;

    test_msg.vel_ned.flags = 0;

    test_msg.vel_ned.h_accuracy = 0;

    test_msg.vel_ned.n = 0;

    test_msg.vel_ned.n_sats = 15;

    test_msg.vel_ned.tow = 326826000;

    test_msg.vel_ned.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNed, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelNed, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ned.d, -12)
        << "incorrect value for last_msg.msg.vel_ned.d, expected -12, is "
        << (int64_t)last_msg.msg.vel_ned.d;

    EXPECT_EQ(last_msg.msg.vel_ned.e, -3)
        << "incorrect value for last_msg.msg.vel_ned.e, expected -3, is "
        << (int64_t)last_msg.msg.vel_ned.e;

    EXPECT_EQ(last_msg.msg.vel_ned.flags, 0)
        << "incorrect value for last_msg.msg.vel_ned.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ned.flags;

    EXPECT_EQ(last_msg.msg.vel_ned.h_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ned.h_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.h_accuracy;

    EXPECT_EQ(last_msg.msg.vel_ned.n, 0)
        << "incorrect value for last_msg.msg.vel_ned.n, expected 0, is "
        << (int64_t)last_msg.msg.vel_ned.n;

    EXPECT_EQ(last_msg.msg.vel_ned.n_sats, 15)
        << "incorrect value for last_msg.msg.vel_ned.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.vel_ned.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ned.tow, 326826000)
        << "incorrect value for last_msg.msg.vel_ned.tow, expected 326826000, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.tow;

    EXPECT_EQ(last_msg.msg.vel_ned.v_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ned.v_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgVelNed, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 14, 2, 211, 136, 22,  4,   250, 122, 19, 2, 0,  0, 0,   3,
        0,  0,  0, 232, 255, 255, 255, 0,   0,   0,  0, 15, 0, 152, 208,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned.d = -24;

    test_msg.vel_ned.e = 3;

    test_msg.vel_ned.flags = 0;

    test_msg.vel_ned.h_accuracy = 0;

    test_msg.vel_ned.n = 2;

    test_msg.vel_ned.n_sats = 15;

    test_msg.vel_ned.tow = 326826500;

    test_msg.vel_ned.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNed, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelNed, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ned.d, -24)
        << "incorrect value for last_msg.msg.vel_ned.d, expected -24, is "
        << (int64_t)last_msg.msg.vel_ned.d;

    EXPECT_EQ(last_msg.msg.vel_ned.e, 3)
        << "incorrect value for last_msg.msg.vel_ned.e, expected 3, is "
        << (int64_t)last_msg.msg.vel_ned.e;

    EXPECT_EQ(last_msg.msg.vel_ned.flags, 0)
        << "incorrect value for last_msg.msg.vel_ned.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ned.flags;

    EXPECT_EQ(last_msg.msg.vel_ned.h_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ned.h_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.h_accuracy;

    EXPECT_EQ(last_msg.msg.vel_ned.n, 2)
        << "incorrect value for last_msg.msg.vel_ned.n, expected 2, is "
        << (int64_t)last_msg.msg.vel_ned.n;

    EXPECT_EQ(last_msg.msg.vel_ned.n_sats, 15)
        << "incorrect value for last_msg.msg.vel_ned.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.vel_ned.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ned.tow, 326826500)
        << "incorrect value for last_msg.msg.vel_ned.tow, expected 326826500, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.tow;

    EXPECT_EQ(last_msg.msg.vel_ned.v_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ned.v_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgVelNed, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 14, 2, 211, 136, 22,  248, 251, 122, 19, 1, 0,  0, 0,   0,
        0,  0,  0, 235, 255, 255, 255, 0,   0,   0,  0, 15, 0, 182, 120,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ned.d = -21;

    test_msg.vel_ned.e = 0;

    test_msg.vel_ned.flags = 0;

    test_msg.vel_ned.h_accuracy = 0;

    test_msg.vel_ned.n = 1;

    test_msg.vel_ned.n_sats = 15;

    test_msg.vel_ned.tow = 326827000;

    test_msg.vel_ned.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgVelNed, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelNed, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ned.d, -21)
        << "incorrect value for last_msg.msg.vel_ned.d, expected -21, is "
        << (int64_t)last_msg.msg.vel_ned.d;

    EXPECT_EQ(last_msg.msg.vel_ned.e, 0)
        << "incorrect value for last_msg.msg.vel_ned.e, expected 0, is "
        << (int64_t)last_msg.msg.vel_ned.e;

    EXPECT_EQ(last_msg.msg.vel_ned.flags, 0)
        << "incorrect value for last_msg.msg.vel_ned.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ned.flags;

    EXPECT_EQ(last_msg.msg.vel_ned.h_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ned.h_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.h_accuracy;

    EXPECT_EQ(last_msg.msg.vel_ned.n, 1)
        << "incorrect value for last_msg.msg.vel_ned.n, expected 1, is "
        << (int64_t)last_msg.msg.vel_ned.n;

    EXPECT_EQ(last_msg.msg.vel_ned.n_sats, 15)
        << "incorrect value for last_msg.msg.vel_ned.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.vel_ned.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ned.tow, 326827000)
        << "incorrect value for last_msg.msg.vel_ned.tow, expected 326827000, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.tow;

    EXPECT_EQ(last_msg.msg.vel_ned.v_accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ned.v_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ned.v_accuracy;
  }
}

}  // namespace
