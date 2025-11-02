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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEF.yaml by generate.py.
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

TEST(auto_check_sbp_navigation_MsgVelECEF,
     test_auto_check_sbp_navigation_MsgVelECEF) {
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  13,  2,   211, 136, 20, 40, 244, 122, 19, 248, 255, 255, 255,
        251, 255, 255, 255, 10,  0,  0,  0,   0,   0,  14,  0,   181, 99,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef.accuracy = 0;

    test_msg.vel_ecef.flags = 0;

    test_msg.vel_ecef.n_sats = 14;

    test_msg.vel_ecef.tow = 326825000;

    test_msg.vel_ecef.x = -8;

    test_msg.vel_ecef.y = -5;

    test_msg.vel_ecef.z = 10;

    sbp_message_send(&sbp_state, SbpMsgVelEcef, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef.accuracy, expected 0, is "
        << (int64_t)last_msg.msg.vel_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ecef.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef.n_sats, 14)
        << "incorrect value for last_msg.msg.vel_ecef.n_sats, expected 14, is "
        << (int64_t)last_msg.msg.vel_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef.tow, 326825000)
        << "incorrect value for last_msg.msg.vel_ecef.tow, expected 326825000, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef.x, -8)
        << "incorrect value for last_msg.msg.vel_ecef.x, expected -8, is "
        << (int64_t)last_msg.msg.vel_ecef.x;

    EXPECT_EQ(last_msg.msg.vel_ecef.y, -5)
        << "incorrect value for last_msg.msg.vel_ecef.y, expected -5, is "
        << (int64_t)last_msg.msg.vel_ecef.y;

    EXPECT_EQ(last_msg.msg.vel_ecef.z, 10)
        << "incorrect value for last_msg.msg.vel_ecef.z, expected 10, is "
        << (int64_t)last_msg.msg.vel_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  13,  2,   211, 136, 20, 28, 246, 122, 19, 244, 255, 255, 255,
        238, 255, 255, 255, 11,  0,  0,  0,   0,   0,  15,  0,   215, 120,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef.accuracy = 0;

    test_msg.vel_ecef.flags = 0;

    test_msg.vel_ecef.n_sats = 15;

    test_msg.vel_ecef.tow = 326825500;

    test_msg.vel_ecef.x = -12;

    test_msg.vel_ecef.y = -18;

    test_msg.vel_ecef.z = 11;

    sbp_message_send(&sbp_state, SbpMsgVelEcef, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef.accuracy, expected 0, is "
        << (int64_t)last_msg.msg.vel_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ecef.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.vel_ecef.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.vel_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef.tow, 326825500)
        << "incorrect value for last_msg.msg.vel_ecef.tow, expected 326825500, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef.x, -12)
        << "incorrect value for last_msg.msg.vel_ecef.x, expected -12, is "
        << (int64_t)last_msg.msg.vel_ecef.x;

    EXPECT_EQ(last_msg.msg.vel_ecef.y, -18)
        << "incorrect value for last_msg.msg.vel_ecef.y, expected -18, is "
        << (int64_t)last_msg.msg.vel_ecef.y;

    EXPECT_EQ(last_msg.msg.vel_ecef.z, 11)
        << "incorrect value for last_msg.msg.vel_ecef.z, expected 11, is "
        << (int64_t)last_msg.msg.vel_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  13,  2,   211, 136, 20, 16, 248, 122, 19, 248, 255, 255, 255,
        250, 255, 255, 255, 7,   0,  0,  0,   0,   0,  15,  0,   248, 221,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef.accuracy = 0;

    test_msg.vel_ecef.flags = 0;

    test_msg.vel_ecef.n_sats = 15;

    test_msg.vel_ecef.tow = 326826000;

    test_msg.vel_ecef.x = -8;

    test_msg.vel_ecef.y = -6;

    test_msg.vel_ecef.z = 7;

    sbp_message_send(&sbp_state, SbpMsgVelEcef, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef.accuracy, expected 0, is "
        << (int64_t)last_msg.msg.vel_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ecef.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.vel_ecef.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.vel_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef.tow, 326826000)
        << "incorrect value for last_msg.msg.vel_ecef.tow, expected 326826000, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef.x, -8)
        << "incorrect value for last_msg.msg.vel_ecef.x, expected -8, is "
        << (int64_t)last_msg.msg.vel_ecef.x;

    EXPECT_EQ(last_msg.msg.vel_ecef.y, -6)
        << "incorrect value for last_msg.msg.vel_ecef.y, expected -6, is "
        << (int64_t)last_msg.msg.vel_ecef.y;

    EXPECT_EQ(last_msg.msg.vel_ecef.z, 7)
        << "incorrect value for last_msg.msg.vel_ecef.z, expected 7, is "
        << (int64_t)last_msg.msg.vel_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  13,  2,   211, 136, 20, 4, 250, 122, 19, 249, 255, 255, 255,
        239, 255, 255, 255, 16,  0,  0, 0,   0,   0,  15,  0,   1,   167,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef.accuracy = 0;

    test_msg.vel_ecef.flags = 0;

    test_msg.vel_ecef.n_sats = 15;

    test_msg.vel_ecef.tow = 326826500;

    test_msg.vel_ecef.x = -7;

    test_msg.vel_ecef.y = -17;

    test_msg.vel_ecef.z = 16;

    sbp_message_send(&sbp_state, SbpMsgVelEcef, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef.accuracy, expected 0, is "
        << (int64_t)last_msg.msg.vel_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ecef.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.vel_ecef.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.vel_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef.tow, 326826500)
        << "incorrect value for last_msg.msg.vel_ecef.tow, expected 326826500, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef.x, -7)
        << "incorrect value for last_msg.msg.vel_ecef.x, expected -7, is "
        << (int64_t)last_msg.msg.vel_ecef.x;

    EXPECT_EQ(last_msg.msg.vel_ecef.y, -17)
        << "incorrect value for last_msg.msg.vel_ecef.y, expected -17, is "
        << (int64_t)last_msg.msg.vel_ecef.y;

    EXPECT_EQ(last_msg.msg.vel_ecef.z, 16)
        << "incorrect value for last_msg.msg.vel_ecef.z, expected 16, is "
        << (int64_t)last_msg.msg.vel_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  13,  2,   211, 136, 20, 248, 251, 122, 19, 247, 255, 255, 255,
        243, 255, 255, 255, 14,  0,  0,   0,   0,   0,  15,  0,   191, 43,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef.accuracy = 0;

    test_msg.vel_ecef.flags = 0;

    test_msg.vel_ecef.n_sats = 15;

    test_msg.vel_ecef.tow = 326827000;

    test_msg.vel_ecef.x = -9;

    test_msg.vel_ecef.y = -13;

    test_msg.vel_ecef.z = 14;

    sbp_message_send(&sbp_state, SbpMsgVelEcef, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef.accuracy, expected 0, is "
        << (int64_t)last_msg.msg.vel_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef.flags, expected 0, is "
        << (int64_t)last_msg.msg.vel_ecef.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.vel_ecef.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.vel_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef.tow, 326827000)
        << "incorrect value for last_msg.msg.vel_ecef.tow, expected 326827000, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef.x, -9)
        << "incorrect value for last_msg.msg.vel_ecef.x, expected -9, is "
        << (int64_t)last_msg.msg.vel_ecef.x;

    EXPECT_EQ(last_msg.msg.vel_ecef.y, -13)
        << "incorrect value for last_msg.msg.vel_ecef.y, expected -13, is "
        << (int64_t)last_msg.msg.vel_ecef.y;

    EXPECT_EQ(last_msg.msg.vel_ecef.z, 14)
        << "incorrect value for last_msg.msg.vel_ecef.z, expected 14, is "
        << (int64_t)last_msg.msg.vel_ecef.z;
  }
}

}  // namespace
